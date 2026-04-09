#define NOMINMAX
#undef ERROR

#include <crow_all.h>
#include "generated/LogicLexer.h"
#include "generated/LogicParser.h"
#include "ASTBuilder.h"
#include "ASTUtils.h"

#include <antlr4-runtime.h>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <any>
#include <fstream>
#include <functional>
#include <locale>

/* ---------- Label ---------- */

std::string simplifyLabel(const std::string& type, const std::string& value) {
if (type == "And") return "∧";
if (type == "Or") return "∨";
if (type == "Not") return "¬";
if (type == "Implies") return "→";
if (type == "Iff") return "↔";
if (type == "Variable") return value;
return value.empty() ? type : value;
}

/* ---------- Mermaid ---------- */

int& nodeIdCounter() {
static int counter = 0;
return counter;
}

void resetNodeId() {
nodeIdCounter() = 0;
}

void buildMermaid(const std::shared_ptr<ASTNode>& node,
std::ostringstream& oss,
const std::string& parent = "") {


if (!node) return;

int& id = nodeIdCounter();
std::string nodeId = "n" + std::to_string(id++);

std::string base = simplifyLabel(node->type, node->value);
std::string label = base;

// 🔥 Add (x1) annotation
if (!node->label.empty()) {
    label += " (" + node->label + ")";
}

// Escape
for (char& c : label)
    if (c == '"' || c == '\\') c = ' ';

oss << nodeId << "((\"" << label << "\"));\n";

if (!parent.empty())
    oss << parent << " --> " << nodeId << ";\n";

for (auto& child : node->children)
    buildMermaid(child, oss, nodeId);


}

/* ---------- Parser ---------- */

std::shared_ptr<ASTNode> parseExpression(const std::string& exprStr) {
antlr4::ANTLRInputStream input(exprStr);
LogicLexer lexer(&input);
antlr4::CommonTokenStream tokens(&lexer);
LogicParser parser(&tokens);


auto tree = parser.expr();
ASTBuilder builder;
auto astAny = builder.visit(tree);

return std::any_cast<std::shared_ptr<ASTNode>>(astAny);


}

/* ---------- MAIN ---------- */

int main() {


// UTF-8
try {
    std::locale::global(std::locale("en_US.UTF-8"));
} catch (...) {
    try { std::locale::global(std::locale(".UTF-8")); }
    catch (...) {}
}

std::wcout.imbue(std::locale());
std::cout.imbue(std::locale());

crow::SimpleApp app;

/* ---------- Serve UI ---------- */
CROW_ROUTE(app, "/")([]() {
    std::ifstream file("static/index.html", std::ios::binary);
    if (!file.is_open())
        return crow::response(404, "index.html not found");

    std::ostringstream buffer;
    buffer << file.rdbuf();

    crow::response res(buffer.str());
    res.set_header("Content-Type", "text/html; charset=UTF-8");
    return res;
});

/* ---------- Parse ---------- */
CROW_ROUTE(app, "/parse").methods("POST"_method)
([](const crow::request& req) {

    std::string expr = req.body;
    if (expr.empty())
        return crow::response(400, "Empty expression");

    try {
        resetNodeId();

        auto ast = parseExpression(expr);

        /* ---------- Tseitin FIRST ---------- */
        TseitinResult tseitin = astToTseitin(ast.get());

/* ---------- Mermaid AFTER ---------- */
        std::ostringstream oss;
        oss << "graph TD;\n";
        buildMermaid(ast, oss);

        /* ---------- Node ranges ---------- */
        crow::json::wvalue::list nodeRanges;

        std::function<void(const std::shared_ptr<ASTNode>&)> collect =
            [&](const std::shared_ptr<ASTNode>& n) {
                if (!n) return;

                crow::json::wvalue item;
                item["label"] = simplifyLabel(n->type, n->value); // IMPORTANT: base label only
                item["start"] = n->start;
                item["end"] = n->end;

                nodeRanges.push_back(std::move(item));

                for (auto& c : n->children)
                    collect(c);
            };

        collect(ast);

        /* ---------- JSON ---------- */
        crow::json::wvalue data;

        data["mermaid"] = oss.str();
        data["ranges"] = std::move(nodeRanges);
        data["top"] = tseitin.topVar;

        /* ---------- CNF ---------- */
        crow::json::wvalue::list cnfList;
        for (auto &c : tseitin.cnf)
            cnfList.push_back(c);
        data["cnf"] = std::move(cnfList);

        /* ---------- Steps ---------- */
        crow::json::wvalue::list stepList;

        for (auto &s : tseitin.steps) {
            crow::json::wvalue step;
            step["var"] = s.var;
            step["formula"] = s.formula;

            crow::json::wvalue::list cls;
            for (auto &c : s.clauses)
                cls.push_back(c);

            step["clauses"] = std::move(cls);
            stepList.push_back(std::move(step));
        }

        data["steps"] = std::move(stepList);

        /* ---------- Mapping ---------- */
        crow::json::wvalue::list mappingList;

        for (auto &m : tseitin.mapping) {
            crow::json::wvalue item;
            item["var"] = m.first;
            item["expr"] = m.second;
            mappingList.push_back(std::move(item));
        }

        data["mapping"] = std::move(mappingList);

        crow::response res{data};
        res.set_header("Content-Type", "application/json; charset=UTF-8");
        return res;

    } catch (const std::exception& e) {

        crow::response err(500, std::string("Parse error: ") + e.what());
        err.set_header("Content-Type", "text/plain; charset=UTF-8");
        return err;
    }
});

std::cout << " FINAL CLEAN VERSION RUNNING \n";

app.port(18080).multithreaded().run();


}

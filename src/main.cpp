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
#include <codecvt>

std::string simplifyLabel(const std::string& type, const std::string& value) {
    if (type == "And") return "∧";
    if (type == "Or") return "∨";
    if (type == "Not") return "¬";
    if (type == "Implies") return "→";
    if (type == "Iff") return "↔";
    if (type == "Variable") return value;
    return value.empty() ? type : value;
}

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

    if (node->type == "Group" ||
        node->type == "Expr" ||
        node->type == "OrExpr" ||
        node->type == "AndExpr" ||
        node->type == "Atom") {
        for (auto& child : node->children)
            buildMermaid(child, oss, parent);
        return;
    }

    int& id = nodeIdCounter();
    std::string nodeId = "n" + std::to_string(id++);

    std::string label = simplifyLabel(node->type, node->value);
    for (char& c : label)
        if (c == '"' || c == '\\') c = ' ';

    oss << nodeId << "((\"" << label << "\"));\n";

    if (!parent.empty())
        oss << parent << " --> " << nodeId << ";\n";

    for (auto& child : node->children)
        buildMermaid(child, oss, nodeId);
}

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

int main() {
    try {
    std::locale::global(std::locale("en_US.UTF-8"));
} catch (...) {
    try {
        std::locale::global(std::locale(".UTF-8"));
    } catch (...) {
        std::cerr << "⚠️ Warning: Unable to set UTF-8 locale. Continuing with default locale.\n";
    }
}

    std::wcout.imbue(std::locale());
    std::cout.imbue(std::locale());

    crow::SimpleApp app;

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

    CROW_ROUTE(app, "/parse").methods("POST"_method)([](const crow::request& req) {
        std::string expr = req.body;
        if (expr.empty())
            return crow::response(400, "Empty expression");

        try {
            resetNodeId();
            auto ast = parseExpression(expr);

            std::ostringstream oss;
            oss << "graph TD;\n";
            buildMermaid(ast, oss);

            std::string tseitin = astToTseitin(ast.get());

            crow::json::wvalue::list nodeRanges;
            std::function<void(const std::shared_ptr<ASTNode>&)> collect =
                [&](const std::shared_ptr<ASTNode>& n) {
                    if (!n) return;
                    crow::json::wvalue item;
                    item["label"] = simplifyLabel(n->type, n->value);
                    item["start"] = n->start;
                    item["end"] = n->end;
                    nodeRanges.push_back(std::move(item));
                    for (auto& c : n->children) collect(c);
                };
            collect(ast);

            crow::json::wvalue data;
            data["mermaid"] = oss.str();
            data["cnf"] = tseitin;
            data["ranges"] = std::move(nodeRanges);

            crow::response res{data};
            res.set_header("Content-Type", "application/json; charset=UTF-8");
            return res;

        } catch (const std::exception& e) {
            crow::response err(500, std::string("Parse error: ") + e.what());
            err.set_header("Content-Type", "text/plain; charset=UTF-8");
            return err;
        }
    });

    std::cout << "✅ NEW CPP VERSION RUNNING — Auto deploy works! \n";
    app.port(18080).multithreaded().run();
}

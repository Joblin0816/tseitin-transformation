#include "ASTUtils.h"
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <functional>
#include <set>

/* ---------- Symbols ---------- */

std::string getSymbol(const std::string& type) {
    static const std::unordered_map<std::string, std::string> symbols = {
        {"And", "∧"},
        {"Or", "∨"},
        {"Not", "¬"},
        {"Implies", "→"},
        {"Iff", "↔"}
    };
    auto it = symbols.find(type);
    return (it != symbols.end()) ? it->second : type;
}

/* ---------- AST → Formula (NEW) ---------- */
/* This is the key addition */

static std::string astToFormula(const ASTNode* node) {
    if (!node) return "";

    if (node->type == "Variable") {
        return node->value;
    }

    if (node->type == "Not") {
        return "¬" + astToFormula(node->children[0].get());
    }

    if (node->children.size() == 2) {
        std::string a = astToFormula(node->children[0].get());
        std::string b = astToFormula(node->children[1].get());

        if (node->type == "And")     return "(" + a + " ∧ " + b + ")";
        if (node->type == "Or")      return "(" + a + " ∨ " + b + ")";
        if (node->type == "Implies") return "(" + a + " → " + b + ")";
        if (node->type == "Iff")     return "(" + a + " ↔ " + b + ")";
    }

    if (!node->children.empty())
        return astToFormula(node->children[0].get());

    return "";
}

/* ---------- Mermaid ---------- */

void buildMermaid(const ASTNode* node, std::ostringstream& out, int& id, int parentId) {
    if (!node) return;

    int nodeId = id++;
    std::string label;

    if (node->type == "Group") {
        for (const auto& child : node->children)
            buildMermaid(child.get(), out, id, parentId);
        return;
    }

    label = (node->type == "Variable") ? node->value : getSymbol(node->type);

    out << "n" << nodeId << "((" << label << "))\n";

    if (parentId >= 0)
        out << "n" << parentId << " --> n" << nodeId << "\n";

    for (const auto& child : node->children)
        buildMermaid(child.get(), out, id, nodeId);
}

std::string astToMermaid(const ASTNode* root) {
    std::ostringstream out;
    out << "graph TD;\n";
    int id = 0;
    buildMermaid(root, out, id, -1);
    return out.str();
}

/* ---------- Tseitin ---------- */

static std::string freshVar(int id) {
    return "t" + std::to_string(id);
}

std::string astToTseitin(const ASTNode* root) {
    if (!root) return "";

    int nextId = 1;
    std::map<const ASTNode*, std::string> nodeVar;
    std::vector<std::vector<std::pair<std::string,bool>>> clauses;

    std::function<std::string(const ASTNode*)> visit =
    [&](const ASTNode* node)->std::string {
        if (!node) return "";

        if (node->type == "Variable") {
            std::string v = node->value;
            nodeVar[node] = v;
            return v;
        }

        if (node->type == "Group" && !node->children.empty())
            return visit(node->children[0].get());

        std::vector<std::string> childVars;
        for (auto &c : node->children)
            childVars.push_back(visit(c.get()));

        std::string cur = freshVar(nextId++);
        nodeVar[node] = cur;

        if (node->type == "Not") {
            std::string a = childVars[0];
            clauses.push_back({{cur,true},{a,true}});
            clauses.push_back({{cur,false},{a,false}});
        }
        else if (node->type == "And") {
            std::string a = childVars[0], b = childVars[1];
            clauses.push_back({{cur,true},{a,false}});
            clauses.push_back({{cur,true},{b,false}});
            clauses.push_back({{a,true},{b,true},{cur,false}});
        }
        else if (node->type == "Or") {
            std::string a = childVars[0], b = childVars[1];
            clauses.push_back({{a,true},{cur,false}});
            clauses.push_back({{b,true},{cur,false}});
            clauses.push_back({{cur,true},{a,false},{b,false}});
        }
        else if (node->type == "Implies") {
            std::string a = childVars[0], b = childVars[1];
            clauses.push_back({{cur,true},{a,true},{b,false}});
            clauses.push_back({{cur,false},{a,false}});
            clauses.push_back({{cur,false},{b,true}});
        }
        else if (node->type == "Iff") {
            std::string a = childVars[0], b = childVars[1];
            clauses.push_back({{cur,true},{a,true},{b,false}});
            clauses.push_back({{cur,true},{b,true},{a,false}});
            clauses.push_back({{cur,false},{a,false},{b,false}});
            clauses.push_back({{cur,false},{a,true},{b,true}});
        }

        return cur;
    };

    std::string top = visit(root);
    clauses.push_back({{top,false}});

    std::ostringstream out;
    out << "Top variable: " << top << "\\n\\n";
    out << "Variable mapping:\\n";

    std::vector<std::pair<std::string,std::string>> mapping;
    for (auto &kv : nodeVar)
        mapping.push_back({kv.second, astToFormula(kv.first)});

    std::sort(mapping.begin(), mapping.end(),
              [](auto &a, auto &b){ return a.first < b.first; });

    std::set<std::string> seen;
    for (auto &p : mapping) {
        if (seen.insert(p.first + ":" + p.second).second)
            out << p.first << " => " << p.second << "\\n";
    }

    out << "\\nCNF clauses:\\n";
    for (auto &cl : clauses) {
        out << "(";
        bool first = true;
        for (auto &lit : cl) {
            if (!first) out << " ∨ ";
            out << (lit.second ? "¬" : "") << lit.first;
            first = false;
        }
        out << ")\\n";
    }

    return out.str();
}

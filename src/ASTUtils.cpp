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

/* ---------- AST → Formula (REQUIRED FIX) ---------- */

static std::string astToFormula(const ASTNode* node) {
    if (!node) return "";

    if (node->type == "Variable")
        return node->value;

    if (node->type == "Not")
        return "¬" + astToFormula(node->children[0].get());

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

/* ---------- Tseitin ---------- */

static std::string freshVar(int id) {
    return "t" + std::to_string(id);
}

TseitinResult astToTseitin(const ASTNode* root) {
    TseitinResult result;
    if (!root) return result;

    int nextId = 1;

    std::map<const ASTNode*, std::string> nodeVar;

    std::vector<std::vector<std::pair<std::string,bool>>> clauses;
    std::vector<TseitinStep> steps;

    std::function<std::string(const ASTNode*)> visit =
    [&](const ASTNode* node)->std::string {

        if (!node) return "";

        if (node->type == "Variable") {
            nodeVar[node] = node->value;
            return node->value;
        }

        if (node->type == "Group" && !node->children.empty())
            return visit(node->children[0].get());

        std::vector<std::string> childVars;
        for (auto &c : node->children)
            childVars.push_back(visit(c.get()));

        std::string cur = freshVar(nextId++);
        nodeVar[node] = cur;

        std::vector<std::string> localClauses;

        /* ---------- Operators ---------- */

        if (node->type == "Not") {
            std::string a = childVars[0];

            clauses.push_back({{cur,true},{a,true}});
            clauses.push_back({{cur,false},{a,false}});

            localClauses = {
                "(¬" + cur + " ∨ ¬" + a + ")",
                "(" + cur + " ∨ " + a + ")"
            };
        }

        else if (node->type == "And") {
            std::string a = childVars[0], b = childVars[1];

            clauses.push_back({{cur,true},{a,false}});
            clauses.push_back({{cur,true},{b,false}});
            clauses.push_back({{a,true},{b,true},{cur,false}});

            localClauses = {
                "(¬" + cur + " ∨ " + a + ")",
                "(¬" + cur + " ∨ " + b + ")",
                "(¬" + a + " ∨ ¬" + b + " ∨ " + cur + ")"
            };
        }

        else if (node->type == "Or") {
            std::string a = childVars[0], b = childVars[1];

            clauses.push_back({{a,true},{cur,false}});
            clauses.push_back({{b,true},{cur,false}});
            clauses.push_back({{cur,true},{a,false},{b,false}});

            localClauses = {
                "(" + a + " ∨ ¬" + cur + ")",
                "(" + b + " ∨ ¬" + cur + ")",
                "(¬" + a + " ∨ ¬" + b + " ∨ " + cur + ")"
            };
        }

        else if (node->type == "Implies") {
            std::string a = childVars[0], b = childVars[1];

            clauses.push_back({{cur,true},{a,true},{b,false}});
            clauses.push_back({{cur,false},{a,false}});
            clauses.push_back({{cur,false},{b,true}});

            localClauses = {
                "(¬" + cur + " ∨ ¬" + a + " ∨ " + b + ")",
                "(" + cur + " ∨ " + a + ")",
                "(" + cur + " ∨ ¬" + b + ")"
            };
        }

        else if (node->type == "Iff") {
            std::string a = childVars[0], b = childVars[1];

            clauses.push_back({{cur,true},{a,true},{b,false}});
            clauses.push_back({{cur,true},{b,true},{a,false}});
            clauses.push_back({{cur,false},{a,false},{b,false}});
            clauses.push_back({{cur,false},{a,true},{b,true}});

            localClauses = {
                "(¬" + cur + " ∨ ¬" + a + " ∨ " + b + ")",
                "(¬" + cur + " ∨ ¬" + b + " ∨ " + a + ")",
                "(" + cur + " ∨ " + a + " ∨ " + b + ")",
                "(" + cur + " ∨ ¬" + a + " ∨ ¬" + b + ")"
            };
        }

        /* ---------- Step Tracking ---------- */

        steps.push_back({
            cur,
            astToFormula(node),
            localClauses
        });

        return cur;
    };

    std::string top = visit(root);

    /* ---------- Final clause ---------- */

    clauses.push_back({{top,false}});
    result.topVar = top;

    /* ---------- CNF ---------- */

    for (auto &cl : clauses) {
        std::ostringstream line;
        line << "(";
        bool first = true;
        for (auto &lit : cl) {
            if (!first) line << " ∨ ";
            line << (lit.second ? "¬" : "") << lit.first;
            first = false;
        }
        line << ")";
        result.cnf.push_back(line.str());
    }

    result.steps = steps;

    /* ---------- Variable Mapping (FIXED) ---------- */

    std::vector<std::pair<std::string,std::string>> mapping;
    std::set<std::string> seen;

    for (auto &kv : nodeVar) {
        std::string var = kv.second;
        std::string expr = astToFormula(kv.first);

        if (expr.empty()) continue;

        std::string key = var + ":" + expr;

        if (seen.insert(key).second) {
            mapping.push_back({var, expr});
        }
    }

    std::sort(mapping.begin(), mapping.end());
    result.mapping = mapping;

    return result;
}
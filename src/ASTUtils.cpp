#include "ASTUtils.h"
#include <sstream>
#include <unordered_map>
#include <map>
#include <sstream>
#include <algorithm>
#include <functional> 
#include <set>

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

void buildMermaid(const ASTNode* node, std::ostringstream& out, int& id, int parentId) {
    if (!node) return;

    int nodeId = id++;
    std::string label;

    if (node->type == "Group") {
        for (const auto& child : node->children) {
            buildMermaid(child.get(), out, id, parentId);
        }
        return;
    }

    if (node->type == "Variable") {
        label = node->value;  
    } else {
        label = getSymbol(node->type);
    }

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

static std::string freshVar(int id) {
    return "t" + std::to_string(id);
}

// static std::string litStr(const std::string &v, bool neg) {
//     return (neg ? "¬" : "") + v;
// }

std::string astToTseitin(const ASTNode* root) {
    if (!root) return "";

    int nextId = 1;
    std::map<const ASTNode*, std::string> nodeVar;
    std::vector<std::vector<std::pair<std::string,bool>>> clauses;

    std::function<std::string(const ASTNode*)> visit = [&](const ASTNode* node)->std::string {
        if (!node) return "";
        if (node->type == "Variable") {
            std::string v = node->value.empty() ? ("v" + std::to_string(nextId++)) : node->value;
            nodeVar[node] = v;
            return v;
        }
        if (node->type == "Group") {
            if (!node->children.empty()) return visit(node->children[0].get());
        }

        std::vector<std::string> childVars;
        for (auto &cptr : node->children) childVars.push_back( visit(cptr.get()) );

        std::string cur = freshVar(nextId++);
        nodeVar[node] = cur;

        if (node->type == "Not") {
            std::string a = childVars.size() ? childVars[0] : "UNKNOWN";
            clauses.push_back({{cur,true},{a,true}});
            clauses.push_back({{cur,false},{a,false}});
        } else if (node->type == "And") {
            if (childVars.size() >= 2) {
                std::string a = childVars[0], b = childVars[1];
                clauses.push_back({{cur,true},{a,false}});
                clauses.push_back({{cur,true},{b,false}});
                clauses.push_back({{a,true},{b,true},{cur,false}});
            } else if (childVars.size() == 1) {\
                std::string a = childVars[0];
                clauses.push_back({{cur,true},{a,false}});
                clauses.push_back({{cur,false},{a,true}});
            }
        } else if (node->type == "Or") {
            if (childVars.size() >= 2) {
                std::string a = childVars[0], b = childVars[1];
                clauses.push_back({{a,true},{cur,false}});
                clauses.push_back({{b,true},{cur,false}});
                clauses.push_back({{cur,true},{a,false},{b,false}});
            } else if (childVars.size() == 1) {
                std::string a = childVars[0];
                clauses.push_back({{cur,true},{a,false}});
                clauses.push_back({{cur,false},{a,true}});
            }
        } else if (node->type == "Implies") {
            if (childVars.size() >= 2) {
                std::string a = childVars[0], b = childVars[1];
                clauses.push_back({{cur,true},{a,true},{b,false}});
                clauses.push_back({{cur,false},{a,false}});
                clauses.push_back({{cur,false},{b,true}});
            }
        } else if (node->type == "Iff") {
            if (childVars.size() >= 2) {
                std::string a = childVars[0], b = childVars[1];
                clauses.push_back({{cur,true},{a,true},{b,false}});
                clauses.push_back({{cur,true},{b,true},{a,false}});
                clauses.push_back({{cur,false},{a,false},{b,false}});
                clauses.push_back({{cur,false},{a,true},{b,true}});
            }
        } else {
            for (auto &cv : childVars) {
                clauses.push_back({{cur,true},{cv,false}});
                clauses.push_back({{cur,false},{cv,true}});
            }
        }
        return cur;
    };

    std::string top = visit(root);
    clauses.push_back({{top,false}});
    std::ostringstream out;
    out << "Top variable: " << top << "\\n\\n";
    out << "Variable mapping:\\n";
    std::vector<std::pair<std::string,std::string>> mapping;
    for (auto &kv : nodeVar) mapping.push_back({kv.second, kv.first->type + (kv.first->value.empty() ? "" : (":" + kv.first->value))});
    std::sort(mapping.begin(), mapping.end(), [](auto &a, auto &b){ return a.first < b.first; });
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

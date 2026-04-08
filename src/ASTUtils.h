#pragma once
#include "ASTNode.h"
#include <string>
#include <vector>

struct TseitinStep {
    std::string var;
    std::string formula;
    std::vector<std::string> clauses;
};

struct TseitinResult {
    std::string topVar;
    std::vector<TseitinStep> steps;
    std::vector<std::string> cnf;
    std::vector<std::pair<std::string,std::string>> mapping; // ✅ MUST EXIST
};

std::string astToMermaid(const ASTNode* root);
TseitinResult astToTseitin(const ASTNode* root);
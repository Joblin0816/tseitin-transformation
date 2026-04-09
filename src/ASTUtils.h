#pragma once

#include "ASTNode.h"
#include <string>
#include <vector>

/* ---------- Step ---------- */
struct TseitinStep {
    std::string var;
    std::string formula;
    std::vector<std::string> clauses;
};

/* ---------- Result ---------- */
struct TseitinResult {
    std::string topVar;
    std::vector<TseitinStep> steps;
    std::vector<std::string> cnf;
    std::vector<std::pair<std::string, std::string>> mapping;
};

/* ---------- Function ---------- */
TseitinResult astToTseitin(const ASTNode* root);
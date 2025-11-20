#pragma once
#include "ASTNode.h"
#include <string>

std::string astToMermaid(const ASTNode* root);
std::string astToTseitin(const ASTNode* root);

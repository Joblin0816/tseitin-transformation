#pragma once
#include <string>
#include <vector>
#include <memory>

struct ASTNode {
    std::string type;
    std::string value;
    std::vector<std::shared_ptr<ASTNode>> children;

    int start = -1;
    int end = -1;
};

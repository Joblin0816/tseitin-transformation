#pragma once

#include "generated/LogicBaseVisitor.h"
#include "ASTNode.h"
#include <any>
#include <memory>

class ASTBuilder : public LogicBaseVisitor {
public:
std::any visitExpr(LogicParser::ExprContext *ctx) override;
std::any visitIffExpr(LogicParser::IffExprContext *ctx) override;
std::any visitImpliesExpr(LogicParser::ImpliesExprContext *ctx) override;
std::any visitOrExpr(LogicParser::OrExprContext *ctx) override;
std::any visitAndExpr(LogicParser::AndExprContext *ctx) override;
std::any visitAtom(LogicParser::AtomContext *ctx) override;
};

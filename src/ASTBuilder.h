#pragma once
#include "generated/LogicBaseVisitor.h"
#include "ASTNode.h"
#include <any>

class ASTBuilder : public LogicBaseVisitor {
public:
    virtual std::any visitExpr(LogicParser::ExprContext *ctx) override;
    virtual std::any visitIffExpr(LogicParser::IffExprContext *ctx) override;
    virtual std::any visitImpliesExpr(LogicParser::ImpliesExprContext *ctx) override;
    virtual std::any visitOrExpr(LogicParser::OrExprContext *ctx) override;
    virtual std::any visitAndExpr(LogicParser::AndExprContext *ctx) override;
    virtual std::any visitAtom(LogicParser::AtomContext *ctx) override;
};

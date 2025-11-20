
// Generated from grammar/Logic.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LogicVisitor.h"


/**
 * This class provides an empty implementation of LogicVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  LogicBaseVisitor : public LogicVisitor {
public:

  virtual std::any visitExpr(LogicParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIffExpr(LogicParser::IffExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImpliesExpr(LogicParser::ImpliesExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(LogicParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(LogicParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom(LogicParser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }


};


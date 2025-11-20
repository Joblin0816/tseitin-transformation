
// Generated from grammar/Logic.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LogicParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by LogicParser.
 */
class  LogicListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterExpr(LogicParser::ExprContext *ctx) = 0;
  virtual void exitExpr(LogicParser::ExprContext *ctx) = 0;

  virtual void enterIffExpr(LogicParser::IffExprContext *ctx) = 0;
  virtual void exitIffExpr(LogicParser::IffExprContext *ctx) = 0;

  virtual void enterImpliesExpr(LogicParser::ImpliesExprContext *ctx) = 0;
  virtual void exitImpliesExpr(LogicParser::ImpliesExprContext *ctx) = 0;

  virtual void enterOrExpr(LogicParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(LogicParser::OrExprContext *ctx) = 0;

  virtual void enterAndExpr(LogicParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(LogicParser::AndExprContext *ctx) = 0;

  virtual void enterAtom(LogicParser::AtomContext *ctx) = 0;
  virtual void exitAtom(LogicParser::AtomContext *ctx) = 0;


};


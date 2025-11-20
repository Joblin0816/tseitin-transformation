
// Generated from grammar/Logic.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LogicListener.h"


/**
 * This class provides an empty implementation of LogicListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  LogicBaseListener : public LogicListener {
public:

  virtual void enterExpr(LogicParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(LogicParser::ExprContext * /*ctx*/) override { }

  virtual void enterIffExpr(LogicParser::IffExprContext * /*ctx*/) override { }
  virtual void exitIffExpr(LogicParser::IffExprContext * /*ctx*/) override { }

  virtual void enterImpliesExpr(LogicParser::ImpliesExprContext * /*ctx*/) override { }
  virtual void exitImpliesExpr(LogicParser::ImpliesExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(LogicParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(LogicParser::OrExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(LogicParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(LogicParser::AndExprContext * /*ctx*/) override { }

  virtual void enterAtom(LogicParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(LogicParser::AtomContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


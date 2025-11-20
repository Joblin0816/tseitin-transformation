
// Generated from grammar/Logic.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "LogicParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by LogicParser.
 */
class  LogicVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by LogicParser.
   */
    virtual std::any visitExpr(LogicParser::ExprContext *context) = 0;

    virtual std::any visitIffExpr(LogicParser::IffExprContext *context) = 0;

    virtual std::any visitImpliesExpr(LogicParser::ImpliesExprContext *context) = 0;

    virtual std::any visitOrExpr(LogicParser::OrExprContext *context) = 0;

    virtual std::any visitAndExpr(LogicParser::AndExprContext *context) = 0;

    virtual std::any visitAtom(LogicParser::AtomContext *context) = 0;


};


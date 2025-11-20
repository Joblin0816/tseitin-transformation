#include "ASTBuilder.h"

std::any ASTBuilder::visitExpr(LogicParser::ExprContext *ctx) {
    auto node = std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->iffExpr()));
    node->start = ctx->getStart()->getStartIndex();
    node->end = ctx->getStop()->getStopIndex();
    return node;
}

std::any ASTBuilder::visitIffExpr(LogicParser::IffExprContext *ctx) {
    auto node = std::make_shared<ASTNode>();
    node->start = ctx->getStart()->getStartIndex();
    node->end = ctx->getStop()->getStopIndex();

    if (ctx->impliesExpr().size() == 2) {
        node->type = "Iff";
        node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->impliesExpr(0))));
        node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->impliesExpr(1))));
    } else {
        return visit(ctx->impliesExpr(0));
    }
    return node;
}

std::any ASTBuilder::visitImpliesExpr(LogicParser::ImpliesExprContext *ctx) {
    auto node = std::make_shared<ASTNode>();
    node->start = ctx->getStart()->getStartIndex();
    node->end = ctx->getStop()->getStopIndex();

    if (ctx->orExpr().size() == 2) {
        node->type = "Implies";
        node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->orExpr(0))));
        node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->orExpr(1))));
    } else {
        return visit(ctx->orExpr(0));
    }
    return node;
}

std::any ASTBuilder::visitOrExpr(LogicParser::OrExprContext *ctx) {
    auto node = std::make_shared<ASTNode>();
    node->start = ctx->getStart()->getStartIndex();
    node->end = ctx->getStop()->getStopIndex();

    if (ctx->andExpr().size() >= 2) {
        node->type = "Or";
        for (auto expr : ctx->andExpr())
            node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(expr)));
    } else {
        return visit(ctx->andExpr(0));
    }
    return node;
}

std::any ASTBuilder::visitAndExpr(LogicParser::AndExprContext *ctx) {
    auto node = std::make_shared<ASTNode>();
    node->start = ctx->getStart()->getStartIndex();
    node->end = ctx->getStop()->getStopIndex();

    if (ctx->atom().size() >= 2) {
        node->type = "And";
        for (auto a : ctx->atom())
            node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(a)));
    } else {
        return visit(ctx->atom(0));
    }
    return node;
}

std::any ASTBuilder::visitAtom(LogicParser::AtomContext *ctx) {
    auto node = std::make_shared<ASTNode>();
    node->start = ctx->getStart()->getStartIndex();
    node->end = ctx->getStop()->getStopIndex();

    if (!ctx->children.empty()) {
        std::string first = ctx->children[0]->getText();

        if (first == "NOT" || first == "¬") {
            node->type = "Not";
            node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->children[1])));
        } 
        else if (first == "(") {
            node->type = "Group";
            node->children.push_back(std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->expr())));
        } 
        else {
            node->type = "Variable";
            node->value = first;
        }
    }
    return node;
}

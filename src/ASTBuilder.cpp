#include "ASTBuilder.h"

/* ---------- ROOT ---------- */

std::any ASTBuilder::visitExpr(LogicParser::ExprContext *ctx) {
auto node = std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->iffExpr()));
node->start = ctx->getStart()->getStartIndex();
node->end   = ctx->getStop()->getStopIndex();
return node;
}

/* ---------- IFF ---------- */

std::any ASTBuilder::visitIffExpr(LogicParser::IffExprContext *ctx) {
if (ctx->impliesExpr().size() == 1)
return visit(ctx->impliesExpr(0));


auto node = std::make_shared<ASTNode>();
node->type = "Iff";

node->start = ctx->getStart()->getStartIndex();
node->end   = ctx->getStop()->getStopIndex();

node->children.push_back(
    std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->impliesExpr(0)))
);
node->children.push_back(
    std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->impliesExpr(1)))
);

return node;


}

/* ---------- IMPLIES ---------- */

std::any ASTBuilder::visitImpliesExpr(LogicParser::ImpliesExprContext *ctx) {
if (ctx->orExpr().size() == 1)
return visit(ctx->orExpr(0));


auto node = std::make_shared<ASTNode>();
node->type = "Implies";

node->start = ctx->getStart()->getStartIndex();
node->end   = ctx->getStop()->getStopIndex();

node->children.push_back(
    std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->orExpr(0)))
);
node->children.push_back(
    std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->orExpr(1)))
);

return node;


}

/* ---------- OR (BINARY TREE) ---------- */

std::any ASTBuilder::visitOrExpr(LogicParser::OrExprContext *ctx) {
if (ctx->andExpr().size() == 1)
return visit(ctx->andExpr(0));


auto left = std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->andExpr(0)));

for (size_t i = 1; i < ctx->andExpr().size(); ++i) {
    auto parent = std::make_shared<ASTNode>();
    parent->type = "Or";

    parent->children.push_back(left);
    parent->children.push_back(
        std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->andExpr(i)))
    );

    left = parent;
}

return left;


}

/* ---------- AND (BINARY TREE) ---------- */

std::any ASTBuilder::visitAndExpr(LogicParser::AndExprContext *ctx) {
if (ctx->atom().size() == 1)
return visit(ctx->atom(0));


auto left = std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->atom(0)));

for (size_t i = 1; i < ctx->atom().size(); ++i) {
    auto parent = std::make_shared<ASTNode>();
    parent->type = "And";

    parent->children.push_back(left);
    parent->children.push_back(
        std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->atom(i)))
    );

    left = parent;
}

return left;


}

/* ---------- ATOM ---------- */

std::any ASTBuilder::visitAtom(LogicParser::AtomContext *ctx) {


if (!ctx->children.empty()) {
    std::string first = ctx->children[0]->getText();

    /* ---------- NOT ---------- */
    if (first == "NOT" || first == "¬") {
        auto node = std::make_shared<ASTNode>();
        node->type = "Not";

        node->children.push_back(
            std::any_cast<std::shared_ptr<ASTNode>>(visit(ctx->children[1]))
        );

        node->start = ctx->getStart()->getStartIndex();
        node->end   = ctx->getStop()->getStopIndex();

        return node;
    }

    /* ---------- (expr) → FLATTEN ---------- */
    if (first == "(") {
        return visit(ctx->expr()); 
    }

    /* ---------- VARIABLE ---------- */
    auto node = std::make_shared<ASTNode>();
    node->type = "Variable";
    node->value = first;

    node->start = ctx->getStart()->getStartIndex();
    node->end   = ctx->getStop()->getStopIndex();

    return node;
}

return nullptr;


}

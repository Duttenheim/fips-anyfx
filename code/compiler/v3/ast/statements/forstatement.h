#pragma once
//------------------------------------------------------------------------------
/**
    For loop

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "statement.h"
#include "ast/expressions/expression.h"
#include <vector>
namespace AnyFX
{

struct ForStatement : public Statement
{
    /// constructor
    ForStatement(const std::vector<Symbol*>& declarations, Expression* condition, const std::vector<Expression*>& expressions, Statement* contents);
    std::vector<Symbol*> declarations;
    Expression* condition;
    std::vector<Expression*> expressions;
    Statement* contents;
};

} // namespace AnyFX

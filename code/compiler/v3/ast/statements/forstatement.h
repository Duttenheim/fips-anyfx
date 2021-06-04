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
    ForStatement(Symbol* declaration, Expression* condition, Statement* statement, Statement* contents);
    Symbol* declaration;
    Expression* condition;
    Statement* statement;
    Statement* contents;
};

} // namespace AnyFX

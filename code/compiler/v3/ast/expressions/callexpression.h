#pragma once
//------------------------------------------------------------------------------
/**
    Function call expression

    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "expression.h"
#include <vector>

namespace AnyFX
{

struct CallExpression : public Expression
{
    /// constructor
    CallExpression(Expression* function, const std::vector<Expression*>& args);

    /// eval type
    bool EvalType(Compiler* compiler, Type::FullType& out) const override;
    /// eval symbol
    bool EvalSymbol(Compiler* compiler, std::string& out) const override;
    /// evaluates expression as a string
    std::string EvalString(Compiler* compiler) const override;

    Expression* function;
    std::vector<Expression*> args;
};

} // namespace AnyFX

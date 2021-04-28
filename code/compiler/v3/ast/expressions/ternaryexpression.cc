//------------------------------------------------------------------------------
//  @file ternaryexpression.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "ternaryexpression.h"
#include "util.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
TernaryExpression::TernaryExpression(Expression* ifExpression, Expression* elseExpression)
    : ifExpression(ifExpression)
    , elseExpression(elseExpression)
{
    this->symbolType = TernaryStatementType;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
TernaryExpression::EvalString(Compiler* compiler) const
{
    return Format("? %s : %s", this->ifExpression->EvalString(compiler), this->elseExpression->EvalString(compiler));
}

} // namespace AnyFX

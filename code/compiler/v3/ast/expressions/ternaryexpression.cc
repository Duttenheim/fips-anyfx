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
TernaryExpression::TernaryExpression(Expression* lhs, Expression* ifExpression, Expression* elseExpression)
    : lhs(lhs)
    , ifExpression(ifExpression)
    , elseExpression(elseExpression)
{
    this->symbolType = TernaryExpressionType;
}

//------------------------------------------------------------------------------
/**
*/
TernaryExpression::~TernaryExpression()
{
    delete this->lhs;
    delete this->ifExpression;
    delete this->elseExpression;
}

//------------------------------------------------------------------------------
/**
*/
std::string
TernaryExpression::EvalString(Compiler* compiler) const
{
    std::string lhs, ifStr, elseStr;
    lhs = this->lhs->EvalString(compiler);
    ifStr = this->ifExpression->EvalString(compiler);
    elseStr = this->elseExpression->EvalString(compiler);
    return Format("%s ? %s : %s", lhs.c_str(), ifStr.c_str(), elseStr.c_str());
}

} // namespace AnyFX

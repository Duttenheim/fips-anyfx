//------------------------------------------------------------------------------
//  @file expressionstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "expressionstatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ExpressionStatement::ExpressionStatement(Expression* expression)
    : expression(expression)
{
    this->symbolType = ExpressionStatementType;
}

} // namespace AnyFX

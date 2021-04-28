//------------------------------------------------------------------------------
//  @file ifstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "ifstatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
IfStatement::IfStatement(Expression* condition, Statement* ifStatement, Statement* elseStatement)
    : condition(condition)
    , ifStatement(ifStatement)
    , elseStatement(elseStatement)
{
    this->symbolType = IfStatementType;
}

} // namespace AnyFX
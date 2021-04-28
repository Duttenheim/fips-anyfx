//------------------------------------------------------------------------------
//  @file whilestatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "whilestatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
WhileStatement::WhileStatement(Expression* condition, Statement* statement, bool isDoWhile)
    : condition(condition)
    , statement(statement)
    , isDoWhile(isDoWhile)
{
    this->symbolType = WhileStatementType;
}

} // namespace AnyFX

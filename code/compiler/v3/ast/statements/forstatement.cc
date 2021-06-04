//------------------------------------------------------------------------------
//  @file forstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "forstatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ForStatement::ForStatement(Symbol* declaration, Expression* condition, Statement* statement, Statement* contents)
    : declaration(declaration)
    , condition(condition)
    , statement(statement)
    , contents(contents)
{
    this->symbolType = ForStatementType;
}

} // namespace AnyFX

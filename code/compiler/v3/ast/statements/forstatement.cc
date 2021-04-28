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
ForStatement::ForStatement(const std::vector<Symbol*>& declarations, Expression* condition, const std::vector<Expression*>& expressions, Statement* contents)
    : declarations(declarations)
    , condition(condition)
    , expressions(expressions)
    , contents(contents)
{
    this->symbolType = ForStatementType;
}

} // namespace AnyFX

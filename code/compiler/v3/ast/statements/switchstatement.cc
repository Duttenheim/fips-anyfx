//------------------------------------------------------------------------------
//  @file switchstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "switchstatement.h"
#include <array>
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
SwitchStatement::SwitchStatement(Expression* switchExpression, const std::vector<std::string>& caseValues, const std::vector<Statement*>& caseStatements, Statement* defaultStatement)
    : switchExpression(switchExpression)
    , caseValues(caseValues)
    , caseStatements(caseStatements)
    , defaultStatement(defaultStatement)
{
    this->symbolType = SwitchStatementType;
}

} // namespace AnyFX

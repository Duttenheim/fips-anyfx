//------------------------------------------------------------------------------
//  @file switchstatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "switchstatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
SwitchStatement::SwitchStatement(Expression* switchExpression, const std::vector<std::string>& caseValues, const std::vector<Statement*>& caseStatements)
    : switchExpression(switchExpression)
    , caseValues(caseValues)
    , caseStatements(caseStatements)
{
    this->symbolType = SwitchStatementType;
}

} // namespace AnyFX

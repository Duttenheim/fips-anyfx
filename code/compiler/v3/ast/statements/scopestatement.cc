//------------------------------------------------------------------------------
//  @file scopestatement.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "scopestatement.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
ScopeStatement::ScopeStatement(const std::vector<Symbol*>& contents)
    : statements(contents)
{
    this->symbolType = ScopeStatementType;
}

} // namespace AnyFX

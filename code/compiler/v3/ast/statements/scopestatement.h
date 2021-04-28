#pragma once
//------------------------------------------------------------------------------
/**
    Scope, can hold both statements and variable declarations

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "statement.h"
#include <vector>
namespace AnyFX
{

struct ScopeStatement : public Statement
{
    /// constructor
    ScopeStatement(const std::vector<Symbol*>& contents);

    std::vector<Symbol*> statements;
};

} // namespace AnyFX

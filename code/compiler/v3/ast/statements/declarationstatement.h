#pragma once
//------------------------------------------------------------------------------
/**
    Variable declaration

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "statement.h"
#include "ast/expressions/expression.h"
#include <vector>
namespace AnyFX
{

struct DeclarationStatement : public Statement
{
    /// constructor
    DeclarationStatement(const std::string& type, const std::string& name, const std::vector<std::string>& qualifiers, Expression* initializer);

    std::string type;
    std::string name;
    std::vector<std::string> qualifiers;
    Expression* initializer;
};

} // namespace AnyFX

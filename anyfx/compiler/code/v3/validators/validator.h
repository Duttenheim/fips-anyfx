#pragma once
//------------------------------------------------------------------------------
/**
    The validator performs type checking and other validation.
    It provides a set of function pointers for validation, which the implementations bind

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "ast/symbol.h"
#include <vector>
namespace AnyFX
{

struct Compiler;
struct Validator
{

    /// validate
    virtual bool Validate(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);

    /// validate function
    virtual bool ValidateFunction();

};

} // namespace AnyFX

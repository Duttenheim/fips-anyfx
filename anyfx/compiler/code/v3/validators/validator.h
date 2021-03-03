#pragma once
//------------------------------------------------------------------------------
/**
    The validator performs type checking and other validation.
    It provides a set of function pointers for validation, which the implementations bind

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <hash_map>
#include "symbol.h"
namespace AnyFX
{

class Validator
{
public:

    /// validate
    virtual bool Validate(Symbol* symbol, std::vector<std::string>& errors);

    /// validate function
    virtual bool ValidateFunction();


private:

};

} // namespace AnyFX

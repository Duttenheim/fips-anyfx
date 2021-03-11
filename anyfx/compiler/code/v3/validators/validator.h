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
    virtual bool Validate(Compiler* compiler, const std::vector<Symbol*>& symbols, std::vector<std::string>& errors);


    /// validate blendstate
    virtual bool ValidateBlendState(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);
    /// validate compound resource
    virtual bool ValidateCompoundResource(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);
    /// validate function
    virtual bool ValidateFunction(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);
    /// validate program
    virtual bool ValidateProgram(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);
    /// validate render state
    virtual bool ValidateRenderState(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);
    /// validate structure 
    virtual bool ValidateStructure(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);
    /// validate typed resource
    virtual bool ValidateVariable(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);

};

} // namespace AnyFX

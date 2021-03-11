//------------------------------------------------------------------------------
//  @file spirvvalidator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "spirvvalidator.h"
namespace AnyFX 
{

//------------------------------------------------------------------------------
/**
*/
SPIRVValidator::SPIRVValidator(const SourceLanguage& lang)
    : sourceLanguage(lang)
{
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateBlendState(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateCompoundResource(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateFunction(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateProgram(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateRenderState(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateStructure(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateVariable(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors)
{
    return false;
}

} // namespace AnyFX
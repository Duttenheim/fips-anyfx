//------------------------------------------------------------------------------
//  @file generator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "generator.h"
#include "ast/symbol.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
bool 
Generator::Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
void 
Generator::GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
}

//------------------------------------------------------------------------------
/**
*/
void 
Generator::GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
}

//------------------------------------------------------------------------------
/**
*/
void 
Generator::GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument)
{
}

} // namespace AnyFX

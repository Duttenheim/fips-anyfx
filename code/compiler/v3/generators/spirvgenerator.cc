//------------------------------------------------------------------------------
//  @file spirvgenerator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "spirvgenerator.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVGenerator::Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
void 
SPIRVGenerator::GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
}

//------------------------------------------------------------------------------
/**
*/
void 
SPIRVGenerator::GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
}

//------------------------------------------------------------------------------
/**
*/
void 
SPIRVGenerator::GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument)
{
}

} // namespace AnyFX

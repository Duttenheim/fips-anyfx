//------------------------------------------------------------------------------
//  @file spirvgenerator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "spirvgenerator.h"
#include "v3/ast/program.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVGenerator::Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc)
{
    Program::__Resolved* progResolved = static_cast<Program::__Resolved*>(program->resolved);
    for (auto it : progResolved->programMappings)
    {
        // for each shader, generate code and use it as a binary output
        if (it.first >= Program::__Resolved::VertexShader && it.first <= Program::__Resolved::RayIntersectionShader)
        {
            std::string code;
            code.append("; Magic:     0x07230203 (SPIR-V)\n");
            code.append("; Version:   0x00010000 (Version: 1.0.0)\n");
            code.append("; Generator: 0x00080001 (AnyFX; 1)\n");
            code.append("OpCapability Shader\n");
        }
    }
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

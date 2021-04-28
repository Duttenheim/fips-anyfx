#pragma once
//------------------------------------------------------------------------------
/**
    Compiler backend for SPIRV code generation. This is not to be confused
    with compiling for Vulkan, this generator is meant for generating 
    pure SPIRV output from the AST.

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "generator.h"
namespace AnyFX
{

class SPIRVGenerator : public Generator
{
public:

    /// generate SPIRV output
    bool Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc) override;

    /// generate function
    void GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode) override;
    /// generate structure 
    void GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode) override;
    /// generate variable
    void GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument) override;
};

} // namespace AnyFX

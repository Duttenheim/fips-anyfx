#pragma once
//------------------------------------------------------------------------------
/**
    Compiler backend for GLSL code generation

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "generator.h"
namespace AnyFX
{

class GLSLGenerator : public Generator
{
public:

    enum LanguageFeatureSet
    {
        OpenGLFeatureSet,
        VulkanFeatureSet
    };

    /// constructor
    GLSLGenerator(LanguageFeatureSet featureSet);

    /// generate GLSL output
    bool Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc) override;

    /// generate function
    void GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode) override;
    /// generate structure 
    void GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode) override;
    /// generate variable
    void GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument) override;

    LanguageFeatureSet featureSet;
};

} // namespace AnyFX

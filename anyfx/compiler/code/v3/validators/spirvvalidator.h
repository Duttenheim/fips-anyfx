#pragma once
//------------------------------------------------------------------------------
/**
    The SPIRV validator validates shader output according to Vulkan/SPIRV rules

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "validator.h"
namespace AnyFX
{

class SPIRVValidator : public Validator
{
public:
    enum SourceLanguage
    {
        GLSL,
        HLSL
    };

    /// constructor, takes source language to select mode for glslang
    SPIRVValidator(const SourceLanguage& lang);

    /// validate blendstate
    bool ValidateBlendState(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors) override;
    /// validate compound resource
    bool ValidateCompoundResource(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors) override;
    /// validate function
    bool ValidateFunction(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors) override;
    /// validate program
    bool ValidateProgram(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors) override;
    /// validate render state
    bool ValidateRenderState(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors) override;
    /// validate structure 
    bool ValidateStructure(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors) override;
    /// validate typed resource
    bool ValidateVariable(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors) override;

    SourceLanguage sourceLanguage;

};

} // namespace AnyFX

#pragma once
//------------------------------------------------------------------------------
/**
    The SPIRV validator validates shader output according to Vulkan/SPIRV rules

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "validator.h"
#include <set>
#include <map>
namespace AnyFX
{

class SPIRVValidator : public Validator
{
public:
    enum class SourceLanguage : uint8_t
    {
        GLSL,
        HLSL
    };

    /// constructor, takes source language to select mode for glslang
    SPIRVValidator(const SourceLanguage& lang);

    /// validate blendstate
    bool ValidateBlendState(Compiler* compiler, Symbol* symbol) override;
    /// validate compound resource
    bool ValidateCompoundVariable(Compiler* compiler, Symbol* symbol) override;
    /// validate function
    bool ValidateFunction(Compiler* compiler, Symbol* symbol) override;
    /// validate program
    bool ValidateProgram(Compiler* compiler, Symbol* symbol) override;
    /// validate render state
    bool ValidateRenderState(Compiler* compiler, Symbol* symbol) override;
    /// validate structure 
    bool ValidateStructure(Compiler* compiler, Symbol* symbol) override;
    /// validate typed resource
    bool ValidateVariable(Compiler* compiler, Symbol* symbol) override;

    SourceLanguage sourceLanguage;

    std::set<std::string> allowedReadWriteTextureAttributes;
    std::set<std::string> allowedTextureAttributes;
    std::set<std::string> allowedSamplerAttributes;
    std::set<std::string> allowedScalarAttributes;

    std::set<std::string> allowedSamplerStateAttributes;
    std::set<std::string> allowedConstantBufferAttributes;
    std::set<std::string> allowedStorageBufferAttributes;

    std::set<std::string> allowedFunctionAttributes;

    std::set<std::string> allowedParameterAttributes;
};

} // namespace AnyFX

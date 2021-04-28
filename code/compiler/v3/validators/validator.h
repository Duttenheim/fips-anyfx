#pragma once
//------------------------------------------------------------------------------
/**
    The validator performs type checking and other validation.
    It provides a set of function pointers for validation, which the implementations bind

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "ast/symbol.h"
#include <set>
#include <map>
#include <vector>
namespace AnyFX
{

struct Compiler;
struct Validator
{
    /// constructor
    Validator();

    /// resolve
    bool Resolve(Compiler* compiler, const std::vector<Symbol*>& symbols);

    /// resolve blend state
    bool ResolveSamplerState(Compiler* compiler, Symbol* symbol);
    /// resolve function
    bool ResolveFunction(Compiler* compiler, Symbol* symbol);
    /// resolve program
    bool ResolveProgram(Compiler* compiler, Symbol* symbol);
    /// resolve render state
    bool ResolveRenderState(Compiler* compiler, Symbol* symbol);
    /// resolve structure 
    bool ResolveStructure(Compiler* compiler, Symbol* symbol);
    /// resolve variable
    bool ResolveVariable(Compiler* compiler, Symbol* symbol);

    /// validate
    bool Validate(Compiler* compiler, const std::vector<Symbol*>& symbols);

    /// validate blendstate
    bool ValidateSamplerState(Compiler* compiler, Symbol* symbol);
    /// validate function
    bool ValidateFunction(Compiler* compiler, Symbol* symbol);
    /// validate program
    bool ValidateProgram(Compiler* compiler, Symbol* symbol);
    /// validate render state
    bool ValidateRenderState(Compiler* compiler, Symbol* symbol);
    /// validate structure 
    bool ValidateStructure(Compiler* compiler, Symbol* symbol);
    /// validate typed resource
    bool ValidateVariable(Compiler* compiler, Symbol* symbol);

    std::set<std::string> allowedReadWriteTextureAttributes;
    std::set<std::string> allowedTextureAttributes;
    std::set<std::string> allowedSampledTextureAttributes;
    std::set<std::string> allowedSamplerAttributes;
    std::set<std::string> allowedScalarAttributes;

    std::set<std::string> allowedSamplerStateAttributes;
    std::set<std::string> allowedConstantBufferAttributes;
    std::set<std::string> allowedStorageBufferAttributes;

    std::set<std::string> allowedFunctionAttributes;

    std::set<std::string> allowedParameterAttributes;

    std::set<std::string> allowedStructureAttributes;

    enum ResourceIndexingMode
    {
        ResourceIndexingByType,    // resource indexing is by type, so each constant buffer, storage buffer, texture and sampler have their own set of indexes
        ResourceIndexingByGroup    // resource indexing is by group, so each resource in a group get an incremental index
    };
    ResourceIndexingMode resourceIndexingMode;
    std::map<uint32_t, uint32_t> resourceIndexCounter;
    uint8_t defaultGroup;


    uint32_t inParameterIndexCounter;
    uint32_t outParameterIndexCounter;
};

} // namespace AnyFX

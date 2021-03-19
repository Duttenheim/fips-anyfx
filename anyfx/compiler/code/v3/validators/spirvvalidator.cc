//------------------------------------------------------------------------------
//  @file spirvvalidator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "spirvvalidator.h"
#include <map>
#include "ast/blendstate.h"
#include "ast/compoundvariable.h"
#include "ast/function.h"
#include "ast/program.h"
#include "ast/renderstate.h"
#include "ast/structure.h"
#include "ast/variable.h"
#include "compiler.h"
#include "util.h"
namespace AnyFX 
{


//------------------------------------------------------------------------------
/**
*/
std::set<std::string> readWriteTextureFormatsFloat =
{
    "rgba32f", "rgba16f", "rg32f", "rg16f", "r11f_g11f_b10f",
    "r32f", "r16f", "rgba16", "rgb10_a2", "rgba8", "rg16", "rg8",
    "r16", "r8", "rgba16_snorm", "rgba8_snorm", "rg16_snorm", "rg8_snorm",
    "r16_snorm", "r8_snorm"
};
std::set<std::string> readWriteTextureFormatsInt =
{
    "rgba32i", "rgba16i", "rgba8i", "rg32i", "rg16i", "rg8i",
    "r32i", "r16i", "r8i"
};
std::set<std::string> readWriteTextureFormatsUint =
{
    "rgba32u", "rgba16u", "rgb10_a2u", "rgba8u", "rg32u",
    "rg16u", "rg8u", "r32u", "r16u", "r8u"
};

std::set<std::string> readWriteTextureAccessFlags =
{
    "read", "write", "readwrite", "read_write", "atomic", "volatile"
};

std::set<std::string> readWriteTextureQualifiers =
{
    "group", "binding"
};

std::set<std::string> textureQualifiers =
{
    "group", "binding"
};

std::set<std::string> samplerQualifiers =
{
    "group", "binding"
};

std::set<std::string> scalarQualifiers =
{
    "const", "group_shared",
};

std::set<std::string> samplerStateQualifiers =
{
    "group", "binding"
};

std::set<std::string> constantBufferQualifiers =
{
    "group", "binding"
};

std::set<std::string> storageBufferAccessFlags =
{
    "read", "write", "readwrite", "read_write", "atomic", "volatile"
};

std::set<std::string> storageBufferQualifiers =
{
    "group", "binding"
};

std::set<std::string> functionAttributes =
{
    "local_size_x", "localsizex"
    , "local_size_y", "localsizey"
    , "local_size_z", "localsizez"
    , "earlydepth", "early_depth"
    , "shader"
};

std::set<std::string> parameterAccessFlags =
{
    "in", "out", "inout"
};

std::set<std::string> parameterQualifiers =
{
    "const"
};

//------------------------------------------------------------------------------
/**
*/
SPIRVValidator::SPIRVValidator(const SourceLanguage& lang)
    : sourceLanguage(lang)
{
    this->allowedReadWriteTextureAttributes.insert(readWriteTextureFormatsFloat.begin(), readWriteTextureFormatsFloat.end());
    this->allowedReadWriteTextureAttributes.insert(readWriteTextureFormatsInt.begin(), readWriteTextureFormatsInt.end());
    this->allowedReadWriteTextureAttributes.insert(readWriteTextureFormatsUint.begin(), readWriteTextureFormatsUint.end());
    this->allowedReadWriteTextureAttributes.insert(readWriteTextureAccessFlags.begin(), readWriteTextureAccessFlags.end());
    this->allowedReadWriteTextureAttributes.insert(readWriteTextureQualifiers.begin(), readWriteTextureQualifiers.end());

    this->allowedTextureAttributes.insert(textureQualifiers.begin(), textureQualifiers.end());

    this->allowedSamplerAttributes.insert(samplerQualifiers.begin(), samplerQualifiers.end());

    this->allowedScalarAttributes.insert(scalarQualifiers.begin(), scalarQualifiers.end());

    this->allowedSamplerAttributes.insert(samplerStateQualifiers.begin(), samplerStateQualifiers.end());

    this->allowedConstantBufferAttributes.insert(constantBufferQualifiers.begin(), constantBufferQualifiers.end());

    this->allowedStorageBufferAttributes.insert(storageBufferAccessFlags.begin(), storageBufferAccessFlags.end());
    this->allowedStorageBufferAttributes.insert(storageBufferQualifiers.begin(), storageBufferQualifiers.end());

    this->allowedFunctionAttributes.insert(functionAttributes.begin(), functionAttributes.end());

    this->allowedParameterAttributes.insert(parameterQualifiers.begin(), parameterQualifiers.end());
    this->allowedParameterAttributes.insert(parameterAccessFlags.begin(), parameterAccessFlags.end());
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateBlendState(Compiler* compiler, Symbol* symbol)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateCompoundVariable(Compiler* compiler, Symbol* symbol)
{
    CompoundVariable* var = static_cast<CompoundVariable*>(symbol);

    if (stringToTypeLookup.find(var->type) == stringToTypeLookup.end())
    {
        compiler->Error(AnyFX::Format("Invalid type '%s'", var->type.c_str()), symbol);
        return false;
    }

    // resolve type
    Variable::__Resolved* typeResolved = static_cast<Variable::__Resolved*>(var->resolved);
    typeResolved->type = Variable::__Resolved::StringToType(var->type);
    if (typeResolved->type == Variable::__Resolved::InvalidType)
    {
        compiler->Error(AnyFX::Format("INTERNAL COMPILER ERROR, type '%s' does not have a numerical mapping", var->type.c_str()), symbol);
        return false;
    }

    // figure out set of allowed attributes
    std::set<std::string>* allowedAttributesSet = nullptr;
    if (samplerStateTypeLookup.find(var->type) != samplerStateTypeLookup.end())
        allowedAttributesSet = &this->allowedSamplerStateAttributes;
    else if (constantBufferTypeLookup.find(var->type) != constantBufferTypeLookup.end())
        allowedAttributesSet = &this->allowedConstantBufferAttributes;
    else if (storageBufferTypeLookup.find(var->type) != storageBufferTypeLookup.end())
        allowedAttributesSet = &this->allowedStorageBufferAttributes;

    // run attribute validation
    for (const Attribute& attr : var->attributes)
    {
        if (allowedAttributesSet == nullptr || (allowedAttributesSet->find(attr.name) == allowedAttributesSet->end()))
        {
            compiler->Error(AnyFX::Format("Invalid attribute for type '%s': '%s'", var->type.c_str(), attr.name.c_str()), symbol);
            return false;
        }

        // resolve attributes, do unique single qualifiers first, then go into more complicated ones
        if (attr.name == "group")
            typeResolved->group = attr.expression->EvalUInt(compiler);
        else if (attr.name == "binding")
            typeResolved->binding = attr.expression->EvalUInt(compiler);
        else
        {
            // look for access flags if type is a storage buffer
            if (typeResolved->type == Variable::__Resolved::StorageBuffer)
            {
                auto it = storageBufferAccessFlags.find(attr.name);
                if (it != storageBufferAccessFlags.end())
                    typeResolved->accessFlags = Variable::__Resolved::StringToAccessFlags(attr.name);
            }
        }
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateFunction(Compiler* compiler, Symbol* symbol)
{
    Function* fun = static_cast<Function*>(symbol);
    Function::__Resolved* typeResolved = static_cast<Function::__Resolved*>(fun->resolved);
    typeResolved->returnType = Variable::__Resolved::StringToType(fun->returnType);
    if (typeResolved->returnType == Variable::__Resolved::InvalidType)
    {
        compiler->Error(AnyFX::Format("INTERNAL COMPILER ERROR, type '%s' does not have a numerical mapping", fun->returnType.c_str()), symbol);
        return false;
    }

    // run attribute validation
    for (const Attribute& attr : fun->attributes)
    {
        if (this->allowedFunctionAttributes.find(attr.name) == this->allowedFunctionAttributes.end())
        {
            compiler->Error(AnyFX::Format("Invalid attribute for function: '%s'", attr.name.c_str()), symbol);
            return false;
        }

        if (attr.name == "localsizex" || attr.name == "local_size_x")
            typeResolved->computeShaderWorkGroupSize[0] = attr.expression->EvalUInt(compiler);
        else if (attr.name == "localsizey" || attr.name == "local_size_y")
            typeResolved->computeShaderWorkGroupSize[1] = attr.expression->EvalUInt(compiler);
        else if (attr.name == "localsizez" || attr.name == "local_size_z")
            typeResolved->computeShaderWorkGroupSize[2] = attr.expression->EvalUInt(compiler);
        else if (attr.name == "earlydepth" || attr.name == "early_depth")
            typeResolved->earlyDepth = true;
        else if (attr.name == "shader")
            compiler->AddSymbol(fun->name, fun); // if shader, add symbol as just the name without signature
    }

    // run validation on parameters
    for (Variable* var : fun->parameters)
    {
        Variable::__Resolved* typeResolved = static_cast<Variable::__Resolved*>(fun->resolved);
        typeResolved->isParameter = true;
        this->ValidateVariable(compiler, var);
    }

    return true;
}



//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateProgram(Compiler* compiler, Symbol* symbol)
{
    Program* prog = static_cast<Program*>(symbol);
    Program::__Resolved* typeResolved = static_cast<Program::__Resolved*>(prog->resolved);

    for (const Program::Entry& entry : prog->entries)
    {
        Program::__Resolved::ProgramEntryType entryType = Program::__Resolved::StringToEntryType(entry.name);
        if (entryType == Program::__Resolved::ProgramEntryType::InvalidEntryType)
        {
            compiler->Error(AnyFX::Format("INTERNAL COMPILER ERROR, program entry '%s' does not have a mapping", entry.name.c_str()), symbol);
            return false;
        }

        // get the symbol for this entry
        Symbol* value = compiler->GetSymbol(entry.value);
        if (value == nullptr)
        {
            compiler->Error(AnyFX::Format("Symbol '%s' not defined", entry.value.c_str()), symbol);
            return false;
        }

        auto it = typeResolved->programMappings.find(entryType);
        if (it != typeResolved->programMappings.end())
        {
            compiler->Error(AnyFX::Format("Program already binds '%s'", entry.name.c_str()), symbol);
            return false;
        }

        typeResolved->programMappings[entryType] = symbol;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateRenderState(Compiler* compiler, Symbol* symbol)
{
    RenderState* var = static_cast<RenderState*>(symbol);
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateStructure(Compiler* compiler, Symbol* symbol)
{
    Structure* var = static_cast<Structure*>(symbol);
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
SPIRVValidator::ValidateVariable(Compiler* compiler, Symbol* symbol)
{
    Variable* var = static_cast<Variable*>(symbol);
    Variable::__Resolved* typeResolved = static_cast<Variable::__Resolved*>(var->resolved);

    if (stringToTypeLookup.find(var->type) == stringToTypeLookup.end())
    {
        compiler->Error(AnyFX::Format("Invalid type '%s'", var->type.c_str()), symbol);
        return false;
    }

    // resolve type
    typeResolved->type = Variable::__Resolved::StringToType(var->type);
    if (typeResolved->type == Variable::__Resolved::InvalidType)
    {
        compiler->Error(AnyFX::Format("INTERNAL COMPILER ERROR, type '%s' does not have a numerical mapping", var->type.c_str()), symbol);
        return false;
    }

    // figure out set of allowed attributes
    std::set<std::string>* allowedAttributesSet = nullptr;
    if (typeResolved->isParameter)
        allowedAttributesSet = &this->allowedParameterAttributes;
    else
    {
        if (readWriteTextureTypeLookup.find(var->type) != readWriteTextureTypeLookup.end())
            allowedAttributesSet = &this->allowedReadWriteTextureAttributes;
        else if (textureTypeLookup.find(var->type) != textureTypeLookup.end())
            allowedAttributesSet = &this->allowedTextureAttributes;
        else if (samplerTypeLookup.find(var->type) != samplerTypeLookup.end())
            allowedAttributesSet = &this->allowedSamplerAttributes;
        else if (scalarTypeLookup.find(var->type) != scalarTypeLookup.end())
            allowedAttributesSet = &this->allowedScalarAttributes;
    }
    

    // run attribute validation
    for (const Attribute& attr : var->attributes)
    {
        if (allowedAttributesSet == nullptr || (allowedAttributesSet->find(attr.name) == allowedAttributesSet->end()))
        {
            compiler->Error(AnyFX::Format("Invalid attribute for type '%s': '%s'", var->type.c_str(), attr.name.c_str()), symbol);
            return false;
        }

        // resolve attributes
        if (attr.name == "group")
            typeResolved->group = attr.expression->EvalUInt(compiler);
        else if (attr.name == "binding")
            typeResolved->binding = attr.expression->EvalUInt(compiler);
        else if (attr.name == "const")
            typeResolved->isConst = true;
        else
        {
            // more complicated lookups
            auto it = readWriteTextureAccessFlags.find(attr.name);
            if (it != readWriteTextureAccessFlags.end())
                typeResolved->accessFlags = Variable::__Resolved::StringToAccessFlags(attr.name);
        }

        // resolve parameter attributes
        if (typeResolved->isParameter)
        {
            if (parameterAccessFlags.find(attr.name) != parameterAccessFlags.end())
                typeResolved->parameterFlags = Variable::__Resolved::StringToParameterFlags(attr.name);
        }
    }

    // setup initializers
    if (!var->initializers.empty())
    {
        // only allow initializers on parameters or const variables
        if (!typeResolved->isConst || typeResolved->isParameter)
        {
            compiler->Error(AnyFX::Format("Initializer can only be used on 'const' qualifier variables or function parameters"), symbol);
            return false;
        }

        uint32_t typeComponents = Variable::__Resolved::TypeToComponentCount(typeResolved->type);

        // reduce type to single component
        const Variable::__Resolved::Type singleComponentType = Variable::__Resolved::TypeToSingleComponent(typeResolved->type);
        if (
            singleComponentType != Variable::__Resolved::Float
            || singleComponentType != Variable::__Resolved::Int
            || singleComponentType != Variable::__Resolved::UInt
            || singleComponentType != Variable::__Resolved::Bool)
        {
            compiler->Error(AnyFX::Format("Initializer only accepts components as floats, ints, uints or bools"), symbol);
            return false;
        }

        // run through initializers and evaluate value expressions
        for (auto& initializer : var->initializers)
        {
            if (initializer.size() != typeComponents)
            {
                compiler->Error(AnyFX::Format("Initializer expected %d initializers but got %d", typeComponents, initializer.size()), symbol);
                return false;
            }

            std::vector<Variable::__Resolved::InitializerUnion> values;
            for (auto& expr : initializer)
            {
                Variable::__Resolved::InitializerUnion value;
                switch (singleComponentType)
                {
                case Variable::__Resolved::Float:
                    value.f = expr->EvalFloat(compiler);
                    break;
                case Variable::__Resolved::Int:
                    value.i = expr->EvalInt(compiler);
                    break;
                case Variable::__Resolved::UInt:
                    value.u = expr->EvalUInt(compiler);
                    break;
                case Variable::__Resolved::Bool:
                    value.b = expr->EvalBool(compiler);
                    break;
                default:
                    compiler->Error(AnyFX::Format("INTERNAL COMPILER ERROR did not catch type '%s' as an invalid array initializer type", var->type), symbol);
                    return false;
                }
                values.push_back(value);
            }
            typeResolved->initializers.push_back(values);
        }
    }

    return true;
}

} // namespace AnyFX
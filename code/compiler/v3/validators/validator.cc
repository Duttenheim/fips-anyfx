//------------------------------------------------------------------------------
//  @file validator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "validator.h"
#include "ast/alias.h"
#include "ast/samplerstate.h"
#include "ast/function.h"
#include "ast/program.h"
#include "ast/renderstate.h"
#include "ast/structure.h"
#include "ast/variable.h"

#include "ast/expressions/binaryexpression.h"
#include "ast/expressions/commaexpression.h"
#include "ast/expressions/arrayindexexpression.h"
#include "ast/expressions/symbolexpression.h"
#include "ast/expressions/callexpression.h"
#include "ast/expressions/ternaryexpression.h"
#include "ast/expressions/initializerexpression.h"
#include "ast/expressions/accessexpression.h"
#include "ast/expressions/unaryexpression.h"

#include "ast/statements/breakstatement.h"
#include "ast/statements/continuestatement.h"
#include "ast/statements/expressionstatement.h"
#include "ast/statements/forstatement.h"
#include "ast/statements/ifstatement.h"
#include "ast/statements/returnstatement.h"
#include "ast/statements/scopestatement.h"
#include "ast/statements/switchstatement.h"
#include "ast/statements/whilestatement.h"

#include "compiler.h"
#include "util.h"
#include <algorithm>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
std::set<std::string> readWriteAccessFlags =
{
    "read", "write", "read_write", "atomic", "volatile"
};

std::set<std::string> readWriteTextureQualifiers =
{
    "group", "binding"
};

std::set<std::string> textureQualifiers =
{
    "group", "binding"
};

std::set<std::string> sampledTextureQualifiers =
{
    "group", "binding"
};

std::set<std::string> scalarQualifiers =
{
    "const", "group_shared",
};

std::set<std::string> samplerQualifiers =
{
    "group", "binding"
};

std::set<std::string> constantBufferQualifiers =
{
    "group", "binding"
};

std::set<std::string> storageBufferAccessFlags =
{
    "read", "write", "read_write", "atomic", "volatile"
};

std::set<std::string> storageBufferQualifiers =
{
    "group", "binding"
};

std::set<std::string> functionAttributes =
{
    "local_size_x", "local_size_y", "local_size_z", "early_depth"
    , "input_vertices", "max_output_vertices", "winding"
    , "topology", "patch_type", "patch_size", "partition",
    "prototype"
};

std::set<std::string> parameterAccessFlags =
{
    "in", "out", "in_out"
};

std::set<std::string> parameterQualifiers =
{
    "patch", "no_interpolate", "no_perspective", "binding", "pixel_origin"
};

std::set<std::string> structureQualifiers =
{
    "group", "binding", "push"
};

std::set<std::string> pixelShaderInputQualifiers =
{
    "binding", "no_interpolate", "no_perspective", "pixel_origin"
};

std::set<std::string> hullOutputQualifiers =
{
    "patch", "domain"
};

std::set<std::string> domainInputQualifiers =
{
    "binding", "patch"
};

std::set<std::string> attributesRequiringEvaluation =
{
    "binding", "group", "local_size_x", "local_size_y", "local_size_z"
    , "input_vertices", "max_output_vertices", "winding"
    , "topology", "patch_type", "patch_size", "partition"
};

std::set<std::string> pointerQualifiers =
{
    "uniform", "mutable", "read", "write", "read_write", "atomic", "volatile"
};

//------------------------------------------------------------------------------
/**
*/
Validator::Validator() 
    : resourceIndexingMode(ResourceIndexingByGroup)
    , defaultGroup(0)
{
    this->allowedReadWriteTextureAttributes.insert(readWriteAccessFlags.begin(), readWriteAccessFlags.end());
    this->allowedReadWriteTextureAttributes.insert(readWriteTextureQualifiers.begin(), readWriteTextureQualifiers.end());

    // add formats
    for (auto it : Variable::stringToFormats)
    {
        this->allowedReadWriteTextureAttributes.insert(it.first);
    }

    this->allowedTextureAttributes.insert(textureQualifiers.begin(), textureQualifiers.end());
    this->allowedSampledTextureAttributes.insert(sampledTextureQualifiers.begin(), sampledTextureQualifiers.end());
    this->allowedScalarAttributes.insert(scalarQualifiers.begin(), scalarQualifiers.end());
    this->allowedSamplerAttributes.insert(samplerQualifiers.begin(), samplerQualifiers.end());
    this->allowedConstantBufferAttributes.insert(constantBufferQualifiers.begin(), constantBufferQualifiers.end());
    this->allowedStorageBufferAttributes.insert(storageBufferAccessFlags.begin(), storageBufferAccessFlags.end());
    this->allowedStorageBufferAttributes.insert(storageBufferQualifiers.begin(), storageBufferQualifiers.end());
    this->allowedPointerAttributes.insert(pointerQualifiers.begin(), pointerQualifiers.end());
    this->allowedPointerAttributes.insert(readWriteAccessFlags.begin(), readWriteAccessFlags.end());

    this->allowedFunctionAttributes.insert(functionAttributes.begin(), functionAttributes.end());

    this->allowedParameterAttributes.insert(parameterQualifiers.begin(), parameterQualifiers.end());
    this->allowedParameterAttributes.insert(parameterAccessFlags.begin(), parameterAccessFlags.end());
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::Resolve(Compiler* compiler, Symbol* symbol)
{
    switch (symbol->symbolType)
    {
    case Symbol::SymbolType::FunctionType:
        return this->ResolveFunction(compiler, symbol);
        break;
    case Symbol::SymbolType::AliasType:
        return this->ResolveAlias(compiler, symbol);
        break;
    case Symbol::SymbolType::ProgramType:
        return this->ResolveProgram(compiler, symbol);
        break;
    case Symbol::SymbolType::RenderStateType:
        return this->ResolveRenderState(compiler, symbol);
        break;
    case Symbol::SymbolType::StructureType:
        return this->ResolveStructure(compiler, symbol);
        break;
    case Symbol::SymbolType::VariableType:
        return this->ResolveVariable(compiler, symbol);
        break;
    case Symbol::SymbolType::SamplerStateType:
        return this->ResolveSamplerState(compiler, symbol);
        break;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ResolveAlias(Compiler* compiler, Symbol* symbol)
{
    Alias* alias = static_cast<Alias*>(symbol);
    Symbol* sym = compiler->GetSymbol(alias->type);
    if (sym == nullptr)
    {
        compiler->UnrecognizedTypeError(alias->type, alias);
        return false;
    }
    return compiler->AddSymbol(alias->name, sym);
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ResolveType(Compiler* compiler, Symbol* symbol)
{
    Type* type = static_cast<Type*>(symbol);
    bool ret = true;

    for (Variable* var : type->members)
    {
        Variable::__Resolved* res = static_cast<Variable::__Resolved*>(var->resolved);
        res->typeSymbol = static_cast<Type*>(compiler->GetSymbol(var->type.name));
    }

    for (Variable* var : type->staticMembers)
    {
        Variable::__Resolved* res = static_cast<Variable::__Resolved*>(var->resolved);
        res->typeSymbol = static_cast<Type*>(compiler->GetSymbol(var->type.name));
    }

    for (Function* fun : type->methods)
    {
        Function::__Resolved* res = static_cast<Function::__Resolved*>(fun->resolved);
        res->returnTypeSymbol = static_cast<Type*>(compiler->GetSymbol(fun->returnType.name));
    }

    for (Function* fun : type->staticMethods)
    {
        Function::__Resolved* res = static_cast<Function::__Resolved*>(fun->resolved);
        res->returnTypeSymbol = static_cast<Type*>(compiler->GetSymbol(fun->returnType.name));
    }

    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool
Validator::ResolveSamplerState(Compiler* compiler, Symbol* symbol)
{
    SamplerState* state = static_cast<SamplerState*>(symbol);
    SamplerState::__Resolved* stateResolved = static_cast<SamplerState::__Resolved*>(state->resolved);

    if (!compiler->AddSymbol(symbol->name, symbol))
        return false;

    for (Expression* entry : state->entries)
    {
        const BinaryExpression* assignEntry = static_cast<const BinaryExpression*>(entry);

        if (assignEntry->symbolType != Symbol::BinaryExpressionType || assignEntry->op != '=')
        {
            compiler->Error(Format("Sampler state entry '%s' must be an assignment expression", assignEntry->EvalString(compiler).c_str()), assignEntry);
            return false;
        }

        // check if lhs is binary expression, then check if array access
        if (assignEntry->left->symbolType != Symbol::SymbolExpressionType)
        {
            compiler->Error(Format("Sampler state entry '%s' must be a valid identifier", assignEntry->left->EvalString(compiler).c_str()), assignEntry->left);
            return false;
        }

        std::string entry = assignEntry->left->EvalString(compiler);
        SamplerState::__Resolved::SamplerStateEntryType entryType = SamplerState::__Resolved::StringToEntryType(entry.c_str());
        if (entryType == SamplerState::__Resolved::InvalidSamplerStateEntryType)
        {
            compiler->Error(Format("Invalid sampler state entry '%s'", entry.c_str()), assignEntry);
            return false;
        }

        std::string stringValue;
        AddressMode addressMode;
        float f;
        bool b;

        Filter filter;
        switch (entryType)
        {
        case SamplerState::__Resolved::AllAddressType:
            stringValue = assignEntry->right->EvalString(compiler);
            addressMode = SamplerState::__Resolved::StringToAddressMode(stringValue);
            stateResolved->addressU = stateResolved->addressV = stateResolved->addressW = addressMode;
            if (stateResolved->addressU == InvalidAddressMode)
            {
                compiler->Error(Format("Invalid address mode '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::AddressUType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->addressU = SamplerState::__Resolved::StringToAddressMode(stringValue);
            if (stateResolved->addressU == InvalidAddressMode)
            {
                compiler->Error(Format("Invalid address mode '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::AddressVType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->addressV = SamplerState::__Resolved::StringToAddressMode(assignEntry->right->EvalString(compiler));
            if (stateResolved->addressV == InvalidAddressMode)
            {
                compiler->Error(Format("Invalid address mode '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::AddressWType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->addressW = SamplerState::__Resolved::StringToAddressMode(assignEntry->right->EvalString(compiler));
            if (stateResolved->addressW == InvalidAddressMode)
            {
                compiler->Error(Format("Invalid address mode '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::AllFilterType:
            stringValue = assignEntry->right->EvalString(compiler);
            filter = SamplerState::__Resolved::StringToFilter(assignEntry->right->EvalString(compiler));
            stateResolved->minFilter = stateResolved->magFilter = stateResolved->mipFilter = filter;
            if (stateResolved->minFilter == InvalidFilter)
            {
                compiler->Error(Format("Invalid filter '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::MinFilterType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->minFilter = SamplerState::__Resolved::StringToFilter(assignEntry->right->EvalString(compiler));
            if (stateResolved->minFilter == InvalidFilter)
            {
                compiler->Error(Format("Invalid filter '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::MagFilterType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->magFilter = SamplerState::__Resolved::StringToFilter(assignEntry->right->EvalString(compiler));
            if (stateResolved->magFilter == InvalidFilter)
            {
                compiler->Error(Format("Invalid filter '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::MipFilterType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->mipFilter = SamplerState::__Resolved::StringToFilter(assignEntry->right->EvalString(compiler));
            if (stateResolved->mipFilter == InvalidFilter)
            {
                compiler->Error(Format("Invalid filter '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::MipLodBiasType:
            if (!assignEntry->right->EvalFloat(compiler, f))
            {
                compiler->Error(Format("Value '%s' has to be a compile time float constant", stringValue.c_str()), assignEntry);
                return false;
            }
            stateResolved->mipLodBias = f;
            break;
        case SamplerState::__Resolved::AnisotropicFlagType:
            if (!assignEntry->right->EvalBool(compiler, b))
            {
                compiler->Error(Format("Value '%s' has to be a compile time bool constant", stringValue.c_str()), assignEntry);
                return false;
            }
            stateResolved->anisotropicEnabled = b;
            break;
        case SamplerState::__Resolved::MaxAnisotropyType:
            if (!assignEntry->right->EvalFloat(compiler, f))
            {
                compiler->Error(Format("Value '%s' has to be a compile time float constant", stringValue.c_str()), assignEntry);
                return false;
            }
            stateResolved->maxAnisotropy = f;
            break;
        case SamplerState::__Resolved::CompareFlagType:
            if (!assignEntry->right->EvalBool(compiler, b))
            {
                compiler->Error(Format("Value '%s' has to be a compile time bool constant", stringValue.c_str()), assignEntry);
                return false;
            }
            stateResolved->compareSamplerEnabled = b;
            break;
        case SamplerState::__Resolved::CompareModeType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->compareMode = State::__Resolved::StringToCompareMode(assignEntry->right->EvalString(compiler));
            if (stateResolved->compareMode == InvalidCompareMode)
            {
                compiler->Error(Format("Invalid comparison mode '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::MinLodType:
            if (!assignEntry->right->EvalFloat(compiler, f))
            {
                compiler->Error(Format("Value '%s' has to be a compile time float constant", stringValue.c_str()), assignEntry);
                return false;
            }
            stateResolved->minLod = f;
            break;
        case SamplerState::__Resolved::MaxLodType:
            if (!assignEntry->right->EvalFloat(compiler, f))
            {
                compiler->Error(Format("Value '%s' has to be a compile time float constant", stringValue.c_str()), assignEntry);
                return false;
            }
            stateResolved->maxLod = f;
            break;
        case SamplerState::__Resolved::BorderColorType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->borderColor = SamplerState::__Resolved::StringToBorderColor(assignEntry->right->EvalString(compiler));
            if (stateResolved->borderColor == InvalidBorderColor)
            {
                compiler->Error(Format("Invalid border '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::UnnormalizedSamplingType:
            if (!assignEntry->right->EvalBool(compiler, b))
            {
                compiler->Error(Format("Value '%s' has to be a compile time bool constant", stringValue.c_str()), assignEntry);
                return false;
            }
            stateResolved->unnormalizedSamplingEnabled = b;
            break;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ResolveFunction(Compiler* compiler, Symbol* symbol)
{
    Function* fun = static_cast<Function*>(symbol);
    Function::__Resolved* funResolved = static_cast<Function::__Resolved*>(fun->resolved);

    // setup our variables and attributes as sets
    std::string paramList;
    for (Variable* var : fun->parameters)
    {
        // add comma if not first argument
        if (var != fun->parameters.front())
            paramList.append(",");

        // finally add type
        paramList.append(var->type.name);
    }

    std::string attributeList;
    bool isPrototype = false;

    // make a set of all attributes
    for (const Attribute& attr : fun->attributes)
    {
        std::string attrAsString;
        if (!attr.ToString(compiler, attrAsString))
        {
            compiler->Error(Format("Attribute '%s' can not be evaluated to a compile time value", attr.name.c_str()), symbol);
            return false;
        }
        attributeList.append(Format("%s ", attrAsString.c_str()));
        if (attr.name == "prototype")
            isPrototype = true;
    }

    // format function with all attributes and parameters
    std::string functionFormatted = Format("%s%s %s(%s)", attributeList.c_str(), fun->returnType.name.c_str(), fun->name.c_str(), paramList.c_str());
    fun->signature = functionFormatted;

    // if prototype, add as an ordinary symbol
    if (isPrototype)
    {
        if (!compiler->AddSymbol(fun->name, fun, false))
            return false;
    }
    else
    {
        // find functions with similar name
        std::vector<Symbol*> matchingFunctions = compiler->GetSymbols(fun->name);
        for (Symbol* matchingFunction : matchingFunctions)
        {
            Function* otherFunction = static_cast<Function*>(matchingFunction);

            if (!fun->IsCompatible(otherFunction, false))
                continue;

            // if all checks prove these functions are identical, throw error
            if (fun->returnType == otherFunction->returnType)
                compiler->Error(Format("Function '%s' can not be overloaded because it only differs by return type when trying to overload previous definition at %s(%d)", functionFormatted.c_str(), otherFunction->location.file.c_str(), otherFunction->location.line), fun);
            else
                compiler->Error(Format("Function '%s' redefinition, previous definition at %s(%d)", functionFormatted.c_str(), otherFunction->location.file.c_str(), otherFunction->location.line), fun);

            return false;
        }
    }

    // if we didn't fault, add the symbol
    if (!compiler->AddSymbol(fun->name, fun, true))
        return false;

    Type* type = (Type*)compiler->GetSymbol(fun->returnType.name);
    if (type == nullptr)
    {
        compiler->UnrecognizedTypeError(fun->returnType.name, fun);
        return false;
    }
    funResolved->returnTypeSymbol = type;

    // run attribute validation
    for (const Attribute& attr : fun->attributes)
    {
        if (!set_contains(this->allowedFunctionAttributes, attr.name))
        {
            compiler->Error(Format("Invalid attribute for function: '%s'", attr.name.c_str()), symbol);
            return false;
        }

        // make sure attribute has expression
        if (attr.expression == nullptr && set_contains(attributesRequiringEvaluation, attr.name))
        {
            compiler->Error(Format("Attribute '%s' requires value but none provided", attr.name.c_str()), symbol);
            return false;
        }

        if (attr.name == "local_size_x")
            if (!attr.expression->EvalUInt(compiler, funResolved->computeShaderWorkGroupSize[0]))
            {
                compiler->Error(Format("Value '%s' has to be a compile time uint constant", attr.name.c_str()), symbol);
                return false;
            }
        else if (attr.name == "local_size_y")
            if (!attr.expression->EvalUInt(compiler, funResolved->computeShaderWorkGroupSize[1]))
            {
                compiler->Error(Format("Value '%s' has to be a compile time uint constant", attr.name.c_str()), symbol);
                return false;
            }
        else if (attr.name == "local_size_z")
            if (!attr.expression->EvalUInt(compiler, funResolved->computeShaderWorkGroupSize[2]))
            {
                compiler->Error(Format("Value '%s' has to be a compile time uint constant", attr.name.c_str()), symbol);
                return false;
            }
        else if (attr.name == "early_depth")
            funResolved->earlyDepth = true;
        else if (attr.name == "invocations")
            if (!attr.expression->EvalUInt(compiler, funResolved->invocations))
            {
                compiler->Error(Format("Value '%s' has to be a compile time uint constant", attr.name.c_str()), symbol);
                return false;
            }
        else if (attr.name == "max_output_vertices")
            if (!attr.expression->EvalUInt(compiler, funResolved->maxOutputVertices))
            {
                compiler->Error(Format("Value '%s' has to be a compile time uint constant", attr.name.c_str()), symbol);
                return false;
            }
        else if (attr.name == "patch_size")
            if (!attr.expression->EvalUInt(compiler, funResolved->patchSize))
            {
                compiler->Error(Format("Value '%s' has to be a compile time uint constant", attr.name.c_str()), symbol);
                return false;
            }
        else if (attr.name == "winding")
        {
            std::string str = attr.expression->EvalString(compiler);
            funResolved->windingOrder = Function::__Resolved::WindingOrderFromString(str);
            if (funResolved->windingOrder == Function::__Resolved::InvalidWindingOrder)
            {
                compiler->Error(Format("Attribute 'winding' supports values: cw/clockwise, ccw/counter_clockwise, but got '%s'", str.c_str()), symbol);
                return false;
            }
        }
        else if (attr.name == "input_topology")
        {
            std::string str = attr.expression->EvalString(compiler);
            funResolved->inputPrimitiveTopology = Function::__Resolved::PrimitiveTopologyFromString(str);
            if (funResolved->inputPrimitiveTopology == Function::__Resolved::InvalidPrimitiveTopology)
            {
                compiler->Error(Format("Attribute 'input_topology' supports values: points, lines, lines_adjacency, triangles, triangles_adjacency, but got '%s'", str.c_str()), symbol);
                return false;
            }
        }
        else if (attr.name == "output_topology")
        {
            std::string str = attr.expression->EvalString(compiler);
            funResolved->outputPrimitiveTopology = Function::__Resolved::PrimitiveTopologyFromString(str);
            if (funResolved->outputPrimitiveTopology == Function::__Resolved::InvalidPrimitiveTopology 
                || funResolved->outputPrimitiveTopology == Function::__Resolved::LinesAdjacency
                || funResolved->outputPrimitiveTopology == Function::__Resolved::TrianglesAdjacency)
            {
                compiler->Error(Format("Attribute 'output_topology' supports values: points, lines, triangles, but got '%s'", str.c_str()), symbol);
                return false;
            }
        }
        else if (attr.name == "patch_type")
        {
            std::string str = attr.expression->EvalString(compiler);
            funResolved->patchType = Function::__Resolved::PatchTypeFromString(str);
            if (funResolved->patchType == Function::__Resolved::InvalidPatchType)
            {
                compiler->Error(Format("Attribute 'patch_type' supports values: isolines, triangles, quads, but got '%s'", str.c_str()), symbol);
                return false;
            }
        }
        else if (attr.name == "partition")
        {
            std::string str = attr.expression->EvalString(compiler);
            funResolved->partitionMethod = Function::__Resolved::PartitionMethodFromString(str);
            if (funResolved->partitionMethod == Function::__Resolved::InvalidPartitionMethod)
            {
                compiler->Error(Format("Attribute 'partition' supports values: steps/integer, even/fract_even, odd/fract_odd, but got '%s'", str.c_str()), symbol);
                return false;
            }
        }
        else if (attr.name == "prototype")
        {
            if (fun->hasBody)
            {
                compiler->Error(Format("Prototype function '%s' may not have a function body", fun->name.c_str()), symbol);
                return false;
            }
            funResolved->isPrototype = true;
        }
        else if (attr.name == "pixel_origin")
        {
            std::string str = attr.expression->EvalString(compiler);
            funResolved->pixelOrigin = Function::__Resolved::PixelOriginFromString(str);
            if (funResolved->pixelOrigin == Function::__Resolved::InvalidPixelOrigin)
            {
                compiler->Error(Format("Attribute 'pixel_origin' supports values: lower/lower_left, upper/upper_left, center, but got '%s'", str.c_str()), symbol);
                return false;
            }
        }
    }

    // validate attributes
    if (!funResolved->isShader)
    {
        if (funResolved->earlyDepth)
        {
            compiler->Error("'early_depth' is only allowed on functions with the 'shader' qualifier", symbol);
            return false;
        }

        if (
            funResolved->computeShaderWorkGroupSize[0] > 1
            || funResolved->computeShaderWorkGroupSize[1] > 1
            || funResolved->computeShaderWorkGroupSize[2] > 1
            )
        {
            compiler->Error("'local_size_(x/y/z)' is only allowed on functions with the 'shader' qualifier", symbol);
            return false;
        }
    }

    // before resolving variables (as parameters), reset in and out bindings
    this->inParameterIndexCounter = 0;
    this->outParameterIndexCounter = 0;

    // push scope for function parameters and body
    compiler->PushScope(Compiler::Scope::Type::Local, fun);

    // run validation on parameters
    for (Variable* var : fun->parameters)
    {
        Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
        varResolved->usageBits.flags.isParameter = true;
        this->ResolveVariable(compiler, var);
    }

    // validate function body
    if (fun->ast != nullptr
        && !this->ValidateStatement(compiler, fun->ast))
    {
        compiler->PopScope();
        return false;
    }

    // pop scope
    compiler->PopScope(); 

    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ResolveProgram(Compiler* compiler, Symbol* symbol)
{
    Program* prog = static_cast<Program*>(symbol);
    Program::__Resolved* progResolved = static_cast<Program::__Resolved*>(prog->resolved);

    for (const Expression* entry : prog->entries)
    {
        const BinaryExpression* assignEntry = static_cast<const BinaryExpression*>(entry);
        if (entry->symbolType != Symbol::BinaryExpressionType || assignEntry->left->symbolType == Symbol::ArrayIndexExpressionType)
        {
            compiler->Error(Format("Program entry '%s' must be an assignment expression", assignEntry->EvalString(compiler).c_str()), symbol);
            return false;
        }

        // only allow symbol assignments
        if (assignEntry->right->symbolType != Symbol::SymbolExpressionType)
        {
            compiler->Error(Format("Program binds '%s' but it is not an identifier", assignEntry->EvalString(compiler).c_str()), symbol);
            return false;
        }

        std::string entry = assignEntry->left->EvalString(compiler);
        Program::__Resolved::ProgramEntryType entryType = Program::__Resolved::StringToEntryType(entry);
        if (entryType == Program::__Resolved::InvalidProgramEntryType)
        {
            // get all functions responding to this function
            Function* functionStub = static_cast<Function*>(compiler->GetSymbol(entry));

            // check that we actually got a symbol
            if (functionStub == nullptr)
            {
                compiler->UnrecognizedTypeError(entry, symbol);
                return false;
            }

            // check that it's actually a function
            if (functionStub->symbolType != Symbol::FunctionType)
            {
                compiler->Error(Format("Symbol '%s' is not a recognized function", entry.c_str()), symbol);
                return false;
            }

            // next up, function to assign
            std::string functionName;
            if (!assignEntry->right->EvalSymbol(compiler, functionName))
            {
                compiler->Error(Format("Expected symbol, but got '%s'", entry.c_str()), symbol);
                return false;
            }
            std::vector<Symbol*> functions = compiler->GetSymbols(functionName);

            // again, check if not null
            if (functions.empty())
            {
                compiler->UnrecognizedTypeError(functionName, symbol);
                return false;
            }

            bool matched = false;
            for (Symbol* sym : functions)
            {
                Function* func = static_cast<Function*>(sym);

                // and check that it's actually a function
                if (func->symbolType != Symbol::FunctionType)
                {
                    compiler->Error(Format("Symbol '%s' is not a recognized function", functionName.c_str()), symbol);
                    return false;
                }

                if (functionStub->IsCompatible(func, true))
                {
                    // if compatible, this is our match
                    progResolved->functionOverrides[functionStub] = func;
                    matched = true;
                }
            }

            if (!matched)
            {
                std::string candidates;
                for (Symbol* sym : functions)
                {
                    Function* func = static_cast<Function*>(sym);
                    candidates.append(func->signature);
                    if (sym != functions.back())
                        candidates.append(",\n");
                }
                compiler->Error(Format("Function prototype '%s' can not bind function '%s', possible candidates: \n%s", functionStub->name.c_str(), assignEntry->right->EvalString(compiler).c_str(), candidates.c_str()), symbol);
                return false;
            }
        }
        else
        {
            // get the symbol for this entry
            std::string sym;
            if (!assignEntry->right->EvalSymbol(compiler, sym))
            {
                compiler->Error(Format("Entry '%s' has to be a symbol", entry.c_str()), symbol);
                return false;
            }
            Symbol* value = compiler->GetSymbol(sym);
            if (value->symbolType != Symbol::SymbolType::FunctionType)
            {
                compiler->Error(Format("Program binds symbol '%s' to '%s' but it is not a recognized function", sym.c_str(), assignEntry->name.c_str()), assignEntry);
                return false;
            }

            progResolved->programMappings[entryType] = value;

            switch (entryType)
            {
            case Program::__Resolved::VertexShader:
                progResolved->usage.flags.hasVertexShader = true;
                break;
            case Program::__Resolved::HullShader:
                progResolved->usage.flags.hasHullShader = true;
                break;
            case Program::__Resolved::DomainShader:
                progResolved->usage.flags.hasDomainShader = true;
                break;
            case Program::__Resolved::GeometryShader:
                progResolved->usage.flags.hasGeometryShader = true;
                break;
            case Program::__Resolved::PixelShader:
                progResolved->usage.flags.hasPixelShader = true;
                break;
            case Program::__Resolved::ComputeShader:
                progResolved->usage.flags.hasComputeShader = true;
                break;
            case Program::__Resolved::RayGenerationShader:
                progResolved->usage.flags.hasRayGenerationShader = true;
                break;
            case Program::__Resolved::RayMissShader:
                progResolved->usage.flags.hasRayMissShader = true;
                break;
            case Program::__Resolved::RayHitShader:
                progResolved->usage.flags.hasRayHitShader = true;
                break;
            case Program::__Resolved::RayClosestHitShader:
                progResolved->usage.flags.hasRayClosestHitShader = true;
                break;
            case Program::__Resolved::RayAnyHitShader:
                progResolved->usage.flags.hasRayAnyHitShader = true;
                break;
            case Program::__Resolved::RayIntersectionShader:
                progResolved->usage.flags.hasRayIntersectionShader = true;
                break;
            case Program::__Resolved::RenderState:
                progResolved->usage.flags.hasRenderState = true;
                break;
            }

            // if shader, value must be a function
            if (entryType >= Program::__Resolved::ProgramEntryType::VertexShader
                && entryType <= Program::__Resolved::ProgramEntryType::RayIntersectionShader)
            {
                Function* fun = static_cast<Function*>(value);
                Function::__Resolved* funResolved = static_cast<Function::__Resolved*>(value->resolved);

                switch (entryType)
                {
                case Program::__Resolved::ProgramEntryType::VertexShader:
                    funResolved->shaderUsage.flags.isVertexShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::HullShader:
                    funResolved->shaderUsage.flags.isHullShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::DomainShader:
                    funResolved->shaderUsage.flags.isDomainShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::GeometryShader:
                    funResolved->shaderUsage.flags.isGeometryShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::PixelShader:
                    funResolved->shaderUsage.flags.isPixelShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::ComputeShader:
                    funResolved->shaderUsage.flags.isComputeShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::RayGenerationShader:
                    funResolved->shaderUsage.flags.isRayGenerationShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::RayMissShader:
                    funResolved->shaderUsage.flags.isRayMissShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::RayHitShader:
                    funResolved->shaderUsage.flags.isRayHitShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::RayClosestHitShader:
                    funResolved->shaderUsage.flags.isRayClosestHitShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::RayAnyHitShader:
                    funResolved->shaderUsage.flags.isRayAnyHitShader = true;
                    break;
                case Program::__Resolved::ProgramEntryType::RayIntersectionShader:
                    funResolved->shaderUsage.flags.isRayIntersectionShader = true;
                    break;
                }

                // when we've set these flags, run function validation to make sure it's properly formatted
                if (!this->ValidateFunction(compiler, fun))
                    return false;
            }
            else
            {
                if (value->symbolType != Symbol::SymbolType::RenderStateType)
                {
                    compiler->Error(Format("Program binds symbol '%s' as RenderState but it is not a recognized render_state symbol", assignEntry->name.c_str(), assignEntry->name.c_str()), assignEntry);
                    return false;
                }
            }
        }
    }

    if (!this->ValidateProgram(compiler, prog))
        return false;

    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ResolveRenderState(Compiler* compiler, Symbol* symbol)
{
    RenderState* state = static_cast<RenderState*>(symbol);
    RenderState::__Resolved* stateResolved = static_cast<RenderState::__Resolved*>(state->resolved);

    if (!compiler->AddSymbol(symbol->name, symbol))
        return false;

    for (const Expression* entry : state->entries)
    {
        const BinaryExpression* assignEntry = static_cast<const BinaryExpression*>(entry);

        if (assignEntry->symbolType != Symbol::BinaryExpressionType || assignEntry->op != '=')
        {
            compiler->Error(Format("Render state entry '%s' not an assignment statement", assignEntry->EvalString(compiler).c_str()), entry);
            return false;
        }

        std::string entry;

        // if left is binary, then validate it is an array expression
        if (assignEntry->left->symbolType == Symbol::ArrayIndexExpressionType)
        {
            const ArrayIndexExpression* lhs = static_cast<const ArrayIndexExpression*>(assignEntry->left);
            if (lhs->right->symbolType != Symbol::IntExpressionType
                && lhs->right->symbolType != Symbol::UIntExpressionType)
            {
                compiler->Error(Format("Render state entry '%s' may be either identifier or array expression", assignEntry->EvalString(compiler).c_str()), assignEntry);
                return false;
            }
            if (lhs->left->symbolType != Symbol::SymbolExpressionType)
            {
                compiler->Error(Format("Render state array entry '%s' must be a valid identifier", lhs->left->EvalString(compiler).c_str()), assignEntry);
                return false;
            }
            entry = lhs->left->EvalString(compiler);
        }
        else
        {
            if (assignEntry->left->symbolType != Symbol::SymbolExpressionType)
            {
                compiler->Error(Format("Render state entry '%s' must be a valid identifier", assignEntry->left->EvalString(compiler).c_str()), assignEntry);
                return false;
            }
            entry = assignEntry->left->EvalString(compiler);
        }

        RenderState::__Resolved::RenderStateEntryType entryType = RenderState::__Resolved::StringToEntryType(entry);
        if (entryType == RenderState::__Resolved::InvalidRenderStateEntryType)
        {
            compiler->Error(Format("Invalid render state entry '%s'", entry.c_str()), assignEntry);
            return false;
        }

        if (entryType >= RenderState::__Resolved::BlendEnabledType && entryType <= RenderState::__Resolved::ColorComponentMaskType)
        {
            uint32_t index = -1;
            if (assignEntry->left->symbolType == Symbol::ArrayIndexExpressionType)
            {
                const ArrayIndexExpression* lhs = static_cast<const ArrayIndexExpression*>(assignEntry->left);
                if (lhs->right->symbolType != Symbol::IntExpressionType
                    && lhs->right->symbolType != Symbol::UIntExpressionType)
                {
                    compiler->Error(Format("Blend state entry '%s' must supply an array index", lhs->EvalString(compiler).c_str()), assignEntry);
                    return false;
                }
                if (!lhs->right->EvalUInt(compiler, index))
                {
                    compiler->Error(Format("Blend state entry '%s' array index must be a compile time constant", lhs->EvalString(compiler).c_str()), assignEntry);
                    return false;
                }
            }

            if (index >= 8)
            {
                compiler->Error(Format("Only 8 blend states are allowed"), assignEntry);
                return false;
            }

            std::string str;
            switch (entryType)
            {
            case RenderState::__Resolved::BlendEnabledType:
                if (!assignEntry->right->EvalBool(compiler, stateResolved->blendStates[index].blendEnabled))
                {
                    compiler->Error(Format("Blend state entry '%s' must evaluate to a compile time bool", entry.c_str()), assignEntry);
                    return false;
                }
                break;
            case RenderState::__Resolved::SourceBlendColorFactorType:
                str = assignEntry->right->EvalString(compiler);
                stateResolved->blendStates[index].sourceColorBlendFactor = RenderState::__Resolved::StringToBlendFactor(str);
                break;
            case RenderState::__Resolved::DestinationBlendColorFactorType:
                str = assignEntry->right->EvalString(compiler);
                stateResolved->blendStates[index].destinationColorBlendFactor = RenderState::__Resolved::StringToBlendFactor(str);
                break;
            case RenderState::__Resolved::SourceBlendAlphaFactorType:
                str = assignEntry->right->EvalString(compiler);
                stateResolved->blendStates[index].sourceAlphaBlendFactor = RenderState::__Resolved::StringToBlendFactor(str);
                break;
            case RenderState::__Resolved::DestinationBlendAlphaFactorType:
                str = assignEntry->right->EvalString(compiler);
                stateResolved->blendStates[index].destinationAlphaBlendFactor = RenderState::__Resolved::StringToBlendFactor(str);
                break;

                
            }
        }
        else if (assignEntry->left->symbolType == Symbol::ArrayIndexExpressionType)
        {
            compiler->Error(Format("Render state entry '%s' is an array", assignEntry->name.c_str()), assignEntry);
            return false;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ResolveStructure(Compiler* compiler, Symbol* symbol)
{
    Structure* struc = static_cast<Structure*>(symbol);
    Structure::__Resolved* strucResolved = static_cast<Structure::__Resolved*>(struc->resolved);

    if (!compiler->AddSymbol(symbol->name, symbol))
        return false;

    // run attribute validation
    for (const Attribute& attr : struc->attributes)
    {
        if (!set_contains(this->allowedStructureAttributes, attr.name))
        {
            compiler->Error(Format("Invalid attribute for structure '%s': '%s'", struc->name.c_str(), attr.name.c_str()), symbol);
            return false;
        }

        if (set_contains(structureQualifiers, attr.name))
        {
            if (attr.name == "group")
                if (!attr.expression->EvalUInt(compiler, strucResolved->group))
                {
                    compiler->Error(Format("group qualifier has to evaluate to a compile time uint", attr.name.c_str()), symbol);
                    return false;
                }
            else if (attr.name == "binding")
                if (!attr.expression->EvalUInt(compiler, strucResolved->binding))
                {
                    compiler->Error(Format("binding qualifier has to evaluate to a compile time uint", attr.name.c_str()), symbol);
                    return false;
                }
            else if (attr.name == "push")
            {
                strucResolved->usageFlags.flags.isPush = true;
            }
        }
    }

    // push scope for struct but not for storage and constant buffers
    Compiler::TypeScope scope(compiler, struc);

    // validate members
    for (Variable* var : struc->members)
    {
        Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
        varResolved->usageBits.flags.isStructMember = true;
        this->ResolveVariable(compiler, var);
    }

    return true;
}


//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ResolveVariable(Compiler* compiler, Symbol* symbol)
{
    Variable* var = static_cast<Variable*>(symbol);
    Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);

    Type* type = (Type*)compiler->GetSymbol(var->type.name);
    if (type == nullptr)
    {
        compiler->UnrecognizedTypeError(var->type.name, symbol);
        return false;
    }
    varResolved->typeSymbol = type;
    var->type.name = type->name;        // because we can do an alias lookup, this value might change
    varResolved->type = var->type;

    // struct members may only be scalars
    if (varResolved->usageBits.flags.isStructMember && type->category != Type::ScalarCategory)
    {
        compiler->Error(Format("Member '%s' may only be scalar type if member of a struct", varResolved->name.c_str()), symbol);
        return false;
    }

    // resolve array type and names
    if (var->nameExpression != nullptr)
    {
        Expression* expr = var->nameExpression;


loop_variable:
        // make sure binary expression is valid
        if (expr->symbolType == Symbol::BinaryExpressionType)
        {
            BinaryExpression* binaryExpression = static_cast<BinaryExpression*>(expr);
            if (binaryExpression->op != '=')
            {
                compiler->Error(Format("Expected assignment expression but got operator '%s'", FourCCToString(binaryExpression->op).c_str()), expr);
                return false;
            }
            if (!this->ValidateExpression(compiler, binaryExpression->right))
                return false;
            varResolved->value = binaryExpression->right;
            expr = binaryExpression->left;
            goto loop_variable;
        }
        else if (expr->symbolType == Symbol::ArrayIndexExpressionType)
        {
            // array expression means we have an array level
            ArrayIndexExpression* arrayIndexExpression = static_cast<ArrayIndexExpression*>(expr);
            varResolved->type.modifiers.push_back(Type::FullType::Modifier::ArrayLevel);
            if (arrayIndexExpression->right != nullptr)
            {
                uint32_t size;
                if (!arrayIndexExpression->right->EvalUInt(compiler, size))
                    return false;

                if (size == 0)
                {
                    compiler->Error(Format("Array size must be non-zero"), arrayIndexExpression);
                    return false;
                }
                varResolved->type.modifierValues.push_back(size);
            }
            else
            {
                varResolved->type.modifierValues.push_back(Type::FullType::UNSIZED_ARRAY);
            }

            // if array access is missing size, value is uninitialized and it's not in the global scope, throw error
            if (arrayIndexExpression->right == nullptr
                && varResolved->value == nullptr
                && !compiler->IsScopeGlobal())
            {
                compiler->Error(Format("Invalid array declaration, size can't be determined"), expr);
                return false;
            }

            expr = arrayIndexExpression->left;
            goto loop_variable;
        }
        else if (expr->symbolType == Symbol::UnaryExpressionType)
        {
            // unary expression can only mean pointer
            UnaryExpression* unaryExpression = static_cast<UnaryExpression*>(expr);
            if (unaryExpression->op == StringToFourCC("*"))
            {
                varResolved->type.modifiers.push_back(Type::FullType::Modifier::PointerLevel);
                varResolved->type.modifierValues.push_back(0);
                varResolved->pointerLevels++;
            }
            else
            {
                compiler->Error(Format("Expected pointer indirection '*' but got '%s'", FourCCToString(unaryExpression->op).c_str()), expr);
                return false;
            }
            expr = unaryExpression->expr;
            goto loop_variable;
        }
        else if (expr->symbolType == Symbol::SymbolExpressionType)
        {
            // the last stage is to parse just the name
            if (!expr->EvalSymbol(compiler, varResolved->name))
            {
                compiler->Error(Format("Expected symbol expression"), symbol);
                return false;
            }

            if (!compiler->AddSymbol(varResolved->name, var))
                return false;
        }
        else
        {
            compiler->Error(Format("Expected either identifier, assignment or pointer expression"), symbol);
            return false;
        }
    }

    // If struct member, only allow sized arrays and no initializers
    if (varResolved->usageBits.flags.isStructMember)
    {
        if (varResolved->value != nullptr)
        {
            compiler->Error(Format("'struct' members may not have initializers"), symbol);
            return false;
        }

        for (uint32_t size : varResolved->type.modifierValues)
            if (size == 0)
            {
                compiler->Error(Format("'struct' array member can't be of dynamic size"), symbol);
                return false;
            }
    }

    // figure out set of allowed attributes
    std::set<std::string>* allowedAttributesSet = nullptr;
    if (varResolved->usageBits.flags.isStructMember)
        allowedAttributesSet = nullptr;
    else if (varResolved->usageBits.flags.isParameter)
        allowedAttributesSet = &this->allowedParameterAttributes;
    else
    {
        if (type->category == Type::ReadWriteTextureCategory)
            allowedAttributesSet = &this->allowedReadWriteTextureAttributes;
        else if (type->category == Type::TextureCategory)
            allowedAttributesSet = &this->allowedTextureAttributes;
        else if (type->category == Type::SampledTextureCategory)
            allowedAttributesSet = &this->allowedSampledTextureAttributes;
        else if (type->category == Type::ScalarCategory)
            allowedAttributesSet = &this->allowedScalarAttributes;
        else if (type->category == Type::SamplerCategory)
            allowedAttributesSet = &this->allowedSamplerAttributes;
        else if (type->category == Type::UserTypeCategory
                && varResolved->pointerLevels > 0)
        {
            allowedAttributesSet = &this->allowedPointerAttributes;
        }
    }

    // run attribute validation
    for (const Attribute& attr : var->attributes)
    {
        if (allowedAttributesSet == nullptr || (!set_contains(*allowedAttributesSet, attr.name)))
        {
            compiler->Error(Format("Invalid attribute for type '%s': '%s'", varResolved->name.c_str(), attr.name.c_str()), symbol);
            return false;
        }

        // resolve attributes
        if (attr.name == "group")
        {
            if (!attr.expression->EvalUInt(compiler, varResolved->group))
            {
                compiler->Error(Format("Expected compile time constant for 'group' qualifier"), symbol);
                return false;
            }
        }
        else if (attr.name == "binding")
        {
            if (!attr.expression->EvalUInt(compiler, varResolved->binding))
            {
                compiler->Error(Format("Expected compile time constant for 'binding' qualifier"), symbol);
                return false;
            }
        }
        else if (attr.name == "const")
            varResolved->usageBits.flags.isConst = true;
        else if (attr.name == "uniform")
        {
            varResolved->usageBits.flags.isUniform = true;
            if (varResolved->usageBits.flags.isMutable)
            {
                compiler->Error(Format("Variable declared as 'mutable' can't also be 'uniform'"), symbol);
                return false;
            }
        }
        else if (attr.name == "mutable")
        {
            varResolved->usageBits.flags.isMutable = true;
            if (varResolved->usageBits.flags.isUniform)
            {
                compiler->Error(Format("Variable declared as 'uniform' can't also be 'mutable'"), symbol);
                return false;
            }
        }
        else if (attr.name == "group_shared")
            varResolved->usageBits.flags.isGroupShared = true;
        else
        {
            // more complicated lookups
            if (set_contains(readWriteAccessFlags, attr.name))
            {
                if (attr.name == "read")
                    varResolved->accessBits.flags.readAccess = true;
                else if (attr.name == "write")
                    varResolved->accessBits.flags.writeAccess = true;
                else if (attr.name == "read_write")
                    varResolved->accessBits.flags.readAccess = varResolved->accessBits.flags.writeAccess = true;
                else if (attr.name == "atomic")
                    varResolved->accessBits.flags.atomicAccess = true;
                else if (attr.name == "volatile")
                    varResolved->accessBits.flags.volatileAccess = true;
            }
        }

        if (set_contains(parameterAccessFlags, attr.name))
        {
            if (attr.name == "in")
                varResolved->parameterBits.flags.isIn = true;
            else if (attr.name == "out")
                varResolved->parameterBits.flags.isOut = true;
            else if (attr.name == "in_out")
                varResolved->parameterBits.flags.isIn = varResolved->parameterBits.flags.isOut = true;
        }
        else if (set_contains(parameterQualifiers, attr.name))
        {
            if (attr.name == "patch")
                varResolved->parameterBits.flags.isPatch = true;
            else if (attr.name == "no_perspective")
                varResolved->parameterBits.flags.isNoPerspective = true;
            else if (attr.name == "no_interpolate")
                varResolved->parameterBits.flags.isNoInterpolate = true;
            else if (attr.name == "binding")
                if (!attr.expression->EvalUInt(compiler, varResolved->binding))
                {
                    compiler->Error(Format("Expected compile time constant for 'binding' qualifier"), symbol);
                    return false;
                }
        }

        // check image formats
        if (map_contains(Variable::stringToFormats, attr.name))
        {
            varResolved->imageFormat = Variable::stringToFormats[attr.name];
        }
    }

    if (compiler->IsScopeGlobal())
    {
        if (type->category != Type::ScalarCategory)
        {
            uint16_t numArrays = 0;
            for (Type::FullType::Modifier mod : varResolved->type.modifiers)
            {
                if (mod == Type::FullType::Modifier::ArrayLevel)
                    numArrays++;
            }
            if (numArrays > 1)
            {
                compiler->Error(Format("Global variables may only be single array"), symbol);
                return false;
            }
            if (varResolved->pointerLevels > 1)
            {
                compiler->Error(Format("Global variables may only be single pointer"), symbol);
                return false;
            }

            if (type->category == Type::ReadWriteTextureCategory
                && varResolved->pointerLevels == 0)
            {
                compiler->Error(Format("Instance of 'readWriteTexture' must be pointer if in global scope"), symbol);
                return false;
            }            
            else if (type->category == Type::TextureCategory
                     && varResolved->pointerLevels == 0)
            {
                compiler->Error(Format("Instance of 'texture' must be pointer if in global scope"), symbol);
                return false;
            }
            else if (type->category == Type::SampledTextureCategory
                     && varResolved->pointerLevels == 0)
            {
                compiler->Error(Format("Instance of 'sampledTexture' must be pointer if in global scope"), symbol);
                return false;
            }
            else if (type->category == Type::SamplerCategory
                     && varResolved->pointerLevels == 0)
            {
                compiler->Error(Format("Instance of 'sampler' must be pointer if in global scope"), symbol);
                return false;
            }
            else if (type->category == Type::UserTypeCategory
                     && varResolved->pointerLevels == 0)
            {
                compiler->Error(Format("Instance of '%s' must be pointer if in global scope", type->name.c_str()), symbol);
                return false;
            }
        }
        else // scalar
        {
            if (!varResolved->usageBits.flags.isConst)
            {
                compiler->Error(Format("Non-const scalars are not allowed in global scope"), symbol);
                return false;
            }
            else if (varResolved->usageBits.flags.isConst && varResolved->value == nullptr)
            {
                // check for variable initialization criteria
                compiler->Error(Format("Variable declared as const but is never initialized"), symbol);
                return false;
            }
        }
    }
    else
    {
        if (varResolved->pointerLevels > 0)
        {
            compiler->Error(Format("Poiners are only allowed as symbols in the global scope", type->name.c_str()), symbol);
            return false;
        }
    }

    // validate types on both sides of the assignment
    if (varResolved->value != nullptr)
    {
        Type::FullType lhs = varResolved->type;
        Type::FullType rhs;
        if (!varResolved->value->EvalType(compiler, rhs))
        {
            compiler->UnrecognizedTypeError(rhs.name, symbol);
            return false;
        }

        Type* lhsType = compiler->GetSymbol<Type>(lhs.name);
        std::vector<Symbol*> assignmentOperators = lhsType->GetSymbols("operator=");
        Symbol* fun = Function::MatchOverload(compiler, assignmentOperators, { rhs });
        if (lhs != rhs
            && fun == nullptr)
        {
            compiler->Error(Format("Type '%s' can't be converted to '%s'", lhs.ToString(compiler).c_str(), rhs.ToString(compiler).c_str()), symbol);
            return false;
        }

        // Okay, so now when we're done, we'll copy over the modifier values from rhs to lhs
        varResolved->type.modifierValues = rhs.modifierValues;
    }

    // check if image formats have been resolved
    if (type->category == Type::ReadWriteTextureCategory 
        && varResolved->imageFormat == Variable::InvalidImageFormat)
    {
        compiler->Error(Format("readWriteTexture variable '%s' must provide a format qualifier", varResolved->name.c_str()), var);
        return false;
    }

    if (varResolved->usageBits.flags.isParameter)
    {
        // if parameter, resolve in and out bindings
        if (varResolved->binding == Variable::__Resolved::NOT_BOUND)
        {
            if (varResolved->parameterBits.flags.isIn)
                varResolved->inBinding = this->inParameterIndexCounter++;
            if (varResolved->parameterBits.flags.isOut)
                varResolved->outBinding = this->outParameterIndexCounter++;
        }
        else
        {
            if (varResolved->parameterBits.flags.isIn)
                this->inParameterIndexCounter = varResolved->inBinding + 1;
            if (varResolved->parameterBits.flags.isOut)
                this->outParameterIndexCounter = varResolved->outBinding + 1;
        }
    }
    else
    {
        Type::Category cat = type->category;

        // if user type and mutable or uniform, convert to either mutable or constant type
        if (cat == Type::Category::UserTypeCategory)
        {
            if (varResolved->usageBits.flags.isMutable)
                cat = Type::Category::MutableStructureCategory;
            else if (varResolved->usageBits.flags.isUniform)
                cat = Type::Category::UniformStructureCategory;

            if (varResolved->pointerLevels == 0)
            {
                compiler->Error(Format("Variable of '%s' with qualifier 'uniform' or 'mutable' must be pointer", type->name.c_str()), var);
                return false;
            }
            else if (cat == Type::Category::UserTypeCategory)
            {
                compiler->Error(Format("Variable of '%s' pointer must be either 'uniform' or 'mutable'", type->name.c_str()), var);
                return false;
            }
        }
        else
        {
            if (varResolved->usageBits.flags.isMutable)
            {
                compiler->Error(Format("Non-struct variable declared 'mutable'"), var);
                return false;
            }
            if (varResolved->usageBits.flags.isUniform)
            {
                compiler->Error(Format("Non-struct variable declared 'uniform'"), var);
                return false;
            }
        }

        // if not a parameter, assume resource (these types can't be declared inside functions)
        if (cat == Type::Category::ReadWriteTextureCategory
            || cat == Type::Category::SampledTextureCategory
            || cat == Type::Category::TextureCategory
            || cat == Type::Category::SamplerCategory
            || cat == Type::Category::InputAttachmentCategory
            || cat == Type::Category::UniformStructureCategory
            || cat == Type::Category::MutableStructureCategory)
        {
            if (varResolved->group == Variable::__Resolved::NOT_BOUND)
            {
                varResolved->group = this->defaultGroup;
            }

            if (this->resourceIndexingMode == ResourceIndexingByType)
            {
                auto it = this->resourceIndexCounter.find(cat);
                if (it == this->resourceIndexCounter.end())
                {
                    this->resourceIndexCounter[cat] = 0;
                    it = this->resourceIndexCounter.find(varResolved->group);
                }

                if (varResolved->binding == Variable::__Resolved::NOT_BOUND)
                {
                    varResolved->binding = it->second++;
                }
                else
                {
                    this->resourceIndexCounter[cat] = max(it->second, varResolved->binding + 1);
                }
            }
            else if (this->resourceIndexingMode == ResourceIndexingByGroup)
            {
                auto it = this->resourceIndexCounter.find(varResolved->group);
                if (it == this->resourceIndexCounter.end())
                {
                    this->resourceIndexCounter[varResolved->group] = 0;
                    it = this->resourceIndexCounter.find(varResolved->group);
                }

                if (varResolved->binding == Variable::__Resolved::NOT_BOUND)
                {
                    varResolved->binding = it->second++;
                }
                else
                {
                    this->resourceIndexCounter[varResolved->group] = max(it->second, varResolved->binding + 1);
                }
            }
        }

        if (cat == Type::Category::MutableStructureCategory
            || cat == Type::Category::UniformStructureCategory)
        {
            // Generate mutable/uniform variant of struct
            Structure* generatedStruct = new Structure;
            for (Variable* var : type->members)
            {
                Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
                Variable* generatedVar = new Variable;
                Variable::__Resolved* generatedVarResolved = static_cast<Variable::__Resolved*>(generatedVar->resolved);
                generatedVar->name = var->name;
                generatedVar->type = var->type;
                generatedVarResolved->usageBits = varResolved->usageBits;
                generatedVarResolved->type = varResolved->type;
                generatedVarResolved->typeSymbol = varResolved->typeSymbol;
                generatedVarResolved->name = varResolved->name;
                generatedStruct->members.push_back(generatedVar);
            }
            Structure::__Resolved* generatedStructResolved = static_cast<Structure::__Resolved*>(generatedStruct->resolved);
            generatedStruct->name = varResolved->name;
            generatedStruct->annotations = var->annotations;
            generatedStruct->location = var->location;
            generatedStructResolved->group = varResolved->group;
            generatedStructResolved->binding = varResolved->binding;
            if (cat == Type::Category::MutableStructureCategory)
                generatedStructResolved->usageFlags.flags.isMutableBuffer = true;
            else if (cat == Type::Category::UniformStructureCategory)
                generatedStructResolved->usageFlags.flags.isUniformBuffer = true;

            // Insert symbol before this one, avoiding resolving (we assume the struct and members are already valid)
            compiler->symbols.insert(compiler->symbols.begin() + compiler->symbolIterator, generatedStruct);
            compiler->symbolIterator++;
        }

        
    }

    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateFunction(Compiler* compiler, Symbol* symbol)
{
    Function* fun = static_cast<Function*>(symbol);
    Function::__Resolved* funResolved = static_cast<Function::__Resolved*>(fun->resolved);

    for (Variable* var : fun->parameters)
    {
        // if function is used for shader, validate parameters with special rules
        if (funResolved->shaderUsage.bits != 0x0)
        {
            Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
            if (varResolved->parameterBits.flags.isIn
                && varResolved->parameterBits.flags.isOut)
            {
                compiler->Error(Format("Parameter '%s' can not be both 'in' and 'out' or 'in_out' if function '%s' is used as a shader", var->name.c_str(), fun->name.c_str()), var);
                return false;
            }

            if (varResolved->parameterBits.flags.isPatch
                && !(funResolved->shaderUsage.flags.isHullShader || funResolved->shaderUsage.flags.isDomainShader))
            {
                compiler->Error(Format("Parameter '%s' can not use 'patch' if function is not being used as a HullShader/TessellationControlShader or DomainShader/TessellationEvaluationShader", var->name.c_str(), fun->name.c_str()), var);
                return false;
            }

            if (varResolved->parameterBits.flags.isNoInterpolate
                && !funResolved->shaderUsage.flags.isPixelShader)
            {
                compiler->Error(Format("Parameter '%s' can not use 'no_interpolate' if function is not being used as a PixelShader", var->name.c_str(), fun->name.c_str()), var);
                return false;
            }

            if (varResolved->parameterBits.flags.isNoPerspective
                && !funResolved->shaderUsage.flags.isPixelShader)
            {
                compiler->Error(Format("Parameter '%s' can not use 'no_perspective' if function is not being used as a PixelShader", var->name.c_str(), fun->name.c_str()), var);
                return false;
            }
        }
    }

    // validate function attribute validity
    if (funResolved->shaderUsage.flags.isPixelShader)
    {
        uint32_t numOutputs = 0;
        for (Variable* var : fun->parameters)
        {
            Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
            if (varResolved->parameterBits.flags.isOut)
                numOutputs++;
        }
        if (numOutputs == 0)
            compiler->Warning(Format("Function '%s' is used as pixel shader but produces no color output", fun->name.c_str()), symbol);
    }
    else
    {
        if (funResolved->earlyDepth)
            compiler->Warning(Format("Function '%s' has attribute 'early_depth' but is not used as a pixel shader", fun->name.c_str()), symbol);
    }

    if (funResolved->shaderUsage.flags.isHullShader)
    {
        if (funResolved->patchSize == Function::__Resolved::INVALID_SIZE)
        {
            compiler->Error(Format("Hull shader '%s' is hull/tessellation control shader but does not define 'patch_size'", fun->name.c_str()), symbol);
            return false;
        }
    }
    else
    {
        if (funResolved->patchSize != Function::__Resolved::INVALID_SIZE)
            compiler->Warning(Format("Function '%s' has attribute 'patch_size' but is not used as a HullShader/TessellationControlShader", fun->name.c_str()), symbol);
    }

    if (funResolved->shaderUsage.flags.isDomainShader)
    {
        // validate required qualifiers
        if (funResolved->patchType != Function::__Resolved::InvalidPatchType)
        {
            compiler->Warning(Format("Domain shader '%s' does not define 'patch_type' for DomainShader/TessellationEvaluationShader, defaulting to 'triangles'", fun->name.c_str()), symbol);
            funResolved->patchType = Function::__Resolved::PatchType::TrianglePatch;
        }
        if (funResolved->partitionMethod != Function::__Resolved::InvalidPartitionMethod)
        {
            compiler->Warning(Format("Domain shader '%s' does not define 'partition', defaulting to 'steps'", fun->name.c_str()), symbol);
            funResolved->partitionMethod = Function::__Resolved::PartitionMethod::IntegerSteps;
        }
    }
    else
    {
        if (funResolved->patchType != Function::__Resolved::InvalidPatchType)
            compiler->Warning(Format("Function '%s' has attribute 'patch_type' but is not used as a DomainShader/TessellationEvaluationShader", fun->name.c_str()), symbol);
        if (funResolved->partitionMethod != Function::__Resolved::InvalidPartitionMethod)
            compiler->Warning(Format("Function '%s' has attribute 'partition' but is not used as a DomainShader/TessellationEvaluationShader", fun->name.c_str()), symbol);
    }

    if (funResolved->shaderUsage.flags.isGeometryShader)
    {
        if (funResolved->maxOutputVertices == Function::__Resolved::INVALID_SIZE)
        {
            compiler->Error(Format("Geometry shader '%s' does not define 'max_output_vertices' for GeometryShader", fun->name.c_str()), symbol);
            return false;
        }
        if (funResolved->inputPrimitiveTopology == Function::__Resolved::InvalidPrimitiveTopology)
        {
            compiler->Warning(Format("Geometry shader '%s' does not define 'input_topology' for GeometryShader, defaulting to 'triangles'", fun->name.c_str()), symbol);
            funResolved->inputPrimitiveTopology = Function::__Resolved::Triangles;
        }
        if (funResolved->outputPrimitiveTopology == Function::__Resolved::InvalidPrimitiveTopology)
        {
            compiler->Warning(Format("Geometry shader '%s' does not define 'output_topology' for GeometryShader, defaulting to 'triangles'", fun->name.c_str()), symbol);
            funResolved->outputPrimitiveTopology = Function::__Resolved::Triangles;
        }
    }
    else
    {
        if (funResolved->invocations != Function::__Resolved::INVALID_SIZE)
            compiler->Warning(Format("Function '%s' has attribute 'invocations' but is not used as a GeometryShader", fun->name.c_str()), symbol);
        if (funResolved->maxOutputVertices != Function::__Resolved::INVALID_SIZE)
            compiler->Warning(Format("Function '%s' has attribute 'max_output_vertices' but is not used as a GeometryShader", fun->name.c_str()), symbol);
        if (funResolved->inputPrimitiveTopology != Function::__Resolved::InvalidPrimitiveTopology)
            compiler->Warning(Format("Function '%s' has attribute 'input_topology' but is not used as a GeometryShader", fun->name.c_str()), symbol);
        if (funResolved->outputPrimitiveTopology != Function::__Resolved::InvalidPrimitiveTopology)
            compiler->Warning(Format("Function '%s' has attribute 'output_topology' but is not used as a GeometryShader", fun->name.c_str()), symbol);
    }

    if (funResolved->shaderUsage.flags.isComputeShader)
    {
        if (funResolved->computeShaderWorkGroupSize[0] <= 0)
        {
            compiler->Error(Format("Compute shader must declare 'local_size_x' bigger than or equal to 1", fun->name.c_str()), symbol);
            return false;
        }
        if (funResolved->computeShaderWorkGroupSize[1] <= 0)
        {
            compiler->Error(Format("Compute shader must declare 'local_size_y' bigger than or equal to 1", fun->name.c_str()), symbol);
            return false;
        }
        if (funResolved->computeShaderWorkGroupSize[2] <= 0)
        {
            compiler->Error(Format("Compute shader must declare 'local_size_z' bigger than or equal to 1", fun->name.c_str()), symbol);
            return false;
        }
    }
    else
    {
        if (funResolved->computeShaderWorkGroupSize[0] > 1)
            compiler->Warning(Format("Function '%s' has attribute 'local_size_x' but is not used as a compute shader", fun->name.c_str()), symbol);
        if (funResolved->computeShaderWorkGroupSize[1] > 1)
            compiler->Warning(Format("Function '%s' has attribute 'local_size_y' but is not used as a compute shader", fun->name.c_str()), symbol);
        if (funResolved->computeShaderWorkGroupSize[2] > 1)
            compiler->Warning(Format("Function '%s' has attribute 'local_size_z' but is not used as a compute shader", fun->name.c_str()), symbol);
    }

    return true;
}

//------------------------------------------------------------------------------
/**
    First filters parameters based on in/out qualifiers, then sorts within that set
    based on either inBinding or outBinding respectively
*/
std::vector<Variable*>
SortAndFilterParameters(const std::vector<Variable*>& vars, bool in)
{
    std::vector<Variable*> ret;
    for (Variable* var : vars)
    {
        Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
        if (varResolved->parameterBits.flags.isIn && in)
            ret.push_back(var);
        else if (varResolved->parameterBits.flags.isOut && !in)
            ret.push_back(var);
    }

    // sort based on in or out binding respectively
    std::sort(ret.begin(), ret.end(), [in](Variable* a, Variable* b)
    {
        Variable::__Resolved* aResolved = static_cast<Variable::__Resolved*>(a->resolved);
        Variable::__Resolved* bResolved = static_cast<Variable::__Resolved*>(b->resolved);
        return in ? aResolved->inBinding < bResolved->inBinding : aResolved->outBinding < bResolved->outBinding;
    });
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool 
ValidateParameterSets(Compiler* compiler, Function* outFunc, Function* inFunc)
{
    std::vector<Variable*> outParams = SortAndFilterParameters(outFunc->parameters, false);
    std::vector<Variable*> inParams = SortAndFilterParameters(inFunc->parameters, true);
    size_t inIterator = 0;
    for (Variable* var : outParams)
    {
        Variable::__Resolved* outResolved = static_cast<Variable::__Resolved*>(var->resolved);
        Variable::__Resolved* inResolved = static_cast<Variable::__Resolved*>(inParams[inIterator]->resolved);

        // if bindings don't match, it means the output will be unused since the parameter sets should be sorted
        if (outResolved->outBinding != inResolved->inBinding)
        {
            compiler->Warning(Format("Unused parameter '%s' (binding %d) from shader '%s' to '%s'", var->name.c_str(), outResolved->outBinding, outFunc->name.c_str(), inFunc->name.c_str()), outFunc);
        }
        else
        {
            if (var->type != inParams[inIterator]->type)
            {
                compiler->Error(Format("Can't match types '%s' and '%s' between shader '%s' and '%s'", var->type.name.c_str(), inParams[inIterator]->type.name.c_str(), outFunc->name.c_str(), inFunc->name.c_str()), outFunc);
                return false;
            }
        }
    }

    return true;
}


//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateProgram(Compiler* compiler, Symbol* symbol)
{
    Program* prog = static_cast<Program*>(symbol);
    Program::__Resolved* progResolved = static_cast<Program::__Resolved*>(prog->resolved);

    if (progResolved->usage.flags.hasHullShader
        && !progResolved->usage.flags.hasDomainShader)
    {
        compiler->Error(Format("HullShader/TessellationControlShader is not allowed without a DomainShader/TessellationEvaluationShader"), symbol);
        return false;
    }

    if (progResolved->usage.flags.hasHullShader
        && !progResolved->usage.flags.hasVertexShader)
    {
        compiler->Error(Format("HullShader/TessellationControlShader is not allowed without a VertexShader"), symbol);
        return false;
    }

    if (progResolved->usage.flags.hasGeometryShader
        && !progResolved->usage.flags.hasVertexShader)
    {
        compiler->Error(Format("GeometryShader is not allowed without a VertexShader"), symbol);
        return false;
    }

    enum GraphicsProgramTristate
    {
        NotSet,
        IsGraphics,
        IsCompute
    };
    GraphicsProgramTristate programType = GraphicsProgramTristate::NotSet;

    // validate program setup as compute or graphics program, do it on a first-come-first-serve basis
    for (auto& it : progResolved->programMappings)
    {
        if (it.first == Program::__Resolved::ComputeShader)
        {
            if (programType == GraphicsProgramTristate::IsGraphics)
            {
                compiler->Error(Format("Invalid program setup, program already used as a graphics program, ComputeShader is not allowed"), symbol);
                return false;
            }
            programType = GraphicsProgramTristate::IsCompute;
        }
        else if (it.first == Program::__Resolved::VertexShader
            || it.first == Program::__Resolved::HullShader
            || it.first == Program::__Resolved::DomainShader
            || it.first == Program::__Resolved::GeometryShader
            || it.first == Program::__Resolved::PixelShader
            || it.first == Program::__Resolved::RayAnyHitShader
            || it.first == Program::__Resolved::RayHitShader
            || it.first == Program::__Resolved::RayIntersectionShader
            || it.first == Program::__Resolved::RayMissShader
            || it.first == Program::__Resolved::RenderState
            )
        {
            if (programType == GraphicsProgramTristate::IsCompute)
            {
                compiler->Error(Format("Invalid program setup, program already used with ComputeShader but '%s' was provided", Program::__Resolved::EntryTypeToString(it.first)), symbol);
                return false;
            }
            programType = GraphicsProgramTristate::IsGraphics;
        }
    }

    // if a part of the graphics pipeline, go through the different stages and validate them
    if (!progResolved->usage.flags.hasComputeShader)
    {
        Function* lastPrimitiveShader = nullptr;
        if (progResolved->usage.flags.hasVertexShader)
        {
            Function* vs = static_cast<Function*>(progResolved->programMappings[Program::__Resolved::VertexShader]);
            lastPrimitiveShader = vs;
        }

        if (progResolved->usage.flags.hasHullShader)
        {
            if (lastPrimitiveShader == nullptr)
            {
                compiler->Error(Format("Invalid program setup, HullShader/TessellationControlShader needs a VertexShader"), symbol);
                return false;
            }
            Function* hs = static_cast<Function*>(progResolved->programMappings[Program::__Resolved::HullShader]);
            if (!ValidateParameterSets(compiler, lastPrimitiveShader, hs))
                return false;

            lastPrimitiveShader = hs;
        }

        if (progResolved->usage.flags.hasDomainShader)
        {
            if (lastPrimitiveShader == nullptr 
                && map_contains(progResolved->programMappings, Program::__Resolved::HullShader))
            {
                compiler->Error(Format("Invalid program setup, DomainShader needs a HullShader/TessellationControlShader"), symbol);
                return false;
            }
            Function* ds = static_cast<Function*>(progResolved->programMappings[Program::__Resolved::DomainShader]);
            if (!ValidateParameterSets(compiler, lastPrimitiveShader, ds))
                return false;

            lastPrimitiveShader = ds;
        }

        if (progResolved->usage.flags.hasGeometryShader)
        {
            if (lastPrimitiveShader == nullptr)
            {
                compiler->Error(Format("Invalid program setup, GeometryShader needs either a VertexShader or a VertexShader-HullShader/TessellationControlShader-DomainShader/TessellationEvaluationShader setup"), symbol);
                return false;
            }
            Function* gs = static_cast<Function*>(progResolved->programMappings[Program::__Resolved::GeometryShader]);
            if (!ValidateParameterSets(compiler, lastPrimitiveShader, gs))
                return false;

            lastPrimitiveShader = gs;
        }

        if (progResolved->usage.flags.hasPixelShader)
        {
            if (lastPrimitiveShader == nullptr)
            {
                compiler->Error(Format("Invalid program setup, PixelShader needs either a VertexShader, a VertexShader-GeometryShader, a VertexShader-HullShader/TessellationControlShader-DomainShader/TessellationEvaluationShader or a VertexShader-HullShader/TessellationControlShader-DomainShader/TessellationEvaluationShader-GeometryShader setup"), symbol);
                return false;
            }
            Function* ps = static_cast<Function*>(progResolved->programMappings[Program::__Resolved::PixelShader]);
            if (!ValidateParameterSets(compiler, lastPrimitiveShader, ps))
                return false;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateStatement(Compiler* compiler, Statement* statement)
{
    switch (statement->symbolType)
    {
    case Symbol::BreakStatementType:
        return this->ValidateBreakStatement(compiler, statement);
    case Symbol::ContinueStatementType:
        return this->ValidateContinueStatement(compiler, statement);
    case Symbol::ExpressionStatementType:
        return this->ValidateExpressionStatement(compiler, statement);
    case Symbol::ForStatementType:
        return this->ValidateForStatement(compiler, statement);
    case Symbol::IfStatementType:
        return this->ValidateIfStatement(compiler, statement);
    case Symbol::ReturnStatementType:
        return this->ValidateReturnStatement(compiler, statement);
    case Symbol::ScopeStatementType:
        return this->ValidateScopeStatement(compiler, statement);
    case Symbol::SwitchStatementType:
        return this->ValidateSwitchStatement(compiler, statement);
    case Symbol::WhileStatementType:
        return this->ValidateWhileStatement(compiler, statement);
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateBreakStatement(Compiler* compiler, Statement* statement)
{
    Symbol* scopeOwner = compiler->GetScopeOwner();
    if (scopeOwner == nullptr
        || !(
        scopeOwner->symbolType == Symbol::ForStatementType
        || scopeOwner->symbolType == Symbol::WhileStatementType
        || scopeOwner->symbolType == Symbol::SwitchStatementType)
        )
    {
        compiler->Error(Format("Statement 'break' is only valid inside a for, while or switch statement body"), statement);
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateContinueStatement(Compiler* compiler, Statement* statement)
{
    Symbol* scopeOwner = compiler->GetScopeOwner();
    if (scopeOwner == nullptr
        || !(
        scopeOwner->symbolType == Symbol::ForStatementType
        || scopeOwner->symbolType == Symbol::WhileStatementType)
        )
    {
        compiler->Error(Format("Statement 'break' is only valid inside a for or while statement body"), statement);
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateExpressionStatement(Compiler* compiler, Statement* statement)
{
    ExpressionStatement* expr = static_cast<ExpressionStatement*>(statement);
    return this->ValidateExpression(compiler, expr->expr);
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateForStatement(Compiler* compiler, Statement* statement)
{
    ForStatement* forStatement = static_cast<ForStatement*>(statement);
    for (Symbol* declaration : forStatement->declarations)
        if (!this->ResolveVariable(compiler, declaration))
            return false;
    if (forStatement->condition != nullptr
        && !this->ValidateExpression(compiler, forStatement->condition))
        return false;
    if (forStatement->loop != nullptr
        && !this->ValidateExpression(compiler, forStatement->loop))
        return false;

    compiler->PushScope(Compiler::Scope::Type::Local, forStatement);
    if (!this->ValidateStatement(compiler, forStatement->contents))
        return false;
    compiler->PopScope();
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateIfStatement(Compiler* compiler, Statement* statement)
{
    IfStatement* ifStatement = static_cast<IfStatement*>(statement);
    if (!this->ValidateExpression(compiler, ifStatement->condition))
        return false;
    if (!this->ValidateStatement(compiler, ifStatement->ifStatement))
        return false;
    if (ifStatement->elseStatement
        && !this->ValidateStatement(compiler, ifStatement->elseStatement))
        return false;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateReturnStatement(Compiler* compiler, Statement* statement)
{
    ReturnStatement* returnStatement = static_cast<ReturnStatement*>(statement);
    if (!this->ValidateExpression(compiler, returnStatement->returnValue))
        return false;
    Symbol* scopeOwner = compiler->GetScopeOwner();
    if (scopeOwner == nullptr
        || scopeOwner->symbolType != Symbol::FunctionType)
    {
        compiler->Error(Format("Statement 'return' is only valid inside function body"), statement);
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateScopeStatement(Compiler* compiler, Statement* statement)
{
    compiler->PushScope(Compiler::Scope::Type::Local);

    ScopeStatement* scopeStatement = static_cast<ScopeStatement*>(statement);
    for (Symbol* stat : scopeStatement->statements)
    {
        if (stat->symbolType == Symbol::VariableType)
        {
            if (!this->ResolveVariable(compiler, stat))
                return false;
        }
        else
        {
            if (!this->ValidateStatement(compiler, static_cast<Statement*>(stat)))
                return false;
        }
    }

    compiler->PopScope();
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateSwitchStatement(Compiler* compiler, Statement* statement)
{
    SwitchStatement* switchStatement = static_cast<SwitchStatement*>(statement);
    if (!this->ValidateExpression(compiler, switchStatement->switchExpression))
        return false;

    compiler->PushScope(Compiler::Scope::Type::Local, switchStatement);

    for (size_t i = 0; i < switchStatement->caseStatements.size(); i++)
    {
        if (!this->ValidateStatement(compiler, switchStatement->caseStatements[i]))
            return false;
    }
    if (switchStatement->defaultStatement != nullptr
        && !this->ValidateStatement(compiler, switchStatement->defaultStatement))
        return false;

    compiler->PopScope();
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateWhileStatement(Compiler* compiler, Statement* statement)
{
    WhileStatement* whileStatement = static_cast<WhileStatement*>(statement);
    if (!this->ValidateExpression(compiler, whileStatement->condition))
        return false;
    compiler->PushScope(Compiler::Scope::Type::Local, whileStatement);
    if (!this->ValidateStatement(compiler, whileStatement->statement))
        return false;
    compiler->PopScope();
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateExpression(Compiler* compiler, Expression* expression)
{
    switch (expression->symbolType)
    {
    case Symbol::CommaExpressionType:
        return this->ValidateCommaExpression(compiler, expression);
    case Symbol::BinaryExpressionType:
        return this->ValidateBinaryExpression(compiler, expression);
    case Symbol::InitializerExpressionType:
        return this->ValidateInitializerExpression(compiler, expression);
    case Symbol::ArrayIndexExpressionType:
        return this->ValidateArrayIndexExpression(compiler, expression);
    case Symbol::TernaryExpressionType:
        return this->ValidateTernaryExpression(compiler, expression);
    case Symbol::CallExpressionType:
        return this->ValidateCallExpression(compiler, expression);
    case Symbol::AccessExpressionType:
        return this->ValidateAccessExpression(compiler, expression);
    case Symbol::SymbolExpressionType:
        return this->ValidateSymbolExpression(compiler, expression);
    case Symbol::UnaryExpressionType:
        return this->ValidateUnaryExpression(compiler, expression);
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateAccessExpression(Compiler* compiler, Expression* expression)
{
    AccessExpression* accessExpr = static_cast<AccessExpression*>(expression);
    Type::FullType leftType;

    if (!accessExpr->left->EvalType(compiler, leftType))
    {
        compiler->UnrecognizedTypeError(leftType.name, expression);
        return false;
    }

    if (!this->ValidateExpression(compiler, accessExpr->left))
        return false;

    // if deref, check that left hand side has a pointer modifier
    if (accessExpr->deref)
    {
        if (leftType.modifiers.empty()
            || leftType.modifiers.back() != Type::FullType::Modifier::PointerLevel)
        {
            compiler->Error(Format("Cannot dereference type '%s', did you mean to use '.' instead?", leftType.ToString(compiler).c_str()), expression);
            return false;
        }
    }

    // get type
    Type* type = static_cast<Type*>(compiler->GetSymbol(leftType.name));

    if (type == nullptr)
    {
        std::string var;
        accessExpr->left->EvalSymbol(compiler, var);
        compiler->UnrecognizedTypeError(leftType.name, expression);
        return false;
    }

    Compiler::TypeScope scope(compiler, type);

    std::string member;
    if (!accessExpr->right->EvalSymbol(compiler, member))
    {
        compiler->Error(Format("Expected valid symbol for right hand side"), accessExpr);
        return false;
    }

    // check if swizzle if is vector
    if (type->IsVector())
    {
        // if vector, the only allowed member is a swizzle
        unsigned swizzle;
        if (!Type::SwizzleMask(member, swizzle))
        {
            compiler->Error(Format("Invalid swizzle mask '%s'", member.c_str()), accessExpr);
            return false;
        }  
        unsigned biggestComponent = Type::SwizzleMaskBiggestComponent(swizzle);
        if (biggestComponent > type->columnSize)
        {
            compiler->Error(Format("Swizzle '%s' indexes beyond vector column size '%s'", member.c_str(), type->name.c_str()), accessExpr);
            return false;
        }
        
    }
    else
    {
        // not vector type, lookup member
        Symbol* sym = compiler->GetSymbol(member);
        if (sym == nullptr)
        {
            compiler->Error(Format("Type '%s' does not have member or method '%s'", leftType.ToString(compiler).c_str(), member.c_str()), accessExpr);
            return false;
        }
    }
    
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateArrayIndexExpression(Compiler* compiler, Expression* expression)
{
    ArrayIndexExpression* arrayIndexExpr = static_cast<ArrayIndexExpression*>(expression);
    Type::FullType lhsType;
    if (!arrayIndexExpr->left->EvalType(compiler, lhsType))
    {
        compiler->UnrecognizedTypeError(lhsType.name, expression);
        return false;
    }

    // if lhs is level 0
    if (lhsType.modifiers.empty())
    {
        std::string typeString = lhsType.name;
        Type* type = static_cast<Type*>(compiler->GetSymbol(typeString));
        auto it = type->lookup.find("operator[]");
        if (it == type->lookup.end())
        {
            compiler->Error(Format("'%s' does not implement the [] operator", lhsType.ToString(compiler).c_str()), arrayIndexExpr->right);
            return false;
        }
    }
    else if (lhsType.modifiers.back() != Type::FullType::Modifier::ArrayLevel)
    {
        compiler->Error(Format("operator [] not valid on non-array type '%s'", lhsType.ToString(compiler).c_str()), arrayIndexExpr->right);
        return false;
    }
        

    if (arrayIndexExpr->right != nullptr)
    {
        if (!this->ValidateExpression(compiler, arrayIndexExpr->right))
            return false;

        Type::FullType type;
        if (!arrayIndexExpr->right->EvalType(compiler, type))
        {
            compiler->UnrecognizedTypeError(type.name, expression);
            return false;
        }
        Type* typeSymbol = compiler->GetSymbol<Type>(type.name);
        if (typeSymbol->name != "uint" && typeSymbol->name != "int")
        {
            compiler->Error(Format("Expected array index to be uint or int but got '%s'", type.ToString(compiler).c_str()), arrayIndexExpr->right);
            return false;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateCommaExpression(Compiler* compiler, Expression* expression)
{
    CommaExpression* commaExpr = static_cast<CommaExpression*>(expression);
    return this->ValidateExpression(compiler, commaExpr->left) && this->ValidateExpression(compiler, commaExpr->right);
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateBinaryExpression(Compiler* compiler, Expression* expression)
{
    BinaryExpression* binExp = static_cast<BinaryExpression*>(expression);

    Type::FullType leftType, rightType;
    if (!binExp->left->EvalType(compiler, leftType))
    {
        compiler->UnrecognizedTypeError(leftType.name, expression);
        return false;
    }
    if (!binExp->right->EvalType(compiler, rightType))
    {
        compiler->UnrecognizedTypeError(rightType.name, expression);
        return false;
    }
    Type* leftTypeSymbol = compiler->GetSymbol<Type>(leftType.name);
    Type* rightTypeSymbol = compiler->GetSymbol<Type>(rightType.name);

    // find operators for types and compare
    std::string operatorName = Format("operator%s", FourCCToString(binExp->op).c_str());
    std::vector<Symbol*> leftOperators = leftTypeSymbol->GetSymbols(operatorName);
    if (leftOperators.empty())
    {
        compiler->Error(Format("Type '%s' does not implement '%s'", leftTypeSymbol->name.c_str(), operatorName.c_str()), binExp);
        return false;
    }
    else
    {
        Symbol* match = Function::MatchOverload(compiler, leftOperators, { rightType });
        if (match == nullptr)
        {
            compiler->Error(Format("No overloads of '%s' matches type '%s' for type '%s'", operatorName.c_str(), rightType.ToString(compiler).c_str(), leftType.ToString(compiler).c_str()), binExp);
            return false;
        }
    }

    return this->ValidateExpression(compiler, binExp->left) && this->ValidateExpression(compiler, binExp->right);
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateCallExpression(Compiler* compiler, Expression* expression)
{
    bool ret = true;
    CallExpression* call = static_cast<CallExpression*>(expression);
    std::vector<Type::FullType> args;
    for (Expression* expr : call->args)
    {
        ret &= this->ValidateExpression(compiler, expr);
        Type::FullType type;
        if (!expr->EvalType(compiler, type))
        {
            compiler->UnrecognizedTypeError(type.name, expression);
            return false;
        }
        args.push_back(type);
    }

    std::string funName;
    if (!call->function->EvalSymbol(compiler, funName))
    {
        compiler->Error(Format("Could not function name for '%s'", call->EvalString(compiler).c_str()), expression);
        return false;
    }
    std::vector<Symbol*> overloads = compiler->GetSymbols(funName);
    for (Symbol* symbol : overloads)
    {
        if (symbol->symbolType == Symbol::TypeType)
        {
            Type* typeSymbol = static_cast<Type*>(symbol);
            std::vector<Symbol*> constructors = typeSymbol->GetSymbols(funName);
            Symbol* match = Function::MatchOverload(compiler, constructors, args, true);
            if (match == nullptr)
            {
                std::string argList;
                for (size_t i = 0; i < args.size(); i++)
                {
                    argList.append(args[i].ToString(compiler));
                    if (i < args.size() - 1)
                        argList.append(", ");
                }
                compiler->Error(Format("No constructor for type '%s' matches arguments '%s'", typeSymbol->name.c_str(), argList.c_str()), call);
                return false;
            }
        }
        else if (symbol->symbolType == Symbol::FunctionType)
        {
            Symbol* match = Function::MatchOverload(compiler, overloads, args);
            if (match == nullptr)
            {
                std::string argList;
                for (size_t i = 0; i < args.size(); i++)
                {
                    argList.append(args[i].ToString(compiler));
                    if (i < args.size() - 1)
                        argList.append(", ");
                }
                compiler->Error(Format("No overload of '%s' matches arguments '%s'", funName.c_str(), argList.c_str()), call);
                return false;
            }
        }
    }

    return ret;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateInitializerExpression(Compiler* compiler, Expression* expression)
{
    // check that all initializers are equivalent
    InitializerExpression* rhs = static_cast<InitializerExpression*>(expression);
    Type::FullType type;

    // first step, validate expressions
    for (Expression* expr : rhs->values)
        if (!this->ValidateExpression(compiler, expr))
            return false;

    if (!rhs->values.front()->EvalType(compiler, type))
    {
        compiler->UnrecognizedTypeError(type.name, expression);
        return false;
    }
    for (size_t i = 0; i < rhs->values.size(); i++)
    {
        Expression* expr = rhs->values[i];
        Type::FullType nextType;
        if (!expr->EvalType(compiler, nextType))
        {
            compiler->UnrecognizedTypeError(type.name, expression);
            return false;
        }
        if (type != nextType)
        {
            compiler->Error(Format("Initializer list at index '%d' expected type '%s' but got '%s'", i, type.ToString(compiler).c_str(), nextType.ToString(compiler).c_str()), rhs);
            return false;
        }
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateSymbolExpression(Compiler* compiler, Expression* expression)
{
    SymbolExpression* symExpr = static_cast<SymbolExpression*>(expression);
    Symbol* sym = compiler->GetSymbol(symExpr->symbol);
    if (sym == nullptr)
    {
        compiler->Error(Format("Unrecognized symbol '%s' in scope", symExpr->symbol.c_str()), symExpr);
        return false;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateTernaryExpression(Compiler* compiler, Expression* expression)
{
    TernaryExpression* ternaryExpr = static_cast<TernaryExpression*>(expression);
    Type::FullType lhsType, middleType, lastType;
    if (!ternaryExpr->lhs->EvalType(compiler, lhsType))
    {
        compiler->UnrecognizedTypeError(lhsType.name, expression);
        return false;
    }
    if (!ternaryExpr->ifExpression->EvalType(compiler, middleType))
    {
        compiler->UnrecognizedTypeError(middleType.name, expression);
        return false;
    }
    if (!ternaryExpr->elseExpression->EvalType(compiler, lastType))
    {
        compiler->UnrecognizedTypeError(lastType.name, expression);
        return false;
    }

    if (
        (lhsType.name != "bool" 
        && lhsType.name != "int" 
        && lhsType.name != "uint") 
        || !lhsType.modifiers.empty())
    {
        compiler->Error(Format("Condition must evaluate to 'bool', 'int' or 'uint', but got '%s'", lhsType.name.c_str()), expression);
        return false;
    }

    if (middleType != lastType)
    {
        compiler->Error(Format("Type mismatch between '%s' : '%s'", middleType.ToString(compiler).c_str(), lastType.ToString(compiler).c_str()), expression);
        return false;
    }

    if (!this->ValidateExpression(compiler, ternaryExpr->lhs))
        return false;
    if (!this->ValidateExpression(compiler, ternaryExpr->ifExpression))
        return false;
    if (!this->ValidateExpression(compiler, ternaryExpr->elseExpression))
        return false;
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateUnaryExpression(Compiler* compiler, Expression* expression)
{
    UnaryExpression* unary = static_cast<UnaryExpression*>(expression);
    Type::FullType type;
    if (!unary->expr->EvalType(compiler, type))
    {
        compiler->UnrecognizedTypeError(type.name, expression);
        return false;
    }

    if (unary->op == '*'
        && type.modifiers.empty()
        && type.modifiers.back() != Type::FullType::Modifier::PointerLevel)
    {
        compiler->Error(Format("Can't dereference type '%s'", type.ToString(compiler).c_str()), expression);
        return false;
    }
    return true;
}

} // namespace AnyFX

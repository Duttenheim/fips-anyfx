//------------------------------------------------------------------------------
//  @file validator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "validator.h"
#include "ast/samplerstate.h"
#include "ast/function.h"
#include "ast/program.h"
#include "ast/renderstate.h"
#include "ast/structure.h"
#include "ast/variable.h"
#include "ast/expressions/binaryexpression.h"
#include "ast/expressions/arrayindexexpression.h"
#include "compiler.h"
#include "util.h"
#include <algorithm>

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
std::set<std::string> readWriteTextureAccessFlags =
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

std::set<std::string> structureTypes =
{
    "mutable", "const"
};

std::set<std::string> structureAccessFlags =
{
    "read", "write", "read_write", "atomic", "volatile"
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

//------------------------------------------------------------------------------
/**
*/
Validator::Validator() 
    : resourceIndexingMode(ResourceIndexingByGroup)
    , defaultGroup(0)
{
    this->allowedReadWriteTextureAttributes.insert(readWriteTextureAccessFlags.begin(), readWriteTextureAccessFlags.end());
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

    this->allowedFunctionAttributes.insert(functionAttributes.begin(), functionAttributes.end());

    this->allowedParameterAttributes.insert(parameterQualifiers.begin(), parameterQualifiers.end());
    this->allowedParameterAttributes.insert(parameterAccessFlags.begin(), parameterAccessFlags.end());

    this->allowedStructureAttributes.insert(structureTypes.begin(), structureTypes.end());
    this->allowedStructureAttributes.insert(structureAccessFlags.begin(), structureAccessFlags.end());
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::Resolve(Compiler* compiler, const std::vector<Symbol*>& symbols)
{
    bool ret = true;
    for (Symbol* sym : symbols)
    {
        switch (sym->symbolType)
        {
        case Symbol::SymbolType::FunctionType:
            ret &= this->ResolveFunction(compiler, sym);
            break;
        case Symbol::SymbolType::ProgramType:
            ret &= this->ResolveProgram(compiler, sym);
            break;
        case Symbol::SymbolType::RenderStateType:
            ret &= this->ResolveRenderState(compiler, sym);
            break;
        case Symbol::SymbolType::StructureType:
            ret &= this->ResolveStructure(compiler, sym);
            break;
        case Symbol::SymbolType::VariableType:
            ret &= this->ResolveVariable(compiler, sym);
            break;
        case Symbol::SymbolType::SamplerStateType:
            ret &= this->ResolveSamplerState(compiler, sym);
            break;
        }
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

    for (Expression* entry : state->entries)
    {
        const BinaryExpression* assignEntry = static_cast<const BinaryExpression*>(entry);

        if (assignEntry->symbolType != Symbol::BinaryExpressionType || assignEntry->op != '=')
        {
            compiler->Error(Format("Sampler state entry must be an assignment expression"), entry);
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
            stateResolved->minFilter = SamplerState::__Resolved::StringToFilter(assign->right->EvalString(compiler));
            if (stateResolved->minFilter == InvalidFilter)
            {
                compiler->Error(Format("Invalid filter '%s'", stringValue.c_str()), assignEntry);
                return false;
            }
            break;
        case SamplerState::__Resolved::MagFilterType:
            stringValue = assignEntry->right->EvalString(compiler);
            stateResolved->magFilter = SamplerState::__Resolved::StringToFilter(assign->right->EvalString(compiler));
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
            stateResolved->mipLodBias = assignEntry->right->EvalFloat(compiler);
            break;
        case SamplerState::__Resolved::AnisotropicFlagType:
            stateResolved->anisotropicEnabled = assignEntry->right->EvalBool(compiler);
            break;
        case SamplerState::__Resolved::MaxAnisotropyType:
            stateResolved->maxAnisotropy = assignEntry->right->EvalFloat(compiler);
            break;
        case SamplerState::__Resolved::CompareFlagType:
            stateResolved->compareSamplerEnabled = assignEntry->right->EvalBool(compiler);
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
            stateResolved->minLod = assignEntry->right->EvalFloat(compiler);
            break;
        case SamplerState::__Resolved::MaxLodType:
            stateResolved->maxLod = assignEntry->right->EvalFloat(compiler);
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
            stateResolved->unnormalizedSamplingEnabled = assignEntry->right->EvalBool(compiler);
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

    Type* type = (Type*)compiler->GetSymbol(fun->returnType);
    funResolved->returnType = type;
    if (funResolved->returnType->code == Type::Code::InvalidType)
    {
        compiler->Error(Format("INTERNAL COMPILER ERROR, type '%s' does not have a numerical mapping", fun->returnType.c_str()), symbol);
        return false;
    }

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
            funResolved->computeShaderWorkGroupSize[0] = attr.expression->EvalUInt(compiler);
        else if (attr.name == "local_size_y")
            funResolved->computeShaderWorkGroupSize[1] = attr.expression->EvalUInt(compiler);
        else if (attr.name == "local_size_z")
            funResolved->computeShaderWorkGroupSize[2] = attr.expression->EvalUInt(compiler);
        else if (attr.name == "early_depth")
            funResolved->earlyDepth = true;
        else if (attr.name == "invocations")
            funResolved->invocations = attr.expression->EvalUInt(compiler);
        else if (attr.name == "max_output_vertices")
            funResolved->maxOutputVertices = attr.expression->EvalUInt(compiler);
        else if (attr.name == "patch_size")
            funResolved->patchSize = attr.expression->EvalUInt(compiler);
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

    // run validation on parameters
    for (Variable* var : fun->parameters)
    {
        Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
        varResolved->usageBits.flags.isParameter = true;
        this->ResolveVariable(compiler, var);
    }

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
            compiler->Error(Format("Program entry '%s' is not an array", assignEntry->name.c_str()), symbol);
            return false;
        }

        // only allow symbol assignments
        if (assignEntry->right->symbolType != Symbol::SymbolExpressionType)
        {
            compiler->Error(Format("Program binds '%s' but it is not an identifier", assignEntry->right->EvalString(compiler).c_str()), symbol);
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
                compiler->Error(Format("Unrecognized symbol '%s'", entry), symbol);
                return false;
            }

            // check that it's actually a function
            if (functionStub->symbolType != Symbol::FunctionType)
            {
                compiler->Error(Format("Symbol '%s' is not a recognized function", entry.c_str()), symbol);
                return false;
            }

            // next up, function to assign
            std::pair<Compiler::SymbolIterator, Compiler::SymbolIterator> functions = compiler->GetSymbols(assignEntry->right->EvalString(compiler));
            Function* functionImplementation = static_cast<Function*>(functions.first->second);

            // again, check if not null
            if (functionImplementation == nullptr)
            {
                compiler->Error(Format("Unrecognized symbol '%s'", assignEntry->right->EvalString(compiler).c_str()), symbol);
                return false;
            }

            // and check that it's actually a function
            if (functionImplementation->symbolType != Symbol::FunctionType)
            {
                compiler->Error(Format("Symbol '%s' is not a recognized function", assignEntry->right->EvalString(compiler).c_str()), symbol);
                return false;
            }

            bool matched = false;
            for (auto it = functions.first; it != functions.second; it++)
            {
                Function* func = static_cast<Function*>(it->second);
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
                for (auto it = functions.first; it != functions.second; it++)
                {
                    Function* func = static_cast<Function*>(it->second);
                    candidates.append(func->signature);
                    if (it != functions.second)
                        candidates.append(",\n");
                }
                compiler->Error(Format("Function prototype '%s' can not bind function '%s', possible candidates: \n%s", functionStub->name.c_str(), assignEntry->right->EvalString(compiler).c_str(), candidates.c_str()), symbol);
                return false;
            }
        }
        else
        {
            // get the symbol for this entry
            Symbol* value = assignEntry->right->EvalSymbol(compiler);
            if (value->symbolType != Symbol::SymbolType::FunctionType)
            {
                compiler->Error(Format("Program binds symbol '%s' to '%s' but it is not a recognized function", assignEntry->name.c_str(), assignEntry->name.c_str()), assignEntry);
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

    for (const Expression* entry : state->entries)
    {
        const BinaryExpression* assignEntry = static_cast<const BinaryExpression*>(entry);

        if (assignEntry->symbolType != Symbol::BinaryExpressionType || assignEntry->op != '=')
        {
            compiler->Error(Format("Render state entry not an assignment statement"), entry);
            return false;
        }

        std::string entry;

        // if left is binary, then validate it is an array expression
        if (assignEntry->left->symbolType == Symbol::BinaryExpressionType)
        {
            const BinaryExpression* lhs = static_cast<const BinaryExpression*>(assignEntry->left);
            if (lhs->right->symbolType != Symbol::ArrayIndexExpressionType)
            {
                compiler->Error(Format("Render state entry '%s' may be either identifier or array expression", lhs->right->name.c_str()), assignEntry);
                return false;
            }
            if (lhs->left->symbolType != Symbol::SymbolExpressionType)
            {
                compiler->Error(Format("Render state array entry '%s' must be a valid identifier", lhs->left->name.c_str()), assignEntry);
                return false;
            }
            entry = lhs->left->EvalString(compiler);
        }
        else
        {
            if (assignEntry->left->symbolType != Symbol::SymbolExpressionType)
            {
                compiler->Error(Format("Render state entry '%s' must be a valid identifier", assignEntry->left->name.c_str()), assignEntry);
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
            if (assignEntry->left->symbolType != Symbol::BinaryExpressionType)
            {
                const BinaryExpression* lhs = static_cast<const BinaryExpression*>(assignEntry->left);
                if (lhs->right->symbolType != Symbol::ArrayIndexExpressionType)
                {
                    compiler->Error(Format("Blend state entry '%s' must supply an array index", entry.c_str()), assignEntry);
                    return false;
                }
                index = lhs->right->EvalUInt(compiler);
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
                stateResolved->blendStates[index].blendEnabled = assignEntry->right->EvalBool(compiler);
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

    // run attribute validation
    for (const Attribute& attr : struc->attributes)
    {
        if (!set_contains(this->allowedStructureAttributes, attr.name))
        {
            compiler->Error(Format("Invalid attribute for structure '%s': '%s'", struc->name.c_str(), attr.name.c_str()), symbol);
            return false;
        }

        // check structure types
        if (set_contains(structureTypes, attr.name))
        {
            if (strucResolved->usageFlags.bits != 0)
            {
                compiler->Error(Format("struct '%s' already has type defined, '%s' is invalid: '%s'", struc->name.c_str(), attr.name.c_str()), symbol);
                return false;
            }
            if (attr.name == "mutable")
                strucResolved->usageFlags.flags.isStorageBuffer = true;
            else if (attr.name == "const")
                strucResolved->usageFlags.flags.isConstantBuffer = true;
        }

        if (set_contains(structureAccessFlags, attr.name))
        {
            if (!strucResolved->usageFlags.flags.isStorageBuffer)
            {
                compiler->Error(Format("Access flags ('%s') can only be set on a 'mutable' type struct: '%s'", attr.name.c_str()), symbol);
                return false;
            }
            if (attr.name == "read")
                strucResolved->accessBits.flags.readAccess = true;
            else if (attr.name == "write")
                strucResolved->accessBits.flags.writeAccess = true;
            else if (attr.name == "read_write")
                strucResolved->accessBits.flags.readAccess = strucResolved->accessBits.flags.writeAccess = true;
            else if (attr.name == "atomic")
                strucResolved->accessBits.flags.atomicAccess = true;
            else if (attr.name == "volatile")
                strucResolved->accessBits.flags.volatileAccess = true;
        }

        if (set_contains(structureQualifiers, attr.name))
        {
            if (!strucResolved->usageFlags.flags.isStorageBuffer && !strucResolved->usageFlags.flags.isConstantBuffer)
            {
                compiler->Error(Format("Binding qualifiers flags ('%s') can only be set on a 'mutable' or 'const' type struct: '%s'", attr.name.c_str()), symbol);
                return false;
            }
            if (attr.name == "group")
                strucResolved->group = attr.expression->EvalUInt(compiler);
            else if (attr.name == "binding")
                strucResolved->binding = attr.expression->EvalUInt(compiler);
            else if (attr.name == "push")
            {
                if (!strucResolved->usageFlags.flags.isConstantBuffer)
                {
                    compiler->Error(Format("Qualifier 'push' is only allowed on a 'const' type struct: '%s'", attr.name.c_str()), symbol);
                    return false;
                }
                strucResolved->usageFlags.flags.isPush = true;
            }
        }
    }

    // evaluate binding and group if storage or constant buffer
    if (strucResolved->usageFlags.flags.isStorageBuffer || strucResolved->usageFlags.flags.isConstantBuffer)
    {
        if (strucResolved->group == Structure::__Resolved::NOT_BOUND)
        {
            strucResolved->group = this->defaultGroup;
        }
        if (this->resourceIndexingMode == ResourceIndexingByType)
        {
            Type::Category cat = strucResolved->usageFlags.flags.isStorageBuffer ? Type::MutableStructureCategory : Type::ConstantStructureCategory;
            auto it = this->resourceIndexCounter.find(cat);
            if (it == this->resourceIndexCounter.end())
            {
                this->resourceIndexCounter[cat] = 0;
                it = this->resourceIndexCounter.find(strucResolved->group);
            }

            if (strucResolved->binding == Structure::__Resolved::NOT_BOUND)
            {
                strucResolved->binding = it->second++;
            }
            else
            {
                this->resourceIndexCounter[cat] = max(it->second, strucResolved->binding + 1);
            }
        }
        else if (this->resourceIndexingMode == ResourceIndexingByGroup)
        {
            auto it = this->resourceIndexCounter.find(strucResolved->group);
            if (it == this->resourceIndexCounter.end())
            {
                this->resourceIndexCounter[strucResolved->group] = 0;
                it = this->resourceIndexCounter.find(strucResolved->group);
            }

            if (strucResolved->binding == Structure::__Resolved::NOT_BOUND)
            {
                strucResolved->binding = it->second++;
            }
            else
            {
                this->resourceIndexCounter[strucResolved->group] = max(it->second, strucResolved->binding + 1);
            }
        }
    }

    // validate members
    for (Variable* var : struc->members)
    {
        Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
        varResolved->usageBits.flags.isConstantBufferMember = strucResolved->usageFlags.flags.isConstantBuffer;
        varResolved->usageBits.flags.isStorageBufferMember = strucResolved->usageFlags.flags.isStorageBuffer;
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

    Type* type = (Type*)compiler->GetSymbol(var->type);
    if (type == nullptr)
    {
        compiler->Error(Format("Unrecognized type '%s'", var->type.c_str()), symbol);
        return false;
    }
    varResolved->type = type;

    // struct members may only be scalars
    if (varResolved->usageBits.flags.isStructMember && !type->IsScalar())
    {
        compiler->Error(Format("Member '%s' may only be scalar type if member of a struct", var->name.c_str()), symbol);
        return false;
    }

    // figure out set of allowed attributes
    std::set<std::string>* allowedAttributesSet = nullptr;
    if (varResolved->usageBits.flags.isStructMember)
        allowedAttributesSet = nullptr;
    else if (varResolved->usageBits.flags.isParameter)
        allowedAttributesSet = &this->allowedParameterAttributes;
    else
    {
        if (type->IsReadWriteTexture())
            allowedAttributesSet = &this->allowedReadWriteTextureAttributes;
        else if (type->IsTexture())
            allowedAttributesSet = &this->allowedTextureAttributes;
        else if (type->IsSampledTexture())
            allowedAttributesSet = &this->allowedSampledTextureAttributes;
        else if (type->IsScalar())
            allowedAttributesSet = &this->allowedScalarAttributes;
        else if (type->IsSampler())
            allowedAttributesSet = &this->allowedSamplerAttributes;
    }

    // run attribute validation
    for (const Attribute& attr : var->attributes)
    {
        if (allowedAttributesSet == nullptr || (!set_contains(*allowedAttributesSet, attr.name)))
        {
            compiler->Error(Format("Invalid attribute for type '%s': '%s'", var->type.c_str(), attr.name.c_str()), symbol);
            return false;
        }

        // resolve attributes
        if (attr.name == "group")
            varResolved->group = attr.expression->EvalUInt(compiler);
        else if (attr.name == "binding")
            varResolved->binding = attr.expression->EvalUInt(compiler);
        else if (attr.name == "const")
            varResolved->usageBits.flags.isConst = true;
        else if (attr.name == "group_shared")
            varResolved->usageBits.flags.isGroupShared = true;
        else
        {
            // more complicated lookups
            if (set_contains(readWriteTextureAccessFlags, attr.name))
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
                varResolved->binding = attr.expression->EvalUInt(compiler);
        }

        // check image formats
        if (map_contains(Variable::stringToFormats, attr.name))
        {
            varResolved->imageFormat = Variable::stringToFormats[attr.name];
        }
    }

    // check if image formats have been resolved
    if (type->IsReadWriteTexture() && varResolved->imageFormat == Variable::InvalidImageFormat)
    {
        compiler->Error(Format("Image variable '%s' must provide a format qualifier", var->name.c_str()), var);
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
        // if not a parameter, assume resource (these types can't be declared inside functions)
        if (type->IsReadWriteTexture()
            || type->IsSampledTexture()
            || type->IsTexture()
            || type->IsSampler()
            || type->IsInputAttachment())
        {
            if (varResolved->group == Variable::__Resolved::NOT_BOUND)
            {
                varResolved->group = this->defaultGroup;
            }

            if (this->resourceIndexingMode == ResourceIndexingByType)
            {
                Type::Category cat = type->ToCategory();
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
    }

    // setup array
    if (var->isArray)
    {
        if (var->arraySizeExpression)
            varResolved->arraySize = var->arraySizeExpression->EvalUInt(compiler);
    }

    // setup initializers
    if (!var->initializers.empty())
    {
        // only allow initializers on parameters or const variables
        if (!varResolved->usageBits.flags.isConst || varResolved->usageBits.flags.isParameter)
        {
            compiler->Error(Format("Initializer can only be used on 'const' qualifier variables or function parameters"), symbol);
            return false;
        }

        uint32_t typeComponents = type->ComponentCount();

        // reduce type to single component
        const Type::Code singleComponentType = type->SingleComponent();
        if (
            singleComponentType != Type::Code::Float
            && singleComponentType != Type::Code::Int
            && singleComponentType != Type::Code::UInt
            && singleComponentType != Type::Code::Bool)
        {
            compiler->Error(Format("Initializer only accepts components as floats, ints, uints or bools"), symbol);
            return false;
        }

        // run through initializers and evaluate value expressions
        for (auto& initializer : var->initializers)
        {
            if (initializer.size() != typeComponents)
            {
                compiler->Error(Format("Initializer expected %d initializers but got %d", typeComponents, initializer.size()), symbol);
                return false;
            }

            std::vector<Variable::__Resolved::Initializer> values;
            for (auto& expr : initializer)
            {
                Variable::__Resolved::Initializer value;
                switch (singleComponentType)
                {
                case Type::Code::Float:
                    value.type = Variable::__Resolved::Initializer::FloatType;
                    value.data.f = expr->EvalFloat(compiler);
                    break;
                case Type::Code::Int:
                    value.type = Variable::__Resolved::Initializer::IntType;
                    value.data.i = expr->EvalInt(compiler);
                    break;
                case Type::Code::UInt:
                    value.type = Variable::__Resolved::Initializer::UIntType;
                    value.data.u = expr->EvalUInt(compiler);
                    break;
                case Type::Code::Bool:
                    value.type = Variable::__Resolved::Initializer::BoolType;
                    value.data.b = expr->EvalBool(compiler);
                    break;
                default:
                    compiler->Error(Format("INTERNAL COMPILER ERROR did not catch type '%s' as a invalid array initializer type", var->type), symbol);
                    return false;
                }
                values.push_back(value);
            }
            varResolved->initializers.push_back(values);
        }
    }

    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool
Validator::Validate(Compiler* compiler, const std::vector<Symbol*>& symbols)
{
    bool ret = true;
    for (Symbol* sym : symbols)
    {
        switch (sym->symbolType)
        {
        case Symbol::SymbolType::FunctionType:
            ret &= this->ValidateFunction(compiler, sym);
            break;
        case Symbol::SymbolType::ProgramType:
            ret &= this->ValidateProgram(compiler, sym);
            break;
        case Symbol::SymbolType::RenderStateType:
            ret &= this->ValidateRenderState(compiler, sym);
            break;
        case Symbol::SymbolType::StructureType:
            ret &= this->ValidateStructure(compiler, sym);
            break;
        case Symbol::SymbolType::VariableType:
            ret &= this->ValidateVariable(compiler, sym);
            break;
        case Symbol::SymbolType::SamplerStateType:
            ret &= this->ValidateSamplerState(compiler, sym);
            break;
        }
    }
    return ret;
}


//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateSamplerState(Compiler* compiler, Symbol* symbol)
{
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
            compiler->Warning(Format("Function '%s' is used as pixel shader but produces no outputs", fun->name.c_str()), symbol);
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
            compiler->Error(Format("Function '%s' is hull/tessellation control shader but does not define 'patch_size'", fun->name.c_str()), symbol);
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
            compiler->Warning(Format("Function '%s' does not define 'patch_type' for DomainShader/TessellationEvaluationShader, defaulting to 'triangles'", fun->name.c_str()), symbol);
            funResolved->patchType = Function::__Resolved::PatchType::TrianglePatch;
        }
        if (funResolved->partitionMethod != Function::__Resolved::InvalidPartitionMethod)
        {
            compiler->Warning(Format("Function '%s' does not define 'partition', defaulting to 'steps'", fun->name.c_str()), symbol);
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
            compiler->Error(Format("Function '%s' does not define 'max_output_vertices' for GeometryShader", fun->name.c_str()), symbol);
            return false;
        }
        if (funResolved->inputPrimitiveTopology == Function::__Resolved::InvalidPrimitiveTopology)
        {
            compiler->Warning(Format("Function '%s' does not define 'input_topology' for GeometryShader, defaulting to 'triangles'", fun->name.c_str()), symbol);
            funResolved->inputPrimitiveTopology = Function::__Resolved::Triangles;
        }
        if (funResolved->outputPrimitiveTopology == Function::__Resolved::InvalidPrimitiveTopology)
        {
            compiler->Warning(Format("Function '%s' does not define 'output_topology' for GeometryShader, defaulting to 'triangles'", fun->name.c_str()), symbol);
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
            compiler->Error(Format("Function must declare 'local_size_x' bigger than or equal to 1", fun->name.c_str()), symbol);
            return false;
        }
        if (funResolved->computeShaderWorkGroupSize[1] <= 0)
        {
            compiler->Error(Format("Function must declare 'local_size_y' bigger than or equal to 1", fun->name.c_str()), symbol);
            return false;
        }
        if (funResolved->computeShaderWorkGroupSize[2] <= 0)
        {
            compiler->Error(Format("Function must declare 'local_size_z' bigger than or equal to 1", fun->name.c_str()), symbol);
            return false;
        }
    }
    else
    {
        if (funResolved->computeShaderWorkGroupSize[0] > 1)
            compiler->Warning(Format("Function '%s' has attribute 'local_size_x' but is not used as a ComputeShader", fun->name.c_str()), symbol);
        if (funResolved->computeShaderWorkGroupSize[1] > 1)
            compiler->Warning(Format("Function '%s' has attribute 'local_size_y' but is not used as a ComputeShader", fun->name.c_str()), symbol);
        if (funResolved->computeShaderWorkGroupSize[2] > 1)
            compiler->Warning(Format("Function '%s' has attribute 'local_size_z' but is not used as a ComputeShader", fun->name.c_str()), symbol);
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
            if (outResolved->type != inResolved->type)
            {
                compiler->Error(Format("Can't match types '%s' and '%s' between shader '%s' and '%s'", var->type.c_str(), inParams[inIterator]->type.c_str(), outFunc->name.c_str(), inFunc->name.c_str()), outFunc);
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
    GraphicsProgramTristate programType = NotSet;

    // validate program setup as compute or graphics program, do it on a first-come-first-serve basis
    for (auto& it : progResolved->programMappings)
    {
        if (it.first == Program::__Resolved::ComputeShader)
        {
            if (programType == IsGraphics)
            {
                compiler->Error(Format("Invalid program setup, program already used as a graphics program, ComputeShader is not allowed"), symbol);
                return false;
            }
            programType = IsCompute;
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
            if (programType == IsCompute)
            {
                compiler->Error(Format("Invalid program setup, program already used with ComputeShader but '%s' was provided", Program::__Resolved::EntryTypeToString(it.first)), symbol);
                return false;
            }
            programType = IsGraphics;
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
Validator::ValidateRenderState(Compiler* compiler, Symbol* symbol)
{
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateStructure(Compiler* compiler, Symbol* symbol)
{
    return true;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Validator::ValidateVariable(Compiler* compiler, Symbol* symbol)
{
    return true;
}

} // namespace AnyFX

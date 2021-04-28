//------------------------------------------------------------------------------
//  compiler.cc
//  (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "compiler.h"
#include "ast/program.h"
#include "validators/validator.h"
#include "generators/hlslgenerator.h"
#include "generators/glslgenerator.h"
#include "generators/spirvgenerator.h"
#include "generators/hgenerator.h"
#include "util.h"
#include "v3/ast/type.h"
#include "v3/ast/variable.h"
#include "v3/ast/renderstate.h"
#include "v3/ast/samplerstate.h"
#include "v3/ast/program.h"
#include "v3/ast/structure.h"
#include "v3/ast/variable.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Compiler::Compiler() 
    : debugOutput(false)
{
    // setup default types and their lookups
    Variable::SetupImageFormats();
    const std::map<std::string, Symbol*> defaultTypes = Type::SetupDefaultTypes();
    auto it = defaultTypes.begin();
    while (it != defaultTypes.end())
    {
        this->AddSymbol(it->first, it->second);
        it++;
    }

    this->validator = new Validator;
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Setup(const Compiler::Language& lang, const std::vector<std::string>& defines, unsigned int version)
{
    switch (lang)
    {
    case Language::GLSL_SPIRV:
        this->generator = new GLSLGenerator(GLSLGenerator::VulkanFeatureSet);
        break;
    case Language::GLSL:
        this->generator = new GLSLGenerator(GLSLGenerator::OpenGLFeatureSet);
        break;
    case Language::HLSL_SPIRV:
    case Language::HLSL:
        this->generator = new HLSLGenerator();
        break;
    case Language::SPIRV:
        this->generator = new SPIRVGenerator();
        break;
    }

    // if we want other header generators in the future, add here
    this->headerGenerator = new HGenerator();
}

//------------------------------------------------------------------------------
/**
*/
bool 
Compiler::AddSymbol(const std::string& name, Symbol* symbol, bool allowDuplicate)
{
    auto it = this->symbolLookup.find(name);
    if (it != this->symbolLookup.end() && !allowDuplicate)
    {
        Symbol* symbol = it->second;
        this->errors.push_back(Format("Symbol %s redefinition, previous definition at %s(%d)", name.c_str(), symbol->location.file.c_str(), symbol->location.line));
        return false;
    }
    this->symbolLookup.insert({name, symbol});
    this->symbols.push_back(symbol);
    return true;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
Compiler::GetSymbol(const std::string& name) const
{
    auto it = this->symbolLookup.find(name);
    if (it != this->symbolLookup.end())
        return it->second;
    else
        return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
std::pair<Compiler::SymbolIterator, Compiler::SymbolIterator>
Compiler::GetSymbols(const std::string& name) const
{
    return this->symbolLookup.equal_range(name);
}

//------------------------------------------------------------------------------
/**
*/
bool 
Compiler::Compile(Effect* root, BinWriter& binaryWriter, TextWriter& headerWriter)
{
    bool ret = true;

    // run end-of-parse pass, which adds symbols to the symbol lookup table
    for (size_t i = 0; i < root->symbols.size(); i++)
    {
        ret &= root->symbols[i]->EndOfParse(this);
    }

    // if failed, don't proceed to next step
    if (!ret || !this->errors.empty())
        return false;

    // resolves parser state to compiler internal state, which can then be validated
    ret &= this->validator->Resolve(this, this->symbols);

    // if failed, don't proceed to next step
    if (!ret || !this->errors.empty())
        return false;

    // validates 
    ret &= this->validator->Validate(this, this->symbols);

    // if failed, don't proceed to next step
    if (!ret || !this->errors.empty())
        return false;

    // setup potential debug output stream
    std::function<void(const std::string&, const std::string&)> writeFunction = nullptr;
    if (this->debugOutput)
    {
        writeFunction = [this](const std::string& name, const std::string& code)
        {
            TextWriter outputStream;
            outputStream.SetPath(this->debugPath + "/" + name);
            if (outputStream.Open())
            {
                outputStream.WriteString(code);
                outputStream.Close();
            }
        };
    }

    // collect programs
    for (Symbol* symbol : this->symbols)
    {
        if (symbol->symbolType == Symbol::ProgramType)
        {
            ret &= this->generator->Generate(this, static_cast<Program*>(symbol), this->symbols, writeFunction);
        }
    }

    // if failed, don't proceed to next step
    if (!ret || !this->errors.empty())
        return false;

    // output binary if possible
    if (binaryWriter.Open())
    {
        // write magic
        binaryWriter.WriteInt('AFX3');

        // run binary output step
        Serialize::DynamicLengthBlob blob;
        for (Symbol* symbol : this->symbols)
        {
            this->OutputBinary(symbol, binaryWriter, blob);
        }

        // output dynamic blob
        binaryWriter.WriteBytes(&blob.data[0], blob.iterator);

        // write size of dynamic blob at the end
        binaryWriter.WriteUInt(blob.iterator);
        binaryWriter.Close();
    }
    else
    {
        return false;
    }

    // header writing is optional
    if (headerWriter.Open())
    {
        ret &= this->headerGenerator->Generate(this, nullptr, this->symbols, [&headerWriter](const std::string& name, const std::string& code)
        {
            headerWriter.WriteString(code);
        });

        headerWriter.Close();
    }

    return ret;
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Error(const std::string& msg, const std::string& file, int line, int column)
{
    std::string err = Format("%s(%d) : error: %s", file.c_str(), line, msg.c_str());
    this->errors.push_back(err);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Error(const std::string& msg, const Symbol* sym)
{
    this->Error(msg, sym->location.file, sym->location.line, sym->location.column);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Warning(const std::string& msg, const std::string& file, int line, int column)
{
    std::string err = Format("%s(%d) : warning: %s", file.c_str(), line, msg.c_str());
    this->warnings.push_back(err);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Warning(const std::string& msg, const Symbol* sym)
{
    this->Warning(msg, sym->location.file, sym->location.line, sym->location.column);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::GeneratorError(const std::string& msg)
{
    this->errors.push_back(msg);
}

//------------------------------------------------------------------------------
/**
*/
void
WriteAnnotation(Compiler* compiler, const Annotation& annot, size_t offset, Serialize::DynamicLengthBlob& dynamicDataBlob)
{
    Serialize::Annotation output;
    output.nameLength = annot.name.length();
    output.nameOffset = dynamicDataBlob.Write(annot.name.c_str(), annot.name.length());
    if (annot.value != nullptr)
    {
        switch (annot.value->symbolType)
        {
        case Symbol::StringExpressionType:
        {
            std::string str = annot.value->EvalString(compiler);
            output.data.s.stringOffset = dynamicDataBlob.Write(str.c_str(), str.length());
            output.data.s.stringLength = str.length();
            output.type = Serialize::StringType;
            break;
        }
        case Symbol::IntExpressionType:
        {
            unsigned int i = annot.value->EvalUInt(compiler);
            output.data.i = i;
            output.type = Serialize::IntType;
            break;
        }
        case Symbol::FloatExpressionType:
        {
            float f = annot.value->EvalFloat(compiler);
            output.data.f = f;
            output.type = Serialize::FloatType;
            break;
        }
        case Symbol::BoolExpressionType:
        {
            bool b = annot.value->EvalBool(compiler);
            output.data.b = b;
            output.type = Serialize::BoolType;
            break;
        }
        }
    }
    else
    {
        output.type = Serialize::NoData;
    }
    dynamicDataBlob.WriteReserved(output, offset);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::OutputBinary(Symbol* symbol, BinWriter& writer, Serialize::DynamicLengthBlob& dynamicDataBlob)
{
    if (symbol->symbolType == Symbol::ProgramType)
    {
        Program* program = static_cast<Program*>(symbol);
        Program::__Resolved* resolved = static_cast<Program::__Resolved*>(symbol->resolved);
        Serialize::Program output;
        output.nameLength = symbol->name.length();
        output.nameOffset = dynamicDataBlob.Write(symbol->name.c_str(), symbol->name.length());

        if (resolved->usage.flags.hasVertexShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::VertexShader];
            output.vs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.vs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.vs.binaryOffset = -1;
            output.vs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasHullShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::HullShader];
            output.hs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.hs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.hs.binaryOffset = -1;
            output.hs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasDomainShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::DomainShader];
            output.ds.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.ds.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.ds.binaryOffset = -1;
            output.ds.binaryLength = -1;
        }

        if (resolved->usage.flags.hasGeometryShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::GeometryShader];
            output.gs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.gs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.gs.binaryOffset = -1;
            output.gs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasPixelShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::PixelShader];
            output.ps.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.ps.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.ps.binaryOffset = -1;
            output.ps.binaryLength = -1;
        }

        if (resolved->usage.flags.hasComputeShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::ComputeShader];
            output.cs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.cs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.cs.binaryOffset = -1;
            output.cs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasRayGenerationShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::RayGenerationShader];
            output.rgs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.rgs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.rgs.binaryOffset = -1;
            output.rgs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasRayMissShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::RayMissShader];
            output.rms.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.rms.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.rms.binaryOffset = -1;
            output.rms.binaryLength = -1;
        }

        if (resolved->usage.flags.hasRayHitShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::RayHitShader];
            output.rhs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.rhs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.rhs.binaryOffset = -1;
            output.rhs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasRayClosestHitShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::RayClosestHitShader];
            output.rchs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.rchs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.rchs.binaryOffset = -1;
            output.rchs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasRayAnyHitShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::RayAnyHitShader];
            output.rahs.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.rahs.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.rahs.binaryOffset = -1;
            output.rahs.binaryLength = -1;
        }

        if (resolved->usage.flags.hasRayIntersectionShader)
        {
            const std::vector<uint32_t>& binary = resolved->binaries[Program::__Resolved::RayIntersectionShader];
            output.ris.binaryOffset = dynamicDataBlob.Write((const char*)&binary.front(), binary.size() * sizeof(uint32_t));
            output.ris.binaryLength = binary.size() * sizeof(uint32_t);
        }
        else
        {
            output.ris.binaryOffset = -1;
            output.ris.binaryLength = -1;
        }

        if (resolved->usage.flags.hasRenderState)
        {
            Symbol* renderState = resolved->programMappings[Program::__Resolved::RenderState];
            output.renderStateLength = renderState->name.length();
            output.renderStateOffset = dynamicDataBlob.Write(renderState->name.c_str(), renderState->name.length());
        }

        output.annotationsOffset = dynamicDataBlob.Reserve<Serialize::Annotation>(program->annotations.size());
        output.annotationsCount = program->annotations.size();

        size_t offset = output.annotationsOffset;
        for (const Annotation& annot : program->annotations)
        {
            WriteAnnotation(this, annot, offset, dynamicDataBlob);
            offset += sizeof(Serialize::Annotation);
        }

        writer.WriteType(output);
    }
    else if (symbol->symbolType == Symbol::RenderStateType)
    {
        RenderState::__Resolved* resolved = static_cast<RenderState::__Resolved*>(symbol->resolved);
        Serialize::RenderState output;
        output.nameLength = symbol->name.length();
        output.nameOffset = dynamicDataBlob.Write(symbol->name.c_str(), symbol->name.length());
        output.depthClampEnabled = resolved->depthClampEnabled;
        output.noPixels = resolved->noPixels;
        output.polygonMode = resolved->polygonMode;
        output.cullMode = resolved->cullMode;
        output.windingOrderMode = resolved->windingOrderMode;
        output.depthBiasEnabled = resolved->depthBiasEnabled;
        output.depthBiasFactor = resolved->depthBiasFactor;
        output.depthBiasClamp = resolved->depthBiasClamp;
        output.depthBiasSlopeFactor = resolved->depthBiasSlopeFactor;
        output.lineWidth = resolved->lineWidth;
        output.depthTestEnabled = resolved->depthTestEnabled;
        output.depthWriteEnabled = resolved->depthWriteEnabled;
        output.depthCompare = resolved->depthCompare;
        output.depthBoundsTestEnabled = resolved->depthBoundsTestEnabled;
        output.minDepthBounds = resolved->minDepthBounds;
        output.maxDepthBounds = resolved->maxDepthBounds;
        output.stencilEnabled = resolved->stencilEnabled;
        output.frontStencilState = resolved->frontStencilState;
        output.backStencilState = resolved->backStencilState;
        output.logicOpEnabled = resolved->logicOpEnabled;
        output.logicOp = resolved->logicOp;
        output.depthClampEnabled = resolved->depthClampEnabled;
        output.backStencilState = resolved->backStencilState;

        output.blendStatesOffset = dynamicDataBlob.iterator;
        output.blendStatesCount = 8 * sizeof(BlendState);
        for (int i = 0; i < 8; i++)
        {
            const BlendState& state = resolved->blendStates[i];
            dynamicDataBlob.Write(state);
        }

        writer.WriteType(output);
    }
    else if (symbol->symbolType == Symbol::SamplerStateType)
    {
        SamplerState::__Resolved* resolved = static_cast<SamplerState::__Resolved*>(symbol->resolved);
        Serialize::SamplerState output;

        output.nameLength = symbol->name.length();
        output.nameOffset = dynamicDataBlob.Write(symbol->name.c_str(), symbol->name.length());
        output.addressU = resolved->addressU;
        output.addressV = resolved->addressV;
        output.addressW = resolved->addressW;
        output.minFilter = resolved->minFilter;
        output.magFilter = resolved->magFilter;
        output.mipFilter = resolved->mipFilter;
        output.mipLodBias = resolved->mipLodBias;
        output.anisotropicEnabled = resolved->anisotropicEnabled;
        output.maxAnisotropy = resolved->maxAnisotropy;
        output.compareSamplerEnabled = resolved->compareSamplerEnabled;
        output.compareMode = resolved->compareMode;
        output.minLod = resolved->minLod;
        output.maxLod = resolved->maxLod;
        output.borderColor = resolved->borderColor;
        output.unnormalizedSamplingEnabled = resolved->unnormalizedSamplingEnabled;

        writer.WriteType(output);
    }
    else if (symbol->symbolType == Symbol::StructureType)
    {
        Structure* structure = static_cast<Structure*>(symbol);
        Structure::__Resolved* resolved = static_cast<Structure::__Resolved*>(symbol->resolved);
        Serialize::Structure output;
        output.isConst = false;
        output.isMutable = false;
        output.binding = resolved->binding;
        output.group = resolved->group;
        output.nameLength = symbol->name.length();
        output.nameOffset = dynamicDataBlob.Write(symbol->name.c_str(), symbol->name.length());
        output.size = resolved->byteSize;
        if (resolved->usageFlags.flags.isConstantBuffer)
        {
            output.isConst = true;
        }
        else if (resolved->usageFlags.flags.isStorageBuffer)
        {
            output.isMutable = true;
        }

        // start serializing variables
        output.variablesOffset = dynamicDataBlob.Reserve<Serialize::Variable>(structure->members.size());
        output.variablesCount = structure->members.size();

        size_t offset = output.variablesOffset;
        for (Variable* var : structure->members)
        {
            Variable::__Resolved* resolved = static_cast<Variable::__Resolved*>(var->resolved);
            Serialize::Variable varOutput;
            varOutput.binding = -1;
            varOutput.group = -1;
            varOutput.nameLength = var->name.length();
            varOutput.nameOffset = dynamicDataBlob.Write(var->name.c_str(), var->name.length());
            varOutput.byteSize = resolved->byteSize;
            varOutput.structureOffset = resolved->structureOffset;
            varOutput.isArray = var->isArray;
            varOutput.arraySize = resolved->arraySize;

            // write variable
            dynamicDataBlob.WriteReserved(varOutput, offset);
            offset += sizeof(Serialize::Variable);
        }

        // end serializing variables

        output.annotationsOffset = dynamicDataBlob.Reserve<Serialize::Annotation>(structure->annotations.size());
        output.annotationsCount = structure->annotations.size();

        size_t annotOffset = output.annotationsOffset;
        for (const Annotation& annot : structure->annotations)
        {
            WriteAnnotation(this, annot, annotOffset, dynamicDataBlob);
            annotOffset += sizeof(Serialize::Annotation);
        }

        writer.WriteType(output);
    }
    else if (symbol->symbolType == Symbol::VariableType)
    {
        Variable* var = static_cast<Variable*>(symbol);
        Variable::__Resolved* resolved = static_cast<Variable::__Resolved*>(symbol->resolved);
        Serialize::Variable output;
        output.binding = resolved->binding;
        output.group = resolved->group;
        output.isArray = var->isArray;
        output.arraySize = resolved->arraySize;
        output.nameLength = symbol->name.length();
        output.nameOffset = dynamicDataBlob.Write(symbol->name.c_str(), symbol->name.length());
        output.byteSize = resolved->byteSize;
        output.structureOffset = resolved->structureOffset;

        output.annotationsOffset = dynamicDataBlob.Reserve<Serialize::Annotation>(var->annotations.size());
        output.annotationsCount = var->annotations.size();

        size_t offset = output.annotationsOffset;
        for (const Annotation& annot : var->annotations)
        {
            WriteAnnotation(this, annot, offset, dynamicDataBlob);
            offset += sizeof(Serialize::Annotation);
        }

        writer.WriteType(output);
    }
}

} // namespace AnyFX
//------------------------------------------------------------------------------
//  @file glslgenerator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "glslgenerator.h"
#include "ast/symbol.h"
#include "ast/function.h"
#include "ast/structure.h"
#include "ast/variable.h"
#include "ast/program.h"
#include "ast/expressions/initializerexpression.h"
#include "ast/expressions/callexpression.h"

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

#include "glslang/Include/ResourceLimits.h"
#include "glslang/Public/ShaderLang.h"
#define ENABLE_OPT 1
#include "SPIRV/GlslangToSpv.h"
#include "SPIRV/SpvTools.h"
#include "spirv-tools/optimizer.hpp"

TBuiltInResource DefaultResources;

void SetupDefaultResources()
{
    DefaultResources.maxLights = 32;
    DefaultResources.maxClipPlanes = 6;
    DefaultResources.maxTextureUnits = 32;
    DefaultResources.maxTextureCoords = 32;
    DefaultResources.maxVertexAttribs = 64;
    DefaultResources.maxVertexUniformComponents = 4096;
    DefaultResources.maxVaryingFloats = 64;
    DefaultResources.maxVertexTextureImageUnits = 32;
    DefaultResources.maxCombinedTextureImageUnits = 80;
    DefaultResources.maxTextureImageUnits = 32;
    DefaultResources.maxFragmentUniformComponents = 4096;
    DefaultResources.maxDrawBuffers = 32;
    DefaultResources.maxVertexUniformVectors = 128;
    DefaultResources.maxVaryingVectors = 8;
    DefaultResources.maxFragmentUniformVectors = 16;
    DefaultResources.maxVertexOutputVectors = 16;
    DefaultResources.maxFragmentInputVectors = 15;
    DefaultResources.minProgramTexelOffset = -8;
    DefaultResources.maxProgramTexelOffset = 7;
    DefaultResources.maxClipDistances = 8;
    DefaultResources.maxComputeWorkGroupCountX = 65535;
    DefaultResources.maxComputeWorkGroupCountY = 65535;
    DefaultResources.maxComputeWorkGroupCountZ = 65535;
    DefaultResources.maxComputeWorkGroupSizeX = 1024;
    DefaultResources.maxComputeWorkGroupSizeY = 1024;
    DefaultResources.maxComputeWorkGroupSizeZ = 64;
    DefaultResources.maxComputeUniformComponents = 1024;
    DefaultResources.maxComputeTextureImageUnits = 16;
    DefaultResources.maxComputeImageUniforms = 8;
    DefaultResources.maxComputeAtomicCounters = 8;
    DefaultResources.maxComputeAtomicCounterBuffers = 1;
    DefaultResources.maxVaryingComponents = 60;
    DefaultResources.maxVertexOutputComponents = 64;
    DefaultResources.maxGeometryInputComponents = 64;
    DefaultResources.maxGeometryOutputComponents = 128;
    DefaultResources.maxFragmentInputComponents = 128;
    DefaultResources.maxImageUnits = 8;
    DefaultResources.maxCombinedImageUnitsAndFragmentOutputs = 8;
    DefaultResources.maxCombinedShaderOutputResources = 8;
    DefaultResources.maxImageSamples = 0;
    DefaultResources.maxVertexImageUniforms = 0;
    DefaultResources.maxTessControlImageUniforms = 0;
    DefaultResources.maxTessEvaluationImageUniforms = 0;
    DefaultResources.maxGeometryImageUniforms = 0;
    DefaultResources.maxFragmentImageUniforms = 8;
    DefaultResources.maxCombinedImageUniforms = 8;
    DefaultResources.maxGeometryTextureImageUnits = 16;
    DefaultResources.maxGeometryOutputVertices = 256;
    DefaultResources.maxGeometryTotalOutputComponents = 1024;
    DefaultResources.maxGeometryUniformComponents = 1024;
    DefaultResources.maxGeometryVaryingComponents = 64;
    DefaultResources.maxTessControlInputComponents = 128;
    DefaultResources.maxTessControlOutputComponents = 128;
    DefaultResources.maxTessControlTextureImageUnits = 16;
    DefaultResources.maxTessControlUniformComponents = 1024;
    DefaultResources.maxTessControlTotalOutputComponents = 4096;
    DefaultResources.maxTessEvaluationInputComponents = 128;
    DefaultResources.maxTessEvaluationOutputComponents = 128;
    DefaultResources.maxTessEvaluationTextureImageUnits = 16;
    DefaultResources.maxTessEvaluationUniformComponents = 1024;
    DefaultResources.maxTessPatchComponents = 120;
    DefaultResources.maxPatchVertices = 32;
    DefaultResources.maxTessGenLevel = 64;
    DefaultResources.maxViewports = 16;
    DefaultResources.maxVertexAtomicCounters = 0;
    DefaultResources.maxTessControlAtomicCounters = 0;
    DefaultResources.maxTessEvaluationAtomicCounters = 0;
    DefaultResources.maxGeometryAtomicCounters = 0;
    DefaultResources.maxFragmentAtomicCounters = 8;
    DefaultResources.maxCombinedAtomicCounters = 8;
    DefaultResources.maxAtomicCounterBindings = 1;
    DefaultResources.maxVertexAtomicCounterBuffers = 0;
    DefaultResources.maxTessControlAtomicCounterBuffers = 0;
    DefaultResources.maxTessEvaluationAtomicCounterBuffers = 0;
    DefaultResources.maxGeometryAtomicCounterBuffers = 0;
    DefaultResources.maxFragmentAtomicCounterBuffers = 1;
    DefaultResources.maxCombinedAtomicCounterBuffers = 1;
    DefaultResources.maxAtomicCounterBufferSize = 16384;
    DefaultResources.maxTransformFeedbackBuffers = 4;
    DefaultResources.maxTransformFeedbackInterleavedComponents = 64;
    DefaultResources.maxCullDistances = 8;
    DefaultResources.maxCombinedClipAndCullDistances = 8;
    DefaultResources.maxSamples = 4;

    DefaultResources.limits.nonInductiveForLoops = 1;
    DefaultResources.limits.whileLoops = 1;
    DefaultResources.limits.doWhileLoops = 1;
    DefaultResources.limits.generalUniformIndexing = 1;
    DefaultResources.limits.generalAttributeMatrixVectorIndexing = 1;
    DefaultResources.limits.generalVaryingIndexing = 1;
    DefaultResources.limits.generalSamplerIndexing = 1;
    DefaultResources.limits.generalVariableIndexing = 1;
    DefaultResources.limits.generalConstantMatrixVectorIndexing = 1;
}


namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
GLSLGenerator::GLSLGenerator(LanguageFeatureSet featureSet)
    : featureSet(featureSet)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
bool
GLSLGenerator::Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc)
{
    SetupDefaultResources();

    static const std::map<Program::__Resolved::ProgramEntryType, EShLanguage> entryToGlslangShaderMappings =
    {
        { Program::__Resolved::VertexShader, EShLangVertex },
        { Program::__Resolved::HullShader, EShLangTessControl },
        { Program::__Resolved::DomainShader, EShLangTessEvaluation },
        { Program::__Resolved::GeometryShader, EShLangGeometry },
        { Program::__Resolved::PixelShader, EShLangFragment },
        { Program::__Resolved::ComputeShader, EShLangCompute },
        { Program::__Resolved::RayGenerationShader, EShLangRayGen },
        { Program::__Resolved::RayMissShader, EShLangMiss },
        { Program::__Resolved::RayHitShader, EShLangIntersect },
        { Program::__Resolved::RayClosestHitShader, EShLangClosestHit },
        { Program::__Resolved::RayAnyHitShader, EShLangAnyHit },
        { Program::__Resolved::RayIntersectionShader, EShLangIntersect }
    };

    Program::__Resolved* progResolved = static_cast<Program::__Resolved*>(program->resolved);
    std::vector<glslang::TShader*> shaders;
    for (auto it : progResolved->programMappings)
    {
        // for each shader, generate code and use it as a binary output
        if (it.first >= Program::__Resolved::VertexShader && it.first <= Program::__Resolved::RayIntersectionShader)
        {
            std::string code;
            this->mainFunction = static_cast<Function*>(it.second);
            for (Symbol* symbol : symbols)
            {
                switch (symbol->symbolType)
                {
                case Symbol::SymbolType::FunctionType:
                    this->GenerateFunction(compiler, program, symbol, code);
                    break;
                case Symbol::SymbolType::StructureType:
                    this->GenerateStructure(compiler, program, symbol, code);
                    break;
                case Symbol::SymbolType::VariableType:
                    this->GenerateVariable(compiler, program, symbol, code, false);
                    break;
                }
            }

            if (!map_contains(entryToGlslangShaderMappings, it.first))
            {
                compiler->Error(Format("Internal error, no known mapping of shader '%s'", Program::__Resolved::EntryTypeToString(it.first).c_str()), program);
                return false;
            }

            EShMessages messages = (EShMessages)(EShMsgDefault | EShMsgRelaxedErrors | EShMsgSpvRules | (this->featureSet == VulkanFeatureSet ? EShMsgVulkanRules : 0x0));

            // add platform specific message output
#if defined(_MSC_VER)
            messages = (EShMessages)(messages | EShMsgMSVCFormat);
#elif defined(__GNUC__) || defined(__clang__)
            messages = (EShMessages)(messages | EShMsgClangGCCFormat);
#endif

            std::string header;
            if (this->featureSet == OpenGLFeatureSet)
            {
                header = "\
#version 460 core\n\
#define gl_InstanceID gl_InstanceIndex\n\
#define gl_VertexID gl_VertexIndex\n\
#extension GL_GOOGLE_cpp_style_line_directive : enable\n\
#extension GL_ARB_separate_shader_objects : enable\n\
#extension GL_ARB_shading_language_420pack : enable\n\
#extension GL_KHR_shader_subgroup_quad : enable\n\
#define OPENGL\n";
            }
            else if (this->featureSet == VulkanFeatureSet)
            {
                header = "\
#version 460 core\n\
#define gl_InstanceID gl_InstanceIndex\n\
#define gl_VertexID gl_VertexIndex\n\
#extension GL_GOOGLE_cpp_style_line_directive : enable\n\
#extension GL_ARB_separate_shader_objects : enable\n\
#extension GL_ARB_shading_language_420pack : enable\n\
#extension GL_KHR_shader_subgroup_quad : enable\n\
#define SPIRV\n";
            }

            glslang::TShader* shaderObject = new glslang::TShader(entryToGlslangShaderMappings.at(it.first));
            const char* sources[] = { header.c_str(), code.c_str() };
            int lengths[] = { header.length(), code.length() };
            shaderObject->setStringsWithLengths(sources, lengths, 2);

            // perform compilation
            if (this->featureSet == OpenGLFeatureSet)
            {
                shaderObject->setEnvTarget(glslang::EShTargetSpv, glslang::EShTargetSpv_1_0);
                shaderObject->setEnvClient(glslang::EShClientOpenGL, glslang::EShTargetOpenGL_450);
            }
            else
            {
                shaderObject->setEnvTarget(glslang::EShTargetSpv, glslang::EShTargetSpv_1_3);
                shaderObject->setEnvClient(glslang::EShClientVulkan, glslang::EShTargetVulkan_1_2);
            }
            
            if (!shaderObject->parse(&DefaultResources, 460, EProfile::ENoProfile, false, true, messages))
            {
                std::string message = shaderObject->getInfoLog();
                compiler->GeneratorError(message);
                delete shaderObject;
                return false;
            }

            // run writer function
            if (writerFunc)
                writerFunc(program->name + "_" + this->mainFunction->name, std::string(sources[0]) + std::string(sources[1]));

            // add shaders to list
            shaders.push_back(shaderObject);
        }
    }

    // link program
    glslang::TProgram* programObject = new glslang::TProgram();
    for (glslang::TShader* shader : shaders)
    {
        programObject->addShader(shader);
    }

    EShMessages messages = EShMsgDefault;
    if (!programObject->link(messages))
    {
        std::string message = programObject->getInfoLog();
        compiler->GeneratorError(message);
        return false;
    }

    // build reflection to get uniform stuff
    bool refbuilt = programObject->buildReflection();
    assert(refbuilt);

    // run optimizations
    spvtools::Optimizer* optimizer = nullptr;
    if (this->featureSet == OpenGLFeatureSet)
        optimizer = new spvtools::Optimizer(SPV_ENV_OPENGL_4_5);
    else if (this->featureSet == VulkanFeatureSet)
        optimizer = new spvtools::Optimizer(SPV_ENV_VULKAN_1_2);
    
    optimizer->RegisterPerformancePasses();

    for (Program::__Resolved::ProgramEntryType i = Program::__Resolved::VertexShader; i < Program::__Resolved::RayIntersectionShader; i = (Program::__Resolved::ProgramEntryType)((int)i + 1))
    {
        glslang::TIntermediate* intermediate = programObject->getIntermediate(entryToGlslangShaderMappings.at(i));
        if (intermediate != NULL)
        {
            glslang::SpvOptions options;
            options.disableOptimizer = false;
            options.optimizeSize = true;

            std::vector<uint32_t> binary;
            glslang::GlslangToSpv(*intermediate, binary);

            std::vector<uint32_t> optimized;
            optimizer->Run(binary.data(), binary.size(), &optimized);

            // copy binary to program
            progResolved->binaries[i] = optimized;
        }
    }

    // cleanup
    delete optimizer;
    delete programObject;

    for (glslang::TShader* shader : shaders)
    {
        delete shader;
    }
    return true;
}

struct TypeDimensions
{
    unsigned int x, y;
};

std::map<std::string, TypeDimensions> typeToDimensions =
{
    { "float",      { 1, 1 } },
    { "float2",     { 2, 1 } },
    { "float3",     { 3, 1 } },
    { "float4",     { 4, 1 } },
    { "int",        { 1, 1 } },
    { "int2",       { 2, 1 } },
    { "int3",       { 3, 1 } },
    { "int4",       { 4, 1 } },
    { "uint",       { 1, 1 } },
    { "uint2",      { 2, 1 } },
    { "uint3",      { 3, 1 } },
    { "uint4",      { 4, 1 } },
    { "bool",       { 1, 1 } },
    { "bool2",      { 2, 1 } },
    { "bool3",      { 3, 1 } },
    { "bool4",      { 4, 1 } },
    { "float2x2",   { 2, 2 } },
    { "float2x3",   { 2, 3 } },
    { "float2x4",   { 2, 4 } },
    { "float3x2",   { 3, 2 } },
    { "float3x3",   { 3, 3 } },
    { "float3x4",   { 3, 4 } },
    { "float4x2",   { 4, 2 } },
    { "float4x3",   { 4, 3 } },
    { "float4x4",   { 4, 4 } }
};

// type being the underlying base type (float2x2 -> float)
std::map<std::string, unsigned int> typeToByteSize =
{
    { "float",      4 },
    { "float2",     4 },
    { "float3",     4 },
    { "float4",     4 },
    { "int",        4 },
    { "int2",       4 },
    { "int3",       4 },
    { "int4",       4 },
    { "uint",       4 },
    { "uint2",      4 },
    { "uint3",      4 },
    { "uint4",      4 },
    { "bool",       1 },
    { "bool2",      1 },
    { "bool3",      1 },
    { "bool4",      1 },
    { "float2x2",   4 },
    { "float2x3",   4 },
    { "float2x4",   4 },
    { "float3x2",   4 },
    { "float3x3",   4 },
    { "float3x4",   4 },
    { "float4x2",   4 },
    { "float4x3",   4 },
    { "float4x4",   4 },
};

//------------------------------------------------------------------------------
/**
*/
uint32_t
RoundToPow2(uint32_t value, uint32_t power)
{
    return value = (value + power - 1) & ~(power - 1);
}

//------------------------------------------------------------------------------
/**
    Calculate the alignment and byte size for a type
*/
void
CalculateLayout(Compiler* compiler, Variable* var, uint32_t arraySize, const bool std140, uint32_t& size, uint32_t& alignment, uint32_t& arrayElementPadding)
{
    Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
    TypeDimensions dimensions = typeToDimensions[var->type.name];
    uint32_t byteSize = typeToByteSize[var->type.name];
    const uint32_t vec4alignment = 16;
    arrayElementPadding = 0;

    /*
    1.  If the member is a scalar consuming N basic machine units, the base alignment is N.
    2.  If the member is a two- or four-component vector with components consuming N basic machine units, the base alignment is 2N or 4N, respectively.
    3.  If the member is a three-component vector with components consuming N basic machine units, the base alignment is 4N.
    4.  If the member is an array of scalars or vectors, the base alignment and array stride are set to match the base alignment of a single array element,
        according to rules (1), (2), and (3), and rounded up to the base alignment of a vec4. The array may have padding at the end;
        the base offset of the member following the array is rounded up to the next multiple of the base alignment.
    5.  If the member is a column-major matrix with C columns and R rows, the matrix is stored identically to an array of C column vectors with R
        components each, according to rule (4).
    6.  If the member is an array of S column-major matrices with C columns and R rows, the matrix is stored identically to a row of
        S�C column vectors with R components each, according to rule (4).
    7.  If the member is a row-major matrix with C columns and R rows, the matrix is stored identically to an array of R row vectors with C components each,
        according to rule (4).
    8.  If the member is an array of S row-major matrices with C columns and R rows, the matrix is stored identically to a row of S�R row vectors with C
        components each, according to rule (4).
    9.  If the member is a structure, the base alignment of the structure is N, where N is the largest base alignment value of any of its members,
        and rounded up to the base alignment of a vec4. The individual members of this sub-structure are then assigned offsets by applying this set of
        rules recursively, where the base offset of the first member of the sub-structure is equal to the aligned offset of the structure.
        The structure may have padding at the end; the base offset of the member following the sub-structure is
        rounded up to the next multiple of the base alignment of the structure.
    10. If the member is an array of S structures, the S elements of the array are laid out in order, according to rule
    For std430, rounding up to vec4 in rule 4 and 9 is not relevant
    */

    switch (dimensions.x)
    {
    case 0:
        break;
    case 1:
        alignment = byteSize;
        size = byteSize;
        break;
    case 2:
        alignment = byteSize * 2;
        size = byteSize * 2;
        break;
    case 3:
        alignment = byteSize * 4;
        size = byteSize * 3;
        break;
    case 4:
        alignment = byteSize * 4;
        size = byteSize * 4;
        break;
    default:
        // should never happen
        alignment = byteSize;
        size = byteSize;
        break;
    }

    if (arraySize > 1)
    {
        // array case
        CalculateLayout(compiler, var, 1, std140, size, alignment, arrayElementPadding);
        uint32_t baseAlignment = alignment;
        if (std140)
            alignment = max(vec4alignment, alignment);

        // element padding is the difference between size and alignment
        if (std140)
            arrayElementPadding = size % alignment;

        // the final size is the size per element + element padding * number of elements
        size = (size + arrayElementPadding) * arraySize;
    }
    else if (varResolved->typeSymbol->symbolType == Symbol::StructureType)
    {
        // struct case
        Structure* struc = static_cast<Structure*>(varResolved->typeSymbol);
        Structure::__Resolved* strucResolved = static_cast<Structure::__Resolved*>(struc->resolved);
        alignment = strucResolved->baseAlignment;
        size = strucResolved->byteSize;
    }
    else if (dimensions.y > 1)
    {
        // matrix case
        if (std140)
            alignment = max(vec4alignment, alignment);
        size = RoundToPow2(size, alignment);
        size *= dimensions.y;
    }
}

std::map<std::string, std::string> typeToGlslType =
{
    { "readWriteTexture1D", "image1D" },
    { "readWriteTexture2D", "image2D" },
    { "readWriteTexture2DMS", "image2DMS" },
    { "readWriteTextureCube", "imageCube" },
    { "readWriteTexture3D", "image3D" },
    { "readWriteTexture1DArray", "image1DArray" },
    { "readWriteTexture2DArray", "image2DArray" },
    { "readWriteTexture2DMSArray", "image2DMSArray" },
    { "readWriteTextureCubeArray", "imageCubeArray" },
    { "texture1D", "texture1D" },
    { "texture2D", "texture2D" },
    { "texture2DMS", "texture2DMS" },
    { "textureCube", "textureCube" },
    { "texture3D", "texture3D" },
    { "texture1DArray", "texture1DArray" },
    { "texture2DArray", "texture2DArray" },
    { "texture2DMSArray", "texture2DMSArray" },
    { "textureCubeArray", "textureCubeArray" },
    { "sampledTexture1D", "sampler1D" },
    { "sampledTexture2D", "sampler2D" },
    { "sampledTexture2DMS", "sampler2DMS" },
    { "sampledTextureCube", "samplerCube" },
    { "sampledTexture3D", "sampler3D" },
    { "sampledTexture1DArray", "sampler1DArray" },
    { "sampledTexture2DArray", "sampler2DArray" },
    { "sampledTexture2DMSArray", "sampler2DMSArray" },
    { "sampledTextureCubeArray", "samplerCubeArray" },
    { "inputAttachment", "subpassInput" },
    { "inputAttachmentMS", "subpassInputMS" },
    { "float", "float" },
    { "float2", "vec2" },
    { "float3", "vec3" },
    { "float4", "vec4" },
    { "int", "int" },
    { "int2", "ivec2" },
    { "int3", "ivec3" },
    { "int4", "ivec4" },
    { "uint", "uint" },
    { "uint2", "uvec2" },
    { "uint3", "uvec3" },
    { "uint4", "uvec4" },
    { "bool", "bool" },
    { "bool2", "bvec2" },
    { "bool3", "bvec3" },
    { "bool4", "bvec4" },
    { "float2x2", "mat2" },
    { "float2x3", "mat2x3" },
    { "float2x4", "mat2x4" },
    { "float3x2", "mat3x2" },
    { "float3x3", "mat3" },
    { "float3x4", "mat3x4" },
    { "float4x2", "mat4x2" },
    { "float4x3", "mat4x3" },
    { "float4x4", "mat4" },
    { "sampler", "sampler" },
    { "void", "void" }
};

std::map<Variable::ImageFormat, std::string> imageFormatToGlsl =
{
    { Variable::ImageFormat::RGBA16, "rgba16" },
    { Variable::ImageFormat::RGB10_A2, "rgb10_a2" },
    { Variable::ImageFormat::RGBA8, "rgba8" },
    { Variable::ImageFormat::RG16, "rg16" },
    { Variable::ImageFormat::RG8, "rg8" },
    { Variable::ImageFormat::R16, "r16" },
    { Variable::ImageFormat::R8, "r8" },
    { Variable::ImageFormat::RGBA16_SNORM, "rgba16_snorm" },
    { Variable::ImageFormat::RGBA8_SNORM, "rgba8_snorm" },
    { Variable::ImageFormat::RG16_SNORM, "rg16_snorm" },
    { Variable::ImageFormat::RG8_SNORM, "rg8_snorm" },
    { Variable::ImageFormat::R16_SNORM, "r16_snorm" },
    { Variable::ImageFormat::R8_SNORM, "r8_snorm" },
    { Variable::ImageFormat::RGBA32F, "rgba32f" },
    { Variable::ImageFormat::RGBA16F, "rgba16f" },
    { Variable::ImageFormat::RG32F, "rg32f" },
    { Variable::ImageFormat::RG16F, "rg16f" },
    { Variable::ImageFormat::R11G11B10F, "r11f_g11f_b10f" },
    { Variable::ImageFormat::R32F, "r32f" },
    { Variable::ImageFormat::R16F, "r16f" },
    { Variable::ImageFormat::RGA32I, "rga32i" },
    { Variable::ImageFormat::RGBA16I, "rgba16i" },
    { Variable::ImageFormat::RGBA8I, "rgba8i" },
    { Variable::ImageFormat::RG32I, "rg32i" },
    { Variable::ImageFormat::RG16I, "rg16i" },
    { Variable::ImageFormat::RG8I, "rg8i" },
    { Variable::ImageFormat::R32I, "r32i" },
    { Variable::ImageFormat::R16I, "r16i" },
    { Variable::ImageFormat::R8I, "r8i" },
    { Variable::ImageFormat::RGA32U, "rga32ui" },
    { Variable::ImageFormat::RGBA16U, "rgba16ui" },
    { Variable::ImageFormat::RGB10_A2U, "rgb10_a2ui" },
    { Variable::ImageFormat::RGBA8U, "rgba8ui" },
    { Variable::ImageFormat::RG32U, "rg32ui" },
    { Variable::ImageFormat::RG16U, "rg16ui" },
    { Variable::ImageFormat::RG8U, "rg8ui" },
    { Variable::ImageFormat::R32U, "r32ui" },
    { Variable::ImageFormat::R16U, "r16ui" },
    { Variable::ImageFormat::R8U, "r8ui" }
};

void GenerateExpressionGLSL(Compiler* compiler, Expression* expr, std::string& outCode);

//------------------------------------------------------------------------------
/**
*/
void
GenerateCallExpressionGLSL(Compiler* compiler, Expression* expr, std::string& outCode)
{
    CallExpression* callExpression = static_cast<CallExpression*>(expr);
    std::string fun;
    callExpression->EvalSymbol(compiler, fun);
    auto it = typeToGlslType.find(fun);
    if (it != typeToGlslType.end())
    {
        fun = it->second;
    }

    std::string args;
    for (Expression* arg : callExpression->args)
    {
        std::string str;
        GenerateExpressionGLSL(compiler, arg, str);
        args.append(str);
        if (arg != callExpression->args.back())
            args.append(", ");
    }
    outCode.append(Format("%s(%s)", fun.c_str(), args.c_str()));
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateInitializerExpressionGLSL(Compiler* compiler, Expression* expr, std::string& outCode)
{
    std::string inner;
    InitializerExpression* initExpression = static_cast<InitializerExpression*>(expr);
    for (Expression* expr : initExpression->values)
    {
        if (expr->symbolType == Symbol::InitializerExpressionType)
            GenerateInitializerExpressionGLSL(compiler, expr, inner);
        else
        {
            Type::FullType type;
            if (!expr->EvalType(compiler, type))
            {
                compiler->Error(Format("INTERNAL ERROR IN '%s' LINE '%s'", __FILE__, __LINE__), expr);
            }

            GenerateExpressionGLSL(compiler, expr, inner);
            if (expr != initExpression->values.back())
                inner.append(",");
        }
    }
    outCode = Format("{ %s }", inner.c_str());
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateExpressionGLSL(Compiler* compiler, Expression* expr, std::string& outCode)
{
    switch (expr->symbolType)
    {
        // call expression might have to change constructor types
        case Symbol::CallExpressionType:
            GenerateCallExpressionGLSL(compiler, expr, outCode);
            break;
        case Symbol::InitializerExpressionType:
            GenerateInitializerExpressionGLSL(compiler, expr, outCode);
            break;
        default:
            outCode.append(expr->EvalString(compiler));
            break;
    }
}

void GenerateStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode);

//------------------------------------------------------------------------------
/**
*/
void
GenerateVariableGLSL(Compiler* compiler, Variable* var, std::string& outCode)
{
    Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);

    std::string type;
    if (varResolved->typeSymbol->symbolType == Symbol::StructureType)
        type = varResolved->type.name;
    else
        type = typeToGlslType[varResolved->type.name];

    if (varResolved->value != nullptr)
    {
        std::string value;
        GenerateExpressionGLSL(compiler, varResolved->value, value);
        outCode.append(Format("%s %s = %s", type.c_str(), varResolved->name.c_str(), value.c_str()));
    }
    else
    {
        outCode.append(Format("%s %s", type.c_str(), varResolved->name.c_str()));
    }
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateForStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode)
{
    ForStatement* forStatement = static_cast<ForStatement*>(statement);
    Variable* var = static_cast<Variable*>(forStatement->declaration);
    std::string declarations;
    if (var != nullptr)
    {
        Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);

        GenerateVariableGLSL(compiler, var, declarations);

        for (Variable* sibling : varResolved->siblings)
        {
            declarations.append(",");
            GenerateVariableGLSL(compiler, sibling, declarations);
        }
    }

    std::string conditions = "";
    if (forStatement->condition != nullptr)
        GenerateExpressionGLSL(compiler, forStatement->condition, conditions);

    std::string endOfLoopStatement = "";
    if (forStatement->statement != nullptr)
        GenerateStatementGLSL(compiler, forStatement->statement, endOfLoopStatement);

    std::string contents = "";
    GenerateStatementGLSL(compiler, forStatement->contents, contents);

    outCode.append(Format("for (%s;%s;%s)\n{\n\t%s\n}", declarations.c_str(), conditions.c_str(), endOfLoopStatement.c_str(), contents.c_str()));
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateIfStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode)
{
    IfStatement* ifStatement = static_cast<IfStatement*>(statement);
    std::string condition;
    GenerateExpressionGLSL(compiler, ifStatement->condition, condition);

    std::string ifBody;
    GenerateStatementGLSL(compiler, ifStatement->ifStatement, ifBody);

    std::string elseBody = "";
    if (ifStatement->elseStatement)
    {
        elseBody = "else";
        GenerateStatementGLSL(compiler, ifStatement->elseStatement, elseBody);
    }

    outCode.append(Format("if (%s) %s%s", condition.c_str(), ifBody.c_str(), elseBody.c_str()));
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateReturnStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode)
{
    ReturnStatement* returnStatement = static_cast<ReturnStatement*>(statement);
    if (returnStatement->returnValue != nullptr)
    {
        std::string val;
        GenerateExpressionGLSL(compiler, returnStatement->returnValue, val);
        outCode.append(Format("return %s;", val.c_str()));
    }
    else
    {
        outCode.append("return;");
    }
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateScopeStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode)
{
    ScopeStatement* scope = static_cast<ScopeStatement*>(statement);
    std::string contents;
    for (Symbol* content : scope->statements)
    {
        if (content->symbolType == Symbol::VariableType)
            GenerateVariableGLSL(compiler, static_cast<Variable*>(content), contents);
        else
            GenerateStatementGLSL(compiler, static_cast<Statement*>(content), contents);
    }
    outCode.append(Format("{%s}", contents.c_str()));
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateSwitchStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode)
{
    SwitchStatement* switchStatement = static_cast<SwitchStatement*>(statement);

    std::string expr;
    GenerateExpressionGLSL(compiler, switchStatement->switchExpression, expr);

    std::string cases;
    for (size_t i = 0; i < switchStatement->caseValues.size(); i++)
    {
        std::string caseValue = switchStatement->caseValues[i];
        std::string caseStatement;
        GenerateStatementGLSL(compiler, switchStatement->caseStatements[i], caseStatement);
        cases.append(Format("case %s:\n%s", caseValue.c_str(), caseStatement.c_str()));
    }

    if (switchStatement->defaultStatement != nullptr)
    {
        std::string defaultStatement;
        GenerateStatementGLSL(compiler, switchStatement->defaultStatement, defaultStatement);
        cases.append(Format("default:\n%s", defaultStatement.c_str()));
    }

    outCode.append(Format("switch (%s)\n{\n\t%s\n}", expr.c_str(), cases.c_str()));
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateWhileStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode)
{
    WhileStatement* whileStatement = static_cast<WhileStatement*>(statement);

    std::string cond;
    GenerateExpressionGLSL(compiler, whileStatement->condition, cond);

    std::string body;
    GenerateStatementGLSL(compiler, whileStatement->statement, body);

    if (whileStatement->isDoWhile)
    {
        outCode.append(Format("do \n{\n\t%s\n} while (%s)", body.c_str(), cond.c_str()));
    }
    else
    {
        outCode.append(Format("while (%s)\n{\n\t%s\n}", cond.c_str(), body.c_str()));
    }
}

//------------------------------------------------------------------------------
/**
*/
void
GenerateStatementGLSL(Compiler* compiler, Statement* statement, std::string& outCode)
{
    switch (statement->symbolType)
    {
        case Symbol::BreakStatementType:
            outCode.append("break;");
            break;
        case Symbol::ContinueStatementType:
            outCode.append("continue;");
            break;
        case Symbol::ExpressionStatementType:
            GenerateExpressionGLSL(compiler, static_cast<ExpressionStatement*>(statement)->expr, outCode);
            outCode.append(";");
            break;
        case Symbol::ForStatementType:
            GenerateForStatementGLSL(compiler, statement, outCode);
            break;
        case Symbol::IfStatementType:
            GenerateIfStatementGLSL(compiler, statement, outCode);
            break;
        case Symbol::ReturnStatementType:
            GenerateReturnStatementGLSL(compiler, statement, outCode);
            break;
        case Symbol::ScopeStatementType:
            GenerateScopeStatementGLSL(compiler, statement, outCode);
            break;
        case Symbol::SwitchStatementType:
            GenerateSwitchStatementGLSL(compiler, statement, outCode);
            break;
        case Symbol::WhileStatementType:
            GenerateWhileStatementGLSL(compiler, statement, outCode);
            break;
    }
}

//------------------------------------------------------------------------------
/**
*/
void 
GLSLGenerator::GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
    Function* fun = static_cast<Function*>(symbol);
    Function::__Resolved* funResolved = static_cast<Function::__Resolved*>(fun->resolved);

    Program::__Resolved* progResolved = static_cast<Program::__Resolved*>(program->resolved);


    bool isMain = fun == this->mainFunction;

    // skip shader functions which are not shaders
    if (funResolved->shaderUsage.bits != 0x0 && !isMain)
        return;

    // convert typename to glsl
    Type::FullType returnType = fun->returnType;
    if (funResolved->returnTypeSymbol->symbolType != Symbol::StructureType)
        returnType.name = typeToGlslType[returnType.name];

    std::string body;
    if (funResolved->isPrototype)
    {
        if (map_contains(progResolved->functionOverrides, fun))
            body = progResolved->functionOverrides[fun]->body;
        else
        {
            compiler->Warning(Format("Prototype function '%s' is not bound for program '%s'", fun->name.c_str(), program->name.c_str()), fun);
            return;
        }
    }
    else
    {
        body = fun->body;
    }

    std::string arguments;
    for (Variable* param : fun->parameters)
    {
        this->GenerateVariable(compiler, program, param, arguments, isMain);

        if (!isMain)
        {
            if (param != fun->parameters.back())
                arguments.append(", ");
        }
        else
        {
            arguments.append(";\n");
        }
    }
    std::string name = isMain ? "main" : fun->name;

    
    if (isMain)
    {
        outCode.append(Format("%s\n", arguments.c_str()));
        outCode.append(Format("#line %d %s\n", fun->location.line, fun->location.file.c_str()));
        outCode.append(Format("void %s()\
\n{\n\
    %s\
\n}\n\n",
        name.c_str(), body.c_str()));
    }
    else
    {
        outCode.append(Format("#line %d %s\n", fun->location.line, fun->location.file.c_str()));
        outCode.append(Format("%s %s(%s)\
\n{\n\
    %s\
\n}\n\n", 
       returnType.ToString(compiler).c_str(), name.c_str(), arguments.c_str(), body.c_str()));
    }
}

//------------------------------------------------------------------------------
/**
*/
void 
GLSLGenerator::GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
    Structure* struc = static_cast<Structure*>(symbol);
    Structure::__Resolved* strucResolved = static_cast<Structure::__Resolved*>(struc->resolved);

    // format variables
    std::string members;
    uint32_t maxAlignment = strucResolved->usageFlags.flags.isConstantBuffer ? 16 : 0;
    uint32_t offset = 0;
    for (Variable* var : struc->members)
    {
        Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);

        // calculate GLSL alignment
        uint32_t size;
        uint32_t alignment;
        uint32_t arrayElementPadding;
        CalculateLayout(compiler, var, varResolved->arraySize, strucResolved->usageFlags.flags.isConstantBuffer ? true : false, size, alignment, arrayElementPadding);
        maxAlignment = max(alignment, maxAlignment);

        varResolved->byteSize = size;
        varResolved->elementPadding = arrayElementPadding;

        // calculate padding
        if (offset % alignment > 0)
        {
            int padding = alignment - (offset % alignment);
            offset += padding;
            varResolved->startPadding = padding;
        }

        // set offset within structure
        varResolved->structureOffset = offset;

        // progress to next variable
        offset += size;

        // generate code for variable
        this->GenerateVariable(compiler, program, var, members, false);
        if (var != struc->members.back())
            members.append("\n");
    }

    strucResolved->byteSize = offset;
    strucResolved->baseAlignment = maxAlignment;

    if (strucResolved->usageFlags.flags.isConstantBuffer)
    {
        outCode.append(Format("layout(std140, set=%d, binding=%d) ", strucResolved->group, strucResolved->binding));

        outCode.append(Format("uniform %s \n{\n%s\n};\n\n", struc->name.c_str(), members.c_str()));
    }
    else if (strucResolved->usageFlags.flags.isStorageBuffer)
    {
        outCode.append(Format("layout(std430, set=%d, binding=%d) ", strucResolved->group, strucResolved->binding));

        if (strucResolved->accessBits.flags.atomicAccess)
            outCode.append("coherent ");
        if (strucResolved->accessBits.flags.volatileAccess)
            outCode.append("volatile ");
        if (strucResolved->accessBits.flags.readAccess && strucResolved->accessBits.flags.writeAccess)
            outCode.append("restrict ");
        else
        {
            if (strucResolved->accessBits.flags.readAccess)
                outCode.append("readonly ");
            if (strucResolved->accessBits.flags.writeAccess)
                outCode.append("writeonly ");
        }

        outCode.append(Format("buffer %s \n{\n%s\n};\n\n", struc->name.c_str(), members.c_str()));
    }
    else
    {
        outCode.append(Format("struct %s \n{\n%s\n};\n\n", struc->name.c_str(), members.c_str()));
    }
}

//------------------------------------------------------------------------------
/**
*/
void 
GLSLGenerator::GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument)
{
    Variable* var = static_cast<Variable*>(symbol);
    Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);

    Type::FullType type = varResolved->type;
    if (varResolved->typeSymbol->symbolType != Symbol::StructureType)
    {
        auto it = typeToGlslType.find(type.name);
        if (it == typeToGlslType.end())
        {
            compiler->Error(Format("INTERNAL ERROR, built-in type '%s' has no GLSL mapping", type.name.c_str()), symbol);
        }
        type.name = it->second.c_str();

    }

    std::string name = varResolved->name;
    std::string arraySize = "";
    for (size_t i = 0; i < varResolved->type.modifiers.size(); i++)
    {
        uint32_t size = -1;
        if (varResolved->type.modifierExpressions[i] != nullptr)
        {
            varResolved->type.modifierExpressions[i]->EvalUInt(compiler, size);
            arraySize.append(Format("[%d]", size));
        }
        else
        {
            arraySize.append(Format("[]"));
        }
    }

    // format parameters
    if (varResolved->usageBits.flags.isParameter)
    {
        if (isShaderArgument)
        {
            outCode.append(Format("#line %d %s\n", var->location.line, var->location.file.c_str()));
            outCode.append(Format("layout(location=%d) ", varResolved->binding));
        }

        if (varResolved->parameterBits.flags.isIn && varResolved->parameterBits.flags.isOut)
            outCode.append("inout ");
        else
        {
            if (varResolved->parameterBits.flags.isIn)
                outCode.append("in ");
            if (varResolved->parameterBits.flags.isOut)
                outCode.append("out ");
        }

        if (varResolved->parameterBits.flags.isNoInterpolate)
            outCode.append("flat ");
        if (varResolved->parameterBits.flags.isNoPerspective)
            outCode.append("noperspective ");

        if (varResolved->parameterBits.flags.isPatch)
            outCode.append("patch ");

        outCode.append(Format("%s %s", type.name.c_str(), name.c_str()));
    }
    else if (varResolved->usageBits.flags.isConst)
    {
        std::string initializerStr;
        GenerateExpressionGLSL(compiler, varResolved->value, initializerStr);
        outCode.append(Format("const %s %s%s = %s;\n", type.name.c_str(), name.c_str(), arraySize.c_str(), initializerStr.c_str()));
    }
    else if (!varResolved->usageBits.flags.isConstantBufferMember && !varResolved->usageBits.flags.isStorageBufferMember && !varResolved->usageBits.flags.isStructMember)
    {
        outCode.append(Format("#line %d %s\n", var->location.line, var->location.file.c_str()));
        if (varResolved->typeSymbol->category == Type::ReadWriteTextureCategory)
        {
            outCode.append(Format("layout(set=%d, binding=%d, %s) ", varResolved->group, varResolved->binding, imageFormatToGlsl[varResolved->imageFormat].c_str()));

            // if integer or unsigned, format variable
            if (Variable::IsImageFormatInteger(varResolved->imageFormat))
                type.name = Format("i%s", type.name.c_str());
            else if (Variable::IsImageFormatUnsigned(varResolved->imageFormat))
                type.name = Format("u%s", type.name.c_str());
        }
        else
            outCode.append(Format("layout(set=%d, binding=%d) ", varResolved->group, varResolved->binding));

        if (varResolved->accessBits.flags.atomicAccess)
            outCode.append("coherent ");
        if (varResolved->accessBits.flags.volatileAccess)
            outCode.append("volatile ");
        if (varResolved->accessBits.flags.readAccess && varResolved->accessBits.flags.writeAccess)
            outCode.append("restrict ");
        else
        {
            if (varResolved->accessBits.flags.readAccess)
                outCode.append("readonly ");
            if (varResolved->accessBits.flags.writeAccess)
                outCode.append("writeonly ");
        }

        if (varResolved->usageBits.flags.isGroupShared)
            outCode.append("shared ");

        outCode.append(Format("uniform %s %s%s;\n", type.name.c_str(), name.c_str(), arraySize.c_str()));
    }
    else
    {
        outCode.append(Format("    %s %s%s;", type.name.c_str(), name.c_str(), arraySize.c_str()));
    }

}

} // namespace AnyFX

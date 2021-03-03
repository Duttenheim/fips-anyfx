//------------------------------------------------------------------------------
//  compiler.cc
//  (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "compiler.h"
#include "validators/hlslvalidator.h"
#include "validators/glslvalidator.h"
#include "validators/spirvvalidator.h"
#include "generators/hlslgenerator.h"
#include "generators/glslgenerator.h"
#include "generators/spirvgenerator.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Setup(const Language& lang, const std::vector<std::string>& defines, unsigned int version)
{
    switch (lang)
    {
    case GLSL:
        this->validator = new GLSLValidator();
        break;
    case HLSL:
        this->validator = new HLSLValidator();
        break;
    case HLSL_SPIRV:
        this->validator = new SPIRVValidator(SPIRVValidator::HLSL);
        break;
    case GLSL_SPIRV:
        this->validator = new SPIRVValidator(SPIRVValidator::GLSL);
        break;
    }

    switch (lang)
    {
    case GLSL:
        this->generator = new GLSLGenerator();
        break;
    case HLSL:
        this->generator = new HLSLGenerator();
        break;
    case GLSL_SPIRV:
    case HLSL_SPIRV:
        this->generator = new SPIRVGenerator();
    }
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::AddSymbol(const std::string signature, Symbol* symbol)
{
    this->symbolLookup[signature] = symbol;
    this->symbols.push_back(symbol);
}

//------------------------------------------------------------------------------
/**
*/
bool 
Compiler::Compile(BinWriter& binaryWriter, TextWriter& headerWriter, std::vector<std::string>& errors)
{
    bool ret = true;

    // run validation step
    for (size_t i = 0; i < this->symbols.size(); i++)
    {
        ret &= this->validator->Validate(this->symbols[i], errors);
    }

    // run generator step
    for (size_t i = 0; i < this->symbols.size(); i++)
    {
        ret &= this->generator->Generate(this->symbols[i], errors);
    }

    // run binary output step
    for (size_t i = 0; i < this->symbols.size(); i++)
    {
        this->OutputBinary(this->symbols[i], binaryWriter);
        this->OutputHeader(this->symbols[i], headerWriter);
    }

    return ret;
}

} // namespace AnyFX

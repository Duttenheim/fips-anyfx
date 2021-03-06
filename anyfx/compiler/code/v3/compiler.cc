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
#include "util.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Setup(const Compiler::Language& lang, const std::vector<std::string>& defines, unsigned int version)
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
        this->validator = new SPIRVValidator(SPIRVValidator::SourceLanguage::HLSL);
        break;
    case GLSL_SPIRV:
        this->validator = new SPIRVValidator(SPIRVValidator::SourceLanguage::GLSL);
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
bool 
Compiler::AddSymbol(const std::string signature, Symbol* symbol, std::vector<std::string>& errors)
{
    auto it = this->symbolLookup.find(signature);
    if (it != this->symbolLookup.end())
    {
        Symbol* symbol = it->second;
        errors.push_back(Format("Symbol %s redefinition, original definition at %s(%d)", signature.c_str(), symbol->location.file.c_str(), symbol->location.line));
        return false;
    }
    this->symbolLookup[signature] = symbol;
    this->symbols.push_back(symbol);
    return true;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
Compiler::GetSymbol(const std::string signature) const
{
    auto it = this->symbolLookup.find(signature);
    if (it != this->symbolLookup.end())
        return it->second;
    else
        return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Compiler::Compile(Effect* root, BinWriter& binaryWriter, TextWriter& headerWriter)
{
    bool ret = true;

    for (size_t i = 0; i < root->symbols.size(); i++)
    {
        root->symbols[i]->EndOfParse(this);
        ret &= this->AddSymbol(root->symbols[i]->signature, root->symbols[i], this->errors);
    }

    // if failed, don't proceed to next step
    if (!ret)
        return ret;

    // run validation step
    for (size_t i = 0; i < this->symbols.size(); i++)
    {
        ret &= this->validator->Validate(this, this->symbols[i], this->errors);
    }

    // if failed, don't proceed to next step
    if (!ret)
        return ret;

    // run generator step
    for (size_t i = 0; i < this->symbols.size(); i++)
    {
        ret &= this->generator->Generate(this, this->symbols[i], this->errors);
    }

    // if failed, don't proceed to next step
    if (!ret)
        return ret;

    // run binary output step
    for (size_t i = 0; i < this->symbols.size(); i++)
    {
        this->OutputBinary(this->symbols[i], binaryWriter);
        this->OutputHeader(this->symbols[i], headerWriter);
    }

    return ret;
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Error(const std::string& msg, const std::string& file, int line, int column)
{
    std::string err = Format("%s(%d) : error:%s", file.c_str(), line, msg.c_str());
    this->errors.push_back(err);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Error(const std::string& msg, Symbol* sym)
{
    std::string err = Format("%s(%d) : error:%s", sym->location.file.c_str(), sym->location.line, msg.c_str());
    this->errors.push_back(err);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::OutputBinary(Symbol* symbol, BinWriter& writer)
{
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::OutputHeader(Symbol* symbol, TextWriter& writer)
{
}

} // namespace AnyFX

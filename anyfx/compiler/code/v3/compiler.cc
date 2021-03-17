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
    case Language::GLSL:
        this->validator = new GLSLValidator();
        break;
    case Language::HLSL:
        this->validator = new HLSLValidator();
        break;
    case Language::HLSL_SPIRV:
        this->validator = new SPIRVValidator(SPIRVValidator::SourceLanguage::HLSL);
        break;
    case Language::GLSL_SPIRV:
        this->validator = new SPIRVValidator(SPIRVValidator::SourceLanguage::GLSL);
        break;
    }

    switch (lang)
    {
    case Language::GLSL:
        this->generator = new GLSLGenerator();
        break;
    case Language::HLSL:
        this->generator = new HLSLGenerator();
        break;
    case Language::GLSL_SPIRV:
    case Language::HLSL_SPIRV:
        this->generator = new SPIRVGenerator();
    }
}

//------------------------------------------------------------------------------
/**
*/
bool 
Compiler::AddSymbol(const std::string& signature, const std::string& name, Symbol* symbol)
{
    auto it = this->symbolsBySignatureLookup.find(signature);
    if (it != this->symbolsBySignatureLookup.end())
    {
        Symbol* symbol = it->second;
        this->errors.push_back(Format("Symbol %s redefinition, original definition at %s(%d)", signature.c_str(), symbol->location.file.c_str(), symbol->location.line));
        return false;
    }
    this->symbolsBySignatureLookup[signature] = symbol;
    this->symbols.push_back(symbol);
    return true;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
Compiler::GetSymbolByName(const std::string& signature) const
{
    auto it = this->symbolsByNameLookup.find(signature);
    if (it != this->symbolsBySignatureLookup.end())
        return it->second;
    else
        return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
Compiler::GetSymbolBySignature(const std::string& signature) const
{
    auto it = this->symbolsBySignatureLookup.find(signature);
    if (it != this->symbolsBySignatureLookup.end())
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
        ret &= this->AddSymbol(root->symbols[i]->resolved->signature, root->symbols[i]);
    }

    // if failed, don't proceed to next step
    if (!ret)
        return ret;

    ret &= this->validator->Validate(this, this->symbols);

    // if failed, don't proceed to next step
    if (!ret)
        return ret;

    // run generator step
    ret &= this->generator->Generate(this, this->symbols);

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
    std::string err = Format("%s(%d) : error: %s", file.c_str(), line, msg.c_str());
    this->errors.push_back(err);
}

//------------------------------------------------------------------------------
/**
*/
void 
Compiler::Error(const std::string& msg, Symbol* sym)
{
    this->Error(msg, sym->location.file, sym->location.line, sym->location.column);
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

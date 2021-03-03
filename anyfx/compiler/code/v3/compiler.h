#pragma once
//------------------------------------------------------------------------------
/**
    Compiler frontend

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <map>
#include "symbol.h"
#include "validators/validator.h"
#include "generators/generator.h"
#include "util/code/binwriter.h"
#include "util/code/textwriter.h"
namespace AnyFX
{

class Compiler
{
public:

    enum Language
    {
        GLSL,
        GLSL_SPIRV, // like GLSL but produces SPIRV output
        HLSL,
        HLSL_SPIRV // like HLSL but produces SPIRV output
    };

    /// setup compiler with target language
    void Setup(const Language& lang, const std::vector<std::string>& defines, unsigned int version);

    /// adds symbol to compiler context
    void AddSymbol(const std::string signature, Symbol* symbol);

    /// runs the validation and generation steps, returns true if successful, otherwise false and a list of error messages
    bool Compile(BinWriter& binaryWriter, TextWriter& headerWriter, std::vector<std::string>& errors);

private:

    /// output binary data
    void OutputBinary(Symbol* symbol, BinWriter& writer);
    /// output header data
    void OutputHeader(Symbol* symbol, TextWriter& writer);
    std::vector<Symbol*> symbols;
    std::map<std::string, Symbol*> symbolLookup;
    std::vector<std::string> defines;

    Validator* validator = nullptr;
    Generator* generator = nullptr;

};

} // namespace AnyFX

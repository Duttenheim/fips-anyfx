#pragma once
//------------------------------------------------------------------------------
/**
    Compiler frontend

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <map>
#include "ast/symbol.h"
#include "ast/effect.h"
#include "validators/validator.h"
#include "generators/generator.h"
#include "util/code/binwriter.h"
#include "util/code/textwriter.h"
namespace AnyFX
{

struct Compiler
{
    enum class Language : uint8_t
    {
        GLSL,
        GLSL_SPIRV, // like GLSL but produces SPIRV output
        HLSL,
        HLSL_SPIRV // like HLSL but produces SPIRV output
    };

    /// setup compiler with target language
    void Setup(const Compiler::Language& lang, const std::vector<std::string>& defines, unsigned int version);

    /// adds symbol to compiler context
    bool AddSymbol(const std::string& signature, Symbol* symbol);
    /// get symbol by signature
    Symbol* GetSymbol(const std::string& signature) const;

    /// runs the validation and generation steps, returns true if successful, otherwise false and a list of error messages
    bool Compile(Effect* root, BinWriter& binaryWriter, TextWriter& headerWriter);

    /// produce error in compiler with explicit file, line and column
    void Error(const std::string& msg, const std::string& file, int line, int column);
    /// produce error in compiler from symbol
    void Error(const std::string& msg, Symbol* sym);

    /// output binary data
    void OutputBinary(Symbol* symbol, BinWriter& writer);
    /// output header data
    void OutputHeader(Symbol* symbol, TextWriter& writer);

    std::vector<Symbol*> symbols;
    std::map<std::string, Symbol*> symbolLookup;
    std::vector<std::string> defines;

    std::vector<std::string> errors;

    Validator* validator = nullptr;
    Generator* generator = nullptr;

};

} // namespace AnyFX

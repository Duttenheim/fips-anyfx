#pragma once
//------------------------------------------------------------------------------
/**
    Compiler backend for code generation. This class is responsible for outputting
    code to generate the machine binary code.

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include <functional>

namespace AnyFX
{

struct Symbol;
struct Compiler;
struct Program;
struct Function;
struct Generator
{
    /// generate code
    virtual bool Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc);

    /// generate function
    virtual void GenerateFunction(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode);
    /// generate structure 
    virtual void GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode);
    /// generate variable
    virtual void GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument);

    std::vector<std::string> targetLanguageFiles;
    Function* mainFunction;
};

} // namespace AnyFX

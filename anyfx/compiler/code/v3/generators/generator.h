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
namespace AnyFX
{

struct Symbol;
struct Compiler;
struct Generator
{

    /// generate code
    bool Generate(Compiler* compiler, const std::vector<Symbol*>& symbols, std::vector<std::string>& errors);

    std::vector<std::string> targetLanguageFiles;
};

} // namespace AnyFX

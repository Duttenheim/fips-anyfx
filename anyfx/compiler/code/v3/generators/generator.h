#pragma once
//------------------------------------------------------------------------------
/**
    Compiler backend for code generation 

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
    bool Generate(Compiler* compiler, Symbol* symbol, std::vector<std::string>& errors);
};

} // namespace AnyFX

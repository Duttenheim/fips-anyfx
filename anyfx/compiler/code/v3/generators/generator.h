#pragma once
//------------------------------------------------------------------------------
/**
    Compiler backend for code generation 

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
namespace AnyFX
{

class Generator
{
public:

    /// generate code
    bool Generate(Symbol* symbol, std::vector<std::string>& errors);
};

} // namespace AnyFX

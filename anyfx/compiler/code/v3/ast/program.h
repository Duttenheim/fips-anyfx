#pragma once
//------------------------------------------------------------------------------
/**
    AST for Program

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <vector>
#include "symbol.h"
namespace AnyFX
{

struct Program : public Symbol
{
    struct SubroutineMapping
    {
        std::string name;
        std::string value;
    };
    struct Entry
    {
        std::string name;
        std::string value;
        std::vector<SubroutineMapping> subroutines;
    };
    std::vector<Entry> entries;
    Annotations annotations;

};

} // namespace AnyFX

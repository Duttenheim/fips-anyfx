#pragma once
//------------------------------------------------------------------------------
/**
    An attribute holds some sort of symbol-related metadata

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <string>
namespace AnyFX
{

class Expression;

struct Attribute
{
    std::string name;
    Expression* expression;
};

} // namespace AnyFX

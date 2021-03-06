#pragma once
//------------------------------------------------------------------------------
/**
    Annotations contains a list of key-value pairs used to pass metadata from 
    source file to reflection, which distinguishes them from attributes which
    are used by the compiler to understand how to transform the code

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include <vector>
#include <string>
#include "expressions/expression.h"
namespace AnyFX 
{

struct Annotations
{
    struct Annotation
    {
        std::string name;
        Expression* value;
    };
    std::vector<Annotation> entries;
};

} // namespace AnyFX

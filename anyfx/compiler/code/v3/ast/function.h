#pragma once
//------------------------------------------------------------------------------
/**
    AST for Function 
            
    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attributable.h"
#include "annotations.h"
#include <vector>
namespace AnyFX
{

struct Variable;
struct Function : public Attributable
{
    std::string returnType;
    std::string code;
    std::vector<Variable*> parameters;
    Annotations annotations;

    bool EndOfParse(Compiler* compiler) override;
};

} // namespace AnyFX

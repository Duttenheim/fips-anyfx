#pragma once
//------------------------------------------------------------------------------
/**
    AST for Function 
            
    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attributable.h"
#include "annotations.h"
#include "variable.h"
#include <vector>
namespace AnyFX
{

struct Variable;
struct Function : public Attributable
{
    /// constructor
    Function();

    std::string returnType;
    std::string code;
    std::vector<Variable*> parameters;
    Annotations annotations;

    struct __Resolved : public Symbol::__Resolved
    {
        Variable::__Resolved::Type returnType;

        unsigned int computeShaderWorkGroupSize[3];
        bool earlyDepth;
    };

    bool EndOfParse(Compiler* compiler) override;
};

} // namespace AnyFX

#pragma once
//------------------------------------------------------------------------------
/**
    AST for a struct
            
    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attributable.h"
#include "variable.h"
namespace AnyFX
{

struct Structure : public Attributable
{
    /// constructor
    Structure();
    /// destructor
    ~Structure();

    std::vector<Variable*> variables;
};

} // namespace AnyFX

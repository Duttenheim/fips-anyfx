#pragma once
//------------------------------------------------------------------------------
/**
    AST for compound variables (struct-like resources like rw buffers, constant buffers, AS structures)

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attributable.h"
#include "variable.h"
#include <vector>
namespace AnyFX
{

struct CompoundVariable : public Variable
{
    /// constructor
    CompoundVariable();
    /// destructor
    ~CompoundVariable();

    std::vector<Variable*> variables;
    std::string instanceName;
};

} // namespace AnyFX

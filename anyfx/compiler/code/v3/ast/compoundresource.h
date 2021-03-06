#pragma once
//------------------------------------------------------------------------------
/**
    AST for compund resource (struct-like resources like rw buffers, constant buffers, AS structures)

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attributable.h"
#include "variable.h"
#include <vector>
namespace AnyFX
{

struct CompoundResource : public Attributable
{
    /// constructor
    CompoundResource();
    /// destructor
    ~CompoundResource();

    std::vector<Variable*> variables;
    std::string instanceName;

    Expression* arraySizeExpression;
    bool isArray;

    std::string type;
    Annotations annotations;
};

} // namespace AnyFX

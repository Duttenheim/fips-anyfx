#pragma once
//------------------------------------------------------------------------------
/**
    AST for typed resource, such as samplers, textures etc, and not compunds

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "attributable.h"
#include "annotations.h"
namespace AnyFX
{

struct TypedResource : public Attributable
{
    /// constructor
    TypedResource();
    /// destructor
    ~TypedResource();

    Expression* arraySizeExpression;
    bool isArray;

    std::string type;
    Annotations annotations;
};

} // namespace AnyFX

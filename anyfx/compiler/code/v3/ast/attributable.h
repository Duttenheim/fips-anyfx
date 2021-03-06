#pragma once
//------------------------------------------------------------------------------
/**
    Any symbol that can have attributes is attributable

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "symbol.h"
#include "attribute.h"
#include <vector>
namespace AnyFX
{

struct Attributable : public Symbol
{
    std::vector<Attribute> attributes;
};

} // namespace AnyFX

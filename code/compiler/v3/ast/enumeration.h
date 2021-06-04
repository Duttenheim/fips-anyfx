#pragma once
//------------------------------------------------------------------------------
/**
    Enumeration

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "types/type.h"
namespace AnyFX
{

struct Enumeration : public Type
{
    /// constructor
    Enumeration(const std::vector<std::string>& labels, const std::vector<Expression*>& values);

    std::vector<std::string> labels;
    std::vector<Expression*> values;
};

} // namespace AnyFX

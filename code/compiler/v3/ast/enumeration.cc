//------------------------------------------------------------------------------
//  @file enumeration.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "enumeration.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Enumeration::Enumeration(const std::vector<std::string>& labels, const std::vector<Expression*>& values)
    : labels(labels)
    , values(values)
{
    this->symbolType = Symbol::EnumerationType;
}
} // namespace AnyFX

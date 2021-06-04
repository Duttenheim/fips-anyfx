#pragma once
//------------------------------------------------------------------------------
/**
    Bool type

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Bool : public Type
{
    /// constructor
    Bool();

    Function ctorUInt;
    Function ctorInt;

    Function orOperator;
    Function andOperator;
    Function xorOperator;
    Function orAssignOperator;
    Function andAssignOperator;
    Function xorAssignOperator;
    Function ororOperator;
    Function andandOperator;

    Function assignOperator;
};

} // namespace AnyFX

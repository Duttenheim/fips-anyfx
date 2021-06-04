#pragma once
//------------------------------------------------------------------------------
/**
    Bool vector of 2

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Bool2 : public Type
{
    /// constructor
    Bool2();

    Function ctorXY;
    Function ctorSingleValue;

    Function bracketOperatorInt;
    Function bracketOperatorUInt;

    Function assignOperator;

    Variable swizzleX[2];
    Variable swizzleXY[2][2];

    
};

} // namespace AnyFX

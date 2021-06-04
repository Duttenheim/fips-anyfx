#pragma once
//------------------------------------------------------------------------------
/**
    Bool vector of 4

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Bool4 : public Type
{
    ///constructor
    Bool4();

    Function ctorSingleValue;
    Function ctorXYZW;

    Function bracketOperatorInt;
    Function bracketOperatorUInt;

    Function assignOperator;

    Variable swizzleX[4];
    Variable swizzleXY[4][4];
    Variable swizzleXYZ[4][4][4];
    Variable swizzleXYZW[4][4][4][4];
};

} // namespace AnyFX

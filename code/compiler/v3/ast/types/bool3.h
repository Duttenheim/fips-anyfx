#pragma once
//------------------------------------------------------------------------------
/**
    Bool vector of 3

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Bool3 : public Type
{
    /// constructor
    Bool3();

    Function ctorXYZ;
    Function ctorSingleValue;

    Function bracketOperatorInt;
    Function bracketOperatorUInt;

    Function assignOperator;

    Variable swizzleX[3];
    Variable swizzleXY[3][3];
    Variable swizzleXYZ[3][3][3];
};

} // namespace AnyFX

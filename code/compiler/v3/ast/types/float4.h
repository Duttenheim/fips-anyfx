#pragma once
//------------------------------------------------------------------------------
/**
    Float vector of 4

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Float4 : public Type
{
    /// constructor
    Float4();

    Function ctorSingleValue;
    Function ctorXYZW;
    Function ctorFloat3W;
    Function ctorFloat2ZW;

    Function additionOperator;
    Function subtractionOperator;
    Function multiplicationOperator;
    Function divisionOperator;
    Function additionAssignOperator;
    Function subtractionAssignOperator;
    Function multiplicationAssignOperator;
    Function divisionAssignOperator;

    Function bracketOperatorInt;
    Function bracketOperatorUInt;

    Function assignOperator;

    Variable swizzleX[4];
    Variable swizzleXY[4][4];
    Variable swizzleXYZ[4][4][4];
    Variable swizzleXYZW[4][4][4][4];
};

} // namespace AnyFX

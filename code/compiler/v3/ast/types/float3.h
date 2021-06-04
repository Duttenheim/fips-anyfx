#pragma once
//------------------------------------------------------------------------------
/**
    Float vector of 3

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Float3 : public Type
{
    /// constructor
    Float3();

    Function ctorXYZ;
    Function ctorSingleValue;

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

    Variable swizzleX[3];
    Variable swizzleXY[3][3];
    Variable swizzleXYZ[3][3][3];    
};

} // namespace AnyFX

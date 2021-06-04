#pragma once
//------------------------------------------------------------------------------
/**
    Integer vector of 2

    @copyright (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Int2 : public Type
{
    /// constructor
    Int2();

    Function ctorXY;
    Function ctorSingleValue;

    Function andOperator;
    Function orOperator;
    Function xorOperator;
    Function leftShiftOperator;
    Function rightShiftOperator;
    Function andAssignOperator;
    Function orAssignOperator;
    Function xorAssignOperator;
    Function leftShiftAssignOperator;
    Function rightShiftAssignOperator;

    Function additionOperator;
    Function subtractionOperator;
    Function multiplicationOperator;
    Function divisionOperator;
    Function moduloOperator;
    Function additionAssignOperator;
    Function subtractionAssignOperator;
    Function multiplicationAssignOperator;
    Function divisionAssignOperator;
    Function moduloAssignOperator;

    Function bracketOperatorInt;
    Function bracketOperatorUInt;

    Function assignOperator;

    Variable swizzleX[2];
    Variable swizzleXY[2][2];
};

} // namespace AnyFX

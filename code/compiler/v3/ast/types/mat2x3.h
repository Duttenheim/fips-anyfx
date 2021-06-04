#pragma once
//------------------------------------------------------------------------------
/**
    Matrix 2x3

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "type.h"
#include "ast/function.h"
namespace AnyFX
{

struct Mat2x3 : public Type
{
    /// constructor
    Mat2x3();

    Function floatConstructor;
    Function vectorConstructor;

    Function additionOperator;
    Function subtractionOperator;
    Function multiplyOperator;
    Function additionAssignOperator;
    Function subtractionAssignOperator;
    Function multiplyAssignOperator;

    Function vectorTransformOperator;

    Function assignOperator;

    Function bracketOperatorInt;
    Function bracketOperatorUInt;
};

} // namespace AnyFX

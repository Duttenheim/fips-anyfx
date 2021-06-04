//------------------------------------------------------------------------------
//  @file float2.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "float2.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Float2::Float2()
{
    this->baseType = Type::Float;
    this->columnSize = 2;
    this->rowSize = 1;
    this->byteSize = 8;
    this->category = Type::ScalarCategory;

    __IMPLEMENT_FUNCTION(ctorXY, float2, float2);
    __ADD_FUNCTION_PARAM(x, float);
    __ADD_FUNCTION_PARAM(y, float);

    __IMPLEMENT_FUNCTION_1(ctorSingleValue, float2, float2, float);

    __IMPLEMENT_FUNCTION_1(additionOperator, operator+, float2, float2);
    __IMPLEMENT_FUNCTION_1(subtractionOperator, operator-, float2, float2);
    __IMPLEMENT_FUNCTION_1(multiplicationOperator, operator*, float2, float2);
    __IMPLEMENT_FUNCTION_1(divisionOperator, operator/, float2, float2);
    __IMPLEMENT_FUNCTION_1(additionAssignOperator, operator+=, float2, float2);
    __IMPLEMENT_FUNCTION_1(subtractionAssignOperator, operator-=, float2, float2);
    __IMPLEMENT_FUNCTION_1(multiplicationAssignOperator, operator*=, float2, float2);
    __IMPLEMENT_FUNCTION_1(divisionAssignOperator, operator/=, float2, float2);

    __IMPLEMENT_FUNCTION_1(bracketOperatorInt, operator[], float, int);
    __IMPLEMENT_FUNCTION_1(bracketOperatorUInt, operator[], float, uint);

    __IMPLEMENT_FUNCTION_1(assignOperator, operator=, float4, float2);


    char swizzleMask[] = { 'x', 'y' };
    for (char x = 0; x < 2; x++)
    {
        __ADD_VARIBLE_LOOKUP(swizzleX[x], Format("%c", swizzleMask[x]), float);
        for (char y = 0; y < 2; y++)
        {
            __ADD_VARIBLE_LOOKUP(swizzleXY[x][y], Format("%c%c", swizzleMask[x], swizzleMask[y]), float2);
        }
    }
}

} // namespace AnyFX

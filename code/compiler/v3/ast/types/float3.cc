//------------------------------------------------------------------------------
//  @file float3.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "float3.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Float3::Float3()
{
    this->baseType = Type::Float;
    this->columnSize = 3;
    this->rowSize = 1;
    this->byteSize = 12;
    this->category = Type::ScalarCategory;

    __IMPLEMENT_FUNCTION(ctorXYZ, float3, float3);
    __ADD_FUNCTION_PARAM(x, float);
    __ADD_FUNCTION_PARAM(y, float);
    __ADD_FUNCTION_PARAM(z, float);

    __IMPLEMENT_FUNCTION_1(ctorSingleValue, float3, float3, float);

    __IMPLEMENT_FUNCTION_1(additionOperator, operator+, float3, float3);
    __IMPLEMENT_FUNCTION_1(subtractionOperator, operator-, float3, float3);
    __IMPLEMENT_FUNCTION_1(multiplicationOperator, operator*, float3, float3);
    __IMPLEMENT_FUNCTION_1(divisionOperator, operator/, float3, float3);
    __IMPLEMENT_FUNCTION_1(additionAssignOperator, operator+=, float3, float3);
    __IMPLEMENT_FUNCTION_1(subtractionAssignOperator, operator-=, float3, float3);
    __IMPLEMENT_FUNCTION_1(multiplicationAssignOperator, operator*=, float3, float3);
    __IMPLEMENT_FUNCTION_1(divisionAssignOperator, operator/=, float3, float3);

    __IMPLEMENT_FUNCTION_1(bracketOperatorInt, operator[], float, int);
    __IMPLEMENT_FUNCTION_1(bracketOperatorUInt, operator[], float, uint);

    __IMPLEMENT_FUNCTION_1(assignOperator, operator=, float3, float3);

    char swizzleMask[] = { 'x', 'y', 'z' };
    for (char x = 0; x < 3; x++)
    {
        __ADD_VARIBLE_LOOKUP(swizzleX[x], Format("%c", swizzleMask[x]), float);
        for (char y = 0; y < 3; y++)
        {
            __ADD_VARIBLE_LOOKUP(swizzleXY[x][y], Format("%c%c", swizzleMask[x], swizzleMask[y]), float2);
            for (char z = 0; z < 3; z++)
            {
                __ADD_VARIBLE_LOOKUP(swizzleXYZ[x][y][z], Format("%c%c%c", swizzleMask[x], swizzleMask[y], swizzleMask[z]), float3);
            }
        }
    }
}

} // namespace AnyFX

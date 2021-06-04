//------------------------------------------------------------------------------
//  @file mat4x2.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "mat4x2.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Mat4x2::Mat4x2()
{
    this->baseType = Type::Float;
    this->rowSize = 4;
    this->columnSize = 2;
    this->byteSize = 32;
    this->category = Type::ScalarCategory;

    __IMPLEMENT_FUNCTION(floatConstructor, float4x2, float4x2);
    __ADD_FUNCTION_PARAM(m00, float);
    __ADD_FUNCTION_PARAM(m01, float);
    __ADD_FUNCTION_PARAM(m10, float);
    __ADD_FUNCTION_PARAM(m11, float);
    __ADD_FUNCTION_PARAM(m20, float);
    __ADD_FUNCTION_PARAM(m21, float);
    __ADD_FUNCTION_PARAM(m30, float);
    __ADD_FUNCTION_PARAM(m31, float);

    __IMPLEMENT_FUNCTION(vectorConstructor, float4x2, float4x2);
    __ADD_FUNCTION_PARAM(r0, float2);
    __ADD_FUNCTION_PARAM(r1, float2);
    __ADD_FUNCTION_PARAM(r2, float2);
    __ADD_FUNCTION_PARAM(r3, float2);

    __IMPLEMENT_FUNCTION_1(additionOperator, operator+, float4x2, float4x2);
    __IMPLEMENT_FUNCTION_1(subtractionOperator, operator-, float4x2, float4x2);
    __IMPLEMENT_FUNCTION_1(multiplyOperator, operator*, float4x2, float4x2);
    __IMPLEMENT_FUNCTION_1(additionAssignOperator, operator+=, float4x2, float4x2);
    __IMPLEMENT_FUNCTION_1(subtractionAssignOperator, operator-=, float4x2, float4x2);
    __IMPLEMENT_FUNCTION_1(multiplyAssignOperator, operator*=, float4x2, float4x2);

    __IMPLEMENT_FUNCTION_1(vectorTransformOperator, operator*, float2, float2);

    __IMPLEMENT_FUNCTION_1(assignOperator, operator=, float4x2, float4x2);

    __IMPLEMENT_FUNCTION_1(bracketOperatorInt, operator[], float2, int);
    __IMPLEMENT_FUNCTION_1(bracketOperatorUInt, operator[], float2, uint);
}

} // namespace AnyFX

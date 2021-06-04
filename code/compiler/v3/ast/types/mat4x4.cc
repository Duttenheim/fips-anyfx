//------------------------------------------------------------------------------
//  @file mat4x4.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "mat4x4.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Mat4x4::Mat4x4()
{
    this->baseType = Type::Float;
    this->rowSize = 4;
    this->columnSize = 4;
    this->byteSize = 64;
    this->category = Type::ScalarCategory;

    __IMPLEMENT_FUNCTION(floatConstructor, float4x4, float4x4);
    __ADD_FUNCTION_PARAM(m00, float);
    __ADD_FUNCTION_PARAM(m01, float);
    __ADD_FUNCTION_PARAM(m02, float);
    __ADD_FUNCTION_PARAM(m03, float);
    __ADD_FUNCTION_PARAM(m10, float);
    __ADD_FUNCTION_PARAM(m11, float);
    __ADD_FUNCTION_PARAM(m12, float);
    __ADD_FUNCTION_PARAM(m13, float);
    __ADD_FUNCTION_PARAM(m20, float);
    __ADD_FUNCTION_PARAM(m21, float);
    __ADD_FUNCTION_PARAM(m22, float);
    __ADD_FUNCTION_PARAM(m23, float);
    __ADD_FUNCTION_PARAM(m30, float);
    __ADD_FUNCTION_PARAM(m31, float);
    __ADD_FUNCTION_PARAM(m32, float);
    __ADD_FUNCTION_PARAM(m33, float);

    __IMPLEMENT_FUNCTION(vectorConstructor, float4x4, float4x4);
    __ADD_FUNCTION_PARAM(r0, float4);
    __ADD_FUNCTION_PARAM(r1, float4);
    __ADD_FUNCTION_PARAM(r2, float4);
    __ADD_FUNCTION_PARAM(r3, float4);

    __IMPLEMENT_FUNCTION_1(additionOperator, operator+, float4x4, float4x4);
    __IMPLEMENT_FUNCTION_1(subtractionOperator, operator-, float4x4, float4x4);
    __IMPLEMENT_FUNCTION_1(multiplyOperator, operator*, float4x4, float4x4);
    __IMPLEMENT_FUNCTION_1(additionAssignOperator, operator+=, float4x4, float4x4);
    __IMPLEMENT_FUNCTION_1(subtractionAssignOperator, operator-=, float4x4, float4x4);
    __IMPLEMENT_FUNCTION_1(multiplyAssignOperator, operator*=, float4x4, float4x4);

    __IMPLEMENT_FUNCTION_1(vectorTransformOperator, operator*, float4, float4);

    __IMPLEMENT_FUNCTION_1(assignOperator, operator=, float4x4, float4x4);

    __IMPLEMENT_FUNCTION_1(bracketOperatorInt, operator[], float4, int);
    __IMPLEMENT_FUNCTION_1(bracketOperatorUInt, operator[], float4 , uint);
}

} // namespace AnyFX

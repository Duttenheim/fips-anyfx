//------------------------------------------------------------------------------
//  @file bool4.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "bool4.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Bool4::Bool4()
{
    this->baseType = Type::Bool;
    this->columnSize = 4;
    this->rowSize = 1;
    this->byteSize = 4;
    this->category = Type::ScalarCategory;

    // setup constructor for xyzw
    __IMPLEMENT_FUNCTION(ctorXYZW, bool4, bool4);
    __ADD_FUNCTION_PARAM(x, bool);
    __ADD_FUNCTION_PARAM(y, bool);
    __ADD_FUNCTION_PARAM(z, bool);
    __ADD_FUNCTION_PARAM(w, bool);

    // setup constructor for single component
    __IMPLEMENT_FUNCTION_1(ctorSingleValue, bool4, bool4, bool);

    __IMPLEMENT_FUNCTION_1(bracketOperatorInt, operator[], bool, int);
    __IMPLEMENT_FUNCTION_1(bracketOperatorUInt, operator[], bool, uint);

    __IMPLEMENT_FUNCTION_1(assignOperator, operator=, bool4, bool4);

    char swizzleMask[] = { 'x', 'y', 'z', 'w' };
    for (char x = 0; x < 4; x++)
    {
        __ADD_VARIBLE_LOOKUP(swizzleX[x], Format("%c", swizzleMask[x]), bool);
        for (char y = 0; y < 4; y++)
        {
            __ADD_VARIBLE_LOOKUP(swizzleXY[x][y], Format("%c%c", swizzleMask[x], swizzleMask[y]), bool2);
            for (char z = 0; z < 4; z++)
            {
                __ADD_VARIBLE_LOOKUP(swizzleXYZ[x][y][z], Format("%c%c%c", swizzleMask[x], swizzleMask[y], swizzleMask[z]), bool3);
                for (char w = 0; w < 4; w++)
                {
                    __ADD_VARIBLE_LOOKUP(swizzleXYZW[x][y][z][w], Format("%c%c%c%c", swizzleMask[x], swizzleMask[y], swizzleMask[z], swizzleMask[w]), bool4);
                }
            }
        }
    }
}

} // namespace AnyFX

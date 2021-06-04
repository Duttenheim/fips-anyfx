//------------------------------------------------------------------------------
//  @file bool2.cc
//  @copyright (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "bool2.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Bool2::Bool2()
{
    this->baseType = Type::Bool;
    this->rowSize = 1;
    this->columnSize = 2;
    this->byteSize = 2;
    this->category = Type::ScalarCategory;

    // setup constructor for xy
    __IMPLEMENT_FUNCTION(ctorXY, bool2, bool2);
    __ADD_FUNCTION_PARAM(x, bool);
    __ADD_FUNCTION_PARAM(y, bool);

        // setup constructor for single component
    __IMPLEMENT_FUNCTION_1(ctorSingleValue, bool2, bool2, bool);

    __IMPLEMENT_FUNCTION_1(bracketOperatorInt, operator[], bool, int);
    __IMPLEMENT_FUNCTION_1(bracketOperatorUInt, operator[], bool, uint);

    __IMPLEMENT_FUNCTION_1(assignOperator, operator=, bool2, bool2);

    char swizzleMask[] = { 'x', 'y' };
    for (char x = 0; x < 2; x++)
    {
        __ADD_VARIBLE_LOOKUP(swizzleX[x], Format("%c", swizzleMask[x]), bool);
        for (char y = 0; y < 2; y++)
        {
            __ADD_VARIBLE_LOOKUP(swizzleXY[x][y], Format("%c%c", swizzleMask[x], swizzleMask[y]), bool2);
        }
    }   
}

} // namespace AnyFX

//------------------------------------------------------------------------------
//  @file type.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "type.h"
#include "util.h"
#include "bool.h"
#include "bool2.h"
#include "bool3.h"
#include "bool4.h"
#include "int.h"
#include "int2.h"
#include "int3.h"
#include "int4.h"
#include "uint.h"
#include "uint2.h"
#include "uint3.h"
#include "uint4.h"
#include "float.h"
#include "float2.h"
#include "float3.h"
#include "float4.h"
#include "mat2x2.h"
#include "mat2x3.h"
#include "mat2x4.h"
#include "mat3x2.h"
#include "mat3x3.h"
#include "mat3x4.h"
#include "mat4x2.h"
#include "mat4x3.h"
#include "mat4x4.h"
#include <set>
namespace AnyFX
{

Function* activeFunction = nullptr;

#define __BEGIN_TYPES__ std::map<std::string, Symbol*> types; Type* newType = nullptr;

#define __MAKE_TYPE(typecode)\
newType = new Type();\
newType->name = #typecode;\
types[#typecode] = newType;

#define __MAKE_RWTEX()\
newType->category = Type::ReadWriteTextureCategory;

#define __MAKE_TEX()\
newType->category = Type::TextureCategory;

#define __MAKE_SAMPTEX()\
newType->category = Type::SampledTextureCategory;

#define __MAKE_INPUTATTACH()\
newType->category = Type::InputAttachmentCategory;

#define __MAKE_SAMPLER()\
newType->category = Type::SamplerCategory;

#define __MAKE_TYPE_CUSTOM(t1, t2)\
newType = new t2();\
newType->name = #t1;\
types[#t1] = newType;

#define __ADD_LOOKUP(name) types[#name] = newType;
#define __END_TYPES__ return types;

//------------------------------------------------------------------------------
/**
*/
Type::Type()
{
    this->symbolType = Symbol::TypeType;
    this->baseType = Type::InvalidType;
    this->rowSize = 1;
    this->columnSize = 1;
    this->byteSize = 4;
    this->category = Type::InvalidCategory;
}

//------------------------------------------------------------------------------
/**
*/
Type::~Type()
{
    for (Function* fun : this->methods)
        delete fun;
    for (Variable* var : this->members)
        delete var;
}

std::map<Type::Code, std::string> codeToStringMapping =
{
    { Type::Float, "float" }
    , { Type::Float16, "float16" }
    , { Type::Int, "int" }
    , { Type::Int16, "int16" }
    , { Type::UInt, "uint" }
    , { Type::UInt16, "uint16" }
    , { Type::Bool, "bool" }
};

//------------------------------------------------------------------------------
/**
*/
std::string 
Type::CodeToString(const Code& code)
{
    auto it = codeToStringMapping.find(code);
    if (it == codeToStringMapping.end())
        return "";
    else
        return it->second;
}

//------------------------------------------------------------------------------
/**
*/
Symbol* 
Type::GetSymbol(const std::string str)
{
    auto it = this->lookup.find(str);
    if (it != this->lookup.end())
        return it->second;
    else
        return nullptr;
}

//------------------------------------------------------------------------------
/**
*/
std::vector<Symbol*> 
Type::GetSymbols(const std::string str)
{
    std::vector<Symbol*> ret;
    auto range = this->lookup.equal_range(str);
    for (auto it = range.first; it != range.second; it++)
        ret.push_back((*it).second);
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
std::map<std::string, Symbol*>
Type::SetupDefaultTypes()
{
    __BEGIN_TYPES__

    __MAKE_TYPE(readWriteTexture1D);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTexture2D);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTexture2DMS);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTexture3D);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTextureCube);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTexture1DArray);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTexture2DArray);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTexture2DMSArray);
    __MAKE_RWTEX();

    __MAKE_TYPE(readWriteTextureCubeArray);
    __MAKE_RWTEX();

    __MAKE_TYPE(texture1D);
    __MAKE_TEX();

    __MAKE_TYPE(texture2D);
    __MAKE_TEX();

    __MAKE_TYPE(texture2DMS);
    __MAKE_TEX();

    __MAKE_TYPE(texture3D);
    __MAKE_TEX();

    __MAKE_TYPE(textureCube);
    __MAKE_TEX();

    __MAKE_TYPE(texture1DArray);
    __MAKE_TEX();

    __MAKE_TYPE(texture2DArray);
    __MAKE_TEX();

    __MAKE_TYPE(texture2DMSArray);
    __MAKE_TEX();

    __MAKE_TYPE(textureCubeArray);
    __MAKE_TEX();

    __MAKE_TYPE(sampledTexture1D);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTexture2D);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTexture2DMS);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTexture3D);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTextureCube);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTexture1DArray);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTexture2DArray);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTexture2DMSArray);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(sampledTextureCubeArray);
    __MAKE_SAMPTEX();

    __MAKE_TYPE(inputAttachment);
    __MAKE_INPUTATTACH();

    __MAKE_TYPE(inputAttachmentMS);
    __MAKE_INPUTATTACH();

    __MAKE_TYPE_CUSTOM(float, AnyFX::Float);
    __MAKE_TYPE_CUSTOM(float2, AnyFX::Float2);
    __MAKE_TYPE_CUSTOM(float3, AnyFX::Float3);
    __MAKE_TYPE_CUSTOM(float4, AnyFX::Float4);
    __MAKE_TYPE_CUSTOM(int, AnyFX::Int);
    __MAKE_TYPE_CUSTOM(int2, AnyFX::Int2);
    __MAKE_TYPE_CUSTOM(int3, AnyFX::Int3);
    __MAKE_TYPE_CUSTOM(int4, AnyFX::Int4);
    __MAKE_TYPE_CUSTOM(uint, AnyFX::UInt);
    __MAKE_TYPE_CUSTOM(uint2, AnyFX::UInt2);
    __MAKE_TYPE_CUSTOM(uint3, AnyFX::UInt3);
    __MAKE_TYPE_CUSTOM(uint4, AnyFX::UInt4);
    __MAKE_TYPE_CUSTOM(bool, AnyFX::Bool);
    __MAKE_TYPE_CUSTOM(bool2, AnyFX::Bool2);
    __MAKE_TYPE_CUSTOM(bool3, AnyFX::Bool3);
    __MAKE_TYPE_CUSTOM(bool4, AnyFX::Bool4);
    __MAKE_TYPE_CUSTOM(float2x2, AnyFX::Mat2x2);
    __MAKE_TYPE_CUSTOM(float2x3, AnyFX::Mat2x3);
    __MAKE_TYPE_CUSTOM(float2x4, AnyFX::Mat2x4);
    __MAKE_TYPE_CUSTOM(float3x2, AnyFX::Mat3x2);
    __MAKE_TYPE_CUSTOM(float3x3, AnyFX::Mat3x3);
    __MAKE_TYPE_CUSTOM(float3x4, AnyFX::Mat3x4);
    __MAKE_TYPE_CUSTOM(float4x2, AnyFX::Mat4x2);
    __MAKE_TYPE_CUSTOM(float4x3, AnyFX::Mat4x3);
    __MAKE_TYPE_CUSTOM(float4x4, AnyFX::Mat4x4);
    __MAKE_TYPE(sampler);
    __MAKE_SAMPLER();

    __MAKE_TYPE(void);

    __END_TYPES__
}

std::map<Type::Code, std::vector<std::string>> singleComponentToVectorMap =
{
    { Type::Float, { "float", "float2", "float3", "float4" } }
    , { Type::Int, { "int", "int2", "int3", "int4" } }
    , { Type::UInt, { "uint", "uint2", "uint3", "uint4" } }
    , { Type::Bool, { "bool", "bool2", "bool3", "bool4" } }

};

//------------------------------------------------------------------------------
/**
*/
const std::string 
Type::ToVector(const Type::Code baseType, unsigned members)
{
    if (members > 4)
        return "";
    else
        return singleComponentToVectorMap[baseType][members - 1];
}

//------------------------------------------------------------------------------
/**
*/
const bool
Type::IsVector() const
{
    return this->category == Type::ScalarCategory && this->columnSize > 1 && this->rowSize <= 1;
}

//------------------------------------------------------------------------------
/**
*/
const bool 
Type::IsMatrix() const
{
    return this->category == Type::ScalarCategory && this->columnSize > 1 && this->rowSize > 1;
}

//------------------------------------------------------------------------------
/**
*/
bool 
Type::SwizzleMask(const std::string& str, unsigned& out)
{
    out = 0;
// convert to swizzle mask
    uint32_t mask = 0x000000FF;
    for (size_t i = 0; i < str.length() && i <= 4; i++)
    {
        char c = str[i];
        switch (c)
        {
            case 'x':
            case 'r':
            out |= (X_R << i * 8) & mask;
            break;
            case 'y':
            case 'g':
            out |= (Y_G << i * 8) & mask;
            break;
            case 'z':
            case 'b':
            out |= (Z_B << i * 8) & mask;
            break;
            case 'w':
            case 'a':
            out |= (W_A << i * 8) & mask;
            break;
            case '0':
            out |= (_0 << i * 8) & mask;
            break;
            case '1':
            out |= (_1 << i * 8) & mask;
            break;
            default:
            return false;
        }
        mask <<= 8;
    }
    return true;
}

//------------------------------------------------------------------------------
/**
*/
unsigned 
Type::SwizzleMaskComponents(unsigned mask)
{
    int numComponents = 0;
    if ((mask & 0x000000FF) != 0)
        numComponents++;
    if ((mask & 0x0000FF00) != 0)
        numComponents++;
    if ((mask & 0x00FF0000) != 0)
        numComponents++;
    if ((mask & 0xFF000000) != 0)
        numComponents++;
    return numComponents;
}


//------------------------------------------------------------------------------
/**
*/
unsigned
Type::SwizzleMaskBiggestComponent(unsigned mask)
{
    unsigned ret = max(mask & 0x000000FF, ((mask >> 8) & 0x000000FF));
    ret = max(ret, ((mask >> 16) & 0x000000FF));
    ret = max(ret, ((mask >> 24) & 0x000000FF));

#if __GNUC__ 
    ret = __builtin_ctz(ret) + 1;
#elif _MSC_VER
    ret = __lzcnt(ret) + 1;
#endif
    return ret;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
Type::FullType::ToString(Compiler* compiler)
{
    std::string modifiers = "";
    for (int i = this->modifiers.size()-1; i >= 0; i--)
    {
        uint32_t size = this->modifierValues[i];
        if (this->modifiers[i] == Type::FullType::Modifier::ArrayLevel)
            if (size == 0)
                modifiers.append("[]");
            else
            {
                modifiers.append(Format("[%d]", size));
            }
        else if (this->modifiers[i] == Type::FullType::Modifier::PointerLevel)
            modifiers.append("*");
    }

    return Format("%s%s", this->name.c_str(), modifiers.c_str());
}

} // namespace AnyFX

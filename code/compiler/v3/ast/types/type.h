#pragma once
//------------------------------------------------------------------------------
/**
    The type symbol is the most primitive representation of a type

    (C) 2021 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "ast/symbol.h"
#include <vector>
#include <map>

#define __IMPLEMENT_FUNCTION_1(method, id, t, argtype)\
this->method.name = #id;\
this->method.returnType = {#t};\
this->lookup.insert({ #id, &this->method });\
this->staticMethods.push_back(&this->method);\
activeFunction = &this->method;\
{\
    Variable* var = new Variable; \
    var->name = "_arg0"; \
    var->type = { #argtype }; \
    activeFunction->parameters.push_back(var); \
}

#define __IMPLEMENT_FUNCTION(method, id, type)\
this->method.name = #id;\
this->method.returnType = {#type};\
this->lookup.insert({ #id, &this->method });\
this->staticMethods.push_back(&this->method);\
activeFunction = &this->method;;\


#define __ADD_FUNCTION_LOOKUP(id)\
this->lookup.insert({ #id, activeFunction });

#define __ADD_FUNCTION_PARAM(id, t)\
{\
    Variable* var = new Variable;\
    var->name = #id;\
    var->type = {#t};\
    activeFunction->parameters.push_back(var);\
}

#define __ADD_VARIBLE_LOOKUP(variable, id, t)\
this->variable.name = id;\
this->variable.type = {#t};\
this->lookup.insert({id, &this->variable});

namespace AnyFX
{

struct Variable;
struct Function;
struct Expression;
struct Compiler;
extern Function* activeFunction;

struct Type : public Symbol
{
    /// constructor
    Type();
    /// destructor
    virtual ~Type();

    enum Code
    {
        /// scalar types
        Float,
        Float16,
        Int,
        Int16,
        UInt,
        UInt16,
        Bool,

        /// fail when this type is detected as soon as possible
        InvalidType
    };

    /// convert type to string
    static std::string CodeToString(const Type::Code& code);

    enum Category
    {
        InvalidCategory,
        ReadWriteTextureCategory,
        TextureCategory,
        SampledTextureCategory,
        InputAttachmentCategory,
        ScalarCategory,
        UserTypeCategory,
        ConstantStructureCategory,
        MutableStructureCategory,
        VoidCategory,
        SamplerCategory
    };

    enum SwizzleMask
    {
        X_R = 0x1,
        Y_G = 0x2,
        Z_B = 0x4,
        W_A = 0x8,
        _0 = 0x10,
        _1 = 0x20,
    };

    /// convert string to swizzle mask, returns true if possible swizzle mask
    static bool SwizzleMask(const std::string& str, unsigned& out);
    /// count set bits in swizzle mask
    static unsigned SwizzleMaskComponents(unsigned mask);
    /// count highest value in swizzle mask
    static unsigned SwizzleMaskBiggestComponent(unsigned mask);

    /// convert from type to vector with count
    static const std::string ToVector(const Type::Code baseType, unsigned dimensions);
    /// returns true if type is vector
    const bool IsVector() const;

    Code baseType;
    uint32_t rowSize;
    uint32_t columnSize;
    uint32_t byteSize;
    Category category;

    struct FullType
    {
        std::string name;

        enum class Modifier : uint8_t
        {
            ArrayLevel,
            PointerLevel
        };
        
        std::vector<Modifier> modifiers;
        std::vector<Expression*> modifierExpressions;

        bool operator==(const FullType& rhs) const
        {
            return this->name == rhs.name && this->modifiers == rhs.modifiers;
        }

        bool operator!=(const FullType& rhs) const
        {
            return this->name != rhs.name || this->modifiers != rhs.modifiers;
        }

        std::string ToString(Compiler* compiler);
    };

    std::vector<Variable*> members;
    std::vector<Function*> methods;
    std::vector<Variable*> staticMembers;
    std::vector<Function*> staticMethods;
    std::multimap<std::string, Symbol*> lookup;

    /// return member symbol
    Symbol* GetSymbol(const std::string str);
    /// return member symbols matching string
    std::vector<Symbol*> GetSymbols(const std::string str);

    /// setup all default shader types, like float, int, vec4, etc
    static std::map<std::string, Symbol*> SetupDefaultTypes();

};

} // namespace AnyFX

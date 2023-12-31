#pragma once
//------------------------------------------------------------------------------
/**
    @class Variable
    
    A variable describes a semi-transparent type declaration, variable name, and default value 
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "types.h"
#include "datatype.h"
#include "symbol.h"
#include "valuelist.h"
#include "annotation.h"
#include "types.h"
#include "expressions/expression.h"
namespace AnyFX
{

class Variable : public Symbol
{
public:

    enum ImageFormat
    {
        RGBA32F,
        RGBA16F,
        RG32F,
        RG16F,
        R11G11B10F,
        R32F,
        R16F,
        RGBA16,
        RGB10A2,
        RGBA8,
        RG16,
        RG8,
        R16,
        R8,
        RGBA16SNORM,
        RGBA8SNORM,
        RG16SNORM,
        RG8SNORM,
        R16SNORM,
        R8SNORM,
        RGBA32I,
        RGBA16I,
        RGBA8I,
        RG32I,
        RG16I,
        RG8I,
        R32I,
        R16I,
        R8I,
        RGBA32UI,
        RGBA16UI,
        RGB10A2UI,
        RGBA8UI,
        RG32UI,
        RG16UI,
        RG8UI,
        R32UI,
        R16UI,
        R8UI,
        NoFormat,

        NumImageFormats,

        InvalidImageFormat
    };

    enum ArrayType
    {
        NoArray,            // not an array
        SimpleArray,		// evaluate array size by using value table single entry number of values
        TypedArray,			// evaluate array size by using value table size
        ExplicitArray,		// evaluate array size by expression
        UnsizedArray
    };

    enum QualifierFlags
    {
        NoQualifiers = 0,
        GroupShared = 1 << 0,   // group shared means shared within a shader compute group
        Shared = 1 << 1,        // ordinary shared means shared during the application execution
        Bindless = 1 << 2,      // denotes that a texture should be used as bindless
        RayPayload = 1 << 3,    // Variable is passed between raytracing shaders
    };

    struct Binding
    {
        enum class Type
        {
            Buffer,
            Texture,
            AccelerationStructure
        } type;

        union
        {
            struct
            {
                unsigned slot, size;
            } buffer;

            struct
            {
                unsigned slot;
            } texture;
        } binding;

        std::string name;
        unsigned group;
    };

    /// constructor
    Variable();
    /// destructor
    virtual ~Variable();

    /// set annotation
    void SetAnnotation(const Annotation& annotation);

    /// add array size expression
    void AddSizeExpression(Expression* expr);

    /// sets array type
    void SetArrayType(const ArrayType& type);
    /// gets array type
    const ArrayType& GetArrayType() const;

    /// gets array sizes
    const int GetArraySize() const;
    /// gets variable byte size
    const unsigned GetByteSize() const;

    /// adds a value-type pair
    void AddValue(const DataType& type, const ValueList& value);
    /// adds a value-type for basic types
    void AddValue(const ValueList& value);

    /// returns true if default value exists
    bool HasDefaultValue() const;

    /// returns true if variable is a subroutine method pointer
    bool IsSubroutine() const;
    /// returns true if variable is a uniform (it is not shader local)
    bool IsUniform() const;

    /// sets the type of a variable
    void SetDataType(const DataType& type);
    /// get variable type
    const DataType& GetDataType() const;

    /// preprocess variable
    void Preprocess();
    /// type checks variables
    void TypeCheck(TypeChecker& typechecker);
    /// compiles variable
    void Compile(BinWriter& writer);

    /// get binding
    const Binding GetBinding() const;

    /// format variable to fit target language
    std::string Format(const Header& header, bool inVarblock = false) const;

private:
    friend class VarBlock;
    friend class VarBuffer;
    friend class Effect;
    friend class Structure;

    /// evaluates array size
    void EvaluateArraySize(TypeChecker& typechecker);

    /// converts image format to string based on header
    std::string FormatImageFormat(const Header& header) const;
    /// converts access pattern to string based on header
    std::string FormatImageAccess(const Header& header) const;

    
    std::string defaultValue;
    std::vector<std::pair<DataType, ValueList> > valueTable;
    DataType type;
    ImageFormat format;
    unsigned accessMode;
    int qualifierFlags;
    bool isUniform;

    ArrayType arrayType;
    bool isSubroutine;
    int arraySize;
    std::vector<int> arraySizes;
    std::vector<Expression*> sizeExpressions;

    std::string fullName; // name of path (parentStruct1.parentStruct2.name)

    bool hasDefaultValue;
    bool hasAnnotation;
    Annotation annotation;

    // the binding unit for this variable
    unsigned group;
    unsigned binding;

    // index used if variable is an input attachment
    unsigned index;

    // aligned offset
    unsigned alignedOffset;
    unsigned padding;
}; 

//------------------------------------------------------------------------------
/**
*/
inline void
Variable::SetAnnotation(const Annotation& annotation)
{
    this->annotation = annotation;
    this->hasAnnotation = true;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
Variable::AddSizeExpression(Expression* expr)
{
    this->sizeExpressions.push_back(expr);
}

//------------------------------------------------------------------------------
/**
*/
inline void
Variable::SetArrayType(const ArrayType& type)
{
    this->arrayType = type;
}

//------------------------------------------------------------------------------
/**
*/
inline const Variable::ArrayType& 
Variable::GetArrayType() const
{
    return this->arrayType;
}

//------------------------------------------------------------------------------
/**
*/
inline const int 
Variable::GetArraySize() const
{
    return this->arraySize;
}

//------------------------------------------------------------------------------
/**
*/
inline bool 
Variable::HasDefaultValue() const
{
    return this->hasDefaultValue;
}

//------------------------------------------------------------------------------
/**
*/
inline bool 
Variable::IsSubroutine() const
{
    return this->isSubroutine;
}

//------------------------------------------------------------------------------
/**
*/
inline bool
Variable::IsUniform() const
{
    return this->isUniform;
}

//------------------------------------------------------------------------------
/**
*/
inline void
Variable::SetDataType(const DataType& type)
{
    this->type = type;
}

//------------------------------------------------------------------------------
/**
*/
inline const DataType& 
Variable::GetDataType() const
{
    return this->type;
}

} // namespace AnyFX
//------------------------------------------------------------------------------

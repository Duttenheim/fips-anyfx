#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::Symbol
    
    Basic object representation, contains basic information for an AnyFX symbol.
    
    (C) 2013 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <string>
namespace AnyFX
{

struct Compiler;
struct Symbol
{
    enum Type
    {
        InvalidType,
        ProgramType,
        RenderStateType,
        SamplerType,
        VariableType,
        CompoundResourceType,
        TypedResourceType,
        SubroutineType,
        FunctionType,
        StructureType,
        FloatType,
        IntType,
        BoolType,
        StringType,

        NumSymbolTypes
    };

    struct Location
    {
        std::string file;
        int line;
        int column;

        Location()
            : line(-1)
            , column(-1)
        {}
    };

    /// constructor
    Symbol();
    /// destructor
    virtual ~Symbol();

    //------------------------------------------------------------------------------
    /**
        Parser state
    */
    //------------------------------------------------------------------------------
    bool reserved;
    std::string name;
    Type symbolType;

    Location location;

    /// construct string representing the line:row and file for this symbol
    std::string GetLocation() const;

    /// trigger an end-of-parsing event, this is where objects can setup their compiler contextual states
    virtual bool EndOfParse(Compiler* compiler);

    //------------------------------------------------------------------------------
    /**
        Compiler state
    */
    //------------------------------------------------------------------------------
    std::string signature;

    std::string TypeToString() const;
}; 

} // namespace AnyFX
//------------------------------------------------------------------------------
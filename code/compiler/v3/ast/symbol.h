#pragma once
//------------------------------------------------------------------------------
/**
    @class AnyFX::Symbol
    
    Basic object representation, contains basic information for an AnyFX symbol.

    Each symbol has a set of parser data and compiler data. Parser data comes from
    the ANTLR parse of the source code. The other half, compiler data, is data resolved
    from the validation and generation step, and includes the unfolded result of expressions,
    flags and such.
    
    (C) 2021 Gustav Sterbrant
*/
//------------------------------------------------------------------------------
#include <string>

#define _IMPLEMENT_ATTRIBUTES() std::vector<Attribute> attributes;
#define _IMPLEMENT_ANNOTATIONS() std::vector<Annotation> annotations;

namespace AnyFX
{

struct Compiler;
struct Symbol
{
    enum SymbolType
    {
        InvalidType,
        ProgramType,
        RenderStateType,
        SamplerStateType,
        VariableType,
        SubroutineType,
        FunctionType,
        StructureType,
        FloatExpressionType,
        IntExpressionType,
        BoolExpressionType,
        StringExpressionType,
        BinaryExpressionType,
        SymbolExpressionType,
        AccessExpressionType,
        ArrayIndexExpressionType,
        AssignExpressionType,
        CallExpressionType,
        BreakStatementType,
        ContinueStatementType,
        DeclarationStatementType,
        ExpressionStatementType,
        ForStatementType,
        IfStatementType,
        ReturnStatementType,
        ScopeStatementType,
        SwitchStatementType,
        TernaryStatementType,
        WhileStatementType,

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
    std::string name;
    SymbolType symbolType;

    Location location;

    /// construct string representing the line:row and file for this symbol
    std::string GetLocation() const;

    /// trigger an end-of-parsing event, this is where objects can setup their compiler contextual states
    virtual bool EndOfParse(Compiler* compiler);

    const std::string TypeToString() const;

    //------------------------------------------------------------------------------
    /**
        Compiler state
    */
    //------------------------------------------------------------------------------
    struct __Resolved
    {
        std::string signature;
    };
    __Resolved* resolved;
}; 

} // namespace AnyFX
//------------------------------------------------------------------------------
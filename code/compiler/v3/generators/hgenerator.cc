//------------------------------------------------------------------------------
//  @file hgenerator.cc
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "hgenerator.h"
#include "ast/symbol.h"
#include "ast/structure.h"
#include "util.h"
namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
bool 
HGenerator::Generate(Compiler* compiler, Program* program, const std::vector<Symbol*>& symbols, std::function<void(const std::string&, const std::string&)> writerFunc)
{
    std::string output;
    for (Symbol* sym : symbols)
    {
        switch (sym->symbolType)
        {
        case Symbol::StructureType:
            this->GenerateStructure(compiler, program, sym, output);
            break;
        case Symbol::VariableType:
            this->GenerateVariable(compiler, program, sym, output, false);
            break;
        }
    }

    // output header
    if (writerFunc)
        writerFunc("header", output);

    return true;
}

std::map<Type::Code, std::string> typeToHeaderType =
{
    { Type::Code::Float, "float" },
    { Type::Code::Float2, "float" },
    { Type::Code::Float3, "float" },
    { Type::Code::Float4, "float" },
    { Type::Code::Int, "int" },
    { Type::Code::Int2, "int" },
    { Type::Code::Int3, "int" },
    { Type::Code::Int4, "int" },
    { Type::Code::UInt, "unsigned int" },
    { Type::Code::UInt2, "unsigned int" },
    { Type::Code::UInt3, "unsigned int" },
    { Type::Code::UInt4, "unsigned int" },
    { Type::Code::Bool, "bool" },
    { Type::Code::Bool2, "bool" },
    { Type::Code::Bool3, "bool" },
    { Type::Code::Bool4, "bool" },
    { Type::Code::Mat2x2, "float" },
    { Type::Code::Mat2x3, "float" },
    { Type::Code::Mat2x4, "float" },
    { Type::Code::Mat3x2, "float" },
    { Type::Code::Mat3x3, "float" },
    { Type::Code::Mat3x4, "float" },
    { Type::Code::Mat4x2, "float" },
    { Type::Code::Mat4x3, "float" },
    { Type::Code::Mat4x4, "float" },
    { Type::Code::Void, "void" }
};

std::map<Type::Code, std::string> typeToArraySize =
{
    { Type::Code::Float, "" },
    { Type::Code::Float2, "[2]" },
    { Type::Code::Float3, "[3]" },
    { Type::Code::Float4, "[4]" },
    { Type::Code::Int, "" },
    { Type::Code::Int2, "[2]" },
    { Type::Code::Int3, "[3]" },
    { Type::Code::Int4, "[4]" },
    { Type::Code::UInt, "" },
    { Type::Code::UInt2, "[2]" },
    { Type::Code::UInt3, "[3]" },
    { Type::Code::UInt4, "[4]" },
    { Type::Code::Bool, "" },
    { Type::Code::Bool2, "[2]" },
    { Type::Code::Bool3, "[3]" },
    { Type::Code::Bool4, "[4]" },
    { Type::Code::Mat2x2, "[2][2]" },
    { Type::Code::Mat2x3, "[2][3]" },
    { Type::Code::Mat2x4, "[2][4]" },
    { Type::Code::Mat3x2, "[3][2]" },
    { Type::Code::Mat3x3, "[3][3]" },
    { Type::Code::Mat3x4, "[3][4]" },
    { Type::Code::Mat4x2, "[4][2]" },
    { Type::Code::Mat4x3, "[4][3]" },
    { Type::Code::Mat4x4, "[4][4]" },
    { Type::Code::Void, "void" }
};

//------------------------------------------------------------------------------
/**
*/
void 
HGenerator::GenerateStructure(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode)
{
    Structure* struc = static_cast<Structure*>(symbol);
    std::string variables;
    for (Variable* var : struc->members)
    {
        this->GenerateVariable(compiler, program, var, variables, false);
        if (var != struc->members.back())
            variables.append("\n");
    }

    outCode.append(Format("struct %s\n{\n%s\n};\n\n", struc->name.c_str(), variables.c_str()));
}

//------------------------------------------------------------------------------
/**
*/
void 
HGenerator::GenerateVariable(Compiler* compiler, Program* program, Symbol* symbol, std::string& outCode, bool isShaderArgument)
{
    Variable* var = static_cast<Variable*>(symbol);
    Variable::__Resolved* varResolved = static_cast<Variable::__Resolved*>(var->resolved);
    if (varResolved->usageBits.flags.isStructMember
        || varResolved->usageBits.flags.isConstantBufferMember
        || varResolved->usageBits.flags.isStorageBufferMember)
    {        
        // add start padding if any
        if (varResolved->startPadding > 0)
        {
            outCode.append(Format("    unsigned int : %d;\n", varResolved->startPadding));
        }

        std::string type = typeToHeaderType[varResolved->type->code];
        std::string arrayType = typeToArraySize[varResolved->type->code];

        // if element padding, we need to split the array into elements where each element is padded
        if (varResolved->elementPadding > 0)
        {
            for (int i = 0; i < varResolved->arraySize; i++)
            {
                // don't pad the first element
                if (i > 0)
                    outCode.append(Format("    unsigned int : %d;\n", varResolved->elementPadding));
                outCode.append(Format("    %s %s_%d%s;", type.c_str(), var->name.c_str(), i, arrayType.c_str()));
                if (i < varResolved->arraySize - 1)
                    outCode.append("\n");
            }
        }
        else
        {
            outCode.append(Format("    %s %s%s;", type.c_str(), var->name.c_str(), arrayType.c_str()));
        }
        
    }
    else if (varResolved->usageBits.flags.isConst)
    {
        std::string typeStr = typeToHeaderType[varResolved->type->code];
        std::string arrayTypeStr = typeToArraySize[varResolved->type->code];
        std::string initializerStr;
        for (int j = 0; j < varResolved->initializers.size(); j++)
        {
            auto& initializers = varResolved->initializers[j];
            std::string internalInitializerStr;
            for (int i = 0; i < initializers.size(); i++)
            {
                auto& init = initializers[i];
                switch (init.type)
                {
                case Variable::__Resolved::Initializer::FloatType:
                    internalInitializerStr.append(Format("%f", init.data.f));
                    break;
                case Variable::__Resolved::Initializer::IntType:
                    internalInitializerStr.append(Format("%d", init.data.f));
                    break;
                case Variable::__Resolved::Initializer::UIntType:
                    internalInitializerStr.append(Format("%d", init.data.f));
                    break;
                case Variable::__Resolved::Initializer::BoolType:
                    internalInitializerStr.append(init.data.b ? "true" : "false");
                    break;
                }

                if (i != initializers.size() - 1)
                    internalInitializerStr.append(", ");
            }

            // if we have more than one initializer, add {} around it
            if (initializers.size() > 1)
                internalInitializerStr = Format("{ %s }", internalInitializerStr.c_str());

            initializerStr.append(internalInitializerStr);
            if (j != varResolved->initializers.size() - 1)
                initializerStr.append(", ");
        }
        std::string arraySize = "";
        if (varResolved->arraySize > 1)
        {
            initializerStr = Format("{ %s }", initializerStr.c_str());
            arraySize = Format("[%d]", varResolved->arraySize);
        }
        else
            initializerStr = Format("%s", initializerStr.c_str());
        outCode.append(Format("const %s %s%s%s = %s;\n", typeStr.c_str(), var->name.c_str(), arraySize.c_str(), arrayTypeStr.c_str(), initializerStr.c_str()));
    }
}

} // namespace AnyFX

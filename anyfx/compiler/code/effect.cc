//------------------------------------------------------------------------------
//  effect.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "./effect.h"
#include <assert.h>
#include "constant.h"
#include "generator.h"
#include <algorithm>
#include <map>
#include <variant>

#define VERSION_MAJOR 2
#define VERSION_MINOR 1

#define ROUND_TO_POW(n, p) ((n + p - 1) & ~(p - 1))

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Effect::Effect()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Effect::~Effect()
{
    this->shaders.clear();
    
    for (auto symbol : this->symbols)
    {
        symbol->Destroy();
    }
    this->symbols.clear();

    for (auto symbol : this->subroutinesToDelete)
    {
        symbol->Destroy();
    }
    this->subroutinesToDelete.clear();
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddProgram(Program* program)
{
    this->symbols.push_back(program);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddVariable(Variable* var)
{
    this->symbols.push_back(var);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddRenderState(RenderState* state)
{
    this->symbols.push_back(state);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddFunction(Function* function)
{
    this->symbols.push_back(function);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddStructure(Structure* structure)
{
    this->symbols.push_back(structure);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddVarBlock(VarBlock* varBlock)
{
    this->symbols.push_back(varBlock);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddVarBuffer(VarBuffer* varBuffer)
{
    this->symbols.push_back(varBuffer);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddSubroutine(Subroutine* subroutine)
{
    this->symbols.push_back(subroutine);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::AddSampler(Sampler* sampler)
{
    this->symbols.push_back(sampler);
}

//------------------------------------------------------------------------------
/**
*/
void 
Effect::Setup()
{
    assert(this->header.GetType() != Header::InvalidType);

    // reset static states
    Shader::ResetBindings();

    std::vector<Function*> functions;
    std::vector<unsigned> programIndexes;
    std::vector<Program*> programs;
    unsigned indexOfFirstProgram = 0xFFFFFFFF;
    unsigned i;
    for (i = 0; i < this->symbols.size(); i++)
    {
        Symbol* sym = this->symbols[i];
        if (sym->GetType() == Symbol::FunctionType)
            functions.push_back((Function*)sym);
        else if (sym->GetType() == Symbol::ProgramType)
        {
            programs.push_back((Program*)sym);
            programIndexes.push_back(i);
        }
    }

    // Go through programs and build shaders. This will effectively 
    unsigned numAddedShaders = 0;
    for (i = 0; i < programs.size(); i++)
    {
        unsigned originalIndex = programIndexes[i] + numAddedShaders, newIndex = programIndexes[i] + numAddedShaders;
        programs[i]->BuildShaders(this->header, this->alloc, newIndex, functions, this->symbols, this->shaders);
        numAddedShaders += newIndex - originalIndex;
    }

    // Erase all functions marked as shader, they are already picked up and saved 
    // in the shaders variable above
    for (i = 0; i < this->symbols.size(); i++)
    {
        Symbol* sym = this->symbols[i];
        if (sym->GetType() == Symbol::FunctionType)
        {
            // get function
            Function* func = (Function*)sym;

            if (func->IsShader())
            {
                this->functionsToDelete.push_back(sym);
                this->symbols.erase(this->symbols.begin() + i);
                i--;
            }
        }
    }

    // create a placeholder render state, which will be used for programs where no render state is explicitly assigned
    this->placeholderRenderState = this->alloc.Alloc<RenderState>();
    this->placeholderRenderState->SetName("PlaceholderState");
    this->placeholderRenderState->SetReserved(true);
    this->symbols.insert(this->symbols.begin(), this->placeholderRenderState);

    if (header.GetFlags() & Header::PutGlobalVariablesInBlock)
    {
        if (!this->symbols.empty())
        {
            this->placeholderVarBlock = this->alloc.Alloc<VarBlock>();
            this->placeholderVarBlock->SetName("GlobalBlock");
            this->placeholderVarBlock->SetReserved(true);
            this->placeholderVarBlock->AddQualifier("shared");
            this->symbols.insert(this->symbols.begin(), this->placeholderVarBlock);

            for (i = 0; i < this->symbols.size(); i++)
            {
                if (this->symbols[i]->GetType() == Symbol::VariableType)
                {
                    Variable* var = (Variable*)this->symbols[i];
                    var->Preprocess();
                    if (var->GetDataType().GetType() < DataType::Sampler1D && var->IsUniform())
                    {
                        this->placeholderVarBlock->AddVariable(var);
                        this->symbols.erase(this->symbols.begin() + i);
                        i--;
                    }
                }
            }

            // sort variables, since we can't handle the alignment manually here
            this->placeholderVarBlock->SortVariables();
        }
    }
    else
    {
        for (i = 0; i < this->symbols.size(); i++)
        {
            if (this->symbols[i]->GetType() == Symbol::VariableType)
            {
                Variable* var = (Variable*)this->symbols[i];
                var->Preprocess();
            }
        }
    }

    // if header has default group number, use it
    const std::string& defaultSet = this->header.GetValue("/DEFAULTSET");
    unsigned defaultSetIdx = 0;
    if (defaultSet != "/DEFAULTSET")
    {
        defaultSetIdx = std::stoi(defaultSet);
    }

    for (i = 0; i < this->symbols.size(); i++)
    {
        switch (this->symbols[i]->GetType())
        {
            case Symbol::VarblockType:
                static_cast<VarBlock*>(this->symbols[i])->group = defaultSetIdx;
                break;
            case Symbol::VarbufferType:
                static_cast<VarBuffer*>(this->symbols[i])->group = defaultSetIdx;
                break;
            case Symbol::SamplerType:
                static_cast<Sampler*>(this->symbols[i])->group = defaultSetIdx;
                break;
            case Symbol::VariableType:
                static_cast<Variable*>(this->symbols[i])->group = defaultSetIdx;
                break;
            default:
                continue;
        }
    }
    
    // now, finalize all shaders, this adds all structures, varblocks and functions into all shaders, making sure they compile properly
    // we let the target compiler optimize unnecessary variables and functions away
    std::map<std::string, Shader*>::iterator it;
    for (it = this->shaders.begin(); it != this->shaders.end(); it++)
    {
        Shader* shader = it->second;
        shader->Setup();
    }
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::TypeCheck(TypeChecker& typechecker)
{
    this->header.TypeCheck(typechecker);

    unsigned i;
    unsigned j = 0;

    for (i = 0; i < this->symbols.size(); i++)
    {
        Symbol* sym = this->symbols[i];
        sym->TypeCheck(typechecker);
        if (sym->GetType() == Symbol::SubroutineType)
        {
            Subroutine* subroutine = (Subroutine*)sym;
            subroutine->UpdateCode(this->header, j++);
        }
        else if (sym->GetType() == Symbol::FunctionType)
        {
            Function* func = (Function*)sym;
            func->Restore(this->header, j++);
        }
    }

    // remove variables used as subroutines
    for (i = 0; i < this->symbols.size(); i++)
    {
        Symbol* sym = this->symbols[i];
        if (sym->GetType() == Symbol::VariableType)
        {
            Variable* var = (Variable*)sym;
            if (this->header.GetFlags() & Header::NoSubroutines && var->IsSubroutine())
            {
                this->subroutinesToDelete.push_back(sym);
                this->symbols.erase(this->symbols.begin() + i);
                i--;
            }
        }
    }
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::Generate(Generator& generator)
{
    // typecheck all shaders
    std::map<std::string, Shader*>::iterator it;
    unsigned i = 0;
    for (it = this->shaders.begin(); it != this->shaders.end(); it++)
    {
        Shader* shader = it->second;

        // generate code for shaders
        shader->Generate(generator, this->symbols);

        // output generated code if we flag it
        if (this->header.GetFlags() & Header::OutputGeneratedShaders)
        {
            BinWriter out;
            out.SetPath(AnyFX::Format("%s_%d%s", this->debugOutput.c_str(), i++, "_debug.txt"));
            out.Open();
            const std::string compiled = shader->GetCompiledCode();
            out.WriteBytes(compiled.c_str(), compiled.length());
            out.Close();
        }
    }

    if (generator.GetStatus() == Generator::Success) 
        for (i = 0; i < this->symbols.size(); i++)
        {
            Symbol* sym = this->symbols[i];
            if (sym->GetType() == Symbol::ProgramType)
            {
                Program* prog = (Program*)sym;
                prog->Generate(generator);

                if (this->header.GetFlags() & Header::OutputGeneratedShaders)
                {
                    unsigned j;
                    for (j = 0; j < ProgramRow::NumProgramRows - 1; j++)
                    {
                        BinWriter out;
                        out.SetPath(AnyFX::Format("%s_%s_%d%s", this->debugOutput.c_str(), prog->GetName().c_str(), j, "_debug.bin"));
                        out.Open();
                        const std::vector<unsigned> bin = prog->GetBinary(j);
                        prog->WriteBinary(bin, out);
                        out.Close();
                    }
                }
            }
        }
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::Compile(BinWriter& writer)
{
    assert(this->header.GetType() != Header::InvalidType);

    // write magic number
    writer.WriteInt('ANFX');
    writer.WriteInt(VERSION_MAJOR);
    writer.WriteInt(VERSION_MINOR);

    std::vector<RenderState*> renderStates;
    std::vector<Subroutine*> subroutines;
    std::vector<Program*> programs;
    std::vector<Variable*> variables;
    std::vector<Sampler*> samplers;
    std::vector<VarBlock*> varblocks;
    std::vector<VarBuffer*> varbuffers;
    unsigned i;
    for (i = 0; i < this->symbols.size(); i++)
    {
        Symbol* sym = this->symbols[i];
        switch (sym->GetType())
        {
            case Symbol::RenderStateType:
                renderStates.push_back((RenderState*)sym);
                break;
            case Symbol::SubroutineType:
                subroutines.push_back((Subroutine*)sym);
                break;
            case Symbol::ProgramType:
                programs.push_back((Program*)sym);
                break;
            case Symbol::VariableType:
                variables.push_back((Variable*)sym);
                break;
            case Symbol::SamplerType:
                samplers.push_back((Sampler*)sym);
                break;
            case Symbol::VarblockType:
                varblocks.push_back((VarBlock*)sym);
                break;
            case Symbol::VarbufferType:
                varbuffers.push_back((VarBuffer*)sym);
                break;
        }
    }

    // write header, vital!
    this->header.Compile(writer);

    
    // write FourCC code for shaders
    writer.WriteInt('SHAD');

    // write amount of shaders
    writer.WriteInt(this->shaders.size());

    // compile all shaders
    std::map<std::string, Shader*>::iterator it;
    for (it = this->shaders.begin(); it != this->shaders.end(); it++)
    {
        Shader* shader = it->second;

        // then compile
        shader->Compile(writer);
    }

    // write FourCC code for render states
    writer.WriteInt('RENS');

    // write amount of render states
    writer.WriteInt(renderStates.size());

    // compile render states for runtime
    for (i = 0; i < renderStates.size(); i++)
    {
        renderStates[i]->Compile(writer);
    }

    // write FourCC code for subroutines
    writer.WriteInt('SUBR');

    // write amount of subroutines
    writer.WriteInt(subroutines.size());

    // compile subroutines for runtime
    for (i = 0; i < subroutines.size(); i++)
    {
        subroutines[i]->Compile(writer);
    }

    // write FourCC code for programs
    writer.WriteInt('PROG');

    // write amount of programs
    writer.WriteInt(programs.size());

    // compile programs for runtime
    for (i = 0; i < programs.size(); i++)
    {
        programs[i]->Compile(writer);    }

    // write FourCC code for variables
    writer.WriteInt('VARI');

    // write amount of variables
    writer.WriteInt(variables.size());

    // compile variables for runtime
    for (i = 0; i < variables.size(); i++)
    {
        variables[i]->Compile(writer);
    }

    // write FourCC code for samplers
    writer.WriteInt('SAMP');

    // write amount of samplers
    writer.WriteInt(samplers.size());

    for (i = 0; i < samplers.size(); i++)
    {
        samplers[i]->Compile(writer);
    }

    // write FourCC code for varblocks
    writer.WriteInt('VARB');

    // write amount of varblocks
    writer.WriteInt(varblocks.size());

    // compile varblocks for runtime
    for (i = 0; i < varblocks.size(); i++)
    {
        varblocks[i]->Compile(writer);
    }

    // write FourCC code for varbuffers
    writer.WriteInt('VRBF');

    // write amount of varbuffers
    writer.WriteInt(varbuffers.size());

    // compile varbuffers for runtime
    for (i = 0; i < varbuffers.size(); i++)
    {
        varbuffers[i]->Compile(writer);
    }
}

//------------------------------------------------------------------------------
/**
*/
void 
Effect::GenerateHeader(TextWriter& writer)
{
    
    std::string output = AnyFX::Format("#pragma once\n\
//------------------------------------------------------------------------------\n\
/** \n	Generated from shader '%s' \n\n\
    DO NOT MODIFY HERE!!! \n \
*/\
\n#include <map>\
\n#include <string>\
\n#include <cstdint>\
\ntypedef uint64_t buffer_ptr;\
\ntypedef uint32_t uint;\
\n\nnamespace %s\n{\n\n", 
        this->file.c_str(), this->name.c_str());
    writer.WriteString(output);

    unsigned i;

    std::map<int, std::vector<Variable::Binding>> bindings; 

    for (i = 0; i < this->symbols.size(); i++)
    {
        Symbol* sym = this->symbols[i];
        if (sym->GetType() == Symbol::StructureType
            || sym->GetType() == Symbol::VariableType
            || sym->GetType() == Symbol::VarblockType
            || sym->GetType() == Symbol::VarbufferType)
        {
            if (sym->GetType() == Symbol::VariableType)
            {
                Variable* variable = (Variable*)sym;
                if ((variable->GetDataType().GetType() >= DataType::ALL_TEXTURE_TYPES_BEGIN && variable->GetDataType().GetType() <= DataType::ALL_TEXTURE_TYPES_END)
                    || (variable->GetDataType().GetType() == DataType::AccelerationStructure))
                {
                    Variable::Binding binding = variable->GetBinding();
                    bindings[binding.group].push_back(binding);
                    continue;
                }
            }
            else if (sym->GetType() == Symbol::VarblockType)
            {
                VarBlock* varblock = (VarBlock*)sym;
                auto binding = varblock->GetBinding();
                bindings[binding.group].push_back(binding);
            }
            else if (sym->GetType() == Symbol::VarbufferType)
            {
                VarBuffer* varbuffer = (VarBuffer*)sym;
                auto binding = varbuffer->GetBinding();
                bindings[binding.group].push_back(binding);
            }
            writer.WriteString(sym->Format(this->header));
        }
    }

    // Generate resource table classes
    auto iter = bindings.begin();
    while (iter != bindings.end())
    {
        std::string tableName = AnyFX::Format("Table_%d", iter->first);
        auto name = this->resourceTableNames.find(iter->first);
        if (name != this->resourceTableNames.end())
            tableName = AnyFX::Format("Table_%s", name->second.c_str());
        writer.WriteString(AnyFX::Format("struct %s \n{\n\t", tableName.c_str()));
        for (auto binding : iter->second)
        {
            if (binding.type == Variable::Binding::Type::Texture ||
                binding.type == Variable::Binding::Type::AccelerationStructure)
            {
                writer.WriteString(AnyFX::Format("static const unsigned %s_SLOT = %d;\n\t", binding.name.c_str(), binding.binding.texture.slot));
            }
            else
            {
                writer.WriteString(AnyFX::Format("static const unsigned %s_SLOT = %d;\n\t", binding.name.c_str(), binding.binding.buffer.slot));
            }
        }
        writer.WriteString("\n};\n");
        iter++;
    }

    writer.WriteString("}");
}

//------------------------------------------------------------------------------
/**
*/
unsigned 
Effect::RoundToPow2(unsigned number, unsigned power)
{
    return number = (number + power - 1) & ~(power - 1);
}

//------------------------------------------------------------------------------
/**
*/
void
Effect::GetAlignmentGLSL(const DataType& type, unsigned arraySize, unsigned& size, unsigned& alignment, const bool std140, const bool structMember, TypeChecker& typechecker)
{
    DataType::Dimensions dims = DataType::ToDimensions(type);
    unsigned byteSize = DataType::ToByteSize(DataType::ToPrimitiveType(type));
    const unsigned vec4alignment = 16;
    unsigned elementAlignment = 0;

    /*
    1.  If the member is a scalar consuming N basic machine units, the base alignment is N.
    2.  If the member is a two- or four-component vector with components consuming N basic machine units, the base alignment is 2N or 4N, respectively.
    3.  If the member is a three-component vector with components consuming N basic machine units, the base alignment is 4N.
    4.  If the member is an array of scalars or vectors, the base alignment and array stride are set to match the base alignment of a single array element, 
        according to rules (1), (2), and (3), and rounded up to the base alignment of a vec4. The array may have padding at the end; 
        the base offset of the member following the array is rounded up to the next multiple of the base alignment.
    5.  If the member is a column-major matrix with C columns and R rows, the matrix is stored identically to an array of C column vectors with R 
        components each, according to rule (4).
    6.  If the member is an array of S column-major matrices with C columns and R rows, the matrix is stored identically to a row of 
        S×C column vectors with R components each, according to rule (4).
    7.  If the member is a row-major matrix with C columns and R rows, the matrix is stored identically to an array of R row vectors with C components each, 
        according to rule (4).
    8.  If the member is an array of S row-major matrices with C columns and R rows, the matrix is stored identically to a row of S×R row vectors with C 
        components each, according to rule (4).
    9.  If the member is a structure, the base alignment of the structure is N, where N is the largest base alignment value of any of its members, 
        and rounded up to the base alignment of a vec4. The individual members of this sub-structure are then assigned offsets by applying this set of 
        rules recursively, where the base offset of the first member of the sub-structure is equal to the aligned offset of the structure. 
        The structure may have padding at the end; the base offset of the member following the sub-structure is 
        rounded up to the next multiple of the base alignment of the structure.
    10. If the member is an array of S structures, the S elements of the array are laid out in order, according to rule

    For std430, rounding up to vec4 in rule 4 and 9 is not relevant
    */

    // calculate alignment per element
    switch (dims.x)
    {
    case 0:		// this happens if we have structs
        break;
    case 1:
        alignment = byteSize;
        size = byteSize;
        break;
    case 2:
        alignment = byteSize * 2;
        size = byteSize * 2;
        break;
    case 3:
        alignment = byteSize * 4;
        size = byteSize * 3;
        break;
    case 4:
        alignment = byteSize * 4;
        size = byteSize * 4;
        break;
    default:
        // should never happen
        alignment = byteSize;
        size = byteSize;
        break;
    }

    if (arraySize > 1) // if array
    {
        Effect::GetAlignmentGLSL(type, 1, size, alignment, std140, structMember, typechecker);
        unsigned int baseAlignment = alignment;
        if (std140)
            alignment = std::max(vec4alignment, alignment);
        size *= arraySize;
        size = RoundToPow2(size, baseAlignment);
    }
    else if (type.GetType() == DataType::UserType)  // if structure
    {
        Symbol* sym = typechecker.GetSymbol(type.GetName());
        if (sym != nullptr)
        {
            if (sym->GetType() == Symbol::StructureType)
            {
                Structure* structure = (Structure*)sym;
                if (structure->isPointer)
                {
                    size = 8;
                    alignment = 8;
                }
                else
                {
                    structure->UpdateAlignmentAndSize(typechecker);
                    size = structure->alignedSize;
                    alignment = structure->alignment;
                }
            }
            else
            {
                size = 0;
                alignment = vec4alignment;
            }
        }
        else
        {
            size = 1;
            alignment = vec4alignment;
        }
    }
    else if (dims.y > 1) // if matrix
    {
        if (std140)
            alignment = std::max(vec4alignment, alignment);
        size = RoundToPow2(size, alignment);
        size *= dims.y;
    }
}

} // namespace AnyFX

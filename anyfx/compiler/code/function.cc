//------------------------------------------------------------------------------
//  function.cc
//  (C) 2013 Gustav Sterbrant
//------------------------------------------------------------------------------
#include "function.h"
#include "util.h"
#include "typechecker.h"

namespace AnyFX
{

//------------------------------------------------------------------------------
/**
*/
Function::Function() :
    fileIndex(-1),
    shaderTarget(false)
{
    this->symbolType = Symbol::FunctionType;

    unsigned i;
    for (i = 0; i < FunctionAttribute::NumIntFlags; i++)
    {
        this->intAttributeMask[i] = false;
        this->intAttributes[i] = 0;
    }

    for (i = 0; i < FunctionAttribute::NumFloatFlags; i++)
    {
        this->floatAttributeMask[i] = false;
        this->floatAttributes[i] = 0;
    }

    for (i = 0; i < FunctionAttribute::NumBoolFlags; i++)
    {
        this->boolAttributeMask[i] = false;
        this->boolAttributes[i] = false;
    }

    for (i = 0; i < FunctionAttribute::NumStringFlags; i++)
    {
        this->stringAttributeMask[i] = false;
        this->stringAttributes[i] = "";
    }
}

//------------------------------------------------------------------------------
/**
*/
Function::~Function()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
void
Function::SetParameters(const std::vector<Parameter>& parameters)
{
    this->parameters = parameters;
}

//------------------------------------------------------------------------------
/**
*/
void
Function::SetReturnType(const DataType& type)
{
    this->returnType = type;
}

//------------------------------------------------------------------------------
/**
*/
void
Function::SetCode(const std::string& data)
{
    this->code = data;
}

//------------------------------------------------------------------------------
/**
*/
void
Function::ConsumeAttribute(const FunctionAttribute& attr)
{
    this->attributes.push_back(attr);
}

//------------------------------------------------------------------------------
/**
*/
void
Function::TypeCheck(TypeChecker& typechecker)
{
    // create a signature if not a shader target, we cannot overload shader targets
    if (!this->shaderTarget)
    {
        std::string signature;
        unsigned i;
        for (i = 0; i < this->parameters.size(); i++)
        {
            const Parameter& firstParam = this->parameters[i];
            signature += DataType::ToSignature(firstParam.GetDataType()) + ",";
        }
        this->signature = signature;
    }	

    // add function, if failed we must have a redefinition
    if (!typechecker.AddSymbol(this)) return;

    // evaluate attributes
    this->EvaluateAttributes(typechecker);

    if (this->returnType.GetType() == DataType::Undefined)
    {
        std::string message = AnyFX::Format("Return type of function '%s' is undefined, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
        typechecker.Error(message, this->GetFile(), this->GetLine());
    }

    for (int i = 0; i < this->invalidAttributes.size(); i++)
    {
        std::string message = AnyFX::Format("Invalid function attribute '%s', %s\n", this->invalidAttributes[i].c_str(), this->ErrorSuffix().c_str());
        typechecker.Error(message, this->GetFile(), this->GetLine());
    }

    for (int i = 0; i < this->invalidAttributeValues.size(); i++)
    {
        std::string message = AnyFX::Format("Invalid function attribute value '%s', %s\n", this->invalidAttributeValues[i].c_str(), this->ErrorSuffix().c_str());
        typechecker.Error(message, this->GetFile(), this->GetLine());
    }

    // type check parameters
    unsigned input = 0;
    unsigned output = 0;
    for (int i = 0; i < this->parameters.size(); i++)
    {
        AnyFX::Parameter& param = this->parameters[i];
        param.TypeCheck(typechecker);

        if (this->IsShader() &&
            (param.GetIO() == Parameter::NoIO || param.GetIO() == Parameter::InputOutput))
        {
            std::string message = AnyFX::Format("Shader parameter '%s' must be either declared with 'out' or 'in', %s\n", param.GetName().c_str(), this->ErrorSuffix().c_str());
            typechecker.Error(message, this->GetFile(), this->GetLine());
        }

        if (!param.HasExplicitSlot())
        {
            if (param.GetIO() == Parameter::Input)          param.SetParameterIndex(input++);
            else if (param.GetIO() == Parameter::Output)    param.SetParameterIndex(output++);
            else                                            param.SetParameterIndex(i);
        }        
        else
        {
            if (param.GetIO() == Parameter::Input)			input = param.GetSlot();
            else if (param.GetIO() == Parameter::Output)	output = param.GetSlot();
        }
    }

    unsigned j;
    for (int i = 0; i < this->parameters.size(); i++)
    {
        const Parameter& firstParam = this->parameters[i];

        for (j = i+1; j < this->parameters.size(); j++)
        {
            const Parameter& secondParam = this->parameters[j];
            // if parameters have no attribute we must make sure we don't have duplicates
            if (firstParam.GetAttribute() != Parameter::NoAttribute)
            {
                if (firstParam.GetName() != secondParam.GetName())
                {
                    if (firstParam.GetAttribute() == secondParam.GetAttribute())
                    {
                        std::string firstAttr = Parameter::AttributeToString(firstParam.GetAttribute());
                        std::string secondAttr = Parameter::AttributeToString(secondParam.GetAttribute());
                        std::string message = AnyFX::Format("Parameters '%s' (%s) and '%s' (%s) may not have the same qualifiers, %s\n",
                            firstParam.GetName().c_str(), 
                            firstAttr.c_str(),
                            secondParam.GetName().c_str(),
                            secondAttr.c_str(),
                            this->ErrorSuffix().c_str());
                        typechecker.Error(message, this->GetFile(), this->GetLine());
                    }
                }
            }
            if (firstParam.GetSlot() == secondParam.GetSlot() && firstParam.GetIO() == secondParam.GetIO())
            {
                std::string msg = AnyFX::Format("Parameters '%s' and '%s' share the same binding slot '%d' in shader function '%s'. Probably due to one or both of them having an explicit slot defined, %s\n",
                    firstParam.GetName().c_str(),
                    secondParam.GetName().c_str(),
                    firstParam.GetSlot(),
                    this->name.c_str(),
                    this->ErrorSuffix().c_str());
                typechecker.Error(msg, this->GetFile(), this->GetLine());
            }
        }		
    }
}

//------------------------------------------------------------------------------
/**
*/
void
Function::Restore(const Header& header, int index)
{
    std::string restoredCode;
    this->fileIndex = index;

    const Header::Type& type = header.GetType();

    // restore return value and name
    restoredCode.append(DataType::ToProfileType(this->returnType, type));
    restoredCode.append("\n");
    restoredCode.append(this->name);
    restoredCode.append("(");

    unsigned i;
    for (i = 0; i < this->parameters.size(); i++)
    {
        const Parameter& param = this->parameters[i];

        // write const qualifier if present
        if (param.GetConst())
        {
            restoredCode.append("const ");
        }

        // write IO mode
        if (param.GetIO() == Parameter::Input)
        {
            restoredCode.append("in ");
        }
        else if (param.GetIO() == Parameter::Output)
        {
            restoredCode.append("out ");
        }
        else if (param.GetIO() == Parameter::InputOutput)
        {
            restoredCode.append("inout ");
        }

        restoredCode.append(DataType::ToProfileType(param.GetDataType(), type));
        restoredCode.append(" ");
        restoredCode.append(param.GetName());

        if (param.IsArray())
        {
            std::string arrayString = AnyFX::Format("[%d]", param.GetArraySize());
            restoredCode.append(arrayString);
        }

        if (i < this->parameters.size()-1)
        {
            restoredCode.append(", ");
        }
    }

    // finalize by closing parameter list and append the code
    restoredCode.append(")\n{\n");
    restoredCode.append(AnyFX::Format("#line %d %s\n", this->codeLine, this->file.c_str()));
    restoredCode.append(this->code);
    restoredCode.append("\n}\n\n");

    // now, replace the code with the restored code
    this->code = restoredCode;
}

//------------------------------------------------------------------------------
/**
*/
void 
Function::EvaluateAttributes(TypeChecker& typeChecker)
{

#define SET_INT_ATTR(x) { this->intAttributes[x] = attr.GetExpression()->EvalInt(typeChecker);  this->intAttributeMask[x] = true; }
#define SET_INT_ATTR_VAL(x, y) { this->intAttributes[x] = y;  this->intAttributeMask[x] = true; }
#define SET_FLOAT_ATTR(x) { this->floatAttributes[x] = attr.GetExpression()->EvalFloat(typeChecker);  this->floatAttributeMask[x] = true; }
#define SET_BOOL_ATTR(x) { this->boolAttributes[x] = attr.GetBool();  this->boolAttributeMask[x] = true; }
#define SET_STRING_ATTR(x) { this->stringAttributes[x] = attr.GetExpression()->EvalString(typeChecker);  this->stringAttributeMask[x] = true; }

    for (int i = 0; i < this->attributes.size(); i++)
    {
        const FunctionAttribute& attr = this->attributes[i];
        if (attr.GetFlag() == "maxvertexcount" || attr.GetFlag() == "max_vertex_count")
            SET_INT_ATTR(FunctionAttribute::MaxVertexCount)
        else if (attr.GetFlag() == "max_primitive_count")
            SET_INT_ATTR(FunctionAttribute::MaxPrimitives)
        else if (attr.GetFlag() == "instances") 
            SET_INT_ATTR(FunctionAttribute::Instances)
        else if (attr.GetFlag() == "inputvertices" || attr.GetFlag() == "input_vertices")
            SET_INT_ATTR(FunctionAttribute::InputVertices)
        else if (attr.GetFlag() == "outputvertices" || attr.GetFlag() == "output_vertices")
            SET_INT_ATTR(FunctionAttribute::OutputVertices)
        else if (attr.GetFlag() == "localsizex" || attr.GetFlag() == "local_size_x")
            SET_INT_ATTR(FunctionAttribute::LocalSizeX)
        else if (attr.GetFlag() == "localsizey" || attr.GetFlag() == "local_size_y")
            SET_INT_ATTR(FunctionAttribute::LocalSizeY)
        else if (attr.GetFlag() == "localsizez" || attr.GetFlag() == "local_size_z")
            SET_INT_ATTR(FunctionAttribute::LocalSizeZ)
        else if (attr.GetFlag() == "maxtess" || attr.GetFlag() == "max_tess")
            SET_FLOAT_ATTR(FunctionAttribute::MaxTessellation)
        else if (attr.GetFlag() == "earlydepth" || attr.GetFlag() == "early_depth")
            SET_BOOL_ATTR(FunctionAttribute::EarlyDepth)
        else if (attr.GetFlag() == "patchfunction" || attr.GetFlag() == "patch_function")
            SET_STRING_ATTR(FunctionAttribute::PatchFunction)
        else if (attr.GetFlag() == "topology")
        {
            const std::string& value = attr.GetExpression()->EvalString(typeChecker);
            if (value == "triangle")	SET_INT_ATTR_VAL(FunctionAttribute::Topology, FunctionAttribute::Triangle)
            else if (value == "quad")	SET_INT_ATTR_VAL(FunctionAttribute::Topology, FunctionAttribute::Quad)
            else if (value == "line")	SET_INT_ATTR_VAL(FunctionAttribute::Topology, FunctionAttribute::Line)
            else if (value == "point")	SET_INT_ATTR_VAL(FunctionAttribute::Topology, FunctionAttribute::Point)
            else this->invalidAttributeValues.push_back(value);
        }
        else if (attr.GetFlag() == "winding")
        {
            const std::string& value = attr.GetExpression()->EvalString(typeChecker);
            if (value == "cw")			SET_INT_ATTR_VAL(FunctionAttribute::WindingOrder, FunctionAttribute::CW)
            else if (value == "ccw")	SET_INT_ATTR_VAL(FunctionAttribute::WindingOrder, FunctionAttribute::CCW)
            else this->invalidAttributeValues.push_back(value);
        }
        else if (attr.GetFlag() == "partition")
        {
            const std::string& value = attr.GetExpression()->EvalString(typeChecker);
            if (value == "integer")		SET_INT_ATTR_VAL(FunctionAttribute::PartitionMethod, FunctionAttribute::Integer)
            else if (value == "even")	SET_INT_ATTR_VAL(FunctionAttribute::PartitionMethod, FunctionAttribute::Even)
            else if (value == "odd")	SET_INT_ATTR_VAL(FunctionAttribute::PartitionMethod, FunctionAttribute::Odd)
            else if (value == "pow")	SET_INT_ATTR_VAL(FunctionAttribute::PartitionMethod, FunctionAttribute::Pow)
            else this->invalidAttributeValues.push_back(value);
        }
        else if (attr.GetFlag() == "inputprimitive" || attr.GetFlag() == "input_primitive")
        {
            const std::string& value = attr.GetExpression()->EvalString(typeChecker);
            if (value == "points")					SET_INT_ATTR_VAL(FunctionAttribute::InputPrimitive, FunctionAttribute::IPoints)
            else if (value == "lines")				SET_INT_ATTR_VAL(FunctionAttribute::InputPrimitive, FunctionAttribute::ILines)
            else if (value == "lines_adjacent")		SET_INT_ATTR_VAL(FunctionAttribute::InputPrimitive, FunctionAttribute::ILinesAdjacent)
            else if (value == "triangles")			SET_INT_ATTR_VAL(FunctionAttribute::InputPrimitive, FunctionAttribute::ITriangles)
            else if (value == "triangles_adjacent") SET_INT_ATTR_VAL(FunctionAttribute::InputPrimitive, FunctionAttribute::ITrianglesAdjacent)
            else this->invalidAttributeValues.push_back(value);
        }
        else if (attr.GetFlag() == "outputprimitive" || attr.GetFlag() == "output_primitive")
        {
            const std::string& value = attr.GetExpression()->EvalString(typeChecker);
            if (value == "points")				                            SET_INT_ATTR_VAL(FunctionAttribute::OutputPrimitive, FunctionAttribute::OPoints)
            else if (value == "line_strip" || value == "lines")		        SET_INT_ATTR_VAL(FunctionAttribute::OutputPrimitive, FunctionAttribute::OLineStrip)
            else if (value == "triangle_strip" || value == "triangles")     SET_INT_ATTR_VAL(FunctionAttribute::OutputPrimitive, FunctionAttribute::OTriangleStrip)
            else this->invalidAttributeValues.push_back(value);
        }
        else if (attr.GetFlag() == "pixelorigin" || attr.GetFlag() == "pixel_origin")
        {
            const std::string& value = attr.GetExpression()->EvalString(typeChecker);
            if (value == "center")				SET_INT_ATTR_VAL(FunctionAttribute::PixelOrigin, FunctionAttribute::PCenter)
            else if (value == "default")		SET_INT_ATTR_VAL(FunctionAttribute::PixelOrigin, FunctionAttribute::PDefault)
            else this->invalidAttributeValues.push_back(value);
        }
        else
            this->invalidAttributes.push_back(attr.GetFlag());

        attr.GetExpression();
    }

    // clear attributes
    this->attributes.clear();
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<const Parameter*> 
Function::GetInputParameters() const
{
    std::vector<const Parameter*> result;
    unsigned i;
    for (i = 0; i < this->parameters.size(); i++)
    {
        const Parameter* param = &this->parameters[i];
        if (param->GetIO() == Parameter::Input || param->GetIO() == Parameter::NoIO)
        {
            result.push_back(param);
        }
    }
    return result;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<const Parameter*>
Function::GetOutputParameters() const
{
    std::vector<const Parameter*> result;
    unsigned i;
    for (i = 0; i < this->parameters.size(); i++)
    {
        const Parameter* param = &this->parameters[i];
        if (param->GetIO() == Parameter::Output || param->GetIO() == Parameter::NoIO)
        {
            result.push_back(param);
        }
    }
    return result;
}

//------------------------------------------------------------------------------
/**
*/
const std::vector<Parameter>&
Function::GetParameters() const
{
    return this->parameters;
}

//------------------------------------------------------------------------------
/**
*/
std::string 
Function::Format(const Header& header) const
{
    return this->GetCode();
}

//------------------------------------------------------------------------------
/**
*/
Parameter* 
Function::GetParameter( unsigned index )
{
    return &this->parameters[index];
}

//------------------------------------------------------------------------------
/**
*/
const Parameter* 
Function::GetParameter( unsigned index ) const
{
    return &this->parameters[index];
}

} // namespace AnyFX

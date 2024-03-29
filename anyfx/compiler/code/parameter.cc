//------------------------------------------------------------------------------
//  parameter.cc
//  (C) 2013 gscept
//------------------------------------------------------------------------------
#include "parameter.h"
#include "typechecker.h"
#include "programrow.h"
#include "datatype.h"
#include "shader.h"
#include "structure.h"
#include "util.h"
namespace AnyFX
{


//------------------------------------------------------------------------------
/**
*/
Parameter::Parameter() :
	ioMode(NoIO),
	interpolation(Smooth),
	attribute(NoAttribute),
	feedbackBufferExpression(nullptr),
	feedbackOffsetExpression(nullptr),
	feedbackBuffer(-1),
	feedbackOffset(0),
    slotExpression(nullptr),
    index(-1),
    explicitSlot(false),
	patchParam(false),
	isConst(false),
	sizeExpression(nullptr),
	isArray(false),
	arraySize(1),
	parentShader(nullptr),
    userType(nullptr),
	padding(0),
	alignedOffset(0)
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
Parameter::~Parameter()
{
	// empty
}


//------------------------------------------------------------------------------
/**
*/
unsigned 
Parameter::GetRenderTargetIndex() const
{
	assert(this->attribute >= Parameter::Color0 && this->attribute <= Parameter::Color7);
	return this->attribute - Parameter::Color0;
}

//------------------------------------------------------------------------------
/**
*/
std::string
Parameter::Format(const Header& header, unsigned& input, unsigned& output) const
{
	unsigned shaderType = -1;
	if (this->parentShader) 
        shaderType = this->parentShader->GetType();

	std::string formattedCode;
	
	if (header.GetType() == Header::GLSL || header.GetType() == Header::SPIRV)
	{
        std::string layoutFormat = "";
        std::string interpolationFormat = "";
        std::string qualifierFormat = "";
        std::string ioFormat = "";

		// resolve the layout type, for ordinary variables, this is using location, with transform buffer stuff, this is using xfb_buffer and xfb_offset
		if (this->IsTransformFeedback())
		{
			if (shaderType != ProgramRow::PixelShader)
			{
                layoutFormat = AnyFX::Format("xfb_buffer = %d, xfb_offset = %d ", this->feedbackBuffer, this->feedbackOffset);
			}			
			else
			{
				// type checker should throw an error before we get here...
			}
		}
		else
		{
            // For some reason in GLSL, rayPayload and callableData isn't using in/out qualifiers
            if (this->GetIO() == Parameter::Input || this->GetIO() == Parameter::NoIO)
            {
                ioFormat = "in";
                layoutFormat += AnyFX::Format("location = %d ", this->index);
            }
            else if (this->GetIO() == Parameter::Output)
            {
                ioFormat = "out";
                layoutFormat += AnyFX::Format("location = %d ", output++);
            }
		}

		// first handle qualifiers		
		if (shaderType == ProgramRow::PixelShader)
		{
			if (this->GetIO() == Parameter::Input || this->GetIO() == Parameter::NoIO)
			{
				if (this->interpolation == Flat)					interpolationFormat += "flat ";
				else if (this->interpolation == NoPerspective)		interpolationFormat += "noperspective ";
			}
		}
		else if (shaderType == ProgramRow::VertexShader)
		{
			if (this->GetIO() == Parameter::Output || this->GetIO() == Parameter::NoIO)
			{
                if (this->interpolation == Flat)					interpolationFormat += "flat ";
                else if (this->interpolation == NoPerspective)		interpolationFormat += "noperspective ";
			}
		}
		else if (shaderType == ProgramRow::GeometryShader)
		{
			if (this->GetIO() == Parameter::Input || this->GetIO() == Parameter::NoIO)
			{
                if (this->interpolation == Flat)					interpolationFormat += "flat ";
			}
		}
		else if (shaderType == ProgramRow::HullShader)
		{
            if (this->interpolation == Flat)					interpolationFormat += "flat ";
			if (this->GetIO() == Parameter::Output)
			{
				if (this->GetPatchParam())
				{
                    qualifierFormat += "patch ";
				}
			}
		}
		else if (shaderType == ProgramRow::DomainShader)
		{
            if (this->interpolation == Flat)					interpolationFormat += "flat ";
			if (this->GetIO() == Parameter::Input || this->GetIO() == Parameter::NoIO)
			{
				if (this->GetPatchParam())
				{
                    qualifierFormat += "patch ";
				}
			}
		}
        else if (
            shaderType == ProgramRow::RayGenerationShader 
            || shaderType == ProgramRow::RayAnyHitShader 
            || shaderType == ProgramRow::RayClosestHitShader 
            || shaderType == ProgramRow::RayMissShader 
            || shaderType == ProgramRow::RayIntersectionShader
            )
        {
            if (this->attribute == Parameter::RayPayload)
            {
                // For some reason, GLSL doesn't use the in/out qualifiers for raytracing...
                ioFormat = "";
                if (this->GetIO() == Parameter::Input)
                {
                    qualifierFormat += "rayPayloadInEXT ";
                }
                else
                {
                    qualifierFormat += "rayPayloadEXT ";
                }
            }
            else if (this->attribute == Parameter::CallResult)
            {
                ioFormat = "";
                if (this->GetIO() == Parameter::Input)
                {
                    qualifierFormat += "callableDataInEXT ";
                }
                else
                {
                    qualifierFormat += "callableDataEXT ";
                }
            }
            else if (this->attribute == Parameter::HitAttribute)
            {
                layoutFormat = "";
                ioFormat = "";
                qualifierFormat += "hitAttributeEXT ";
            }
        }

        std::string decoration = "";
        std::string layout = "";
        if (!layoutFormat.empty())
            layout = AnyFX::Format("layout(%s)", layoutFormat.c_str());
        if (shaderType != -1)
            decoration = AnyFX::Format("%s %s %s%s ", interpolationFormat.c_str(), layout.c_str(), qualifierFormat.c_str(), ioFormat.c_str());

		formattedCode.append("\t");
		formattedCode.append(decoration);
        formattedCode.append(DataType::ToProfileType(this->GetDataType(), header.GetType()));
		formattedCode.append(" ");
		formattedCode.append(this->GetName());

		if (this->isArray)
		{
			if (this->arraySize > 1)
			{
				std::string number = AnyFX::Format("%d", this->arraySize);
				formattedCode.append("[");
				formattedCode.append(number);
				formattedCode.append("]");
			}
			else
			{
				// add array size of undetermined size
				formattedCode.append("[]");
			}
		}		
		formattedCode.append(";\n");
	}
	else if (header.GetType() == Header::C)
	{
		DataType::Dimensions dims = DataType::ToDimensions(this->GetDataType());
        if (this->userType != nullptr && this->userType->GetType() == StructureType)
        {
            Structure* struc = (Structure*)this->userType;
            if (struc->isPointer)
                formattedCode.append("buffer_ptr");
            else
                formattedCode.append(DataType::ToProfileType(this->GetDataType(), header.GetType()));
        }
        else
        {
            formattedCode.append(DataType::ToProfileType(this->GetDataType(), header.GetType()));
        }
		formattedCode.append(" ");
		formattedCode.append(this->GetName());

		if (this->isArray)
		{
			if (this->arraySize > 1)
			{
				std::string number = AnyFX::Format("%d", this->arraySize);
				formattedCode.append("[");
				formattedCode.append(number);
				formattedCode.append("]");
			}
		}

		if (dims.x > 1 || dims.y > 1)
		{
			// change the signature if we have a Nx3 column major matrix, since vectors in this format should always be vec4
			if (dims.x == 3 && dims.y > 1)
				formattedCode.append(AnyFX::Format("[%d][%d]", dims.y, 4));
			else
				formattedCode.append(AnyFX::Format("[%d]", dims.x * dims.y));
		}

		formattedCode.append(";\n");
	}
	
	return formattedCode;
}


//------------------------------------------------------------------------------
/**
*/
void
Parameter::TypeCheck(TypeChecker& typechecker)
{
	// check that type is defined
	if (this->type.GetType() == DataType::Undefined)
	{
		std::string message = AnyFX::Format("Type of parameter '%s' is undefined, %s\n", this->name.c_str(), this->ErrorSuffix().c_str());
		typechecker.Error(message, this->GetFile(), this->GetLine());
	}

    if (this->GetDataType() == DataType::UserType)
        this->userType = typechecker.GetSymbol(this->GetDataType().GetName());

	unsigned i;
	for (i = 0; i < this->qualifiers.size(); i++)
	{
		const std::string& qualifier = this->qualifiers[i];

		if (qualifier == "const")					this->isConst = true;
		else if (qualifier == "patch")				this->patchParam = true;
		else if (qualifier == "in")					this->ioMode = Input;
		else if (qualifier == "out")				this->ioMode = Output;
		else if (qualifier == "inout")				this->ioMode = InputOutput;
		else if (qualifier == "flat")				this->interpolation = Flat;
		else if (qualifier == "noperspective")		this->interpolation = NoPerspective;
		else
		{
			std::string message = AnyFX::Format("Unknown qualifier '%s', %s\n", qualifier.c_str(), this->ErrorSuffix().c_str());
			typechecker.Error(message, this->GetFile(), this->GetLine());
		}
	}

	// check attribute string
	if (!this->attributeString.empty())
	{
		if (this->attributeString == "drawinstanceID" ||
            this->attributeString == "draw-instance_id") 					
                                                                            { this->attribute = Parameter::DrawInstance; }
		else if (this->attributeString == "vertexID" || 
                 this->attributeString == "vertex_id")
                                                                            { this->attribute = Parameter::Vertex; }
		else if (this->attributeString == "primitiveID" || 
                 this->attributeString == "primitive_id") 
                                                                            { this->attribute = Parameter::Primitive; }
		else if (this->attributeString == "invocationID" || 
                 this->attributeString == "invocationID")
                                                                            { this->attribute = Parameter::Invocation; }
		else if (this->attributeString == "viewportID" || 
                 this->attributeString == "viewport_id") 
                                                                            { this->attribute = Parameter::Viewport; }
		else if (this->attributeString == "rendertargetID" ||
                 this->attributeString == "rendertarget_id")
                                                                            { this->attribute = Parameter::Rendertarget; }
		else if (this->attributeString == "innertessellation" ||
                 this->attributeString == "inner_tessellation")
                                                                            { this->attribute = Parameter::InnerTessellation; }
		else if (this->attributeString == "outertessellation" ||
                 this->attributeString == "outer_tessellation")
                                                                            { this->attribute = Parameter::OuterTessellation; }
		else if (this->attributeString == "position") 						{ this->attribute = Parameter::Position; }
		else if (this->attributeString == "pointsize" ||
                 this->attributeString == "point_size")
                                                                            { this->attribute = Parameter::PointSize; }
		else if (this->attributeString == "clipdistance" ||
                 this->attributeString == "clip_distance")
                                                                            { this->attribute = Parameter::ClipDistance; }
		else if (this->attributeString == "frontface" || 
                 this->attributeString == "front_face")
                                                                            { this->attribute = Parameter::FrontFace; }
		else if (this->attributeString == "coordinate") 					{ this->attribute = Parameter::Coordinate; }
		else if (this->attributeString == "depth")							{ this->attribute = Parameter::Depth; }
		else if (this->attributeString == "color0") 						{ this->attribute = Parameter::Color0; }
		else if (this->attributeString == "color1") 						{ this->attribute = Parameter::Color1; }
		else if (this->attributeString == "color2") 						{ this->attribute = Parameter::Color2; }
		else if (this->attributeString == "color3") 						{ this->attribute = Parameter::Color3; }
		else if (this->attributeString == "color4") 						{ this->attribute = Parameter::Color4; }
		else if (this->attributeString == "color5") 						{ this->attribute = Parameter::Color5; }
		else if (this->attributeString == "color6") 						{ this->attribute = Parameter::Color6; }
		else if (this->attributeString == "color7") 						{ this->attribute = Parameter::Color7; }
		else if (this->attributeString == "workgroupID" || 
                 this->attributeString == "workgroup_id")					
                                                                            { this->attribute = Parameter::WorkGroup; }
		else if (this->attributeString == "numgroups" ||
                 this->attributeString == "num_groups")						
                                                                            { this->attribute = Parameter::NumGroups; }
		else if (this->attributeString == "localID" || 
                 this->attributeString == "local_id") 						
                                                                            { this->attribute = Parameter::LocalID; }
		else if (this->attributeString == "localindex" 
                 || this->attributeString == "local_index") 				
                                                                            { this->attribute = Parameter::LocalIndex; }
		else if (this->attributeString == "globalID") 						{ this->attribute = Parameter::GlobalID; }
        else if (this->attributeString == "ray_payload")                    { this->attribute = Parameter::RayPayload; }
        else if (this->attributeString == "call_result")                    { this->attribute = Parameter::CallResult; }
        else if (this->attributeString == "hit_attribute")                  { this->attribute = Parameter::HitAttribute; }
		else 																{ this->attribute = Parameter::InvalidAttribute; }
	}

	if (this->sizeExpression)
	{
		this->arraySize = this->sizeExpression->EvalInt(typechecker);
		this->sizeExpression;
	}

	Header::Type type = typechecker.GetHeader().GetType();
	if (NULL != this->parentShader)
	{
		if (this->isConst)
		{
			std::string message = AnyFX::Format("Qualifier 'const' is not allowed on shader parameter, %s\n", this->ErrorSuffix().c_str());
			typechecker.Error(message, this->GetFile(), this->GetLine());
		}

		unsigned shaderType = this->parentShader->GetType();
        if (this->slotExpression)
        {
            if (shaderType != ProgramRow::VertexShader)
            {
                std::string message = AnyFX::Format("Slot qualifier is not valid unless parameter is to a vertex shader, %s\n", this->ErrorSuffix().c_str());
                typechecker.Warning(message, this->GetFile(), this->GetLine());
            }
            else
            {
                this->index = this->slotExpression->EvalUInt(typechecker);
            }            
			this->slotExpression;
        }
		else if (type == Header::SPIRV && shaderType == ProgramRow::VertexShader && (this->GetIO() == Parameter::Input || this->GetIO() == Parameter::InputOutput))
		{
			std::string message = AnyFX::Format("SPIR-V requires specific slot to be assigned explicitly in input to vertex shader, for vertex attributes to be consistently mapped on the API side, shader '%s', parameter '%s', %s\n", this->parentShader->GetName().c_str(), this->GetName().c_str(), this->ErrorSuffix().c_str());
			typechecker.Error(message, this->GetFile(), this->GetLine());
		}

		if (shaderType == ProgramRow::VertexShader)
		{
			if (this->GetPatchParam())
			{
				std::string message = AnyFX::Format("Pixel/Fragment shader inputs/outputs does not support the 'patch' qualifier. Ignoring qualifier, %s\n", this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
			if (this->attribute != Parameter::NoAttribute && (type == Header::GLSL || type == Header::SPIRV))
			{
				std::string attributeString = this->AttributeToString(this->attribute);
				std::string message = AnyFX::Format("Qualifier '%s' serves no purpose in GLSL. Ignoring qualifier, %s\n", attributeString.c_str(), this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
		}
		else if (shaderType == ProgramRow::PixelShader)
		{
			if (this->GetPatchParam())
			{
				std::string message = AnyFX::Format("Pixel/Fragment shader inputs/outputs does not support the 'patch' qualifier. Ignoring qualifier, %s\n", this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
			if (this->feedbackBufferExpression || this->feedbackOffsetExpression)
			{
				std::string message = AnyFX::Format("Pixel/Fragment shader has no concept of transform feedbacks, %s\n", this->ErrorSuffix().c_str());
				typechecker.Error(message, this->GetFile(), this->GetLine());
			}
			if (this->GetIO() == Parameter::Output)
			{
				if (!(this->attribute >= Color0 && this->attribute <= Color7))
				{
					std::string message = AnyFX::Format("Pixel/Fragment color output must be declared explicitly, resolve by giving output a qualifier in the range: [color0] - [color7], %s\n", this->ErrorSuffix().c_str());
					typechecker.Error(message, this->GetFile(), this->GetLine());
				}
			}
			if (this->GetIO() == Parameter::InputOutput)
			{
				// should throw an error if this happens
				std::string message = AnyFX::Format("Pixel/Fragment shader doesn't support parameters with the 'inout' qualifier, since outputs has to use the [colorX] qualifier, %s\n", this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
		}
		else if (shaderType == ProgramRow::GeometryShader)
		{
			if (this->GetPatchParam())
			{
				std::string message = AnyFX::Format("Pixel/Fragment shader inputs/outputs does not support the 'patch' qualifier. Ignoring qualifier, %s\n", this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
			if (this->GetIO() == Parameter::Input)
			{
				if (!this->isArray)
				{
					std::string message = AnyFX::Format("Input to Geometry shader must be of array type, %s\n", this->ErrorSuffix().c_str());
					typechecker.Error(message, this->GetFile(), this->GetLine());
				}
			}	
			if (this->attribute != Parameter::NoAttribute && (type == Header::GLSL || type == Header::SPIRV))
			{
				std::string attributeString = this->AttributeToString(this->attribute);
				std::string message = AnyFX::Format("Qualifier '%s' serves no purpose in GLSL. Ignoring qualifier, %s\n", attributeString.c_str(), this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
		}
		else if (shaderType == ProgramRow::HullShader)
		{
			if (this->GetIO() == Parameter::Input)
			{
				if (!this->isArray)
				{
					std::string message = AnyFX::Format("Input to Hull/Control shader '%s' must be of array type, %s\n", parentShader->GetName().c_str(), this->ErrorSuffix().c_str());
					typechecker.Error(message, this->GetFile(), this->GetLine());
				}
			}
			else if (this->GetIO() == Parameter::Output)
			{
			if (!this->isArray)
				{
					std::string message = AnyFX::Format("Output from Hull/Control shader '%s' must be of array type, %s\n", parentShader->GetName().c_str(), this->ErrorSuffix().c_str());
					typechecker.Error(message, this->GetFile(), this->GetLine());
				}
			}
			else if (this->GetIO() == Parameter::InputOutput)
			{
				std::string message = AnyFX::Format("Hull/Control shaders does not support the 'inout' since input and output size may be of different size, %s\n", this->ErrorSuffix().c_str());
				typechecker.Error(message, this->GetFile(), this->GetLine());
			}
			if (this->attribute != Parameter::NoAttribute && (type == Header::GLSL || type == Header::SPIRV))
			{
				std::string attributeString = this->AttributeToString(this->attribute);
				std::string message = AnyFX::Format("Qualifier '%s' serves no purpose in GLSL. Ignoring qualifier, %s\n", attributeString.c_str(), this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
		}
		else if (shaderType == ProgramRow::DomainShader)
		{
			if (this->GetIO() == Parameter::Input)
			{
				if (!this->isArray)
				{
					std::string message = AnyFX::Format("Input to Domain/Evaluation shader '%s' must be of array type, %s\n", parentShader->GetName().c_str(), this->ErrorSuffix().c_str());
					typechecker.Error(message, this->GetFile(), this->GetLine());
				}
			}
			if (this->attribute != Parameter::NoAttribute && (type == Header::GLSL || type == Header::SPIRV))
			{
				std::string attributeString = this->AttributeToString(this->attribute);
				std::string message = AnyFX::Format("Qualifier '%s' serves no purpose in GLSL. Ignoring qualifier, %s\n", attributeString.c_str(), this->ErrorSuffix().c_str());
				typechecker.Warning(message, this->GetFile(), this->GetLine());
			}
		}

		// solve transform feedback stuff
		if (this->feedbackBufferExpression)
		{
			if (this->GetIO() != Parameter::Output)
			{
				std::string message = AnyFX::Format("Qualifier 'feedback' has no function unless the parameter is an output parameter, %s\n", this->ErrorSuffix().c_str());
				typechecker.Error(message, this->GetFile(), this->GetLine());
			}
			this->feedbackBuffer = this->feedbackBufferExpression->EvalInt(typechecker);
			this->feedbackOffset = this->feedbackOffsetExpression->EvalUInt(typechecker);
			this->feedbackOffsetExpression;
			this->feedbackBufferExpression;

			// make sure the offset is valid
			if (this->feedbackOffset % DataType::ToByteSize(DataType::ToPrimitiveType(this->type)) != 0)
			{
				std::string message = AnyFX::Format("Feedback buffer parameter offset must be a multiple of the parameter type, %s\n", this->ErrorSuffix().c_str());
				typechecker.Error(message, this->GetFile(), this->GetLine());
			}
		}
	}	

	switch (typechecker.GetHeader().GetType())
	{
	case Header::SPIRV:
	case Header::GLSL:
		{
			switch (this->attribute)
			{
			case DrawInstance:
			case Vertex:
			case Primitive:
			case Invocation:
			case Viewport:
			case Rendertarget:
			case InnerTessellation:
			case OuterTessellation:
			case Position:
			case PointSize:
			case ClipDistance:
			case FrontFace:
			case Coordinate:
			case Depth:
			case WorkGroup:
			case NumGroups:
			case LocalID:
			case LocalIndex:
			case GlobalID:
			case Color0:
			case Color1:
			case Color2:
			case Color3:
			case Color4:
			case Color5:
			case Color6:
			case Color7:
            case RayPayload:
            case CallResult:
            case HitAttribute:
			case NoAttribute:
				break; // accept attribute
			default:
				{
					std::string attrString = AttributeToString(this->attribute);
					std::string message = AnyFX::Format("Parameter attribute type '%s' is not valid for GLSL4, %s\n", attrString.c_str(), this->ErrorSuffix().c_str());
					typechecker.Error(message, this->GetFile(), this->GetLine());
                    break;
				}	
			}
            break;
		}
	case Header::HLSL:
		{
			switch (this->attribute)
			{
			case DrawInstance:
			case Vertex:
			case Primitive:
			case Invocation:
			case Viewport:
			case Rendertarget:
			case InnerTessellation:
			case OuterTessellation:
			case Position:
			case ClipDistance:
			case FrontFace:
			case Depth:
			case WorkGroup:
			case LocalID:
			case LocalIndex:
			case GlobalID:
			case Color0:
			case Color1:
			case Color2:
			case Color3:
			case Color4:
			case Color5:
			case Color6:
			case Color7:
            case RayPayload:
            case CallResult:
            case HitAttribute:
			case NoAttribute:
				break;	// accept attribute
			case PointSize:
				{
					std::string message = AnyFX::Format("HLSL targets doesn't support [pointsize] as parameter qualifier, ignoring qualifier, %s\n", this->ErrorSuffix().c_str());
					typechecker.Warning(message, this->GetFile(), this->GetLine());
					break;
				}				
			case NumGroups:
				{
					std::string message = AnyFX::Format("HLSL targets doesn't support [numgroups] as parameter qualifier, ignoring qualifier, %s\n", this->ErrorSuffix().c_str());
					typechecker.Warning(message, this->GetFile(), this->GetLine());
					break;
				}
			case Coordinate:
				{
					std::string message = AnyFX::Format("HLSL targets doesn't support [coordinate] as parameter qualifier, ignoring qualifier, %s\n", this->ErrorSuffix().c_str());
					typechecker.Warning(message, this->GetFile(), this->GetLine());
					break;
				}
			default:
				{
					std::string attrString = AttributeToString(this->attribute);
					std::string message = AnyFX::Format("Parameter qualifier type '%s' is not valid for HLSL, %s\n", attrString.c_str(), this->ErrorSuffix().c_str());
					typechecker.Error(message, this->GetFile(), this->GetLine());
                    break;
				}		
			}
            break;
		}
	}
}

//------------------------------------------------------------------------------
/**
*/
std::string
Parameter::FormatAttribute(const Header::Type& type)
{
	switch (type)
	{
		case Header::SPIRV:
		case Header::GLSL:
		{
			switch (this->attribute)
			{
			case DrawInstance:
				return "gl_InstanceID";
			case Vertex:
				return "gl_VertexID";
			case Primitive:
				return "gl_PrimitiveID";
			case Invocation:
				return "gl_InvocationID";
			case Viewport:
				return "gl_ViewportIndex";
			case Rendertarget:
				return "gl_Layer";
			case InnerTessellation:
				return "gl_TessLevelInner";
			case OuterTessellation:
				return "gl_TessLevelOuter";
			case Position:
				return "gl_Position";
			case PointSize:
				return "gl_PointSize";
			case ClipDistance:
				return "gl_ClipDistance[]";
			case FrontFace:
				return "gl_FrontFacing";
			case Coordinate:
				return "gl_FragCoord";
			case Depth:
				return "gl_Depth";
			case WorkGroup:
				return "gl_WorkGroupID";
			case NumGroups:
				return "gl_NumWorkGroups";
			case LocalID:
				return "gl_LocalInvocationID";
			case LocalIndex:
				return "gl_LocalInvocationIndex";
			case GlobalID:
				return "gl_GlobalInvocationID";
			case Color0:
				return "/* Render target 0 */";
			case Color1:
				return "/* Render target 1 */";
			case Color2:
				return "/* Render target 2 */";
			case Color3:
				return "/* Render target 3 */";
			case Color4:
				return "/* Render target 4 */";
			case Color5:
				return "/* Render target 5 */";
			case Color6:
				return "/* Render target 6 */";
			case Color7:
				return "/* Render target 7 */";
            case RayPayload:
                return "rayPayloadExt";
            case CallResult:
                return "callbackResultEXT";
            case HitAttribute:
                return "hitAttributeEXT";
			default:
				return "undefined";
			}
		}
		case Header::HLSL:
		{
			switch (this->attribute)
			{
			case DrawInstance:
				return "SV_InstanceID";
			case Vertex:
				return "SV_VertexID";
			case Primitive:
				return "SV_PrimitiveID";
			case Invocation:
				return "SV_GSInstanceID";
			case Viewport:
				return "SV_ViewportArrayIndex";
			case Rendertarget:
				return "SV_RenderTargetArrayIndex";
			case InnerTessellation:
				return "SV_InsideTessFactor";
			case OuterTessellation:
				return "SV_TessFactor";
			case Position:
				return "SV_Position";
			case ClipDistance:
				return "SV_ClipDistance";
			case FrontFace:
				return "SV_IsFrontFace";
			case Depth:
				return "SV_Depth";
			case WorkGroup:
				return "SV_GroupID";
			case LocalID:
				return "SV_GroupID";
			case LocalIndex:
				return "SV_GroupIndex";
			case GlobalID:
				return "SV_DispatchThreadID";
			case Color0:
				return "SV_TARGET0";
			case Color1:
				return "SV_TARGET1";
			case Color2:
				return "SV_TARGET2";
			case Color3:
				return "SV_TARGET3";
			case Color4:
				return "SV_TARGET4";
			case Color5:
				return "SV_TARGET5";
			case Color6:
				return "SV_TARGET6";
			case Color7:
				return "SV_TARGET7";
			case PointSize:
			case NumGroups:
			case Coordinate:
			default:
				return "undefined";
			}
		}
	}

	// fallthrough
	return "";
}

//------------------------------------------------------------------------------
/**
*/
void
Parameter::Compile(BinWriter& writer)
{
	writer.WriteInt('PARA');

	writer.WriteInt(this->ioMode);
	writer.WriteInt(this->attribute);
	writer.WriteInt(this->type.GetType());
	writer.WriteString(this->name);
}

//------------------------------------------------------------------------------
/**
*/
bool
Parameter::Compatible(Parameter* other)
{
	if (this->type == DataType::Float4)
	{
		if (other->type == DataType::Float4) return true;
	}
	else if (this->type == DataType::Float3)
	{
		if (other->type == DataType::Float4) return true;
		else if (other->type == DataType::Float3) return true;
	}
	else if (this->type == DataType::Float2)
	{
		if (other->type == DataType::Float4) return true;
		else if (other->type == DataType::Float3) return true;
		else if (other->type == DataType::Float2) return true;
	}
	else if (this->type == DataType::Float)
	{
		if (other->type == DataType::Float4) return true;
		else if (other->type == DataType::Float3) return true;
		else if (other->type == DataType::Float2) return true;
		else if (other->type == DataType::Float) return true; 
	}
	else if (this->type == DataType::Integer4)
	{
		if (other->type == DataType::Integer4) return true;
	}
	else if (this->type == DataType::Integer3)
	{
		if (other->type == DataType::Integer4) return true;
		else if (other->type == DataType::Integer3) return true;
	}
	else if (this->type == DataType::Integer2)
	{
		if (other->type == DataType::Integer4) return true;
		else if (other->type == DataType::Integer3) return true;
		else if (other->type == DataType::Integer2) return true;
	}
	else if (this->type == DataType::Integer)
	{
		if (other->type == DataType::Integer4) return true;
		else if (other->type == DataType::Integer3) return true;
		else if (other->type == DataType::Integer2) return true;
		else if (other->type == DataType::Integer) return true; 
	}
	else if (this->type == DataType::UInteger4)
	{
		if (other->type == DataType::UInteger4) return true;
	}
	else if (this->type == DataType::UInteger3)
	{
		if (other->type == DataType::UInteger4) return true;
		else if (other->type == DataType::UInteger3) return true;
	}
	else if (this->type == DataType::UInteger2)
	{
		if (other->type == DataType::UInteger4) return true;
		else if (other->type == DataType::UInteger3) return true;
		else if (other->type == DataType::UInteger2) return true;
	}
	else if (this->type == DataType::UInteger)
	{
		if (other->type == DataType::UInteger4) return true;
		else if (other->type == DataType::UInteger3) return true;
		else if (other->type == DataType::UInteger2) return true;
		else if (other->type == DataType::UInteger) return true; 
	}
	else if (this->type == DataType::Short4)
	{
		if (other->type == DataType::Short4) return true;
	}
	else if (this->type == DataType::Short3)
	{
		if (other->type == DataType::Short4) return true;
		else if (other->type == DataType::Short3) return true;
	}
	else if (this->type == DataType::Short2)
	{
		if (other->type == DataType::Short4) return true;
		else if (other->type == DataType::Short3) return true;
		else if (other->type == DataType::Short2) return true;
	}
	else if (this->type == DataType::Short)
	{
		if (other->type == DataType::Short4) return true;
		else if (other->type == DataType::Short3) return true;
		else if (other->type == DataType::Short2) return true;
		else if (other->type == DataType::Short) return true; 
	}
	else if (this->type == DataType::Bool4)
	{
		if (other->type == DataType::Bool4) return true;
	}
	else if (this->type == DataType::Bool3)
	{
		if (other->type == DataType::Bool4) return true;
		else if (other->type == DataType::Bool3) return true;
	}
	else if (this->type == DataType::Bool2)
	{
		if (other->type == DataType::Bool4) return true;
		else if (other->type == DataType::Bool3) return true;
		else if (other->type == DataType::Bool2) return true;
	}
	else if (this->type == DataType::Bool)
	{
		if (other->type == DataType::Bool4) return true;
		else if (other->type == DataType::Bool3) return true;
		else if (other->type == DataType::Bool2) return true;
		else if (other->type == DataType::Bool) return true; 
	}
	else
	{
		// if we cannot perform any implicit conversions, then the rule is that the inputs and outputs are identical
		return this->type == other->type;
	}

	// fallthrough
	return false;
}

//------------------------------------------------------------------------------
/**
*/
std::string
Parameter::AttributeToString(const Attribute& attr)
{
	switch (attr)
	{
	case DrawInstance:
		return "drawinstance";
	case Vertex:
		return "vertex";
	case Primitive:
		return "primitive";
	case Invocation:
		return "invocation";
	case Viewport:
		return "viewport";
	case Rendertarget:
		return "rendertarget";
	case InnerTessellation:
		return "innertessellation";
	case OuterTessellation:
		return "outertessellation";
	case Position:
		return "position";
	case PointSize:
		return "pointsize";
	case ClipDistance:
		return "clipdistance";
	case FrontFace:
		return "frontface";
	case Coordinate:
		return "coordinate";
	case Depth:
		return "depth";
	case WorkGroup:
		return "workgroup";
	case NumGroups:
		return "numgroups";
	case LocalID:
		return "localID";
	case LocalIndex:
		return "localindex";
	case GlobalID:
		return "globalID";
	case Color0:
		return "color0";
	case Color1:
		return "color1";
	case Color2:
		return "color2";
	case Color3:
		return "color3";
	case Color4:
		return "color4";
	case Color5:
		return "color5";
	case Color6:
		return "color6";
	case Color7:
		return "color7";
    case RayPayload:
        return "ray_payload";
    case CallResult:
        return "ray_result";
    case HitAttribute:
        return "hit_attribute";
	default:
		return "undefined attribute";
	}
}

} // namespace AnyFX

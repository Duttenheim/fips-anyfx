#pragma once
//------------------------------------------------------------------------------
/**
	Lists enums used by the compiler do describe flags
	
	(C) 2016 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------

namespace AnyFX
{

enum Implementation
{
	HLSL,
	GLSL,
	SPIRV,
	Metal,
	PS,
	Wii,
	C,

	InvalidType,

	NumImplementations
};

enum AddressMode
{
	Wrap = 0,
	Mirror,
	Clamp,
	Border,
	MirrorOnce,

	NumAddressModes
};

enum FilterMode
{
	MinMagMipPoint = 0,
	MinMagMipLinear,
	MinMagPointMipLinear,
	MinMipPointMagLinear,
	MinPointMipMagLinear,
	MinLinearMipMagPoint,
	MinMipLinearMagPoint,
	MinMagLinearMipPoint,
	Anisotropic,
	PointAll,
	LinearAll,

	NumFilterModes
};

enum ComparisonFunc
{
	Never = 0,
	Less,
	LessEqual,
	Greater,
	GreaterEqual,
	Equal,
	NotEqual,
	Always,

	NumDrawDepthFuncs
};

enum BorderColorMode
{
	Transparent,
	Black,
	White
};

enum BlendMode
{
	ZeroBlend,
	OneBlend,
	SourceColor,
	OneMinusSourceColor,
	DestinationColor,
	OneMinusDestinationColor,
	SourceAlpha,
	OneMinusSourceAlpha,
	DestinationAlpha,
	OneMinusDestinationAlpha,
	SourceAlphaSaturate,
	ConstantColor,
	OneMinusConstantColor,
	ConstantAlpha,
	OneMinusConstantAlpha,

	NumBlendModes
};

enum BlendOperation
{
	Add,
	Sub,
	InvSub,
	Min,
	Max,

	NumBlendOperations
};

enum BlendBoolFlag
{
	BlendEnabled,

	NumBlendBoolFlags
};

enum BlendModeFlag
{
	SrcBlend,
	DstBlend,
	SrcBlendAlpha,
	DstBlendAlpha,

	NumBlendModeFlags
};

enum BlendFuncFlag
{
	BlendOp,
	BlendOpAlpha,

	NumBlendFlags
};

enum StencilOperation
{
	Keep,
	Zero,
	Replace,
	Increase,
	IncreaseWrap,
	Decrease,
	DecreaseWrap,
	Invert,

	NumStencilOperations
};

enum StencilOpFlag
{
	StencilFrontFailOp,
	StencilBackFailOp,
	StencilFrontPassOp,
	StencilBackPassOp,
	StencilFrontDepthFailOp,
	StencilBackDepthFailOp,

	NumStencilOpFlags
};

enum StencilFuncFlag
{
	StencilFrontFunc,
	StencilBackFunc,

	NumStencilFuncFlags
};

enum DrawBoolFlag
{
	DepthEnabled,
	DepthWrite,
	DepthAttachmentRead,
	SeparateBlend,
	StencilEnabled,
	AlphaToCoverageEnabled,
	MultisampleEnabled,
	RasterizerDiscardEnabled,
	LogicOpEnabled,
	PolygonOffsetEnabled,

	NumDrawBoolFlags
};

enum DrawIntFlag
{
	StencilReadMask,
	StencilWriteMask,
	DepthFunc,
	CullMode,
	FillMode,

	NumDrawIntFlags
};

enum DrawCullMode
{
	Back,
	Front,
	None,

	NumDrawCullModes
};

enum DrawFillMode
{
	Solid,
	Line,
	Point,

	NumDrawFillModes
};

enum DrawWindingMode
{
	CW,
	CCW,

	NumWindingModes
};

enum DrawSampleCount
{
	Bits1,
	Bits2,
	Bits4,
	Bits8,
	Bits16,
	Bits32,
	Bits64,

	NumSampleCounts
};

enum DrawLogicalOperation
{
	Clear,
	And,
	AndReverse,
	Copy,
	AndInverted,
	NoOp,
	Xor,
	Or,
	Nor,
	Equivalent,
	Inverted,
	OrReverse,
	CopyInverted,
	OrInverted,
	Nand,
	Set
};

enum ShaderType
{
	VertexShader,
	PixelShader,
	GeometryShader,
	HullShader,
	DomainShader,
	ComputeShader,

	NumInternalShaderTypes
};

} // namespace AnyFX
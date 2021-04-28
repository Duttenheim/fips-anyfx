//------------------------------------------------------------------------------
//  @file completeshader.fx
//  @copyright (C) 2021 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------

read rgba32f image2D myReadImage;
write rgb10_a2 image2D myWriteImage;
binding(0) rg16f read_write image2D myReadWriteImage;
volatile r8u image2D myVolatileImage[5];
atomic r32i image2D myAtomicImage[];

alias textureHandle as int;

@Visibility("CS")
group(0) sampler MyDynamicSampler;

struct MyStruct
{
    int i;  
    textureHandle tex;
};

@Visibility("CS")
struct const MyConstantBuffer
{
    int NumWorkGroups;
    vec2 ElementPaddedArray[10];
};

struct mutable MyStorageBuffer
{
    int ProvokePadding;
    vec3 Output;  
};

const int NUM_FOO = 5;
const vec4 NUM_BLORF[2] = { vec4(1,1,1,1), vec4(2,2,2,2) };

// sampler_states gets converted to ordinary sampler objects, 
// but is supposed to be read on the receiving side
sampler_state MyImmutableSampler
{
    AddressU = Wrap;
    AddressV = Clamp;
    AddressW = Mirror;
    Filter = Linear;
    AnisotropicEnabled = true;
    MaxAnisotropy = 16;
};

render_state MyRenderState
{
    BlendEnabled[0] = true;
    DepthCompare = Greater;
    DepthWriteEnabled = false;
};

//------------------------------------------------------------------------------
/**
    Test statements
*/
int
MegaFunction()
{
    int foo = 5;
    {
        int foo = 5;
    }

    if (foo)
    {
        int bar = 5;
        if (foo)
            return bar;
        else
            return bar;
    }
    else
    {
        int bar = 5;
    }

    while (true)
    {
        if (foo == 0)
            break;
        foo--;
    }

    foo = 5;
    do 
    {
        foo--;
    } while (foo > 0);

    foo = 6;
    for (int i = 0; i < foo; i++)
    {
        if (i % 2)
            continue;
    }

    return foo == 6 ? 1 : 0;
}

//------------------------------------------------------------------------------
/**
*/
vec4 
Function(in float f)
{
    return vec4(f);
}

//------------------------------------------------------------------------------
/**
    Overload function
*/
vec4
Function(in int i)
{
    return vec4(i);
}

//------------------------------------------------------------------------------
/**
    Per-program bind function
*/
prototype vec4 DynamicFunction(in int i);

//------------------------------------------------------------------------------
/**
*/
void
ComputeShader()
{
    imageStore(myReadWriteImage, ivec2(0, 0), Function(NumWorkGroups));
}

//------------------------------------------------------------------------------
/**
*/
@Mask("MyProgram")
program MyProgram
{
    ComputeShader = ComputeShader;
};

//------------------------------------------------------------------------------
/**
*/
void
VertexShader(
    binding(0) in vec4 position
    , binding(0) out vec4 Position
)
{
    Position = position;
}

//------------------------------------------------------------------------------
/**
*/
void
PixelShader(
    binding(0) in vec4 position
    , binding(0) out vec4 Color
)
{
    Color = position;
}

//------------------------------------------------------------------------------
/**
*/
@Mask("MyGraphicsProgram")
program MyGraphicsProgram
{
    DynamicFunction = Function;
    VertexShader = VertexShader;
    PixelShader = PixelShader;
};

//------------------------------------------------------------------------------
//  test_shader.fx
//  (C) 2021 Gustav Sterbrant
//------------------------------------------------------------------------------

texture2D Fog;
texture2D Reflections;
texture2D AO;
readwrite rgba16f image2D Lighting;

group(BATCH_GROUP) constant CombineUniforms [ Visibility = "CS"; ]
{
    vec2 LowresResolution;
} myUniforms[5];

//------------------------------------------------------------------------------
/**
*/
local_size_x(64)
shader
void csCombine()
{
    vec2 coord = vec2(gl_GlobalInvocationID.xy) * LowresResolution;
    ivec2 fullscaleCoord = ivec2(gl_GlobalInvocationID.xy);
    vec4 fog = texture(sampler2D(Fog, PosteffectUpscaleSampler), coord);
    vec4 reflections = texture(sampler2D(Reflections, PosteffectUpscaleSampler), coord);
    float ao = texture(sampler2D(AO, PosteffectUpscaleSampler), coord).r;
    vec4 light = imageLoad(Lighting, fullscaleCoord);

    vec3 res = light.rgb * (1 - (ao)) * fog.a
        //+ reflections.rgb * fog.a 
        + fog.rgb;
    imageStore(Lighting, fullscaleCoord, vec4(res, 1));
}

//------------------------------------------------------------------------------
/**
*/
program Combine [ Mask = "Combine"; ]
{
    ComputeShader = csCombine();
};

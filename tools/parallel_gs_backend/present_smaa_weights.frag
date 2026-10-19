#version 450
#extension GL_GOOGLE_include_directive : require
layout(push_constant) uniform PresentSize { uvec2 source; uvec2 destination; uint flags; } extent;
#define SMAA_GLSL_4
#define SMAA_PRESET_HIGH
#define SMAA_RT_METRICS vec4(1.0 / vec2(extent.destination), vec2(extent.destination))
#include "smaa/upstream/SMAA.hlsl"
layout(set=0,binding=0) uniform sampler2D edgeTexture;
layout(set=0,binding=1) uniform sampler2D areaTexture;
layout(set=0,binding=2) uniform sampler2D searchTexture;
layout(location=0) out vec4 weights;
void main() {
    vec2 uv = gl_FragCoord.xy / vec2(extent.destination);
    vec2 pixel; vec4 offset[3]; SMAABlendingWeightCalculationVS(uv, pixel, offset);
    weights = SMAABlendingWeightCalculationPS(uv, pixel, offset, edgeTexture, areaTexture, searchTexture, vec4(0));
}

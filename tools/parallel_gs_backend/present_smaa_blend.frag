#version 450
#extension GL_GOOGLE_include_directive : require
layout(push_constant) uniform PresentSize { uvec2 source; uvec2 destination; uint flags; uint fps; uint frameMs; uint ups; } extent;
#define SMAA_GLSL_4
#define SMAA_PRESET_HIGH
#define SMAA_RT_METRICS vec4(1.0 / vec2(extent.destination), vec2(extent.destination))
#include "smaa/upstream/SMAA.hlsl"
#include "present_color.glsl"
#include "present_layout.glsl"
#include "present_performance.glsl"
layout(set=0,binding=0) uniform sampler2D colorTexture;
layout(set=0,binding=1) uniform sampler2D weightTexture;
layout(location=0) out vec4 hostColor;
void main() {
    vec2 outputSize = vec2(extent.destination);
    vec2 picture = pictureSize(extent.source, extent.destination, extent.flags);
    vec2 origin = (outputSize - picture) * 0.5;
    if (any(lessThan(gl_FragCoord.xy, origin)) || any(greaterThanEqual(gl_FragCoord.xy, origin + picture))) {
        hostColor = vec4(0,0,0,1);
    } else {
        vec2 uv = gl_FragCoord.xy / outputSize;
        vec4 offset; SMAANeighborhoodBlendingVS(uv, offset);
        hostColor = displayColor(SMAANeighborhoodBlendingPS(uv, offset, colorTexture, weightTexture).rgb, extent.flags);
    }
    hostColor = performanceOverlay(hostColor, extent.destination, extent.fps, extent.frameMs, extent.ups);
}

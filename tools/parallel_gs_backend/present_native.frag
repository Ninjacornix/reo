#version 450
#extension GL_GOOGLE_include_directive : require
#include "present_color.glsl"
#include "present_layout.glsl"
layout(set=0,binding=0) uniform sampler2D mergedScanout;
layout(location=0) out vec4 hostColor;
// Bits 0/1: scaling/FXAA; bytes 1/2: brightness/gamma percent (zero = neutral).
layout(push_constant) uniform PresentSize { uvec2 source; uvec2 destination; uint linear; } extent;

float luminance(vec3 color) { return dot(color, vec3(0.299, 0.587, 0.114)); }
vec3 readColor(vec2 uv) { return textureLod(mergedScanout, uv, 0).rgb; }
// Independent implementation of directional screen-space FXAA filtering.
vec3 antialias(vec2 uv, vec2 stepSize) {
    vec3 middle = readColor(uv);
    float center = luminance(middle);
    float nw = luminance(readColor(uv + vec2(-1,-1) * stepSize));
    float ne = luminance(readColor(uv + vec2( 1,-1) * stepSize));
    float sw = luminance(readColor(uv + vec2(-1, 1) * stepSize));
    float se = luminance(readColor(uv + vec2( 1, 1) * stepSize));
    float lowest = min(center, min(min(nw, ne), min(sw, se)));
    float highest = max(center, max(max(nw, ne), max(sw, se)));
    if (highest - lowest < max(0.03125, highest * 0.125)) return middle;
    vec2 direction = vec2(sw + se - nw - ne, nw + sw - ne - se);
    float reduction = max((nw + ne + sw + se) * 0.03125, 0.0078125);
    direction /= min(abs(direction.x), abs(direction.y)) + reduction;
    direction = clamp(direction, vec2(-8), vec2(8)) * stepSize;
    vec3 narrow = (readColor(uv - direction / 6.0) + readColor(uv + direction / 6.0)) * 0.5;
    vec3 wide = narrow * 0.5 + (readColor(uv - direction * 0.5) + readColor(uv + direction * 0.5)) * 0.25;
    float wideLuma = luminance(wide);
    return wideLuma < lowest || wideLuma > highest ? narrow : wide;
}
void main() {
    vec2 drawn = pictureSize(extent.source, extent.destination, extent.linear);
    vec2 origin = (vec2(extent.destination) - drawn) * 0.5;
    vec2 texel = (gl_FragCoord.xy - origin) * vec2(extent.source) / drawn;
    if (any(lessThan(texel, vec2(0))) || any(greaterThanEqual(texel, vec2(extent.source)))) {
        hostColor = vec4(0,0,0,1);
    } else if ((extent.linear & 2u) != 0u) {
        // This pass runs at output resolution. Source-texel offsets make the
        // directional filter span enlarged glyphs and produce stippled text.
        hostColor = displayColor(antialias(texel / vec2(extent.source), 1.0 / drawn), extent.linear);
    } else if ((extent.linear & 1u) != 0u) {
        hostColor = displayColor(readColor(texel / vec2(extent.source)), extent.linear);
    } else {
        hostColor = displayColor(texelFetch(mergedScanout, ivec2(texel), 0).rgb, extent.linear);
    }
}

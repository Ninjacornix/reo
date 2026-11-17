// Compact bitmap text in the final presentation pass. No extra render target,
// draw, font texture, readback or fullscreen processing pass.
const uint performanceFont[147] = uint[](
    14,17,19,21,25,17,14, 4,12,4,4,4,4,14,
    14,17,1,2,4,8,31, 30,1,1,14,1,1,30,
    2,6,10,18,31,2,2, 31,16,16,30,1,1,30,
    14,16,16,30,17,17,14, 31,1,2,4,8,8,8,
    14,17,17,14,17,17,14, 14,17,17,15,1,1,14,
    31,16,16,30,16,16,16, 30,17,17,30,16,16,16,
    15,16,16,14,1,1,30, 30,17,17,30,20,18,17,
    14,17,17,31,17,17,17, 17,27,21,21,17,17,17,
    31,16,16,30,16,16,31, 17,17,17,17,17,17,14,
    0,4,4,0,4,4,0, 0,0,0,0,0,12,12,
    0,0,0,0,0,0,0);
const uint performanceLabels[18] = uint[](
    10,11,12,20,20,18, 10,13,14,15,16,18, 17,11,12,20,20,18);

uint performanceCharacter(int row, int column, uint value) {
    if (column < 6) return performanceLabels[row * 6 + column];
    if (column == 7) return value >= 10000u ? (value / 10000u) % 10u : 20u;
    if (column == 8) return value >= 1000u ? (value / 1000u) % 10u : 20u;
    if (column == 9) return value >= 100u ? (value / 100u) % 10u : 20u;
    if (column == 10) return (value / 10u) % 10u;
    if (column == 11) return 19u;
    if (column == 12) return value % 10u;
    if (row == 1 && column == 14) return 15u;
    if (row == 1 && column == 15) return 12u;
    return 20u;
}
vec4 performanceOverlay(vec4 color, uvec2 destination, uint fps, uint frameMs, uint ups) {
    if ((fps & 0x80000000u) == 0u) return color;
    int scale = clamp(int(destination.y) / 480, 2, 4);
    ivec2 size = ivec2(104, 35) * scale;
    ivec2 origin = ivec2(int(destination.x) - size.x - 8 * scale, 8 * scale);
    ivec2 p = ivec2(gl_FragCoord.xy) - origin;
    if (any(lessThan(p, ivec2(0))) || any(greaterThanEqual(p, size))) return color;
    vec4 background = vec4(color.rgb * 0.22, 1);
    p = p / scale - 4;
    if (any(lessThan(p, ivec2(0))) || p.x >= 96 || p.y >= 27) return background;
    int row = p.y / 9;
    if (p.y % 9 >= 7 || p.x % 6 >= 5) return background;
    uint value = row == 0 ? fps & 0x1fffffffu : row == 1 ? frameMs : ups;
    uint glyph = performanceCharacter(row, p.x / 6, value);
    uint bits = performanceFont[glyph * 7u + uint(p.y % 9)];
    bool ink = ((bits >> uint(4 - p.x % 6)) & 1u) != 0u;
    return ink ? vec4(0.83, 1.0, 0.87, 1) : background;
}

// Black screen while the game connects (fps word bit 28; bits 16..23 animate):
// eight dots on a small ring in the middle of the screen, the brightest one moving round.
vec4 connectingSpinner(vec2 fragment, uvec2 destination, uint flags) {
    if ((flags & 0x10000000u) == 0u) return vec4(0, 0, 0, 1);
    float scale = max(1.0, float(destination.y) / 480.0);
    vec2 centre = vec2(destination) * 0.5;
    vec2 d = fragment - centre;
    float lead = float((flags >> 16u) & 7u);
    vec3 color = vec3(0.0);
    for (int i = 0; i < 8; ++i) {
        float a = 6.2831853 * float(i) / 8.0;
        vec2 dot_ = vec2(cos(a), sin(a)) * 14.0 * scale;
        float dist = length(d - dot_);
        float age = mod(lead - float(i) + 8.0, 8.0);
        float level = 0.9 - age * 0.1;
        color = max(color, vec3(level) * (1.0 - smoothstep(2.5 * scale, 3.5 * scale, dist)));
    }
    return vec4(color, 1.0);
}

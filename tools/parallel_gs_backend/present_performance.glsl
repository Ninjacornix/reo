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

// Modern camera crosshair (bit 30 of the fps word): a centre dot and four arms
// with a dark outline, scaled with the output height, at the window centre
// where the picture is centred.
bool crosshairShape(ivec2 p, int thickness, int gap, int arm) {
    bool horizontal = abs(p.y) <= thickness && abs(p.x) >= gap && abs(p.x) <= gap + arm;
    bool vertical = abs(p.x) <= thickness && abs(p.y) >= gap && abs(p.y) <= gap + arm;
    bool centre = abs(p.x) <= thickness && abs(p.y) <= thickness;
    return horizontal || vertical || centre;
}
vec4 crosshairOverlay(vec4 color, uvec2 destination, uint flags) {
    if ((flags & 0x40000000u) == 0u) return color;
    int scale = clamp(int(destination.y) / 480, 1, 4);
    ivec2 p = ivec2(gl_FragCoord.xy) - ivec2(destination) / 2;
    int thickness = scale / 2, gap = 4 * scale, arm = 6 * scale;
    if (crosshairShape(p, thickness, gap, arm)) return vec4(0.93, 0.96, 0.93, 1);
    if (crosshairShape(p, thickness + 1, gap - 1, arm + 2)) return vec4(color.rgb * 0.25, 1);
    return color;
}

// Black screen while the game connects (fps word bit 28; bits 16..23 animate):
// eight dots on a small ring in the middle of the screen, the brightest one moving round.
// Status text under the connecting spinner (stage in bits 24..27 of the fps word):
// a 5x7 pixel font for the letters the messages use. Generated from the list in
// recomp/overrides/reo_hw_bridge.cpp (networkStageText); keep the order in sync.
const uint STATUS_GLYPH_LO[21] = uint[](0x0u, 0xa31fc631u, 0xa31f463eu, 0xa308422eu, 0xa318c63eu, 0xe10f421fu, 0xa30bc62fu, 0x631fc631u, 0x8842108eu, 0xc4210a4cu, 0x654c5251u, 0x2108421fu, 0x639ace31u, 0xa318c62eu, 0xa31f4210u, 0xa31f5251u, 0xe107043eu, 0xc8421084u, 0x6318c62eu, 0x631ad6aau, 0x62a21084u);
const uint STATUS_GLYPH_HI[21] = uint[](0x0u, 0x3u, 0x7u, 0x3u, 0x7u, 0x7u, 0x3u, 0x4u, 0x3u, 0x1u, 0x4u, 0x4u, 0x4u, 0x3u, 0x7u, 0x7u, 0x3u, 0x7u, 0x4u, 0x4u, 0x4u);
const uint STATUS_TEXT[116] = uint[](3u, 13u, 12u, 12u, 5u, 3u, 17u, 8u, 12u, 6u, 11u, 13u, 1u, 4u, 8u, 12u, 6u, 0u, 12u, 5u, 17u, 19u, 13u, 15u, 10u, 0u, 16u, 5u, 17u, 17u, 8u, 12u, 6u, 16u, 3u, 13u, 12u, 12u, 5u, 3u, 17u, 8u, 12u, 6u, 0u, 17u, 13u, 0u, 17u, 7u, 5u, 0u, 12u, 5u, 17u, 19u, 13u, 15u, 10u, 14u, 15u, 5u, 14u, 1u, 15u, 8u, 12u, 6u, 0u, 20u, 13u, 18u, 15u, 0u, 1u, 3u, 3u, 13u, 18u, 12u, 17u, 16u, 8u, 6u, 12u, 8u, 12u, 6u, 0u, 8u, 12u, 9u, 13u, 8u, 12u, 8u, 12u, 6u, 0u, 17u, 7u, 5u, 0u, 11u, 13u, 2u, 2u, 20u, 16u, 17u, 1u, 15u, 17u, 8u, 12u, 6u);
const uint STATUS_START[7] = uint[](0u, 10u, 34u, 59u, 81u, 91u, 108u);
const uint STATUS_LENGTH[7] = uint[](10u, 24u, 25u, 22u, 10u, 17u, 8u);
float statusText(vec2 fragment, vec2 centre, float scale, uint stage) {
    if (stage >= 7u) return 0.0;
    uint count = STATUS_LENGTH[stage];
    float pixel = 2.0 * scale;                 // one font pixel
    vec2 cell = vec2(6.0, 9.0) * pixel;        // 5x7 glyph plus spacing
    vec2 origin = vec2(centre.x - float(count) * cell.x * 0.5, centre.y + 36.0 * scale);
    vec2 p = fragment - origin;
    if (p.x < 0.0 || p.y < 0.0 || p.y >= 7.0 * pixel) return 0.0;
    uint column = uint(p.x / cell.x);
    if (column >= count) return 0.0;
    vec2 inside = (p - vec2(float(column) * cell.x, 0.0)) / pixel;
    if (inside.x >= 5.0) return 0.0;
    uint glyph = STATUS_TEXT[STATUS_START[stage] + column];
    uint bit = 34u - (uint(inside.y) * 5u + uint(inside.x));   // first row is the highest bit
    uint word = bit >= 32u ? STATUS_GLYPH_HI[glyph] : STATUS_GLYPH_LO[glyph];
    return float((word >> (bit & 31u)) & 1u);
}

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
    color = max(color, vec3(0.85) * statusText(fragment, centre, scale, (flags >> 24u) & 15u));
    return vec4(color, 1.0);
}

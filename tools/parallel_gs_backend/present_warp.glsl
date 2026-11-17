// Presentation warp (runtime/gs/performance.h, namespace warp). Include after the
// push constants (warp0..2, warpParams, warpInfo) and a `depthValues` storage buffer
// holding the shown frame's GS Z buffer (one uint per pixel, warpInfo.yz = size).
// Picture coordinates are 0..1 with y down; NDC has y up.
//   warpInfo.x == 1: rotation; rows map shown NDC (nx, ny, 1) to the rendered frame.
//   warpInfo.x == 2: depth; rows = rendered->shown camera rotation, .w = translation,
//                    warpParams = (tan x, tan y, a, b) with Z = a + b / distance.
vec2 warpRotation(vec2 picture, vec4 r0, vec4 r1, vec4 r2) {
    vec3 q = vec3(picture.x * 2.0 - 1.0, 1.0 - picture.y * 2.0, 1.0);
    vec3 v = vec3(dot(r0.xyz, q), dot(r1.xyz, q), dot(r2.xyz, q));
    if (v.z <= 1e-4) return picture;
    vec2 ndc = v.xy / v.z;
    return clamp(vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5), vec2(0.0), vec2(1.0));
}
float warpDistance(vec2 ndc, uvec2 size, vec4 params) {
    vec2 picture = clamp(vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5), vec2(0.0), vec2(0.99999));
    uvec2 at = uvec2(picture * vec2(size));
    float z = float(depthValues.values[at.y * size.x + at.x]);
    float d = params.w / (z - params.z);
    return (d > 1.0 && d < 1.0e6) ? d : 1.0e6;  // cleared / out of range: far away
}
vec2 warpDepth(vec2 picture, vec4 r0, vec4 r1, vec4 r2, vec4 params, uvec2 size) {
    mat3 m = mat3(vec3(r0.x, r1.x, r2.x), vec3(r0.y, r1.y, r2.y), vec3(r0.z, r1.z, r2.z));  // rows r0..r2
    vec3 o = vec3(r0.w, r1.w, r2.w);
    vec2 tan2 = params.xy;
    vec2 q = vec2(picture.x * 2.0 - 1.0, 1.0 - picture.y * 2.0);
    // Start from the rotation-only answer, then correct with the depth of the guess.
    vec3 shownRay = vec3(-q.x * tan2.x, q.y * tan2.y, 1.0);
    vec3 back = transpose(m) * shownRay;
    vec2 s = back.z > 1e-4 ? vec2(-back.x / back.z / tan2.x, back.y / back.z / tan2.y) : q;
    for (int i = 0; i < 4; ++i) {
        float d = warpDistance(s, size, params);
        vec3 rendered = vec3(-s.x * tan2.x * d, s.y * tan2.y * d, d);
        vec3 shown = m * rendered + o;
        if (shown.z <= 1e-3) break;
        vec2 estimate = vec2(-shown.x / shown.z / tan2.x, shown.y / shown.z / tan2.y);
        s += q - estimate;
    }
    return clamp(vec2(s.x * 0.5 + 0.5, 0.5 - s.y * 0.5), vec2(0.0), vec2(1.0));
}
vec2 warpPicture(vec2 picture, vec4 r0, vec4 r1, vec4 r2, vec4 params, uvec4 info) {
    if (info.x == 1u) return warpRotation(picture, r0, r1, r2);
    if (info.x == 2u && info.y > 0u && info.z > 0u) return warpDepth(picture, r0, r1, r2, params, info.yz);
    return picture;
}

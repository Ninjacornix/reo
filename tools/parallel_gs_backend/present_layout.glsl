// Presentation only. Bits 24:25 select aspect; 26:28 select screen fit.
vec2 pictureSize(uvec2 source, uvec2 destination, uint flags) {
    vec2 outputSize = vec2(destination);
    // 4:3, 16:9, 21:9 (3440x1440, the common ultrawide panel) and 32:9.
    const float aspects[4] = float[4](4.0 / 3.0, 16.0 / 9.0, 43.0 / 18.0, 32.0 / 9.0);
    float aspect = aspects[(flags >> 24u) & 3u];
    vec2 unit = vec2(aspect, 1.0);
    float fitHeight = min(outputSize.x / aspect, outputSize.y);
    uint mode = (flags >> 26u) & 7u;
    if (mode == 1u) return outputSize; // Stretch: use every output pixel.
    if (mode == 2u) return unit * min(float(source.y), fitHeight); // Center, downscale only if needed.
    if (mode == 3u) return unit * max(outputSize.x / aspect, outputSize.y); // Fill with cropping.
    return unit * fitHeight;
}

// Presentation warp: picture coordinates (0..1, y down) of the shown frame to the
// rendered frame for a pure camera rotation (rows from performance.h warp::build).
// r0.w == 0 disables it. Points outside the rendered frame clamp to its edge.
vec2 warpPicture(vec2 picture, vec4 r0, vec4 r1, vec4 r2) {
    if (r0.w == 0.0) return picture;
    vec3 q = vec3(picture.x * 2.0 - 1.0, 1.0 - picture.y * 2.0, 1.0);
    vec3 v = vec3(dot(r0.xyz, q), dot(r1.xyz, q), dot(r2.xyz, q));
    if (v.z <= 1e-4) return picture;
    vec2 ndc = v.xy / v.z;
    return clamp(vec2(ndc.x * 0.5 + 0.5, 0.5 - ndc.y * 0.5), vec2(0.0), vec2(1.0));
}

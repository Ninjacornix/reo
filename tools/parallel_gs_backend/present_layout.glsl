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

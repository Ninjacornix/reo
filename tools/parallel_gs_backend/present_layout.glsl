// Presentation only. Bits 24:25 select aspect; 26:28 select screen fit.
vec2 pictureSize(uvec2 source, uvec2 destination, uint flags) {
    vec2 outputSize = vec2(destination);
    float aspect = ((flags >> 24u) & 3u) == 1u ? 16.0 / 9.0 : 4.0 / 3.0;
    vec2 unit = vec2(aspect, 1.0);
    float fitHeight = min(outputSize.x / aspect, outputSize.y);
    uint mode = (flags >> 26u) & 7u;
    if (mode == 1u) return outputSize; // Stretch: use every output pixel.
    if (mode == 2u) return unit * min(float(source.y), fitHeight); // Center, downscale only if needed.
    if (mode == 3u) return unit * max(outputSize.x / aspect, outputSize.y); // Fill with cropping.
    return unit * fitHeight;
}

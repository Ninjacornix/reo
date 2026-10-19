vec4 displayColor(vec3 color, uint flags) {
    uint brightness = (flags >> 8u) & 255u;
    uint gammaValue = (flags >> 16u) & 255u;
    if ((brightness == 0u || brightness == 100u) && (gammaValue == 0u || gammaValue == 100u))
        return vec4(color, 1.0);
    float gain = brightness == 0u ? 1.0 : float(brightness) / 100.0;
    float gamma = gammaValue == 0u ? 1.0 : float(gammaValue) / 100.0;
    return vec4(pow(clamp(color * gain, 0.0, 1.0), vec3(1.0 / gamma)), 1.0);
}


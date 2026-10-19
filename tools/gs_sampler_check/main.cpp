// The selected frozen source is copied into the build output by run.bat.
// Including it gives the oracle access to the exact anonymous lerpChannel;
// there are no production wrappers or header/API changes.
#include "selected_source.cpp"
#include <xmmintrin.h>
#include <emmintrin.h>
#include <limits>
#include <fstream>
#include <cstring>

#define main gsSamplerTriangleFixtureMain
#include "triangle_fixture.inc"
#undef main

namespace sampler_oracle {
uint32_t raw(float f) {
    uint32_t u;
    std::memcpy(&u, &f, 4);
    return u;
}
// Independently round the final finite float's IEEE representation, without
// lroundf or a floating +0.5. Ties round away from zero, then clamp to a byte.
uint8_t roundedByte(float f) {
    const uint32_t u = raw(f), exponent = (u >> 23) & 255, fraction = u & 0x7fffff;
    const bool negative = (u >> 31) != 0;
    if (negative || exponent == 0)
        return 0;
    const int e = int(exponent) - 127;
    if (e >= 8)
        return 255;
    if (e < -1)
        return 0;
    const uint32_t mantissa = 0x800000 | fraction;
    const unsigned shift = unsigned(23 - e);
    const uint32_t rounded = (mantissa + (uint32_t(1) << (shift - 1))) >> shift;
    return uint8_t(std::min(rounded, 255u));
}
float scalar(float a, float b, float c, float d, float fx, float fy) {
    const auto x = _mm_set_ss(fx), y = _mm_set_ss(fy);
    const auto aa = _mm_set_ss(a), bb = _mm_set_ss(b);
    const auto cc = _mm_set_ss(c), dd = _mm_set_ss(d);
    const auto top = _mm_add_ss(aa, _mm_mul_ss(_mm_sub_ss(bb, aa), x));
    const auto bottom = _mm_add_ss(cc, _mm_mul_ss(_mm_sub_ss(dd, cc), x));
    return _mm_cvtss_f32(_mm_add_ss(top, _mm_mul_ss(_mm_sub_ss(bottom, top), y)));
}
uint32_t originalColor(uint32_t aa, uint32_t bb, uint32_t cc, uint32_t dd, float x, float y) {
    const uint8_t r = lerpChannel(uint8_t(aa), uint8_t(bb), uint8_t(cc), uint8_t(dd), x, y);
    const uint8_t g =
        lerpChannel(uint8_t(aa >> 8), uint8_t(bb >> 8), uint8_t(cc >> 8), uint8_t(dd >> 8), x, y);
    const uint8_t b = lerpChannel(uint8_t(aa >> 16), uint8_t(bb >> 16), uint8_t(cc >> 16),
                                  uint8_t(dd >> 16), x, y);
    const uint8_t a = lerpChannel(uint8_t(aa >> 24), uint8_t(bb >> 24), uint8_t(cc >> 24),
                                  uint8_t(dd >> 24), x, y);
    return uint32_t(r) | (uint32_t(g) << 8) | (uint32_t(b) << 16) | (uint32_t(a) << 24);
}
uint32_t actualColor(uint32_t aa, uint32_t bb, uint32_t cc, uint32_t dd, float x, float y) {
#if defined(REO_GS_PACKED_SAMPLER)
    return bilinearColor(aa, bb, cc, dd, x, y);
#else
    return originalColor(aa, bb, cc, dd, x, y);
#endif
}
int numeric(const char* path) {
    std::ofstream dump, flags;
    if (path) {
        dump.open(std::string(path) + ".numeric", std::ios::binary);
        flags.open(std::string(path) + ".mxcsr", std::ios::binary);
        if (!dump || !flags)
            return 2;
    }
    unsigned checks = 0, failures = 0;
    uint64_t digest = 14695981039346656037ull;
    const unsigned saved = _mm_getcsr();
    auto check = [&](unsigned a, unsigned b, unsigned c, unsigned d, float x, float y) {
        // Volatile inputs prevent constant-folding across the dynamic MXCSR.
        volatile float vx = x, vy = y;
        const uint32_t aa = a | (b << 8) | (c << 16) | (d << 24),
                       bb = b | (a << 8) | (d << 16) | (c << 24);
        const uint32_t cc = c | (d << 8) | (a << 16) | (b << 24),
                       dd = d | (c << 8) | (b << 16) | (a << 24);
        const unsigned inputCsr = (_mm_getcsr() & ~0x3fu) | ((checks & 1) ? 0x3f : 0);
        _mm_setcsr(inputCsr);
        const uint32_t actual = actualColor(aa, bb, cc, dd, vx, vy);
        const unsigned actualCsr = _mm_getcsr();
        _mm_setcsr(inputCsr);
        const uint32_t original = originalColor(aa, bb, cc, dd, vx, vy);
        const unsigned originalCsr = _mm_getcsr();
        uint32_t expected = 0;
        for (unsigned lane = 0; lane < 4; ++lane) {
            const auto shift = lane * 8;
            expected |= uint32_t(roundedByte(scalar(
                            float(uint8_t(aa >> shift)), float(uint8_t(bb >> shift)),
                            float(uint8_t(cc >> shift)), float(uint8_t(dd >> shift)), vx, vy)))
                        << shift;
            digest = (digest ^ uint8_t(actual >> shift)) * 1099511628211ull;
        }
        if ((raw(x) & 0x7f800000u) == 0x7f800000u || (raw(y) & 0x7f800000u) == 0x7f800000u)
            expected = original; // CRT nonfinite controls require scalar parity.
        ++checks;
        if (path) {
            dump.write(reinterpret_cast<const char*>(&actual), 4);
            flags.write(reinterpret_cast<const char*>(&actualCsr), 4);
        }
        if (actual != expected || actual != original || actualCsr != originalCsr) {
            if (failures < 8)
                std::printf("FAIL numeric c=%u/%u/%u/%u x=%08x y=%08x actual=%08x expected=%08x "
                            "scalar=%08x csr=%x scalarcsr=%x\n",
                            a, b, c, d, raw(x), raw(y), actual, expected, original, actualCsr,
                            originalCsr);
            ++failures;
        }
    };
    std::vector<float> weights{-0.25f,
                               -0.0f,
                               0.0f,
                               std::numeric_limits<float>::denorm_min(),
                               std::numeric_limits<float>::min(),
                               0.0625f,
                               0.25f,
                               std::nextafter(0.5f, 0.0f),
                               0.5f,
                               std::nextafter(0.5f, 1.0f),
                               0.75f,
                               std::nextafter(1.0f, 0.0f),
                               1.0f,
                               1.25f};
    constexpr std::array<std::array<unsigned, 4>, 12> colors{{{{0, 255, 255, 0}},
                                                              {{255, 0, 0, 255}},
                                                              {{0, 1, 0, 1}},
                                                              {{254, 255, 254, 255}},
                                                              {{255, 255, 255, 255}},
                                                              {{0, 0, 0, 0}},
                                                              {{127, 128, 129, 130}},
                                                              {{17, 203, 91, 249}},
                                                              {{255, 1, 128, 0}},
                                                              {{1, 254, 0, 255}},
                                                              {{128, 128, 127, 127}},
                                                              {{3, 5, 7, 11}}}};
    for (unsigned round = 0; round < 4; ++round)
        for (unsigned denorm = 0; denorm < 2; ++denorm) {
            const unsigned control =
                (saved & ~(0x6000u | 0x8040u | 0x3fu)) | (round << 13) | (denorm ? 0x8040 : 0);
            _mm_setcsr(control);
            for (const auto& c : colors)
                for (float x : weights)
                    for (float y : weights)
                        check(c[0], c[1], c[2], c[3], x, y);
            // Every byte-range half-integer, including both adjacent float weights.
            for (unsigned a = 0; a < 255; ++a)
                for (float w : {std::nextafter(0.5f, 0.0f), 0.5f, std::nextafter(0.5f, 1.0f)}) {
                    check(a, a + 1, a, a + 1, w, 0.0f);
                    check(a, a, a + 1, a + 1, 0.0f, w);
                }
            // Adjacent floats around k+0.5 with a full-range ramp provide finer
            // cases than the one-unit ramp after its addition rounds to float.
            for (unsigned a = 0; a < 255; ++a) {
                const float w = (float(a) + 0.5f) / 255.0f;
                for (float x : {std::nextafter(w, 0.0f), w, std::nextafter(w, 1.0f)})
                    check(0, 255, 0, 255, x, 0.0f);
            }
            for (float bad :
                 {std::numeric_limits<float>::infinity(), -std::numeric_limits<float>::infinity(),
                  std::numeric_limits<float>::quiet_NaN()}) {
                check(0, 255, 17, 203, bad, 0.5f);
                check(17, 203, 0, 255, 0.5f, bad);
            }
            // Exact constant output with precision unmasked must select the scalar
            // fallback without changing host exception control or introducing traps.
            _mm_setcsr(control & ~0x1000u);
            check(128, 128, 128, 128, 0.25f, 0.75f);
            _mm_setcsr(control);
            if ((_mm_getcsr() & 0xffc0) != (control & 0xffc0)) {
                ++failures;
                std::printf("FAIL MXCSR control changed\n");
            }
        }
    _mm_setcsr(saved);
    if (path && (!dump || !flags))
        return 2;
    std::printf("NUMERIC checks=%u failures=%u hash=%016llx\n", checks, failures,
                static_cast<unsigned long long>(digest));
    return failures ? 1 : 0;
}
} // namespace sampler_oracle

int main(int argc, char** argv) {
    const char* path = nullptr;
    for (int i = 1; i + 1 < argc; ++i)
        if (!std::strcmp(argv[i], "--dump"))
            path = argv[i + 1];
    if (const int status = sampler_oracle::numeric(path))
        return status;
    return gsSamplerTriangleFixtureMain(argc, argv);
}

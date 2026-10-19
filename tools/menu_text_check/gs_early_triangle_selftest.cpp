// Two processes (REO_GS_EARLY_TESTS=0/1) must emit identical complete-VRAM
// hashes. Fixed interior-pixel assertions are independent of either pipeline.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmct16.h"
#include "runtime/ps2_gs_psmt8.h"
#include <algorithm>
#include <array>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
constexpr unsigned X = 12, Y = 20, Texture = 4096, Palette = 8192;
constexpr uint32_t Old = 0x80445566, New = 0x20112233;
uint32_t bits(float v) {
    uint32_t u;
    std::memcpy(&u, &v, 4);
    return u;
}
uint64_t hash(const std::vector<uint8_t>& bytes) {
    uint64_t h = 14695981039346656037ull;
    for (auto b : bytes)
        h = (h ^ b) * 1099511628211ull;
    return h;
}
uint32_t fbAddress(unsigned format, unsigned x = X, unsigned y = Y) {
    if (format == GS_PSM_CT16)
        return GSPSMCT16::addrPSMCT16(0, 1, x, y);
    if (format == GS_PSM_CT16S)
        return GSPSMCT16::addrPSMCT16S(0, 1, x, y);
    return GSPSMCT32::addrPSMCT32(0, 1, x, y);
}
uint16_t color16(uint32_t c) {
    return uint16_t(((c & 255) >> 3) | ((((c >> 8) & 255) >> 3) << 5) |
                    ((((c >> 16) & 255) >> 3) << 10) | (((c >> 24) >= 64) ? 0x8000 : 0));
}
} // namespace

int main() {
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    GSRegisters registers{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &registers);
    unsigned checks = 0, failures = 0;
    auto store = [&](unsigned address, uint32_t v, unsigned n = 4) {
        std::memcpy(vram.data() + address, &v, n);
    };
    auto read = [&](unsigned address, unsigned n = 4) {
        uint32_t v = 0;
        std::memcpy(&v, vram.data() + address, n);
        return v;
    };
    auto setup = [&](uint64_t test, unsigned zFormat = 0, bool zMask = false,
                     unsigned frameFormat = 0, uint32_t frameMask = 0) {
        std::fill(vram.begin(), vram.end(), 0);
        gs.writeRegister(GS_REG_FRAME_1, (1ull << 16) | (uint64_t(frameFormat) << 24) |
                                             (uint64_t(frameMask) << 32));
        gs.writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (63ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, test);
        gs.writeRegister(GS_REG_ZBUF_1, 4ull | (uint64_t(zFormat) << 24) | (uint64_t(zMask) << 32));
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PABE, 0);
        gs.writeRegister(GS_REG_ALPHA_1, 0x44);
        gs.writeRegister(GS_REG_TEX0_1, Texture | (1ull << 14) | (3ull << 26) | (3ull << 30) |
                                            (1ull << 34) | (1ull << 35));
        gs.writeRegister(GS_REG_TEX1_1, 0);
        gs.writeRegister(GS_REG_CLAMP_1, 5);
        gs.writeRegister(GS_REG_TEXCLUT, 0);
        gs.writeRegister(GS_REG_TEXA, 0x8000000000ull);
        for (unsigned y = 0; y < 8; ++y)
            for (unsigned x = 0; x < 8; ++x)
                store(GSPSMCT32::addrPSMCT32(Texture, 1, x, y), New);
    };
    auto triangle = [&](std::array<uint32_t, 3> depths, bool bilinear = false, bool blend = false) {
        gs.writeRegister(GS_REG_TEX1_1, bilinear ? 0x60 : 0);
        gs.writeRegister(GS_REG_PRIM,
                         GS_PRIM_TRIANGLE | (1u << 3) | (1u << 4) | (blend ? 1u << 6 : 0));
        constexpr unsigned xs[]{4, 36, 4}, ys[]{4, 4, 36};
        constexpr float qs[]{1, 2, 4}, us[]{.0625f, .875f, .0625f}, vs[]{.0625f, .0625f, .875f};
        for (unsigned i = 0; i < 3; ++i) {
            gs.writeRegister(GS_REG_RGBAQ, 0x80808080ull | (uint64_t(bits(qs[i])) << 32));
            gs.writeRegister(GS_REG_ST,
                             bits(us[i] * qs[i]) | (uint64_t(bits(vs[i] * qs[i])) << 32));
            gs.writeRegister(GS_REG_XYZ2, xs[i] * 16 | (uint64_t(ys[i] * 16) << 16) |
                                              (uint64_t(depths[i]) << 32));
        }
    };
    auto report = [&](const char* family, unsigned a, unsigned b, unsigned c, unsigned d,
                      bool valid) {
        ++checks;
        failures += !valid;
        std::printf("%s %s a=%u b=%u c=%u d=%u hash=%016llx\n", valid ? "PASS" : "FAIL", family, a,
                    b, c, d, static_cast<unsigned long long>(hash(vram)));
    };
    // x12/y20 Z32/24 independently resolves block17/column40 =0x91A0.
    // Z16/16S independently resolve blocks28/16:0x9CA2/0x90A2.
    constexpr unsigned formats[]{0, 1, 2, 10}, offsets[]{0x91a0, 0x91a0, 0x9ca2, 0x90a2};
    for (unsigned format = 0; format < 4; ++format)
        for (unsigned function = 0; function < 4; ++function)
            for (unsigned masked = 0; masked < 2; ++masked)
                for (unsigned source = 99; source <= 101; ++source)
                    for (unsigned alpha = 0; alpha < 5; ++alpha) {
                        const bool alphaPass = alpha == 0;
                        const unsigned afail = alphaPass ? 0 : alpha - 1;
                        setup((1ull << 16) | (uint64_t(function) << 17) |
                                  (alphaPass ? 0 : 1ull | (uint64_t(afail) << 12)),
                              formats[format], masked != 0);
                        const unsigned bytes = format < 2 ? 4 : 2;
                        const uint32_t mask = format == 1   ? 0xffffff
                                              : format >= 2 ? 0xffff
                                                            : 0xffffffff;
                        store(fbAddress(0), Old);
                        store(offsets[format], format == 1 ? 0xab000064 : 100, bytes);
                        triangle({source, source, source});
                        const bool zPass = function == 1 || (function == 2 && source >= 100) ||
                                           (function == 3 && source > 100);
                        uint32_t expectedColor = Old;
                        if (zPass && (alphaPass || afail == 1))
                            expectedColor = New;
                        if (zPass && !alphaPass && afail == 3)
                            expectedColor = (New & 0xffffff) | (Old & 0xff000000);
                        const bool writeZ = zPass && !masked && (alphaPass || afail == 2);
                        const uint32_t expectedZ = writeZ ? source : 100;
                        const bool valid = read(fbAddress(0)) == expectedColor &&
                                           (read(offsets[format], bytes) & mask) == expectedZ &&
                                           (format != 1 || (read(offsets[format]) >> 24) == 0xab);
                        report("depth-alpha", formats[format], function, source, masked * 5 + alpha,
                               valid);
                    }
    for (unsigned format = 0; format < 4; ++format) {
        const unsigned bytes = format < 2 ? 4 : 2;
        const uint32_t mask = format == 1 ? 0xffffff : format >= 2 ? 0xffff : 0xffffffff;
        setup((1ull << 16) | (2ull << 17), formats[format]);
        store(fbAddress(0), Old);
        store(offsets[format], mask, bytes);
        triangle({0xffffffff, 0xffffffff, 0xffffffff});
        report("format-overflow-clamp", formats[format], 0, 0, 0,
               read(fbAddress(0)) == New && (read(offsets[format], bytes) & mask) == mask);
    }
    constexpr unsigned framebufferFormats[]{GS_PSM_CT32, GS_PSM_CT24, GS_PSM_CT16, GS_PSM_CT16S};
    for (unsigned frame : framebufferFormats)
        for (unsigned datm = 0; datm < 2; ++datm)
            for (unsigned destinationBit = 0; destinationBit < 2; ++destinationBit)
                for (unsigned afail = 0; afail < 4; ++afail) {
                    const bool frame16 = frame == GS_PSM_CT16 || frame == GS_PSM_CT16S;
                    setup((1ull << 14) | (uint64_t(datm) << 15) | (1ull << 16) | (1ull << 17) |
                              1ull | (uint64_t(afail) << 12),
                          0, false, frame);
                    const uint32_t old = frame16 ? (0x1234 | (destinationBit << 15))
                                                 : ((Old & 0x7fffffff) | (destinationBit << 31));
                    store(fbAddress(frame), old, frame16 ? 2 : 4);
                    store(0x91a0, 100);
                    triangle({101, 101, 101});
                    const bool pass = frame != GS_PSM_CT24 && datm == destinationBit;
                    uint32_t expectedColor = old;
                    if (pass && afail == 1)
                        expectedColor = frame16 ? color16(New) : New;
                    if (pass && afail == 3)
                        expectedColor = frame16 ? ((color16(New) & 0x7fff) | (old & 0x8000))
                                                : ((New & 0xffffff) | (old & 0xff000000));
                    report("date-alpha", frame, datm, destinationBit, afail,
                           read(fbAddress(frame), frame16 ? 2 : 4) == expectedColor &&
                               read(0x91a0) == (pass && afail == 2 ? 101u : 100u));
                }
    for (unsigned fullMask = 0; fullMask < 2; ++fullMask) {
        setup((1ull << 16) | (2ull << 17), 0, false, 0, fullMask ? 0xffffffff : 0x00ff00ff);
        store(fbAddress(0), Old);
        store(0x91a0, 100);
        triangle({101, 101, 101});
        const uint32_t expected = fullMask ? Old : ((New & ~0x00ff00ffu) | (Old & 0x00ff00ffu));
        report("frame-mask-independent-depth", fullMask, 0, 0, 0,
               read(fbAddress(0)) == expected && read(0x91a0) == 101);
    }
    setup(0);
    store(fbAddress(0), Old);
    store(0x91a0, 100);
    triangle({99, 99, 99});
    report("ZTE-disabled", 0, 0, 0, 0, read(fbAddress(0)) == New && read(0x91a0) == 100);
    setup((1ull << 16) | (3ull << 17));
    store(fbAddress(0), Old);
    store(0x91a0, 182);
    triangle({100, 164, 228});
    report("affine-Z-not-vertex", 0, 0, 0, 0, read(fbAddress(0)) == New && read(0x91a0) == 183);
    for (unsigned afail = 0; afail < 4; ++afail)
        for (unsigned reference = 31; reference <= 32; ++reference) {
            setup(1ull | (6ull << 1) | (uint64_t(reference) << 4) | (uint64_t(afail) << 12) |
                  (1ull << 16) | (2ull << 17));
            store(fbAddress(0), Old);
            store(0x91a0, 100);
            triangle({101, 101, 101});
            const bool pass = reference == 31;
            const uint32_t expected = pass || afail == 1 ? New
                                      : afail == 3       ? (New & 0xffffff) | (Old & 0xff000000)
                                                         : Old;
            report("texture-alpha-threshold", afail, reference, 0, 0,
                   read(fbAddress(0)) == expected &&
                       read(0x91a0) == (pass || afail == 2 ? 101u : 100u));
        }
    setup((1ull << 16) | (3ull << 17));
    store(fbAddress(0), Old);
    store(0x91a0, 0xf0000011);
    triangle({0xf0000012, 0xf0000012, 0xf0000012});
    report("exact-high-unsigned-Z", 0, 0, 0, 0,
           read(fbAddress(0)) == New && read(0x91a0) == 0xf0000012);
    setup((1ull << 16) | (2ull << 17), 3);
    store(fbAddress(0), Old);
    triangle({101, 101, 101});
    report("invalid-depth-format", 0, 0, 0, 0, read(fbAddress(0)) == Old);
    for (unsigned format = 0; format < 2; ++format) {
        setup((1ull << 16) | (2ull << 17), format);
        gs.writeRegister(GS_REG_ZBUF_1, 511ull | (uint64_t(format) << 24));
        store(fbAddress(0), Old);
        store(0x3ff1a0, format ? 0xab000064 : 100);
        triangle({101, 101, 101});
        report("wrapped-Z32-page", format, 0, 0, 0,
               read(fbAddress(0)) == New && read(0x3ff1a0) == (format ? 0xab000065u : 101u));
    }

    // Live feedback controls deliberately alias texture or palette reads with
    // FB/depth writes. On/off full-VRAM parity is required; no cached reset GS
    // state or immutable texel snapshot serves as the expected result.
    for (unsigned alias = 0; alias < 5; ++alias)
        for (unsigned afail = 0; afail < 4; ++afail)
            for (unsigned linear = 0; linear < 2; ++linear) {
                setup((1ull << 16) | (2ull << 17) | 1ull | (uint64_t(afail) << 12));
                for (size_t i = 0; i < vram.size(); ++i)
                    vram[i] = uint8_t((i * 73 + (i >> 8) * 19) & 255);
                // Small live Z values permit both accepted and rejected fragments.
                for (unsigned y = 0; y < 64; ++y)
                    for (unsigned x = 0; x < 64; ++x) {
                        const unsigned off =
                            (alias == 4 ? 0 : 32768) + (y / 32) * 8192 + (x / 64) * 8192 +
                            (GSPSMCT32::blockTable32[(y / 8) % 4][(x / 8) % 8] ^ 24) * 256 +
                            GSPSMCT32::columnTable32[y % 8][x % 8] * 4;
                        store(off, ((x + y) & 1) ? 120 : 80);
                    }
                unsigned textureBlock = Texture, paletteBlock = Palette;
                if (alias == 0)
                    textureBlock = 0; // Texture/framebuffer.
                if (alias == 1)
                    textureBlock = 128; // Texture/depth (ZBP4).
                if (alias == 2)
                    paletteBlock = 0; // Palette/framebuffer.
                if (alias == 3)
                    paletteBlock = 128; // Palette/depth.
                const bool paletted = alias == 2 || alias == 3;
                gs.writeRegister(GS_REG_TEX0_1,
                                 textureBlock | (1ull << 14) |
                                     (uint64_t(paletted ? GS_PSM_T8 : GS_PSM_CT32) << 20) |
                                     (6ull << 26) | (6ull << 30) | (1ull << 34) | (1ull << 35) |
                                     (uint64_t(paletteBlock) << 37) | (1ull << 55));
                if (alias == 4)
                    gs.writeRegister(GS_REG_ZBUF_1, 0); // FB/Z overlap, no masked write.
                gs.writeRegister(GS_REG_CLAMP_1, 0);
                triangle({90, 140, 190}, linear != 0, true);
                triangle({190, 140, 90}, linear != 0, true);
                report("live-feedback-parity", alias, afail, linear, 0, true);
            }
    std::printf("early_triangle_checks=%u failures=%u\n", checks, failures);
    return failures ? 1 : 0;
}

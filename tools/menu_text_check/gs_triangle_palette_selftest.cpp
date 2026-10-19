// Run separate processes with REO_GS_TRI_PALETTE_CACHE=0 and =1. Every
// complete-VRAM hash must agree; key pixels below are independent color oracles.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmct16.h"
#include "runtime/ps2_gs_psmt8.h"
#include "runtime/ps2_gs_psmt4.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
constexpr unsigned Texture = 4096, Palette = 8192;
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
uint32_t paletteAddress(unsigned cbp, unsigned width, unsigned psm, unsigned x, unsigned y) {
    if (psm == GS_PSM_CT16)
        return GSPSMCT16::addrPSMCT16(cbp, width, x, y);
    if (psm == GS_PSM_CT16S)
        return GSPSMCT16::addrPSMCT16S(cbp, width, x, y);
    return GSPSMCT32::addrPSMCT32(cbp, width, x, y);
}
unsigned paletteIndex(unsigned source, unsigned index, unsigned csm, unsigned csa) {
    unsigned selected = source == GS_PSM_T4 ? csa * 16 + (index & 15) : index;
    if (!csm) { // CSM1 selects physical bank16 for index8 and bank8 for index16.
        // This optimization preserves the runtime's existing eight-bit CSM1
        // direct-VRAM selection, including its CSA31 truncation. This is a
        // compatibility oracle, not proof of hardware CLUT-load semantics.
        selected %= 256;
        static constexpr unsigned bank[]{0, 16, 8, 24};
        selected = (selected & ~24u) + bank[(selected >> 3) & 3];
    }
    return selected;
}
} // namespace

int main() {
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    GSRegisters registers{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &registers);
    unsigned checks = 0, failures = 0;
    auto store = [&](unsigned off, uint32_t color, unsigned n = 4) {
        std::memcpy(vram.data() + off, &color, n);
    };
    auto read = [&](unsigned off, unsigned n = 4) {
        uint32_t color = 0;
        std::memcpy(&color, vram.data() + off, n);
        return color;
    };
    auto setup = [&](unsigned source, unsigned cpsm, unsigned csm, unsigned csa, unsigned cbp,
                     unsigned cbw, unsigned cou, unsigned cov, unsigned frame = 0, unsigned fbp = 0,
                     unsigned zbp = 4, unsigned zformat = 0, bool zmask = true,
                     uint32_t fbmask = 0) {
        std::fill(vram.begin(), vram.end(), 0);
        gs.writeRegister(GS_REG_FRAME_1,
                         fbp | (1ull << 16) | (uint64_t(frame) << 24) | (uint64_t(fbmask) << 32));
        gs.writeRegister(GS_REG_SCISSOR_1, (127ull << 16) | (127ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, (1ull << 16) | (1ull << 17));
        gs.writeRegister(GS_REG_ZBUF_1, zbp | (uint64_t(zformat) << 24) | (uint64_t(zmask) << 32));
        gs.writeRegister(GS_REG_ALPHA_1, 0x44);
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PABE, 0);
        gs.writeRegister(GS_REG_TEX0_1, Texture | (1ull << 14) | (uint64_t(source) << 20) |
                                            (3ull << 26) | (3ull << 30) | (1ull << 34) |
                                            (1ull << 35) | (uint64_t(cbp) << 37) |
                                            (uint64_t(cpsm) << 51) | (uint64_t(csm) << 55) |
                                            (uint64_t(csa) << 56));
        gs.writeRegister(GS_REG_TEXCLUT, cbw | (uint64_t(cou) << 6) | (uint64_t(cov) << 12));
        gs.writeRegister(GS_REG_TEXA, 0x8000000020ull);
        gs.writeRegister(GS_REG_CLAMP_1, 5);
    };
    auto textureIndex = [&](unsigned source, unsigned index) {
        for (unsigned y = 0; y < 8; ++y)
            for (unsigned x = 0; x < 8; ++x) {
                if (source == GS_PSM_T8)
                    vram[GSPSMT8::addrPSMT8(Texture, 1, x, y)] = uint8_t(index);
                else {
                    const unsigned nibble = GSPSMT4::addrPSMT4(Texture, 1, x, y), off = nibble / 2,
                                   shift = (nibble & 1) * 4;
                    vram[off] = uint8_t((vram[off] & ~(15u << shift)) | ((index & 15) << shift));
                }
            }
    };
    auto triangle = [&](unsigned ybase = 4, unsigned shade = 128, unsigned depth = 101,
                        bool linear = false) {
        gs.writeRegister(GS_REG_TEX1_1, linear ? 0x60 : 0);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_TRIANGLE | (1u << 3) | (1u << 4));
        const unsigned xs[]{4, 52, 4}, ys[]{ybase, ybase, ybase + 48};
        for (unsigned i = 0; i < 3; ++i) {
            const float q = float(1u << i);
            gs.writeRegister(GS_REG_RGBAQ, shade | (uint64_t(shade) << 8) |
                                               (uint64_t(shade) << 16) | (128ull << 24) |
                                               (uint64_t(bits(q)) << 32));
            gs.writeRegister(GS_REG_ST, bits(.25f * q) | (uint64_t(bits(.25f * q)) << 32));
            gs.writeRegister(GS_REG_XYZ2,
                             xs[i] * 16 | (uint64_t(ys[i] * 16) << 16) | (uint64_t(depth) << 32));
        }
    };
    auto report = [&](const char* family, unsigned a, unsigned b, unsigned c, unsigned d,
                      bool valid) {
        ++checks;
        failures += !valid;
        std::printf("%s %s a=%u b=%u c=%u d=%u hash=%016llx\n", valid ? "PASS" : "FAIL", family, a,
                    b, c, d, static_cast<unsigned long long>(hash(vram)));
    };
    constexpr unsigned sources[]{GS_PSM_T4, GS_PSM_T8},
        formats[]{GS_PSM_CT32, GS_PSM_CT24, GS_PSM_CT16, GS_PSM_CT16S};
    // 288 controls: runtime CSM1/2 compatibility, T4 CSA (including31), moved
    // TEXCLUT origins/stride, both filters, and TEXA/AEM zero/nonzero colors.
    for (unsigned source : sources)
        for (unsigned cpsm : formats)
            for (unsigned csm = 0; csm < 2; ++csm)
                for (unsigned variant = 0; variant < 3; ++variant)
                    for (unsigned alpha = 0; alpha < 3; ++alpha)
                        for (unsigned linear = 0; linear < 2; ++linear) {
                            const unsigned index = source == GS_PSM_T4 ? (variant == 0   ? 8
                                                                          : variant == 1 ? 5
                                                                                         : 15)
                                                                       : (variant == 0   ? 8
                                                                          : variant == 1 ? 16
                                                                                         : 250);
                            const unsigned csa = variant == 0 ? 0 : variant == 1 ? 1 : 31;
                            const unsigned cbw = variant == 0   ? 1
                                                 : variant == 1 ? 2
                                                                : 0,
                                           cou = variant == 0   ? 0
                                                 : variant == 1 ? 17
                                                                : 63,
                                           cov = variant == 0   ? 0
                                                 : variant == 1 ? 37
                                                                : 1023;
                            // Maximum COV verifies the actual far-away entry, rather than treating
                            // CBP alone as the palette range.
                            setup(source, cpsm, csm, csa, Palette, cbw, cou, cov);
                            textureIndex(source, index);
                            gs.writeRegister(GS_REG_TEXA,
                                             0x8000000020ull | (alpha == 2 ? 1ull << 15 : 0));
                            const unsigned selected = paletteIndex(source, index, csm, csa),
                                           off = paletteAddress(Palette, cbw ? cbw : 1, cpsm,
                                                                cou + (selected & 15),
                                                                cov + (selected >> 4));
                            const bool sixteen = cpsm == GS_PSM_CT16 || cpsm == GS_PSM_CT16S;
                            const unsigned bytes = sixteen ? 2 : 4;
                            const uint32_t raw =
                                alpha == 2
                                    ? 0
                                    : (sixteen ? (alpha == 0 ? 0xca93 : 0x4a93) : 0x7a543210);
                            const bool legacyHighBank =
                                source == GS_PSM_T4 && csm == 0 && variant == 2;
                            if (legacyHighBank) {
                                // Distinct upper-bank sentinel makes selecting physical511 fail;
                                // placing the same color in both banks would hide an address bug.
                                // Full hardware16-bit CSA/CLD behavior needs a separate CLUT model.
                                const unsigned upper = paletteAddress(Palette, cbw ? cbw : 1, cpsm,
                                                                      cou + 15, cov + 31);
                                if (uint64_t(upper) + bytes <= vram.size())
                                    store(upper, sixteen ? 0x7fff : 0x80224466, bytes);
                            }
                            if (uint64_t(off) + bytes <= vram.size())
                                store(off, raw, bytes);
                            triangle(4, 128, 101, linear != 0);
                            uint32_t expected = 0xffff00ff;
                            if (uint64_t(off) + bytes <= vram.size()) {
                                if (alpha == 2)
                                    expected = 0;
                                else if (sixteen)
                                    expected = (alpha == 0 ? 0x80000000 : 0x20000000) | 0x0090a098;
                                else
                                    expected = cpsm == GS_PSM_CT24 ? 0x20543210 : 0x7a543210;
                            }
                            report(legacyHighBank ? "runtime-upper-CSA-compatibility"
                                                  : "address-texa-filter",
                                   source, cpsm, csm, variant * 6 + alpha * 2 + linear,
                                   read(GSPSMCT32::addrPSMCT32(0, 1, 12, 20)) == expected);
                            // Each triangle gets a fresh cache even when every register is kept.
                            if (uint64_t(off) + bytes <= vram.size())
                                store(off, 0, bytes);
                            triangle(4, 128, 101, linear != 0);
                            const uint32_t zeroExpected =
                                uint64_t(off) + bytes > vram.size() ? 0xffff00ff
                                : cpsm == GS_PSM_CT32 || alpha == 2 ? 0
                                                                    : 0x20000000;
                            report("fresh-triangle-palette", source, cpsm, csm,
                                   variant * 6 + alpha * 2 + linear,
                                   read(GSPSMCT32::addrPSMCT32(0, 1, 12, 20)) == zeroExpected);
                        }
    for (unsigned source : sources)
        for (unsigned cpsm : formats) {
            setup(source, cpsm, 1, 31, 16383, 1, 63, 1023);
            textureIndex(source, 0);
            triangle();
            report("invalid-entry-bounds", source, cpsm, 0, 0,
                   read(GSPSMCT32::addrPSMCT32(0, 1, 12, 20)) == 0xffff00ff);
        }
    // Live framebuffer palette feedback has an independent final-pixel oracle:
    // palette(16,8) is shaded from705030 to382818, then later texels read that
    // updated entry and shade it to1c140c. A stale palette gives382818 instead.
    for (unsigned source : sources)
        for (unsigned linear = 0; linear < 2; ++linear) {
            setup(source, GS_PSM_CT32, 1, 0, 0, 1, 16, 8);
            textureIndex(source, 0);
            gs.writeRegister(GS_REG_TEX0_1, Texture | (1ull << 14) | (uint64_t(source) << 20) |
                                                (3ull << 26) | (3ull << 30) | (1ull << 34) |
                                                (1ull << 55));
            store(GSPSMCT32::addrPSMCT32(0, 1, 16, 8), 0x80705030);
            triangle(4, 64, 101, linear != 0);
            report("live-frame-palette", source, linear, 0, 0,
                   read(GSPSMCT32::addrPSMCT32(0, 1, 12, 20)) == 0x801c140c);
        }
    // Actual Z32 permutation maps depth(16,8) to palette CT32(48,24).
    // ZBP511 at y40 wraps the same write back to page0. Later texels must see101.
    for (unsigned source : sources)
        for (unsigned wrap = 0; wrap < 2; ++wrap)
            for (unsigned linear = 0; linear < 2; ++linear) {
                setup(source, GS_PSM_CT32, 1, 0, wrap ? 0 : 128, 1, 48, 24, GS_PSM_CT32, 32,
                      wrap ? 511 : 4, 0, false);
                textureIndex(source, 0);
                store(GSPSMCT32::addrPSMCT32(wrap ? 0 : 128, 1, 48, 24), 0x80705030);
                triangle(wrap ? 36 : 4, 128, 101, linear != 0);
                report("live-depth-palette-wrap", source, wrap, linear, 0,
                       read(GSPSMCT32::addrPSMCT32(32 * 32, 1, 12, wrap ? 52 : 20)) == 101);
            }
    // Full-VRAM hash parity controls cover partial entry aliases, all FB/Z
    // formats and AFAIL write masks. Patterned VRAM and two triangles ensure
    // palette entries can change within and between primitives.
    constexpr unsigned depthFormats[]{0, 1, 2, 10};
    for (unsigned source : sources)
        for (unsigned format = 0; format < 4; ++format)
            for (unsigned afail = 0; afail < 4; ++afail)
                for (unsigned alias = 0; alias < 4; ++alias)
                    for (unsigned linear = 0; linear < 2; ++linear) {
                        const unsigned cbp = alias == 0   ? 0
                                             : alias == 1 ? 128
                                             : alias == 2 ? 16352
                                                          : 0;
                        const unsigned cou = alias == 3 ? 48 : 0, cov = alias == 3 ? 88 : 0;
                        setup(source, formats[format], alias & 1, afail, cbp, 1, cou, cov,
                              formats[format], 0, alias == 2 ? 511 : 4, depthFormats[format], false,
                              afail == 3 ? 0xffffffff : 0);
                        for (size_t i = 0; i < vram.size(); ++i)
                            vram[i] = uint8_t((i * 73 + (i >> 8) * 19) & 255);
                        textureIndex(source, 0);
                        gs.writeRegister(GS_REG_TEST_1, (1ull << 16) | (1ull << 17) | 1ull |
                                                            (uint64_t(afail) << 12));
                        triangle(alias == 2 ? 36 : 4, 64, 0x80543210, linear != 0);
                        triangle(alias == 2 ? 36 : 4, 128, 0x80705030, linear != 0);
                        report("live-all-format-afail-parity", source, format, afail,
                               alias * 2 + linear, true);
                    }
    // Index texture feedback remains live even when palette colors are safe.
    // Output changes future T4 nibbles/T8 bytes; a decoded-index cache would fail
    // off/on VRAM parity despite having a disjoint CLUT.
    for (unsigned source : sources)
        for (unsigned format = 0; format < 4; ++format)
            for (unsigned alias = 0; alias < 2; ++alias)
                for (unsigned linear = 0; linear < 2; ++linear) {
                    setup(source, GS_PSM_CT32, 0, 0, Palette, 1, 0, 0, formats[format], 0, 4,
                          depthFormats[format], false);
                    for (size_t i = 0; i < vram.size(); ++i)
                        vram[i] = uint8_t((i * 73 + (i >> 8) * 19) & 255);
                    gs.writeRegister(GS_REG_TEX0_1, (alias ? 128 : 0) | (1ull << 14) |
                                                        (uint64_t(source) << 20) | (6ull << 26) |
                                                        (6ull << 30) | (1ull << 34) | (1ull << 35) |
                                                        (uint64_t(Palette) << 37));
                    triangle(4, 64, 0x80543210, linear != 0);
                    triangle(4, 128, 0x80705030, linear != 0);
                    report("live-index-texture-parity", source, format, alias, linear, true);
                }
    if (std::getenv("REO_GS_PALETTE_BENCH")) {
        for (unsigned source : sources)
            for (unsigned linear = 0; linear < 2; ++linear) {
                setup(source, GS_PSM_CT32, 0, 0, Palette, 1, 0, 0);
                textureIndex(source, 8);
                store(GSPSMCT32::addrPSMCT32(Palette, 1, 0, 1), 0x80705030);
                const auto start = std::chrono::steady_clock::now();
                for (unsigned n = 0; n < 512; ++n)
                    triangle(4, 128, 101, linear != 0);
                const auto us = std::chrono::duration_cast<std::chrono::microseconds>(
                                    std::chrono::steady_clock::now() - start)
                                    .count();
                std::printf("BENCH source=%u linear=%u triangles=512 us=%lld hash=%016llx\n",
                            source, linear, static_cast<long long>(us),
                            static_cast<unsigned long long>(hash(vram)));
            }
    }
    std::printf("triangle_palette_checks=%u failures=%u\n", checks, failures);
    return failures ? 1 : 0;
}

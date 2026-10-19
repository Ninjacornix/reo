// Production sampler, coordinate-coded VRAM, independent expected coordinates.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmt4.h"
#include "runtime/ps2_gs_psmt8.h"
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
constexpr unsigned textureBlock = 4096;
constexpr unsigned t4Block = 8192, t8Block = 12288, paletteBlock = 15360;
uint32_t bits(float f) {
    uint32_t v;
    std::memcpy(&v, &f, 4);
    return v;
}
uint32_t color(unsigned x, unsigned y) {
    return (7 + x * 3) | ((9 + y * 3) << 8) | ((11 + x + y) << 16) | 0x80000000u;
}
uint32_t sampledColor(unsigned format, unsigned x, unsigned y) {
    if (!format)
        return color(x, y);
    const unsigned index = (x + 3 * y) & (format == 1 ? 255 : 15);
    return color(index % 64, index / 64);
}
uint64_t clampReg(unsigned u, unsigned v, unsigned minU = 2, unsigned maxU = 5, unsigned minV = 3,
                  unsigned maxV = 6) {
    return u | (uint64_t(v) << 2) | (uint64_t(minU) << 4) | (uint64_t(maxU) << 14) |
           (uint64_t(minV) << 24) | (uint64_t(maxV) << 34);
}
// Explicit cases are not a second copy of the production mode resolver.
struct Case {
    const char* name;
    unsigned um, vm, umin, umax, vmin, vmax;
    float u, v;
    int u0, u1, v0, v1;
};
constexpr Case cases[]{
    {"repeat positive", 0, 0, 0, 0, 0, 0, 10, 11, 1, 2, 2, 3},
    {"repeat negative", 0, 0, 0, 0, 0, 0, -1, -2, 6, 7, 5, 6},
    {"clamp positive", 1, 1, 0, 0, 0, 0, 10, 11, 7, 7, 7, 7},
    {"clamp negative", 1, 1, 0, 0, 0, 0, -1, -2, 0, 0, 0, 0},
    {"region clamp low", 2, 2, 2, 5, 3, 6, -1, -2, 2, 2, 3, 3},
    {"region clamp high", 2, 2, 2, 5, 3, 6, 10, 11, 5, 5, 6, 6},
    {"region clamp beyond TW", 2, 2, 12, 15, 20, 23, 10, 30, 12, 12, 23, 23},
    {"region repeat", 3, 3, 3, 16, 5, 32, 10, 11, 17, 18, 32, 33},
    {"region repeat negative", 3, 3, 3, 16, 5, 32, -1, -2, 18, 19, 37, 36},
    {"repeat U clamp V", 0, 1, 0, 0, 0, 0, 10, -2, 1, 2, 0, 0},
    {"region clamp U repeat V", 2, 0, 12, 15, 0, 0, 10, 11, 12, 12, 2, 3},
    {"repeat U region repeat V", 0, 3, 0, 0, 5, 32, 10, 11, 1, 2, 32, 33},
};
uint32_t average(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t result = 0;
    for (unsigned shift = 0; shift < 32; shift += 8) {
        const unsigned total = ((a >> shift) & 255) + ((b >> shift) & 255) + ((c >> shift) & 255) +
                               ((d >> shift) & 255);
        result |= ((total + 2) / 4) << shift;
    }
    return result;
}
} // namespace

int main() {
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    GSRegisters regs{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &regs);
    for (unsigned y = 0; y < 64; ++y)
        for (unsigned x = 0; x < 64; ++x) {
            const uint32_t value = color(x, y);
            std::memcpy(vram.data() + GSPSMCT32::addrPSMCT32(textureBlock, 1, x, y), &value, 4);
            vram[GSPSMT8::addrPSMT8(t8Block, 1, x, y)] = uint8_t((x + 3 * y) & 255);
            const unsigned nibble = GSPSMT4::addrPSMT4(t4Block, 1, x, y), shift = (nibble & 1) * 4;
            auto& packed = vram[nibble / 2];
            packed = uint8_t((packed & ~(15u << shift)) | (((x + 3 * y) & 15) << shift));
        }
    for (unsigned index = 0; index < 256; ++index) {
        const uint32_t value = color(index % 64, index / 64);
        std::memcpy(vram.data() + GSPSMCT32::addrPSMCT32(paletteBlock, 1, index % 16, index / 16),
                    &value, 4);
    }
    gs.writeRegister(GS_REG_FRAME_1, 1ull << 16);
    gs.writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (63ull << 48));
    gs.writeRegister(GS_REG_XYOFFSET_1, 0);
    gs.writeRegister(GS_REG_TEST_1, 0);
    gs.writeRegister(GS_REG_ZBUF_1, 1ull << 32);
    unsigned checks = 0, failed = 0;
    for (unsigned format = 0; format < 3; ++format)
        for (const auto& c : cases)
            for (unsigned linear = 0; linear < 2; ++linear)
                for (unsigned fst = 0; fst < 2; ++fst) {
                    if (fst && (c.u < 0 || c.v < 0))
                        continue;
                    const unsigned block = format == 0   ? textureBlock
                                           : format == 1 ? t8Block
                                                         : t4Block;
                    const unsigned psm = format == 0   ? GS_PSM_CT32
                                         : format == 1 ? GS_PSM_T8
                                                       : GS_PSM_T4;
                    gs.writeRegister(GS_REG_TEX0_1,
                                     block | (1ull << 14) | (uint64_t(psm) << 20) | (3ull << 26) |
                                         (3ull << 30) | (1ull << 34) | (1ull << 35) |
                                         (uint64_t(paletteBlock) << 37) | (1ull << 55));
                    gs.writeRegister(GS_REG_CLAMP_1,
                                     clampReg(c.um, c.vm, c.umin, c.umax, c.vmin, c.vmax));
                    gs.writeRegister(GS_REG_TEX1_1, linear ? 0x60 : 0);
                    gs.writeRegister(GS_REG_PRIM,
                                     GS_PRIM_TRIANGLE | (1u << 4) | (fst ? 1u << 8 : 0));
                    const auto fb = GSPSMCT32::addrPSMCT32(0, 1, 4, 4);
                    uint32_t zero = 0;
                    std::memcpy(vram.data() + fb, &zero, 4);
                    const float u = linear ? c.u : c.u - .25f, v = linear ? c.v : c.v - .25f;
                    for (const auto& xy :
                         std::array<std::array<unsigned, 2>, 3>{{{0, 0}, {16, 0}, {0, 16}}}) {
                        gs.writeRegister(GS_REG_RGBAQ, 0x80808080ull | (uint64_t(bits(1)) << 32));
                        gs.writeRegister(GS_REG_ST, bits(u / 8) | (uint64_t(bits(v / 8)) << 32));
                        if (fst)
                            gs.writeRegister(GS_REG_UV,
                                             unsigned(u * 16) | (uint64_t(unsigned(v * 16)) << 16));
                        gs.writeRegister(GS_REG_XYZ2, xy[0] * 16 | (uint64_t(xy[1] * 16) << 16));
                    }
                    const uint32_t expected = linear ? average(sampledColor(format, c.u0, c.v0),
                                                               sampledColor(format, c.u1, c.v0),
                                                               sampledColor(format, c.u0, c.v1),
                                                               sampledColor(format, c.u1, c.v1))
                                                     : sampledColor(format, c.u0, c.v0);
                    uint32_t actual;
                    std::memcpy(&actual, vram.data() + fb, 4);
                    ++checks;
                    if (actual != expected) {
                        ++failed;
                        std::printf("FAIL %s format=%u linear=%u fst=%u got=%08x expected=%08x\n",
                                    c.name, format, linear, fst, actual, expected);
                    }
                }
    // CT32 1:1 sprite shortcut must obey the same modes, including reverse UV.
    gs.writeRegister(GS_REG_TEX0_1, textureBlock | (1ull << 14) | (3ull << 26) | (3ull << 30) |
                                        (1ull << 34) | (1ull << 35));
    for (unsigned mode = 0; mode < 4; ++mode)
        for (unsigned linear = 0; linear < 2; ++linear)
            for (unsigned reverse = 0; reverse < 2; ++reverse) {
                gs.writeRegister(GS_REG_CLAMP_1, clampReg(mode, mode, 3, 16, 5, 32));
                gs.writeRegister(GS_REG_TEX1_1, linear ? 0x60 : 0);
                gs.writeRegister(GS_REG_PRIM, GS_PRIM_SPRITE | (1u << 4) | (1u << 8));
                for (unsigned i = 0; i < 2; ++i) {
                    const unsigned uv = reverse ? (i ? 8 : 16) : (i ? 16 : 8);
                    gs.writeRegister(GS_REG_RGBAQ, 0x80808080ull | (uint64_t(bits(1)) << 32));
                    gs.writeRegister(GS_REG_UV, uv * 16 | (uint64_t(uv * 16) << 16));
                    gs.writeRegister(GS_REG_XYZ2,
                                     (8 + i * 8) * 16 | (uint64_t((8 + i * 8) * 16) << 16));
                }
                bool passed = true;
                for (unsigned y = 0; y < 8; ++y)
                    for (unsigned x = 0; x < 8; ++x) {
                        unsigned tx = reverse ? 15 - x : 8 + x, ty = reverse ? 15 - y : 8 + y;
                        // Finite explicit ranges for this shortcut control.
                        if (mode == 0) {
                            tx %= 8;
                            ty %= 8;
                        }
                        if (mode == 1) {
                            tx = 7;
                            ty = 7;
                        }
                        if (mode == 2) {
                            tx = tx < 3 ? 3 : tx > 16 ? 16 : tx;
                            ty = ty < 5 ? 5 : ty > 32 ? 32 : ty;
                        }
                        if (mode == 3) {
                            tx = (tx & 3) | 16;
                            ty = (ty & 5) | 32;
                        }
                        uint32_t actual;
                        std::memcpy(&actual,
                                    vram.data() + GSPSMCT32::addrPSMCT32(0, 1, 8 + x, 8 + y), 4);
                        passed &= actual == color(tx, ty);
                    }
                ++checks;
                if (!passed) {
                    ++failed;
                    std::printf("FAIL sprite mode=%u linear=%u reverse=%u\n", mode, linear,
                                reverse);
                }
            }
    // Region coordinates beyond TW/TH reach writable source pages: preserve
    // sequential feedback, including the next 32-row page at the right edge.
    // The old declared-size page proof incorrectly permits row workers here.
    for (size_t i = 0; i < vram.size(); ++i)
        vram[i] = uint8_t((i * 73 + (i >> 9) * 19) & 255);
    auto expectedVram = vram;
    for (unsigned y = 0; y < 128; ++y)
        for (unsigned x = 0; x < 256; ++x) {
            uint32_t value;
            std::memcpy(&value, expectedVram.data() + GSPSMCT32::addrPSMCT32(0, 4, x, y), 4);
            std::memcpy(expectedVram.data() + GSPSMCT32::addrPSMCT32(32, 4, x, y), &value, 4);
        }
    gs.writeRegister(GS_REG_FRAME_1, 1ull | (4ull << 16));
    gs.writeRegister(GS_REG_SCISSOR_1, (255ull << 16) | (127ull << 48));
    gs.writeRegister(GS_REG_TEX0_1,
                     (4ull << 14) | (3ull << 26) | (3ull << 30) | (1ull << 34) | (1ull << 35));
    gs.writeRegister(GS_REG_CLAMP_1, clampReg(2, 2, 0, 255, 0, 127));
    gs.writeRegister(GS_REG_TEX1_1, 0);
    gs.writeRegister(GS_REG_PRIM, GS_PRIM_SPRITE | (1u << 4) | (1u << 8));
    for (unsigned i = 0; i < 2; ++i) {
        gs.writeRegister(GS_REG_RGBAQ, 0x80808080ull | (uint64_t(bits(1)) << 32));
        gs.writeRegister(GS_REG_UV, i * 256 * 16 | (uint64_t(i * 128 * 16) << 16));
        gs.writeRegister(GS_REG_XYZ2, i * 256 * 16 | (uint64_t(i * 128 * 16) << 16));
    }
    ++checks;
    if (vram != expectedVram) {
        ++failed;
        std::puts("FAIL large region sprite retains sequential alias feedback");
    }
    std::printf("CLAMP checks=%u passed=%u failed=%u\n", checks, checks - failed, failed);
    return failed ? 1 : 0;
}

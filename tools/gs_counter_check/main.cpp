// Run in separate processes with REO_GS_TRI_PARALLEL=0/1. --dump writes every
// complete VRAM image; compare.py requires exact bytes, not screenshot hashes.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmct16.h"
#include "runtime/ps2_gs_psmt8.h"
#include "runtime/ps2_gs_psmt4.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>
#include <string>
#include <vector>

extern std::atomic<uint32_t> g_pxCalls, g_pxScissor, g_pxAlpha;
namespace {
constexpr uint32_t Old = 0x80604820, New = 0x80543210;
constexpr unsigned X = 64, Y = 64;
uint32_t bits(float f) {
    uint32_t u;
    std::memcpy(&u, &f, 4);
    return u;
}
uint16_t pack16(uint32_t c) {
    return uint16_t(((c & 255) >> 3) | ((((c >> 8) & 255) >> 3) << 5) |
                    ((((c >> 16) & 255) >> 3) << 10) | (((c >> 24) >= 128) ? 0x8000 : 0));
}
uint64_t hash(const std::vector<uint8_t>& v) {
    uint64_t h = 14695981039346656037ull;
    for (auto b : v)
        h = (h ^ b) * 1099511628211ull;
    return h;
}
uint32_t colorAddress(unsigned block, unsigned width, unsigned format, unsigned x, unsigned y) {
    if (format == GS_PSM_CT16)
        return GSPSMCT16::addrPSMCT16(block, width, x, y);
    if (format == GS_PSM_CT16S)
        return GSPSMCT16::addrPSMCT16S(block, width, x, y);
    return GSPSMCT32::addrPSMCT32(block, width, x, y);
}
uint32_t zAddress(unsigned page, unsigned width, unsigned format, unsigned x, unsigned y) {
    if (format == 2)
        return GSPSMCT16::addrPSMZ16(page * 32, width, x, y) % PS2_GS_VRAM_SIZE;
    if (format == 10)
        return GSPSMCT16::addrPSMZ16S(page * 32, width, x, y) % PS2_GS_VRAM_SIZE;
    const unsigned block = GSPSMCT32::blockTable32[(y / 8) & 3][(x / 8) & 7] ^ 24;
    return ((page + (y / 32) * width + x / 64) * 8192 + block * 256 +
            GSPSMCT32::columnTable32[y & 7][x & 7] * 4) %
           PS2_GS_VRAM_SIZE;
}
unsigned clutIndex(unsigned index, unsigned source, unsigned csm, unsigned csa) {
    unsigned i = source == GS_PSM_T4 ? csa * 16 + (index & 15) : index;
    if (!csm)
        i = (i & 0xE7) | ((i & 8) << 1) | ((i & 16) >> 1);
    return i;
}
struct Case {
    std::string name;
    unsigned source = GS_PSM_CT32, frame = GS_PSM_CT32, fbp = 0, fbw = 4, zbp = 64, zformat = 0;
    unsigned tbp = 4096, tbw = 2, cbp = 8192, cpsm = GS_PSM_CT32, csm = 0, csa = 0, cbw = 1,
             cou = 0, cov = 0;
    bool textured = true, fst = false, linear = false, reverse = false, blend = false,
         zmask = false, iip = true, tcc = true;
    bool oracle = true, sequence = false, coordinate = false, varyDepth = false, warm = true;
    uint64_t test = (1ull << 16) | (2ull << 17), clamp = 5;
    uint32_t frameMask = 0, expected = New, expectedDepth = 200;
    unsigned alpha = 128, fba = 0, pabe = 0, qmode = 0, ybase = 4, limit = 255, xmin = 0, ymin = 0;
};
} // namespace

int main(int argc, char** argv) {
    const char* dumpPath = nullptr;
    unsigned bench = 0;
    for (int i = 1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "--dump") && i + 1 < argc)
            dumpPath = argv[++i];
        else if (!std::strcmp(argv[i], "--bench") && i + 1 < argc)
            bench = unsigned(std::strtoul(argv[++i], nullptr, 10));
        else {
            std::fprintf(stderr,
                         "Usage: gs_triangle_parallel_check [--dump file] [--bench count]\n");
            return 2;
        }
    }
    _putenv("REO_GS_THREAD=0");
    std::ofstream dump;
    if (dumpPath) {
        dump.open(dumpPath, std::ios::binary);
        if (!dump)
            return 2;
    }
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    GSRegisters registers{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &registers);
    unsigned checks = 0, failures = 0, caseIndex = 0;
    auto store = [&](unsigned off, uint32_t color, unsigned bytes = 4) {
        if (uint64_t(off) + bytes <= vram.size())
            std::memcpy(vram.data() + off, &color, bytes);
    };
    auto read = [&](unsigned off, unsigned bytes = 4) {
        uint32_t v = 0;
        if (uint64_t(off) + bytes <= vram.size())
            std::memcpy(&v, vram.data() + off, bytes);
        return v;
    };
    auto check = [&](const std::string& name, bool ok) {
        ++checks;
        failures += !ok;
        if (!ok)
            std::printf("FAIL oracle %s\n", name.c_str());
    };
    auto indexed = [&](unsigned source, unsigned tbp, unsigned tbw, unsigned x, unsigned y,
                       unsigned index) {
        if (source == GS_PSM_T8) {
            unsigned off = GSPSMT8::addrPSMT8(tbp, tbw, x, y);
            if (off < vram.size())
                vram[off] = uint8_t(index);
        } else {
            unsigned n = GSPSMT4::addrPSMT4(tbp, tbw ? tbw : 1, x, y), off = n / 2,
                     shift = (n & 1) * 4;
            if (off < vram.size())
                vram[off] = uint8_t((vram[off] & ~(15 << shift)) | ((index & 15) << shift));
        }
    };
    // Exercise the actual existing sprite row pool first. Its workers retain
    // a different palette in TLS; triangle workers must not reuse those colors.
    auto warmWorkers = [&] {
        gs.writeRegister(GS_REG_FRAME_1, 256 | (4ull << 16));
        gs.writeRegister(GS_REG_SCISSOR_1, (255ull << 16) | (255ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, 0);
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PABE, 0);
        gs.writeRegister(GS_REG_TEXCLUT, 1);
        gs.writeRegister(GS_REG_TEX0_1, 14000 | (2ull << 14) | (uint64_t(GS_PSM_T8) << 20) |
                                            (6ull << 26) | (6ull << 30) | (1ull << 34) |
                                            (1ull << 35) | (12000ull << 37));
        gs.writeRegister(GS_REG_TEX1_1, 0);
        gs.writeRegister(GS_REG_CLAMP_1, 5);
        for (unsigned i = 0; i < 256; ++i)
            store(GSPSMCT32::addrPSMCT32(12000, 1, i & 15, i / 16), 0x80775533);
        for (unsigned y = 0; y < 64; ++y)
            for (unsigned x = 0; x < 64; ++x)
                indexed(GS_PSM_T8, 14000, 2, x, y, 8);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_SPRITE | (1u << 4) | (1u << 8));
        gs.writeRegister(GS_REG_RGBAQ, 0x3f80000080808080ull);
        gs.writeRegister(GS_REG_UV, 52 | (84ull << 16));
        gs.writeRegister(GS_REG_XYZ2, 4 * 16 | (4ull * 16 << 16));
        gs.writeRegister(GS_REG_XYZ2, 252 * 16 | (252ull * 16 << 16));
    };
    auto setup = [&](const Case& c) {
        if (c.warm && (c.source == GS_PSM_T4 || c.source == GS_PSM_T8))
            warmWorkers();
        for (size_t i = 0; i < vram.size(); ++i)
            vram[i] = uint8_t((i * 29 + (i >> 8) * 7 + 17) & 255);
        const unsigned fw = c.fbw ? c.fbw : 1;
        for (unsigned y = 0; y < 256; ++y)
            for (unsigned x = 0; x < 256; ++x) {
                const bool sixteen = c.frame == GS_PSM_CT16 || c.frame == GS_PSM_CT16S;
                store(colorAddress(c.fbp * 32, fw, c.frame, x, y), sixteen ? pack16(Old) : Old,
                      sixteen ? 2 : 4);
                store(zAddress(c.zbp, fw, c.zformat, x, y), c.zformat == 1 ? 0x7e000064 : 100,
                      c.zformat == 2 || c.zformat == 10 ? 2 : 4);
            }
        if (c.textured) {
            for (unsigned y = 0; y < 256; ++y)
                for (unsigned x = 0; x < 256; ++x) {
                    if (c.source == GS_PSM_T4 || c.source == GS_PSM_T8)
                        indexed(c.source, c.tbp, c.tbw, x, y, 8);
                    else {
                        const bool sixteen = c.source == GS_PSM_CT16 || c.source == GS_PSM_CT16S;
                        const uint32_t raw =
                            c.coordinate ? (0x80000000 | (x & 63) | ((y & 63) << 8) | (0x30u << 16))
                            : sixteen    ? 0xca93
                                         : New;
                        store(colorAddress(c.tbp, c.tbw ? c.tbw : 1, c.source, x, y), raw,
                              sixteen ? 2 : 4);
                    }
                }
            if (c.source == GS_PSM_T4 || c.source == GS_PSM_T8) {
                const bool sixteen = c.cpsm == GS_PSM_CT16 || c.cpsm == GS_PSM_CT16S;
                const unsigned entries = c.source == GS_PSM_T4 ? 16 : 256;
                for (unsigned i = 0; i < entries; ++i) {
                    unsigned ci = clutIndex(i, c.source, c.csm, c.csa);
                    store(colorAddress(c.cbp, c.cbw ? c.cbw : 1, c.cpsm, c.cou + (ci & 15),
                                       c.cov + ci / 16),
                          sixteen ? 0xca93 : New, sixteen ? 2 : 4);
                }
            }
        }
        gs.writeRegister(GS_REG_FRAME_1, c.fbp | (uint64_t(c.fbw) << 16) |
                                             (uint64_t(c.frame) << 24) |
                                             (uint64_t(c.frameMask) << 32));
        gs.writeRegister(GS_REG_SCISSOR_1, c.xmin | (uint64_t(c.limit) << 16) |
                                               (uint64_t(c.ymin) << 32) |
                                               (uint64_t(c.limit) << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, c.test);
        gs.writeRegister(GS_REG_ZBUF_1,
                         c.zbp | (uint64_t(c.zformat) << 24) | (uint64_t(c.zmask) << 32));
        gs.writeRegister(GS_REG_ALPHA_1, 0x44);
        gs.writeRegister(GS_REG_FBA_1, c.fba);
        gs.writeRegister(GS_REG_PABE, c.pabe);
        gs.writeRegister(GS_REG_TEX0_1, c.tbp | (uint64_t(c.tbw) << 14) |
                                            (uint64_t(c.source) << 20) | (6ull << 26) |
                                            (6ull << 30) | (uint64_t(c.tcc) << 34) | (1ull << 35) |
                                            (uint64_t(c.cbp) << 37) | (uint64_t(c.cpsm) << 51) |
                                            (uint64_t(c.csm) << 55) | (uint64_t(c.csa) << 56));
        gs.writeRegister(GS_REG_TEXCLUT, c.cbw | (uint64_t(c.cou) << 6) | (uint64_t(c.cov) << 12));
        gs.writeRegister(GS_REG_TEXA, 0x8000000020ull);
        gs.writeRegister(GS_REG_TEX1_1, c.linear ? 0x60 : 0);
        gs.writeRegister(GS_REG_CLAMP_1, c.clamp);
    };
    auto triangle = [&](const Case& c, unsigned depth = 200) {
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_TRIANGLE | (uint64_t(c.iip) << 3) |
                                          (uint64_t(c.textured) << 4) | (uint64_t(c.blend) << 6) |
                                          (uint64_t(c.fst) << 8));
        const unsigned order[]{0, c.reverse ? 2u : 1u, c.reverse ? 1u : 2u};
        const unsigned xs[]{4, 252, 4}, ys[]{c.ybase, c.ybase, c.ybase + 248};
        for (unsigned k = 0; k < 3; ++k) {
            unsigned i = order[k];
            float q = float(1u << i);
            if (c.qmode == 1)
                q = -q;
            if (c.qmode == 2 && i == 1)
                q = -q;
            if (c.qmode == 3)
                q = std::numeric_limits<float>::quiet_NaN();
            const unsigned u = c.coordinate ? (i == 1 ? 52 * 16 : 4 * 16) : 52,
                           v = c.coordinate ? (i == 2 ? 52 * 16 : 4 * 16) : 84;
            const float s = c.coordinate ? float(u) / 1024 : 3.25f / 64,
                        t = c.coordinate ? float(v) / 1024 : 5.25f / 64;
            gs.writeRegister(GS_REG_RGBAQ,
                             0x00808080ull | (uint64_t(c.alpha) << 24) | (uint64_t(bits(q)) << 32));
            gs.writeRegister(GS_REG_ST, bits(c.qmode == 3 ? s : s * q) |
                                            (uint64_t(bits(c.qmode == 3 ? t : t * q)) << 32));
            gs.writeRegister(GS_REG_UV, u | (uint64_t(v) << 16));
            const unsigned z = c.varyDepth ? depth + i * 248 : depth;
            gs.writeRegister(GS_REG_XYZ2,
                             xs[i] * 16 | (uint64_t(ys[i] * 16) << 16) | (uint64_t(z) << 32));
        }
    };
    auto run = [&](const Case& c) {
        setup(c);
        g_pxCalls.store(0xFFFFFFF0u);
        g_pxScissor.store(0xFFFFFFF0u);
        g_pxAlpha.store(0xFFFFFFF0u);
        triangle(c);
        if (c.sequence)
            triangle(c, 300);
        std::printf("COUNTERS %u %s %u %u %u\n", caseIndex, c.name.c_str(), g_pxCalls.load(),
                    g_pxScissor.load(), g_pxAlpha.load());
        const uint32_t actual = read(colorAddress(c.fbp * 32, c.fbw ? c.fbw : 1, c.frame, X, Y));
        const uint32_t z = read(zAddress(c.zbp, c.fbw ? c.fbw : 1, c.zformat, X, Y));
        if (c.oracle) {
            check(c.name + " color", actual == c.expected);
            check(c.name + " depth",
                  z == (c.zformat == 1 ? (0x7e000000 | c.expectedDepth) : c.expectedDepth));
        }
        std::printf("CASE %u %s hash=%016llx color=%08x depth=%08x oracle=%u\n", caseIndex++,
                    c.name.c_str(), static_cast<unsigned long long>(hash(vram)), actual, z,
                    unsigned(c.oracle));
        if (dump.is_open()) {
            dump.write(reinterpret_cast<const char*>(vram.data()), std::streamsize(vram.size()));
            if (!dump) {
                ++failures;
            }
        }
    };
    constexpr unsigned sources[]{GS_PSM_CT32,  GS_PSM_CT24, GS_PSM_CT16,
                                 GS_PSM_CT16S, GS_PSM_T4,   GS_PSM_T8};
    for (unsigned source : sources)
        for (unsigned fixed = 0; fixed < 2; ++fixed)
            for (unsigned linear = 0; linear < 2; ++linear) {
                Case c;
                c.name = "format-" + std::to_string(source) + "-fst-" + std::to_string(fixed) +
                         "-linear-" + std::to_string(linear);
                c.source = source;
                c.fst = fixed != 0;
                c.linear = linear != 0;
                c.reverse = (source + fixed + linear) & 1;
                c.expected = source == GS_PSM_CT24                             ? 0x20543210
                             : source == GS_PSM_CT16 || source == GS_PSM_CT16S ? 0x8090a098
                                                                               : New;
                run(c);
            }
    for (unsigned source : {unsigned(GS_PSM_T4), unsigned(GS_PSM_T8)})
        for (unsigned format : {unsigned(GS_PSM_CT32), unsigned(GS_PSM_CT24), unsigned(GS_PSM_CT16),
                                unsigned(GS_PSM_CT16S)})
            for (unsigned csm = 0; csm < 2; ++csm) {
                Case c;
                c.name = "clut-" + std::to_string(source) + "-" + std::to_string(format) + "-csm-" +
                         std::to_string(csm);
                c.source = source;
                c.cpsm = format;
                c.csm = csm;
                c.csa = 31;
                c.cou = 17;
                c.cov = 37;
                c.cbw = 2;
                c.linear = true;
                c.expected = format == GS_PSM_CT24                             ? 0x20543210
                             : format == GS_PSM_CT16 || format == GS_PSM_CT16S ? 0x8090a098
                                                                               : New;
                run(c);
            }
    for (unsigned mode = 0; mode < 4; ++mode) {
        Case c;
        c.name = "clamp-mode-" + std::to_string(mode);
        c.linear = true;
        c.clamp = mode | (uint64_t(mode) << 2) | (31ull << 4) | (128ull << 14) | (31ull << 24) |
                  (128ull << 34);
        run(c);
    }
    {
        Case c;
        c.name = "negative-q";
        c.qmode = 1;
        run(c);
    }
    {
        Case c;
        c.name = "clipped-scissor";
        c.xmin = 32;
        c.ymin = 32;
        c.limit = 200;
        run(c);
    }
    {
        Case c;
        c.name = "nontextured";
        c.textured = false;
        c.iip = false;
        c.expected = 0x80808080;
        run(c);
    }
    {
        Case c;
        c.name = "coordinate-stq";
        c.coordinate = true;
        c.oracle = false;
        run(c);
    }
    {
        Case c;
        c.name = "varying-z";
        c.varyDepth = true;
        c.expectedDepth = 381;
        run(c);
    }
    {
        Case c;
        c.name = "sequential-primitives";
        c.sequence = true;
        c.expectedDepth = 300;
        run(c);
    }
    {
        Case c;
        c.name = "z24-high-byte";
        c.zformat = 1;
        run(c);
    }
    {
        Case c;
        c.name = "frame24";
        c.frame = GS_PSM_CT24;
        run(c);
    }
    {
        Case c;
        c.name = "zmask";
        c.zmask = true;
        c.expectedDepth = 100;
        run(c);
    }
    {
        Case c;
        c.name = "z-never-fallback";
        c.test = 1ull << 16;
        c.expected = Old;
        c.expectedDepth = 100;
        run(c);
    }
    {
        Case c;
        c.name = "z-greater-pass";
        c.test = (1ull << 16) | (3ull << 17);
        run(c);
    }
    {
        Case c;
        c.name = "date-pass";
        c.test |= (1ull << 14) | (1ull << 15);
        run(c);
    }
    {
        Case c;
        c.name = "date-reject";
        c.test |= 1ull << 14;
        c.expected = Old;
        c.expectedDepth = 100;
        run(c);
    }
    {
        Case c;
        c.name = "blend-half";
        c.blend = true;
        c.iip = false;
        c.tcc = false;
        c.alpha = 64;
        c.expected = 0x405a3d18;
        run(c);
    }
    {
        Case c;
        c.name = "frame-mask";
        c.frameMask = 0x00ff0000;
        c.expected = 0x80603210;
        run(c);
    }
    {
        Case c;
        c.name = "frame-fully-masked";
        c.frameMask = ~0u;
        c.expected = Old;
        run(c);
    }
    for (unsigned fail = 0; fail < 4; ++fail) {
        Case c;
        c.name = "afail-" + std::to_string(fail);
        c.source = GS_PSM_CT24;
        c.test |= 1 | (uint64_t(fail) << 12);
        c.expected = fail == 0 || fail == 2 ? Old : fail == 3 ? 0x80543210 : 0x20543210;
        c.expectedDepth = fail == 1 || fail == 3 ? 100 : fail == 0 ? 100 : 200;
        run(c);
    }
    // All of these must retain live serial reads. Include aliases where the
    // palette's origin, region addressing or wrapped depth moves the hazard.
    for (unsigned variant = 0; variant < 12; ++variant) {
        Case c;
        c.oracle = false;
        c.name = "fallback-" + std::to_string(variant);
        switch (variant) {
            case 0:
                c.zbp = 0;
                break; // FB(32,16) aliases Z(0,0).
            case 1:
                c.fbw = 1;
                break; // FB(64,0) aliases FB(0,32).
            case 2:
                c.zbp = 508;
                break;
            case 3:
                c.tbp = 0;
                break;
            case 4:
                c.tbp = 64 * 32;
                break;
            case 5:
                c.source = GS_PSM_T8;
                c.cbp = 0;
                break;
            case 6:
                c.source = GS_PSM_T4;
                c.cbp = 64 * 32;
                break;
            case 7:
                c.source = GS_PSM_T8;
                c.fbp = 32;
                c.zbp = 96;
                c.cbp = 0;
                c.cov = 1023;
                break;
            case 8:
                c.source = GS_PSM_T8;
                c.cbp = 32 * 32;
                c.cov = 1023;
                break;
            case 9:
                c.frame = GS_PSM_CT16S;
                break;
            case 10:
                c.zformat = 2;
                break;
            case 11:
                c.qmode = 2;
                break;
        }
        run(c);
    }
    {
        Case c;
        c.name = "nonfinite-q-fallback";
        c.qmode = 3;
        c.oracle = false;
        run(c);
    }
    {
        Case c;
        c.name = "unaligned-texture-base";
        c.tbp += 31;
        run(c);
    }
    {
        Case c;
        c.name = "region-texture-frame-alias";
        c.tbp = 0;
        c.clamp = 3 | (3ull << 2) | (31ull << 4) | (128ull << 14) | (31ull << 24) | (128ull << 34);
        c.oracle = false;
        run(c);
    }
    // Coordinate-coded STQ has an independent analytic check at an interior
    // pixel: w1=w2=60.5/248, Q=w0+2w1+4w2, U=(4w0+104w1+16w2)/Q.
    {
        Case c;
        c.name = "coordinate-stq-oracle";
        c.coordinate = true;
        c.oracle = false;
        setup(c);
        triangle(c);
        const double w = 60.5 / 248, w0 = 1 - 2 * w, q = w0 + 2 * w + 4 * w;
        const unsigned u = unsigned(std::floor((4 * w0 + 104 * w + 16 * w) / q));
        const unsigned v = unsigned(std::floor((4 * w0 + 8 * w + 208 * w) / q));
        check(c.name, read(colorAddress(0, 4, 0, X, Y)) == (0x80300000 | u | (v << 8)));
    }
    // Independent atomic fallback controls outside triangle-band scope.
    {
        Case c;
        c.textured = false;
        setup(c);
        g_pxCalls.store(0);
        g_pxScissor.store(0);
        g_pxAlpha.store(0);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_POINT);
        gs.writeRegister(GS_REG_RGBAQ, New | (uint64_t(bits(1.0f)) << 32));
        gs.writeRegister(GS_REG_XYZ2, (64ull * 16) | ((64ull * 16) << 16) | (200ull << 32));
        check("point fallback counters",
              g_pxCalls.load() == 1 && g_pxScissor.load() == 0 && g_pxAlpha.load() == 0);
        gs.writeRegister(GS_REG_XYZ2, (1023ull * 16) | ((1023ull * 16) << 16) | (200ull << 32));
        check("point outside scissor counters", g_pxCalls.load() == 2 && g_pxScissor.load() == 1);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_LINE);
        gs.writeRegister(GS_REG_XYZ2, (64ull * 16) | ((64ull * 16) << 16) | (200ull << 32));
        gs.writeRegister(GS_REG_XYZ2, (67ull * 16) | ((64ull * 16) << 16) | (200ull << 32));
        check("line fallback counters", g_pxCalls.load() == 6 && g_pxScissor.load() == 1);
    }
    if (bench) {
        Case c;
        c.name = "benchmark";
        c.source = GS_PSM_T8;
        c.linear = true;
        setup(c);
        const auto start = std::chrono::steady_clock::now();
        for (unsigned i = 0; i < bench; ++i)
            triangle(c);
        const auto us = std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::steady_clock::now() - start)
                            .count();
        std::printf("BENCH triangles=%u us=%lld hash=%016llx\n", bench, static_cast<long long>(us),
                    static_cast<unsigned long long>(hash(vram)));
    }
    std::printf("cases=%u independent_checks=%u failures=%u parallel=%s\n", caseIndex, checks,
                failures,
                std::getenv("REO_GS_TRI_PARALLEL") ? std::getenv("REO_GS_TRI_PARALLEL") : "unset");
    return failures ? 1 : 0;
}

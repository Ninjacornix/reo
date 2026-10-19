// Include the frozen selected source so no public GS or rasterizer ABI changes
// are needed. The stop facade latches at a pixel-count boundary and exercises
// the unchanged row/pool stop guards without a timing-dependent shutdown race.
#include <atomic>
#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include "runtime/ps2_memory.h"
bool spriteFixtureStopRequested();
#define ps2GsWorkerStopRequested spriteFixtureStopRequested
#include "selected_source.cpp"
#undef ps2GsWorkerStopRequested

namespace {
std::atomic<bool> fixtureStop{false}, stopEnabled{false};
std::atomic<uint32_t> stopAt{0};
constexpr uint32_t Old = 0x80604820u, New = 0x80543210u;
constexpr size_t VramSize = PS2_GS_VRAM_SIZE;
uint64_t hash(const std::vector<uint8_t>& v) {
    uint64_t h = 14695981039346656037ull;
    for (auto b : v)
        h = (h ^ b) * 1099511628211ull;
    return h;
}
uint32_t load(const std::vector<uint8_t>& v, size_t p, unsigned n = 4) {
    uint32_t u = 0;
    if (p + n <= v.size())
        std::memcpy(&u, v.data() + p, n);
    return u;
}
void store(std::vector<uint8_t>& v, size_t p, uint32_t u, unsigned n = 4) {
    if (p + n <= v.size())
        std::memcpy(v.data() + p, &u, n);
}
uint32_t frameAddr(unsigned page, unsigned width, unsigned format, unsigned x, unsigned y) {
    if (format == GS_PSM_CT16)
        return GSPSMCT16::addrPSMCT16(page * 32, width, x, y);
    if (format == GS_PSM_CT16S)
        return GSPSMCT16::addrPSMCT16S(page * 32, width, x, y);
    return GSPSMCT32::addrPSMCT32(page * 32, width, x, y);
}
uint32_t zAddr(unsigned page, unsigned width, unsigned format, unsigned x, unsigned y) {
    if (format == 2)
        return GSPSMCT16::addrPSMZ16(page * 32, width, x, y) % VramSize;
    if (format == 10)
        return GSPSMCT16::addrPSMZ16S(page * 32, width, x, y) % VramSize;
    const unsigned block = GSPSMCT32::blockTable32[(y / 8) & 3][(x / 8) & 7] ^ 24;
    return unsigned(((uint64_t(page) + (y / 32) * width + x / 64) * 8192 + block * 256 +
                     GSPSMCT32::columnTable32[y & 7][x & 7] * 4) %
                    VramSize);
}
struct Case {
    std::string name = "always";
    unsigned frame = GS_PSM_CT32, fbp = 0, fbw = 4, zbp = 64, zformat = 0;
    unsigned x0 = 0, y0 = 0, x1 = 256, y1 = 192, sx0 = 0, sy0 = 0, sx1 = 2047, sy1 = 2047;
    unsigned ztst = 1, sourceZ = 200, destZ = 100, afail = 0, alpha = 128;
    uint32_t mask = 0;
    bool zmask = false, date = false, datm = true, alternatingAlpha = false, alphaFail = false;
    bool zte = true, blend = false, oracle = true, proof = true, sequence = false, reverse = false;
    bool textured = false, fst = true, linear = false, endpointInvalid = false;
    unsigned source = GS_PSM_CT32, tbp = 14336, tbw = 4, cbp = 12288, cpsm = GS_PSM_CT32, csm = 0,
             csa = 0, cbw = 1, cou = 0, cov = 0;
    uint64_t clamp = 5, rawTest = ~0ull, zextra = 0;
};
} // namespace

bool spriteFixtureStopRequested() {
    if (stopEnabled.load(std::memory_order_relaxed) &&
        g_pxCalls.load(std::memory_order_relaxed) >= stopAt.load(std::memory_order_relaxed))
        fixtureStop.store(true, std::memory_order_relaxed);
    return fixtureStop.load(std::memory_order_relaxed);
}

int main(int argc, char** argv) {
    const char* dumpPath = nullptr;
    unsigned bench = 0, rounds = 9;
    for (int i = 1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "--dump") && i + 1 < argc)
            dumpPath = argv[++i];
        else if (!std::strcmp(argv[i], "--bench") && i + 1 < argc)
            bench = unsigned(std::strtoul(argv[++i], nullptr, 10));
        else if (!std::strcmp(argv[i], "--rounds") && i + 1 < argc)
            rounds = unsigned(std::strtoul(argv[++i], nullptr, 10));
        else
            return 2;
    }
    _putenv("REO_GS_THREAD=0");
    std::ofstream dump;
    if (dumpPath) {
        dump.open(dumpPath, std::ios::binary);
        if (!dump.is_open())
            return 2;
    }
    std::vector<uint8_t> vram(VramSize);
    GSRegisters regs{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &regs);
    unsigned checks = 0, failures = 0, cases = 0;
    auto check = [&](const std::string& name, bool ok) {
        ++checks;
        if (!ok) {
            ++failures;
            std::printf("FAIL %s\n", name.c_str());
        }
    };
    auto test = [&](const Case& c) {
        if (c.rawTest != ~0ull)
            return c.rawTest;
        return (uint64_t(c.zte) << 16) | (uint64_t(c.ztst) << 17) | (uint64_t(c.date) << 14) |
               (uint64_t(c.datm) << 15) | (c.alphaFail ? (1ull | (uint64_t(c.afail) << 12)) : 0);
    };
    auto setup = [&](const Case& c) {
        for (size_t i = 0; i < vram.size(); ++i)
            vram[i] = uint8_t((i * 29 + (i >> 8) * 7 + 17) & 255);
        const unsigned width = c.fbw ? c.fbw : 1;
        for (unsigned y = c.y0; y < c.y1; ++y)
            for (unsigned x = c.x0; x < c.x1; ++x) {
                const uint32_t old = c.alternatingAlpha && ((x + y) & 1) ? Old & 0x7fffffffu : Old;
                const unsigned n = (c.frame == GS_PSM_CT16 || c.frame == GS_PSM_CT16S) ? 2 : 4;
                store(vram, frameAddr(c.fbp, width, c.frame, x, y), n == 2 ? 0xb109u : old, n);
                const unsigned zn = c.zformat == 2 || c.zformat == 10 ? 2 : 4;
                store(vram, zAddr(c.zbp, width, c.zformat, x, y),
                      c.zformat == 1 ? 0x7e000000 | c.destZ : c.destZ, zn);
            }
        if (c.textured) {
            for (unsigned y = 0; y < 256; ++y)
                for (unsigned x = 0; x < 256; ++x) {
                    if (c.source == GS_PSM_T8) {
                        const unsigned off = GSPSMT8::addrPSMT8(c.tbp, c.tbw ? c.tbw : 1, x, y);
                        if (off < vram.size())
                            vram[off] = 8;
                    } else if (c.source == GS_PSM_T4) {
                        const unsigned n = GSPSMT4::addrPSMT4(c.tbp, c.tbw ? c.tbw : 1, x, y),
                                       off = n / 2, shift = (n & 1) * 4;
                        if (off < vram.size())
                            vram[off] = uint8_t((vram[off] & ~(15u << shift)) | (8u << shift));
                    } else {
                        const bool small = c.source == GS_PSM_CT16 || c.source == GS_PSM_CT16S;
                        const unsigned addr =
                            small ? (c.source == GS_PSM_CT16
                                         ? GSPSMCT16::addrPSMCT16(c.tbp, c.tbw ? c.tbw : 1, x, y)
                                         : GSPSMCT16::addrPSMCT16S(c.tbp, c.tbw ? c.tbw : 1, x, y))
                                  : GSPSMCT32::addrPSMCT32(c.tbp, c.tbw ? c.tbw : 1, x, y);
                        store(vram, addr, small ? 0xa8c2u : New, small ? 2 : 4);
                    }
                }
            if (c.source == GS_PSM_T4 || c.source == GS_PSM_T8) {
                const unsigned entries = c.source == GS_PSM_T4 ? 16 : 256;
                for (unsigned i = 0; i < entries; ++i) {
                    unsigned index = c.source == GS_PSM_T4 ? c.csa * 16 + i : i;
                    if (!c.csm)
                        index = (index & 0xe7) | ((index & 8) << 1) | ((index & 16) >> 1);
                    const unsigned x = c.cou + (index & 15), y = c.cov + (index >> 4);
                    const bool small = c.cpsm == GS_PSM_CT16 || c.cpsm == GS_PSM_CT16S;
                    const unsigned off =
                        small ? (c.cpsm == GS_PSM_CT16
                                     ? GSPSMCT16::addrPSMCT16(c.cbp, c.cbw ? c.cbw : 1, x, y)
                                     : GSPSMCT16::addrPSMCT16S(c.cbp, c.cbw ? c.cbw : 1, x, y))
                              : GSPSMCT32::addrPSMCT32(c.cbp, c.cbw ? c.cbw : 1, x, y);
                    store(vram, off, small ? 0xa8c2u : New, small ? 2 : 4);
                }
            }
        }
        gs.writeRegister(GS_REG_TEX0_1, c.tbp | (uint64_t(c.tbw) << 14) |
                                            (uint64_t(c.source) << 20) | (6ull << 26) |
                                            (6ull << 30) | (1ull << 34) | (1ull << 35) |
                                            (uint64_t(c.cbp) << 37) | (uint64_t(c.cpsm) << 51) |
                                            (uint64_t(c.csm) << 55) | (uint64_t(c.csa) << 56));
        gs.writeRegister(GS_REG_TEX1_1, c.linear ? 0x60 : 0);
        gs.writeRegister(GS_REG_CLAMP_1, c.clamp);
        gs.writeRegister(GS_REG_TEXCLUT, c.cbw | (uint64_t(c.cou) << 6) | (uint64_t(c.cov) << 12));
        gs.writeRegister(GS_REG_TEXA, 0x8000000080ull);
        gs.writeRegister(GS_REG_FRAME_1, c.fbp | (uint64_t(c.fbw) << 16) |
                                             (uint64_t(c.frame) << 24) | (uint64_t(c.mask) << 32));
        gs.writeRegister(GS_REG_SCISSOR_1, c.sx0 | (uint64_t(c.sx1) << 16) |
                                               (uint64_t(c.sy0) << 32) | (uint64_t(c.sy1) << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, test(c));
        gs.writeRegister(GS_REG_ZBUF_1, c.zbp | (uint64_t(c.zformat) << 24) |
                                            (uint64_t(c.zmask) << 32) | c.zextra);
        gs.writeRegister(GS_REG_ALPHA_1, 0x44);
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PABE, 0);
    };
    auto draw = [&](const Case& c) {
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_SPRITE | (uint64_t(c.textured) << 4) |
                                          (uint64_t(c.blend) << 6) | (uint64_t(c.fst) << 8));
        gs.writeRegister(GS_REG_RGBAQ, (uint64_t(0x3f800000u) << 32) | (uint64_t(c.alpha) << 24) |
                                           (New & 0xffffffu));
        const unsigned xs[]{c.reverse ? c.x1 : c.x0, c.reverse ? c.x0 : c.x1};
        const unsigned ys[]{c.reverse ? c.y1 : c.y0, c.reverse ? c.y0 : c.y1};
        auto texcoord = [&](unsigned n) {
            const unsigned u = n ? 52 : 4, v = n ? 52 : 4;
            gs.writeRegister(GS_REG_UV, u * 16 | (uint64_t(v * 16) << 16));
            float s = float(u) / 64, t = float(v) / 64;
            if (c.endpointInvalid)
                s = std::numeric_limits<float>::infinity();
            uint32_t sb, tb;
            std::memcpy(&sb, &s, 4);
            std::memcpy(&tb, &t, 4);
            gs.writeRegister(GS_REG_ST, sb | (uint64_t(tb) << 32));
        };
        texcoord(0);
        // First vertex deliberately has a different Z; sprites use vertex 1.
        gs.writeRegister(GS_REG_XYZ2, xs[0] * 16 | (uint64_t(ys[0] * 16) << 16) | (17ull << 32));
        texcoord(1);
        gs.writeRegister(GS_REG_XYZ2,
                         xs[1] * 16 | (uint64_t(ys[1] * 16) << 16) | (uint64_t(c.sourceZ) << 32));
    };
    // Independent full-VRAM expected image for disjoint CT32/24 outputs. No
    // production depthAddress, classifyAlphaTest or writePixel is used here.
    auto expected = [&](const Case& c, const std::vector<uint8_t>& initial) {
        auto out = initial;
        const unsigned width = c.fbw ? c.fbw : 1;
        for (unsigned y = std::max(c.y0, c.sy0); y < std::min(c.y1, c.sy1 + 1); ++y)
            for (unsigned x = std::max(c.x0, c.sx0); x < std::min(c.x1, c.sx1 + 1); ++x) {
                const unsigned f = frameAddr(c.fbp, width, c.frame, x, y),
                               z = zAddr(c.zbp, width, c.zformat, x, y);
                const uint32_t old = load(initial, f), oldZ = load(initial, z),
                               zmask = c.zformat == 1 ? 0xffffffu : 0xffffffffu;
                if (c.date && (c.frame == GS_PSM_CT24 || bool(old >> 31) != c.datm))
                    continue;
                if (c.zte && (!c.ztst || (c.ztst == 2 && c.sourceZ < (oldZ & zmask)) ||
                              (c.ztst == 3 && c.sourceZ <= (oldZ & zmask))))
                    continue;
                const bool color = !c.alphaFail || c.afail == 1 || c.afail == 3;
                const bool depth = !c.alphaFail || c.afail == 2;
                if (c.zte && !c.zmask && depth)
                    store(out, z, c.sourceZ, c.zformat == 1 ? 3 : 4);
                if (color) {
                    const bool sixteenTexture =
                        c.textured && (c.source == GS_PSM_CT16 || c.source == GS_PSM_CT16S ||
                                       ((c.source == GS_PSM_T4 || c.source == GS_PSM_T8) &&
                                        (c.cpsm == GS_PSM_CT16 || c.cpsm == GS_PSM_CT16S)));
                    uint32_t raw = c.textured ? (sixteenTexture ? 0x80503010u : New)
                                              : ((uint32_t(c.alpha) << 24) | (New & 0xffffffu));
                    if (c.alphaFail && c.afail == 3)
                        raw = (raw & 0xffffffu) | (old & 0xff000000u);
                    // Preserve the existing complete pixel writer's word/mask
                    // behavior; the parallel candidate changes no CT24 policy.
                    const uint32_t mask = c.mask;
                    store(out, f, (raw & ~mask) | (old & mask));
                }
            }
        return out;
    };
    auto run = [&](const Case& c) {
        setup(c);
        auto initial = vram;
        const uint32_t before = g_pxCalls.load();
        const uint32_t beforeAlpha = g_pxAlpha.load(), beforeScissor = g_pxScissor.load();
        draw(c);
        if (c.sequence)
            draw(c);
        const uint32_t calls = g_pxCalls.load() - before;
        const unsigned w = std::min(c.x1, c.sx1 + 1) - std::max(c.x0, c.sx0),
                       h = std::min(c.y1, c.sy1 + 1) - std::max(c.y0, c.sy0);
        check(c.name + " attempts", calls == w * h * (c.sequence ? 2 : 1));
        check(c.name + " no scissor rejection", g_pxScissor.load() == beforeScissor);
        if (c.oracle) {
            auto e = expected(c, initial);
            if (c.sequence)
                e = expected(c, e);
            check(c.name + " complete independent VRAM", e == vram);
        }
#ifdef REO_SPRITE_DEPTH_CANDIDATE
        GSContext ctx{};
        ctx.frame = {uint16_t(c.fbp), uint8_t(c.fbw), uint8_t(c.frame), c.mask};
        ctx.zbuf = c.zbp | (uint64_t(c.zformat) << 24) | (uint64_t(c.zmask) << 32) | c.zextra;
        if (!c.textured)
            check(c.name + " eligibility",
                  spriteDepthParallelSafe(ctx, unsigned(vram.size()), int(std::max(c.x0, c.sx0)),
                                          int(std::max(c.y0, c.sy0)),
                                          int(std::min(c.x1, c.sx1 + 1) - 1),
                                          int(std::min(c.y1, c.sy1 + 1) - 1)) == c.proof);
#ifdef REO_SPRITE_TEXTURE_DEPTH_CANDIDATE
        if (c.textured) {
            ctx.tex0.tbp0 = c.tbp;
            ctx.tex0.tbw = c.tbw;
            ctx.tex0.psm = c.source;
            ctx.tex0.tw = 6;
            ctx.tex0.th = 6;
            ctx.tex0.cbp = c.cbp;
            ctx.tex0.cpsm = c.cpsm;
            ctx.tex0.csm = c.csm;
            ctx.tex0.csa = c.csa;
            ctx.clamp = c.clamp;
            GSTexClutReg clut{};
            clut.cbw = c.cbw;
            clut.cou = c.cou;
            clut.cov = c.cov;
            const float u0 = c.endpointInvalid ? std::numeric_limits<float>::infinity() : 4.0f;
            check(c.name + " texture eligibility",
                  spriteTextureDepthParallelSafe(
                      ctx, clut, unsigned(vram.size()), int(std::max(c.x0, c.sx0)),
                      int(std::max(c.y0, c.sy0)), int(std::min(c.x1, c.sx1 + 1) - 1),
                      int(std::min(c.y1, c.sy1 + 1) - 1), u0, 4.0f, 52.0f, 52.0f) == c.proof);
        }
#endif
#endif
        std::printf("CASE %u %s hash=%016llx calls=%u scissor=%u alpha=%u oracle=%u\n", cases++,
                    c.name.c_str(), static_cast<unsigned long long>(hash(vram)), calls,
                    g_pxScissor.load() - beforeScissor, g_pxAlpha.load() - beforeAlpha,
                    unsigned(c.oracle));
        if (dump.is_open())
            dump.write(reinterpret_cast<const char*>(vram.data()), vram.size());
    };
    // Prime the existing retained row workers with intentionally wrong palette,
    // decoded texels and depth. New depth-aware bands must sample live data and
    // restore the old TLS after their final pixel.
    const auto mainThread = std::this_thread::get_id();
    DecodedTexelCache staleDecoded;
    staleDecoded.x = 0;
    staleDecoded.y = 0;
    staleDecoded.width = 256;
    staleDecoded.height = 256;
    staleDecoded.pixels.assign(256 * 256, 0x80eeccaa);
    static thread_local bool fixtureWarmed = false;
    RowPool::get().run(0, 255, [&](int, int) {
        fixtureWarmed = true;
        t_pixelDepth = 0x12345678u;
        t_clutCache.valid = true;
        std::fill_n(t_clutCache.table, 256, 0x80eeddccu);
        t_decodedTexels = &staleDecoded;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    });
    t_pixelDepth = 0;
    t_clutCache.valid = false;
    t_decodedTexels = nullptr;
    std::vector<Case> suite;
    auto add = [&](std::string n, auto fn) {
        Case c;
        c.name = n;
        fn(c);
        suite.push_back(c);
    };
    for (unsigned fmt : {unsigned(GS_PSM_CT32), unsigned(GS_PSM_CT24)})
        for (unsigned zf : {0u, 1u})
            for (unsigned zt : {0u, 1u, 2u, 3u})
                add("format" + std::to_string(fmt) + "-z" + std::to_string(zf) + "-test" +
                        std::to_string(zt),
                    [&](Case& c) {
                        c.frame = fmt;
                        c.zformat = zf;
                        c.ztst = zt;
                    });
    add("ge-equal", [](Case& c) {
        c.ztst = 2;
        c.sourceZ = 100;
    });
    add("gt-equal", [](Case& c) {
        c.ztst = 3;
        c.sourceZ = 100;
    });
    add("ge-reject", [](Case& c) {
        c.ztst = 2;
        c.sourceZ = 99;
    });
    add("raw-overflow-z24", [](Case& c) {
        c.zformat = 1;
        c.ztst = 3;
        c.sourceZ = 0xfffffffdu;
        c.destZ = 0xffffffu;
    });
    add("masked-ge", [](Case& c) {
        c.zmask = true;
        c.ztst = 2;
    });
    add("masked-never", [](Case& c) {
        c.zmask = true;
        c.ztst = 0;
    });
    for (unsigned datm : {0u, 1u})
        add("date" + std::to_string(datm), [&](Case& c) {
            c.date = true;
            c.datm = datm != 0;
            c.alternatingAlpha = true;
        });
    add("date-z-disabled", [](Case& c) {
        c.date = true;
        c.alternatingAlpha = true;
        c.zte = false;
    });
    add("date-ct24", [](Case& c) {
        c.date = true;
        c.frame = GS_PSM_CT24;
    });
    for (unsigned af : {0u, 1u, 2u, 3u})
        add("afail" + std::to_string(af), [&](Case& c) {
            c.alphaFail = true;
            c.afail = af;
            c.alpha = 64;
        });
    add("partial-mask", [](Case& c) { c.mask = 0x00f00f0fu; });
    add("full-mask", [](Case& c) { c.mask = 0xffffffffu; });
    add("blend", [](Case& c) { c.blend = true; });
    add("reverse", [](Case& c) { c.reverse = true; });
    add("clipped", [](Case& c) {
        c.sx0 = 17;
        c.sy0 = 19;
        c.sx1 = 230;
        c.sy1 = 180;
    });
    add("sequence", [](Case& c) {
        c.ztst = 3;
        c.sequence = true;
    });
    for (unsigned fb : {0u, 112u})
        add("logo-fbp" + std::to_string(fb), [&](Case& c) {
            c.fbp = fb;
            c.fbw = 8;
            c.zbp = 224;
            c.x1 = 512;
            c.y1 = 448;
            c.mask = 1;
        });
    add("row-width-edge", [](Case& c) {
        c.fbw = 8;
        c.zbp = 128;
        c.x0 = 256;
        c.x1 = 512;
    });
    add("tiny-serial-gate", [](Case& c) {
        c.x1 = 64;
        c.y1 = 16;
    });
    add("row-width-alias-fallback", [](Case& c) {
        c.fbw = 2;
        c.x1 = 256;
        c.oracle = false;
        c.proof = false;
    });
    add("fbz-overlap-fallback", [](Case& c) {
        c.zbp = 16;
        c.oracle = false;
        c.proof = false;
    });
    add("fbz-identical-fallback", [](Case& c) {
        c.zbp = 0;
        c.oracle = false;
        c.proof = false;
    });
    add("z-wrap-fallback", [](Case& c) {
        c.zbp = 500;
        c.oracle = false;
        c.proof = false;
    });
    add("fb-wrap-fallback", [](Case& c) {
        c.fbp = 500;
        c.oracle = false;
        c.proof = false;
    });
    add("ct16-fallback", [](Case& c) {
        c.frame = GS_PSM_CT16;
        c.oracle = false;
        c.proof = false;
    });
    add("ct16s-fallback", [](Case& c) {
        c.frame = GS_PSM_CT16S;
        c.oracle = false;
        c.proof = false;
    });
    add("z16-fallback", [](Case& c) {
        c.zformat = 2;
        c.oracle = false;
        c.proof = false;
    });
    add("z16s-fallback", [](Case& c) {
        c.zformat = 10;
        c.oracle = false;
        c.proof = false;
    });
    add("zero-width-fallback", [](Case& c) {
        c.fbw = 0;
        c.oracle = false;
        c.proof = false;
    });
    for (unsigned source : {unsigned(GS_PSM_CT32), unsigned(GS_PSM_CT24), unsigned(GS_PSM_CT16),
                            unsigned(GS_PSM_CT16S), unsigned(GS_PSM_T8), unsigned(GS_PSM_T4)})
        for (unsigned linear : {0u, 1u})
            for (unsigned mode : {0u, 1u, 2u, 3u}) {
                add("texture" + std::to_string(source) + "-linear" + std::to_string(linear) +
                        "-clamp" + std::to_string(mode),
                    [&](Case& c) {
                        c.textured = true;
                        c.source = source;
                        c.linear = linear != 0;
                        c.ztst = 2;
                        c.zmask = true;
                        c.oracle = true;
                        c.clamp = mode | (uint64_t(mode) << 2);
                        if (mode == 2)
                            c.clamp |= (19ull << 14) | (19ull << 34);
                        if (mode == 3)
                            c.clamp |=
                                (31ull << 4) | (128ull << 14) | (31ull << 24) | (128ull << 34);
                    });
            }
    for (unsigned fb : {0u, 112u})
        add("textured-logo-fbp" + std::to_string(fb), [&](Case& c) {
            c.textured = true;
            c.source = GS_PSM_T4;
            c.tbp = 0x2a00;
            c.tbw = 2;
            c.cbp = 0x3000;
            c.fbp = fb;
            c.fbw = 8;
            c.zbp = 224;
            c.x1 = 512;
            c.y1 = 448;
            c.mask = 1;
            c.ztst = 2;
            c.zmask = true;
            c.sourceZ = 0xfffffffdu;
            c.blend = true;
            c.clamp = 0x4c0004c00aull;
            c.rawTest = 0x5000full;
            c.zextra = 0x30000000ull;
        });
    add("stq-texture", [](Case& c) {
        c.textured = true;
        c.fst = false;
        c.ztst = 2;
        c.zmask = true;
        c.source = GS_PSM_T8;
    });
    add("nonfinite-stq-fallback", [](Case& c) {
        c.textured = true;
        c.fst = false;
        c.endpointInvalid = true;
        c.oracle = false;
        c.proof = false;
    });
    add("texture-fb-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.tbp = 0;
        c.oracle = false;
        c.proof = false;
    });
    add("texture-z-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.tbp = 64 * 32;
        c.oracle = false;
        c.proof = false;
    });
    add("masked-z-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.tbp = 64 * 32;
        c.zmask = true;
        c.ztst = 2;
        c.oracle = false;
        c.proof = false;
    });
    add("region-t4-z-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.source = GS_PSM_T4;
        c.tbp = 63 * 32;
        c.tbw = 2;
        c.clamp = 10 | (128ull << 24) | (128ull << 34);
        c.oracle = false;
        c.proof = false;
    });
    add("unaligned-t8-z-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.source = GS_PSM_T8;
        c.tbp = 63 * 32 + 31;
        c.tbw = 2;
        c.oracle = false;
        c.proof = false;
    });
    add("clut-fb-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.source = GS_PSM_T8;
        c.cbp = 0;
        c.oracle = false;
        c.proof = false;
    });
    add("clut-z-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.source = GS_PSM_T4;
        c.cbp = 64 * 32;
        c.oracle = false;
        c.proof = false;
    });
    add("clut-origin-z-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.source = GS_PSM_T4;
        c.cbp = 60 * 32;
        c.cov = 128;
        c.oracle = false;
        c.proof = false;
    });
    add("clut-unaligned-z-feedback-fallback", [](Case& c) {
        c.textured = true;
        c.source = GS_PSM_T4;
        c.cbp = 63 * 32 + 31;
        c.csm = 1;
        c.oracle = false;
        c.proof = false;
    });
    add("zero-t8-width-fallback", [](Case& c) {
        c.textured = true;
        c.source = GS_PSM_T8;
        c.tbw = 0;
        c.oracle = false;
        c.proof = false;
    });
    add("texture-wrap-fallback", [](Case& c) {
        c.textured = true;
        c.tbp = 16383;
        c.oracle = false;
        c.proof = false;
    });
    for (unsigned cpsm : {unsigned(GS_PSM_CT32), unsigned(GS_PSM_CT24), unsigned(GS_PSM_CT16),
                          unsigned(GS_PSM_CT16S)})
        for (unsigned csm : {0u, 1u})
            add("clut-format" + std::to_string(cpsm) + "-csm" + std::to_string(csm), [&](Case& c) {
                c.textured = true;
                c.source = GS_PSM_T4;
                c.cpsm = cpsm;
                c.csm = csm;
                c.csa = 13;
                c.cou = 32;
                c.cov = 32;
                c.cbw = 2;
                c.oracle = true;
            });
    // All draws reuse the same workers, varying second-vertex Z and test state.
    for (const auto& c : suite)
        run(c);
    for (unsigned i = 0; i < 4; ++i) {
        Case c;
        c.name = "worker-reuse" + std::to_string(i);
        c.sourceZ = 0x80000000u + i;
        c.zformat = i & 1;
        run(c);
    }
#ifdef REO_SPRITE_DEPTH_CANDIDATE
    {
        GSContext ctx{};
        ctx.frame = {0, 8, GS_PSM_CT32, 0};
        ctx.zbuf = 224;
        check("negative X rejected",
              !spriteDepthParallelSafe(ctx, unsigned(vram.size()), -1, 0, 511, 447));
        check("negative Y rejected",
              !spriteDepthParallelSafe(ctx, unsigned(vram.size()), 0, -1, 511, 447));
        check("reversed X rejected",
              !spriteDepthParallelSafe(ctx, unsigned(vram.size()), 511, 0, 0, 447));
        check("reversed Y rejected",
              !spriteDepthParallelSafe(ctx, unsigned(vram.size()), 0, 447, 511, 0));
        check("row crossing rejected",
              !spriteDepthParallelSafe(ctx, unsigned(vram.size()), 0, 0, 512, 447));
        check("short VRAM rejected", !spriteDepthParallelSafe(ctx, 0x200000, 0, 0, 511, 447));
        ctx.zbuf = 3ull << 24;
        check("invalid depth format rejected",
              !spriteDepthParallelSafe(ctx, unsigned(vram.size()), 0, 0, 511, 447));
    }
#endif

    // Cancellation is nondeterministic in row count, so compare each complete
    // VRAM image with an independently reconstructed completed-row oracle,
    // not with another run's cancellation timing. Every row must be entirely
    // untouched or have BOTH the expected color and expected raw depth.
    for (unsigned i = 0; i < 3; ++i) {
        Case c;
        c.sourceZ = 0xf0000000u + i;
        c.textured = i != 0;
        c.source = i == 1 ? GS_PSM_T4 : GS_PSM_T8;
        c.linear = true;
        c.clamp = 0x4c0004c00aull;
        setup(c);
        auto initial = vram, expectedPartial = initial;
        const uint32_t start = g_pxCalls.load();
        stopAt.store(start + c.x1 * c.y1 / 2);
        fixtureStop.store(false);
        stopEnabled.store(true);
        draw(c);
        stopEnabled.store(false);
        fixtureStop.store(false);
        unsigned completed = 0;
        bool wholeRows = true;
        for (unsigned y = 0; y < c.y1; ++y) {
            const bool changed = load(vram, frameAddr(c.fbp, c.fbw, c.frame, 0, y)) == New;
            completed += changed;
            for (unsigned x = 0; x < c.x1; ++x) {
                const unsigned f = frameAddr(c.fbp, c.fbw, c.frame, x, y),
                               z = zAddr(c.zbp, c.fbw, c.zformat, x, y);
                wholeRows &= load(vram, f) == (changed ? New : load(initial, f)) &&
                             load(vram, z) == (changed ? c.sourceZ : load(initial, z));
                if (changed) {
                    store(expectedPartial, f, New);
                    store(expectedPartial, z, c.sourceZ);
                }
            }
        }
        check("partial-stop full VRAM", wholeRows && vram == expectedPartial);
        check("partial-stop exact attempts", g_pxCalls.load() - start == completed * c.x1);
        check("partial-stop incomplete", completed > 0 && completed < c.y1);
        std::printf("STOP iteration=%u rows=%u calls=%u hash=%016llx\n", i, completed,
                    g_pxCalls.load() - start, static_cast<unsigned long long>(hash(vram)));
        c.name = "after-stop-reuse" + std::to_string(i);
        run(c);
    }
    std::atomic<unsigned> retainedChecked{0};
    std::atomic<bool> retainedGood{true};
    RowPool::get().run(0, 255, [&](int, int) {
        if (std::this_thread::get_id() != mainThread && fixtureWarmed) {
            retainedChecked.fetch_add(1);
            if (t_pixelDepth != 0x12345678u || !t_clutCache.valid ||
                t_clutCache.table[0] != 0x80eeddccu || t_decodedTexels != &staleDecoded)
                retainedGood.store(false);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    });
    check("retained worker TLS restored", retainedGood.load());
    std::printf("WORKER_TLS checked_bands=%u good=%u\n", retainedChecked.load(),
                unsigned(retainedGood.load()));
    if (bench) {
        Case c;
        c.name = "benchmark-textured-logo";
        c.textured = true;
        c.source = GS_PSM_T4;
        c.tbp = 0x2a00;
        c.tbw = 2;
        c.ztst = 2;
        c.zmask = true;
        c.clamp = 0x4c0004c00aull;
        c.rawTest = 0x5000full;
        c.zextra = 0x30000000ull;
        c.linear = true;
        c.fbw = 8;
        c.zbp = 224;
        c.x1 = 512;
        c.y1 = 448;
        c.mask = 1;
        for (unsigned r = 0; r < rounds; ++r) {
            setup(c);
            draw(c);
            auto begin = std::chrono::steady_clock::now();
            for (unsigned i = 0; i < bench; ++i)
                draw(c);
            const auto us = std::chrono::duration_cast<std::chrono::microseconds>(
                                std::chrono::steady_clock::now() - begin)
                                .count();
            std::printf("BENCH round=%u sprites=%u us=%lld hash=%016llx\n", r, bench,
                        static_cast<long long>(us), static_cast<unsigned long long>(hash(vram)));
        }
    }
    check("caller depth restored", t_pixelDepth == 0);
    ps2GsJoinRasterWorkers();
    std::printf("SUMMARY cases=%u independent_checks=%u failures=%u\n", cases, checks, failures);
    return failures ? 1 : 0;
}

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
        gs.writeRegister(GS_REG_FRAME_1, c.fbp | (uint64_t(c.fbw) << 16) |
                                             (uint64_t(c.frame) << 24) | (uint64_t(c.mask) << 32));
        gs.writeRegister(GS_REG_SCISSOR_1, c.sx0 | (uint64_t(c.sx1) << 16) |
                                               (uint64_t(c.sy0) << 32) | (uint64_t(c.sy1) << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, test(c));
        gs.writeRegister(GS_REG_ZBUF_1,
                         c.zbp | (uint64_t(c.zformat) << 24) | (uint64_t(c.zmask) << 32));
        gs.writeRegister(GS_REG_ALPHA_1, 0x44);
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PABE, 0);
    };
    auto draw = [&](const Case& c) {
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_SPRITE | (uint64_t(c.blend) << 6));
        gs.writeRegister(GS_REG_RGBAQ, (uint64_t(0x3f800000u) << 32) | (uint64_t(c.alpha) << 24) |
                                           (New & 0xffffffu));
        const unsigned xs[]{c.reverse ? c.x1 : c.x0, c.reverse ? c.x0 : c.x1};
        const unsigned ys[]{c.reverse ? c.y1 : c.y0, c.reverse ? c.y0 : c.y1};
        // First vertex deliberately has a different Z; sprites use vertex 1.
        gs.writeRegister(GS_REG_XYZ2, xs[0] * 16 | (uint64_t(ys[0] * 16) << 16) | (17ull << 32));
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
                    uint32_t raw = (uint32_t(c.alpha) << 24) | (New & 0xffffffu);
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
        ctx.zbuf = c.zbp | (uint64_t(c.zformat) << 24) | (uint64_t(c.zmask) << 32);
        check(c.name + " eligibility",
              spriteDepthParallelSafe(ctx, unsigned(vram.size()), int(std::max(c.x0, c.sx0)),
                                      int(std::max(c.y0, c.sy0)),
                                      int(std::min(c.x1, c.sx1 + 1) - 1),
                                      int(std::min(c.y1, c.sy1 + 1) - 1)) == c.proof);
#endif
        std::printf("CASE %u %s hash=%016llx calls=%u scissor=%u alpha=%u oracle=%u\n", cases++,
                    c.name.c_str(), static_cast<unsigned long long>(hash(vram)), calls,
                    g_pxScissor.load() - beforeScissor, g_pxAlpha.load() - beforeAlpha,
                    unsigned(c.oracle));
        if (dump.is_open())
            dump.write(reinterpret_cast<const char*>(vram.data()), vram.size());
    };
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
    if (bench) {
        Case c;
        c.name = "benchmark-logo";
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

// Deterministic check of the GS sprite fast paths (D37/D39): draws a fixed pseudo-random
// set of sprites through GS::writeRegister and prints an FNV-1a hash of VRAM. run.bat runs
// it with and without REO_GS_NO_FASTPATH=1; the two hashes must be identical.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
uint32_t g_rng = 0x12345678u;
uint32_t rnd() {
    g_rng ^= g_rng << 13;
    g_rng ^= g_rng >> 17;
    g_rng ^= g_rng << 5;
    return g_rng;
}
uint32_t rnd(uint32_t n) {
    return rnd() % n;
}

uint64_t fnv(const uint8_t* p, size_t n) {
    uint64_t h = 1469598103934665603ull;
    for (size_t i = 0; i < n; ++i) {
        h ^= p[i];
        h *= 1099511628211ull;
    }
    return h;
}
} // namespace

int main(int argc, char** argv) {
    const int cases = argc > 1 ? std::atoi(argv[1]) : 4000;
    _putenv("REO_GS_THREAD=0"); // synchronous GS: draw on this thread

    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    for (auto& b : vram)
        b = static_cast<uint8_t>(rnd());
    GS gs;
    gs.init(vram.data(), static_cast<uint32_t>(vram.size()), nullptr);

    uint32_t fastEligible = 0;
    uint32_t textureCases[7]{}, stCases = 0, dateCases = 0, zteCases = 0;
    for (int i = 0; i < cases; ++i) {
        // Frame: PSMCT32 or PSMCT24, 640 wide, random base page; sometimes masked.
        const uint64_t framePsm = rnd(4) == 0 ? 0x01u /*CT24*/ : 0x00u /*CT32*/;
        const uint64_t fbmsk = rnd(5) == 0 ? (rnd() & 0xFF0000FFu) : 0u;
        gs.writeRegister(GS_REG_FRAME_1,
                         (rnd(64) & 0x1FFu) | (10ull << 16) | (framePsm << 24) | (fbmsk << 32));
        gs.writeRegister(GS_REG_SCISSOR_1, (0ull) | (639ull << 16) | (0ull << 32) | (447ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_ZBUF_1, 1ull << 32); // ZMSK
        gs.writeRegister(GS_REG_ALPHA_1, rnd(4) | (rnd(4) << 2) | (rnd(4) << 4) | (rnd(4) << 6) |
                                             (static_cast<uint64_t>(rnd(256)) << 32));
        gs.writeRegister(GS_REG_PABE, rnd(3) == 0 ? 1u : 0u);
        gs.writeRegister(GS_REG_FBA_1, rnd(3) == 0 ? 1u : 0u);
        // DATE/depth state must select a faithful generic pipeline without
        // making fast/default/serial modes produce different VRAM.
        const uint64_t test =
            (rnd(2) ? (1u | (rnd(8) << 1) | (rnd(256) << 4) | (rnd(4) << 12)) : 0u) |
            (static_cast<uint64_t>(rnd(2)) << 14) | (static_cast<uint64_t>(rnd(2)) << 15) |
            (static_cast<uint64_t>(rnd(2)) << 16) | (static_cast<uint64_t>(rnd(4)) << 17);
        gs.writeRegister(GS_REG_TEST_1, test);
        dateCases += (test & (1ull << 14)) != 0;
        zteCases += (test & (1ull << 16)) != 0;
        gs.writeRegister(GS_REG_TEXA,
                         rnd(256) | (rnd(2) << 15) | (static_cast<uint64_t>(rnd(256)) << 32));

        // Include palette and 16-bit texture sources through the generic sampler.
        const uint32_t texKind = rnd(7);
        const uint64_t textureFormats[] = {0x13u /*T8*/,   0x01u /*CT24*/,  0x14u /*T4*/,
                                           0x02u /*CT16*/, 0x0au /*CT16S*/, 0x00u,
                                           0x00u};
        const uint64_t texPsm = textureFormats[texKind];
        const uint64_t tw = 6 + rnd(4), th = 6 + rnd(4);
        gs.writeRegister(GS_REG_TEX0_1, (static_cast<uint64_t>(rnd(4096)) & 0x3FFFu) |
                                            (static_cast<uint64_t>(4 + rnd(8)) << 14) |
                                            (texPsm << 20) | (tw << 26) | (th << 30) |
                                            (static_cast<uint64_t>(rnd(2)) << 34) |
                                            (static_cast<uint64_t>(rnd(4)) << 35) |
                                            (static_cast<uint64_t>(rnd(4096)) << 37));
        const bool linear = rnd(2) != 0;
        gs.writeRegister(GS_REG_TEX1_1, linear ? ((1ull << 5) | (1ull << 6)) : 0u);

        const bool tme = rnd(4) != 0;
        const bool abe = rnd(2) != 0;
        const bool fst = rnd(4) != 0;
        if (tme)
            ++textureCases[texKind];
        stCases += tme && !fst;
        gs.writeRegister(GS_REG_PRIM,
                         6u | (tme ? 1u << 4 : 0u) | (abe ? 1u << 6 : 0u) | (fst ? 1u << 8 : 0u));
        gs.writeRegister(GS_REG_RGBAQ, rnd() | (0x3F800000ull << 32));

        const bool big = rnd(4) == 0; // >= 32k pixels exercises the row-parallel path
        const int w = 1 + static_cast<int>(rnd(big ? 600 : 120)),
                  h = 1 + static_cast<int>(rnd(big ? 450 : 120));
        const int x0 = static_cast<int>(rnd(700)) - 30, y0 = static_cast<int>(rnd(500)) - 30;
        const int u0 = static_cast<int>(rnd(200)), v0 = static_cast<int>(rnd(200));
        int u1, v1;
        const uint32_t mapping = rnd(3);
        if (mapping == 0) {
            u1 = u0 + w;
            v1 = v0 + h;
        } // 1:1 forward
        else if (mapping == 1) {
            u1 = u0 - w;
            v1 = v0 - h;
        } // 1:1 reversed
        else {
            u1 = u0 + static_cast<int>(rnd(250));
            v1 = v0 + static_cast<int>(rnd(250));
        } // scaled
        if (u1 < 0)
            u1 = 0;
        if (v1 < 0)
            v1 = 0;
        if (tme && fst && (texPsm == 0x00u || texPsm == 0x01u) && mapping != 2 && u1 >= 0 &&
            v1 >= 0)
            ++fastEligible;
        auto vertex = [&](int x, int y, int u, int v) {
            gs.writeRegister(GS_REG_UV, (static_cast<uint64_t>(u * 16) & 0x3FFFu) |
                                            ((static_cast<uint64_t>(v * 16) & 0x3FFFu) << 16));
            if (!fst) {
                const float s = static_cast<float>(u) / static_cast<float>(1u << tw);
                const float t = static_cast<float>(v) / static_cast<float>(1u << th);
                uint32_t sBits = 0, tBits = 0;
                std::memcpy(&sBits, &s, sizeof(s));
                std::memcpy(&tBits, &t, sizeof(t));
                gs.writeRegister(GS_REG_ST, sBits | (static_cast<uint64_t>(tBits) << 32));
            }
            gs.writeRegister(GS_REG_XYZ2, (static_cast<uint64_t>(x * 16) & 0xFFFFu) |
                                              ((static_cast<uint64_t>(y * 16) & 0xFFFFu) << 16));
        };
        vertex(x0 < 0 ? 0 : x0, y0 < 0 ? 0 : y0, u0, v0);
        vertex((x0 < 0 ? 0 : x0) + w, (y0 < 0 ? 0 : y0) + h, u1, v1);
    }
    // Target bounded decoded-tile sampling: stretched tiny sources, reversed
    // UVs, clamped texture edges, clipped rectangles, area-limit fallback, and
    // texture/palette aliases that must retain sequential live reads.
    uint32_t cacheScenarios = 0;
    for (uint32_t psm : {0x13u, 0x14u})
        for (unsigned scenario = 0; scenario < 8; ++scenario) {
            constexpr uint32_t framePage = 320, frameBlock = framePage * 32;
            const bool textureAlias = scenario == 5, paletteAlias = scenario == 6;
            const uint32_t tbp = textureAlias ? frameBlock : 128u;
            const uint32_t cbp = paletteAlias ? frameBlock : 3000u;
            const unsigned dimension = scenario == 7 ? 9u : 8u;
            gs.writeRegister(GS_REG_FRAME_1, framePage | (10ull << 16));
            gs.writeRegister(GS_REG_SCISSOR_1,
                             16ull | (300ull << 16) | (8ull << 32) | (350ull << 48));
            gs.writeRegister(GS_REG_XYOFFSET_1, 0);
            gs.writeRegister(GS_REG_TEST_1, 0);
            gs.writeRegister(GS_REG_ALPHA_1,
                             0x44); // (source-destination)*source_alpha + destination.
            gs.writeRegister(GS_REG_FBA_1, 0);
            gs.writeRegister(GS_REG_PABE, scenario & 1u);
            gs.writeRegister(GS_REG_TEXCLUT, 1);
            gs.writeRegister(GS_REG_TEX0_1, tbp | (4ull << 14) |
                                                (static_cast<uint64_t>(psm) << 20) |
                                                (static_cast<uint64_t>(dimension) << 26) |
                                                (static_cast<uint64_t>(dimension) << 30) |
                                                (1ull << 34) | (static_cast<uint64_t>(cbp) << 37));
            gs.writeRegister(GS_REG_TEX1_1, scenario == 4 ? 0u : ((1ull << 5) | (1ull << 6)));
            gs.writeRegister(GS_REG_PRIM, 6u | (1u << 4) | (1u << 6) | (1u << 8));
            gs.writeRegister(GS_REG_RGBAQ, 0x3f80000080808080ull);
            const int uv[][4] = {{0, 0, 15, 31},       {15, 31, 0, 0},  {250, 250, 280, 280},
                                 {400, 400, 500, 500}, {15, 31, 0, 0},  {0, 0, 15, 31},
                                 {0, 0, 15, 31},       {0, 0, 511, 511}};
            const int widths[] = {230, 268, 128, 128, 307, 230, 230, 128};
            const int heights[] = {32, 80, 128, 128, 32, 32, 32, 128};
            auto vertex = [&](int x, int y, int u, int v) {
                gs.writeRegister(GS_REG_UV, static_cast<uint64_t>(u * 16) |
                                                (static_cast<uint64_t>(v * 16) << 16));
                gs.writeRegister(GS_REG_XYZ2, static_cast<uint64_t>(x * 16) |
                                                  (static_cast<uint64_t>(y * 16) << 16));
            };
            vertex(0, 0, uv[scenario][0], uv[scenario][1]);
            vertex(widths[scenario], heights[scenario], uv[scenario][2], uv[scenario][3]);
            ++cacheScenarios;
        }
    // TEXCLUT can place a palette inside the destination even when CBP's
    // generous16KiB range ends exactly at FRAME. Live sampling must observe
    // earlier writes to entry0; cached/parallel palette reads would freeze it.
    std::memset(vram.data() + 0x40000, 0, 0x10000);
    const uint32_t aliasColor = 0x804080f0u;
    std::memcpy(vram.data() + 0x4000, &aliasColor, sizeof(aliasColor));
    gs.writeRegister(GS_REG_FRAME_1, 2u | (4ull << 16));
    gs.writeRegister(GS_REG_SCISSOR_1, (255ull << 16) | (127ull << 48));
    gs.writeRegister(GS_REG_XYOFFSET_1, 0);
    gs.writeRegister(GS_REG_TEST_1, 0);
    gs.writeRegister(GS_REG_FBA_1, 0);
    gs.writeRegister(GS_REG_TEXCLUT, 1u | (64ull << 12));
    gs.writeRegister(GS_REG_TEX0_1, 1024u | (1ull << 14) | (0x13ull << 20) | (4ull << 26) |
                                        (4ull << 30) | (1ull << 34));
    gs.writeRegister(GS_REG_TEX1_1, 0);
    gs.writeRegister(GS_REG_PRIM, 6u | (1u << 4) | (1u << 8));
    gs.writeRegister(GS_REG_RGBAQ, 0x3f80000080404040ull);
    gs.writeRegister(GS_REG_UV, 0);
    gs.writeRegister(GS_REG_XYZ2, 0);
    gs.writeRegister(GS_REG_XYZ2, (256ull * 16) | ((128ull * 16) << 16));
    ++cacheScenarios;
    std::printf("cases=%d fast-eligible(textured 1:1)=%u fastpath=%s vram_fnv=%016llx\n", cases,
                fastEligible, std::getenv("REO_GS_NO_FASTPATH") ? "off" : "on",
                static_cast<unsigned long long>(fnv(vram.data(), vram.size())));
    std::printf("coverage: T8=%u CT24=%u T4=%u CT16=%u CT16S=%u CT32=%u ST=%u DATE=%u ZTE=%u "
                "tile_scenarios=%u\n",
                textureCases[0], textureCases[1], textureCases[2], textureCases[3], textureCases[4],
                textureCases[5] + textureCases[6], stCases, dateCases, zteCases, cacheScenarios);
    return 0;
}

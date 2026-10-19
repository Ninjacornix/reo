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

namespace
{
    uint32_t g_rng = 0x12345678u;
    uint32_t rnd()
    {
        g_rng ^= g_rng << 13;
        g_rng ^= g_rng >> 17;
        g_rng ^= g_rng << 5;
        return g_rng;
    }
    uint32_t rnd(uint32_t n) { return rnd() % n; }

    uint64_t fnv(const uint8_t *p, size_t n)
    {
        uint64_t h = 1469598103934665603ull;
        for (size_t i = 0; i < n; ++i)
        {
            h ^= p[i];
            h *= 1099511628211ull;
        }
        return h;
    }
}

int main(int argc, char **argv)
{
    const int cases = argc > 1 ? std::atoi(argv[1]) : 4000;
    _putenv("REO_GS_THREAD=0"); // synchronous GS: draw on this thread

    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    for (auto &b : vram)
        b = static_cast<uint8_t>(rnd());
    GS gs;
    gs.init(vram.data(), static_cast<uint32_t>(vram.size()), nullptr);

    uint32_t fastEligible = 0;
    for (int i = 0; i < cases; ++i)
    {
        // Frame: PSMCT32 or PSMCT24, 640 wide, random base page; sometimes masked.
        const uint64_t framePsm = rnd(4) == 0 ? 0x01u /*CT24*/ : 0x00u /*CT32*/;
        const uint64_t fbmsk = rnd(5) == 0 ? (rnd() & 0xFF0000FFu) : 0u;
        gs.writeRegister(GS_REG_FRAME_1, (rnd(64) & 0x1FFu) | (10ull << 16) | (framePsm << 24) | (fbmsk << 32));
        gs.writeRegister(GS_REG_SCISSOR_1, (0ull) | (639ull << 16) | (0ull << 32) | (447ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_ZBUF_1, 1ull << 32); // ZMSK
        gs.writeRegister(GS_REG_ALPHA_1, rnd(4) | (rnd(4) << 2) | (rnd(4) << 4) | (rnd(4) << 6) |
                                             (static_cast<uint64_t>(rnd(256)) << 32));
        gs.writeRegister(GS_REG_PABE, rnd(3) == 0 ? 1u : 0u);
        gs.writeRegister(GS_REG_FBA_1, rnd(3) == 0 ? 1u : 0u);
        const uint64_t test = rnd(2) ? (1u | (rnd(8) << 1) | (rnd(256) << 4) | (rnd(4) << 12)) : 0u;
        gs.writeRegister(GS_REG_TEST_1, test);
        gs.writeRegister(GS_REG_TEXA, rnd(256) | (rnd(2) << 15) | (static_cast<uint64_t>(rnd(256)) << 32));

        // Texture: PSMCT32/24 (fast-path eligible) or PSMT8 with a CLUT (generic only).
        const uint32_t texKind = rnd(5);
        const uint64_t texPsm = texKind == 0 ? 0x13u /*T8*/ : (texKind == 1 ? 0x01u : 0x00u);
        const uint64_t tw = 6 + rnd(4), th = 6 + rnd(4);
        gs.writeRegister(GS_REG_TEX0_1, (static_cast<uint64_t>(rnd(4096)) & 0x3FFFu) | (static_cast<uint64_t>(4 + rnd(8)) << 14) |
                                            (texPsm << 20) | (tw << 26) | (th << 30) | (static_cast<uint64_t>(rnd(2)) << 34) |
                                            (static_cast<uint64_t>(rnd(4)) << 35) | (static_cast<uint64_t>(rnd(4096)) << 37));
        const bool linear = rnd(2) != 0;
        gs.writeRegister(GS_REG_TEX1_1, linear ? ((1ull << 5) | (1ull << 6)) : 0u);

        const bool tme = rnd(4) != 0;
        const bool abe = rnd(2) != 0;
        gs.writeRegister(GS_REG_PRIM, 6u | (tme ? 1u << 4 : 0u) | (abe ? 1u << 6 : 0u) | (1u << 8) /*FST*/);
        gs.writeRegister(GS_REG_RGBAQ, rnd() | (0x3F800000ull << 32));

        const bool big = rnd(4) == 0; // >= 32k pixels exercises the row-parallel path
        const int w = 1 + static_cast<int>(rnd(big ? 600 : 120)), h = 1 + static_cast<int>(rnd(big ? 450 : 120));
        const int x0 = static_cast<int>(rnd(700)) - 30, y0 = static_cast<int>(rnd(500)) - 30;
        const int u0 = static_cast<int>(rnd(200)), v0 = static_cast<int>(rnd(200));
        int u1, v1;
        const uint32_t mapping = rnd(3);
        if (mapping == 0) { u1 = u0 + w; v1 = v0 + h; }       // 1:1 forward
        else if (mapping == 1) { u1 = u0 - w; v1 = v0 - h; }  // 1:1 reversed
        else { u1 = u0 + static_cast<int>(rnd(250)); v1 = v0 + static_cast<int>(rnd(250)); } // scaled
        if (u1 < 0) u1 = 0;
        if (v1 < 0) v1 = 0;
        if (tme && texKind != 0 && mapping != 2 && u1 >= 0 && v1 >= 0)
            ++fastEligible;
        auto vertex = [&](int x, int y, int u, int v) {
            gs.writeRegister(GS_REG_UV, (static_cast<uint64_t>(u * 16) & 0x3FFFu) | ((static_cast<uint64_t>(v * 16) & 0x3FFFu) << 16));
            gs.writeRegister(GS_REG_XYZ2, (static_cast<uint64_t>(x * 16) & 0xFFFFu) | ((static_cast<uint64_t>(y * 16) & 0xFFFFu) << 16));
        };
        vertex(x0 < 0 ? 0 : x0, y0 < 0 ? 0 : y0, u0, v0);
        vertex((x0 < 0 ? 0 : x0) + w, (y0 < 0 ? 0 : y0) + h, u1, v1);
    }
    std::printf("cases=%d fast-eligible(textured 1:1)=%u fastpath=%s vram_fnv=%016llx\n", cases, fastEligible,
                std::getenv("REO_GS_NO_FASTPATH") ? "off" : "on", static_cast<unsigned long long>(fnv(vram.data(), vram.size())));
    return 0;
}

// Production GS cost controls for pure depth/DATE rejection before shading.
// Synthetic assets only. Run the unchanged and candidate libraries separately.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

extern std::atomic<uint32_t> g_pxCalls;
namespace {
constexpr unsigned W = 512, H = 448, TexBlock = 8192, ZPage = 128;
uint32_t bits(float f) {
    uint32_t u;
    std::memcpy(&u, &f, 4);
    return u;
}
uint64_t hash(const std::vector<uint8_t>& data) {
    uint64_t h = 14695981039346656037ull;
    for (uint8_t b : data)
        h = (h ^ b) * 1099511628211ull;
    return h;
}
uint32_t zOffset(unsigned x, unsigned y) {
    // Independent Z32 XOR-block layout; benchmark scene is disjoint FB/Z/TEX.
    return ZPage * 8192 + (y / 32) * 8 * 8192 + (x / 64) * 8192 +
           (GSPSMCT32::blockTable32[(y / 8) % 4][(x / 8) % 8] ^ 24) * 256 +
           GSPSMCT32::columnTable32[y % 8][x % 8] * 4;
}
} // namespace
int main(int argc, char** argv) {
    const unsigned iterations = argc > 1 ? std::clamp(std::atoi(argv[1]), 1, 128) : 16;
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE, 0);
    GSRegisters regs{};
    GS gs;
    gs.init(vram.data(), uint32_t(vram.size()), &regs);
    auto store = [&](unsigned off, uint32_t value) { std::memcpy(vram.data() + off, &value, 4); };
    auto read = [&](unsigned off) {
        uint32_t value;
        std::memcpy(&value, vram.data() + off, 4);
        return value;
    };
    enum Outcome { Accepted, DepthRejected, DateRejected, HalfRejected };
    unsigned failures = 0;
    auto run = [&](const char* name, bool textured, bool bilinear, Outcome outcome) {
        std::fill(vram.begin(), vram.end(), 0);
        for (unsigned y = 0; y < 512; ++y)
            for (unsigned x = 0; x < 512; ++x)
                store(GSPSMCT32::addrPSMCT32(TexBlock, 8, x, y),
                      0x80000000u | ((x * 13 + 7) & 255) | (((y * 17 + 11) & 255) << 8) |
                          (((x + y + 31) & 255) << 16));
        for (unsigned y = 0; y < H; ++y)
            for (unsigned x = 0; x < W; ++x)
                store(zOffset(x, y),
                      outcome == DepthRejected || (outcome == HalfRejected && x >= W / 2)
                          ? 0xffffffffu
                          : 0u);
        gs.writeRegister(GS_REG_FRAME_1, 8ull << 16);
        gs.writeRegister(GS_REG_SCISSOR_1, ((W - 1ull) << 16) | ((H - 1ull) << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_ZBUF_1,
                         ZPage | (1ull << 32)); // Test only; repeated triangles remain comparable.
        gs.writeRegister(GS_REG_TEST_1, outcome == DateRejected ? (1ull << 14) | (1ull << 15)
                                                                : (1ull << 16) | (2ull << 17));
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_TEX0_1, TexBlock | (8ull << 14) | (9ull << 26) | (9ull << 30) |
                                            (1ull << 34) | (1ull << 35));
        gs.writeRegister(GS_REG_TEX1_1, bilinear ? (1ull << 5) | (1ull << 6) : 0);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_TRIANGLE | (1u << 3) | (textured ? 1u << 4 : 0));
        const auto before = hash(vram);
        const auto callsBefore = g_pxCalls.load(std::memory_order_relaxed);
        const auto started = std::chrono::steady_clock::now();
        for (unsigned n = 0; n < iterations; ++n) {
            const unsigned xs[] = {0, W, 0}, ys[] = {0, 0, H};
            const float us[] = {.05f, .9f, .05f}, vs[] = {.05f, .05f, .9f}, qs[] = {1, 2, 4};
            for (unsigned k = 0; k < 3; ++k) {
                gs.writeRegister(GS_REG_RGBAQ, 0x80443322ull | (uint64_t(bits(qs[k])) << 32));
                gs.writeRegister(GS_REG_ST, uint64_t(bits(us[k] * qs[k])) |
                                                (uint64_t(bits(vs[k] * qs[k])) << 32));
                gs.writeRegister(GS_REG_XYZ2, uint64_t(xs[k] * 16) | (uint64_t(ys[k] * 16) << 16) |
                                                  (1ull << 32));
            }
        }
        gs.getLastDisplayBaseBytes();
        const auto elapsed =
            std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - started)
                .count();
        const auto calls = g_pxCalls.load(std::memory_order_relaxed) - callsBefore;
        const auto after = hash(vram);
        const bool unchanged = outcome == DepthRejected || outcome == DateRejected;
        const bool pass = unchanged ? before == after
                                    : read(GSPSMCT32::addrPSMCT32(0, 8, 64, 64)) != 0 &&
                                          (outcome != HalfRejected ||
                                           read(GSPSMCT32::addrPSMCT32(0, 8, 300, 32)) == 0);
        failures += !pass;
        std::printf("%s name=%s textured=%u linear=%u iterations=%u ms=%.3f per_triangle_ms=%.6f "
                    "writer_calls=%u hash=%016llx unchanged=%u\n",
                    pass ? "PASS" : "FAIL", name, unsigned(textured), unsigned(bilinear),
                    iterations, elapsed, elapsed / iterations, calls,
                    static_cast<unsigned long long>(after), unsigned(unchanged));
    };
    run("accepted-textured-point", true, false, Accepted);
    run("accepted-textured-linear", true, true, Accepted);
    run("depth-reject-textured-point", true, false, DepthRejected);
    run("depth-reject-textured-linear", true, true, DepthRejected);
    run("depth-reject-untextured", false, false, DepthRejected);
    run("date-reject-textured-linear", true, true, DateRejected);
    run("date-reject-untextured", false, false, DateRejected);
    run("mixed-depth-textured-linear", true, true, HalfRejected);
    std::printf("reject_benchmark_cases=8 failures=%u early_tests_env=%s\n", failures,
                std::getenv("REO_GS_EARLY_TEST") ? std::getenv("REO_GS_EARLY_TEST") : "unset");
    return failures ? 1 : 0;
}

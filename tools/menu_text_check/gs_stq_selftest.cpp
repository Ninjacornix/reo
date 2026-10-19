// Production GS rendering against a coordinate-coded CT32 texture and an
// analytic interior-pixel oracle. No game code, files or screenshot hashes.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {
constexpr unsigned kTextureBlock = 256, kSize = 32;
struct Vertex {
    unsigned x, y;
    float u, v, q;
};
uint32_t bits(float value) {
    uint32_t result;
    std::memcpy(&result, &value, 4);
    return result;
}
uint32_t texture(unsigned x, unsigned y) {
    return (4u + x * 7u) | ((5u + y * 7u) << 8) | ((31u + x + y) << 16) | (128u << 24);
}
struct Result {
    unsigned checks = 0, mismatches = 0;
};
} // namespace

int main(int argc, char** argv) {
    const bool expectBug = argc == 2 && std::strcmp(argv[1], "--expect-current-bug") == 0;
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE, 0);
    GSRegisters regs{};
    GS gs;
    gs.init(vram.data(), uint32_t(vram.size()), &regs);
    auto run = [&](const char* name, std::array<Vertex, 3> vertices, bool fst) {
        std::memset(vram.data(), 0, vram.size());
        for (unsigned y = 0; y < kSize; ++y)
            for (unsigned x = 0; x < kSize; ++x) {
                const uint32_t color = texture(x, y);
                std::memcpy(vram.data() + GSPSMCT32::addrPSMCT32(kTextureBlock, 1, x, y), &color,
                            4);
            }
        gs.writeRegister(GS_REG_FRAME_1, 1ull << 16);
        gs.writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (63ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, 0);
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_ZBUF_1, 1ull << 32);
        gs.writeRegister(GS_REG_TEX1_1, 0);  // Nearest; no bilinear rounding ambiguity.
        gs.writeRegister(GS_REG_CLAMP_1, 5); // Explicit CLAMP on both axes for this oracle.
        gs.writeRegister(GS_REG_TEX0_1,
                         kTextureBlock | (1ull << 14) | (5ull << 26) | (5ull << 30) | (1ull << 34) |
                             (1ull << 35)); // 32x32 CT32, RGBA DECAL, disjoint from framebuffer.
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_TRIANGLE | (1u << 4) | (fst ? 1u << 8 : 0));
        for (const auto& vertex : vertices) {
            gs.writeRegister(GS_REG_RGBAQ, 0x80808080ull | (uint64_t(bits(vertex.q)) << 32));
            gs.writeRegister(GS_REG_ST, uint64_t(bits(vertex.u * vertex.q)) |
                                            (uint64_t(bits(vertex.v * vertex.q)) << 32));
            gs.writeRegister(GS_REG_UV, unsigned(vertex.u * kSize * 16) |
                                            (uint64_t(unsigned(vertex.v * kSize * 16)) << 16));
            gs.writeRegister(GS_REG_XYZ2,
                             uint64_t(vertex.x * 16) | (uint64_t(vertex.y * 16) << 16));
        }
        gs.getLastDisplayBaseBytes();
        const auto& a = vertices[0];
        const auto& b = vertices[1];
        const auto& c = vertices[2];
        const double denom =
            (double(b.y) - c.y) * (double(a.x) - c.x) + (double(c.x) - b.x) * (double(a.y) - c.y);
        Result result;
        for (unsigned y = 4; y < 52; ++y)
            for (unsigned x = 4; x < 52; ++x) {
                const double px = x + .5, py = y + .5;
                const double w0 =
                    ((double(b.y) - c.y) * (px - c.x) + (double(c.x) - b.x) * (py - c.y)) / denom;
                const double w1 =
                    ((double(c.y) - a.y) * (px - c.x) + (double(a.x) - c.x) * (py - c.y)) / denom;
                const double w2 = 1 - w0 - w1;
                if (std::min({w0, w1, w2}) < .05)
                    continue; // Exclude triangle coverage/top-left differences.
                double u, v;
                if (fst) {
                    // Fixed UV coordinates have no Q division.
                    u = a.u * kSize * w0 + b.u * kSize * w1 + c.u * kSize * w2;
                    v = a.v * kSize * w0 + b.v * kSize * w1 + c.v * kSize * w2;
                } else {
                    // GS linearly interpolates supplied S, T and Q, then divides once.
                    const double q = a.q * w0 + b.q * w1 + c.q * w2;
                    u = (a.u * a.q * w0 + b.u * b.q * w1 + c.u * c.q * w2) / q * kSize;
                    v = (a.v * a.q * w0 + b.v * b.q * w1 + c.v * c.q * w2) / q * kSize;
                }
                if (std::abs(u - std::round(u)) < .002 || std::abs(v - std::round(v)) < .002)
                    continue;
                const unsigned tx = unsigned(std::clamp(int(u), 0, 31)),
                               ty = unsigned(std::clamp(int(v), 0, 31));
                uint32_t actual;
                std::memcpy(&actual, vram.data() + GSPSMCT32::addrPSMCT32(0, 1, x, y), 4);
                const uint32_t expected = texture(tx, ty);
                ++result.checks;
                if (actual != expected) {
                    if (!result.mismatches)
                        std::printf("  first mismatch %s pixel=(%u,%u) expected_texel=(%u,%u) "
                                    "actual=%08x expected=%08x\n",
                                    name, x, y, tx, ty, actual, expected);
                    ++result.mismatches;
                }
            }
        std::printf("%s %s checked=%u mismatches=%u\n", result.mismatches ? "FAIL" : "PASS", name,
                    result.checks, result.mismatches);
        return result;
    };
    std::array<Vertex, 3> vertices{
        {{4, 4, .0625f, .0625f, 2}, {52, 4, .875f, .0625f, 2}, {4, 52, .0625f, .875f, 2}}};
    const auto constant = run("constant nonunit Q control", vertices, false);
    const auto fixed = run("FST ignores Q control", vertices, true);
    vertices[0].q = 1;
    vertices[1].q = 2;
    vertices[2].q = 4;
    const auto varying = run("varying positive Q", vertices, false);
    std::swap(vertices[1], vertices[2]);
    const auto winding = run("varying Q reversed winding", vertices, false);
    for (auto& vertex : vertices)
        vertex.q = -vertex.q;
    const auto negative = run("varying same-sign negative Q", vertices, false);
    const bool controls =
        constant.checks > 500 && fixed.checks > 500 && !constant.mismatches && !fixed.mismatches;
    const bool defect =
        varying.mismatches > 100 && winding.mismatches > 100 && negative.mismatches > 100;
    const bool corrected = !varying.mismatches && !winding.mismatches && !negative.mismatches;
    std::printf("stq_cases=5 controls=%u mode=%s\n", unsigned(controls),
                expectBug ? "baseline-defect" : "correct");
    return controls && (expectBug ? defect : corrected) ? 0 : 1;
}

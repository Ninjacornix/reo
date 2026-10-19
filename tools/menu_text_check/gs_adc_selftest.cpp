// Production primitive assembly: ADC suppresses drawing, not vertex history.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

struct Vertex {
    unsigned x, y;
    bool draw;
};
uint64_t fnv(const std::vector<uint8_t>& bytes) {
    uint64_t hash = 14695981039346656037ull;
    for (uint8_t byte : bytes)
        hash = (hash ^ byte) * 1099511628211ull;
    return hash;
}
int main(int argc, char** argv) {
    const bool expectBug = argc == 2 && std::strcmp(argv[1], "--expect-current-bug") == 0;
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE, 0);
    GSRegisters regs{};
    GS gs;
    gs.init(vram.data(), uint32_t(vram.size()), &regs);
    auto configure = [&](unsigned primitive) {
        gs.getLastDisplayBaseBytes();
        std::memset(vram.data(), 0, vram.size());
        gs.writeRegister(GS_REG_FRAME_1, 1ull << 16);
        gs.writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (63ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_ZBUF_1, 1ull << 32);
        gs.writeRegister(GS_REG_TEST_1, 0);
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PRIM, primitive);
        gs.writeRegister(GS_REG_RGBAQ, 0x3f800000ff443322ull);
    };
    auto emit = [&](const std::vector<Vertex>& vertices) {
        for (const auto& vertex : vertices)
            gs.writeRegister(vertex.draw ? GS_REG_XYZ2 : GS_REG_XYZ3,
                             uint64_t(vertex.x * 16) | (uint64_t(vertex.y * 16) << 16));
        gs.getLastDisplayBaseBytes();
    };
    unsigned mismatches = 0;
    auto test = [&](const char* name, unsigned primitive, std::vector<Vertex> input,
                    unsigned referencePrimitive, std::vector<Vertex> expected) {
        configure(primitive);
        emit(input);
        const auto actual = vram;
        configure(referencePrimitive);
        emit(expected);
        const bool same = actual == vram;
        mismatches += !same;
        std::printf("%s %s actual=%016llx expected=%016llx\n", same ? "PASS" : "FAIL", name,
                    static_cast<unsigned long long>(fnv(actual)),
                    static_cast<unsigned long long>(fnv(vram)));
    };
    auto history = [](unsigned count) {
        std::vector<Vertex> result;
        for (unsigned i = 0; i < count; ++i)
            result.push_back({300 + i, 300 + i, false});
        return result;
    };
    const Vertex a{8, 8, true}, b{32, 8, true}, c{8, 32, true}, d{32, 32, true};
    auto input = history(9);
    input.push_back(a);
    test("point skips consume vertices", GS_PRIM_POINT, input, GS_PRIM_POINT, {a});
    input = history(10);
    input.push_back(a);
    input.push_back(b);
    test("line list skips consume complete pairs", GS_PRIM_LINE, input, GS_PRIM_LINE, {a, b});
    input = history(8);
    input.push_back({a.x, a.y, false});
    input.push_back(b);
    test("line strip skips retain latest vertex", GS_PRIM_LINESTRIP, input, GS_PRIM_LINE, {a, b});
    input = history(9);
    input.push_back(a);
    input.push_back(b);
    input.push_back(c);
    test("triangle list skips consume complete triples", GS_PRIM_TRIANGLE, input, GS_PRIM_TRIANGLE,
         {a, b, c});
    input = history(9);
    input.push_back({a.x, a.y, false});
    input.push_back({b.x, b.y, false});
    input.push_back(c);
    test("triangle strip skips retain latest two vertices", GS_PRIM_TRISTRIP, input,
         GS_PRIM_TRIANGLE, {a, b, c});
    input = {{a.x, a.y, false}};
    const auto skipped = history(9);
    input.insert(input.end(), skipped.begin(), skipped.end());
    input.push_back({b.x, b.y, false});
    input.push_back(c);
    test("triangle fan skips retain anchor and latest vertex", GS_PRIM_TRIFAN, input,
         GS_PRIM_TRIANGLE, {a, b, c});
    input = history(10);
    input.push_back(a);
    input.push_back(d);
    test("sprite skips consume complete pairs", GS_PRIM_SPRITE, input, GS_PRIM_SPRITE, {a, d});
    std::printf("adc_cases=7 mismatches=%u mode=%s\n", mismatches,
                expectBug ? "baseline-defect" : "correct");
    return expectBug ? (mismatches >= 3 ? 0 : 1) : (mismatches ? 1 : 0);
}

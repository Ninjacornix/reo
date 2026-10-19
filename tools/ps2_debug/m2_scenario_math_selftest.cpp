// Actual generated overlay angle helpers and actual original main VU0 trig code.
// Owned ELF/overlay supply the polynomial constants; std trig is an oracle only.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <vector>

void o0_003700C0_0x3700c0(uint8_t*, R5900Context*, PS2Runtime*);
void o0_00370100_0x370100(uint8_t*, R5900Context*, PS2Runtime*);
void sub_00192190_0x192190(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001921A0_0x1921a0(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018F340_0x18f340(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018F470_0x18f470(uint8_t*, R5900Context*, PS2Runtime*);
void sub_0018F570_0x18f570(uint8_t*, R5900Context*, PS2Runtime*);

static float enteredRadians;
static uint32_t enteredTarget;
static void sineEntry(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    enteredRadians = ctx->f[12];
    enteredTarget = ctx->pc;
    sub_00192190_0x192190(ram, ctx, rt);
}
static void cosineEntry(uint8_t* ram, R5900Context* ctx, PS2Runtime* rt) {
    enteredRadians = ctx->f[12];
    enteredTarget = ctx->pc;
    sub_001921A0_0x1921a0(ram, ctx, rt);
}
static void check(bool pass, const char* why) {
    if (!pass)
        throw std::runtime_error(why);
}
static std::vector<uint8_t> read(const char* path) {
    std::ifstream stream(path, std::ios::binary);
    check(bool(stream), "owned input could not be opened");
    return {std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()};
}
static uint32_t word(const std::vector<uint8_t>& b, size_t off) {
    check(off + 4 <= b.size(), "owned input header truncated");
    uint32_t v;
    std::memcpy(&v, b.data() + off, 4);
    return v;
}

int main(int argc, char** argv) {
    try {
        check(argc == 3, "usage: math_selftest owned-main.elf owned-original-o0.bin");
        PS2Runtime runtime;
        check(runtime.memory().initialize(), "RAM initialization");
        auto* ram = runtime.memory().getRDRAM();
        auto* ctx = &runtime.cpu();
        const auto elf = read(argv[1]);
        check(word(elf, 0) == 0x464c457f, "main input must be ELF");
        const uint32_t phoff = word(elf, 28);
        const uint16_t phnum = uint16_t(elf[44] | elf[45] << 8);
        for (unsigned n = 0; n < phnum; ++n) {
            const size_t ph = phoff + n * 32;
            if (word(elf, ph) != 1)
                continue;
            const uint32_t off = word(elf, ph + 4), va = word(elf, ph + 8),
                           size = word(elf, ph + 16);
            check(uint64_t(off) + size <= elf.size() && uint64_t(va) + size <= PS2_RAM_SIZE,
                  "ELF segment out of bounds");
            std::memcpy(ram + va, elf.data() + off, size);
        }
        const auto overlay = read(argv[2]);
        check(word(overlay, 0) == 0x336f574d && word(overlay, 8) == 0x370000,
              "overlay MWo3 revision");
        check(overlay.size() + 0x370000 <= PS2_RAM_SIZE, "overlay bounds");
        std::memcpy(ram + 0x370000, overlay.data(), overlay.size());
        runtime.registerFunction(0x192190, sineEntry);
        runtime.registerFunction(0x1921a0, cosineEntry);
        runtime.registerFunction(0x18f340, sub_0018F340_0x18f340);
        runtime.registerFunction(0x18f470, sub_0018F470_0x18f470);
        constexpr uint32_t ra = 0x100008, sp = 0x1f00000;
        float scale;
        std::memcpy(&scale, ram + 0x38b290, 4);
        unsigned cases = 0, numericFailures = 0, signFailures = 0;
        double maxError = 0;
        uint32_t worstInput = 0;
        bool worstCosine = false;
        float worstActual = 0;
        double worstExpected = 0;
        auto run = [&](uint32_t input, bool cosine) {
            *ctx = R5900Context{};
            ctx->pc = cosine ? 0x370100 : 0x3700c0;
            // Architecturally constant VF0=(0,0,0,1), as native initialize sets.
            ctx->vu0_vf[0] = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
            SET_GPR_U32(ctx, 4, input);
            SET_GPR_U32(ctx, 29, sp);
            SET_GPR_U32(ctx, 31, ra);
            for (int r = 16; r <= 23; ++r)
                SET_GPR_VEC(ctx, r, _mm_set_epi32(r + 3, r + 2, r + 1, r));
            enteredTarget = 0;
            enteredRadians = -100;
            if (cosine)
                o0_00370100_0x370100(ram, ctx, &runtime);
            else
                o0_003700C0_0x3700c0(ram, ctx, &runtime);
            check(enteredTarget == (cosine ? 0x1921a0u : 0x192190u),
                  "helper must enter original tail target");
            const float expectedRadians = float(input & 0xffffu) * scale;
            check(enteredRadians == expectedRadians,
                  "wrapped angle mask/conversion or tail delay slot differs");
            check(ctx->pc == ra && GPR_U32(ctx, 31) == ra && GPR_U32(ctx, 29) == sp,
                  "original return/RA/SP changed");
            for (int r = 16; r <= 23; ++r) {
                alignas(16) uint32_t v[4];
                _mm_store_si128(reinterpret_cast<__m128i*>(v), GPR_VEC(ctx, r));
                check(v[0] == unsigned(r) && v[1] == unsigned(r + 1) && v[2] == unsigned(r + 2) &&
                          v[3] == unsigned(r + 3),
                      "saved vector register changed");
            }
            const double angle = double(input & 0xffffu) * (6.2831853071795864769 / 65536.0);
            const double expected = cosine ? std::cos(angle) : std::sin(angle);
            const double error = std::abs(double(ctx->f[0]) - expected);
            if (error > maxError) {
                maxError = error;
                worstInput = input;
                worstCosine = cosine;
                worstActual = ctx->f[0];
                worstExpected = expected;
            }
            if (std::abs(expected) > 0.0001 && std::signbit(ctx->f[0]) != std::signbit(expected))
                ++signFailures;
            if (!std::isfinite(ctx->f[0]) || error > 0.003) {
                if (numericFailures < 16)
                    std::fprintf(
                        stderr,
                        "input=%08X cosine=%d actual=%.9g expected=%.9g error=%.9g target=%X\n",
                        input, cosine, ctx->f[0], expected, error, enteredTarget);
                ++numericFailures;
            }
            ++cases;
        };
        // All original 16-bit headings plus wrapped signed/high-word aliases.
        for (uint32_t input = 0; input < 65536; ++input) {
            run(input, false);
            run(input, true);
        }
        for (uint32_t input :
             {0x10000u, 0x14000u, 0x18000u, 0x1c000u, 0xffffc000u, 0xffffdcb4u, 0x12342345u}) {
            run(input, false);
            run(input, true);
        }
        // Actual combined routine writes sine/cosine to VF6.x/y in its original
        // SQC2 output. Exercise both positive wrapped and negative headings.
        unsigned combinedCases = 0, combinedFailures = 0;
        double combinedMaxError = 0;
        auto combined = [&](int heading) {
            *ctx = R5900Context{};
            ctx->pc = 0x18f570;
            ctx->vu0_vf[0] = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
            constexpr uint32_t output = 0x1e00000;
            SET_GPR_U32(ctx, 4, output);
            SET_GPR_U32(ctx, 29, sp);
            SET_GPR_U32(ctx, 31, ra);
            for (int r = 16; r <= 23; ++r)
                SET_GPR_VEC(ctx, r, _mm_set_epi32(r + 3, r + 2, r + 1, r));
            ctx->f[12] = float(heading) * scale;
            std::memset(ram + output, 0xCD, 32);
            sub_0018F570_0x18f570(ram, ctx, &runtime);
            check(ctx->pc == ra && GPR_U32(ctx, 31) == ra && GPR_U32(ctx, 29) == sp,
                  "combined original return/RA/SP changed");
            for (int r = 16; r <= 23; ++r) {
                alignas(16) uint32_t v[4];
                _mm_store_si128(reinterpret_cast<__m128i*>(v), GPR_VEC(ctx, r));
                check(v[0] == unsigned(r) && v[1] == unsigned(r + 1) && v[2] == unsigned(r + 2) &&
                          v[3] == unsigned(r + 3),
                      "combined saved vector register changed");
            }
            float actual[4];
            std::memcpy(actual, ram + output, sizeof(actual));
            const double angle = double(heading) * (6.2831853071795864769 / 65536.0);
            const double expected[2] = {std::sin(angle), std::cos(angle)};
            for (unsigned lane = 0; lane < 2; ++lane) {
                const double error = std::abs(double(actual[lane]) - expected[lane]);
                if (error > combinedMaxError)
                    combinedMaxError = error;
                if (!std::isfinite(actual[lane]) || error > 0.003) {
                    if (combinedFailures < 16)
                        std::fprintf(
                            stderr,
                            "combined heading=%d lane=%u actual=%.9g expected=%.9g error=%.9g\n",
                            heading, lane, actual[lane], expected[lane], error);
                    ++combinedFailures;
                }
            }
            for (unsigned i = 16; i < 32; ++i)
                check(ram[output + i] == 0xCD, "combined output overrun");
            ++combinedCases;
        };
        for (int heading = -65536; heading < 65536; ++heading)
            combined(heading);
        std::printf("%s: %u actual combined sine/cosine cases (two lanes), numerical failures=%u "
                    "max error=%.9g; original RA/SP and output extent preserved\n",
                    combinedFailures ? "FAIL" : "PASS", combinedCases, combinedFailures,
                    combinedMaxError);
        std::printf("%s: %u actual generated angle/main-trig cases, original tail "
                    "targets/RA/SP/saved registers; numerical failures=%u sign failures=%u max "
                    "error=%.9g at %08X cosine=%d actual=%.9g expected=%.9g\n",
                    numericFailures ? "FAIL" : "PASS", cases, numericFailures, signFailures,
                    maxError, worstInput, worstCosine, worstActual, worstExpected);
        if (numericFailures || combinedFailures)
            return 1;
        return 0;
    } catch (const std::exception& e) {
        std::fprintf(stderr, "FAIL: %s\n", e.what());
        return 1;
    }
}

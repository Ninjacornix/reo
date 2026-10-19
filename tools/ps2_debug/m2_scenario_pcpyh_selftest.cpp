// Compile the actual guest memset and actual emitted PCPYH expressions.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <cstdio>
#include <cstring>
#include <initializer_list>
#include <stdexcept>
#include "pcpyh_emitted.inc"

void sub_00107C68_0x107c68(uint8_t*, R5900Context*, PS2Runtime*);
static void check(bool value, const char* reason) {
    if (!value)
        throw std::runtime_error(reason);
}

int main() {
    try {
        PS2Runtime runtime;
        check(runtime.memory().initialize(), "RAM initialization");
        auto* ram = runtime.memory().getRDRAM();
        auto* ctx = &runtime.cpu();
        const uint32_t base = 0x110000, ra = 0x100008, sp = 0x1f00000;
        unsigned cases = 0;
        for (unsigned offset = 0; offset < 16; ++offset)
            for (unsigned length = 0; length <= 65; ++length)
                for (unsigned value : {0u, 0xffu, 0x5au, 0x1a5u}) {
                    uint8_t expected[128];
                    std::memset(expected, 0xcd, sizeof(expected));
                    std::memset(expected + 16 + offset, value, length);
                    std::memset(ram + base, 0xcd, sizeof(expected));
                    ctx->pc = 0x107c68;
                    SET_GPR_U32(ctx, 4, base + 16 + offset);
                    SET_GPR_U32(ctx, 5, value);
                    SET_GPR_U32(ctx, 6, length);
                    SET_GPR_U32(ctx, 29, sp);
                    SET_GPR_U32(ctx, 31, ra);
                    for (int r = 16; r <= 23; ++r)
                        SET_GPR_VEC(ctx, r, _mm_set_epi32(r + 3, r + 2, r + 1, r));
                    sub_00107C68_0x107c68(ram, ctx, &runtime);
                    check(ctx->pc == ra, "memset must return to original RA");
                    check(GPR_U32(ctx, 2) == base + 16 + offset, "memset must return destination");
                    check(GPR_U32(ctx, 29) == sp && GPR_U32(ctx, 31) == ra,
                          "memset must preserve SP and RA");
                    check(GPR_U32(ctx, 4) == base + 16 + offset,
                          "memset must preserve destination argument");
                    for (int r = 16; r <= 23; ++r) {
                        alignas(16) uint32_t words[4];
                        _mm_store_si128((__m128i*)words, GPR_VEC(ctx, r));
                        check(words[0] == unsigned(r) && words[1] == unsigned(r + 1) &&
                                  words[2] == unsigned(r + 2) && words[3] == unsigned(r + 3),
                              "memset must preserve saved vector registers");
                    }
                    check(std::memcmp(ram + base, expected, sizeof(expected)) == 0,
                          "actual guest memset fill or boundary mismatch");
                    ++cases;
                }
        // A realistic cold cache must invalidate Kevin's zero-valued identity.
        std::memset(ram + 0x7434b0, 0, 32);
        ctx->pc = 0x107c68;
        SET_GPR_U32(ctx, 4, 0x7434b0);
        SET_GPR_U32(ctx, 5, 0xff);
        SET_GPR_U32(ctx, 6, 20);
        SET_GPR_U32(ctx, 31, ra);
        sub_00107C68_0x107c68(ram, ctx, &runtime);
        for (int i = 0; i < 20; ++i)
            check(ram[0x7434b0 + i] == 0xff,
                  "original 20-byte model cache reset must invalidate every slot");
        for (int i = 20; i < 32; ++i)
            check(ram[0x7434b0 + i] == 0, "model cache reset must not extend past 20 bytes");
        struct InstructionCase {
            void (*run)(R5900Context*);
            int source, dest;
        };
        const InstructionCase instructions[] = {
            {emitted_107988, 10, 8}, {emitted_107c94, 8, 3}, {emitted_14a89c, 11, 11}};
        const uint16_t input[8] = {0x1234, 0x2222, 0x3333, 0x4444, 0xabcd, 0x6666, 0x7777, 0x8888};
        for (const auto& instruction : instructions) {
            SET_GPR_VEC(ctx, 0, _mm_setzero_si128());
            SET_GPR_VEC(ctx, instruction.source, _mm_loadu_si128((const __m128i*)input));
            instruction.run(ctx);
            uint16_t output[8];
            _mm_storeu_si128((__m128i*)output, GPR_VEC(ctx, instruction.dest));
            for (int i = 0; i < 8; ++i)
                check(output[i] == (i < 4 ? 0x1234 : 0xabcd),
                      "actual emitted PCPYH must broadcast rt low/high halfwords");
            check(GPR_U64(ctx, 0) == 0, "PCPYH must preserve zero register");
        }
        std::printf("PASS: %u actual memset cases, original 20-byte cache invalidation, three "
                    "production PCPYH source/lane cases\n",
                    cases);
        return 0;
    } catch (const std::exception& error) {
        std::fprintf(stderr, "FAIL: %s\n", error.what());
        return 1;
    }
}

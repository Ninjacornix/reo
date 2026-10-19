// Exercise the restored original guest functions with isolated SDK callees.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <cstdio>
#include <cstring>
#include <stdexcept>

void o1_00588200_0x588200(uint8_t*, R5900Context*, PS2Runtime*);
void sub_001F73B0_0x1f73b0(uint8_t*, R5900Context*, PS2Runtime*);
static int copies, colors, packets, polls, completions, resets;
static int pollResult;
static void check(bool condition, const char* reason) {
    if (!condition)
        throw std::runtime_error(reason);
}
static void done(R5900Context* ctx) {
    ctx->pc = GPR_U32(ctx, 31);
}
static void copy(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    ++copies;
    std::memmove(ram + GPR_U32(ctx, 4), ram + GPR_U32(ctx, 5), GPR_U32(ctx, 6));
    done(ctx);
}
static void templateCopy(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    ++copies;
    done(ctx);
}
static void color(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    ++colors;
    SET_GPR_U32(ctx, 2, 0x80808080);
    done(ctx);
}
static void submit(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    check(GPR_U32(ctx, 4) == 0x70000000, "sprite must submit its scratchpad packet");
    ++packets;
    done(ctx);
}
static void poll(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    ++polls;
    SET_GPR_S32(ctx, 2, pollResult);
    done(ctx);
}
static void completed(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    ++completions;
    done(ctx);
}
static void reset(uint8_t*, R5900Context* ctx, PS2Runtime*) {
    ++resets;
    done(ctx);
}

int main() {
    try {
        PS2Runtime runtime;
        check(runtime.memory().initialize(), "RAM initialize");
        uint8_t* ram = runtime.memory().getRDRAM();
        auto& ctx = runtime.cpu();
        R5900Context* ctxPtr = &ctx;
        runtime.registerFunction(0x189b08, templateCopy);
        runtime.registerFunction(0x198b60, color);
        runtime.registerFunction(0x193e20, submit);
        runtime.registerFunction(0x107ab0, copy);
        runtime.registerFunction(0x709b40, poll);
        runtime.registerFunction(0x1f71f0, completed);
        runtime.registerFunction(0x1f71e0, reset);
        runtime.registerFunction(0x1f7160, reset);
        const uint32_t sp = 0x1f00000, ra = 0x100008;
        auto prepare = [&](uint32_t pc) {
            ctx.pc = pc;
            SET_GPR_U32(&ctx, 29, sp);
            SET_GPR_U32(&ctx, 31, ra);
        };
        auto returnCheck = [&]() {
            check(ctx.pc == ra, "original return address restored");
            check(GPR_U32(ctxPtr, 29) == sp, "original stack pointer restored");
        };
        const uint32_t width = 640, height = 448, frame = 1;
        std::memcpy(ram + 0x29f9bc, &width, 4);
        std::memcpy(ram + 0x29f9c0, &height, 4);
        std::memcpy(ram + 0x29f9b4, &frame, 4);
        const int16_t sprite[] = {10, 20, 30, 40, -1, -1, 0, 0, 30, 40};
        std::memcpy(ram + 0x100000, sprite, sizeof(sprite));
        prepare(0x588200);
        SET_GPR_U32(&ctx, 4, 0x100000);
        SET_GPR_U32(&ctx, 5, 0x12345678);
        for (int r = 16; r <= 21; ++r)
            SET_GPR_U64(&ctx, r, 0x1100000000ull + r);
        o1_00588200_0x588200(ram, &ctx, &runtime);
        returnCheck();
        check(copies == 1 && colors == 1 && packets == 1,
              "sprite must reach original final packet submit");
        for (int r = 16; r <= 21; ++r)
            check(GPR_U64(ctxPtr, r) == 0x1100000000ull + r,
                  "callee-saved sprite registers restored");
        const uint32_t disabled = 1;
        std::memcpy(ram + 0x29fda4, &disabled, 4);
        prepare(0x588200);
        o1_00588200_0x588200(ram, &ctx, &runtime);
        returnCheck();
        check(packets == 1, "disabled renderer must restore context without submitting");
        std::memset(ram + 0x36f080, 0, 0x60);
        prepare(0x1f73b0);
        sub_001F73B0_0x1f73b0(ram, &ctx, &runtime);
        returnCheck();
        check(GPR_S64(ctxPtr, 2) == 1 && ram[0x36f0c0] == 1,
              "no progress payload must complete immediately");
        ram[0x36f0c0] = 0xff;
        prepare(0x1f73b0);
        sub_001F73B0_0x1f73b0(ram, &ctx, &runtime);
        returnCheck();
        check(GPR_S64(ctxPtr, 2) == -1, "cached error status must remain signed");
        ram[0x36f0c0] = 0;
        const uint32_t payload = 0x100000;
        std::memcpy(ram + 0x36f094, &payload, 4);
        std::memset(ram + 0x35f080, 0x5a, 0x8000);
        prepare(0x1f73b0);
        sub_001F73B0_0x1f73b0(ram, &ctx, &runtime);
        returnCheck();
        check(GPR_S64(ctxPtr, 2) == 0 && ram[0x36f0d8] == 2,
              "payload preparation advances original phase");
        check(std::memcmp(ram + 0x35f080, ram + 0x367080, 0x8000) == 0,
              "payload copy matches original");
        pollResult = 0;
        prepare(0x1f73b0);
        sub_001F73B0_0x1f73b0(ram, &ctx, &runtime);
        returnCheck();
        check(polls == 1 && ram[0x36f0d8] == 3 && GPR_S64(ctxPtr, 2) == 0,
              "busy progress poll remains pending");
        pollResult = 5;
        prepare(0x1f73b0);
        sub_001F73B0_0x1f73b0(ram, &ctx, &runtime);
        returnCheck();
        check(completions == 1 && GPR_S64(ctxPtr, 2) == 2 && ram[0x36f0d8] == 0,
              "successful payload completes and resets phase");
        ram[0x36f0c0] = 0;
        ram[0x36f0d8] = 3;
        pollResult = -1;
        prepare(0x1f73b0);
        sub_001F73B0_0x1f73b0(ram, &ctx, &runtime);
        returnCheck();
        check(resets == 2 && GPR_S64(ctxPtr, 2) == -1 && ram[0x36f0d8] == 0,
              "failed payload performs both original resets");
        std::puts("PASS: sprite submit/disabled path/context restoration; progress "
                  "cold/cached/payload/busy/success/error");
        return 0;
    } catch (const std::exception& error) {
        std::fprintf(stderr, "FAIL: %s\n", error.what());
        return 1;
    }
}

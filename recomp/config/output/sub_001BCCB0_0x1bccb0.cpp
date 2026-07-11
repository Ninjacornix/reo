#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001BCCB0
// Address: 0x1bccb0 - 0x1bcd30
void sub_001BCCB0_0x1bccb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1bccb0u;

    // 0x1bccb0: 0x27bdfff0
    ctx->pc = 0x1bccb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bccb4: 0xffbf0000
    ctx->pc = 0x1bccb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bccb8: 0xc06c8b0
    ctx->pc = 0x1BCCB8u;
    SET_GPR_U32(ctx, 31, 0x1BCCC0u);
    ctx->pc = 0x1B22C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B22C0_0x1b22c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCC0u; }
    }
    if (ctx->pc != 0x1BCCC0u) { return; }
    ctx->pc = 0x1BCCC0u;
    // 0x1bccc0: 0xc06c8d0
    ctx->pc = 0x1BCCC0u;
    SET_GPR_U32(ctx, 31, 0x1BCCC8u);
    ctx->pc = 0x1B2340u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2340_0x1b2340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCC8u; }
    }
    if (ctx->pc != 0x1BCCC8u) { return; }
    ctx->pc = 0x1BCCC8u;
    // 0x1bccc8: 0xc06bda8
    ctx->pc = 0x1BCCC8u;
    SET_GPR_U32(ctx, 31, 0x1BCCD0u);
    ctx->pc = 0x1BCCCCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AF6A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF6A0_0x1af6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCD0u; }
    }
    if (ctx->pc != 0x1BCCD0u) { return; }
    ctx->pc = 0x1BCCD0u;
    // 0x1bccd0: 0xc06bc30
    ctx->pc = 0x1BCCD0u;
    SET_GPR_U32(ctx, 31, 0x1BCCD8u);
    ctx->pc = 0x1BCCD4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AF0C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF0C0_0x1af0c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCD8u; }
    }
    if (ctx->pc != 0x1BCCD8u) { return; }
    ctx->pc = 0x1BCCD8u;
    // 0x1bccd8: 0x3c04001c
    ctx->pc = 0x1bccd8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)28 << 16));
    // 0x1bccdc: 0x2405000a
    ctx->pc = 0x1bccdcu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 10));
    // 0x1bcce0: 0xc06dfb8
    ctx->pc = 0x1BCCE0u;
    SET_GPR_U32(ctx, 31, 0x1BCCE8u);
    ctx->pc = 0x1BCCE4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294949104));
    ctx->pc = 0x1B7EE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7EE0_0x1b7ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCE8u; }
    }
    if (ctx->pc != 0x1BCCE8u) { return; }
    ctx->pc = 0x1BCCE8u;
    // 0x1bcce8: 0x3c04001c
    ctx->pc = 0x1bcce8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)28 << 16));
    // 0x1bccec: 0x2405000b
    ctx->pc = 0x1bccecu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 11));
    // 0x1bccf0: 0xc06dfb8
    ctx->pc = 0x1BCCF0u;
    SET_GPR_U32(ctx, 31, 0x1BCCF8u);
    ctx->pc = 0x1BCCF4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294947968));
    ctx->pc = 0x1B7EE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7EE0_0x1b7ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCF8u; }
    }
    if (ctx->pc != 0x1BCCF8u) { return; }
    ctx->pc = 0x1BCCF8u;
    // 0x1bccf8: 0x3c010032
    ctx->pc = 0x1bccf8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bccfc: 0xc074ee4
    ctx->pc = 0x1BCCFCu;
    SET_GPR_U32(ctx, 31, 0x1BCD04u);
    ctx->pc = 0x1BCD00u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17344), (uint8_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1D3B90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3B90_0x1d3b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD04u; }
    }
    if (ctx->pc != 0x1BCD04u) { return; }
    ctx->pc = 0x1BCD04u;
    // 0x1bcd04: 0xc0747f0
    ctx->pc = 0x1BCD04u;
    SET_GPR_U32(ctx, 31, 0x1BCD0Cu);
    ctx->pc = 0x1D1FC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1FC0_0x1d1fc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD0Cu; }
    }
    if (ctx->pc != 0x1BCD0Cu) { return; }
    ctx->pc = 0x1BCD0Cu;
    // 0x1bcd0c: 0xc06cf64
    ctx->pc = 0x1BCD0Cu;
    SET_GPR_U32(ctx, 31, 0x1BCD14u);
    ctx->pc = 0x1B3D90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3D90_0x1b3d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD14u; }
    }
    if (ctx->pc != 0x1BCD14u) { return; }
    ctx->pc = 0x1BCD14u;
    // 0x1bcd14: 0xdfbf0000
    ctx->pc = 0x1bcd14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bcd18: 0x3e00008
    ctx->pc = 0x1BCD18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BCD1Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BCD20u;
    // 0x1bcd20: 0x80748a0
    ctx->pc = 0x1BCD20u;
    ctx->pc = 0x1D2280u;
    entry_1d2280_0x1d25b0(rdram, ctx, runtime); return;
    ctx->pc = 0x1BCD28u;
    // 0x1bcd28: 0x0
    ctx->pc = 0x1bcd28u;
    // NOP
    // 0x1bcd2c: 0x0
    ctx->pc = 0x1bcd2cu;
    // NOP
}

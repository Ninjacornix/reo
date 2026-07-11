#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018DCB0
// Address: 0x18dcb0 - 0x18dce0
void sub_0018DCB0_0x18dcb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18dcb0u;

    // 0x18dcb0: 0x27bdfff0
    ctx->pc = 0x18dcb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18dcb4: 0xffbf0000
    ctx->pc = 0x18dcb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x18dcb8: 0xc0635b0
    ctx->pc = 0x18DCB8u;
    SET_GPR_U32(ctx, 31, 0x18DCC0u);
    ctx->pc = 0x18D6C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D6C0_0x18d6c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DCC0u; }
    }
    if (ctx->pc != 0x18DCC0u) { return; }
    ctx->pc = 0x18DCC0u;
    // 0x18dcc0: 0xc068364
    ctx->pc = 0x18DCC0u;
    SET_GPR_U32(ctx, 31, 0x18DCC8u);
    ctx->pc = 0x1A0D90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0D90_0x1a0d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DCC8u; }
    }
    if (ctx->pc != 0x18DCC8u) { return; }
    ctx->pc = 0x18DCC8u;
    // 0x18dcc8: 0xc063000
    ctx->pc = 0x18DCC8u;
    SET_GPR_U32(ctx, 31, 0x18DCD0u);
    ctx->pc = 0x18C000u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C000_0x18c000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DCD0u; }
    }
    if (ctx->pc != 0x18DCD0u) { return; }
    ctx->pc = 0x18DCD0u;
    // 0x18dcd0: 0xdfbf0000
    ctx->pc = 0x18dcd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18dcd4: 0x3e00008
    ctx->pc = 0x18DCD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DCD8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18DCDCu;
    // 0x18dcdc: 0x0
    ctx->pc = 0x18dcdcu;
    // NOP
}

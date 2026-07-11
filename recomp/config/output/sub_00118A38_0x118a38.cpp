#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00118A38
// Address: 0x118a38 - 0x118a70
void sub_00118A38_0x118a38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x118a38u;

    // 0x118a38: 0x27bdfff0
    ctx->pc = 0x118a38u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x118a3c: 0x3c020021
    ctx->pc = 0x118a3cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x118a40: 0x3c040026
    ctx->pc = 0x118a40u;
    SET_GPR_U32(ctx, 4, ((uint32_t)38 << 16));
    // 0x118a44: 0xffbf0000
    ctx->pc = 0x118a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x118a48: 0xac409ddc
    ctx->pc = 0x118a48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942172), GPR_U32(ctx, 0));
    // 0x118a4c: 0x2484e168
    ctx->pc = 0x118a4cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294959464));
    // 0x118a50: 0x282d
    ctx->pc = 0x118a50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118a54: 0xc041f1a
    ctx->pc = 0x118A54u;
    SET_GPR_U32(ctx, 31, 0x118A5Cu);
    ctx->pc = 0x118A58u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118A5Cu; }
    }
    if (ctx->pc != 0x118A5Cu) { return; }
    ctx->pc = 0x118A5Cu;
    // 0x118a5c: 0xdfbf0000
    ctx->pc = 0x118a5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x118a60: 0x102d
    ctx->pc = 0x118a60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118a64: 0x3e00008
    ctx->pc = 0x118A64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118A68u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x118A6Cu;
    // 0x118a6c: 0x0
    ctx->pc = 0x118a6cu;
    // NOP
}

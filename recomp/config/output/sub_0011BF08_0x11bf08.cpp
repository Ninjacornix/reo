#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011BF08
// Address: 0x11bf08 - 0x11bf40
void sub_0011BF08_0x11bf08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11bf08u;

    // 0x11bf08: 0x27bdfff0
    ctx->pc = 0x11bf08u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11bf0c: 0x3c020021
    ctx->pc = 0x11bf0cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x11bf10: 0x2403ffff
    ctx->pc = 0x11bf10u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11bf14: 0x3c040026
    ctx->pc = 0x11bf14u;
    SET_GPR_U32(ctx, 4, ((uint32_t)38 << 16));
    // 0x11bf18: 0xffbf0000
    ctx->pc = 0x11bf18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11bf1c: 0x2484e628
    ctx->pc = 0x11bf1cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294960680));
    // 0x11bf20: 0xac439e00
    ctx->pc = 0x11bf20u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942208), GPR_U32(ctx, 3));
    // 0x11bf24: 0x282d
    ctx->pc = 0x11bf24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bf28: 0xc041f1a
    ctx->pc = 0x11BF28u;
    SET_GPR_U32(ctx, 31, 0x11BF30u);
    ctx->pc = 0x11BF2Cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BF30u; }
    }
    if (ctx->pc != 0x11BF30u) { return; }
    ctx->pc = 0x11BF30u;
    // 0x11bf30: 0xdfbf0000
    ctx->pc = 0x11bf30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11bf34: 0x102d
    ctx->pc = 0x11bf34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bf38: 0x3e00008
    ctx->pc = 0x11BF38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BF3Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11BF40u;
}

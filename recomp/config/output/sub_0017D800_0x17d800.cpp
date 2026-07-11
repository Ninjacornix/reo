#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0017D800
// Address: 0x17d800 - 0x17d828
void sub_0017D800_0x17d800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x17d800u;

    // 0x17d800: 0x10800007
    ctx->pc = 0x17D800u;
    {
        const bool branch_taken_0x17d800 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        if (branch_taken_0x17d800) {
            ctx->pc = 0x17D820u;
            goto label_17d820;
        }
    }
    ctx->pc = 0x17D808u;
    // 0x17d808: 0xac800000
    ctx->pc = 0x17d808u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x17d80c: 0x3c030023
    ctx->pc = 0x17d80cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x17d810: 0x2463f748
    ctx->pc = 0x17d810u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294965064));
    // 0x17d814: 0x8c620000
    ctx->pc = 0x17d814u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17d818: 0x2442ffff
    ctx->pc = 0x17d818u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x17d81c: 0xac620000
    ctx->pc = 0x17d81cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_17d820:
    // 0x17d820: 0x3e00008
    ctx->pc = 0x17D820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D820u: goto label_17d820;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D828u;
}

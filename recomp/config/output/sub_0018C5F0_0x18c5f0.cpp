#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018C5F0
// Address: 0x18c5f0 - 0x18c620
void sub_0018C5F0_0x18c5f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18c5f0u;

    // 0x18c5f0: 0x3c031000
    ctx->pc = 0x18c5f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x18c5f4: 0x7c800000
    ctx->pc = 0x18c5f4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 0));
    // 0x18c5f8: 0xa31821
    ctx->pc = 0x18c5f8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18c5fc: 0x24020001
    ctx->pc = 0x18c5fcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x18c600: 0x14c20005
    ctx->pc = 0x18C600u;
    {
        const bool branch_taken_0x18c600 = (GPR_U32(ctx, 6) != GPR_U32(ctx, 2));
        ctx->pc = 0x18C604u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x18c600) {
            ctx->pc = 0x18C618u;
            goto label_18c618;
        }
    }
    ctx->pc = 0x18C608u;
    // 0x18c608: 0x8c830000
    ctx->pc = 0x18c608u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18c60c: 0x3c028000
    ctx->pc = 0x18c60cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
    // 0x18c610: 0x621025
    ctx->pc = 0x18c610u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18c614: 0xac820000
    ctx->pc = 0x18c614u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_18c618:
    // 0x18c618: 0x3e00008
    ctx->pc = 0x18C618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C61Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C618u: goto label_18c618;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C620u;
}

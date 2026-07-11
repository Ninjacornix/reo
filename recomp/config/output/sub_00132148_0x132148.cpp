#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00132148
// Address: 0x132148 - 0x132160
void sub_00132148_0x132148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x132148u;

    // 0x132148: 0x3c030022
    ctx->pc = 0x132148u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13214c: 0x2463b75c
    ctx->pc = 0x13214cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294948700));
    // 0x132150: 0x8c620000
    ctx->pc = 0x132150u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x132154: 0x24420001
    ctx->pc = 0x132154u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x132158: 0x3e00008
    ctx->pc = 0x132158u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13215Cu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x132160u;
}

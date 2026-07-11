#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013F218
// Address: 0x13f218 - 0x13f230
void sub_0013F218_0x13f218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13f218u;

    // 0x13f218: 0x3c030022
    ctx->pc = 0x13f218u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13f21c: 0x24634758
    ctx->pc = 0x13f21cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 18264));
    // 0x13f220: 0x8c620000
    ctx->pc = 0x13f220u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13f224: 0x24420001
    ctx->pc = 0x13f224u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x13f228: 0x3e00008
    ctx->pc = 0x13F228u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F22Cu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F230u;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012C918
// Address: 0x12c918 - 0x12c930
void sub_0012C918_0x12c918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12c918u;

    // 0x12c918: 0x3c030021
    ctx->pc = 0x12c918u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12c91c: 0x24637d80
    ctx->pc = 0x12c91cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 32128));
    // 0x12c920: 0x8c620000
    ctx->pc = 0x12c920u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12c924: 0x24420001
    ctx->pc = 0x12c924u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x12c928: 0x3e00008
    ctx->pc = 0x12C928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C92Cu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12C930u;
}

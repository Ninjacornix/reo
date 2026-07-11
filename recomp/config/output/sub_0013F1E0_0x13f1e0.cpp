#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013F1E0
// Address: 0x13f1e0 - 0x13f218
void sub_0013F1E0_0x13f1e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13f1e0u;

    // 0x13f1e0: 0x52880
    ctx->pc = 0x13f1e0u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 2));
    // 0x13f1e4: 0x852021
    ctx->pc = 0x13f1e4u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x13f1e8: 0x8c830008
    ctx->pc = 0x13f1e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13f1ec: 0x3e00008
    ctx->pc = 0x13F1ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F1F0u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F1F4u;
    // 0x13f1f4: 0x0
    ctx->pc = 0x13f1f4u;
    // NOP
    // 0x13f1f8: 0x3c020022
    ctx->pc = 0x13f1f8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13f1fc: 0x3e00008
    ctx->pc = 0x13F1FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F200u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 18264), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F204u;
    // 0x13f204: 0x0
    ctx->pc = 0x13f204u;
    // NOP
    // 0x13f208: 0x3c020022
    ctx->pc = 0x13f208u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13f20c: 0x3e00008
    ctx->pc = 0x13F20Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F210u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 18264), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F214u;
    // 0x13f214: 0x0
    ctx->pc = 0x13f214u;
    // NOP
}

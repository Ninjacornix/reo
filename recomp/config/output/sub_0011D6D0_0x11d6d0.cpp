#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011D6D0
// Address: 0x11d6d0 - 0x11d728
void sub_0011D6D0_0x11d6d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11d6d0u;

    // 0x11d6d0: 0x27bdffb0
    ctx->pc = 0x11d6d0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11d6d4: 0x24020001
    ctx->pc = 0x11d6d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x11d6d8: 0xffbf0040
    ctx->pc = 0x11d6d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11d6dc: 0x3a0202d
    ctx->pc = 0x11d6dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d6e0: 0xafa20028
    ctx->pc = 0x11d6e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x11d6e4: 0xafa20004
    ctx->pc = 0x11d6e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x11d6e8: 0xafa20008
    ctx->pc = 0x11d6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x11d6ec: 0xc045188
    ctx->pc = 0x11D6ECu;
    SET_GPR_U32(ctx, 31, 0x11D6F4u);
    ctx->pc = 0x11D6F0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
    ctx->pc = 0x114620u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D6F4u; }
    }
    if (ctx->pc != 0x11D6F4u) { return; }
    ctx->pc = 0x11D6F4u;
    // 0x11d6f4: 0x3c030021
    ctx->pc = 0x11d6f4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x11d6f8: 0x27a40020
    ctx->pc = 0x11d6f8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x11d6fc: 0xc045188
    ctx->pc = 0x11D6FCu;
    SET_GPR_U32(ctx, 31, 0x11D704u);
    ctx->pc = 0x11D700u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294943856), GPR_U32(ctx, 2));
    ctx->pc = 0x114620u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D704u; }
    }
    if (ctx->pc != 0x11D704u) { return; }
    ctx->pc = 0x11D704u;
    // 0x11d704: 0x3c030021
    ctx->pc = 0x11d704u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x11d708: 0xdfbf0040
    ctx->pc = 0x11d708u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11d70c: 0xac62a474
    ctx->pc = 0x11d70cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294943860), GPR_U32(ctx, 2));
    // 0x11d710: 0x3e00008
    ctx->pc = 0x11D710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D714u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D718u;
    // 0x11d718: 0x3c030021
    ctx->pc = 0x11d718u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x11d71c: 0x3e00008
    ctx->pc = 0x11D71Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D720u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4294943860)));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D724u;
    // 0x11d724: 0x0
    ctx->pc = 0x11d724u;
    // NOP
}

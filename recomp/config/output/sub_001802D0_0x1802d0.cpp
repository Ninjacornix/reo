#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001802D0
// Address: 0x1802d0 - 0x180310
void sub_001802D0_0x1802d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1802d0u;

    // 0x1802d0: 0x24030001
    ctx->pc = 0x1802d0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1802d4: 0x3c020023
    ctx->pc = 0x1802d4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1802d8: 0x3c040027
    ctx->pc = 0x1802d8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)39 << 16));
    // 0x1802dc: 0xac43f9e0
    ctx->pc = 0x1802dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294965728), GPR_U32(ctx, 3));
    // 0x1802e0: 0x24846188
    ctx->pc = 0x1802e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 24968));
    // 0x1802e4: 0x24833340
    ctx->pc = 0x1802e4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 4), 13120));
label_1802e8:
    // 0x1802e8: 0xac800000
    ctx->pc = 0x1802e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1802ec: 0xac800004
    ctx->pc = 0x1802ecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x1802f0: 0xac800008
    ctx->pc = 0x1802f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1802f4: 0xac80000c
    ctx->pc = 0x1802f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x1802f8: 0x24840334
    ctx->pc = 0x1802f8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 820));
    // 0x1802fc: 0x83102a
    ctx->pc = 0x1802fcu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 4), GPR_S32(ctx, 3)));
    // 0x180300: 0x1440fff9
    ctx->pc = 0x180300u;
    {
        const bool branch_taken_0x180300 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x180300) {
            ctx->pc = 0x1802E8u;
            goto label_1802e8;
        }
    }
    ctx->pc = 0x180308u;
    // 0x180308: 0x3e00008
    ctx->pc = 0x180308u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18030Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1802E8u: goto label_1802e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180310u;
}

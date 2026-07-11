#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013D4D0
// Address: 0x13d4d0 - 0x13d4f8
void sub_0013D4D0_0x13d4d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13d4d0u;

    // 0x13d4d0: 0x14800005
    ctx->pc = 0x13D4D0u;
    {
        const bool branch_taken_0x13d4d0 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x13D4D4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
        if (branch_taken_0x13d4d0) {
            ctx->pc = 0x13D4E8u;
            goto label_13d4e8;
        }
    }
    ctx->pc = 0x13D4D8u;
    // 0x13d4d8: 0x3c030022
    ctx->pc = 0x13d4d8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13d4dc: 0xac40dfe8
    ctx->pc = 0x13d4dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294959080), GPR_U32(ctx, 0));
    // 0x13d4e0: 0x3e00008
    ctx->pc = 0x13D4E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D4E4u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294959084), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D4E8u: goto label_13d4e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D4E8u;
label_13d4e8:
    // 0x13d4e8: 0x3c030022
    ctx->pc = 0x13d4e8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x13d4ec: 0xac44dfe8
    ctx->pc = 0x13d4ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294959080), GPR_U32(ctx, 4));
    // 0x13d4f0: 0x3e00008
    ctx->pc = 0x13D4F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D4F4u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294959084), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D4E8u: goto label_13d4e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D4F8u;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D4D0
// Address: 0x13d4d0 - 0x13d4f8
void sub_0013D4D0_0x13d4d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D4D0_0x13d4d0");
#endif

    ctx->pc = 0x13d4d0u;

    // 0x13d4d0: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13D4D0u;
    {
        const bool branch_taken_0x13d4d0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D4D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D4D0u;
            // 0x13d4d4: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d4d0) {
            ctx->pc = 0x13D4E8u;
            goto label_13d4e8;
        }
    }
    ctx->pc = 0x13D4D8u;
    // 0x13d4d8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13d4d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13d4dc: 0xac40dfe8  sw          $zero, -0x2018($v0)
    ctx->pc = 0x13d4dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294959080), GPR_U32(ctx, 0));
    // 0x13d4e0: 0x3e00008  jr          $ra
    ctx->pc = 0x13D4E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D4E0u;
            // 0x13d4e4: 0xac60dfec  sw          $zero, -0x2014($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294959084), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D4E8u: goto label_13d4e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D4E8u;
label_13d4e8:
    // 0x13d4e8: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13d4e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13d4ec: 0xac44dfe8  sw          $a0, -0x2018($v0)
    ctx->pc = 0x13d4ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294959080), GPR_U32(ctx, 4));
    // 0x13d4f0: 0x3e00008  jr          $ra
    ctx->pc = 0x13D4F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D4F0u;
            // 0x13d4f4: 0xac65dfec  sw          $a1, -0x2014($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294959084), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D4E8u: goto label_13d4e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D4F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

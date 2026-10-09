#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD4B0
// Address: 0x1ad4b0 - 0x1ad4e0
void sub_001AD4B0_0x1ad4b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD4B0_0x1ad4b0");
#endif

    ctx->pc = 0x1ad4b0u;

    // 0x1ad4b0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad4b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad4b4: 0xac24382c  sw          $a0, 0x382C($at)
    ctx->pc = 0x1ad4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14380), GPR_U32(ctx, 4));
    // 0x1ad4b8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad4b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad4bc: 0xac253830  sw          $a1, 0x3830($at)
    ctx->pc = 0x1ad4bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14384), GPR_U32(ctx, 5));
    // 0x1ad4c0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad4c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad4c4: 0xac203810  sw          $zero, 0x3810($at)
    ctx->pc = 0x1ad4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14352), GPR_U32(ctx, 0));
    // 0x1ad4c8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad4c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad4cc: 0xac203824  sw          $zero, 0x3824($at)
    ctx->pc = 0x1ad4ccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14372), GPR_U32(ctx, 0));
    // 0x1ad4d0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad4d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad4d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD4D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD4D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD4D4u;
            // 0x1ad4d8: 0xac203828  sw          $zero, 0x3828($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 14376), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1AD4DCu;
    // 0x1ad4dc: 0x0  nop
    ctx->pc = 0x1ad4dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

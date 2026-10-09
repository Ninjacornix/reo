#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7850
// Address: 0x1b7850 - 0x1b786c
void sub_001B7850_0x1b7850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7850_0x1b7850");
#endif

    ctx->pc = 0x1b7850u;

    // 0x1b7850: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b7850u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7854: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7854u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7858: 0xac640070  sw          $a0, 0x70($v1)
    ctx->pc = 0x1b7858u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 112), GPR_U32(ctx, 4));
    // 0x1b785c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b785cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b7860: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b7860u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b7864: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7864u;
            // 0x1b7868: 0xac650074  sw          $a1, 0x74($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 116), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B786Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

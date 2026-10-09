#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5650
// Address: 0x1b5650 - 0x1b5670
void sub_001B5650_0x1b5650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5650_0x1b5650");
#endif

    ctx->pc = 0x1b5650u;

    // 0x1b5650: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b5650u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b5654: 0x8c234768  lw          $v1, 0x4768($at)
    ctx->pc = 0x1b5654u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b5658: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B565Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5658u;
            // 0x1b565c: 0xac640080  sw          $a0, 0x80($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 128), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B5660u;
    // 0x1b5660: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b5660u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b5664: 0x8c224768  lw          $v0, 0x4768($at)
    ctx->pc = 0x1b5664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18280)));
    // 0x1b5668: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5668u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B566Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5668u;
            // 0x1b566c: 0x8c420080  lw          $v0, 0x80($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 128)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1B5670u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

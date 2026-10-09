#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148008
// Address: 0x148008 - 0x148020
void sub_00148008_0x148008(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148008_0x148008");
#endif

    ctx->pc = 0x148008u;

    // 0x148008: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148008u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14800c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x14800cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148010: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x148010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148014: 0xfc650090  sd          $a1, 0x90($v1)
    ctx->pc = 0x148014u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 144), GPR_U64(ctx, 5));
    // 0x148018: 0x3e00008  jr          $ra
    ctx->pc = 0x148018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14801Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148018u;
            // 0x14801c: 0xac64008c  sw          $a0, 0x8C($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 140), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148020u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

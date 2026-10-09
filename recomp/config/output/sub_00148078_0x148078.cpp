#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148078
// Address: 0x148078 - 0x148084
void sub_00148078_0x148078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148078_0x148078");
#endif

    ctx->pc = 0x148078u;

    // 0x148078: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x148078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14807c: 0x3e00008  jr          $ra
    ctx->pc = 0x14807Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14807Cu;
            // 0x148080: 0x244200cc  addiu       $v0, $v0, 0xCC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 204));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148084u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

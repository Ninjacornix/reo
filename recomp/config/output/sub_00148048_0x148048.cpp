#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148048
// Address: 0x148048 - 0x148054
void sub_00148048_0x148048(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148048_0x148048");
#endif

    ctx->pc = 0x148048u;

    // 0x148048: 0x8c830040  lw          $v1, 0x40($a0)
    ctx->pc = 0x148048u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x14804c: 0x3e00008  jr          $ra
    ctx->pc = 0x14804Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14804Cu;
            // 0x148050: 0x8c6200e4  lw          $v0, 0xE4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 228)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x148054u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

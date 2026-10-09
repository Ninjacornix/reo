#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001642D0
// Address: 0x1642d0 - 0x1642d8
void sub_001642D0_0x1642d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001642D0_0x1642d0");
#endif

    ctx->pc = 0x1642d0u;

    // 0x1642d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1642D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1642D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1642D0u;
            // 0x1642d4: 0x8c820064  lw          $v0, 0x64($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 100)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1642D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

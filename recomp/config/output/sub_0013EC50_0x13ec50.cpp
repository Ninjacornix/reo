#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EC50
// Address: 0x13ec50 - 0x13ec58
void sub_0013EC50_0x13ec50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EC50_0x13ec50");
#endif

    ctx->pc = 0x13ec50u;

    // 0x13ec50: 0x3e00008  jr          $ra
    ctx->pc = 0x13EC50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EC54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC50u;
            // 0x13ec54: 0xa0850024  sb          $a1, 0x24($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 36), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13EC58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

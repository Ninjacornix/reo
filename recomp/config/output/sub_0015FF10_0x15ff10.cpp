#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FF10
// Address: 0x15ff10 - 0x15ff18
void sub_0015FF10_0x15ff10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FF10_0x15ff10");
#endif

    ctx->pc = 0x15ff10u;

    // 0x15ff10: 0x3e00008  jr          $ra
    ctx->pc = 0x15FF10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FF14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF10u;
            // 0x15ff14: 0x8c820134  lw          $v0, 0x134($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 308)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15FF18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

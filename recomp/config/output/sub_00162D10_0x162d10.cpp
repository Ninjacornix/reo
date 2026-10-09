#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162D10
// Address: 0x162d10 - 0x162d18
void sub_00162D10_0x162d10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162D10_0x162d10");
#endif

    ctx->pc = 0x162d10u;

    // 0x162d10: 0x3e00008  jr          $ra
    ctx->pc = 0x162D10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162D10u;
            // 0x162d14: 0x8c8201f8  lw          $v0, 0x1F8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 504)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x162D18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

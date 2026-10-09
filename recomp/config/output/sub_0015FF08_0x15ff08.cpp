#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FF08
// Address: 0x15ff08 - 0x15ff10
void sub_0015FF08_0x15ff08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FF08_0x15ff08");
#endif

    ctx->pc = 0x15ff08u;

    // 0x15ff08: 0x3e00008  jr          $ra
    ctx->pc = 0x15FF08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF08u;
            // 0x15ff0c: 0x8c820044  lw          $v0, 0x44($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15FF10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

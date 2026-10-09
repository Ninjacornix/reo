#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D6F0
// Address: 0x12d6f0 - 0x12d6f8
void sub_0012D6F0_0x12d6f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D6F0_0x12d6f0");
#endif

    ctx->pc = 0x12d6f0u;

    // 0x12d6f0: 0x3e00008  jr          $ra
    ctx->pc = 0x12D6F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6F0u;
            // 0x12d6f4: 0x8c820034  lw          $v0, 0x34($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 52)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D6F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

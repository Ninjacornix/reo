#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D96F0
// Address: 0x1d96f0 - 0x1d96fc
void sub_001D96F0_0x1d96f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D96F0_0x1d96f0");
#endif

    ctx->pc = 0x1d96f0u;

    // 0x1d96f0: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d96f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d96f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D96F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D96F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96F4u;
            // 0x1d96f8: 0x24428c80  addiu       $v0, $v0, -0x7380 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937728));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D96FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

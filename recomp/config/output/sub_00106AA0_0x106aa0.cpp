#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106AA0
// Address: 0x106aa0 - 0x106aac
void sub_00106AA0_0x106aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106AA0_0x106aa0");
#endif

    ctx->pc = 0x106aa0u;

    // 0x106aa0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x106aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x106aa4: 0x3e00008  jr          $ra
    ctx->pc = 0x106AA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106AA4u;
            // 0x106aa8: 0x244278d0  addiu       $v0, $v0, 0x78D0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30928));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x106AACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

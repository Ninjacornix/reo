#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114DD0
// Address: 0x114dd0 - 0x114dd8
void sub_00114DD0_0x114dd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114DD0_0x114dd0");
#endif

    ctx->pc = 0x114dd0u;

    // 0x114dd0: 0x3e00008  jr          $ra
    ctx->pc = 0x114DD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114DD0u;
            // 0x114dd4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114DD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

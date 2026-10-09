#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DA30
// Address: 0x12da30 - 0x12da38
void sub_0012DA30_0x12da30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DA30_0x12da30");
#endif

    ctx->pc = 0x12da30u;

    // 0x12da30: 0x3e00008  jr          $ra
    ctx->pc = 0x12DA30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DA30u;
            // 0x12da34: 0x24820058  addiu       $v0, $a0, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 88));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12DA38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

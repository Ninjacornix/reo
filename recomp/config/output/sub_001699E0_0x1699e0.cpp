#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001699E0
// Address: 0x1699e0 - 0x1699ec
void sub_001699E0_0x1699e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001699E0_0x1699e0");
#endif

    ctx->pc = 0x1699e0u;

    // 0x1699e0: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1699e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1699e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1699E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1699E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1699E4u;
            // 0x1699e8: 0x24420790  addiu       $v0, $v0, 0x790 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1936));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1699ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

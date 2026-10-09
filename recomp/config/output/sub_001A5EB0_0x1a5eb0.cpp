#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5EB0
// Address: 0x1a5eb0 - 0x1a5ebc
void sub_001A5EB0_0x1a5eb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5EB0_0x1a5eb0");
#endif

    ctx->pc = 0x1a5eb0u;

    // 0x1a5eb0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5eb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5eb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5EB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5EB4u;
            // 0x1a5eb8: 0xa0240990  sb          $a0, 0x990($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 2448), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A5EBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

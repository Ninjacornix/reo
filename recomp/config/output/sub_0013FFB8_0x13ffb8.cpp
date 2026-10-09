#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013FFB8
// Address: 0x13ffb8 - 0x13ffc0
void sub_0013FFB8_0x13ffb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013FFB8_0x13ffb8");
#endif

    ctx->pc = 0x13ffb8u;

    // 0x13ffb8: 0x3e00008  jr          $ra
    ctx->pc = 0x13FFB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FFB8u;
            // 0x13ffbc: 0x8c82001c  lw          $v0, 0x1C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13FFC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

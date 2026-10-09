#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F7C8
// Address: 0x13f7c8 - 0x13f7d0
void sub_0013F7C8_0x13f7c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F7C8_0x13f7c8");
#endif

    ctx->pc = 0x13f7c8u;

    // 0x13f7c8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F7C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F7CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F7C8u;
            // 0x13f7cc: 0x8c820014  lw          $v0, 0x14($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F7D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

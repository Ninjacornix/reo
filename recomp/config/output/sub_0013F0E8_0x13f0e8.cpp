#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F0E8
// Address: 0x13f0e8 - 0x13f0f0
void sub_0013F0E8_0x13f0e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F0E8_0x13f0e8");
#endif

    ctx->pc = 0x13f0e8u;

    // 0x13f0e8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0E8u;
            // 0x13f0ec: 0x8c820030  lw          $v0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F0F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

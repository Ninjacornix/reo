#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F9D8
// Address: 0x13f9d8 - 0x13f9e0
void sub_0013F9D8_0x13f9d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F9D8_0x13f9d8");
#endif

    ctx->pc = 0x13f9d8u;

    // 0x13f9d8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F9D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F9DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F9D8u;
            // 0x13f9dc: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F9E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

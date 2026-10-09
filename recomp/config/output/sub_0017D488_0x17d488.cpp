#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D488
// Address: 0x17d488 - 0x17d490
void sub_0017D488_0x17d488(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D488_0x17d488");
#endif

    ctx->pc = 0x17d488u;

    // 0x17d488: 0x3e00008  jr          $ra
    ctx->pc = 0x17D488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D488u;
            // 0x17d48c: 0x8c820068  lw          $v0, 0x68($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 104)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D490u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

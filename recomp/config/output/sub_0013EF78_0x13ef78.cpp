#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EF78
// Address: 0x13ef78 - 0x13ef80
void sub_0013EF78_0x13ef78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EF78_0x13ef78");
#endif

    ctx->pc = 0x13ef78u;

    // 0x13ef78: 0x3e00008  jr          $ra
    ctx->pc = 0x13EF78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF78u;
            // 0x13ef7c: 0xa0850026  sb          $a1, 0x26($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 38), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13EF80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

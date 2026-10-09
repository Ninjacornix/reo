#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124F00
// Address: 0x124f00 - 0x124f08
void sub_00124F00_0x124f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124F00_0x124f00");
#endif

    ctx->pc = 0x124f00u;

    // 0x124f00: 0x3e00008  jr          $ra
    ctx->pc = 0x124F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F00u;
            // 0x124f04: 0x8482001c  lh          $v0, 0x1C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 28)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124F08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

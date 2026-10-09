#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D728
// Address: 0x12d728 - 0x12d734
void sub_0012D728_0x12d728(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D728_0x12d728");
#endif

    ctx->pc = 0x12d728u;

    // 0x12d728: 0xac860054  sw          $a2, 0x54($a0)
    ctx->pc = 0x12d728u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 84), GPR_U32(ctx, 6));
    // 0x12d72c: 0x3e00008  jr          $ra
    ctx->pc = 0x12D72Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D72Cu;
            // 0x12d730: 0xac850050  sw          $a1, 0x50($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 80), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D734u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

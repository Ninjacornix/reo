#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1DA0
// Address: 0x1a1da0 - 0x1a1db0
void sub_001A1DA0_0x1a1da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1DA0_0x1a1da0");
#endif

    ctx->pc = 0x1a1da0u;

    // 0x1a1da0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1DA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1DA0u;
            // 0x1a1da4: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A1DA8u;
    // 0x1a1da8: 0x0  nop
    ctx->pc = 0x1a1da8u;
    // NOP
    // 0x1a1dac: 0x0  nop
    ctx->pc = 0x1a1dacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

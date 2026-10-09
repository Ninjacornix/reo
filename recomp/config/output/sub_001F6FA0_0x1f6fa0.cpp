#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F6FA0
// Address: 0x1f6fa0 - 0x1f6fa8
void sub_001F6FA0_0x1f6fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F6FA0_0x1f6fa0");
#endif

    ctx->pc = 0x1f6fa0u;

    // 0x1f6fa0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6FA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6FA0u;
            // 0x1f6fa4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F6FA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

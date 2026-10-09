#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001663A8
// Address: 0x1663a8 - 0x1663b0
void sub_001663A8_0x1663a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001663A8_0x1663a8");
#endif

    ctx->pc = 0x1663a8u;

    // 0x1663a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1663A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1663ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1663A8u;
            // 0x1663ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1663B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

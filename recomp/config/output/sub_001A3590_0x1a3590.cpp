#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3590
// Address: 0x1a3590 - 0x1a35a0
void sub_001A3590_0x1a3590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3590_0x1a3590");
#endif

    ctx->pc = 0x1a3590u;

    // 0x1a3590: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3590u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3590u;
            // 0x1a3594: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A3598u;
    // 0x1a3598: 0x0  nop
    ctx->pc = 0x1a3598u;
    // NOP
    // 0x1a359c: 0x0  nop
    ctx->pc = 0x1a359cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

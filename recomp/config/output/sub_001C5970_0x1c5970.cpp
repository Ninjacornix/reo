#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5970
// Address: 0x1c5970 - 0x1c5980
void sub_001C5970_0x1c5970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5970_0x1c5970");
#endif

    ctx->pc = 0x1c5970u;

    // 0x1c5970: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1c5970u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5974: 0x806e1f8  j           func_1B87E0
    ctx->pc = 0x1C5974u;
    ctx->pc = 0x1C5978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5974u;
            // 0x1c5978: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B87E0u;
    if (runtime->hasFunction(0x1B87E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B87E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B87E0_0x1b87e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C597Cu;
    // 0x1c597c: 0x0  nop
    ctx->pc = 0x1c597cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

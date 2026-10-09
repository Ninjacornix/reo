#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5980
// Address: 0x1c5980 - 0x1c5990
void sub_001C5980_0x1c5980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5980_0x1c5980");
#endif

    ctx->pc = 0x1c5980u;

    // 0x1c5980: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1c5980u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c5984: 0x806e1f8  j           func_1B87E0
    ctx->pc = 0x1C5984u;
    ctx->pc = 0x1C5988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5984u;
            // 0x1c5988: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B87E0u;
    if (runtime->hasFunction(0x1B87E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B87E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B87E0_0x1b87e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C598Cu;
    // 0x1c598c: 0x0  nop
    ctx->pc = 0x1c598cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

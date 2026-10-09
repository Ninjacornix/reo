#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2550
// Address: 0x1d2550 - 0x1d255c
void sub_001D2550_0x1d2550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2550_0x1d2550");
#endif

    ctx->pc = 0x1d2550u;

    // 0x1d2550: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d2550u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2554: 0x8073784  j           func_1CDE10
    ctx->pc = 0x1D2554u;
    ctx->pc = 0x1D2558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2554u;
            // 0x1d2558: 0x24052500  addiu       $a1, $zero, 0x2500 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CDE10_0x1cde10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D255Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

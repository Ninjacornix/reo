#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8860
// Address: 0x1b8860 - 0x1b8870
void sub_001B8860_0x1b8860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8860_0x1b8860");
#endif

    ctx->pc = 0x1b8860u;

    // 0x1b8860: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1b8860u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8864: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b8864u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8868: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8868u;
    ctx->pc = 0x1B886Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8868u;
            // 0x1b886c: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8870u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

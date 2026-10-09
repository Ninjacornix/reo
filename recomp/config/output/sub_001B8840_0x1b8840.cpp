#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8840
// Address: 0x1b8840 - 0x1b8850
void sub_001B8840_0x1b8840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8840_0x1b8840");
#endif

    ctx->pc = 0x1b8840u;

    // 0x1b8840: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8840u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8844: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1b8844u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8848: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8848u;
    ctx->pc = 0x1B884Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8848u;
            // 0x1b884c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8850u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

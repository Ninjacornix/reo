#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B93B0
// Address: 0x1b93b0 - 0x1b93d0
void sub_001B93B0_0x1b93b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B93B0_0x1b93b0");
#endif

    ctx->pc = 0x1b93b0u;

    // 0x1b93b0: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x1b93b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b93b4: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b93b4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b93b8: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x1b93b8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b93bc: 0x806b1fc  j           func_1AC7F0
    ctx->pc = 0x1B93BCu;
    ctx->pc = 0x1B93C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B93BCu;
            // 0x1b93c0: 0xe0482d  daddu       $t1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC7F0u;
    if (runtime->hasFunction(0x1AC7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AC7F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AC7F0_0x1ac7f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B93C4u;
    // 0x1b93c4: 0x0  nop
    ctx->pc = 0x1b93c4u;
    // NOP
    // 0x1b93c8: 0x0  nop
    ctx->pc = 0x1b93c8u;
    // NOP
    // 0x1b93cc: 0x0  nop
    ctx->pc = 0x1b93ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

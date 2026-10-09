#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8800
// Address: 0x1b8800 - 0x1b8810
void sub_001B8800_0x1b8800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8800_0x1b8800");
#endif

    ctx->pc = 0x1b8800u;

    // 0x1b8800: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8800u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8804: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b8804u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8808: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8808u;
    ctx->pc = 0x1B880Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8808u;
            // 0x1b880c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8810u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

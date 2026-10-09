#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA9F0
// Address: 0x1ba9f0 - 0x1ba9fc
void sub_001BA9F0_0x1ba9f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA9F0_0x1ba9f0");
#endif

    ctx->pc = 0x1ba9f0u;

    // 0x1ba9f0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1ba9f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba9f4: 0x806e9e4  j           func_1BA790
    ctx->pc = 0x1BA9F4u;
    ctx->pc = 0x1BA9F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA9F4u;
            // 0x1ba9f8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA790u;
    if (runtime->hasFunction(0x1BA790u)) {
        auto targetFn = runtime->lookupFunction(0x1BA790u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001BA790_0x1ba790(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BA9FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8810
// Address: 0x1b8810 - 0x1b8820
void sub_001B8810_0x1b8810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8810_0x1b8810");
#endif

    ctx->pc = 0x1b8810u;

    // 0x1b8810: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8810u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8814: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b8814u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8818: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8818u;
    ctx->pc = 0x1B881Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8818u;
            // 0x1b881c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8820u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

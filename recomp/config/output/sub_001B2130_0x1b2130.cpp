#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2130
// Address: 0x1b2130 - 0x1b2140
void sub_001B2130_0x1b2130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2130_0x1b2130");
#endif

    ctx->pc = 0x1b2130u;

    // 0x1b2130: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b2130u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2134: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1B2134u;
    ctx->pc = 0x1B2138u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2134u;
            // 0x1b2138: 0x24061f44  addiu       $a2, $zero, 0x1F44 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8004));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B213Cu;
    // 0x1b213c: 0x0  nop
    ctx->pc = 0x1b213cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

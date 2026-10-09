#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2120
// Address: 0x1b2120 - 0x1b2130
void sub_001B2120_0x1b2120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2120_0x1b2120");
#endif

    ctx->pc = 0x1b2120u;

    // 0x1b2120: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b2120u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2124: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1B2124u;
    ctx->pc = 0x1B2128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2124u;
            // 0x1b2128: 0x24060c84  addiu       $a2, $zero, 0xC84 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3204));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B212Cu;
    // 0x1b212c: 0x0  nop
    ctx->pc = 0x1b212cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

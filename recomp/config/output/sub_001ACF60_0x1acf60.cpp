#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ACF60
// Address: 0x1acf60 - 0x1acf70
void sub_001ACF60_0x1acf60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ACF60_0x1acf60");
#endif

    ctx->pc = 0x1acf60u;

    // 0x1acf60: 0x8069f14  j           func_1A7C50
    ctx->pc = 0x1ACF60u;
    ctx->pc = 0x1ACF64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACF60u;
            // 0x1acf64: 0x38840001  xori        $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7C50u;
    if (runtime->hasFunction(0x1A7C50u)) {
        auto targetFn = runtime->lookupFunction(0x1A7C50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A7C50_0x1a7c50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1ACF68u;
    // 0x1acf68: 0x0  nop
    ctx->pc = 0x1acf68u;
    // NOP
    // 0x1acf6c: 0x0  nop
    ctx->pc = 0x1acf6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

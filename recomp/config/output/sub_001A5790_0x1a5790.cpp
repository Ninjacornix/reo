#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5790
// Address: 0x1a5790 - 0x1a57a0
void sub_001A5790_0x1a5790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5790_0x1a5790");
#endif

    ctx->pc = 0x1a5790u;

    // 0x1a5790: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1a5790u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5794: 0x8069650  j           func_1A5940
    ctx->pc = 0x1A5794u;
    ctx->pc = 0x1A5798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5794u;
            // 0x1a5798: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5940u;
    if (runtime->hasFunction(0x1A5940u)) {
        auto targetFn = runtime->lookupFunction(0x1A5940u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A5940_0x1a5940(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A579Cu;
    // 0x1a579c: 0x0  nop
    ctx->pc = 0x1a579cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

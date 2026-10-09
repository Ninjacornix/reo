#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ACEA0
// Address: 0x1acea0 - 0x1aceb0
void sub_001ACEA0_0x1acea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ACEA0_0x1acea0");
#endif

    ctx->pc = 0x1acea0u;

    // 0x1acea0: 0x8069ec4  j           func_1A7B10
    ctx->pc = 0x1ACEA0u;
    ctx->pc = 0x1ACEA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACEA0u;
            // 0x1acea4: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7B10u;
    if (runtime->hasFunction(0x1A7B10u)) {
        auto targetFn = runtime->lookupFunction(0x1A7B10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A7B10_0x1a7b10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1ACEA8u;
    // 0x1acea8: 0x0  nop
    ctx->pc = 0x1acea8u;
    // NOP
    // 0x1aceac: 0x0  nop
    ctx->pc = 0x1aceacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A57A0
// Address: 0x1a57a0 - 0x1a57b0
void sub_001A57A0_0x1a57a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A57A0_0x1a57a0");
#endif

    ctx->pc = 0x1a57a0u;

    // 0x1a57a0: 0x8069688  j           func_1A5A20
    ctx->pc = 0x1A57A0u;
    ctx->pc = 0x1A57A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A57A0u;
            // 0x1a57a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5A20u;
    if (runtime->hasFunction(0x1A5A20u)) {
        auto targetFn = runtime->lookupFunction(0x1A5A20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A5A20_0x1a5a20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A57A8u;
    // 0x1a57a8: 0x0  nop
    ctx->pc = 0x1a57a8u;
    // NOP
    // 0x1a57ac: 0x0  nop
    ctx->pc = 0x1a57acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

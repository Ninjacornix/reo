#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA440
// Address: 0x1da440 - 0x1da448
void sub_001DA440_0x1da440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA440_0x1da440");
#endif

    ctx->pc = 0x1da440u;

    // 0x1da440: 0x8076920  j           func_1DA480
    ctx->pc = 0x1DA440u;
    ctx->pc = 0x1DA444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA440u;
            // 0x1da444: 0x24040040  addiu       $a0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DA480u;
    if (runtime->hasFunction(0x1DA480u)) {
        auto targetFn = runtime->lookupFunction(0x1DA480u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001DA480_0x1da480(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1DA448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

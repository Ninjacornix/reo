#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148670
// Address: 0x148670 - 0x148680
void sub_00148670_0x148670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148670_0x148670");
#endif

    ctx->pc = 0x148670u;

    // 0x148670: 0xac800860  sw          $zero, 0x860($a0)
    ctx->pc = 0x148670u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 2144), GPR_U32(ctx, 0));
    // 0x148674: 0x8050fe2  j           func_143F88
    ctx->pc = 0x148674u;
    ctx->pc = 0x148678u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148674u;
            // 0x148678: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x143F88u;
    if (runtime->hasFunction(0x143F88u)) {
        auto targetFn = runtime->lookupFunction(0x143F88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00143F88_0x143f88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x14867Cu;
    // 0x14867c: 0x0  nop
    ctx->pc = 0x14867cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

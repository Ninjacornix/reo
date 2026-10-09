#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6BE0
// Address: 0x1c6be0 - 0x1c6be8
void sub_001C6BE0_0x1c6be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6BE0_0x1c6be0");
#endif

    ctx->pc = 0x1c6be0u;

    // 0x1c6be0: 0x8071ea0  j           func_1C7A80
    ctx->pc = 0x1C6BE0u;
    ctx->pc = 0x1C6BE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6BE0u;
            // 0x1c6be4: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7A80u;
    if (runtime->hasFunction(0x1C7A80u)) {
        auto targetFn = runtime->lookupFunction(0x1C7A80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C7A80_0x1c7a80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6BE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

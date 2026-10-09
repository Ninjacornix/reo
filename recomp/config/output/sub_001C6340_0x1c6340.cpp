#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6340
// Address: 0x1c6340 - 0x1c6348
void sub_001C6340_0x1c6340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6340_0x1c6340");
#endif

    ctx->pc = 0x1c6340u;

    // 0x1c6340: 0x8072108  j           func_1C8420
    ctx->pc = 0x1C6340u;
    ctx->pc = 0x1C6344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6340u;
            // 0x1c6344: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8420u;
    if (runtime->hasFunction(0x1C8420u)) {
        auto targetFn = runtime->lookupFunction(0x1C8420u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8420_0x1c8420(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6348u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

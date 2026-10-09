#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6660
// Address: 0x1c6660 - 0x1c6668
void sub_001C6660_0x1c6660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6660_0x1c6660");
#endif

    ctx->pc = 0x1c6660u;

    // 0x1c6660: 0x8072200  j           func_1C8800
    ctx->pc = 0x1C6660u;
    ctx->pc = 0x1C6664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6660u;
            // 0x1c6664: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8800u;
    if (runtime->hasFunction(0x1C8800u)) {
        auto targetFn = runtime->lookupFunction(0x1C8800u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8800_0x1c8800(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6668u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

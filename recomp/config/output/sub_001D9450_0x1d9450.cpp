#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9450
// Address: 0x1d9450 - 0x1d9460
void sub_001D9450_0x1d9450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9450_0x1d9450");
#endif

    ctx->pc = 0x1d9450u;

    // 0x1d9450: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9450u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9454: 0x8045198  j           func_114660
    ctx->pc = 0x1D9454u;
    ctx->pc = 0x1D9458u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9454u;
            // 0x1d9458: 0x8c2482c0  lw          $a0, -0x7D40($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294935232)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114660_0x114660(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D945Cu;
    // 0x1d945c: 0x0  nop
    ctx->pc = 0x1d945cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

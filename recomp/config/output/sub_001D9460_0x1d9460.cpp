#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9460
// Address: 0x1d9460 - 0x1d9470
void sub_001D9460_0x1d9460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9460_0x1d9460");
#endif

    ctx->pc = 0x1d9460u;

    // 0x1d9460: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9460u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9464: 0x8045190  j           func_114640
    ctx->pc = 0x1D9464u;
    ctx->pc = 0x1D9468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9464u;
            // 0x1d9468: 0x8c2482c0  lw          $a0, -0x7D40($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294935232)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D946Cu;
    // 0x1d946c: 0x0  nop
    ctx->pc = 0x1d946cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

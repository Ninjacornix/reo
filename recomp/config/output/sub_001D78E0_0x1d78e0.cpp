#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D78E0
// Address: 0x1d78e0 - 0x1d78f0
void sub_001D78E0_0x1d78e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D78E0_0x1d78e0");
#endif

    ctx->pc = 0x1d78e0u;

    // 0x1d78e0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d78e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d78e4: 0x8045198  j           func_114660
    ctx->pc = 0x1D78E4u;
    ctx->pc = 0x1D78E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D78E4u;
            // 0x1d78e8: 0x8c245240  lw          $a0, 0x5240($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 21056)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114660_0x114660(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D78ECu;
    // 0x1d78ec: 0x0  nop
    ctx->pc = 0x1d78ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

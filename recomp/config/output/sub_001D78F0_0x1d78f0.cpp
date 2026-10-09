#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D78F0
// Address: 0x1d78f0 - 0x1d7900
void sub_001D78F0_0x1d78f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D78F0_0x1d78f0");
#endif

    ctx->pc = 0x1d78f0u;

    // 0x1d78f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d78f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d78f4: 0x8045190  j           func_114640
    ctx->pc = 0x1D78F4u;
    ctx->pc = 0x1D78F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D78F4u;
            // 0x1d78f8: 0x8c245240  lw          $a0, 0x5240($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 21056)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D78FCu;
    // 0x1d78fc: 0x0  nop
    ctx->pc = 0x1d78fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

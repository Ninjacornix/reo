#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D59B8
// Address: 0x1d59b8 - 0x1d59c4
void sub_001D59B8_0x1d59b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D59B8_0x1d59b8");
#endif

    ctx->pc = 0x1d59b8u;

    // 0x1d59b8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d59b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d59bc: 0x8045194  j           func_114650
    ctx->pc = 0x1D59BCu;
    ctx->pc = 0x1D59C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D59BCu;
            // 0x1d59c0: 0x8c446998  lw          $a0, 0x6998($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 27032)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114650_0x114650(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D59C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

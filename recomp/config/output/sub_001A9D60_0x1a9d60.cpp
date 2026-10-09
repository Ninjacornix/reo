#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9D60
// Address: 0x1a9d60 - 0x1a9d70
void sub_001A9D60_0x1a9d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9D60_0x1a9d60");
#endif

    ctx->pc = 0x1a9d60u;

    // 0x1a9d60: 0x8ca60020  lw          $a2, 0x20($a1)
    ctx->pc = 0x1a9d60u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x1a9d64: 0x8ca50008  lw          $a1, 0x8($a1)
    ctx->pc = 0x1a9d64u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1a9d68: 0x806a6b0  j           func_1A9AC0
    ctx->pc = 0x1A9D68u;
    ctx->pc = 0x1A9D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9D68u;
            // 0x1a9d6c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9AC0u;
    if (runtime->hasFunction(0x1A9AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A9AC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A9AC0_0x1a9ac0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1A9D70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

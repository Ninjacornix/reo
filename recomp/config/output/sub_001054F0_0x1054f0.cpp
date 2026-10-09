#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001054F0
// Address: 0x1054f0 - 0x10550c
void sub_001054F0_0x1054f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001054F0_0x1054f0");
#endif

    ctx->pc = 0x1054f0u;

    // 0x1054f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1054f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1054f4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1054f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1054f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1054f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1054fc: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x1054fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x105500: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x105500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x105504: 0x8041534  j           func_1054D0
    ctx->pc = 0x105504u;
    ctx->pc = 0x105508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105504u;
            // 0x105508: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1054D0u;
    if (runtime->hasFunction(0x1054D0u)) {
        auto targetFn = runtime->lookupFunction(0x1054D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001054D0_0x1054d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10550Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

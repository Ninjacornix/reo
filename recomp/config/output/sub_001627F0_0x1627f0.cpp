#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001627F0
// Address: 0x1627f0 - 0x162808
void sub_001627F0_0x1627f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001627F0_0x1627f0");
#endif

    ctx->pc = 0x1627f0u;

    // 0x1627f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1627f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1627f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1627f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1627f8: 0x8c84004c  lw          $a0, 0x4C($a0)
    ctx->pc = 0x1627f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x1627fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1627fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162800: 0x804f434  j           func_13D0D0
    ctx->pc = 0x162800u;
    ctx->pc = 0x162804u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162800u;
            // 0x162804: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D0D0u;
    if (runtime->hasFunction(0x13D0D0u)) {
        auto targetFn = runtime->lookupFunction(0x13D0D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D0D0_0x13d0d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162808u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

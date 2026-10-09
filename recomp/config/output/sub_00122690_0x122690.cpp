#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122690
// Address: 0x122690 - 0x1226a8
void sub_00122690_0x122690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122690_0x122690");
#endif

    ctx->pc = 0x122690u;

    // 0x122690: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122694: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122698: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x122698u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12269c: 0x8047e1e  j           func_11F878
    ctx->pc = 0x12269Cu;
    ctx->pc = 0x1226A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12269Cu;
            // 0x1226a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F878u;
    if (runtime->hasFunction(0x11F878u)) {
        auto targetFn = runtime->lookupFunction(0x11F878u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011F878_0x11f878(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1226A4u;
    // 0x1226a4: 0x0  nop
    ctx->pc = 0x1226a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

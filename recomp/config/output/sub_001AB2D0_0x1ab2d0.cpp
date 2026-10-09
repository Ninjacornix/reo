#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB2D0
// Address: 0x1ab2d0 - 0x1ab2f0
void sub_001AB2D0_0x1ab2d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB2D0_0x1ab2d0");
#endif

    ctx->pc = 0x1ab2d0u;

    // 0x1ab2d0: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1ab2d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1ab2d4: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1ab2d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1ab2d8: 0x2484fcc8  addiu       $a0, $a0, -0x338
    ctx->pc = 0x1ab2d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966472));
    // 0x1ab2dc: 0x24a52b10  addiu       $a1, $a1, 0x2B10
    ctx->pc = 0x1ab2dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11024));
    // 0x1ab2e0: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x1ab2e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ab2e4: 0x806a6b0  j           func_1A9AC0
    ctx->pc = 0x1AB2E4u;
    ctx->pc = 0x1AB2E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB2E4u;
            // 0x1ab2e8: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9AC0u;
    if (runtime->hasFunction(0x1A9AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A9AC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A9AC0_0x1a9ac0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AB2ECu;
    // 0x1ab2ec: 0x0  nop
    ctx->pc = 0x1ab2ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

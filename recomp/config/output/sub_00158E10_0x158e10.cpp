#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158E10
// Address: 0x158e10 - 0x158e30
void sub_00158E10_0x158e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158E10_0x158e10");
#endif

    ctx->pc = 0x158e10u;

    // 0x158e10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x158e10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x158e14: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x158e14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x158e18: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x158e18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x158e1c: 0x2484d8c0  addiu       $a0, $a0, -0x2740
    ctx->pc = 0x158e1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957248));
    // 0x158e20: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x158e20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158e24: 0x805638c  j           func_158E30
    ctx->pc = 0x158E24u;
    ctx->pc = 0x158E28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158E24u;
            // 0x158e28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158E30u;
    if (runtime->hasFunction(0x158E30u)) {
        auto targetFn = runtime->lookupFunction(0x158E30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158E30_0x158e30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x158E2Cu;
    // 0x158e2c: 0x0  nop
    ctx->pc = 0x158e2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

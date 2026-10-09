#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001634C0
// Address: 0x1634c0 - 0x1634d4
void sub_001634C0_0x1634c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001634C0_0x1634c0");
#endif

    ctx->pc = 0x1634c0u;

    // 0x1634c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1634c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1634c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1634c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1634c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1634c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1634cc: 0x805084e  j           func_142138
    ctx->pc = 0x1634CCu;
    ctx->pc = 0x1634D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1634CCu;
            // 0x1634d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142138u;
    if (runtime->hasFunction(0x142138u)) {
        auto targetFn = runtime->lookupFunction(0x142138u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00142138_0x142138(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1634D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

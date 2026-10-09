#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001054D0
// Address: 0x1054d0 - 0x1054ec
void sub_001054D0_0x1054d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001054D0_0x1054d0");
#endif

    ctx->pc = 0x1054d0u;

    // 0x1054d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1054d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1054d4: 0x3c050010  lui         $a1, 0x10
    ctx->pc = 0x1054d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16 << 16));
    // 0x1054d8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1054d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1054dc: 0x24a550b0  addiu       $a1, $a1, 0x50B0
    ctx->pc = 0x1054dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20656));
    // 0x1054e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1054e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1054e4: 0x80419ce  j           func_106738
    ctx->pc = 0x1054E4u;
    ctx->pc = 0x1054E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1054E4u;
            // 0x1054e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106738u;
    if (runtime->hasFunction(0x106738u)) {
        auto targetFn = runtime->lookupFunction(0x106738u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00106738_0x106738(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1054ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F7C0
// Address: 0x15f7c0 - 0x15f7d8
void sub_0015F7C0_0x15f7c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F7C0_0x15f7c0");
#endif

    ctx->pc = 0x15f7c0u;

    // 0x15f7c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f7c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f7c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f7c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f7c8: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15f7c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f7cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f7ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f7d0: 0x8059856  j           func_166158
    ctx->pc = 0x15F7D0u;
    ctx->pc = 0x15F7D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F7D0u;
            // 0x15f7d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166158u;
    if (runtime->hasFunction(0x166158u)) {
        auto targetFn = runtime->lookupFunction(0x166158u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166158_0x166158(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F7D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

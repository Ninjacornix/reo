#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F7A8
// Address: 0x15f7a8 - 0x15f7c0
void sub_0015F7A8_0x15f7a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F7A8_0x15f7a8");
#endif

    ctx->pc = 0x15f7a8u;

    // 0x15f7a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f7a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f7ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15f7acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15f7b0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15f7b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15f7b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15f7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f7b8: 0x80598b8  j           func_1662E0
    ctx->pc = 0x15F7B8u;
    ctx->pc = 0x15F7BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F7B8u;
            // 0x15f7bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1662E0u;
    if (runtime->hasFunction(0x1662E0u)) {
        auto targetFn = runtime->lookupFunction(0x1662E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001662E0_0x1662e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F7C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

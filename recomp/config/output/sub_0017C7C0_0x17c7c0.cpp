#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C7C0
// Address: 0x17c7c0 - 0x17c7e0
void sub_0017C7C0_0x17c7c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C7C0_0x17c7c0");
#endif

    ctx->pc = 0x17c7c0u;

    // 0x17c7c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c7c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c7c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c7c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c7c8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c7c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c7cc: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c7ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c7d0: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x17c7d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x17c7d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c7d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c7d8: 0x805f798  j           func_17DE60
    ctx->pc = 0x17C7D8u;
    ctx->pc = 0x17C7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C7D8u;
            // 0x17c7dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17DE60u;
    if (runtime->hasFunction(0x17DE60u)) {
        auto targetFn = runtime->lookupFunction(0x17DE60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017DE60_0x17de60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C7E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

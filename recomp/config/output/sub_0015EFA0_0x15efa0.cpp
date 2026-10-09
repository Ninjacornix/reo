#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EFA0
// Address: 0x15efa0 - 0x15efb8
void sub_0015EFA0_0x15efa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EFA0_0x15efa0");
#endif

    ctx->pc = 0x15efa0u;

    // 0x15efa0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15efa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15efa4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15efa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15efa8: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15efa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15efac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15efacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15efb0: 0x805cfca  j           func_173F28
    ctx->pc = 0x15EFB0u;
    ctx->pc = 0x15EFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15EFB0u;
            // 0x15efb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173F28u;
    if (runtime->hasFunction(0x173F28u)) {
        auto targetFn = runtime->lookupFunction(0x173F28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00173F28_0x173f28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15EFB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

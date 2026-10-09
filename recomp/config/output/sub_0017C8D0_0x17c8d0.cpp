#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C8D0
// Address: 0x17c8d0 - 0x17c8f0
void sub_0017C8D0_0x17c8d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C8D0_0x17c8d0");
#endif

    ctx->pc = 0x17c8d0u;

    // 0x17c8d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c8d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c8d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c8d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c8d8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c8d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c8dc: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c8dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c8e0: 0x8c840030  lw          $a0, 0x30($a0)
    ctx->pc = 0x17c8e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x17c8e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c8e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c8e8: 0x805e9de  j           func_17A778
    ctx->pc = 0x17C8E8u;
    ctx->pc = 0x17C8ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C8E8u;
            // 0x17c8ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A778u;
    if (runtime->hasFunction(0x17A778u)) {
        auto targetFn = runtime->lookupFunction(0x17A778u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017A778_0x17a778(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C8F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

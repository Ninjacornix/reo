#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C8F0
// Address: 0x17c8f0 - 0x17c910
void sub_0017C8F0_0x17c8f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C8F0_0x17c8f0");
#endif

    ctx->pc = 0x17c8f0u;

    // 0x17c8f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17c8f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17c8f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17c8f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17c8f8: 0x8c86003c  lw          $a2, 0x3C($a0)
    ctx->pc = 0x17c8f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
    // 0x17c8fc: 0x8ca5004c  lw          $a1, 0x4C($a1)
    ctx->pc = 0x17c8fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x17c900: 0x8c840030  lw          $a0, 0x30($a0)
    ctx->pc = 0x17c900u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x17c904: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17c904u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c908: 0x805e9ee  j           func_17A7B8
    ctx->pc = 0x17C908u;
    ctx->pc = 0x17C90Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C908u;
            // 0x17c90c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A7B8u;
    if (runtime->hasFunction(0x17A7B8u)) {
        auto targetFn = runtime->lookupFunction(0x17A7B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017A7B8_0x17a7b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

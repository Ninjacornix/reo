#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FEA0
// Address: 0x15fea0 - 0x15feb8
void sub_0015FEA0_0x15fea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FEA0_0x15fea0");
#endif

    ctx->pc = 0x15fea0u;

    // 0x15fea0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fea4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15fea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15fea8: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15fea8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15feac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15feacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15feb0: 0x805d58e  j           func_175638
    ctx->pc = 0x15FEB0u;
    ctx->pc = 0x15FEB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FEB0u;
            // 0x15feb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175638u;
    if (runtime->hasFunction(0x175638u)) {
        auto targetFn = runtime->lookupFunction(0x175638u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175638_0x175638(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FEB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

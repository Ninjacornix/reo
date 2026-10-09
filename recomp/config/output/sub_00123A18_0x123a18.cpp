#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123A18
// Address: 0x123a18 - 0x123a40
void sub_00123A18_0x123a18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123A18_0x123a18");
#endif

    ctx->pc = 0x123a18u;

    // 0x123a18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x123a18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x123a1c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123a20: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x123a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x123a24: 0x8483009a  lh          $v1, 0x9A($a0)
    ctx->pc = 0x123a24u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
    // 0x123a28: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x123A28u;
    {
        const bool branch_taken_0x123a28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x123A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123A28u;
            // 0x123a2c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123a28) {
            ctx->pc = 0x123A38u;
            goto label_123a38;
        }
    }
    ctx->pc = 0x123A30u;
    // 0x123a30: 0x8048e26  j           func_123898
    ctx->pc = 0x123A30u;
    ctx->pc = 0x123A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123A30u;
            // 0x123a34: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123898u;
    if (runtime->hasFunction(0x123898u)) {
        auto targetFn = runtime->lookupFunction(0x123898u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00123898_0x123898(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x123A38u;
label_123a38:
    // 0x123a38: 0x8048dc0  j           func_123700
    ctx->pc = 0x123A38u;
    ctx->pc = 0x123A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123A38u;
            // 0x123a3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123700u;
    if (runtime->hasFunction(0x123700u)) {
        auto targetFn = runtime->lookupFunction(0x123700u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00123700_0x123700(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x123A40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

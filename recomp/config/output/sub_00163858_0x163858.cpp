#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163858
// Address: 0x163858 - 0x163880
void sub_00163858_0x163858(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163858_0x163858");
#endif

    ctx->pc = 0x163858u;

    // 0x163858: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16385c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16385cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163860: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163864: 0x8c830060  lw          $v1, 0x60($a0)
    ctx->pc = 0x163864u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 96)));
    // 0x163868: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x163868u;
    {
        const bool branch_taken_0x163868 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x16386Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163868u;
            // 0x16386c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163868) {
            ctx->pc = 0x163878u;
            goto label_163878;
        }
    }
    ctx->pc = 0x163870u;
    // 0x163870: 0x8058e20  j           func_163880
    ctx->pc = 0x163870u;
    ctx->pc = 0x163874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163870u;
            // 0x163874: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163880u;
    if (runtime->hasFunction(0x163880u)) {
        auto targetFn = runtime->lookupFunction(0x163880u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163880_0x163880(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163878u;
label_163878:
    // 0x163878: 0x3e00008  jr          $ra
    ctx->pc = 0x163878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16387Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163878u;
            // 0x16387c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163878u: goto label_163878;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163880u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160620
// Address: 0x160620 - 0x16065c
void sub_00160620_0x160620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160620_0x160620");
#endif

    ctx->pc = 0x160620u;

    // 0x160620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160624: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x160624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160628: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16062c: 0x14a20006  bne         $a1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16062Cu;
    {
        const bool branch_taken_0x16062c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x160630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16062Cu;
            // 0x160630: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16062c) {
            ctx->pc = 0x160648u;
            goto label_160648;
        }
    }
    ctx->pc = 0x160634u;
    // 0x160634: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160634u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160638: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x160638u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x16063c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16063cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160640: 0x805afb2  j           func_16BEC8
    ctx->pc = 0x160640u;
    ctx->pc = 0x160644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160640u;
            // 0x160644: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BEC8u;
    if (runtime->hasFunction(0x16BEC8u)) {
        auto targetFn = runtime->lookupFunction(0x16BEC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016BEC8_0x16bec8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160648u;
label_160648:
    // 0x160648: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160648u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16064c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x16064cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x160650: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x160650u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160654: 0x805afb2  j           func_16BEC8
    ctx->pc = 0x160654u;
    ctx->pc = 0x160658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160654u;
            // 0x160658: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BEC8u;
    if (runtime->hasFunction(0x16BEC8u)) {
        auto targetFn = runtime->lookupFunction(0x16BEC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016BEC8_0x16bec8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16065Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D638
// Address: 0x12d638 - 0x12d678
void sub_0012D638_0x12d638(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D638_0x12d638");
#endif

    ctx->pc = 0x12d638u;

    // 0x12d638: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d638u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d63c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12d63cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12d640: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d644: 0x80830001  lb          $v1, 0x1($a0)
    ctx->pc = 0x12d644u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x12d648: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12D648u;
    {
        const bool branch_taken_0x12d648 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x12D64Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D648u;
            // 0x12d64c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d648) {
            ctx->pc = 0x12D660u;
            goto label_12d660;
        }
    }
    ctx->pc = 0x12D650u;
    // 0x12d650: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d650u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d654: 0x804b564  j           func_12D590
    ctx->pc = 0x12D654u;
    ctx->pc = 0x12D658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D654u;
            // 0x12d658: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D590u;
    if (runtime->hasFunction(0x12D590u)) {
        auto targetFn = runtime->lookupFunction(0x12D590u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D590_0x12d590(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D65Cu;
    // 0x12d65c: 0x0  nop
    ctx->pc = 0x12d65cu;
    // NOP
label_12d660:
    // 0x12d660: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12D660u;
    {
        const bool branch_taken_0x12d660 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x12D664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D660u;
            // 0x12d664: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d660) {
            ctx->pc = 0x12D670u;
            goto label_12d670;
        }
    }
    ctx->pc = 0x12D668u;
    // 0x12d668: 0x804b338  j           func_12CCE0
    ctx->pc = 0x12D668u;
    ctx->pc = 0x12D66Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D668u;
            // 0x12d66c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CCE0u;
    if (runtime->hasFunction(0x12CCE0u)) {
        auto targetFn = runtime->lookupFunction(0x12CCE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012CCE0_0x12cce0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D670u;
label_12d670:
    // 0x12d670: 0x3e00008  jr          $ra
    ctx->pc = 0x12D670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D670u;
            // 0x12d674: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D660u: goto label_12d660;
            case 0x12D670u: goto label_12d670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D678u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

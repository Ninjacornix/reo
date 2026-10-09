#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFD50
// Address: 0x1afd50 - 0x1afdd0
void sub_001AFD50_0x1afd50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFD50_0x1afd50");
#endif

    switch (ctx->pc) {
        case 0x1afd70u: goto label_1afd70;
        case 0x1afdb4u: goto label_1afdb4;
        case 0x1afdc4u: goto label_1afdc4;
        default: break;
    }

    ctx->pc = 0x1afd50u;

    // 0x1afd50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afd50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afd54: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1afd54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1afd58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afd58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afd5c: 0x902343fa  lbu         $v1, 0x43FA($at)
    ctx->pc = 0x1afd5cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17402)));
    // 0x1afd60: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AFD60u;
    {
        const bool branch_taken_0x1afd60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afd60) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFD68u;
    // 0x1afd68: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFD68u;
    SET_GPR_U32(ctx, 31, 0x1AFD70u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFD70u; }
        if (ctx->pc != 0x1AFD70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFD70u; }
        if (ctx->pc != 0x1AFD70u) { return; }
    }
    ctx->pc = 0x1AFD70u;
label_1afd70:
    // 0x1afd70: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afd70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afd74: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1AFD74u;
    {
        const bool branch_taken_0x1afd74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD74u;
            // 0x1afd78: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd74) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFD7Cu;
    // 0x1afd7c: 0x10430011  beq         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AFD7Cu;
    {
        const bool branch_taken_0x1afd7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afd7c) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFD84u;
    // 0x1afd84: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afd84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afd88: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1AFD88u;
    {
        const bool branch_taken_0x1afd88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afd88) {
            ctx->pc = 0x1AFDBCu;
            goto label_1afdbc;
        }
    }
    ctx->pc = 0x1AFD90u;
    // 0x1afd90: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFD90u;
    {
        const bool branch_taken_0x1afd90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD90u;
            // 0x1afd94: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd90) {
            ctx->pc = 0x1AFDA0u;
            goto label_1afda0;
        }
    }
    ctx->pc = 0x1AFD98u;
    // 0x1afd98: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1AFD98u;
    {
        const bool branch_taken_0x1afd98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD98u;
            // 0x1afd9c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd98) {
            ctx->pc = 0x1AFDC8u;
            goto label_1afdc8;
        }
    }
    ctx->pc = 0x1AFDA0u;
label_1afda0:
    // 0x1afda0: 0x9023ae94  lbu         $v1, -0x516C($at)
    ctx->pc = 0x1afda0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946452)));
    // 0x1afda4: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AFDA4u;
    {
        const bool branch_taken_0x1afda4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1afda4) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFDACu;
    // 0x1afdac: 0xc204210  jal         func_810840
    ctx->pc = 0x1AFDACu;
    SET_GPR_U32(ctx, 31, 0x1AFDB4u);
    ctx->pc = 0x810840u;
    {
        auto targetFn = runtime->lookupFunction(0x810840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDB4u; }
        if (ctx->pc != 0x1AFDB4u) { return; }
    }
    ctx->pc = 0x1AFDB4u;
label_1afdb4:
    // 0x1afdb4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFDB4u;
    {
        const bool branch_taken_0x1afdb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afdb4) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFDBCu;
label_1afdbc:
    // 0x1afdbc: 0xc204a48  jal         func_812920
    ctx->pc = 0x1AFDBCu;
    SET_GPR_U32(ctx, 31, 0x1AFDC4u);
    ctx->pc = 0x812920u;
    {
        auto targetFn = runtime->lookupFunction(0x812920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDC4u; }
        if (ctx->pc != 0x1AFDC4u) { return; }
    }
    ctx->pc = 0x1AFDC4u;
label_1afdc4:
    // 0x1afdc4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afdc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afdc8:
    // 0x1afdc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFDC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFDCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFDC8u;
            // 0x1afdcc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFDD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DACAC
// Address: 0x1dacac - 0x1dadd4
void sub_001DACAC_0x1dacac(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DACAC_0x1dacac");
#endif

    switch (ctx->pc) {
        case 0x1dad28u: goto label_1dad28;
        default: break;
    }

    ctx->pc = 0x1dacacu;

    // 0x1dacac: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dacacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dacb0: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dacb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dacb4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1dacb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1dacb8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dacb8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dacbc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dacbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dacc0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1dacc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1dacc4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dacc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dacc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dacc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1daccc: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DACCCu;
    {
        const bool branch_taken_0x1daccc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1daccc) {
            ctx->pc = 0x1DACF0u;
            goto label_1dacf0;
        }
    }
    ctx->pc = 0x1DACD4u;
    // 0x1dacd4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dacd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dacd8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dacd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dacdc: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dacdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dace0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dace0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dace4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dace4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dace8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DACE8u;
    {
        const bool branch_taken_0x1dace8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dace8) {
            ctx->pc = 0x1DACFCu;
            goto label_1dacfc;
        }
    }
    ctx->pc = 0x1DACF0u;
label_1dacf0:
    // 0x1dacf0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1dacf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dacf4: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1DACF4u;
    {
        const bool branch_taken_0x1dacf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dacf4) {
            ctx->pc = 0x1DADBCu;
            goto label_1dadbc;
        }
    }
    ctx->pc = 0x1DACFCu;
label_1dacfc:
    // 0x1dacfc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dacfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dad00: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dad00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dad04: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dad04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dad08: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dad08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dad0c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dad0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dad10: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dad10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dad14: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad18: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dad18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dad1c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1dad1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad20: 0xc07cac2  jal         func_1F2B08
    ctx->pc = 0x1DAD20u;
    SET_GPR_U32(ctx, 31, 0x1DAD28u);
    ctx->pc = 0x1F2B08u;
    if (runtime->hasFunction(0x1F2B08u)) {
        auto targetFn = runtime->lookupFunction(0x1F2B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAD28u; }
        if (ctx->pc != 0x1DAD28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2B08_0x1f2b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAD28u; }
        if (ctx->pc != 0x1DAD28u) { return; }
    }
    ctx->pc = 0x1DAD28u;
label_1dad28:
    // 0x1dad28: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad2c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad30: 0x8c420524  lw          $v0, 0x524($v0)
    ctx->pc = 0x1dad30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1316)));
    // 0x1dad34: 0xac620034  sw          $v0, 0x34($v1)
    ctx->pc = 0x1dad34u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 52), GPR_U32(ctx, 2));
    // 0x1dad38: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad3c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad40: 0x8c420528  lw          $v0, 0x528($v0)
    ctx->pc = 0x1dad40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1320)));
    // 0x1dad44: 0xac620038  sw          $v0, 0x38($v1)
    ctx->pc = 0x1dad44u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 56), GPR_U32(ctx, 2));
    // 0x1dad48: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad4c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad50: 0x8c42052c  lw          $v0, 0x52C($v0)
    ctx->pc = 0x1dad50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1324)));
    // 0x1dad54: 0xac62003c  sw          $v0, 0x3C($v1)
    ctx->pc = 0x1dad54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 60), GPR_U32(ctx, 2));
    // 0x1dad58: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad5c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad60: 0x8c420530  lw          $v0, 0x530($v0)
    ctx->pc = 0x1dad60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1328)));
    // 0x1dad64: 0xac620040  sw          $v0, 0x40($v1)
    ctx->pc = 0x1dad64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 64), GPR_U32(ctx, 2));
    // 0x1dad68: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad6c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad70: 0x8c420534  lw          $v0, 0x534($v0)
    ctx->pc = 0x1dad70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1332)));
    // 0x1dad74: 0xac620044  sw          $v0, 0x44($v1)
    ctx->pc = 0x1dad74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 68), GPR_U32(ctx, 2));
    // 0x1dad78: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad7c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad80: 0x8c420538  lw          $v0, 0x538($v0)
    ctx->pc = 0x1dad80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1336)));
    // 0x1dad84: 0xac620048  sw          $v0, 0x48($v1)
    ctx->pc = 0x1dad84u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 72), GPR_U32(ctx, 2));
    // 0x1dad88: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad8c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad90: 0x8c42053c  lw          $v0, 0x53C($v0)
    ctx->pc = 0x1dad90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1340)));
    // 0x1dad94: 0xac62004c  sw          $v0, 0x4C($v1)
    ctx->pc = 0x1dad94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 76), GPR_U32(ctx, 2));
    // 0x1dad98: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad9c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dada0: 0x8c420540  lw          $v0, 0x540($v0)
    ctx->pc = 0x1dada0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1344)));
    // 0x1dada4: 0xac620050  sw          $v0, 0x50($v1)
    ctx->pc = 0x1dada4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 80), GPR_U32(ctx, 2));
    // 0x1dada8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dada8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dadac: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dadacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dadb0: 0x8c420544  lw          $v0, 0x544($v0)
    ctx->pc = 0x1dadb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1348)));
    // 0x1dadb4: 0xac620054  sw          $v0, 0x54($v1)
    ctx->pc = 0x1dadb4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 84), GPR_U32(ctx, 2));
    // 0x1dadb8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dadb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dadbc:
    // 0x1dadbc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dadbcu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dadc0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dadc0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dadc4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1dadc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1dadc8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1dadc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1dadcc: 0x3e00008  jr          $ra
    ctx->pc = 0x1DADCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DACF0u: goto label_1dacf0;
            case 0x1DACFCu: goto label_1dacfc;
            case 0x1DAD28u: goto label_1dad28;
            case 0x1DADBCu: goto label_1dadbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DADD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

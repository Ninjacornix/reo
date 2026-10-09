#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E7C8
// Address: 0x16e7c8 - 0x16e890
void sub_0016E7C8_0x16e7c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E7C8_0x16e7c8");
#endif

    switch (ctx->pc) {
        case 0x16e808u: goto label_16e808;
        default: break;
    }

    ctx->pc = 0x16e7c8u;

    // 0x16e7c8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16e7c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16e7cc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16e7ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16e7d0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16e7d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e7d4: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16e7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16e7d8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x16e7d8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e7dc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16e7dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16e7e0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16e7e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16e7e4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16e7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x16e7e8: 0x8c911b30  lw          $s1, 0x1B30($a0)
    ctx->pc = 0x16e7e8u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x16e7ec: 0x8e2200e4  lw          $v0, 0xE4($s1)
    ctx->pc = 0x16e7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 228)));
    // 0x16e7f0: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x16e7f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x16e7f4: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x16E7F4u;
    {
        const bool branch_taken_0x16e7f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E7F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E7F4u;
            // 0x16e7f8: 0x8e300074  lw          $s0, 0x74($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 116)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e7f4) {
            ctx->pc = 0x16E830u;
            goto label_16e830;
        }
    }
    ctx->pc = 0x16E7FCu;
    // 0x16e7fc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16e7fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e800: 0xc056510  jal         func_159440
    ctx->pc = 0x16E800u;
    SET_GPR_U32(ctx, 31, 0x16E808u);
    ctx->pc = 0x16E804u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E800u;
            // 0x16e804: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159440u;
    if (runtime->hasFunction(0x159440u)) {
        auto targetFn = runtime->lookupFunction(0x159440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E808u; }
        if (ctx->pc != 0x16E808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159440_0x159440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E808u; }
        if (ctx->pc != 0x16E808u) { return; }
    }
    ctx->pc = 0x16E808u;
label_16e808:
    // 0x16e808: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x16e808u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16e80c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16E80Cu;
    {
        const bool branch_taken_0x16e80c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E80Cu;
            // 0x16e810: 0x38830001  xori        $v1, $a0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e80c) {
            ctx->pc = 0x16E828u;
            goto label_16e828;
        }
    }
    ctx->pc = 0x16E814u;
    // 0x16e814: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16e814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16e818: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x16e818u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16e81c: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x16e81cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x16e820: 0x62800a  movz        $s0, $v1, $v0
    ctx->pc = 0x16e820u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 3));
    // 0x16e824: 0x38830001  xori        $v1, $a0, 0x1
    ctx->pc = 0x16e824u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)1);
label_16e828:
    // 0x16e828: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x16e828u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16e82c: 0x43800a  movz        $s0, $v0, $v1
    ctx->pc = 0x16e82cu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
label_16e830:
    // 0x16e830: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16e830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16e834: 0x16420008  bne         $s2, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16E834u;
    {
        const bool branch_taken_0x16e834 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x16E838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E834u;
            // 0x16e838: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e834) {
            ctx->pc = 0x16E858u;
            goto label_16e858;
        }
    }
    ctx->pc = 0x16E83Cu;
    // 0x16e83c: 0x8e620018  lw          $v0, 0x18($s3)
    ctx->pc = 0x16e83cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x16e840: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x16e840u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x16e844: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x16e844u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x16e848: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x16E848u;
    {
        const bool branch_taken_0x16e848 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e848) {
            ctx->pc = 0x16E84Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E848u;
            // 0x16e84c: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E870u;
            goto label_16e870;
        }
    }
    ctx->pc = 0x16E850u;
    // 0x16e850: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x16E850u;
    {
        const bool branch_taken_0x16e850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E850u;
            // 0x16e854: 0xae300074  sw          $s0, 0x74($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 116), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e850) {
            ctx->pc = 0x16E874u;
            goto label_16e874;
        }
    }
    ctx->pc = 0x16E858u;
label_16e858:
    // 0x16e858: 0x16020003  bne         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16E858u;
    {
        const bool branch_taken_0x16e858 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x16E85Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E858u;
            // 0x16e85c: 0x24030005  addiu       $v1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e858) {
            ctx->pc = 0x16E868u;
            goto label_16e868;
        }
    }
    ctx->pc = 0x16E860u;
    // 0x16e860: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16E860u;
    {
        const bool branch_taken_0x16e860 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E860u;
            // 0x16e864: 0x24100003  addiu       $s0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e860) {
            ctx->pc = 0x16E870u;
            goto label_16e870;
        }
    }
    ctx->pc = 0x16E868u;
label_16e868:
    // 0x16e868: 0x3a020003  xori        $v0, $s0, 0x3
    ctx->pc = 0x16e868u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ (uint64_t)(uint16_t)3);
    // 0x16e86c: 0x62800a  movz        $s0, $v1, $v0
    ctx->pc = 0x16e86cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 3));
label_16e870:
    // 0x16e870: 0xae300074  sw          $s0, 0x74($s1)
    ctx->pc = 0x16e870u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 116), GPR_U32(ctx, 16));
label_16e874:
    // 0x16e874: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16e874u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16e878: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16e878u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16e87c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16e87cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16e880: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16e880u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16e884: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16e884u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16e888: 0x3e00008  jr          $ra
    ctx->pc = 0x16E888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E88Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E888u;
            // 0x16e88c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E808u: goto label_16e808;
            case 0x16E828u: goto label_16e828;
            case 0x16E830u: goto label_16e830;
            case 0x16E858u: goto label_16e858;
            case 0x16E868u: goto label_16e868;
            case 0x16E870u: goto label_16e870;
            case 0x16E874u: goto label_16e874;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E890u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

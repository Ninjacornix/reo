#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BAA0
// Address: 0x13baa0 - 0x13bba8
void sub_0013BAA0_0x13baa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BAA0_0x13baa0");
#endif

    switch (ctx->pc) {
        case 0x13bb1cu: goto label_13bb1c;
        case 0x13bb30u: goto label_13bb30;
        case 0x13bb38u: goto label_13bb38;
        case 0x13bb40u: goto label_13bb40;
        case 0x13bb48u: goto label_13bb48;
        case 0x13bb50u: goto label_13bb50;
        case 0x13bb7cu: goto label_13bb7c;
        default: break;
    }

    ctx->pc = 0x13baa0u;

    // 0x13baa0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13baa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13baa4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13baa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13baa8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13baa8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13baac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13baacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13bab0: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x13bab0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13bab4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13bab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13bab8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13bab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13babc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13babcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x13bac0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x13bac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x13bac4: 0x1600000c  bnez        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x13BAC4u;
    {
        const bool branch_taken_0x13bac4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13BAC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BAC4u;
            // 0x13bac8: 0xffbf0030  sd          $ra, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bac4) {
            ctx->pc = 0x13BAF8u;
            goto label_13baf8;
        }
    }
    ctx->pc = 0x13BACCu;
    // 0x13bacc: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13baccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13bad0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13bad0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13bad4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13bad4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13bad8: 0x24a5d110  addiu       $a1, $a1, -0x2EF0
    ctx->pc = 0x13bad8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955280));
    // 0x13badc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13badcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13bae0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13bae0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13bae4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13bae4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13bae8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13bae8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13baec: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13baecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13baf0: 0x804ebf2  j           func_13AFC8
    ctx->pc = 0x13BAF0u;
    ctx->pc = 0x13BAF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BAF0u;
            // 0x13baf4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13BAF8u;
label_13baf8:
    // 0x13baf8: 0x92020002  lbu         $v0, 0x2($s0)
    ctx->pc = 0x13baf8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x13bafc: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x13bafcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x13bb00: 0x54400021  bnel        $v0, $zero, . + 4 + (0x21 << 2)
    ctx->pc = 0x13BB00u;
    {
        const bool branch_taken_0x13bb00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13bb00) {
            ctx->pc = 0x13BB04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB00u;
            // 0x13bb04: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13BB88u;
            goto label_13bb88;
        }
    }
    ctx->pc = 0x13BB08u;
    // 0x13bb08: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x13bb08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x13bb0c: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13BB0Cu;
    {
        const bool branch_taken_0x13bb0c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BB10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB0Cu;
            // 0x13bb10: 0x3c110063  lui         $s1, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)99 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bb0c) {
            ctx->pc = 0x13BB1Cu;
            goto label_13bb1c;
        }
    }
    ctx->pc = 0x13BB14u;
    // 0x13bb14: 0xc04de1a  jal         func_137868
    ctx->pc = 0x13BB14u;
    SET_GPR_U32(ctx, 31, 0x13BB1Cu);
    ctx->pc = 0x137868u;
    if (runtime->hasFunction(0x137868u)) {
        auto targetFn = runtime->lookupFunction(0x137868u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB1Cu; }
        if (ctx->pc != 0x13BB1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137868_0x137868(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB1Cu; }
        if (ctx->pc != 0x13BB1Cu) { return; }
    }
    ctx->pc = 0x13BB1Cu;
label_13bb1c:
    // 0x13bb1c: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x13bb1cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13bb20: 0x3631fff6  ori         $s1, $s1, 0xFFF6
    ctx->pc = 0x13bb20u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)65526);
    // 0x13bb24: 0x3c140022  lui         $s4, 0x22
    ctx->pc = 0x13bb24u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)34 << 16));
    // 0x13bb28: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x13BB28u;
    {
        const bool branch_taken_0x13bb28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB28u;
            // 0x13bb2c: 0x3c150024  lui         $s5, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bb28) {
            ctx->pc = 0x13BB38u;
            goto label_13bb38;
        }
    }
    ctx->pc = 0x13BB30u;
label_13bb30:
    // 0x13bb30: 0xc04ebe6  jal         func_13AF98
    ctx->pc = 0x13BB30u;
    SET_GPR_U32(ctx, 31, 0x13BB38u);
    ctx->pc = 0x13AF98u;
    if (runtime->hasFunction(0x13AF98u)) {
        auto targetFn = runtime->lookupFunction(0x13AF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB38u; }
        if (ctx->pc != 0x13BB38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AF98_0x13af98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB38u; }
        if (ctx->pc != 0x13BB38u) { return; }
    }
    ctx->pc = 0x13BB38u;
label_13bb38:
    // 0x13bb38: 0xc04df60  jal         func_137D80
    ctx->pc = 0x13BB38u;
    SET_GPR_U32(ctx, 31, 0x13BB40u);
    ctx->pc = 0x137D80u;
    if (runtime->hasFunction(0x137D80u)) {
        auto targetFn = runtime->lookupFunction(0x137D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB40u; }
        if (ctx->pc != 0x13BB40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137D80_0x137d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB40u; }
        if (ctx->pc != 0x13BB40u) { return; }
    }
    ctx->pc = 0x13BB40u;
label_13bb40:
    // 0x13bb40: 0xc04ec76  jal         func_13B1D8
    ctx->pc = 0x13BB40u;
    SET_GPR_U32(ctx, 31, 0x13BB48u);
    ctx->pc = 0x13B1D8u;
    if (runtime->hasFunction(0x13B1D8u)) {
        auto targetFn = runtime->lookupFunction(0x13B1D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB48u; }
        if (ctx->pc != 0x13BB48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B1D8_0x13b1d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB48u; }
        if (ctx->pc != 0x13BB48u) { return; }
    }
    ctx->pc = 0x13BB48u;
label_13bb48:
    // 0x13bb48: 0xc04eeea  jal         func_13BBA8
    ctx->pc = 0x13BB48u;
    SET_GPR_U32(ctx, 31, 0x13BB50u);
    ctx->pc = 0x13BB4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB48u;
            // 0x13bb4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BBA8u;
    if (runtime->hasFunction(0x13BBA8u)) {
        auto targetFn = runtime->lookupFunction(0x13BBA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB50u; }
        if (ctx->pc != 0x13BB50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BBA8_0x13bba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB50u; }
        if (ctx->pc != 0x13BB50u) { return; }
    }
    ctx->pc = 0x13BB50u;
label_13bb50:
    // 0x13bb50: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x13bb50u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x13bb54: 0x5473000a  bnel        $v1, $s3, . + 4 + (0xA << 2)
    ctx->pc = 0x13BB54u;
    {
        const bool branch_taken_0x13bb54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        if (branch_taken_0x13bb54) {
            ctx->pc = 0x13BB58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB54u;
            // 0x13bb58: 0xae000028  sw          $zero, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13BB80u;
            goto label_13bb80;
        }
    }
    ctx->pc = 0x13BB5Cu;
    // 0x13bb5c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13bb5cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13bb60: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x13bb60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13bb64: 0x1040fff2  beqz        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x13BB64u;
    {
        const bool branch_taken_0x13bb64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13BB68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB64u;
            // 0x13bb68: 0x8e82dea4  lw          $v0, -0x215C($s4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294958756)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13bb64) {
            ctx->pc = 0x13BB30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13bb30;
        }
    }
    ctx->pc = 0x13BB6Cu;
    // 0x13bb6c: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x13BB6Cu;
    {
        const bool branch_taken_0x13bb6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x13bb6c) {
            ctx->pc = 0x13BB70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB6Cu;
            // 0x13bb70: 0xae000028  sw          $zero, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13BB80u;
            goto label_13bb80;
        }
    }
    ctx->pc = 0x13BB74u;
    // 0x13bb74: 0xc045a12  jal         func_116848
    ctx->pc = 0x13BB74u;
    SET_GPR_U32(ctx, 31, 0x13BB7Cu);
    ctx->pc = 0x13BB78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BB74u;
            // 0x13bb78: 0x26a4d128  addiu       $a0, $s5, -0x2ED8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294955304));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB7Cu; }
        if (ctx->pc != 0x13BB7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BB7Cu; }
        if (ctx->pc != 0x13BB7Cu) { return; }
    }
    ctx->pc = 0x13BB7Cu;
label_13bb7c:
    // 0x13bb7c: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x13bb7cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
label_13bb80:
    // 0x13bb80: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x13bb80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x13bb84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13bb84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13bb88:
    // 0x13bb88: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13bb88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13bb8c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13bb8cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13bb90: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13bb90u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13bb94: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13bb94u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13bb98: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x13bb98u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13bb9c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13bb9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13bba0: 0x3e00008  jr          $ra
    ctx->pc = 0x13BBA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BBA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BBA0u;
            // 0x13bba4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13BAF8u: goto label_13baf8;
            case 0x13BB1Cu: goto label_13bb1c;
            case 0x13BB30u: goto label_13bb30;
            case 0x13BB38u: goto label_13bb38;
            case 0x13BB40u: goto label_13bb40;
            case 0x13BB48u: goto label_13bb48;
            case 0x13BB50u: goto label_13bb50;
            case 0x13BB7Cu: goto label_13bb7c;
            case 0x13BB80u: goto label_13bb80;
            case 0x13BB88u: goto label_13bb88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13BBA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

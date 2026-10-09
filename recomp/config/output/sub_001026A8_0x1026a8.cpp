#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001026A8
// Address: 0x1026a8 - 0x1027f0
void sub_001026A8_0x1026a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001026A8_0x1026a8");
#endif

    switch (ctx->pc) {
        case 0x1026c8u: goto label_1026c8;
        case 0x1026e0u: goto label_1026e0;
        case 0x1026fcu: goto label_1026fc;
        case 0x102724u: goto label_102724;
        case 0x102740u: goto label_102740;
        case 0x102754u: goto label_102754;
        case 0x102768u: goto label_102768;
        case 0x10277cu: goto label_10277c;
        case 0x102790u: goto label_102790;
        case 0x1027a4u: goto label_1027a4;
        case 0x1027a8u: goto label_1027a8;
        case 0x1027c4u: goto label_1027c4;
        default: break;
    }

    ctx->pc = 0x1026a8u;

    // 0x1026a8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1026a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1026ac: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1026acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1026b0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1026b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1026b4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1026b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026b8: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1026b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1026bc: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1026bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1026c0: 0xc0408a6  jal         func_102298
    ctx->pc = 0x1026C0u;
    SET_GPR_U32(ctx, 31, 0x1026C8u);
    ctx->pc = 0x1026C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1026C0u;
            // 0x1026c4: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102298u;
    if (runtime->hasFunction(0x102298u)) {
        auto targetFn = runtime->lookupFunction(0x102298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026C8u; }
        if (ctx->pc != 0x1026C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102298_0x102298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026C8u; }
        if (ctx->pc != 0x1026C8u) { return; }
    }
    ctx->pc = 0x1026C8u;
label_1026c8:
    // 0x1026c8: 0x14400042  bnez        $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x1026C8u;
    {
        const bool branch_taken_0x1026c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1026CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1026C8u;
            // 0x1026cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1026c8) {
            ctx->pc = 0x1027D4u;
            goto label_1027d4;
        }
    }
    ctx->pc = 0x1026D0u;
    // 0x1026d0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1026d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026d4: 0x2653021c  addiu       $s3, $s2, 0x21C
    ctx->pc = 0x1026d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 540));
    // 0x1026d8: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x1026d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026dc: 0x0  nop
    ctx->pc = 0x1026dcu;
    // NOP
label_1026e0:
    // 0x1026e0: 0x7a020000  lq          $v0, 0x0($s0)
    ctx->pc = 0x1026e0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1026e4: 0x26240400  addiu       $a0, $s1, 0x400
    ctx->pc = 0x1026e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1024));
    // 0x1026e8: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1026e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1026ec: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1026ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026f0: 0x7fa20000  sq          $v0, 0x0($sp)
    ctx->pc = 0x1026f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 2));
    // 0x1026f4: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x1026F4u;
    SET_GPR_U32(ctx, 31, 0x1026FCu);
    ctx->pc = 0x1026F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1026F4u;
            // 0x1026f8: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026FCu; }
        if (ctx->pc != 0x1026FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026FCu; }
        if (ctx->pc != 0x1026FCu) { return; }
    }
    ctx->pc = 0x1026FCu;
label_1026fc:
    // 0x1026fc: 0x2e220020  sltiu       $v0, $s1, 0x20
    ctx->pc = 0x1026fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x102700: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x102700u;
    {
        const bool branch_taken_0x102700 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102700u;
            // 0x102704: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102700) {
            ctx->pc = 0x1026E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1026e0;
        }
    }
    ctx->pc = 0x102708u;
    // 0x102708: 0x9e420200  lwu         $v0, 0x200($s2)
    ctx->pc = 0x102708u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 512)));
    // 0x10270c: 0x70001ca9  por         $v1, $zero, $zero
    ctx->pc = 0x10270cu;
    SET_GPR_VEC(ctx, 3, PS2_POR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x102710: 0x7fa30000  sq          $v1, 0x0($sp)
    ctx->pc = 0x102710u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 3));
    // 0x102714: 0x24040430  addiu       $a0, $zero, 0x430
    ctx->pc = 0x102714u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1072));
    // 0x102718: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102718u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10271c: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x10271Cu;
    SET_GPR_U32(ctx, 31, 0x102724u);
    ctx->pc = 0x102720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10271Cu;
            // 0x102720: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102724u; }
        if (ctx->pc != 0x102724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102724u; }
        if (ctx->pc != 0x102724u) { return; }
    }
    ctx->pc = 0x102724u;
label_102724:
    // 0x102724: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x102724u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102728: 0x9e420204  lwu         $v0, 0x204($s2)
    ctx->pc = 0x102728u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 516)));
    // 0x10272c: 0x24040431  addiu       $a0, $zero, 0x431
    ctx->pc = 0x10272cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1073));
    // 0x102730: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102730u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102734: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x102734u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102738: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102738u;
    SET_GPR_U32(ctx, 31, 0x102740u);
    ctx->pc = 0x10273Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102738u;
            // 0x10273c: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102740u; }
        if (ctx->pc != 0x102740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102740u; }
        if (ctx->pc != 0x102740u) { return; }
    }
    ctx->pc = 0x102740u;
label_102740:
    // 0x102740: 0x9e420208  lwu         $v0, 0x208($s2)
    ctx->pc = 0x102740u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 520)));
    // 0x102744: 0x24040432  addiu       $a0, $zero, 0x432
    ctx->pc = 0x102744u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1074));
    // 0x102748: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102748u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10274c: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x10274Cu;
    SET_GPR_U32(ctx, 31, 0x102754u);
    ctx->pc = 0x102750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10274Cu;
            // 0x102750: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102754u; }
        if (ctx->pc != 0x102754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102754u; }
        if (ctx->pc != 0x102754u) { return; }
    }
    ctx->pc = 0x102754u;
label_102754:
    // 0x102754: 0x9e42020c  lwu         $v0, 0x20C($s2)
    ctx->pc = 0x102754u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 524)));
    // 0x102758: 0x24040434  addiu       $a0, $zero, 0x434
    ctx->pc = 0x102758u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1076));
    // 0x10275c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x10275cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102760: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102760u;
    SET_GPR_U32(ctx, 31, 0x102768u);
    ctx->pc = 0x102764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102760u;
            // 0x102764: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102768u; }
        if (ctx->pc != 0x102768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102768u; }
        if (ctx->pc != 0x102768u) { return; }
    }
    ctx->pc = 0x102768u;
label_102768:
    // 0x102768: 0x9e420210  lwu         $v0, 0x210($s2)
    ctx->pc = 0x102768u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 528)));
    // 0x10276c: 0x24040435  addiu       $a0, $zero, 0x435
    ctx->pc = 0x10276cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1077));
    // 0x102770: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102770u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102774: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102774u;
    SET_GPR_U32(ctx, 31, 0x10277Cu);
    ctx->pc = 0x102778u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102774u;
            // 0x102778: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10277Cu; }
        if (ctx->pc != 0x10277Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10277Cu; }
        if (ctx->pc != 0x10277Cu) { return; }
    }
    ctx->pc = 0x10277Cu;
label_10277c:
    // 0x10277c: 0x9e420214  lwu         $v0, 0x214($s2)
    ctx->pc = 0x10277cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 532)));
    // 0x102780: 0x24040436  addiu       $a0, $zero, 0x436
    ctx->pc = 0x102780u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1078));
    // 0x102784: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102784u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102788: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102788u;
    SET_GPR_U32(ctx, 31, 0x102790u);
    ctx->pc = 0x10278Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102788u;
            // 0x10278c: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102790u; }
        if (ctx->pc != 0x102790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102790u; }
        if (ctx->pc != 0x102790u) { return; }
    }
    ctx->pc = 0x102790u;
label_102790:
    // 0x102790: 0x9e420218  lwu         $v0, 0x218($s2)
    ctx->pc = 0x102790u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 536)));
    // 0x102794: 0x24040437  addiu       $a0, $zero, 0x437
    ctx->pc = 0x102794u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1079));
    // 0x102798: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102798u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10279c: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x10279Cu;
    SET_GPR_U32(ctx, 31, 0x1027A4u);
    ctx->pc = 0x1027A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10279Cu;
            // 0x1027a0: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027A4u; }
        if (ctx->pc != 0x1027A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027A4u; }
        if (ctx->pc != 0x1027A4u) { return; }
    }
    ctx->pc = 0x1027A4u;
label_1027a4:
    // 0x1027a4: 0x0  nop
    ctx->pc = 0x1027a4u;
    // NOP
label_1027a8:
    // 0x1027a8: 0x96020000  lhu         $v0, 0x0($s0)
    ctx->pc = 0x1027a8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1027ac: 0x26240420  addiu       $a0, $s1, 0x420
    ctx->pc = 0x1027acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1056));
    // 0x1027b0: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1027b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1027b4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1027b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1027b8: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x1027b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x1027bc: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x1027BCu;
    SET_GPR_U32(ctx, 31, 0x1027C4u);
    ctx->pc = 0x1027C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1027BCu;
            // 0x1027c0: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027C4u; }
        if (ctx->pc != 0x1027C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027C4u; }
        if (ctx->pc != 0x1027C4u) { return; }
    }
    ctx->pc = 0x1027C4u;
label_1027c4:
    // 0x1027c4: 0x2e220010  sltiu       $v0, $s1, 0x10
    ctx->pc = 0x1027c4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1027c8: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1027C8u;
    {
        const bool branch_taken_0x1027c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1027CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1027C8u;
            // 0x1027cc: 0x26100002  addiu       $s0, $s0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1027c8) {
            ctx->pc = 0x1027A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1027a8;
        }
    }
    ctx->pc = 0x1027D0u;
    // 0x1027d0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1027d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1027d4:
    // 0x1027d4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1027d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1027d8: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x1027d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1027dc: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1027dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1027e0: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1027e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1027e4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1027e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1027e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1027E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1027ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1027E8u;
            // 0x1027ec: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1026C8u: goto label_1026c8;
            case 0x1026E0u: goto label_1026e0;
            case 0x1026FCu: goto label_1026fc;
            case 0x102724u: goto label_102724;
            case 0x102740u: goto label_102740;
            case 0x102754u: goto label_102754;
            case 0x102768u: goto label_102768;
            case 0x10277Cu: goto label_10277c;
            case 0x102790u: goto label_102790;
            case 0x1027A4u: goto label_1027a4;
            case 0x1027A8u: goto label_1027a8;
            case 0x1027C4u: goto label_1027c4;
            case 0x1027D4u: goto label_1027d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1027F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

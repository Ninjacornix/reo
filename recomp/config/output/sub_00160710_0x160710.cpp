#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160710
// Address: 0x160710 - 0x1607d8
void sub_00160710_0x160710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160710_0x160710");
#endif

    switch (ctx->pc) {
        case 0x160724u: goto label_160724;
        case 0x16073cu: goto label_16073c;
        case 0x160750u: goto label_160750;
        case 0x160784u: goto label_160784;
        case 0x1607b0u: goto label_1607b0;
        default: break;
    }

    ctx->pc = 0x160710u;

    // 0x160710: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x160710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x160714: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x160714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x160718: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x160718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x16071c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16071Cu;
    SET_GPR_U32(ctx, 31, 0x160724u);
    ctx->pc = 0x160720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16071Cu;
            // 0x160720: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160724u; }
        if (ctx->pc != 0x160724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160724u; }
        if (ctx->pc != 0x160724u) { return; }
    }
    ctx->pc = 0x160724u;
label_160724:
    // 0x160724: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x160724u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160728: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x160728u;
    {
        const bool branch_taken_0x160728 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16072Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160728u;
            // 0x16072c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160728) {
            ctx->pc = 0x160748u;
            goto label_160748;
        }
    }
    ctx->pc = 0x160730u;
    // 0x160730: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160730u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160734: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160734u;
    SET_GPR_U32(ctx, 31, 0x16073Cu);
    ctx->pc = 0x160738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160734u;
            // 0x160738: 0x2484f778  addiu       $a0, $a0, -0x888 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16073Cu; }
        if (ctx->pc != 0x16073Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16073Cu; }
        if (ctx->pc != 0x16073Cu) { return; }
    }
    ctx->pc = 0x16073Cu;
label_16073c:
    // 0x16073c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16073Cu;
    {
        const bool branch_taken_0x16073c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16073Cu;
            // 0x160740: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16073c) {
            ctx->pc = 0x160754u;
            goto label_160754;
        }
    }
    ctx->pc = 0x160744u;
    // 0x160744: 0x0  nop
    ctx->pc = 0x160744u;
    // NOP
label_160748:
    // 0x160748: 0xc057fa2  jal         func_15FE88
    ctx->pc = 0x160748u;
    SET_GPR_U32(ctx, 31, 0x160750u);
    ctx->pc = 0x15FE88u;
    if (runtime->hasFunction(0x15FE88u)) {
        auto targetFn = runtime->lookupFunction(0x15FE88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160750u; }
        if (ctx->pc != 0x160750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FE88_0x15fe88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160750u; }
        if (ctx->pc != 0x160750u) { return; }
    }
    ctx->pc = 0x160750u;
label_160750:
    // 0x160750: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x160750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_160754:
    // 0x160754: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x160754u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x160758: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x160758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16075c: 0x3e00008  jr          $ra
    ctx->pc = 0x16075Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16075Cu;
            // 0x160760: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160724u: goto label_160724;
            case 0x16073Cu: goto label_16073c;
            case 0x160748u: goto label_160748;
            case 0x160750u: goto label_160750;
            case 0x160754u: goto label_160754;
            case 0x160784u: goto label_160784;
            case 0x1607A8u: goto label_1607a8;
            case 0x1607B0u: goto label_1607b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160764u;
    // 0x160764: 0x0  nop
    ctx->pc = 0x160764u;
    // NOP
    // 0x160768: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160768u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16076c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16076cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160770: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x160770u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160774: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x160774u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160778: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x160778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16077c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16077Cu;
    SET_GPR_U32(ctx, 31, 0x160784u);
    ctx->pc = 0x160780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16077Cu;
            // 0x160780: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160784u; }
        if (ctx->pc != 0x160784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160784u; }
        if (ctx->pc != 0x160784u) { return; }
    }
    ctx->pc = 0x160784u;
label_160784:
    // 0x160784: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x160784u;
    {
        const bool branch_taken_0x160784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160784u;
            // 0x160788: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160784) {
            ctx->pc = 0x1607A8u;
            goto label_1607a8;
        }
    }
    ctx->pc = 0x16078Cu;
    // 0x16078c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16078cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160790: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160790u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160794: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160794u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160798: 0x2484f7b0  addiu       $a0, $a0, -0x850
    ctx->pc = 0x160798u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965168));
    // 0x16079c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16079cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1607a0: 0x8058dd4  j           func_163750
    ctx->pc = 0x1607A0u;
    ctx->pc = 0x1607A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1607A0u;
            // 0x1607a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1607A8u;
label_1607a8:
    // 0x1607a8: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x1607A8u;
    SET_GPR_U32(ctx, 31, 0x1607B0u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1607B0u; }
        if (ctx->pc != 0x1607B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1607B0u; }
        if (ctx->pc != 0x1607B0u) { return; }
    }
    ctx->pc = 0x1607B0u;
label_1607b0:
    // 0x1607b0: 0x3a260001  xori        $a2, $s1, 0x1
    ctx->pc = 0x1607b0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 17) ^ (uint64_t)(uint16_t)1);
    // 0x1607b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1607b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1607b8: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x1607b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1607bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1607bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1607c0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1607c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1607c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1607c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1607c8: 0x6302b  sltu        $a2, $zero, $a2
    ctx->pc = 0x1607c8u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x1607cc: 0x805d4ce  j           func_175338
    ctx->pc = 0x1607CCu;
    ctx->pc = 0x1607D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1607CCu;
            // 0x1607d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1607D4u;
    // 0x1607d4: 0x0  nop
    ctx->pc = 0x1607d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

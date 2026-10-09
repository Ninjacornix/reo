#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F2D8
// Address: 0x11f2d8 - 0x11f7d0
void sub_0011F2D8_0x11f2d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F2D8_0x11f2d8");
#endif

    switch (ctx->pc) {
        case 0x11f320u: goto label_11f320;
        case 0x11f34cu: goto label_11f34c;
        case 0x11f360u: goto label_11f360;
        case 0x11f38cu: goto label_11f38c;
        case 0x11f3b4u: goto label_11f3b4;
        case 0x11f3bcu: goto label_11f3bc;
        case 0x11f3ccu: goto label_11f3cc;
        case 0x11f478u: goto label_11f478;
        case 0x11f4bcu: goto label_11f4bc;
        case 0x11f4c4u: goto label_11f4c4;
        case 0x11f51cu: goto label_11f51c;
        case 0x11f548u: goto label_11f548;
        case 0x11f560u: goto label_11f560;
        case 0x11f584u: goto label_11f584;
        case 0x11f5e4u: goto label_11f5e4;
        case 0x11f664u: goto label_11f664;
        case 0x11f68cu: goto label_11f68c;
        case 0x11f69cu: goto label_11f69c;
        case 0x11f734u: goto label_11f734;
        case 0x11f758u: goto label_11f758;
        default: break;
    }

    ctx->pc = 0x11f2d8u;

    // 0x11f2d8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x11f2d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x11f2dc: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x11f2dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x11f2e0: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x11f2e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x11f2e4: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x11f2e4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f2e8: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x11f2e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11f2ec: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x11f2ecu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f2f0: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x11f2f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x11f2f4: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x11f2f4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f2f8: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f2f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f2fc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f2fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f300: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f304: 0x16800004  bnez        $s4, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F304u;
    {
        const bool branch_taken_0x11f304 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F304u;
            // 0x11f308: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f304) {
            ctx->pc = 0x11F318u;
            goto label_11f318;
        }
    }
    ctx->pc = 0x11F30Cu;
    // 0x11f30c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f30cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f310: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x11F310u;
    {
        const bool branch_taken_0x11f310 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F310u;
            // 0x11f314: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f310) {
            ctx->pc = 0x11F3DCu;
            goto label_11f3dc;
        }
    }
    ctx->pc = 0x11F318u;
label_11f318:
    // 0x11f318: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F318u;
    SET_GPR_U32(ctx, 31, 0x11F320u);
    ctx->pc = 0x11F31Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F318u;
            // 0x11f31c: 0x3c120026  lui         $s2, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F320u; }
        if (ctx->pc != 0x11F320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F320u; }
        if (ctx->pc != 0x11F320u) { return; }
    }
    ctx->pc = 0x11F320u;
label_11f320:
    // 0x11f320: 0x8e501d00  lw          $s0, 0x1D00($s2)
    ctx->pc = 0x11f320u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 7424)));
    // 0x11f324: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F324u;
    {
        const bool branch_taken_0x11f324 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F324u;
            // 0x11f328: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f324) {
            ctx->pc = 0x11F334u;
            goto label_11f334;
        }
    }
    ctx->pc = 0x11F32Cu;
    // 0x11f32c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x11f32cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11f330: 0xae421d00  sw          $v0, 0x1D00($s2)
    ctx->pc = 0x11f330u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 7424), GPR_U32(ctx, 2));
label_11f334:
    // 0x11f334: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F334u;
    {
        const bool branch_taken_0x11f334 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f334) {
            ctx->pc = 0x11F358u;
            goto label_11f358;
        }
    }
    ctx->pc = 0x11F33Cu;
    // 0x11f33c: 0x12600003  beqz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F33Cu;
    {
        const bool branch_taken_0x11f33c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f33c) {
            ctx->pc = 0x11F34Cu;
            goto label_11f34c;
        }
    }
    ctx->pc = 0x11F344u;
    // 0x11f344: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F344u;
    SET_GPR_U32(ctx, 31, 0x11F34Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F34Cu; }
        if (ctx->pc != 0x11F34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F34Cu; }
        if (ctx->pc != 0x11F34Cu) { return; }
    }
    ctx->pc = 0x11F34Cu;
label_11f34c:
    // 0x11f34c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f34cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f350: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x11F350u;
    {
        const bool branch_taken_0x11f350 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F350u;
            // 0x11f354: 0x34428005  ori         $v0, $v0, 0x8005 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32773);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f350) {
            ctx->pc = 0x11F3DCu;
            goto label_11f3dc;
        }
    }
    ctx->pc = 0x11F358u;
label_11f358:
    // 0x11f358: 0xc047a38  jal         func_11E8E0
    ctx->pc = 0x11F358u;
    SET_GPR_U32(ctx, 31, 0x11F360u);
    ctx->pc = 0x11E8E0u;
    if (runtime->hasFunction(0x11E8E0u)) {
        auto targetFn = runtime->lookupFunction(0x11E8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F360u; }
        if (ctx->pc != 0x11F360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E8E0_0x11e8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F360u; }
        if (ctx->pc != 0x11F360u) { return; }
    }
    ctx->pc = 0x11F360u;
label_11f360:
    // 0x11f360: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11f360u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f364: 0x623000b  bgezl       $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x11F364u;
    {
        const bool branch_taken_0x11f364 = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x11f364) {
            ctx->pc = 0x11F368u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F364u;
            // 0x11f368: 0xae140008  sw          $s4, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F394u;
            goto label_11f394;
        }
    }
    ctx->pc = 0x11F36Cu;
    // 0x11f36c: 0x8e421d00  lw          $v0, 0x1D00($s2)
    ctx->pc = 0x11f36cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 7424)));
    // 0x11f370: 0xae501d00  sw          $s0, 0x1D00($s2)
    ctx->pc = 0x11f370u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 7424), GPR_U32(ctx, 16));
    // 0x11f374: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x11f374u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x11f378: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x11f378u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x11f37c: 0x12600017  beqz        $s3, . + 4 + (0x17 << 2)
    ctx->pc = 0x11F37Cu;
    {
        const bool branch_taken_0x11f37c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F37Cu;
            // 0x11f380: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f37c) {
            ctx->pc = 0x11F3DCu;
            goto label_11f3dc;
        }
    }
    ctx->pc = 0x11F384u;
    // 0x11f384: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F384u;
    SET_GPR_U32(ctx, 31, 0x11F38Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F38Cu; }
        if (ctx->pc != 0x11F38Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F38Cu; }
        if (ctx->pc != 0x11F38Cu) { return; }
    }
    ctx->pc = 0x11F38Cu;
label_11f38c:
    // 0x11f38c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x11F38Cu;
    {
        const bool branch_taken_0x11f38c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F38Cu;
            // 0x11f390: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f38c) {
            ctx->pc = 0x11F3DCu;
            goto label_11f3dc;
        }
    }
    ctx->pc = 0x11F394u;
label_11f394:
    // 0x11f394: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x11f394u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x11f398: 0xae15000c  sw          $s5, 0xC($s0)
    ctx->pc = 0x11f398u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 21));
    // 0x11f39c: 0x24c6f278  addiu       $a2, $a2, -0xD88
    ctx->pc = 0x11f39cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294963832));
    // 0x11f3a0: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x11f3a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x11f3a4: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x11f3a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f3a8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11f3a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f3ac: 0xc047c00  jal         func_11F000
    ctx->pc = 0x11F3ACu;
    SET_GPR_U32(ctx, 31, 0x11F3B4u);
    ctx->pc = 0x11F3B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F3ACu;
            // 0x11f3b0: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F000u;
    if (runtime->hasFunction(0x11F000u)) {
        auto targetFn = runtime->lookupFunction(0x11F000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F3B4u; }
        if (ctx->pc != 0x11F3B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F000_0x11f000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F3B4u; }
        if (ctx->pc != 0x11F3B4u) { return; }
    }
    ctx->pc = 0x11F3B4u;
label_11f3b4:
    // 0x11f3b4: 0xc047ade  jal         func_11EB78
    ctx->pc = 0x11F3B4u;
    SET_GPR_U32(ctx, 31, 0x11F3BCu);
    ctx->pc = 0x11F3B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F3B4u;
            // 0x11f3b8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EB78u;
    if (runtime->hasFunction(0x11EB78u)) {
        auto targetFn = runtime->lookupFunction(0x11EB78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F3BCu; }
        if (ctx->pc != 0x11F3BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EB78_0x11eb78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F3BCu; }
        if (ctx->pc != 0x11F3BCu) { return; }
    }
    ctx->pc = 0x11F3BCu;
label_11f3bc:
    // 0x11f3bc: 0x12600004  beqz        $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F3BCu;
    {
        const bool branch_taken_0x11f3bc = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F3C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F3BCu;
            // 0x11f3c0: 0x101100  sll         $v0, $s0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f3bc) {
            ctx->pc = 0x11F3D0u;
            goto label_11f3d0;
        }
    }
    ctx->pc = 0x11F3C4u;
    // 0x11f3c4: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F3C4u;
    SET_GPR_U32(ctx, 31, 0x11F3CCu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F3CCu; }
        if (ctx->pc != 0x11F3CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F3CCu; }
        if (ctx->pc != 0x11F3CCu) { return; }
    }
    ctx->pc = 0x11F3CCu;
label_11f3cc:
    // 0x11f3cc: 0x101100  sll         $v0, $s0, 4
    ctx->pc = 0x11f3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
label_11f3d0:
    // 0x11f3d0: 0x322300fe  andi        $v1, $s1, 0xFE
    ctx->pc = 0x11f3d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)254);
    // 0x11f3d4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x11f3d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x11f3d8: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x11f3d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
label_11f3dc:
    // 0x11f3dc: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x11f3dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11f3e0: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x11f3e0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11f3e4: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x11f3e4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11f3e8: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x11f3e8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f3ec: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f3ecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f3f0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f3f0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f3f4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f3f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f3f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f3f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f3fc: 0x3e00008  jr          $ra
    ctx->pc = 0x11F3FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F3FCu;
            // 0x11f400: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F404u;
    // 0x11f404: 0x0  nop
    ctx->pc = 0x11f404u;
    // NOP
    // 0x11f408: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x11f408u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x11f40c: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x11f40cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x11f410: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x11f410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x11f414: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x11f414u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f418: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f41c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11f41cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f420: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x11f420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x11f424: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x11f424u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f428: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f42c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f42cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f430: 0x16600004  bnez        $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F430u;
    {
        const bool branch_taken_0x11f430 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F430u;
            // 0x11f434: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f430) {
            ctx->pc = 0x11F444u;
            goto label_11f444;
        }
    }
    ctx->pc = 0x11F438u;
    // 0x11f438: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f438u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f43c: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x11F43Cu;
    {
        const bool branch_taken_0x11f43c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F43Cu;
            // 0x11f440: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f43c) {
            ctx->pc = 0x11F4D4u;
            goto label_11f4d4;
        }
    }
    ctx->pc = 0x11F444u;
label_11f444:
    // 0x11f444: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x11f444u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
    // 0x11f448: 0x8e501d00  lw          $s0, 0x1D00($s2)
    ctx->pc = 0x11f448u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 7424)));
    // 0x11f44c: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F44Cu;
    {
        const bool branch_taken_0x11f44c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f44c) {
            ctx->pc = 0x11F45Cu;
            goto label_11f45c;
        }
    }
    ctx->pc = 0x11F454u;
    // 0x11f454: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x11f454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x11f458: 0xae421d00  sw          $v0, 0x1D00($s2)
    ctx->pc = 0x11f458u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 7424), GPR_U32(ctx, 2));
label_11f45c:
    // 0x11f45c: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F45Cu;
    {
        const bool branch_taken_0x11f45c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f45c) {
            ctx->pc = 0x11F470u;
            goto label_11f470;
        }
    }
    ctx->pc = 0x11F464u;
    // 0x11f464: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f464u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f468: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x11F468u;
    {
        const bool branch_taken_0x11f468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F468u;
            // 0x11f46c: 0x34428005  ori         $v0, $v0, 0x8005 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32773);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f468) {
            ctx->pc = 0x11F4D4u;
            goto label_11f4d4;
        }
    }
    ctx->pc = 0x11F470u;
label_11f470:
    // 0x11f470: 0xc047a1c  jal         func_11E870
    ctx->pc = 0x11F470u;
    SET_GPR_U32(ctx, 31, 0x11F478u);
    ctx->pc = 0x11E870u;
    if (runtime->hasFunction(0x11E870u)) {
        auto targetFn = runtime->lookupFunction(0x11E870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F478u; }
        if (ctx->pc != 0x11F478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E870_0x11e870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F478u; }
        if (ctx->pc != 0x11F478u) { return; }
    }
    ctx->pc = 0x11F478u;
label_11f478:
    // 0x11f478: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11f478u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f47c: 0x6230007  bgezl       $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x11F47Cu;
    {
        const bool branch_taken_0x11f47c = (GPR_S64(ctx, 17) >= 0);
        if (branch_taken_0x11f47c) {
            ctx->pc = 0x11F480u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F47Cu;
            // 0x11f480: 0xae130008  sw          $s3, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F49Cu;
            goto label_11f49c;
        }
    }
    ctx->pc = 0x11F484u;
    // 0x11f484: 0x8e431d00  lw          $v1, 0x1D00($s2)
    ctx->pc = 0x11f484u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 7424)));
    // 0x11f488: 0xae501d00  sw          $s0, 0x1D00($s2)
    ctx->pc = 0x11f488u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 7424), GPR_U32(ctx, 16));
    // 0x11f48c: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x11f48cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x11f490: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x11f490u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x11f494: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x11F494u;
    {
        const bool branch_taken_0x11f494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F494u;
            // 0x11f498: 0xdfbf0060  ld          $ra, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f494) {
            ctx->pc = 0x11F4D8u;
            goto label_11f4d8;
        }
    }
    ctx->pc = 0x11F49Cu;
label_11f49c:
    // 0x11f49c: 0x3c060012  lui         $a2, 0x12
    ctx->pc = 0x11f49cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)18 << 16));
    // 0x11f4a0: 0xae14000c  sw          $s4, 0xC($s0)
    ctx->pc = 0x11f4a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 20));
    // 0x11f4a4: 0x24c6f278  addiu       $a2, $a2, -0xD88
    ctx->pc = 0x11f4a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294963832));
    // 0x11f4a8: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x11f4a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x11f4ac: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x11f4acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f4b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11f4b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f4b4: 0xc047bc2  jal         func_11EF08
    ctx->pc = 0x11F4B4u;
    SET_GPR_U32(ctx, 31, 0x11F4BCu);
    ctx->pc = 0x11F4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F4B4u;
            // 0x11f4b8: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EF08u;
    if (runtime->hasFunction(0x11EF08u)) {
        auto targetFn = runtime->lookupFunction(0x11EF08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4BCu; }
        if (ctx->pc != 0x11F4BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EF08_0x11ef08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4BCu; }
        if (ctx->pc != 0x11F4BCu) { return; }
    }
    ctx->pc = 0x11F4BCu;
label_11f4bc:
    // 0x11f4bc: 0xc047ab2  jal         func_11EAC8
    ctx->pc = 0x11F4BCu;
    SET_GPR_U32(ctx, 31, 0x11F4C4u);
    ctx->pc = 0x11F4C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F4BCu;
            // 0x11f4c0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EAC8u;
    if (runtime->hasFunction(0x11EAC8u)) {
        auto targetFn = runtime->lookupFunction(0x11EAC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4C4u; }
        if (ctx->pc != 0x11F4C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EAC8_0x11eac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F4C4u; }
        if (ctx->pc != 0x11F4C4u) { return; }
    }
    ctx->pc = 0x11F4C4u;
label_11f4c4:
    // 0x11f4c4: 0x101100  sll         $v0, $s0, 4
    ctx->pc = 0x11f4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x11f4c8: 0x322300fe  andi        $v1, $s1, 0xFE
    ctx->pc = 0x11f4c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)254);
    // 0x11f4cc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x11f4ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x11f4d0: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x11f4d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
label_11f4d4:
    // 0x11f4d4: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x11f4d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_11f4d8:
    // 0x11f4d8: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x11f4d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11f4dc: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x11f4dcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f4e0: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f4e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f4e4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f4e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f4e8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f4e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f4ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f4ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f4f0: 0x3e00008  jr          $ra
    ctx->pc = 0x11F4F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F4F0u;
            // 0x11f4f4: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F4F8u;
    // 0x11f4f8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11f4f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11f4fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f4fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f500: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11f500u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f504: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f508: 0x101202  srl         $v0, $s0, 8
    ctx->pc = 0x11f508u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 16), 8));
    // 0x11f50c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f50cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f510: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11f510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11f514: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F514u;
    SET_GPR_U32(ctx, 31, 0x11F51Cu);
    ctx->pc = 0x11F518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F514u;
            // 0x11f518: 0x28900  sll         $s1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F51Cu; }
        if (ctx->pc != 0x11F51Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F51Cu; }
        if (ctx->pc != 0x11F51Cu) { return; }
    }
    ctx->pc = 0x11F51Cu;
label_11f51c:
    // 0x11f51c: 0x6000006  bltz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11F51Cu;
    {
        const bool branch_taken_0x11f51c = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x11F520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F51Cu;
            // 0x11f520: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f51c) {
            ctx->pc = 0x11F538u;
            goto label_11f538;
        }
    }
    ctx->pc = 0x11F524u;
    // 0x11f524: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x11f524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x11f528: 0x2021026  xor         $v0, $s0, $v0
    ctx->pc = 0x11f528u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 2));
    // 0x11f52c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x11f52cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x11f530: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F530u;
    {
        const bool branch_taken_0x11f530 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f530) {
            ctx->pc = 0x11F554u;
            goto label_11f554;
        }
    }
    ctx->pc = 0x11F538u;
label_11f538:
    // 0x11f538: 0x12400003  beqz        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F538u;
    {
        const bool branch_taken_0x11f538 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f538) {
            ctx->pc = 0x11F548u;
            goto label_11f548;
        }
    }
    ctx->pc = 0x11F540u;
    // 0x11f540: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F540u;
    SET_GPR_U32(ctx, 31, 0x11F548u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F548u; }
        if (ctx->pc != 0x11F548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F548u; }
        if (ctx->pc != 0x11F548u) { return; }
    }
    ctx->pc = 0x11F548u;
label_11f548:
    // 0x11f548: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f548u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f54c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x11F54Cu;
    {
        const bool branch_taken_0x11f54c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F54Cu;
            // 0x11f550: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f54c) {
            ctx->pc = 0x11F588u;
            goto label_11f588;
        }
    }
    ctx->pc = 0x11F554u;
label_11f554:
    // 0x11f554: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x11f554u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x11f558: 0xc047a72  jal         func_11E9C8
    ctx->pc = 0x11F558u;
    SET_GPR_U32(ctx, 31, 0x11F560u);
    ctx->pc = 0x11E9C8u;
    if (runtime->hasFunction(0x11E9C8u)) {
        auto targetFn = runtime->lookupFunction(0x11E9C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F560u; }
        if (ctx->pc != 0x11F560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E9C8_0x11e9c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F560u; }
        if (ctx->pc != 0x11F560u) { return; }
    }
    ctx->pc = 0x11F560u;
label_11f560:
    // 0x11f560: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f560u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f564: 0x8c621d00  lw          $v0, 0x1D00($v1)
    ctx->pc = 0x11f564u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 7424)));
    // 0x11f568: 0xac711d00  sw          $s1, 0x1D00($v1)
    ctx->pc = 0x11f568u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 7424), GPR_U32(ctx, 17));
    // 0x11f56c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x11f56cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x11f570: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x11f570u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x11f574: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F574u;
    {
        const bool branch_taken_0x11f574 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F574u;
            // 0x11f578: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f574) {
            ctx->pc = 0x11F588u;
            goto label_11f588;
        }
    }
    ctx->pc = 0x11F57Cu;
    // 0x11f57c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F57Cu;
    SET_GPR_U32(ctx, 31, 0x11F584u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F584u; }
        if (ctx->pc != 0x11F584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F584u; }
        if (ctx->pc != 0x11F584u) { return; }
    }
    ctx->pc = 0x11F584u;
label_11f584:
    // 0x11f584: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11f584u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11f588:
    // 0x11f588: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11f588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f58c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f58cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f590: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f590u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f594: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f594u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f598: 0x3e00008  jr          $ra
    ctx->pc = 0x11F598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F59Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F598u;
            // 0x11f59c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F5A0u;
    // 0x11f5a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11f5a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11f5a4: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x11f5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x11f5a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f5a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f5ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11f5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11f5b0: 0x4800006  bltz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x11F5B0u;
    {
        const bool branch_taken_0x11f5b0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x11F5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F5B0u;
            // 0x11f5b4: 0x28100  sll         $s0, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f5b0) {
            ctx->pc = 0x11F5CCu;
            goto label_11f5cc;
        }
    }
    ctx->pc = 0x11F5B8u;
    // 0x11f5b8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x11f5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11f5bc: 0x821026  xor         $v0, $a0, $v0
    ctx->pc = 0x11f5bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 2));
    // 0x11f5c0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x11f5c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x11f5c4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F5C4u;
    {
        const bool branch_taken_0x11f5c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11f5c4) {
            ctx->pc = 0x11F5D8u;
            goto label_11f5d8;
        }
    }
    ctx->pc = 0x11F5CCu;
label_11f5cc:
    // 0x11f5cc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f5d0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x11F5D0u;
    {
        const bool branch_taken_0x11f5d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F5D0u;
            // 0x11f5d4: 0x34428002  ori         $v0, $v0, 0x8002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32770);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f5d0) {
            ctx->pc = 0x11F608u;
            goto label_11f608;
        }
    }
    ctx->pc = 0x11F5D8u;
label_11f5d8:
    // 0x11f5d8: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x11f5d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11f5dc: 0xc047a4a  jal         func_11E928
    ctx->pc = 0x11F5DCu;
    SET_GPR_U32(ctx, 31, 0x11F5E4u);
    ctx->pc = 0x11E928u;
    if (runtime->hasFunction(0x11E928u)) {
        auto targetFn = runtime->lookupFunction(0x11E928u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F5E4u; }
        if (ctx->pc != 0x11F5E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011E928_0x11e928(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F5E4u; }
        if (ctx->pc != 0x11F5E4u) { return; }
    }
    ctx->pc = 0x11F5E4u;
label_11f5e4:
    // 0x11f5e4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11f5e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f5e8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11F5E8u;
    {
        const bool branch_taken_0x11f5e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F5ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F5E8u;
            // 0x11f5ec: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f5e8) {
            ctx->pc = 0x11F608u;
            goto label_11f608;
        }
    }
    ctx->pc = 0x11F5F0u;
    // 0x11f5f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11f5f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11f5f4: 0x8c431d00  lw          $v1, 0x1D00($v0)
    ctx->pc = 0x11f5f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 7424)));
    // 0x11f5f8: 0xac501d00  sw          $s0, 0x1D00($v0)
    ctx->pc = 0x11f5f8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 7424), GPR_U32(ctx, 16));
    // 0x11f5fc: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x11f5fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x11f600: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x11f600u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x11f604: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11f604u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_11f608:
    // 0x11f608: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11f608u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f60c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f60cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f610: 0x3e00008  jr          $ra
    ctx->pc = 0x11F610u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F610u;
            // 0x11f614: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F618u;
    // 0x11f618: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11f618u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11f61c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f61cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f620: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11f620u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11f624: 0xac40b408  sw          $zero, -0x4BF8($v0)
    ctx->pc = 0x11f624u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294947848), GPR_U32(ctx, 0));
    // 0x11f628: 0xac60b40c  sw          $zero, -0x4BF4($v1)
    ctx->pc = 0x11f628u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294947852), GPR_U32(ctx, 0));
    // 0x11f62c: 0x24841d08  addiu       $a0, $a0, 0x1D08
    ctx->pc = 0x11f62cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7432));
    // 0x11f630: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11f630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f634: 0x8041f1a  j           func_107C68
    ctx->pc = 0x11F634u;
    ctx->pc = 0x11F638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F634u;
            // 0x11f638: 0x24060200  addiu       $a2, $zero, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11F63Cu;
    // 0x11f63c: 0x0  nop
    ctx->pc = 0x11f63cu;
    // NOP
    // 0x11f640: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11f640u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11f644: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11f644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11f648: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f64c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11f64cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f650: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f650u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f654: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f658: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11f658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11f65c: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F65Cu;
    SET_GPR_U32(ctx, 31, 0x11F664u);
    ctx->pc = 0x11F660u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F65Cu;
            // 0x11f660: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F664u; }
        if (ctx->pc != 0x11F664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F664u; }
        if (ctx->pc != 0x11F664u) { return; }
    }
    ctx->pc = 0x11F664u;
label_11f664:
    // 0x11f664: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f664u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f668: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x11f668u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x11f66c: 0x8c73b408  lw          $s3, -0x4BF8($v1)
    ctx->pc = 0x11f66cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294947848)));
    // 0x11f670: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11f670u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f674: 0xacb1b40c  sw          $s1, -0x4BF4($a1)
    ctx->pc = 0x11f674u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294947852), GPR_U32(ctx, 17));
    // 0x11f678: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11f678u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f67c: 0xac70b408  sw          $s0, -0x4BF8($v1)
    ctx->pc = 0x11f67cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294947848), GPR_U32(ctx, 16));
    // 0x11f680: 0x113100  sll         $a2, $s1, 4
    ctx->pc = 0x11f680u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x11f684: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x11F684u;
    SET_GPR_U32(ctx, 31, 0x11F68Cu);
    ctx->pc = 0x11F688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F684u;
            // 0x11f688: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F68Cu; }
        if (ctx->pc != 0x11F68Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F68Cu; }
        if (ctx->pc != 0x11F68Cu) { return; }
    }
    ctx->pc = 0x11F68Cu;
label_11f68c:
    // 0x11f68c: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F68Cu;
    {
        const bool branch_taken_0x11f68c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F68Cu;
            // 0x11f690: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f68c) {
            ctx->pc = 0x11F6A0u;
            goto label_11f6a0;
        }
    }
    ctx->pc = 0x11F694u;
    // 0x11f694: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F694u;
    SET_GPR_U32(ctx, 31, 0x11F69Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F69Cu; }
        if (ctx->pc != 0x11F69Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F69Cu; }
        if (ctx->pc != 0x11F69Cu) { return; }
    }
    ctx->pc = 0x11F69Cu;
label_11f69c:
    // 0x11f69c: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x11f69cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_11f6a0:
    // 0x11f6a0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11f6a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f6a4: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f6a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f6a8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f6a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f6ac: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f6acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f6b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f6b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f6b4: 0x3e00008  jr          $ra
    ctx->pc = 0x11F6B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F6B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F6B4u;
            // 0x11f6b8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F6BCu;
    // 0x11f6bc: 0x0  nop
    ctx->pc = 0x11f6bcu;
    // NOP
    // 0x11f6c0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11f6c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11f6c4: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x11f6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x11f6c8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11f6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11f6cc: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x11f6ccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f6d0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11f6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11f6d4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11f6d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f6d8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11f6d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11f6dc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11f6dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f6e0: 0x6010008  bgez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F6E0u;
    {
        const bool branch_taken_0x11f6e0 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x11F6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F6E0u;
            // 0x11f6e4: 0xffb10010  sd          $s1, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f6e0) {
            ctx->pc = 0x11F704u;
            goto label_11f704;
        }
    }
    ctx->pc = 0x11F6E8u;
    // 0x11f6e8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11f6e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11f6ec: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f6ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f6f0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11f6f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11f6f4: 0x24711d08  addiu       $s1, $v1, 0x1D08
    ctx->pc = 0x11f6f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 7432));
    // 0x11f6f8: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x11f6f8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x11f6fc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11F6FCu;
    {
        const bool branch_taken_0x11f6fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F6FCu;
            // 0x11f700: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f6fc) {
            ctx->pc = 0x11F714u;
            goto label_11f714;
        }
    }
    ctx->pc = 0x11F704u;
label_11f704:
    // 0x11f704: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11f704u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11f708: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f708u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f70c: 0x8c51b408  lw          $s1, -0x4BF8($v0)
    ctx->pc = 0x11f70cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947848)));
    // 0x11f710: 0x8c62b40c  lw          $v0, -0x4BF4($v1)
    ctx->pc = 0x11f710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294947852)));
label_11f714:
    // 0x11f714: 0x202102b  sltu        $v0, $s0, $v0
    ctx->pc = 0x11f714u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f718: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11F718u;
    {
        const bool branch_taken_0x11f718 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11f718) {
            ctx->pc = 0x11F72Cu;
            goto label_11f72c;
        }
    }
    ctx->pc = 0x11F720u;
    // 0x11f720: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x11f720u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11f724: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x11F724u;
    {
        const bool branch_taken_0x11f724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F724u;
            // 0x11f728: 0x34420069  ori         $v0, $v0, 0x69 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)105);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f724) {
            ctx->pc = 0x11F75Cu;
            goto label_11f75c;
        }
    }
    ctx->pc = 0x11F72Cu;
label_11f72c:
    // 0x11f72c: 0xc047598  jal         func_11D660
    ctx->pc = 0x11F72Cu;
    SET_GPR_U32(ctx, 31, 0x11F734u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F734u; }
        if (ctx->pc != 0x11F734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F734u; }
        if (ctx->pc != 0x11F734u) { return; }
    }
    ctx->pc = 0x11F734u;
label_11f734:
    // 0x11f734: 0x101900  sll         $v1, $s0, 4
    ctx->pc = 0x11f734u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x11f738: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x11f738u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x11f73c: 0xac720000  sw          $s2, 0x0($v1)
    ctx->pc = 0x11f73cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 18));
    // 0x11f740: 0xac730004  sw          $s3, 0x4($v1)
    ctx->pc = 0x11f740u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 19));
    // 0x11f744: 0x380202d  daddu       $a0, $gp, $zero
    ctx->pc = 0x11f744u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f748: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F748u;
    {
        const bool branch_taken_0x11f748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F74Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F748u;
            // 0x11f74c: 0xac640008  sw          $a0, 0x8($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f748) {
            ctx->pc = 0x11F758u;
            goto label_11f758;
        }
    }
    ctx->pc = 0x11F750u;
    // 0x11f750: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11F750u;
    SET_GPR_U32(ctx, 31, 0x11F758u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F758u; }
        if (ctx->pc != 0x11F758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11F758u; }
        if (ctx->pc != 0x11F758u) { return; }
    }
    ctx->pc = 0x11F758u;
label_11f758:
    // 0x11f758: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11f758u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11f75c:
    // 0x11f75c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11f75cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11f760: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x11f760u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11f764: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11f764u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11f768: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11f768u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11f76c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11f76cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11f770: 0x3e00008  jr          $ra
    ctx->pc = 0x11F770u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F770u;
            // 0x11f774: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F778u;
    // 0x11f778: 0x4830008  bgezl       $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F778u;
    {
        const bool branch_taken_0x11f778 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x11f778) {
            ctx->pc = 0x11F77Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F778u;
            // 0x11f77c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F79Cu;
            goto label_11f79c;
        }
    }
    ctx->pc = 0x11F780u;
    // 0x11f780: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11f780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11f784: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f784u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f788: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11f788u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11f78c: 0x24651d08  addiu       $a1, $v1, 0x1D08
    ctx->pc = 0x11f78cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 7432));
    // 0x11f790: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x11f790u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x11f794: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x11F794u;
    {
        const bool branch_taken_0x11f794 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F794u;
            // 0x11f798: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f794) {
            ctx->pc = 0x11F7A8u;
            goto label_11f7a8;
        }
    }
    ctx->pc = 0x11F79Cu;
label_11f79c:
    // 0x11f79c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f79cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f7a0: 0x8c45b408  lw          $a1, -0x4BF8($v0)
    ctx->pc = 0x11f7a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947848)));
    // 0x11f7a4: 0x8c62b40c  lw          $v0, -0x4BF4($v1)
    ctx->pc = 0x11f7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294947852)));
label_11f7a8:
    // 0x11f7a8: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x11f7a8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f7ac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F7ACu;
    {
        const bool branch_taken_0x11f7ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7ACu;
            // 0x11f7b0: 0x41900  sll         $v1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f7ac) {
            ctx->pc = 0x11F7BCu;
            goto label_11f7bc;
        }
    }
    ctx->pc = 0x11F7B4u;
    // 0x11f7b4: 0x3e00008  jr          $ra
    ctx->pc = 0x11F7B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F7B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7B4u;
            // 0x11f7b8: 0x2402ff97  addiu       $v0, $zero, -0x69 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967191));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F7BCu;
label_11f7bc:
    // 0x11f7bc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11f7bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f7c0: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x11f7c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x11f7c4: 0x3e00008  jr          $ra
    ctx->pc = 0x11F7C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F7C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7C4u;
            // 0x11f7c8: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F318u: goto label_11f318;
            case 0x11F320u: goto label_11f320;
            case 0x11F334u: goto label_11f334;
            case 0x11F34Cu: goto label_11f34c;
            case 0x11F358u: goto label_11f358;
            case 0x11F360u: goto label_11f360;
            case 0x11F38Cu: goto label_11f38c;
            case 0x11F394u: goto label_11f394;
            case 0x11F3B4u: goto label_11f3b4;
            case 0x11F3BCu: goto label_11f3bc;
            case 0x11F3CCu: goto label_11f3cc;
            case 0x11F3D0u: goto label_11f3d0;
            case 0x11F3DCu: goto label_11f3dc;
            case 0x11F444u: goto label_11f444;
            case 0x11F45Cu: goto label_11f45c;
            case 0x11F470u: goto label_11f470;
            case 0x11F478u: goto label_11f478;
            case 0x11F49Cu: goto label_11f49c;
            case 0x11F4BCu: goto label_11f4bc;
            case 0x11F4C4u: goto label_11f4c4;
            case 0x11F4D4u: goto label_11f4d4;
            case 0x11F4D8u: goto label_11f4d8;
            case 0x11F51Cu: goto label_11f51c;
            case 0x11F538u: goto label_11f538;
            case 0x11F548u: goto label_11f548;
            case 0x11F554u: goto label_11f554;
            case 0x11F560u: goto label_11f560;
            case 0x11F584u: goto label_11f584;
            case 0x11F588u: goto label_11f588;
            case 0x11F5CCu: goto label_11f5cc;
            case 0x11F5D8u: goto label_11f5d8;
            case 0x11F5E4u: goto label_11f5e4;
            case 0x11F608u: goto label_11f608;
            case 0x11F664u: goto label_11f664;
            case 0x11F68Cu: goto label_11f68c;
            case 0x11F69Cu: goto label_11f69c;
            case 0x11F6A0u: goto label_11f6a0;
            case 0x11F704u: goto label_11f704;
            case 0x11F714u: goto label_11f714;
            case 0x11F72Cu: goto label_11f72c;
            case 0x11F734u: goto label_11f734;
            case 0x11F758u: goto label_11f758;
            case 0x11F75Cu: goto label_11f75c;
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F7CCu;
    // 0x11f7cc: 0x0  nop
    ctx->pc = 0x11f7ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

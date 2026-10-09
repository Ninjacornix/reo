#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B330
// Address: 0x13b330 - 0x13b528
void sub_0013B330_0x13b330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B330_0x13b330");
#endif

    switch (ctx->pc) {
        case 0x13b360u: goto label_13b360;
        case 0x13b380u: goto label_13b380;
        case 0x13b388u: goto label_13b388;
        case 0x13b394u: goto label_13b394;
        case 0x13b3a0u: goto label_13b3a0;
        case 0x13b3ccu: goto label_13b3cc;
        case 0x13b40cu: goto label_13b40c;
        case 0x13b444u: goto label_13b444;
        case 0x13b460u: goto label_13b460;
        case 0x13b470u: goto label_13b470;
        case 0x13b478u: goto label_13b478;
        case 0x13b480u: goto label_13b480;
        case 0x13b490u: goto label_13b490;
        case 0x13b49cu: goto label_13b49c;
        case 0x13b4b0u: goto label_13b4b0;
        case 0x13b4b8u: goto label_13b4b8;
        case 0x13b4c0u: goto label_13b4c0;
        case 0x13b4c8u: goto label_13b4c8;
        case 0x13b4d8u: goto label_13b4d8;
        case 0x13b4e0u: goto label_13b4e0;
        case 0x13b4ecu: goto label_13b4ec;
        case 0x13b508u: goto label_13b508;
        default: break;
    }

    ctx->pc = 0x13b330u;

    // 0x13b330: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13b330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13b334: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13b334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13b338: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13b338u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b33c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13b33cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13b340: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B340u;
    {
        const bool branch_taken_0x13b340 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B340u;
            // 0x13b344: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b340) {
            ctx->pc = 0x13B358u;
            goto label_13b358;
        }
    }
    ctx->pc = 0x13B348u;
    // 0x13b348: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b348u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b34c: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x13B34Cu;
    {
        const bool branch_taken_0x13b34c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B34Cu;
            // 0x13b350: 0x24a5ce58  addiu       $a1, $a1, -0x31A8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954584));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b34c) {
            ctx->pc = 0x13B500u;
            goto label_13b500;
        }
    }
    ctx->pc = 0x13B354u;
    // 0x13b354: 0x0  nop
    ctx->pc = 0x13b354u;
    // NOP
label_13b358:
    // 0x13b358: 0xc04f1fa  jal         func_13C7E8
    ctx->pc = 0x13B358u;
    SET_GPR_U32(ctx, 31, 0x13B360u);
    ctx->pc = 0x13B35Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B358u;
            // 0x13b35c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C7E8u;
    if (runtime->hasFunction(0x13C7E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B360u; }
        if (ctx->pc != 0x13B360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7E8_0x13c7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B360u; }
        if (ctx->pc != 0x13B360u) { return; }
    }
    ctx->pc = 0x13B360u;
label_13b360:
    // 0x13b360: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13b360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13b364: 0x1440006a  bnez        $v0, . + 4 + (0x6A << 2)
    ctx->pc = 0x13B364u;
    {
        const bool branch_taken_0x13b364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B364u;
            // 0x13b368: 0x8fb10004  lw          $s1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b364) {
            ctx->pc = 0x13B510u;
            goto label_13b510;
        }
    }
    ctx->pc = 0x13B36Cu;
    // 0x13b36c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b36cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b370: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13b370u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b374: 0x2451dd60  addiu       $s1, $v0, -0x22A0
    ctx->pc = 0x13b374u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958432));
    // 0x13b378: 0xc04efa0  jal         func_13BE80
    ctx->pc = 0x13B378u;
    SET_GPR_U32(ctx, 31, 0x13B380u);
    ctx->pc = 0x13B37Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B378u;
            // 0x13b37c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13BE80u;
    if (runtime->hasFunction(0x13BE80u)) {
        auto targetFn = runtime->lookupFunction(0x13BE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B380u; }
        if (ctx->pc != 0x13B380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE80_0x13be80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B380u; }
        if (ctx->pc != 0x13B380u) { return; }
    }
    ctx->pc = 0x13B380u;
label_13b380:
    // 0x13b380: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B380u;
    SET_GPR_U32(ctx, 31, 0x13B388u);
    ctx->pc = 0x13B384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B380u;
            // 0x13b384: 0x24044400  addiu       $a0, $zero, 0x4400 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B388u; }
        if (ctx->pc != 0x13B388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B388u; }
        if (ctx->pc != 0x13B388u) { return; }
    }
    ctx->pc = 0x13B388u;
label_13b388:
    // 0x13b388: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b38c: 0xc04e146  jal         func_138518
    ctx->pc = 0x13B38Cu;
    SET_GPR_U32(ctx, 31, 0x13B394u);
    ctx->pc = 0x13B390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B38Cu;
            // 0x13b390: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138518u;
    if (runtime->hasFunction(0x138518u)) {
        auto targetFn = runtime->lookupFunction(0x138518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B394u; }
        if (ctx->pc != 0x13B394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138518_0x138518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B394u; }
        if (ctx->pc != 0x13B394u) { return; }
    }
    ctx->pc = 0x13B394u;
label_13b394:
    // 0x13b394: 0x24044401  addiu       $a0, $zero, 0x4401
    ctx->pc = 0x13b394u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17409));
    // 0x13b398: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B398u;
    SET_GPR_U32(ctx, 31, 0x13B3A0u);
    ctx->pc = 0x13B39Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B398u;
            // 0x13b39c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B3A0u; }
        if (ctx->pc != 0x13B3A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B3A0u; }
        if (ctx->pc != 0x13B3A0u) { return; }
    }
    ctx->pc = 0x13B3A0u;
label_13b3a0:
    // 0x13b3a0: 0x601000f  bgez        $s0, . + 4 + (0xF << 2)
    ctx->pc = 0x13B3A0u;
    {
        const bool branch_taken_0x13b3a0 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x13B3A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B3A0u;
            // 0x13b3a4: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b3a0) {
            ctx->pc = 0x13B3E0u;
            goto label_13b3e0;
        }
    }
    ctx->pc = 0x13B3A8u;
    // 0x13b3a8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b3a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b3ac: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x13b3acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13b3b0: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13b3b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13b3b4: 0x10640006  beq         $v1, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13B3B4u;
    {
        const bool branch_taken_0x13b3b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x13B3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B3B4u;
            // 0x13b3b8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b3b4) {
            ctx->pc = 0x13B3D0u;
            goto label_13b3d0;
        }
    }
    ctx->pc = 0x13B3BCu;
    // 0x13b3bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13b3bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13b3c0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x13b3c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b3c4: 0xc045a12  jal         func_116848
    ctx->pc = 0x13B3C4u;
    SET_GPR_U32(ctx, 31, 0x13B3CCu);
    ctx->pc = 0x13B3C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B3C4u;
            // 0x13b3c8: 0x2484ce88  addiu       $a0, $a0, -0x3178 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B3CCu; }
        if (ctx->pc != 0x13B3CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B3CCu; }
        if (ctx->pc != 0x13B3CCu) { return; }
    }
    ctx->pc = 0x13B3CCu;
label_13b3cc:
    // 0x13b3cc: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b3ccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
label_13b3d0:
    // 0x13b3d0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b3d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b3d4: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x13B3D4u;
    {
        const bool branch_taken_0x13b3d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B3D4u;
            // 0x13b3d8: 0x24a5cea8  addiu       $a1, $a1, -0x3158 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954664));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b3d4) {
            ctx->pc = 0x13B500u;
            goto label_13b500;
        }
    }
    ctx->pc = 0x13B3DCu;
    // 0x13b3dc: 0x0  nop
    ctx->pc = 0x13b3dcu;
    // NOP
label_13b3e0:
    // 0x13b3e0: 0x34420004  ori         $v0, $v0, 0x4
    ctx->pc = 0x13b3e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4);
    // 0x13b3e4: 0x1602000e  bne         $s0, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x13B3E4u;
    {
        const bool branch_taken_0x13b3e4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x13B3E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B3E4u;
            // 0x13b3e8: 0x24020013  addiu       $v0, $zero, 0x13 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b3e4) {
            ctx->pc = 0x13B420u;
            goto label_13b420;
        }
    }
    ctx->pc = 0x13B3ECu;
    // 0x13b3ec: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b3ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b3f0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x13b3f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13b3f4: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13b3f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13b3f8: 0x10640005  beq         $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B3F8u;
    {
        const bool branch_taken_0x13b3f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x13B3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B3F8u;
            // 0x13b3fc: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b3f8) {
            ctx->pc = 0x13B410u;
            goto label_13b410;
        }
    }
    ctx->pc = 0x13B400u;
    // 0x13b400: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13b400u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13b404: 0xc045a12  jal         func_116848
    ctx->pc = 0x13B404u;
    SET_GPR_U32(ctx, 31, 0x13B40Cu);
    ctx->pc = 0x13B408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B404u;
            // 0x13b408: 0x2484ced0  addiu       $a0, $a0, -0x3130 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B40Cu; }
        if (ctx->pc != 0x13B40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B40Cu; }
        if (ctx->pc != 0x13B40Cu) { return; }
    }
    ctx->pc = 0x13B40Cu;
label_13b40c:
    // 0x13b40c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b40cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
label_13b410:
    // 0x13b410: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b410u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b414: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x13B414u;
    {
        const bool branch_taken_0x13b414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B414u;
            // 0x13b418: 0x24a5cf08  addiu       $a1, $a1, -0x30F8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954760));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b414) {
            ctx->pc = 0x13B500u;
            goto label_13b500;
        }
    }
    ctx->pc = 0x13B41Cu;
    // 0x13b41c: 0x0  nop
    ctx->pc = 0x13b41cu;
    // NOP
label_13b420:
    // 0x13b420: 0x1602000d  bne         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13B420u;
    {
        const bool branch_taken_0x13b420 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x13B424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B420u;
            // 0x13b424: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b420) {
            ctx->pc = 0x13B458u;
            goto label_13b458;
        }
    }
    ctx->pc = 0x13B428u;
    // 0x13b428: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x13b428u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13b42c: 0x8c43dea4  lw          $v1, -0x215C($v0)
    ctx->pc = 0x13b42cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958756)));
    // 0x13b430: 0x10640005  beq         $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B430u;
    {
        const bool branch_taken_0x13b430 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x13B434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B430u;
            // 0x13b434: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b430) {
            ctx->pc = 0x13B448u;
            goto label_13b448;
        }
    }
    ctx->pc = 0x13B438u;
    // 0x13b438: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13b438u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13b43c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13B43Cu;
    SET_GPR_U32(ctx, 31, 0x13B444u);
    ctx->pc = 0x13B440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B43Cu;
            // 0x13b440: 0x2484cf30  addiu       $a0, $a0, -0x30D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954800));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B444u; }
        if (ctx->pc != 0x13B444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B444u; }
        if (ctx->pc != 0x13B444u) { return; }
    }
    ctx->pc = 0x13B444u;
label_13b444:
    // 0x13b444: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b444u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
label_13b448:
    // 0x13b448: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b448u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b44c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x13B44Cu;
    {
        const bool branch_taken_0x13b44c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B44Cu;
            // 0x13b450: 0x24a5cf08  addiu       $a1, $a1, -0x30F8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954760));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b44c) {
            ctx->pc = 0x13B500u;
            goto label_13b500;
        }
    }
    ctx->pc = 0x13B454u;
    // 0x13b454: 0x0  nop
    ctx->pc = 0x13b454u;
    // NOP
label_13b458:
    // 0x13b458: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B458u;
    SET_GPR_U32(ctx, 31, 0x13B460u);
    ctx->pc = 0x13B45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B458u;
            // 0x13b45c: 0x24044600  addiu       $a0, $zero, 0x4600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17920));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B460u; }
        if (ctx->pc != 0x13B460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B460u; }
        if (ctx->pc != 0x13B460u) { return; }
    }
    ctx->pc = 0x13B460u;
label_13b460:
    // 0x13b460: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13b460u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b464: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13b464u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b468: 0xc04e0fa  jal         func_1383E8
    ctx->pc = 0x13B468u;
    SET_GPR_U32(ctx, 31, 0x13B470u);
    ctx->pc = 0x13B46Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B468u;
            // 0x13b46c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1383E8u;
    if (runtime->hasFunction(0x1383E8u)) {
        auto targetFn = runtime->lookupFunction(0x1383E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B470u; }
        if (ctx->pc != 0x13B470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B470u; }
        if (ctx->pc != 0x13B470u) { return; }
    }
    ctx->pc = 0x13B470u;
label_13b470:
    // 0x13b470: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B470u;
    SET_GPR_U32(ctx, 31, 0x13B478u);
    ctx->pc = 0x13B474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B470u;
            // 0x13b474: 0x24044601  addiu       $a0, $zero, 0x4601 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17921));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B478u; }
        if (ctx->pc != 0x13B478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B478u; }
        if (ctx->pc != 0x13B478u) { return; }
    }
    ctx->pc = 0x13B478u;
label_13b478:
    // 0x13b478: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B478u;
    SET_GPR_U32(ctx, 31, 0x13B480u);
    ctx->pc = 0x13B47Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B478u;
            // 0x13b47c: 0x24044600  addiu       $a0, $zero, 0x4600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17920));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B480u; }
        if (ctx->pc != 0x13B480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B480u; }
        if (ctx->pc != 0x13B480u) { return; }
    }
    ctx->pc = 0x13B480u;
label_13b480:
    // 0x13b480: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13b480u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b484: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13b484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b488: 0xc04e0fa  jal         func_1383E8
    ctx->pc = 0x13B488u;
    SET_GPR_U32(ctx, 31, 0x13B490u);
    ctx->pc = 0x13B48Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B488u;
            // 0x13b48c: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1383E8u;
    if (runtime->hasFunction(0x1383E8u)) {
        auto targetFn = runtime->lookupFunction(0x1383E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B490u; }
        if (ctx->pc != 0x13B490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001383E8_0x1383e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B490u; }
        if (ctx->pc != 0x13B490u) { return; }
    }
    ctx->pc = 0x13B490u;
label_13b490:
    // 0x13b490: 0x24044601  addiu       $a0, $zero, 0x4601
    ctx->pc = 0x13b490u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17921));
    // 0x13b494: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B494u;
    SET_GPR_U32(ctx, 31, 0x13B49Cu);
    ctx->pc = 0x13B498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B494u;
            // 0x13b498: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B49Cu; }
        if (ctx->pc != 0x13B49Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B49Cu; }
        if (ctx->pc != 0x13B49Cu) { return; }
    }
    ctx->pc = 0x13B49Cu;
label_13b49c:
    // 0x13b49c: 0x621000c  bgez        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x13B49Cu;
    {
        const bool branch_taken_0x13b49c = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x13B4A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B49Cu;
            // 0x13b4a0: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b49c) {
            ctx->pc = 0x13B4D0u;
            goto label_13b4d0;
        }
    }
    ctx->pc = 0x13B4A4u;
    // 0x13b4a4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b4a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b4a8: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13B4A8u;
    SET_GPR_U32(ctx, 31, 0x13B4B0u);
    ctx->pc = 0x13B4ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4A8u;
            // 0x13b4ac: 0x24a5cf68  addiu       $a1, $a1, -0x3098 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4B0u; }
        if (ctx->pc != 0x13B4B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4B0u; }
        if (ctx->pc != 0x13B4B0u) { return; }
    }
    ctx->pc = 0x13B4B0u;
label_13b4b0:
    // 0x13b4b0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B4B0u;
    SET_GPR_U32(ctx, 31, 0x13B4B8u);
    ctx->pc = 0x13B4B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4B0u;
            // 0x13b4b4: 0x24044500  addiu       $a0, $zero, 0x4500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4B8u; }
        if (ctx->pc != 0x13B4B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4B8u; }
        if (ctx->pc != 0x13B4B8u) { return; }
    }
    ctx->pc = 0x13B4B8u;
label_13b4b8:
    // 0x13b4b8: 0xc04e160  jal         func_138580
    ctx->pc = 0x13B4B8u;
    SET_GPR_U32(ctx, 31, 0x13B4C0u);
    ctx->pc = 0x13B4BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4B8u;
            // 0x13b4bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4C0u; }
        if (ctx->pc != 0x13B4C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4C0u; }
        if (ctx->pc != 0x13B4C0u) { return; }
    }
    ctx->pc = 0x13B4C0u;
label_13b4c0:
    // 0x13b4c0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B4C0u;
    SET_GPR_U32(ctx, 31, 0x13B4C8u);
    ctx->pc = 0x13B4C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4C0u;
            // 0x13b4c4: 0x24044501  addiu       $a0, $zero, 0x4501 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17665));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4C8u; }
        if (ctx->pc != 0x13B4C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4C8u; }
        if (ctx->pc != 0x13B4C8u) { return; }
    }
    ctx->pc = 0x13B4C8u;
label_13b4c8:
    // 0x13b4c8: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x13B4C8u;
    {
        const bool branch_taken_0x13b4c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B4CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4C8u;
            // 0x13b4cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b4c8) {
            ctx->pc = 0x13B514u;
            goto label_13b514;
        }
    }
    ctx->pc = 0x13B4D0u;
label_13b4d0:
    // 0x13b4d0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B4D0u;
    SET_GPR_U32(ctx, 31, 0x13B4D8u);
    ctx->pc = 0x13B4D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4D0u;
            // 0x13b4d4: 0x24045000  addiu       $a0, $zero, 0x5000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4D8u; }
        if (ctx->pc != 0x13B4D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4D8u; }
        if (ctx->pc != 0x13B4D8u) { return; }
    }
    ctx->pc = 0x13B4D8u;
label_13b4d8:
    // 0x13b4d8: 0xc04e160  jal         func_138580
    ctx->pc = 0x13B4D8u;
    SET_GPR_U32(ctx, 31, 0x13B4E0u);
    ctx->pc = 0x13B4DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4D8u;
            // 0x13b4dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4E0u; }
        if (ctx->pc != 0x13B4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4E0u; }
        if (ctx->pc != 0x13B4E0u) { return; }
    }
    ctx->pc = 0x13B4E0u;
label_13b4e0:
    // 0x13b4e0: 0x24045001  addiu       $a0, $zero, 0x5001
    ctx->pc = 0x13b4e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20481));
    // 0x13b4e4: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B4E4u;
    SET_GPR_U32(ctx, 31, 0x13B4ECu);
    ctx->pc = 0x13B4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4E4u;
            // 0x13b4e8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4ECu; }
        if (ctx->pc != 0x13B4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B4ECu; }
        if (ctx->pc != 0x13B4ECu) { return; }
    }
    ctx->pc = 0x13B4ECu;
label_13b4ec:
    // 0x13b4ec: 0x6030009  bgezl       $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13B4ECu;
    {
        const bool branch_taken_0x13b4ec = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x13b4ec) {
            ctx->pc = 0x13B4F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B4ECu;
            // 0x13b4f0: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B514u;
            goto label_13b514;
        }
    }
    ctx->pc = 0x13B4F4u;
    // 0x13b4f4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b4f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b4f8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13b4f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b4fc: 0x24a5cf98  addiu       $a1, $a1, -0x3068
    ctx->pc = 0x13b4fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954904));
label_13b500:
    // 0x13b500: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13B500u;
    SET_GPR_U32(ctx, 31, 0x13B508u);
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B508u; }
        if (ctx->pc != 0x13B508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B508u; }
        if (ctx->pc != 0x13B508u) { return; }
    }
    ctx->pc = 0x13B508u;
label_13b508:
    // 0x13b508: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13B508u;
    {
        const bool branch_taken_0x13b508 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B508u;
            // 0x13b50c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b508) {
            ctx->pc = 0x13B514u;
            goto label_13b514;
        }
    }
    ctx->pc = 0x13B510u;
label_13b510:
    // 0x13b510: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x13b510u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_13b514:
    // 0x13b514: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13b514u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b518: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13b518u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13b51c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13b51cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13b520: 0x3e00008  jr          $ra
    ctx->pc = 0x13B520u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B520u;
            // 0x13b524: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B358u: goto label_13b358;
            case 0x13B360u: goto label_13b360;
            case 0x13B380u: goto label_13b380;
            case 0x13B388u: goto label_13b388;
            case 0x13B394u: goto label_13b394;
            case 0x13B3A0u: goto label_13b3a0;
            case 0x13B3CCu: goto label_13b3cc;
            case 0x13B3D0u: goto label_13b3d0;
            case 0x13B3E0u: goto label_13b3e0;
            case 0x13B40Cu: goto label_13b40c;
            case 0x13B410u: goto label_13b410;
            case 0x13B420u: goto label_13b420;
            case 0x13B444u: goto label_13b444;
            case 0x13B448u: goto label_13b448;
            case 0x13B458u: goto label_13b458;
            case 0x13B460u: goto label_13b460;
            case 0x13B470u: goto label_13b470;
            case 0x13B478u: goto label_13b478;
            case 0x13B480u: goto label_13b480;
            case 0x13B490u: goto label_13b490;
            case 0x13B49Cu: goto label_13b49c;
            case 0x13B4B0u: goto label_13b4b0;
            case 0x13B4B8u: goto label_13b4b8;
            case 0x13B4C0u: goto label_13b4c0;
            case 0x13B4C8u: goto label_13b4c8;
            case 0x13B4D0u: goto label_13b4d0;
            case 0x13B4D8u: goto label_13b4d8;
            case 0x13B4E0u: goto label_13b4e0;
            case 0x13B4ECu: goto label_13b4ec;
            case 0x13B500u: goto label_13b500;
            case 0x13B508u: goto label_13b508;
            case 0x13B510u: goto label_13b510;
            case 0x13B514u: goto label_13b514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B528u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

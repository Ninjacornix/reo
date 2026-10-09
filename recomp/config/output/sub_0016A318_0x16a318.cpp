#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A318
// Address: 0x16a318 - 0x16a4b8
void sub_0016A318_0x16a318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A318_0x16a318");
#endif

    switch (ctx->pc) {
        case 0x16a360u: goto label_16a360;
        case 0x16a37cu: goto label_16a37c;
        case 0x16a390u: goto label_16a390;
        case 0x16a3b8u: goto label_16a3b8;
        case 0x16a3d0u: goto label_16a3d0;
        case 0x16a3e0u: goto label_16a3e0;
        case 0x16a3f8u: goto label_16a3f8;
        case 0x16a420u: goto label_16a420;
        case 0x16a444u: goto label_16a444;
        case 0x16a468u: goto label_16a468;
        default: break;
    }

    ctx->pc = 0x16a318u;

    // 0x16a318: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x16a318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x16a31c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x16a31cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x16a320: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x16a320u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a324: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16a324u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16a328: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16a328u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a32c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x16a32cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x16a330: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16a330u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a334: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x16a334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x16a338: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x16a338u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a33c: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x16a33cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x16a340: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x16a340u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a344: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16a344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x16a348: 0x100382d  daddu       $a3, $t0, $zero
    ctx->pc = 0x16a348u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a34c: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x16a34cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x16a350: 0xae800000  sw          $zero, 0x0($s4)
    ctx->pc = 0x16a350u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x16a354: 0x8e021aec  lw          $v0, 0x1AEC($s0)
    ctx->pc = 0x16a354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6892)));
    // 0x16a358: 0xc05ac32  jal         func_16B0C8
    ctx->pc = 0x16A358u;
    SET_GPR_U32(ctx, 31, 0x16A360u);
    ctx->pc = 0x16A35Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A358u;
            // 0x16a35c: 0x8c510000  lw          $s1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B0C8u;
    if (runtime->hasFunction(0x16B0C8u)) {
        auto targetFn = runtime->lookupFunction(0x16B0C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A360u; }
        if (ctx->pc != 0x16A360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B0C8_0x16b0c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A360u; }
        if (ctx->pc != 0x16A360u) { return; }
    }
    ctx->pc = 0x16A360u;
label_16a360:
    // 0x16a360: 0x1040004b  beqz        $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x16A360u;
    {
        const bool branch_taken_0x16a360 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A360u;
            // 0x16a364: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a360) {
            ctx->pc = 0x16A490u;
            goto label_16a490;
        }
    }
    ctx->pc = 0x16A368u;
    // 0x16a368: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x16a368u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a36c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x16a36cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a370: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x16a370u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a374: 0xc055900  jal         func_156400
    ctx->pc = 0x16A374u;
    SET_GPR_U32(ctx, 31, 0x16A37Cu);
    ctx->pc = 0x16A378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A374u;
            // 0x16a378: 0x27a80004  addiu       $t0, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x156400u;
    if (runtime->hasFunction(0x156400u)) {
        auto targetFn = runtime->lookupFunction(0x156400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A37Cu; }
        if (ctx->pc != 0x16A37Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00156400_0x156400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A37Cu; }
        if (ctx->pc != 0x16A37Cu) { return; }
    }
    ctx->pc = 0x16A37Cu;
label_16a37c:
    // 0x16a37c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16A37Cu;
    {
        const bool branch_taken_0x16a37c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A37Cu;
            // 0x16a380: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a37c) {
            ctx->pc = 0x16A394u;
            goto label_16a394;
        }
    }
    ctx->pc = 0x16A384u;
    // 0x16a384: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16a384u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16a388: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16A388u;
    SET_GPR_U32(ctx, 31, 0x16A390u);
    ctx->pc = 0x16A38Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A388u;
            // 0x16a38c: 0x34a50d03  ori         $a1, $a1, 0xD03 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3331);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A390u; }
        if (ctx->pc != 0x16A390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A390u; }
        if (ctx->pc != 0x16A390u) { return; }
    }
    ctx->pc = 0x16A390u;
label_16a390:
    // 0x16a390: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x16a390u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_16a394:
    // 0x16a394: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16a394u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16a398: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x16a398u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x16a39c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x16a39cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x16a3a0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A3A0u;
    {
        const bool branch_taken_0x16a3a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A3A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3A0u;
            // 0x16a3a4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a3a0) {
            ctx->pc = 0x16A3BCu;
            goto label_16a3bc;
        }
    }
    ctx->pc = 0x16A3A8u;
    // 0x16a3a8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16a3a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a3ac: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x16a3acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a3b0: 0xc05adce  jal         func_16B738
    ctx->pc = 0x16A3B0u;
    SET_GPR_U32(ctx, 31, 0x16A3B8u);
    ctx->pc = 0x16A3B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3B0u;
            // 0x16a3b4: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B738u;
    if (runtime->hasFunction(0x16B738u)) {
        auto targetFn = runtime->lookupFunction(0x16B738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3B8u; }
        if (ctx->pc != 0x16A3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B738_0x16b738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3B8u; }
        if (ctx->pc != 0x16A3B8u) { return; }
    }
    ctx->pc = 0x16A3B8u;
label_16a3b8:
    // 0x16a3b8: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16a3b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_16a3bc:
    // 0x16a3bc: 0x3c020008  lui         $v0, 0x8
    ctx->pc = 0x16a3bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
    // 0x16a3c0: 0x14620010  bne         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x16A3C0u;
    {
        const bool branch_taken_0x16a3c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x16A3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3C0u;
            // 0x16a3c4: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a3c0) {
            ctx->pc = 0x16A404u;
            goto label_16a404;
        }
    }
    ctx->pc = 0x16A3C8u;
    // 0x16a3c8: 0xc059f74  jal         func_167DD0
    ctx->pc = 0x16A3C8u;
    SET_GPR_U32(ctx, 31, 0x16A3D0u);
    ctx->pc = 0x16A3CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3C8u;
            // 0x16a3cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167DD0u;
    if (runtime->hasFunction(0x167DD0u)) {
        auto targetFn = runtime->lookupFunction(0x167DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3D0u; }
        if (ctx->pc != 0x16A3D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167DD0_0x167dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3D0u; }
        if (ctx->pc != 0x16A3D0u) { return; }
    }
    ctx->pc = 0x16A3D0u;
label_16a3d0:
    // 0x16a3d0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16A3D0u;
    {
        const bool branch_taken_0x16a3d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A3D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3D0u;
            // 0x16a3d4: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a3d0) {
            ctx->pc = 0x16A3E8u;
            goto label_16a3e8;
        }
    }
    ctx->pc = 0x16A3D8u;
    // 0x16a3d8: 0xc05ac2c  jal         func_16B0B0
    ctx->pc = 0x16A3D8u;
    SET_GPR_U32(ctx, 31, 0x16A3E0u);
    ctx->pc = 0x16A3DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3D8u;
            // 0x16a3dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B0B0u;
    if (runtime->hasFunction(0x16B0B0u)) {
        auto targetFn = runtime->lookupFunction(0x16B0B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3E0u; }
        if (ctx->pc != 0x16A3E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B0B0_0x16b0b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3E0u; }
        if (ctx->pc != 0x16A3E0u) { return; }
    }
    ctx->pc = 0x16A3E0u;
label_16a3e0:
    // 0x16a3e0: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x16A3E0u;
    {
        const bool branch_taken_0x16a3e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3E0u;
            // 0x16a3e4: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a3e0) {
            ctx->pc = 0x16A488u;
            goto label_16a488;
        }
    }
    ctx->pc = 0x16A3E8u;
label_16a3e8:
    // 0x16a3e8: 0x14710006  bne         $v1, $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A3E8u;
    {
        const bool branch_taken_0x16a3e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 17));
        if (branch_taken_0x16a3e8) {
            ctx->pc = 0x16A404u;
            goto label_16a404;
        }
    }
    ctx->pc = 0x16A3F0u;
    // 0x16a3f0: 0xc059f7c  jal         func_167DF0
    ctx->pc = 0x16A3F0u;
    SET_GPR_U32(ctx, 31, 0x16A3F8u);
    ctx->pc = 0x16A3F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3F0u;
            // 0x16a3f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167DF0u;
    if (runtime->hasFunction(0x167DF0u)) {
        auto targetFn = runtime->lookupFunction(0x167DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3F8u; }
        if (ctx->pc != 0x16A3F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167DF0_0x167df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A3F8u; }
        if (ctx->pc != 0x16A3F8u) { return; }
    }
    ctx->pc = 0x16A3F8u;
label_16a3f8:
    // 0x16a3f8: 0x14400023  bnez        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x16A3F8u;
    {
        const bool branch_taken_0x16a3f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A3F8u;
            // 0x16a3fc: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a3f8) {
            ctx->pc = 0x16A488u;
            goto label_16a488;
        }
    }
    ctx->pc = 0x16A400u;
    // 0x16a400: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16a400u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_16a404:
    // 0x16a404: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x16A404u;
    {
        const bool branch_taken_0x16a404 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A404u;
            // 0x16a408: 0x3c020004  lui         $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a404) {
            ctx->pc = 0x16A428u;
            goto label_16a428;
        }
    }
    ctx->pc = 0x16A40Cu;
    // 0x16a40c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16a40cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a410: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x16a410u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a414: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x16a414u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a418: 0xc05a92e  jal         func_16A4B8
    ctx->pc = 0x16A418u;
    SET_GPR_U32(ctx, 31, 0x16A420u);
    ctx->pc = 0x16A41Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A418u;
            // 0x16a41c: 0x27a70008  addiu       $a3, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A4B8u;
    if (runtime->hasFunction(0x16A4B8u)) {
        auto targetFn = runtime->lookupFunction(0x16A4B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A420u; }
        if (ctx->pc != 0x16A420u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A4B8_0x16a4b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A420u; }
        if (ctx->pc != 0x16A420u) { return; }
    }
    ctx->pc = 0x16A420u;
label_16a420:
    // 0x16a420: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x16A420u;
    {
        const bool branch_taken_0x16a420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A420u;
            // 0x16a424: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a420) {
            ctx->pc = 0x16A488u;
            goto label_16a488;
        }
    }
    ctx->pc = 0x16A428u;
label_16a428:
    // 0x16a428: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x16a428u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x16a42c: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x16A42Cu;
    {
        const bool branch_taken_0x16a42c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a42c) {
            ctx->pc = 0x16A430u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A42Cu;
            // 0x16a430: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A450u;
            goto label_16a450;
        }
    }
    ctx->pc = 0x16A434u;
    // 0x16a434: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16a434u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16a438: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16a438u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a43c: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16A43Cu;
    SET_GPR_U32(ctx, 31, 0x16A444u);
    ctx->pc = 0x16A440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A43Cu;
            // 0x16a440: 0x34a50d05  ori         $a1, $a1, 0xD05 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3333);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A444u; }
        if (ctx->pc != 0x16A444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A444u; }
        if (ctx->pc != 0x16A444u) { return; }
    }
    ctx->pc = 0x16A444u;
label_16a444:
    // 0x16a444: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x16A444u;
    {
        const bool branch_taken_0x16a444 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A444u;
            // 0x16a448: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a444) {
            ctx->pc = 0x16A48Cu;
            goto label_16a48c;
        }
    }
    ctx->pc = 0x16A44Cu;
    // 0x16a44c: 0x0  nop
    ctx->pc = 0x16a44cu;
    // NOP
label_16a450:
    // 0x16a450: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16a450u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a454: 0x27a7000c  addiu       $a3, $sp, 0xC
    ctx->pc = 0x16a454u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x16a458: 0x27a80010  addiu       $t0, $sp, 0x10
    ctx->pc = 0x16a458u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x16a45c: 0x2453023  subu        $a2, $s2, $a1
    ctx->pc = 0x16a45cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x16a460: 0xc05a998  jal         func_16A660
    ctx->pc = 0x16A460u;
    SET_GPR_U32(ctx, 31, 0x16A468u);
    ctx->pc = 0x16A464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A460u;
            // 0x16a464: 0x2652821  addu        $a1, $s3, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A660u;
    if (runtime->hasFunction(0x16A660u)) {
        auto targetFn = runtime->lookupFunction(0x16A660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A468u; }
        if (ctx->pc != 0x16A468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A660_0x16a660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A468u; }
        if (ctx->pc != 0x16A468u) { return; }
    }
    ctx->pc = 0x16A468u;
label_16a468:
    // 0x16a468: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16a468u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16a46c: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x16a46cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a470: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x16a470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a474: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A474u;
    {
        const bool branch_taken_0x16a474 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16A478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A474u;
            // 0x16a478: 0x2a0102d  daddu       $v0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a474) {
            ctx->pc = 0x16A490u;
            goto label_16a490;
        }
    }
    ctx->pc = 0x16A47Cu;
    // 0x16a47c: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x16a47cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a480: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x16a480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16a484: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16a484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_16a488:
    // 0x16a488: 0xae820000  sw          $v0, 0x0($s4)
    ctx->pc = 0x16a488u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
label_16a48c:
    // 0x16a48c: 0x2a0102d  daddu       $v0, $s5, $zero
    ctx->pc = 0x16a48cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_16a490:
    // 0x16a490: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16a490u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a494: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x16a494u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a498: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x16a498u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a49c: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x16a49cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16a4a0: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x16a4a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16a4a4: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x16a4a4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16a4a8: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x16a4a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x16a4ac: 0x3e00008  jr          $ra
    ctx->pc = 0x16A4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A4ACu;
            // 0x16a4b0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A360u: goto label_16a360;
            case 0x16A37Cu: goto label_16a37c;
            case 0x16A390u: goto label_16a390;
            case 0x16A394u: goto label_16a394;
            case 0x16A3B8u: goto label_16a3b8;
            case 0x16A3BCu: goto label_16a3bc;
            case 0x16A3D0u: goto label_16a3d0;
            case 0x16A3E0u: goto label_16a3e0;
            case 0x16A3E8u: goto label_16a3e8;
            case 0x16A3F8u: goto label_16a3f8;
            case 0x16A404u: goto label_16a404;
            case 0x16A420u: goto label_16a420;
            case 0x16A428u: goto label_16a428;
            case 0x16A444u: goto label_16a444;
            case 0x16A450u: goto label_16a450;
            case 0x16A468u: goto label_16a468;
            case 0x16A488u: goto label_16a488;
            case 0x16A48Cu: goto label_16a48c;
            case 0x16A490u: goto label_16a490;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A4B4u;
    // 0x16a4b4: 0x0  nop
    ctx->pc = 0x16a4b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

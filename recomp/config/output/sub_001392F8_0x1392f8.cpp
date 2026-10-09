#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001392F8
// Address: 0x1392f8 - 0x1393e8
void sub_001392F8_0x1392f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001392F8_0x1392f8");
#endif

    switch (ctx->pc) {
        case 0x139338u: goto label_139338;
        case 0x139344u: goto label_139344;
        case 0x139354u: goto label_139354;
        case 0x139358u: goto label_139358;
        case 0x139390u: goto label_139390;
        default: break;
    }

    ctx->pc = 0x1392f8u;

    // 0x1392f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1392f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1392fc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1392fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x139300: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x139300u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x139304: 0x8e62c42c  lw          $v0, -0x3BD4($s3)
    ctx->pc = 0x139304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4294951980)));
    // 0x139308: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x139308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13930c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13930cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x139310: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x139310u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x139314: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x139314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x139318: 0x14400027  bnez        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x139318u;
    {
        const bool branch_taken_0x139318 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13931Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139318u;
            // 0x13931c: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139318) {
            ctx->pc = 0x1393B8u;
            goto label_1393b8;
        }
    }
    ctx->pc = 0x139320u;
    // 0x139320: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x139320u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x139324: 0x3c120022  lui         $s2, 0x22
    ctx->pc = 0x139324u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)34 << 16));
    // 0x139328: 0x3c140024  lui         $s4, 0x24
    ctx->pc = 0x139328u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)36 << 16));
    // 0x13932c: 0x2611c870  addiu       $s1, $s0, -0x3790
    ctx->pc = 0x13932cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4294953072));
    // 0x139330: 0x8e45c414  lw          $a1, -0x3BEC($s2)
    ctx->pc = 0x139330u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294951956)));
    // 0x139334: 0x0  nop
    ctx->pc = 0x139334u;
    // NOP
label_139338:
    // 0x139338: 0x2604c870  addiu       $a0, $s0, -0x3790
    ctx->pc = 0x139338u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4294953072));
    // 0x13933c: 0xc045e06  jal         func_117818
    ctx->pc = 0x13933Cu;
    SET_GPR_U32(ctx, 31, 0x139344u);
    ctx->pc = 0x139340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13933Cu;
            // 0x139340: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139344u; }
        if (ctx->pc != 0x139344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139344u; }
        if (ctx->pc != 0x139344u) { return; }
    }
    ctx->pc = 0x139344u;
label_139344:
    // 0x139344: 0x443000c  bgezl       $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x139344u;
    {
        const bool branch_taken_0x139344 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x139344) {
            ctx->pc = 0x139348u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139344u;
            // 0x139348: 0x8e220024  lw          $v0, 0x24($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139378u;
            goto label_139378;
        }
    }
    ctx->pc = 0x13934Cu;
    // 0x13934c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13934Cu;
    SET_GPR_U32(ctx, 31, 0x139354u);
    ctx->pc = 0x139350u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13934Cu;
            // 0x139350: 0x2684ca00  addiu       $a0, $s4, -0x3600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294953472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139354u; }
        if (ctx->pc != 0x139354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139354u; }
        if (ctx->pc != 0x139354u) { return; }
    }
    ctx->pc = 0x139354u;
label_139354:
    // 0x139354: 0x0  nop
    ctx->pc = 0x139354u;
    // NOP
label_139358:
    // 0x139358: 0x0  nop
    ctx->pc = 0x139358u;
    // NOP
    // 0x13935c: 0x0  nop
    ctx->pc = 0x13935cu;
    // NOP
    // 0x139360: 0x0  nop
    ctx->pc = 0x139360u;
    // NOP
    // 0x139364: 0x0  nop
    ctx->pc = 0x139364u;
    // NOP
    // 0x139368: 0x0  nop
    ctx->pc = 0x139368u;
    // NOP
    // 0x13936c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13936Cu;
    {
        const bool branch_taken_0x13936c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13936c) {
            ctx->pc = 0x139358u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139358;
        }
    }
    ctx->pc = 0x139374u;
    // 0x139374: 0x0  nop
    ctx->pc = 0x139374u;
    // NOP
label_139378:
    // 0x139378: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x139378u;
    {
        const bool branch_taken_0x139378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13937Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139378u;
            // 0x13937c: 0x2663c42c  addiu       $v1, $s3, -0x3BD4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4294951980));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139378) {
            ctx->pc = 0x1393BCu;
            goto label_1393bc;
        }
    }
    ctx->pc = 0x139380u;
    // 0x139380: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x139380u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x139384: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x139384u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x139388: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x139388u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x13938c: 0x0  nop
    ctx->pc = 0x13938cu;
    // NOP
label_139390:
    // 0x139390: 0x0  nop
    ctx->pc = 0x139390u;
    // NOP
    // 0x139394: 0x0  nop
    ctx->pc = 0x139394u;
    // NOP
    // 0x139398: 0x0  nop
    ctx->pc = 0x139398u;
    // NOP
    // 0x13939c: 0x0  nop
    ctx->pc = 0x13939cu;
    // NOP
    // 0x1393a0: 0x0  nop
    ctx->pc = 0x1393a0u;
    // NOP
    // 0x1393a4: 0x5443fffa  bnel        $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1393A4u;
    {
        const bool branch_taken_0x1393a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1393a4) {
            ctx->pc = 0x1393A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1393A4u;
            // 0x1393a8: 0x2442fffc  addiu       $v0, $v0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139390u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139390;
        }
    }
    ctx->pc = 0x1393ACu;
    // 0x1393ac: 0x1000ffe2  b           . + 4 + (-0x1E << 2)
    ctx->pc = 0x1393ACu;
    {
        const bool branch_taken_0x1393ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1393B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1393ACu;
            // 0x1393b0: 0x8e45c414  lw          $a1, -0x3BEC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294951956)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1393ac) {
            ctx->pc = 0x139338u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139338;
        }
    }
    ctx->pc = 0x1393B4u;
    // 0x1393b4: 0x0  nop
    ctx->pc = 0x1393b4u;
    // NOP
label_1393b8:
    // 0x1393b8: 0x2663c42c  addiu       $v1, $s3, -0x3BD4
    ctx->pc = 0x1393b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4294951980));
label_1393bc:
    // 0x1393bc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1393bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1393c0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1393c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1393c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1393c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1393c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1393c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1393cc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1393ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1393d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1393d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1393d4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1393d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1393d8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1393d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1393dc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1393dcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1393e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1393E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1393E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1393E0u;
            // 0x1393e4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139338u: goto label_139338;
            case 0x139344u: goto label_139344;
            case 0x139354u: goto label_139354;
            case 0x139358u: goto label_139358;
            case 0x139378u: goto label_139378;
            case 0x139390u: goto label_139390;
            case 0x1393B8u: goto label_1393b8;
            case 0x1393BCu: goto label_1393bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1393E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

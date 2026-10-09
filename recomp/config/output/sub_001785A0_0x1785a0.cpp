#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001785A0
// Address: 0x1785a0 - 0x1787e8
void sub_001785A0_0x1785a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001785A0_0x1785a0");
#endif

    switch (ctx->pc) {
        case 0x1785fcu: goto label_1785fc;
        case 0x178610u: goto label_178610;
        case 0x17861cu: goto label_17861c;
        case 0x178628u: goto label_178628;
        case 0x178638u: goto label_178638;
        case 0x178648u: goto label_178648;
        case 0x178654u: goto label_178654;
        case 0x178660u: goto label_178660;
        case 0x17866cu: goto label_17866c;
        case 0x178760u: goto label_178760;
        case 0x178778u: goto label_178778;
        default: break;
    }

    ctx->pc = 0x1785a0u;

    // 0x1785a0: 0x27bdfe00  addiu       $sp, $sp, -0x200
    ctx->pc = 0x1785a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966784));
    // 0x1785a4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1785a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1785a8: 0xffbe01f0  sd          $fp, 0x1F0($sp)
    ctx->pc = 0x1785a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 496), GPR_U64(ctx, 30));
    // 0x1785ac: 0xffb001b0  sd          $s0, 0x1B0($sp)
    ctx->pc = 0x1785acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 432), GPR_U64(ctx, 16));
    // 0x1785b0: 0x2463f1dc  addiu       $v1, $v1, -0xE24
    ctx->pc = 0x1785b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963676));
    // 0x1785b4: 0xffb101b8  sd          $s1, 0x1B8($sp)
    ctx->pc = 0x1785b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 440), GPR_U64(ctx, 17));
    // 0x1785b8: 0xffb201c0  sd          $s2, 0x1C0($sp)
    ctx->pc = 0x1785b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 448), GPR_U64(ctx, 18));
    // 0x1785bc: 0xffb301c8  sd          $s3, 0x1C8($sp)
    ctx->pc = 0x1785bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 456), GPR_U64(ctx, 19));
    // 0x1785c0: 0xffb401d0  sd          $s4, 0x1D0($sp)
    ctx->pc = 0x1785c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 464), GPR_U64(ctx, 20));
    // 0x1785c4: 0xffb501d8  sd          $s5, 0x1D8($sp)
    ctx->pc = 0x1785c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 472), GPR_U64(ctx, 21));
    // 0x1785c8: 0xffb601e0  sd          $s6, 0x1E0($sp)
    ctx->pc = 0x1785c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 480), GPR_U64(ctx, 22));
    // 0x1785cc: 0xffb701e8  sd          $s7, 0x1E8($sp)
    ctx->pc = 0x1785ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 488), GPR_U64(ctx, 23));
    // 0x1785d0: 0xffbf01f8  sd          $ra, 0x1F8($sp)
    ctx->pc = 0x1785d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 504), GPR_U64(ctx, 31));
    // 0x1785d4: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1785d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1785d8: 0x10400077  beqz        $v0, . + 4 + (0x77 << 2)
    ctx->pc = 0x1785D8u;
    {
        const bool branch_taken_0x1785d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1785DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1785D8u;
            // 0x1785dc: 0x80f02d  daddu       $fp, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1785d8) {
            ctx->pc = 0x1787B8u;
            goto label_1787b8;
        }
    }
    ctx->pc = 0x1785E0u;
    // 0x1785e0: 0xdfd20118  ld          $s2, 0x118($fp)
    ctx->pc = 0x1785e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 30), 280)));
    // 0x1785e4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1785e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1785e8: 0xdfd10120  ld          $s1, 0x120($fp)
    ctx->pc = 0x1785e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 30), 288)));
    // 0x1785ec: 0x24540c78  addiu       $s4, $v0, 0xC78
    ctx->pc = 0x1785ecu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 3192));
    // 0x1785f0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1785f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1785f4: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x1785F4u;
    SET_GPR_U32(ctx, 31, 0x1785FCu);
    ctx->pc = 0x1785F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1785F4u;
            // 0x1785f8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1785FCu; }
        if (ctx->pc != 0x1785FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1785FCu; }
        if (ctx->pc != 0x1785FCu) { return; }
    }
    ctx->pc = 0x1785FCu;
label_1785fc:
    // 0x1785fc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1785fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178600: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x178600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x178604: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x178604u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x178608: 0xc0444ca  jal         func_111328
    ctx->pc = 0x178608u;
    SET_GPR_U32(ctx, 31, 0x178610u);
    ctx->pc = 0x17860Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178608u;
            // 0x17860c: 0xafa201a0  sw          $v0, 0x1A0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 416), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178610u; }
        if (ctx->pc != 0x178610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178610u; }
        if (ctx->pc != 0x178610u) { return; }
    }
    ctx->pc = 0x178610u;
label_178610:
    // 0x178610: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x178610u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178614: 0xc0444ca  jal         func_111328
    ctx->pc = 0x178614u;
    SET_GPR_U32(ctx, 31, 0x17861Cu);
    ctx->pc = 0x178618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178614u;
            // 0x178618: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17861Cu; }
        if (ctx->pc != 0x17861Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17861Cu; }
        if (ctx->pc != 0x17861Cu) { return; }
    }
    ctx->pc = 0x17861Cu;
label_17861c:
    // 0x17861c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17861cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178620: 0xc04480e  jal         func_112038
    ctx->pc = 0x178620u;
    SET_GPR_U32(ctx, 31, 0x178628u);
    ctx->pc = 0x178624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178620u;
            // 0x178624: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178628u; }
        if (ctx->pc != 0x178628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178628u; }
        if (ctx->pc != 0x178628u) { return; }
    }
    ctx->pc = 0x178628u;
label_178628:
    // 0x178628: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x178628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x17862c: 0xdc250cf0  ld          $a1, 0xCF0($at)
    ctx->pc = 0x17862cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 3312)));
    // 0x178630: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x178630u;
    SET_GPR_U32(ctx, 31, 0x178638u);
    ctx->pc = 0x178634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178630u;
            // 0x178634: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178638u; }
        if (ctx->pc != 0x178638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178638u; }
        if (ctx->pc != 0x178638u) { return; }
    }
    ctx->pc = 0x178638u;
label_178638:
    // 0x178638: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x178638u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x17863c: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x17863cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x178640: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x178640u;
    SET_GPR_U32(ctx, 31, 0x178648u);
    ctx->pc = 0x178644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178640u;
            // 0x178644: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178648u; }
        if (ctx->pc != 0x178648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178648u; }
        if (ctx->pc != 0x178648u) { return; }
    }
    ctx->pc = 0x178648u;
label_178648:
    // 0x178648: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x178648u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17864c: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x17864Cu;
    SET_GPR_U32(ctx, 31, 0x178654u);
    ctx->pc = 0x178650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17864Cu;
            // 0x178650: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178654u; }
        if (ctx->pc != 0x178654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178654u; }
        if (ctx->pc != 0x178654u) { return; }
    }
    ctx->pc = 0x178654u;
label_178654:
    // 0x178654: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x178654u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178658: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x178658u;
    SET_GPR_U32(ctx, 31, 0x178660u);
    ctx->pc = 0x17865Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178658u;
            // 0x17865c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178660u; }
        if (ctx->pc != 0x178660u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178660u; }
        if (ctx->pc != 0x178660u) { return; }
    }
    ctx->pc = 0x178660u;
label_178660:
    // 0x178660: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x178660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178664: 0xc0448a6  jal         func_112298
    ctx->pc = 0x178664u;
    SET_GPR_U32(ctx, 31, 0x17866Cu);
    ctx->pc = 0x178668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178664u;
            // 0x178668: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17866Cu; }
        if (ctx->pc != 0x17866Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17866Cu; }
        if (ctx->pc != 0x17866Cu) { return; }
    }
    ctx->pc = 0x17866Cu;
label_17866c:
    // 0x17866c: 0x2628ffff  addiu       $t0, $s1, -0x1
    ctx->pc = 0x17866cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x178670: 0xdfc30128  ld          $v1, 0x128($fp)
    ctx->pc = 0x178670u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 30), 296)));
    // 0x178674: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x178674u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x178678: 0xdfcd0108  ld          $t5, 0x108($fp)
    ctx->pc = 0x178678u;
    SET_GPR_U64(ctx, 13, READ64(ADD32(GPR_U32(ctx, 30), 264)));
    // 0x17867c: 0x3c0b7fff  lui         $t3, 0x7FFF
    ctx->pc = 0x17867cu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32767 << 16));
    // 0x178680: 0x356bffff  ori         $t3, $t3, 0xFFFF
    ctx->pc = 0x178680u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)65535);
    // 0x178684: 0xdfcc0188  ld          $t4, 0x188($fp)
    ctx->pc = 0x178684u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 30), 392)));
    // 0x178688: 0x222400a  movz        $t0, $s1, $v0
    ctx->pc = 0x178688u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 17));
    // 0x17868c: 0x8fd90128  lw          $t9, 0x128($fp)
    ctx->pc = 0x17868cu;
    SET_GPR_S32(ctx, 25, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 296)));
    // 0x178690: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x178690u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178694: 0x8fd801b0  lw          $t8, 0x1B0($fp)
    ctx->pc = 0x178694u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 432)));
    // 0x178698: 0x12483f  dsra32      $t1, $s2, 0
    ctx->pc = 0x178698u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 18) >> (32 + 0));
    // 0x17869c: 0x8fcf01a0  lw          $t7, 0x1A0($fp)
    ctx->pc = 0x17869cu;
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 416)));
    // 0x1786a0: 0x1a3682f  dsubu       $t5, $t5, $v1
    ctx->pc = 0x1786a0u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) - GPR_U64(ctx, 3));
    // 0x1786a4: 0x8fce0190  lw          $t6, 0x190($fp)
    ctx->pc = 0x1786a4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 400)));
    // 0x1786a8: 0x183602f  dsubu       $t4, $t4, $v1
    ctx->pc = 0x1786a8u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) - GPR_U64(ctx, 3));
    // 0x1786ac: 0x8fd10008  lw          $s1, 0x8($fp)
    ctx->pc = 0x1786acu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1786b0: 0x24b5824  and         $t3, $s2, $t3
    ctx->pc = 0x1786b0u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 18) & GPR_U64(ctx, 11));
    // 0x1786b4: 0x8fc30198  lw          $v1, 0x198($fp)
    ctx->pc = 0x1786b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 408)));
    // 0x1786b8: 0xd683c  dsll32      $t5, $t5, 0
    ctx->pc = 0x1786b8u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) << (32 + 0));
    // 0x1786bc: 0xd683f  dsra32      $t5, $t5, 0
    ctx->pc = 0x1786bcu;
    SET_GPR_S64(ctx, 13, GPR_S64(ctx, 13) >> (32 + 0));
    // 0x1786c0: 0x8fd0019c  lw          $s0, 0x19C($fp)
    ctx->pc = 0x1786c0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 412)));
    // 0x1786c4: 0xc603c  dsll32      $t4, $t4, 0
    ctx->pc = 0x1786c4u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) << (32 + 0));
    // 0x1786c8: 0xc603f  dsra32      $t4, $t4, 0
    ctx->pc = 0x1786c8u;
    SET_GPR_S64(ctx, 12, GPR_S64(ctx, 12) >> (32 + 0));
    // 0x1786cc: 0x8fc20194  lw          $v0, 0x194($fp)
    ctx->pc = 0x1786ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 404)));
    // 0x1786d0: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1786d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1786d4: 0x8fd60108  lw          $s6, 0x108($fp)
    ctx->pc = 0x1786d4u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 264)));
    // 0x1786d8: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x1786d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1786dc: 0x8fd301ac  lw          $s3, 0x1AC($fp)
    ctx->pc = 0x1786dcu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 428)));
    // 0x1786e0: 0xb583c  dsll32      $t3, $t3, 0
    ctx->pc = 0x1786e0u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) << (32 + 0));
    // 0x1786e4: 0xb583f  dsra32      $t3, $t3, 0
    ctx->pc = 0x1786e4u;
    SET_GPR_S64(ctx, 11, GPR_S64(ctx, 11) >> (32 + 0));
    // 0x1786e8: 0x8fd701b4  lw          $s7, 0x1B4($fp)
    ctx->pc = 0x1786e8u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 436)));
    // 0x1786ec: 0x8fd501b8  lw          $s5, 0x1B8($fp)
    ctx->pc = 0x1786ecu;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 440)));
    // 0x1786f0: 0x8fd40004  lw          $s4, 0x4($fp)
    ctx->pc = 0x1786f0u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1786f4: 0x8fd20188  lw          $s2, 0x188($fp)
    ctx->pc = 0x1786f4u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 392)));
    // 0x1786f8: 0x8fca0118  lw          $t2, 0x118($fp)
    ctx->pc = 0x1786f8u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 280)));
    // 0x1786fc: 0x8fa701a0  lw          $a3, 0x1A0($sp)
    ctx->pc = 0x1786fcu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 416)));
    // 0x178700: 0xafac0020  sw          $t4, 0x20($sp)
    ctx->pc = 0x178700u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 12));
    // 0x178704: 0xafb10050  sw          $s1, 0x50($sp)
    ctx->pc = 0x178704u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 17));
    // 0x178708: 0xafb00058  sw          $s0, 0x58($sp)
    ctx->pc = 0x178708u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 16));
    // 0x17870c: 0xafb20000  sw          $s2, 0x0($sp)
    ctx->pc = 0x17870cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 18));
    // 0x178710: 0xafb60008  sw          $s6, 0x8($sp)
    ctx->pc = 0x178710u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 22));
    // 0x178714: 0xafb90010  sw          $t9, 0x10($sp)
    ctx->pc = 0x178714u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 25));
    // 0x178718: 0xafad0018  sw          $t5, 0x18($sp)
    ctx->pc = 0x178718u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 13));
    // 0x17871c: 0xafb30028  sw          $s3, 0x28($sp)
    ctx->pc = 0x17871cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 19));
    // 0x178720: 0xafb80030  sw          $t8, 0x30($sp)
    ctx->pc = 0x178720u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 24));
    // 0x178724: 0xafb70038  sw          $s7, 0x38($sp)
    ctx->pc = 0x178724u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 23));
    // 0x178728: 0xafb50040  sw          $s5, 0x40($sp)
    ctx->pc = 0x178728u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 21));
    // 0x17872c: 0xafb40048  sw          $s4, 0x48($sp)
    ctx->pc = 0x17872cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 20));
    // 0x178730: 0xafaf0060  sw          $t7, 0x60($sp)
    ctx->pc = 0x178730u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 15));
    // 0x178734: 0xafae0068  sw          $t6, 0x68($sp)
    ctx->pc = 0x178734u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 14));
    // 0x178738: 0xafa20070  sw          $v0, 0x70($sp)
    ctx->pc = 0x178738u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 2));
    // 0x17873c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17873cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x178740: 0xafa30078  sw          $v1, 0x78($sp)
    ctx->pc = 0x178740u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 3));
    // 0x178744: 0x8c4cef68  lw          $t4, -0x1098($v0)
    ctx->pc = 0x178744u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963048)));
    // 0x178748: 0x8fc301a8  lw          $v1, 0x1A8($fp)
    ctx->pc = 0x178748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 424)));
    // 0x17874c: 0x8fc201a4  lw          $v0, 0x1A4($fp)
    ctx->pc = 0x17874cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 420)));
    // 0x178750: 0xafa30088  sw          $v1, 0x88($sp)
    ctx->pc = 0x178750u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 136), GPR_U32(ctx, 3));
    // 0x178754: 0xafa20080  sw          $v0, 0x80($sp)
    ctx->pc = 0x178754u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 2));
    // 0x178758: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x178758u;
    SET_GPR_U32(ctx, 31, 0x178760u);
    ctx->pc = 0x17875Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178758u;
            // 0x17875c: 0xafac0090  sw          $t4, 0x90($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 144), GPR_U32(ctx, 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178760u; }
        if (ctx->pc != 0x178760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178760u; }
        if (ctx->pc != 0x178760u) { return; }
    }
    ctx->pc = 0x178760u;
label_178760:
    // 0x178760: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x178760u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178764: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x178764u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x178768: 0x2451f1e4  addiu       $s1, $v0, -0xE1C
    ctx->pc = 0x178768u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963684));
    // 0x17876c: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x17876cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x178770: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x178770u;
    SET_GPR_U32(ctx, 31, 0x178778u);
    ctx->pc = 0x178774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178770u;
            // 0x178774: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178778u; }
        if (ctx->pc != 0x178778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178778u; }
        if (ctx->pc != 0x178778u) { return; }
    }
    ctx->pc = 0x178778u;
label_178778:
    // 0x178778: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x178778u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17877c: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x17877cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x178780: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x178780u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x178784: 0x24a5f1dc  addiu       $a1, $a1, -0xE24
    ctx->pc = 0x178784u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294963676));
    // 0x178788: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x178788u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x17878c: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x17878cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x178790: 0x8c85f1d8  lw          $a1, -0xE28($a0)
    ctx->pc = 0x178790u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294963672)));
    // 0x178794: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x178794u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x178798: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x178798u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17879c: 0x2442fc00  addiu       $v0, $v0, -0x400
    ctx->pc = 0x17879cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966272));
    // 0x1787a0: 0x62182b  sltu        $v1, $v1, $v0
    ctx->pc = 0x1787a0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1787a4: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1787A4u;
    {
        const bool branch_taken_0x1787a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1787A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1787A4u;
            // 0x1787a8: 0xdfb001b0  ld          $s0, 0x1B0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 432)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1787a4) {
            ctx->pc = 0x1787BCu;
            goto label_1787bc;
        }
    }
    ctx->pc = 0x1787ACu;
    // 0x1787ac: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1787acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1787b0: 0x8c43f1e8  lw          $v1, -0xE18($v0)
    ctx->pc = 0x1787b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963688)));
    // 0x1787b4: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1787b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1787b8:
    // 0x1787b8: 0xdfb001b0  ld          $s0, 0x1B0($sp)
    ctx->pc = 0x1787b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 432)));
label_1787bc:
    // 0x1787bc: 0xdfb101b8  ld          $s1, 0x1B8($sp)
    ctx->pc = 0x1787bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 440)));
    // 0x1787c0: 0xdfb201c0  ld          $s2, 0x1C0($sp)
    ctx->pc = 0x1787c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 448)));
    // 0x1787c4: 0xdfb301c8  ld          $s3, 0x1C8($sp)
    ctx->pc = 0x1787c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 456)));
    // 0x1787c8: 0xdfb401d0  ld          $s4, 0x1D0($sp)
    ctx->pc = 0x1787c8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 464)));
    // 0x1787cc: 0xdfb501d8  ld          $s5, 0x1D8($sp)
    ctx->pc = 0x1787ccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 472)));
    // 0x1787d0: 0xdfb601e0  ld          $s6, 0x1E0($sp)
    ctx->pc = 0x1787d0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x1787d4: 0xdfb701e8  ld          $s7, 0x1E8($sp)
    ctx->pc = 0x1787d4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x1787d8: 0xdfbe01f0  ld          $fp, 0x1F0($sp)
    ctx->pc = 0x1787d8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x1787dc: 0xdfbf01f8  ld          $ra, 0x1F8($sp)
    ctx->pc = 0x1787dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x1787e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1787E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1787E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1787E0u;
            // 0x1787e4: 0x27bd0200  addiu       $sp, $sp, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1785FCu: goto label_1785fc;
            case 0x178610u: goto label_178610;
            case 0x17861Cu: goto label_17861c;
            case 0x178628u: goto label_178628;
            case 0x178638u: goto label_178638;
            case 0x178648u: goto label_178648;
            case 0x178654u: goto label_178654;
            case 0x178660u: goto label_178660;
            case 0x17866Cu: goto label_17866c;
            case 0x178760u: goto label_178760;
            case 0x178778u: goto label_178778;
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1787E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

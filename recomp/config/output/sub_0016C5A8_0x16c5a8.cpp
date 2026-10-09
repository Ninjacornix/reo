#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C5A8
// Address: 0x16c5a8 - 0x16c6b8
void sub_0016C5A8_0x16c5a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C5A8_0x16c5a8");
#endif

    switch (ctx->pc) {
        case 0x16c5d4u: goto label_16c5d4;
        case 0x16c604u: goto label_16c604;
        case 0x16c628u: goto label_16c628;
        case 0x16c648u: goto label_16c648;
        case 0x16c658u: goto label_16c658;
        case 0x16c668u: goto label_16c668;
        default: break;
    }

    ctx->pc = 0x16c5a8u;

    // 0x16c5a8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16c5a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16c5ac: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16c5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16c5b0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16c5b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16c5b4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16c5b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c5b8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16c5b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16c5bc: 0x26500078  addiu       $s0, $s2, 0x78
    ctx->pc = 0x16c5bcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 120));
    // 0x16c5c0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16c5c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16c5c4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16c5c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x16c5c8: 0x8e531b30  lw          $s3, 0x1B30($s2)
    ctx->pc = 0x16c5c8u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 6960)));
    // 0x16c5cc: 0xc05b58c  jal         func_16D630
    ctx->pc = 0x16C5CCu;
    SET_GPR_U32(ctx, 31, 0x16C5D4u);
    ctx->pc = 0x16C5D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C5CCu;
            // 0x16c5d0: 0x8e710000  lw          $s1, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16D630u;
    if (runtime->hasFunction(0x16D630u)) {
        auto targetFn = runtime->lookupFunction(0x16D630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C5D4u; }
        if (ctx->pc != 0x16C5D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016D630_0x16d630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C5D4u; }
        if (ctx->pc != 0x16C5D4u) { return; }
    }
    ctx->pc = 0x16C5D4u;
label_16c5d4:
    // 0x16c5d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16c5d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16c5d8: 0x50430026  beql        $v0, $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x16C5D8u;
    {
        const bool branch_taken_0x16c5d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x16c5d8) {
            ctx->pc = 0x16C5DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16C5D8u;
            // 0x16c5dc: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16C674u;
            goto label_16c674;
        }
    }
    ctx->pc = 0x16C5E0u;
    // 0x16c5e0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x16c5e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16c5e4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16C5E4u;
    {
        const bool branch_taken_0x16c5e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C5E4u;
            // 0x16c5e8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c5e4) {
            ctx->pc = 0x16C5FCu;
            goto label_16c5fc;
        }
    }
    ctx->pc = 0x16C5ECu;
    // 0x16c5ec: 0x8e03007c  lw          $v1, 0x7C($s0)
    ctx->pc = 0x16c5ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x16c5f0: 0x1060001f  beqz        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x16C5F0u;
    {
        const bool branch_taken_0x16c5f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C5F0u;
            // 0x16c5f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c5f0) {
            ctx->pc = 0x16C670u;
            goto label_16c670;
        }
    }
    ctx->pc = 0x16C5F8u;
    // 0x16c5f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16c5f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_16c5fc:
    // 0x16c5fc: 0xc0564c6  jal         func_159318
    ctx->pc = 0x16C5FCu;
    SET_GPR_U32(ctx, 31, 0x16C604u);
    ctx->pc = 0x16C600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C5FCu;
            // 0x16c600: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159318u;
    if (runtime->hasFunction(0x159318u)) {
        auto targetFn = runtime->lookupFunction(0x159318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C604u; }
        if (ctx->pc != 0x16C604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159318_0x159318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C604u; }
        if (ctx->pc != 0x16C604u) { return; }
    }
    ctx->pc = 0x16C604u;
label_16c604:
    // 0x16c604: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16c604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c608: 0x3c030003  lui         $v1, 0x3
    ctx->pc = 0x16c608u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)3 << 16));
    // 0x16c60c: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x16c60cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c610: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x16c610u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x16c614: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16c614u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16c618: 0x10c30015  beq         $a2, $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x16C618u;
    {
        const bool branch_taken_0x16c618 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x16C61Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C618u;
            // 0x16c61c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c618) {
            ctx->pc = 0x16C670u;
            goto label_16c670;
        }
    }
    ctx->pc = 0x16C620u;
    // 0x16c620: 0xc059d52  jal         func_167548
    ctx->pc = 0x16C620u;
    SET_GPR_U32(ctx, 31, 0x16C628u);
    ctx->pc = 0x167548u;
    if (runtime->hasFunction(0x167548u)) {
        auto targetFn = runtime->lookupFunction(0x167548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C628u; }
        if (ctx->pc != 0x16C628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167548_0x167548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C628u; }
        if (ctx->pc != 0x16C628u) { return; }
    }
    ctx->pc = 0x16C628u;
label_16c628:
    // 0x16c628: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16c628u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c62c: 0x8e6300e8  lw          $v1, 0xE8($s3)
    ctx->pc = 0x16c62cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 232)));
    // 0x16c630: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16c630u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16c634: 0x43302a  slt         $a2, $v0, $v1
    ctx->pc = 0x16c634u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x16c638: 0x10c0000d  beqz        $a2, . + 4 + (0xD << 2)
    ctx->pc = 0x16C638u;
    {
        const bool branch_taken_0x16c638 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C638u;
            // 0x16c63c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c638) {
            ctx->pc = 0x16C670u;
            goto label_16c670;
        }
    }
    ctx->pc = 0x16C640u;
    // 0x16c640: 0xc05df24  jal         func_177C90
    ctx->pc = 0x16C640u;
    SET_GPR_U32(ctx, 31, 0x16C648u);
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C648u; }
        if (ctx->pc != 0x16C648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C648u; }
        if (ctx->pc != 0x16C648u) { return; }
    }
    ctx->pc = 0x16C648u;
label_16c648:
    // 0x16c648: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16c648u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c64c: 0x2c510001  sltiu       $s1, $v0, 0x1
    ctx->pc = 0x16c64cu;
    SET_GPR_U64(ctx, 17, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x16c650: 0xc059d52  jal         func_167548
    ctx->pc = 0x16C650u;
    SET_GPR_U32(ctx, 31, 0x16C658u);
    ctx->pc = 0x16C654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C650u;
            // 0x16c654: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167548u;
    if (runtime->hasFunction(0x167548u)) {
        auto targetFn = runtime->lookupFunction(0x167548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C658u; }
        if (ctx->pc != 0x16C658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167548_0x167548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C658u; }
        if (ctx->pc != 0x16C658u) { return; }
    }
    ctx->pc = 0x16C658u;
label_16c658:
    // 0x16c658: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16c658u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c65c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16c65cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c660: 0xc059d42  jal         func_167508
    ctx->pc = 0x16C660u;
    SET_GPR_U32(ctx, 31, 0x16C668u);
    ctx->pc = 0x16C664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C660u;
            // 0x16c664: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167508u;
    if (runtime->hasFunction(0x167508u)) {
        auto targetFn = runtime->lookupFunction(0x167508u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C668u; }
        if (ctx->pc != 0x16C668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167508_0x167508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C668u; }
        if (ctx->pc != 0x16C668u) { return; }
    }
    ctx->pc = 0x16C668u;
label_16c668:
    // 0x16c668: 0x202802a  slt         $s0, $s0, $v0
    ctx->pc = 0x16c668u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16c66c: 0x2e020001  sltiu       $v0, $s0, 0x1
    ctx->pc = 0x16c66cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_16c670:
    // 0x16c670: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16c670u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16c674:
    // 0x16c674: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16c674u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c678: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16c678u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c67c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16c67cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16c680: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16c680u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16c684: 0x3e00008  jr          $ra
    ctx->pc = 0x16C684u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C684u;
            // 0x16c688: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C5D4u: goto label_16c5d4;
            case 0x16C5FCu: goto label_16c5fc;
            case 0x16C604u: goto label_16c604;
            case 0x16C628u: goto label_16c628;
            case 0x16C648u: goto label_16c648;
            case 0x16C658u: goto label_16c658;
            case 0x16C668u: goto label_16c668;
            case 0x16C670u: goto label_16c670;
            case 0x16C674u: goto label_16c674;
            case 0x16C6ACu: goto label_16c6ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C68Cu;
    // 0x16c68c: 0x0  nop
    ctx->pc = 0x16c68cu;
    // NOP
    // 0x16c690: 0x24840da4  addiu       $a0, $a0, 0xDA4
    ctx->pc = 0x16c690u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 3492));
    // 0x16c694: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x16c694u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x16c698: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x16c698u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x16c69c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x16c69cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x16c6a0: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x16C6A0u;
    {
        const bool branch_taken_0x16c6a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16C6A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C6A0u;
            // 0x16c6a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c6a0) {
            ctx->pc = 0x16C6ACu;
            goto label_16c6ac;
        }
    }
    ctx->pc = 0x16C6A8u;
    // 0x16c6a8: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x16c6a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_16c6ac:
    // 0x16c6ac: 0x3e00008  jr          $ra
    ctx->pc = 0x16C6ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C5D4u: goto label_16c5d4;
            case 0x16C5FCu: goto label_16c5fc;
            case 0x16C604u: goto label_16c604;
            case 0x16C628u: goto label_16c628;
            case 0x16C648u: goto label_16c648;
            case 0x16C658u: goto label_16c658;
            case 0x16C668u: goto label_16c668;
            case 0x16C670u: goto label_16c670;
            case 0x16C674u: goto label_16c674;
            case 0x16C6ACu: goto label_16c6ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C6B4u;
    // 0x16c6b4: 0x0  nop
    ctx->pc = 0x16c6b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

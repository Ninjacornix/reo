#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173330
// Address: 0x173330 - 0x1734b8
void sub_00173330_0x173330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173330_0x173330");
#endif

    switch (ctx->pc) {
        case 0x173374u: goto label_173374;
        case 0x173398u: goto label_173398;
        case 0x1733acu: goto label_1733ac;
        case 0x1733d4u: goto label_1733d4;
        case 0x17340cu: goto label_17340c;
        case 0x173430u: goto label_173430;
        case 0x1734a0u: goto label_1734a0;
        default: break;
    }

    ctx->pc = 0x173330u;

    // 0x173330: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173334: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x173334u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x173338: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x173338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17333c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17333cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173340: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x173340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x173344: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x173344u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x173348: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x173348u;
    {
        const bool branch_taken_0x173348 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17334Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173348u;
            // 0x17334c: 0x2605094c  addiu       $a1, $s0, 0x94C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 2380));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173348) {
            ctx->pc = 0x17337Cu;
            goto label_17337c;
        }
    }
    ctx->pc = 0x173350u;
    // 0x173350: 0x8e020050  lw          $v0, 0x50($s0)
    ctx->pc = 0x173350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
    // 0x173354: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x173354u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x173358: 0x10430015  beq         $v0, $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x173358u;
    {
        const bool branch_taken_0x173358 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17335Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173358u;
            // 0x17335c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173358) {
            ctx->pc = 0x1733B0u;
            goto label_1733b0;
        }
    }
    ctx->pc = 0x173360u;
    // 0x173360: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x173360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x173364: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x173364u;
    {
        const bool branch_taken_0x173364 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x173368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173364u;
            // 0x173368: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173364) {
            ctx->pc = 0x17337Cu;
            goto label_17337c;
        }
    }
    ctx->pc = 0x17336Cu;
    // 0x17336c: 0xc05d884  jal         func_176210
    ctx->pc = 0x17336Cu;
    SET_GPR_U32(ctx, 31, 0x173374u);
    ctx->pc = 0x173370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17336Cu;
            // 0x173370: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176210u;
    if (runtime->hasFunction(0x176210u)) {
        auto targetFn = runtime->lookupFunction(0x176210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173374u; }
        if (ctx->pc != 0x173374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176210_0x176210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173374u; }
        if (ctx->pc != 0x173374u) { return; }
    }
    ctx->pc = 0x173374u;
label_173374:
    // 0x173374: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x173374u;
    {
        const bool branch_taken_0x173374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173374u;
            // 0x173378: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173374) {
            ctx->pc = 0x173388u;
            goto label_173388;
        }
    }
    ctx->pc = 0x17337Cu;
label_17337c:
    // 0x17337c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x17337Cu;
    {
        const bool branch_taken_0x17337c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x173380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17337Cu;
            // 0x173380: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17337c) {
            ctx->pc = 0x1733B0u;
            goto label_1733b0;
        }
    }
    ctx->pc = 0x173384u;
    // 0x173384: 0x0  nop
    ctx->pc = 0x173384u;
    // NOP
label_173388:
    // 0x173388: 0x4600009  bltz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x173388u;
    {
        const bool branch_taken_0x173388 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x17338Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173388u;
            // 0x17338c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173388) {
            ctx->pc = 0x1733B0u;
            goto label_1733b0;
        }
    }
    ctx->pc = 0x173390u;
    // 0x173390: 0xc05d58a  jal         func_175628
    ctx->pc = 0x173390u;
    SET_GPR_U32(ctx, 31, 0x173398u);
    ctx->pc = 0x173394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173390u;
            // 0x173394: 0x24050036  addiu       $a1, $zero, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173398u; }
        if (ctx->pc != 0x173398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173398u; }
        if (ctx->pc != 0x173398u) { return; }
    }
    ctx->pc = 0x173398u;
label_173398:
    // 0x173398: 0x240503e8  addiu       $a1, $zero, 0x3E8
    ctx->pc = 0x173398u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x17339c: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x17339cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1733a0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1733a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1733a4: 0xc05d9de  jal         func_176778
    ctx->pc = 0x1733A4u;
    SET_GPR_U32(ctx, 31, 0x1733ACu);
    ctx->pc = 0x1733A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1733A4u;
            // 0x1733a8: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176778u;
    if (runtime->hasFunction(0x176778u)) {
        auto targetFn = runtime->lookupFunction(0x176778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733ACu; }
        if (ctx->pc != 0x1733ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176778_0x176778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733ACu; }
        if (ctx->pc != 0x1733ACu) { return; }
    }
    ctx->pc = 0x1733ACu;
label_1733ac:
    // 0x1733ac: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1733acu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_1733b0:
    // 0x1733b0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1733b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1733b4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1733b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1733b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1733B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1733BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1733B8u;
            // 0x1733bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173374u: goto label_173374;
            case 0x17337Cu: goto label_17337c;
            case 0x173388u: goto label_173388;
            case 0x173398u: goto label_173398;
            case 0x1733ACu: goto label_1733ac;
            case 0x1733B0u: goto label_1733b0;
            case 0x1733D4u: goto label_1733d4;
            case 0x1733E8u: goto label_1733e8;
            case 0x17340Cu: goto label_17340c;
            case 0x173430u: goto label_173430;
            case 0x173458u: goto label_173458;
            case 0x17346Cu: goto label_17346c;
            case 0x173490u: goto label_173490;
            case 0x1734A0u: goto label_1734a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1733C0u;
    // 0x1733c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1733c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1733c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1733c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1733c8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1733c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1733cc: 0xc05cf04  jal         func_173C10
    ctx->pc = 0x1733CCu;
    SET_GPR_U32(ctx, 31, 0x1733D4u);
    ctx->pc = 0x1733D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1733CCu;
            // 0x1733d0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173C10u;
    if (runtime->hasFunction(0x173C10u)) {
        auto targetFn = runtime->lookupFunction(0x173C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733D4u; }
        if (ctx->pc != 0x1733D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C10_0x173c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733D4u; }
        if (ctx->pc != 0x1733D4u) { return; }
    }
    ctx->pc = 0x1733D4u;
label_1733d4:
    // 0x1733d4: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1733D4u;
    {
        const bool branch_taken_0x1733d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1733d4) {
            ctx->pc = 0x1733D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1733D4u;
            // 0x1733d8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1733E8u;
            goto label_1733e8;
        }
    }
    ctx->pc = 0x1733DCu;
    // 0x1733dc: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1733dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1733e0: 0xae03004c  sw          $v1, 0x4C($s0)
    ctx->pc = 0x1733e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
    // 0x1733e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1733e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1733e8:
    // 0x1733e8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1733e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1733ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1733ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1733F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1733ECu;
            // 0x1733f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173374u: goto label_173374;
            case 0x17337Cu: goto label_17337c;
            case 0x173388u: goto label_173388;
            case 0x173398u: goto label_173398;
            case 0x1733ACu: goto label_1733ac;
            case 0x1733B0u: goto label_1733b0;
            case 0x1733D4u: goto label_1733d4;
            case 0x1733E8u: goto label_1733e8;
            case 0x17340Cu: goto label_17340c;
            case 0x173430u: goto label_173430;
            case 0x173458u: goto label_173458;
            case 0x17346Cu: goto label_17346c;
            case 0x173490u: goto label_173490;
            case 0x1734A0u: goto label_1734a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1733F4u;
    // 0x1733f4: 0x0  nop
    ctx->pc = 0x1733f4u;
    // NOP
    // 0x1733f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1733f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1733fc: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1733fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x173400: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x173400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x173404: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x173404u;
    SET_GPR_U32(ctx, 31, 0x17340Cu);
    ctx->pc = 0x173408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173404u;
            // 0x173408: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17340Cu; }
        if (ctx->pc != 0x17340Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17340Cu; }
        if (ctx->pc != 0x17340Cu) { return; }
    }
    ctx->pc = 0x17340Cu;
label_17340c:
    // 0x17340c: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x17340cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x173410: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x173410u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x173414: 0xafa00004  sw          $zero, 0x4($sp)
    ctx->pc = 0x173414u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
    // 0x173418: 0x2446f18c  addiu       $a2, $v0, -0xE74
    ctx->pc = 0x173418u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x17341c: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x17341cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x173420: 0x24070006  addiu       $a3, $zero, 0x6
    ctx->pc = 0x173420u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x173424: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x173424u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x173428: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x173428u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x17342c: 0x0  nop
    ctx->pc = 0x17342cu;
    // NOP
label_173430:
    // 0x173430: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x173430u;
    {
        const bool branch_taken_0x173430 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173430u;
            // 0x173434: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173430) {
            ctx->pc = 0x17346Cu;
            goto label_17346c;
        }
    }
    ctx->pc = 0x173438u;
    // 0x173438: 0x8c420048  lw          $v0, 0x48($v0)
    ctx->pc = 0x173438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x17343c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17343Cu;
    {
        const bool branch_taken_0x17343c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17343Cu;
            // 0x173440: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17343c) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x173444u;
    // 0x173444: 0x10470004  beq         $v0, $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x173444u;
    {
        const bool branch_taken_0x173444 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 7));
        ctx->pc = 0x173448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173444u;
            // 0x173448: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173444) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x17344Cu;
    // 0x17344c: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x17344Cu;
    {
        const bool branch_taken_0x17344c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x173450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17344Cu;
            // 0x173450: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17344c) {
            ctx->pc = 0x173458u;
            goto label_173458;
        }
    }
    ctx->pc = 0x173454u;
    // 0x173454: 0x24100002  addiu       $s0, $zero, 0x2
    ctx->pc = 0x173454u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_173458:
    // 0x173458: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x173458u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x17345c: 0x3a22021  addu        $a0, $sp, $v0
    ctx->pc = 0x17345cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x173460: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x173460u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x173464: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x173464u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x173468: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x173468u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
label_17346c:
    // 0x17346c: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x17346cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x173470: 0x4a3ffef  bgezl       $a1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x173470u;
    {
        const bool branch_taken_0x173470 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x173470) {
            ctx->pc = 0x173474u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173470u;
            // 0x173474: 0x8cc20000  lw          $v0, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173430u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173430;
        }
    }
    ctx->pc = 0x173478u;
    // 0x173478: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x173478u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x17347c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x17347Cu;
    {
        const bool branch_taken_0x17347c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x173480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17347Cu;
            // 0x173480: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17347c) {
            ctx->pc = 0x173490u;
            goto label_173490;
        }
    }
    ctx->pc = 0x173484u;
    // 0x173484: 0x8fa20008  lw          $v0, 0x8($sp)
    ctx->pc = 0x173484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173488: 0x24100002  addiu       $s0, $zero, 0x2
    ctx->pc = 0x173488u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17348c: 0x2800a  movz        $s0, $zero, $v0
    ctx->pc = 0x17348cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 0));
label_173490:
    // 0x173490: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x173490u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x173494: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x173494u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x173498: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x173498u;
    SET_GPR_U32(ctx, 31, 0x1734A0u);
    ctx->pc = 0x17349Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173498u;
            // 0x17349c: 0xac50f120  sw          $s0, -0xEE0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963488), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734A0u; }
        if (ctx->pc != 0x1734A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1734A0u; }
        if (ctx->pc != 0x1734A0u) { return; }
    }
    ctx->pc = 0x1734A0u;
label_1734a0:
    // 0x1734a0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1734a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1734a4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1734a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1734a8: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1734a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1734ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1734ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1734B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1734ACu;
            // 0x1734b0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173374u: goto label_173374;
            case 0x17337Cu: goto label_17337c;
            case 0x173388u: goto label_173388;
            case 0x173398u: goto label_173398;
            case 0x1733ACu: goto label_1733ac;
            case 0x1733B0u: goto label_1733b0;
            case 0x1733D4u: goto label_1733d4;
            case 0x1733E8u: goto label_1733e8;
            case 0x17340Cu: goto label_17340c;
            case 0x173430u: goto label_173430;
            case 0x173458u: goto label_173458;
            case 0x17346Cu: goto label_17346c;
            case 0x173490u: goto label_173490;
            case 0x1734A0u: goto label_1734a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1734B4u;
    // 0x1734b4: 0x0  nop
    ctx->pc = 0x1734b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

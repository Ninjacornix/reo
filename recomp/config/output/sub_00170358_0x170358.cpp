#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170358
// Address: 0x170358 - 0x1704d0
void sub_00170358_0x170358(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170358_0x170358");
#endif

    switch (ctx->pc) {
        case 0x1703a4u: goto label_1703a4;
        case 0x1703d4u: goto label_1703d4;
        case 0x1703ecu: goto label_1703ec;
        case 0x170444u: goto label_170444;
        case 0x170474u: goto label_170474;
        case 0x17048cu: goto label_17048c;
        default: break;
    }

    ctx->pc = 0x170358u;

    // 0x170358: 0x8c832ab0  lw          $v1, 0x2AB0($a0)
    ctx->pc = 0x170358u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 10928)));
    // 0x17035c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x17035cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170360: 0x8c841b30  lw          $a0, 0x1B30($a0)
    ctx->pc = 0x170360u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x170364: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x170364u;
    {
        const bool branch_taken_0x170364 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x170368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170364u;
            // 0x170368: 0x24650ac4  addiu       $a1, $v1, 0xAC4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 2756));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170364) {
            ctx->pc = 0x170380u;
            goto label_170380;
        }
    }
    ctx->pc = 0x17036Cu;
    // 0x17036c: 0x8c820088  lw          $v0, 0x88($a0)
    ctx->pc = 0x17036cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 136)));
    // 0x170370: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x170370u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170374: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x170374u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x170378: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x170378u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17037c: 0xa3100a  movz        $v0, $a1, $v1
    ctx->pc = 0x17037cu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
label_170380:
    // 0x170380: 0x3e00008  jr          $ra
    ctx->pc = 0x170380u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170380u: goto label_170380;
            case 0x1703A4u: goto label_1703a4;
            case 0x1703C8u: goto label_1703c8;
            case 0x1703D4u: goto label_1703d4;
            case 0x1703ECu: goto label_1703ec;
            case 0x1703F8u: goto label_1703f8;
            case 0x170408u: goto label_170408;
            case 0x170444u: goto label_170444;
            case 0x170468u: goto label_170468;
            case 0x170474u: goto label_170474;
            case 0x17048Cu: goto label_17048c;
            case 0x170498u: goto label_170498;
            case 0x1704B0u: goto label_1704b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170388u;
    // 0x170388: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17038c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17038cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170390: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170390u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170394: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x170394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170398: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x170398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17039c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x17039Cu;
    SET_GPR_U32(ctx, 31, 0x1703A4u);
    ctx->pc = 0x1703A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17039Cu;
            // 0x1703a0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703A4u; }
        if (ctx->pc != 0x1703A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703A4u; }
        if (ctx->pc != 0x1703A4u) { return; }
    }
    ctx->pc = 0x1703A4u;
label_1703a4:
    // 0x1703a4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1703a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1703a8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1703A8u;
    {
        const bool branch_taken_0x1703a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1703ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1703A8u;
            // 0x1703ac: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1703a8) {
            ctx->pc = 0x1703C8u;
            goto label_1703c8;
        }
    }
    ctx->pc = 0x1703B0u;
    // 0x1703b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1703b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1703b4: 0x34a50188  ori         $a1, $a1, 0x188
    ctx->pc = 0x1703b4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)392);
    // 0x1703b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1703b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1703bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1703bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1703c0: 0x805a704  j           func_169C10
    ctx->pc = 0x1703C0u;
    ctx->pc = 0x1703C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1703C0u;
            // 0x1703c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1703C8u;
label_1703c8:
    // 0x1703c8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1703c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1703cc: 0xc05c134  jal         func_1704D0
    ctx->pc = 0x1703CCu;
    SET_GPR_U32(ctx, 31, 0x1703D4u);
    ctx->pc = 0x1703D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1703CCu;
            // 0x1703d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1704D0u;
    if (runtime->hasFunction(0x1704D0u)) {
        auto targetFn = runtime->lookupFunction(0x1704D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703D4u; }
        if (ctx->pc != 0x1703D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001704D0_0x1704d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703D4u; }
        if (ctx->pc != 0x1703D4u) { return; }
    }
    ctx->pc = 0x1703D4u;
label_1703d4:
    // 0x1703d4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1703d4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1703d8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1703d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1703dc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1703DCu;
    {
        const bool branch_taken_0x1703dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1703E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1703DCu;
            // 0x1703e0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1703dc) {
            ctx->pc = 0x1703F8u;
            goto label_1703f8;
        }
    }
    ctx->pc = 0x1703E4u;
    // 0x1703e4: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1703E4u;
    SET_GPR_U32(ctx, 31, 0x1703ECu);
    ctx->pc = 0x1703E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1703E4u;
            // 0x1703e8: 0x34a50f30  ori         $a1, $a1, 0xF30 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3888);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703ECu; }
        if (ctx->pc != 0x1703ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1703ECu; }
        if (ctx->pc != 0x1703ECu) { return; }
    }
    ctx->pc = 0x1703ECu;
label_1703ec:
    // 0x1703ec: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1703ECu;
    {
        const bool branch_taken_0x1703ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1703F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1703ECu;
            // 0x1703f0: 0x8e020974  lw          $v0, 0x974($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2420)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1703ec) {
            ctx->pc = 0x170408u;
            goto label_170408;
        }
    }
    ctx->pc = 0x1703F4u;
    // 0x1703f4: 0x0  nop
    ctx->pc = 0x1703f4u;
    // NOP
label_1703f8:
    // 0x1703f8: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1703f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1703fc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1703fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x170400: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x170400u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x170404: 0x8e020974  lw          $v0, 0x974($s0)
    ctx->pc = 0x170404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2420)));
label_170408:
    // 0x170408: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170408u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17040c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x17040cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x170410: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x170410u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170414: 0xae020974  sw          $v0, 0x974($s0)
    ctx->pc = 0x170414u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2420), GPR_U32(ctx, 2));
    // 0x170418: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170418u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17041c: 0x3e00008  jr          $ra
    ctx->pc = 0x17041Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17041Cu;
            // 0x170420: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170380u: goto label_170380;
            case 0x1703A4u: goto label_1703a4;
            case 0x1703C8u: goto label_1703c8;
            case 0x1703D4u: goto label_1703d4;
            case 0x1703ECu: goto label_1703ec;
            case 0x1703F8u: goto label_1703f8;
            case 0x170408u: goto label_170408;
            case 0x170444u: goto label_170444;
            case 0x170468u: goto label_170468;
            case 0x170474u: goto label_170474;
            case 0x17048Cu: goto label_17048c;
            case 0x170498u: goto label_170498;
            case 0x1704B0u: goto label_1704b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170424u;
    // 0x170424: 0x0  nop
    ctx->pc = 0x170424u;
    // NOP
    // 0x170428: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x170428u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17042c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17042cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170430: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x170430u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170434: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x170434u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170438: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x170438u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17043c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x17043Cu;
    SET_GPR_U32(ctx, 31, 0x170444u);
    ctx->pc = 0x170440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17043Cu;
            // 0x170440: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170444u; }
        if (ctx->pc != 0x170444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170444u; }
        if (ctx->pc != 0x170444u) { return; }
    }
    ctx->pc = 0x170444u;
label_170444:
    // 0x170444: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x170444u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x170448: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x170448u;
    {
        const bool branch_taken_0x170448 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17044Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170448u;
            // 0x17044c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170448) {
            ctx->pc = 0x170468u;
            goto label_170468;
        }
    }
    ctx->pc = 0x170450u;
    // 0x170450: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170450u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170454: 0x34a50189  ori         $a1, $a1, 0x189
    ctx->pc = 0x170454u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)393);
    // 0x170458: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x170458u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17045c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17045cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170460: 0x805a704  j           func_169C10
    ctx->pc = 0x170460u;
    ctx->pc = 0x170464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170460u;
            // 0x170464: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x170468u;
label_170468:
    // 0x170468: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x170468u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17046c: 0xc05c134  jal         func_1704D0
    ctx->pc = 0x17046Cu;
    SET_GPR_U32(ctx, 31, 0x170474u);
    ctx->pc = 0x170470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17046Cu;
            // 0x170470: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1704D0u;
    if (runtime->hasFunction(0x1704D0u)) {
        auto targetFn = runtime->lookupFunction(0x1704D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170474u; }
        if (ctx->pc != 0x170474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001704D0_0x1704d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170474u; }
        if (ctx->pc != 0x170474u) { return; }
    }
    ctx->pc = 0x170474u;
label_170474:
    // 0x170474: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x170474u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170478: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x170478u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17047c: 0x14c00006  bnez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x17047Cu;
    {
        const bool branch_taken_0x17047c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x170480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17047Cu;
            // 0x170480: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17047c) {
            ctx->pc = 0x170498u;
            goto label_170498;
        }
    }
    ctx->pc = 0x170484u;
    // 0x170484: 0xc05a704  jal         func_169C10
    ctx->pc = 0x170484u;
    SET_GPR_U32(ctx, 31, 0x17048Cu);
    ctx->pc = 0x170488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170484u;
            // 0x170488: 0x34a50f31  ori         $a1, $a1, 0xF31 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3889);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17048Cu; }
        if (ctx->pc != 0x17048Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17048Cu; }
        if (ctx->pc != 0x17048Cu) { return; }
    }
    ctx->pc = 0x17048Cu;
label_17048c:
    // 0x17048c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x17048Cu;
    {
        const bool branch_taken_0x17048c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x170490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17048Cu;
            // 0x170490: 0x8e020974  lw          $v0, 0x974($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2420)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17048c) {
            ctx->pc = 0x1704B0u;
            goto label_1704b0;
        }
    }
    ctx->pc = 0x170494u;
    // 0x170494: 0x0  nop
    ctx->pc = 0x170494u;
    // NOP
label_170498:
    // 0x170498: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x170498u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x17049c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x17049cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1704a0: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1704a0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1704a4: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x1704a4u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1704a8: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x1704a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x1704ac: 0x8e020974  lw          $v0, 0x974($s0)
    ctx->pc = 0x1704acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2420)));
label_1704b0:
    // 0x1704b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1704b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1704b4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1704b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1704b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1704b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1704bc: 0xae020974  sw          $v0, 0x974($s0)
    ctx->pc = 0x1704bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2420), GPR_U32(ctx, 2));
    // 0x1704c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1704c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1704c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1704C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1704C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1704C4u;
            // 0x1704c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170380u: goto label_170380;
            case 0x1703A4u: goto label_1703a4;
            case 0x1703C8u: goto label_1703c8;
            case 0x1703D4u: goto label_1703d4;
            case 0x1703ECu: goto label_1703ec;
            case 0x1703F8u: goto label_1703f8;
            case 0x170408u: goto label_170408;
            case 0x170444u: goto label_170444;
            case 0x170468u: goto label_170468;
            case 0x170474u: goto label_170474;
            case 0x17048Cu: goto label_17048c;
            case 0x170498u: goto label_170498;
            case 0x1704B0u: goto label_1704b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1704CCu;
    // 0x1704cc: 0x0  nop
    ctx->pc = 0x1704ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001506C0
// Address: 0x1506c0 - 0x150a48
void sub_001506C0_0x1506c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001506C0_0x1506c0");
#endif

    switch (ctx->pc) {
        case 0x1506e8u: goto label_1506e8;
        case 0x15071cu: goto label_15071c;
        case 0x150758u: goto label_150758;
        case 0x150760u: goto label_150760;
        case 0x150784u: goto label_150784;
        case 0x1507d4u: goto label_1507d4;
        case 0x150810u: goto label_150810;
        case 0x150870u: goto label_150870;
        case 0x1508fcu: goto label_1508fc;
        case 0x15096cu: goto label_15096c;
        case 0x1509f4u: goto label_1509f4;
        default: break;
    }

    ctx->pc = 0x1506c0u;

    // 0x1506c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1506c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1506c4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1506c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1506c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1506c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1506cc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1506CCu;
    {
        const bool branch_taken_0x1506cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1506D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1506CCu;
            // 0x1506d0: 0xac820008  sw          $v0, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1506cc) {
            ctx->pc = 0x1506E8u;
            goto label_1506e8;
        }
    }
    ctx->pc = 0x1506D4u;
    // 0x1506d4: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1506d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1506d8: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1506D8u;
    {
        const bool branch_taken_0x1506d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1506d8) {
            ctx->pc = 0x1506DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1506D8u;
            // 0x1506dc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1506ECu;
            goto label_1506ec;
        }
    }
    ctx->pc = 0x1506E0u;
    // 0x1506e0: 0x40f809  jalr        $v0
    ctx->pc = 0x1506E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1506E8u);
        ctx->pc = 0x1506E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1506E0u;
            // 0x1506e4: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1506E8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1506E8u: goto label_1506e8;
            case 0x1506ECu: goto label_1506ec;
            case 0x15071Cu: goto label_15071c;
            case 0x150748u: goto label_150748;
            case 0x150758u: goto label_150758;
            case 0x150760u: goto label_150760;
            case 0x150784u: goto label_150784;
            case 0x15078Cu: goto label_15078c;
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1506E8u; }
            if (ctx->pc != 0x1506E8u) { return; }
        }
        }
    }
    ctx->pc = 0x1506E8u;
label_1506e8:
    // 0x1506e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1506e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1506ec:
    // 0x1506ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1506ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1506F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1506ECu;
            // 0x1506f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1506E8u: goto label_1506e8;
            case 0x1506ECu: goto label_1506ec;
            case 0x15071Cu: goto label_15071c;
            case 0x150748u: goto label_150748;
            case 0x150758u: goto label_150758;
            case 0x150760u: goto label_150760;
            case 0x150784u: goto label_150784;
            case 0x15078Cu: goto label_15078c;
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1506F4u;
    // 0x1506f4: 0x0  nop
    ctx->pc = 0x1506f4u;
    // NOP
    // 0x1506f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1506f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1506fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1506fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150700: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x150700u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150704: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x150704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x150708: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x150708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15070c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15070cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x150710: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x150710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x150714: 0xc05578e  jal         func_155E38
    ctx->pc = 0x150714u;
    SET_GPR_U32(ctx, 31, 0x15071Cu);
    ctx->pc = 0x150718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150714u;
            // 0x150718: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15071Cu; }
        if (ctx->pc != 0x15071Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15071Cu; }
        if (ctx->pc != 0x15071Cu) { return; }
    }
    ctx->pc = 0x15071Cu;
label_15071c:
    // 0x15071c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15071Cu;
    {
        const bool branch_taken_0x15071c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15071Cu;
            // 0x150720: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15071c) {
            ctx->pc = 0x150748u;
            goto label_150748;
        }
    }
    ctx->pc = 0x150724u;
    // 0x150724: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x150724u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150728: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150728u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15072c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15072cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150730: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150730u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150734: 0x34a5020a  ori         $a1, $a1, 0x20A
    ctx->pc = 0x150734u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)522);
    // 0x150738: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x150738u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15073c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15073cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x150740: 0x805419c  j           func_150670
    ctx->pc = 0x150740u;
    ctx->pc = 0x150744u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150740u;
            // 0x150744: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150748u;
label_150748:
    // 0x150748: 0x3c11ff03  lui         $s1, 0xFF03
    ctx->pc = 0x150748u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)65283 << 16));
    // 0x15074c: 0x24120004  addiu       $s2, $zero, 0x4
    ctx->pc = 0x15074cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x150750: 0x36310305  ori         $s1, $s1, 0x305
    ctx->pc = 0x150750u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)773);
    // 0x150754: 0x0  nop
    ctx->pc = 0x150754u;
    // NOP
label_150758:
    // 0x150758: 0xc056b7a  jal         func_15ADE8
    ctx->pc = 0x150758u;
    SET_GPR_U32(ctx, 31, 0x150760u);
    ctx->pc = 0x15075Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150758u;
            // 0x15075c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15ADE8u;
    if (runtime->hasFunction(0x15ADE8u)) {
        auto targetFn = runtime->lookupFunction(0x15ADE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150760u; }
        if (ctx->pc != 0x150760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015ADE8_0x15ade8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150760u; }
        if (ctx->pc != 0x150760u) { return; }
    }
    ctx->pc = 0x150760u;
label_150760:
    // 0x150760: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x150760u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150764: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x150764u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x150768: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x150768u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x15076c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15076Cu;
    {
        const bool branch_taken_0x15076c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15076Cu;
            // 0x150770: 0x304300cc  andi        $v1, $v0, 0xCC (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)204);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15076c) {
            ctx->pc = 0x15078Cu;
            goto label_15078c;
        }
    }
    ctx->pc = 0x150774u;
    // 0x150774: 0x54600005  bnel        $v1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x150774u;
    {
        const bool branch_taken_0x150774 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x150774) {
            ctx->pc = 0x150778u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x150774u;
            // 0x150778: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15078Cu;
            goto label_15078c;
        }
    }
    ctx->pc = 0x15077Cu;
    // 0x15077c: 0xc056c04  jal         func_15B010
    ctx->pc = 0x15077Cu;
    SET_GPR_U32(ctx, 31, 0x150784u);
    ctx->pc = 0x15B010u;
    if (runtime->hasFunction(0x15B010u)) {
        auto targetFn = runtime->lookupFunction(0x15B010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150784u; }
        if (ctx->pc != 0x150784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B010_0x15b010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150784u; }
        if (ctx->pc != 0x150784u) { return; }
    }
    ctx->pc = 0x150784u;
label_150784:
    // 0x150784: 0x1052fff4  beq         $v0, $s2, . + 4 + (-0xC << 2)
    ctx->pc = 0x150784u;
    {
        const bool branch_taken_0x150784 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        if (branch_taken_0x150784) {
            ctx->pc = 0x150758u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150758;
        }
    }
    ctx->pc = 0x15078Cu;
label_15078c:
    // 0x15078c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x15078cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150790: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x150790u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x150794: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x150794u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150798: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150798u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15079c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15079cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1507a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1507a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1507a4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1507a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1507a8: 0x805419c  j           func_150670
    ctx->pc = 0x1507A8u;
    ctx->pc = 0x1507ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1507A8u;
            // 0x1507ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1507B0u;
    // 0x1507b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1507B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1506E8u: goto label_1506e8;
            case 0x1506ECu: goto label_1506ec;
            case 0x15071Cu: goto label_15071c;
            case 0x150748u: goto label_150748;
            case 0x150758u: goto label_150758;
            case 0x150760u: goto label_150760;
            case 0x150784u: goto label_150784;
            case 0x15078Cu: goto label_15078c;
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1507B8u;
    // 0x1507b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1507b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1507bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1507bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1507c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1507c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1507c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1507c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1507c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1507c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1507cc: 0xc05578e  jal         func_155E38
    ctx->pc = 0x1507CCu;
    SET_GPR_U32(ctx, 31, 0x1507D4u);
    ctx->pc = 0x1507D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1507CCu;
            // 0x1507d0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1507D4u; }
        if (ctx->pc != 0x1507D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1507D4u; }
        if (ctx->pc != 0x1507D4u) { return; }
    }
    ctx->pc = 0x1507D4u;
label_1507d4:
    // 0x1507d4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1507D4u;
    {
        const bool branch_taken_0x1507d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1507D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1507D4u;
            // 0x1507d8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1507d4) {
            ctx->pc = 0x1507F8u;
            goto label_1507f8;
        }
    }
    ctx->pc = 0x1507DCu;
    // 0x1507dc: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1507dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1507e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1507e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1507e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1507e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1507e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1507e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1507ec: 0x34a5020c  ori         $a1, $a1, 0x20C
    ctx->pc = 0x1507ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)524);
    // 0x1507f0: 0x805419c  j           func_150670
    ctx->pc = 0x1507F0u;
    ctx->pc = 0x1507F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1507F0u;
            // 0x1507f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1507F8u;
label_1507f8:
    // 0x1507f8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1507f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1507fc: 0x26030058  addiu       $v1, $s0, 0x58
    ctx->pc = 0x1507fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 88));
    // 0x150800: 0x651025  or          $v0, $v1, $a1
    ctx->pc = 0x150800u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x150804: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x150804u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x150808: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x150808u;
    {
        const bool branch_taken_0x150808 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15080Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150808u;
            // 0x15080c: 0x26040098  addiu       $a0, $s0, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 152));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150808) {
            ctx->pc = 0x150870u;
            goto label_150870;
        }
    }
    ctx->pc = 0x150810u;
label_150810:
    // 0x150810: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x150810u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x150814: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x150814u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x150818: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x150818u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x15081c: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x15081cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x150820: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x150820u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x150824: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x150824u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x150828: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x150828u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x15082c: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x15082cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x150830: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x150830u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150834: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x150834u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150838: 0xb0a6000f  sdl         $a2, 0xF($a1)
    ctx->pc = 0x150838u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15083c: 0xb4a60008  sdr         $a2, 0x8($a1)
    ctx->pc = 0x15083cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150840: 0xb0a70017  sdl         $a3, 0x17($a1)
    ctx->pc = 0x150840u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150844: 0xb4a70010  sdr         $a3, 0x10($a1)
    ctx->pc = 0x150844u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150848: 0xb0a8001f  sdl         $t0, 0x1F($a1)
    ctx->pc = 0x150848u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15084c: 0xb4a80018  sdr         $t0, 0x18($a1)
    ctx->pc = 0x15084cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150850: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x150850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x150854: 0x0  nop
    ctx->pc = 0x150854u;
    // NOP
    // 0x150858: 0x0  nop
    ctx->pc = 0x150858u;
    // NOP
    // 0x15085c: 0x1464ffec  bne         $v1, $a0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x15085Cu;
    {
        const bool branch_taken_0x15085c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x150860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15085Cu;
            // 0x150860: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15085c) {
            ctx->pc = 0x150810u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150810;
        }
    }
    ctx->pc = 0x150864u;
    // 0x150864: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x150864u;
    {
        const bool branch_taken_0x150864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x150864) {
            ctx->pc = 0x1508A4u;
            goto label_1508a4;
        }
    }
    ctx->pc = 0x15086Cu;
    // 0x15086c: 0x0  nop
    ctx->pc = 0x15086cu;
    // NOP
label_150870:
    // 0x150870: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x150870u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x150874: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x150874u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x150878: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x150878u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x15087c: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x15087cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x150880: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x150880u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x150884: 0xfca60008  sd          $a2, 0x8($a1)
    ctx->pc = 0x150884u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 6));
    // 0x150888: 0xfca70010  sd          $a3, 0x10($a1)
    ctx->pc = 0x150888u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 7));
    // 0x15088c: 0xfca80018  sd          $t0, 0x18($a1)
    ctx->pc = 0x15088cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 8));
    // 0x150890: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x150890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x150894: 0x0  nop
    ctx->pc = 0x150894u;
    // NOP
    // 0x150898: 0x0  nop
    ctx->pc = 0x150898u;
    // NOP
    // 0x15089c: 0x1464fff4  bne         $v1, $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x15089Cu;
    {
        const bool branch_taken_0x15089c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x1508A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15089Cu;
            // 0x1508a0: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15089c) {
            ctx->pc = 0x150870u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150870;
        }
    }
    ctx->pc = 0x1508A4u;
label_1508a4:
    // 0x1508a4: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x1508a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1508a8: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x1508a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1508ac: 0x6864000f  ldl         $a0, 0xF($v1)
    ctx->pc = 0x1508acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1508b0: 0x6c640008  ldr         $a0, 0x8($v1)
    ctx->pc = 0x1508b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1508b4: 0x8c660010  lw          $a2, 0x10($v1)
    ctx->pc = 0x1508b4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1508b8: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x1508b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508bc: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x1508bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508c0: 0xb0a4000f  sdl         $a0, 0xF($a1)
    ctx->pc = 0x1508c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508c4: 0xb4a40008  sdr         $a0, 0x8($a1)
    ctx->pc = 0x1508c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1508c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1508cc: 0xaca60010  sw          $a2, 0x10($a1)
    ctx->pc = 0x1508ccu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 6));
    // 0x1508d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1508d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1508d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1508d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1508d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1508D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1508DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1508D8u;
            // 0x1508dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1506E8u: goto label_1506e8;
            case 0x1506ECu: goto label_1506ec;
            case 0x15071Cu: goto label_15071c;
            case 0x150748u: goto label_150748;
            case 0x150758u: goto label_150758;
            case 0x150760u: goto label_150760;
            case 0x150784u: goto label_150784;
            case 0x15078Cu: goto label_15078c;
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1508E0u;
    // 0x1508e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1508e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1508e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1508e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1508e8: 0x24900128  addiu       $s0, $a0, 0x128
    ctx->pc = 0x1508e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x1508ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1508ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1508f0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1508f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1508f4: 0xc05578e  jal         func_155E38
    ctx->pc = 0x1508F4u;
    SET_GPR_U32(ctx, 31, 0x1508FCu);
    ctx->pc = 0x1508F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1508F4u;
            // 0x1508f8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1508FCu; }
        if (ctx->pc != 0x1508FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1508FCu; }
        if (ctx->pc != 0x1508FCu) { return; }
    }
    ctx->pc = 0x1508FCu;
label_1508fc:
    // 0x1508fc: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1508fcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150900: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x150900u;
    {
        const bool branch_taken_0x150900 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150900u;
            // 0x150904: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150900) {
            ctx->pc = 0x150920u;
            goto label_150920;
        }
    }
    ctx->pc = 0x150908u;
    // 0x150908: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150908u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15090c: 0x34a5020d  ori         $a1, $a1, 0x20D
    ctx->pc = 0x15090cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)525);
    // 0x150910: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150910u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150914: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150914u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150918: 0x805419c  j           func_150670
    ctx->pc = 0x150918u;
    ctx->pc = 0x15091Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150918u;
            // 0x15091c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150920u;
label_150920:
    // 0x150920: 0x8e0202f8  lw          $v0, 0x2F8($s0)
    ctx->pc = 0x150920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 760)));
    // 0x150924: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150928: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x150928u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x15092c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15092cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150930: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150930u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150934: 0x3e00008  jr          $ra
    ctx->pc = 0x150934u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150934u;
            // 0x150938: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1506E8u: goto label_1506e8;
            case 0x1506ECu: goto label_1506ec;
            case 0x15071Cu: goto label_15071c;
            case 0x150748u: goto label_150748;
            case 0x150758u: goto label_150758;
            case 0x150760u: goto label_150760;
            case 0x150784u: goto label_150784;
            case 0x15078Cu: goto label_15078c;
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15093Cu;
    // 0x15093c: 0x0  nop
    ctx->pc = 0x15093cu;
    // NOP
    // 0x150940: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x150940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x150944: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150948: 0x24900128  addiu       $s0, $a0, 0x128
    ctx->pc = 0x150948u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x15094c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15094cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x150950: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x150950u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150954: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x150954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x150958: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x150958u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15095c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15095cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x150960: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x150960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x150964: 0xc05578e  jal         func_155E38
    ctx->pc = 0x150964u;
    SET_GPR_U32(ctx, 31, 0x15096Cu);
    ctx->pc = 0x150968u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150964u;
            // 0x150968: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15096Cu; }
        if (ctx->pc != 0x15096Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15096Cu; }
        if (ctx->pc != 0x15096Cu) { return; }
    }
    ctx->pc = 0x15096Cu;
label_15096c:
    // 0x15096c: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15096cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150970: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x150970u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150974: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x150974u;
    {
        const bool branch_taken_0x150974 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150974u;
            // 0x150978: 0x34a5020f  ori         $a1, $a1, 0x20F (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)527);
        ctx->in_delay_slot = false;
        if (branch_taken_0x150974) {
            ctx->pc = 0x150998u;
            goto label_150998;
        }
    }
    ctx->pc = 0x15097Cu;
    // 0x15097c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15097cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150980: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150980u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150984: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150984u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150988: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x150988u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15098c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15098cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x150990: 0x805419c  j           func_150670
    ctx->pc = 0x150990u;
    ctx->pc = 0x150994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150990u;
            // 0x150994: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150998u;
label_150998:
    // 0x150998: 0x8e0202fc  lw          $v0, 0x2FC($s0)
    ctx->pc = 0x150998u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 764)));
    // 0x15099c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15099cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1509a0: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x1509a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1509a4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1509a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1509a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1509a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1509ac: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1509acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1509b0: 0x8e0300e4  lw          $v1, 0xE4($s0)
    ctx->pc = 0x1509b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 228)));
    // 0x1509b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1509b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1509b8: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x1509b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x1509bc: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x1509bcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x1509c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1509c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1509c4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1509c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1509c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1509C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1509CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1509C8u;
            // 0x1509cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1506E8u: goto label_1506e8;
            case 0x1506ECu: goto label_1506ec;
            case 0x15071Cu: goto label_15071c;
            case 0x150748u: goto label_150748;
            case 0x150758u: goto label_150758;
            case 0x150760u: goto label_150760;
            case 0x150784u: goto label_150784;
            case 0x15078Cu: goto label_15078c;
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1509D0u;
    // 0x1509d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1509d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1509d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1509d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1509d8: 0x24900128  addiu       $s0, $a0, 0x128
    ctx->pc = 0x1509d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x1509dc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1509dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1509e0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1509e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1509e4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1509e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1509e8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1509e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1509ec: 0xc05578e  jal         func_155E38
    ctx->pc = 0x1509ECu;
    SET_GPR_U32(ctx, 31, 0x1509F4u);
    ctx->pc = 0x1509F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1509ECu;
            // 0x1509f0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1509F4u; }
        if (ctx->pc != 0x1509F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1509F4u; }
        if (ctx->pc != 0x1509F4u) { return; }
    }
    ctx->pc = 0x1509F4u;
label_1509f4:
    // 0x1509f4: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1509f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1509f8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1509f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1509fc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1509FCu;
    {
        const bool branch_taken_0x1509fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1509FCu;
            // 0x150a00: 0x34a5020e  ori         $a1, $a1, 0x20E (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)526);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1509fc) {
            ctx->pc = 0x150A20u;
            goto label_150a20;
        }
    }
    ctx->pc = 0x150A04u;
    // 0x150a04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150a04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150a08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150a08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150a0c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150a0cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150a10: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x150a10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x150a14: 0x805419c  j           func_150670
    ctx->pc = 0x150A14u;
    ctx->pc = 0x150A18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150A14u;
            // 0x150a18: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150A1Cu;
    // 0x150a1c: 0x0  nop
    ctx->pc = 0x150a1cu;
    // NOP
label_150a20:
    // 0x150a20: 0x8e0200d0  lw          $v0, 0xD0($s0)
    ctx->pc = 0x150a20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 208)));
    // 0x150a24: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x150a24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x150a28: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x150a28u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x150a2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150a2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150a30: 0x8e0300d4  lw          $v1, 0xD4($s0)
    ctx->pc = 0x150a30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 212)));
    // 0x150a34: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150a34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150a38: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x150a38u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x150a3c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150a3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150a40: 0x3e00008  jr          $ra
    ctx->pc = 0x150A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150A40u;
            // 0x150a44: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1506E8u: goto label_1506e8;
            case 0x1506ECu: goto label_1506ec;
            case 0x15071Cu: goto label_15071c;
            case 0x150748u: goto label_150748;
            case 0x150758u: goto label_150758;
            case 0x150760u: goto label_150760;
            case 0x150784u: goto label_150784;
            case 0x15078Cu: goto label_15078c;
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            case 0x15096Cu: goto label_15096c;
            case 0x150998u: goto label_150998;
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150A48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

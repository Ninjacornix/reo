#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106358
// Address: 0x106358 - 0x106738
void sub_00106358_0x106358(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106358_0x106358");
#endif

    switch (ctx->pc) {
        case 0x1063b8u: goto label_1063b8;
        case 0x1063d8u: goto label_1063d8;
        case 0x1063e0u: goto label_1063e0;
        case 0x106418u: goto label_106418;
        case 0x106460u: goto label_106460;
        case 0x106470u: goto label_106470;
        case 0x1064b0u: goto label_1064b0;
        case 0x1064f4u: goto label_1064f4;
        case 0x106508u: goto label_106508;
        case 0x106538u: goto label_106538;
        case 0x10655cu: goto label_10655c;
        case 0x106598u: goto label_106598;
        case 0x1065a8u: goto label_1065a8;
        case 0x1065dcu: goto label_1065dc;
        case 0x10663cu: goto label_10663c;
        case 0x106650u: goto label_106650;
        case 0x106684u: goto label_106684;
        case 0x1066a8u: goto label_1066a8;
        case 0x1066d4u: goto label_1066d4;
        default: break;
    }

    ctx->pc = 0x106358u;

    // 0x106358: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x106358u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x10635c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10635cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106360: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106360u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106364: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x106364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x106368: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x106368u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10636c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10636cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106370: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x106370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x106374: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x106374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x106378: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x106378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x10637c: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x10637cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x106380: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x106380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x106384: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x106384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x106388: 0x8ed20008  lw          $s2, 0x8($s6)
    ctx->pc = 0x106388u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x10638c: 0x124000df  beqz        $s2, . + 4 + (0xDF << 2)
    ctx->pc = 0x10638Cu;
    {
        const bool branch_taken_0x10638c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x106390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10638Cu;
            // 0x106390: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10638c) {
            ctx->pc = 0x10670Cu;
            goto label_10670c;
        }
    }
    ctx->pc = 0x106394u;
    // 0x106394: 0x9623000c  lhu         $v1, 0xC($s1)
    ctx->pc = 0x106394u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x106398: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x106398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x10639c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10639Cu;
    {
        const bool branch_taken_0x10639c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10639c) {
            ctx->pc = 0x1063B0u;
            goto label_1063b0;
        }
    }
    ctx->pc = 0x1063A4u;
    // 0x1063a4: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x1063a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1063a8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1063A8u;
    {
        const bool branch_taken_0x1063a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1063ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1063A8u;
            // 0x1063ac: 0x30620002  andi        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1063a8) {
            ctx->pc = 0x1063C8u;
            goto label_1063c8;
        }
    }
    ctx->pc = 0x1063B0u;
label_1063b0:
    // 0x1063b0: 0xc043e64  jal         func_10F990
    ctx->pc = 0x1063B0u;
    SET_GPR_U32(ctx, 31, 0x1063B8u);
    ctx->pc = 0x10F990u;
    if (runtime->hasFunction(0x10F990u)) {
        auto targetFn = runtime->lookupFunction(0x10F990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1063B8u; }
        if (ctx->pc != 0x1063B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F990_0x10f990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1063B8u; }
        if (ctx->pc != 0x1063B8u) { return; }
    }
    ctx->pc = 0x1063B8u;
label_1063b8:
    // 0x1063b8: 0x144000d4  bnez        $v0, . + 4 + (0xD4 << 2)
    ctx->pc = 0x1063B8u;
    {
        const bool branch_taken_0x1063b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1063BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1063B8u;
            // 0x1063bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1063b8) {
            ctx->pc = 0x10670Cu;
            goto label_10670c;
        }
    }
    ctx->pc = 0x1063C0u;
    // 0x1063c0: 0x9623000c  lhu         $v1, 0xC($s1)
    ctx->pc = 0x1063c0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1063c4: 0x30620002  andi        $v0, $v1, 0x2
    ctx->pc = 0x1063c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
label_1063c8:
    // 0x1063c8: 0x8ed40000  lw          $s4, 0x0($s6)
    ctx->pc = 0x1063c8u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1063cc: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1063CCu;
    {
        const bool branch_taken_0x1063cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1063D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1063CCu;
            // 0x1063d0: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1063cc) {
            ctx->pc = 0x106448u;
            goto label_106448;
        }
    }
    ctx->pc = 0x1063D4u;
    // 0x1063d4: 0x24150400  addiu       $s5, $zero, 0x400
    ctx->pc = 0x1063d4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_1063d8:
    // 0x1063d8: 0x56400009  bnel        $s2, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1063D8u;
    {
        const bool branch_taken_0x1063d8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x1063d8) {
            ctx->pc = 0x1063DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1063D8u;
            // 0x1063dc: 0x2e430401  sltiu       $v1, $s2, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x106400u;
            goto label_106400;
        }
    }
    ctx->pc = 0x1063E0u;
label_1063e0:
    // 0x1063e0: 0x8e920004  lw          $s2, 0x4($s4)
    ctx->pc = 0x1063e0u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x1063e4: 0x8e930000  lw          $s3, 0x0($s4)
    ctx->pc = 0x1063e4u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1063e8: 0x0  nop
    ctx->pc = 0x1063e8u;
    // NOP
    // 0x1063ec: 0x0  nop
    ctx->pc = 0x1063ecu;
    // NOP
    // 0x1063f0: 0x0  nop
    ctx->pc = 0x1063f0u;
    // NOP
    // 0x1063f4: 0x1240fffa  beqz        $s2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1063F4u;
    {
        const bool branch_taken_0x1063f4 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1063F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1063F4u;
            // 0x1063f8: 0x26940008  addiu       $s4, $s4, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1063f4) {
            ctx->pc = 0x1063E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1063e0;
        }
    }
    ctx->pc = 0x1063FCu;
    // 0x1063fc: 0x2e430401  sltiu       $v1, $s2, 0x401
    ctx->pc = 0x1063fcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
label_106400:
    // 0x106400: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x106400u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x106404: 0x8e24001c  lw          $a0, 0x1C($s1)
    ctx->pc = 0x106404u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x106408: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x106408u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10640c: 0x243300b  movn        $a2, $s2, $v1
    ctx->pc = 0x10640cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 18));
    // 0x106410: 0x40f809  jalr        $v0
    ctx->pc = 0x106410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x106418u);
        ctx->pc = 0x106414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106410u;
            // 0x106414: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x106418u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1063B0u: goto label_1063b0;
            case 0x1063B8u: goto label_1063b8;
            case 0x1063C8u: goto label_1063c8;
            case 0x1063D8u: goto label_1063d8;
            case 0x1063E0u: goto label_1063e0;
            case 0x106400u: goto label_106400;
            case 0x106418u: goto label_106418;
            case 0x106448u: goto label_106448;
            case 0x106460u: goto label_106460;
            case 0x106468u: goto label_106468;
            case 0x106470u: goto label_106470;
            case 0x106490u: goto label_106490;
            case 0x1064B0u: goto label_1064b0;
            case 0x1064C8u: goto label_1064c8;
            case 0x1064F4u: goto label_1064f4;
            case 0x106508u: goto label_106508;
            case 0x106518u: goto label_106518;
            case 0x106538u: goto label_106538;
            case 0x106550u: goto label_106550;
            case 0x10655Cu: goto label_10655c;
            case 0x10656Cu: goto label_10656c;
            case 0x106578u: goto label_106578;
            case 0x106598u: goto label_106598;
            case 0x1065A8u: goto label_1065a8;
            case 0x1065C4u: goto label_1065c4;
            case 0x1065DCu: goto label_1065dc;
            case 0x1065F0u: goto label_1065f0;
            case 0x1065F4u: goto label_1065f4;
            case 0x1065FCu: goto label_1065fc;
            case 0x10663Cu: goto label_10663c;
            case 0x106650u: goto label_106650;
            case 0x106660u: goto label_106660;
            case 0x106664u: goto label_106664;
            case 0x106684u: goto label_106684;
            case 0x106698u: goto label_106698;
            case 0x1066A8u: goto label_1066a8;
            case 0x1066C4u: goto label_1066c4;
            case 0x1066D4u: goto label_1066d4;
            case 0x1066E4u: goto label_1066e4;
            case 0x106700u: goto label_106700;
            case 0x10670Cu: goto label_10670c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x106418u; }
            if (ctx->pc != 0x106418u) { return; }
        }
        }
    }
    ctx->pc = 0x106418u;
label_106418:
    // 0x106418: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x106418u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10641c: 0x5a0000b8  blezl       $s0, . + 4 + (0xB8 << 2)
    ctx->pc = 0x10641Cu;
    {
        const bool branch_taken_0x10641c = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x10641c) {
            ctx->pc = 0x106420u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10641Cu;
            // 0x106420: 0x9623000c  lhu         $v1, 0xC($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106700u;
            goto label_106700;
        }
    }
    ctx->pc = 0x106424u;
    // 0x106424: 0x8ec20008  lw          $v0, 0x8($s6)
    ctx->pc = 0x106424u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x106428: 0x2709821  addu        $s3, $s3, $s0
    ctx->pc = 0x106428u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x10642c: 0x2509023  subu        $s2, $s2, $s0
    ctx->pc = 0x10642cu;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x106430: 0x501023  subu        $v0, $v0, $s0
    ctx->pc = 0x106430u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x106434: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x106434u;
    {
        const bool branch_taken_0x106434 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106434u;
            // 0x106438: 0xaec20008  sw          $v0, 0x8($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106434) {
            ctx->pc = 0x1063D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1063d8;
        }
    }
    ctx->pc = 0x10643Cu;
    // 0x10643c: 0x100000b3  b           . + 4 + (0xB3 << 2)
    ctx->pc = 0x10643Cu;
    {
        const bool branch_taken_0x10643c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10643Cu;
            // 0x106440: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10643c) {
            ctx->pc = 0x10670Cu;
            goto label_10670c;
        }
    }
    ctx->pc = 0x106444u;
    // 0x106444: 0x0  nop
    ctx->pc = 0x106444u;
    // NOP
label_106448:
    // 0x106448: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x106448u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x10644c: 0x14400052  bnez        $v0, . + 4 + (0x52 << 2)
    ctx->pc = 0x10644Cu;
    {
        const bool branch_taken_0x10644c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10644Cu;
            // 0x106450: 0xb82d  daddu       $s7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10644c) {
            ctx->pc = 0x106598u;
            goto label_106598;
        }
    }
    ctx->pc = 0x106454u;
    // 0x106454: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x106454u;
    {
        const bool branch_taken_0x106454 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x106454) {
            ctx->pc = 0x106468u;
            goto label_106468;
        }
    }
    ctx->pc = 0x10645Cu;
    // 0x10645c: 0x0  nop
    ctx->pc = 0x10645cu;
    // NOP
label_106460:
    // 0x106460: 0x9623000c  lhu         $v1, 0xC($s1)
    ctx->pc = 0x106460u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x106464: 0x0  nop
    ctx->pc = 0x106464u;
    // NOP
label_106468:
    // 0x106468: 0x16400009  bnez        $s2, . + 4 + (0x9 << 2)
    ctx->pc = 0x106468u;
    {
        const bool branch_taken_0x106468 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x10646Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106468u;
            // 0x10646c: 0x30620200  andi        $v0, $v1, 0x200 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)512);
        ctx->in_delay_slot = false;
        if (branch_taken_0x106468) {
            ctx->pc = 0x106490u;
            goto label_106490;
        }
    }
    ctx->pc = 0x106470u;
label_106470:
    // 0x106470: 0x8e920004  lw          $s2, 0x4($s4)
    ctx->pc = 0x106470u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x106474: 0x8e930000  lw          $s3, 0x0($s4)
    ctx->pc = 0x106474u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x106478: 0x0  nop
    ctx->pc = 0x106478u;
    // NOP
    // 0x10647c: 0x0  nop
    ctx->pc = 0x10647cu;
    // NOP
    // 0x106480: 0x0  nop
    ctx->pc = 0x106480u;
    // NOP
    // 0x106484: 0x1240fffa  beqz        $s2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x106484u;
    {
        const bool branch_taken_0x106484 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x106488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106484u;
            // 0x106488: 0x26940008  addiu       $s4, $s4, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106484) {
            ctx->pc = 0x106470u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106470;
        }
    }
    ctx->pc = 0x10648Cu;
    // 0x10648c: 0x30620200  andi        $v0, $v1, 0x200
    ctx->pc = 0x10648cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)512);
label_106490:
    // 0x106490: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x106490u;
    {
        const bool branch_taken_0x106490 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106490u;
            // 0x106494: 0x8e300008  lw          $s0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106490) {
            ctx->pc = 0x1064C8u;
            goto label_1064c8;
        }
    }
    ctx->pc = 0x106498u;
    // 0x106498: 0x250102b  sltu        $v0, $s2, $s0
    ctx->pc = 0x106498u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x10649c: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x10649cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1064a0: 0x242800b  movn        $s0, $s2, $v0
    ctx->pc = 0x1064a0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 18));
    // 0x1064a4: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1064a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1064a8: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x1064A8u;
    SET_GPR_U32(ctx, 31, 0x1064B0u);
    ctx->pc = 0x1064ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1064A8u;
            // 0x1064ac: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1064B0u; }
        if (ctx->pc != 0x1064B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1064B0u; }
        if (ctx->pc != 0x1064B0u) { return; }
    }
    ctx->pc = 0x1064B0u;
label_1064b0:
    // 0x1064b0: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x1064b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1064b4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1064b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1064b8: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1064b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1064bc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1064bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1064c0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1064C0u;
    {
        const bool branch_taken_0x1064c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1064C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1064C0u;
            // 0x1064c4: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1064c0) {
            ctx->pc = 0x10656Cu;
            goto label_10656c;
        }
    }
    ctx->pc = 0x1064C8u;
label_1064c8:
    // 0x1064c8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1064c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1064cc: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x1064ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1064d0: 0x44102b  sltu        $v0, $v0, $a0
    ctx->pc = 0x1064d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1064d4: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x1064D4u;
    {
        const bool branch_taken_0x1064d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1064d4) {
            ctx->pc = 0x1064D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1064D4u;
            // 0x1064d8: 0x8e300014  lw          $s0, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106518u;
            goto label_106518;
        }
    }
    ctx->pc = 0x1064DCu;
    // 0x1064dc: 0x212102b  sltu        $v0, $s0, $s2
    ctx->pc = 0x1064dcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x1064e0: 0x5040000d  beql        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x1064E0u;
    {
        const bool branch_taken_0x1064e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1064e0) {
            ctx->pc = 0x1064E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1064E0u;
            // 0x1064e4: 0x8e300014  lw          $s0, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106518u;
            goto label_106518;
        }
    }
    ctx->pc = 0x1064E8u;
    // 0x1064e8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1064e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1064ec: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x1064ECu;
    SET_GPR_U32(ctx, 31, 0x1064F4u);
    ctx->pc = 0x1064F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1064ECu;
            // 0x1064f0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1064F4u; }
        if (ctx->pc != 0x1064F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1064F4u; }
        if (ctx->pc != 0x1064F4u) { return; }
    }
    ctx->pc = 0x1064F4u;
label_1064f4:
    // 0x1064f4: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1064f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1064f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1064f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1064fc: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1064fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x106500: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x106500u;
    SET_GPR_U32(ctx, 31, 0x106508u);
    ctx->pc = 0x106504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106500u;
            // 0x106504: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106508u; }
        if (ctx->pc != 0x106508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106508u; }
        if (ctx->pc != 0x106508u) { return; }
    }
    ctx->pc = 0x106508u;
label_106508:
    // 0x106508: 0x5040001b  beql        $v0, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x106508u;
    {
        const bool branch_taken_0x106508 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x106508) {
            ctx->pc = 0x10650Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106508u;
            // 0x10650c: 0x8ec20008  lw          $v0, 0x8($s6) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106578u;
            goto label_106578;
        }
    }
    ctx->pc = 0x106510u;
    // 0x106510: 0x1000007b  b           . + 4 + (0x7B << 2)
    ctx->pc = 0x106510u;
    {
        const bool branch_taken_0x106510 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106510u;
            // 0x106514: 0x9623000c  lhu         $v1, 0xC($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106510) {
            ctx->pc = 0x106700u;
            goto label_106700;
        }
    }
    ctx->pc = 0x106518u;
label_106518:
    // 0x106518: 0x250102b  sltu        $v0, $s2, $s0
    ctx->pc = 0x106518u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x10651c: 0x5440000c  bnel        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x10651Cu;
    {
        const bool branch_taken_0x10651c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10651c) {
            ctx->pc = 0x106520u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10651Cu;
            // 0x106520: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106550u;
            goto label_106550;
        }
    }
    ctx->pc = 0x106524u;
    // 0x106524: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x106524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x106528: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x106528u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10652c: 0x8e24001c  lw          $a0, 0x1C($s1)
    ctx->pc = 0x10652cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x106530: 0x40f809  jalr        $v0
    ctx->pc = 0x106530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x106538u);
        ctx->pc = 0x106534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106530u;
            // 0x106534: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x106538u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1063B0u: goto label_1063b0;
            case 0x1063B8u: goto label_1063b8;
            case 0x1063C8u: goto label_1063c8;
            case 0x1063D8u: goto label_1063d8;
            case 0x1063E0u: goto label_1063e0;
            case 0x106400u: goto label_106400;
            case 0x106418u: goto label_106418;
            case 0x106448u: goto label_106448;
            case 0x106460u: goto label_106460;
            case 0x106468u: goto label_106468;
            case 0x106470u: goto label_106470;
            case 0x106490u: goto label_106490;
            case 0x1064B0u: goto label_1064b0;
            case 0x1064C8u: goto label_1064c8;
            case 0x1064F4u: goto label_1064f4;
            case 0x106508u: goto label_106508;
            case 0x106518u: goto label_106518;
            case 0x106538u: goto label_106538;
            case 0x106550u: goto label_106550;
            case 0x10655Cu: goto label_10655c;
            case 0x10656Cu: goto label_10656c;
            case 0x106578u: goto label_106578;
            case 0x106598u: goto label_106598;
            case 0x1065A8u: goto label_1065a8;
            case 0x1065C4u: goto label_1065c4;
            case 0x1065DCu: goto label_1065dc;
            case 0x1065F0u: goto label_1065f0;
            case 0x1065F4u: goto label_1065f4;
            case 0x1065FCu: goto label_1065fc;
            case 0x10663Cu: goto label_10663c;
            case 0x106650u: goto label_106650;
            case 0x106660u: goto label_106660;
            case 0x106664u: goto label_106664;
            case 0x106684u: goto label_106684;
            case 0x106698u: goto label_106698;
            case 0x1066A8u: goto label_1066a8;
            case 0x1066C4u: goto label_1066c4;
            case 0x1066D4u: goto label_1066d4;
            case 0x1066E4u: goto label_1066e4;
            case 0x106700u: goto label_106700;
            case 0x10670Cu: goto label_10670c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x106538u; }
            if (ctx->pc != 0x106538u) { return; }
        }
        }
    }
    ctx->pc = 0x106538u;
label_106538:
    // 0x106538: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x106538u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10653c: 0x5e00000e  bgtzl       $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x10653Cu;
    {
        const bool branch_taken_0x10653c = (GPR_S64(ctx, 16) > 0);
        if (branch_taken_0x10653c) {
            ctx->pc = 0x106540u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10653Cu;
            // 0x106540: 0x8ec20008  lw          $v0, 0x8($s6) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106578u;
            goto label_106578;
        }
    }
    ctx->pc = 0x106544u;
    // 0x106544: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x106544u;
    {
        const bool branch_taken_0x106544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106544u;
            // 0x106548: 0x9623000c  lhu         $v1, 0xC($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106544) {
            ctx->pc = 0x106700u;
            goto label_106700;
        }
    }
    ctx->pc = 0x10654Cu;
    // 0x10654c: 0x0  nop
    ctx->pc = 0x10654cu;
    // NOP
label_106550:
    // 0x106550: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x106550u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106554: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x106554u;
    SET_GPR_U32(ctx, 31, 0x10655Cu);
    ctx->pc = 0x106558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106554u;
            // 0x106558: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10655Cu; }
        if (ctx->pc != 0x10655Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10655Cu; }
        if (ctx->pc != 0x10655Cu) { return; }
    }
    ctx->pc = 0x10655Cu;
label_10655c:
    // 0x10655c: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x10655cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x106560: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x106560u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x106564: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x106564u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x106568: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x106568u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_10656c:
    // 0x10656c: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x10656cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x106570: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x106570u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x106574: 0x8ec20008  lw          $v0, 0x8($s6)
    ctx->pc = 0x106574u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
label_106578:
    // 0x106578: 0x2709821  addu        $s3, $s3, $s0
    ctx->pc = 0x106578u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x10657c: 0x2509023  subu        $s2, $s2, $s0
    ctx->pc = 0x10657cu;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x106580: 0x501023  subu        $v0, $v0, $s0
    ctx->pc = 0x106580u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x106584: 0x1440ffb6  bnez        $v0, . + 4 + (-0x4A << 2)
    ctx->pc = 0x106584u;
    {
        const bool branch_taken_0x106584 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106584u;
            // 0x106588: 0xaec20008  sw          $v0, 0x8($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106584) {
            ctx->pc = 0x106460u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106460;
        }
    }
    ctx->pc = 0x10658Cu;
    // 0x10658c: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x10658Cu;
    {
        const bool branch_taken_0x10658c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10658Cu;
            // 0x106590: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10658c) {
            ctx->pc = 0x10670Cu;
            goto label_10670c;
        }
    }
    ctx->pc = 0x106594u;
    // 0x106594: 0x0  nop
    ctx->pc = 0x106594u;
    // NOP
label_106598:
    // 0x106598: 0x1640000a  bnez        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x106598u;
    {
        const bool branch_taken_0x106598 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x106598) {
            ctx->pc = 0x1065C4u;
            goto label_1065c4;
        }
    }
    ctx->pc = 0x1065A0u;
    // 0x1065a0: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x1065a0u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1065a4: 0x0  nop
    ctx->pc = 0x1065a4u;
    // NOP
label_1065a8:
    // 0x1065a8: 0x8e920004  lw          $s2, 0x4($s4)
    ctx->pc = 0x1065a8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x1065ac: 0x8e930000  lw          $s3, 0x0($s4)
    ctx->pc = 0x1065acu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1065b0: 0x0  nop
    ctx->pc = 0x1065b0u;
    // NOP
    // 0x1065b4: 0x0  nop
    ctx->pc = 0x1065b4u;
    // NOP
    // 0x1065b8: 0x0  nop
    ctx->pc = 0x1065b8u;
    // NOP
    // 0x1065bc: 0x1240fffa  beqz        $s2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1065BCu;
    {
        const bool branch_taken_0x1065bc = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1065C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1065BCu;
            // 0x1065c0: 0x26940008  addiu       $s4, $s4, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1065bc) {
            ctx->pc = 0x1065A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1065a8;
        }
    }
    ctx->pc = 0x1065C4u;
label_1065c4:
    // 0x1065c4: 0x56e0000d  bnel        $s7, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x1065C4u;
    {
        const bool branch_taken_0x1065c4 = (GPR_U64(ctx, 23) != GPR_U64(ctx, 0));
        if (branch_taken_0x1065c4) {
            ctx->pc = 0x1065C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1065C4u;
            // 0x1065c8: 0x8e280000  lw          $t0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1065FCu;
            goto label_1065fc;
        }
    }
    ctx->pc = 0x1065CCu;
    // 0x1065cc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1065ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1065d0: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1065d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1065d4: 0xc041e4e  jal         func_107938
    ctx->pc = 0x1065D4u;
    SET_GPR_U32(ctx, 31, 0x1065DCu);
    ctx->pc = 0x1065D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1065D4u;
            // 0x1065d8: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107938u;
    if (runtime->hasFunction(0x107938u)) {
        auto targetFn = runtime->lookupFunction(0x107938u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1065DCu; }
        if (ctx->pc != 0x1065DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107938_0x107938(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1065DCu; }
        if (ctx->pc != 0x1065DCu) { return; }
    }
    ctx->pc = 0x1065DCu;
label_1065dc:
    // 0x1065dc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1065DCu;
    {
        const bool branch_taken_0x1065dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1065E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1065DCu;
            // 0x1065e0: 0x531023  subu        $v0, $v0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1065dc) {
            ctx->pc = 0x1065F0u;
            goto label_1065f0;
        }
    }
    ctx->pc = 0x1065E4u;
    // 0x1065e4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1065E4u;
    {
        const bool branch_taken_0x1065e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1065E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1065E4u;
            // 0x1065e8: 0x24550001  addiu       $s5, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1065e4) {
            ctx->pc = 0x1065F4u;
            goto label_1065f4;
        }
    }
    ctx->pc = 0x1065ECu;
    // 0x1065ec: 0x0  nop
    ctx->pc = 0x1065ecu;
    // NOP
label_1065f0:
    // 0x1065f0: 0x26550001  addiu       $s5, $s2, 0x1
    ctx->pc = 0x1065f0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1065f4:
    // 0x1065f4: 0x24170001  addiu       $s7, $zero, 0x1
    ctx->pc = 0x1065f4u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1065f8: 0x8e280000  lw          $t0, 0x0($s1)
    ctx->pc = 0x1065f8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_1065fc:
    // 0x1065fc: 0x255102b  sltu        $v0, $s2, $s5
    ctx->pc = 0x1065fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 21)) ? 1 : 0);
    // 0x106600: 0x8e230010  lw          $v1, 0x10($s1)
    ctx->pc = 0x106600u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x106604: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x106604u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106608: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x106608u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x10660c: 0x2a2280a  movz        $a1, $s5, $v0
    ctx->pc = 0x10660cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 21));
    // 0x106610: 0x8e270014  lw          $a3, 0x14($s1)
    ctx->pc = 0x106610u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x106614: 0x68182b  sltu        $v1, $v1, $t0
    ctx->pc = 0x106614u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x106618: 0x10600011  beqz        $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x106618u;
    {
        const bool branch_taken_0x106618 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10661Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106618u;
            // 0x10661c: 0x878021  addu        $s0, $a0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106618) {
            ctx->pc = 0x106660u;
            goto label_106660;
        }
    }
    ctx->pc = 0x106620u;
    // 0x106620: 0x205102a  slt         $v0, $s0, $a1
    ctx->pc = 0x106620u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x106624: 0x5040000f  beql        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x106624u;
    {
        const bool branch_taken_0x106624 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x106624) {
            ctx->pc = 0x106628u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106624u;
            // 0x106628: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106664u;
            goto label_106664;
        }
    }
    ctx->pc = 0x10662Cu;
    // 0x10662c: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x10662cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106630: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x106630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106634: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x106634u;
    SET_GPR_U32(ctx, 31, 0x10663Cu);
    ctx->pc = 0x106638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106634u;
            // 0x106638: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10663Cu; }
        if (ctx->pc != 0x10663Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10663Cu; }
        if (ctx->pc != 0x10663Cu) { return; }
    }
    ctx->pc = 0x10663Cu;
label_10663c:
    // 0x10663c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x10663cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x106640: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x106640u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106644: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x106644u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x106648: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x106648u;
    SET_GPR_U32(ctx, 31, 0x106650u);
    ctx->pc = 0x10664Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106648u;
            // 0x10664c: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106650u; }
        if (ctx->pc != 0x106650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106650u; }
        if (ctx->pc != 0x106650u) { return; }
    }
    ctx->pc = 0x106650u;
label_106650:
    // 0x106650: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x106650u;
    {
        const bool branch_taken_0x106650 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106650u;
            // 0x106654: 0x2b0a823  subu        $s5, $s5, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106650) {
            ctx->pc = 0x1066C4u;
            goto label_1066c4;
        }
    }
    ctx->pc = 0x106658u;
    // 0x106658: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x106658u;
    {
        const bool branch_taken_0x106658 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10665Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106658u;
            // 0x10665c: 0x9623000c  lhu         $v1, 0xC($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106658) {
            ctx->pc = 0x106700u;
            goto label_106700;
        }
    }
    ctx->pc = 0x106660u;
label_106660:
    // 0x106660: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x106660u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_106664:
    // 0x106664: 0xb0102a  slt         $v0, $a1, $s0
    ctx->pc = 0x106664u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x106668: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x106668u;
    {
        const bool branch_taken_0x106668 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x106668) {
            ctx->pc = 0x10666Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106668u;
            // 0x10666c: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106698u;
            goto label_106698;
        }
    }
    ctx->pc = 0x106670u;
    // 0x106670: 0x8e220024  lw          $v0, 0x24($s1)
    ctx->pc = 0x106670u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x106674: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x106674u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106678: 0x8e24001c  lw          $a0, 0x1C($s1)
    ctx->pc = 0x106678u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x10667c: 0x40f809  jalr        $v0
    ctx->pc = 0x10667Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x106684u);
        ctx->pc = 0x106680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10667Cu;
            // 0x106680: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x106684u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1063B0u: goto label_1063b0;
            case 0x1063B8u: goto label_1063b8;
            case 0x1063C8u: goto label_1063c8;
            case 0x1063D8u: goto label_1063d8;
            case 0x1063E0u: goto label_1063e0;
            case 0x106400u: goto label_106400;
            case 0x106418u: goto label_106418;
            case 0x106448u: goto label_106448;
            case 0x106460u: goto label_106460;
            case 0x106468u: goto label_106468;
            case 0x106470u: goto label_106470;
            case 0x106490u: goto label_106490;
            case 0x1064B0u: goto label_1064b0;
            case 0x1064C8u: goto label_1064c8;
            case 0x1064F4u: goto label_1064f4;
            case 0x106508u: goto label_106508;
            case 0x106518u: goto label_106518;
            case 0x106538u: goto label_106538;
            case 0x106550u: goto label_106550;
            case 0x10655Cu: goto label_10655c;
            case 0x10656Cu: goto label_10656c;
            case 0x106578u: goto label_106578;
            case 0x106598u: goto label_106598;
            case 0x1065A8u: goto label_1065a8;
            case 0x1065C4u: goto label_1065c4;
            case 0x1065DCu: goto label_1065dc;
            case 0x1065F0u: goto label_1065f0;
            case 0x1065F4u: goto label_1065f4;
            case 0x1065FCu: goto label_1065fc;
            case 0x10663Cu: goto label_10663c;
            case 0x106650u: goto label_106650;
            case 0x106660u: goto label_106660;
            case 0x106664u: goto label_106664;
            case 0x106684u: goto label_106684;
            case 0x106698u: goto label_106698;
            case 0x1066A8u: goto label_1066a8;
            case 0x1066C4u: goto label_1066c4;
            case 0x1066D4u: goto label_1066d4;
            case 0x1066E4u: goto label_1066e4;
            case 0x106700u: goto label_106700;
            case 0x10670Cu: goto label_10670c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x106684u; }
            if (ctx->pc != 0x106684u) { return; }
        }
        }
    }
    ctx->pc = 0x106684u;
label_106684:
    // 0x106684: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x106684u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106688: 0x1e00000e  bgtz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x106688u;
    {
        const bool branch_taken_0x106688 = (GPR_S64(ctx, 16) > 0);
        ctx->pc = 0x10668Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106688u;
            // 0x10668c: 0x2b0a823  subu        $s5, $s5, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106688) {
            ctx->pc = 0x1066C4u;
            goto label_1066c4;
        }
    }
    ctx->pc = 0x106690u;
    // 0x106690: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x106690u;
    {
        const bool branch_taken_0x106690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106690u;
            // 0x106694: 0x9623000c  lhu         $v1, 0xC($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106690) {
            ctx->pc = 0x106700u;
            goto label_106700;
        }
    }
    ctx->pc = 0x106698u;
label_106698:
    // 0x106698: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x106698u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10669c: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x10669cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1066a0: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x1066A0u;
    SET_GPR_U32(ctx, 31, 0x1066A8u);
    ctx->pc = 0x1066A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1066A0u;
            // 0x1066a4: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1066A8u; }
        if (ctx->pc != 0x1066A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1066A8u; }
        if (ctx->pc != 0x1066A8u) { return; }
    }
    ctx->pc = 0x1066A8u;
label_1066a8:
    // 0x1066a8: 0x8e230008  lw          $v1, 0x8($s1)
    ctx->pc = 0x1066a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1066ac: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1066acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1066b0: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1066b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1066b4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1066b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1066b8: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x1066b8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x1066bc: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1066bcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1066c0: 0x2b0a823  subu        $s5, $s5, $s0
    ctx->pc = 0x1066c0u;
    SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 16)));
label_1066c4:
    // 0x1066c4: 0x56a00007  bnel        $s5, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1066C4u;
    {
        const bool branch_taken_0x1066c4 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x1066c4) {
            ctx->pc = 0x1066C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1066C4u;
            // 0x1066c8: 0x8ec20008  lw          $v0, 0x8($s6) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1066E4u;
            goto label_1066e4;
        }
    }
    ctx->pc = 0x1066CCu;
    // 0x1066cc: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x1066CCu;
    SET_GPR_U32(ctx, 31, 0x1066D4u);
    ctx->pc = 0x1066D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1066CCu;
            // 0x1066d0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1066D4u; }
        if (ctx->pc != 0x1066D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1066D4u; }
        if (ctx->pc != 0x1066D4u) { return; }
    }
    ctx->pc = 0x1066D4u;
label_1066d4:
    // 0x1066d4: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x1066D4u;
    {
        const bool branch_taken_0x1066d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1066d4) {
            ctx->pc = 0x1066D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1066D4u;
            // 0x1066d8: 0x9623000c  lhu         $v1, 0xC($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106700u;
            goto label_106700;
        }
    }
    ctx->pc = 0x1066DCu;
    // 0x1066dc: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x1066dcu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1066e0: 0x8ec20008  lw          $v0, 0x8($s6)
    ctx->pc = 0x1066e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
label_1066e4:
    // 0x1066e4: 0x2709821  addu        $s3, $s3, $s0
    ctx->pc = 0x1066e4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x1066e8: 0x2509023  subu        $s2, $s2, $s0
    ctx->pc = 0x1066e8u;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x1066ec: 0x501023  subu        $v0, $v0, $s0
    ctx->pc = 0x1066ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1066f0: 0x1440ffa9  bnez        $v0, . + 4 + (-0x57 << 2)
    ctx->pc = 0x1066F0u;
    {
        const bool branch_taken_0x1066f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1066F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1066F0u;
            // 0x1066f4: 0xaec20008  sw          $v0, 0x8($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1066f0) {
            ctx->pc = 0x106598u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_106598;
        }
    }
    ctx->pc = 0x1066F8u;
    // 0x1066f8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1066F8u;
    {
        const bool branch_taken_0x1066f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1066FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1066F8u;
            // 0x1066fc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1066f8) {
            ctx->pc = 0x10670Cu;
            goto label_10670c;
        }
    }
    ctx->pc = 0x106700u;
label_106700:
    // 0x106700: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x106700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x106704: 0x34630040  ori         $v1, $v1, 0x40
    ctx->pc = 0x106704u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)64);
    // 0x106708: 0xa623000c  sh          $v1, 0xC($s1)
    ctx->pc = 0x106708u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 12), (uint16_t)GPR_U32(ctx, 3));
label_10670c:
    // 0x10670c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10670cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106710: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106710u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106714: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x106714u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106718: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x106718u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10671c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x10671cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x106720: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x106720u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x106724: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x106724u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x106728: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x106728u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10672c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x10672cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x106730: 0x3e00008  jr          $ra
    ctx->pc = 0x106730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106730u;
            // 0x106734: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1063B0u: goto label_1063b0;
            case 0x1063B8u: goto label_1063b8;
            case 0x1063C8u: goto label_1063c8;
            case 0x1063D8u: goto label_1063d8;
            case 0x1063E0u: goto label_1063e0;
            case 0x106400u: goto label_106400;
            case 0x106418u: goto label_106418;
            case 0x106448u: goto label_106448;
            case 0x106460u: goto label_106460;
            case 0x106468u: goto label_106468;
            case 0x106470u: goto label_106470;
            case 0x106490u: goto label_106490;
            case 0x1064B0u: goto label_1064b0;
            case 0x1064C8u: goto label_1064c8;
            case 0x1064F4u: goto label_1064f4;
            case 0x106508u: goto label_106508;
            case 0x106518u: goto label_106518;
            case 0x106538u: goto label_106538;
            case 0x106550u: goto label_106550;
            case 0x10655Cu: goto label_10655c;
            case 0x10656Cu: goto label_10656c;
            case 0x106578u: goto label_106578;
            case 0x106598u: goto label_106598;
            case 0x1065A8u: goto label_1065a8;
            case 0x1065C4u: goto label_1065c4;
            case 0x1065DCu: goto label_1065dc;
            case 0x1065F0u: goto label_1065f0;
            case 0x1065F4u: goto label_1065f4;
            case 0x1065FCu: goto label_1065fc;
            case 0x10663Cu: goto label_10663c;
            case 0x106650u: goto label_106650;
            case 0x106660u: goto label_106660;
            case 0x106664u: goto label_106664;
            case 0x106684u: goto label_106684;
            case 0x106698u: goto label_106698;
            case 0x1066A8u: goto label_1066a8;
            case 0x1066C4u: goto label_1066c4;
            case 0x1066D4u: goto label_1066d4;
            case 0x1066E4u: goto label_1066e4;
            case 0x106700u: goto label_106700;
            case 0x10670Cu: goto label_10670c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106738u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

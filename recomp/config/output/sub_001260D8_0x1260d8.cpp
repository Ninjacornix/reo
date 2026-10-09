#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001260D8
// Address: 0x1260d8 - 0x12626c
void sub_001260D8_0x1260d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001260D8_0x1260d8");
#endif

    switch (ctx->pc) {
        case 0x12610cu: goto label_12610c;
        case 0x12612cu: goto label_12612c;
        case 0x126190u: goto label_126190;
        case 0x1261e8u: goto label_1261e8;
        case 0x12624cu: goto label_12624c;
        default: break;
    }

    ctx->pc = 0x1260d8u;

    // 0x1260d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1260d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1260dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1260dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1260e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1260e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1260e4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1260e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1260e8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1260e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1260ec: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x1260ecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x1260f0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1260f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1260f4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1260f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1260f8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1260f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1260fc: 0x1462004b  bne         $v1, $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x1260FCu;
    {
        const bool branch_taken_0x1260fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x126100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1260FCu;
            // 0x126100: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1260fc) {
            ctx->pc = 0x12622Cu;
            goto label_12622c;
        }
    }
    ctx->pc = 0x126104u;
    // 0x126104: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x126104u;
    SET_GPR_U32(ctx, 31, 0x12610Cu);
    ctx->pc = 0x126108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126104u;
            // 0x126108: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12610Cu; }
        if (ctx->pc != 0x12610Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12610Cu; }
        if (ctx->pc != 0x12610Cu) { return; }
    }
    ctx->pc = 0x12610Cu;
label_12610c:
    // 0x12610c: 0x54400047  bnel        $v0, $zero, . + 4 + (0x47 << 2)
    ctx->pc = 0x12610Cu;
    {
        const bool branch_taken_0x12610c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12610c) {
            ctx->pc = 0x126110u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12610Cu;
            // 0x126110: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12622Cu;
            goto label_12622c;
        }
    }
    ctx->pc = 0x126114u;
    // 0x126114: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x126114u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x126118: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x126118u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x12611c: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x12611cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x126120: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x126120u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x126124: 0x40f809  jalr        $v0
    ctx->pc = 0x126124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12612Cu);
        ctx->pc = 0x126128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126124u;
            // 0x126128: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12612Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12612Cu; }
            if (ctx->pc != 0x12612Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12612Cu;
label_12612c:
    // 0x12612c: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x12612cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x126130: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x126130u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x126134: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x126134u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126138: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x126138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x12613c: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x12613cu;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x126140: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x126140u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x126144: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x126144u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126148: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x126148u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x12614c: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x12614cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x126150: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x126150u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x126154: 0x8e2a0014  lw          $t2, 0x14($s1)
    ctx->pc = 0x126154u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x126158: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x126158u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x12615c: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x12615cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x126160: 0x1435821  addu        $t3, $t2, $v1
    ctx->pc = 0x126160u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x126164: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x126164u;
    {
        const bool branch_taken_0x126164 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x126168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126164u;
            // 0x126168: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126164) {
            ctx->pc = 0x1261D8u;
            goto label_1261d8;
        }
    }
    ctx->pc = 0x12616Cu;
    // 0x12616c: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x12616cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x126170: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x126170u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126174: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x126174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x126178: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x126178u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12617c: 0x19200024  blez        $t1, . + 4 + (0x24 << 2)
    ctx->pc = 0x12617Cu;
    {
        const bool branch_taken_0x12617c = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12617Cu;
            // 0x126180: 0x1426021  addu        $t4, $t2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12617c) {
            ctx->pc = 0x126210u;
            goto label_126210;
        }
    }
    ctx->pc = 0x126184u;
    // 0x126184: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x126184u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126188: 0x340aff80  ori         $t2, $zero, 0xFF80
    ctx->pc = 0x126188u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x12618c: 0x0  nop
    ctx->pc = 0x12618cu;
    // NOP
label_126190:
    // 0x126190: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x126190u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x126194: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x126194u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126198: 0x8b2821  addu        $a1, $a0, $t3
    ctx->pc = 0x126198u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x12619c: 0x8c2021  addu        $a0, $a0, $t4
    ctx->pc = 0x12619cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1261a0: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x1261a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x1261a4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1261a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1261a8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1261a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1261ac: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x1261acu;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1261b0: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1261b0u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1261b4: 0x90e20001  lbu         $v0, 0x1($a3)
    ctx->pc = 0x1261b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1261b8: 0x24e70002  addiu       $a3, $a3, 0x2
    ctx->pc = 0x1261b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2));
    // 0x1261bc: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x1261bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1261c0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1261c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1261c4: 0x14c0fff2  bnez        $a2, . + 4 + (-0xE << 2)
    ctx->pc = 0x1261C4u;
    {
        const bool branch_taken_0x1261c4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1261C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1261C4u;
            // 0x1261c8: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1261c4) {
            ctx->pc = 0x126190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126190;
        }
    }
    ctx->pc = 0x1261CCu;
    // 0x1261cc: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1261CCu;
    {
        const bool branch_taken_0x1261cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1261D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1261CCu;
            // 0x1261d0: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1261cc) {
            ctx->pc = 0x126210u;
            goto label_126210;
        }
    }
    ctx->pc = 0x1261D4u;
    // 0x1261d4: 0x0  nop
    ctx->pc = 0x1261d4u;
    // NOP
label_1261d8:
    // 0x1261d8: 0x1920000d  blez        $t1, . + 4 + (0xD << 2)
    ctx->pc = 0x1261D8u;
    {
        const bool branch_taken_0x1261d8 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1261DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1261D8u;
            // 0x1261dc: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1261d8) {
            ctx->pc = 0x126210u;
            goto label_126210;
        }
    }
    ctx->pc = 0x1261E0u;
    // 0x1261e0: 0x160282d  daddu       $a1, $t3, $zero
    ctx->pc = 0x1261e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1261e4: 0x3406ff80  ori         $a2, $zero, 0xFF80
    ctx->pc = 0x1261e4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
label_1261e8:
    // 0x1261e8: 0x2481021  addu        $v0, $s2, $t0
    ctx->pc = 0x1261e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
    // 0x1261ec: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1261ecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1261f0: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1261f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1261f4: 0x109202a  slt         $a0, $t0, $t1
    ctx->pc = 0x1261f4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1261f8: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1261f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1261fc: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1261fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126200: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x126200u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x126204: 0x1480fff8  bnez        $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x126204u;
    {
        const bool branch_taken_0x126204 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x126208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126204u;
            // 0x126208: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126204) {
            ctx->pc = 0x1261E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1261e8;
        }
    }
    ctx->pc = 0x12620Cu;
    // 0x12620c: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x12620cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_126210:
    // 0x126210: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x126210u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x126214: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x126214u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126218: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x126218u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x12621c: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x12621cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x126220: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x126220u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x126224: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x126224u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x126228: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x126228u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_12622c:
    // 0x12622c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12622cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126230: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x126230u;
    {
        const bool branch_taken_0x126230 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x126230) {
            ctx->pc = 0x126234u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126230u;
            // 0x126234: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126258u;
            goto label_126258;
        }
    }
    ctx->pc = 0x126238u;
    // 0x126238: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x126238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x12623c: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x12623cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x126240: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x126240u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x126244: 0x60f809  jalr        $v1
    ctx->pc = 0x126244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12624Cu);
        ctx->pc = 0x126248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126244u;
            // 0x126248: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12624Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12624Cu; }
            if (ctx->pc != 0x12624Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12624Cu;
label_12624c:
    // 0x12624c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12624cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x126250: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x126250u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x126254: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x126254u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_126258:
    // 0x126258: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x126258u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12625c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12625cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x126260: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x126260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x126264: 0x3e00008  jr          $ra
    ctx->pc = 0x126264u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126264u;
            // 0x126268: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12626Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

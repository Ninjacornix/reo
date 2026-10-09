#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123700
// Address: 0x123700 - 0x123898
void sub_00123700_0x123700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123700_0x123700");
#endif

    switch (ctx->pc) {
        case 0x123734u: goto label_123734;
        case 0x123754u: goto label_123754;
        case 0x1237b0u: goto label_1237b0;
        case 0x123808u: goto label_123808;
        case 0x123878u: goto label_123878;
        default: break;
    }

    ctx->pc = 0x123700u;

    // 0x123700: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x123700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x123704: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123708: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x123708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12370c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12370cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123710: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x123710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x123714: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x123714u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x123718: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x123718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12371c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12371cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x123720: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x123720u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x123724: 0x1462004c  bne         $v1, $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x123724u;
    {
        const bool branch_taken_0x123724 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x123728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123724u;
            // 0x123728: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123724) {
            ctx->pc = 0x123858u;
            goto label_123858;
        }
    }
    ctx->pc = 0x12372Cu;
    // 0x12372c: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x12372Cu;
    SET_GPR_U32(ctx, 31, 0x123734u);
    ctx->pc = 0x123730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12372Cu;
            // 0x123730: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123734u; }
        if (ctx->pc != 0x123734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123734u; }
        if (ctx->pc != 0x123734u) { return; }
    }
    ctx->pc = 0x123734u;
label_123734:
    // 0x123734: 0x54400048  bnel        $v0, $zero, . + 4 + (0x48 << 2)
    ctx->pc = 0x123734u;
    {
        const bool branch_taken_0x123734 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x123734) {
            ctx->pc = 0x123738u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123734u;
            // 0x123738: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123858u;
            goto label_123858;
        }
    }
    ctx->pc = 0x12373Cu;
    // 0x12373c: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x12373cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x123740: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x123740u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x123744: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x123744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x123748: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x123748u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x12374c: 0x40f809  jalr        $v0
    ctx->pc = 0x12374Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x123754u);
        ctx->pc = 0x123750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12374Cu;
            // 0x123750: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x123754u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x123754u; }
            if (ctx->pc != 0x123754u) { return; }
        }
        }
    }
    ctx->pc = 0x123754u;
label_123754:
    // 0x123754: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x123754u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x123758: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x123758u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x12375c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x12375cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x123760: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x123760u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x123764: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x123764u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x123768: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x123768u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x12376c: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x12376cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x123770: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x123770u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x123774: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x123774u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x123778: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x123778u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x12377c: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x12377cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x123780: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x123780u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x123784: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x123784u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x123788: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x123788u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x12378c: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x12378Cu;
    {
        const bool branch_taken_0x12378c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x123790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12378Cu;
            // 0x123790: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12378c) {
            ctx->pc = 0x123800u;
            goto label_123800;
        }
    }
    ctx->pc = 0x123794u;
    // 0x123794: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x123794u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x123798: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x123798u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12379c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x12379cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1237a0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1237a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1237a4: 0x19200024  blez        $t1, . + 4 + (0x24 << 2)
    ctx->pc = 0x1237A4u;
    {
        const bool branch_taken_0x1237a4 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1237A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1237A4u;
            // 0x1237a8: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1237a4) {
            ctx->pc = 0x123838u;
            goto label_123838;
        }
    }
    ctx->pc = 0x1237ACu;
    // 0x1237ac: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1237acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1237b0:
    // 0x1237b0: 0x94e20000  lhu         $v0, 0x0($a3)
    ctx->pc = 0x1237b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1237b4: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x1237b4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1237b8: 0x8a2821  addu        $a1, $a0, $t2
    ctx->pc = 0x1237b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x1237bc: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x1237bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x1237c0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1237c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1237c4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1237c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1237c8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1237c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1237cc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1237ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1237d0: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x1237d0u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1237d4: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x1237d4u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1237d8: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x1237d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x1237dc: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1237dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1237e0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1237e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1237e4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1237e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1237e8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1237e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1237ec: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1237ECu;
    {
        const bool branch_taken_0x1237ec = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1237F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1237ECu;
            // 0x1237f0: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1237ec) {
            ctx->pc = 0x1237B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1237b0;
        }
    }
    ctx->pc = 0x1237F4u;
    // 0x1237f4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1237F4u;
    {
        const bool branch_taken_0x1237f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1237F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1237F4u;
            // 0x1237f8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1237f4) {
            ctx->pc = 0x123838u;
            goto label_123838;
        }
    }
    ctx->pc = 0x1237FCu;
    // 0x1237fc: 0x0  nop
    ctx->pc = 0x1237fcu;
    // NOP
label_123800:
    // 0x123800: 0x1920000d  blez        $t1, . + 4 + (0xD << 2)
    ctx->pc = 0x123800u;
    {
        const bool branch_taken_0x123800 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x123804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123800u;
            // 0x123804: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123800) {
            ctx->pc = 0x123838u;
            goto label_123838;
        }
    }
    ctx->pc = 0x123808u;
label_123808:
    // 0x123808: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x123808u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x12380c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x12380cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x123810: 0x921021  addu        $v0, $a0, $s2
    ctx->pc = 0x123810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x123814: 0x8a2021  addu        $a0, $a0, $t2
    ctx->pc = 0x123814u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x123818: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x123818u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12381c: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x12381cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x123820: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x123820u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123824: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x123824u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x123828: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x123828u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12382c: 0x14a0fff6  bnez        $a1, . + 4 + (-0xA << 2)
    ctx->pc = 0x12382Cu;
    {
        const bool branch_taken_0x12382c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x123830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12382Cu;
            // 0x123830: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12382c) {
            ctx->pc = 0x123808u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_123808;
        }
    }
    ctx->pc = 0x123834u;
    // 0x123834: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x123834u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_123838:
    // 0x123838: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x123838u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x12383c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x12383cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x123840: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x123840u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x123844: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x123844u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x123848: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x123848u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x12384c: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x12384cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x123850: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x123850u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x123854: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x123854u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_123858:
    // 0x123858: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x123858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12385c: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12385Cu;
    {
        const bool branch_taken_0x12385c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12385c) {
            ctx->pc = 0x123860u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12385Cu;
            // 0x123860: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123884u;
            goto label_123884;
        }
    }
    ctx->pc = 0x123864u;
    // 0x123864: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x123864u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x123868: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x123868u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x12386c: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x12386cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x123870: 0x60f809  jalr        $v1
    ctx->pc = 0x123870u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x123878u);
        ctx->pc = 0x123874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123870u;
            // 0x123874: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x123878u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x123878u; }
            if (ctx->pc != 0x123878u) { return; }
        }
        }
    }
    ctx->pc = 0x123878u;
label_123878:
    // 0x123878: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x123878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12387c: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x12387cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x123880: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x123880u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_123884:
    // 0x123884: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x123884u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x123888: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x123888u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12388c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12388cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x123890: 0x3e00008  jr          $ra
    ctx->pc = 0x123890u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123890u;
            // 0x123894: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123898u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

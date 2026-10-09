#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125F60
// Address: 0x125f60 - 0x1260d4
void sub_00125F60_0x125f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125F60_0x125f60");
#endif

    switch (ctx->pc) {
        case 0x125f94u: goto label_125f94;
        case 0x125fb4u: goto label_125fb4;
        case 0x126010u: goto label_126010;
        case 0x126050u: goto label_126050;
        case 0x1260b4u: goto label_1260b4;
        default: break;
    }

    ctx->pc = 0x125f60u;

    // 0x125f60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125f60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x125f64: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x125f64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125f68: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x125f68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125f6c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x125f6cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125f70: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x125f70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x125f74: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x125f74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x125f78: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x125f78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x125f7c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x125f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x125f80: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x125f80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x125f84: 0x14620043  bne         $v1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x125F84u;
    {
        const bool branch_taken_0x125f84 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x125F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125F84u;
            // 0x125f88: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125f84) {
            ctx->pc = 0x126094u;
            goto label_126094;
        }
    }
    ctx->pc = 0x125F8Cu;
    // 0x125f8c: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x125F8Cu;
    SET_GPR_U32(ctx, 31, 0x125F94u);
    ctx->pc = 0x125F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125F8Cu;
            // 0x125f90: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125F94u; }
        if (ctx->pc != 0x125F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125F94u; }
        if (ctx->pc != 0x125F94u) { return; }
    }
    ctx->pc = 0x125F94u;
label_125f94:
    // 0x125f94: 0x5440003f  bnel        $v0, $zero, . + 4 + (0x3F << 2)
    ctx->pc = 0x125F94u;
    {
        const bool branch_taken_0x125f94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125f94) {
            ctx->pc = 0x125F98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125F94u;
            // 0x125f98: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126094u;
            goto label_126094;
        }
    }
    ctx->pc = 0x125F9Cu;
    // 0x125f9c: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x125f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x125fa0: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x125fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x125fa4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x125fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x125fa8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x125fa8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x125fac: 0x40f809  jalr        $v0
    ctx->pc = 0x125FACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x125FB4u);
        ctx->pc = 0x125FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125FACu;
            // 0x125fb0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x125FB4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x125FB4u; }
            if (ctx->pc != 0x125FB4u) { return; }
        }
        }
    }
    ctx->pc = 0x125FB4u;
label_125fb4:
    // 0x125fb4: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x125fb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x125fb8: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x125fb8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x125fbc: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x125fbcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125fc0: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x125fc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x125fc4: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x125fc4u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x125fc8: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x125fc8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x125fcc: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x125fccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125fd0: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x125fd0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x125fd4: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x125fd4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x125fd8: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x125fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x125fdc: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x125fdcu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x125fe0: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x125fe0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125fe4: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x125fe4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x125fe8: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x125fe8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x125fec: 0x14860016  bne         $a0, $a2, . + 4 + (0x16 << 2)
    ctx->pc = 0x125FECu;
    {
        const bool branch_taken_0x125fec = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x125FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125FECu;
            // 0x125ff0: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125fec) {
            ctx->pc = 0x126048u;
            goto label_126048;
        }
    }
    ctx->pc = 0x125FF4u;
    // 0x125ff4: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x125ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x125ff8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x125ff8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125ffc: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x125ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x126000: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x126000u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x126004: 0x1920001b  blez        $t1, . + 4 + (0x1B << 2)
    ctx->pc = 0x126004u;
    {
        const bool branch_taken_0x126004 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126004u;
            // 0x126008: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126004) {
            ctx->pc = 0x126074u;
            goto label_126074;
        }
    }
    ctx->pc = 0x12600Cu;
    // 0x12600c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12600cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_126010:
    // 0x126010: 0x81840  sll         $v1, $t0, 1
    ctx->pc = 0x126010u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126014: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126014u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126018: 0x94e50000  lhu         $a1, 0x0($a3)
    ctx->pc = 0x126018u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12601c: 0x6a2021  addu        $a0, $v1, $t2
    ctx->pc = 0x12601cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x126020: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x126020u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126024: 0x6b1821  addu        $v1, $v1, $t3
    ctx->pc = 0x126024u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x126028: 0xa4850000  sh          $a1, 0x0($a0)
    ctx->pc = 0x126028u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x12602c: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x12602cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x126030: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x126030u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x126034: 0x14c0fff6  bnez        $a2, . + 4 + (-0xA << 2)
    ctx->pc = 0x126034u;
    {
        const bool branch_taken_0x126034 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x126038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126034u;
            // 0x126038: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126034) {
            ctx->pc = 0x126010u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126010;
        }
    }
    ctx->pc = 0x12603Cu;
    // 0x12603c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x12603Cu;
    {
        const bool branch_taken_0x12603c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12603Cu;
            // 0x126040: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12603c) {
            ctx->pc = 0x126074u;
            goto label_126074;
        }
    }
    ctx->pc = 0x126044u;
    // 0x126044: 0x0  nop
    ctx->pc = 0x126044u;
    // NOP
label_126048:
    // 0x126048: 0x1920000a  blez        $t1, . + 4 + (0xA << 2)
    ctx->pc = 0x126048u;
    {
        const bool branch_taken_0x126048 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x12604Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126048u;
            // 0x12604c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126048) {
            ctx->pc = 0x126074u;
            goto label_126074;
        }
    }
    ctx->pc = 0x126050u;
label_126050:
    // 0x126050: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x126050u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126054: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126054u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126058: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x126058u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x12605c: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x12605cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x126060: 0x94640000  lhu         $a0, 0x0($v1)
    ctx->pc = 0x126060u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x126064: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x126064u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126068: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x126068u;
    {
        const bool branch_taken_0x126068 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x12606Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126068u;
            // 0x12606c: 0xa4440000  sh          $a0, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126068) {
            ctx->pc = 0x126050u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126050;
        }
    }
    ctx->pc = 0x126070u;
    // 0x126070: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x126070u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_126074:
    // 0x126074: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x126074u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x126078: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x126078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12607c: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x12607cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x126080: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x126080u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x126084: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x126084u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x126088: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x126088u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x12608c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x12608cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x126090: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x126090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_126094:
    // 0x126094: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x126094u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126098: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x126098u;
    {
        const bool branch_taken_0x126098 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x126098) {
            ctx->pc = 0x12609Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126098u;
            // 0x12609c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1260C0u;
            goto label_1260c0;
        }
    }
    ctx->pc = 0x1260A0u;
    // 0x1260a0: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x1260a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x1260a4: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x1260a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x1260a8: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x1260a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1260ac: 0x60f809  jalr        $v1
    ctx->pc = 0x1260ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1260B4u);
        ctx->pc = 0x1260B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1260ACu;
            // 0x1260b0: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1260B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1260B4u; }
            if (ctx->pc != 0x1260B4u) { return; }
        }
        }
    }
    ctx->pc = 0x1260B4u;
label_1260b4:
    // 0x1260b4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1260b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1260b8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1260b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1260bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1260bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1260c0:
    // 0x1260c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1260c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1260c4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1260c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1260c8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1260c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1260cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1260CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1260D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1260CCu;
            // 0x1260d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1260D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

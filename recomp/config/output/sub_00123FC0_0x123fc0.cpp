#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123FC0
// Address: 0x123fc0 - 0x124158
void sub_00123FC0_0x123fc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123FC0_0x123fc0");
#endif

    switch (ctx->pc) {
        case 0x123ff4u: goto label_123ff4;
        case 0x124014u: goto label_124014;
        case 0x124070u: goto label_124070;
        case 0x1240c8u: goto label_1240c8;
        case 0x124138u: goto label_124138;
        default: break;
    }

    ctx->pc = 0x123fc0u;

    // 0x123fc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x123fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x123fc4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123fc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x123fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x123fcc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x123fccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123fd0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x123fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x123fd4: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x123fd4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x123fd8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x123fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x123fdc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x123fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x123fe0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x123fe0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x123fe4: 0x1462004c  bne         $v1, $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x123FE4u;
    {
        const bool branch_taken_0x123fe4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x123FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123FE4u;
            // 0x123fe8: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123fe4) {
            ctx->pc = 0x124118u;
            goto label_124118;
        }
    }
    ctx->pc = 0x123FECu;
    // 0x123fec: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x123FECu;
    SET_GPR_U32(ctx, 31, 0x123FF4u);
    ctx->pc = 0x123FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123FECu;
            // 0x123ff0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123FF4u; }
        if (ctx->pc != 0x123FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123FF4u; }
        if (ctx->pc != 0x123FF4u) { return; }
    }
    ctx->pc = 0x123FF4u;
label_123ff4:
    // 0x123ff4: 0x54400048  bnel        $v0, $zero, . + 4 + (0x48 << 2)
    ctx->pc = 0x123FF4u;
    {
        const bool branch_taken_0x123ff4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x123ff4) {
            ctx->pc = 0x123FF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123FF4u;
            // 0x123ff8: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124118u;
            goto label_124118;
        }
    }
    ctx->pc = 0x123FFCu;
    // 0x123ffc: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x123ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x124000: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x124000u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x124004: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x124004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x124008: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x124008u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x12400c: 0x40f809  jalr        $v0
    ctx->pc = 0x12400Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x124014u);
        ctx->pc = 0x124010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12400Cu;
            // 0x124010: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124014u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124014u; }
            if (ctx->pc != 0x124014u) { return; }
        }
        }
    }
    ctx->pc = 0x124014u;
label_124014:
    // 0x124014: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x124014u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x124018: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x124018u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x12401c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x12401cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124020: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x124020u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x124024: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x124024u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x124028: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x124028u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x12402c: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x12402cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124030: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x124030u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x124034: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x124034u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x124038: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x124038u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x12403c: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x12403cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x124040: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x124040u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124044: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x124044u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x124048: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x124048u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x12404c: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x12404Cu;
    {
        const bool branch_taken_0x12404c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x124050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12404Cu;
            // 0x124050: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12404c) {
            ctx->pc = 0x1240C0u;
            goto label_1240c0;
        }
    }
    ctx->pc = 0x124054u;
    // 0x124054: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x124054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x124058: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x124058u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12405c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x12405cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x124060: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124060u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x124064: 0x19200024  blez        $t1, . + 4 + (0x24 << 2)
    ctx->pc = 0x124064u;
    {
        const bool branch_taken_0x124064 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x124068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124064u;
            // 0x124068: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124064) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x12406Cu;
    // 0x12406c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12406cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_124070:
    // 0x124070: 0x94e20000  lhu         $v0, 0x0($a3)
    ctx->pc = 0x124070u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x124074: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x124074u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x124078: 0x8a2821  addu        $a1, $a0, $t2
    ctx->pc = 0x124078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x12407c: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x12407cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x124080: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x124080u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x124084: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x124084u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x124088: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x124088u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12408c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x12408cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x124090: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x124090u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x124094: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x124094u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124098: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x124098u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x12409c: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x12409cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1240a0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1240a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1240a4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1240a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1240a8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1240a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1240ac: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1240ACu;
    {
        const bool branch_taken_0x1240ac = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1240B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240ACu;
            // 0x1240b0: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240ac) {
            ctx->pc = 0x124070u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124070;
        }
    }
    ctx->pc = 0x1240B4u;
    // 0x1240b4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1240B4u;
    {
        const bool branch_taken_0x1240b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1240B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240B4u;
            // 0x1240b8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240b4) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x1240BCu;
    // 0x1240bc: 0x0  nop
    ctx->pc = 0x1240bcu;
    // NOP
label_1240c0:
    // 0x1240c0: 0x1920000d  blez        $t1, . + 4 + (0xD << 2)
    ctx->pc = 0x1240C0u;
    {
        const bool branch_taken_0x1240c0 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1240C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240C0u;
            // 0x1240c4: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240c0) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x1240C8u;
label_1240c8:
    // 0x1240c8: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x1240c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1240cc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1240ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1240d0: 0x921021  addu        $v0, $a0, $s2
    ctx->pc = 0x1240d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x1240d4: 0x8a2021  addu        $a0, $a0, $t2
    ctx->pc = 0x1240d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x1240d8: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1240d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1240dc: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x1240dcu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1240e0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1240e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1240e4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1240e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1240e8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1240e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1240ec: 0x14a0fff6  bnez        $a1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1240ECu;
    {
        const bool branch_taken_0x1240ec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1240F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240ECu;
            // 0x1240f0: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240ec) {
            ctx->pc = 0x1240C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1240c8;
        }
    }
    ctx->pc = 0x1240F4u;
    // 0x1240f4: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x1240f4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1240f8:
    // 0x1240f8: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x1240f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1240fc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1240fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124100: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x124100u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x124104: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x124104u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x124108: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x124108u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x12410c: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x12410cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x124110: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124110u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x124114: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x124114u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124118:
    // 0x124118: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12411c: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12411Cu;
    {
        const bool branch_taken_0x12411c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12411c) {
            ctx->pc = 0x124120u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12411Cu;
            // 0x124120: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124144u;
            goto label_124144;
        }
    }
    ctx->pc = 0x124124u;
    // 0x124124: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x124124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x124128: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x124128u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x12412c: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x12412cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x124130: 0x60f809  jalr        $v1
    ctx->pc = 0x124130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124138u);
        ctx->pc = 0x124134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124130u;
            // 0x124134: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124138u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124138u; }
            if (ctx->pc != 0x124138u) { return; }
        }
        }
    }
    ctx->pc = 0x124138u;
label_124138:
    // 0x124138: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x124138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12413c: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x12413cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x124140: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124140u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_124144:
    // 0x124144: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124144u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124148: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124148u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12414c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12414cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124150: 0x3e00008  jr          $ra
    ctx->pc = 0x124150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124150u;
            // 0x124154: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124158u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

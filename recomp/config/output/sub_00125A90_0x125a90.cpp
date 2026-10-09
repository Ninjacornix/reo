#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125A90
// Address: 0x125a90 - 0x125c04
void sub_00125A90_0x125a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125A90_0x125a90");
#endif

    switch (ctx->pc) {
        case 0x125ac4u: goto label_125ac4;
        case 0x125ae4u: goto label_125ae4;
        case 0x125b40u: goto label_125b40;
        case 0x125b80u: goto label_125b80;
        case 0x125be4u: goto label_125be4;
        default: break;
    }

    ctx->pc = 0x125a90u;

    // 0x125a90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125a90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x125a94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x125a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125a98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x125a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125a9c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x125a9cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125aa0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x125aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x125aa4: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x125aa4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x125aa8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x125aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x125aac: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x125aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x125ab0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x125ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x125ab4: 0x14620043  bne         $v1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x125AB4u;
    {
        const bool branch_taken_0x125ab4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x125AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125AB4u;
            // 0x125ab8: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125ab4) {
            ctx->pc = 0x125BC4u;
            goto label_125bc4;
        }
    }
    ctx->pc = 0x125ABCu;
    // 0x125abc: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x125ABCu;
    SET_GPR_U32(ctx, 31, 0x125AC4u);
    ctx->pc = 0x125AC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125ABCu;
            // 0x125ac0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125AC4u; }
        if (ctx->pc != 0x125AC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125AC4u; }
        if (ctx->pc != 0x125AC4u) { return; }
    }
    ctx->pc = 0x125AC4u;
label_125ac4:
    // 0x125ac4: 0x5440003f  bnel        $v0, $zero, . + 4 + (0x3F << 2)
    ctx->pc = 0x125AC4u;
    {
        const bool branch_taken_0x125ac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125ac4) {
            ctx->pc = 0x125AC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125AC4u;
            // 0x125ac8: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125BC4u;
            goto label_125bc4;
        }
    }
    ctx->pc = 0x125ACCu;
    // 0x125acc: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x125accu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x125ad0: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x125ad0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x125ad4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x125ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x125ad8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x125ad8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x125adc: 0x40f809  jalr        $v0
    ctx->pc = 0x125ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x125AE4u);
        ctx->pc = 0x125AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125ADCu;
            // 0x125ae0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x125AE4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x125AE4u; }
            if (ctx->pc != 0x125AE4u) { return; }
        }
        }
    }
    ctx->pc = 0x125AE4u;
label_125ae4:
    // 0x125ae4: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x125ae4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x125ae8: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x125ae8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x125aec: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x125aecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125af0: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x125af0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x125af4: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x125af4u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x125af8: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x125af8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x125afc: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x125afcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b00: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x125b00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x125b04: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x125b04u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x125b08: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x125b08u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x125b0c: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x125b0cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x125b10: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x125b10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b14: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x125b14u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x125b18: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x125b18u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x125b1c: 0x14860016  bne         $a0, $a2, . + 4 + (0x16 << 2)
    ctx->pc = 0x125B1Cu;
    {
        const bool branch_taken_0x125b1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x125B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B1Cu;
            // 0x125b20: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b1c) {
            ctx->pc = 0x125B78u;
            goto label_125b78;
        }
    }
    ctx->pc = 0x125B24u;
    // 0x125b24: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x125b24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x125b28: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x125b28u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125b2c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x125b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x125b30: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x125b30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x125b34: 0x1920001b  blez        $t1, . + 4 + (0x1B << 2)
    ctx->pc = 0x125B34u;
    {
        const bool branch_taken_0x125b34 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x125B38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B34u;
            // 0x125b38: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b34) {
            ctx->pc = 0x125BA4u;
            goto label_125ba4;
        }
    }
    ctx->pc = 0x125B3Cu;
    // 0x125b3c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x125b3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_125b40:
    // 0x125b40: 0x81840  sll         $v1, $t0, 1
    ctx->pc = 0x125b40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x125b44: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x125b44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x125b48: 0x94e50000  lhu         $a1, 0x0($a3)
    ctx->pc = 0x125b48u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x125b4c: 0x6a2021  addu        $a0, $v1, $t2
    ctx->pc = 0x125b4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x125b50: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x125b50u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b54: 0x6b1821  addu        $v1, $v1, $t3
    ctx->pc = 0x125b54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x125b58: 0xa4850000  sh          $a1, 0x0($a0)
    ctx->pc = 0x125b58u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x125b5c: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x125b5cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x125b60: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x125b60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x125b64: 0x14c0fff6  bnez        $a2, . + 4 + (-0xA << 2)
    ctx->pc = 0x125B64u;
    {
        const bool branch_taken_0x125b64 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x125B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B64u;
            // 0x125b68: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b64) {
            ctx->pc = 0x125B40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125b40;
        }
    }
    ctx->pc = 0x125B6Cu;
    // 0x125b6c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x125B6Cu;
    {
        const bool branch_taken_0x125b6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B6Cu;
            // 0x125b70: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b6c) {
            ctx->pc = 0x125BA4u;
            goto label_125ba4;
        }
    }
    ctx->pc = 0x125B74u;
    // 0x125b74: 0x0  nop
    ctx->pc = 0x125b74u;
    // NOP
label_125b78:
    // 0x125b78: 0x1920000a  blez        $t1, . + 4 + (0xA << 2)
    ctx->pc = 0x125B78u;
    {
        const bool branch_taken_0x125b78 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x125B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B78u;
            // 0x125b7c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b78) {
            ctx->pc = 0x125BA4u;
            goto label_125ba4;
        }
    }
    ctx->pc = 0x125B80u;
label_125b80:
    // 0x125b80: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x125b80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x125b84: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x125b84u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x125b88: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x125b88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x125b8c: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x125b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x125b90: 0x94640000  lhu         $a0, 0x0($v1)
    ctx->pc = 0x125b90u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x125b94: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x125b94u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125b98: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x125B98u;
    {
        const bool branch_taken_0x125b98 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x125B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125B98u;
            // 0x125b9c: 0xa4440000  sh          $a0, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125b98) {
            ctx->pc = 0x125B80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125b80;
        }
    }
    ctx->pc = 0x125BA0u;
    // 0x125ba0: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x125ba0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_125ba4:
    // 0x125ba4: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x125ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x125ba8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x125ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125bac: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x125bacu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x125bb0: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x125bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x125bb4: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x125bb4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x125bb8: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x125bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x125bbc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x125bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x125bc0: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x125bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_125bc4:
    // 0x125bc4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x125bc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125bc8: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x125BC8u;
    {
        const bool branch_taken_0x125bc8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x125bc8) {
            ctx->pc = 0x125BCCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125BC8u;
            // 0x125bcc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125BF0u;
            goto label_125bf0;
        }
    }
    ctx->pc = 0x125BD0u;
    // 0x125bd0: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x125bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x125bd4: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x125bd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x125bd8: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x125bd8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x125bdc: 0x60f809  jalr        $v1
    ctx->pc = 0x125BDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x125BE4u);
        ctx->pc = 0x125BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125BDCu;
            // 0x125be0: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x125BE4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x125BE4u; }
            if (ctx->pc != 0x125BE4u) { return; }
        }
        }
    }
    ctx->pc = 0x125BE4u;
label_125be4:
    // 0x125be4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x125be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x125be8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x125be8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x125bec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125becu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_125bf0:
    // 0x125bf0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x125bf0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125bf4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x125bf4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x125bf8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x125bf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x125bfc: 0x3e00008  jr          $ra
    ctx->pc = 0x125BFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125BFCu;
            // 0x125c00: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125AC4u: goto label_125ac4;
            case 0x125AE4u: goto label_125ae4;
            case 0x125B40u: goto label_125b40;
            case 0x125B78u: goto label_125b78;
            case 0x125B80u: goto label_125b80;
            case 0x125BA4u: goto label_125ba4;
            case 0x125BC4u: goto label_125bc4;
            case 0x125BE4u: goto label_125be4;
            case 0x125BF0u: goto label_125bf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125C04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

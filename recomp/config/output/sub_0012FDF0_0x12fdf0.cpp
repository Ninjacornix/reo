#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FDF0
// Address: 0x12fdf0 - 0x12ff5c
void sub_0012FDF0_0x12fdf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FDF0_0x12fdf0");
#endif

    switch (ctx->pc) {
        case 0x12fe28u: goto label_12fe28;
        case 0x12fe58u: goto label_12fe58;
        case 0x12fe84u: goto label_12fe84;
        case 0x12feb8u: goto label_12feb8;
        case 0x12fee4u: goto label_12fee4;
        case 0x12ff10u: goto label_12ff10;
        case 0x12ff24u: goto label_12ff24;
        default: break;
    }

    ctx->pc = 0x12fdf0u;

    // 0x12fdf0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12fdf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12fdf4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12fdf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12fdf8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12fdf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12fdfc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12fdfcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fe00: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x12fe00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x12fe04: 0x263202c8  addiu       $s2, $s1, 0x2C8
    ctx->pc = 0x12fe04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 712));
    // 0x12fe08: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x12fe08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x12fe0c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x12fe0cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fe10: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x12fe10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x12fe14: 0x26300004  addiu       $s0, $s1, 0x4
    ctx->pc = 0x12fe14u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x12fe18: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12fe18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12fe1c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x12FE1Cu;
    {
        const bool branch_taken_0x12fe1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE1Cu;
            // 0x12fe20: 0x8e34000c  lw          $s4, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fe1c) {
            ctx->pc = 0x12FE58u;
            goto label_12fe58;
        }
    }
    ctx->pc = 0x12FE24u;
    // 0x12fe24: 0x0  nop
    ctx->pc = 0x12fe24u;
    // NOP
label_12fe28:
    // 0x12fe28: 0x8e070000  lw          $a3, 0x0($s0)
    ctx->pc = 0x12fe28u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12fe2c: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x12fe2cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x12fe30: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x12fe30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fe34: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x12fe34u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x12fe38: 0x8ce80000  lw          $t0, 0x0($a3)
    ctx->pc = 0x12fe38u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12fe3c: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x12fe3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fe40: 0x94620000  lhu         $v0, 0x0($v1)
    ctx->pc = 0x12fe40u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12fe44: 0xa6420000  sh          $v0, 0x0($s2)
    ctx->pc = 0x12fe44u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fe48: 0xa6420004  sh          $v0, 0x4($s2)
    ctx->pc = 0x12fe48u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fe4c: 0x8d02001c  lw          $v0, 0x1C($t0)
    ctx->pc = 0x12fe4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 28)));
    // 0x12fe50: 0x40f809  jalr        $v0
    ctx->pc = 0x12FE50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12FE58u);
        ctx->pc = 0x12FE54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE50u;
            // 0x12fe54: 0x26520002  addiu       $s2, $s2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12FE58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12FE58u; }
            if (ctx->pc != 0x12FE58u) { return; }
        }
        }
    }
    ctx->pc = 0x12FE58u;
label_12fe58:
    // 0x12fe58: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12fe58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12fe5c: 0x263102a  slt         $v0, $s3, $v1
    ctx->pc = 0x12fe5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12fe60: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x12FE60u;
    {
        const bool branch_taken_0x12fe60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FE64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE60u;
            // 0x12fe64: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fe60) {
            ctx->pc = 0x12FEA4u;
            goto label_12fea4;
        }
    }
    ctx->pc = 0x12FE68u;
    // 0x12fe68: 0x8e080000  lw          $t0, 0x0($s0)
    ctx->pc = 0x12fe68u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12fe6c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12fe6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fe70: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x12fe70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12fe74: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x12fe74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x12fe78: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x12fe78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x12fe7c: 0x60f809  jalr        $v1
    ctx->pc = 0x12FE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12FE84u);
        ctx->pc = 0x12FE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE7Cu;
            // 0x12fe80: 0x100202d  daddu       $a0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12FE84u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12FE84u; }
            if (ctx->pc != 0x12FE84u) { return; }
        }
        }
    }
    ctx->pc = 0x12FE84u;
label_12fe84:
    // 0x12fe84: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12fe84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fe88: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x12fe88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12fe8c: 0x1440ffe6  bnez        $v0, . + 4 + (-0x1A << 2)
    ctx->pc = 0x12FE8Cu;
    {
        const bool branch_taken_0x12fe8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE8Cu;
            // 0x12fe90: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fe8c) {
            ctx->pc = 0x12FE28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12fe28;
        }
    }
    ctx->pc = 0x12FE94u;
    // 0x12fe94: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12fe94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12fe98: 0x263102a  slt         $v0, $s3, $v1
    ctx->pc = 0x12fe98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12fe9c: 0x54400028  bnel        $v0, $zero, . + 4 + (0x28 << 2)
    ctx->pc = 0x12FE9Cu;
    {
        const bool branch_taken_0x12fe9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12fe9c) {
            ctx->pc = 0x12FEA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FE9Cu;
            // 0x12fea0: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FF40u;
            goto label_12ff40;
        }
    }
    ctx->pc = 0x12FEA4u;
label_12fea4:
    // 0x12fea4: 0x5860000d  blezl       $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x12FEA4u;
    {
        const bool branch_taken_0x12fea4 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x12fea4) {
            ctx->pc = 0x12FEA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEA4u;
            // 0x12fea8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FEDCu;
            goto label_12fedc;
        }
    }
    ctx->pc = 0x12FEACu;
    // 0x12feac: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x12feacu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12feb0: 0x26230088  addiu       $v1, $s1, 0x88
    ctx->pc = 0x12feb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 136));
    // 0x12feb4: 0x2624008c  addiu       $a0, $s1, 0x8C
    ctx->pc = 0x12feb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
label_12feb8:
    // 0x12feb8: 0x94620240  lhu         $v0, 0x240($v1)
    ctx->pc = 0x12feb8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 576)));
    // 0x12febc: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x12febcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x12fec0: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x12fec0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fec4: 0x24630002  addiu       $v1, $v1, 0x2
    ctx->pc = 0x12fec4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
    // 0x12fec8: 0x94820240  lhu         $v0, 0x240($a0)
    ctx->pc = 0x12fec8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 576)));
    // 0x12fecc: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x12feccu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fed0: 0x1660fff9  bnez        $s3, . + 4 + (-0x7 << 2)
    ctx->pc = 0x12FED0u;
    {
        const bool branch_taken_0x12fed0 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FED0u;
            // 0x12fed4: 0x24840002  addiu       $a0, $a0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fed0) {
            ctx->pc = 0x12FEB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12feb8;
        }
    }
    ctx->pc = 0x12FED8u;
    // 0x12fed8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12fed8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12fedc:
    // 0x12fedc: 0xc04bc24  jal         func_12F090
    ctx->pc = 0x12FEDCu;
    SET_GPR_U32(ctx, 31, 0x12FEE4u);
    ctx->pc = 0x12FEE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEDCu;
            // 0x12fee0: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12F090u;
    if (runtime->hasFunction(0x12F090u)) {
        auto targetFn = runtime->lookupFunction(0x12F090u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FEE4u; }
        if (ctx->pc != 0x12FEE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012F090_0x12f090(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FEE4u; }
        if (ctx->pc != 0x12FEE4u) { return; }
    }
    ctx->pc = 0x12FEE4u;
label_12fee4:
    // 0x12fee4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12fee4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fee8: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x12FEE8u;
    {
        const bool branch_taken_0x12fee8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEE8u;
            // 0x12feec: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fee8) {
            ctx->pc = 0x12FF3Cu;
            goto label_12ff3c;
        }
    }
    ctx->pc = 0x12FEF0u;
    // 0x12fef0: 0x8e22002c  lw          $v0, 0x2C($s1)
    ctx->pc = 0x12fef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
    // 0x12fef4: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12fef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12fef8: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12fef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12fefc: 0x1860000d  blez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x12FEFCu;
    {
        const bool branch_taken_0x12fefc = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12FF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FEFCu;
            // 0x12ff00: 0xae22002c  sw          $v0, 0x2C($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fefc) {
            ctx->pc = 0x12FF34u;
            goto label_12ff34;
        }
    }
    ctx->pc = 0x12FF04u;
    // 0x12ff04: 0x26300080  addiu       $s0, $s1, 0x80
    ctx->pc = 0x12ff04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x12ff08: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12ff08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12ff0c: 0x0  nop
    ctx->pc = 0x12ff0cu;
    // NOP
label_12ff10:
    // 0x12ff10: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x12ff10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x12ff14: 0x8e250064  lw          $a1, 0x64($s1)
    ctx->pc = 0x12ff14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 100)));
    // 0x12ff18: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x12ff18u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x12ff1c: 0xc04b8da  jal         func_12E368
    ctx->pc = 0x12FF1Cu;
    SET_GPR_U32(ctx, 31, 0x12FF24u);
    ctx->pc = 0x12FF20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF1Cu;
            // 0x12ff20: 0x8e26005c  lw          $a2, 0x5C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 92)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E368u;
    if (runtime->hasFunction(0x12E368u)) {
        auto targetFn = runtime->lookupFunction(0x12E368u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FF24u; }
        if (ctx->pc != 0x12FF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E368_0x12e368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FF24u; }
        if (ctx->pc != 0x12FF24u) { return; }
    }
    ctx->pc = 0x12FF24u;
label_12ff24:
    // 0x12ff24: 0x8e220058  lw          $v0, 0x58($s1)
    ctx->pc = 0x12ff24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12ff28: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x12ff28u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12ff2c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12FF2Cu;
    {
        const bool branch_taken_0x12ff2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ff2c) {
            ctx->pc = 0x12FF30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF2Cu;
            // 0x12ff30: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FF10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ff10;
        }
    }
    ctx->pc = 0x12FF34u;
label_12ff34:
    // 0x12ff34: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12ff34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12ff38: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x12ff38u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
label_12ff3c:
    // 0x12ff3c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12ff3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_12ff40:
    // 0x12ff40: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12ff40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ff44: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x12ff44u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ff48: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x12ff48u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ff4c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x12ff4cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ff50: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12ff50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12ff54: 0x3e00008  jr          $ra
    ctx->pc = 0x12FF54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FF58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF54u;
            // 0x12ff58: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FE28u: goto label_12fe28;
            case 0x12FE58u: goto label_12fe58;
            case 0x12FE84u: goto label_12fe84;
            case 0x12FEA4u: goto label_12fea4;
            case 0x12FEB8u: goto label_12feb8;
            case 0x12FEDCu: goto label_12fedc;
            case 0x12FEE4u: goto label_12fee4;
            case 0x12FF10u: goto label_12ff10;
            case 0x12FF24u: goto label_12ff24;
            case 0x12FF34u: goto label_12ff34;
            case 0x12FF3Cu: goto label_12ff3c;
            case 0x12FF40u: goto label_12ff40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FF5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

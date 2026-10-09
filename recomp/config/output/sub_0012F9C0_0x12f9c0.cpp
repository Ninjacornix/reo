#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012F9C0
// Address: 0x12f9c0 - 0x12fae8
void sub_0012F9C0_0x12f9c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012F9C0_0x12f9c0");
#endif

    switch (ctx->pc) {
        case 0x12f9f8u: goto label_12f9f8;
        case 0x12fa28u: goto label_12fa28;
        case 0x12fa4cu: goto label_12fa4c;
        case 0x12fa50u: goto label_12fa50;
        case 0x12fa78u: goto label_12fa78;
        case 0x12fa94u: goto label_12fa94;
        default: break;
    }

    ctx->pc = 0x12f9c0u;

    // 0x12f9c0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12f9c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12f9c4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12f9c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12f9c8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12f9c8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f9cc: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x12f9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x12f9d0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12f9d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12f9d4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x12f9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x12f9d8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x12f9d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x12f9dc: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x12f9dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x12f9e0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x12f9e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x12f9e4: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12f9e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x12f9e8: 0x1860002f  blez        $v1, . + 4 + (0x2F << 2)
    ctx->pc = 0x12F9E8u;
    {
        const bool branch_taken_0x12f9e8 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x12F9ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12F9E8u;
            // 0x12f9ec: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12f9e8) {
            ctx->pc = 0x12FAA8u;
            goto label_12faa8;
        }
    }
    ctx->pc = 0x12F9F0u;
    // 0x12f9f0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x12f9f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f9f4: 0x0  nop
    ctx->pc = 0x12f9f4u;
    // NOP
label_12f9f8:
    // 0x12f9f8: 0x8e220068  lw          $v0, 0x68($s1)
    ctx->pc = 0x12f9f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 104)));
    // 0x12f9fc: 0x28040  sll         $s0, $v0, 1
    ctx->pc = 0x12f9fcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12fa00: 0x1a000025  blez        $s0, . + 4 + (0x25 << 2)
    ctx->pc = 0x12FA00u;
    {
        const bool branch_taken_0x12fa00 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x12FA04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FA00u;
            // 0x12fa04: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fa00) {
            ctx->pc = 0x12FA98u;
            goto label_12fa98;
        }
    }
    ctx->pc = 0x12FA08u;
    // 0x12fa08: 0x26330004  addiu       $s3, $s1, 0x4
    ctx->pc = 0x12fa08u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x12fa0c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12fa0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fa10: 0x2749021  addu        $s2, $s3, $s4
    ctx->pc = 0x12fa10u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
    // 0x12fa14: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x12fa14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12fa18: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12fa18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12fa1c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x12fa1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x12fa20: 0x40f809  jalr        $v0
    ctx->pc = 0x12FA20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12FA28u);
        ctx->pc = 0x12FA24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FA20u;
            // 0x12fa24: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12FA28u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F9F8u: goto label_12f9f8;
            case 0x12FA28u: goto label_12fa28;
            case 0x12FA4Cu: goto label_12fa4c;
            case 0x12FA50u: goto label_12fa50;
            case 0x12FA70u: goto label_12fa70;
            case 0x12FA78u: goto label_12fa78;
            case 0x12FA94u: goto label_12fa94;
            case 0x12FA98u: goto label_12fa98;
            case 0x12FAA8u: goto label_12faa8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12FA28u; }
            if (ctx->pc != 0x12FA28u) { return; }
        }
        }
    }
    ctx->pc = 0x12FA28u;
label_12fa28:
    // 0x12fa28: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12fa28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fa2c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x12fa2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12fa30: 0x1050000f  beq         $v0, $s0, . + 4 + (0xF << 2)
    ctx->pc = 0x12FA30u;
    {
        const bool branch_taken_0x12fa30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x12FA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FA30u;
            // 0x12fa34: 0x40302d  daddu       $a2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fa30) {
            ctx->pc = 0x12FA70u;
            goto label_12fa70;
        }
    }
    ctx->pc = 0x12FA38u;
    // 0x12fa38: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x12fa38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12fa3c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12fa3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12fa40: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12fa40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12fa44: 0x40f809  jalr        $v0
    ctx->pc = 0x12FA44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12FA4Cu);
        ctx->pc = 0x12FA48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FA44u;
            // 0x12fa48: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12FA4Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F9F8u: goto label_12f9f8;
            case 0x12FA28u: goto label_12fa28;
            case 0x12FA4Cu: goto label_12fa4c;
            case 0x12FA50u: goto label_12fa50;
            case 0x12FA70u: goto label_12fa70;
            case 0x12FA78u: goto label_12fa78;
            case 0x12FA94u: goto label_12fa94;
            case 0x12FA98u: goto label_12fa98;
            case 0x12FAA8u: goto label_12faa8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12FA4Cu; }
            if (ctx->pc != 0x12FA4Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12FA4Cu;
label_12fa4c:
    // 0x12fa4c: 0x0  nop
    ctx->pc = 0x12fa4cu;
    // NOP
label_12fa50:
    // 0x12fa50: 0x0  nop
    ctx->pc = 0x12fa50u;
    // NOP
    // 0x12fa54: 0x0  nop
    ctx->pc = 0x12fa54u;
    // NOP
    // 0x12fa58: 0x0  nop
    ctx->pc = 0x12fa58u;
    // NOP
    // 0x12fa5c: 0x0  nop
    ctx->pc = 0x12fa5cu;
    // NOP
    // 0x12fa60: 0x0  nop
    ctx->pc = 0x12fa60u;
    // NOP
    // 0x12fa64: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x12FA64u;
    {
        const bool branch_taken_0x12fa64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12fa64) {
            ctx->pc = 0x12FA50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12fa50;
        }
    }
    ctx->pc = 0x12FA6Cu;
    // 0x12fa6c: 0x0  nop
    ctx->pc = 0x12fa6cu;
    // NOP
label_12fa70:
    // 0x12fa70: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12FA70u;
    SET_GPR_U32(ctx, 31, 0x12FA78u);
    ctx->pc = 0x12FA74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FA70u;
            // 0x12fa74: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FA78u; }
        if (ctx->pc != 0x12FA78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FA78u; }
        if (ctx->pc != 0x12FA78u) { return; }
    }
    ctx->pc = 0x12FA78u;
label_12fa78:
    // 0x12fa78: 0x2741821  addu        $v1, $s3, $s4
    ctx->pc = 0x12fa78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
    // 0x12fa7c: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x12fa7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12fa80: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12fa80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fa84: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12fa84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12fa88: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12fa88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12fa8c: 0x40f809  jalr        $v0
    ctx->pc = 0x12FA8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12FA94u);
        ctx->pc = 0x12FA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FA8Cu;
            // 0x12fa90: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12FA94u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F9F8u: goto label_12f9f8;
            case 0x12FA28u: goto label_12fa28;
            case 0x12FA4Cu: goto label_12fa4c;
            case 0x12FA50u: goto label_12fa50;
            case 0x12FA70u: goto label_12fa70;
            case 0x12FA78u: goto label_12fa78;
            case 0x12FA94u: goto label_12fa94;
            case 0x12FA98u: goto label_12fa98;
            case 0x12FAA8u: goto label_12faa8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12FA94u; }
            if (ctx->pc != 0x12FA94u) { return; }
        }
        }
    }
    ctx->pc = 0x12FA94u;
label_12fa94:
    // 0x12fa94: 0x8e230058  lw          $v1, 0x58($s1)
    ctx->pc = 0x12fa94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 88)));
label_12fa98:
    // 0x12fa98: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x12fa98u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x12fa9c: 0x2a3102a  slt         $v0, $s5, $v1
    ctx->pc = 0x12fa9cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12faa0: 0x1440ffd5  bnez        $v0, . + 4 + (-0x2B << 2)
    ctx->pc = 0x12FAA0u;
    {
        const bool branch_taken_0x12faa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FAA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FAA0u;
            // 0x12faa4: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12faa0) {
            ctx->pc = 0x12F9F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12f9f8;
        }
    }
    ctx->pc = 0x12FAA8u;
label_12faa8:
    // 0x12faa8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12faa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12faac: 0xae200028  sw          $zero, 0x28($s1)
    ctx->pc = 0x12faacu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 0));
    // 0x12fab0: 0xa2220001  sb          $v0, 0x1($s1)
    ctx->pc = 0x12fab0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12fab4: 0xae20002c  sw          $zero, 0x2C($s1)
    ctx->pc = 0x12fab4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 0));
    // 0x12fab8: 0xae200030  sw          $zero, 0x30($s1)
    ctx->pc = 0x12fab8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 0));
    // 0x12fabc: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x12fabcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x12fac0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12fac0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12fac4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12fac4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12fac8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x12fac8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12facc: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x12faccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12fad0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x12fad0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12fad4: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x12fad4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12fad8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x12fad8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12fadc: 0x3e00008  jr          $ra
    ctx->pc = 0x12FADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FADCu;
            // 0x12fae0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12F9F8u: goto label_12f9f8;
            case 0x12FA28u: goto label_12fa28;
            case 0x12FA4Cu: goto label_12fa4c;
            case 0x12FA50u: goto label_12fa50;
            case 0x12FA70u: goto label_12fa70;
            case 0x12FA78u: goto label_12fa78;
            case 0x12FA94u: goto label_12fa94;
            case 0x12FA98u: goto label_12fa98;
            case 0x12FAA8u: goto label_12faa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FAE4u;
    // 0x12fae4: 0x0  nop
    ctx->pc = 0x12fae4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

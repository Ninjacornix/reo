#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CEB8
// Address: 0x12ceb8 - 0x12cfd8
void sub_0012CEB8_0x12ceb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CEB8_0x12ceb8");
#endif

    switch (ctx->pc) {
        case 0x12cf08u: goto label_12cf08;
        case 0x12cf20u: goto label_12cf20;
        case 0x12cf28u: goto label_12cf28;
        case 0x12cf4cu: goto label_12cf4c;
        default: break;
    }

    ctx->pc = 0x12ceb8u;

    // 0x12ceb8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12ceb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12cebc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12cebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12cec0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12cec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12cec4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12cec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12cec8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12cec8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cecc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ceccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ced0: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x12ced0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ced4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12ced4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12ced8: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x12ced8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cedc: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12cedcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12cee0: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x12cee0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cee4: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x12cee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x12cee8: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x12cee8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ceec: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12ceecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12cef0: 0x2651001c  addiu       $s1, $s2, 0x1C
    ctx->pc = 0x12cef0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 28));
    // 0x12cef4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x12cef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x12cef8: 0x2650000c  addiu       $s0, $s2, 0xC
    ctx->pc = 0x12cef8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
    // 0x12cefc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x12CEFCu;
    {
        const bool branch_taken_0x12cefc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CEFCu;
            // 0x12cf00: 0x8e54000c  lw          $s4, 0xC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cefc) {
            ctx->pc = 0x12CF20u;
            goto label_12cf20;
        }
    }
    ctx->pc = 0x12CF04u;
    // 0x12cf04: 0x0  nop
    ctx->pc = 0x12cf04u;
    // NOP
label_12cf08:
    // 0x12cf08: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12cf08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12cf0c: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x12cf0cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x12cf10: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x12cf10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12cf14: 0x8c680018  lw          $t0, 0x18($v1)
    ctx->pc = 0x12cf14u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x12cf18: 0x100f809  jalr        $t0
    ctx->pc = 0x12CF18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 8);
        SET_GPR_U32(ctx, 31, 0x12CF20u);
        ctx->pc = 0x12CF1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CF18u;
            // 0x12cf1c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12CF20u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CF08u: goto label_12cf08;
            case 0x12CF20u: goto label_12cf20;
            case 0x12CF28u: goto label_12cf28;
            case 0x12CF4Cu: goto label_12cf4c;
            case 0x12CFA0u: goto label_12cfa0;
            case 0x12CFA4u: goto label_12cfa4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12CF20u; }
            if (ctx->pc != 0x12CF20u) { return; }
        }
        }
    }
    ctx->pc = 0x12CF20u;
label_12cf20:
    // 0x12cf20: 0xc04939e  jal         func_124E78
    ctx->pc = 0x12CF20u;
    SET_GPR_U32(ctx, 31, 0x12CF28u);
    ctx->pc = 0x12CF24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CF20u;
            // 0x12cf24: 0x8e440004  lw          $a0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E78u;
    if (runtime->hasFunction(0x124E78u)) {
        auto targetFn = runtime->lookupFunction(0x124E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CF28u; }
        if (ctx->pc != 0x12CF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E78_0x124e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CF28u; }
        if (ctx->pc != 0x12CF28u) { return; }
    }
    ctx->pc = 0x12CF28u;
label_12cf28:
    // 0x12cf28: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12cf28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cf2c: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x12cf2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12cf30: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x12cf30u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x12cf34: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x12cf34u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cf38: 0x26310008  addiu       $s1, $s1, 0x8
    ctx->pc = 0x12cf38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x12cf3c: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x12CF3Cu;
    {
        const bool branch_taken_0x12cf3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12CF40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CF3Cu;
            // 0x12cf40: 0x24064000  addiu       $a2, $zero, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cf3c) {
            ctx->pc = 0x12CF08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12cf08;
        }
    }
    ctx->pc = 0x12CF44u;
    // 0x12cf44: 0xc04ffee  jal         func_13FFB8
    ctx->pc = 0x12CF44u;
    SET_GPR_U32(ctx, 31, 0x12CF4Cu);
    ctx->pc = 0x12CF48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CF44u;
            // 0x12cf48: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFB8u;
    if (runtime->hasFunction(0x13FFB8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CF4Cu; }
        if (ctx->pc != 0x12CF4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFB8_0x13ffb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CF4Cu; }
        if (ctx->pc != 0x12CF4Cu) { return; }
    }
    ctx->pc = 0x12CF4Cu;
label_12cf4c:
    // 0x12cf4c: 0x8e43001c  lw          $v1, 0x1C($s2)
    ctx->pc = 0x12cf4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x12cf50: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x12cf50u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12cf54: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x12cf54u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x12cf58: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x12cf58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x12cf5c: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x12cf5cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x12cf60: 0xaec30000  sw          $v1, 0x0($s6)
    ctx->pc = 0x12cf60u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 3));
    // 0x12cf64: 0x8e420020  lw          $v0, 0x20($s2)
    ctx->pc = 0x12cf64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x12cf68: 0x8e440038  lw          $a0, 0x38($s2)
    ctx->pc = 0x12cf68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0x12cf6c: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x12cf6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x12cf70: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x12cf70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12cf74: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x12cf74u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x12cf78: 0x44182a  slt         $v1, $v0, $a0
    ctx->pc = 0x12cf78u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x12cf7c: 0x43200b  movn        $a0, $v0, $v1
    ctx->pc = 0x12cf7cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
    // 0x12cf80: 0xaee40000  sw          $a0, 0x0($s7)
    ctx->pc = 0x12cf80u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 4));
    // 0x12cf84: 0x8e43003c  lw          $v1, 0x3C($s2)
    ctx->pc = 0x12cf84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
    // 0x12cf88: 0x4620005  bltzl       $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12CF88u;
    {
        const bool branch_taken_0x12cf88 = (GPR_S64(ctx, 3) < 0);
        if (branch_taken_0x12cf88) {
            ctx->pc = 0x12CF8Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12CF88u;
            // 0x12cf8c: 0x3c021fff  lui         $v0, 0x1FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8191 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12CFA0u;
            goto label_12cfa0;
        }
    }
    ctx->pc = 0x12CF90u;
    // 0x12cf90: 0x8e420040  lw          $v0, 0x40($s2)
    ctx->pc = 0x12cf90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 64)));
    // 0x12cf94: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12CF94u;
    {
        const bool branch_taken_0x12cf94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CF98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CF94u;
            // 0x12cf98: 0x621023  subu        $v0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cf94) {
            ctx->pc = 0x12CFA4u;
            goto label_12cfa4;
        }
    }
    ctx->pc = 0x12CF9Cu;
    // 0x12cf9c: 0x0  nop
    ctx->pc = 0x12cf9cu;
    // NOP
label_12cfa0:
    // 0x12cfa0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x12cfa0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_12cfa4:
    // 0x12cfa4: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x12cfa4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
    // 0x12cfa8: 0x8e440004  lw          $a0, 0x4($s2)
    ctx->pc = 0x12cfa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x12cfac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12cfacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cfb0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12cfb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12cfb4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12cfb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12cfb8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12cfb8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12cfbc: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12cfbcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12cfc0: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12cfc0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12cfc4: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12cfc4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12cfc8: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x12cfc8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12cfcc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x12cfccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12cfd0: 0x8049398  j           func_124E60
    ctx->pc = 0x12CFD0u;
    ctx->pc = 0x12CFD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CFD0u;
            // 0x12cfd4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E60u;
    if (runtime->hasFunction(0x124E60u)) {
        auto targetFn = runtime->lookupFunction(0x124E60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124E60_0x124e60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12CFD8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

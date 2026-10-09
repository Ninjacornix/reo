#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012EDB0
// Address: 0x12edb0 - 0x12eee0
void sub_0012EDB0_0x12edb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012EDB0_0x12edb0");
#endif

    switch (ctx->pc) {
        case 0x12edf8u: goto label_12edf8;
        case 0x12ee70u: goto label_12ee70;
        case 0x12ee88u: goto label_12ee88;
        case 0x12eea4u: goto label_12eea4;
        default: break;
    }

    ctx->pc = 0x12edb0u;

    // 0x12edb0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12edb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12edb4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x12edb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x12edb8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12edb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12edbc: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x12edbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x12edc0: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x12edc0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12edc4: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x12edc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x12edc8: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x12edc8u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12edcc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12edccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12edd0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12edd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x12edd4: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x12edd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x12edd8: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x12edd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x12eddc: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x12eddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x12ede0: 0x8e420058  lw          $v0, 0x58($s2)
    ctx->pc = 0x12ede0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 88)));
    // 0x12ede4: 0x18400033  blez        $v0, . + 4 + (0x33 << 2)
    ctx->pc = 0x12EDE4u;
    {
        const bool branch_taken_0x12ede4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x12EDE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EDE4u;
            // 0x12ede8: 0x8e54000c  lw          $s4, 0xC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ede4) {
            ctx->pc = 0x12EEB4u;
            goto label_12eeb4;
        }
    }
    ctx->pc = 0x12EDECu;
    // 0x12edec: 0x265102a8  addiu       $s1, $s2, 0x2A8
    ctx->pc = 0x12edecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), 680));
    // 0x12edf0: 0x26530290  addiu       $s3, $s2, 0x290
    ctx->pc = 0x12edf0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 656));
    // 0x12edf4: 0x964402d0  lhu         $a0, 0x2D0($s2)
    ctx->pc = 0x12edf4u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 720)));
label_12edf8:
    // 0x12edf8: 0x964502d2  lhu         $a1, 0x2D2($s2)
    ctx->pc = 0x12edf8u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 722)));
    // 0x12edfc: 0x96630000  lhu         $v1, 0x0($s3)
    ctx->pc = 0x12edfcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12ee00: 0x26730002  addiu       $s3, $s3, 0x2
    ctx->pc = 0x12ee00u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
    // 0x12ee04: 0x852818  mult        $a1, $a0, $a1
    ctx->pc = 0x12ee04u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x12ee08: 0x964202d4  lhu         $v0, 0x2D4($s2)
    ctx->pc = 0x12ee08u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 724)));
    // 0x12ee0c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x12ee0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x12ee10: 0x8e260000  lw          $a2, 0x0($s1)
    ctx->pc = 0x12ee10u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12ee14: 0x832026  xor         $a0, $a0, $v1
    ctx->pc = 0x12ee14u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 3));
    // 0x12ee18: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x12ee18u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x12ee1c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x12ee1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12ee20: 0x48403  sra         $s0, $a0, 16
    ctx->pc = 0x12ee20u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 4), 16));
    // 0x12ee24: 0x30427fff  andi        $v0, $v0, 0x7FFF
    ctx->pc = 0x12ee24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x12ee28: 0x14c00009  bnez        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x12EE28u;
    {
        const bool branch_taken_0x12ee28 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x12EE2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EE28u;
            // 0x12ee2c: 0xa64202d0  sh          $v0, 0x2D0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 720), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ee28) {
            ctx->pc = 0x12EE50u;
            goto label_12ee50;
        }
    }
    ctx->pc = 0x12EE30u;
    // 0x12ee30: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x12ee30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x12ee34: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12EE34u;
    {
        const bool branch_taken_0x12ee34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12EE38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EE34u;
            // 0x12ee38: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ee34) {
            ctx->pc = 0x12EE54u;
            goto label_12ee54;
        }
    }
    ctx->pc = 0x12EE3Cu;
    // 0x12ee3c: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x12ee3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x12ee40: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12EE40u;
    {
        const bool branch_taken_0x12ee40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12EE44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EE40u;
            // 0x12ee44: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ee40) {
            ctx->pc = 0x12EE58u;
            goto label_12ee58;
        }
    }
    ctx->pc = 0x12EE48u;
    // 0x12ee48: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x12ee48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x12ee4c: 0x2800a  movz        $s0, $zero, $v0
    ctx->pc = 0x12ee4cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 0));
label_12ee50:
    // 0x12ee50: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12ee50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_12ee54:
    // 0x12ee54: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12ee54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_12ee58:
    // 0x12ee58: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12ee58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ee5c: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x12ee5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ee60: 0x101203  sra         $v0, $s0, 8
    ctx->pc = 0x12ee60u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 16), 8));
    // 0x12ee64: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x12ee64u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x12ee68: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12EE68u;
    SET_GPR_U32(ctx, 31, 0x12EE70u);
    ctx->pc = 0x12EE6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EE68u;
            // 0x12ee6c: 0xa3a20000  sb          $v0, 0x0($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EE70u; }
        if (ctx->pc != 0x12EE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EE70u; }
        if (ctx->pc != 0x12EE70u) { return; }
    }
    ctx->pc = 0x12EE70u;
label_12ee70:
    // 0x12ee70: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x12ee70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ee74: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12ee74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ee78: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12ee78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ee7c: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x12ee7cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ee80: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12EE80u;
    SET_GPR_U32(ctx, 31, 0x12EE88u);
    ctx->pc = 0x12EE84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EE80u;
            // 0x12ee84: 0xa3b00000  sb          $s0, 0x0($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 0), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EE88u; }
        if (ctx->pc != 0x12EE88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EE88u; }
        if (ctx->pc != 0x12EE88u) { return; }
    }
    ctx->pc = 0x12EE88u;
label_12ee88:
    // 0x12ee88: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12ee88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ee8c: 0x26310010  addiu       $s1, $s1, 0x10
    ctx->pc = 0x12ee8cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x12ee90: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12ee90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ee94: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x12ee94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12ee98: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x12ee98u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ee9c: 0xc04b7d4  jal         func_12DF50
    ctx->pc = 0x12EE9Cu;
    SET_GPR_U32(ctx, 31, 0x12EEA4u);
    ctx->pc = 0x12EEA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EE9Cu;
            // 0x12eea0: 0x26d60012  addiu       $s6, $s6, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DF50u;
    if (runtime->hasFunction(0x12DF50u)) {
        auto targetFn = runtime->lookupFunction(0x12DF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EEA4u; }
        if (ctx->pc != 0x12EEA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DF50_0x12df50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EEA4u; }
        if (ctx->pc != 0x12EEA4u) { return; }
    }
    ctx->pc = 0x12EEA4u;
label_12eea4:
    // 0x12eea4: 0x8e430058  lw          $v1, 0x58($s2)
    ctx->pc = 0x12eea4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 88)));
    // 0x12eea8: 0x2a3182a  slt         $v1, $s5, $v1
    ctx->pc = 0x12eea8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x12eeac: 0x5460ffd2  bnel        $v1, $zero, . + 4 + (-0x2E << 2)
    ctx->pc = 0x12EEACu;
    {
        const bool branch_taken_0x12eeac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12eeac) {
            ctx->pc = 0x12EEB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EEACu;
            // 0x12eeb0: 0x964402d0  lhu         $a0, 0x2D0($s2) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 720)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EDF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12edf8;
        }
    }
    ctx->pc = 0x12EEB4u;
label_12eeb4:
    // 0x12eeb4: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x12eeb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eeb8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12eeb8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12eebc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12eebcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12eec0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x12eec0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12eec4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x12eec4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12eec8: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x12eec8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12eecc: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x12eeccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12eed0: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x12eed0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12eed4: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x12eed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12eed8: 0x3e00008  jr          $ra
    ctx->pc = 0x12EED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12EEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EED8u;
            // 0x12eedc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12EDF8u: goto label_12edf8;
            case 0x12EE50u: goto label_12ee50;
            case 0x12EE54u: goto label_12ee54;
            case 0x12EE58u: goto label_12ee58;
            case 0x12EE70u: goto label_12ee70;
            case 0x12EE88u: goto label_12ee88;
            case 0x12EEA4u: goto label_12eea4;
            case 0x12EEB4u: goto label_12eeb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12EEE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019ED90
// Address: 0x19ed90 - 0x19ee90
void sub_0019ED90_0x19ed90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019ED90_0x19ed90");
#endif

    switch (ctx->pc) {
        case 0x19edbcu: goto label_19edbc;
        case 0x19edd8u: goto label_19edd8;
        case 0x19edfcu: goto label_19edfc;
        case 0x19ee04u: goto label_19ee04;
        default: break;
    }

    ctx->pc = 0x19ed90u;

    // 0x19ed90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x19ed90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x19ed94: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x19ed94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19ed98: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19ed98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19ed9c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19ed9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19eda0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x19eda0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19eda4: 0x16200010  bnez        $s1, . + 4 + (0x10 << 2)
    ctx->pc = 0x19EDA4u;
    {
        const bool branch_taken_0x19eda4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x19EDA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EDA4u;
            // 0x19eda8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eda4) {
            ctx->pc = 0x19EDE8u;
            goto label_19ede8;
        }
    }
    ctx->pc = 0x19EDACu;
    // 0x19edac: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x19edacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x19edb0: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x19edb0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x19edb4: 0xc067ac4  jal         func_19EB10
    ctx->pc = 0x19EDB4u;
    SET_GPR_U32(ctx, 31, 0x19EDBCu);
    ctx->pc = 0x19EDB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19EDB4u;
            // 0x19edb8: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EB10u;
    if (runtime->hasFunction(0x19EB10u)) {
        auto targetFn = runtime->lookupFunction(0x19EB10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EDBCu; }
        if (ctx->pc != 0x19EDBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EB10_0x19eb10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EDBCu; }
        if (ctx->pc != 0x19EDBCu) { return; }
    }
    ctx->pc = 0x19EDBCu;
label_19edbc:
    // 0x19edbc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19EDBCu;
    {
        const bool branch_taken_0x19edbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19EDC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EDBCu;
            // 0x19edc0: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19edbc) {
            ctx->pc = 0x19EDCCu;
            goto label_19edcc;
        }
    }
    ctx->pc = 0x19EDC4u;
    // 0x19edc4: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x19EDC4u;
    {
        const bool branch_taken_0x19edc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EDC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EDC4u;
            // 0x19edc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19edc4) {
            ctx->pc = 0x19EE7Cu;
            goto label_19ee7c;
        }
    }
    ctx->pc = 0x19EDCCu;
label_19edcc:
    // 0x19edcc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x19edccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19edd0: 0xc067b00  jal         func_19EC00
    ctx->pc = 0x19EDD0u;
    SET_GPR_U32(ctx, 31, 0x19EDD8u);
    ctx->pc = 0x19EDD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19EDD0u;
            // 0x19edd4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19EC00u;
    if (runtime->hasFunction(0x19EC00u)) {
        auto targetFn = runtime->lookupFunction(0x19EC00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EDD8u; }
        if (ctx->pc != 0x19EDD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EC00_0x19ec00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EDD8u; }
        if (ctx->pc != 0x19EDD8u) { return; }
    }
    ctx->pc = 0x19EDD8u;
label_19edd8:
    // 0x19edd8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19edd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19eddc: 0x8c22f9f8  lw          $v0, -0x608($at)
    ctx->pc = 0x19eddcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965752)));
    // 0x19ede0: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x19EDE0u;
    {
        const bool branch_taken_0x19ede0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EDE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EDE0u;
            // 0x19ede4: 0xa6220014  sh          $v0, 0x14($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 20), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ede0) {
            ctx->pc = 0x19EE2Cu;
            goto label_19ee2c;
        }
    }
    ctx->pc = 0x19EDE8u;
label_19ede8:
    // 0x19ede8: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x19ede8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x19edec: 0x1080000f  beqz        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x19EDECu;
    {
        const bool branch_taken_0x19edec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19edec) {
            ctx->pc = 0x19EE2Cu;
            goto label_19ee2c;
        }
    }
    ctx->pc = 0x19EDF4u;
    // 0x19edf4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x19EDF4u;
    {
        const bool branch_taken_0x19edf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EDF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EDF4u;
            // 0x19edf8: 0x84850014  lh          $a1, 0x14($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19edf4) {
            ctx->pc = 0x19EE14u;
            goto label_19ee14;
        }
    }
    ctx->pc = 0x19EDFCu;
label_19edfc:
    // 0x19edfc: 0xc067adc  jal         func_19EB70
    ctx->pc = 0x19EDFCu;
    SET_GPR_U32(ctx, 31, 0x19EE04u);
    ctx->pc = 0x19EB70u;
    if (runtime->hasFunction(0x19EB70u)) {
        auto targetFn = runtime->lookupFunction(0x19EB70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EE04u; }
        if (ctx->pc != 0x19EE04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EB70_0x19eb70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EE04u; }
        if (ctx->pc != 0x19EE04u) { return; }
    }
    ctx->pc = 0x19EE04u;
label_19ee04:
    // 0x19ee04: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x19ee04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x19ee08: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x19EE08u;
    {
        const bool branch_taken_0x19ee08 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19ee08) {
            ctx->pc = 0x19EE2Cu;
            goto label_19ee2c;
        }
    }
    ctx->pc = 0x19EE10u;
    // 0x19ee10: 0x84850014  lh          $a1, 0x14($a0)
    ctx->pc = 0x19ee10u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 20)));
label_19ee14:
    // 0x19ee14: 0x86230014  lh          $v1, 0x14($s1)
    ctx->pc = 0x19ee14u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x19ee18: 0x86020010  lh          $v0, 0x10($s0)
    ctx->pc = 0x19ee18u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x19ee1c: 0xa31823  subu        $v1, $a1, $v1
    ctx->pc = 0x19ee1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x19ee20: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x19ee20u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x19ee24: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x19EE24u;
    {
        const bool branch_taken_0x19ee24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x19ee24) {
            ctx->pc = 0x19EDFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19edfc;
        }
    }
    ctx->pc = 0x19EE2Cu;
label_19ee2c:
    // 0x19ee2c: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x19ee2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x19ee30: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x19EE30u;
    {
        const bool branch_taken_0x19ee30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x19ee30) {
            ctx->pc = 0x19EE48u;
            goto label_19ee48;
        }
    }
    ctx->pc = 0x19EE38u;
    // 0x19ee38: 0xa0400035  sb          $zero, 0x35($v0)
    ctx->pc = 0x19ee38u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 53), (uint8_t)GPR_U32(ctx, 0));
    // 0x19ee3c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x19ee3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19ee40: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x19ee40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x19ee44: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19ee44u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_19ee48:
    // 0x19ee48: 0x86230014  lh          $v1, 0x14($s1)
    ctx->pc = 0x19ee48u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x19ee4c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19ee4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ee50: 0xa6030014  sh          $v1, 0x14($s0)
    ctx->pc = 0x19ee50u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 20), (uint16_t)GPR_U32(ctx, 3));
    // 0x19ee54: 0xa2020035  sb          $v0, 0x35($s0)
    ctx->pc = 0x19ee54u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 53), (uint8_t)GPR_U32(ctx, 2));
    // 0x19ee58: 0xae300008  sw          $s0, 0x8($s1)
    ctx->pc = 0x19ee58u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 16));
    // 0x19ee5c: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x19ee5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x19ee60: 0xae23000c  sw          $v1, 0xC($s1)
    ctx->pc = 0x19ee60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
    // 0x19ee64: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x19ee64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19ee68: 0xae230010  sw          $v1, 0x10($s1)
    ctx->pc = 0x19ee68u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 3));
    // 0x19ee6c: 0x86030010  lh          $v1, 0x10($s0)
    ctx->pc = 0x19ee6cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x19ee70: 0xa6230016  sh          $v1, 0x16($s1)
    ctx->pc = 0x19ee70u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 22), (uint16_t)GPR_U32(ctx, 3));
    // 0x19ee74: 0x86030012  lh          $v1, 0x12($s0)
    ctx->pc = 0x19ee74u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 18)));
    // 0x19ee78: 0xa6230018  sh          $v1, 0x18($s1)
    ctx->pc = 0x19ee78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 24), (uint16_t)GPR_U32(ctx, 3));
label_19ee7c:
    // 0x19ee7c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x19ee7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19ee80: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19ee80u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19ee84: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19ee84u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19ee88: 0x3e00008  jr          $ra
    ctx->pc = 0x19EE88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19EE8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EE88u;
            // 0x19ee8c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19EDBCu: goto label_19edbc;
            case 0x19EDCCu: goto label_19edcc;
            case 0x19EDD8u: goto label_19edd8;
            case 0x19EDE8u: goto label_19ede8;
            case 0x19EDFCu: goto label_19edfc;
            case 0x19EE04u: goto label_19ee04;
            case 0x19EE14u: goto label_19ee14;
            case 0x19EE2Cu: goto label_19ee2c;
            case 0x19EE48u: goto label_19ee48;
            case 0x19EE7Cu: goto label_19ee7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19EE90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

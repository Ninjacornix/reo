#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129010
// Address: 0x129010 - 0x1290c8
void sub_00129010_0x129010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129010_0x129010");
#endif

    switch (ctx->pc) {
        case 0x129038u: goto label_129038;
        case 0x129060u: goto label_129060;
        case 0x129068u: goto label_129068;
        case 0x12907cu: goto label_12907c;
        case 0x129090u: goto label_129090;
        default: break;
    }

    ctx->pc = 0x129010u;

    // 0x129010: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129014: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x129014u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129018: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12901c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12901cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129020: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x129020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x129024: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x129024u;
    {
        const bool branch_taken_0x129024 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x129028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129024u;
            // 0x129028: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129024) {
            ctx->pc = 0x129040u;
            goto label_129040;
        }
    }
    ctx->pc = 0x12902Cu;
    // 0x12902c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12902cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129030: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129030u;
    SET_GPR_U32(ctx, 31, 0x129038u);
    ctx->pc = 0x129034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129030u;
            // 0x129034: 0x24849eb8  addiu       $a0, $a0, -0x6148 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129038u; }
        if (ctx->pc != 0x129038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129038u; }
        if (ctx->pc != 0x129038u) { return; }
    }
    ctx->pc = 0x129038u;
label_129038:
    // 0x129038: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x129038u;
    {
        const bool branch_taken_0x129038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12903Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129038u;
            // 0x12903c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129038) {
            ctx->pc = 0x1290B8u;
            goto label_1290b8;
        }
    }
    ctx->pc = 0x129040u;
label_129040:
    // 0x129040: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x129040u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x129044: 0x3c08000f  lui         $t0, 0xF
    ctx->pc = 0x129044u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)15 << 16));
    // 0x129048: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x129048u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x12904c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x12904cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129050: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x129050u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x129054: 0x3508ffff  ori         $t0, $t0, 0xFFFF
    ctx->pc = 0x129054u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65535);
    // 0x129058: 0xc04c13a  jal         func_1304E8
    ctx->pc = 0x129058u;
    SET_GPR_U32(ctx, 31, 0x129060u);
    ctx->pc = 0x12905Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129058u;
            // 0x12905c: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1304E8u;
    if (runtime->hasFunction(0x1304E8u)) {
        auto targetFn = runtime->lookupFunction(0x1304E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129060u; }
        if (ctx->pc != 0x129060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001304E8_0x1304e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129060u; }
        if (ctx->pc != 0x129060u) { return; }
    }
    ctx->pc = 0x129060u;
label_129060:
    // 0x129060: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x129060u;
    SET_GPR_U32(ctx, 31, 0x129068u);
    ctx->pc = 0x129064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129060u;
            // 0x129064: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129068u; }
        if (ctx->pc != 0x129068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129068u; }
        if (ctx->pc != 0x129068u) { return; }
    }
    ctx->pc = 0x129068u;
label_129068:
    // 0x129068: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x129068u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12906c: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x12906Cu;
    {
        const bool branch_taken_0x12906c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x12906c) {
            ctx->pc = 0x129088u;
            goto label_129088;
        }
    }
    ctx->pc = 0x129074u;
    // 0x129074: 0xc04c158  jal         func_130560
    ctx->pc = 0x129074u;
    SET_GPR_U32(ctx, 31, 0x12907Cu);
    ctx->pc = 0x129078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129074u;
            // 0x129078: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130560u;
    if (runtime->hasFunction(0x130560u)) {
        auto targetFn = runtime->lookupFunction(0x130560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12907Cu; }
        if (ctx->pc != 0x12907Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130560_0x130560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12907Cu; }
        if (ctx->pc != 0x12907Cu) { return; }
    }
    ctx->pc = 0x12907Cu;
label_12907c:
    // 0x12907c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x12907Cu;
    {
        const bool branch_taken_0x12907c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12907Cu;
            // 0x129080: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12907c) {
            ctx->pc = 0x1290B8u;
            goto label_1290b8;
        }
    }
    ctx->pc = 0x129084u;
    // 0x129084: 0x0  nop
    ctx->pc = 0x129084u;
    // NOP
label_129088:
    // 0x129088: 0xc04c390  jal         func_130E40
    ctx->pc = 0x129088u;
    SET_GPR_U32(ctx, 31, 0x129090u);
    ctx->pc = 0x12908Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129088u;
            // 0x12908c: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E40u;
    if (runtime->hasFunction(0x130E40u)) {
        auto targetFn = runtime->lookupFunction(0x130E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129090u; }
        if (ctx->pc != 0x129090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E40_0x130e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129090u; }
        if (ctx->pc != 0x129090u) { return; }
    }
    ctx->pc = 0x129090u;
label_129090:
    // 0x129090: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x129090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x129094: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x129094u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129098: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x129098u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x12909c: 0x246407ff  addiu       $a0, $v1, 0x7FF
    ctx->pc = 0x12909cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2047));
    // 0x1290a0: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1290a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1290a4: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x1290a4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x1290a8: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x1290a8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x1290ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1290acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1290b0: 0xae030040  sw          $v1, 0x40($s0)
    ctx->pc = 0x1290b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 3));
    // 0x1290b4: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1290b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
label_1290b8:
    // 0x1290b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1290b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1290bc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1290bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1290c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1290C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1290C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1290C0u;
            // 0x1290c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129038u: goto label_129038;
            case 0x129040u: goto label_129040;
            case 0x129060u: goto label_129060;
            case 0x129068u: goto label_129068;
            case 0x12907Cu: goto label_12907c;
            case 0x129088u: goto label_129088;
            case 0x129090u: goto label_129090;
            case 0x1290B8u: goto label_1290b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1290C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

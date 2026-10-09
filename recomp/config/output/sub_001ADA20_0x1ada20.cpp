#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ADA20
// Address: 0x1ada20 - 0x1adc00
void sub_001ADA20_0x1ada20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ADA20_0x1ada20");
#endif

    switch (ctx->pc) {
        case 0x1ada4cu: goto label_1ada4c;
        case 0x1ada64u: goto label_1ada64;
        case 0x1ada9cu: goto label_1ada9c;
        case 0x1adac4u: goto label_1adac4;
        case 0x1adae8u: goto label_1adae8;
        case 0x1adaf4u: goto label_1adaf4;
        case 0x1adb4cu: goto label_1adb4c;
        case 0x1adb68u: goto label_1adb68;
        case 0x1adb80u: goto label_1adb80;
        case 0x1adbb8u: goto label_1adbb8;
        case 0x1adbd8u: goto label_1adbd8;
        case 0x1adbe4u: goto label_1adbe4;
        default: break;
    }

    ctx->pc = 0x1ada20u;

    // 0x1ada20: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ada20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ada24: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1ada24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1ada28: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ada28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ada2c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ada2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ada30: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1ada30u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ada34: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ada34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ada38: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1ada38u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ada3c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1ada3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ada40: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x1ada40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1ada44: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1ADA44u;
    SET_GPR_U32(ctx, 31, 0x1ADA4Cu);
    ctx->pc = 0x1ADA48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA44u;
            // 0x1ada48: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADA4Cu; }
        if (ctx->pc != 0x1ADA4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADA4Cu; }
        if (ctx->pc != 0x1ADA4Cu) { return; }
    }
    ctx->pc = 0x1ADA4Cu;
label_1ada4c:
    // 0x1ada4c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADA4Cu;
    {
        const bool branch_taken_0x1ada4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADA50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA4Cu;
            // 0x1ada50: 0x2404000a  addiu       $a0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ada4c) {
            ctx->pc = 0x1ADA5Cu;
            goto label_1ada5c;
        }
    }
    ctx->pc = 0x1ADA54u;
    // 0x1ada54: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1ADA54u;
    {
        const bool branch_taken_0x1ada54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADA58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA54u;
            // 0x1ada58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ada54) {
            ctx->pc = 0x1ADB08u;
            goto label_1adb08;
        }
    }
    ctx->pc = 0x1ADA5Cu;
label_1ada5c:
    // 0x1ada5c: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1ADA5Cu;
    SET_GPR_U32(ctx, 31, 0x1ADA64u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADA64u; }
        if (ctx->pc != 0x1ADA64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADA64u; }
        if (ctx->pc != 0x1ADA64u) { return; }
    }
    ctx->pc = 0x1ADA64u;
label_1ada64:
    // 0x1ada64: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1ADA64u;
    {
        const bool branch_taken_0x1ada64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADA68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA64u;
            // 0x1ada68: 0x131840  sll         $v1, $s3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ada64) {
            ctx->pc = 0x1ADA7Cu;
            goto label_1ada7c;
        }
    }
    ctx->pc = 0x1ADA6Cu;
    // 0x1ada6c: 0x16600003  bnez        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADA6Cu;
    {
        const bool branch_taken_0x1ada6c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ada6c) {
            ctx->pc = 0x1ADA7Cu;
            goto label_1ada7c;
        }
    }
    ctx->pc = 0x1ADA74u;
    // 0x1ada74: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1ADA74u;
    {
        const bool branch_taken_0x1ada74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA74u;
            // 0x1ada78: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ada74) {
            ctx->pc = 0x1ADB08u;
            goto label_1adb08;
        }
    }
    ctx->pc = 0x1ADA7Cu;
label_1ada7c:
    // 0x1ada7c: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ada7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ada80: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x1ada80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x1ada84: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1ada84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1ada88: 0x380c0  sll         $s0, $v1, 3
    ctx->pc = 0x1ada88u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ada8c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ada8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ada90: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1ada90u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ada94: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1ADA94u;
    SET_GPR_U32(ctx, 31, 0x1ADA9Cu);
    ctx->pc = 0x1ADA98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA94u;
            // 0x1ada98: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADA9Cu; }
        if (ctx->pc != 0x1ADA9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADA9Cu; }
        if (ctx->pc != 0x1ADA9Cu) { return; }
    }
    ctx->pc = 0x1ADA9Cu;
label_1ada9c:
    // 0x1ada9c: 0x621000b  bgez        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x1ADA9Cu;
    {
        const bool branch_taken_0x1ada9c = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1ADAA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADA9Cu;
            // 0x1adaa0: 0x3c02002c  lui         $v0, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ada9c) {
            ctx->pc = 0x1ADACCu;
            goto label_1adacc;
        }
    }
    ctx->pc = 0x1ADAA4u;
    // 0x1adaa4: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adaa4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adaa8: 0x131880  sll         $v1, $s3, 2
    ctx->pc = 0x1adaa8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x1adaac: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1adaacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1adab0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1adab0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adab4: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x1adab4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adab8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1adab8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1adabc: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1ADABCu;
    SET_GPR_U32(ctx, 31, 0x1ADAC4u);
    ctx->pc = 0x1ADAC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADABCu;
            // 0x1adac0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADAC4u; }
        if (ctx->pc != 0x1ADAC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADAC4u; }
        if (ctx->pc != 0x1ADAC4u) { return; }
    }
    ctx->pc = 0x1ADAC4u;
label_1adac4:
    // 0x1adac4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1ADAC4u;
    {
        const bool branch_taken_0x1adac4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADAC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADAC4u;
            // 0x1adac8: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adac4) {
            ctx->pc = 0x1ADAECu;
            goto label_1adaec;
        }
    }
    ctx->pc = 0x1ADACCu;
label_1adacc:
    // 0x1adacc: 0x131880  sll         $v1, $s3, 2
    ctx->pc = 0x1adaccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x1adad0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1adad0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adad4: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1adad4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1adad8: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x1adad8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adadc: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1adadcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1adae0: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1ADAE0u;
    SET_GPR_U32(ctx, 31, 0x1ADAE8u);
    ctx->pc = 0x1ADAE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADAE0u;
            // 0x1adae4: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADAE8u; }
        if (ctx->pc != 0x1ADAE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADAE8u; }
        if (ctx->pc != 0x1ADAE8u) { return; }
    }
    ctx->pc = 0x1ADAE8u;
label_1adae8:
    // 0x1adae8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x1adae8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_1adaec:
    // 0x1adaec: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1ADAECu;
    SET_GPR_U32(ctx, 31, 0x1ADAF4u);
    ctx->pc = 0x1ADAF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADAECu;
            // 0x1adaf0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADAF4u; }
        if (ctx->pc != 0x1ADAF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADAF4u; }
        if (ctx->pc != 0x1ADAF4u) { return; }
    }
    ctx->pc = 0x1ADAF4u;
label_1adaf4:
    // 0x1adaf4: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1adaf4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1adaf8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1adaf8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adafc: 0x24638d70  addiu       $v1, $v1, -0x7290
    ctx->pc = 0x1adafcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937968));
    // 0x1adb00: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1adb00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1adb04: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1adb04u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_1adb08:
    // 0x1adb08: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1adb08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1adb0c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1adb0cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1adb10: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1adb10u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1adb14: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1adb14u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1adb18: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1adb18u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1adb1c: 0x3e00008  jr          $ra
    ctx->pc = 0x1ADB1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ADB20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB1Cu;
            // 0x1adb20: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ADA4Cu: goto label_1ada4c;
            case 0x1ADA5Cu: goto label_1ada5c;
            case 0x1ADA64u: goto label_1ada64;
            case 0x1ADA7Cu: goto label_1ada7c;
            case 0x1ADA9Cu: goto label_1ada9c;
            case 0x1ADAC4u: goto label_1adac4;
            case 0x1ADACCu: goto label_1adacc;
            case 0x1ADAE8u: goto label_1adae8;
            case 0x1ADAECu: goto label_1adaec;
            case 0x1ADAF4u: goto label_1adaf4;
            case 0x1ADB08u: goto label_1adb08;
            case 0x1ADB4Cu: goto label_1adb4c;
            case 0x1ADB60u: goto label_1adb60;
            case 0x1ADB68u: goto label_1adb68;
            case 0x1ADB78u: goto label_1adb78;
            case 0x1ADB80u: goto label_1adb80;
            case 0x1ADB98u: goto label_1adb98;
            case 0x1ADBB8u: goto label_1adbb8;
            case 0x1ADBD8u: goto label_1adbd8;
            case 0x1ADBE4u: goto label_1adbe4;
            case 0x1ADBE8u: goto label_1adbe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ADB24u;
    // 0x1adb24: 0x0  nop
    ctx->pc = 0x1adb24u;
    // NOP
    // 0x1adb28: 0x0  nop
    ctx->pc = 0x1adb28u;
    // NOP
    // 0x1adb2c: 0x0  nop
    ctx->pc = 0x1adb2cu;
    // NOP
    // 0x1adb30: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1adb30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1adb34: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1adb34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1adb38: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1adb38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1adb3c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1adb3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adb40: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1adb40u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1adb44: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1ADB44u;
    SET_GPR_U32(ctx, 31, 0x1ADB4Cu);
    ctx->pc = 0x1ADB48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB44u;
            // 0x1adb48: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB4Cu; }
        if (ctx->pc != 0x1ADB4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB4Cu; }
        if (ctx->pc != 0x1ADB4Cu) { return; }
    }
    ctx->pc = 0x1ADB4Cu;
label_1adb4c:
    // 0x1adb4c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1adb4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adb50: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADB50u;
    {
        const bool branch_taken_0x1adb50 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1ADB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB50u;
            // 0x1adb54: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb50) {
            ctx->pc = 0x1ADB60u;
            goto label_1adb60;
        }
    }
    ctx->pc = 0x1ADB58u;
    // 0x1adb58: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1ADB58u;
    {
        const bool branch_taken_0x1adb58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB58u;
            // 0x1adb5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb58) {
            ctx->pc = 0x1ADBE8u;
            goto label_1adbe8;
        }
    }
    ctx->pc = 0x1ADB60u;
label_1adb60:
    // 0x1adb60: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1ADB60u;
    SET_GPR_U32(ctx, 31, 0x1ADB68u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB68u; }
        if (ctx->pc != 0x1ADB68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB68u; }
        if (ctx->pc != 0x1ADB68u) { return; }
    }
    ctx->pc = 0x1ADB68u;
label_1adb68:
    // 0x1adb68: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADB68u;
    {
        const bool branch_taken_0x1adb68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB68u;
            // 0x1adb6c: 0x2404000a  addiu       $a0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb68) {
            ctx->pc = 0x1ADB78u;
            goto label_1adb78;
        }
    }
    ctx->pc = 0x1ADB70u;
    // 0x1adb70: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1ADB70u;
    {
        const bool branch_taken_0x1adb70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB70u;
            // 0x1adb74: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb70) {
            ctx->pc = 0x1ADBE8u;
            goto label_1adbe8;
        }
    }
    ctx->pc = 0x1ADB78u;
label_1adb78:
    // 0x1adb78: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1ADB78u;
    SET_GPR_U32(ctx, 31, 0x1ADB80u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB80u; }
        if (ctx->pc != 0x1ADB80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB80u; }
        if (ctx->pc != 0x1ADB80u) { return; }
    }
    ctx->pc = 0x1ADB80u;
label_1adb80:
    // 0x1adb80: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1ADB80u;
    {
        const bool branch_taken_0x1adb80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB80u;
            // 0x1adb84: 0x111840  sll         $v1, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb80) {
            ctx->pc = 0x1ADB98u;
            goto label_1adb98;
        }
    }
    ctx->pc = 0x1ADB88u;
    // 0x1adb88: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADB88u;
    {
        const bool branch_taken_0x1adb88 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1adb88) {
            ctx->pc = 0x1ADB98u;
            goto label_1adb98;
        }
    }
    ctx->pc = 0x1ADB90u;
    // 0x1adb90: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1ADB90u;
    {
        const bool branch_taken_0x1adb90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB90u;
            // 0x1adb94: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb90) {
            ctx->pc = 0x1ADBE8u;
            goto label_1adbe8;
        }
    }
    ctx->pc = 0x1ADB98u;
label_1adb98:
    // 0x1adb98: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adb98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adb9c: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1adb9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1adba0: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1adba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1adba4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1adba4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1adba8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1adba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adbac: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1adbacu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1adbb0: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1ADBB0u;
    SET_GPR_U32(ctx, 31, 0x1ADBB8u);
    ctx->pc = 0x1ADBB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBB0u;
            // 0x1adbb4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBB8u; }
        if (ctx->pc != 0x1ADBB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBB8u; }
        if (ctx->pc != 0x1ADBB8u) { return; }
    }
    ctx->pc = 0x1ADBB8u;
label_1adbb8:
    // 0x1adbb8: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adbb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adbbc: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1adbbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1adbc0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1adbc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adbc4: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1adbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1adbc8: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1adbc8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adbcc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1adbccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1adbd0: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1ADBD0u;
    SET_GPR_U32(ctx, 31, 0x1ADBD8u);
    ctx->pc = 0x1ADBD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBD0u;
            // 0x1adbd4: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBD8u; }
        if (ctx->pc != 0x1ADBD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBD8u; }
        if (ctx->pc != 0x1ADBD8u) { return; }
    }
    ctx->pc = 0x1ADBD8u;
label_1adbd8:
    // 0x1adbd8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1adbd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1adbdc: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1ADBDCu;
    SET_GPR_U32(ctx, 31, 0x1ADBE4u);
    ctx->pc = 0x1ADBE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBDCu;
            // 0x1adbe0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBE4u; }
        if (ctx->pc != 0x1ADBE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBE4u; }
        if (ctx->pc != 0x1ADBE4u) { return; }
    }
    ctx->pc = 0x1ADBE4u;
label_1adbe4:
    // 0x1adbe4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1adbe4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1adbe8:
    // 0x1adbe8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1adbe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1adbec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1adbecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1adbf0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1adbf0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1adbf4: 0x3e00008  jr          $ra
    ctx->pc = 0x1ADBF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ADBF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBF4u;
            // 0x1adbf8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ADA4Cu: goto label_1ada4c;
            case 0x1ADA5Cu: goto label_1ada5c;
            case 0x1ADA64u: goto label_1ada64;
            case 0x1ADA7Cu: goto label_1ada7c;
            case 0x1ADA9Cu: goto label_1ada9c;
            case 0x1ADAC4u: goto label_1adac4;
            case 0x1ADACCu: goto label_1adacc;
            case 0x1ADAE8u: goto label_1adae8;
            case 0x1ADAECu: goto label_1adaec;
            case 0x1ADAF4u: goto label_1adaf4;
            case 0x1ADB08u: goto label_1adb08;
            case 0x1ADB4Cu: goto label_1adb4c;
            case 0x1ADB60u: goto label_1adb60;
            case 0x1ADB68u: goto label_1adb68;
            case 0x1ADB78u: goto label_1adb78;
            case 0x1ADB80u: goto label_1adb80;
            case 0x1ADB98u: goto label_1adb98;
            case 0x1ADBB8u: goto label_1adbb8;
            case 0x1ADBD8u: goto label_1adbd8;
            case 0x1ADBE4u: goto label_1adbe4;
            case 0x1ADBE8u: goto label_1adbe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ADBFCu;
    // 0x1adbfc: 0x0  nop
    ctx->pc = 0x1adbfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

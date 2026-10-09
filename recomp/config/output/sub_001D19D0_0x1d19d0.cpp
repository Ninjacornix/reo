#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D19D0
// Address: 0x1d19d0 - 0x1d1b10
void sub_001D19D0_0x1d19d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D19D0_0x1d19d0");
#endif

    switch (ctx->pc) {
        case 0x1d1a28u: goto label_1d1a28;
        case 0x1d1a54u: goto label_1d1a54;
        case 0x1d1aa4u: goto label_1d1aa4;
        case 0x1d1abcu: goto label_1d1abc;
        case 0x1d1ad4u: goto label_1d1ad4;
        case 0x1d1ae4u: goto label_1d1ae4;
        case 0x1d1aecu: goto label_1d1aec;
        default: break;
    }

    ctx->pc = 0x1d19d0u;

label_1d19d0:
    // 0x1d19d0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d19d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d19d4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d19d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d19d8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d19d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d19dc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d19dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d19e0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d19e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d19e4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d19e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d19e8: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d19e8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d19ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d19ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d19f0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1d19f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d19f4: 0x8c940000  lw          $s4, 0x0($a0)
    ctx->pc = 0x1d19f4u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d19f8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1d19f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d19fc: 0x8c930004  lw          $s3, 0x4($a0)
    ctx->pc = 0x1d19fcu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d1a00: 0x3c05004f  lui         $a1, 0x4F
    ctx->pc = 0x1d1a00u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)79 << 16));
    // 0x1d1a04: 0x24a58970  addiu       $a1, $a1, -0x7690
    ctx->pc = 0x1d1a04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294936944));
    // 0x1d1a08: 0x26460008  addiu       $a2, $s2, 0x8
    ctx->pc = 0x1d1a08u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
    // 0x1d1a0c: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x1d1a0cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1a10: 0x200402d  daddu       $t0, $s0, $zero
    ctx->pc = 0x1d1a10u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1a14: 0x3282ffff  andi        $v0, $s4, 0xFFFF
    ctx->pc = 0x1d1a14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)65535);
    // 0x1d1a18: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x1d1a18u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d1a1c: 0x3262ffff  andi        $v0, $s3, 0xFFFF
    ctx->pc = 0x1d1a1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1d1a20: 0xc0745b0  jal         func_1D16C0
    ctx->pc = 0x1D1A20u;
    SET_GPR_U32(ctx, 31, 0x1D1A28u);
    ctx->pc = 0x1D1A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1A20u;
            // 0x1d1a24: 0xa0a20001  sb          $v0, 0x1($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D16C0u;
    if (runtime->hasFunction(0x1D16C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D16C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1A28u; }
        if (ctx->pc != 0x1D1A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D16C0_0x1d16c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1A28u; }
        if (ctx->pc != 0x1D1A28u) { return; }
    }
    ctx->pc = 0x1D1A28u;
label_1d1a28:
    // 0x1d1a28: 0x3c05004e  lui         $a1, 0x4E
    ctx->pc = 0x1d1a28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)78 << 16));
    // 0x1d1a2c: 0x3283ffff  andi        $v1, $s4, 0xFFFF
    ctx->pc = 0x1d1a2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)65535);
    // 0x1d1a30: 0x24a56a20  addiu       $a1, $a1, 0x6A20
    ctx->pc = 0x1d1a30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27168));
    // 0x1d1a34: 0x3262ffff  andi        $v0, $s3, 0xFFFF
    ctx->pc = 0x1d1a34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1d1a38: 0xa0a30000  sb          $v1, 0x0($a1)
    ctx->pc = 0x1d1a38u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d1a3c: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x1d1a3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1a40: 0x200402d  daddu       $t0, $s0, $zero
    ctx->pc = 0x1d1a40u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1a44: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1d1a44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1a48: 0x264600a8  addiu       $a2, $s2, 0xA8
    ctx->pc = 0x1d1a48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 168));
    // 0x1d1a4c: 0xc0745b0  jal         func_1D16C0
    ctx->pc = 0x1D1A4Cu;
    SET_GPR_U32(ctx, 31, 0x1D1A54u);
    ctx->pc = 0x1D1A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1A4Cu;
            // 0x1d1a50: 0xa0a20001  sb          $v0, 0x1($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D16C0u;
    if (runtime->hasFunction(0x1D16C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D16C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1A54u; }
        if (ctx->pc != 0x1D1A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D16C0_0x1d16c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1A54u; }
        if (ctx->pc != 0x1D1A54u) { return; }
    }
    ctx->pc = 0x1D1A54u;
label_1d1a54:
    // 0x1d1a54: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d1a54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d1a58: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d1a58u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d1a5c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d1a5cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d1a60: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d1a60u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d1a64: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d1a64u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1a68: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1a68u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1a6c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1A6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1A6Cu;
            // 0x1d1a70: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D19D0u: goto label_1d19d0;
            case 0x1D1A28u: goto label_1d1a28;
            case 0x1D1A54u: goto label_1d1a54;
            case 0x1D1AA4u: goto label_1d1aa4;
            case 0x1D1ABCu: goto label_1d1abc;
            case 0x1D1AD4u: goto label_1d1ad4;
            case 0x1D1AE4u: goto label_1d1ae4;
            case 0x1D1AECu: goto label_1d1aec;
            case 0x1D1AF8u: goto label_1d1af8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1A74u;
    // 0x1d1a74: 0x0  nop
    ctx->pc = 0x1d1a74u;
    // NOP
    // 0x1d1a78: 0x0  nop
    ctx->pc = 0x1d1a78u;
    // NOP
    // 0x1d1a7c: 0x0  nop
    ctx->pc = 0x1d1a7cu;
    // NOP
    // 0x1d1a80: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d1a80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d1a84: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d1a84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d1a88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d1a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d1a8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1a8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1a90: 0x9023ae0f  lbu         $v1, -0x51F1($at)
    ctx->pc = 0x1d1a90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946319)));
    // 0x1d1a94: 0x14600018  bnez        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1D1A94u;
    {
        const bool branch_taken_0x1d1a94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d1a94) {
            ctx->pc = 0x1D1AF8u;
            goto label_1d1af8;
        }
    }
    ctx->pc = 0x1D1A9Cu;
    // 0x1d1a9c: 0xc06c77c  jal         func_1B1DF0
    ctx->pc = 0x1D1A9Cu;
    SET_GPR_U32(ctx, 31, 0x1D1AA4u);
    ctx->pc = 0x1B1DF0u;
    if (runtime->hasFunction(0x1B1DF0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AA4u; }
        if (ctx->pc != 0x1D1AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1DF0_0x1b1df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AA4u; }
        if (ctx->pc != 0x1D1AA4u) { return; }
    }
    ctx->pc = 0x1D1AA4u;
label_1d1aa4:
    // 0x1d1aa4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1aa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1aa8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1aa8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1aac: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d1aacu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1ab0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1ab0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1ab4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1AB4u;
    SET_GPR_U32(ctx, 31, 0x1D1ABCu);
    ctx->pc = 0x1D1AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1AB4u;
            // 0x1d1ab8: 0x24a56380  addiu       $a1, $a1, 0x6380 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1ABCu; }
        if (ctx->pc != 0x1D1ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1ABCu; }
        if (ctx->pc != 0x1D1ABCu) { return; }
    }
    ctx->pc = 0x1D1ABCu;
label_1d1abc:
    // 0x1d1abc: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1d1abcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1d1ac0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1ac0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1ac4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d1ac4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ac8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d1ac8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1acc: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1ACCu;
    SET_GPR_U32(ctx, 31, 0x1D1AD4u);
    ctx->pc = 0x1D1AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1ACCu;
            // 0x1d1ad0: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AD4u; }
        if (ctx->pc != 0x1D1AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AD4u; }
        if (ctx->pc != 0x1D1AD4u) { return; }
    }
    ctx->pc = 0x1D1AD4u;
label_1d1ad4:
    // 0x1d1ad4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1ad4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ad8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d1ad8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1adc: 0xc074674  jal         func_1D19D0
    ctx->pc = 0x1D1ADCu;
    SET_GPR_U32(ctx, 31, 0x1D1AE4u);
    ctx->pc = 0x1D1AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1ADCu;
            // 0x1d1ae0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D19D0u;
    goto label_1d19d0;
    ctx->pc = 0x1D1AE4u;
label_1d1ae4:
    // 0x1d1ae4: 0xc06cb38  jal         func_1B2CE0
    ctx->pc = 0x1D1AE4u;
    SET_GPR_U32(ctx, 31, 0x1D1AECu);
    ctx->pc = 0x1B2CE0u;
    if (runtime->hasFunction(0x1B2CE0u)) {
        auto targetFn = runtime->lookupFunction(0x1B2CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AECu; }
        if (ctx->pc != 0x1D1AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2CE0_0x1b2ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AECu; }
        if (ctx->pc != 0x1D1AECu) { return; }
    }
    ctx->pc = 0x1D1AECu;
label_1d1aec:
    // 0x1d1aec: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d1aecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1af0: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1d1af0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1d1af4: 0xa023ae0f  sb          $v1, -0x51F1($at)
    ctx->pc = 0x1d1af4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946319), (uint8_t)GPR_U32(ctx, 3));
label_1d1af8:
    // 0x1d1af8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d1af8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1afc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1afcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1b00: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1B00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1B00u;
            // 0x1d1b04: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D19D0u: goto label_1d19d0;
            case 0x1D1A28u: goto label_1d1a28;
            case 0x1D1A54u: goto label_1d1a54;
            case 0x1D1AA4u: goto label_1d1aa4;
            case 0x1D1ABCu: goto label_1d1abc;
            case 0x1D1AD4u: goto label_1d1ad4;
            case 0x1D1AE4u: goto label_1d1ae4;
            case 0x1D1AECu: goto label_1d1aec;
            case 0x1D1AF8u: goto label_1d1af8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1B08u;
    // 0x1d1b08: 0x0  nop
    ctx->pc = 0x1d1b08u;
    // NOP
    // 0x1d1b0c: 0x0  nop
    ctx->pc = 0x1d1b0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

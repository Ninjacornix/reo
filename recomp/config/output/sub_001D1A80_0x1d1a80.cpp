#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1A80
// Address: 0x1d1a80 - 0x1d1b08
void sub_001D1A80_0x1d1a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1A80_0x1d1a80");
#endif

    switch (ctx->pc) {
        case 0x1d1aa4u: goto label_1d1aa4;
        case 0x1d1abcu: goto label_1d1abc;
        case 0x1d1ad4u: goto label_1d1ad4;
        case 0x1d1ae4u: goto label_1d1ae4;
        case 0x1d1aecu: goto label_1d1aec;
        default: break;
    }

    ctx->pc = 0x1d1a80u;

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
    if (runtime->hasFunction(0x1D19D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D19D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AE4u; }
        if (ctx->pc != 0x1D1AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D19D0_0x1d19d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1AE4u; }
        if (ctx->pc != 0x1D1AE4u) { return; }
    }
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
    ctx->pc = GPR_U32(ctx, 31); return;
}

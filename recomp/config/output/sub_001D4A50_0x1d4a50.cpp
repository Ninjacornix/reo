#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4A50
// Address: 0x1d4a50 - 0x1d4adc
void sub_001D4A50_0x1d4a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4A50_0x1d4a50");
#endif

    switch (ctx->pc) {
        case 0x1d4a64u: goto label_1d4a64;
        case 0x1d4a70u: goto label_1d4a70;
        case 0x1d4a78u: goto label_1d4a78;
        case 0x1d4aa8u: goto label_1d4aa8;
        case 0x1d4ab8u: goto label_1d4ab8;
        default: break;
    }

    ctx->pc = 0x1d4a50u;

    // 0x1d4a50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d4a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d4a54: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d4a54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d4a58: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d4a58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4a5c: 0xc16e8e0  jal         func_5BA380
    ctx->pc = 0x1D4A5Cu;
    SET_GPR_U32(ctx, 31, 0x1D4A64u);
    ctx->pc = 0x1D4A60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4A5Cu;
            // 0x1d4a60: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5BA380u;
    {
        auto targetFn = runtime->lookupFunction(0x5BA380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A64u; }
        if (ctx->pc != 0x1D4A64u) { return; }
    }
    ctx->pc = 0x1D4A64u;
label_1d4a64:
    // 0x1d4a64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4a64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4a68: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d4a68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a6c: 0x8c31440c  lw          $s1, 0x440C($at)
    ctx->pc = 0x1d4a6cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
label_1d4a70:
    // 0x1d4a70: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1D4A70u;
    SET_GPR_U32(ctx, 31, 0x1D4A78u);
    ctx->pc = 0x1D4A74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4A70u;
            // 0x1d4a74: 0x26044000  addiu       $a0, $s0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A78u; }
        if (ctx->pc != 0x1D4A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A78u; }
        if (ctx->pc != 0x1D4A78u) { return; }
    }
    ctx->pc = 0x1D4A78u;
label_1d4a78:
    // 0x1d4a78: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D4A78u;
    {
        const bool branch_taken_0x1d4a78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4a78) {
            ctx->pc = 0x1D4AB8u;
            goto label_1d4ab8;
        }
    }
    ctx->pc = 0x1D4A80u;
    // 0x1d4a80: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d4a80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d4a84: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1d4a84u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d4a88: 0x244268d0  addiu       $v0, $v0, 0x68D0
    ctx->pc = 0x1d4a88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26832));
    // 0x1d4a8c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d4a8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a90: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4a90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4a94: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d4a94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a98: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1d4a98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d4a9c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d4aa0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4AA0u;
    SET_GPR_U32(ctx, 31, 0x1D4AA8u);
    ctx->pc = 0x1D4AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4AA0u;
            // 0x1d4aa4: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AA8u; }
        if (ctx->pc != 0x1D4AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AA8u; }
        if (ctx->pc != 0x1D4AA8u) { return; }
    }
    ctx->pc = 0x1D4AA8u;
label_1d4aa8:
    // 0x1d4aa8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4AA8u;
    {
        const bool branch_taken_0x1d4aa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4AA8u;
            // 0x1d4aac: 0x26044000  addiu       $a0, $s0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4aa8) {
            ctx->pc = 0x1D4AB8u;
            goto label_1d4ab8;
        }
    }
    ctx->pc = 0x1D4AB0u;
    // 0x1d4ab0: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D4AB0u;
    SET_GPR_U32(ctx, 31, 0x1D4AB8u);
    ctx->pc = 0x1D4AB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4AB0u;
            // 0x1d4ab4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AB8u; }
        if (ctx->pc != 0x1D4AB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AB8u; }
        if (ctx->pc != 0x1D4AB8u) { return; }
    }
    ctx->pc = 0x1D4AB8u;
label_1d4ab8:
    // 0x1d4ab8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d4ab8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d4abc: 0x2a030010  slti        $v1, $s0, 0x10
    ctx->pc = 0x1d4abcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1d4ac0: 0x1460ffeb  bnez        $v1, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1D4AC0u;
    {
        const bool branch_taken_0x1d4ac0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4ac0) {
            ctx->pc = 0x1D4A70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d4a70;
        }
    }
    ctx->pc = 0x1D4AC8u;
    // 0x1d4ac8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d4ac8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4acc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d4accu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4ad0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4ad0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4ad4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4AD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4AD4u;
            // 0x1d4ad8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4A64u: goto label_1d4a64;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4A78u: goto label_1d4a78;
            case 0x1D4AA8u: goto label_1d4aa8;
            case 0x1D4AB8u: goto label_1d4ab8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4ADCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4BA0
// Address: 0x1b4ba0 - 0x1b4c44
void sub_001B4BA0_0x1b4ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4BA0_0x1b4ba0");
#endif

    switch (ctx->pc) {
        case 0x1b4bc8u: goto label_1b4bc8;
        case 0x1b4c04u: goto label_1b4c04;
        case 0x1b4c20u: goto label_1b4c20;
        case 0x1b4c28u: goto label_1b4c28;
        case 0x1b4c30u: goto label_1b4c30;
        default: break;
    }

    ctx->pc = 0x1b4ba0u;

    // 0x1b4ba0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b4ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b4ba4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b4ba4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b4ba8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b4ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b4bac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b4bacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4bb0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b4bb0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4bb4: 0x8c22aa30  lw          $v0, -0x55D0($at)
    ctx->pc = 0x1b4bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945328)));
    // 0x1b4bb8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4BB8u;
    {
        const bool branch_taken_0x1b4bb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4BB8u;
            // 0x1b4bbc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4bb8) {
            ctx->pc = 0x1B4BC8u;
            goto label_1b4bc8;
        }
    }
    ctx->pc = 0x1B4BC0u;
    // 0x1b4bc0: 0xc06d314  jal         func_1B4C50
    ctx->pc = 0x1B4BC0u;
    SET_GPR_U32(ctx, 31, 0x1B4BC8u);
    ctx->pc = 0x1B4C50u;
    if (runtime->hasFunction(0x1B4C50u)) {
        auto targetFn = runtime->lookupFunction(0x1B4C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4BC8u; }
        if (ctx->pc != 0x1B4BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4C50_0x1b4c50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4BC8u; }
        if (ctx->pc != 0x1B4BC8u) { return; }
    }
    ctx->pc = 0x1B4BC8u;
label_1b4bc8:
    // 0x1b4bc8: 0x10807c  dsll32      $s0, $s0, 1
    ctx->pc = 0x1b4bc8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 1));
    // 0x1b4bcc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4bccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4bd0: 0x10807e  dsrl32      $s0, $s0, 1
    ctx->pc = 0x1b4bd0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 1));
    // 0x1b4bd4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b4bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b4bd8: 0x8c28440c  lw          $t0, 0x440C($at)
    ctx->pc = 0x1b4bd8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1b4bdc: 0x24424770  addiu       $v0, $v0, 0x4770
    ctx->pc = 0x1b4bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18288));
    // 0x1b4be0: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1b4be0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1b4be4: 0x3c05000a  lui         $a1, 0xA
    ctx->pc = 0x1b4be4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)10 << 16));
    // 0x1b4be8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b4be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b4bec: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1b4becu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b4bf0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1b4bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b4bf4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b4bf4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4bf8: 0x1058821  addu        $s1, $t0, $a1
    ctx->pc = 0x1b4bf8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1b4bfc: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1B4BFCu;
    SET_GPR_U32(ctx, 31, 0x1B4C04u);
    ctx->pc = 0x1B4C00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4BFCu;
            // 0x1b4c00: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C04u; }
        if (ctx->pc != 0x1B4C04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C04u; }
        if (ctx->pc != 0x1B4C04u) { return; }
    }
    ctx->pc = 0x1B4C04u;
label_1b4c04:
    // 0x1b4c04: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B4C04u;
    {
        const bool branch_taken_0x1b4c04 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1B4C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C04u;
            // 0x1b4c08: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4c04) {
            ctx->pc = 0x1B4C30u;
            goto label_1b4c30;
        }
    }
    ctx->pc = 0x1B4C0Cu;
    // 0x1b4c0c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b4c0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4c10: 0x94274414  lhu         $a3, 0x4414($at)
    ctx->pc = 0x1b4c10u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b4c14: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1b4c14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4c18: 0xc06d404  jal         func_1B5010
    ctx->pc = 0x1B4C18u;
    SET_GPR_U32(ctx, 31, 0x1B4C20u);
    ctx->pc = 0x1B4C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C18u;
            // 0x1b4c1c: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5010u;
    if (runtime->hasFunction(0x1B5010u)) {
        auto targetFn = runtime->lookupFunction(0x1B5010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C20u; }
        if (ctx->pc != 0x1B4C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5010_0x1b5010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C20u; }
        if (ctx->pc != 0x1B4C20u) { return; }
    }
    ctx->pc = 0x1B4C20u;
label_1b4c20:
    // 0x1b4c20: 0xc06d568  jal         func_1B55A0
    ctx->pc = 0x1B4C20u;
    SET_GPR_U32(ctx, 31, 0x1B4C28u);
    ctx->pc = 0x1B55A0u;
    if (runtime->hasFunction(0x1B55A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C28u; }
        if (ctx->pc != 0x1B4C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55A0_0x1b55a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C28u; }
        if (ctx->pc != 0x1B4C28u) { return; }
    }
    ctx->pc = 0x1B4C28u;
label_1b4c28:
    // 0x1b4c28: 0xc06d588  jal         func_1B5620
    ctx->pc = 0x1B4C28u;
    SET_GPR_U32(ctx, 31, 0x1B4C30u);
    ctx->pc = 0x1B4C2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C28u;
            // 0x1b4c2c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5620u;
    if (runtime->hasFunction(0x1B5620u)) {
        auto targetFn = runtime->lookupFunction(0x1B5620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C30u; }
        if (ctx->pc != 0x1B4C30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5620_0x1b5620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4C30u; }
        if (ctx->pc != 0x1B4C30u) { return; }
    }
    ctx->pc = 0x1B4C30u;
label_1b4c30:
    // 0x1b4c30: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b4c30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b4c34: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b4c34u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4c38: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4c38u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4c3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4C3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4C40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4C3Cu;
            // 0x1b4c40: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4BC8u: goto label_1b4bc8;
            case 0x1B4C04u: goto label_1b4c04;
            case 0x1B4C20u: goto label_1b4c20;
            case 0x1B4C28u: goto label_1b4c28;
            case 0x1B4C30u: goto label_1b4c30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4C44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

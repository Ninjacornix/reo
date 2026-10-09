#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AEA70
// Address: 0x1aea70 - 0x1aeb00
void sub_001AEA70_0x1aea70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AEA70_0x1aea70");
#endif

    switch (ctx->pc) {
        case 0x1aea8cu: goto label_1aea8c;
        case 0x1aeab4u: goto label_1aeab4;
        case 0x1aeac0u: goto label_1aeac0;
        case 0x1aeac8u: goto label_1aeac8;
        case 0x1aeaecu: goto label_1aeaec;
        default: break;
    }

    ctx->pc = 0x1aea70u;

    // 0x1aea70: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1aea70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1aea74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1aea74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1aea78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1aea78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1aea7c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1aea7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aea80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aea80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aea84: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AEA84u;
    SET_GPR_U32(ctx, 31, 0x1AEA8Cu);
    ctx->pc = 0x1AEA88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA84u;
            // 0x1aea88: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA8Cu; }
        if (ctx->pc != 0x1AEA8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEA8Cu; }
        if (ctx->pc != 0x1AEA8Cu) { return; }
    }
    ctx->pc = 0x1AEA8Cu;
label_1aea8c:
    // 0x1aea8c: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1AEA8Cu;
    {
        const bool branch_taken_0x1aea8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEA8Cu;
            // 0x1aea90: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aea8c) {
            ctx->pc = 0x1AEAECu;
            goto label_1aeaec;
        }
    }
    ctx->pc = 0x1AEA94u;
    // 0x1aea94: 0x112080  sll         $a0, $s1, 2
    ctx->pc = 0x1aea94u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1aea98: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1aea98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1aea9c: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1aea9cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aeaa0: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aeaa0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aeaa4: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AEAA4u;
    {
        const bool branch_taken_0x1aeaa4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aeaa4) {
            ctx->pc = 0x1AEAECu;
            goto label_1aeaec;
        }
    }
    ctx->pc = 0x1AEAACu;
    // 0x1aeaac: 0xc04aa3c  jal         func_12A8F0
    ctx->pc = 0x1AEAACu;
    SET_GPR_U32(ctx, 31, 0x1AEAB4u);
    ctx->pc = 0x12A8F0u;
    if (runtime->hasFunction(0x12A8F0u)) {
        auto targetFn = runtime->lookupFunction(0x12A8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAB4u; }
        if (ctx->pc != 0x1AEAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A8F0_0x12a8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAB4u; }
        if (ctx->pc != 0x1AEAB4u) { return; }
    }
    ctx->pc = 0x1AEAB4u;
label_1aeab4:
    // 0x1aeab4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aeab4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aeab8: 0xc04aa0c  jal         func_12A830
    ctx->pc = 0x1AEAB8u;
    SET_GPR_U32(ctx, 31, 0x1AEAC0u);
    ctx->pc = 0x1AEABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAB8u;
            // 0x1aeabc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A830u;
    if (runtime->hasFunction(0x12A830u)) {
        auto targetFn = runtime->lookupFunction(0x12A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC0u; }
        if (ctx->pc != 0x1AEAC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A830_0x12a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC0u; }
        if (ctx->pc != 0x1AEAC0u) { return; }
    }
    ctx->pc = 0x1AEAC0u;
label_1aeac0:
    // 0x1aeac0: 0xc04a9e0  jal         func_12A780
    ctx->pc = 0x1AEAC0u;
    SET_GPR_U32(ctx, 31, 0x1AEAC8u);
    ctx->pc = 0x1AEAC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAC0u;
            // 0x1aeac4: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A780u;
    if (runtime->hasFunction(0x12A780u)) {
        auto targetFn = runtime->lookupFunction(0x12A780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC8u; }
        if (ctx->pc != 0x1AEAC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A780_0x12a780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAC8u; }
        if (ctx->pc != 0x1AEAC8u) { return; }
    }
    ctx->pc = 0x1AEAC8u;
label_1aeac8:
    // 0x1aeac8: 0x111840  sll         $v1, $s1, 1
    ctx->pc = 0x1aeac8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1aeacc: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1aeaccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1aead0: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1aead0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1aead4: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1aead4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1aead8: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1aead8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1aeadc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1aeadcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1aeae0: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1aeae0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1aeae4: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1AEAE4u;
    SET_GPR_U32(ctx, 31, 0x1AEAECu);
    ctx->pc = 0x1AEAE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAE4u;
            // 0x1aeae8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAECu; }
        if (ctx->pc != 0x1AEAECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEAECu; }
        if (ctx->pc != 0x1AEAECu) { return; }
    }
    ctx->pc = 0x1AEAECu;
label_1aeaec:
    // 0x1aeaec: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1aeaecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1aeaf0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1aeaf0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aeaf4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aeaf4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aeaf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEAF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEAF8u;
            // 0x1aeafc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AEA8Cu: goto label_1aea8c;
            case 0x1AEAB4u: goto label_1aeab4;
            case 0x1AEAC0u: goto label_1aeac0;
            case 0x1AEAC8u: goto label_1aeac8;
            case 0x1AEAECu: goto label_1aeaec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEB00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

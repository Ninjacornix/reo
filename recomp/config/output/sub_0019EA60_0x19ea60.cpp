#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019EA60
// Address: 0x19ea60 - 0x19eb10
void sub_0019EA60_0x19ea60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019EA60_0x19ea60");
#endif

    switch (ctx->pc) {
        case 0x19ea84u: goto label_19ea84;
        case 0x19eaa0u: goto label_19eaa0;
        case 0x19eac8u: goto label_19eac8;
        case 0x19eae8u: goto label_19eae8;
        default: break;
    }

    ctx->pc = 0x19ea60u;

    // 0x19ea60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x19ea60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x19ea64: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ea64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ea68: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x19ea68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x19ea6c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19ea6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ea70: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19ea70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19ea74: 0xac20be80  sw          $zero, -0x4180($at)
    ctx->pc = 0x19ea74u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950528), GPR_U32(ctx, 0));
    // 0x19ea78: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x19ea78u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ea7c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ea7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ea80: 0xac22fee8  sw          $v0, -0x118($at)
    ctx->pc = 0x19ea80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967016), GPR_U32(ctx, 2));
label_19ea84:
    // 0x19ea84: 0x3c02002a  lui         $v0, 0x2A
    ctx->pc = 0x19ea84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)42 << 16));
    // 0x19ea88: 0x1018c0  sll         $v1, $s0, 3
    ctx->pc = 0x19ea88u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x19ea8c: 0x2442be90  addiu       $v0, $v0, -0x4170
    ctx->pc = 0x19ea8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294950544));
    // 0x19ea90: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19ea90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ea94: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x19ea94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x19ea98: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19EA98u;
    SET_GPR_U32(ctx, 31, 0x19EAA0u);
    ctx->pc = 0x19EA9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19EA98u;
            // 0x19ea9c: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EAA0u; }
        if (ctx->pc != 0x19EAA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EAA0u; }
        if (ctx->pc != 0x19EAA0u) { return; }
    }
    ctx->pc = 0x19EAA0u;
label_19eaa0:
    // 0x19eaa0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x19eaa0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x19eaa4: 0x2a020006  slti        $v0, $s0, 0x6
    ctx->pc = 0x19eaa4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x19eaa8: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x19EAA8u;
    {
        const bool branch_taken_0x19eaa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x19eaa8) {
            ctx->pc = 0x19EA84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19ea84;
        }
    }
    ctx->pc = 0x19EAB0u;
    // 0x19eab0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19eab0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19eab4: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x19eab4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19eab8: 0xac20bec8  sw          $zero, -0x4138($at)
    ctx->pc = 0x19eab8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950600), GPR_U32(ctx, 0));
    // 0x19eabc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19eabcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19eac0: 0xac20bed0  sw          $zero, -0x4130($at)
    ctx->pc = 0x19eac0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950608), GPR_U32(ctx, 0));
    // 0x19eac4: 0x1018c0  sll         $v1, $s0, 3
    ctx->pc = 0x19eac4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
label_19eac8:
    // 0x19eac8: 0x3c02002a  lui         $v0, 0x2A
    ctx->pc = 0x19eac8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)42 << 16));
    // 0x19eacc: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x19eaccu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x19ead0: 0x2442bee0  addiu       $v0, $v0, -0x4120
    ctx->pc = 0x19ead0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294950624));
    // 0x19ead4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x19ead4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x19ead8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19ead8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19eadc: 0x2406001c  addiu       $a2, $zero, 0x1C
    ctx->pc = 0x19eadcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x19eae0: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19EAE0u;
    SET_GPR_U32(ctx, 31, 0x19EAE8u);
    ctx->pc = 0x19EAE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19EAE0u;
            // 0x19eae4: 0x432021  addu        $a0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EAE8u; }
        if (ctx->pc != 0x19EAE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EAE8u; }
        if (ctx->pc != 0x19EAE8u) { return; }
    }
    ctx->pc = 0x19EAE8u;
label_19eae8:
    // 0x19eae8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x19eae8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x19eaec: 0x2a030200  slti        $v1, $s0, 0x200
    ctx->pc = 0x19eaecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x19eaf0: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x19EAF0u;
    {
        const bool branch_taken_0x19eaf0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19EAF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EAF0u;
            // 0x19eaf4: 0x1018c0  sll         $v1, $s0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eaf0) {
            ctx->pc = 0x19EAC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19eac8;
        }
    }
    ctx->pc = 0x19EAF8u;
    // 0x19eaf8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x19eaf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19eafc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19eafcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19eb00: 0x3e00008  jr          $ra
    ctx->pc = 0x19EB00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19EB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB00u;
            // 0x19eb04: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19EA84u: goto label_19ea84;
            case 0x19EAA0u: goto label_19eaa0;
            case 0x19EAC8u: goto label_19eac8;
            case 0x19EAE8u: goto label_19eae8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19EB08u;
    // 0x19eb08: 0x0  nop
    ctx->pc = 0x19eb08u;
    // NOP
    // 0x19eb0c: 0x0  nop
    ctx->pc = 0x19eb0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

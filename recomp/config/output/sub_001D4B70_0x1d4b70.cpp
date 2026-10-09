#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4B70
// Address: 0x1d4b70 - 0x1d4c00
void sub_001D4B70_0x1d4b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4B70_0x1d4b70");
#endif

    switch (ctx->pc) {
        case 0x1d4b94u: goto label_1d4b94;
        case 0x1d4bc8u: goto label_1d4bc8;
        case 0x1d4bd8u: goto label_1d4bd8;
        default: break;
    }

    ctx->pc = 0x1d4b70u;

    // 0x1d4b70: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d4b70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d4b74: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4b74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4b78: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d4b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d4b7c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d4b7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4b80: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d4b80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4b84: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4b84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4b88: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1d4b88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4b8c: 0x8c32440c  lw          $s2, 0x440C($at)
    ctx->pc = 0x1d4b8cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4b90: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1d4b90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_1d4b94:
    // 0x1d4b94: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1d4b94u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d4b98: 0x460000f  bltz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1D4B98u;
    {
        const bool branch_taken_0x1d4b98 = (GPR_S64(ctx, 3) < 0);
        if (branch_taken_0x1d4b98) {
            ctx->pc = 0x1D4BD8u;
            goto label_1d4bd8;
        }
    }
    ctx->pc = 0x1D4BA0u;
    // 0x1d4ba0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d4ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d4ba4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d4ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d4ba8: 0x24426910  addiu       $v0, $v0, 0x6910
    ctx->pc = 0x1d4ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26896));
    // 0x1d4bac: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d4bacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4bb0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4bb4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d4bb4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4bb8: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1d4bb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d4bbc: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d4bc0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4BC0u;
    SET_GPR_U32(ctx, 31, 0x1D4BC8u);
    ctx->pc = 0x1D4BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4BC0u;
            // 0x1d4bc4: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4BC8u; }
        if (ctx->pc != 0x1D4BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4BC8u; }
        if (ctx->pc != 0x1D4BC8u) { return; }
    }
    ctx->pc = 0x1D4BC8u;
label_1d4bc8:
    // 0x1d4bc8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4BC8u;
    {
        const bool branch_taken_0x1d4bc8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4BC8u;
            // 0x1d4bcc: 0x26244011  addiu       $a0, $s1, 0x4011 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16401));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4bc8) {
            ctx->pc = 0x1D4BD8u;
            goto label_1d4bd8;
        }
    }
    ctx->pc = 0x1D4BD0u;
    // 0x1d4bd0: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D4BD0u;
    SET_GPR_U32(ctx, 31, 0x1D4BD8u);
    ctx->pc = 0x1D4BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4BD0u;
            // 0x1d4bd4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4BD8u; }
        if (ctx->pc != 0x1D4BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4BD8u; }
        if (ctx->pc != 0x1D4BD8u) { return; }
    }
    ctx->pc = 0x1D4BD8u;
label_1d4bd8:
    // 0x1d4bd8: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1d4bd8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1d4bdc: 0x2a230004  slti        $v1, $s1, 0x4
    ctx->pc = 0x1d4bdcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1d4be0: 0x1460ffec  bnez        $v1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1D4BE0u;
    {
        const bool branch_taken_0x1d4be0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4BE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4BE0u;
            // 0x1d4be4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4be0) {
            ctx->pc = 0x1D4B94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d4b94;
        }
    }
    ctx->pc = 0x1D4BE8u;
    // 0x1d4be8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d4be8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d4bec: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d4becu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4bf0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d4bf0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4bf4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4bf4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4bf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4BF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4BF8u;
            // 0x1d4bfc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BC8u: goto label_1d4bc8;
            case 0x1D4BD8u: goto label_1d4bd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4C00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

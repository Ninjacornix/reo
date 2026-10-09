#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6C70
// Address: 0x1b6c70 - 0x1b6d40
void sub_001B6C70_0x1b6c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6C70_0x1b6c70");
#endif

    switch (ctx->pc) {
        case 0x1b6ca0u: goto label_1b6ca0;
        case 0x1b6cb0u: goto label_1b6cb0;
        case 0x1b6cb8u: goto label_1b6cb8;
        case 0x1b6cfcu: goto label_1b6cfc;
        case 0x1b6d08u: goto label_1b6d08;
        default: break;
    }

    ctx->pc = 0x1b6c70u;

    // 0x1b6c70: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b6c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b6c74: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b6c74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b6c78: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b6c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b6c7c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b6c7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b6c80: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b6c80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b6c84: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b6c84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b6c88: 0x8c23aaf8  lw          $v1, -0x5508($at)
    ctx->pc = 0x1b6c88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945528)));
    // 0x1b6c8c: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b6c8cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b6c90: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6C90u;
    {
        const bool branch_taken_0x1b6c90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B6C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6C90u;
            // 0x1b6c94: 0x2610aaf0  addiu       $s0, $s0, -0x5510 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6c90) {
            ctx->pc = 0x1B6CA8u;
            goto label_1b6ca8;
        }
    }
    ctx->pc = 0x1B6C98u;
    // 0x1b6c98: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1B6C98u;
    SET_GPR_U32(ctx, 31, 0x1B6CA0u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6CA0u; }
        if (ctx->pc != 0x1B6CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6CA0u; }
        if (ctx->pc != 0x1B6CA0u) { return; }
    }
    ctx->pc = 0x1B6CA0u;
label_1b6ca0:
    // 0x1b6ca0: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1B6CA0u;
    {
        const bool branch_taken_0x1b6ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6CA0u;
            // 0x1b6ca4: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6ca0) {
            ctx->pc = 0x1B6D2Cu;
            goto label_1b6d2c;
        }
    }
    ctx->pc = 0x1B6CA8u;
label_1b6ca8:
    // 0x1b6ca8: 0xafa4003c  sw          $a0, 0x3C($sp)
    ctx->pc = 0x1b6ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 4));
    // 0x1b6cac: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b6cacu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b6cb0:
    // 0x1b6cb0: 0xc06d9b0  jal         func_1B66C0
    ctx->pc = 0x1B6CB0u;
    SET_GPR_U32(ctx, 31, 0x1B6CB8u);
    ctx->pc = 0x1B6CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6CB0u;
            // 0x1b6cb4: 0x27a4003c  addiu       $a0, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B66C0u;
    if (runtime->hasFunction(0x1B66C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B66C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6CB8u; }
        if (ctx->pc != 0x1B6CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B66C0_0x1b66c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6CB8u; }
        if (ctx->pc != 0x1B6CB8u) { return; }
    }
    ctx->pc = 0x1B6CB8u;
label_1b6cb8:
    // 0x1b6cb8: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1B6CB8u;
    {
        const bool branch_taken_0x1b6cb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6cb8) {
            ctx->pc = 0x1B6D24u;
            goto label_1b6d24;
        }
    }
    ctx->pc = 0x1B6CC0u;
    // 0x1b6cc0: 0x8e030094  lw          $v1, 0x94($s0)
    ctx->pc = 0x1b6cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1b6cc4: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1B6CC4u;
    {
        const bool branch_taken_0x1b6cc4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6CC4u;
            // 0x1b6cc8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6cc4) {
            ctx->pc = 0x1B6CF4u;
            goto label_1b6cf4;
        }
    }
    ctx->pc = 0x1B6CCCu;
    // 0x1b6ccc: 0x28410010  slti        $at, $v0, 0x10
    ctx->pc = 0x1b6cccu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1b6cd0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6CD0u;
    {
        const bool branch_taken_0x1b6cd0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6CD0u;
            // 0x1b6cd4: 0x28410080  slti        $at, $v0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6cd0) {
            ctx->pc = 0x1B6CE0u;
            goto label_1b6ce0;
        }
    }
    ctx->pc = 0x1B6CD8u;
    // 0x1b6cd8: 0x1000fff5  b           . + 4 + (-0xB << 2)
    ctx->pc = 0x1B6CD8u;
    {
        const bool branch_taken_0x1b6cd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6CD8u;
            // 0x1b6cdc: 0x26310002  addiu       $s1, $s1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6cd8) {
            ctx->pc = 0x1B6CB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b6cb0;
        }
    }
    ctx->pc = 0x1B6CE0u;
label_1b6ce0:
    // 0x1b6ce0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6CE0u;
    {
        const bool branch_taken_0x1b6ce0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6ce0) {
            ctx->pc = 0x1B6CF0u;
            goto label_1b6cf0;
        }
    }
    ctx->pc = 0x1B6CE8u;
    // 0x1b6ce8: 0x1000fff1  b           . + 4 + (-0xF << 2)
    ctx->pc = 0x1B6CE8u;
    {
        const bool branch_taken_0x1b6ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6CECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6CE8u;
            // 0x1b6cec: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6ce8) {
            ctx->pc = 0x1B6CB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b6cb0;
        }
    }
    ctx->pc = 0x1B6CF0u;
label_1b6cf0:
    // 0x1b6cf0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b6cf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b6cf4:
    // 0x1b6cf4: 0xc06d9fc  jal         func_1B67F0
    ctx->pc = 0x1B6CF4u;
    SET_GPR_U32(ctx, 31, 0x1B6CFCu);
    ctx->pc = 0x1B6CF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6CF4u;
            // 0x1b6cf8: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B67F0u;
    if (runtime->hasFunction(0x1B67F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B67F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6CFCu; }
        if (ctx->pc != 0x1B6CFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B67F0_0x1b67f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6CFCu; }
        if (ctx->pc != 0x1B6CFCu) { return; }
    }
    ctx->pc = 0x1B6CFCu;
label_1b6cfc:
    // 0x1b6cfc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b6cfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6d00: 0xc06da8c  jal         func_1B6A30
    ctx->pc = 0x1B6D00u;
    SET_GPR_U32(ctx, 31, 0x1B6D08u);
    ctx->pc = 0x1B6D04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D00u;
            // 0x1b6d04: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6A30u;
    if (runtime->hasFunction(0x1B6A30u)) {
        auto targetFn = runtime->lookupFunction(0x1B6A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6D08u; }
        if (ctx->pc != 0x1B6D08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6A30_0x1b6a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6D08u; }
        if (ctx->pc != 0x1B6D08u) { return; }
    }
    ctx->pc = 0x1B6D08u;
label_1b6d08:
    // 0x1b6d08: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6D08u;
    {
        const bool branch_taken_0x1b6d08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b6d08) {
            ctx->pc = 0x1B6D18u;
            goto label_1b6d18;
        }
    }
    ctx->pc = 0x1B6D10u;
    // 0x1b6d10: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B6D10u;
    {
        const bool branch_taken_0x1b6d10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D10u;
            // 0x1b6d14: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6d10) {
            ctx->pc = 0x1B6D1Cu;
            goto label_1b6d1c;
        }
    }
    ctx->pc = 0x1B6D18u;
label_1b6d18:
    // 0x1b6d18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b6d18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b6d1c:
    // 0x1b6d1c: 0x1000ffe4  b           . + 4 + (-0x1C << 2)
    ctx->pc = 0x1B6D1Cu;
    {
        const bool branch_taken_0x1b6d1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D1Cu;
            // 0x1b6d20: 0x2228821  addu        $s1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6d1c) {
            ctx->pc = 0x1B6CB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b6cb0;
        }
    }
    ctx->pc = 0x1B6D24u;
label_1b6d24:
    // 0x1b6d24: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1b6d24u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b6d28: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b6d28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1b6d2c:
    // 0x1b6d2c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b6d2cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b6d30: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b6d30u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b6d34: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6D34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6D34u;
            // 0x1b6d38: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B6CA0u: goto label_1b6ca0;
            case 0x1B6CA8u: goto label_1b6ca8;
            case 0x1B6CB0u: goto label_1b6cb0;
            case 0x1B6CB8u: goto label_1b6cb8;
            case 0x1B6CE0u: goto label_1b6ce0;
            case 0x1B6CF0u: goto label_1b6cf0;
            case 0x1B6CF4u: goto label_1b6cf4;
            case 0x1B6CFCu: goto label_1b6cfc;
            case 0x1B6D08u: goto label_1b6d08;
            case 0x1B6D18u: goto label_1b6d18;
            case 0x1B6D1Cu: goto label_1b6d1c;
            case 0x1B6D24u: goto label_1b6d24;
            case 0x1B6D2Cu: goto label_1b6d2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B6D3Cu;
    // 0x1b6d3c: 0x0  nop
    ctx->pc = 0x1b6d3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

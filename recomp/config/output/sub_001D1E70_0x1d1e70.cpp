#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1E70
// Address: 0x1d1e70 - 0x1d1f30
void sub_001D1E70_0x1d1e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1E70_0x1d1e70");
#endif

    switch (ctx->pc) {
        case 0x1d1eb4u: goto label_1d1eb4;
        case 0x1d1ed0u: goto label_1d1ed0;
        case 0x1d1f00u: goto label_1d1f00;
        case 0x1d1f24u: goto label_1d1f24;
        default: break;
    }

    ctx->pc = 0x1d1e70u;

    // 0x1d1e70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d1e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d1e74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d1e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d1e78: 0x94820bb4  lhu         $v0, 0xBB4($a0)
    ctx->pc = 0x1d1e78u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2996)));
    // 0x1d1e7c: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1D1E7Cu;
    {
        const bool branch_taken_0x1d1e7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1e7c) {
            ctx->pc = 0x1D1ED8u;
            goto label_1d1ed8;
        }
    }
    ctx->pc = 0x1D1E84u;
    // 0x1d1e84: 0x9083054d  lbu         $v1, 0x54D($a0)
    ctx->pc = 0x1d1e84u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1357)));
    // 0x1d1e88: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1d1e88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1d1e8c: 0x34468000  ori         $a2, $v0, 0x8000
    ctx->pc = 0x1d1e8cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x1d1e90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d1e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1e94: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D1E94u;
    {
        const bool branch_taken_0x1d1e94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d1e94) {
            ctx->pc = 0x1D1EBCu;
            goto label_1d1ebc;
        }
    }
    ctx->pc = 0x1D1E9Cu;
    // 0x1d1e9c: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1e9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1ea0: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1ea0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1ea4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1ea8: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1d1ea8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1eac: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1EACu;
    SET_GPR_U32(ctx, 31, 0x1D1EB4u);
    ctx->pc = 0x1D1EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EACu;
            // 0x1d1eb0: 0x24451100  addiu       $a1, $v0, 0x1100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1EB4u; }
        if (ctx->pc != 0x1D1EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1EB4u; }
        if (ctx->pc != 0x1D1EB4u) { return; }
    }
    ctx->pc = 0x1D1EB4u;
label_1d1eb4:
    // 0x1d1eb4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D1EB4u;
    {
        const bool branch_taken_0x1d1eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D1EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EB4u;
            // 0x1d1eb8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1eb4) {
            ctx->pc = 0x1D1F28u;
            goto label_1d1f28;
        }
    }
    ctx->pc = 0x1D1EBCu;
label_1d1ebc:
    // 0x1d1ebc: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1ebcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1ec0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1ec4: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x1d1ec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ec8: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1EC8u;
    SET_GPR_U32(ctx, 31, 0x1D1ED0u);
    ctx->pc = 0x1D1ECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EC8u;
            // 0x1d1ecc: 0x24451000  addiu       $a1, $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1ED0u; }
        if (ctx->pc != 0x1D1ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1ED0u; }
        if (ctx->pc != 0x1D1ED0u) { return; }
    }
    ctx->pc = 0x1D1ED0u;
label_1d1ed0:
    // 0x1d1ed0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D1ED0u;
    {
        const bool branch_taken_0x1d1ed0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1ed0) {
            ctx->pc = 0x1D1F24u;
            goto label_1d1f24;
        }
    }
    ctx->pc = 0x1D1ED8u;
label_1d1ed8:
    // 0x1d1ed8: 0x9083054d  lbu         $v1, 0x54D($a0)
    ctx->pc = 0x1d1ed8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1357)));
    // 0x1d1edc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d1edcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1ee0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D1EE0u;
    {
        const bool branch_taken_0x1d1ee0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D1EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EE0u;
            // 0x1d1ee4: 0x30c200ff  andi        $v0, $a2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1ee0) {
            ctx->pc = 0x1D1F08u;
            goto label_1d1f08;
        }
    }
    ctx->pc = 0x1D1EE8u;
    // 0x1d1ee8: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1ee8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1eec: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1eecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1ef0: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1ef4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1d1ef4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1ef8: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1EF8u;
    SET_GPR_U32(ctx, 31, 0x1D1F00u);
    ctx->pc = 0x1D1EFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1EF8u;
            // 0x1d1efc: 0x24451100  addiu       $a1, $v0, 0x1100 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F00u; }
        if (ctx->pc != 0x1D1F00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F00u; }
        if (ctx->pc != 0x1D1F00u) { return; }
    }
    ctx->pc = 0x1D1F00u;
label_1d1f00:
    // 0x1d1f00: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D1F00u;
    {
        const bool branch_taken_0x1d1f00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1f00) {
            ctx->pc = 0x1D1F24u;
            goto label_1d1f24;
        }
    }
    ctx->pc = 0x1D1F08u;
label_1d1f08:
    // 0x1d1f08: 0x30a300ff  andi        $v1, $a1, 0xFF
    ctx->pc = 0x1d1f08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1f0c: 0x22c00  sll         $a1, $v0, 16
    ctx->pc = 0x1d1f0cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x1d1f10: 0x90820003  lbu         $v0, 0x3($a0)
    ctx->pc = 0x1d1f10u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1d1f14: 0xa32025  or          $a0, $a1, $v1
    ctx->pc = 0x1d1f14u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1d1f18: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1d1f18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1d1f1c: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D1F1Cu;
    SET_GPR_U32(ctx, 31, 0x1D1F24u);
    ctx->pc = 0x1D1F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1F1Cu;
            // 0x1d1f20: 0x24451000  addiu       $a1, $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F24u; }
        if (ctx->pc != 0x1D1F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1F24u; }
        if (ctx->pc != 0x1D1F24u) { return; }
    }
    ctx->pc = 0x1D1F24u;
label_1d1f24:
    // 0x1d1f24: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d1f24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1d1f28:
    // 0x1d1f28: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1F28u;
            // 0x1d1f2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1EB4u: goto label_1d1eb4;
            case 0x1D1EBCu: goto label_1d1ebc;
            case 0x1D1ED0u: goto label_1d1ed0;
            case 0x1D1ED8u: goto label_1d1ed8;
            case 0x1D1F00u: goto label_1d1f00;
            case 0x1D1F08u: goto label_1d1f08;
            case 0x1D1F24u: goto label_1d1f24;
            case 0x1D1F28u: goto label_1d1f28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1F30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

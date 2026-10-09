#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BFF70
// Address: 0x1bff70 - 0x1c0020
void sub_001BFF70_0x1bff70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BFF70_0x1bff70");
#endif

    switch (ctx->pc) {
        case 0x1bffa4u: goto label_1bffa4;
        case 0x1bffc8u: goto label_1bffc8;
        case 0x1bfff0u: goto label_1bfff0;
        default: break;
    }

    ctx->pc = 0x1bff70u;

    // 0x1bff70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bff70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bff74: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bff74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bff78: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bff78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bff7c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bff7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bff80: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1bff80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bff84: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1BFF84u;
    {
        const bool branch_taken_0x1bff84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BFF88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFF84u;
            // 0x1bff88: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bff84) {
            ctx->pc = 0x1BFFE8u;
            goto label_1bffe8;
        }
    }
    ctx->pc = 0x1BFF8Cu;
    // 0x1bff8c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFF8Cu;
    {
        const bool branch_taken_0x1bff8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bff8c) {
            ctx->pc = 0x1BFF9Cu;
            goto label_1bff9c;
        }
    }
    ctx->pc = 0x1BFF94u;
    // 0x1bff94: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1BFF94u;
    {
        const bool branch_taken_0x1bff94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFF98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFF94u;
            // 0x1bff98: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bff94) {
            ctx->pc = 0x1C000Cu;
            goto label_1c000c;
        }
    }
    ctx->pc = 0x1BFF9Cu;
label_1bff9c:
    // 0x1bff9c: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFF9Cu;
    SET_GPR_U32(ctx, 31, 0x1BFFA4u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFFA4u; }
        if (ctx->pc != 0x1BFFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFFA4u; }
        if (ctx->pc != 0x1BFFA4u) { return; }
    }
    ctx->pc = 0x1BFFA4u;
label_1bffa4:
    // 0x1bffa4: 0x4400018  bltz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1BFFA4u;
    {
        const bool branch_taken_0x1bffa4 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bffa4) {
            ctx->pc = 0x1C0008u;
            goto label_1c0008;
        }
    }
    ctx->pc = 0x1BFFACu;
    // 0x1bffac: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bffacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bffb0: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bffb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bffb4: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bffb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bffb8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bffb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bffbc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bffbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bffc0: 0xc0603d8  jal         func_180F60
    ctx->pc = 0x1BFFC0u;
    SET_GPR_U32(ctx, 31, 0x1BFFC8u);
    ctx->pc = 0x1BFFC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFFC0u;
            // 0x1bffc4: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180F60u;
    if (runtime->hasFunction(0x180F60u)) {
        auto targetFn = runtime->lookupFunction(0x180F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFFC8u; }
        if (ctx->pc != 0x1BFFC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180F60_0x180f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFFC8u; }
        if (ctx->pc != 0x1BFFC8u) { return; }
    }
    ctx->pc = 0x1BFFC8u;
label_1bffc8:
    // 0x1bffc8: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFFC8u;
    {
        const bool branch_taken_0x1bffc8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bffc8) {
            ctx->pc = 0x1BFFD8u;
            goto label_1bffd8;
        }
    }
    ctx->pc = 0x1BFFD0u;
    // 0x1bffd0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BFFD0u;
    {
        const bool branch_taken_0x1bffd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFFD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFFD0u;
            // 0x1bffd4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bffd0) {
            ctx->pc = 0x1C000Cu;
            goto label_1c000c;
        }
    }
    ctx->pc = 0x1BFFD8u;
label_1bffd8:
    // 0x1bffd8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bffd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bffdc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bffdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bffe0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1BFFE0u;
    {
        const bool branch_taken_0x1bffe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFFE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFFE0u;
            // 0x1bffe4: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bffe0) {
            ctx->pc = 0x1C0008u;
            goto label_1c0008;
        }
    }
    ctx->pc = 0x1BFFE8u;
label_1bffe8:
    // 0x1bffe8: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFFE8u;
    SET_GPR_U32(ctx, 31, 0x1BFFF0u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFFF0u; }
        if (ctx->pc != 0x1BFFF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFFF0u; }
        if (ctx->pc != 0x1BFFF0u) { return; }
    }
    ctx->pc = 0x1BFFF0u;
label_1bfff0:
    // 0x1bfff0: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BFFF0u;
    {
        const bool branch_taken_0x1bfff0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfff0) {
            ctx->pc = 0x1C0008u;
            goto label_1c0008;
        }
    }
    ctx->pc = 0x1BFFF8u;
    // 0x1bfff8: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfff8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfffc: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1bfffcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c0000: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C0000u;
    {
        const bool branch_taken_0x1c0000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0000u;
            // 0x1c0004: 0x40102a  slt         $v0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0000) {
            ctx->pc = 0x1C000Cu;
            goto label_1c000c;
        }
    }
    ctx->pc = 0x1C0008u;
label_1c0008:
    // 0x1c0008: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c0008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1c000c:
    // 0x1c000c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c000cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0010: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0010u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0014: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0014u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0014u;
            // 0x1c0018: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BFF9Cu: goto label_1bff9c;
            case 0x1BFFA4u: goto label_1bffa4;
            case 0x1BFFC8u: goto label_1bffc8;
            case 0x1BFFD8u: goto label_1bffd8;
            case 0x1BFFE8u: goto label_1bffe8;
            case 0x1BFFF0u: goto label_1bfff0;
            case 0x1C0008u: goto label_1c0008;
            case 0x1C000Cu: goto label_1c000c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C001Cu;
    // 0x1c001c: 0x0  nop
    ctx->pc = 0x1c001cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

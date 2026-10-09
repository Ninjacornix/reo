#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C0020
// Address: 0x1c0020 - 0x1c00d0
void sub_001C0020_0x1c0020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C0020_0x1c0020");
#endif

    switch (ctx->pc) {
        case 0x1c0054u: goto label_1c0054;
        case 0x1c0078u: goto label_1c0078;
        case 0x1c00a0u: goto label_1c00a0;
        default: break;
    }

    ctx->pc = 0x1c0020u;

    // 0x1c0020: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c0020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c0024: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c0024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0028: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c0028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c002c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c002cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c0030: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1c0030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c0034: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1C0034u;
    {
        const bool branch_taken_0x1c0034 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C0038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0034u;
            // 0x1c0038: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0034) {
            ctx->pc = 0x1C0098u;
            goto label_1c0098;
        }
    }
    ctx->pc = 0x1C003Cu;
    // 0x1c003c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C003Cu;
    {
        const bool branch_taken_0x1c003c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c003c) {
            ctx->pc = 0x1C004Cu;
            goto label_1c004c;
        }
    }
    ctx->pc = 0x1C0044u;
    // 0x1c0044: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1C0044u;
    {
        const bool branch_taken_0x1c0044 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0044u;
            // 0x1c0048: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0044) {
            ctx->pc = 0x1C00BCu;
            goto label_1c00bc;
        }
    }
    ctx->pc = 0x1C004Cu;
label_1c004c:
    // 0x1c004c: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1C004Cu;
    SET_GPR_U32(ctx, 31, 0x1C0054u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0054u; }
        if (ctx->pc != 0x1C0054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0054u; }
        if (ctx->pc != 0x1C0054u) { return; }
    }
    ctx->pc = 0x1C0054u;
label_1c0054:
    // 0x1c0054: 0x4400018  bltz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1C0054u;
    {
        const bool branch_taken_0x1c0054 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c0054) {
            ctx->pc = 0x1C00B8u;
            goto label_1c00b8;
        }
    }
    ctx->pc = 0x1C005Cu;
    // 0x1c005c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1c005cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1c0060: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1c0060u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1c0064: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1c0064u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1c0068: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c0068u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c006c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c006cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c0070: 0xc0603f8  jal         func_180FE0
    ctx->pc = 0x1C0070u;
    SET_GPR_U32(ctx, 31, 0x1C0078u);
    ctx->pc = 0x1C0074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0070u;
            // 0x1c0074: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180FE0u;
    if (runtime->hasFunction(0x180FE0u)) {
        auto targetFn = runtime->lookupFunction(0x180FE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0078u; }
        if (ctx->pc != 0x1C0078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180FE0_0x180fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0078u; }
        if (ctx->pc != 0x1C0078u) { return; }
    }
    ctx->pc = 0x1C0078u;
label_1c0078:
    // 0x1c0078: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0078u;
    {
        const bool branch_taken_0x1c0078 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1c0078) {
            ctx->pc = 0x1C0088u;
            goto label_1c0088;
        }
    }
    ctx->pc = 0x1C0080u;
    // 0x1c0080: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1C0080u;
    {
        const bool branch_taken_0x1c0080 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0080u;
            // 0x1c0084: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0080) {
            ctx->pc = 0x1C00BCu;
            goto label_1c00bc;
        }
    }
    ctx->pc = 0x1C0088u;
label_1c0088:
    // 0x1c0088: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1c0088u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c008c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c008cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c0090: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C0090u;
    {
        const bool branch_taken_0x1c0090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0090u;
            // 0x1c0094: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0090) {
            ctx->pc = 0x1C00B8u;
            goto label_1c00b8;
        }
    }
    ctx->pc = 0x1C0098u;
label_1c0098:
    // 0x1c0098: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1C0098u;
    SET_GPR_U32(ctx, 31, 0x1C00A0u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C00A0u; }
        if (ctx->pc != 0x1C00A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C00A0u; }
        if (ctx->pc != 0x1C00A0u) { return; }
    }
    ctx->pc = 0x1C00A0u;
label_1c00a0:
    // 0x1c00a0: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C00A0u;
    {
        const bool branch_taken_0x1c00a0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c00a0) {
            ctx->pc = 0x1C00B8u;
            goto label_1c00b8;
        }
    }
    ctx->pc = 0x1C00A8u;
    // 0x1c00a8: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1c00a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1c00ac: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1c00acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c00b0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C00B0u;
    {
        const bool branch_taken_0x1c00b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C00B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C00B0u;
            // 0x1c00b4: 0x40102a  slt         $v0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c00b0) {
            ctx->pc = 0x1C00BCu;
            goto label_1c00bc;
        }
    }
    ctx->pc = 0x1C00B8u;
label_1c00b8:
    // 0x1c00b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c00b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1c00bc:
    // 0x1c00bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c00bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c00c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c00c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c00c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C00C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C00C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C00C4u;
            // 0x1c00c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C004Cu: goto label_1c004c;
            case 0x1C0054u: goto label_1c0054;
            case 0x1C0078u: goto label_1c0078;
            case 0x1C0088u: goto label_1c0088;
            case 0x1C0098u: goto label_1c0098;
            case 0x1C00A0u: goto label_1c00a0;
            case 0x1C00B8u: goto label_1c00b8;
            case 0x1C00BCu: goto label_1c00bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C00CCu;
    // 0x1c00cc: 0x0  nop
    ctx->pc = 0x1c00ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

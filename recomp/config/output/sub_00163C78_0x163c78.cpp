#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163C78
// Address: 0x163c78 - 0x163cf0
void sub_00163C78_0x163c78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163C78_0x163c78");
#endif

    switch (ctx->pc) {
        case 0x163cb8u: goto label_163cb8;
        case 0x163cc8u: goto label_163cc8;
        case 0x163cd0u: goto label_163cd0;
        case 0x163cd8u: goto label_163cd8;
        default: break;
    }

    ctx->pc = 0x163c78u;

    // 0x163c78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163c78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163c7c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163c7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163c80: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163c80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163c84: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x163c88: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x163c88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x163c8c: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x163c8cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x163c90: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x163C90u;
    {
        const bool branch_taken_0x163c90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x163C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163C90u;
            // 0x163c94: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163c90) {
            ctx->pc = 0x163CC8u;
            goto label_163cc8;
        }
    }
    ctx->pc = 0x163C98u;
    // 0x163c98: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x163c98u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x163c9c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x163c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x163ca0: 0x8c630530  lw          $v1, 0x530($v1)
    ctx->pc = 0x163ca0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1328)));
    // 0x163ca4: 0x600008  jr          $v1
    ctx->pc = 0x163CA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163CB0u: goto label_163cb0;
            case 0x163CC0u: goto label_163cc0;
            case 0x163CC8u: goto label_163cc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163CACu;
    // 0x163cac: 0x0  nop
    ctx->pc = 0x163cacu;
    // NOP
label_163cb0:
    // 0x163cb0: 0xc058e3a  jal         func_1638E8
    ctx->pc = 0x163CB0u;
    SET_GPR_U32(ctx, 31, 0x163CB8u);
    ctx->pc = 0x163CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163CB0u;
            // 0x163cb4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1638E8u;
    if (runtime->hasFunction(0x1638E8u)) {
        auto targetFn = runtime->lookupFunction(0x1638E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CB8u; }
        if (ctx->pc != 0x163CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001638E8_0x1638e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CB8u; }
        if (ctx->pc != 0x163CB8u) { return; }
    }
    ctx->pc = 0x163CB8u;
label_163cb8:
    // 0x163cb8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x163CB8u;
    {
        const bool branch_taken_0x163cb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x163cb8) {
            ctx->pc = 0x163CC8u;
            goto label_163cc8;
        }
    }
    ctx->pc = 0x163CC0u;
label_163cc0:
    // 0x163cc0: 0xc058efc  jal         func_163BF0
    ctx->pc = 0x163CC0u;
    SET_GPR_U32(ctx, 31, 0x163CC8u);
    ctx->pc = 0x163CC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163CC0u;
            // 0x163cc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163BF0u;
    if (runtime->hasFunction(0x163BF0u)) {
        auto targetFn = runtime->lookupFunction(0x163BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CC8u; }
        if (ctx->pc != 0x163CC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163BF0_0x163bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CC8u; }
        if (ctx->pc != 0x163CC8u) { return; }
    }
    ctx->pc = 0x163CC8u;
label_163cc8:
    // 0x163cc8: 0xc058f3c  jal         func_163CF0
    ctx->pc = 0x163CC8u;
    SET_GPR_U32(ctx, 31, 0x163CD0u);
    ctx->pc = 0x163CCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163CC8u;
            // 0x163ccc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163CF0u;
    if (runtime->hasFunction(0x163CF0u)) {
        auto targetFn = runtime->lookupFunction(0x163CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CD0u; }
        if (ctx->pc != 0x163CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163CF0_0x163cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CD0u; }
        if (ctx->pc != 0x163CD0u) { return; }
    }
    ctx->pc = 0x163CD0u;
label_163cd0:
    // 0x163cd0: 0xc057eae  jal         func_15FAB8
    ctx->pc = 0x163CD0u;
    SET_GPR_U32(ctx, 31, 0x163CD8u);
    ctx->pc = 0x163CD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163CD0u;
            // 0x163cd4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FAB8u;
    if (runtime->hasFunction(0x15FAB8u)) {
        auto targetFn = runtime->lookupFunction(0x15FAB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CD8u; }
        if (ctx->pc != 0x163CD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FAB8_0x15fab8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163CD8u; }
        if (ctx->pc != 0x163CD8u) { return; }
    }
    ctx->pc = 0x163CD8u;
label_163cd8:
    // 0x163cd8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x163cd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163cdc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163cdcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163ce0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163ce0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163ce4: 0x3e00008  jr          $ra
    ctx->pc = 0x163CE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163CE4u;
            // 0x163ce8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163CB0u: goto label_163cb0;
            case 0x163CB8u: goto label_163cb8;
            case 0x163CC0u: goto label_163cc0;
            case 0x163CC8u: goto label_163cc8;
            case 0x163CD0u: goto label_163cd0;
            case 0x163CD8u: goto label_163cd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163CECu;
    // 0x163cec: 0x0  nop
    ctx->pc = 0x163cecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135D60
// Address: 0x135d60 - 0x135dc8
void sub_00135D60_0x135d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135D60_0x135d60");
#endif

    switch (ctx->pc) {
        case 0x135d7cu: goto label_135d7c;
        case 0x135da0u: goto label_135da0;
        case 0x135db4u: goto label_135db4;
        default: break;
    }

    ctx->pc = 0x135d60u;

    // 0x135d60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135d64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135d68: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x135D68u;
    {
        const bool branch_taken_0x135d68 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D68u;
            // 0x135d6c: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135d68) {
            ctx->pc = 0x135D88u;
            goto label_135d88;
        }
    }
    ctx->pc = 0x135D70u;
    // 0x135d70: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135d70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135d74: 0xc04d480  jal         func_135200
    ctx->pc = 0x135D74u;
    SET_GPR_U32(ctx, 31, 0x135D7Cu);
    ctx->pc = 0x135D78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135D74u;
            // 0x135d78: 0x2484b9c8  addiu       $a0, $a0, -0x4638 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135D7Cu; }
        if (ctx->pc != 0x135D7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135D7Cu; }
        if (ctx->pc != 0x135D7Cu) { return; }
    }
    ctx->pc = 0x135D7Cu;
label_135d7c:
    // 0x135d7c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x135D7Cu;
    {
        const bool branch_taken_0x135d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D7Cu;
            // 0x135d80: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135d7c) {
            ctx->pc = 0x135DB8u;
            goto label_135db8;
        }
    }
    ctx->pc = 0x135D84u;
    // 0x135d84: 0x0  nop
    ctx->pc = 0x135d84u;
    // NOP
label_135d88:
    // 0x135d88: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x135d88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x135d8c: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x135d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x135d90: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x135D90u;
    {
        const bool branch_taken_0x135d90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135d90) {
            ctx->pc = 0x135D94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135D90u;
            // 0x135d94: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135DA8u;
            goto label_135da8;
        }
    }
    ctx->pc = 0x135D98u;
    // 0x135d98: 0x40f809  jalr        $v0
    ctx->pc = 0x135D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135DA0u);
        ctx->pc = 0x135D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135D98u;
            // 0x135d9c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135DA0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135D7Cu: goto label_135d7c;
            case 0x135D88u: goto label_135d88;
            case 0x135DA0u: goto label_135da0;
            case 0x135DA8u: goto label_135da8;
            case 0x135DB4u: goto label_135db4;
            case 0x135DB8u: goto label_135db8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135DA0u; }
            if (ctx->pc != 0x135DA0u) { return; }
        }
        }
    }
    ctx->pc = 0x135DA0u;
label_135da0:
    // 0x135da0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x135DA0u;
    {
        const bool branch_taken_0x135da0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135DA0u;
            // 0x135da4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135da0) {
            ctx->pc = 0x135DB4u;
            goto label_135db4;
        }
    }
    ctx->pc = 0x135DA8u;
label_135da8:
    // 0x135da8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x135da8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135dac: 0xc04d480  jal         func_135200
    ctx->pc = 0x135DACu;
    SET_GPR_U32(ctx, 31, 0x135DB4u);
    ctx->pc = 0x135DB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135DACu;
            // 0x135db0: 0x2484b9e8  addiu       $a0, $a0, -0x4618 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135DB4u; }
        if (ctx->pc != 0x135DB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135DB4u; }
        if (ctx->pc != 0x135DB4u) { return; }
    }
    ctx->pc = 0x135DB4u;
label_135db4:
    // 0x135db4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x135db4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_135db8:
    // 0x135db8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135db8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135dbc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135dbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x135DC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135DC0u;
            // 0x135dc4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135D7Cu: goto label_135d7c;
            case 0x135D88u: goto label_135d88;
            case 0x135DA0u: goto label_135da0;
            case 0x135DA8u: goto label_135da8;
            case 0x135DB4u: goto label_135db4;
            case 0x135DB8u: goto label_135db8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135DC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

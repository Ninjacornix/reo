#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3840
// Address: 0x1a3840 - 0x1a3880
void sub_001A3840_0x1a3840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3840_0x1a3840");
#endif

    switch (ctx->pc) {
        case 0x1a3854u: goto label_1a3854;
        default: break;
    }

    ctx->pc = 0x1a3840u;

    // 0x1a3840: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3844: 0x3c050007  lui         $a1, 0x7
    ctx->pc = 0x1a3844u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)7 << 16));
    // 0x1a3848: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a384c: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A384Cu;
    SET_GPR_U32(ctx, 31, 0x1A3854u);
    ctx->pc = 0x1A3850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A384Cu;
            // 0x1a3850: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3854u; }
        if (ctx->pc != 0x1A3854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3854u; }
        if (ctx->pc != 0x1A3854u) { return; }
    }
    ctx->pc = 0x1A3854u;
label_1a3854:
    // 0x1a3854: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3854u;
    {
        const bool branch_taken_0x1a3854 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3854) {
            ctx->pc = 0x1A3864u;
            goto label_1a3864;
        }
    }
    ctx->pc = 0x1A385Cu;
    // 0x1a385c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A385Cu;
    {
        const bool branch_taken_0x1a385c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A385Cu;
            // 0x1a3860: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a385c) {
            ctx->pc = 0x1A3868u;
            goto label_1a3868;
        }
    }
    ctx->pc = 0x1A3864u;
label_1a3864:
    // 0x1a3864: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1a3864u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_1a3868:
    // 0x1a3868: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3868u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a386c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A386Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A386Cu;
            // 0x1a3870: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3854u: goto label_1a3854;
            case 0x1A3864u: goto label_1a3864;
            case 0x1A3868u: goto label_1a3868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3874u;
    // 0x1a3874: 0x0  nop
    ctx->pc = 0x1a3874u;
    // NOP
    // 0x1a3878: 0x0  nop
    ctx->pc = 0x1a3878u;
    // NOP
    // 0x1a387c: 0x0  nop
    ctx->pc = 0x1a387cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

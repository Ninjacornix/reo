#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6360
// Address: 0x1c6360 - 0x1c6394
void sub_001C6360_0x1c6360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6360_0x1c6360");
#endif

    switch (ctx->pc) {
        case 0x1c6370u: goto label_1c6370;
        default: break;
    }

    ctx->pc = 0x1c6360u;

    // 0x1c6360: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6364: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6368: 0xc0721fc  jal         func_1C87F0
    ctx->pc = 0x1C6368u;
    SET_GPR_U32(ctx, 31, 0x1C6370u);
    ctx->pc = 0x1C636Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6368u;
            // 0x1c636c: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C87F0u;
    if (runtime->hasFunction(0x1C87F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C87F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6370u; }
        if (ctx->pc != 0x1C6370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C87F0_0x1c87f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6370u; }
        if (ctx->pc != 0x1C6370u) { return; }
    }
    ctx->pc = 0x1C6370u;
label_1c6370:
    // 0x1c6370: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c6370u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c6374: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C6374u;
    {
        const bool branch_taken_0x1c6374 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c6374) {
            ctx->pc = 0x1C6384u;
            goto label_1c6384;
        }
    }
    ctx->pc = 0x1C637Cu;
    // 0x1c637c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C637Cu;
    {
        const bool branch_taken_0x1c637c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C6380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C637Cu;
            // 0x1c6380: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c637c) {
            ctx->pc = 0x1C6388u;
            goto label_1c6388;
        }
    }
    ctx->pc = 0x1C6384u;
label_1c6384:
    // 0x1c6384: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c6384u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c6388:
    // 0x1c6388: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c6388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c638c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C638Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C638Cu;
            // 0x1c6390: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6370u: goto label_1c6370;
            case 0x1C6384u: goto label_1c6384;
            case 0x1C6388u: goto label_1c6388;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6394u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

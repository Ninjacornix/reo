#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6580
// Address: 0x1b6580 - 0x1b65b0
void sub_001B6580_0x1b6580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6580_0x1b6580");
#endif

    switch (ctx->pc) {
        case 0x1b6594u: goto label_1b6594;
        case 0x1b65a4u: goto label_1b65a4;
        default: break;
    }

    ctx->pc = 0x1b6580u;

    // 0x1b6580: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b6580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b6584: 0x14a00005  bnez        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6584u;
    {
        const bool branch_taken_0x1b6584 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6584u;
            // 0x1b6588: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6584) {
            ctx->pc = 0x1B659Cu;
            goto label_1b659c;
        }
    }
    ctx->pc = 0x1B658Cu;
    // 0x1b658c: 0xc06d96c  jal         func_1B65B0
    ctx->pc = 0x1B658Cu;
    SET_GPR_U32(ctx, 31, 0x1B6594u);
    ctx->pc = 0x1B65B0u;
    if (runtime->hasFunction(0x1B65B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B65B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6594u; }
        if (ctx->pc != 0x1B6594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B65B0_0x1b65b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B6594u; }
        if (ctx->pc != 0x1B6594u) { return; }
    }
    ctx->pc = 0x1B6594u;
label_1b6594:
    // 0x1b6594: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6594u;
    {
        const bool branch_taken_0x1b6594 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6594u;
            // 0x1b6598: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6594) {
            ctx->pc = 0x1B65A8u;
            goto label_1b65a8;
        }
    }
    ctx->pc = 0x1B659Cu;
label_1b659c:
    // 0x1b659c: 0xc06d99c  jal         func_1B6670
    ctx->pc = 0x1B659Cu;
    SET_GPR_U32(ctx, 31, 0x1B65A4u);
    ctx->pc = 0x1B6670u;
    if (runtime->hasFunction(0x1B6670u)) {
        auto targetFn = runtime->lookupFunction(0x1B6670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B65A4u; }
        if (ctx->pc != 0x1B65A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6670_0x1b6670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B65A4u; }
        if (ctx->pc != 0x1B65A4u) { return; }
    }
    ctx->pc = 0x1B65A4u;
label_1b65a4:
    // 0x1b65a4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b65a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1b65a8:
    // 0x1b65a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B65A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B65ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65A8u;
            // 0x1b65ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B6594u: goto label_1b6594;
            case 0x1B659Cu: goto label_1b659c;
            case 0x1B65A4u: goto label_1b65a4;
            case 0x1B65A8u: goto label_1b65a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B65B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

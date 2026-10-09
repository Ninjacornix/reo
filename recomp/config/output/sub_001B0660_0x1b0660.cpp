#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0660
// Address: 0x1b0660 - 0x1b0694
void sub_001B0660_0x1b0660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0660_0x1b0660");
#endif

    switch (ctx->pc) {
        case 0x1b0688u: goto label_1b0688;
        default: break;
    }

    ctx->pc = 0x1b0660u;

    // 0x1b0660: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0664: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b0664u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0668: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b066c: 0xac208df8  sw          $zero, -0x7208($at)
    ctx->pc = 0x1b066cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938104), GPR_U32(ctx, 0));
    // 0x1b0670: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b0670u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0674: 0x8c238df0  lw          $v1, -0x7210($at)
    ctx->pc = 0x1b0674u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938096)));
    // 0x1b0678: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0678u;
    {
        const bool branch_taken_0x1b0678 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B067Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0678u;
            // 0x1b067c: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0678) {
            ctx->pc = 0x1B0688u;
            goto label_1b0688;
        }
    }
    ctx->pc = 0x1B0680u;
    // 0x1b0680: 0xc072e3c  jal         func_1CB8F0
    ctx->pc = 0x1B0680u;
    SET_GPR_U32(ctx, 31, 0x1B0688u);
    ctx->pc = 0x1B0684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0680u;
            // 0x1b0684: 0xac208df0  sw          $zero, -0x7210($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294938096), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB8F0u;
    if (runtime->hasFunction(0x1CB8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CB8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0688u; }
        if (ctx->pc != 0x1B0688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB8F0_0x1cb8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0688u; }
        if (ctx->pc != 0x1B0688u) { return; }
    }
    ctx->pc = 0x1B0688u;
label_1b0688:
    // 0x1b0688: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b0688u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b068c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B068Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B068Cu;
            // 0x1b0690: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0688u: goto label_1b0688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0694u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

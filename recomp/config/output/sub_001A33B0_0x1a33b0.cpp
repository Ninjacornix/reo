#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A33B0
// Address: 0x1a33b0 - 0x1a33e0
void sub_001A33B0_0x1a33b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A33B0_0x1a33b0");
#endif

    switch (ctx->pc) {
        case 0x1a33c0u: goto label_1a33c0;
        default: break;
    }

    ctx->pc = 0x1a33b0u;

    // 0x1a33b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a33b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a33b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a33b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a33b8: 0xc068cc4  jal         func_1A3310
    ctx->pc = 0x1A33B8u;
    SET_GPR_U32(ctx, 31, 0x1A33C0u);
    ctx->pc = 0x1A3310u;
    if (runtime->hasFunction(0x1A3310u)) {
        auto targetFn = runtime->lookupFunction(0x1A3310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A33C0u; }
        if (ctx->pc != 0x1A33C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3310_0x1a3310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A33C0u; }
        if (ctx->pc != 0x1A33C0u) { return; }
    }
    ctx->pc = 0x1A33C0u;
label_1a33c0:
    // 0x1a33c0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A33C0u;
    {
        const bool branch_taken_0x1a33c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a33c0) {
            ctx->pc = 0x1A33D0u;
            goto label_1a33d0;
        }
    }
    ctx->pc = 0x1A33C8u;
    // 0x1a33c8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A33C8u;
    {
        const bool branch_taken_0x1a33c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A33CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A33C8u;
            // 0x1a33cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a33c8) {
            ctx->pc = 0x1A33D4u;
            goto label_1a33d4;
        }
    }
    ctx->pc = 0x1A33D0u;
label_1a33d0:
    // 0x1a33d0: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1a33d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_1a33d4:
    // 0x1a33d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a33d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a33d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A33D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A33DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A33D8u;
            // 0x1a33dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A33C0u: goto label_1a33c0;
            case 0x1A33D0u: goto label_1a33d0;
            case 0x1A33D4u: goto label_1a33d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A33E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

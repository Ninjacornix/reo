#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9840
// Address: 0x1a9840 - 0x1a986c
void sub_001A9840_0x1a9840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9840_0x1a9840");
#endif

    switch (ctx->pc) {
        case 0x1a9860u: goto label_1a9860;
        default: break;
    }

    ctx->pc = 0x1a9840u;

    // 0x1a9840: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a9840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9844: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9844u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a9848: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a9848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a984c: 0x8c2416a8  lw          $a0, 0x16A8($at)
    ctx->pc = 0x1a984cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5800)));
    // 0x1a9850: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9850u;
    {
        const bool branch_taken_0x1a9850 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9850) {
            ctx->pc = 0x1A9860u;
            goto label_1a9860;
        }
    }
    ctx->pc = 0x1A9858u;
    // 0x1a9858: 0xc04a5f8  jal         func_1297E0
    ctx->pc = 0x1A9858u;
    SET_GPR_U32(ctx, 31, 0x1A9860u);
    ctx->pc = 0x1297E0u;
    if (runtime->hasFunction(0x1297E0u)) {
        auto targetFn = runtime->lookupFunction(0x1297E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9860u; }
        if (ctx->pc != 0x1A9860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297E0_0x1297e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9860u; }
        if (ctx->pc != 0x1A9860u) { return; }
    }
    ctx->pc = 0x1A9860u;
label_1a9860:
    // 0x1a9860: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a9860u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9864: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9864u;
            // 0x1a9868: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9860u: goto label_1a9860;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A986Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

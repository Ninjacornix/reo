#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132870
// Address: 0x132870 - 0x13288c
void sub_00132870_0x132870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132870_0x132870");
#endif

    switch (ctx->pc) {
        case 0x132880u: goto label_132880;
        default: break;
    }

    ctx->pc = 0x132870u;

    // 0x132870: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132874: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132878: 0xc04b654  jal         func_12D950
    ctx->pc = 0x132878u;
    SET_GPR_U32(ctx, 31, 0x132880u);
    ctx->pc = 0x13287Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132878u;
            // 0x13287c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D950u;
    if (runtime->hasFunction(0x12D950u)) {
        auto targetFn = runtime->lookupFunction(0x12D950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132880u; }
        if (ctx->pc != 0x132880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D950_0x12d950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132880u; }
        if (ctx->pc != 0x132880u) { return; }
    }
    ctx->pc = 0x132880u;
label_132880:
    // 0x132880: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132884: 0x3e00008  jr          $ra
    ctx->pc = 0x132884u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132884u;
            // 0x132888: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132880u: goto label_132880;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13288Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

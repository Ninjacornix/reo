#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132850
// Address: 0x132850 - 0x13286c
void sub_00132850_0x132850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132850_0x132850");
#endif

    switch (ctx->pc) {
        case 0x132860u: goto label_132860;
        default: break;
    }

    ctx->pc = 0x132850u;

    // 0x132850: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132854: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132858: 0xc04b63e  jal         func_12D8F8
    ctx->pc = 0x132858u;
    SET_GPR_U32(ctx, 31, 0x132860u);
    ctx->pc = 0x13285Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132858u;
            // 0x13285c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8F8u;
    if (runtime->hasFunction(0x12D8F8u)) {
        auto targetFn = runtime->lookupFunction(0x12D8F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132860u; }
        if (ctx->pc != 0x132860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8F8_0x12d8f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132860u; }
        if (ctx->pc != 0x132860u) { return; }
    }
    ctx->pc = 0x132860u;
label_132860:
    // 0x132860: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132860u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132864: 0x3e00008  jr          $ra
    ctx->pc = 0x132864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132864u;
            // 0x132868: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132860u: goto label_132860;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13286Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

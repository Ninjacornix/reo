#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115300
// Address: 0x115300 - 0x115320
void sub_00115300_0x115300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115300_0x115300");
#endif

    switch (ctx->pc) {
        case 0x115310u: goto label_115310;
        default: break;
    }

    ctx->pc = 0x115300u;

    // 0x115300: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x115300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x115304: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x115304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x115308: 0xc0450fc  jal         func_1143F0
    ctx->pc = 0x115308u;
    SET_GPR_U32(ctx, 31, 0x115310u);
    ctx->pc = 0x1143F0u;
    if (runtime->hasFunction(0x1143F0u)) {
        auto targetFn = runtime->lookupFunction(0x1143F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115310u; }
        if (ctx->pc != 0x115310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001143F0_0x1143f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115310u; }
        if (ctx->pc != 0x115310u) { return; }
    }
    ctx->pc = 0x115310u;
label_115310:
    // 0x115310: 0xf  sync
    ctx->pc = 0x115310u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x115314: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x115314u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115318: 0x3e00008  jr          $ra
    ctx->pc = 0x115318u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11531Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115318u;
            // 0x11531c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115310u: goto label_115310;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115320u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

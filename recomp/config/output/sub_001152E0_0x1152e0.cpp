#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001152E0
// Address: 0x1152e0 - 0x115300
void sub_001152E0_0x1152e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001152E0_0x1152e0");
#endif

    switch (ctx->pc) {
        case 0x1152f0u: goto label_1152f0;
        default: break;
    }

    ctx->pc = 0x1152e0u;

    // 0x1152e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1152e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1152e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1152e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1152e8: 0xc0450f8  jal         func_1143E0
    ctx->pc = 0x1152E8u;
    SET_GPR_U32(ctx, 31, 0x1152F0u);
    ctx->pc = 0x1143E0u;
    if (runtime->hasFunction(0x1143E0u)) {
        auto targetFn = runtime->lookupFunction(0x1143E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1152F0u; }
        if (ctx->pc != 0x1152F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001143E0_0x1143e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1152F0u; }
        if (ctx->pc != 0x1152F0u) { return; }
    }
    ctx->pc = 0x1152F0u;
label_1152f0:
    // 0x1152f0: 0xf  sync
    ctx->pc = 0x1152f0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1152f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1152f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1152f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1152F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1152FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1152F8u;
            // 0x1152fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1152F0u: goto label_1152f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115300u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

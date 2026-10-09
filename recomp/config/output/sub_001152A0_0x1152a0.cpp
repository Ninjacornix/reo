#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001152A0
// Address: 0x1152a0 - 0x1152c0
void sub_001152A0_0x1152a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001152A0_0x1152a0");
#endif

    switch (ctx->pc) {
        case 0x1152b0u: goto label_1152b0;
        default: break;
    }

    ctx->pc = 0x1152a0u;

    // 0x1152a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1152a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1152a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1152a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1152a8: 0xc0450f0  jal         func_1143C0
    ctx->pc = 0x1152A8u;
    SET_GPR_U32(ctx, 31, 0x1152B0u);
    ctx->pc = 0x1143C0u;
    if (runtime->hasFunction(0x1143C0u)) {
        auto targetFn = runtime->lookupFunction(0x1143C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1152B0u; }
        if (ctx->pc != 0x1152B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001143C0_0x1143c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1152B0u; }
        if (ctx->pc != 0x1152B0u) { return; }
    }
    ctx->pc = 0x1152B0u;
label_1152b0:
    // 0x1152b0: 0xf  sync
    ctx->pc = 0x1152b0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1152b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1152b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1152b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1152B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1152BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1152B8u;
            // 0x1152bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1152B0u: goto label_1152b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1152C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

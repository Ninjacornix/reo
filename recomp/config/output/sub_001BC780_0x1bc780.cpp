#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC780
// Address: 0x1bc780 - 0x1bc7b0
void sub_001BC780_0x1bc780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC780_0x1bc780");
#endif

    switch (ctx->pc) {
        case 0x1bc790u: goto label_1bc790;
        case 0x1bc798u: goto label_1bc798;
        default: break;
    }

    ctx->pc = 0x1bc780u;

    // 0x1bc780: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bc780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bc784: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bc784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bc788: 0xc06f32c  jal         func_1BCCB0
    ctx->pc = 0x1BC788u;
    SET_GPR_U32(ctx, 31, 0x1BC790u);
    ctx->pc = 0x1BCCB0u;
    if (runtime->hasFunction(0x1BCCB0u)) {
        auto targetFn = runtime->lookupFunction(0x1BCCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC790u; }
        if (ctx->pc != 0x1BC790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BCCB0_0x1bccb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC790u; }
        if (ctx->pc != 0x1BC790u) { return; }
    }
    ctx->pc = 0x1BC790u;
label_1bc790:
    // 0x1bc790: 0xc07485c  jal         func_1D2170
    ctx->pc = 0x1BC790u;
    SET_GPR_U32(ctx, 31, 0x1BC798u);
    ctx->pc = 0x1D2170u;
    if (runtime->hasFunction(0x1D2170u)) {
        auto targetFn = runtime->lookupFunction(0x1D2170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC798u; }
        if (ctx->pc != 0x1BC798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D2170_0x1d2170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC798u; }
        if (ctx->pc != 0x1BC798u) { return; }
    }
    ctx->pc = 0x1BC798u;
label_1bc798:
    // 0x1bc798: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bc798u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bc79c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC79Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC79Cu;
            // 0x1bc7a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC790u: goto label_1bc790;
            case 0x1BC798u: goto label_1bc798;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC7A4u;
    // 0x1bc7a4: 0x0  nop
    ctx->pc = 0x1bc7a4u;
    // NOP
    // 0x1bc7a8: 0x0  nop
    ctx->pc = 0x1bc7a8u;
    // NOP
    // 0x1bc7ac: 0x0  nop
    ctx->pc = 0x1bc7acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

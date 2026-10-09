#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D66E0
// Address: 0x1d66e0 - 0x1d6710
void sub_001D66E0_0x1d66e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D66E0_0x1d66e0");
#endif

    switch (ctx->pc) {
        case 0x1d66f0u: goto label_1d66f0;
        default: break;
    }

    ctx->pc = 0x1d66e0u;

    // 0x1d66e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d66e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d66e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d66e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d66e8: 0xc075df8  jal         func_1D77E0
    ctx->pc = 0x1D66E8u;
    SET_GPR_U32(ctx, 31, 0x1D66F0u);
    ctx->pc = 0x1D77E0u;
    if (runtime->hasFunction(0x1D77E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D77E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D66F0u; }
        if (ctx->pc != 0x1D66F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D77E0_0x1d77e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D66F0u; }
        if (ctx->pc != 0x1D66F0u) { return; }
    }
    ctx->pc = 0x1D66F0u;
label_1d66f0:
    // 0x1d66f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d66f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d66f4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d66f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d66f8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d66f8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d66fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D66FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D66FCu;
            // 0x1d6700: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D66F0u: goto label_1d66f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6704u;
    // 0x1d6704: 0x0  nop
    ctx->pc = 0x1d6704u;
    // NOP
    // 0x1d6708: 0x0  nop
    ctx->pc = 0x1d6708u;
    // NOP
    // 0x1d670c: 0x0  nop
    ctx->pc = 0x1d670cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

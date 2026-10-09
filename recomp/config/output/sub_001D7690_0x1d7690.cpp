#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7690
// Address: 0x1d7690 - 0x1d76c0
void sub_001D7690_0x1d7690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7690_0x1d7690");
#endif

    switch (ctx->pc) {
        case 0x1d76a0u: goto label_1d76a0;
        default: break;
    }

    ctx->pc = 0x1d7690u;

    // 0x1d7690: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7694: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7698: 0xc0763f0  jal         func_1D8FC0
    ctx->pc = 0x1D7698u;
    SET_GPR_U32(ctx, 31, 0x1D76A0u);
    ctx->pc = 0x1D769Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7698u;
            // 0x1d769c: 0x8c840000  lw          $a0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8FC0u;
    if (runtime->hasFunction(0x1D8FC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D8FC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D76A0u; }
        if (ctx->pc != 0x1D76A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8FC0_0x1d8fc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D76A0u; }
        if (ctx->pc != 0x1D76A0u) { return; }
    }
    ctx->pc = 0x1D76A0u;
label_1d76a0:
    // 0x1d76a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d76a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d76a4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d76a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d76a8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d76a8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d76ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1D76ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D76B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D76ACu;
            // 0x1d76b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D76A0u: goto label_1d76a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D76B4u;
    // 0x1d76b4: 0x0  nop
    ctx->pc = 0x1d76b4u;
    // NOP
    // 0x1d76b8: 0x0  nop
    ctx->pc = 0x1d76b8u;
    // NOP
    // 0x1d76bc: 0x0  nop
    ctx->pc = 0x1d76bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

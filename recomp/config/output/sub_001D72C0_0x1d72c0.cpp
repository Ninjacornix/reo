#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D72C0
// Address: 0x1d72c0 - 0x1d72f0
void sub_001D72C0_0x1d72c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D72C0_0x1d72c0");
#endif

    switch (ctx->pc) {
        case 0x1d72d0u: goto label_1d72d0;
        default: break;
    }

    ctx->pc = 0x1d72c0u;

    // 0x1d72c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d72c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d72c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d72c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d72c8: 0xc0762d0  jal         func_1D8B40
    ctx->pc = 0x1D72C8u;
    SET_GPR_U32(ctx, 31, 0x1D72D0u);
    ctx->pc = 0x1D8B40u;
    if (runtime->hasFunction(0x1D8B40u)) {
        auto targetFn = runtime->lookupFunction(0x1D8B40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D72D0u; }
        if (ctx->pc != 0x1D72D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8B40_0x1d8b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D72D0u; }
        if (ctx->pc != 0x1D72D0u) { return; }
    }
    ctx->pc = 0x1D72D0u;
label_1d72d0:
    // 0x1d72d0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d72d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d72d4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d72d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d72d8: 0xa0234602  sb          $v1, 0x4602($at)
    ctx->pc = 0x1d72d8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17922), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d72dc: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d72dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d72e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d72e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d72e4: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d72e4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d72e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D72E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D72ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D72E8u;
            // 0x1d72ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D72D0u: goto label_1d72d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D72F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

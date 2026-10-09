#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001719A0
// Address: 0x1719a0 - 0x1719c4
void sub_001719A0_0x1719a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001719A0_0x1719a0");
#endif

    switch (ctx->pc) {
        case 0x1719b4u: goto label_1719b4;
        default: break;
    }

    ctx->pc = 0x1719a0u;

    // 0x1719a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1719a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1719a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1719a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1719a8: 0x8cc41b30  lw          $a0, 0x1B30($a2)
    ctx->pc = 0x1719a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 6960)));
    // 0x1719ac: 0xc05c418  jal         func_171060
    ctx->pc = 0x1719ACu;
    SET_GPR_U32(ctx, 31, 0x1719B4u);
    ctx->pc = 0x1719B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1719ACu;
            // 0x1719b0: 0x24840a48  addiu       $a0, $a0, 0xA48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171060u;
    if (runtime->hasFunction(0x171060u)) {
        auto targetFn = runtime->lookupFunction(0x171060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719B4u; }
        if (ctx->pc != 0x1719B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171060_0x171060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719B4u; }
        if (ctx->pc != 0x1719B4u) { return; }
    }
    ctx->pc = 0x1719B4u;
label_1719b4:
    // 0x1719b4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1719b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1719b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1719b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1719bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1719BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1719C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1719BCu;
            // 0x1719c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1719B4u: goto label_1719b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1719C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

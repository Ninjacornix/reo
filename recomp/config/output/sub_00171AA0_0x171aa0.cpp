#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171AA0
// Address: 0x171aa0 - 0x171ac8
void sub_00171AA0_0x171aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171AA0_0x171aa0");
#endif

    ctx->pc = 0x171aa0u;

    // 0x171aa0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x171aa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x171aa4: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x171aa4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x171aa8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x171aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x171aac: 0x24a560d8  addiu       $a1, $a1, 0x60D8
    ctx->pc = 0x171aacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24792));
    // 0x171ab0: 0x24060048  addiu       $a2, $zero, 0x48
    ctx->pc = 0x171ab0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x171ab4: 0x8c841b30  lw          $a0, 0x1B30($a0)
    ctx->pc = 0x171ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x171ab8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x171ab8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171abc: 0x24840a00  addiu       $a0, $a0, 0xA00
    ctx->pc = 0x171abcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2560));
    // 0x171ac0: 0x80557c8  j           func_155F20
    ctx->pc = 0x171AC0u;
    ctx->pc = 0x171AC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171AC0u;
            // 0x171ac4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155F20u;
    if (runtime->hasFunction(0x155F20u)) {
        auto targetFn = runtime->lookupFunction(0x155F20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00155F20_0x155f20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x171AC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

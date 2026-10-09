#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171A78
// Address: 0x171a78 - 0x171aa0
void sub_00171A78_0x171a78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171A78_0x171a78");
#endif

    ctx->pc = 0x171a78u;

    // 0x171a78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x171a78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x171a7c: 0x24060048  addiu       $a2, $zero, 0x48
    ctx->pc = 0x171a7cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x171a80: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x171a80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x171a84: 0x8c851b30  lw          $a1, 0x1B30($a0)
    ctx->pc = 0x171a84u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x171a88: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x171a88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x171a8c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x171a8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171a90: 0x248460d8  addiu       $a0, $a0, 0x60D8
    ctx->pc = 0x171a90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24792));
    // 0x171a94: 0x24a50a00  addiu       $a1, $a1, 0xA00
    ctx->pc = 0x171a94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2560));
    // 0x171a98: 0x80557c8  j           func_155F20
    ctx->pc = 0x171A98u;
    ctx->pc = 0x171A9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171A98u;
            // 0x171a9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155F20u;
    if (runtime->hasFunction(0x155F20u)) {
        auto targetFn = runtime->lookupFunction(0x155F20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00155F20_0x155f20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x171AA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

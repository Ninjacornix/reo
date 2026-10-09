#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160F70
// Address: 0x160f70 - 0x160f88
void sub_00160F70_0x160f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160F70_0x160f70");
#endif

    ctx->pc = 0x160f70u;

    // 0x160f70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160f74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160f78: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x160f78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x160f7c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160f7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160f80: 0x805f4b6  j           func_17D2D8
    ctx->pc = 0x160F80u;
    ctx->pc = 0x160F84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160F80u;
            // 0x160f84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2D8u;
    if (runtime->hasFunction(0x17D2D8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D2D8_0x17d2d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160F88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

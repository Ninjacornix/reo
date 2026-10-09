#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001620F0
// Address: 0x1620f0 - 0x162108
void sub_001620F0_0x1620f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001620F0_0x1620f0");
#endif

    ctx->pc = 0x1620f0u;

    // 0x1620f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1620f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1620f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1620f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1620f8: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x1620f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x1620fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1620fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162100: 0x805f5b2  j           func_17D6C8
    ctx->pc = 0x162100u;
    ctx->pc = 0x162104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162100u;
            // 0x162104: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D6C8u;
    if (runtime->hasFunction(0x17D6C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D6C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D6C8_0x17d6c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162108u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

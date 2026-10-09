#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D6C8
// Address: 0x17d6c8 - 0x17d6e8
void sub_0017D6C8_0x17d6c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D6C8_0x17d6c8");
#endif

    ctx->pc = 0x17d6c8u;

    // 0x17d6c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d6c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d6cc: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d6ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d6d0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d6d4: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x17d6d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d6d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d6d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d6dc: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x17d6dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d6e0: 0x805f98a  j           func_17E628
    ctx->pc = 0x17D6E0u;
    ctx->pc = 0x17D6E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D6E0u;
            // 0x17d6e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E628u;
    if (runtime->hasFunction(0x17E628u)) {
        auto targetFn = runtime->lookupFunction(0x17E628u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E628_0x17e628(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D6E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

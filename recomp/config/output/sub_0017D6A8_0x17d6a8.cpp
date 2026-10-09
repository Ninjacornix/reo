#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D6A8
// Address: 0x17d6a8 - 0x17d6c8
void sub_0017D6A8_0x17d6a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D6A8_0x17d6a8");
#endif

    ctx->pc = 0x17d6a8u;

    // 0x17d6a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d6a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d6ac: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d6acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d6b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d6b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d6b4: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x17d6b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d6b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d6b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d6bc: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x17d6bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d6c0: 0x805f97a  j           func_17E5E8
    ctx->pc = 0x17D6C0u;
    ctx->pc = 0x17D6C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D6C0u;
            // 0x17d6c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E5E8u;
    if (runtime->hasFunction(0x17E5E8u)) {
        auto targetFn = runtime->lookupFunction(0x17E5E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E5E8_0x17e5e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D6C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

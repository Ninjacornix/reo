#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D688
// Address: 0x17d688 - 0x17d6a8
void sub_0017D688_0x17d688(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D688_0x17d688");
#endif

    ctx->pc = 0x17d688u;

    // 0x17d688: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d68c: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d68cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d690: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d694: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x17d694u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d698: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d698u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d69c: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x17d69cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d6a0: 0x805f96a  j           func_17E5A8
    ctx->pc = 0x17D6A0u;
    ctx->pc = 0x17D6A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D6A0u;
            // 0x17d6a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E5A8u;
    if (runtime->hasFunction(0x17E5A8u)) {
        auto targetFn = runtime->lookupFunction(0x17E5A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E5A8_0x17e5a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D6A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

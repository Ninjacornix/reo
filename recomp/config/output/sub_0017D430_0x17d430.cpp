#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D430
// Address: 0x17d430 - 0x17d448
void sub_0017D430_0x17d430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D430_0x17d430");
#endif

    ctx->pc = 0x17d430u;

    // 0x17d430: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d430u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d434: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d434u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d438: 0x8c840030  lw          $a0, 0x30($a0)
    ctx->pc = 0x17d438u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x17d43c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d43cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d440: 0x805e9f6  j           func_17A7D8
    ctx->pc = 0x17D440u;
    ctx->pc = 0x17D444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D440u;
            // 0x17d444: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A7D8u;
    if (runtime->hasFunction(0x17A7D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A7D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017A7D8_0x17a7d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

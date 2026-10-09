#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C438
// Address: 0x16c438 - 0x16c450
void sub_0016C438_0x16c438(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C438_0x16c438");
#endif

    ctx->pc = 0x16c438u;

    // 0x16c438: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16c438u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c43c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16c43cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16c440: 0x8c851b3c  lw          $a1, 0x1B3C($a0)
    ctx->pc = 0x16c440u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6972)));
    // 0x16c444: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16c444u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c448: 0x8059f40  j           func_167D00
    ctx->pc = 0x16C448u;
    ctx->pc = 0x16C44Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C448u;
            // 0x16c44c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167D00u;
    if (runtime->hasFunction(0x167D00u)) {
        auto targetFn = runtime->lookupFunction(0x167D00u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00167D00_0x167d00(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C450u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

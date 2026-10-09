#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169F60
// Address: 0x169f60 - 0x169f7c
void sub_00169F60_0x169f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169F60_0x169f60");
#endif

    ctx->pc = 0x169f60u;

    // 0x169f60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169f60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169f64: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x169f64u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169f68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169f68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169f6c: 0x8c851ab4  lw          $a1, 0x1AB4($a0)
    ctx->pc = 0x169f6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6836)));
    // 0x169f70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169f70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169f74: 0x8059bf4  j           func_166FD0
    ctx->pc = 0x169F74u;
    ctx->pc = 0x169F78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169F74u;
            // 0x169f78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FD0u;
    if (runtime->hasFunction(0x166FD0u)) {
        auto targetFn = runtime->lookupFunction(0x166FD0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166FD0_0x166fd0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169F7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

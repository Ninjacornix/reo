#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173990
// Address: 0x173990 - 0x1739a8
void sub_00173990_0x173990(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173990_0x173990");
#endif

    ctx->pc = 0x173990u;

    // 0x173990: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173990u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173994: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x173994u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x173998: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x173998u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17399c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17399cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1739a0: 0x805ded2  j           func_177B48
    ctx->pc = 0x1739A0u;
    ctx->pc = 0x1739A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1739A0u;
            // 0x1739a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B48u;
    if (runtime->hasFunction(0x177B48u)) {
        auto targetFn = runtime->lookupFunction(0x177B48u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177B48_0x177b48(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1739A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

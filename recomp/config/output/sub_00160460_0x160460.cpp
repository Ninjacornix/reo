#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160460
// Address: 0x160460 - 0x160480
void sub_00160460_0x160460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160460_0x160460");
#endif

    ctx->pc = 0x160460u;

    // 0x160460: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160464: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x160464u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160468: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16046c: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x16046cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x160470: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x160470u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x160474: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160474u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160478: 0x805afb2  j           func_16BEC8
    ctx->pc = 0x160478u;
    ctx->pc = 0x16047Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160478u;
            // 0x16047c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BEC8u;
    if (runtime->hasFunction(0x16BEC8u)) {
        auto targetFn = runtime->lookupFunction(0x16BEC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016BEC8_0x16bec8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160480u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BA68
// Address: 0x15ba68 - 0x15ba7c
void sub_0015BA68_0x15ba68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BA68_0x15ba68");
#endif

    ctx->pc = 0x15ba68u;

    // 0x15ba68: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ba68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ba6c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ba6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ba70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ba70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ba74: 0x8056ea0  j           func_15BA80
    ctx->pc = 0x15BA74u;
    ctx->pc = 0x15BA78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BA74u;
            // 0x15ba78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015BA80_0x15ba80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15BA7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

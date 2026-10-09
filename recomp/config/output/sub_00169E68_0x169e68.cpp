#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169E68
// Address: 0x169e68 - 0x169e80
void sub_00169E68_0x169e68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169E68_0x169e68");
#endif

    ctx->pc = 0x169e68u;

    // 0x169e68: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169e68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169e6c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169e70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169e70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169e74: 0x804fe16  j           func_13F858
    ctx->pc = 0x169E74u;
    ctx->pc = 0x169E78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169E74u;
            // 0x169e78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F858u;
    if (runtime->hasFunction(0x13F858u)) {
        auto targetFn = runtime->lookupFunction(0x13F858u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F858_0x13f858(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x169E7Cu;
    // 0x169e7c: 0x0  nop
    ctx->pc = 0x169e7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

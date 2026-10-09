#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C668
// Address: 0x12c668 - 0x12c680
void sub_0012C668_0x12c668(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C668_0x12c668");
#endif

    ctx->pc = 0x12c668u;

    // 0x12c668: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c668u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c66c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c66cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c670: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c670u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c674: 0x804f9dc  j           func_13E770
    ctx->pc = 0x12C674u;
    ctx->pc = 0x12C678u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C674u;
            // 0x12c678: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E770u;
    if (runtime->hasFunction(0x13E770u)) {
        auto targetFn = runtime->lookupFunction(0x13E770u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E770_0x13e770(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C67Cu;
    // 0x12c67c: 0x0  nop
    ctx->pc = 0x12c67cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

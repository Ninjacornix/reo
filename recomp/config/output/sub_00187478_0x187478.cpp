#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187478
// Address: 0x187478 - 0x187490
void sub_00187478_0x187478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187478_0x187478");
#endif

    ctx->pc = 0x187478u;

    // 0x187478: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x187478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18747c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x18747cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x187480: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x187480u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x187484: 0x8061ccc  j           func_187330
    ctx->pc = 0x187484u;
    ctx->pc = 0x187488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187484u;
            // 0x187488: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187330u;
    if (runtime->hasFunction(0x187330u)) {
        auto targetFn = runtime->lookupFunction(0x187330u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00187330_0x187330(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18748Cu;
    // 0x18748c: 0x0  nop
    ctx->pc = 0x18748cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

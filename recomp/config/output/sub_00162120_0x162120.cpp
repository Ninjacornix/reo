#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162120
// Address: 0x162120 - 0x162138
void sub_00162120_0x162120(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162120_0x162120");
#endif

    ctx->pc = 0x162120u;

    // 0x162120: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162120u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162124: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162128: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x162128u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x16212c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16212cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162130: 0x805f51e  j           func_17D478
    ctx->pc = 0x162130u;
    ctx->pc = 0x162134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162130u;
            // 0x162134: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D478u;
    if (runtime->hasFunction(0x17D478u)) {
        auto targetFn = runtime->lookupFunction(0x17D478u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D478_0x17d478(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162138u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

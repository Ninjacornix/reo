#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D3F8
// Address: 0x17d3f8 - 0x17d410
void sub_0017D3F8_0x17d3f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D3F8_0x17d3f8");
#endif

    ctx->pc = 0x17d3f8u;

    // 0x17d3f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d3f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d3fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d3fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d400: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x17d400u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x17d404: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d404u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d408: 0x805f8d4  j           func_17E350
    ctx->pc = 0x17D408u;
    ctx->pc = 0x17D40Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D408u;
            // 0x17d40c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E350u;
    if (runtime->hasFunction(0x17E350u)) {
        auto targetFn = runtime->lookupFunction(0x17E350u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E350_0x17e350(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D410u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B5A0
// Address: 0x12b5a0 - 0x12b5b4
void sub_0012B5A0_0x12b5a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B5A0_0x12b5a0");
#endif

    ctx->pc = 0x12b5a0u;

    // 0x12b5a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12b5a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12b5a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12b5a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12b5a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b5a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b5ac: 0x8050808  j           func_142020
    ctx->pc = 0x12B5ACu;
    ctx->pc = 0x12B5B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B5ACu;
            // 0x12b5b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142020u;
    if (runtime->hasFunction(0x142020u)) {
        auto targetFn = runtime->lookupFunction(0x142020u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00142020_0x142020(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B5B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

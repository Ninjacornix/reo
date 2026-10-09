#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141760
// Address: 0x141760 - 0x141778
void sub_00141760_0x141760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141760_0x141760");
#endif

    ctx->pc = 0x141760u;

    // 0x141760: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x141760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x141764: 0x240403e8  addiu       $a0, $zero, 0x3E8
    ctx->pc = 0x141764u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x141768: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x141768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14176c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14176cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141770: 0x8050578  j           func_1415E0
    ctx->pc = 0x141770u;
    ctx->pc = 0x141774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141770u;
            // 0x141774: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1415E0u;
    if (runtime->hasFunction(0x1415E0u)) {
        auto targetFn = runtime->lookupFunction(0x1415E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001415E0_0x1415e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141778u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C878
// Address: 0x12c878 - 0x12c88c
void sub_0012C878_0x12c878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C878_0x12c878");
#endif

    ctx->pc = 0x12c878u;

    // 0x12c878: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c87c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c87cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c880: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c884: 0x804fc3c  j           func_13F0F0
    ctx->pc = 0x12C884u;
    ctx->pc = 0x12C888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C884u;
            // 0x12c888: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F0F0u;
    if (runtime->hasFunction(0x13F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x13F0F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F0F0_0x13f0f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C88Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

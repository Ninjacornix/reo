#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A0C0
// Address: 0x12a0c0 - 0x12a0d4
void sub_0012A0C0_0x12a0c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A0C0_0x12a0c0");
#endif

    ctx->pc = 0x12a0c0u;

    // 0x12a0c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a0c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a0c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a0c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a0c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a0cc: 0x804a808  j           func_12A020
    ctx->pc = 0x12A0CCu;
    ctx->pc = 0x12A0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0CCu;
            // 0x12a0d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A020u;
    if (runtime->hasFunction(0x12A020u)) {
        auto targetFn = runtime->lookupFunction(0x12A020u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012A020_0x12a020(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A0D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

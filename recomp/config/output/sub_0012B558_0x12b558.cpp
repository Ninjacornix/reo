#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B558
// Address: 0x12b558 - 0x12b56c
void sub_0012B558_0x12b558(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B558_0x12b558");
#endif

    ctx->pc = 0x12b558u;

    // 0x12b558: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12b558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12b55c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12b55cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12b560: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b560u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b564: 0x80507f0  j           func_141FC0
    ctx->pc = 0x12B564u;
    ctx->pc = 0x12B568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B564u;
            // 0x12b568: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141FC0u;
    if (runtime->hasFunction(0x141FC0u)) {
        auto targetFn = runtime->lookupFunction(0x141FC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141FC0_0x141fc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B56Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

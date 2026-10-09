#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C860
// Address: 0x12c860 - 0x12c874
void sub_0012C860_0x12c860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C860_0x12c860");
#endif

    ctx->pc = 0x12c860u;

    // 0x12c860: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c864: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c868: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c868u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c86c: 0x804fc3a  j           func_13F0E8
    ctx->pc = 0x12C86Cu;
    ctx->pc = 0x12C870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C86Cu;
            // 0x12c870: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F0E8u;
    if (runtime->hasFunction(0x13F0E8u)) {
        auto targetFn = runtime->lookupFunction(0x13F0E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F0E8_0x13f0e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C874u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

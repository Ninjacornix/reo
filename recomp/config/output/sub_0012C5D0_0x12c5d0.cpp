#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C5D0
// Address: 0x12c5d0 - 0x12c5e4
void sub_0012C5D0_0x12c5d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C5D0_0x12c5d0");
#endif

    ctx->pc = 0x12c5d0u;

    // 0x12c5d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c5d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c5d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c5d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c5d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c5d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c5dc: 0x804f95a  j           func_13E568
    ctx->pc = 0x12C5DCu;
    ctx->pc = 0x12C5E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5DCu;
            // 0x12c5e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E568u;
    if (runtime->hasFunction(0x13E568u)) {
        auto targetFn = runtime->lookupFunction(0x13E568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E568_0x13e568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C5E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

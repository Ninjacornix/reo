#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE400
// Address: 0x1be400 - 0x1be410
void sub_001BE400_0x1be400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE400_0x1be400");
#endif

    ctx->pc = 0x1be400u;

    // 0x1be400: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1be400u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1be404: 0x8046bfc  j           func_11AFF0
    ctx->pc = 0x1BE404u;
    ctx->pc = 0x1BE408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE404u;
            // 0x1be408: 0x24840498  addiu       $a0, $a0, 0x498 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11AFF0u;
    if (runtime->hasFunction(0x11AFF0u)) {
        auto targetFn = runtime->lookupFunction(0x11AFF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011AFF0_0x11aff0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BE40Cu;
    // 0x1be40c: 0x0  nop
    ctx->pc = 0x1be40cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1BB0
// Address: 0x1b1bb0 - 0x1b1bc0
void sub_001B1BB0_0x1b1bb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1BB0_0x1b1bb0");
#endif

    ctx->pc = 0x1b1bb0u;

    // 0x1b1bb0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1bb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1bb4: 0x806c6d0  j           func_1B1B40
    ctx->pc = 0x1B1BB4u;
    ctx->pc = 0x1B1BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1BB4u;
            // 0x1b1bb8: 0x24060640  addiu       $a2, $zero, 0x640 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1600));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1B40u;
    if (runtime->hasFunction(0x1B1B40u)) {
        auto targetFn = runtime->lookupFunction(0x1B1B40u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B1B40_0x1b1b40(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B1BBCu;
    // 0x1b1bbc: 0x0  nop
    ctx->pc = 0x1b1bbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

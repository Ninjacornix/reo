#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE450
// Address: 0x1be450 - 0x1be460
void sub_001BE450_0x1be450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE450_0x1be450");
#endif

    ctx->pc = 0x1be450u;

    // 0x1be450: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1be450u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be454: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1be454u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1be458: 0x8042a0c  j           func_10A830
    ctx->pc = 0x1BE458u;
    ctx->pc = 0x1BE45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE458u;
            // 0x1be45c: 0x24a504b0  addiu       $a1, $a1, 0x4B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010A830_0x10a830(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BE460u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

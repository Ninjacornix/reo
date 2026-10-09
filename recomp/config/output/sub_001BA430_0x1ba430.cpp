#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA430
// Address: 0x1ba430 - 0x1ba438
void sub_001BA430_0x1ba430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA430_0x1ba430");
#endif

    ctx->pc = 0x1ba430u;

    // 0x1ba430: 0x806b1cc  j           func_1AC730
    ctx->pc = 0x1BA430u;
    ctx->pc = 0x1BA434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA430u;
            // 0x1ba434: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC730u;
    if (runtime->hasFunction(0x1AC730u)) {
        auto targetFn = runtime->lookupFunction(0x1AC730u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AC730_0x1ac730(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BA438u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

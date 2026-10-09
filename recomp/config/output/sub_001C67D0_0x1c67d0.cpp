#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C67D0
// Address: 0x1c67d0 - 0x1c67e0
void sub_001C67D0_0x1c67d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C67D0_0x1c67d0");
#endif

    ctx->pc = 0x1c67d0u;

    // 0x1c67d0: 0x8072fd4  j           func_1CBF50
    ctx->pc = 0x1C67D0u;
    ctx->pc = 0x1CBF50u;
    if (runtime->hasFunction(0x1CBF50u)) {
        auto targetFn = runtime->lookupFunction(0x1CBF50u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001CBF50_0x1cbf50(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C67D8u;
    // 0x1c67d8: 0x0  nop
    ctx->pc = 0x1c67d8u;
    // NOP
    // 0x1c67dc: 0x0  nop
    ctx->pc = 0x1c67dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7D40
// Address: 0x1c7d40 - 0x1c7d50
void sub_001C7D40_0x1c7d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7D40_0x1c7d40");
#endif

    ctx->pc = 0x1c7d40u;

    // 0x1c7d40: 0x8072274  j           func_1C89D0
    ctx->pc = 0x1C7D40u;
    ctx->pc = 0x1C89D0u;
    if (runtime->hasFunction(0x1C89D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C89D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C89D0_0x1c89d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C7D48u;
    // 0x1c7d48: 0x0  nop
    ctx->pc = 0x1c7d48u;
    // NOP
    // 0x1c7d4c: 0x0  nop
    ctx->pc = 0x1c7d4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

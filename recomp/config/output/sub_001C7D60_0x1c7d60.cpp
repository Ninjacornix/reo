#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7D60
// Address: 0x1c7d60 - 0x1c7d70
void sub_001C7D60_0x1c7d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7D60_0x1c7d60");
#endif

    ctx->pc = 0x1c7d60u;

    // 0x1c7d60: 0x8072298  j           func_1C8A60
    ctx->pc = 0x1C7D60u;
    ctx->pc = 0x1C8A60u;
    if (runtime->hasFunction(0x1C8A60u)) {
        auto targetFn = runtime->lookupFunction(0x1C8A60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8A60_0x1c8a60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C7D68u;
    // 0x1c7d68: 0x0  nop
    ctx->pc = 0x1c7d68u;
    // NOP
    // 0x1c7d6c: 0x0  nop
    ctx->pc = 0x1c7d6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

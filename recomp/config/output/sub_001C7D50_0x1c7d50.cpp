#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7D50
// Address: 0x1c7d50 - 0x1c7d60
void sub_001C7D50_0x1c7d50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7D50_0x1c7d50");
#endif

    ctx->pc = 0x1c7d50u;

    // 0x1c7d50: 0x80722bc  j           func_1C8AF0
    ctx->pc = 0x1C7D50u;
    ctx->pc = 0x1C8AF0u;
    if (runtime->hasFunction(0x1C8AF0u)) {
        auto targetFn = runtime->lookupFunction(0x1C8AF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8AF0_0x1c8af0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C7D58u;
    // 0x1c7d58: 0x0  nop
    ctx->pc = 0x1c7d58u;
    // NOP
    // 0x1c7d5c: 0x0  nop
    ctx->pc = 0x1c7d5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7D30
// Address: 0x1c7d30 - 0x1c7d40
void sub_001C7D30_0x1c7d30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7D30_0x1c7d30");
#endif

    ctx->pc = 0x1c7d30u;

    // 0x1c7d30: 0x8072258  j           func_1C8960
    ctx->pc = 0x1C7D30u;
    ctx->pc = 0x1C8960u;
    if (runtime->hasFunction(0x1C8960u)) {
        auto targetFn = runtime->lookupFunction(0x1C8960u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8960_0x1c8960(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C7D38u;
    // 0x1c7d38: 0x0  nop
    ctx->pc = 0x1c7d38u;
    // NOP
    // 0x1c7d3c: 0x0  nop
    ctx->pc = 0x1c7d3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

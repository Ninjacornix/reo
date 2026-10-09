#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7D70
// Address: 0x1c7d70 - 0x1c7d80
void sub_001C7D70_0x1c7d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7D70_0x1c7d70");
#endif

    ctx->pc = 0x1c7d70u;

    // 0x1c7d70: 0x80722c8  j           func_1C8B20
    ctx->pc = 0x1C7D70u;
    ctx->pc = 0x1C8B20u;
    if (runtime->hasFunction(0x1C8B20u)) {
        auto targetFn = runtime->lookupFunction(0x1C8B20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8B20_0x1c8b20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C7D78u;
    // 0x1c7d78: 0x0  nop
    ctx->pc = 0x1c7d78u;
    // NOP
    // 0x1c7d7c: 0x0  nop
    ctx->pc = 0x1c7d7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

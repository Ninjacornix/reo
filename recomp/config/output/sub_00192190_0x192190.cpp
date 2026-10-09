#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192190
// Address: 0x192190 - 0x192198
void sub_00192190_0x192190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192190_0x192190");
#endif

    ctx->pc = 0x192190u;

    // 0x192190: 0x8063cd0  j           func_18F340
    ctx->pc = 0x192190u;
    ctx->pc = 0x18F340u;
    if (runtime->hasFunction(0x18F340u)) {
        auto targetFn = runtime->lookupFunction(0x18F340u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0018F340_0x18f340(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x192198u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8430
// Address: 0x1c8430 - 0x1c8438
void sub_001C8430_0x1c8430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8430_0x1c8430");
#endif

    ctx->pc = 0x1c8430u;

    // 0x1c8430: 0x80722e0  j           func_1C8B80
    ctx->pc = 0x1C8430u;
    ctx->pc = 0x1C8B80u;
    if (runtime->hasFunction(0x1C8B80u)) {
        auto targetFn = runtime->lookupFunction(0x1C8B80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8B80_0x1c8b80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C8438u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

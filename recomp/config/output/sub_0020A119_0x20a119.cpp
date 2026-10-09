#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A119
// Address: 0x20a119 - 0x20a11a
void sub_0020A119_0x20a119(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A119_0x20a119");
#endif

    ctx->pc = 0x20a119u;

    // 0x20a119: 0x8000000  j           func_000000
    ctx->pc = 0x20A119u;
    ctx->pc = 0x0u;
    {
        auto targetFn = runtime->lookupFunction(0x0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x20A121u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

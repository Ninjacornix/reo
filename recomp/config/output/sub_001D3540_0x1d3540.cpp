#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3540
// Address: 0x1d3540 - 0x1d3550
void sub_001D3540_0x1d3540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3540_0x1d3540");
#endif

    ctx->pc = 0x1d3540u;

    // 0x1d3540: 0x8068b80  j           func_1A2E00
    ctx->pc = 0x1D3540u;
    ctx->pc = 0x1A2E00u;
    if (runtime->hasFunction(0x1A2E00u)) {
        auto targetFn = runtime->lookupFunction(0x1A2E00u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A2E00_0x1a2e00(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D3548u;
    // 0x1d3548: 0x0  nop
    ctx->pc = 0x1d3548u;
    // NOP
    // 0x1d354c: 0x0  nop
    ctx->pc = 0x1d354cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

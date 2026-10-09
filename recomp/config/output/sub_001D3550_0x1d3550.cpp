#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3550
// Address: 0x1d3550 - 0x1d3560
void sub_001D3550_0x1d3550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3550_0x1d3550");
#endif

    ctx->pc = 0x1d3550u;

    // 0x1d3550: 0x80687f4  j           func_1A1FD0
    ctx->pc = 0x1D3550u;
    ctx->pc = 0x1A1FD0u;
    if (runtime->hasFunction(0x1A1FD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1FD0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001A1FD0_0x1a1fd0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D3558u;
    // 0x1d3558: 0x0  nop
    ctx->pc = 0x1d3558u;
    // NOP
    // 0x1d355c: 0x0  nop
    ctx->pc = 0x1d355cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

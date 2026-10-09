#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7591
// Address: 0x1f7591 - 0x1f7592
void sub_001F7591_0x1f7591(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7591_0x1f7591");
#endif

    ctx->pc = 0x1f7591u;

    // 0x1f7591: 0xff01e100  sd          $at, -0x1F00($t8)
    ctx->pc = 0x1f7591u;
    WRITE64(ADD32(GPR_U32(ctx, 24), 4294959360), GPR_U64(ctx, 1));
    ctx->pc = GPR_U32(ctx, 31); return;
}

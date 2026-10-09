#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7599
// Address: 0x1f7599 - 0x1f759a
void sub_001F7599_0x1f7599(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7599_0x1f7599");
#endif

    ctx->pc = 0x1f7599u;

    // 0x1f7599: 0xff01e200  sd          $at, -0x1E00($t8)
    ctx->pc = 0x1f7599u;
    WRITE64(ADD32(GPR_U32(ctx, 24), 4294959616), GPR_U64(ctx, 1));
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F75A9
// Address: 0x1f75a9 - 0x1f75aa
void sub_001F75A9_0x1f75a9(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F75A9_0x1f75a9");
#endif

    ctx->pc = 0x1f75a9u;

    // 0x1f75a9: 0xff01e400  sd          $at, -0x1C00($t8)
    ctx->pc = 0x1f75a9u;
    WRITE64(ADD32(GPR_U32(ctx, 24), 4294960128), GPR_U64(ctx, 1));
    ctx->pc = GPR_U32(ctx, 31); return;
}

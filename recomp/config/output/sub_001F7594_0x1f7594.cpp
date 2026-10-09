#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7594
// Address: 0x1f7594 - 0x1f7598
void sub_001F7594_0x1f7594(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7594_0x1f7594");
#endif

    ctx->pc = 0x1f7594u;

    // 0x1f7594: 0x2ff  dsra32      $zero, $zero, 11
    ctx->pc = 0x1f7594u;
    SET_GPR_S64(ctx, 0, GPR_S64(ctx, 0) >> (32 + 11));
    ctx->pc = GPR_U32(ctx, 31); return;
}

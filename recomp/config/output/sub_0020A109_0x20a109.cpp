#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A109
// Address: 0x20a109 - 0x20a10a
void sub_0020A109_0x20a109(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A109_0x20a109");
#endif

    ctx->pc = 0x20a109u;

    // 0x20a109: 0x38000000  xori        $zero, $zero, 0x0
    ctx->pc = 0x20a109u;
    SET_GPR_U64(ctx, 0, GPR_U64(ctx, 0) ^ (uint64_t)(uint16_t)0);
    ctx->pc = GPR_U32(ctx, 31); return;
}

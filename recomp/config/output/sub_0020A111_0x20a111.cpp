#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A111
// Address: 0x20a111 - 0x20a112
void sub_0020A111_0x20a111(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A111_0x20a111");
#endif

    ctx->pc = 0x20a111u;

    // 0x20a111: 0xc8000000  lwc2        $0, 0x0($zero)
    ctx->pc = 0x20a111u;
    // Unhandled opcode: 0x32
    ctx->pc = GPR_U32(ctx, 31); return;
}

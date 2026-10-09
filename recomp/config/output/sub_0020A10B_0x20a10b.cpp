#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A10B
// Address: 0x20a10b - 0x20a10c
void sub_0020A10B_0x20a10b(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A10B_0x20a10b");
#endif

    ctx->pc = 0x20a10bu;

    // 0x20a10b: 0x7503800  bltzal      $k0, . + 4 + (0x3800 << 2)
    ctx->pc = 0x20A10Bu;
    {
        const bool branch_taken_0x20a10b = (GPR_S64(ctx, 26) < 0);
        SET_GPR_U32(ctx, 31, 0x20A113u);
        if (branch_taken_0x20a10b) {
            ctx->pc = 0x21810Fu;
            return;
        }
    }
    ctx->pc = 0x20A113u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

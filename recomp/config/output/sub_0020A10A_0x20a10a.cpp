#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A10A
// Address: 0x20a10a - 0x20a10b
void sub_0020A10A_0x20a10a(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A10A_0x20a10a");
#endif

    ctx->pc = 0x20a10au;

    // 0x20a10a: 0x50380000  beql        $at, $t8, . + 4 + (0x0 << 2)
    ctx->pc = 0x20A10Au;
    {
        const bool branch_taken_0x20a10a = (GPR_U64(ctx, 1) == GPR_U64(ctx, 24));
        if (branch_taken_0x20a10a) {
            ctx->pc = 0x20A10Eu;
            return;
        }
    }
    ctx->pc = 0x20A112u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

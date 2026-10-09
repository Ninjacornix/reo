#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A11A
// Address: 0x20a11a - 0x20a11b
void sub_0020A11A_0x20a11a(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A11A_0x20a11a");
#endif

    ctx->pc = 0x20a11au;

    // 0x20a11a: 0x51080000  beql        $t0, $t0, . + 4 + (0x0 << 2)
    ctx->pc = 0x20A11Au;
    {
        const bool branch_taken_0x20a11a = (GPR_U64(ctx, 8) == GPR_U64(ctx, 8));
        if (branch_taken_0x20a11a) {
            ctx->pc = 0x20A11Eu;
            return;
        }
    }
    ctx->pc = 0x20A122u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A112
// Address: 0x20a112 - 0x20a113
void sub_0020A112_0x20a112(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A112_0x20a112");
#endif

    ctx->pc = 0x20a112u;

    // 0x20a112: 0x50c80000  beql        $a2, $t0, . + 4 + (0x0 << 2)
    ctx->pc = 0x20A112u;
    {
        const bool branch_taken_0x20a112 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 8));
        if (branch_taken_0x20a112) {
            ctx->pc = 0x20A116u;
            return;
        }
    }
    ctx->pc = 0x20A11Au;
    ctx->pc = GPR_U32(ctx, 31); return;
}

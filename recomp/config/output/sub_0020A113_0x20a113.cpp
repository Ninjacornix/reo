#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A113
// Address: 0x20a113 - 0x20a114
void sub_0020A113_0x20a113(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A113_0x20a113");
#endif

    ctx->pc = 0x20a113u;

    // 0x20a113: 0x750c800  bltzal      $k0, . + 4 + (-0x3800 << 2)
    ctx->pc = 0x20A113u;
    {
        const bool branch_taken_0x20a113 = (GPR_S64(ctx, 26) < 0);
        SET_GPR_U32(ctx, 31, 0x20A11Bu);
        if (branch_taken_0x20a113) {
            ctx->pc = 0x1FC117u;
            return;
        }
    }
    ctx->pc = 0x20A11Bu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

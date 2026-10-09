#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A11B
// Address: 0x20a11b - 0x20a11c
void sub_0020A11B_0x20a11b(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A11B_0x20a11b");
#endif

    ctx->pc = 0x20a11bu;

    // 0x20a11b: 0x7510800  bgezal      $k0, . + 4 + (0x800 << 2)
    ctx->pc = 0x20A11Bu;
    {
        const bool branch_taken_0x20a11b = (GPR_S64(ctx, 26) >= 0);
        SET_GPR_U32(ctx, 31, 0x20A123u);
        if (branch_taken_0x20a11b) {
            ctx->pc = 0x20C11Fu;
            return;
        }
    }
    ctx->pc = 0x20A123u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

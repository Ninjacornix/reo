#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A11C
// Address: 0x20a11c - 0x20a120
void sub_0020A11C_0x20a11c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A11C_0x20a11c");
#endif

    ctx->pc = 0x20a11cu;

    // 0x20a11c: 0x80075108  lb          $a3, 0x5108($zero)
    ctx->pc = 0x20a11cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 0), 20744)));
    ctx->pc = GPR_U32(ctx, 31); return;
}

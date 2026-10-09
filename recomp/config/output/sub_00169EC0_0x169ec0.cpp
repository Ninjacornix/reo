#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169EC0
// Address: 0x169ec0 - 0x169ec8
void sub_00169EC0_0x169ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169EC0_0x169ec0");
#endif

    ctx->pc = 0x169ec0u;

    // 0x169ec0: 0x3e00008  jr          $ra
    ctx->pc = 0x169EC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x169EC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

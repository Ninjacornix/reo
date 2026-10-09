#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155B88
// Address: 0x155b88 - 0x155b90
void sub_00155B88_0x155b88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155B88_0x155b88");
#endif

    ctx->pc = 0x155b88u;

    // 0x155b88: 0x3e00008  jr          $ra
    ctx->pc = 0x155B88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x155B90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

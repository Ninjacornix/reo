#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001300F8
// Address: 0x1300f8 - 0x130100
void sub_001300F8_0x1300f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001300F8_0x1300f8");
#endif

    ctx->pc = 0x1300f8u;

    // 0x1300f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1300F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130100u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

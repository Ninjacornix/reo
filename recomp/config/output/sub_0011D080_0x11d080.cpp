#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D080
// Address: 0x11d080 - 0x11d090
void sub_0011D080_0x11d080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D080_0x11d080");
#endif

    ctx->pc = 0x11d080u;

    // 0x11d080: 0x24030059  addiu       $v1, $zero, 0x59
    ctx->pc = 0x11d080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 89));
    // 0x11d084: 0xc  syscall     0
    ctx->pc = 0x11d084u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d088: 0x3e00008  jr          $ra
    ctx->pc = 0x11D088u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D090u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D060
// Address: 0x11d060 - 0x11d070
void sub_0011D060_0x11d060(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D060_0x11d060");
#endif

    ctx->pc = 0x11d060u;

    // 0x11d060: 0x24030058  addiu       $v1, $zero, 0x58
    ctx->pc = 0x11d060u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
    // 0x11d064: 0xc  syscall     0
    ctx->pc = 0x11d064u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d068: 0x3e00008  jr          $ra
    ctx->pc = 0x11D068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D070u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

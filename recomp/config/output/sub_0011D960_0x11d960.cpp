#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D960
// Address: 0x11d960 - 0x11d970
void sub_0011D960_0x11d960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D960_0x11d960");
#endif

    ctx->pc = 0x11d960u;

    // 0x11d960: 0x24030074  addiu       $v1, $zero, 0x74
    ctx->pc = 0x11d960u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 116));
    // 0x11d964: 0xc  syscall     0
    ctx->pc = 0x11d964u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d968: 0x3e00008  jr          $ra
    ctx->pc = 0x11D968u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D970u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

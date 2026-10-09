#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DB20
// Address: 0x11db20 - 0x11db30
void sub_0011DB20_0x11db20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DB20_0x11db20");
#endif

    ctx->pc = 0x11db20u;

    // 0x11db20: 0x24030074  addiu       $v1, $zero, 0x74
    ctx->pc = 0x11db20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 116));
    // 0x11db24: 0xc  syscall     0
    ctx->pc = 0x11db24u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11db28: 0x3e00008  jr          $ra
    ctx->pc = 0x11DB28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11DB30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

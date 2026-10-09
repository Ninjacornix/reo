#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114500
// Address: 0x114500 - 0x114510
void sub_00114500_0x114500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114500_0x114500");
#endif

    ctx->pc = 0x114500u;

    // 0x114500: 0x2403ffd2  addiu       $v1, $zero, -0x2E
    ctx->pc = 0x114500u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967250));
    // 0x114504: 0xc  syscall     0
    ctx->pc = 0x114504u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114508: 0x3e00008  jr          $ra
    ctx->pc = 0x114508u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114510u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

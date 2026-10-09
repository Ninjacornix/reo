#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114200
// Address: 0x114200 - 0x114210
void sub_00114200_0x114200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114200_0x114200");
#endif

    ctx->pc = 0x114200u;

    // 0x114200: 0x24030000  addiu       $v1, $zero, 0x0
    ctx->pc = 0x114200u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 0));
    // 0x114204: 0xc  syscall     0
    ctx->pc = 0x114204u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114208: 0x3e00008  jr          $ra
    ctx->pc = 0x114208u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114210u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114550
// Address: 0x114550 - 0x114560
void sub_00114550_0x114550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114550_0x114550");
#endif

    ctx->pc = 0x114550u;

    // 0x114550: 0x24030033  addiu       $v1, $zero, 0x33
    ctx->pc = 0x114550u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 51));
    // 0x114554: 0xc  syscall     0
    ctx->pc = 0x114554u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114558: 0x3e00008  jr          $ra
    ctx->pc = 0x114558u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114560u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

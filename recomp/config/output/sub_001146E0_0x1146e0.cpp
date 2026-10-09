#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001146E0
// Address: 0x1146e0 - 0x1146f0
void sub_001146E0_0x1146e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001146E0_0x1146e0");
#endif

    ctx->pc = 0x1146e0u;

    // 0x1146e0: 0x2403004c  addiu       $v1, $zero, 0x4C
    ctx->pc = 0x1146e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x1146e4: 0xc  syscall     0
    ctx->pc = 0x1146e4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1146e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1146E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1146F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

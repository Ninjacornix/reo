#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001145E0
// Address: 0x1145e0 - 0x1145f0
void sub_001145E0_0x1145e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001145E0_0x1145e0");
#endif

    ctx->pc = 0x1145e0u;

    // 0x1145e0: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1145e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1145e4: 0xc  syscall     0
    ctx->pc = 0x1145e4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1145e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1145E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1145F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

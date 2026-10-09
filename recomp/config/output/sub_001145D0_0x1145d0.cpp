#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001145D0
// Address: 0x1145d0 - 0x1145e0
void sub_001145D0_0x1145d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001145D0_0x1145d0");
#endif

    ctx->pc = 0x1145d0u;

    // 0x1145d0: 0x2403003b  addiu       $v1, $zero, 0x3B
    ctx->pc = 0x1145d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x1145d4: 0xc  syscall     0
    ctx->pc = 0x1145d4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1145d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1145D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1145E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

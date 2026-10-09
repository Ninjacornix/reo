#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114650
// Address: 0x114650 - 0x114660
void sub_00114650_0x114650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114650_0x114650");
#endif

    ctx->pc = 0x114650u;

    // 0x114650: 0x2403ffbd  addiu       $v1, $zero, -0x43
    ctx->pc = 0x114650u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967229));
    // 0x114654: 0xc  syscall     0
    ctx->pc = 0x114654u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114658: 0x3e00008  jr          $ra
    ctx->pc = 0x114658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114660u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114680
// Address: 0x114680 - 0x114690
void sub_00114680_0x114680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114680_0x114680");
#endif

    ctx->pc = 0x114680u;

    // 0x114680: 0x2403ffba  addiu       $v1, $zero, -0x46
    ctx->pc = 0x114680u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967226));
    // 0x114684: 0xc  syscall     0
    ctx->pc = 0x114684u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114688: 0x3e00008  jr          $ra
    ctx->pc = 0x114688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114690u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

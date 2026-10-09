#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114240
// Address: 0x114240 - 0x114250
void sub_00114240_0x114240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114240_0x114240");
#endif

    ctx->pc = 0x114240u;

    // 0x114240: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x114240u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x114244: 0xc  syscall     0
    ctx->pc = 0x114244u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114248: 0x3e00008  jr          $ra
    ctx->pc = 0x114248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114250u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

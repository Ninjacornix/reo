#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112810
// Address: 0x112810 - 0x112820
void sub_00112810_0x112810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112810_0x112810");
#endif

    ctx->pc = 0x112810u;

    // 0x112810: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x112810u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x112814: 0xc  syscall     0
    ctx->pc = 0x112814u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x112818: 0x3e00008  jr          $ra
    ctx->pc = 0x112818u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x112820u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

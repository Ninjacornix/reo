#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114210
// Address: 0x114210 - 0x114220
void sub_00114210_0x114210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114210_0x114210");
#endif

    ctx->pc = 0x114210u;

    // 0x114210: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x114210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x114214: 0xc  syscall     0
    ctx->pc = 0x114214u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114218: 0x3e00008  jr          $ra
    ctx->pc = 0x114218u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114220u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114430
// Address: 0x114430 - 0x114440
void sub_00114430_0x114430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114430_0x114430");
#endif

    ctx->pc = 0x114430u;

    // 0x114430: 0x24030021  addiu       $v1, $zero, 0x21
    ctx->pc = 0x114430u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x114434: 0xc  syscall     0
    ctx->pc = 0x114434u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114438: 0x3e00008  jr          $ra
    ctx->pc = 0x114438u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114440u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

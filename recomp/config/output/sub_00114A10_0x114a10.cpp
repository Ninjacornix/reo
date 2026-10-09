#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114A10
// Address: 0x114a10 - 0x114a20
void sub_00114A10_0x114a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114A10_0x114a10");
#endif

    ctx->pc = 0x114a10u;

    // 0x114a10: 0x2403ff88  addiu       $v1, $zero, -0x78
    ctx->pc = 0x114a10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967176));
    // 0x114a14: 0xc  syscall     0
    ctx->pc = 0x114a14u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114a18: 0x3e00008  jr          $ra
    ctx->pc = 0x114A18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114A20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

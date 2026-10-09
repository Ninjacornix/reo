#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001148A0
// Address: 0x1148a0 - 0x1148d0
void sub_001148A0_0x1148a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001148A0_0x1148a0");
#endif

    ctx->pc = 0x1148a0u;

    // 0x1148a0: 0x24030064  addiu       $v1, $zero, 0x64
    ctx->pc = 0x1148a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1148a4: 0xc  syscall     0
    ctx->pc = 0x1148a4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1148a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1148A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1148B0u;
    // 0x1148b0: 0x24030066  addiu       $v1, $zero, 0x66
    ctx->pc = 0x1148b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1148b4: 0xc  syscall     0
    ctx->pc = 0x1148b4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1148b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1148B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1148C0u;
    // 0x1148c0: 0x2403ff99  addiu       $v1, $zero, -0x67
    ctx->pc = 0x1148c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967193));
    // 0x1148c4: 0xc  syscall     0
    ctx->pc = 0x1148c4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1148c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1148C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1148D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

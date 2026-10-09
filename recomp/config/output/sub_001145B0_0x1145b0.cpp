#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001145B0
// Address: 0x1145b0 - 0x114600
void sub_001145B0_0x1145b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001145B0_0x1145b0");
#endif

    ctx->pc = 0x1145b0u;

    // 0x1145b0: 0x24030039  addiu       $v1, $zero, 0x39
    ctx->pc = 0x1145b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
    // 0x1145b4: 0xc  syscall     0
    ctx->pc = 0x1145b4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1145b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1145B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1145C0u;
    // 0x1145c0: 0x2403ffc6  addiu       $v1, $zero, -0x3A
    ctx->pc = 0x1145c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967238));
    // 0x1145c4: 0xc  syscall     0
    ctx->pc = 0x1145c4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1145c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1145C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1145D0u;
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
    // 0x1145f0: 0x2403003d  addiu       $v1, $zero, 0x3D
    ctx->pc = 0x1145f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
    // 0x1145f4: 0xc  syscall     0
    ctx->pc = 0x1145f4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1145f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1145F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114600u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

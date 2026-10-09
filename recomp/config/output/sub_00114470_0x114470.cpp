#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114470
// Address: 0x114470 - 0x1144b0
void sub_00114470_0x114470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114470_0x114470");
#endif

    ctx->pc = 0x114470u;

    // 0x114470: 0x24030025  addiu       $v1, $zero, 0x25
    ctx->pc = 0x114470u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x114474: 0xc  syscall     0
    ctx->pc = 0x114474u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114478: 0x3e00008  jr          $ra
    ctx->pc = 0x114478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114480u;
    // 0x114480: 0x2403ffda  addiu       $v1, $zero, -0x26
    ctx->pc = 0x114480u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967258));
    // 0x114484: 0xc  syscall     0
    ctx->pc = 0x114484u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114488: 0x3e00008  jr          $ra
    ctx->pc = 0x114488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114490u;
    // 0x114490: 0x24030027  addiu       $v1, $zero, 0x27
    ctx->pc = 0x114490u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x114494: 0xc  syscall     0
    ctx->pc = 0x114494u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114498: 0x3e00008  jr          $ra
    ctx->pc = 0x114498u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1144A0u;
    // 0x1144a0: 0x24030028  addiu       $v1, $zero, 0x28
    ctx->pc = 0x1144a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1144a4: 0xc  syscall     0
    ctx->pc = 0x1144a4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1144a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1144A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1144B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

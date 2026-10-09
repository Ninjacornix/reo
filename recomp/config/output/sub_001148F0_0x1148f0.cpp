#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001148F0
// Address: 0x1148f0 - 0x114930
void sub_001148F0_0x1148f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001148F0_0x1148f0");
#endif

    ctx->pc = 0x1148f0u;

    // 0x1148f0: 0x2403006b  addiu       $v1, $zero, 0x6B
    ctx->pc = 0x1148f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1148f4: 0xc  syscall     0
    ctx->pc = 0x1148f4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1148f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1148F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114900u;
    // 0x114900: 0x2403006c  addiu       $v1, $zero, 0x6C
    ctx->pc = 0x114900u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x114904: 0xc  syscall     0
    ctx->pc = 0x114904u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114908: 0x3e00008  jr          $ra
    ctx->pc = 0x114908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114910u;
    // 0x114910: 0x2403006d  addiu       $v1, $zero, 0x6D
    ctx->pc = 0x114910u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
    // 0x114914: 0xc  syscall     0
    ctx->pc = 0x114914u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114918: 0x3e00008  jr          $ra
    ctx->pc = 0x114918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114920u;
    // 0x114920: 0x2403006e  addiu       $v1, $zero, 0x6E
    ctx->pc = 0x114920u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 110));
    // 0x114924: 0xc  syscall     0
    ctx->pc = 0x114924u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114928: 0x3e00008  jr          $ra
    ctx->pc = 0x114928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

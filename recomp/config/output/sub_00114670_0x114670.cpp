#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114670
// Address: 0x114670 - 0x1146c0
void sub_00114670_0x114670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114670_0x114670");
#endif

    ctx->pc = 0x114670u;

    // 0x114670: 0x24030045  addiu       $v1, $zero, 0x45
    ctx->pc = 0x114670u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x114674: 0xc  syscall     0
    ctx->pc = 0x114674u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114678: 0x3e00008  jr          $ra
    ctx->pc = 0x114678u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
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
    // 0x114690: 0x24030047  addiu       $v1, $zero, 0x47
    ctx->pc = 0x114690u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
    // 0x114694: 0xc  syscall     0
    ctx->pc = 0x114694u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114698: 0x3e00008  jr          $ra
    ctx->pc = 0x114698u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1146A0u;
    // 0x1146a0: 0x2403ffb8  addiu       $v1, $zero, -0x48
    ctx->pc = 0x1146a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967224));
    // 0x1146a4: 0xc  syscall     0
    ctx->pc = 0x1146a4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1146a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1146A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1146B0u;
    // 0x1146b0: 0x24030049  addiu       $v1, $zero, 0x49
    ctx->pc = 0x1146b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 73));
    // 0x1146b4: 0xc  syscall     0
    ctx->pc = 0x1146b4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1146b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1146B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1146C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

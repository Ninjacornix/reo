#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114270
// Address: 0x114270 - 0x1142d0
void sub_00114270_0x114270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114270_0x114270");
#endif

    ctx->pc = 0x114270u;

    // 0x114270: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x114270u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x114274: 0xc  syscall     0
    ctx->pc = 0x114274u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114278: 0x3e00008  jr          $ra
    ctx->pc = 0x114278u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114280u;
    // 0x114280: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x114280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x114284: 0xc  syscall     0
    ctx->pc = 0x114284u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114288: 0x3e00008  jr          $ra
    ctx->pc = 0x114288u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114290u;
    // 0x114290: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x114290u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x114294: 0xc  syscall     0
    ctx->pc = 0x114294u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114298: 0x3e00008  jr          $ra
    ctx->pc = 0x114298u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1142A0u;
    // 0x1142a0: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x1142a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1142a4: 0xc  syscall     0
    ctx->pc = 0x1142a4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1142a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1142A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1142B0u;
    // 0x1142b0: 0x2403000b  addiu       $v1, $zero, 0xB
    ctx->pc = 0x1142b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1142b4: 0xc  syscall     0
    ctx->pc = 0x1142b4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1142b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1142B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1142C0u;
    // 0x1142c0: 0x2403000c  addiu       $v1, $zero, 0xC
    ctx->pc = 0x1142c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1142c4: 0xc  syscall     0
    ctx->pc = 0x1142c4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1142c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1142C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1142D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001143A0
// Address: 0x1143a0 - 0x1143c0
void sub_001143A0_0x1143a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001143A0_0x1143a0");
#endif

    ctx->pc = 0x1143a0u;

    // 0x1143a0: 0x240300fc  addiu       $v1, $zero, 0xFC
    ctx->pc = 0x1143a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
    // 0x1143a4: 0xc  syscall     0
    ctx->pc = 0x1143a4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1143a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1143A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1143B0u;
    // 0x1143b0: 0x240300fd  addiu       $v1, $zero, 0xFD
    ctx->pc = 0x1143b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 253));
    // 0x1143b4: 0xc  syscall     0
    ctx->pc = 0x1143b4u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1143b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1143B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1143C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

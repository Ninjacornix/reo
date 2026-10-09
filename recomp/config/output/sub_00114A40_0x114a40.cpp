#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114A40
// Address: 0x114a40 - 0x114a50
void sub_00114A40_0x114a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114A40_0x114a40");
#endif

    ctx->pc = 0x114a40u;

    // 0x114a40: 0x2403007b  addiu       $v1, $zero, 0x7B
    ctx->pc = 0x114a40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 123));
    // 0x114a44: 0xc  syscall     0
    ctx->pc = 0x114a44u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114a48: 0x3e00008  jr          $ra
    ctx->pc = 0x114A48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114A50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

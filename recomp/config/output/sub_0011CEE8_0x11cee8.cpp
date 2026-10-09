#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CEE8
// Address: 0x11cee8 - 0x11cef8
void sub_0011CEE8_0x11cee8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CEE8_0x11cee8");
#endif

    ctx->pc = 0x11cee8u;

    // 0x11cee8: 0x2403005b  addiu       $v1, $zero, 0x5B
    ctx->pc = 0x11cee8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 91));
    // 0x11ceec: 0xc  syscall     0
    ctx->pc = 0x11ceecu;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11cef0: 0x3e00008  jr          $ra
    ctx->pc = 0x11CEF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11CEF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

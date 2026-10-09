#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D030
// Address: 0x11d030 - 0x11d040
void sub_0011D030_0x11d030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D030_0x11d030");
#endif

    ctx->pc = 0x11d030u;

    // 0x11d030: 0x2403ffaa  addiu       $v1, $zero, -0x56
    ctx->pc = 0x11d030u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x11d034: 0xc  syscall     0
    ctx->pc = 0x11d034u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x11d038: 0x3e00008  jr          $ra
    ctx->pc = 0x11D038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11D040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

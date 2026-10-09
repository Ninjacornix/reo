#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114220
// Address: 0x114220 - 0x114230
void sub_00114220_0x114220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114220_0x114220");
#endif

    ctx->pc = 0x114220u;

    // 0x114220: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x114220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x114224: 0xc  syscall     0
    ctx->pc = 0x114224u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114228: 0x3e00008  jr          $ra
    ctx->pc = 0x114228u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114230u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

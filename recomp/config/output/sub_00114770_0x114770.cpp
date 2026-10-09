#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114770
// Address: 0x114770 - 0x114780
void sub_00114770_0x114770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114770_0x114770");
#endif

    ctx->pc = 0x114770u;

    // 0x114770: 0x2403ffab  addiu       $v1, $zero, -0x55
    ctx->pc = 0x114770u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967211));
    // 0x114774: 0xc  syscall     0
    ctx->pc = 0x114774u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114778: 0x3e00008  jr          $ra
    ctx->pc = 0x114778u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114780u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

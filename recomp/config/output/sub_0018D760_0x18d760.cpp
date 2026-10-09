#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018D760
// Address: 0x18d760 - 0x18d770
void sub_0018D760_0x18d760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018D760_0x18d760");
#endif

    ctx->pc = 0x18d760u;

    // 0x18d760: 0x3e00008  jr          $ra
    ctx->pc = 0x18D760u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18D768u;
    // 0x18d768: 0x0  nop
    ctx->pc = 0x18d768u;
    // NOP
    // 0x18d76c: 0x0  nop
    ctx->pc = 0x18d76cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

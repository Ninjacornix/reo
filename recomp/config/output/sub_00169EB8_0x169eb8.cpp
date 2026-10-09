#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169EB8
// Address: 0x169eb8 - 0x169ec0
void sub_00169EB8_0x169eb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169EB8_0x169eb8");
#endif

    ctx->pc = 0x169eb8u;

    // 0x169eb8: 0x3e00008  jr          $ra
    ctx->pc = 0x169EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x169EC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D740
// Address: 0x17d740 - 0x17d748
void sub_0017D740_0x17d740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D740_0x17d740");
#endif

    ctx->pc = 0x17d740u;

    // 0x17d740: 0x3e00008  jr          $ra
    ctx->pc = 0x17D740u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D748u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

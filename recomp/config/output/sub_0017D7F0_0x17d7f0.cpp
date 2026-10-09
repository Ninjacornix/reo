#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D7F0
// Address: 0x17d7f0 - 0x17d800
void sub_0017D7F0_0x17d7f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D7F0_0x17d7f0");
#endif

    ctx->pc = 0x17d7f0u;

    // 0x17d7f0: 0xac800040  sw          $zero, 0x40($a0)
    ctx->pc = 0x17d7f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 0));
    // 0x17d7f4: 0x3e00008  jr          $ra
    ctx->pc = 0x17D7F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D7F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D7F4u;
            // 0x17d7f8: 0xac80003c  sw          $zero, 0x3C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D7FCu;
    // 0x17d7fc: 0x0  nop
    ctx->pc = 0x17d7fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

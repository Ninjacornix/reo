#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D470
// Address: 0x17d470 - 0x17d478
void sub_0017D470_0x17d470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D470_0x17d470");
#endif

    ctx->pc = 0x17d470u;

    // 0x17d470: 0x3e00008  jr          $ra
    ctx->pc = 0x17D470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D470u;
            // 0x17d474: 0xac850064  sw          $a1, 0x64($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 100), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D248
// Address: 0x17d248 - 0x17d250
void sub_0017D248_0x17d248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D248_0x17d248");
#endif

    ctx->pc = 0x17d248u;

    // 0x17d248: 0x3e00008  jr          $ra
    ctx->pc = 0x17D248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D248u;
            // 0x17d24c: 0xac850004  sw          $a1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D250u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

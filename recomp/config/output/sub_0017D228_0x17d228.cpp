#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D228
// Address: 0x17d228 - 0x17d234
void sub_0017D228_0x17d228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D228_0x17d228");
#endif

    ctx->pc = 0x17d228u;

    // 0x17d228: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17d228u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17d22c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D22Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D22Cu;
            // 0x17d230: 0xac44f29c  sw          $a0, -0xD64($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963868), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D234u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

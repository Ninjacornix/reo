#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D2D8
// Address: 0x17d2d8 - 0x17d2e8
void sub_0017D2D8_0x17d2d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D2D8_0x17d2d8");
#endif

    ctx->pc = 0x17d2d8u;

    // 0x17d2d8: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x17d2d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x17d2dc: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x17d2dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x17d2e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17D2E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D2E0u;
            // 0x17d2e4: 0x8ca2003c  lw          $v0, 0x3C($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 60)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D2E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

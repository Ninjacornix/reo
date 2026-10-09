#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D3C8
// Address: 0x17d3c8 - 0x17d3d0
void sub_0017D3C8_0x17d3c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D3C8_0x17d3c8");
#endif

    ctx->pc = 0x17d3c8u;

    // 0x17d3c8: 0x3e00008  jr          $ra
    ctx->pc = 0x17D3C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D3CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3C8u;
            // 0x17d3cc: 0x8c820028  lw          $v0, 0x28($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D3D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

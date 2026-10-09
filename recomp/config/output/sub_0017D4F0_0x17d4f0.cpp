#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D4F0
// Address: 0x17d4f0 - 0x17d518
void sub_0017D4F0_0x17d4f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D4F0_0x17d4f0");
#endif

    ctx->pc = 0x17d4f0u;

    // 0x17d4f0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x17d4f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d4f4: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x17d4f4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d4f8: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x17d4f8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x17d4fc: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x17d4fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17d500: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x17d500u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17d504: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x17d504u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x17d508: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x17d508u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x17d50c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D50Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D50Cu;
            // 0x17d510: 0xac860000  sw          $a2, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D514u;
    // 0x17d514: 0x0  nop
    ctx->pc = 0x17d514u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

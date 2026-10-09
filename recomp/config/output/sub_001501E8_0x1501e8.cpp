#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001501E8
// Address: 0x1501e8 - 0x150230
void sub_001501E8_0x1501e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001501E8_0x1501e8");
#endif

    ctx->pc = 0x1501e8u;

    // 0x1501e8: 0x870018  mult        $zero, $a0, $a3
    ctx->pc = 0x1501e8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1501ec: 0x70c50018  mult1       $zero, $a2, $a1
    ctx->pc = 0x1501ecu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 5); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x1501f0: 0x1012  mflo        $v0
    ctx->pc = 0x1501f0u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1501f4: 0x2010  mfhi        $a0
    ctx->pc = 0x1501f4u;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x1501f8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1501f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1501fc: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x1501fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x150200: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x150200u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x150204: 0x70001812  mflo1       $v1
    ctx->pc = 0x150204u;
    SET_GPR_U64(ctx, 3, ctx->lo1);
    // 0x150208: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x150208u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x15020c: 0x70001010  mfhi1       $v0
    ctx->pc = 0x15020cu;
    SET_GPR_U64(ctx, 2, ctx->hi1);
    // 0x150210: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x150210u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x150214: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x150214u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x150218: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x150218u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x15021c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x15021cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x150220: 0x44102a  slt         $v0, $v0, $a0
    ctx->pc = 0x150220u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x150224: 0x3e00008  jr          $ra
    ctx->pc = 0x150224u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150224u;
            // 0x150228: 0x38420001  xori        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15022Cu;
    // 0x15022c: 0x0  nop
    ctx->pc = 0x15022cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

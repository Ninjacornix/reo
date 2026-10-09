#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001022C8
// Address: 0x1022c8 - 0x102308
void sub_001022C8_0x1022c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001022C8_0x1022c8");
#endif

    ctx->pc = 0x1022c8u;

    // 0x1022c8: 0xdca20008  ld          $v0, 0x8($a1)
    ctx->pc = 0x1022c8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1022cc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1022ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1022d0: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x1022d0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1022d4: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1022d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1022d8: 0xffa20008  sd          $v0, 0x8($sp)
    ctx->pc = 0x1022d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 2));
    // 0x1022dc: 0xffa30000  sd          $v1, 0x0($sp)
    ctx->pc = 0x1022dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 3));
    // 0x1022e0: 0x7ba20000  lq          $v0, 0x0($sp)
    ctx->pc = 0x1022e0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1022e4: 0x48450800  cfc2.ni     $a1, $vi1
    ctx->pc = 0x1022e4u;
    SET_GPR_U32(ctx, 5, ctx->vu0_mac_flags);
    // 0x1022e8: 0x48230800  qmfc2.ni    $v1, $vf1
    ctx->pc = 0x1022e8u;
    SET_GPR_VEC(ctx, 3, _mm_castps_si128(ctx->vu0_vf[1]));
    // 0x1022ec: 0x48a20800  qmtc2.ni    $v0, $vf1
    ctx->pc = 0x1022ecu;
    ctx->vu0_vf[1] = _mm_castsi128_ps(GPR_VEC(ctx, 2));
    // 0x1022f0: 0x48c40800  ctc2.ni     $a0, $vi1
    ctx->pc = 0x1022f0u;
    ctx->vu0_mac_flags = GPR_U32(ctx, 4);
    // 0x1022f4: 0x4be10b7d  vsqi.xyzw   $vf1, ($vi1++)
    ctx->pc = 0x1022f4u;
    { uint32_t addr = ((uint32_t)(ctx->vi[1] & 0x3FF)) << 4; __m128i old_val = READ128(addr); __m128 res = _mm_blendv_ps(_mm_castsi128_ps(old_val), ctx->vu0_vf[1], _mm_castsi128_ps(_mm_set_epi32(-1, -1, -1, -1))); WRITE128(addr, _mm_castps_si128(res)); ctx->vi[1] = (ctx->vi[1] + 1) & 0x3FF; }
    // 0x1022f8: 0x48c50800  ctc2.ni     $a1, $vi1
    ctx->pc = 0x1022f8u;
    ctx->vu0_mac_flags = GPR_U32(ctx, 5);
    // 0x1022fc: 0x48a30800  qmtc2.ni    $v1, $vf1
    ctx->pc = 0x1022fcu;
    ctx->vu0_vf[1] = _mm_castsi128_ps(GPR_VEC(ctx, 3));
    // 0x102300: 0x3e00008  jr          $ra
    ctx->pc = 0x102300u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102300u;
            // 0x102304: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x102308u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

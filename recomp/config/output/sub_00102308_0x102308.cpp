#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102308
// Address: 0x102308 - 0x102350
void sub_00102308_0x102308(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102308_0x102308");
#endif

    ctx->pc = 0x102308u;

    // 0x102308: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x102308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10230c: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x10230cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x102310: 0x48460800  cfc2.ni     $a2, $vi1
    ctx->pc = 0x102310u;
    SET_GPR_U32(ctx, 6, ctx->vu0_mac_flags);
    // 0x102314: 0x48230800  qmfc2.ni    $v1, $vf1
    ctx->pc = 0x102314u;
    SET_GPR_VEC(ctx, 3, _mm_castps_si128(ctx->vu0_vf[1]));
    // 0x102318: 0x48c50800  ctc2.ni     $a1, $vi1
    ctx->pc = 0x102318u;
    ctx->vu0_mac_flags = GPR_U32(ctx, 5);
    // 0x10231c: 0x4be10b7c  vlqi.xyzw   $vf1, ($vi1++)
    ctx->pc = 0x10231cu;
    { uint32_t addr = ((uint32_t)(ctx->vi[1] & 0x3FF)) << 4; __m128 res = _mm_castsi128_ps(READ128(addr)); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[1] = _mm_blendv_ps(ctx->vu0_vf[1], res, _mm_castsi128_ps(mask)); ctx->vi[1] = (ctx->vi[1] + 1) & 0x3FF; }
    // 0x102320: 0x48220800  qmfc2.ni    $v0, $vf1
    ctx->pc = 0x102320u;
    SET_GPR_VEC(ctx, 2, _mm_castps_si128(ctx->vu0_vf[1]));
    // 0x102324: 0x48c60800  ctc2.ni     $a2, $vi1
    ctx->pc = 0x102324u;
    ctx->vu0_mac_flags = GPR_U32(ctx, 6);
    // 0x102328: 0x48a30800  qmtc2.ni    $v1, $vf1
    ctx->pc = 0x102328u;
    ctx->vu0_vf[1] = _mm_castsi128_ps(GPR_VEC(ctx, 3));
    // 0x10232c: 0x7fa20000  sq          $v0, 0x0($sp)
    ctx->pc = 0x10232cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 2));
    // 0x102330: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x102330u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102334: 0xdfa30000  ld          $v1, 0x0($sp)
    ctx->pc = 0x102334u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102338: 0xdfa50008  ld          $a1, 0x8($sp)
    ctx->pc = 0x102338u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10233c: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x10233cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x102340: 0xfc850008  sd          $a1, 0x8($a0)
    ctx->pc = 0x102340u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 5));
    // 0x102344: 0x3e00008  jr          $ra
    ctx->pc = 0x102344u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102344u;
            // 0x102348: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10234Cu;
    // 0x10234c: 0x0  nop
    ctx->pc = 0x10234cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

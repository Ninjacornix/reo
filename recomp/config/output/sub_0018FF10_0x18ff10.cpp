#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FF10
// Address: 0x18ff10 - 0x18ff60
void sub_0018FF10_0x18ff10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FF10_0x18ff10");
#endif

    ctx->pc = 0x18ff10u;

    // 0x18ff10: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18ff10u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x18ff14: 0x24634e00  addiu       $v1, $v1, 0x4E00
    ctx->pc = 0x18ff14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19968));
    // 0x18ff18: 0x44066000  mfc1        $a2, $f12
    ctx->pc = 0x18ff18u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x18ff1c: 0x44076800  mfc1        $a3, $f13
    ctx->pc = 0x18ff1cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x18ff20: 0x44087000  mfc1        $t0, $f14
    ctx->pc = 0x18ff20u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18ff24: 0xd8670030  lqc2        $vf7, 0x30($v1)
    ctx->pc = 0x18ff24u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x18ff28: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x18ff28u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x18ff2c: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x18ff2cu;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x18ff30: 0x48a8b000  qmtc2.ni    $t0, $vf22
    ctx->pc = 0x18ff30u;
    ctx->vu0_vf[22] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18ff34: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x18ff34u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18ff38: 0xd8650010  lqc2        $vf5, 0x10($v1)
    ctx->pc = 0x18ff38u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x18ff3c: 0xd8660020  lqc2        $vf6, 0x20($v1)
    ctx->pc = 0x18ff3cu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x18ff40: 0x4b1401c0  vaddx.x     $vf7, $vf0, $vf20x
    ctx->pc = 0x18ff40u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18ff44: 0x4a9501c0  vaddx.y     $vf7, $vf0, $vf21x
    ctx->pc = 0x18ff44u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18ff48: 0x4a5601c0  vaddx.z     $vf7, $vf0, $vf22x
    ctx->pc = 0x18ff48u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[22], ctx->vu0_vf[22], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18ff4c: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18ff4cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x18ff50: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18ff50u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x18ff54: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x18ff54u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x18ff58: 0x3e00008  jr          $ra
    ctx->pc = 0x18FF58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FF5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FF58u;
            // 0x18ff5c: 0xf8870030  sqc2        $vf7, 0x30($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 48), _mm_castps_si128(ctx->vu0_vf[7]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18FF60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

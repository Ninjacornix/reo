#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191900
// Address: 0x191900 - 0x1919d0
void sub_00191900_0x191900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191900_0x191900");
#endif

    ctx->pc = 0x191900u;

    // 0x191900: 0x4be6033d  vmr32.xyzw  $vf6, $vf0
    ctx->pc = 0x191900u;
    ctx->vu0_vf[6] = _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,3,2,1));
    // 0x191904: 0x4be7033c  vmove.xyzw  $vf7, $vf0
    ctx->pc = 0x191904u;
    ctx->vu0_vf[7] = ctx->vu0_vf[0];
    // 0x191908: 0x4be5333d  vmr32.xyzw  $vf5, $vf6
    ctx->pc = 0x191908u;
    ctx->vu0_vf[5] = _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,3,2,1));
    // 0x19190c: 0x4be42b3d  vmr32.xyzw  $vf4, $vf5
    ctx->pc = 0x19190cu;
    ctx->vu0_vf[4] = _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,3,2,1));
    // 0x191910: 0x44086000  mfc1        $t0, $f12
    ctx->pc = 0x191910u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x191914: 0x0  nop
    ctx->pc = 0x191914u;
    // NOP
    // 0x191918: 0x48a84000  qmtc2.ni    $t0, $vf8
    ctx->pc = 0x191918u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x19191c: 0x44086800  mfc1        $t0, $f13
    ctx->pc = 0x19191cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x191920: 0x0  nop
    ctx->pc = 0x191920u;
    // NOP
    // 0x191924: 0x48a84800  qmtc2.ni    $t0, $vf9
    ctx->pc = 0x191924u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x191928: 0xd8aa0000  lqc2        $vf10, 0x0($a1)
    ctx->pc = 0x191928u;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x19192c: 0xd8cb0000  lqc2        $vf11, 0x0($a2)
    ctx->pc = 0x19192cu;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x191930: 0xd8ac0010  lqc2        $vf12, 0x10($a1)
    ctx->pc = 0x191930u;
    ctx->vu0_vf[12] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x191934: 0xd8cd0010  lqc2        $vf13, 0x10($a2)
    ctx->pc = 0x191934u;
    ctx->vu0_vf[13] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x191938: 0xd8ae0030  lqc2        $vf14, 0x30($a1)
    ctx->pc = 0x191938u;
    ctx->vu0_vf[14] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 48)));
    // 0x19193c: 0xd8cf0030  lqc2        $vf15, 0x30($a2)
    ctx->pc = 0x19193cu;
    ctx->vu0_vf[15] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 48)));
    // 0x191940: 0x4bc851bc  vmulax.xyz  $ACC, $vf10, $vf8x
    ctx->pc = 0x191940u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191944: 0x4bc95a88  vmaddx.xyz  $vf10, $vf11, $vf9x
    ctx->pc = 0x191944u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x191948: 0x4bc861bc  vmulax.xyz  $ACC, $vf12, $vf8x
    ctx->pc = 0x191948u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19194c: 0x4bc96b08  vmaddx.xyz  $vf12, $vf13, $vf9x
    ctx->pc = 0x19194cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[13], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x191950: 0x4bc871bc  vmulax.xyz  $ACC, $vf14, $vf8x
    ctx->pc = 0x191950u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[14], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191954: 0x4bc979c8  vmaddx.xyz  $vf7, $vf15, $vf9x
    ctx->pc = 0x191954u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[15], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x191958: 0x4bca512a  vmul.xyz    $vf4, $vf10, $vf10
    ctx->pc = 0x191958u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], ctx->vu0_vf[10]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x19195c: 0x4b042101  vaddy.x     $vf4, $vf4, $vf4y
    ctx->pc = 0x19195cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191960: 0x4b042102  vaddz.x     $vf4, $vf4, $vf4z
    ctx->pc = 0x191960u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191964: 0x4a6403be  vrsqrt      $Q, $vf0w, $vf4x
    ctx->pc = 0x191964u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x191968: 0x4a0003bf  vwaitq
    ctx->pc = 0x191968u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x19196c: 0x4bc0511c  vmulq.xyz   $vf4, $vf10, $Q
    ctx->pc = 0x19196cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191970: 0x4bcc616a  vmul.xyz    $vf5, $vf12, $vf12
    ctx->pc = 0x191970u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[12], ctx->vu0_vf[12]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191974: 0x4b052941  vaddy.x     $vf5, $vf5, $vf5y
    ctx->pc = 0x191974u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191978: 0x4b052942  vaddz.x     $vf5, $vf5, $vf5z
    ctx->pc = 0x191978u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x19197c: 0x4a6503be  vrsqrt      $Q, $vf0w, $vf5x
    ctx->pc = 0x19197cu;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x191980: 0x4a0003bf  vwaitq
    ctx->pc = 0x191980u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x191984: 0x4bc0615c  vmulq.xyz   $vf5, $vf12, $Q
    ctx->pc = 0x191984u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[12], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191988: 0x4bc522fe  vopmula.xyz $ACC, $vf4, $vf5
    ctx->pc = 0x191988u;
    { __m128 res = PS2_VOPMUL(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, res, _mm_castsi128_ps(mask)); }
    // 0x19198c: 0x4bc429ae  vopmsub.xyz $vf6, $vf5, $vf4
    ctx->pc = 0x19198cu;
    { __m128 res = PS2_VSUB(ctx->vu0_acc, PS2_VOPMUL(ctx->vu0_vf[5], ctx->vu0_vf[4])); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x191990: 0x4bc6322a  vmul.xyz    $vf8, $vf6, $vf6
    ctx->pc = 0x191990u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[8] = PS2_VBLEND(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x191994: 0x4b084201  vaddy.x     $vf8, $vf8, $vf8y
    ctx->pc = 0x191994u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x191998: 0x4b084202  vaddz.x     $vf8, $vf8, $vf8z
    ctx->pc = 0x191998u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x19199c: 0x4a6803be  vrsqrt      $Q, $vf0w, $vf8x
    ctx->pc = 0x19199cu;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x1919a0: 0x4a0003bf  vwaitq
    ctx->pc = 0x1919a0u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x1919a4: 0x4bc0319c  vmulq.xyz   $vf6, $vf6, $Q
    ctx->pc = 0x1919a4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1919a8: 0x4bc432fe  vopmula.xyz $ACC, $vf6, $vf4
    ctx->pc = 0x1919a8u;
    { __m128 res = PS2_VOPMUL(ctx->vu0_vf[6], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, res, _mm_castsi128_ps(mask)); }
    // 0x1919ac: 0x4bc6216e  vopmsub.xyz $vf5, $vf4, $vf6
    ctx->pc = 0x1919acu;
    { __m128 res = PS2_VSUB(ctx->vu0_acc, PS2_VOPMUL(ctx->vu0_vf[4], ctx->vu0_vf[6])); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1919b0: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x1919b0u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x1919b4: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x1919b4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x1919b8: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x1919b8u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x1919bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1919BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1919C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1919BCu;
            // 0x1919c0: 0xf8870030  sqc2        $vf7, 0x30($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 48), _mm_castps_si128(ctx->vu0_vf[7]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1919C4u;
    // 0x1919c4: 0x0  nop
    ctx->pc = 0x1919c4u;
    // NOP
    // 0x1919c8: 0x0  nop
    ctx->pc = 0x1919c8u;
    // NOP
    // 0x1919cc: 0x0  nop
    ctx->pc = 0x1919ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

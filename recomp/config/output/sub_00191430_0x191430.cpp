#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191430
// Address: 0x191430 - 0x191500
void sub_00191430_0x191430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191430_0x191430");
#endif

    ctx->pc = 0x191430u;

    // 0x191430: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x191430u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x191434: 0x24634e00  addiu       $v1, $v1, 0x4E00
    ctx->pc = 0x191434u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19968));
    // 0x191438: 0xd8a80000  lqc2        $vf8, 0x0($a1)
    ctx->pc = 0x191438u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x19143c: 0xd8a90010  lqc2        $vf9, 0x10($a1)
    ctx->pc = 0x19143cu;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x191440: 0xd8aa0020  lqc2        $vf10, 0x20($a1)
    ctx->pc = 0x191440u;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x191444: 0xd8ab0030  lqc2        $vf11, 0x30($a1)
    ctx->pc = 0x191444u;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 48)));
    // 0x191448: 0x4bc8406a  vmul.xyz    $vf1, $vf8, $vf8
    ctx->pc = 0x191448u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[8], ctx->vu0_vf[8]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[1] = PS2_VBLEND(ctx->vu0_vf[1], res, _mm_castsi128_ps(mask)); }
    // 0x19144c: 0x4b010841  vaddy.x     $vf1, $vf1, $vf1y
    ctx->pc = 0x19144cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[1], _mm_shuffle_ps(ctx->vu0_vf[1], ctx->vu0_vf[1], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[1] = _mm_blendv_ps(ctx->vu0_vf[1], res, _mm_castsi128_ps(mask)); }
    // 0x191450: 0x4b010842  vaddz.x     $vf1, $vf1, $vf1z
    ctx->pc = 0x191450u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[1], _mm_shuffle_ps(ctx->vu0_vf[1], ctx->vu0_vf[1], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[1] = _mm_blendv_ps(ctx->vu0_vf[1], res, _mm_castsi128_ps(mask)); }
    // 0x191454: 0x4a6103be  vrsqrt      $Q, $vf0w, $vf1x
    ctx->pc = 0x191454u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[1], ctx->vu0_vf[1], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x191458: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x191458u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x19145c: 0xd8650010  lqc2        $vf5, 0x10($v1)
    ctx->pc = 0x19145cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x191460: 0xd8660020  lqc2        $vf6, 0x20($v1)
    ctx->pc = 0x191460u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x191464: 0xd8670030  lqc2        $vf7, 0x30($v1)
    ctx->pc = 0x191464u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x191468: 0x4bc948aa  vmul.xyz    $vf2, $vf9, $vf9
    ctx->pc = 0x191468u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[9], ctx->vu0_vf[9]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[2] = PS2_VBLEND(ctx->vu0_vf[2], res, _mm_castsi128_ps(mask)); }
    // 0x19146c: 0x4b021081  vaddy.x     $vf2, $vf2, $vf2y
    ctx->pc = 0x19146cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[2], _mm_shuffle_ps(ctx->vu0_vf[2], ctx->vu0_vf[2], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[2] = _mm_blendv_ps(ctx->vu0_vf[2], res, _mm_castsi128_ps(mask)); }
    // 0x191470: 0x4b021082  vaddz.x     $vf2, $vf2, $vf2z
    ctx->pc = 0x191470u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[2], _mm_shuffle_ps(ctx->vu0_vf[2], ctx->vu0_vf[2], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[2] = _mm_blendv_ps(ctx->vu0_vf[2], res, _mm_castsi128_ps(mask)); }
    // 0x191474: 0x4bca50ea  vmul.xyz    $vf3, $vf10, $vf10
    ctx->pc = 0x191474u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], ctx->vu0_vf[10]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[3] = PS2_VBLEND(ctx->vu0_vf[3], res, _mm_castsi128_ps(mask)); }
    // 0x191478: 0x4b0318c1  vaddy.x     $vf3, $vf3, $vf3y
    ctx->pc = 0x191478u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[3], _mm_shuffle_ps(ctx->vu0_vf[3], ctx->vu0_vf[3], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[3] = _mm_blendv_ps(ctx->vu0_vf[3], res, _mm_castsi128_ps(mask)); }
    // 0x19147c: 0x4b0318c2  vaddz.x     $vf3, $vf3, $vf3z
    ctx->pc = 0x19147cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[3], _mm_shuffle_ps(ctx->vu0_vf[3], ctx->vu0_vf[3], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[3] = _mm_blendv_ps(ctx->vu0_vf[3], res, _mm_castsi128_ps(mask)); }
    // 0x191480: 0x4bcb056c  vsub.xyz    $vf21, $vf0, $vf11
    ctx->pc = 0x191480u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[11]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[21] = PS2_VBLEND(ctx->vu0_vf[21], res, _mm_castsi128_ps(mask)); }
    // 0x191484: 0x4a0003bf  vwaitq
    ctx->pc = 0x191484u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x191488: 0x4b000520  vaddq.x     $vf20, $vf0, $Q
    ctx->pc = 0x191488u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[20] = _mm_blendv_ps(ctx->vu0_vf[20], res, _mm_castsi128_ps(mask)); }
    // 0x19148c: 0x4a6203be  vrsqrt      $Q, $vf0w, $vf2x
    ctx->pc = 0x19148cu;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[2], ctx->vu0_vf[2], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x191490: 0x4b08a118  vmulx.x     $vf4, $vf20, $vf8x
    ctx->pc = 0x191490u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191494: 0x4b08a159  vmuly.x     $vf5, $vf20, $vf8y
    ctx->pc = 0x191494u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191498: 0x4b08a19a  vmulz.x     $vf6, $vf20, $vf8z
    ctx->pc = 0x191498u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x19149c: 0x4a0003bf  vwaitq
    ctx->pc = 0x19149cu;
    // VWAITQ (Q already resolved in this runtime)
    // 0x1914a0: 0x4a800520  vaddq.y     $vf20, $vf0, $Q
    ctx->pc = 0x1914a0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[20] = _mm_blendv_ps(ctx->vu0_vf[20], res, _mm_castsi128_ps(mask)); }
    // 0x1914a4: 0x4a6303be  vrsqrt      $Q, $vf0w, $vf3x
    ctx->pc = 0x1914a4u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[3], ctx->vu0_vf[3], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x1914a8: 0x4a89a118  vmulx.y     $vf4, $vf20, $vf9x
    ctx->pc = 0x1914a8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1914ac: 0x4a89a159  vmuly.y     $vf5, $vf20, $vf9y
    ctx->pc = 0x1914acu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1914b0: 0x4a89a19a  vmulz.y     $vf6, $vf20, $vf9z
    ctx->pc = 0x1914b0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1914b4: 0x4a0003bf  vwaitq
    ctx->pc = 0x1914b4u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x1914b8: 0x4a400520  vaddq.z     $vf20, $vf0, $Q
    ctx->pc = 0x1914b8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[20] = _mm_blendv_ps(ctx->vu0_vf[20], res, _mm_castsi128_ps(mask)); }
    // 0x1914bc: 0x4a4aa118  vmulx.z     $vf4, $vf20, $vf10x
    ctx->pc = 0x1914bcu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1914c0: 0x4a4aa159  vmuly.z     $vf5, $vf20, $vf10y
    ctx->pc = 0x1914c0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1914c4: 0x4a4aa19a  vmulz.z     $vf6, $vf20, $vf10z
    ctx->pc = 0x1914c4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[20], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1914c8: 0x4bd521bc  vmulax.xyz  $ACC, $vf4, $vf21x
    ctx->pc = 0x1914c8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1914cc: 0x4bd528bd  vmadday.xyz $ACC, $vf5, $vf21y
    ctx->pc = 0x1914ccu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1914d0: 0x4bd531ca  vmaddz.xyz  $vf7, $vf6, $vf21z
    ctx->pc = 0x1914d0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1914d4: 0x4bd4212a  vmul.xyz    $vf4, $vf4, $vf20
    ctx->pc = 0x1914d4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[20]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1914d8: 0x4bd4296a  vmul.xyz    $vf5, $vf5, $vf20
    ctx->pc = 0x1914d8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], ctx->vu0_vf[20]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1914dc: 0x4bd431aa  vmul.xyz    $vf6, $vf6, $vf20
    ctx->pc = 0x1914dcu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], ctx->vu0_vf[20]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1914e0: 0x4bd439ea  vmul.xyz    $vf7, $vf7, $vf20
    ctx->pc = 0x1914e0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], ctx->vu0_vf[20]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[7] = PS2_VBLEND(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1914e4: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x1914e4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x1914e8: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x1914e8u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x1914ec: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x1914ecu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x1914f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1914F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1914F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1914F0u;
            // 0x1914f4: 0xf8870030  sqc2        $vf7, 0x30($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 48), _mm_castps_si128(ctx->vu0_vf[7]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1914F8u;
    // 0x1914f8: 0x0  nop
    ctx->pc = 0x1914f8u;
    // NOP
    // 0x1914fc: 0x0  nop
    ctx->pc = 0x1914fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

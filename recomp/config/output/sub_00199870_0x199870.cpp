#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00199870
// Address: 0x199870 - 0x199920
void sub_00199870_0x199870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00199870_0x199870");
#endif

    ctx->pc = 0x199870u;

    // 0x199870: 0xd8c70000  lqc2        $vf7, 0x0($a2)
    ctx->pc = 0x199870u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x199874: 0xd8c80010  lqc2        $vf8, 0x10($a2)
    ctx->pc = 0x199874u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x199878: 0xd8c90020  lqc2        $vf9, 0x20($a2)
    ctx->pc = 0x199878u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x19987c: 0xd8ca0030  lqc2        $vf10, 0x30($a2)
    ctx->pc = 0x19987cu;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 48)));
    // 0x199880: 0xd8eb0000  lqc2        $vf11, 0x0($a3)
    ctx->pc = 0x199880u;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x199884: 0x4bcb39bc  vmulax.xyz  $ACC, $vf7, $vf11x
    ctx->pc = 0x199884u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x199888: 0x4bcb40bd  vmadday.xyz $ACC, $vf8, $vf11y
    ctx->pc = 0x199888u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19988c: 0x4bcb4aca  vmaddz.xyz  $vf11, $vf9, $vf11z
    ctx->pc = 0x19988cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x199890: 0x4bcb5b2a  vmul.xyz    $vf12, $vf11, $vf11
    ctx->pc = 0x199890u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[11], ctx->vu0_vf[11]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x199894: 0x4b0c6301  vaddy.x     $vf12, $vf12, $vf12y
    ctx->pc = 0x199894u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x199898: 0x4b0c6302  vaddz.x     $vf12, $vf12, $vf12z
    ctx->pc = 0x199898u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x19989c: 0x4a6c03be  vrsqrt      $Q, $vf0w, $vf12x
    ctx->pc = 0x19989cu;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x1998a0: 0x4a0003bf  vwaitq
    ctx->pc = 0x1998a0u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x1998a4: 0x4bc0591c  vmulq.xyz   $vf4, $vf11, $Q
    ctx->pc = 0x1998a4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[11], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1998a8: 0xd8eb0010  lqc2        $vf11, 0x10($a3)
    ctx->pc = 0x1998a8u;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x1998ac: 0xd8ec0020  lqc2        $vf12, 0x20($a3)
    ctx->pc = 0x1998acu;
    ctx->vu0_vf[12] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x1998b0: 0x4beb39bc  vmulax.xyzw $ACC, $vf7, $vf11x
    ctx->pc = 0x1998b0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1998b4: 0x4beb40bd  vmadday.xyzw $ACC, $vf8, $vf11y
    ctx->pc = 0x1998b4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1998b8: 0x4beb48be  vmaddaz.xyzw $ACC, $vf9, $vf11z
    ctx->pc = 0x1998b8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1998bc: 0x4beb514b  vmaddw.xyzw $vf5, $vf10, $vf11w
    ctx->pc = 0x1998bcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1998c0: 0x4bec39bc  vmulax.xyzw $ACC, $vf7, $vf12x
    ctx->pc = 0x1998c0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1998c4: 0x4bec40bd  vmadday.xyzw $ACC, $vf8, $vf12y
    ctx->pc = 0x1998c4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1998c8: 0x4bec48be  vmaddaz.xyzw $ACC, $vf9, $vf12z
    ctx->pc = 0x1998c8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1998cc: 0x4bec518b  vmaddw.xyzw $vf6, $vf10, $vf12w
    ctx->pc = 0x1998ccu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1998d0: 0x4b0401c0  vaddx.x     $vf7, $vf0, $vf4x
    ctx->pc = 0x1998d0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1998d4: 0x4b040201  vaddy.x     $vf8, $vf0, $vf4y
    ctx->pc = 0x1998d4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x1998d8: 0x4b040242  vaddz.x     $vf9, $vf0, $vf4z
    ctx->pc = 0x1998d8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x1998dc: 0x4a8501c0  vaddx.y     $vf7, $vf0, $vf5x
    ctx->pc = 0x1998dcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1998e0: 0x4a850201  vaddy.y     $vf8, $vf0, $vf5y
    ctx->pc = 0x1998e0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x1998e4: 0x4a850242  vaddz.y     $vf9, $vf0, $vf5z
    ctx->pc = 0x1998e4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x1998e8: 0x4a4601c0  vaddx.z     $vf7, $vf0, $vf6x
    ctx->pc = 0x1998e8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1998ec: 0x4a460201  vaddy.z     $vf8, $vf0, $vf6y
    ctx->pc = 0x1998ecu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x1998f0: 0x4a460242  vaddz.z     $vf9, $vf0, $vf6z
    ctx->pc = 0x1998f0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x1998f4: 0xf8870000  sqc2        $vf7, 0x0($a0)
    ctx->pc = 0x1998f4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x1998f8: 0xf8880010  sqc2        $vf8, 0x10($a0)
    ctx->pc = 0x1998f8u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[8]));
    // 0x1998fc: 0xf8890020  sqc2        $vf9, 0x20($a0)
    ctx->pc = 0x1998fcu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x199900: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x199900u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x199904: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199904u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199908: 0xc42041ec  lwc1        $f0, 0x41EC($at)
    ctx->pc = 0x199908u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16876)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19990c: 0xe4a00004  swc1        $f0, 0x4($a1)
    ctx->pc = 0x19990cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x199910: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199910u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199914: 0xc42041f0  lwc1        $f0, 0x41F0($at)
    ctx->pc = 0x199914u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16880)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199918: 0x3e00008  jr          $ra
    ctx->pc = 0x199918u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19991Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199918u;
            // 0x19991c: 0xe4a00008  swc1        $f0, 0x8($a1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x199920u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

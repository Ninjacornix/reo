#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191580
// Address: 0x191580 - 0x191658
void sub_00191580_0x191580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191580_0x191580");
#endif

    ctx->pc = 0x191580u;

    // 0x191580: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x191580u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191584: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x191584u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x191588: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x191588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19158c: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x19158cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x191590: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x191590u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191594: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x191594u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191598: 0xe4e20000  swc1        $f2, 0x0($a3)
    ctx->pc = 0x191598u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 0), bits); }
    // 0x19159c: 0xe4e10004  swc1        $f1, 0x4($a3)
    ctx->pc = 0x19159cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 4), bits); }
    // 0x1915a0: 0xe4e00008  swc1        $f0, 0x8($a3)
    ctx->pc = 0x1915a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 8), bits); }
    // 0x1915a4: 0xc4c20000  lwc1        $f2, 0x0($a2)
    ctx->pc = 0x1915a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1915a8: 0xc4c10004  lwc1        $f1, 0x4($a2)
    ctx->pc = 0x1915a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1915ac: 0xc4c00008  lwc1        $f0, 0x8($a2)
    ctx->pc = 0x1915acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1915b0: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x1915b0u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x1915b4: 0xe4610004  swc1        $f1, 0x4($v1)
    ctx->pc = 0x1915b4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x1915b8: 0xe4600008  swc1        $f0, 0x8($v1)
    ctx->pc = 0x1915b8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 8), bits); }
    // 0x1915bc: 0xd8e40000  lqc2        $vf4, 0x0($a3)
    ctx->pc = 0x1915bcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1915c0: 0xd8650000  lqc2        $vf5, 0x0($v1)
    ctx->pc = 0x1915c0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1915c4: 0x4bc422aa  vmul.xyz    $vf10, $vf4, $vf4
    ctx->pc = 0x1915c4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1915c8: 0x4b0a5281  vaddy.x     $vf10, $vf10, $vf10y
    ctx->pc = 0x1915c8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1915cc: 0x4b0a5282  vaddz.x     $vf10, $vf10, $vf10z
    ctx->pc = 0x1915ccu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1915d0: 0x4a6a03be  vrsqrt      $Q, $vf0w, $vf10x
    ctx->pc = 0x1915d0u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x1915d4: 0x4a0003bf  vwaitq
    ctx->pc = 0x1915d4u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x1915d8: 0x4bc0211c  vmulq.xyz   $vf4, $vf4, $Q
    ctx->pc = 0x1915d8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1915dc: 0x4bc52aaa  vmul.xyz    $vf10, $vf5, $vf5
    ctx->pc = 0x1915dcu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1915e0: 0x4b0a5281  vaddy.x     $vf10, $vf10, $vf10y
    ctx->pc = 0x1915e0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1915e4: 0x4b0a5282  vaddz.x     $vf10, $vf10, $vf10z
    ctx->pc = 0x1915e4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1915e8: 0x4a6a03be  vrsqrt      $Q, $vf0w, $vf10x
    ctx->pc = 0x1915e8u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x1915ec: 0x4a0003bf  vwaitq
    ctx->pc = 0x1915ecu;
    // VWAITQ (Q already resolved in this runtime)
    // 0x1915f0: 0x4bc0295c  vmulq.xyz   $vf5, $vf5, $Q
    ctx->pc = 0x1915f0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1915f4: 0x4bc522fe  vopmula.xyz $ACC, $vf4, $vf5
    ctx->pc = 0x1915f4u;
    { __m128 res = PS2_VOPMUL(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, res, _mm_castsi128_ps(mask)); }
    // 0x1915f8: 0x4bc429ae  vopmsub.xyz $vf6, $vf5, $vf4
    ctx->pc = 0x1915f8u;
    { __m128 res = PS2_VSUB(ctx->vu0_acc, PS2_VOPMUL(ctx->vu0_vf[5], ctx->vu0_vf[4])); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1915fc: 0x4bc6322a  vmul.xyz    $vf8, $vf6, $vf6
    ctx->pc = 0x1915fcu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[8] = PS2_VBLEND(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x191600: 0x4b084201  vaddy.x     $vf8, $vf8, $vf8y
    ctx->pc = 0x191600u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x191604: 0x4b084202  vaddz.x     $vf8, $vf8, $vf8z
    ctx->pc = 0x191604u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x191608: 0x4a6803be  vrsqrt      $Q, $vf0w, $vf8x
    ctx->pc = 0x191608u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x19160c: 0x4a0003bf  vwaitq
    ctx->pc = 0x19160cu;
    // VWAITQ (Q already resolved in this runtime)
    // 0x191610: 0x4bc0319c  vmulq.xyz   $vf6, $vf6, $Q
    ctx->pc = 0x191610u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x191614: 0x4bc432fe  vopmula.xyz $ACC, $vf6, $vf4
    ctx->pc = 0x191614u;
    { __m128 res = PS2_VOPMUL(ctx->vu0_vf[6], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, res, _mm_castsi128_ps(mask)); }
    // 0x191618: 0x4bc6216e  vopmsub.xyz $vf5, $vf4, $vf6
    ctx->pc = 0x191618u;
    { __m128 res = PS2_VSUB(ctx->vu0_acc, PS2_VOPMUL(ctx->vu0_vf[4], ctx->vu0_vf[6])); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x19161c: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x19161cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191620: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x191620u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x191624: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x191624u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x191628: 0x44801800  mtc1        $zero, $f3
    ctx->pc = 0x191628u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x19162c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19162cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x191630: 0x44801000  mtc1        $zero, $f2
    ctx->pc = 0x191630u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x191634: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x191634u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x191638: 0xe483000c  swc1        $f3, 0xC($a0)
    ctx->pc = 0x191638u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 12), bits); }
    // 0x19163c: 0xe482001c  swc1        $f2, 0x1C($a0)
    ctx->pc = 0x19163cu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 28), bits); }
    // 0x191640: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x191640u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191644: 0x0  nop
    ctx->pc = 0x191644u;
    // NOP
    // 0x191648: 0xe481002c  swc1        $f1, 0x2C($a0)
    ctx->pc = 0x191648u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 44), bits); }
    // 0x19164c: 0xe480003c  swc1        $f0, 0x3C($a0)
    ctx->pc = 0x19164cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 60), bits); }
    // 0x191650: 0x3e00008  jr          $ra
    ctx->pc = 0x191650u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191650u;
            // 0x191654: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x191658u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

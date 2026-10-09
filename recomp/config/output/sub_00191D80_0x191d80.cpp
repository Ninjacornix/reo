#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191D80
// Address: 0x191d80 - 0x191df0
void sub_00191D80_0x191d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191D80_0x191d80");
#endif

    ctx->pc = 0x191d80u;

    // 0x191d80: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191d80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191d84: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x191d84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x191d88: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191d88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191d8c: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x191d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191d90: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191d90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191d94: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x191d94u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x191d98: 0xe4610004  swc1        $f1, 0x4($v1)
    ctx->pc = 0x191d98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x191d9c: 0xe4600008  swc1        $f0, 0x8($v1)
    ctx->pc = 0x191d9cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 8), bits); }
    // 0x191da0: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x191da0u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x191da4: 0x4bc4216a  vmul.xyz    $vf5, $vf4, $vf4
    ctx->pc = 0x191da4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191da8: 0x4b052941  vaddy.x     $vf5, $vf5, $vf5y
    ctx->pc = 0x191da8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191dac: 0x4b052942  vaddz.x     $vf5, $vf5, $vf5z
    ctx->pc = 0x191dacu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191db0: 0x4a6503be  vrsqrt      $Q, $vf0w, $vf5x
    ctx->pc = 0x191db0u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x191db4: 0x4a0003bf  vwaitq
    ctx->pc = 0x191db4u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x191db8: 0x4bc0211c  vmulq.xyz   $vf4, $vf4, $Q
    ctx->pc = 0x191db8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191dbc: 0xf8640000  sqc2        $vf4, 0x0($v1)
    ctx->pc = 0x191dbcu;
    WRITE128(ADD32(GPR_U32(ctx, 3), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191dc0: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x191dc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191dc4: 0xc4620000  lwc1        $f2, 0x0($v1)
    ctx->pc = 0x191dc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191dc8: 0xc4610004  lwc1        $f1, 0x4($v1)
    ctx->pc = 0x191dc8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191dcc: 0xc4600008  lwc1        $f0, 0x8($v1)
    ctx->pc = 0x191dccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191dd0: 0xe4820000  swc1        $f2, 0x0($a0)
    ctx->pc = 0x191dd0u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x191dd4: 0xe4810004  swc1        $f1, 0x4($a0)
    ctx->pc = 0x191dd4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x191dd8: 0xe4800008  swc1        $f0, 0x8($a0)
    ctx->pc = 0x191dd8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x191ddc: 0x3e00008  jr          $ra
    ctx->pc = 0x191DDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191DDCu;
            // 0x191de0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x191DE4u;
    // 0x191de4: 0x0  nop
    ctx->pc = 0x191de4u;
    // NOP
    // 0x191de8: 0x0  nop
    ctx->pc = 0x191de8u;
    // NOP
    // 0x191dec: 0x0  nop
    ctx->pc = 0x191decu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FF60
// Address: 0x18ff60 - 0x18ffa4
void sub_0018FF60_0x18ff60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FF60_0x18ff60");
#endif

    ctx->pc = 0x18ff60u;

    // 0x18ff60: 0x44066000  mfc1        $a2, $f12
    ctx->pc = 0x18ff60u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x18ff64: 0xd8840000  lqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18ff64u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18ff68: 0xd8850010  lqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18ff68u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x18ff6c: 0xd8860020  lqc2        $vf6, 0x20($a0)
    ctx->pc = 0x18ff6cu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x18ff70: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x18ff70u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x18ff74: 0xd8870030  lqc2        $vf7, 0x30($a0)
    ctx->pc = 0x18ff74u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x18ff78: 0x4a0002ff  vnop
    ctx->pc = 0x18ff78u;
    // NOP operation, no action needed for VU0
    // 0x18ff7c: 0x4a0002ff  vnop
    ctx->pc = 0x18ff7cu;
    // NOP operation, no action needed for VU0
    // 0x18ff80: 0x4bf42118  vmulx.xyzw  $vf4, $vf4, $vf20x
    ctx->pc = 0x18ff80u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x18ff84: 0x4bf42958  vmulx.xyzw  $vf5, $vf5, $vf20x
    ctx->pc = 0x18ff84u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18ff88: 0x4bf43198  vmulx.xyzw  $vf6, $vf6, $vf20x
    ctx->pc = 0x18ff88u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18ff8c: 0x4bf439d8  vmulx.xyzw  $vf7, $vf7, $vf20x
    ctx->pc = 0x18ff8cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18ff90: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18ff90u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x18ff94: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18ff94u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x18ff98: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x18ff98u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x18ff9c: 0x3e00008  jr          $ra
    ctx->pc = 0x18FF9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FFA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FF9Cu;
            // 0x18ffa0: 0xf8870030  sqc2        $vf7, 0x30($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 48), _mm_castps_si128(ctx->vu0_vf[7]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18FFA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

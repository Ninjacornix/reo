#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FFB0
// Address: 0x18ffb0 - 0x18ffe0
void sub_0018FFB0_0x18ffb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FFB0_0x18ffb0");
#endif

    ctx->pc = 0x18ffb0u;

    // 0x18ffb0: 0x44066000  mfc1        $a2, $f12
    ctx->pc = 0x18ffb0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x18ffb4: 0xd8840000  lqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18ffb4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18ffb8: 0xd8850010  lqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18ffb8u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x18ffbc: 0xd8860020  lqc2        $vf6, 0x20($a0)
    ctx->pc = 0x18ffbcu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x18ffc0: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x18ffc0u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x18ffc4: 0x4bd42118  vmulx.xyz   $vf4, $vf4, $vf20x
    ctx->pc = 0x18ffc4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x18ffc8: 0x4bd42958  vmulx.xyz   $vf5, $vf5, $vf20x
    ctx->pc = 0x18ffc8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18ffcc: 0x4bd43198  vmulx.xyz   $vf6, $vf6, $vf20x
    ctx->pc = 0x18ffccu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18ffd0: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18ffd0u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x18ffd4: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18ffd4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x18ffd8: 0x3e00008  jr          $ra
    ctx->pc = 0x18FFD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FFD8u;
            // 0x18ffdc: 0xf8860020  sqc2        $vf6, 0x20($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18FFE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

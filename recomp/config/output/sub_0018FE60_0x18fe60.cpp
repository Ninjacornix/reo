#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FE60
// Address: 0x18fe60 - 0x18feb0
void sub_0018FE60_0x18fe60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FE60_0x18fe60");
#endif

    ctx->pc = 0x18fe60u;

    // 0x18fe60: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18fe60u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x18fe64: 0x24634e00  addiu       $v1, $v1, 0x4E00
    ctx->pc = 0x18fe64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19968));
    // 0x18fe68: 0x44066000  mfc1        $a2, $f12
    ctx->pc = 0x18fe68u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x18fe6c: 0x44076800  mfc1        $a3, $f13
    ctx->pc = 0x18fe6cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x18fe70: 0x44087000  mfc1        $t0, $f14
    ctx->pc = 0x18fe70u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18fe74: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x18fe74u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18fe78: 0x48a64000  qmtc2.ni    $a2, $vf8
    ctx->pc = 0x18fe78u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x18fe7c: 0x48a74800  qmtc2.ni    $a3, $vf9
    ctx->pc = 0x18fe7cu;
    ctx->vu0_vf[9] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x18fe80: 0x48a85000  qmtc2.ni    $t0, $vf10
    ctx->pc = 0x18fe80u;
    ctx->vu0_vf[10] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18fe84: 0xd8650010  lqc2        $vf5, 0x10($v1)
    ctx->pc = 0x18fe84u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x18fe88: 0xd8660020  lqc2        $vf6, 0x20($v1)
    ctx->pc = 0x18fe88u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x18fe8c: 0xd8670030  lqc2        $vf7, 0x30($v1)
    ctx->pc = 0x18fe8cu;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x18fe90: 0x4b080100  vaddx.x     $vf4, $vf0, $vf8x
    ctx->pc = 0x18fe90u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x18fe94: 0x4a890140  vaddx.y     $vf5, $vf0, $vf9x
    ctx->pc = 0x18fe94u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18fe98: 0x4a4a0180  vaddx.z     $vf6, $vf0, $vf10x
    ctx->pc = 0x18fe98u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18fe9c: 0xf8870030  sqc2        $vf7, 0x30($a0)
    ctx->pc = 0x18fe9cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 48), _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x18fea0: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18fea0u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x18fea4: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18fea4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x18fea8: 0x3e00008  jr          $ra
    ctx->pc = 0x18FEA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FEACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FEA8u;
            // 0x18feac: 0xf8860020  sqc2        $vf6, 0x20($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18FEB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

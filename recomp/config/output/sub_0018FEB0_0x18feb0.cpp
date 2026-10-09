#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FEB0
// Address: 0x18feb0 - 0x1900e0
void sub_0018FEB0_0x18feb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FEB0_0x18feb0");
#endif

    switch (ctx->pc) {
        case 0x18fff8u: goto label_18fff8;
        case 0x190004u: goto label_190004;
        case 0x190044u: goto label_190044;
        case 0x190050u: goto label_190050;
        default: break;
    }

    ctx->pc = 0x18feb0u;

label_18feb0:
    // 0x18feb0: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18feb0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x18feb4: 0x24634e00  addiu       $v1, $v1, 0x4E00
    ctx->pc = 0x18feb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19968));
    // 0x18feb8: 0x44066000  mfc1        $a2, $f12
    ctx->pc = 0x18feb8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x18febc: 0x44076800  mfc1        $a3, $f13
    ctx->pc = 0x18febcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x18fec0: 0x44087000  mfc1        $t0, $f14
    ctx->pc = 0x18fec0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18fec4: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x18fec4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18fec8: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x18fec8u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x18fecc: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x18feccu;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x18fed0: 0x48a8b000  qmtc2.ni    $t0, $vf22
    ctx->pc = 0x18fed0u;
    ctx->vu0_vf[22] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18fed4: 0xd8650010  lqc2        $vf5, 0x10($v1)
    ctx->pc = 0x18fed4u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x18fed8: 0xd8660020  lqc2        $vf6, 0x20($v1)
    ctx->pc = 0x18fed8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x18fedc: 0xd8880000  lqc2        $vf8, 0x0($a0)
    ctx->pc = 0x18fedcu;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18fee0: 0xd8890010  lqc2        $vf9, 0x10($a0)
    ctx->pc = 0x18fee0u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x18fee4: 0xd88a0020  lqc2        $vf10, 0x20($a0)
    ctx->pc = 0x18fee4u;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x18fee8: 0x4b140100  vaddx.x     $vf4, $vf0, $vf20x
    ctx->pc = 0x18fee8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x18feec: 0x4a950140  vaddx.y     $vf5, $vf0, $vf21x
    ctx->pc = 0x18feecu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18fef0: 0x4a560180  vaddx.z     $vf6, $vf0, $vf22x
    ctx->pc = 0x18fef0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[22], ctx->vu0_vf[22], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18fef4: 0x4a204100  vaddx.w     $vf4, $vf8, $vf0x
    ctx->pc = 0x18fef4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x18fef8: 0x4a204940  vaddx.w     $vf5, $vf9, $vf0x
    ctx->pc = 0x18fef8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18fefc: 0x4a205180  vaddx.w     $vf6, $vf10, $vf0x
    ctx->pc = 0x18fefcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18ff00: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18ff00u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x18ff04: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18ff04u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x18ff08: 0x3e00008  jr          $ra
    ctx->pc = 0x18FF08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FF08u;
            // 0x18ff0c: 0xf8860020  sqc2        $vf6, 0x20($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18FF10u;
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
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18FF60u;
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
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18FFA4u;
    // 0x18ffa4: 0x0  nop
    ctx->pc = 0x18ffa4u;
    // NOP
    // 0x18ffa8: 0x0  nop
    ctx->pc = 0x18ffa8u;
    // NOP
    // 0x18ffac: 0x0  nop
    ctx->pc = 0x18ffacu;
    // NOP
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
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18FFE0u;
    // 0x18ffe0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x18ffe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18ffe4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18ffe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18ffe8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18ffe8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18ffec: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18ffecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fff0: 0xc063fac  jal         func_18FEB0
    ctx->pc = 0x18FFF0u;
    SET_GPR_U32(ctx, 31, 0x18FFF8u);
    ctx->pc = 0x18FFF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18FFF0u;
            // 0x18fff4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FEB0u;
    goto label_18feb0;
    ctx->pc = 0x18FFF8u;
label_18fff8:
    // 0x18fff8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18fff8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fffc: 0xc0644f8  jal         func_1913E0
    ctx->pc = 0x18FFFCu;
    SET_GPR_U32(ctx, 31, 0x190004u);
    ctx->pc = 0x190000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18FFFCu;
            // 0x190000: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1913E0u;
    if (runtime->hasFunction(0x1913E0u)) {
        auto targetFn = runtime->lookupFunction(0x1913E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190004u; }
        if (ctx->pc != 0x190004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001913E0_0x1913e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190004u; }
        if (ctx->pc != 0x190004u) { return; }
    }
    ctx->pc = 0x190004u;
label_190004:
    // 0x190004: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x190004u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x190008: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x190008u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19000c: 0x3e00008  jr          $ra
    ctx->pc = 0x19000Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19000Cu;
            // 0x190010: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190014u;
    // 0x190014: 0x0  nop
    ctx->pc = 0x190014u;
    // NOP
    // 0x190018: 0x0  nop
    ctx->pc = 0x190018u;
    // NOP
    // 0x19001c: 0x0  nop
    ctx->pc = 0x19001cu;
    // NOP
    // 0x190020: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x190020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x190024: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x190024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x190028: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x190028u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19002c: 0xc4ac0000  lwc1        $f12, 0x0($a1)
    ctx->pc = 0x19002cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x190030: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x190030u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190034: 0xc4ad0004  lwc1        $f13, 0x4($a1)
    ctx->pc = 0x190034u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x190038: 0xc4ae0008  lwc1        $f14, 0x8($a1)
    ctx->pc = 0x190038u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x19003c: 0xc063fac  jal         func_18FEB0
    ctx->pc = 0x19003Cu;
    SET_GPR_U32(ctx, 31, 0x190044u);
    ctx->pc = 0x190040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19003Cu;
            // 0x190040: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FEB0u;
    goto label_18feb0;
    ctx->pc = 0x190044u;
label_190044:
    // 0x190044: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x190044u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190048: 0xc0644f8  jal         func_1913E0
    ctx->pc = 0x190048u;
    SET_GPR_U32(ctx, 31, 0x190050u);
    ctx->pc = 0x19004Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190048u;
            // 0x19004c: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1913E0u;
    if (runtime->hasFunction(0x1913E0u)) {
        auto targetFn = runtime->lookupFunction(0x1913E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190050u; }
        if (ctx->pc != 0x190050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001913E0_0x1913e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190050u; }
        if (ctx->pc != 0x190050u) { return; }
    }
    ctx->pc = 0x190050u;
label_190050:
    // 0x190050: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x190050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x190054: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x190054u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x190058: 0x3e00008  jr          $ra
    ctx->pc = 0x190058u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19005Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190058u;
            // 0x19005c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190060u;
    // 0x190060: 0xe48c0030  swc1        $f12, 0x30($a0)
    ctx->pc = 0x190060u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x190064: 0xe48d0034  swc1        $f13, 0x34($a0)
    ctx->pc = 0x190064u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x190068: 0x3e00008  jr          $ra
    ctx->pc = 0x190068u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19006Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190068u;
            // 0x19006c: 0xe48e0038  swc1        $f14, 0x38($a0) (Delay Slot)
        { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190070u;
    // 0x190070: 0xc4800030  lwc1        $f0, 0x30($a0)
    ctx->pc = 0x190070u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190074: 0x460c0000  add.s       $f0, $f0, $f12
    ctx->pc = 0x190074u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[12]);
    // 0x190078: 0xe4800030  swc1        $f0, 0x30($a0)
    ctx->pc = 0x190078u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x19007c: 0xc4800034  lwc1        $f0, 0x34($a0)
    ctx->pc = 0x19007cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190080: 0x460d0000  add.s       $f0, $f0, $f13
    ctx->pc = 0x190080u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[13]);
    // 0x190084: 0xe4800034  swc1        $f0, 0x34($a0)
    ctx->pc = 0x190084u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x190088: 0xc4800038  lwc1        $f0, 0x38($a0)
    ctx->pc = 0x190088u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19008c: 0x460e0000  add.s       $f0, $f0, $f14
    ctx->pc = 0x19008cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[14]);
    // 0x190090: 0x3e00008  jr          $ra
    ctx->pc = 0x190090u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190090u;
            // 0x190094: 0xe4800038  swc1        $f0, 0x38($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190098u;
    // 0x190098: 0x0  nop
    ctx->pc = 0x190098u;
    // NOP
    // 0x19009c: 0x0  nop
    ctx->pc = 0x19009cu;
    // NOP
    // 0x1900a0: 0xc4810030  lwc1        $f1, 0x30($a0)
    ctx->pc = 0x1900a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1900a4: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x1900a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1900a8: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1900a8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1900ac: 0xe4800030  swc1        $f0, 0x30($a0)
    ctx->pc = 0x1900acu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x1900b0: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x1900b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1900b4: 0xc4800034  lwc1        $f0, 0x34($a0)
    ctx->pc = 0x1900b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1900b8: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x1900b8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1900bc: 0xe4800034  swc1        $f0, 0x34($a0)
    ctx->pc = 0x1900bcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x1900c0: 0xc4a10008  lwc1        $f1, 0x8($a1)
    ctx->pc = 0x1900c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1900c4: 0xc4800038  lwc1        $f0, 0x38($a0)
    ctx->pc = 0x1900c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1900c8: 0x46010000  add.s       $f0, $f0, $f1
    ctx->pc = 0x1900c8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1900cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1900CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1900D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1900CCu;
            // 0x1900d0: 0xe4800038  swc1        $f0, 0x38($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FEB0u: goto label_18feb0;
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1900D4u;
    // 0x1900d4: 0x0  nop
    ctx->pc = 0x1900d4u;
    // NOP
    // 0x1900d8: 0x0  nop
    ctx->pc = 0x1900d8u;
    // NOP
    // 0x1900dc: 0x0  nop
    ctx->pc = 0x1900dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

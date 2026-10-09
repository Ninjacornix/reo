#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F260
// Address: 0x18f260 - 0x18f570
void sub_0018F260_0x18f260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F260_0x18f260");
#endif

    ctx->pc = 0x18f260u;

    // 0x18f260: 0x44086000  mfc1        $t0, $f12
    ctx->pc = 0x18f260u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f264: 0x0  nop
    ctx->pc = 0x18f264u;
    // NOP
    // 0x18f268: 0x48a81800  qmtc2.ni    $t0, $vf3
    ctx->pc = 0x18f268u;
    ctx->vu0_vf[3] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f26c: 0x44087000  mfc1        $t0, $f14
    ctx->pc = 0x18f26cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[14], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f270: 0x0  nop
    ctx->pc = 0x18f270u;
    // NOP
    // 0x18f274: 0x48a82000  qmtc2.ni    $t0, $vf4
    ctx->pc = 0x18f274u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f278: 0x44088800  mfc1        $t0, $f17
    ctx->pc = 0x18f278u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[17], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f27c: 0x0  nop
    ctx->pc = 0x18f27cu;
    // NOP
    // 0x18f280: 0x48a82800  qmtc2.ni    $t0, $vf5
    ctx->pc = 0x18f280u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f284: 0x44086800  mfc1        $t0, $f13
    ctx->pc = 0x18f284u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[13], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f288: 0x0  nop
    ctx->pc = 0x18f288u;
    // NOP
    // 0x18f28c: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x18f28cu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f290: 0x44088000  mfc1        $t0, $f16
    ctx->pc = 0x18f290u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[16], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f294: 0x0  nop
    ctx->pc = 0x18f294u;
    // NOP
    // 0x18f298: 0x48a83800  qmtc2.ni    $t0, $vf7
    ctx->pc = 0x18f298u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f29c: 0x44087800  mfc1        $t0, $f15
    ctx->pc = 0x18f29cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[15], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f2a0: 0x0  nop
    ctx->pc = 0x18f2a0u;
    // NOP
    // 0x18f2a4: 0x48a84000  qmtc2.ni    $t0, $vf8
    ctx->pc = 0x18f2a4u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f2a8: 0x44089000  mfc1        $t0, $f18
    ctx->pc = 0x18f2a8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[18], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f2ac: 0x0  nop
    ctx->pc = 0x18f2acu;
    // NOP
    // 0x18f2b0: 0x48a81000  qmtc2.ni    $t0, $vf2
    ctx->pc = 0x18f2b0u;
    ctx->vu0_vf[2] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f2b4: 0x4b041a6c  vsub.x      $vf9, $vf3, $vf4
    ctx->pc = 0x18f2b4u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[3], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[9] = PS2_VBLEND(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x18f2b8: 0x4b042aac  vsub.x      $vf10, $vf5, $vf4
    ctx->pc = 0x18f2b8u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[5], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x18f2bc: 0x4a6a03bc  vdiv        $Q, $vf0w, $vf10x
    ctx->pc = 0x18f2bcu;
    { float fs = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,3))); float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); if (ft != 0.0f) { ctx->vu0_q = fs / ft; } else { uint32_t sign = (std::bit_cast<uint32_t>(fs) ^ std::bit_cast<uint32_t>(ft)) & 0x80000000u; uint32_t maxf = 0x7F7FFFFFu | sign; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x18f2c0: 0x4a0003bf  vwaitq
    ctx->pc = 0x18f2c0u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x18f2c4: 0x4b0002a0  vaddq.x     $vf10, $vf0, $Q
    ctx->pc = 0x18f2c4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x18f2c8: 0x4b0a52ea  vmul.x      $vf11, $vf10, $vf10
    ctx->pc = 0x18f2c8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], ctx->vu0_vf[10]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x18f2cc: 0x4b094b2a  vmul.x      $vf12, $vf9, $vf9
    ctx->pc = 0x18f2ccu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[9], ctx->vu0_vf[9]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x18f2d0: 0x4b0a636a  vmul.x      $vf13, $vf12, $vf10
    ctx->pc = 0x18f2d0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[12], ctx->vu0_vf[10]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[13] = PS2_VBLEND(ctx->vu0_vf[13], res, _mm_castsi128_ps(mask)); }
    // 0x18f2d4: 0x4b0963aa  vmul.x      $vf14, $vf12, $vf9
    ctx->pc = 0x18f2d4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[12], ctx->vu0_vf[9]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[14] = PS2_VBLEND(ctx->vu0_vf[14], res, _mm_castsi128_ps(mask)); }
    // 0x18f2d8: 0x4b0b73aa  vmul.x      $vf14, $vf14, $vf11
    ctx->pc = 0x18f2d8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[14], ctx->vu0_vf[11]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[14] = PS2_VBLEND(ctx->vu0_vf[14], res, _mm_castsi128_ps(mask)); }
    // 0x18f2dc: 0x4b000043  vaddw.x     $vf1, $vf0, $vf0w
    ctx->pc = 0x18f2dcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[1] = _mm_blendv_ps(ctx->vu0_vf[1], res, _mm_castsi128_ps(mask)); }
    // 0x18f2e0: 0x4b010868  vadd.x      $vf1, $vf1, $vf1
    ctx->pc = 0x18f2e0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[1], ctx->vu0_vf[1]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[1] = PS2_VBLEND(ctx->vu0_vf[1], res, _mm_castsi128_ps(mask)); }
    // 0x18f2e4: 0x4b0e0bea  vmul.x      $vf15, $vf1, $vf14
    ctx->pc = 0x18f2e4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[1], ctx->vu0_vf[14]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[15] = PS2_VBLEND(ctx->vu0_vf[15], res, _mm_castsi128_ps(mask)); }
    // 0x18f2e8: 0x4b0a7bea  vmul.x      $vf15, $vf15, $vf10
    ctx->pc = 0x18f2e8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[15], ctx->vu0_vf[10]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[15] = PS2_VBLEND(ctx->vu0_vf[15], res, _mm_castsi128_ps(mask)); }
    // 0x18f2ec: 0x4b000843  vaddw.x     $vf1, $vf1, $vf0w
    ctx->pc = 0x18f2ecu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[1], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[1] = _mm_blendv_ps(ctx->vu0_vf[1], res, _mm_castsi128_ps(mask)); }
    // 0x18f2f0: 0x4b0c0c2a  vmul.x      $vf16, $vf1, $vf12
    ctx->pc = 0x18f2f0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[1], ctx->vu0_vf[12]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[16] = PS2_VBLEND(ctx->vu0_vf[16], res, _mm_castsi128_ps(mask)); }
    // 0x18f2f4: 0x4b0b842a  vmul.x      $vf16, $vf16, $vf11
    ctx->pc = 0x18f2f4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[16], ctx->vu0_vf[11]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[16] = PS2_VBLEND(ctx->vu0_vf[16], res, _mm_castsi128_ps(mask)); }
    // 0x18f2f8: 0x4b107c6c  vsub.x      $vf17, $vf15, $vf16
    ctx->pc = 0x18f2f8u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[15], ctx->vu0_vf[16]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[17] = PS2_VBLEND(ctx->vu0_vf[17], res, _mm_castsi128_ps(mask)); }
    // 0x18f2fc: 0x4b008c43  vaddw.x     $vf17, $vf17, $vf0w
    ctx->pc = 0x18f2fcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[17], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[17] = _mm_blendv_ps(ctx->vu0_vf[17], res, _mm_castsi128_ps(mask)); }
    // 0x18f300: 0x4b11346a  vmul.x      $vf17, $vf6, $vf17
    ctx->pc = 0x18f300u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], ctx->vu0_vf[17]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[17] = PS2_VBLEND(ctx->vu0_vf[17], res, _mm_castsi128_ps(mask)); }
    // 0x18f304: 0x4b0f84ac  vsub.x      $vf18, $vf16, $vf15
    ctx->pc = 0x18f304u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[16], ctx->vu0_vf[15]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f308: 0x4b123caa  vmul.x      $vf18, $vf7, $vf18
    ctx->pc = 0x18f308u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], ctx->vu0_vf[18]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f30c: 0x4b128c68  vadd.x      $vf17, $vf17, $vf18
    ctx->pc = 0x18f30cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[17], ctx->vu0_vf[18]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[17] = PS2_VBLEND(ctx->vu0_vf[17], res, _mm_castsi128_ps(mask)); }
    // 0x18f310: 0x4b0d74ac  vsub.x      $vf18, $vf14, $vf13
    ctx->pc = 0x18f310u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[14], ctx->vu0_vf[13]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f314: 0x4b0d94ac  vsub.x      $vf18, $vf18, $vf13
    ctx->pc = 0x18f314u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[18], ctx->vu0_vf[13]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f318: 0x4b0994a8  vadd.x      $vf18, $vf18, $vf9
    ctx->pc = 0x18f318u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[18], ctx->vu0_vf[9]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f31c: 0x4b1244aa  vmul.x      $vf18, $vf8, $vf18
    ctx->pc = 0x18f31cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[8], ctx->vu0_vf[18]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f320: 0x4b128c68  vadd.x      $vf17, $vf17, $vf18
    ctx->pc = 0x18f320u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[17], ctx->vu0_vf[18]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[17] = PS2_VBLEND(ctx->vu0_vf[17], res, _mm_castsi128_ps(mask)); }
    // 0x18f324: 0x4b0d74ac  vsub.x      $vf18, $vf14, $vf13
    ctx->pc = 0x18f324u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[14], ctx->vu0_vf[13]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f328: 0x4b1214aa  vmul.x      $vf18, $vf2, $vf18
    ctx->pc = 0x18f328u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[2], ctx->vu0_vf[18]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[18] = PS2_VBLEND(ctx->vu0_vf[18], res, _mm_castsi128_ps(mask)); }
    // 0x18f32c: 0x4b128c68  vadd.x      $vf17, $vf17, $vf18
    ctx->pc = 0x18f32cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[17], ctx->vu0_vf[18]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[17] = PS2_VBLEND(ctx->vu0_vf[17], res, _mm_castsi128_ps(mask)); }
    // 0x18f330: 0x48288800  qmfc2.ni    $t0, $vf17
    ctx->pc = 0x18f330u;
    SET_GPR_VEC(ctx, 8, _mm_castps_si128(ctx->vu0_vf[17]));
    // 0x18f334: 0x44880000  mtc1        $t0, $f0
    ctx->pc = 0x18f334u;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f338: 0x3e00008  jr          $ra
    ctx->pc = 0x18F338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F368u: goto label_18f368;
            case 0x18F3B0u: goto label_18f3b0;
            case 0x18F3E8u: goto label_18f3e8;
            case 0x18F3F0u: goto label_18f3f0;
            case 0x18F450u: goto label_18f450;
            case 0x18F454u: goto label_18f454;
            case 0x18F498u: goto label_18f498;
            case 0x18F4E0u: goto label_18f4e0;
            case 0x18F514u: goto label_18f514;
            case 0x18F518u: goto label_18f518;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F340u;
    // 0x18f340: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x18f340u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x18f344: 0xc4201c90  lwc1        $f0, 0x1C90($at)
    ctx->pc = 0x18f344u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7312)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18f348: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18f348u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f34c: 0x45010006  bc1t        . + 4 + (0x6 << 2)
    ctx->pc = 0x18F34Cu;
    {
        const bool branch_taken_0x18f34c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x18F350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F34Cu;
            // 0x18f350: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f34c) {
            ctx->pc = 0x18F368u;
            goto label_18f368;
        }
    }
    ctx->pc = 0x18F354u;
    // 0x18f354: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x18f354u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x18f358: 0xc4201c88  lwc1        $f0, 0x1C88($at)
    ctx->pc = 0x18f358u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7304)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18f35c: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f35cu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f360: 0x45010013  bc1t        . + 4 + (0x13 << 2)
    ctx->pc = 0x18F360u;
    {
        const bool branch_taken_0x18f360 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18f360) {
            ctx->pc = 0x18F3B0u;
            goto label_18f3b0;
        }
    }
    ctx->pc = 0x18F368u;
label_18f368:
    // 0x18f368: 0x2442fe20  addiu       $v0, $v0, -0x1E0
    ctx->pc = 0x18f368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966816));
    // 0x18f36c: 0x44086000  mfc1        $t0, $f12
    ctx->pc = 0x18f36cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f370: 0xd8460000  lqc2        $vf6, 0x0($v0)
    ctx->pc = 0x18f370u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18f374: 0x48a82000  qmtc2.ni    $t0, $vf4
    ctx->pc = 0x18f374u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f378: 0x8402a  slt         $t0, $zero, $t0
    ctx->pc = 0x18f378u;
    SET_GPR_U64(ctx, 8, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x18f37c: 0x48c81000  ctc2.ni     $t0, $vi2
    ctx->pc = 0x18f37cu;
    ctx->vu0_vpu_stat = GPR_U32(ctx, 8);
    // 0x18f380: 0x4b0621d8  vmulx.x     $vf7, $vf4, $vf6x
    ctx->pc = 0x18f380u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f384: 0x4b07397c  vftoi0.x    $vf7, $vf7
    ctx->pc = 0x18f384u;
    { __m128 src = ctx->vu0_vf[7]; src = _mm_mul_ps(src, _mm_set1_ps(1.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f388: 0x4a013bfc  vmtir       $vi1, $vf7x
    ctx->pc = 0x18f388u;
    { uint32_t bits; float src = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(0,0,0,0))); std::memcpy(&bits, &src, sizeof(bits)); ctx->vi[1] = (uint16_t)(bits & 0xFFFF); }
    // 0x18f38c: 0x4a0307b2  viaddi      $vi3, $vi0, -0x2
    ctx->pc = 0x18f38cu;
    ctx->vi[3] = ctx->vi[0] + -2;
    // 0x18f390: 0x4a020870  viadd       $vi1, $vi1, $vi2
    ctx->pc = 0x18f390u;
    ctx->vi[1] = ctx->vi[1] + ctx->vi[2];
    // 0x18f394: 0x4a030874  viand       $vi1, $vi1, $vi3
    ctx->pc = 0x18f394u;
    ctx->vi[1] = ctx->vi[1] & ctx->vi[3];
    // 0x18f398: 0x4b070bfd  vmfir.x     $vf7, $vi1
    ctx->pc = 0x18f398u;
    { uint32_t tmp = (uint32_t)(int32_t)(int16_t)ctx->vi[1]; float val; std::memcpy(&val, &tmp, sizeof(val)); __m128 res = _mm_set1_ps(val); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f39c: 0x4b07393c  vitof0.x    $vf7, $vf7
    ctx->pc = 0x18f39cu;
    { __m128i src = _mm_castps_si128(ctx->vu0_vf[7]); __m128 res = _mm_cvtepi32_ps(src); res = _mm_mul_ps(res, _mm_set1_ps(1.0f)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f3a0: 0x4b0639d9  vmuly.x     $vf7, $vf7, $vf6y
    ctx->pc = 0x18f3a0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f3a4: 0x4b0721ec  vsub.x      $vf7, $vf4, $vf7
    ctx->pc = 0x18f3a4u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[4], ctx->vu0_vf[7]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = PS2_VBLEND(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f3a8: 0x48283800  qmfc2.ni    $t0, $vf7
    ctx->pc = 0x18f3a8u;
    SET_GPR_VEC(ctx, 8, _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x18f3ac: 0x44886000  mtc1        $t0, $f12
    ctx->pc = 0x18f3acu;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
label_18f3b0:
    // 0x18f3b0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x18f3b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x18f3b4: 0x2463fe30  addiu       $v1, $v1, -0x1D0
    ctx->pc = 0x18f3b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966832));
    // 0x18f3b8: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x18f3b8u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f3bc: 0x0  nop
    ctx->pc = 0x18f3bcu;
    // NOP
    // 0x18f3c0: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f3c0u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f3c4: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x18f3c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x18f3c8: 0x34220fdb  ori         $v0, $at, 0xFDB
    ctx->pc = 0x18f3c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4059);
    // 0x18f3cc: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18F3CCu;
    {
        const bool branch_taken_0x18f3cc = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18F3D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F3CCu;
            // 0x18f3d0: 0x44820000  mtc1        $v0, $f0 (Delay Slot)
        { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f3cc) {
            ctx->pc = 0x18F3E8u;
            goto label_18f3e8;
        }
    }
    ctx->pc = 0x18F3D4u;
    // 0x18f3d4: 0x4a0002ff  vnop
    ctx->pc = 0x18f3d4u;
    // NOP operation, no action needed for VU0
    // 0x18f3d8: 0x460c0300  add.s       $f12, $f0, $f12
    ctx->pc = 0x18f3d8u;
    ctx->f[12] = FPU_ADD_S(ctx->f[0], ctx->f[12]);
    // 0x18f3dc: 0x8063cfc  j           func_18F3F0
    ctx->pc = 0x18F3DCu;
    ctx->pc = 0x18F3E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F3DCu;
            // 0x18f3e0: 0x20070001  addi        $a3, $zero, 0x1 (Delay Slot)
        { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 0), (int32_t)1, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F3F0u;
    goto label_18f3f0;
    ctx->pc = 0x18F3E4u;
    // 0x18f3e4: 0x4a0002ff  vnop
    ctx->pc = 0x18f3e4u;
    // NOP operation, no action needed for VU0
label_18f3e8:
    // 0x18f3e8: 0x460c0301  sub.s       $f12, $f0, $f12
    ctx->pc = 0x18f3e8u;
    ctx->f[12] = FPU_SUB_S(ctx->f[0], ctx->f[12]);
    // 0x18f3ec: 0x3821  addu        $a3, $zero, $zero
    ctx->pc = 0x18f3ecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_18f3f0:
    // 0x18f3f0: 0x44086000  mfc1        $t0, $f12
    ctx->pc = 0x18f3f0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f3f4: 0x0  nop
    ctx->pc = 0x18f3f4u;
    // NOP
    // 0x18f3f8: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x18f3f8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f3fc: 0x4b0631d8  vmulx.x     $vf7, $vf6, $vf6x
    ctx->pc = 0x18f3fcu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f400: 0xd8650000  lqc2        $vf5, 0x0($v1)
    ctx->pc = 0x18f400u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18f404: 0x4be62958  vmulx.xyzw  $vf5, $vf5, $vf6x
    ctx->pc = 0x18f404u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18f408: 0x4b0031bf  vmulaw.x    $ACC, $vf6, $vf0w
    ctx->pc = 0x18f408u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f40c: 0x4b073a18  vmulx.x     $vf8, $vf7, $vf7x
    ctx->pc = 0x18f40cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x18f410: 0x4a6001ac  vsub.zw     $vf6, $vf0, $vf0
    ctx->pc = 0x18f410u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, -1, 0, 0); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18f414: 0x4b083a58  vmulx.x     $vf9, $vf7, $vf8x
    ctx->pc = 0x18f414u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x18f418: 0x4b084298  vmulx.x     $vf10, $vf8, $vf8x
    ctx->pc = 0x18f418u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x18f41c: 0x4b0538bf  vmaddaw.x   $ACC, $vf7, $vf5w
    ctx->pc = 0x18f41cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f420: 0x4b0540be  vmaddaz.x   $ACC, $vf8, $vf5z
    ctx->pc = 0x18f420u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f424: 0x4b0548bd  vmadday.x   $ACC, $vf9, $vf5y
    ctx->pc = 0x18f424u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f428: 0x4b055188  vmaddx.x    $vf6, $vf10, $vf5x
    ctx->pc = 0x18f428u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18f42c: 0x4b0631ea  vmul.x      $vf7, $vf6, $vf6
    ctx->pc = 0x18f42cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = PS2_VBLEND(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f430: 0x4a2701c4  vsubx.w     $vf7, $vf0, $vf7x
    ctx->pc = 0x18f430u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f434: 0x4b8703bd  .word       0x4B8703BD                   # vsqrt       $Q, $vf7w # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>
    ctx->pc = 0x18f434u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(0,0,0,3))); ctx->vu0_q = sqrtf(std::max(0.0f, ft)); }
    // 0x18f438: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x18F438u;
    {
        const bool branch_taken_0x18f438 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x18F43Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F438u;
            // 0x18f43c: 0x4a0003bf  vwaitq (Delay Slot)
        // VWAITQ (Q already resolved in this runtime)
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f438) {
            ctx->pc = 0x18F450u;
            goto label_18f450;
        }
    }
    ctx->pc = 0x18F440u;
    // 0x18f440: 0x4a0002ff  vnop
    ctx->pc = 0x18f440u;
    // NOP operation, no action needed for VU0
    // 0x18f444: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18F444u;
    {
        const bool branch_taken_0x18f444 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F444u;
            // 0x18f448: 0x4b0001a0  vaddq.x     $vf6, $vf0, $Q (Delay Slot)
        { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f444) {
            ctx->pc = 0x18F454u;
            goto label_18f454;
        }
    }
    ctx->pc = 0x18F44Cu;
    // 0x18f44c: 0x4a0002ff  vnop
    ctx->pc = 0x18f44cu;
    // NOP operation, no action needed for VU0
label_18f450:
    // 0x18f450: 0x4b0001a4  vsubq.x     $vf6, $vf0, $Q
    ctx->pc = 0x18f450u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
label_18f454:
    // 0x18f454: 0x48283000  qmfc2.ni    $t0, $vf6
    ctx->pc = 0x18f454u;
    SET_GPR_VEC(ctx, 8, _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x18f458: 0x44880000  mtc1        $t0, $f0
    ctx->pc = 0x18f458u;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f45c: 0x3e00008  jr          $ra
    ctx->pc = 0x18F45Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F368u: goto label_18f368;
            case 0x18F3B0u: goto label_18f3b0;
            case 0x18F3E8u: goto label_18f3e8;
            case 0x18F3F0u: goto label_18f3f0;
            case 0x18F450u: goto label_18f450;
            case 0x18F454u: goto label_18f454;
            case 0x18F498u: goto label_18f498;
            case 0x18F4E0u: goto label_18f4e0;
            case 0x18F514u: goto label_18f514;
            case 0x18F518u: goto label_18f518;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F464u;
    // 0x18f464: 0x0  nop
    ctx->pc = 0x18f464u;
    // NOP
    // 0x18f468: 0x0  nop
    ctx->pc = 0x18f468u;
    // NOP
    // 0x18f46c: 0x0  nop
    ctx->pc = 0x18f46cu;
    // NOP
    // 0x18f470: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x18f470u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x18f474: 0xc4201c90  lwc1        $f0, 0x1C90($at)
    ctx->pc = 0x18f474u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7312)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18f478: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18f478u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f47c: 0x45010006  bc1t        . + 4 + (0x6 << 2)
    ctx->pc = 0x18F47Cu;
    {
        const bool branch_taken_0x18f47c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x18F480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F47Cu;
            // 0x18f480: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f47c) {
            ctx->pc = 0x18F498u;
            goto label_18f498;
        }
    }
    ctx->pc = 0x18F484u;
    // 0x18f484: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x18f484u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x18f488: 0xc4201c88  lwc1        $f0, 0x1C88($at)
    ctx->pc = 0x18f488u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7304)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18f48c: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f48cu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f490: 0x45010013  bc1t        . + 4 + (0x13 << 2)
    ctx->pc = 0x18F490u;
    {
        const bool branch_taken_0x18f490 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18f490) {
            ctx->pc = 0x18F4E0u;
            goto label_18f4e0;
        }
    }
    ctx->pc = 0x18F498u;
label_18f498:
    // 0x18f498: 0x2442fe20  addiu       $v0, $v0, -0x1E0
    ctx->pc = 0x18f498u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966816));
    // 0x18f49c: 0x44086000  mfc1        $t0, $f12
    ctx->pc = 0x18f49cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f4a0: 0xd8460000  lqc2        $vf6, 0x0($v0)
    ctx->pc = 0x18f4a0u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18f4a4: 0x48a82000  qmtc2.ni    $t0, $vf4
    ctx->pc = 0x18f4a4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f4a8: 0x8402a  slt         $t0, $zero, $t0
    ctx->pc = 0x18f4a8u;
    SET_GPR_U64(ctx, 8, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x18f4ac: 0x48c81000  ctc2.ni     $t0, $vi2
    ctx->pc = 0x18f4acu;
    ctx->vu0_vpu_stat = GPR_U32(ctx, 8);
    // 0x18f4b0: 0x4b0621d8  vmulx.x     $vf7, $vf4, $vf6x
    ctx->pc = 0x18f4b0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f4b4: 0x4b07397c  vftoi0.x    $vf7, $vf7
    ctx->pc = 0x18f4b4u;
    { __m128 src = ctx->vu0_vf[7]; src = _mm_mul_ps(src, _mm_set1_ps(1.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f4b8: 0x4a013bfc  vmtir       $vi1, $vf7x
    ctx->pc = 0x18f4b8u;
    { uint32_t bits; float src = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(0,0,0,0))); std::memcpy(&bits, &src, sizeof(bits)); ctx->vi[1] = (uint16_t)(bits & 0xFFFF); }
    // 0x18f4bc: 0x4a0307b2  viaddi      $vi3, $vi0, -0x2
    ctx->pc = 0x18f4bcu;
    ctx->vi[3] = ctx->vi[0] + -2;
    // 0x18f4c0: 0x4a020870  viadd       $vi1, $vi1, $vi2
    ctx->pc = 0x18f4c0u;
    ctx->vi[1] = ctx->vi[1] + ctx->vi[2];
    // 0x18f4c4: 0x4a030874  viand       $vi1, $vi1, $vi3
    ctx->pc = 0x18f4c4u;
    ctx->vi[1] = ctx->vi[1] & ctx->vi[3];
    // 0x18f4c8: 0x4b070bfd  vmfir.x     $vf7, $vi1
    ctx->pc = 0x18f4c8u;
    { uint32_t tmp = (uint32_t)(int32_t)(int16_t)ctx->vi[1]; float val; std::memcpy(&val, &tmp, sizeof(val)); __m128 res = _mm_set1_ps(val); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f4cc: 0x4b07393c  vitof0.x    $vf7, $vf7
    ctx->pc = 0x18f4ccu;
    { __m128i src = _mm_castps_si128(ctx->vu0_vf[7]); __m128 res = _mm_cvtepi32_ps(src); res = _mm_mul_ps(res, _mm_set1_ps(1.0f)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f4d0: 0x4b0639d9  vmuly.x     $vf7, $vf7, $vf6y
    ctx->pc = 0x18f4d0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f4d4: 0x4b0721ec  vsub.x      $vf7, $vf4, $vf7
    ctx->pc = 0x18f4d4u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[4], ctx->vu0_vf[7]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = PS2_VBLEND(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f4d8: 0x48283800  qmfc2.ni    $t0, $vf7
    ctx->pc = 0x18f4d8u;
    SET_GPR_VEC(ctx, 8, _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x18f4dc: 0x44886000  mtc1        $t0, $f12
    ctx->pc = 0x18f4dcu;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
label_18f4e0:
    // 0x18f4e0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x18f4e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x18f4e4: 0x2463fe30  addiu       $v1, $v1, -0x1D0
    ctx->pc = 0x18f4e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966832));
    // 0x18f4e8: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x18f4e8u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f4ec: 0x0  nop
    ctx->pc = 0x18f4ecu;
    // NOP
    // 0x18f4f0: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f4f0u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f4f4: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x18f4f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x18f4f8: 0x34220fdb  ori         $v0, $at, 0xFDB
    ctx->pc = 0x18f4f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4059);
    // 0x18f4fc: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x18F4FCu;
    {
        const bool branch_taken_0x18f4fc = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18F500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F4FCu;
            // 0x18f500: 0x44820000  mtc1        $v0, $f0 (Delay Slot)
        { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f4fc) {
            ctx->pc = 0x18F514u;
            goto label_18f514;
        }
    }
    ctx->pc = 0x18F504u;
    // 0x18f504: 0x4a0002ff  vnop
    ctx->pc = 0x18f504u;
    // NOP operation, no action needed for VU0
    // 0x18f508: 0x8063d46  j           func_18F518
    ctx->pc = 0x18F508u;
    ctx->pc = 0x18F50Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F508u;
            // 0x18f50c: 0x460c0300  add.s       $f12, $f0, $f12 (Delay Slot)
        ctx->f[12] = FPU_ADD_S(ctx->f[0], ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F518u;
    goto label_18f518;
    ctx->pc = 0x18F510u;
    // 0x18f510: 0x4a0002ff  vnop
    ctx->pc = 0x18f510u;
    // NOP operation, no action needed for VU0
label_18f514:
    // 0x18f514: 0x460c0301  sub.s       $f12, $f0, $f12
    ctx->pc = 0x18f514u;
    ctx->f[12] = FPU_SUB_S(ctx->f[0], ctx->f[12]);
label_18f518:
    // 0x18f518: 0x44086000  mfc1        $t0, $f12
    ctx->pc = 0x18f518u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x18f51c: 0x0  nop
    ctx->pc = 0x18f51cu;
    // NOP
    // 0x18f520: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x18f520u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x18f524: 0x4b0631d8  vmulx.x     $vf7, $vf6, $vf6x
    ctx->pc = 0x18f524u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x18f528: 0xd8650000  lqc2        $vf5, 0x0($v1)
    ctx->pc = 0x18f528u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18f52c: 0x4be62958  vmulx.xyzw  $vf5, $vf5, $vf6x
    ctx->pc = 0x18f52cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18f530: 0x4b0031bf  vmulaw.x    $ACC, $vf6, $vf0w
    ctx->pc = 0x18f530u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f534: 0x4b073a18  vmulx.x     $vf8, $vf7, $vf7x
    ctx->pc = 0x18f534u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x18f538: 0x4ae001ac  vsub.yzw    $vf6, $vf0, $vf0
    ctx->pc = 0x18f538u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, -1, -1, 0); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18f53c: 0x4b083a58  vmulx.x     $vf9, $vf7, $vf8x
    ctx->pc = 0x18f53cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x18f540: 0x4b084298  vmulx.x     $vf10, $vf8, $vf8x
    ctx->pc = 0x18f540u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x18f544: 0x4b0538bf  vmaddaw.x   $ACC, $vf7, $vf5w
    ctx->pc = 0x18f544u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f548: 0x4b0540be  vmaddaz.x   $ACC, $vf8, $vf5z
    ctx->pc = 0x18f548u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f54c: 0x4b0548bd  vmadday.x   $ACC, $vf9, $vf5y
    ctx->pc = 0x18f54cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x18f550: 0x4b055188  vmaddx.x    $vf6, $vf10, $vf5x
    ctx->pc = 0x18f550u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x18f554: 0x4a0002ff  vnop
    ctx->pc = 0x18f554u;
    // NOP operation, no action needed for VU0
    // 0x18f558: 0x48293000  qmfc2.ni    $t1, $vf6
    ctx->pc = 0x18f558u;
    SET_GPR_VEC(ctx, 9, _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x18f55c: 0x44890000  mtc1        $t1, $f0
    ctx->pc = 0x18f55cu;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f560: 0x3e00008  jr          $ra
    ctx->pc = 0x18F560u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F368u: goto label_18f368;
            case 0x18F3B0u: goto label_18f3b0;
            case 0x18F3E8u: goto label_18f3e8;
            case 0x18F3F0u: goto label_18f3f0;
            case 0x18F450u: goto label_18f450;
            case 0x18F454u: goto label_18f454;
            case 0x18F498u: goto label_18f498;
            case 0x18F4E0u: goto label_18f4e0;
            case 0x18F514u: goto label_18f514;
            case 0x18F518u: goto label_18f518;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F568u;
    // 0x18f568: 0x0  nop
    ctx->pc = 0x18f568u;
    // NOP
    // 0x18f56c: 0x0  nop
    ctx->pc = 0x18f56cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

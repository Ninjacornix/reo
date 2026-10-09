#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F470
// Address: 0x18f470 - 0x18f568
void sub_0018F470_0x18f470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F470_0x18f470");
#endif

    ctx->pc = 0x18f470u;

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
            case 0x18F498u: goto label_18f498;
            case 0x18F4E0u: goto label_18f4e0;
            case 0x18F514u: goto label_18f514;
            case 0x18F518u: goto label_18f518;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F568u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

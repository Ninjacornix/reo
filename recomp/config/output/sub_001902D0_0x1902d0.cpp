#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001902D0
// Address: 0x1902d0 - 0x190494
void sub_001902D0_0x1902d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001902D0_0x1902d0");
#endif

    switch (ctx->pc) {
        case 0x1902fcu: goto label_1902fc;
        case 0x190308u: goto label_190308;
        case 0x190388u: goto label_190388;
        case 0x190408u: goto label_190408;
        default: break;
    }

    ctx->pc = 0x1902d0u;

    // 0x1902d0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1902d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1902d4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1902d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1902d8: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1902d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1902dc: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x1902dcu;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x1902e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1902e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1902e4: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x1902e4u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x1902e8: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1902e8u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1902ec: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x1902ecu;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x1902f0: 0x46006d46  mov.s       $f21, $f13
    ctx->pc = 0x1902f0u;
    ctx->f[21] = FPU_MOV_S(ctx->f[13]);
    // 0x1902f4: 0xc063f88  jal         func_18FE20
    ctx->pc = 0x1902F4u;
    SET_GPR_U32(ctx, 31, 0x1902FCu);
    ctx->pc = 0x1902F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1902F4u;
            // 0x1902f8: 0x46007506  mov.s       $f20, $f14 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[14]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FE20u;
    if (runtime->hasFunction(0x18FE20u)) {
        auto targetFn = runtime->lookupFunction(0x18FE20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1902FCu; }
        if (ctx->pc != 0x1902FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FE20_0x18fe20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1902FCu; }
        if (ctx->pc != 0x1902FCu) { return; }
    }
    ctx->pc = 0x1902FCu;
label_1902fc:
    // 0x1902fc: 0x4600b306  mov.s       $f12, $f22
    ctx->pc = 0x1902fcu;
    ctx->f[12] = FPU_MOV_S(ctx->f[22]);
    // 0x190300: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190300u;
    SET_GPR_U32(ctx, 31, 0x190308u);
    ctx->pc = 0x190304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190300u;
            // 0x190304: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190308u; }
        if (ctx->pc != 0x190308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190308u; }
        if (ctx->pc != 0x190308u) { return; }
    }
    ctx->pc = 0x190308u;
label_190308:
    // 0x190308: 0xc7a10050  lwc1        $f1, 0x50($sp)
    ctx->pc = 0x190308u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 80)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19030c: 0xc7a00054  lwc1        $f0, 0x54($sp)
    ctx->pc = 0x19030cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 84)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190310: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190310u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190314: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190314u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190318: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x190318u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19031c: 0xda050010  lqc2        $vf5, 0x10($s0)
    ctx->pc = 0x19031cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x190320: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190320u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190324: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190324u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190328: 0x4ac002a8  vadd.yz     $vf10, $vf0, $vf0
    ctx->pc = 0x190328u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x19032c: 0x4b000283  vaddw.x     $vf10, $vf0, $vf0w
    ctx->pc = 0x19032cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190330: 0x4b0002e8  vadd.x      $vf11, $vf0, $vf0
    ctx->pc = 0x190330u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190334: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190334u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190338: 0x4a5402c0  vaddx.z     $vf11, $vf0, $vf20x
    ctx->pc = 0x190338u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x19033c: 0x4b000328  vadd.x      $vf12, $vf0, $vf0
    ctx->pc = 0x19033cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190340: 0x4a940304  vsubx.y     $vf12, $vf0, $vf20x
    ctx->pc = 0x190340u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190344: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190344u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190348: 0xda060020  lqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190348u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x19034c: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x19034cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190350: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190350u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190354: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190354u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190358: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190358u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19035c: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x19035cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190360: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190360u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190364: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190364u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190368: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190368u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19036c: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x19036cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190370: 0xfa040000  sqc2        $vf4, 0x0($s0)
    ctx->pc = 0x190370u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190374: 0xfa050010  sqc2        $vf5, 0x10($s0)
    ctx->pc = 0x190374u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190378: 0xfa060020  sqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190378u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x19037c: 0x4600ab06  mov.s       $f12, $f21
    ctx->pc = 0x19037cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[21]);
    // 0x190380: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190380u;
    SET_GPR_U32(ctx, 31, 0x190388u);
    ctx->pc = 0x190384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190380u;
            // 0x190384: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190388u; }
        if (ctx->pc != 0x190388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190388u; }
        if (ctx->pc != 0x190388u) { return; }
    }
    ctx->pc = 0x190388u;
label_190388:
    // 0x190388: 0xc7a10040  lwc1        $f1, 0x40($sp)
    ctx->pc = 0x190388u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19038c: 0xc7a00044  lwc1        $f0, 0x44($sp)
    ctx->pc = 0x19038cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 68)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190390: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190390u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190394: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190394u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190398: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x190398u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19039c: 0xda050010  lqc2        $vf5, 0x10($s0)
    ctx->pc = 0x19039cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1903a0: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x1903a0u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x1903a4: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x1903a4u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x1903a8: 0x4b4002e8  vadd.xz     $vf11, $vf0, $vf0
    ctx->pc = 0x1903a8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x1903ac: 0x4a8002c3  vaddw.y     $vf11, $vf0, $vf0w
    ctx->pc = 0x1903acu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x1903b0: 0x4a8002a8  vadd.y      $vf10, $vf0, $vf0
    ctx->pc = 0x1903b0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1903b4: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x1903b4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1903b8: 0x4a540284  vsubx.z     $vf10, $vf0, $vf20x
    ctx->pc = 0x1903b8u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1903bc: 0x4a800328  vadd.y      $vf12, $vf0, $vf0
    ctx->pc = 0x1903bcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x1903c0: 0x4b140300  vaddx.x     $vf12, $vf0, $vf20x
    ctx->pc = 0x1903c0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x1903c4: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x1903c4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x1903c8: 0xda060020  lqc2        $vf6, 0x20($s0)
    ctx->pc = 0x1903c8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1903cc: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x1903ccu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1903d0: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x1903d0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1903d4: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x1903d4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1903d8: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x1903d8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1903dc: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x1903dcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1903e0: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x1903e0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1903e4: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x1903e4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1903e8: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x1903e8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1903ec: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x1903ecu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1903f0: 0xfa040000  sqc2        $vf4, 0x0($s0)
    ctx->pc = 0x1903f0u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x1903f4: 0xfa050010  sqc2        $vf5, 0x10($s0)
    ctx->pc = 0x1903f4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x1903f8: 0xfa060020  sqc2        $vf6, 0x20($s0)
    ctx->pc = 0x1903f8u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x1903fc: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x1903fcu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x190400: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190400u;
    SET_GPR_U32(ctx, 31, 0x190408u);
    ctx->pc = 0x190404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190400u;
            // 0x190404: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190408u; }
        if (ctx->pc != 0x190408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190408u; }
        if (ctx->pc != 0x190408u) { return; }
    }
    ctx->pc = 0x190408u;
label_190408:
    // 0x190408: 0xc7a10030  lwc1        $f1, 0x30($sp)
    ctx->pc = 0x190408u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19040c: 0xc7a00034  lwc1        $f0, 0x34($sp)
    ctx->pc = 0x19040cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190410: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190410u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190414: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190414u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190418: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x190418u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19041c: 0xda050010  lqc2        $vf5, 0x10($s0)
    ctx->pc = 0x19041cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x190420: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190420u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190424: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190424u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190428: 0x4a4002a8  vadd.z      $vf10, $vf0, $vf0
    ctx->pc = 0x190428u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x19042c: 0x4a940280  vaddx.y     $vf10, $vf0, $vf20x
    ctx->pc = 0x19042cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190430: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190430u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190434: 0x4a4002e8  vadd.z      $vf11, $vf0, $vf0
    ctx->pc = 0x190434u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190438: 0x4b1402c4  vsubx.x     $vf11, $vf0, $vf20x
    ctx->pc = 0x190438u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x19043c: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x19043cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190440: 0x4bcc033d  vmr32.xyz   $vf12, $vf0
    ctx->pc = 0x190440u;
    { __m128 res = _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,3,2,1)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190444: 0xda060020  lqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190444u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x190448: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190448u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19044c: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x19044cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190450: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190450u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190454: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190454u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190458: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190458u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19045c: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x19045cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190460: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190460u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190464: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190464u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190468: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190468u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x19046c: 0xfa040000  sqc2        $vf4, 0x0($s0)
    ctx->pc = 0x19046cu;
    WRITE128(ADD32(GPR_U32(ctx, 16), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190470: 0xfa050010  sqc2        $vf5, 0x10($s0)
    ctx->pc = 0x190470u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190474: 0xfa060020  sqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190474u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190478: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x190478u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19047c: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x19047cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x190480: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x190480u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x190484: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x190484u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x190488: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x190488u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x19048c: 0x3e00008  jr          $ra
    ctx->pc = 0x19048Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19048Cu;
            // 0x190490: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1902FCu: goto label_1902fc;
            case 0x190308u: goto label_190308;
            case 0x190388u: goto label_190388;
            case 0x190408u: goto label_190408;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190494u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

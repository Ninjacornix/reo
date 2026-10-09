#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00190A10
// Address: 0x190a10 - 0x1911d0
void sub_00190A10_0x190a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00190A10_0x190a10");
#endif

    switch (ctx->pc) {
        case 0x190a24u: goto label_190a24;
        case 0x190aa4u: goto label_190aa4;
        case 0x190b24u: goto label_190b24;
        case 0x190bb4u: goto label_190bb4;
        case 0x190c34u: goto label_190c34;
        case 0x190cb0u: goto label_190cb0;
        case 0x190d4cu: goto label_190d4c;
        case 0x190dc8u: goto label_190dc8;
        case 0x190e48u: goto label_190e48;
        case 0x190eecu: goto label_190eec;
        case 0x190f68u: goto label_190f68;
        case 0x190fe8u: goto label_190fe8;
        case 0x1910ecu: goto label_1910ec;
        case 0x1910f4u: goto label_1910f4;
        case 0x191104u: goto label_191104;
        case 0x19110cu: goto label_19110c;
        case 0x19111cu: goto label_19111c;
        case 0x191184u: goto label_191184;
        case 0x191198u: goto label_191198;
        case 0x1911acu: goto label_1911ac;
        default: break;
    }

    ctx->pc = 0x190a10u;

    // 0x190a10: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x190a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x190a14: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x190a14u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190a18: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x190a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x190a1c: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190A1Cu;
    SET_GPR_U32(ctx, 31, 0x190A24u);
    ctx->pc = 0x190A20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190A1Cu;
            // 0x190a20: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190A24u; }
        if (ctx->pc != 0x190A24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190A24u; }
        if (ctx->pc != 0x190A24u) { return; }
    }
    ctx->pc = 0x190A24u;
label_190a24:
    // 0x190a24: 0xc7a10030  lwc1        $f1, 0x30($sp)
    ctx->pc = 0x190a24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190a28: 0xc7a00034  lwc1        $f0, 0x34($sp)
    ctx->pc = 0x190a28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190a2c: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190a2cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190a30: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190a30u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190a34: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190a34u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190a38: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190a38u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190a3c: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190a3cu;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190a40: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190a40u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190a44: 0x4ac002a8  vadd.yz     $vf10, $vf0, $vf0
    ctx->pc = 0x190a44u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190a48: 0x4b000283  vaddw.x     $vf10, $vf0, $vf0w
    ctx->pc = 0x190a48u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190a4c: 0x4b0002e8  vadd.x      $vf11, $vf0, $vf0
    ctx->pc = 0x190a4cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190a50: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190a50u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190a54: 0x4a5402c0  vaddx.z     $vf11, $vf0, $vf20x
    ctx->pc = 0x190a54u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190a58: 0x4b000328  vadd.x      $vf12, $vf0, $vf0
    ctx->pc = 0x190a58u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190a5c: 0x4a940304  vsubx.y     $vf12, $vf0, $vf20x
    ctx->pc = 0x190a5cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190a60: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190a60u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190a64: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190a64u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190a68: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190a68u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190a6c: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190a6cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190a70: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190a70u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190a74: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190a74u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190a78: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190a78u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190a7c: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190a7cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190a80: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190a80u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190a84: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190a84u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190a88: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190a88u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190a8c: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190a8cu;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190a90: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190a90u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190a94: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190a94u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190a98: 0x46006b06  mov.s       $f12, $f13
    ctx->pc = 0x190a98u;
    ctx->f[12] = FPU_MOV_S(ctx->f[13]);
    // 0x190a9c: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190A9Cu;
    SET_GPR_U32(ctx, 31, 0x190AA4u);
    ctx->pc = 0x190AA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190A9Cu;
            // 0x190aa0: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190AA4u; }
        if (ctx->pc != 0x190AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190AA4u; }
        if (ctx->pc != 0x190AA4u) { return; }
    }
    ctx->pc = 0x190AA4u;
label_190aa4:
    // 0x190aa4: 0xc7a10020  lwc1        $f1, 0x20($sp)
    ctx->pc = 0x190aa4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190aa8: 0xc7a00024  lwc1        $f0, 0x24($sp)
    ctx->pc = 0x190aa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190aac: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190aacu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190ab0: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190ab0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190ab4: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190ab4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190ab8: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190ab8u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190abc: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190abcu;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190ac0: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190ac0u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190ac4: 0x4b4002e8  vadd.xz     $vf11, $vf0, $vf0
    ctx->pc = 0x190ac4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190ac8: 0x4a8002c3  vaddw.y     $vf11, $vf0, $vf0w
    ctx->pc = 0x190ac8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190acc: 0x4a8002a8  vadd.y      $vf10, $vf0, $vf0
    ctx->pc = 0x190accu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190ad0: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190ad0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190ad4: 0x4a540284  vsubx.z     $vf10, $vf0, $vf20x
    ctx->pc = 0x190ad4u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190ad8: 0x4a800328  vadd.y      $vf12, $vf0, $vf0
    ctx->pc = 0x190ad8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190adc: 0x4b140300  vaddx.x     $vf12, $vf0, $vf20x
    ctx->pc = 0x190adcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190ae0: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190ae0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190ae4: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190ae4u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190ae8: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190ae8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190aec: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190aecu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190af0: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190af0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190af4: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190af4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190af8: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190af8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190afc: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190afcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190b00: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190b00u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b04: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190b04u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b08: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190b08u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190b0c: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190b0cu;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190b10: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190b10u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190b14: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190b14u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190b18: 0x46007306  mov.s       $f12, $f14
    ctx->pc = 0x190b18u;
    ctx->f[12] = FPU_MOV_S(ctx->f[14]);
    // 0x190b1c: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190B1Cu;
    SET_GPR_U32(ctx, 31, 0x190B24u);
    ctx->pc = 0x190B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190B1Cu;
            // 0x190b20: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190B24u; }
        if (ctx->pc != 0x190B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190B24u; }
        if (ctx->pc != 0x190B24u) { return; }
    }
    ctx->pc = 0x190B24u;
label_190b24:
    // 0x190b24: 0xc7a10010  lwc1        $f1, 0x10($sp)
    ctx->pc = 0x190b24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190b28: 0xc7a00014  lwc1        $f0, 0x14($sp)
    ctx->pc = 0x190b28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190b2c: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190b2cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190b30: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190b30u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190b34: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190b34u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190b38: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190b38u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190b3c: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190b3cu;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190b40: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190b40u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190b44: 0x4a4002a8  vadd.z      $vf10, $vf0, $vf0
    ctx->pc = 0x190b44u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190b48: 0x4a940280  vaddx.y     $vf10, $vf0, $vf20x
    ctx->pc = 0x190b48u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190b4c: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190b4cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190b50: 0x4a4002e8  vadd.z      $vf11, $vf0, $vf0
    ctx->pc = 0x190b50u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190b54: 0x4b1402c4  vsubx.x     $vf11, $vf0, $vf20x
    ctx->pc = 0x190b54u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190b58: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190b58u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190b5c: 0x4bcc033d  vmr32.xyz   $vf12, $vf0
    ctx->pc = 0x190b5cu;
    { __m128 res = _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,3,2,1)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190b60: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190b60u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190b64: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190b64u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b68: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190b68u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b6c: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190b6cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190b70: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190b70u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b74: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190b74u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b78: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190b78u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190b7c: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190b7cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b80: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190b80u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190b84: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190b84u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190b88: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190b88u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190b8c: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190b8cu;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190b90: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190b90u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190b94: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x190b94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x190b98: 0x3e00008  jr          $ra
    ctx->pc = 0x190B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190B98u;
            // 0x190b9c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x190A24u: goto label_190a24;
            case 0x190AA4u: goto label_190aa4;
            case 0x190B24u: goto label_190b24;
            case 0x190BB4u: goto label_190bb4;
            case 0x190C34u: goto label_190c34;
            case 0x190CB0u: goto label_190cb0;
            case 0x190D4Cu: goto label_190d4c;
            case 0x190DC8u: goto label_190dc8;
            case 0x190E48u: goto label_190e48;
            case 0x190EECu: goto label_190eec;
            case 0x190F68u: goto label_190f68;
            case 0x190FE8u: goto label_190fe8;
            case 0x1910ECu: goto label_1910ec;
            case 0x1910F4u: goto label_1910f4;
            case 0x191104u: goto label_191104;
            case 0x19110Cu: goto label_19110c;
            case 0x19111Cu: goto label_19111c;
            case 0x191184u: goto label_191184;
            case 0x191198u: goto label_191198;
            case 0x1911ACu: goto label_1911ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190BA0u;
    // 0x190ba0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x190ba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x190ba4: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x190ba4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190ba8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x190ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x190bac: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190BACu;
    SET_GPR_U32(ctx, 31, 0x190BB4u);
    ctx->pc = 0x190BB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190BACu;
            // 0x190bb0: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190BB4u; }
        if (ctx->pc != 0x190BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190BB4u; }
        if (ctx->pc != 0x190BB4u) { return; }
    }
    ctx->pc = 0x190BB4u;
label_190bb4:
    // 0x190bb4: 0xc7a10030  lwc1        $f1, 0x30($sp)
    ctx->pc = 0x190bb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190bb8: 0xc7a00034  lwc1        $f0, 0x34($sp)
    ctx->pc = 0x190bb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190bbc: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190bbcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190bc0: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190bc0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190bc4: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190bc4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190bc8: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190bc8u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190bcc: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190bccu;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190bd0: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190bd0u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190bd4: 0x4ac002a8  vadd.yz     $vf10, $vf0, $vf0
    ctx->pc = 0x190bd4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190bd8: 0x4b000283  vaddw.x     $vf10, $vf0, $vf0w
    ctx->pc = 0x190bd8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190bdc: 0x4b0002e8  vadd.x      $vf11, $vf0, $vf0
    ctx->pc = 0x190bdcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190be0: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190be0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190be4: 0x4a5402c0  vaddx.z     $vf11, $vf0, $vf20x
    ctx->pc = 0x190be4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190be8: 0x4b000328  vadd.x      $vf12, $vf0, $vf0
    ctx->pc = 0x190be8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190bec: 0x4a940304  vsubx.y     $vf12, $vf0, $vf20x
    ctx->pc = 0x190becu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190bf0: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190bf0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190bf4: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190bf4u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190bf8: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190bf8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190bfc: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190bfcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c00: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190c00u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190c04: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190c04u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c08: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190c08u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c0c: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190c0cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190c10: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190c10u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c14: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190c14u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c18: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190c18u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190c1c: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190c1cu;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190c20: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190c20u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190c24: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190c24u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190c28: 0x46007306  mov.s       $f12, $f14
    ctx->pc = 0x190c28u;
    ctx->f[12] = FPU_MOV_S(ctx->f[14]);
    // 0x190c2c: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190C2Cu;
    SET_GPR_U32(ctx, 31, 0x190C34u);
    ctx->pc = 0x190C30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190C2Cu;
            // 0x190c30: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190C34u; }
        if (ctx->pc != 0x190C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190C34u; }
        if (ctx->pc != 0x190C34u) { return; }
    }
    ctx->pc = 0x190C34u;
label_190c34:
    // 0x190c34: 0xc7a10020  lwc1        $f1, 0x20($sp)
    ctx->pc = 0x190c34u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190c38: 0xc7a00024  lwc1        $f0, 0x24($sp)
    ctx->pc = 0x190c38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190c3c: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190c3cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190c40: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190c40u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190c44: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190c44u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190c48: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190c48u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190c4c: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190c4cu;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190c50: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190c50u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190c54: 0x4a4002a8  vadd.z      $vf10, $vf0, $vf0
    ctx->pc = 0x190c54u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190c58: 0x4a940280  vaddx.y     $vf10, $vf0, $vf20x
    ctx->pc = 0x190c58u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190c5c: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190c5cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190c60: 0x4a4002e8  vadd.z      $vf11, $vf0, $vf0
    ctx->pc = 0x190c60u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190c64: 0x4b1402c4  vsubx.x     $vf11, $vf0, $vf20x
    ctx->pc = 0x190c64u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190c68: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190c68u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190c6c: 0x4bcc033d  vmr32.xyz   $vf12, $vf0
    ctx->pc = 0x190c6cu;
    { __m128 res = _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,3,2,1)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190c70: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190c70u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190c74: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190c74u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c78: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190c78u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c7c: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190c7cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190c80: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190c80u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c84: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190c84u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c88: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190c88u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190c8c: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190c8cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c90: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190c90u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190c94: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190c94u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190c98: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190c98u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190c9c: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190c9cu;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190ca0: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190ca0u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190ca4: 0x46006b06  mov.s       $f12, $f13
    ctx->pc = 0x190ca4u;
    ctx->f[12] = FPU_MOV_S(ctx->f[13]);
    // 0x190ca8: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190CA8u;
    SET_GPR_U32(ctx, 31, 0x190CB0u);
    ctx->pc = 0x190CACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190CA8u;
            // 0x190cac: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190CB0u; }
        if (ctx->pc != 0x190CB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190CB0u; }
        if (ctx->pc != 0x190CB0u) { return; }
    }
    ctx->pc = 0x190CB0u;
label_190cb0:
    // 0x190cb0: 0xc7a10010  lwc1        $f1, 0x10($sp)
    ctx->pc = 0x190cb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190cb4: 0xc7a00014  lwc1        $f0, 0x14($sp)
    ctx->pc = 0x190cb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190cb8: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190cb8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190cbc: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190cbcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190cc0: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190cc0u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190cc4: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190cc4u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190cc8: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190cc8u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190ccc: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190cccu;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190cd0: 0x4b4002e8  vadd.xz     $vf11, $vf0, $vf0
    ctx->pc = 0x190cd0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190cd4: 0x4a8002c3  vaddw.y     $vf11, $vf0, $vf0w
    ctx->pc = 0x190cd4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190cd8: 0x4a8002a8  vadd.y      $vf10, $vf0, $vf0
    ctx->pc = 0x190cd8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190cdc: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190cdcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190ce0: 0x4a540284  vsubx.z     $vf10, $vf0, $vf20x
    ctx->pc = 0x190ce0u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190ce4: 0x4a800328  vadd.y      $vf12, $vf0, $vf0
    ctx->pc = 0x190ce4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190ce8: 0x4b140300  vaddx.x     $vf12, $vf0, $vf20x
    ctx->pc = 0x190ce8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190cec: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190cecu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190cf0: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190cf0u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190cf4: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190cf4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190cf8: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190cf8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190cfc: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190cfcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190d00: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190d00u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190d04: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190d04u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190d08: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190d08u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190d0c: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190d0cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190d10: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190d10u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190d14: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190d14u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190d18: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190d18u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190d1c: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190d1cu;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190d20: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190d20u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190d24: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x190d24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x190d28: 0x3e00008  jr          $ra
    ctx->pc = 0x190D28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190D28u;
            // 0x190d2c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x190A24u: goto label_190a24;
            case 0x190AA4u: goto label_190aa4;
            case 0x190B24u: goto label_190b24;
            case 0x190BB4u: goto label_190bb4;
            case 0x190C34u: goto label_190c34;
            case 0x190CB0u: goto label_190cb0;
            case 0x190D4Cu: goto label_190d4c;
            case 0x190DC8u: goto label_190dc8;
            case 0x190E48u: goto label_190e48;
            case 0x190EECu: goto label_190eec;
            case 0x190F68u: goto label_190f68;
            case 0x190FE8u: goto label_190fe8;
            case 0x1910ECu: goto label_1910ec;
            case 0x1910F4u: goto label_1910f4;
            case 0x191104u: goto label_191104;
            case 0x19110Cu: goto label_19110c;
            case 0x19111Cu: goto label_19111c;
            case 0x191184u: goto label_191184;
            case 0x191198u: goto label_191198;
            case 0x1911ACu: goto label_1911ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190D30u;
    // 0x190d30: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x190d30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x190d34: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x190d34u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190d38: 0x46006086  mov.s       $f2, $f12
    ctx->pc = 0x190d38u;
    ctx->f[2] = FPU_MOV_S(ctx->f[12]);
    // 0x190d3c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x190d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x190d40: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x190d40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x190d44: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190D44u;
    SET_GPR_U32(ctx, 31, 0x190D4Cu);
    ctx->pc = 0x190D48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190D44u;
            // 0x190d48: 0x46007306  mov.s       $f12, $f14 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[14]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190D4Cu; }
        if (ctx->pc != 0x190D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190D4Cu; }
        if (ctx->pc != 0x190D4Cu) { return; }
    }
    ctx->pc = 0x190D4Cu;
label_190d4c:
    // 0x190d4c: 0xc7a10030  lwc1        $f1, 0x30($sp)
    ctx->pc = 0x190d4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190d50: 0xc7a00034  lwc1        $f0, 0x34($sp)
    ctx->pc = 0x190d50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190d54: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190d54u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190d58: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190d58u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190d5c: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190d5cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190d60: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190d60u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190d64: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190d64u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190d68: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190d68u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190d6c: 0x4a4002a8  vadd.z      $vf10, $vf0, $vf0
    ctx->pc = 0x190d6cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190d70: 0x4a940280  vaddx.y     $vf10, $vf0, $vf20x
    ctx->pc = 0x190d70u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190d74: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190d74u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190d78: 0x4a4002e8  vadd.z      $vf11, $vf0, $vf0
    ctx->pc = 0x190d78u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190d7c: 0x4b1402c4  vsubx.x     $vf11, $vf0, $vf20x
    ctx->pc = 0x190d7cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190d80: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190d80u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190d84: 0x4bcc033d  vmr32.xyz   $vf12, $vf0
    ctx->pc = 0x190d84u;
    { __m128 res = _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,3,2,1)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190d88: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190d88u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190d8c: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190d8cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190d90: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190d90u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190d94: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190d94u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190d98: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190d98u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190d9c: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190d9cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190da0: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190da0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190da4: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190da4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190da8: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190da8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190dac: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190dacu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190db0: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190db0u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190db4: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190db4u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190db8: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190db8u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190dbc: 0x46006b06  mov.s       $f12, $f13
    ctx->pc = 0x190dbcu;
    ctx->f[12] = FPU_MOV_S(ctx->f[13]);
    // 0x190dc0: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190DC0u;
    SET_GPR_U32(ctx, 31, 0x190DC8u);
    ctx->pc = 0x190DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190DC0u;
            // 0x190dc4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190DC8u; }
        if (ctx->pc != 0x190DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190DC8u; }
        if (ctx->pc != 0x190DC8u) { return; }
    }
    ctx->pc = 0x190DC8u;
label_190dc8:
    // 0x190dc8: 0xc7a10020  lwc1        $f1, 0x20($sp)
    ctx->pc = 0x190dc8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190dcc: 0xc7a00024  lwc1        $f0, 0x24($sp)
    ctx->pc = 0x190dccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190dd0: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190dd0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190dd4: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190dd4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190dd8: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190dd8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190ddc: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190ddcu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190de0: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190de0u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190de4: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190de4u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190de8: 0x4b4002e8  vadd.xz     $vf11, $vf0, $vf0
    ctx->pc = 0x190de8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190dec: 0x4a8002c3  vaddw.y     $vf11, $vf0, $vf0w
    ctx->pc = 0x190decu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190df0: 0x4a8002a8  vadd.y      $vf10, $vf0, $vf0
    ctx->pc = 0x190df0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190df4: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190df4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190df8: 0x4a540284  vsubx.z     $vf10, $vf0, $vf20x
    ctx->pc = 0x190df8u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190dfc: 0x4a800328  vadd.y      $vf12, $vf0, $vf0
    ctx->pc = 0x190dfcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190e00: 0x4b140300  vaddx.x     $vf12, $vf0, $vf20x
    ctx->pc = 0x190e00u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190e04: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190e04u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190e08: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190e08u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190e0c: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190e0cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e10: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190e10u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e14: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190e14u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190e18: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190e18u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e1c: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190e1cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e20: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190e20u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190e24: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190e24u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e28: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190e28u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e2c: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190e2cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190e30: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190e30u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190e34: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190e34u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190e38: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190e38u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190e3c: 0x46001306  mov.s       $f12, $f2
    ctx->pc = 0x190e3cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[2]);
    // 0x190e40: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190E40u;
    SET_GPR_U32(ctx, 31, 0x190E48u);
    ctx->pc = 0x190E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190E40u;
            // 0x190e44: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190E48u; }
        if (ctx->pc != 0x190E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190E48u; }
        if (ctx->pc != 0x190E48u) { return; }
    }
    ctx->pc = 0x190E48u;
label_190e48:
    // 0x190e48: 0xc7a10010  lwc1        $f1, 0x10($sp)
    ctx->pc = 0x190e48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190e4c: 0xc7a00014  lwc1        $f0, 0x14($sp)
    ctx->pc = 0x190e4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190e50: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190e50u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190e54: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190e54u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190e58: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190e58u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190e5c: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190e5cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190e60: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190e60u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190e64: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190e64u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190e68: 0x4ac002a8  vadd.yz     $vf10, $vf0, $vf0
    ctx->pc = 0x190e68u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190e6c: 0x4b000283  vaddw.x     $vf10, $vf0, $vf0w
    ctx->pc = 0x190e6cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190e70: 0x4b0002e8  vadd.x      $vf11, $vf0, $vf0
    ctx->pc = 0x190e70u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190e74: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190e74u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190e78: 0x4a5402c0  vaddx.z     $vf11, $vf0, $vf20x
    ctx->pc = 0x190e78u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190e7c: 0x4b000328  vadd.x      $vf12, $vf0, $vf0
    ctx->pc = 0x190e7cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190e80: 0x4a940304  vsubx.y     $vf12, $vf0, $vf20x
    ctx->pc = 0x190e80u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190e84: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190e84u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190e88: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190e88u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190e8c: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190e8cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e90: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190e90u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e94: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190e94u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190e98: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190e98u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190e9c: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190e9cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190ea0: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190ea0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190ea4: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190ea4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190ea8: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190ea8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190eac: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190eacu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190eb0: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190eb0u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190eb4: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190eb4u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190eb8: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190eb8u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190ebc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x190ebcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x190ec0: 0x3e00008  jr          $ra
    ctx->pc = 0x190EC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190EC0u;
            // 0x190ec4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x190A24u: goto label_190a24;
            case 0x190AA4u: goto label_190aa4;
            case 0x190B24u: goto label_190b24;
            case 0x190BB4u: goto label_190bb4;
            case 0x190C34u: goto label_190c34;
            case 0x190CB0u: goto label_190cb0;
            case 0x190D4Cu: goto label_190d4c;
            case 0x190DC8u: goto label_190dc8;
            case 0x190E48u: goto label_190e48;
            case 0x190EECu: goto label_190eec;
            case 0x190F68u: goto label_190f68;
            case 0x190FE8u: goto label_190fe8;
            case 0x1910ECu: goto label_1910ec;
            case 0x1910F4u: goto label_1910f4;
            case 0x191104u: goto label_191104;
            case 0x19110Cu: goto label_19110c;
            case 0x19111Cu: goto label_19111c;
            case 0x191184u: goto label_191184;
            case 0x191198u: goto label_191198;
            case 0x1911ACu: goto label_1911ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190EC8u;
    // 0x190ec8: 0x0  nop
    ctx->pc = 0x190ec8u;
    // NOP
    // 0x190ecc: 0x0  nop
    ctx->pc = 0x190eccu;
    // NOP
    // 0x190ed0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x190ed0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x190ed4: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x190ed4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190ed8: 0x46006086  mov.s       $f2, $f12
    ctx->pc = 0x190ed8u;
    ctx->f[2] = FPU_MOV_S(ctx->f[12]);
    // 0x190edc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x190edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x190ee0: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x190ee0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x190ee4: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190EE4u;
    SET_GPR_U32(ctx, 31, 0x190EECu);
    ctx->pc = 0x190EE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190EE4u;
            // 0x190ee8: 0x46007306  mov.s       $f12, $f14 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[14]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190EECu; }
        if (ctx->pc != 0x190EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190EECu; }
        if (ctx->pc != 0x190EECu) { return; }
    }
    ctx->pc = 0x190EECu;
label_190eec:
    // 0x190eec: 0xc7a10030  lwc1        $f1, 0x30($sp)
    ctx->pc = 0x190eecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190ef0: 0xc7a00034  lwc1        $f0, 0x34($sp)
    ctx->pc = 0x190ef0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190ef4: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190ef4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190ef8: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190ef8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190efc: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190efcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190f00: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190f00u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190f04: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190f04u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190f08: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190f08u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190f0c: 0x4a4002a8  vadd.z      $vf10, $vf0, $vf0
    ctx->pc = 0x190f0cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190f10: 0x4a940280  vaddx.y     $vf10, $vf0, $vf20x
    ctx->pc = 0x190f10u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190f14: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190f14u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190f18: 0x4a4002e8  vadd.z      $vf11, $vf0, $vf0
    ctx->pc = 0x190f18u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190f1c: 0x4b1402c4  vsubx.x     $vf11, $vf0, $vf20x
    ctx->pc = 0x190f1cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190f20: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190f20u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190f24: 0x4bcc033d  vmr32.xyz   $vf12, $vf0
    ctx->pc = 0x190f24u;
    { __m128 res = _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,3,2,1)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190f28: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190f28u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190f2c: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190f2cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190f30: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190f30u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190f34: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190f34u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190f38: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190f38u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190f3c: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190f3cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190f40: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190f40u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190f44: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190f44u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190f48: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190f48u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190f4c: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190f4cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190f50: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190f50u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190f54: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190f54u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190f58: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190f58u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190f5c: 0x46001306  mov.s       $f12, $f2
    ctx->pc = 0x190f5cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[2]);
    // 0x190f60: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190F60u;
    SET_GPR_U32(ctx, 31, 0x190F68u);
    ctx->pc = 0x190F64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190F60u;
            // 0x190f64: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190F68u; }
        if (ctx->pc != 0x190F68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190F68u; }
        if (ctx->pc != 0x190F68u) { return; }
    }
    ctx->pc = 0x190F68u;
label_190f68:
    // 0x190f68: 0xc7a10020  lwc1        $f1, 0x20($sp)
    ctx->pc = 0x190f68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190f6c: 0xc7a00024  lwc1        $f0, 0x24($sp)
    ctx->pc = 0x190f6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190f70: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190f70u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190f74: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190f74u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190f78: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190f78u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190f7c: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190f7cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x190f80: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190f80u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190f84: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190f84u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190f88: 0x4ac002a8  vadd.yz     $vf10, $vf0, $vf0
    ctx->pc = 0x190f88u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190f8c: 0x4b000283  vaddw.x     $vf10, $vf0, $vf0w
    ctx->pc = 0x190f8cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190f90: 0x4b0002e8  vadd.x      $vf11, $vf0, $vf0
    ctx->pc = 0x190f90u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190f94: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190f94u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190f98: 0x4a5402c0  vaddx.z     $vf11, $vf0, $vf20x
    ctx->pc = 0x190f98u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190f9c: 0x4b000328  vadd.x      $vf12, $vf0, $vf0
    ctx->pc = 0x190f9cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190fa0: 0x4a940304  vsubx.y     $vf12, $vf0, $vf20x
    ctx->pc = 0x190fa0u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190fa4: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190fa4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190fa8: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190fa8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x190fac: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190facu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190fb0: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190fb0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190fb4: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190fb4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x190fb8: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190fb8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190fbc: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190fbcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190fc0: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190fc0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x190fc4: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190fc4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190fc8: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190fc8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x190fcc: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190fccu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x190fd0: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190fd0u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190fd4: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190fd4u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190fd8: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x190fd8u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190fdc: 0x46006b06  mov.s       $f12, $f13
    ctx->pc = 0x190fdcu;
    ctx->f[12] = FPU_MOV_S(ctx->f[13]);
    // 0x190fe0: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190FE0u;
    SET_GPR_U32(ctx, 31, 0x190FE8u);
    ctx->pc = 0x190FE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190FE0u;
            // 0x190fe4: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190FE8u; }
        if (ctx->pc != 0x190FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190FE8u; }
        if (ctx->pc != 0x190FE8u) { return; }
    }
    ctx->pc = 0x190FE8u;
label_190fe8:
    // 0x190fe8: 0xc7a10010  lwc1        $f1, 0x10($sp)
    ctx->pc = 0x190fe8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x190fec: 0xc7a00014  lwc1        $f0, 0x14($sp)
    ctx->pc = 0x190fecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190ff0: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190ff0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190ff4: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190ff4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190ff8: 0xd9240000  lqc2        $vf4, 0x0($t1)
    ctx->pc = 0x190ff8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x190ffc: 0xd9250010  lqc2        $vf5, 0x10($t1)
    ctx->pc = 0x190ffcu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x191000: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x191000u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x191004: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x191004u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x191008: 0x4b4002e8  vadd.xz     $vf11, $vf0, $vf0
    ctx->pc = 0x191008u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x19100c: 0x4a8002c3  vaddw.y     $vf11, $vf0, $vf0w
    ctx->pc = 0x19100cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x191010: 0x4a8002a8  vadd.y      $vf10, $vf0, $vf0
    ctx->pc = 0x191010u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x191014: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x191014u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x191018: 0x4a540284  vsubx.z     $vf10, $vf0, $vf20x
    ctx->pc = 0x191018u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x19101c: 0x4a800328  vadd.y      $vf12, $vf0, $vf0
    ctx->pc = 0x19101cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x191020: 0x4b140300  vaddx.x     $vf12, $vf0, $vf20x
    ctx->pc = 0x191020u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x191024: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x191024u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x191028: 0xd9260020  lqc2        $vf6, 0x20($t1)
    ctx->pc = 0x191028u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x19102c: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x19102cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191030: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x191030u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191034: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x191034u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191038: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x191038u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19103c: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x19103cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191040: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x191040u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191044: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x191044u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191048: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x191048u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x19104c: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x19104cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x191050: 0xf9240000  sqc2        $vf4, 0x0($t1)
    ctx->pc = 0x191050u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191054: 0xf9250010  sqc2        $vf5, 0x10($t1)
    ctx->pc = 0x191054u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x191058: 0xf9260020  sqc2        $vf6, 0x20($t1)
    ctx->pc = 0x191058u;
    WRITE128(ADD32(GPR_U32(ctx, 9), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x19105c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19105cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191060: 0x3e00008  jr          $ra
    ctx->pc = 0x191060u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191060u;
            // 0x191064: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x190A24u: goto label_190a24;
            case 0x190AA4u: goto label_190aa4;
            case 0x190B24u: goto label_190b24;
            case 0x190BB4u: goto label_190bb4;
            case 0x190C34u: goto label_190c34;
            case 0x190CB0u: goto label_190cb0;
            case 0x190D4Cu: goto label_190d4c;
            case 0x190DC8u: goto label_190dc8;
            case 0x190E48u: goto label_190e48;
            case 0x190EECu: goto label_190eec;
            case 0x190F68u: goto label_190f68;
            case 0x190FE8u: goto label_190fe8;
            case 0x1910ECu: goto label_1910ec;
            case 0x1910F4u: goto label_1910f4;
            case 0x191104u: goto label_191104;
            case 0x19110Cu: goto label_19110c;
            case 0x19111Cu: goto label_19111c;
            case 0x191184u: goto label_191184;
            case 0x191198u: goto label_191198;
            case 0x1911ACu: goto label_1911ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191068u;
    // 0x191068: 0x0  nop
    ctx->pc = 0x191068u;
    // NOP
    // 0x19106c: 0x0  nop
    ctx->pc = 0x19106cu;
    // NOP
    // 0x191070: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x191070u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x191074: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x191074u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x191078: 0x27a20050  addiu       $v0, $sp, 0x50
    ctx->pc = 0x191078u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19107c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19107cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x191080: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x191080u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x191084: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x191084u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191088: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x191088u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19108c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19108cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191090: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191090u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x191094: 0x27b10064  addiu       $s1, $sp, 0x64
    ctx->pc = 0x191094u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 100));
    // 0x191098: 0xc4a10000  lwc1        $f1, 0x0($a1)
    ctx->pc = 0x191098u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19109c: 0x27b00068  addiu       $s0, $sp, 0x68
    ctx->pc = 0x19109cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x1910a0: 0xc4c00000  lwc1        $f0, 0x0($a2)
    ctx->pc = 0x1910a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910a4: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1910a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1910a8: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1910a8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1910ac: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x1910acu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x1910b0: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x1910b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1910b4: 0xc4c00004  lwc1        $f0, 0x4($a2)
    ctx->pc = 0x1910b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910b8: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1910b8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1910bc: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x1910bcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x1910c0: 0xc4a10008  lwc1        $f1, 0x8($a1)
    ctx->pc = 0x1910c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1910c4: 0xc4c00008  lwc1        $f0, 0x8($a2)
    ctx->pc = 0x1910c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910c8: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1910c8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1910cc: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x1910ccu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x1910d0: 0xc4e20000  lwc1        $f2, 0x0($a3)
    ctx->pc = 0x1910d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1910d4: 0xc4e10004  lwc1        $f1, 0x4($a3)
    ctx->pc = 0x1910d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1910d8: 0xc4e00008  lwc1        $f0, 0x8($a3)
    ctx->pc = 0x1910d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910dc: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x1910dcu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x1910e0: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x1910e0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x1910e4: 0xc064760  jal         func_191D80
    ctx->pc = 0x1910E4u;
    SET_GPR_U32(ctx, 31, 0x1910ECu);
    ctx->pc = 0x1910E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1910E4u;
            // 0x1910e8: 0xe4400008  swc1        $f0, 0x8($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D80u;
    if (runtime->hasFunction(0x191D80u)) {
        auto targetFn = runtime->lookupFunction(0x191D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910ECu; }
        if (ctx->pc != 0x1910ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D80_0x191d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910ECu; }
        if (ctx->pc != 0x1910ECu) { return; }
    }
    ctx->pc = 0x1910ECu;
label_1910ec:
    // 0x1910ec: 0xc064760  jal         func_191D80
    ctx->pc = 0x1910ECu;
    SET_GPR_U32(ctx, 31, 0x1910F4u);
    ctx->pc = 0x1910F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1910ECu;
            // 0x1910f0: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D80u;
    if (runtime->hasFunction(0x191D80u)) {
        auto targetFn = runtime->lookupFunction(0x191D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910F4u; }
        if (ctx->pc != 0x1910F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D80_0x191d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910F4u; }
        if (ctx->pc != 0x1910F4u) { return; }
    }
    ctx->pc = 0x1910F4u;
label_1910f4:
    // 0x1910f4: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1910f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1910f8: 0x27a50050  addiu       $a1, $sp, 0x50
    ctx->pc = 0x1910f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1910fc: 0xc064794  jal         func_191E50
    ctx->pc = 0x1910FCu;
    SET_GPR_U32(ctx, 31, 0x191104u);
    ctx->pc = 0x191100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1910FCu;
            // 0x191100: 0x27a60060  addiu       $a2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191E50u;
    if (runtime->hasFunction(0x191E50u)) {
        auto targetFn = runtime->lookupFunction(0x191E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191104u; }
        if (ctx->pc != 0x191104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191E50_0x191e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191104u; }
        if (ctx->pc != 0x191104u) { return; }
    }
    ctx->pc = 0x191104u;
label_191104:
    // 0x191104: 0xc064760  jal         func_191D80
    ctx->pc = 0x191104u;
    SET_GPR_U32(ctx, 31, 0x19110Cu);
    ctx->pc = 0x191108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191104u;
            // 0x191108: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D80u;
    if (runtime->hasFunction(0x191D80u)) {
        auto targetFn = runtime->lookupFunction(0x191D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19110Cu; }
        if (ctx->pc != 0x19110Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D80_0x191d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19110Cu; }
        if (ctx->pc != 0x19110Cu) { return; }
    }
    ctx->pc = 0x19110Cu;
label_19110c:
    // 0x19110c: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x19110cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x191110: 0x27a50060  addiu       $a1, $sp, 0x60
    ctx->pc = 0x191110u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x191114: 0xc064794  jal         func_191E50
    ctx->pc = 0x191114u;
    SET_GPR_U32(ctx, 31, 0x19111Cu);
    ctx->pc = 0x191118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191114u;
            // 0x191118: 0x27a60080  addiu       $a2, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191E50u;
    if (runtime->hasFunction(0x191E50u)) {
        auto targetFn = runtime->lookupFunction(0x191E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19111Cu; }
        if (ctx->pc != 0x19111Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191E50_0x191e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19111Cu; }
        if (ctx->pc != 0x19111Cu) { return; }
    }
    ctx->pc = 0x19111Cu;
label_19111c:
    // 0x19111c: 0xae60000c  sw          $zero, 0xC($s3)
    ctx->pc = 0x19111cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 0));
    // 0x191120: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x191120u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x191124: 0xae60001c  sw          $zero, 0x1C($s3)
    ctx->pc = 0x191124u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 0));
    // 0x191128: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x191128u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19112c: 0xae60002c  sw          $zero, 0x2C($s3)
    ctx->pc = 0x19112cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 44), GPR_U32(ctx, 0));
    // 0x191130: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x191130u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x191134: 0xae62003c  sw          $v0, 0x3C($s3)
    ctx->pc = 0x191134u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 2));
    // 0x191138: 0xc7a00080  lwc1        $f0, 0x80($sp)
    ctx->pc = 0x191138u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 128)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19113c: 0xe6600000  swc1        $f0, 0x0($s3)
    ctx->pc = 0x19113cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 0), bits); }
    // 0x191140: 0xc7a00084  lwc1        $f0, 0x84($sp)
    ctx->pc = 0x191140u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 132)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191144: 0xe6600010  swc1        $f0, 0x10($s3)
    ctx->pc = 0x191144u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 16), bits); }
    // 0x191148: 0xc7a00088  lwc1        $f0, 0x88($sp)
    ctx->pc = 0x191148u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 136)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19114c: 0xe6600020  swc1        $f0, 0x20($s3)
    ctx->pc = 0x19114cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 32), bits); }
    // 0x191150: 0xc7a00070  lwc1        $f0, 0x70($sp)
    ctx->pc = 0x191150u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191154: 0xe6600004  swc1        $f0, 0x4($s3)
    ctx->pc = 0x191154u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 4), bits); }
    // 0x191158: 0xc7a00074  lwc1        $f0, 0x74($sp)
    ctx->pc = 0x191158u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 116)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19115c: 0xe6600014  swc1        $f0, 0x14($s3)
    ctx->pc = 0x19115cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 20), bits); }
    // 0x191160: 0xc7a00078  lwc1        $f0, 0x78($sp)
    ctx->pc = 0x191160u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 120)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191164: 0xe6600024  swc1        $f0, 0x24($s3)
    ctx->pc = 0x191164u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 36), bits); }
    // 0x191168: 0xc7a00060  lwc1        $f0, 0x60($sp)
    ctx->pc = 0x191168u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 96)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19116c: 0xe6600008  swc1        $f0, 0x8($s3)
    ctx->pc = 0x19116cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 8), bits); }
    // 0x191170: 0xc6200000  lwc1        $f0, 0x0($s1)
    ctx->pc = 0x191170u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191174: 0xe6600018  swc1        $f0, 0x18($s3)
    ctx->pc = 0x191174u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 24), bits); }
    // 0x191178: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x191178u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19117c: 0xc06477c  jal         func_191DF0
    ctx->pc = 0x19117Cu;
    SET_GPR_U32(ctx, 31, 0x191184u);
    ctx->pc = 0x191180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19117Cu;
            // 0x191180: 0xe6600028  swc1        $f0, 0x28($s3) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 40), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191DF0u;
    if (runtime->hasFunction(0x191DF0u)) {
        auto targetFn = runtime->lookupFunction(0x191DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191184u; }
        if (ctx->pc != 0x191184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191DF0_0x191df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191184u; }
        if (ctx->pc != 0x191184u) { return; }
    }
    ctx->pc = 0x191184u;
label_191184:
    // 0x191184: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191184u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191188: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x191188u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19118c: 0xe6600030  swc1        $f0, 0x30($s3)
    ctx->pc = 0x19118cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 48), bits); }
    // 0x191190: 0xc06477c  jal         func_191DF0
    ctx->pc = 0x191190u;
    SET_GPR_U32(ctx, 31, 0x191198u);
    ctx->pc = 0x191194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191190u;
            // 0x191194: 0x27a50070  addiu       $a1, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191DF0u;
    if (runtime->hasFunction(0x191DF0u)) {
        auto targetFn = runtime->lookupFunction(0x191DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191198u; }
        if (ctx->pc != 0x191198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191DF0_0x191df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191198u; }
        if (ctx->pc != 0x191198u) { return; }
    }
    ctx->pc = 0x191198u;
label_191198:
    // 0x191198: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191198u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19119c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x19119cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1911a0: 0x27a50060  addiu       $a1, $sp, 0x60
    ctx->pc = 0x1911a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1911a4: 0xc06477c  jal         func_191DF0
    ctx->pc = 0x1911A4u;
    SET_GPR_U32(ctx, 31, 0x1911ACu);
    ctx->pc = 0x1911A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1911A4u;
            // 0x1911a8: 0xe6600034  swc1        $f0, 0x34($s3) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 52), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191DF0u;
    if (runtime->hasFunction(0x191DF0u)) {
        auto targetFn = runtime->lookupFunction(0x191DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1911ACu; }
        if (ctx->pc != 0x1911ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191DF0_0x191df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1911ACu; }
        if (ctx->pc != 0x1911ACu) { return; }
    }
    ctx->pc = 0x1911ACu;
label_1911ac:
    // 0x1911ac: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x1911acu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x1911b0: 0xe6600038  swc1        $f0, 0x38($s3)
    ctx->pc = 0x1911b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 56), bits); }
    // 0x1911b4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1911b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1911b8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1911b8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1911bc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1911bcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1911c0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1911c0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1911c4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1911c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1911c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1911C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1911CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1911C8u;
            // 0x1911cc: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x190A24u: goto label_190a24;
            case 0x190AA4u: goto label_190aa4;
            case 0x190B24u: goto label_190b24;
            case 0x190BB4u: goto label_190bb4;
            case 0x190C34u: goto label_190c34;
            case 0x190CB0u: goto label_190cb0;
            case 0x190D4Cu: goto label_190d4c;
            case 0x190DC8u: goto label_190dc8;
            case 0x190E48u: goto label_190e48;
            case 0x190EECu: goto label_190eec;
            case 0x190F68u: goto label_190f68;
            case 0x190FE8u: goto label_190fe8;
            case 0x1910ECu: goto label_1910ec;
            case 0x1910F4u: goto label_1910f4;
            case 0x191104u: goto label_191104;
            case 0x19110Cu: goto label_19110c;
            case 0x19111Cu: goto label_19111c;
            case 0x191184u: goto label_191184;
            case 0x191198u: goto label_191198;
            case 0x1911ACu: goto label_1911ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1911D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

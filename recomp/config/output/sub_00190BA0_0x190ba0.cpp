#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00190BA0
// Address: 0x190ba0 - 0x190d30
void sub_00190BA0_0x190ba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00190BA0_0x190ba0");
#endif

    switch (ctx->pc) {
        case 0x190bb4u: goto label_190bb4;
        case 0x190c34u: goto label_190c34;
        case 0x190cb0u: goto label_190cb0;
        default: break;
    }

    ctx->pc = 0x190ba0u;

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
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190bfc: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190bfcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190c00: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190c00u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190c04: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190c04u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190c08: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190c08u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190c0c: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190c0cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190c10: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190c10u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190c14: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190c14u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190c18: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190c18u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
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
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190c78: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190c78u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190c7c: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190c7cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190c80: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190c80u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190c84: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190c84u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190c88: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190c88u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190c8c: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190c8cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190c90: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190c90u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190c94: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190c94u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
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
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190cf8: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190cf8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190cfc: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190cfcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190d00: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190d00u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190d04: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190d04u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190d08: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190d08u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190d0c: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190d0cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190d10: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190d10u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190d14: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190d14u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
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
            case 0x190BB4u: goto label_190bb4;
            case 0x190C34u: goto label_190c34;
            case 0x190CB0u: goto label_190cb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190D30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

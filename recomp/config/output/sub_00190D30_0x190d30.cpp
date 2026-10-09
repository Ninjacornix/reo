#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00190D30
// Address: 0x190d30 - 0x190ec8
void sub_00190D30_0x190d30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00190D30_0x190d30");
#endif

    switch (ctx->pc) {
        case 0x190d4cu: goto label_190d4c;
        case 0x190dc8u: goto label_190dc8;
        case 0x190e48u: goto label_190e48;
        default: break;
    }

    ctx->pc = 0x190d30u;

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
            case 0x190D4Cu: goto label_190d4c;
            case 0x190DC8u: goto label_190dc8;
            case 0x190E48u: goto label_190e48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190EC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

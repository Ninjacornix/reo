#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00199740
// Address: 0x199740 - 0x199870
void sub_00199740_0x199740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00199740_0x199740");
#endif

    switch (ctx->pc) {
        case 0x199774u: goto label_199774;
        default: break;
    }

    ctx->pc = 0x199740u;

    // 0x199740: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x199740u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x199744: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x199744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x199748: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x199748u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19974c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19974cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x199750: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x199750u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199754: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x199754u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x199758: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x199758u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19975c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19975cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x199760: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x199760u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199764: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x199764u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199768: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x199768u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19976c: 0xc06450c  jal         func_191430
    ctx->pc = 0x19976Cu;
    SET_GPR_U32(ctx, 31, 0x199774u);
    ctx->pc = 0x199770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19976Cu;
            // 0x199770: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191430u;
    if (runtime->hasFunction(0x191430u)) {
        auto targetFn = runtime->lookupFunction(0x191430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199774u; }
        if (ctx->pc != 0x199774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191430_0x191430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199774u; }
        if (ctx->pc != 0x199774u) { return; }
    }
    ctx->pc = 0x199774u;
label_199774:
    // 0x199774: 0x27a30050  addiu       $v1, $sp, 0x50
    ctx->pc = 0x199774u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x199778: 0xda2a0000  lqc2        $vf10, 0x0($s1)
    ctx->pc = 0x199778u;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x19977c: 0xda2b0010  lqc2        $vf11, 0x10($s1)
    ctx->pc = 0x19977cu;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x199780: 0xda2c0020  lqc2        $vf12, 0x20($s1)
    ctx->pc = 0x199780u;
    ctx->vu0_vf[12] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x199784: 0x4b0a01c0  vaddx.x     $vf7, $vf0, $vf10x
    ctx->pc = 0x199784u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x199788: 0x4b0a0201  vaddy.x     $vf8, $vf0, $vf10y
    ctx->pc = 0x199788u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x19978c: 0x4b0a0242  vaddz.x     $vf9, $vf0, $vf10z
    ctx->pc = 0x19978cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x199790: 0x4a8b01c0  vaddx.y     $vf7, $vf0, $vf11x
    ctx->pc = 0x199790u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x199794: 0x4a8b0201  vaddy.y     $vf8, $vf0, $vf11y
    ctx->pc = 0x199794u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x199798: 0x4a8b0242  vaddz.y     $vf9, $vf0, $vf11z
    ctx->pc = 0x199798u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x19979c: 0x4a4c01c0  vaddx.z     $vf7, $vf0, $vf12x
    ctx->pc = 0x19979cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1997a0: 0x4a4c0201  vaddy.z     $vf8, $vf0, $vf12y
    ctx->pc = 0x1997a0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x1997a4: 0x4a4c0242  vaddz.z     $vf9, $vf0, $vf12z
    ctx->pc = 0x1997a4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x1997a8: 0xda0a0000  lqc2        $vf10, 0x0($s0)
    ctx->pc = 0x1997a8u;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1997ac: 0x4bca39bc  vmulax.xyz  $ACC, $vf7, $vf10x
    ctx->pc = 0x1997acu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x1997b0: 0x4bca40bd  vmadday.xyz $ACC, $vf8, $vf10y
    ctx->pc = 0x1997b0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1997b4: 0x4bca4a8a  vmaddz.xyz  $vf10, $vf9, $vf10z
    ctx->pc = 0x1997b4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x1997b8: 0x4bca51ea  vmul.xyz    $vf7, $vf10, $vf10
    ctx->pc = 0x1997b8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], ctx->vu0_vf[10]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[7] = PS2_VBLEND(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1997bc: 0x4b0739c1  vaddy.x     $vf7, $vf7, $vf7y
    ctx->pc = 0x1997bcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1997c0: 0x4b0739c2  vaddz.x     $vf7, $vf7, $vf7z
    ctx->pc = 0x1997c0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x1997c4: 0x4a6703be  vrsqrt      $Q, $vf0w, $vf7x
    ctx->pc = 0x1997c4u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[7], ctx->vu0_vf[7], _MM_SHUFFLE(0,0,0,0))); if (ft > 0.0f) { ctx->vu0_q = 1.0f / sqrtf(ft); } else { uint32_t maxf = 0x7F7FFFFFu; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x1997c8: 0x4a0003bf  vwaitq
    ctx->pc = 0x1997c8u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x1997cc: 0x4bc0511c  vmulq.xyz   $vf4, $vf10, $Q
    ctx->pc = 0x1997ccu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1997d0: 0xd8670000  lqc2        $vf7, 0x0($v1)
    ctx->pc = 0x1997d0u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1997d4: 0xd8680010  lqc2        $vf8, 0x10($v1)
    ctx->pc = 0x1997d4u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1997d8: 0xd8690020  lqc2        $vf9, 0x20($v1)
    ctx->pc = 0x1997d8u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1997dc: 0xd86a0030  lqc2        $vf10, 0x30($v1)
    ctx->pc = 0x1997dcu;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x1997e0: 0xda0b0010  lqc2        $vf11, 0x10($s0)
    ctx->pc = 0x1997e0u;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1997e4: 0xda0c0020  lqc2        $vf12, 0x20($s0)
    ctx->pc = 0x1997e4u;
    ctx->vu0_vf[12] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1997e8: 0x4beb39bc  vmulax.xyzw $ACC, $vf7, $vf11x
    ctx->pc = 0x1997e8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x1997ec: 0x4beb40bd  vmadday.xyzw $ACC, $vf8, $vf11y
    ctx->pc = 0x1997ecu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1997f0: 0x4beb48be  vmaddaz.xyzw $ACC, $vf9, $vf11z
    ctx->pc = 0x1997f0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1997f4: 0x4beb514b  vmaddw.xyzw $vf5, $vf10, $vf11w
    ctx->pc = 0x1997f4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[11], ctx->vu0_vf[11], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x1997f8: 0x4bec39bc  vmulax.xyzw $ACC, $vf7, $vf12x
    ctx->pc = 0x1997f8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x1997fc: 0x4bec40bd  vmadday.xyzw $ACC, $vf8, $vf12y
    ctx->pc = 0x1997fcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x199800: 0x4bec48be  vmaddaz.xyzw $ACC, $vf9, $vf12z
    ctx->pc = 0x199800u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x199804: 0x4bec518b  vmaddw.xyzw $vf6, $vf10, $vf12w
    ctx->pc = 0x199804u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[12], ctx->vu0_vf[12], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x199808: 0x4b0401c0  vaddx.x     $vf7, $vf0, $vf4x
    ctx->pc = 0x199808u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x19980c: 0x4b040201  vaddy.x     $vf8, $vf0, $vf4y
    ctx->pc = 0x19980cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x199810: 0x4b040242  vaddz.x     $vf9, $vf0, $vf4z
    ctx->pc = 0x199810u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x199814: 0x4a8501c0  vaddx.y     $vf7, $vf0, $vf5x
    ctx->pc = 0x199814u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x199818: 0x4a850201  vaddy.y     $vf8, $vf0, $vf5y
    ctx->pc = 0x199818u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x19981c: 0x4a850242  vaddz.y     $vf9, $vf0, $vf5z
    ctx->pc = 0x19981cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x199820: 0x4a4601c0  vaddx.z     $vf7, $vf0, $vf6x
    ctx->pc = 0x199820u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x199824: 0x4a460201  vaddy.z     $vf8, $vf0, $vf6y
    ctx->pc = 0x199824u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x199828: 0x4a460242  vaddz.z     $vf9, $vf0, $vf6z
    ctx->pc = 0x199828u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x19982c: 0xfa670000  sqc2        $vf7, 0x0($s3)
    ctx->pc = 0x19982cu;
    WRITE128(ADD32(GPR_U32(ctx, 19), 0), _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x199830: 0xfa680010  sqc2        $vf8, 0x10($s3)
    ctx->pc = 0x199830u;
    WRITE128(ADD32(GPR_U32(ctx, 19), 16), _mm_castps_si128(ctx->vu0_vf[8]));
    // 0x199834: 0xfa690020  sqc2        $vf9, 0x20($s3)
    ctx->pc = 0x199834u;
    WRITE128(ADD32(GPR_U32(ctx, 19), 32), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x199838: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x199838u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x19983c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19983cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199840: 0xc42041ec  lwc1        $f0, 0x41EC($at)
    ctx->pc = 0x199840u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16876)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199844: 0xe6400004  swc1        $f0, 0x4($s2)
    ctx->pc = 0x199844u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 4), bits); }
    // 0x199848: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199848u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19984c: 0xc42041f0  lwc1        $f0, 0x41F0($at)
    ctx->pc = 0x19984cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16880)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199850: 0xe6400008  swc1        $f0, 0x8($s2)
    ctx->pc = 0x199850u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 8), bits); }
    // 0x199854: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x199854u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x199858: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x199858u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19985c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19985cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x199860: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x199860u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x199864: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x199864u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x199868: 0x3e00008  jr          $ra
    ctx->pc = 0x199868u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19986Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199868u;
            // 0x19986c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199774u: goto label_199774;
            default: break;
        }
        return;
    }
    ctx->pc = 0x199870u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

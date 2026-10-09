#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001996A0
// Address: 0x1996a0 - 0x199740
void sub_001996A0_0x1996a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001996A0_0x1996a0");
#endif

    switch (ctx->pc) {
        case 0x1996ccu: goto label_1996cc;
        default: break;
    }

    ctx->pc = 0x1996a0u;

    // 0x1996a0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1996a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1996a4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1996a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1996a8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1996a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1996ac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1996acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1996b0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1996b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1996b4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1996b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1996b8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1996b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1996bc: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x1996bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1996c0: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1996c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1996c4: 0xc06450c  jal         func_191430
    ctx->pc = 0x1996C4u;
    SET_GPR_U32(ctx, 31, 0x1996CCu);
    ctx->pc = 0x1996C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1996C4u;
            // 0x1996c8: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191430u;
    if (runtime->hasFunction(0x191430u)) {
        auto targetFn = runtime->lookupFunction(0x191430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1996CCu; }
        if (ctx->pc != 0x1996CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191430_0x191430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1996CCu; }
        if (ctx->pc != 0x1996CCu) { return; }
    }
    ctx->pc = 0x1996CCu;
label_1996cc:
    // 0x1996cc: 0x27a30040  addiu       $v1, $sp, 0x40
    ctx->pc = 0x1996ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1996d0: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x1996d0u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1996d4: 0xd8650000  lqc2        $vf5, 0x0($v1)
    ctx->pc = 0x1996d4u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1996d8: 0xd8660010  lqc2        $vf6, 0x10($v1)
    ctx->pc = 0x1996d8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1996dc: 0xd8670020  lqc2        $vf7, 0x20($v1)
    ctx->pc = 0x1996dcu;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1996e0: 0xd8680030  lqc2        $vf8, 0x30($v1)
    ctx->pc = 0x1996e0u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x1996e4: 0x4be429bc  vmulax.xyzw $ACC, $vf5, $vf4x
    ctx->pc = 0x1996e4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1996e8: 0x4be430bd  vmadday.xyzw $ACC, $vf6, $vf4y
    ctx->pc = 0x1996e8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1996ec: 0x4be438be  vmaddaz.xyzw $ACC, $vf7, $vf4z
    ctx->pc = 0x1996ecu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1996f0: 0x4be4410b  vmaddw.xyzw $vf4, $vf8, $vf4w
    ctx->pc = 0x1996f0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1996f4: 0x4be5033c  vmove.xyzw  $vf5, $vf0
    ctx->pc = 0x1996f4u;
    ctx->vu0_vf[5] = ctx->vu0_vf[0];
    // 0x1996f8: 0x4be6033c  vmove.xyzw  $vf6, $vf0
    ctx->pc = 0x1996f8u;
    ctx->vu0_vf[6] = ctx->vu0_vf[0];
    // 0x1996fc: 0x4be7033c  vmove.xyzw  $vf7, $vf0
    ctx->pc = 0x1996fcu;
    ctx->vu0_vf[7] = ctx->vu0_vf[0];
    // 0x199700: 0x4b042940  vaddx.x     $vf5, $vf5, $vf4x
    ctx->pc = 0x199700u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x199704: 0x4b043181  vaddy.x     $vf6, $vf6, $vf4y
    ctx->pc = 0x199704u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x199708: 0x4b0439c2  vaddz.x     $vf7, $vf7, $vf4z
    ctx->pc = 0x199708u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x19970c: 0xfa450000  sqc2        $vf5, 0x0($s2)
    ctx->pc = 0x19970cu;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x199710: 0xfa460010  sqc2        $vf6, 0x10($s2)
    ctx->pc = 0x199710u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 16), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x199714: 0xfa470020  sqc2        $vf7, 0x20($s2)
    ctx->pc = 0x199714u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 32), _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x199718: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199718u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19971c: 0xc42041e8  lwc1        $f0, 0x41E8($at)
    ctx->pc = 0x19971cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16872)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199720: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x199720u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x199724: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x199724u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x199728: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x199728u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19972c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19972cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x199730: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x199730u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x199734: 0x3e00008  jr          $ra
    ctx->pc = 0x199734u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x199738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199734u;
            // 0x199738: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1996CCu: goto label_1996cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19973Cu;
    // 0x19973c: 0x0  nop
    ctx->pc = 0x19973cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

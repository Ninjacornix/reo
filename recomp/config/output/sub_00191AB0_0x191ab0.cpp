#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191AB0
// Address: 0x191ab0 - 0x191d10
void sub_00191AB0_0x191ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191AB0_0x191ab0");
#endif

    switch (ctx->pc) {
        case 0x191b78u: goto label_191b78;
        case 0x191bf8u: goto label_191bf8;
        case 0x191c78u: goto label_191c78;
        default: break;
    }

    ctx->pc = 0x191ab0u;

    // 0x191ab0: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x191ab0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191ab4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x191ab4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x191ab8: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x191ab8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x191abc: 0x27a70000  addiu       $a3, $sp, 0x0
    ctx->pc = 0x191abcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191ac0: 0xe7a00000  swc1        $f0, 0x0($sp)
    ctx->pc = 0x191ac0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x191ac4: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x191ac4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191ac8: 0xe7a00004  swc1        $f0, 0x4($sp)
    ctx->pc = 0x191ac8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x191acc: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x191accu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191ad0: 0xe7a00008  swc1        $f0, 0x8($sp)
    ctx->pc = 0x191ad0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x191ad4: 0xafa3000c  sw          $v1, 0xC($sp)
    ctx->pc = 0x191ad4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
    // 0x191ad8: 0xd8e40000  lqc2        $vf4, 0x0($a3)
    ctx->pc = 0x191ad8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x191adc: 0xd8c50000  lqc2        $vf5, 0x0($a2)
    ctx->pc = 0x191adcu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x191ae0: 0xd8c60010  lqc2        $vf6, 0x10($a2)
    ctx->pc = 0x191ae0u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x191ae4: 0xd8c70020  lqc2        $vf7, 0x20($a2)
    ctx->pc = 0x191ae4u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x191ae8: 0xd8c80030  lqc2        $vf8, 0x30($a2)
    ctx->pc = 0x191ae8u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 48)));
    // 0x191aec: 0x4be429bc  vmulax.xyzw $ACC, $vf5, $vf4x
    ctx->pc = 0x191aecu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191af0: 0x4be430bd  vmadday.xyzw $ACC, $vf6, $vf4y
    ctx->pc = 0x191af0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191af4: 0x4be438be  vmaddaz.xyzw $ACC, $vf7, $vf4z
    ctx->pc = 0x191af4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x191af8: 0x4be4410b  vmaddw.xyzw $vf4, $vf8, $vf4w
    ctx->pc = 0x191af8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191afc: 0x4be403bc  vdiv        $Q, $vf0w, $vf4w
    ctx->pc = 0x191afcu;
    { float fs = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,3))); float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,3))); if (ft != 0.0f) { ctx->vu0_q = fs / ft; } else { uint32_t sign = (std::bit_cast<uint32_t>(fs) ^ std::bit_cast<uint32_t>(ft)) & 0x80000000u; uint32_t maxf = 0x7F7FFFFFu | sign; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x191b00: 0x4a0003bf  vwaitq
    ctx->pc = 0x191b00u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x191b04: 0x4bc0211c  vmulq.xyz   $vf4, $vf4, $Q
    ctx->pc = 0x191b04u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191b08: 0xf8e40000  sqc2        $vf4, 0x0($a3)
    ctx->pc = 0x191b08u;
    WRITE128(ADD32(GPR_U32(ctx, 7), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191b0c: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x191b0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191b10: 0xc4630000  lwc1        $f3, 0x0($v1)
    ctx->pc = 0x191b10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x191b14: 0xc4620004  lwc1        $f2, 0x4($v1)
    ctx->pc = 0x191b14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191b18: 0xc4610008  lwc1        $f1, 0x8($v1)
    ctx->pc = 0x191b18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191b1c: 0xc460000c  lwc1        $f0, 0xC($v1)
    ctx->pc = 0x191b1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191b20: 0xe4830000  swc1        $f3, 0x0($a0)
    ctx->pc = 0x191b20u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x191b24: 0xe4820004  swc1        $f2, 0x4($a0)
    ctx->pc = 0x191b24u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x191b28: 0xe4810008  swc1        $f1, 0x8($a0)
    ctx->pc = 0x191b28u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x191b2c: 0xe480000c  swc1        $f0, 0xC($a0)
    ctx->pc = 0x191b2cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 12), bits); }
    // 0x191b30: 0x3e00008  jr          $ra
    ctx->pc = 0x191B30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191B30u;
            // 0x191b34: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191B78u: goto label_191b78;
            case 0x191BF8u: goto label_191bf8;
            case 0x191C78u: goto label_191c78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191B38u;
    // 0x191b38: 0x0  nop
    ctx->pc = 0x191b38u;
    // NOP
    // 0x191b3c: 0x0  nop
    ctx->pc = 0x191b3cu;
    // NOP
    // 0x191b40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x191b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x191b44: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x191b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x191b48: 0x27a20028  addiu       $v0, $sp, 0x28
    ctx->pc = 0x191b48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x191b4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191b4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x191b50: 0x27a50038  addiu       $a1, $sp, 0x38
    ctx->pc = 0x191b50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x191b54: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191b54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191b58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x191b58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191b5c: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191b5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191b60: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191b60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191b64: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x191b64u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x191b68: 0x27a4003c  addiu       $a0, $sp, 0x3C
    ctx->pc = 0x191b68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x191b6c: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x191b6cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x191b70: 0xc06486c  jal         func_1921B0
    ctx->pc = 0x191B70u;
    SET_GPR_U32(ctx, 31, 0x191B78u);
    ctx->pc = 0x191B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191B70u;
            // 0x191b74: 0xe4400008  swc1        $f0, 0x8($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1921B0u;
    if (runtime->hasFunction(0x1921B0u)) {
        auto targetFn = runtime->lookupFunction(0x1921B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191B78u; }
        if (ctx->pc != 0x191B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001921B0_0x1921b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191B78u; }
        if (ctx->pc != 0x191B78u) { return; }
    }
    ctx->pc = 0x191B78u;
label_191b78:
    // 0x191b78: 0xc7a2002c  lwc1        $f2, 0x2C($sp)
    ctx->pc = 0x191b78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191b7c: 0xc7a10038  lwc1        $f1, 0x38($sp)
    ctx->pc = 0x191b7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191b80: 0xc7a30030  lwc1        $f3, 0x30($sp)
    ctx->pc = 0x191b80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x191b84: 0xc7a0003c  lwc1        $f0, 0x3C($sp)
    ctx->pc = 0x191b84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191b88: 0x4602081a  mula.s      $f1, $f2
    ctx->pc = 0x191b88u;
    ctx->f[31] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x191b8c: 0x4603001d  msub.s      $f0, $f0, $f3
    ctx->pc = 0x191b8cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191b90: 0xe6000004  swc1        $f0, 0x4($s0)
    ctx->pc = 0x191b90u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 4), bits); }
    // 0x191b94: 0xc7a1003c  lwc1        $f1, 0x3C($sp)
    ctx->pc = 0x191b94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191b98: 0xc7a00038  lwc1        $f0, 0x38($sp)
    ctx->pc = 0x191b98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191b9c: 0x4602081a  mula.s      $f1, $f2
    ctx->pc = 0x191b9cu;
    ctx->f[31] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x191ba0: 0x4603001c  madd.s      $f0, $f0, $f3
    ctx->pc = 0x191ba0u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191ba4: 0xe6000008  swc1        $f0, 0x8($s0)
    ctx->pc = 0x191ba4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x191ba8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x191ba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x191bac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x191bacu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191bb0: 0x3e00008  jr          $ra
    ctx->pc = 0x191BB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191BB0u;
            // 0x191bb4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191B78u: goto label_191b78;
            case 0x191BF8u: goto label_191bf8;
            case 0x191C78u: goto label_191c78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191BB8u;
    // 0x191bb8: 0x0  nop
    ctx->pc = 0x191bb8u;
    // NOP
    // 0x191bbc: 0x0  nop
    ctx->pc = 0x191bbcu;
    // NOP
    // 0x191bc0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x191bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x191bc4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x191bc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x191bc8: 0x27a20028  addiu       $v0, $sp, 0x28
    ctx->pc = 0x191bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x191bcc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191bccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x191bd0: 0x27a50038  addiu       $a1, $sp, 0x38
    ctx->pc = 0x191bd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x191bd4: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191bd4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191bd8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x191bd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191bdc: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191bdcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191be0: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191be0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191be4: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x191be4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x191be8: 0x27a4003c  addiu       $a0, $sp, 0x3C
    ctx->pc = 0x191be8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x191bec: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x191becu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x191bf0: 0xc06486c  jal         func_1921B0
    ctx->pc = 0x191BF0u;
    SET_GPR_U32(ctx, 31, 0x191BF8u);
    ctx->pc = 0x191BF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191BF0u;
            // 0x191bf4: 0xe4400008  swc1        $f0, 0x8($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1921B0u;
    if (runtime->hasFunction(0x1921B0u)) {
        auto targetFn = runtime->lookupFunction(0x1921B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191BF8u; }
        if (ctx->pc != 0x191BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001921B0_0x1921b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191BF8u; }
        if (ctx->pc != 0x191BF8u) { return; }
    }
    ctx->pc = 0x191BF8u;
label_191bf8:
    // 0x191bf8: 0xc7a20038  lwc1        $f2, 0x38($sp)
    ctx->pc = 0x191bf8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191bfc: 0xc7a10028  lwc1        $f1, 0x28($sp)
    ctx->pc = 0x191bfcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c00: 0xc7a30030  lwc1        $f3, 0x30($sp)
    ctx->pc = 0x191c00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x191c04: 0xc7a0003c  lwc1        $f0, 0x3C($sp)
    ctx->pc = 0x191c04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191c08: 0x4601101a  mula.s      $f2, $f1
    ctx->pc = 0x191c08u;
    ctx->f[31] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x191c0c: 0x4603001c  madd.s      $f0, $f0, $f3
    ctx->pc = 0x191c0cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191c10: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x191c10u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x191c14: 0xc7a2003c  lwc1        $f2, 0x3C($sp)
    ctx->pc = 0x191c14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191c18: 0xc7a10028  lwc1        $f1, 0x28($sp)
    ctx->pc = 0x191c18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c1c: 0xc7a00038  lwc1        $f0, 0x38($sp)
    ctx->pc = 0x191c1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191c20: 0x46001087  neg.s       $f2, $f2
    ctx->pc = 0x191c20u;
    ctx->f[2] = FPU_NEG_S(ctx->f[2]);
    // 0x191c24: 0x4601101a  mula.s      $f2, $f1
    ctx->pc = 0x191c24u;
    ctx->f[31] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x191c28: 0x4603001c  madd.s      $f0, $f0, $f3
    ctx->pc = 0x191c28u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191c2c: 0xe6000008  swc1        $f0, 0x8($s0)
    ctx->pc = 0x191c2cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x191c30: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x191c30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x191c34: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x191c34u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191c38: 0x3e00008  jr          $ra
    ctx->pc = 0x191C38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191C38u;
            // 0x191c3c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191B78u: goto label_191b78;
            case 0x191BF8u: goto label_191bf8;
            case 0x191C78u: goto label_191c78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191C40u;
    // 0x191c40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x191c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x191c44: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x191c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x191c48: 0x27a20028  addiu       $v0, $sp, 0x28
    ctx->pc = 0x191c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x191c4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191c4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x191c50: 0x27a50038  addiu       $a1, $sp, 0x38
    ctx->pc = 0x191c50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x191c54: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191c54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191c58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x191c58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191c5c: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191c5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c60: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191c60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191c64: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x191c64u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x191c68: 0x27a4003c  addiu       $a0, $sp, 0x3C
    ctx->pc = 0x191c68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x191c6c: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x191c6cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x191c70: 0xc06486c  jal         func_1921B0
    ctx->pc = 0x191C70u;
    SET_GPR_U32(ctx, 31, 0x191C78u);
    ctx->pc = 0x191C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191C70u;
            // 0x191c74: 0xe4400008  swc1        $f0, 0x8($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1921B0u;
    if (runtime->hasFunction(0x1921B0u)) {
        auto targetFn = runtime->lookupFunction(0x1921B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191C78u; }
        if (ctx->pc != 0x191C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001921B0_0x1921b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191C78u; }
        if (ctx->pc != 0x191C78u) { return; }
    }
    ctx->pc = 0x191C78u;
label_191c78:
    // 0x191c78: 0xc7a20038  lwc1        $f2, 0x38($sp)
    ctx->pc = 0x191c78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191c7c: 0xc7a10028  lwc1        $f1, 0x28($sp)
    ctx->pc = 0x191c7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c80: 0xc7a3002c  lwc1        $f3, 0x2C($sp)
    ctx->pc = 0x191c80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x191c84: 0xc7a0003c  lwc1        $f0, 0x3C($sp)
    ctx->pc = 0x191c84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191c88: 0x4601101a  mula.s      $f2, $f1
    ctx->pc = 0x191c88u;
    ctx->f[31] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x191c8c: 0x4603001d  msub.s      $f0, $f0, $f3
    ctx->pc = 0x191c8cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191c90: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x191c90u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x191c94: 0xc7a2003c  lwc1        $f2, 0x3C($sp)
    ctx->pc = 0x191c94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191c98: 0xc7a10028  lwc1        $f1, 0x28($sp)
    ctx->pc = 0x191c98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c9c: 0xc7a00038  lwc1        $f0, 0x38($sp)
    ctx->pc = 0x191c9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191ca0: 0x4601101a  mula.s      $f2, $f1
    ctx->pc = 0x191ca0u;
    ctx->f[31] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x191ca4: 0x4603001c  madd.s      $f0, $f0, $f3
    ctx->pc = 0x191ca4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191ca8: 0xe6000004  swc1        $f0, 0x4($s0)
    ctx->pc = 0x191ca8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 4), bits); }
    // 0x191cac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x191cacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x191cb0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x191cb0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191cb4: 0x3e00008  jr          $ra
    ctx->pc = 0x191CB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191CB4u;
            // 0x191cb8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191B78u: goto label_191b78;
            case 0x191BF8u: goto label_191bf8;
            case 0x191C78u: goto label_191c78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191CBCu;
    // 0x191cbc: 0x0  nop
    ctx->pc = 0x191cbcu;
    // NOP
    // 0x191cc0: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191cc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191cc4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x191cc4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x191cc8: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191cc8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191ccc: 0x27a20000  addiu       $v0, $sp, 0x0
    ctx->pc = 0x191cccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191cd0: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191cd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191cd4: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x191cd4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x191cd8: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x191cd8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x191cdc: 0xe4400008  swc1        $f0, 0x8($v0)
    ctx->pc = 0x191cdcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
    // 0x191ce0: 0xd8440000  lqc2        $vf4, 0x0($v0)
    ctx->pc = 0x191ce0u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x191ce4: 0x4bc4212a  vmul.xyz    $vf4, $vf4, $vf4
    ctx->pc = 0x191ce4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191ce8: 0x4b042101  vaddy.x     $vf4, $vf4, $vf4y
    ctx->pc = 0x191ce8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191cec: 0x4b042102  vaddz.x     $vf4, $vf4, $vf4z
    ctx->pc = 0x191cecu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191cf0: 0x4a0403bd  .word       0x4A0403BD                   # vsqrt       $Q, $vf4x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>
    ctx->pc = 0x191cf0u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_q = sqrtf(std::max(0.0f, ft)); }
    // 0x191cf4: 0x4a0003bf  vwaitq
    ctx->pc = 0x191cf4u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x191cf8: 0x4b000120  vaddq.x     $vf4, $vf0, $Q
    ctx->pc = 0x191cf8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191cfc: 0x48222000  qmfc2.ni    $v0, $vf4
    ctx->pc = 0x191cfcu;
    SET_GPR_VEC(ctx, 2, _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191d00: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x191d00u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191d04: 0x3e00008  jr          $ra
    ctx->pc = 0x191D04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191D04u;
            // 0x191d08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191B78u: goto label_191b78;
            case 0x191BF8u: goto label_191bf8;
            case 0x191C78u: goto label_191c78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191D0Cu;
    // 0x191d0c: 0x0  nop
    ctx->pc = 0x191d0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001919D0
// Address: 0x1919d0 - 0x191ab0
void sub_001919D0_0x1919d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001919D0_0x1919d0");
#endif

    ctx->pc = 0x1919d0u;

    // 0x1919d0: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x1919d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1919d4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1919d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1919d8: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x1919d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1919dc: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x1919dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x1919e0: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x1919e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1919e4: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x1919e4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x1919e8: 0xe4610004  swc1        $f1, 0x4($v1)
    ctx->pc = 0x1919e8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x1919ec: 0xe4600008  swc1        $f0, 0x8($v1)
    ctx->pc = 0x1919ecu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 8), bits); }
    // 0x1919f0: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x1919f0u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1919f4: 0xd8c50000  lqc2        $vf5, 0x0($a2)
    ctx->pc = 0x1919f4u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1919f8: 0xd8c60010  lqc2        $vf6, 0x10($a2)
    ctx->pc = 0x1919f8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x1919fc: 0xd8c70020  lqc2        $vf7, 0x20($a2)
    ctx->pc = 0x1919fcu;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x191a00: 0x4bc429bc  vmulax.xyz  $ACC, $vf5, $vf4x
    ctx->pc = 0x191a00u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x191a04: 0x4bc430bd  vmadday.xyz $ACC, $vf6, $vf4y
    ctx->pc = 0x191a04u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x191a08: 0x4bc4390a  vmaddz.xyz  $vf4, $vf7, $vf4z
    ctx->pc = 0x191a08u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x191a0c: 0xf8640000  sqc2        $vf4, 0x0($v1)
    ctx->pc = 0x191a0cu;
    WRITE128(ADD32(GPR_U32(ctx, 3), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191a10: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x191a10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191a14: 0xc4620000  lwc1        $f2, 0x0($v1)
    ctx->pc = 0x191a14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191a18: 0xc4610004  lwc1        $f1, 0x4($v1)
    ctx->pc = 0x191a18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191a1c: 0xc4600008  lwc1        $f0, 0x8($v1)
    ctx->pc = 0x191a1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191a20: 0xe4820000  swc1        $f2, 0x0($a0)
    ctx->pc = 0x191a20u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x191a24: 0xe4810004  swc1        $f1, 0x4($a0)
    ctx->pc = 0x191a24u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x191a28: 0xe4800008  swc1        $f0, 0x8($a0)
    ctx->pc = 0x191a28u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x191a2c: 0x3e00008  jr          $ra
    ctx->pc = 0x191A2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191A2Cu;
            // 0x191a30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x191A34u;
    // 0x191a34: 0x0  nop
    ctx->pc = 0x191a34u;
    // NOP
    // 0x191a38: 0x0  nop
    ctx->pc = 0x191a38u;
    // NOP
    // 0x191a3c: 0x0  nop
    ctx->pc = 0x191a3cu;
    // NOP
    // 0x191a40: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191a40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191a44: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x191a44u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x191a48: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191a48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191a4c: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x191a4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191a50: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191a50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191a54: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x191a54u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x191a58: 0xe4610004  swc1        $f1, 0x4($v1)
    ctx->pc = 0x191a58u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x191a5c: 0xe4600008  swc1        $f0, 0x8($v1)
    ctx->pc = 0x191a5cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 8), bits); }
    // 0x191a60: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x191a60u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x191a64: 0xd8a50000  lqc2        $vf5, 0x0($a1)
    ctx->pc = 0x191a64u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x191a68: 0xd8a60010  lqc2        $vf6, 0x10($a1)
    ctx->pc = 0x191a68u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x191a6c: 0xd8a70020  lqc2        $vf7, 0x20($a1)
    ctx->pc = 0x191a6cu;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x191a70: 0x4bc429bc  vmulax.xyz  $ACC, $vf5, $vf4x
    ctx->pc = 0x191a70u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x191a74: 0x4bc430bd  vmadday.xyz $ACC, $vf6, $vf4y
    ctx->pc = 0x191a74u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x191a78: 0x4bc4390a  vmaddz.xyz  $vf4, $vf7, $vf4z
    ctx->pc = 0x191a78u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x191a7c: 0xf8640000  sqc2        $vf4, 0x0($v1)
    ctx->pc = 0x191a7cu;
    WRITE128(ADD32(GPR_U32(ctx, 3), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191a80: 0x27a30000  addiu       $v1, $sp, 0x0
    ctx->pc = 0x191a80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191a84: 0xc4620000  lwc1        $f2, 0x0($v1)
    ctx->pc = 0x191a84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191a88: 0xc4610004  lwc1        $f1, 0x4($v1)
    ctx->pc = 0x191a88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191a8c: 0xc4600008  lwc1        $f0, 0x8($v1)
    ctx->pc = 0x191a8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191a90: 0xe4820000  swc1        $f2, 0x0($a0)
    ctx->pc = 0x191a90u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x191a94: 0xe4810004  swc1        $f1, 0x4($a0)
    ctx->pc = 0x191a94u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x191a98: 0xe4800008  swc1        $f0, 0x8($a0)
    ctx->pc = 0x191a98u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x191a9c: 0x3e00008  jr          $ra
    ctx->pc = 0x191A9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191A9Cu;
            // 0x191aa0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x191AA4u;
    // 0x191aa4: 0x0  nop
    ctx->pc = 0x191aa4u;
    // NOP
    // 0x191aa8: 0x0  nop
    ctx->pc = 0x191aa8u;
    // NOP
    // 0x191aac: 0x0  nop
    ctx->pc = 0x191aacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

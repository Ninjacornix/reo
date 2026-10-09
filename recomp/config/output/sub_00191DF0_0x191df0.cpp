#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191DF0
// Address: 0x191df0 - 0x191e50
void sub_00191DF0_0x191df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191DF0_0x191df0");
#endif

    ctx->pc = 0x191df0u;

    // 0x191df0: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191df0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191df4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x191df4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x191df8: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191df8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191dfc: 0x27a30010  addiu       $v1, $sp, 0x10
    ctx->pc = 0x191dfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x191e00: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191e00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191e04: 0x27a20000  addiu       $v0, $sp, 0x0
    ctx->pc = 0x191e04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x191e08: 0xe4620000  swc1        $f2, 0x0($v1)
    ctx->pc = 0x191e08u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x191e0c: 0xe4610004  swc1        $f1, 0x4($v1)
    ctx->pc = 0x191e0cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x191e10: 0xe4600008  swc1        $f0, 0x8($v1)
    ctx->pc = 0x191e10u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 8), bits); }
    // 0x191e14: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x191e14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191e18: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x191e18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191e1c: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x191e1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191e20: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x191e20u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x191e24: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x191e24u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x191e28: 0xe4400008  swc1        $f0, 0x8($v0)
    ctx->pc = 0x191e28u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
    // 0x191e2c: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x191e2cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x191e30: 0xd8450000  lqc2        $vf5, 0x0($v0)
    ctx->pc = 0x191e30u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x191e34: 0x4bc5212a  vmul.xyz    $vf4, $vf4, $vf5
    ctx->pc = 0x191e34u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191e38: 0x4b042101  vaddy.x     $vf4, $vf4, $vf4y
    ctx->pc = 0x191e38u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191e3c: 0x4b042102  vaddz.x     $vf4, $vf4, $vf4z
    ctx->pc = 0x191e3cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191e40: 0x48232000  qmfc2.ni    $v1, $vf4
    ctx->pc = 0x191e40u;
    SET_GPR_VEC(ctx, 3, _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191e44: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x191e44u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x191e48: 0x3e00008  jr          $ra
    ctx->pc = 0x191E48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191E48u;
            // 0x191e4c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x191E50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

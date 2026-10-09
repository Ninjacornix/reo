#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00199A90
// Address: 0x199a90 - 0x199c20
void sub_00199A90_0x199a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00199A90_0x199a90");
#endif

    ctx->pc = 0x199a90u;

    // 0x199a90: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x199a90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x199a94: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x199a94u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x199a98: 0x24634204  addiu       $v1, $v1, 0x4204
    ctx->pc = 0x199a98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16900));
    // 0x199a9c: 0x3c0d0029  lui         $t5, 0x29
    ctx->pc = 0x199a9cu;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)41 << 16));
    // 0x199aa0: 0xc4630000  lwc1        $f3, 0x0($v1)
    ctx->pc = 0x199aa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199aa4: 0x3c0b0029  lui         $t3, 0x29
    ctx->pc = 0x199aa4u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)41 << 16));
    // 0x199aa8: 0xc4620004  lwc1        $f2, 0x4($v1)
    ctx->pc = 0x199aa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199aac: 0x3c090029  lui         $t1, 0x29
    ctx->pc = 0x199aacu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)41 << 16));
    // 0x199ab0: 0xc4610008  lwc1        $f1, 0x8($v1)
    ctx->pc = 0x199ab0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199ab4: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x199ab4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x199ab8: 0xc460000c  lwc1        $f0, 0xC($v1)
    ctx->pc = 0x199ab8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199abc: 0x27ae0000  addiu       $t6, $sp, 0x0
    ctx->pc = 0x199abcu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 29), 0));
    // 0x199ac0: 0x3c050029  lui         $a1, 0x29
    ctx->pc = 0x199ac0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)41 << 16));
    // 0x199ac4: 0x25ad4224  addiu       $t5, $t5, 0x4224
    ctx->pc = 0x199ac4u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 16932));
    // 0x199ac8: 0x27ac0010  addiu       $t4, $sp, 0x10
    ctx->pc = 0x199ac8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x199acc: 0x256b426c  addiu       $t3, $t3, 0x426C
    ctx->pc = 0x199accu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 17004));
    // 0x199ad0: 0x27aa0020  addiu       $t2, $sp, 0x20
    ctx->pc = 0x199ad0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x199ad4: 0x2529428c  addiu       $t1, $t1, 0x428C
    ctx->pc = 0x199ad4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 17036));
    // 0x199ad8: 0x27a80030  addiu       $t0, $sp, 0x30
    ctx->pc = 0x199ad8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x199adc: 0x24e742d4  addiu       $a3, $a3, 0x42D4
    ctx->pc = 0x199adcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 17108));
    // 0x199ae0: 0x27a60040  addiu       $a2, $sp, 0x40
    ctx->pc = 0x199ae0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x199ae4: 0x24a542f4  addiu       $a1, $a1, 0x42F4
    ctx->pc = 0x199ae4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17140));
    // 0x199ae8: 0xe5c30000  swc1        $f3, 0x0($t6)
    ctx->pc = 0x199ae8u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 14), 0), bits); }
    // 0x199aec: 0x27a30050  addiu       $v1, $sp, 0x50
    ctx->pc = 0x199aecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x199af0: 0xe5c20004  swc1        $f2, 0x4($t6)
    ctx->pc = 0x199af0u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 14), 4), bits); }
    // 0x199af4: 0xe5c10008  swc1        $f1, 0x8($t6)
    ctx->pc = 0x199af4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 14), 8), bits); }
    // 0x199af8: 0xe5c0000c  swc1        $f0, 0xC($t6)
    ctx->pc = 0x199af8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 14), 12), bits); }
    // 0x199afc: 0xc5a30000  lwc1        $f3, 0x0($t5)
    ctx->pc = 0x199afcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 13), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199b00: 0xc5a20004  lwc1        $f2, 0x4($t5)
    ctx->pc = 0x199b00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 13), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199b04: 0xc5a10008  lwc1        $f1, 0x8($t5)
    ctx->pc = 0x199b04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 13), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199b08: 0xc5a0000c  lwc1        $f0, 0xC($t5)
    ctx->pc = 0x199b08u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 13), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199b0c: 0xe5830000  swc1        $f3, 0x0($t4)
    ctx->pc = 0x199b0cu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 12), 0), bits); }
    // 0x199b10: 0xe5820004  swc1        $f2, 0x4($t4)
    ctx->pc = 0x199b10u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 12), 4), bits); }
    // 0x199b14: 0xe5810008  swc1        $f1, 0x8($t4)
    ctx->pc = 0x199b14u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 12), 8), bits); }
    // 0x199b18: 0xe580000c  swc1        $f0, 0xC($t4)
    ctx->pc = 0x199b18u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 12), 12), bits); }
    // 0x199b1c: 0xc5630000  lwc1        $f3, 0x0($t3)
    ctx->pc = 0x199b1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 11), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199b20: 0xc5620004  lwc1        $f2, 0x4($t3)
    ctx->pc = 0x199b20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 11), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199b24: 0xc5610008  lwc1        $f1, 0x8($t3)
    ctx->pc = 0x199b24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 11), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199b28: 0xc560000c  lwc1        $f0, 0xC($t3)
    ctx->pc = 0x199b28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 11), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199b2c: 0xe5430000  swc1        $f3, 0x0($t2)
    ctx->pc = 0x199b2cu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 0), bits); }
    // 0x199b30: 0xe5420004  swc1        $f2, 0x4($t2)
    ctx->pc = 0x199b30u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 4), bits); }
    // 0x199b34: 0xe5410008  swc1        $f1, 0x8($t2)
    ctx->pc = 0x199b34u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 8), bits); }
    // 0x199b38: 0xe540000c  swc1        $f0, 0xC($t2)
    ctx->pc = 0x199b38u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 10), 12), bits); }
    // 0x199b3c: 0xc5230000  lwc1        $f3, 0x0($t1)
    ctx->pc = 0x199b3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199b40: 0xc5220004  lwc1        $f2, 0x4($t1)
    ctx->pc = 0x199b40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199b44: 0xc5210008  lwc1        $f1, 0x8($t1)
    ctx->pc = 0x199b44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199b48: 0xc520000c  lwc1        $f0, 0xC($t1)
    ctx->pc = 0x199b48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199b4c: 0xe5030000  swc1        $f3, 0x0($t0)
    ctx->pc = 0x199b4cu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 0), bits); }
    // 0x199b50: 0xe5020004  swc1        $f2, 0x4($t0)
    ctx->pc = 0x199b50u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 4), bits); }
    // 0x199b54: 0xe5010008  swc1        $f1, 0x8($t0)
    ctx->pc = 0x199b54u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 8), bits); }
    // 0x199b58: 0xe500000c  swc1        $f0, 0xC($t0)
    ctx->pc = 0x199b58u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 8), 12), bits); }
    // 0x199b5c: 0xc4e30000  lwc1        $f3, 0x0($a3)
    ctx->pc = 0x199b5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199b60: 0xc4e20004  lwc1        $f2, 0x4($a3)
    ctx->pc = 0x199b60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199b64: 0xc4e10008  lwc1        $f1, 0x8($a3)
    ctx->pc = 0x199b64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199b68: 0xc4e0000c  lwc1        $f0, 0xC($a3)
    ctx->pc = 0x199b68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199b6c: 0xe4c30000  swc1        $f3, 0x0($a2)
    ctx->pc = 0x199b6cu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 0), bits); }
    // 0x199b70: 0xe4c20004  swc1        $f2, 0x4($a2)
    ctx->pc = 0x199b70u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 4), bits); }
    // 0x199b74: 0xe4c10008  swc1        $f1, 0x8($a2)
    ctx->pc = 0x199b74u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 8), bits); }
    // 0x199b78: 0xe4c0000c  swc1        $f0, 0xC($a2)
    ctx->pc = 0x199b78u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 12), bits); }
    // 0x199b7c: 0xc4a30000  lwc1        $f3, 0x0($a1)
    ctx->pc = 0x199b7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199b80: 0xc4a20004  lwc1        $f2, 0x4($a1)
    ctx->pc = 0x199b80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199b84: 0xc4a10008  lwc1        $f1, 0x8($a1)
    ctx->pc = 0x199b84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199b88: 0xc4a0000c  lwc1        $f0, 0xC($a1)
    ctx->pc = 0x199b88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199b8c: 0xe4630000  swc1        $f3, 0x0($v1)
    ctx->pc = 0x199b8cu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x199b90: 0xe4620004  swc1        $f2, 0x4($v1)
    ctx->pc = 0x199b90u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 4), bits); }
    // 0x199b94: 0xe4610008  swc1        $f1, 0x8($v1)
    ctx->pc = 0x199b94u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 8), bits); }
    // 0x199b98: 0xe460000c  swc1        $f0, 0xC($v1)
    ctx->pc = 0x199b98u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 12), bits); }
    // 0x199b9c: 0xd9c40000  lqc2        $vf4, 0x0($t6)
    ctx->pc = 0x199b9cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x199ba0: 0xd9c50020  lqc2        $vf5, 0x20($t6)
    ctx->pc = 0x199ba0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 14), 32)));
    // 0x199ba4: 0xd9c60040  lqc2        $vf6, 0x40($t6)
    ctx->pc = 0x199ba4u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x199ba8: 0xd9c70010  lqc2        $vf7, 0x10($t6)
    ctx->pc = 0x199ba8u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 14), 16)));
    // 0x199bac: 0xd9c80030  lqc2        $vf8, 0x30($t6)
    ctx->pc = 0x199bacu;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 14), 48)));
    // 0x199bb0: 0xd9c90050  lqc2        $vf9, 0x50($t6)
    ctx->pc = 0x199bb0u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 14), 80)));
    // 0x199bb4: 0x4a20012c  vsub.w      $vf4, $vf0, $vf0
    ctx->pc = 0x199bb4u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x199bb8: 0x4a20016c  vsub.w      $vf5, $vf0, $vf0
    ctx->pc = 0x199bb8u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x199bbc: 0x4a2001ac  vsub.w      $vf6, $vf0, $vf0
    ctx->pc = 0x199bbcu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x199bc0: 0x44086000  mfc1        $t0, $f12
    ctx->pc = 0x199bc0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[12], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x199bc4: 0x48c8a800  ctc2.ni     $t0, $vi21
    ctx->pc = 0x199bc4u;
    ctx->vu0_info = GPR_U32(ctx, 8);
    // 0x199bc8: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x199bc8u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x199bcc: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x199bccu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x199bd0: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x199bd0u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x199bd4: 0x4bc039de  vmuli.xyz   $vf7, $vf7, $I
    ctx->pc = 0x199bd4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[7], _mm_set1_ps(ctx->vu0_i)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x199bd8: 0x4bc0421e  vmuli.xyz   $vf8, $vf8, $I
    ctx->pc = 0x199bd8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[8], _mm_set1_ps(ctx->vu0_i)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x199bdc: 0x4bc04a5e  vmuli.xyz   $vf9, $vf9, $I
    ctx->pc = 0x199bdcu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[9], _mm_set1_ps(ctx->vu0_i)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x199be0: 0x4a0002ff  vnop
    ctx->pc = 0x199be0u;
    // NOP operation, no action needed for VU0
    // 0x199be4: 0x4bc039df  vminii.xyz  $vf7, $vf7, $I
    ctx->pc = 0x199be4u;
    { __m128 res = _mm_min_ps(ctx->vu0_vf[7], _mm_set1_ps(ctx->vu0_i)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x199be8: 0x4bc0421f  vminii.xyz  $vf8, $vf8, $I
    ctx->pc = 0x199be8u;
    { __m128 res = _mm_min_ps(ctx->vu0_vf[8], _mm_set1_ps(ctx->vu0_i)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x199bec: 0x4bc04a5f  vminii.xyz  $vf9, $vf9, $I
    ctx->pc = 0x199becu;
    { __m128 res = _mm_min_ps(ctx->vu0_vf[9], _mm_set1_ps(ctx->vu0_i)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x199bf0: 0x4a0002ff  vnop
    ctx->pc = 0x199bf0u;
    // NOP operation, no action needed for VU0
    // 0x199bf4: 0xf8870030  sqc2        $vf7, 0x30($a0)
    ctx->pc = 0x199bf4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 48), _mm_castps_si128(ctx->vu0_vf[7]));
    // 0x199bf8: 0xf8880040  sqc2        $vf8, 0x40($a0)
    ctx->pc = 0x199bf8u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 64), _mm_castps_si128(ctx->vu0_vf[8]));
    // 0x199bfc: 0xf8890050  sqc2        $vf9, 0x50($a0)
    ctx->pc = 0x199bfcu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 80), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x199c00: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x199c00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x199c04: 0xac83005c  sw          $v1, 0x5C($a0)
    ctx->pc = 0x199c04u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 92), GPR_U32(ctx, 3));
    // 0x199c08: 0xac83004c  sw          $v1, 0x4C($a0)
    ctx->pc = 0x199c08u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 3));
    // 0x199c0c: 0xac83003c  sw          $v1, 0x3C($a0)
    ctx->pc = 0x199c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 3));
    // 0x199c10: 0x3e00008  jr          $ra
    ctx->pc = 0x199C10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x199C14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199C10u;
            // 0x199c14: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x199C18u;
    // 0x199c18: 0x0  nop
    ctx->pc = 0x199c18u;
    // NOP
    // 0x199c1c: 0x0  nop
    ctx->pc = 0x199c1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

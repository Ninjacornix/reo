#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001904A0
// Address: 0x1904a0 - 0x190664
void sub_001904A0_0x1904a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001904A0_0x1904a0");
#endif

    switch (ctx->pc) {
        case 0x1904ccu: goto label_1904cc;
        case 0x1904d8u: goto label_1904d8;
        case 0x190558u: goto label_190558;
        case 0x1905d4u: goto label_1905d4;
        default: break;
    }

    ctx->pc = 0x1904a0u;

    // 0x1904a0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1904a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1904a4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1904a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1904a8: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1904a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1904ac: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x1904acu;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x1904b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1904b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1904b4: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x1904b4u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x1904b8: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1904b8u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1904bc: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x1904bcu;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x1904c0: 0x46006d46  mov.s       $f21, $f13
    ctx->pc = 0x1904c0u;
    ctx->f[21] = FPU_MOV_S(ctx->f[13]);
    // 0x1904c4: 0xc063f88  jal         func_18FE20
    ctx->pc = 0x1904C4u;
    SET_GPR_U32(ctx, 31, 0x1904CCu);
    ctx->pc = 0x1904C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1904C4u;
            // 0x1904c8: 0x46007506  mov.s       $f20, $f14 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[14]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FE20u;
    if (runtime->hasFunction(0x18FE20u)) {
        auto targetFn = runtime->lookupFunction(0x18FE20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1904CCu; }
        if (ctx->pc != 0x1904CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FE20_0x18fe20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1904CCu; }
        if (ctx->pc != 0x1904CCu) { return; }
    }
    ctx->pc = 0x1904CCu;
label_1904cc:
    // 0x1904cc: 0x4600b306  mov.s       $f12, $f22
    ctx->pc = 0x1904ccu;
    ctx->f[12] = FPU_MOV_S(ctx->f[22]);
    // 0x1904d0: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x1904D0u;
    SET_GPR_U32(ctx, 31, 0x1904D8u);
    ctx->pc = 0x1904D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1904D0u;
            // 0x1904d4: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1904D8u; }
        if (ctx->pc != 0x1904D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1904D8u; }
        if (ctx->pc != 0x1904D8u) { return; }
    }
    ctx->pc = 0x1904D8u;
label_1904d8:
    // 0x1904d8: 0xc7a10050  lwc1        $f1, 0x50($sp)
    ctx->pc = 0x1904d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 80)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1904dc: 0xc7a00054  lwc1        $f0, 0x54($sp)
    ctx->pc = 0x1904dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 84)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1904e0: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x1904e0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x1904e4: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x1904e4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x1904e8: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x1904e8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1904ec: 0xda050010  lqc2        $vf5, 0x10($s0)
    ctx->pc = 0x1904ecu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1904f0: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x1904f0u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x1904f4: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x1904f4u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x1904f8: 0x4ac002a8  vadd.yz     $vf10, $vf0, $vf0
    ctx->pc = 0x1904f8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x1904fc: 0x4b000283  vaddw.x     $vf10, $vf0, $vf0w
    ctx->pc = 0x1904fcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190500: 0x4b0002e8  vadd.x      $vf11, $vf0, $vf0
    ctx->pc = 0x190500u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190504: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x190504u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190508: 0x4a5402c0  vaddx.z     $vf11, $vf0, $vf20x
    ctx->pc = 0x190508u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x19050c: 0x4b000328  vadd.x      $vf12, $vf0, $vf0
    ctx->pc = 0x19050cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190510: 0x4a940304  vsubx.y     $vf12, $vf0, $vf20x
    ctx->pc = 0x190510u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190514: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190514u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190518: 0xda060020  lqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190518u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x19051c: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x19051cu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190520: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x190520u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190524: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190524u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190528: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190528u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x19052c: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x19052cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190530: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x190530u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190534: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190534u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190538: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190538u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x19053c: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x19053cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190540: 0xfa040000  sqc2        $vf4, 0x0($s0)
    ctx->pc = 0x190540u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190544: 0xfa050010  sqc2        $vf5, 0x10($s0)
    ctx->pc = 0x190544u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190548: 0xfa060020  sqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190548u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x19054c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x19054cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x190550: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x190550u;
    SET_GPR_U32(ctx, 31, 0x190558u);
    ctx->pc = 0x190554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190550u;
            // 0x190554: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190558u; }
        if (ctx->pc != 0x190558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190558u; }
        if (ctx->pc != 0x190558u) { return; }
    }
    ctx->pc = 0x190558u;
label_190558:
    // 0x190558: 0xc7a10040  lwc1        $f1, 0x40($sp)
    ctx->pc = 0x190558u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19055c: 0xc7a00044  lwc1        $f0, 0x44($sp)
    ctx->pc = 0x19055cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 68)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x190560: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x190560u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x190564: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x190564u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x190568: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x190568u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x19056c: 0xda050010  lqc2        $vf5, 0x10($s0)
    ctx->pc = 0x19056cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x190570: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x190570u;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x190574: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x190574u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x190578: 0x4a4002a8  vadd.z      $vf10, $vf0, $vf0
    ctx->pc = 0x190578u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x19057c: 0x4a940280  vaddx.y     $vf10, $vf0, $vf20x
    ctx->pc = 0x19057cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190580: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190580u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190584: 0x4a4002e8  vadd.z      $vf11, $vf0, $vf0
    ctx->pc = 0x190584u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190588: 0x4b1402c4  vsubx.x     $vf11, $vf0, $vf20x
    ctx->pc = 0x190588u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x19058c: 0x4a9502c0  vaddx.y     $vf11, $vf0, $vf21x
    ctx->pc = 0x19058cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x190590: 0x4bcc033d  vmr32.xyz   $vf12, $vf0
    ctx->pc = 0x190590u;
    { __m128 res = _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,3,2,1)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190594: 0xda060020  lqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190594u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x190598: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190598u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x19059c: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x19059cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1905a0: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x1905a0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x1905a4: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x1905a4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x1905a8: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x1905a8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1905ac: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x1905acu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x1905b0: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x1905b0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x1905b4: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x1905b4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1905b8: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x1905b8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x1905bc: 0xfa040000  sqc2        $vf4, 0x0($s0)
    ctx->pc = 0x1905bcu;
    WRITE128(ADD32(GPR_U32(ctx, 16), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x1905c0: 0xfa050010  sqc2        $vf5, 0x10($s0)
    ctx->pc = 0x1905c0u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x1905c4: 0xfa060020  sqc2        $vf6, 0x20($s0)
    ctx->pc = 0x1905c4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x1905c8: 0x4600ab06  mov.s       $f12, $f21
    ctx->pc = 0x1905c8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[21]);
    // 0x1905cc: 0xc063d5c  jal         func_18F570
    ctx->pc = 0x1905CCu;
    SET_GPR_U32(ctx, 31, 0x1905D4u);
    ctx->pc = 0x1905D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1905CCu;
            // 0x1905d0: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F570u;
    if (runtime->hasFunction(0x18F570u)) {
        auto targetFn = runtime->lookupFunction(0x18F570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1905D4u; }
        if (ctx->pc != 0x1905D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F570_0x18f570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1905D4u; }
        if (ctx->pc != 0x1905D4u) { return; }
    }
    ctx->pc = 0x1905D4u;
label_1905d4:
    // 0x1905d4: 0xc7a10030  lwc1        $f1, 0x30($sp)
    ctx->pc = 0x1905d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1905d8: 0xc7a00034  lwc1        $f0, 0x34($sp)
    ctx->pc = 0x1905d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1905dc: 0x44060800  mfc1        $a2, $f1
    ctx->pc = 0x1905dcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x1905e0: 0x44070000  mfc1        $a3, $f0
    ctx->pc = 0x1905e0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 7, bits); }
    // 0x1905e4: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x1905e4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1905e8: 0xda050010  lqc2        $vf5, 0x10($s0)
    ctx->pc = 0x1905e8u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1905ec: 0x48a6a000  qmtc2.ni    $a2, $vf20
    ctx->pc = 0x1905ecu;
    ctx->vu0_vf[20] = _mm_castsi128_ps(GPR_VEC(ctx, 6));
    // 0x1905f0: 0x48a7a800  qmtc2.ni    $a3, $vf21
    ctx->pc = 0x1905f0u;
    ctx->vu0_vf[21] = _mm_castsi128_ps(GPR_VEC(ctx, 7));
    // 0x1905f4: 0x4b4002e8  vadd.xz     $vf11, $vf0, $vf0
    ctx->pc = 0x1905f4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, -1, 0, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x1905f8: 0x4a8002c3  vaddw.y     $vf11, $vf0, $vf0w
    ctx->pc = 0x1905f8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x1905fc: 0x4a8002a8  vadd.y      $vf10, $vf0, $vf0
    ctx->pc = 0x1905fcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190600: 0x4b150280  vaddx.x     $vf10, $vf0, $vf21x
    ctx->pc = 0x190600u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190604: 0x4a540284  vsubx.z     $vf10, $vf0, $vf20x
    ctx->pc = 0x190604u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x190608: 0x4a800328  vadd.y      $vf12, $vf0, $vf0
    ctx->pc = 0x190608u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x19060c: 0x4b140300  vaddx.x     $vf12, $vf0, $vf20x
    ctx->pc = 0x19060cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[20], ctx->vu0_vf[20], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190610: 0x4a550300  vaddx.z     $vf12, $vf0, $vf21x
    ctx->pc = 0x190610u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[21], ctx->vu0_vf[21], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x190614: 0xda060020  lqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190614u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x190618: 0x4bc451bc  vmulax.xyz  $ACC, $vf10, $vf4x
    ctx->pc = 0x190618u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x19061c: 0x4bc458bd  vmadday.xyz $ACC, $vf11, $vf4y
    ctx->pc = 0x19061cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190620: 0x4bc4610a  vmaddz.xyz  $vf4, $vf12, $vf4z
    ctx->pc = 0x190620u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190624: 0x4bc551bc  vmulax.xyz  $ACC, $vf10, $vf5x
    ctx->pc = 0x190624u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190628: 0x4bc558bd  vmadday.xyz $ACC, $vf11, $vf5y
    ctx->pc = 0x190628u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x19062c: 0x4bc5614a  vmaddz.xyz  $vf5, $vf12, $vf5z
    ctx->pc = 0x19062cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x190630: 0x4bc651bc  vmulax.xyz  $ACC, $vf10, $vf6x
    ctx->pc = 0x190630u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x190634: 0x4bc658bd  vmadday.xyz $ACC, $vf11, $vf6y
    ctx->pc = 0x190634u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[11], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x190638: 0x4bc6618a  vmaddz.xyz  $vf6, $vf12, $vf6z
    ctx->pc = 0x190638u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[12], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x19063c: 0xfa040000  sqc2        $vf4, 0x0($s0)
    ctx->pc = 0x19063cu;
    WRITE128(ADD32(GPR_U32(ctx, 16), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x190640: 0xfa050010  sqc2        $vf5, 0x10($s0)
    ctx->pc = 0x190640u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x190644: 0xfa060020  sqc2        $vf6, 0x20($s0)
    ctx->pc = 0x190644u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x190648: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x190648u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19064c: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x19064cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x190650: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x190650u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x190654: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x190654u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x190658: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x190658u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x19065c: 0x3e00008  jr          $ra
    ctx->pc = 0x19065Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19065Cu;
            // 0x190660: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1904CCu: goto label_1904cc;
            case 0x1904D8u: goto label_1904d8;
            case 0x190558u: goto label_190558;
            case 0x1905D4u: goto label_1905d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190664u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

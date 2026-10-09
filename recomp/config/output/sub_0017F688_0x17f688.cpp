#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F688
// Address: 0x17f688 - 0x180170
void sub_0017F688_0x17f688(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F688_0x17f688");
#endif

    switch (ctx->pc) {
        case 0x17f6acu: goto label_17f6ac;
        case 0x17f6f0u: goto label_17f6f0;
        case 0x17f724u: goto label_17f724;
        case 0x17f7a0u: goto label_17f7a0;
        case 0x17f7b0u: goto label_17f7b0;
        case 0x17f7fcu: goto label_17f7fc;
        case 0x17f88cu: goto label_17f88c;
        case 0x17f8a0u: goto label_17f8a0;
        case 0x17f8acu: goto label_17f8ac;
        case 0x17f8bcu: goto label_17f8bc;
        case 0x17f8ccu: goto label_17f8cc;
        case 0x17f8dcu: goto label_17f8dc;
        case 0x17f8e8u: goto label_17f8e8;
        case 0x17f940u: goto label_17f940;
        case 0x17f94cu: goto label_17f94c;
        case 0x17f95cu: goto label_17f95c;
        case 0x17f968u: goto label_17f968;
        case 0x17f978u: goto label_17f978;
        case 0x17f984u: goto label_17f984;
        case 0x17f9acu: goto label_17f9ac;
        case 0x17f9f4u: goto label_17f9f4;
        case 0x17fa00u: goto label_17fa00;
        case 0x17fa0cu: goto label_17fa0c;
        case 0x17fab8u: goto label_17fab8;
        case 0x17fae0u: goto label_17fae0;
        case 0x17fb08u: goto label_17fb08;
        case 0x17fcfcu: goto label_17fcfc;
        case 0x17fd0cu: goto label_17fd0c;
        case 0x17fdbcu: goto label_17fdbc;
        case 0x17fe84u: goto label_17fe84;
        case 0x17ff0cu: goto label_17ff0c;
        case 0x17ff64u: goto label_17ff64;
        case 0x17ffb8u: goto label_17ffb8;
        case 0x17fff4u: goto label_17fff4;
        case 0x180060u: goto label_180060;
        case 0x1800b4u: goto label_1800b4;
        case 0x1800d8u: goto label_1800d8;
        case 0x180148u: goto label_180148;
        default: break;
    }

    ctx->pc = 0x17f688u;

label_17f688:
    // 0x17f688: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f68c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f68cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f690: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f694: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f694u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f698: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17f698u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17f69c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17f69cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f6a0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f6a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f6a4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F6A4u;
    SET_GPR_U32(ctx, 31, 0x17F6ACu);
    ctx->pc = 0x17F6A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F6A4u;
            // 0x17f6a8: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F6ACu; }
        if (ctx->pc != 0x17F6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F6ACu; }
        if (ctx->pc != 0x17F6ACu) { return; }
    }
    ctx->pc = 0x17F6ACu;
label_17f6ac:
    // 0x17f6ac: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x17f6acu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17f6b0: 0x4600a034  c.lt.s      $f20, $f0
    ctx->pc = 0x17f6b0u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17f6b4: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x17f6b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x17f6b8: 0x34210fdb  ori         $at, $at, 0xFDB
    ctx->pc = 0x17f6b8u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4059);
    // 0x17f6bc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x17f6bcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17f6c0: 0x45000004  bc1f        . + 4 + (0x4 << 2)
    ctx->pc = 0x17F6C0u;
    {
        const bool branch_taken_0x17f6c0 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x17f6c0) {
            ctx->pc = 0x17F6D4u;
            goto label_17f6d4;
        }
    }
    ctx->pc = 0x17F6C8u;
    // 0x17f6c8: 0x46140500  add.s       $f20, $f0, $f20
    ctx->pc = 0x17f6c8u;
    ctx->f[20] = FPU_ADD_S(ctx->f[0], ctx->f[20]);
    // 0x17f6cc: 0x805fdb7  j           func_17F6DC
    ctx->pc = 0x17F6CCu;
    ctx->pc = 0x17F6D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F6CCu;
            // 0x17f6d0: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F6DCu;
    goto label_17f6dc;
    ctx->pc = 0x17F6D4u;
label_17f6d4:
    // 0x17f6d4: 0x46140501  sub.s       $f20, $f0, $f20
    ctx->pc = 0x17f6d4u;
    ctx->f[20] = FPU_SUB_S(ctx->f[0], ctx->f[20]);
    // 0x17f6d8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17f6d8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17f6dc:
    // 0x17f6dc: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17f6dcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17f6e0: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x17f6e0u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17f6e4: 0x3e0302d  daddu       $a2, $ra, $zero
    ctx->pc = 0x17f6e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 31) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f6e8: 0xc05fd0a  jal         func_17F428
    ctx->pc = 0x17F6E8u;
    SET_GPR_U32(ctx, 31, 0x17F6F0u);
    ctx->pc = 0x17F428u;
    if (runtime->hasFunction(0x17F428u)) {
        auto targetFn = runtime->lookupFunction(0x17F428u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F6F0u; }
        if (ctx->pc != 0x17F6F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F428_0x17f428(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F6F0u; }
        if (ctx->pc != 0x17F6F0u) { return; }
    }
    ctx->pc = 0x17F6F0u;
label_17f6f0:
    // 0x17f6f0: 0xc0f82d  daddu       $ra, $a2, $zero
    ctx->pc = 0x17f6f0u;
    SET_GPR_U64(ctx, 31, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f6f4: 0x4be62b3c  vmove.xyzw  $vf6, $vf5
    ctx->pc = 0x17f6f4u;
    ctx->vu0_vf[6] = ctx->vu0_vf[5];
    // 0x17f6f8: 0x4be72b3c  vmove.xyzw  $vf7, $vf5
    ctx->pc = 0x17f6f8u;
    ctx->vu0_vf[7] = ctx->vu0_vf[5];
    // 0x17f6fc: 0x4be82b3c  vmove.xyzw  $vf8, $vf5
    ctx->pc = 0x17f6fcu;
    ctx->vu0_vf[8] = ctx->vu0_vf[5];
    // 0x17f700: 0x4be92b3c  vmove.xyzw  $vf9, $vf5
    ctx->pc = 0x17f700u;
    ctx->vu0_vf[9] = ctx->vu0_vf[5];
    // 0x17f704: 0x4a8029c3  vaddw.y     $vf7, $vf5, $vf0w
    ctx->pc = 0x17f704u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x17f708: 0x4a202a43  vaddw.w     $vf9, $vf5, $vf0w
    ctx->pc = 0x17f708u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x17f70c: 0x4a64212c  vsub.zw     $vf4, $vf4, $vf4
    ctx->pc = 0x17f70cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[4], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, -1, 0, 0); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17f710: 0x4a442984  vsubx.z     $vf6, $vf5, $vf4x
    ctx->pc = 0x17f710u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f714: 0x4b042981  vaddy.x     $vf6, $vf5, $vf4y
    ctx->pc = 0x17f714u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f718: 0x4b042a00  vaddx.x     $vf8, $vf5, $vf4x
    ctx->pc = 0x17f718u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x17f71c: 0x4a442a01  vaddy.z     $vf8, $vf5, $vf4y
    ctx->pc = 0x17f71cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x17f720: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x17f720u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_17f724:
    // 0x17f724: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f724u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f728: 0x4be431bc  vmulax.xyzw $ACC, $vf6, $vf4x
    ctx->pc = 0x17f728u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x17f72c: 0x4be438bd  vmadday.xyzw $ACC, $vf7, $vf4y
    ctx->pc = 0x17f72cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17f730: 0x4be440be  vmaddaz.xyzw $ACC, $vf8, $vf4z
    ctx->pc = 0x17f730u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17f734: 0x4be4494b  vmaddw.xyzw $vf5, $vf9, $vf4w
    ctx->pc = 0x17f734u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x17f738: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f738u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f73c: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x17f73cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x17f740: 0x22100010  addi        $s0, $s0, 0x10
    ctx->pc = 0x17f740u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 16), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 16, (int32_t)tmp); }
    // 0x17f744: 0x1407fff7  bne         $zero, $a3, . + 4 + (-0x9 << 2)
    ctx->pc = 0x17F744u;
    {
        const bool branch_taken_0x17f744 = (GPR_U64(ctx, 0) != GPR_U64(ctx, 7));
        ctx->pc = 0x17F748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F744u;
            // 0x17f748: 0x22310010  addi        $s1, $s1, 0x10 (Delay Slot)
        { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 17), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 17, (int32_t)tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f744) {
            ctx->pc = 0x17F724u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17f724;
        }
    }
    ctx->pc = 0x17F74Cu;
    // 0x17f74c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17F74Cu;
    {
        const bool branch_taken_0x17f74c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F74Cu;
            // 0x17f750: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f74c) {
            ctx->pc = 0x17F768u;
            goto label_17f768;
        }
    }
    ctx->pc = 0x17F754u;
    // 0x17f754: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f754u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f758: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f758u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f75c: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f75cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f760: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F760u;
    ctx->pc = 0x17F764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F760u;
            // 0x17f764: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F768u;
label_17f768:
    // 0x17f768: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f768u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f76c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f76cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f770: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f770u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f774: 0x3e00008  jr          $ra
    ctx->pc = 0x17F774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F774u;
            // 0x17f778: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F77Cu;
    // 0x17f77c: 0x0  nop
    ctx->pc = 0x17f77cu;
    // NOP
    // 0x17f780: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f784: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f788: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f78c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17f78cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f790: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f794: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17f794u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f798: 0xc05fd28  jal         func_17F4A0
    ctx->pc = 0x17F798u;
    SET_GPR_U32(ctx, 31, 0x17F7A0u);
    ctx->pc = 0x17F79Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F798u;
            // 0x17f79c: 0xc62c0008  lwc1        $f12, 0x8($s1) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F4A0u;
    if (runtime->hasFunction(0x17F4A0u)) {
        auto targetFn = runtime->lookupFunction(0x17F4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7A0u; }
        if (ctx->pc != 0x17F7A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F4A0_0x17f4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7A0u; }
        if (ctx->pc != 0x17F7A0u) { return; }
    }
    ctx->pc = 0x17F7A0u;
label_17f7a0:
    // 0x17f7a0: 0xc62c0004  lwc1        $f12, 0x4($s1)
    ctx->pc = 0x17f7a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x17f7a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f7a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7a8: 0xc05fda2  jal         func_17F688
    ctx->pc = 0x17F7A8u;
    SET_GPR_U32(ctx, 31, 0x17F7B0u);
    ctx->pc = 0x17F7ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F7A8u;
            // 0x17f7ac: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F688u;
    goto label_17f688;
    ctx->pc = 0x17F7B0u;
label_17f7b0:
    // 0x17f7b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f7b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7b4: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x17f7b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x17f7b8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17f7b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f7bc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x17f7bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7c0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f7c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f7c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f7c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f7c8: 0x805fd64  j           func_17F590
    ctx->pc = 0x17F7C8u;
    ctx->pc = 0x17F7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F7C8u;
            // 0x17f7cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F590u;
    if (runtime->hasFunction(0x17F590u)) {
        auto targetFn = runtime->lookupFunction(0x17F590u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017F590_0x17f590(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F7D0u;
    // 0x17f7d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f7d4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f7d8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f7dc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f7dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7e0: 0xe7b50038  swc1        $f21, 0x38($sp)
    ctx->pc = 0x17f7e0u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 56), bits); }
    // 0x17f7e4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17f7e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7e8: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17f7e8u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17f7ec: 0x46006546  mov.s       $f21, $f12
    ctx->pc = 0x17f7ecu;
    ctx->f[21] = FPU_MOV_S(ctx->f[12]);
    // 0x17f7f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f7f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f7f4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F7F4u;
    SET_GPR_U32(ctx, 31, 0x17F7FCu);
    ctx->pc = 0x17F7F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F7F4u;
            // 0x17f7f8: 0x46006d06  mov.s       $f20, $f13 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7FCu; }
        if (ctx->pc != 0x17F7FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7FCu; }
        if (ctx->pc != 0x17F7FCu) { return; }
    }
    ctx->pc = 0x17F7FCu;
label_17f7fc:
    // 0x17f7fc: 0x4408a800  mfc1        $t0, $f21
    ctx->pc = 0x17f7fcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[21], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17f800: 0x4409a000  mfc1        $t1, $f20
    ctx->pc = 0x17f800u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 9, bits); }
    // 0x17f804: 0xda060000  lqc2        $vf6, 0x0($s0)
    ctx->pc = 0x17f804u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f808: 0x48a82000  qmtc2.ni    $t0, $vf4
    ctx->pc = 0x17f808u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17f80c: 0x48a92800  qmtc2.ni    $t1, $vf5
    ctx->pc = 0x17f80cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(GPR_VEC(ctx, 9));
    // 0x17f810: 0x4be43190  vmaxx.xyzw  $vf6, $vf6, $vf4x
    ctx->pc = 0x17f810u;
    { __m128 res = _mm_max_ps(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f814: 0x4be53194  vminix.xyzw $vf6, $vf6, $vf5x
    ctx->pc = 0x17f814u;
    { __m128 res = _mm_min_ps(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f818: 0xfa260000  sqc2        $vf6, 0x0($s1)
    ctx->pc = 0x17f818u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17f81c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17F81Cu;
    {
        const bool branch_taken_0x17f81c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F81Cu;
            // 0x17f820: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f81c) {
            ctx->pc = 0x17F83Cu;
            goto label_17f83c;
        }
    }
    ctx->pc = 0x17F824u;
    // 0x17f824: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f824u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f828: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f828u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f82c: 0xc7b50038  lwc1        $f21, 0x38($sp)
    ctx->pc = 0x17f82cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17f830: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f830u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f834: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F834u;
    ctx->pc = 0x17F838u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F834u;
            // 0x17f838: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F83Cu;
label_17f83c:
    // 0x17f83c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f83cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f840: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f840u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f844: 0xc7b50038  lwc1        $f21, 0x38($sp)
    ctx->pc = 0x17f844u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17f848: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f848u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f84c: 0x3e00008  jr          $ra
    ctx->pc = 0x17F84Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F84Cu;
            // 0x17f850: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F854u;
    // 0x17f854: 0x0  nop
    ctx->pc = 0x17f854u;
    // NOP
    // 0x17f858: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x17f858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x17f85c: 0xffb40090  sd          $s4, 0x90($sp)
    ctx->pc = 0x17f85cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x17f860: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x17f860u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f864: 0xffb30080  sd          $s3, 0x80($sp)
    ctx->pc = 0x17f864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 19));
    // 0x17f868: 0xffb20070  sd          $s2, 0x70($sp)
    ctx->pc = 0x17f868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 18));
    // 0x17f86c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x17f86cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f870: 0xffb10060  sd          $s1, 0x60($sp)
    ctx->pc = 0x17f870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 17));
    // 0x17f874: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17f874u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f878: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x17f878u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f87c: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x17f87cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x17f880: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x17f880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x17f884: 0xc05fcf4  jal         func_17F3D0
    ctx->pc = 0x17F884u;
    SET_GPR_U32(ctx, 31, 0x17F88Cu);
    ctx->pc = 0x17F888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F884u;
            // 0x17f888: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F3D0u;
    if (runtime->hasFunction(0x17F3D0u)) {
        auto targetFn = runtime->lookupFunction(0x17F3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F88Cu; }
        if (ctx->pc != 0x17F88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F3D0_0x17f3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F88Cu; }
        if (ctx->pc != 0x17F88Cu) { return; }
    }
    ctx->pc = 0x17F88Cu;
label_17f88c:
    // 0x17f88c: 0x27b00040  addiu       $s0, $sp, 0x40
    ctx->pc = 0x17f88cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x17f890: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17f890u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f894: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f894u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f898: 0xc05faee  jal         func_17EBB8
    ctx->pc = 0x17F898u;
    SET_GPR_U32(ctx, 31, 0x17F8A0u);
    ctx->pc = 0x17F89Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F898u;
            // 0x17f89c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EBB8u;
    if (runtime->hasFunction(0x17EBB8u)) {
        auto targetFn = runtime->lookupFunction(0x17EBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8A0u; }
        if (ctx->pc != 0x17F8A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EBB8_0x17ebb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8A0u; }
        if (ctx->pc != 0x17F8A0u) { return; }
    }
    ctx->pc = 0x17F8A0u;
label_17f8a0:
    // 0x17f8a0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17f8a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8a4: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F8A4u;
    SET_GPR_U32(ctx, 31, 0x17F8ACu);
    ctx->pc = 0x17F8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8A4u;
            // 0x17f8a8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8ACu; }
        if (ctx->pc != 0x17F8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8ACu; }
        if (ctx->pc != 0x17F8ACu) { return; }
    }
    ctx->pc = 0x17F8ACu;
label_17f8ac:
    // 0x17f8ac: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x17f8acu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x17f8b0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17f8b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8b4: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F8B4u;
    SET_GPR_U32(ctx, 31, 0x17F8BCu);
    ctx->pc = 0x17F8B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8B4u;
            // 0x17f8b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8BCu; }
        if (ctx->pc != 0x17F8BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8BCu; }
        if (ctx->pc != 0x17F8BCu) { return; }
    }
    ctx->pc = 0x17F8BCu;
label_17f8bc:
    // 0x17f8bc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17f8bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8c0: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x17f8c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17f8c4: 0xc05faee  jal         func_17EBB8
    ctx->pc = 0x17F8C4u;
    SET_GPR_U32(ctx, 31, 0x17F8CCu);
    ctx->pc = 0x17F8C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8C4u;
            // 0x17f8c8: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EBB8u;
    if (runtime->hasFunction(0x17EBB8u)) {
        auto targetFn = runtime->lookupFunction(0x17EBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8CCu; }
        if (ctx->pc != 0x17F8CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EBB8_0x17ebb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8CCu; }
        if (ctx->pc != 0x17F8CCu) { return; }
    }
    ctx->pc = 0x17F8CCu;
label_17f8cc:
    // 0x17f8cc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x17f8ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8d0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17f8d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8d4: 0xc05fc56  jal         func_17F158
    ctx->pc = 0x17F8D4u;
    SET_GPR_U32(ctx, 31, 0x17F8DCu);
    ctx->pc = 0x17F8D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8D4u;
            // 0x17f8d8: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F158u;
    if (runtime->hasFunction(0x17F158u)) {
        auto targetFn = runtime->lookupFunction(0x17F158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8DCu; }
        if (ctx->pc != 0x17F8DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F158_0x17f158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8DCu; }
        if (ctx->pc != 0x17F8DCu) { return; }
    }
    ctx->pc = 0x17F8DCu;
label_17f8dc:
    // 0x17f8dc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x17f8dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8e0: 0xc05fb68  jal         func_17EDA0
    ctx->pc = 0x17F8E0u;
    SET_GPR_U32(ctx, 31, 0x17F8E8u);
    ctx->pc = 0x17F8E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8E0u;
            // 0x17f8e4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EDA0u;
    if (runtime->hasFunction(0x17EDA0u)) {
        auto targetFn = runtime->lookupFunction(0x17EDA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8E8u; }
        if (ctx->pc != 0x17F8E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EDA0_0x17eda0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8E8u; }
        if (ctx->pc != 0x17F8E8u) { return; }
    }
    ctx->pc = 0x17F8E8u;
label_17f8e8:
    // 0x17f8e8: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x17f8e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x17f8ec: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x17f8ecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x17f8f0: 0xdfb30080  ld          $s3, 0x80($sp)
    ctx->pc = 0x17f8f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x17f8f4: 0xdfb20070  ld          $s2, 0x70($sp)
    ctx->pc = 0x17f8f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x17f8f8: 0xdfb10060  ld          $s1, 0x60($sp)
    ctx->pc = 0x17f8f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17f8fc: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x17f8fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17f900: 0x3e00008  jr          $ra
    ctx->pc = 0x17F900u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F900u;
            // 0x17f904: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F908u;
    // 0x17f908: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17f908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17f90c: 0xe7b40050  swc1        $f20, 0x50($sp)
    ctx->pc = 0x17f90cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x17f910: 0x3c01bf80  lui         $at, 0xBF80
    ctx->pc = 0x17f910u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49024 << 16));
    // 0x17f914: 0x4481a000  mtc1        $at, $f20
    ctx->pc = 0x17f914u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x17f918: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17f918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17f91c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17f91cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f920: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x17f920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x17f924: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x17f924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x17f928: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x17f928u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f92c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17f92cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f930: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x17f930u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x17f934: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17f934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17f938: 0xc05fc3c  jal         func_17F0F0
    ctx->pc = 0x17F938u;
    SET_GPR_U32(ctx, 31, 0x17F940u);
    ctx->pc = 0x17F93Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F938u;
            // 0x17f93c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F0F0u;
    if (runtime->hasFunction(0x17F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x17F0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F940u; }
        if (ctx->pc != 0x17F940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F0F0_0x17f0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F940u; }
        if (ctx->pc != 0x17F940u) { return; }
    }
    ctx->pc = 0x17F940u;
label_17f940:
    // 0x17f940: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f944: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F944u;
    SET_GPR_U32(ctx, 31, 0x17F94Cu);
    ctx->pc = 0x17F948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F944u;
            // 0x17f948: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F94Cu; }
        if (ctx->pc != 0x17F94Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F94Cu; }
        if (ctx->pc != 0x17F94Cu) { return; }
    }
    ctx->pc = 0x17F94Cu;
label_17f94c:
    // 0x17f94c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17f94cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f950: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x17f950u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x17f954: 0xc05fc3c  jal         func_17F0F0
    ctx->pc = 0x17F954u;
    SET_GPR_U32(ctx, 31, 0x17F95Cu);
    ctx->pc = 0x17F958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F954u;
            // 0x17f958: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F0F0u;
    if (runtime->hasFunction(0x17F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x17F0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F95Cu; }
        if (ctx->pc != 0x17F95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F0F0_0x17f0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F95Cu; }
        if (ctx->pc != 0x17F95Cu) { return; }
    }
    ctx->pc = 0x17F95Cu;
label_17f95c:
    // 0x17f95c: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x17f95cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x17f960: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F960u;
    SET_GPR_U32(ctx, 31, 0x17F968u);
    ctx->pc = 0x17F964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F960u;
            // 0x17f964: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F968u; }
        if (ctx->pc != 0x17F968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F968u; }
        if (ctx->pc != 0x17F968u) { return; }
    }
    ctx->pc = 0x17F968u;
label_17f968:
    // 0x17f968: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17f968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f96c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x17f96cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x17f970: 0xc05fc3c  jal         func_17F0F0
    ctx->pc = 0x17F970u;
    SET_GPR_U32(ctx, 31, 0x17F978u);
    ctx->pc = 0x17F974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F970u;
            // 0x17f974: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F0F0u;
    if (runtime->hasFunction(0x17F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x17F0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F978u; }
        if (ctx->pc != 0x17F978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F0F0_0x17f0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F978u; }
        if (ctx->pc != 0x17F978u) { return; }
    }
    ctx->pc = 0x17F978u;
label_17f978:
    // 0x17f978: 0x26040020  addiu       $a0, $s0, 0x20
    ctx->pc = 0x17f978u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    // 0x17f97c: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F97Cu;
    SET_GPR_U32(ctx, 31, 0x17F984u);
    ctx->pc = 0x17F980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F97Cu;
            // 0x17f980: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F984u; }
        if (ctx->pc != 0x17F984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F984u; }
        if (ctx->pc != 0x17F984u) { return; }
    }
    ctx->pc = 0x17F984u;
label_17f984:
    // 0x17f984: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x17f984u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17f988: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f988u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f98c: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x17f98cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x17f990: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17f990u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17f994: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x17f994u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f998: 0xe6000030  swc1        $f0, 0x30($s0)
    ctx->pc = 0x17f998u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 48), bits); }
    // 0x17f99c: 0xe601003c  swc1        $f1, 0x3C($s0)
    ctx->pc = 0x17f99cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 60), bits); }
    // 0x17f9a0: 0xe6000038  swc1        $f0, 0x38($s0)
    ctx->pc = 0x17f9a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 56), bits); }
    // 0x17f9a4: 0xc05fb46  jal         func_17ED18
    ctx->pc = 0x17F9A4u;
    SET_GPR_U32(ctx, 31, 0x17F9ACu);
    ctx->pc = 0x17F9A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9A4u;
            // 0x17f9a8: 0xe6000034  swc1        $f0, 0x34($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 52), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ED18u;
    if (runtime->hasFunction(0x17ED18u)) {
        auto targetFn = runtime->lookupFunction(0x17ED18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9ACu; }
        if (ctx->pc != 0x17F9ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ED18_0x17ed18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9ACu; }
        if (ctx->pc != 0x17F9ACu) { return; }
    }
    ctx->pc = 0x17F9ACu;
label_17f9ac:
    // 0x17f9ac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x17f9acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17f9b0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x17f9b0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17f9b4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x17f9b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f9b8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17f9b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f9bc: 0xc7b40050  lwc1        $f20, 0x50($sp)
    ctx->pc = 0x17f9bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 80)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f9c0: 0x3e00008  jr          $ra
    ctx->pc = 0x17F9C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9C0u;
            // 0x17f9c4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F9C8u;
    // 0x17f9c8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17f9c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17f9cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f9d0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17f9d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9d4: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x17f9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x17f9d8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17f9d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17f9dc: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x17f9dcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9e0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f9e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f9e4: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x17f9e4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9e8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17f9e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17f9ec: 0xc05fc76  jal         func_17F1D8
    ctx->pc = 0x17F9ECu;
    SET_GPR_U32(ctx, 31, 0x17F9F4u);
    ctx->pc = 0x17F9F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9ECu;
            // 0x17f9f0: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9F4u; }
        if (ctx->pc != 0x17F9F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9F4u; }
        if (ctx->pc != 0x17F9F4u) { return; }
    }
    ctx->pc = 0x17F9F4u;
label_17f9f4:
    // 0x17f9f4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17f9f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9f8: 0xc05fc76  jal         func_17F1D8
    ctx->pc = 0x17F9F8u;
    SET_GPR_U32(ctx, 31, 0x17FA00u);
    ctx->pc = 0x17F9FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9F8u;
            // 0x17f9fc: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA00u; }
        if (ctx->pc != 0x17FA00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA00u; }
        if (ctx->pc != 0x17FA00u) { return; }
    }
    ctx->pc = 0x17FA00u;
label_17fa00:
    // 0x17fa00: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17fa00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fa04: 0xc05fc76  jal         func_17F1D8
    ctx->pc = 0x17FA04u;
    SET_GPR_U32(ctx, 31, 0x17FA0Cu);
    ctx->pc = 0x17FA08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FA04u;
            // 0x17fa08: 0x26040020  addiu       $a0, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA0Cu; }
        if (ctx->pc != 0x17FA0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA0Cu; }
        if (ctx->pc != 0x17FA0Cu) { return; }
    }
    ctx->pc = 0x17FA0Cu;
label_17fa0c:
    // 0x17fa0c: 0x26040030  addiu       $a0, $s0, 0x30
    ctx->pc = 0x17fa0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x17fa10: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x17fa10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fa14: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x17fa14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17fa18: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x17fa18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17fa1c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17fa1cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17fa20: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17fa20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17fa24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17fa24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fa28: 0x805fc76  j           func_17F1D8
    ctx->pc = 0x17FA28u;
    ctx->pc = 0x17FA2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FA28u;
            // 0x17fa2c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17FA30u;
    // 0x17fa30: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x17fa30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x17fa34: 0x46008807  neg.s       $f0, $f17
    ctx->pc = 0x17fa34u;
    ctx->f[0] = FPU_NEG_S(ctx->f[17]);
    // 0x17fa38: 0xe7b40060  swc1        $f20, 0x60($sp)
    ctx->pc = 0x17fa38u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x17fa3c: 0x46009507  neg.s       $f20, $f18
    ctx->pc = 0x17fa3cu;
    ctx->f[20] = FPU_NEG_S(ctx->f[18]);
    // 0x17fa40: 0xc7a100a0  lwc1        $f1, 0xA0($sp)
    ctx->pc = 0x17fa40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17fa44: 0xe7b50068  swc1        $f21, 0x68($sp)
    ctx->pc = 0x17fa44u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x17fa48: 0x46120000  add.s       $f0, $f0, $f18
    ctx->pc = 0x17fa48u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[18]);
    // 0x17fa4c: 0x46130d42  mul.s       $f21, $f1, $f19
    ctx->pc = 0x17fa4cu;
    ctx->f[21] = FPU_MUL_S(ctx->f[1], ctx->f[19]);
    // 0x17fa50: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17fa50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17fa54: 0x4613a502  mul.s       $f20, $f20, $f19
    ctx->pc = 0x17fa54u;
    ctx->f[20] = FPU_MUL_S(ctx->f[20], ctx->f[19]);
    // 0x17fa58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17fa58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fa5c: 0x46018c42  mul.s       $f17, $f17, $f1
    ctx->pc = 0x17fa5cu;
    ctx->f[17] = FPU_MUL_S(ctx->f[17], ctx->f[1]);
    // 0x17fa60: 0xe7ba0090  swc1        $f26, 0x90($sp)
    ctx->pc = 0x17fa60u;
    { float f = ctx->f[26]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 144), bits); }
    // 0x17fa64: 0x46009cc7  neg.s       $f19, $f19
    ctx->pc = 0x17fa64u;
    ctx->f[19] = FPU_NEG_S(ctx->f[19]);
    // 0x17fa68: 0xe7b90088  swc1        $f25, 0x88($sp)
    ctx->pc = 0x17fa68u;
    { float f = ctx->f[25]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
    // 0x17fa6c: 0x4600ad42  mul.s       $f21, $f21, $f0
    ctx->pc = 0x17fa6cu;
    ctx->f[21] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x17fa70: 0xe7b80080  swc1        $f24, 0x80($sp)
    ctx->pc = 0x17fa70u;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x17fa74: 0x4611a500  add.s       $f20, $f20, $f17
    ctx->pc = 0x17fa74u;
    ctx->f[20] = FPU_ADD_S(ctx->f[20], ctx->f[17]);
    // 0x17fa78: 0xe7b70078  swc1        $f23, 0x78($sp)
    ctx->pc = 0x17fa78u;
    { float f = ctx->f[23]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    // 0x17fa7c: 0x46019cc0  add.s       $f19, $f19, $f1
    ctx->pc = 0x17fa7cu;
    ctx->f[19] = FPU_ADD_S(ctx->f[19], ctx->f[1]);
    // 0x17fa80: 0xe7b60070  swc1        $f22, 0x70($sp)
    ctx->pc = 0x17fa80u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x17fa84: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x17fa84u;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x17fa88: 0x46006e06  mov.s       $f24, $f13
    ctx->pc = 0x17fa88u;
    ctx->f[24] = FPU_MOV_S(ctx->f[13]);
    // 0x17fa8c: 0x460075c6  mov.s       $f23, $f14
    ctx->pc = 0x17fa8cu;
    ctx->f[23] = FPU_MOV_S(ctx->f[14]);
    // 0x17fa90: 0x46007e86  mov.s       $f26, $f15
    ctx->pc = 0x17fa90u;
    ctx->f[26] = FPU_MOV_S(ctx->f[15]);
    // 0x17fa94: 0x0  nop
    ctx->pc = 0x17fa94u;
    // NOP
    // 0x17fa98: 0x0  nop
    ctx->pc = 0x17fa98u;
    // NOP
    // 0x17fa9c: 0x4613ad43  div.s       $f21, $f21, $f19
    ctx->pc = 0x17fa9cu;
    if (ctx->f[19] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[21]) ^ std::bit_cast<uint32_t>(ctx->f[19])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[21] = std::bit_cast<float>(__maxf); } else ctx->f[21] = ctx->f[21] / ctx->f[19];
    // 0x17faa0: 0x0  nop
    ctx->pc = 0x17faa0u;
    // NOP
    // 0x17faa4: 0x0  nop
    ctx->pc = 0x17faa4u;
    // NOP
    // 0x17faa8: 0x4613a503  div.s       $f20, $f20, $f19
    ctx->pc = 0x17faa8u;
    if (ctx->f[19] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[19])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[20] = std::bit_cast<float>(__maxf); } else ctx->f[20] = ctx->f[20] / ctx->f[19];
    // 0x17faac: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17faacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x17fab0: 0xc05fcf4  jal         func_17F3D0
    ctx->pc = 0x17FAB0u;
    SET_GPR_U32(ctx, 31, 0x17FAB8u);
    ctx->pc = 0x17FAB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FAB0u;
            // 0x17fab4: 0x46008646  mov.s       $f25, $f16 (Delay Slot)
        ctx->f[25] = FPU_MOV_S(ctx->f[16]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F3D0u;
    if (runtime->hasFunction(0x17F3D0u)) {
        auto targetFn = runtime->lookupFunction(0x17F3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAB8u; }
        if (ctx->pc != 0x17FAB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F3D0_0x17f3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAB8u; }
        if (ctx->pc != 0x17FAB8u) { return; }
    }
    ctx->pc = 0x17FAB8u;
label_17fab8:
    // 0x17fab8: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x17fab8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x17fabc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x17fabcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17fac0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17fac0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fac4: 0xe6160014  swc1        $f22, 0x14($s0)
    ctx->pc = 0x17fac4u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 20), bits); }
    // 0x17fac8: 0xe6160000  swc1        $f22, 0x0($s0)
    ctx->pc = 0x17fac8u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x17facc: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x17faccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x17fad0: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x17fad0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x17fad4: 0xe600002c  swc1        $f0, 0x2C($s0)
    ctx->pc = 0x17fad4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 44), bits); }
    // 0x17fad8: 0xc05fcf4  jal         func_17F3D0
    ctx->pc = 0x17FAD8u;
    SET_GPR_U32(ctx, 31, 0x17FAE0u);
    ctx->pc = 0x17FADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FAD8u;
            // 0x17fadc: 0xe6000038  swc1        $f0, 0x38($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 56), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F3D0u;
    if (runtime->hasFunction(0x17F3D0u)) {
        auto targetFn = runtime->lookupFunction(0x17F3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAE0u; }
        if (ctx->pc != 0x17FAE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F3D0_0x17f3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAE0u; }
        if (ctx->pc != 0x17FAE0u) { return; }
    }
    ctx->pc = 0x17FAE0u;
label_17fae0:
    // 0x17fae0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17fae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fae4: 0xe7b80000  swc1        $f24, 0x0($sp)
    ctx->pc = 0x17fae4u;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x17fae8: 0xe7b70014  swc1        $f23, 0x14($sp)
    ctx->pc = 0x17fae8u;
    { float f = ctx->f[23]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 20), bits); }
    // 0x17faec: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17faecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17faf0: 0xe7b50028  swc1        $f21, 0x28($sp)
    ctx->pc = 0x17faf0u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x17faf4: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x17faf4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17faf8: 0xe7ba0030  swc1        $f26, 0x30($sp)
    ctx->pc = 0x17faf8u;
    { float f = ctx->f[26]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17fafc: 0xe7b90034  swc1        $f25, 0x34($sp)
    ctx->pc = 0x17fafcu;
    { float f = ctx->f[25]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 52), bits); }
    // 0x17fb00: 0xc05faca  jal         func_17EB28
    ctx->pc = 0x17FB00u;
    SET_GPR_U32(ctx, 31, 0x17FB08u);
    ctx->pc = 0x17FB04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FB00u;
            // 0x17fb04: 0xe7b40038  swc1        $f20, 0x38($sp) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 56), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EB28u;
    if (runtime->hasFunction(0x17EB28u)) {
        auto targetFn = runtime->lookupFunction(0x17EB28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FB08u; }
        if (ctx->pc != 0x17FB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EB28_0x17eb28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FB08u; }
        if (ctx->pc != 0x17FB08u) { return; }
    }
    ctx->pc = 0x17FB08u;
label_17fb08:
    // 0x17fb08: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x17fb08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17fb0c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17fb0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17fb10: 0xc7ba0090  lwc1        $f26, 0x90($sp)
    ctx->pc = 0x17fb10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 144)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[26] = f; }
    // 0x17fb14: 0xc7b90088  lwc1        $f25, 0x88($sp)
    ctx->pc = 0x17fb14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 136)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[25] = f; }
    // 0x17fb18: 0xc7b80080  lwc1        $f24, 0x80($sp)
    ctx->pc = 0x17fb18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 128)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[24] = f; }
    // 0x17fb1c: 0xc7b70078  lwc1        $f23, 0x78($sp)
    ctx->pc = 0x17fb1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 120)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[23] = f; }
    // 0x17fb20: 0xc7b60070  lwc1        $f22, 0x70($sp)
    ctx->pc = 0x17fb20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x17fb24: 0xc7b50068  lwc1        $f21, 0x68($sp)
    ctx->pc = 0x17fb24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 104)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17fb28: 0xc7b40060  lwc1        $f20, 0x60($sp)
    ctx->pc = 0x17fb28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 96)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17fb2c: 0x3e00008  jr          $ra
    ctx->pc = 0x17FB2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FB30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FB2Cu;
            // 0x17fb30: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FB34u;
    // 0x17fb34: 0x0  nop
    ctx->pc = 0x17fb34u;
    // NOP
    // 0x17fb38: 0x46006406  mov.s       $f16, $f12
    ctx->pc = 0x17fb38u;
    ctx->f[16] = FPU_MOV_S(ctx->f[12]);
    // 0x17fb3c: 0x10c0002a  beqz        $a2, . + 4 + (0x2A << 2)
    ctx->pc = 0x17FB3Cu;
    {
        const bool branch_taken_0x17fb3c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FB40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FB3Cu;
            // 0x17fb40: 0x46006bc6  mov.s       $f15, $f13 (Delay Slot)
        ctx->f[15] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17fb3c) {
            ctx->pc = 0x17FBE8u;
            goto label_17fbe8;
        }
    }
    ctx->pc = 0x17FB44u;
    // 0x17fb44: 0xc4a10000  lwc1        $f1, 0x0($a1)
    ctx->pc = 0x17fb44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17fb48: 0xc4a20004  lwc1        $f2, 0x4($a1)
    ctx->pc = 0x17fb48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x17fb4c: 0x46018242  mul.s       $f9, $f16, $f1
    ctx->pc = 0x17fb4cu;
    ctx->f[9] = FPU_MUL_S(ctx->f[16], ctx->f[1]);
    // 0x17fb50: 0xc4a30008  lwc1        $f3, 0x8($a1)
    ctx->pc = 0x17fb50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x17fb54: 0x46027a82  mul.s       $f10, $f15, $f2
    ctx->pc = 0x17fb54u;
    ctx->f[10] = FPU_MUL_S(ctx->f[15], ctx->f[2]);
    // 0x17fb58: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x17fb58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x17fb5c: 0x44812800  mtc1        $at, $f5
    ctx->pc = 0x17fb5cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x17fb60: 0x46037182  mul.s       $f6, $f14, $f3
    ctx->pc = 0x17fb60u;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[3]);
    // 0x17fb64: 0xe490000c  swc1        $f16, 0xC($a0)
    ctx->pc = 0x17fb64u;
    { float f = ctx->f[16]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 12), bits); }
    // 0x17fb68: 0x460009c7  neg.s       $f7, $f1
    ctx->pc = 0x17fb68u;
    ctx->f[7] = FPU_NEG_S(ctx->f[1]);
    // 0x17fb6c: 0xe48f001c  swc1        $f15, 0x1C($a0)
    ctx->pc = 0x17fb6cu;
    { float f = ctx->f[15]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 28), bits); }
    // 0x17fb70: 0x460a4800  add.s       $f0, $f9, $f10
    ctx->pc = 0x17fb70u;
    ctx->f[0] = FPU_ADD_S(ctx->f[9], ctx->f[10]);
    // 0x17fb74: 0xe48e002c  swc1        $f14, 0x2C($a0)
    ctx->pc = 0x17fb74u;
    { float f = ctx->f[14]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 44), bits); }
    // 0x17fb78: 0x46001107  neg.s       $f4, $f2
    ctx->pc = 0x17fb78u;
    ctx->f[4] = FPU_NEG_S(ctx->f[2]);
    // 0x17fb7c: 0xe4870030  swc1        $f7, 0x30($a0)
    ctx->pc = 0x17fb7cu;
    { float f = ctx->f[7]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x17fb80: 0x46001a07  neg.s       $f8, $f3
    ctx->pc = 0x17fb80u;
    ctx->f[8] = FPU_NEG_S(ctx->f[3]);
    // 0x17fb84: 0x46060000  add.s       $f0, $f0, $f6
    ctx->pc = 0x17fb84u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[6]);
    // 0x17fb88: 0xe4840034  swc1        $f4, 0x34($a0)
    ctx->pc = 0x17fb88u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x17fb8c: 0x460179c2  mul.s       $f7, $f15, $f1
    ctx->pc = 0x17fb8cu;
    ctx->f[7] = FPU_MUL_S(ctx->f[15], ctx->f[1]);
    // 0x17fb90: 0x46028102  mul.s       $f4, $f16, $f2
    ctx->pc = 0x17fb90u;
    ctx->f[4] = FPU_MUL_S(ctx->f[16], ctx->f[2]);
    // 0x17fb94: 0xe4880038  swc1        $f8, 0x38($a0)
    ctx->pc = 0x17fb94u;
    { float f = ctx->f[8]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
    // 0x17fb98: 0x46002801  sub.s       $f0, $f5, $f0
    ctx->pc = 0x17fb98u;
    ctx->f[0] = FPU_SUB_S(ctx->f[5], ctx->f[0]);
    // 0x17fb9c: 0x46017042  mul.s       $f1, $f14, $f1
    ctx->pc = 0x17fb9cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[14], ctx->f[1]);
    // 0x17fba0: 0xe4870010  swc1        $f7, 0x10($a0)
    ctx->pc = 0x17fba0u;
    { float f = ctx->f[7]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 16), bits); }
    // 0x17fba4: 0x46027082  mul.s       $f2, $f14, $f2
    ctx->pc = 0x17fba4u;
    ctx->f[2] = FPU_MUL_S(ctx->f[14], ctx->f[2]);
    // 0x17fba8: 0xe4840004  swc1        $f4, 0x4($a0)
    ctx->pc = 0x17fba8u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x17fbac: 0x46050141  sub.s       $f5, $f0, $f5
    ctx->pc = 0x17fbacu;
    ctx->f[5] = FPU_SUB_S(ctx->f[0], ctx->f[5]);
    // 0x17fbb0: 0x46004a40  add.s       $f9, $f9, $f0
    ctx->pc = 0x17fbb0u;
    ctx->f[9] = FPU_ADD_S(ctx->f[9], ctx->f[0]);
    // 0x17fbb4: 0xe4810020  swc1        $f1, 0x20($a0)
    ctx->pc = 0x17fbb4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 32), bits); }
    // 0x17fbb8: 0x46005280  add.s       $f10, $f10, $f0
    ctx->pc = 0x17fbb8u;
    ctx->f[10] = FPU_ADD_S(ctx->f[10], ctx->f[0]);
    // 0x17fbbc: 0xe4820024  swc1        $f2, 0x24($a0)
    ctx->pc = 0x17fbbcu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 36), bits); }
    // 0x17fbc0: 0x46003180  add.s       $f6, $f6, $f0
    ctx->pc = 0x17fbc0u;
    ctx->f[6] = FPU_ADD_S(ctx->f[6], ctx->f[0]);
    // 0x17fbc4: 0xe485003c  swc1        $f5, 0x3C($a0)
    ctx->pc = 0x17fbc4u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 60), bits); }
    // 0x17fbc8: 0x46038002  mul.s       $f0, $f16, $f3
    ctx->pc = 0x17fbc8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[16], ctx->f[3]);
    // 0x17fbcc: 0xe4890000  swc1        $f9, 0x0($a0)
    ctx->pc = 0x17fbccu;
    { float f = ctx->f[9]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x17fbd0: 0x460378c2  mul.s       $f3, $f15, $f3
    ctx->pc = 0x17fbd0u;
    ctx->f[3] = FPU_MUL_S(ctx->f[15], ctx->f[3]);
    // 0x17fbd4: 0xe48a0014  swc1        $f10, 0x14($a0)
    ctx->pc = 0x17fbd4u;
    { float f = ctx->f[10]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 20), bits); }
    // 0x17fbd8: 0xe4860028  swc1        $f6, 0x28($a0)
    ctx->pc = 0x17fbd8u;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
    // 0x17fbdc: 0xe4800008  swc1        $f0, 0x8($a0)
    ctx->pc = 0x17fbdcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x17fbe0: 0x3e00008  jr          $ra
    ctx->pc = 0x17FBE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FBE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FBE0u;
            // 0x17fbe4: 0xe4830018  swc1        $f3, 0x18($a0) (Delay Slot)
        { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 24), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FBE8u;
label_17fbe8:
    // 0x17fbe8: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x17fbe8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x17fbec: 0xc4a40004  lwc1        $f4, 0x4($a1)
    ctx->pc = 0x17fbecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x17fbf0: 0x46028142  mul.s       $f5, $f16, $f2
    ctx->pc = 0x17fbf0u;
    ctx->f[5] = FPU_MUL_S(ctx->f[16], ctx->f[2]);
    // 0x17fbf4: 0xc4a70008  lwc1        $f7, 0x8($a1)
    ctx->pc = 0x17fbf4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x17fbf8: 0x46047982  mul.s       $f6, $f15, $f4
    ctx->pc = 0x17fbf8u;
    ctx->f[6] = FPU_MUL_S(ctx->f[15], ctx->f[4]);
    // 0x17fbfc: 0x3c01bf80  lui         $at, 0xBF80
    ctx->pc = 0x17fbfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49024 << 16));
    // 0x17fc00: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17fc00u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17fc04: 0x46077202  mul.s       $f8, $f14, $f7
    ctx->pc = 0x17fc04u;
    ctx->f[8] = FPU_MUL_S(ctx->f[14], ctx->f[7]);
    // 0x17fc08: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x17fc08u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x17fc0c: 0x46001247  neg.s       $f9, $f2
    ctx->pc = 0x17fc0cu;
    ctx->f[9] = FPU_NEG_S(ctx->f[2]);
    // 0x17fc10: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x17fc10u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x17fc14: 0x46062800  add.s       $f0, $f5, $f6
    ctx->pc = 0x17fc14u;
    ctx->f[0] = FPU_ADD_S(ctx->f[5], ctx->f[6]);
    // 0x17fc18: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x17fc18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x17fc1c: 0x46047282  mul.s       $f10, $f14, $f4
    ctx->pc = 0x17fc1cu;
    ctx->f[10] = FPU_MUL_S(ctx->f[14], ctx->f[4]);
    // 0x17fc20: 0x460022c7  neg.s       $f11, $f4
    ctx->pc = 0x17fc20u;
    ctx->f[11] = FPU_NEG_S(ctx->f[4]);
    // 0x17fc24: 0x46080000  add.s       $f0, $f0, $f8
    ctx->pc = 0x17fc24u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[8]);
    // 0x17fc28: 0x460278c2  mul.s       $f3, $f15, $f2
    ctx->pc = 0x17fc28u;
    ctx->f[3] = FPU_MUL_S(ctx->f[15], ctx->f[2]);
    // 0x17fc2c: 0x46078302  mul.s       $f12, $f16, $f7
    ctx->pc = 0x17fc2cu;
    ctx->f[12] = FPU_MUL_S(ctx->f[16], ctx->f[7]);
    // 0x17fc30: 0x0  nop
    ctx->pc = 0x17fc30u;
    // NOP
    // 0x17fc34: 0x0  nop
    ctx->pc = 0x17fc34u;
    // NOP
    // 0x17fc38: 0x46000843  div.s       $f1, $f1, $f0
    ctx->pc = 0x17fc38u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[0];
    // 0x17fc3c: 0x46002941  sub.s       $f5, $f5, $f0
    ctx->pc = 0x17fc3cu;
    ctx->f[5] = FPU_SUB_S(ctx->f[5], ctx->f[0]);
    // 0x17fc40: 0x46003181  sub.s       $f6, $f6, $f0
    ctx->pc = 0x17fc40u;
    ctx->f[6] = FPU_SUB_S(ctx->f[6], ctx->f[0]);
    // 0x17fc44: 0x46004201  sub.s       $f8, $f8, $f0
    ctx->pc = 0x17fc44u;
    ctx->f[8] = FPU_SUB_S(ctx->f[8], ctx->f[0]);
    // 0x17fc48: 0x46077b42  mul.s       $f13, $f15, $f7
    ctx->pc = 0x17fc48u;
    ctx->f[13] = FPU_MUL_S(ctx->f[15], ctx->f[7]);
    // 0x17fc4c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x17fc4cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x17fc50: 0x46027082  mul.s       $f2, $f14, $f2
    ctx->pc = 0x17fc50u;
    ctx->f[2] = FPU_MUL_S(ctx->f[14], ctx->f[2]);
    // 0x17fc54: 0x46048102  mul.s       $f4, $f16, $f4
    ctx->pc = 0x17fc54u;
    ctx->f[4] = FPU_MUL_S(ctx->f[16], ctx->f[4]);
    // 0x17fc58: 0x460039c7  neg.s       $f7, $f7
    ctx->pc = 0x17fc58u;
    ctx->f[7] = FPU_NEG_S(ctx->f[7]);
    // 0x17fc5c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x17fc5cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x17fc60: 0x46050942  mul.s       $f5, $f1, $f5
    ctx->pc = 0x17fc60u;
    ctx->f[5] = FPU_MUL_S(ctx->f[1], ctx->f[5]);
    // 0x17fc64: 0x460308c2  mul.s       $f3, $f1, $f3
    ctx->pc = 0x17fc64u;
    ctx->f[3] = FPU_MUL_S(ctx->f[1], ctx->f[3]);
    // 0x17fc68: 0x46020882  mul.s       $f2, $f1, $f2
    ctx->pc = 0x17fc68u;
    ctx->f[2] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x17fc6c: 0xe480003c  swc1        $f0, 0x3C($a0)
    ctx->pc = 0x17fc6cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 60), bits); }
    // 0x17fc70: 0x46090a42  mul.s       $f9, $f1, $f9
    ctx->pc = 0x17fc70u;
    ctx->f[9] = FPU_MUL_S(ctx->f[1], ctx->f[9]);
    // 0x17fc74: 0xe4850000  swc1        $f5, 0x0($a0)
    ctx->pc = 0x17fc74u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x17fc78: 0x46040902  mul.s       $f4, $f1, $f4
    ctx->pc = 0x17fc78u;
    ctx->f[4] = FPU_MUL_S(ctx->f[1], ctx->f[4]);
    // 0x17fc7c: 0xe4830010  swc1        $f3, 0x10($a0)
    ctx->pc = 0x17fc7cu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 16), bits); }
    // 0x17fc80: 0x46060982  mul.s       $f6, $f1, $f6
    ctx->pc = 0x17fc80u;
    ctx->f[6] = FPU_MUL_S(ctx->f[1], ctx->f[6]);
    // 0x17fc84: 0xe4820020  swc1        $f2, 0x20($a0)
    ctx->pc = 0x17fc84u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 32), bits); }
    // 0x17fc88: 0x460a0a82  mul.s       $f10, $f1, $f10
    ctx->pc = 0x17fc88u;
    ctx->f[10] = FPU_MUL_S(ctx->f[1], ctx->f[10]);
    // 0x17fc8c: 0xe4890030  swc1        $f9, 0x30($a0)
    ctx->pc = 0x17fc8cu;
    { float f = ctx->f[9]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 48), bits); }
    // 0x17fc90: 0x460b0ac2  mul.s       $f11, $f1, $f11
    ctx->pc = 0x17fc90u;
    ctx->f[11] = FPU_MUL_S(ctx->f[1], ctx->f[11]);
    // 0x17fc94: 0xe4840004  swc1        $f4, 0x4($a0)
    ctx->pc = 0x17fc94u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x17fc98: 0x460c0b02  mul.s       $f12, $f1, $f12
    ctx->pc = 0x17fc98u;
    ctx->f[12] = FPU_MUL_S(ctx->f[1], ctx->f[12]);
    // 0x17fc9c: 0xe4860014  swc1        $f6, 0x14($a0)
    ctx->pc = 0x17fc9cu;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 20), bits); }
    // 0x17fca0: 0x460d0b42  mul.s       $f13, $f1, $f13
    ctx->pc = 0x17fca0u;
    ctx->f[13] = FPU_MUL_S(ctx->f[1], ctx->f[13]);
    // 0x17fca4: 0xe48a0024  swc1        $f10, 0x24($a0)
    ctx->pc = 0x17fca4u;
    { float f = ctx->f[10]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 36), bits); }
    // 0x17fca8: 0x46080a02  mul.s       $f8, $f1, $f8
    ctx->pc = 0x17fca8u;
    ctx->f[8] = FPU_MUL_S(ctx->f[1], ctx->f[8]);
    // 0x17fcac: 0xe48b0034  swc1        $f11, 0x34($a0)
    ctx->pc = 0x17fcacu;
    { float f = ctx->f[11]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 52), bits); }
    // 0x17fcb0: 0x46070842  mul.s       $f1, $f1, $f7
    ctx->pc = 0x17fcb0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[7]);
    // 0x17fcb4: 0xe48c0008  swc1        $f12, 0x8($a0)
    ctx->pc = 0x17fcb4u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x17fcb8: 0xe48d0018  swc1        $f13, 0x18($a0)
    ctx->pc = 0x17fcb8u;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 24), bits); }
    // 0x17fcbc: 0xe4880028  swc1        $f8, 0x28($a0)
    ctx->pc = 0x17fcbcu;
    { float f = ctx->f[8]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 40), bits); }
    // 0x17fcc0: 0x3e00008  jr          $ra
    ctx->pc = 0x17FCC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FCC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FCC0u;
            // 0x17fcc4: 0xe4810038  swc1        $f1, 0x38($a0) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 56), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FCC8u;
    // 0x17fcc8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17fcc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17fccc: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x17fcccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x17fcd0: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x17fcd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x17fcd4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x17fcd4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fcd8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17fcd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17fcdc: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x17fcdcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fce0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17fce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17fce4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17fce4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fce8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17fce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17fcec: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x17fcecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fcf0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17fcf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x17fcf4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FCF4u;
    SET_GPR_U32(ctx, 31, 0x17FCFCu);
    ctx->pc = 0x17FCF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FCF4u;
            // 0x17fcf8: 0x100802d  daddu       $s0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FCFCu; }
        if (ctx->pc != 0x17FCFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FCFCu; }
        if (ctx->pc != 0x17FCFCu) { return; }
    }
    ctx->pc = 0x17FCFCu;
label_17fcfc:
    // 0x17fcfc: 0xda640000  lqc2        $vf4, 0x0($s3)
    ctx->pc = 0x17fcfcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x17fd00: 0xda650010  lqc2        $vf5, 0x10($s3)
    ctx->pc = 0x17fd00u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x17fd04: 0xda660020  lqc2        $vf6, 0x20($s3)
    ctx->pc = 0x17fd04u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 19), 32)));
    // 0x17fd08: 0xda670030  lqc2        $vf7, 0x30($s3)
    ctx->pc = 0x17fd08u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 19), 48)));
label_17fd0c:
    // 0x17fd0c: 0xda480000  lqc2        $vf8, 0x0($s2)
    ctx->pc = 0x17fd0cu;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x17fd10: 0x4be821bc  vmulax.xyzw $ACC, $vf4, $vf8x
    ctx->pc = 0x17fd10u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x17fd14: 0x4be828bd  vmadday.xyzw $ACC, $vf5, $vf8y
    ctx->pc = 0x17fd14u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17fd18: 0x4be830be  vmaddaz.xyzw $ACC, $vf6, $vf8z
    ctx->pc = 0x17fd18u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17fd1c: 0x4be83a4b  vmaddw.xyzw $vf9, $vf7, $vf8w
    ctx->pc = 0x17fd1cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x17fd20: 0x4be903bc  vdiv        $Q, $vf0w, $vf9w
    ctx->pc = 0x17fd20u;
    { float fs = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,3))); float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,3))); if (ft != 0.0f) { ctx->vu0_q = fs / ft; } else { uint32_t sign = (std::bit_cast<uint32_t>(fs) ^ std::bit_cast<uint32_t>(ft)) & 0x80000000u; uint32_t maxf = 0x7F7FFFFFu | sign; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x17fd24: 0x4a0003bf  vwaitq
    ctx->pc = 0x17fd24u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x17fd28: 0x4bc04a5c  vmulq.xyz   $vf9, $vf9, $Q
    ctx->pc = 0x17fd28u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[9], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x17fd2c: 0x12000002  beqz        $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x17FD2Cu;
    {
        const bool branch_taken_0x17fd2c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FD30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FD2Cu;
            // 0x17fd30: 0x4bea497d  vftoi4.xyzw $vf10, $vf9 (Delay Slot)
        { __m128 src = ctx->vu0_vf[9]; src = _mm_mul_ps(src, _mm_set1_ps(16.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x17fd2c) {
            ctx->pc = 0x17FD38u;
            goto label_17fd38;
        }
    }
    ctx->pc = 0x17FD34u;
    // 0x17fd34: 0x4a6a497c  vftoi0.zw   $vf10, $vf9
    ctx->pc = 0x17fd34u;
    { __m128 src = ctx->vu0_vf[9]; src = _mm_mul_ps(src, _mm_set1_ps(1.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
label_17fd38:
    // 0x17fd38: 0xfa8a0000  sqc2        $vf10, 0x0($s4)
    ctx->pc = 0x17fd38u;
    WRITE128(ADD32(GPR_U32(ctx, 20), 0), _mm_castps_si128(ctx->vu0_vf[10]));
    // 0x17fd3c: 0x2231ffff  addi        $s1, $s1, -0x1
    ctx->pc = 0x17fd3cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 17), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 17, (int32_t)tmp); }
    // 0x17fd40: 0x22520010  addi        $s2, $s2, 0x10
    ctx->pc = 0x17fd40u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 18), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 18, (int32_t)tmp); }
    // 0x17fd44: 0x1411fff1  bne         $zero, $s1, . + 4 + (-0xF << 2)
    ctx->pc = 0x17FD44u;
    {
        const bool branch_taken_0x17fd44 = (GPR_U64(ctx, 0) != GPR_U64(ctx, 17));
        ctx->pc = 0x17FD48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FD44u;
            // 0x17fd48: 0x22940010  addi        $s4, $s4, 0x10 (Delay Slot)
        { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 20), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 20, (int32_t)tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x17fd44) {
            ctx->pc = 0x17FD0Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17fd0c;
        }
    }
    ctx->pc = 0x17FD4Cu;
    // 0x17fd4c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17FD4Cu;
    {
        const bool branch_taken_0x17fd4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FD50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FD4Cu;
            // 0x17fd50: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17fd4c) {
            ctx->pc = 0x17FD70u;
            goto label_17fd70;
        }
    }
    ctx->pc = 0x17FD54u;
    // 0x17fd54: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x17fd54u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17fd58: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x17fd58u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17fd5c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17fd5cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17fd60: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17fd60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17fd64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17fd64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fd68: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17FD68u;
    ctx->pc = 0x17FD6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FD68u;
            // 0x17fd6c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17FD70u;
label_17fd70:
    // 0x17fd70: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x17fd70u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17fd74: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x17fd74u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17fd78: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17fd78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17fd7c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17fd7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17fd80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17fd80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fd84: 0x3e00008  jr          $ra
    ctx->pc = 0x17FD84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FD88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FD84u;
            // 0x17fd88: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FD8Cu;
    // 0x17fd8c: 0x0  nop
    ctx->pc = 0x17fd8cu;
    // NOP
    // 0x17fd90: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17fd90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17fd94: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x17fd94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x17fd98: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17fd98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17fd9c: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x17fd9cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fda0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17fda0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17fda4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x17fda4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fda8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17fda8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17fdac: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17fdacu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fdb0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17fdb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17fdb4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FDB4u;
    SET_GPR_U32(ctx, 31, 0x17FDBCu);
    ctx->pc = 0x17FDB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FDB4u;
            // 0x17fdb8: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FDBCu; }
        if (ctx->pc != 0x17FDBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FDBCu; }
        if (ctx->pc != 0x17FDBCu) { return; }
    }
    ctx->pc = 0x17FDBCu;
label_17fdbc:
    // 0x17fdbc: 0xda440000  lqc2        $vf4, 0x0($s2)
    ctx->pc = 0x17fdbcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x17fdc0: 0xda450010  lqc2        $vf5, 0x10($s2)
    ctx->pc = 0x17fdc0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x17fdc4: 0xda460020  lqc2        $vf6, 0x20($s2)
    ctx->pc = 0x17fdc4u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x17fdc8: 0xda470030  lqc2        $vf7, 0x30($s2)
    ctx->pc = 0x17fdc8u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x17fdcc: 0xda280000  lqc2        $vf8, 0x0($s1)
    ctx->pc = 0x17fdccu;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17fdd0: 0x4be821bc  vmulax.xyzw $ACC, $vf4, $vf8x
    ctx->pc = 0x17fdd0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x17fdd4: 0x4be828bd  vmadday.xyzw $ACC, $vf5, $vf8y
    ctx->pc = 0x17fdd4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17fdd8: 0x4be830be  vmaddaz.xyzw $ACC, $vf6, $vf8z
    ctx->pc = 0x17fdd8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17fddc: 0x4be83a4b  vmaddw.xyzw $vf9, $vf7, $vf8w
    ctx->pc = 0x17fddcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x17fde0: 0x4be903bc  vdiv        $Q, $vf0w, $vf9w
    ctx->pc = 0x17fde0u;
    { float fs = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,3))); float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,3))); if (ft != 0.0f) { ctx->vu0_q = fs / ft; } else { uint32_t sign = (std::bit_cast<uint32_t>(fs) ^ std::bit_cast<uint32_t>(ft)) & 0x80000000u; uint32_t maxf = 0x7F7FFFFFu | sign; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x17fde4: 0x4a0003bf  vwaitq
    ctx->pc = 0x17fde4u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x17fde8: 0x4bc04a5c  vmulq.xyz   $vf9, $vf9, $Q
    ctx->pc = 0x17fde8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[9], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x17fdec: 0x12000002  beqz        $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x17FDECu;
    {
        const bool branch_taken_0x17fdec = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FDF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FDECu;
            // 0x17fdf0: 0x4bea497d  vftoi4.xyzw $vf10, $vf9 (Delay Slot)
        { __m128 src = ctx->vu0_vf[9]; src = _mm_mul_ps(src, _mm_set1_ps(16.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x17fdec) {
            ctx->pc = 0x17FDF8u;
            goto label_17fdf8;
        }
    }
    ctx->pc = 0x17FDF4u;
    // 0x17fdf4: 0x4a6a497c  vftoi0.zw   $vf10, $vf9
    ctx->pc = 0x17fdf4u;
    { __m128 src = ctx->vu0_vf[9]; src = _mm_mul_ps(src, _mm_set1_ps(1.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, 0, 0); ctx->vu0_vf[10] = _mm_blendv_ps(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
label_17fdf8:
    // 0x17fdf8: 0xfa6a0000  sqc2        $vf10, 0x0($s3)
    ctx->pc = 0x17fdf8u;
    WRITE128(ADD32(GPR_U32(ctx, 19), 0), _mm_castps_si128(ctx->vu0_vf[10]));
    // 0x17fdfc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17FDFCu;
    {
        const bool branch_taken_0x17fdfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FE00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FDFCu;
            // 0x17fe00: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17fdfc) {
            ctx->pc = 0x17FE1Cu;
            goto label_17fe1c;
        }
    }
    ctx->pc = 0x17FE04u;
    // 0x17fe04: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x17fe04u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17fe08: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17fe08u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17fe0c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17fe0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17fe10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17fe10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fe14: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17FE14u;
    ctx->pc = 0x17FE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FE14u;
            // 0x17fe18: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17FE1Cu;
label_17fe1c:
    // 0x17fe1c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x17fe1cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17fe20: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17fe20u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17fe24: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17fe24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17fe28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17fe28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fe2c: 0x3e00008  jr          $ra
    ctx->pc = 0x17FE2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FE2Cu;
            // 0x17fe30: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FE34u;
    // 0x17fe34: 0x0  nop
    ctx->pc = 0x17fe34u;
    // NOP
    // 0x17fe38: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x17fe38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x17fe3c: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x17fe3cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x17fe40: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x17fe40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17fe44: 0xe4810004  swc1        $f1, 0x4($a0)
    ctx->pc = 0x17fe44u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x17fe48: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x17fe48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x17fe4c: 0x3e00008  jr          $ra
    ctx->pc = 0x17FE4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FE4Cu;
            // 0x17fe50: 0xe4800008  swc1        $f0, 0x8($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FE54u;
    // 0x17fe54: 0x0  nop
    ctx->pc = 0x17fe54u;
    // NOP
    // 0x17fe58: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17fe58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17fe5c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17fe5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17fe60: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17fe60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17fe64: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17fe64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fe68: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17fe68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17fe6c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17fe6cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fe70: 0xe7b40040  swc1        $f20, 0x40($sp)
    ctx->pc = 0x17fe70u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x17fe74: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x17fe74u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fe78: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17fe78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17fe7c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FE7Cu;
    SET_GPR_U32(ctx, 31, 0x17FE84u);
    ctx->pc = 0x17FE80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FE7Cu;
            // 0x17fe80: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FE84u; }
        if (ctx->pc != 0x17FE84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FE84u; }
        if (ctx->pc != 0x17FE84u) { return; }
    }
    ctx->pc = 0x17FE84u;
label_17fe84:
    // 0x17fe84: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17fe84u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17fe88: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17fe88u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17fe8c: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17fe8cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17fe90: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x17fe90u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17fe94: 0x4a29233c  vmove.w     $vf9, $vf4
    ctx->pc = 0x17fe94u;
    { __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], ctx->vu0_vf[4], _mm_castsi128_ps(mask)); }
    // 0x17fe98: 0x4b0001c3  vaddw.x     $vf7, $vf0, $vf0w
    ctx->pc = 0x17fe98u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x17fe9c: 0x4b063a2c  vsub.x      $vf8, $vf7, $vf6
    ctx->pc = 0x17fe9cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = PS2_VBLEND(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x17fea0: 0x4bc621bc  vmulax.xyz  $ACC, $vf4, $vf6x
    ctx->pc = 0x17fea0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x17fea4: 0x4bc82a48  vmaddx.xyz  $vf9, $vf5, $vf8x
    ctx->pc = 0x17fea4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x17fea8: 0xfa490000  sqc2        $vf9, 0x0($s2)
    ctx->pc = 0x17fea8u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x17feac: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17FEACu;
    {
        const bool branch_taken_0x17feac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FEB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FEACu;
            // 0x17feb0: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17feac) {
            ctx->pc = 0x17FECCu;
            goto label_17fecc;
        }
    }
    ctx->pc = 0x17FEB4u;
    // 0x17feb4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17feb4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17feb8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17feb8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17febc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17febcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fec0: 0xc7b40040  lwc1        $f20, 0x40($sp)
    ctx->pc = 0x17fec0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17fec4: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17FEC4u;
    ctx->pc = 0x17FEC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FEC4u;
            // 0x17fec8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17FECCu;
label_17fecc:
    // 0x17fecc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17feccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17fed0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17fed0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17fed4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17fed4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fed8: 0xc7b40040  lwc1        $f20, 0x40($sp)
    ctx->pc = 0x17fed8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17fedc: 0x3e00008  jr          $ra
    ctx->pc = 0x17FEDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FEDCu;
            // 0x17fee0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FEE4u;
    // 0x17fee4: 0x0  nop
    ctx->pc = 0x17fee4u;
    // NOP
    // 0x17fee8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17fee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17feec: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17feecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17fef0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17fef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17fef4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17fef4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fef8: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17fef8u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17fefc: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17fefcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ff00: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17ff00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17ff04: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FF04u;
    SET_GPR_U32(ctx, 31, 0x17FF0Cu);
    ctx->pc = 0x17FF08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF04u;
            // 0x17ff08: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF0Cu; }
        if (ctx->pc != 0x17FF0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF0Cu; }
        if (ctx->pc != 0x17FF0Cu) { return; }
    }
    ctx->pc = 0x17FF0Cu;
label_17ff0c:
    // 0x17ff0c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17ff0cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ff10: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17ff10u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17ff14: 0x48a82800  qmtc2.ni    $t0, $vf5
    ctx->pc = 0x17ff14u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17ff18: 0x4bc52118  vmulx.xyz   $vf4, $vf4, $vf5x
    ctx->pc = 0x17ff18u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17ff1c: 0xfa240000  sqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17ff1cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x17ff20: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17FF20u;
    {
        const bool branch_taken_0x17ff20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FF24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF20u;
            // 0x17ff24: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ff20) {
            ctx->pc = 0x17FF3Cu;
            goto label_17ff3c;
        }
    }
    ctx->pc = 0x17FF28u;
    // 0x17ff28: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ff28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ff2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ff2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ff30: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17ff30u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ff34: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17FF34u;
    ctx->pc = 0x17FF38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF34u;
            // 0x17ff38: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17FF3Cu;
label_17ff3c:
    // 0x17ff3c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ff3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ff40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ff40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ff44: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17ff44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ff48: 0x3e00008  jr          $ra
    ctx->pc = 0x17FF48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FF4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF48u;
            // 0x17ff4c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FF50u;
    // 0x17ff50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17ff50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17ff54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ff54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ff58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17ff58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17ff5c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FF5Cu;
    SET_GPR_U32(ctx, 31, 0x17FF64u);
    ctx->pc = 0x17FF60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF5Cu;
            // 0x17ff60: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF64u; }
        if (ctx->pc != 0x17FF64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF64u; }
        if (ctx->pc != 0x17FF64u) { return; }
    }
    ctx->pc = 0x17FF64u;
label_17ff64:
    // 0x17ff64: 0x4be0012c  vsub.xyzw   $vf4, $vf0, $vf0
    ctx->pc = 0x17ff64u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17ff68: 0x3c034580  lui         $v1, 0x4580
    ctx->pc = 0x17ff68u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17792 << 16));
    // 0x17ff6c: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x17ff6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x17ff70: 0x34634580  ori         $v1, $v1, 0x4580
    ctx->pc = 0x17ff70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17792);
    // 0x17ff74: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x17ff74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x17ff78: 0xda070000  lqc2        $vf7, 0x0($s0)
    ctx->pc = 0x17ff78u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ff7c: 0x48a33000  qmtc2.ni    $v1, $vf6
    ctx->pc = 0x17ff7cu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 3));
    // 0x17ff80: 0x48c08000  ctc2.ni     $zero, $vi16
    ctx->pc = 0x17ff80u;
    ctx->vu0_vpu_stat4 = GPR_U32(ctx, 0);
    // 0x17ff84: 0x4ba4396c  vsub.xyw    $vf5, $vf7, $vf4
    ctx->pc = 0x17ff84u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ff88: 0x4b87316c  vsub.xy     $vf5, $vf6, $vf7
    ctx->pc = 0x17ff88u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[6], ctx->vu0_vf[7]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ff8c: 0x4a0002ff  vnop
    ctx->pc = 0x17ff8cu;
    // NOP operation, no action needed for VU0
    // 0x17ff90: 0x4a0002ff  vnop
    ctx->pc = 0x17ff90u;
    // NOP operation, no action needed for VU0
    // 0x17ff94: 0x4a0002ff  vnop
    ctx->pc = 0x17ff94u;
    // NOP operation, no action needed for VU0
    // 0x17ff98: 0x4a0002ff  vnop
    ctx->pc = 0x17ff98u;
    // NOP operation, no action needed for VU0
    // 0x17ff9c: 0x4a0002ff  vnop
    ctx->pc = 0x17ff9cu;
    // NOP operation, no action needed for VU0
    // 0x17ffa0: 0x48438000  cfc2.ni     $v1, $vi16
    ctx->pc = 0x17ffa0u;
    SET_GPR_U32(ctx, 3, ctx->vu0_vpu_stat4);
    // 0x17ffa4: 0x306300c0  andi        $v1, $v1, 0xC0
    ctx->pc = 0x17ffa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)192);
    // 0x17ffa8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17FFA8u;
    {
        const bool branch_taken_0x17ffa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FFACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FFA8u;
            // 0x17ffac: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ffa8) {
            ctx->pc = 0x17FFB8u;
            goto label_17ffb8;
        }
    }
    ctx->pc = 0x17FFB0u;
    // 0x17ffb0: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x17FFB0u;
    SET_GPR_U32(ctx, 31, 0x17FFB8u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFB8u; }
        if (ctx->pc != 0x17FFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFB8u; }
        if (ctx->pc != 0x17FFB8u) { return; }
    }
    ctx->pc = 0x17FFB8u;
label_17ffb8:
    // 0x17ffb8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x17ffb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ffbc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17ffbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ffc0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ffc0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ffc4: 0x3e00008  jr          $ra
    ctx->pc = 0x17FFC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FFC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FFC4u;
            // 0x17ffc8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FFCCu;
    // 0x17ffcc: 0x0  nop
    ctx->pc = 0x17ffccu;
    // NOP
    // 0x17ffd0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17ffd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17ffd4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17ffd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17ffd8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ffd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ffdc: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17ffdcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ffe0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ffe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ffe4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17ffe4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ffe8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17ffe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17ffec: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FFECu;
    SET_GPR_U32(ctx, 31, 0x17FFF4u);
    ctx->pc = 0x17FFF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FFECu;
            // 0x17fff0: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFF4u; }
        if (ctx->pc != 0x17FFF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFF4u; }
        if (ctx->pc != 0x17FFF4u) { return; }
    }
    ctx->pc = 0x17FFF4u;
label_17fff4:
    // 0x17fff4: 0x4be0012c  vsub.xyzw   $vf4, $vf0, $vf0
    ctx->pc = 0x17fff4u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17fff8: 0x3c034580  lui         $v1, 0x4580
    ctx->pc = 0x17fff8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17792 << 16));
    // 0x17fffc: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x17fffcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x180000: 0x34634580  ori         $v1, $v1, 0x4580
    ctx->pc = 0x180000u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17792);
    // 0x180004: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x180004u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x180008: 0xda460000  lqc2        $vf6, 0x0($s2)
    ctx->pc = 0x180008u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18000c: 0xda280000  lqc2        $vf8, 0x0($s1)
    ctx->pc = 0x18000cu;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x180010: 0xda090000  lqc2        $vf9, 0x0($s0)
    ctx->pc = 0x180010u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x180014: 0x48a33800  qmtc2.ni    $v1, $vf7
    ctx->pc = 0x180014u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(GPR_VEC(ctx, 3));
    // 0x180018: 0x48c08000  ctc2.ni     $zero, $vi16
    ctx->pc = 0x180018u;
    ctx->vu0_vpu_stat4 = GPR_U32(ctx, 0);
    // 0x18001c: 0x4ba4316c  vsub.xyw    $vf5, $vf6, $vf4
    ctx->pc = 0x18001cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[6], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180020: 0x4b86396c  vsub.xy     $vf5, $vf7, $vf6
    ctx->pc = 0x180020u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180024: 0x4ba4416c  vsub.xyw    $vf5, $vf8, $vf4
    ctx->pc = 0x180024u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[8], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180028: 0x4b88396c  vsub.xy     $vf5, $vf7, $vf8
    ctx->pc = 0x180028u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[8]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18002c: 0x4ba4496c  vsub.xyw    $vf5, $vf9, $vf4
    ctx->pc = 0x18002cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[9], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180030: 0x4b89396c  vsub.xy     $vf5, $vf7, $vf9
    ctx->pc = 0x180030u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[9]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180034: 0x4a0002ff  vnop
    ctx->pc = 0x180034u;
    // NOP operation, no action needed for VU0
    // 0x180038: 0x4a0002ff  vnop
    ctx->pc = 0x180038u;
    // NOP operation, no action needed for VU0
    // 0x18003c: 0x4a0002ff  vnop
    ctx->pc = 0x18003cu;
    // NOP operation, no action needed for VU0
    // 0x180040: 0x4a0002ff  vnop
    ctx->pc = 0x180040u;
    // NOP operation, no action needed for VU0
    // 0x180044: 0x4a0002ff  vnop
    ctx->pc = 0x180044u;
    // NOP operation, no action needed for VU0
    // 0x180048: 0x48438000  cfc2.ni     $v1, $vi16
    ctx->pc = 0x180048u;
    SET_GPR_U32(ctx, 3, ctx->vu0_vpu_stat4);
    // 0x18004c: 0x306300c0  andi        $v1, $v1, 0xC0
    ctx->pc = 0x18004cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)192);
    // 0x180050: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x180050u;
    {
        const bool branch_taken_0x180050 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x180054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180050u;
            // 0x180054: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180050) {
            ctx->pc = 0x180060u;
            goto label_180060;
        }
    }
    ctx->pc = 0x180058u;
    // 0x180058: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x180058u;
    SET_GPR_U32(ctx, 31, 0x180060u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180060u; }
        if (ctx->pc != 0x180060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180060u; }
        if (ctx->pc != 0x180060u) { return; }
    }
    ctx->pc = 0x180060u;
label_180060:
    // 0x180060: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x180060u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180064: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x180064u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x180068: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x180068u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18006c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x18006cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180070: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180070u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180074: 0x3e00008  jr          $ra
    ctx->pc = 0x180074u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180074u;
            // 0x180078: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18007Cu;
    // 0x18007c: 0x0  nop
    ctx->pc = 0x18007cu;
    // NOP
    // 0x180080: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x180080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x180084: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x180084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x180088: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x180088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x18008c: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x18008cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180090: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x180090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x180094: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x180094u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180098: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x180098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x18009c: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x18009cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1800a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1800a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1800a4: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1800a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1800a8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1800a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1800ac: 0xc047598  jal         func_11D660
    ctx->pc = 0x1800ACu;
    SET_GPR_U32(ctx, 31, 0x1800B4u);
    ctx->pc = 0x1800B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1800ACu;
            // 0x1800b0: 0x100802d  daddu       $s0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1800B4u; }
        if (ctx->pc != 0x1800B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1800B4u; }
        if (ctx->pc != 0x1800B4u) { return; }
    }
    ctx->pc = 0x1800B4u;
label_1800b4:
    // 0x1800b4: 0xda280000  lqc2        $vf8, 0x0($s1)
    ctx->pc = 0x1800b4u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1800b8: 0xda440000  lqc2        $vf4, 0x0($s2)
    ctx->pc = 0x1800b8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1800bc: 0xda450010  lqc2        $vf5, 0x10($s2)
    ctx->pc = 0x1800bcu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1800c0: 0xda460020  lqc2        $vf6, 0x20($s2)
    ctx->pc = 0x1800c0u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x1800c4: 0xda470030  lqc2        $vf7, 0x30($s2)
    ctx->pc = 0x1800c4u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x1800c8: 0xda890000  lqc2        $vf9, 0x0($s4)
    ctx->pc = 0x1800c8u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1800cc: 0xda6a0000  lqc2        $vf10, 0x0($s3)
    ctx->pc = 0x1800ccu;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1800d0: 0xda8b0000  lqc2        $vf11, 0x0($s4)
    ctx->pc = 0x1800d0u;
    ctx->vu0_vf[11] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1800d4: 0xda6c0000  lqc2        $vf12, 0x0($s3)
    ctx->pc = 0x1800d4u;
    ctx->vu0_vf[12] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 19), 0)));
label_1800d8:
    // 0x1800d8: 0x4be821bc  vmulax.xyzw $ACC, $vf4, $vf8x
    ctx->pc = 0x1800d8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x1800dc: 0x4be828bd  vmadday.xyzw $ACC, $vf5, $vf8y
    ctx->pc = 0x1800dcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1800e0: 0x4be830be  vmaddaz.xyzw $ACC, $vf6, $vf8z
    ctx->pc = 0x1800e0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x1800e4: 0x4be83a0b  vmaddw.xyzw $vf8, $vf7, $vf8w
    ctx->pc = 0x1800e4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x1800e8: 0x4bc84adb  vmulw.xyz   $vf11, $vf9, $vf8w
    ctx->pc = 0x1800e8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x1800ec: 0x4bc8531b  vmulw.xyz   $vf12, $vf10, $vf8w
    ctx->pc = 0x1800ecu;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x1800f0: 0x4a0002ff  vnop
    ctx->pc = 0x1800f0u;
    // NOP operation, no action needed for VU0
    // 0x1800f4: 0x4a0002ff  vnop
    ctx->pc = 0x1800f4u;
    // NOP operation, no action needed for VU0
    // 0x1800f8: 0x48c08000  ctc2.ni     $zero, $vi16
    ctx->pc = 0x1800f8u;
    ctx->vu0_vpu_stat4 = GPR_U32(ctx, 0);
    // 0x1800fc: 0x4bab42ec  vsub.xyw    $vf11, $vf8, $vf11
    ctx->pc = 0x1800fcu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[8], ctx->vu0_vf[11]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[11] = PS2_VBLEND(ctx->vu0_vf[11], res, _mm_castsi128_ps(mask)); }
    // 0x180100: 0x4ba8632c  vsub.xyw    $vf12, $vf12, $vf8
    ctx->pc = 0x180100u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[12], ctx->vu0_vf[8]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[12] = PS2_VBLEND(ctx->vu0_vf[12], res, _mm_castsi128_ps(mask)); }
    // 0x180104: 0x4a2b4b3c  vmove.w     $vf11, $vf9
    ctx->pc = 0x180104u;
    { __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[11] = _mm_blendv_ps(ctx->vu0_vf[11], ctx->vu0_vf[9], _mm_castsi128_ps(mask)); }
    // 0x180108: 0x4a2c533c  vmove.w     $vf12, $vf10
    ctx->pc = 0x180108u;
    { __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[12] = _mm_blendv_ps(ctx->vu0_vf[12], ctx->vu0_vf[10], _mm_castsi128_ps(mask)); }
    // 0x18010c: 0x4a0002ff  vnop
    ctx->pc = 0x18010cu;
    // NOP operation, no action needed for VU0
    // 0x180110: 0x22310010  addi        $s1, $s1, 0x10
    ctx->pc = 0x180110u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 17), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 17, (int32_t)tmp); }
    // 0x180114: 0xda280000  lqc2        $vf8, 0x0($s1)
    ctx->pc = 0x180114u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x180118: 0x2210ffff  addi        $s0, $s0, -0x1
    ctx->pc = 0x180118u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 16), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 16, (int32_t)tmp); }
    // 0x18011c: 0x48438000  cfc2.ni     $v1, $vi16
    ctx->pc = 0x18011cu;
    SET_GPR_U32(ctx, 3, ctx->vu0_vpu_stat4);
    // 0x180120: 0x306300c0  andi        $v1, $v1, 0xC0
    ctx->pc = 0x180120u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)192);
    // 0x180124: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x180124u;
    {
        const bool branch_taken_0x180124 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x180124) {
            ctx->pc = 0x180138u;
            goto label_180138;
        }
    }
    ctx->pc = 0x18012Cu;
    // 0x18012c: 0x1410ffea  bne         $zero, $s0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x18012Cu;
    {
        const bool branch_taken_0x18012c = (GPR_U64(ctx, 0) != GPR_U64(ctx, 16));
        if (branch_taken_0x18012c) {
            ctx->pc = 0x1800D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1800d8;
        }
    }
    ctx->pc = 0x180134u;
    // 0x180134: 0x20030001  addi        $v1, $zero, 0x1
    ctx->pc = 0x180134u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 0), (int32_t)1, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 3, (int32_t)tmp); }
label_180138:
    // 0x180138: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x180138u;
    {
        const bool branch_taken_0x180138 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18013Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180138u;
            // 0x18013c: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180138) {
            ctx->pc = 0x180148u;
            goto label_180148;
        }
    }
    ctx->pc = 0x180140u;
    // 0x180140: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x180140u;
    SET_GPR_U32(ctx, 31, 0x180148u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180148u; }
        if (ctx->pc != 0x180148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180148u; }
        if (ctx->pc != 0x180148u) { return; }
    }
    ctx->pc = 0x180148u;
label_180148:
    // 0x180148: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x180148u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18014c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x18014cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x180150: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x180150u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x180154: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x180154u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x180158: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x180158u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18015c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x18015cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180160: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180160u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180164: 0x3e00008  jr          $ra
    ctx->pc = 0x180164u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180164u;
            // 0x180168: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F688u: goto label_17f688;
            case 0x17F6ACu: goto label_17f6ac;
            case 0x17F6D4u: goto label_17f6d4;
            case 0x17F6DCu: goto label_17f6dc;
            case 0x17F6F0u: goto label_17f6f0;
            case 0x17F724u: goto label_17f724;
            case 0x17F768u: goto label_17f768;
            case 0x17F7A0u: goto label_17f7a0;
            case 0x17F7B0u: goto label_17f7b0;
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            case 0x17F9F4u: goto label_17f9f4;
            case 0x17FA00u: goto label_17fa00;
            case 0x17FA0Cu: goto label_17fa0c;
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            case 0x17FBE8u: goto label_17fbe8;
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            case 0x17FE84u: goto label_17fe84;
            case 0x17FECCu: goto label_17fecc;
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18016Cu;
    // 0x18016c: 0x0  nop
    ctx->pc = 0x18016cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

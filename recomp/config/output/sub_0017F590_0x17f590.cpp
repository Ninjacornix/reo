#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F590
// Address: 0x17f590 - 0x17f684
void sub_0017F590_0x17f590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F590_0x17f590");
#endif

    switch (ctx->pc) {
        case 0x17f5b4u: goto label_17f5b4;
        case 0x17f5f8u: goto label_17f5f8;
        case 0x17f62cu: goto label_17f62c;
        default: break;
    }

    ctx->pc = 0x17f590u;

    // 0x17f590: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f594: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f598: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f59c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f59cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f5a0: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17f5a0u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17f5a4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17f5a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f5a8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f5a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f5ac: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F5ACu;
    SET_GPR_U32(ctx, 31, 0x17F5B4u);
    ctx->pc = 0x17F5B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F5ACu;
            // 0x17f5b0: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F5B4u; }
        if (ctx->pc != 0x17F5B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F5B4u; }
        if (ctx->pc != 0x17F5B4u) { return; }
    }
    ctx->pc = 0x17F5B4u;
label_17f5b4:
    // 0x17f5b4: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x17f5b4u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17f5b8: 0x4600a034  c.lt.s      $f20, $f0
    ctx->pc = 0x17f5b8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x17f5bc: 0x3c013fc9  lui         $at, 0x3FC9
    ctx->pc = 0x17f5bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16329 << 16));
    // 0x17f5c0: 0x34210fdb  ori         $at, $at, 0xFDB
    ctx->pc = 0x17f5c0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)4059);
    // 0x17f5c4: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x17f5c4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17f5c8: 0x45000004  bc1f        . + 4 + (0x4 << 2)
    ctx->pc = 0x17F5C8u;
    {
        const bool branch_taken_0x17f5c8 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x17f5c8) {
            ctx->pc = 0x17F5DCu;
            goto label_17f5dc;
        }
    }
    ctx->pc = 0x17F5D0u;
    // 0x17f5d0: 0x46140500  add.s       $f20, $f0, $f20
    ctx->pc = 0x17f5d0u;
    ctx->f[20] = FPU_ADD_S(ctx->f[0], ctx->f[20]);
    // 0x17f5d4: 0x805fd79  j           func_17F5E4
    ctx->pc = 0x17F5D4u;
    ctx->pc = 0x17F5D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F5D4u;
            // 0x17f5d8: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F5E4u;
    goto label_17f5e4;
    ctx->pc = 0x17F5DCu;
label_17f5dc:
    // 0x17f5dc: 0x46140501  sub.s       $f20, $f0, $f20
    ctx->pc = 0x17f5dcu;
    ctx->f[20] = FPU_SUB_S(ctx->f[0], ctx->f[20]);
    // 0x17f5e0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17f5e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17f5e4:
    // 0x17f5e4: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17f5e4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17f5e8: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x17f5e8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17f5ec: 0x3e0302d  daddu       $a2, $ra, $zero
    ctx->pc = 0x17f5ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 31) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f5f0: 0xc05fd0a  jal         func_17F428
    ctx->pc = 0x17F5F0u;
    SET_GPR_U32(ctx, 31, 0x17F5F8u);
    ctx->pc = 0x17F428u;
    if (runtime->hasFunction(0x17F428u)) {
        auto targetFn = runtime->lookupFunction(0x17F428u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F5F8u; }
        if (ctx->pc != 0x17F5F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F428_0x17f428(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F5F8u; }
        if (ctx->pc != 0x17F5F8u) { return; }
    }
    ctx->pc = 0x17F5F8u;
label_17f5f8:
    // 0x17f5f8: 0xc0f82d  daddu       $ra, $a2, $zero
    ctx->pc = 0x17f5f8u;
    SET_GPR_U64(ctx, 31, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f5fc: 0x4be62b3c  vmove.xyzw  $vf6, $vf5
    ctx->pc = 0x17f5fcu;
    ctx->vu0_vf[6] = ctx->vu0_vf[5];
    // 0x17f600: 0x4be72b3c  vmove.xyzw  $vf7, $vf5
    ctx->pc = 0x17f600u;
    ctx->vu0_vf[7] = ctx->vu0_vf[5];
    // 0x17f604: 0x4be82b3c  vmove.xyzw  $vf8, $vf5
    ctx->pc = 0x17f604u;
    ctx->vu0_vf[8] = ctx->vu0_vf[5];
    // 0x17f608: 0x4be92b3c  vmove.xyzw  $vf9, $vf5
    ctx->pc = 0x17f608u;
    ctx->vu0_vf[9] = ctx->vu0_vf[5];
    // 0x17f60c: 0x4b002983  vaddw.x     $vf6, $vf5, $vf0w
    ctx->pc = 0x17f60cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f610: 0x4a202a43  vaddw.w     $vf9, $vf5, $vf0w
    ctx->pc = 0x17f610u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x17f614: 0x4a64212c  vsub.zw     $vf4, $vf4, $vf4
    ctx->pc = 0x17f614u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[4], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, -1, 0, 0); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17f618: 0x4a4429c0  vaddx.z     $vf7, $vf5, $vf4x
    ctx->pc = 0x17f618u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x17f61c: 0x4a8429c1  vaddy.y     $vf7, $vf5, $vf4y
    ctx->pc = 0x17f61cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x17f620: 0x4a842a04  vsubx.y     $vf8, $vf5, $vf4x
    ctx->pc = 0x17f620u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x17f624: 0x4a442a01  vaddy.z     $vf8, $vf5, $vf4y
    ctx->pc = 0x17f624u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x17f628: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x17f628u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_17f62c:
    // 0x17f62c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f62cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f630: 0x4be431bc  vmulax.xyzw $ACC, $vf6, $vf4x
    ctx->pc = 0x17f630u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17f634: 0x4be438bd  vmadday.xyzw $ACC, $vf7, $vf4y
    ctx->pc = 0x17f634u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17f638: 0x4be440be  vmaddaz.xyzw $ACC, $vf8, $vf4z
    ctx->pc = 0x17f638u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17f63c: 0x4be4494b  vmaddw.xyzw $vf5, $vf9, $vf4w
    ctx->pc = 0x17f63cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f640: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f640u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f644: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x17f644u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x17f648: 0x22100010  addi        $s0, $s0, 0x10
    ctx->pc = 0x17f648u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 16), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 16, (int32_t)tmp); }
    // 0x17f64c: 0x1407fff7  bne         $zero, $a3, . + 4 + (-0x9 << 2)
    ctx->pc = 0x17F64Cu;
    {
        const bool branch_taken_0x17f64c = (GPR_U64(ctx, 0) != GPR_U64(ctx, 7));
        ctx->pc = 0x17F650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F64Cu;
            // 0x17f650: 0x22310010  addi        $s1, $s1, 0x10 (Delay Slot)
        { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 17), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 17, (int32_t)tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f64c) {
            ctx->pc = 0x17F62Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17f62c;
        }
    }
    ctx->pc = 0x17F654u;
    // 0x17f654: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17F654u;
    {
        const bool branch_taken_0x17f654 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F654u;
            // 0x17f658: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f654) {
            ctx->pc = 0x17F670u;
            goto label_17f670;
        }
    }
    ctx->pc = 0x17F65Cu;
    // 0x17f65c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f65cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f660: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f660u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f664: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f664u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f668: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F668u;
    ctx->pc = 0x17F66Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F668u;
            // 0x17f66c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F670u;
label_17f670:
    // 0x17f670: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f670u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f674: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f674u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f678: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f678u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f67c: 0x3e00008  jr          $ra
    ctx->pc = 0x17F67Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F67Cu;
            // 0x17f680: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F5B4u: goto label_17f5b4;
            case 0x17F5DCu: goto label_17f5dc;
            case 0x17F5E4u: goto label_17f5e4;
            case 0x17F5F8u: goto label_17f5f8;
            case 0x17F62Cu: goto label_17f62c;
            case 0x17F670u: goto label_17f670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F684u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

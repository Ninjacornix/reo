#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180080
// Address: 0x180080 - 0x18016c
void sub_00180080_0x180080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180080_0x180080");
#endif

    switch (ctx->pc) {
        case 0x1800b4u: goto label_1800b4;
        case 0x1800d8u: goto label_1800d8;
        case 0x180148u: goto label_180148;
        default: break;
    }

    ctx->pc = 0x180080u;

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
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1800dc: 0x4be828bd  vmadday.xyzw $ACC, $vf5, $vf8y
    ctx->pc = 0x1800dcu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1800e0: 0x4be830be  vmaddaz.xyzw $ACC, $vf6, $vf8z
    ctx->pc = 0x1800e0u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x1800e4: 0x4be83a0b  vmaddw.xyzw $vf8, $vf7, $vf8w
    ctx->pc = 0x1800e4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[8] = _mm_blendv_ps(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
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
            case 0x1800B4u: goto label_1800b4;
            case 0x1800D8u: goto label_1800d8;
            case 0x180138u: goto label_180138;
            case 0x180148u: goto label_180148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18016Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

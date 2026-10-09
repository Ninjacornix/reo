#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EDA0
// Address: 0x17eda0 - 0x17f0f0
void sub_0017EDA0_0x17eda0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EDA0_0x17eda0");
#endif

    switch (ctx->pc) {
        case 0x17edbcu: goto label_17edbc;
        case 0x17ee74u: goto label_17ee74;
        case 0x17eee4u: goto label_17eee4;
        case 0x17ef5cu: goto label_17ef5c;
        case 0x17efdcu: goto label_17efdc;
        case 0x17f044u: goto label_17f044;
        case 0x17f0acu: goto label_17f0ac;
        default: break;
    }

    ctx->pc = 0x17eda0u;

    // 0x17eda0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17eda0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17eda4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17eda4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17eda8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17eda8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17edac: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17edacu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17edb0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17edb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17edb4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EDB4u;
    SET_GPR_U32(ctx, 31, 0x17EDBCu);
    ctx->pc = 0x17EDB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EDB4u;
            // 0x17edb8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EDBCu; }
        if (ctx->pc != 0x17EDBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EDBCu; }
        if (ctx->pc != 0x17EDBCu) { return; }
    }
    ctx->pc = 0x17EDBCu;
label_17edbc:
    // 0x17edbc: 0x7a080000  lq          $t0, 0x0($s0)
    ctx->pc = 0x17edbcu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17edc0: 0x7a090010  lq          $t1, 0x10($s0)
    ctx->pc = 0x17edc0u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17edc4: 0x7a0a0020  lq          $t2, 0x20($s0)
    ctx->pc = 0x17edc4u;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x17edc8: 0xda040030  lqc2        $vf4, 0x30($s0)
    ctx->pc = 0x17edc8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x17edcc: 0x4be5233c  vmove.xyzw  $vf5, $vf4
    ctx->pc = 0x17edccu;
    ctx->vu0_vf[5] = ctx->vu0_vf[4];
    // 0x17edd0: 0x4bc4212c  vsub.xyz    $vf4, $vf4, $vf4
    ctx->pc = 0x17edd0u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[4], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17edd4: 0x4be9233c  vmove.xyzw  $vf9, $vf4
    ctx->pc = 0x17edd4u;
    ctx->vu0_vf[9] = ctx->vu0_vf[4];
    // 0x17edd8: 0x482b2000  qmfc2.ni    $t3, $vf4
    ctx->pc = 0x17edd8u;
    SET_GPR_VEC(ctx, 11, _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x17eddc: 0x71286488  pextlw      $t4, $t1, $t0
    ctx->pc = 0x17eddcu;
    SET_GPR_VEC(ctx, 12, PS2_PEXTLW(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x17ede0: 0x71286ca8  pextuw      $t5, $t1, $t0
    ctx->pc = 0x17ede0u;
    SET_GPR_VEC(ctx, 13, PS2_PEXTUW(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x17ede4: 0x716a7488  pextlw      $t6, $t3, $t2
    ctx->pc = 0x17ede4u;
    SET_GPR_VEC(ctx, 14, PS2_PEXTLW(GPR_VEC(ctx, 11), GPR_VEC(ctx, 10)));
    // 0x17ede8: 0x716a7ca8  pextuw      $t7, $t3, $t2
    ctx->pc = 0x17ede8u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUW(GPR_VEC(ctx, 11), GPR_VEC(ctx, 10)));
    // 0x17edec: 0x71cc4389  pcpyld      $t0, $t6, $t4
    ctx->pc = 0x17edecu;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x17edf0: 0x718e4ba9  pcpyud      $t1, $t4, $t6
    ctx->pc = 0x17edf0u;
    SET_GPR_VEC(ctx, 9, _mm_unpackhi_epi64(GPR_VEC(ctx, 12), GPR_VEC(ctx, 14)));
    // 0x17edf4: 0x71ed5389  pcpyld      $t2, $t7, $t5
    ctx->pc = 0x17edf4u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 15), GPR_VEC(ctx, 13)));
    // 0x17edf8: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x17edf8u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17edfc: 0x48a93800  qmtc2.ni    $t1, $vf7
    ctx->pc = 0x17edfcu;
    ctx->vu0_vf[7] = _mm_castsi128_ps(GPR_VEC(ctx, 9));
    // 0x17ee00: 0x48aa4000  qmtc2.ni    $t2, $vf8
    ctx->pc = 0x17ee00u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(GPR_VEC(ctx, 10));
    // 0x17ee04: 0x4bc531bc  vmulax.xyz  $ACC, $vf6, $vf5x
    ctx->pc = 0x17ee04u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17ee08: 0x4bc538bd  vmadday.xyz $ACC, $vf7, $vf5y
    ctx->pc = 0x17ee08u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17ee0c: 0x4bc5410a  vmaddz.xyz  $vf4, $vf8, $vf5z
    ctx->pc = 0x17ee0cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17ee10: 0x4bc4492c  vsub.xyz    $vf4, $vf9, $vf4
    ctx->pc = 0x17ee10u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[9], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17ee14: 0x7e280000  sq          $t0, 0x0($s1)
    ctx->pc = 0x17ee14u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), GPR_VEC(ctx, 8));
    // 0x17ee18: 0x7e290010  sq          $t1, 0x10($s1)
    ctx->pc = 0x17ee18u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 16), GPR_VEC(ctx, 9));
    // 0x17ee1c: 0x7e2a0020  sq          $t2, 0x20($s1)
    ctx->pc = 0x17ee1cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 32), GPR_VEC(ctx, 10));
    // 0x17ee20: 0xfa240030  sqc2        $vf4, 0x30($s1)
    ctx->pc = 0x17ee20u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 48), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x17ee24: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17EE24u;
    {
        const bool branch_taken_0x17ee24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EE24u;
            // 0x17ee28: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ee24) {
            ctx->pc = 0x17EE3Cu;
            goto label_17ee3c;
        }
    }
    ctx->pc = 0x17EE2Cu;
    // 0x17ee2c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ee2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ee30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ee30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ee34: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EE34u;
    ctx->pc = 0x17EE38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EE34u;
            // 0x17ee38: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EE3Cu;
label_17ee3c:
    // 0x17ee3c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ee3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ee40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ee40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ee44: 0x3e00008  jr          $ra
    ctx->pc = 0x17EE44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EE48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EE44u;
            // 0x17ee48: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EDBCu: goto label_17edbc;
            case 0x17EE3Cu: goto label_17ee3c;
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            case 0x17EEE4u: goto label_17eee4;
            case 0x17EF1Cu: goto label_17ef1c;
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EE4Cu;
    // 0x17ee4c: 0x0  nop
    ctx->pc = 0x17ee4cu;
    // NOP
    // 0x17ee50: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17ee50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17ee54: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ee54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ee58: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ee58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ee5c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17ee5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ee60: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17ee60u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17ee64: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17ee64u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ee68: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17ee68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17ee6c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EE6Cu;
    SET_GPR_U32(ctx, 31, 0x17EE74u);
    ctx->pc = 0x17EE70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EE6Cu;
            // 0x17ee70: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EE74u; }
        if (ctx->pc != 0x17EE74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EE74u; }
        if (ctx->pc != 0x17EE74u) { return; }
    }
    ctx->pc = 0x17EE74u;
label_17ee74:
    // 0x17ee74: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17ee74u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ee78: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17ee78u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17ee7c: 0x48a82800  qmtc2.ni    $t0, $vf5
    ctx->pc = 0x17ee7cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17ee80: 0x4a6503bc  vdiv        $Q, $vf0w, $vf5x
    ctx->pc = 0x17ee80u;
    { float fs = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,3))); float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); if (ft != 0.0f) { ctx->vu0_q = fs / ft; } else { uint32_t sign = (std::bit_cast<uint32_t>(fs) ^ std::bit_cast<uint32_t>(ft)) & 0x80000000u; uint32_t maxf = 0x7F7FFFFFu | sign; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x17ee84: 0x4a0003bf  vwaitq
    ctx->pc = 0x17ee84u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x17ee88: 0x4be0211c  vmulq.xyzw  $vf4, $vf4, $Q
    ctx->pc = 0x17ee88u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17ee8c: 0xfa240000  sqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17ee8cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x17ee90: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17EE90u;
    {
        const bool branch_taken_0x17ee90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EE94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EE90u;
            // 0x17ee94: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ee90) {
            ctx->pc = 0x17EEACu;
            goto label_17eeac;
        }
    }
    ctx->pc = 0x17EE98u;
    // 0x17ee98: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ee98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ee9c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ee9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17eea0: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17eea0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17eea4: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EEA4u;
    ctx->pc = 0x17EEA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EEA4u;
            // 0x17eea8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EEACu;
label_17eeac:
    // 0x17eeac: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17eeacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17eeb0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17eeb0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17eeb4: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17eeb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17eeb8: 0x3e00008  jr          $ra
    ctx->pc = 0x17EEB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EEBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EEB8u;
            // 0x17eebc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EDBCu: goto label_17edbc;
            case 0x17EE3Cu: goto label_17ee3c;
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            case 0x17EEE4u: goto label_17eee4;
            case 0x17EF1Cu: goto label_17ef1c;
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EEC0u;
    // 0x17eec0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17eec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17eec4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17eec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17eec8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17eec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17eecc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17eeccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17eed0: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17eed0u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17eed4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17eed4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17eed8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17eed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17eedc: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EEDCu;
    SET_GPR_U32(ctx, 31, 0x17EEE4u);
    ctx->pc = 0x17EEE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EEDCu;
            // 0x17eee0: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EEE4u; }
        if (ctx->pc != 0x17EEE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EEE4u; }
        if (ctx->pc != 0x17EEE4u) { return; }
    }
    ctx->pc = 0x17EEE4u;
label_17eee4:
    // 0x17eee4: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17eee4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17eee8: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17eee8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17eeec: 0x48a82800  qmtc2.ni    $t0, $vf5
    ctx->pc = 0x17eeecu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17eef0: 0x4a6503bc  vdiv        $Q, $vf0w, $vf5x
    ctx->pc = 0x17eef0u;
    { float fs = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,3))); float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); if (ft != 0.0f) { ctx->vu0_q = fs / ft; } else { uint32_t sign = (std::bit_cast<uint32_t>(fs) ^ std::bit_cast<uint32_t>(ft)) & 0x80000000u; uint32_t maxf = 0x7F7FFFFFu | sign; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x17eef4: 0x4a0003bf  vwaitq
    ctx->pc = 0x17eef4u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x17eef8: 0x4bc0211c  vmulq.xyz   $vf4, $vf4, $Q
    ctx->pc = 0x17eef8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17eefc: 0xfa240000  sqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17eefcu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x17ef00: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17EF00u;
    {
        const bool branch_taken_0x17ef00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EF04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF00u;
            // 0x17ef04: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ef00) {
            ctx->pc = 0x17EF1Cu;
            goto label_17ef1c;
        }
    }
    ctx->pc = 0x17EF08u;
    // 0x17ef08: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ef08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ef0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ef0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ef10: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17ef10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ef14: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EF14u;
    ctx->pc = 0x17EF18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF14u;
            // 0x17ef18: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EF1Cu;
label_17ef1c:
    // 0x17ef1c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ef1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ef20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ef20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ef24: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17ef24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ef28: 0x3e00008  jr          $ra
    ctx->pc = 0x17EF28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF28u;
            // 0x17ef2c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EDBCu: goto label_17edbc;
            case 0x17EE3Cu: goto label_17ee3c;
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            case 0x17EEE4u: goto label_17eee4;
            case 0x17EF1Cu: goto label_17ef1c;
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EF30u;
    // 0x17ef30: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17ef30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17ef34: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17ef34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17ef38: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ef38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ef3c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17ef3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ef40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ef40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ef44: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17ef44u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ef48: 0xe7b40040  swc1        $f20, 0x40($sp)
    ctx->pc = 0x17ef48u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x17ef4c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x17ef4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ef50: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17ef50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17ef54: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EF54u;
    SET_GPR_U32(ctx, 31, 0x17EF5Cu);
    ctx->pc = 0x17EF58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF54u;
            // 0x17ef58: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EF5Cu; }
        if (ctx->pc != 0x17EF5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EF5Cu; }
        if (ctx->pc != 0x17EF5Cu) { return; }
    }
    ctx->pc = 0x17EF5Cu;
label_17ef5c:
    // 0x17ef5c: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17ef5cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17ef60: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17ef60u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ef64: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17ef64u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17ef68: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x17ef68u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17ef6c: 0x4b0001c3  vaddw.x     $vf7, $vf0, $vf0w
    ctx->pc = 0x17ef6cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x17ef70: 0x4b063a2c  vsub.x      $vf8, $vf7, $vf6
    ctx->pc = 0x17ef70u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = PS2_VBLEND(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x17ef74: 0x4be621bc  vmulax.xyzw $ACC, $vf4, $vf6x
    ctx->pc = 0x17ef74u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17ef78: 0x4be82a48  vmaddx.xyzw $vf9, $vf5, $vf8x
    ctx->pc = 0x17ef78u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x17ef7c: 0xfa490000  sqc2        $vf9, 0x0($s2)
    ctx->pc = 0x17ef7cu;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x17ef80: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17EF80u;
    {
        const bool branch_taken_0x17ef80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EF84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF80u;
            // 0x17ef84: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ef80) {
            ctx->pc = 0x17EFA0u;
            goto label_17efa0;
        }
    }
    ctx->pc = 0x17EF88u;
    // 0x17ef88: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17ef88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17ef8c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ef8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ef90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ef90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ef94: 0xc7b40040  lwc1        $f20, 0x40($sp)
    ctx->pc = 0x17ef94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ef98: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EF98u;
    ctx->pc = 0x17EF9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF98u;
            // 0x17ef9c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EFA0u;
label_17efa0:
    // 0x17efa0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17efa0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17efa4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17efa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17efa8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17efa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17efac: 0xc7b40040  lwc1        $f20, 0x40($sp)
    ctx->pc = 0x17efacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17efb0: 0x3e00008  jr          $ra
    ctx->pc = 0x17EFB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EFB0u;
            // 0x17efb4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EDBCu: goto label_17edbc;
            case 0x17EE3Cu: goto label_17ee3c;
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            case 0x17EEE4u: goto label_17eee4;
            case 0x17EF1Cu: goto label_17ef1c;
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EFB8u;
    // 0x17efb8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17efb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17efbc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17efbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17efc0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17efc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17efc4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17efc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17efc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17efc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17efcc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17efccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17efd0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17efd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17efd4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EFD4u;
    SET_GPR_U32(ctx, 31, 0x17EFDCu);
    ctx->pc = 0x17EFD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EFD4u;
            // 0x17efd8: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EFDCu; }
        if (ctx->pc != 0x17EFDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EFDCu; }
        if (ctx->pc != 0x17EFDCu) { return; }
    }
    ctx->pc = 0x17EFDCu;
label_17efdc:
    // 0x17efdc: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17efdcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17efe0: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17efe0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17efe4: 0x4be521a8  vadd.xyzw   $vf6, $vf4, $vf5
    ctx->pc = 0x17efe4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17efe8: 0xfa460000  sqc2        $vf6, 0x0($s2)
    ctx->pc = 0x17efe8u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17efec: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17EFECu;
    {
        const bool branch_taken_0x17efec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EFF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EFECu;
            // 0x17eff0: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17efec) {
            ctx->pc = 0x17F008u;
            goto label_17f008;
        }
    }
    ctx->pc = 0x17EFF4u;
    // 0x17eff4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17eff4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17eff8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17eff8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17effc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17effcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f000: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F000u;
    ctx->pc = 0x17F004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F000u;
            // 0x17f004: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F008u;
label_17f008:
    // 0x17f008: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f008u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f00c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f00cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f010: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f010u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f014: 0x3e00008  jr          $ra
    ctx->pc = 0x17F014u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F014u;
            // 0x17f018: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EDBCu: goto label_17edbc;
            case 0x17EE3Cu: goto label_17ee3c;
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            case 0x17EEE4u: goto label_17eee4;
            case 0x17EF1Cu: goto label_17ef1c;
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F01Cu;
    // 0x17f01c: 0x0  nop
    ctx->pc = 0x17f01cu;
    // NOP
    // 0x17f020: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f024: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17f024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17f028: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f02c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17f02cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f030: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f030u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f034: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17f034u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f038: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17f038u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17f03c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F03Cu;
    SET_GPR_U32(ctx, 31, 0x17F044u);
    ctx->pc = 0x17F040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F03Cu;
            // 0x17f040: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F044u; }
        if (ctx->pc != 0x17F044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F044u; }
        if (ctx->pc != 0x17F044u) { return; }
    }
    ctx->pc = 0x17F044u;
label_17f044:
    // 0x17f044: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17f044u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17f048: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17f048u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f04c: 0x4be521ac  vsub.xyzw   $vf6, $vf4, $vf5
    ctx->pc = 0x17f04cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f050: 0xfa460000  sqc2        $vf6, 0x0($s2)
    ctx->pc = 0x17f050u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17f054: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17F054u;
    {
        const bool branch_taken_0x17f054 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F054u;
            // 0x17f058: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f054) {
            ctx->pc = 0x17F070u;
            goto label_17f070;
        }
    }
    ctx->pc = 0x17F05Cu;
    // 0x17f05c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f05cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f060: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f060u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f064: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f064u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f068: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F068u;
    ctx->pc = 0x17F06Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F068u;
            // 0x17f06c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F070u;
label_17f070:
    // 0x17f070: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f070u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f074: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f074u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f078: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f078u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f07c: 0x3e00008  jr          $ra
    ctx->pc = 0x17F07Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F07Cu;
            // 0x17f080: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EDBCu: goto label_17edbc;
            case 0x17EE3Cu: goto label_17ee3c;
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            case 0x17EEE4u: goto label_17eee4;
            case 0x17EF1Cu: goto label_17ef1c;
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F084u;
    // 0x17f084: 0x0  nop
    ctx->pc = 0x17f084u;
    // NOP
    // 0x17f088: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f088u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f08c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17f08cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17f090: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f094: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17f094u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f098: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f09c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17f09cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f0a0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17f0a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17f0a4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F0A4u;
    SET_GPR_U32(ctx, 31, 0x17F0ACu);
    ctx->pc = 0x17F0A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0A4u;
            // 0x17f0a8: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F0ACu; }
        if (ctx->pc != 0x17F0ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F0ACu; }
        if (ctx->pc != 0x17F0ACu) { return; }
    }
    ctx->pc = 0x17F0ACu;
label_17f0ac:
    // 0x17f0ac: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17f0acu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17f0b0: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17f0b0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f0b4: 0x4be521aa  vmul.xyzw   $vf6, $vf4, $vf5
    ctx->pc = 0x17f0b4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f0b8: 0xfa460000  sqc2        $vf6, 0x0($s2)
    ctx->pc = 0x17f0b8u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17f0bc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17F0BCu;
    {
        const bool branch_taken_0x17f0bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0BCu;
            // 0x17f0c0: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f0bc) {
            ctx->pc = 0x17F0D8u;
            goto label_17f0d8;
        }
    }
    ctx->pc = 0x17F0C4u;
    // 0x17f0c4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f0c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f0c8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f0c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f0cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f0ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f0d0: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F0D0u;
    ctx->pc = 0x17F0D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0D0u;
            // 0x17f0d4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F0D8u;
label_17f0d8:
    // 0x17f0d8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f0d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f0dc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f0dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f0e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f0e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f0e4: 0x3e00008  jr          $ra
    ctx->pc = 0x17F0E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0E4u;
            // 0x17f0e8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EDBCu: goto label_17edbc;
            case 0x17EE3Cu: goto label_17ee3c;
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            case 0x17EEE4u: goto label_17eee4;
            case 0x17EF1Cu: goto label_17ef1c;
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F0ECu;
    // 0x17f0ec: 0x0  nop
    ctx->pc = 0x17f0ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

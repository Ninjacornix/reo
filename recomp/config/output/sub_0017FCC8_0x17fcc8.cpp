#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FCC8
// Address: 0x17fcc8 - 0x17fd8c
void sub_0017FCC8_0x17fcc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FCC8_0x17fcc8");
#endif

    switch (ctx->pc) {
        case 0x17fcfcu: goto label_17fcfc;
        case 0x17fd0cu: goto label_17fd0c;
        default: break;
    }

    ctx->pc = 0x17fcc8u;

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
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
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
            case 0x17FCFCu: goto label_17fcfc;
            case 0x17FD0Cu: goto label_17fd0c;
            case 0x17FD38u: goto label_17fd38;
            case 0x17FD70u: goto label_17fd70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FD8Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

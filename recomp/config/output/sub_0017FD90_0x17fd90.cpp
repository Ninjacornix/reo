#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FD90
// Address: 0x17fd90 - 0x17fe34
void sub_0017FD90_0x17fd90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FD90_0x17fd90");
#endif

    switch (ctx->pc) {
        case 0x17fdbcu: goto label_17fdbc;
        default: break;
    }

    ctx->pc = 0x17fd90u;

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
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
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
            case 0x17FDBCu: goto label_17fdbc;
            case 0x17FDF8u: goto label_17fdf8;
            case 0x17FE1Cu: goto label_17fe1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FE34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

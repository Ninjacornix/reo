#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EC98
// Address: 0x17ec98 - 0x17ed18
void sub_0017EC98_0x17ec98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EC98_0x17ec98");
#endif

    switch (ctx->pc) {
        case 0x17ecb4u: goto label_17ecb4;
        default: break;
    }

    ctx->pc = 0x17ec98u;

    // 0x17ec98: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17ec98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17ec9c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ec9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17eca0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17eca0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17eca4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17eca4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17eca8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17eca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17ecac: 0xc047598  jal         func_11D660
    ctx->pc = 0x17ECACu;
    SET_GPR_U32(ctx, 31, 0x17ECB4u);
    ctx->pc = 0x17ECB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ECACu;
            // 0x17ecb0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ECB4u; }
        if (ctx->pc != 0x17ECB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ECB4u; }
        if (ctx->pc != 0x17ECB4u) { return; }
    }
    ctx->pc = 0x17ECB4u;
label_17ecb4:
    // 0x17ecb4: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17ecb4u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ecb8: 0x4bc4216a  vmul.xyz    $vf5, $vf4, $vf4
    ctx->pc = 0x17ecb8u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ecbc: 0x4b052941  vaddy.x     $vf5, $vf5, $vf5y
    ctx->pc = 0x17ecbcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ecc0: 0x4b052942  vaddz.x     $vf5, $vf5, $vf5z
    ctx->pc = 0x17ecc0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ecc4: 0x4a0503bd  .word       0x4A0503BD                   # vsqrt       $Q, $vf5x # 00000000 <InstrIdType: R5900_COP2_SPECIAL2>
    ctx->pc = 0x17ecc4u;
    { float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_q = sqrtf(std::max(0.0f, ft)); }
    // 0x17ecc8: 0x4a0003bf  vwaitq
    ctx->pc = 0x17ecc8u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x17eccc: 0x4b000160  vaddq.x     $vf5, $vf0, $Q
    ctx->pc = 0x17ecccu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ecd0: 0x4a0002ff  vnop
    ctx->pc = 0x17ecd0u;
    // NOP operation, no action needed for VU0
    // 0x17ecd4: 0x4a0002ff  vnop
    ctx->pc = 0x17ecd4u;
    // NOP operation, no action needed for VU0
    // 0x17ecd8: 0x4a6503bc  vdiv        $Q, $vf0w, $vf5x
    ctx->pc = 0x17ecd8u;
    { float fs = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,3))); float ft = _mm_cvtss_f32(_mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); if (ft != 0.0f) { ctx->vu0_q = fs / ft; } else { uint32_t sign = (std::bit_cast<uint32_t>(fs) ^ std::bit_cast<uint32_t>(ft)) & 0x80000000u; uint32_t maxf = 0x7F7FFFFFu | sign; ctx->vu0_q = std::bit_cast<float>(maxf); } }
    // 0x17ecdc: 0x4be001ac  vsub.xyzw   $vf6, $vf0, $vf0
    ctx->pc = 0x17ecdcu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17ece0: 0x4a0003bf  vwaitq
    ctx->pc = 0x17ece0u;
    // VWAITQ (Q already resolved in this runtime)
    // 0x17ece4: 0x4bc0219c  vmulq.xyz   $vf6, $vf4, $Q
    ctx->pc = 0x17ece4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_set1_ps(ctx->vu0_q)); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17ece8: 0xfa260000  sqc2        $vf6, 0x0($s1)
    ctx->pc = 0x17ece8u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17ecec: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17ECECu;
    {
        const bool branch_taken_0x17ecec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17ECF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17ECECu;
            // 0x17ecf0: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ecec) {
            ctx->pc = 0x17ED04u;
            goto label_17ed04;
        }
    }
    ctx->pc = 0x17ECF4u;
    // 0x17ecf4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ecf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ecf8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ecf8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ecfc: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17ECFCu;
    ctx->pc = 0x17ED00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ECFCu;
            // 0x17ed00: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17ED04u;
label_17ed04:
    // 0x17ed04: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ed04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ed08: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ed08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ed0c: 0x3e00008  jr          $ra
    ctx->pc = 0x17ED0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17ED10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17ED0Cu;
            // 0x17ed10: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17ECB4u: goto label_17ecb4;
            case 0x17ED04u: goto label_17ed04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17ED14u;
    // 0x17ed14: 0x0  nop
    ctx->pc = 0x17ed14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

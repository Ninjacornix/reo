#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EE50
// Address: 0x17ee50 - 0x17eec0
void sub_0017EE50_0x17ee50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EE50_0x17ee50");
#endif

    switch (ctx->pc) {
        case 0x17ee74u: goto label_17ee74;
        default: break;
    }

    ctx->pc = 0x17ee50u;

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
            case 0x17EE74u: goto label_17ee74;
            case 0x17EEACu: goto label_17eeac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EEC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

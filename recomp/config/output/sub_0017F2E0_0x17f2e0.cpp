#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F2E0
// Address: 0x17f2e0 - 0x17f330
void sub_0017F2E0_0x17f2e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F2E0_0x17f2e0");
#endif

    switch (ctx->pc) {
        case 0x17f2fcu: goto label_17f2fc;
        default: break;
    }

    ctx->pc = 0x17f2e0u;

    // 0x17f2e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f2e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f2e4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f2e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f2e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f2e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f2ec: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f2ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f2f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f2f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f2f4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F2F4u;
    SET_GPR_U32(ctx, 31, 0x17F2FCu);
    ctx->pc = 0x17F2F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2F4u;
            // 0x17f2f8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2FCu; }
        if (ctx->pc != 0x17F2FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2FCu; }
        if (ctx->pc != 0x17F2FCu) { return; }
    }
    ctx->pc = 0x17F2FCu;
label_17f2fc:
    // 0x17f2fc: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f2fcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f300: 0x4be5217c  vftoi0.xyzw $vf5, $vf4
    ctx->pc = 0x17f300u;
    { __m128 src = ctx->vu0_vf[4]; src = _mm_mul_ps(src, _mm_set1_ps(1.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f304: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f304u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f308: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F308u;
    {
        const bool branch_taken_0x17f308 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F30Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F308u;
            // 0x17f30c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f308) {
            ctx->pc = 0x17F320u;
            goto label_17f320;
        }
    }
    ctx->pc = 0x17F310u;
    // 0x17f310: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f310u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f314: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f314u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f318: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F318u;
    ctx->pc = 0x17F31Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F318u;
            // 0x17f31c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F320u;
label_17f320:
    // 0x17f320: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f320u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f324: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f324u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f328: 0x3e00008  jr          $ra
    ctx->pc = 0x17F328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F328u;
            // 0x17f32c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F2FCu: goto label_17f2fc;
            case 0x17F320u: goto label_17f320;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F330u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

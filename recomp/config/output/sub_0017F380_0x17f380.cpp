#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F380
// Address: 0x17f380 - 0x17f3d0
void sub_0017F380_0x17f380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F380_0x17f380");
#endif

    switch (ctx->pc) {
        case 0x17f39cu: goto label_17f39c;
        default: break;
    }

    ctx->pc = 0x17f380u;

    // 0x17f380: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f384: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f388: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f38c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f38cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f390: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f394: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F394u;
    SET_GPR_U32(ctx, 31, 0x17F39Cu);
    ctx->pc = 0x17F398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F394u;
            // 0x17f398: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F39Cu; }
        if (ctx->pc != 0x17F39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F39Cu; }
        if (ctx->pc != 0x17F39Cu) { return; }
    }
    ctx->pc = 0x17F39Cu;
label_17f39c:
    // 0x17f39c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f39cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f3a0: 0x4be5213c  vitof0.xyzw $vf5, $vf4
    ctx->pc = 0x17f3a0u;
    { __m128i src = _mm_castps_si128(ctx->vu0_vf[4]); __m128 res = _mm_cvtepi32_ps(src); res = _mm_mul_ps(res, _mm_set1_ps(1.0f)); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f3a4: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f3a4u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f3a8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F3A8u;
    {
        const bool branch_taken_0x17f3a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F3ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F3A8u;
            // 0x17f3ac: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f3a8) {
            ctx->pc = 0x17F3C0u;
            goto label_17f3c0;
        }
    }
    ctx->pc = 0x17F3B0u;
    // 0x17f3b0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f3b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f3b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f3b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f3b8: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F3B8u;
    ctx->pc = 0x17F3BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F3B8u;
            // 0x17f3bc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F3C0u;
label_17f3c0:
    // 0x17f3c0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f3c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f3c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f3c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f3c8: 0x3e00008  jr          $ra
    ctx->pc = 0x17F3C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F3CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F3C8u;
            // 0x17f3cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F39Cu: goto label_17f39c;
            case 0x17F3C0u: goto label_17f3c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F3D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

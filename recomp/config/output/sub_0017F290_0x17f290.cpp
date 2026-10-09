#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F290
// Address: 0x17f290 - 0x17f2e0
void sub_0017F290_0x17f290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F290_0x17f290");
#endif

    switch (ctx->pc) {
        case 0x17f2acu: goto label_17f2ac;
        default: break;
    }

    ctx->pc = 0x17f290u;

    // 0x17f290: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f294: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f298: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f29c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f29cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f2a0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f2a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f2a4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F2A4u;
    SET_GPR_U32(ctx, 31, 0x17F2ACu);
    ctx->pc = 0x17F2A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2A4u;
            // 0x17f2a8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2ACu; }
        if (ctx->pc != 0x17F2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2ACu; }
        if (ctx->pc != 0x17F2ACu) { return; }
    }
    ctx->pc = 0x17F2ACu;
label_17f2ac:
    // 0x17f2ac: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f2acu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f2b0: 0x4be5217d  vftoi4.xyzw $vf5, $vf4
    ctx->pc = 0x17f2b0u;
    { __m128 src = ctx->vu0_vf[4]; src = _mm_mul_ps(src, _mm_set1_ps(16.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f2b4: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f2b4u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f2b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F2B8u;
    {
        const bool branch_taken_0x17f2b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F2BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2B8u;
            // 0x17f2bc: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f2b8) {
            ctx->pc = 0x17F2D0u;
            goto label_17f2d0;
        }
    }
    ctx->pc = 0x17F2C0u;
    // 0x17f2c0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f2c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f2c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f2c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f2c8: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F2C8u;
    ctx->pc = 0x17F2CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2C8u;
            // 0x17f2cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F2D0u;
label_17f2d0:
    // 0x17f2d0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f2d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f2d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f2d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f2d8: 0x3e00008  jr          $ra
    ctx->pc = 0x17F2D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2D8u;
            // 0x17f2dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F2ACu: goto label_17f2ac;
            case 0x17F2D0u: goto label_17f2d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F2E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F020
// Address: 0x17f020 - 0x17f084
void sub_0017F020_0x17f020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F020_0x17f020");
#endif

    switch (ctx->pc) {
        case 0x17f044u: goto label_17f044;
        default: break;
    }

    ctx->pc = 0x17f020u;

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
            case 0x17F044u: goto label_17f044;
            case 0x17F070u: goto label_17f070;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F084u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

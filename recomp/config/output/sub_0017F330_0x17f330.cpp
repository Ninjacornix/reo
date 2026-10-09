#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F330
// Address: 0x17f330 - 0x17f380
void sub_0017F330_0x17f330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F330_0x17f330");
#endif

    switch (ctx->pc) {
        case 0x17f34cu: goto label_17f34c;
        default: break;
    }

    ctx->pc = 0x17f330u;

    // 0x17f330: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f334: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f338: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f33c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f33cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f340: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f344: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F344u;
    SET_GPR_U32(ctx, 31, 0x17F34Cu);
    ctx->pc = 0x17F348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F344u;
            // 0x17f348: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F34Cu; }
        if (ctx->pc != 0x17F34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F34Cu; }
        if (ctx->pc != 0x17F34Cu) { return; }
    }
    ctx->pc = 0x17F34Cu;
label_17f34c:
    // 0x17f34c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f34cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f350: 0x4be5213d  vitof4.xyzw $vf5, $vf4
    ctx->pc = 0x17f350u;
    { __m128i src = _mm_castps_si128(ctx->vu0_vf[4]); __m128 res = _mm_cvtepi32_ps(src); res = _mm_mul_ps(res, _mm_set1_ps(0.0625f)); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f354: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f354u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f358: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F358u;
    {
        const bool branch_taken_0x17f358 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F358u;
            // 0x17f35c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f358) {
            ctx->pc = 0x17F370u;
            goto label_17f370;
        }
    }
    ctx->pc = 0x17F360u;
    // 0x17f360: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f360u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f364: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f364u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f368: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F368u;
    ctx->pc = 0x17F36Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F368u;
            // 0x17f36c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F370u;
label_17f370:
    // 0x17f370: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f370u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f374: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f374u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f378: 0x3e00008  jr          $ra
    ctx->pc = 0x17F378u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F378u;
            // 0x17f37c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F34Cu: goto label_17f34c;
            case 0x17F370u: goto label_17f370;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F380u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

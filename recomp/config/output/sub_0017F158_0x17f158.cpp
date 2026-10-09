#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F158
// Address: 0x17f158 - 0x17f1d8
void sub_0017F158_0x17f158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F158_0x17f158");
#endif

    switch (ctx->pc) {
        case 0x17f17cu: goto label_17f17c;
        default: break;
    }

    ctx->pc = 0x17f158u;

    // 0x17f158: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f15c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17f15cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17f160: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f164: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17f164u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f168: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f16c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17f16cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f170: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17f170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17f174: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F174u;
    SET_GPR_U32(ctx, 31, 0x17F17Cu);
    ctx->pc = 0x17F178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F174u;
            // 0x17f178: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F17Cu; }
        if (ctx->pc != 0x17F17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F17Cu; }
        if (ctx->pc != 0x17F17Cu) { return; }
    }
    ctx->pc = 0x17F17Cu;
label_17f17c:
    // 0x17f17c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f17cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f180: 0xda250030  lqc2        $vf5, 0x30($s1)
    ctx->pc = 0x17f180u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x17f184: 0x7a270000  lq          $a3, 0x0($s1)
    ctx->pc = 0x17f184u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17f188: 0x7a280010  lq          $t0, 0x10($s1)
    ctx->pc = 0x17f188u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x17f18c: 0x7a290020  lq          $t1, 0x20($s1)
    ctx->pc = 0x17f18cu;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x17f190: 0x4bc42968  vadd.xyz    $vf5, $vf5, $vf4
    ctx->pc = 0x17f190u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f194: 0x7e470000  sq          $a3, 0x0($s2)
    ctx->pc = 0x17f194u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), GPR_VEC(ctx, 7));
    // 0x17f198: 0x7e480010  sq          $t0, 0x10($s2)
    ctx->pc = 0x17f198u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 16), GPR_VEC(ctx, 8));
    // 0x17f19c: 0x7e490020  sq          $t1, 0x20($s2)
    ctx->pc = 0x17f19cu;
    WRITE128(ADD32(GPR_U32(ctx, 18), 32), GPR_VEC(ctx, 9));
    // 0x17f1a0: 0xfa450030  sqc2        $vf5, 0x30($s2)
    ctx->pc = 0x17f1a0u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 48), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f1a4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17F1A4u;
    {
        const bool branch_taken_0x17f1a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F1A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F1A4u;
            // 0x17f1a8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f1a4) {
            ctx->pc = 0x17F1C0u;
            goto label_17f1c0;
        }
    }
    ctx->pc = 0x17F1ACu;
    // 0x17f1ac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f1acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f1b0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f1b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f1b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f1b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f1b8: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F1B8u;
    ctx->pc = 0x17F1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F1B8u;
            // 0x17f1bc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F1C0u;
label_17f1c0:
    // 0x17f1c0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f1c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f1c4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f1c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f1c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f1c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f1cc: 0x3e00008  jr          $ra
    ctx->pc = 0x17F1CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F1CCu;
            // 0x17f1d0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F17Cu: goto label_17f17c;
            case 0x17F1C0u: goto label_17f1c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F1D4u;
    // 0x17f1d4: 0x0  nop
    ctx->pc = 0x17f1d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

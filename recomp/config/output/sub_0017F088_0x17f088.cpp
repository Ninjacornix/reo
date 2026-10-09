#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F088
// Address: 0x17f088 - 0x17f0ec
void sub_0017F088_0x17f088(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F088_0x17f088");
#endif

    switch (ctx->pc) {
        case 0x17f0acu: goto label_17f0ac;
        default: break;
    }

    ctx->pc = 0x17f088u;

    // 0x17f088: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f088u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f08c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17f08cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17f090: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f090u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f094: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17f094u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f098: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f098u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f09c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17f09cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f0a0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17f0a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17f0a4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F0A4u;
    SET_GPR_U32(ctx, 31, 0x17F0ACu);
    ctx->pc = 0x17F0A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0A4u;
            // 0x17f0a8: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F0ACu; }
        if (ctx->pc != 0x17F0ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F0ACu; }
        if (ctx->pc != 0x17F0ACu) { return; }
    }
    ctx->pc = 0x17F0ACu;
label_17f0ac:
    // 0x17f0ac: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17f0acu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17f0b0: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17f0b0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f0b4: 0x4be521aa  vmul.xyzw   $vf6, $vf4, $vf5
    ctx->pc = 0x17f0b4u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f0b8: 0xfa460000  sqc2        $vf6, 0x0($s2)
    ctx->pc = 0x17f0b8u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17f0bc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17F0BCu;
    {
        const bool branch_taken_0x17f0bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0BCu;
            // 0x17f0c0: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f0bc) {
            ctx->pc = 0x17F0D8u;
            goto label_17f0d8;
        }
    }
    ctx->pc = 0x17F0C4u;
    // 0x17f0c4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f0c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f0c8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f0c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f0cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f0ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f0d0: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F0D0u;
    ctx->pc = 0x17F0D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0D0u;
            // 0x17f0d4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F0D8u;
label_17f0d8:
    // 0x17f0d8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f0d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f0dc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f0dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f0e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f0e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f0e4: 0x3e00008  jr          $ra
    ctx->pc = 0x17F0E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F0E4u;
            // 0x17f0e8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F0ACu: goto label_17f0ac;
            case 0x17F0D8u: goto label_17f0d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F0ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

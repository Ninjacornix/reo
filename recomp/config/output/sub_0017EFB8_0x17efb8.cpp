#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EFB8
// Address: 0x17efb8 - 0x17f01c
void sub_0017EFB8_0x17efb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EFB8_0x17efb8");
#endif

    switch (ctx->pc) {
        case 0x17efdcu: goto label_17efdc;
        default: break;
    }

    ctx->pc = 0x17efb8u;

    // 0x17efb8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17efb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17efbc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17efbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17efc0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17efc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17efc4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17efc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17efc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17efc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17efcc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17efccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17efd0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17efd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17efd4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EFD4u;
    SET_GPR_U32(ctx, 31, 0x17EFDCu);
    ctx->pc = 0x17EFD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EFD4u;
            // 0x17efd8: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EFDCu; }
        if (ctx->pc != 0x17EFDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EFDCu; }
        if (ctx->pc != 0x17EFDCu) { return; }
    }
    ctx->pc = 0x17EFDCu;
label_17efdc:
    // 0x17efdc: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17efdcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17efe0: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17efe0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17efe4: 0x4be521a8  vadd.xyzw   $vf6, $vf4, $vf5
    ctx->pc = 0x17efe4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17efe8: 0xfa460000  sqc2        $vf6, 0x0($s2)
    ctx->pc = 0x17efe8u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17efec: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17EFECu;
    {
        const bool branch_taken_0x17efec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EFF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EFECu;
            // 0x17eff0: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17efec) {
            ctx->pc = 0x17F008u;
            goto label_17f008;
        }
    }
    ctx->pc = 0x17EFF4u;
    // 0x17eff4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17eff4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17eff8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17eff8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17effc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17effcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f000: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F000u;
    ctx->pc = 0x17F004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F000u;
            // 0x17f004: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F008u;
label_17f008:
    // 0x17f008: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17f008u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f00c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f00cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f010: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f010u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f014: 0x3e00008  jr          $ra
    ctx->pc = 0x17F014u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F014u;
            // 0x17f018: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EFDCu: goto label_17efdc;
            case 0x17F008u: goto label_17f008;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F01Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

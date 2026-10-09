#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FF50
// Address: 0x17ff50 - 0x17ffcc
void sub_0017FF50_0x17ff50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FF50_0x17ff50");
#endif

    switch (ctx->pc) {
        case 0x17ff64u: goto label_17ff64;
        case 0x17ffb8u: goto label_17ffb8;
        default: break;
    }

    ctx->pc = 0x17ff50u;

    // 0x17ff50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17ff50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17ff54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ff54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ff58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17ff58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17ff5c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FF5Cu;
    SET_GPR_U32(ctx, 31, 0x17FF64u);
    ctx->pc = 0x17FF60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF5Cu;
            // 0x17ff60: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF64u; }
        if (ctx->pc != 0x17FF64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF64u; }
        if (ctx->pc != 0x17FF64u) { return; }
    }
    ctx->pc = 0x17FF64u;
label_17ff64:
    // 0x17ff64: 0x4be0012c  vsub.xyzw   $vf4, $vf0, $vf0
    ctx->pc = 0x17ff64u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17ff68: 0x3c034580  lui         $v1, 0x4580
    ctx->pc = 0x17ff68u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17792 << 16));
    // 0x17ff6c: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x17ff6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x17ff70: 0x34634580  ori         $v1, $v1, 0x4580
    ctx->pc = 0x17ff70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17792);
    // 0x17ff74: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x17ff74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x17ff78: 0xda070000  lqc2        $vf7, 0x0($s0)
    ctx->pc = 0x17ff78u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ff7c: 0x48a33000  qmtc2.ni    $v1, $vf6
    ctx->pc = 0x17ff7cu;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 3));
    // 0x17ff80: 0x48c08000  ctc2.ni     $zero, $vi16
    ctx->pc = 0x17ff80u;
    ctx->vu0_vpu_stat4 = GPR_U32(ctx, 0);
    // 0x17ff84: 0x4ba4396c  vsub.xyw    $vf5, $vf7, $vf4
    ctx->pc = 0x17ff84u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ff88: 0x4b87316c  vsub.xy     $vf5, $vf6, $vf7
    ctx->pc = 0x17ff88u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[6], ctx->vu0_vf[7]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ff8c: 0x4a0002ff  vnop
    ctx->pc = 0x17ff8cu;
    // NOP operation, no action needed for VU0
    // 0x17ff90: 0x4a0002ff  vnop
    ctx->pc = 0x17ff90u;
    // NOP operation, no action needed for VU0
    // 0x17ff94: 0x4a0002ff  vnop
    ctx->pc = 0x17ff94u;
    // NOP operation, no action needed for VU0
    // 0x17ff98: 0x4a0002ff  vnop
    ctx->pc = 0x17ff98u;
    // NOP operation, no action needed for VU0
    // 0x17ff9c: 0x4a0002ff  vnop
    ctx->pc = 0x17ff9cu;
    // NOP operation, no action needed for VU0
    // 0x17ffa0: 0x48438000  cfc2.ni     $v1, $vi16
    ctx->pc = 0x17ffa0u;
    SET_GPR_U32(ctx, 3, ctx->vu0_vpu_stat4);
    // 0x17ffa4: 0x306300c0  andi        $v1, $v1, 0xC0
    ctx->pc = 0x17ffa4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)192);
    // 0x17ffa8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17FFA8u;
    {
        const bool branch_taken_0x17ffa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FFACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FFA8u;
            // 0x17ffac: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ffa8) {
            ctx->pc = 0x17FFB8u;
            goto label_17ffb8;
        }
    }
    ctx->pc = 0x17FFB0u;
    // 0x17ffb0: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x17FFB0u;
    SET_GPR_U32(ctx, 31, 0x17FFB8u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFB8u; }
        if (ctx->pc != 0x17FFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFB8u; }
        if (ctx->pc != 0x17FFB8u) { return; }
    }
    ctx->pc = 0x17FFB8u;
label_17ffb8:
    // 0x17ffb8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x17ffb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ffbc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17ffbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ffc0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ffc0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ffc4: 0x3e00008  jr          $ra
    ctx->pc = 0x17FFC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FFC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FFC4u;
            // 0x17ffc8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17FF64u: goto label_17ff64;
            case 0x17FFB8u: goto label_17ffb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FFCCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

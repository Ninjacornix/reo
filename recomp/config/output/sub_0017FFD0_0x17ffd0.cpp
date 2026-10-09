#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FFD0
// Address: 0x17ffd0 - 0x18007c
void sub_0017FFD0_0x17ffd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FFD0_0x17ffd0");
#endif

    switch (ctx->pc) {
        case 0x17fff4u: goto label_17fff4;
        case 0x180060u: goto label_180060;
        default: break;
    }

    ctx->pc = 0x17ffd0u;

    // 0x17ffd0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17ffd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17ffd4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17ffd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17ffd8: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ffd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ffdc: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17ffdcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ffe0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ffe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ffe4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17ffe4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ffe8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17ffe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17ffec: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FFECu;
    SET_GPR_U32(ctx, 31, 0x17FFF4u);
    ctx->pc = 0x17FFF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FFECu;
            // 0x17fff0: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFF4u; }
        if (ctx->pc != 0x17FFF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FFF4u; }
        if (ctx->pc != 0x17FFF4u) { return; }
    }
    ctx->pc = 0x17FFF4u;
label_17fff4:
    // 0x17fff4: 0x4be0012c  vsub.xyzw   $vf4, $vf0, $vf0
    ctx->pc = 0x17fff4u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[0], ctx->vu0_vf[0]); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[4] = PS2_VBLEND(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17fff8: 0x3c034580  lui         $v1, 0x4580
    ctx->pc = 0x17fff8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17792 << 16));
    // 0x17fffc: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x17fffcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x180000: 0x34634580  ori         $v1, $v1, 0x4580
    ctx->pc = 0x180000u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17792);
    // 0x180004: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x180004u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x180008: 0xda460000  lqc2        $vf6, 0x0($s2)
    ctx->pc = 0x180008u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18000c: 0xda280000  lqc2        $vf8, 0x0($s1)
    ctx->pc = 0x18000cu;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x180010: 0xda090000  lqc2        $vf9, 0x0($s0)
    ctx->pc = 0x180010u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x180014: 0x48a33800  qmtc2.ni    $v1, $vf7
    ctx->pc = 0x180014u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(GPR_VEC(ctx, 3));
    // 0x180018: 0x48c08000  ctc2.ni     $zero, $vi16
    ctx->pc = 0x180018u;
    ctx->vu0_vpu_stat4 = GPR_U32(ctx, 0);
    // 0x18001c: 0x4ba4316c  vsub.xyw    $vf5, $vf6, $vf4
    ctx->pc = 0x18001cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[6], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180020: 0x4b86396c  vsub.xy     $vf5, $vf7, $vf6
    ctx->pc = 0x180020u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180024: 0x4ba4416c  vsub.xyw    $vf5, $vf8, $vf4
    ctx->pc = 0x180024u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[8], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180028: 0x4b88396c  vsub.xy     $vf5, $vf7, $vf8
    ctx->pc = 0x180028u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[8]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x18002c: 0x4ba4496c  vsub.xyw    $vf5, $vf9, $vf4
    ctx->pc = 0x18002cu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[9], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(-1, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180030: 0x4b89396c  vsub.xy     $vf5, $vf7, $vf9
    ctx->pc = 0x180030u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[9]); __m128i mask = _mm_set_epi32(0, 0, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x180034: 0x4a0002ff  vnop
    ctx->pc = 0x180034u;
    // NOP operation, no action needed for VU0
    // 0x180038: 0x4a0002ff  vnop
    ctx->pc = 0x180038u;
    // NOP operation, no action needed for VU0
    // 0x18003c: 0x4a0002ff  vnop
    ctx->pc = 0x18003cu;
    // NOP operation, no action needed for VU0
    // 0x180040: 0x4a0002ff  vnop
    ctx->pc = 0x180040u;
    // NOP operation, no action needed for VU0
    // 0x180044: 0x4a0002ff  vnop
    ctx->pc = 0x180044u;
    // NOP operation, no action needed for VU0
    // 0x180048: 0x48438000  cfc2.ni     $v1, $vi16
    ctx->pc = 0x180048u;
    SET_GPR_U32(ctx, 3, ctx->vu0_vpu_stat4);
    // 0x18004c: 0x306300c0  andi        $v1, $v1, 0xC0
    ctx->pc = 0x18004cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)192);
    // 0x180050: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x180050u;
    {
        const bool branch_taken_0x180050 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x180054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180050u;
            // 0x180054: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180050) {
            ctx->pc = 0x180060u;
            goto label_180060;
        }
    }
    ctx->pc = 0x180058u;
    // 0x180058: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x180058u;
    SET_GPR_U32(ctx, 31, 0x180060u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180060u; }
        if (ctx->pc != 0x180060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180060u; }
        if (ctx->pc != 0x180060u) { return; }
    }
    ctx->pc = 0x180060u;
label_180060:
    // 0x180060: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x180060u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180064: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x180064u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x180068: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x180068u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18006c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x18006cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x180070: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x180070u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180074: 0x3e00008  jr          $ra
    ctx->pc = 0x180074u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180074u;
            // 0x180078: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17FFF4u: goto label_17fff4;
            case 0x180060u: goto label_180060;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18007Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

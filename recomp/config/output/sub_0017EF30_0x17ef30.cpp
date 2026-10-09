#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EF30
// Address: 0x17ef30 - 0x17efb8
void sub_0017EF30_0x17ef30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EF30_0x17ef30");
#endif

    switch (ctx->pc) {
        case 0x17ef5cu: goto label_17ef5c;
        default: break;
    }

    ctx->pc = 0x17ef30u;

    // 0x17ef30: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17ef30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17ef34: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17ef34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17ef38: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ef38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ef3c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17ef3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ef40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ef40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ef44: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17ef44u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ef48: 0xe7b40040  swc1        $f20, 0x40($sp)
    ctx->pc = 0x17ef48u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x17ef4c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x17ef4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ef50: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17ef50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17ef54: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EF54u;
    SET_GPR_U32(ctx, 31, 0x17EF5Cu);
    ctx->pc = 0x17EF58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF54u;
            // 0x17ef58: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EF5Cu; }
        if (ctx->pc != 0x17EF5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EF5Cu; }
        if (ctx->pc != 0x17EF5Cu) { return; }
    }
    ctx->pc = 0x17EF5Cu;
label_17ef5c:
    // 0x17ef5c: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17ef5cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17ef60: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17ef60u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ef64: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17ef64u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17ef68: 0x48a83000  qmtc2.ni    $t0, $vf6
    ctx->pc = 0x17ef68u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17ef6c: 0x4b0001c3  vaddw.x     $vf7, $vf0, $vf0w
    ctx->pc = 0x17ef6cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(3,3,3,3))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[7] = _mm_blendv_ps(ctx->vu0_vf[7], res, _mm_castsi128_ps(mask)); }
    // 0x17ef70: 0x4b063a2c  vsub.x      $vf8, $vf7, $vf6
    ctx->pc = 0x17ef70u;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[7], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[8] = PS2_VBLEND(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x17ef74: 0x4be621bc  vmulax.xyzw $ACC, $vf4, $vf6x
    ctx->pc = 0x17ef74u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[6], ctx->vu0_vf[6], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x17ef78: 0x4be82a48  vmaddx.xyzw $vf9, $vf5, $vf8x
    ctx->pc = 0x17ef78u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x17ef7c: 0xfa490000  sqc2        $vf9, 0x0($s2)
    ctx->pc = 0x17ef7cu;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x17ef80: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17EF80u;
    {
        const bool branch_taken_0x17ef80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EF84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF80u;
            // 0x17ef84: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ef80) {
            ctx->pc = 0x17EFA0u;
            goto label_17efa0;
        }
    }
    ctx->pc = 0x17EF88u;
    // 0x17ef88: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17ef88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17ef8c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ef8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ef90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ef90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ef94: 0xc7b40040  lwc1        $f20, 0x40($sp)
    ctx->pc = 0x17ef94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ef98: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EF98u;
    ctx->pc = 0x17EF9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EF98u;
            // 0x17ef9c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EFA0u;
label_17efa0:
    // 0x17efa0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17efa0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17efa4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17efa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17efa8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17efa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17efac: 0xc7b40040  lwc1        $f20, 0x40($sp)
    ctx->pc = 0x17efacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17efb0: 0x3e00008  jr          $ra
    ctx->pc = 0x17EFB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EFB0u;
            // 0x17efb4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EF5Cu: goto label_17ef5c;
            case 0x17EFA0u: goto label_17efa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EFB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

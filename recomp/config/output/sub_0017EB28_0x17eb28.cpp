#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EB28
// Address: 0x17eb28 - 0x17ebb8
void sub_0017EB28_0x17eb28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EB28_0x17eb28");
#endif

    switch (ctx->pc) {
        case 0x17eb4cu: goto label_17eb4c;
        case 0x17eb60u: goto label_17eb60;
        default: break;
    }

    ctx->pc = 0x17eb28u;

    // 0x17eb28: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17eb28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17eb2c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17eb2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17eb30: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17eb30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17eb34: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17eb34u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17eb38: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17eb38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17eb3c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17eb3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17eb40: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17eb40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17eb44: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EB44u;
    SET_GPR_U32(ctx, 31, 0x17EB4Cu);
    ctx->pc = 0x17EB48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EB44u;
            // 0x17eb48: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EB4Cu; }
        if (ctx->pc != 0x17EB4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EB4Cu; }
        if (ctx->pc != 0x17EB4Cu) { return; }
    }
    ctx->pc = 0x17EB4Cu;
label_17eb4c:
    // 0x17eb4c: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17eb4cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17eb50: 0xda250010  lqc2        $vf5, 0x10($s1)
    ctx->pc = 0x17eb50u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x17eb54: 0xda260020  lqc2        $vf6, 0x20($s1)
    ctx->pc = 0x17eb54u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x17eb58: 0xda270030  lqc2        $vf7, 0x30($s1)
    ctx->pc = 0x17eb58u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x17eb5c: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x17eb5cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_17eb60:
    // 0x17eb60: 0xda080000  lqc2        $vf8, 0x0($s0)
    ctx->pc = 0x17eb60u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17eb64: 0x4be821bc  vmulax.xyzw $ACC, $vf4, $vf8x
    ctx->pc = 0x17eb64u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17eb68: 0x4be828bd  vmadday.xyzw $ACC, $vf5, $vf8y
    ctx->pc = 0x17eb68u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17eb6c: 0x4be830be  vmaddaz.xyzw $ACC, $vf6, $vf8z
    ctx->pc = 0x17eb6cu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); { __m128 accres = res; __m128i amask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, accres, _mm_castsi128_ps(amask)); } }
    // 0x17eb70: 0x4be83a4b  vmaddw.xyzw $vf9, $vf7, $vf8w
    ctx->pc = 0x17eb70u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x17eb74: 0xfa490000  sqc2        $vf9, 0x0($s2)
    ctx->pc = 0x17eb74u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x17eb78: 0x20e7ffff  addi        $a3, $a3, -0x1
    ctx->pc = 0x17eb78u;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 7), (int32_t)4294967295, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 7, (int32_t)tmp); }
    // 0x17eb7c: 0x22100010  addi        $s0, $s0, 0x10
    ctx->pc = 0x17eb7cu;
    { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 16), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 16, (int32_t)tmp); }
    // 0x17eb80: 0x1407fff7  bne         $zero, $a3, . + 4 + (-0x9 << 2)
    ctx->pc = 0x17EB80u;
    {
        const bool branch_taken_0x17eb80 = (GPR_U64(ctx, 0) != GPR_U64(ctx, 7));
        ctx->pc = 0x17EB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EB80u;
            // 0x17eb84: 0x22520010  addi        $s2, $s2, 0x10 (Delay Slot)
        { uint32_t tmp; bool ov; ADD32_OV(GPR_U32(ctx, 18), (int32_t)16, tmp, ov); if (ov) runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S32(ctx, 18, (int32_t)tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x17eb80) {
            ctx->pc = 0x17EB60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17eb60;
        }
    }
    ctx->pc = 0x17EB88u;
    // 0x17eb88: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17EB88u;
    {
        const bool branch_taken_0x17eb88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EB8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EB88u;
            // 0x17eb8c: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17eb88) {
            ctx->pc = 0x17EBA4u;
            goto label_17eba4;
        }
    }
    ctx->pc = 0x17EB90u;
    // 0x17eb90: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17eb90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17eb94: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17eb94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17eb98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17eb98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17eb9c: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EB9Cu;
    ctx->pc = 0x17EBA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EB9Cu;
            // 0x17eba0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EBA4u;
label_17eba4:
    // 0x17eba4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17eba4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17eba8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17eba8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ebac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ebacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ebb0: 0x3e00008  jr          $ra
    ctx->pc = 0x17EBB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EBB0u;
            // 0x17ebb4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EB4Cu: goto label_17eb4c;
            case 0x17EB60u: goto label_17eb60;
            case 0x17EBA4u: goto label_17eba4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EBB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

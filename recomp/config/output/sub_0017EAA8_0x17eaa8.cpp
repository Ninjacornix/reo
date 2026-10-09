#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EAA8
// Address: 0x17eaa8 - 0x17eb24
void sub_0017EAA8_0x17eaa8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EAA8_0x17eaa8");
#endif

    switch (ctx->pc) {
        case 0x17eaccu: goto label_17eacc;
        default: break;
    }

    ctx->pc = 0x17eaa8u;

    // 0x17eaa8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17eaa8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17eaac: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17eaacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17eab0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17eab0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17eab4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17eab4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17eab8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17eab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17eabc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17eabcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17eac0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17eac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17eac4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EAC4u;
    SET_GPR_U32(ctx, 31, 0x17EACCu);
    ctx->pc = 0x17EAC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EAC4u;
            // 0x17eac8: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EACCu; }
        if (ctx->pc != 0x17EACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EACCu; }
        if (ctx->pc != 0x17EACCu) { return; }
    }
    ctx->pc = 0x17EACCu;
label_17eacc:
    // 0x17eacc: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17eaccu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17ead0: 0xda250010  lqc2        $vf5, 0x10($s1)
    ctx->pc = 0x17ead0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x17ead4: 0xda260020  lqc2        $vf6, 0x20($s1)
    ctx->pc = 0x17ead4u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x17ead8: 0xda270030  lqc2        $vf7, 0x30($s1)
    ctx->pc = 0x17ead8u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x17eadc: 0xda080000  lqc2        $vf8, 0x0($s0)
    ctx->pc = 0x17eadcu;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17eae0: 0x4be821bc  vmulax.xyzw $ACC, $vf4, $vf8x
    ctx->pc = 0x17eae0u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); ctx->vu0_acc = res; }
    // 0x17eae4: 0x4be828bd  vmadday.xyzw $ACC, $vf5, $vf8y
    ctx->pc = 0x17eae4u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17eae8: 0x4be830be  vmaddaz.xyzw $ACC, $vf6, $vf8z
    ctx->pc = 0x17eae8u;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); ctx->vu0_acc = res; }
    // 0x17eaec: 0x4be83a4b  vmaddw.xyzw $vf9, $vf7, $vf8w
    ctx->pc = 0x17eaecu;
    { __m128 mul_res = PS2_VMUL(ctx->vu0_vf[7], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(3,3,3,3))); __m128 res = PS2_VADD(ctx->vu0_acc, mul_res); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[9] = _mm_blendv_ps(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); ctx->vu0_acc = res; }
    // 0x17eaf0: 0xfa490000  sqc2        $vf9, 0x0($s2)
    ctx->pc = 0x17eaf0u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x17eaf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17EAF4u;
    {
        const bool branch_taken_0x17eaf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EAF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EAF4u;
            // 0x17eaf8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17eaf4) {
            ctx->pc = 0x17EB10u;
            goto label_17eb10;
        }
    }
    ctx->pc = 0x17EAFCu;
    // 0x17eafc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17eafcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17eb00: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17eb00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17eb04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17eb04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17eb08: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EB08u;
    ctx->pc = 0x17EB0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EB08u;
            // 0x17eb0c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EB10u;
label_17eb10:
    // 0x17eb10: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17eb10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17eb14: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17eb14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17eb18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17eb18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17eb1c: 0x3e00008  jr          $ra
    ctx->pc = 0x17EB1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EB20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EB1Cu;
            // 0x17eb20: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EACCu: goto label_17eacc;
            case 0x17EB10u: goto label_17eb10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EB24u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

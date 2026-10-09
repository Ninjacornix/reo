#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FEE8
// Address: 0x17fee8 - 0x17ff50
void sub_0017FEE8_0x17fee8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FEE8_0x17fee8");
#endif

    switch (ctx->pc) {
        case 0x17ff0cu: goto label_17ff0c;
        default: break;
    }

    ctx->pc = 0x17fee8u;

    // 0x17fee8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17fee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17feec: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17feecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17fef0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17fef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17fef4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17fef4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fef8: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17fef8u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17fefc: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17fefcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ff00: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17ff00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17ff04: 0xc047598  jal         func_11D660
    ctx->pc = 0x17FF04u;
    SET_GPR_U32(ctx, 31, 0x17FF0Cu);
    ctx->pc = 0x17FF08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF04u;
            // 0x17ff08: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF0Cu; }
        if (ctx->pc != 0x17FF0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FF0Cu; }
        if (ctx->pc != 0x17FF0Cu) { return; }
    }
    ctx->pc = 0x17FF0Cu;
label_17ff0c:
    // 0x17ff0c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17ff0cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ff10: 0x4408a000  mfc1        $t0, $f20
    ctx->pc = 0x17ff10u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17ff14: 0x48a82800  qmtc2.ni    $t0, $vf5
    ctx->pc = 0x17ff14u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17ff18: 0x4bc52118  vmulx.xyz   $vf4, $vf4, $vf5x
    ctx->pc = 0x17ff18u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x17ff1c: 0xfa240000  sqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17ff1cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x17ff20: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17FF20u;
    {
        const bool branch_taken_0x17ff20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17FF24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF20u;
            // 0x17ff24: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ff20) {
            ctx->pc = 0x17FF3Cu;
            goto label_17ff3c;
        }
    }
    ctx->pc = 0x17FF28u;
    // 0x17ff28: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ff28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ff2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ff2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ff30: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17ff30u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ff34: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17FF34u;
    ctx->pc = 0x17FF38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF34u;
            // 0x17ff38: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17FF3Cu;
label_17ff3c:
    // 0x17ff3c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ff3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ff40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ff40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ff44: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17ff44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ff48: 0x3e00008  jr          $ra
    ctx->pc = 0x17FF48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FF4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FF48u;
            // 0x17ff4c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17FF0Cu: goto label_17ff0c;
            case 0x17FF3Cu: goto label_17ff3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FF50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

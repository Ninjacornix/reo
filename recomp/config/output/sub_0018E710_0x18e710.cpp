#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E710
// Address: 0x18e710 - 0x18e7d0
void sub_0018E710_0x18e710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E710_0x18e710");
#endif

    switch (ctx->pc) {
        case 0x18e740u: goto label_18e740;
        case 0x18e7bcu: goto label_18e7bc;
        default: break;
    }

    ctx->pc = 0x18e710u;

    // 0x18e710: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18e710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18e714: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18e714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x18e718: 0x27a60038  addiu       $a2, $sp, 0x38
    ctx->pc = 0x18e718u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x18e71c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x18e71cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x18e720: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x18e720u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x18e724: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18e724u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e728: 0xafa0003c  sw          $zero, 0x3C($sp)
    ctx->pc = 0x18e728u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 0));
    // 0x18e72c: 0x46006506  mov.s       $f20, $f12
    ctx->pc = 0x18e72cu;
    ctx->f[20] = FPU_MOV_S(ctx->f[12]);
    // 0x18e730: 0xafa00038  sw          $zero, 0x38($sp)
    ctx->pc = 0x18e730u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
    // 0x18e734: 0x86070000  lh          $a3, 0x0($s0)
    ctx->pc = 0x18e734u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18e738: 0xc063bac  jal         func_18EEB0
    ctx->pc = 0x18E738u;
    SET_GPR_U32(ctx, 31, 0x18E740u);
    ctx->pc = 0x18E73Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E738u;
            // 0x18e73c: 0x27a5003c  addiu       $a1, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18EEB0u;
    if (runtime->hasFunction(0x18EEB0u)) {
        auto targetFn = runtime->lookupFunction(0x18EEB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E740u; }
        if (ctx->pc != 0x18E740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018EEB0_0x18eeb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E740u; }
        if (ctx->pc != 0x18E740u) { return; }
    }
    ctx->pc = 0x18E740u;
label_18e740:
    // 0x18e740: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x18e740u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x18e744: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x18e744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x18e748: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18E748u;
    {
        const bool branch_taken_0x18e748 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e748) {
            ctx->pc = 0x18E764u;
            goto label_18e764;
        }
    }
    ctx->pc = 0x18E750u;
    // 0x18e750: 0x8fa2003c  lw          $v0, 0x3C($sp)
    ctx->pc = 0x18e750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e754: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x18e754u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18e758: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18e758u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e75c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x18E75Cu;
    {
        const bool branch_taken_0x18e75c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E75Cu;
            // 0x18e760: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e75c) {
            ctx->pc = 0x18E7BCu;
            goto label_18e7bc;
        }
    }
    ctx->pc = 0x18E764u;
label_18e764:
    // 0x18e764: 0x84440000  lh          $a0, 0x0($v0)
    ctx->pc = 0x18e764u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18e768: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x18e768u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x18e76c: 0x8fa7003c  lw          $a3, 0x3C($sp)
    ctx->pc = 0x18e76cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e770: 0x84430002  lh          $v1, 0x2($v0)
    ctx->pc = 0x18e770u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x18e774: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x18e774u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e778: 0x84e60000  lh          $a2, 0x0($a3)
    ctx->pc = 0x18e778u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x18e77c: 0x84e50002  lh          $a1, 0x2($a3)
    ctx->pc = 0x18e77cu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x18e780: 0x46800c20  cvt.s.w     $f16, $f1
    ctx->pc = 0x18e780u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[16] = FPU_CVT_S_W(tmp); }
    // 0x18e784: 0x84420004  lh          $v0, 0x4($v0)
    ctx->pc = 0x18e784u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x18e788: 0x84e40006  lh          $a0, 0x6($a3)
    ctx->pc = 0x18e788u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 6)));
    // 0x18e78c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18e78cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e790: 0x44850800  mtc1        $a1, $f1
    ctx->pc = 0x18e790u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e794: 0x0  nop
    ctx->pc = 0x18e794u;
    // NOP
    // 0x18e798: 0x46800460  cvt.s.w     $f17, $f0
    ctx->pc = 0x18e798u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[17] = FPU_CVT_S_W(tmp); }
    // 0x18e79c: 0x46800ba0  cvt.s.w     $f14, $f1
    ctx->pc = 0x18e79cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[14] = FPU_CVT_S_W(tmp); }
    // 0x18e7a0: 0x44861000  mtc1        $a2, $f2
    ctx->pc = 0x18e7a0u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x18e7a4: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x18e7a4u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e7a8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18e7a8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e7ac: 0x46801360  cvt.s.w     $f13, $f2
    ctx->pc = 0x18e7acu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
    // 0x18e7b0: 0x46800be0  cvt.s.w     $f15, $f1
    ctx->pc = 0x18e7b0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x18e7b4: 0xc063c98  jal         func_18F260
    ctx->pc = 0x18E7B4u;
    SET_GPR_U32(ctx, 31, 0x18E7BCu);
    ctx->pc = 0x18E7B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E7B4u;
            // 0x18e7b8: 0x468004a0  cvt.s.w     $f18, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[18] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F260u;
    if (runtime->hasFunction(0x18F260u)) {
        auto targetFn = runtime->lookupFunction(0x18F260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E7BCu; }
        if (ctx->pc != 0x18E7BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F260_0x18f260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E7BCu; }
        if (ctx->pc != 0x18E7BCu) { return; }
    }
    ctx->pc = 0x18E7BCu;
label_18e7bc:
    // 0x18e7bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18e7bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18e7c0: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x18e7c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x18e7c4: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x18e7c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18e7c8: 0x3e00008  jr          $ra
    ctx->pc = 0x18E7C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E7CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E7C8u;
            // 0x18e7cc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E740u: goto label_18e740;
            case 0x18E764u: goto label_18e764;
            case 0x18E7BCu: goto label_18e7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E7D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

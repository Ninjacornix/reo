#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E660
// Address: 0x18e660 - 0x18e710
void sub_0018E660_0x18e660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E660_0x18e660");
#endif

    switch (ctx->pc) {
        case 0x18e690u: goto label_18e690;
        case 0x18e6f0u: goto label_18e6f0;
        default: break;
    }

    ctx->pc = 0x18e660u;

    // 0x18e660: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18e660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18e664: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18e664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x18e668: 0x27a60038  addiu       $a2, $sp, 0x38
    ctx->pc = 0x18e668u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x18e66c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x18e66cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x18e670: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x18e670u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x18e674: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18e674u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e678: 0xafa0003c  sw          $zero, 0x3C($sp)
    ctx->pc = 0x18e678u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 0));
    // 0x18e67c: 0x46006506  mov.s       $f20, $f12
    ctx->pc = 0x18e67cu;
    ctx->f[20] = FPU_MOV_S(ctx->f[12]);
    // 0x18e680: 0xafa00038  sw          $zero, 0x38($sp)
    ctx->pc = 0x18e680u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
    // 0x18e684: 0x86070000  lh          $a3, 0x0($s0)
    ctx->pc = 0x18e684u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18e688: 0xc063b48  jal         func_18ED20
    ctx->pc = 0x18E688u;
    SET_GPR_U32(ctx, 31, 0x18E690u);
    ctx->pc = 0x18E68Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E688u;
            // 0x18e68c: 0x27a5003c  addiu       $a1, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18ED20u;
    if (runtime->hasFunction(0x18ED20u)) {
        auto targetFn = runtime->lookupFunction(0x18ED20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E690u; }
        if (ctx->pc != 0x18E690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018ED20_0x18ed20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E690u; }
        if (ctx->pc != 0x18E690u) { return; }
    }
    ctx->pc = 0x18E690u;
label_18e690:
    // 0x18e690: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x18e690u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x18e694: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x18e694u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x18e698: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x18E698u;
    {
        const bool branch_taken_0x18e698 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e698) {
            ctx->pc = 0x18E6B4u;
            goto label_18e6b4;
        }
    }
    ctx->pc = 0x18E6A0u;
    // 0x18e6a0: 0x8fa2003c  lw          $v0, 0x3C($sp)
    ctx->pc = 0x18e6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e6a4: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x18e6a4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18e6a8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18e6a8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e6ac: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x18E6ACu;
    {
        const bool branch_taken_0x18e6ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E6B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E6ACu;
            // 0x18e6b0: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e6ac) {
            ctx->pc = 0x18E6F0u;
            goto label_18e6f0;
        }
    }
    ctx->pc = 0x18E6B4u;
label_18e6b4:
    // 0x18e6b4: 0x8fa4003c  lw          $a0, 0x3C($sp)
    ctx->pc = 0x18e6b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x18e6b8: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x18e6b8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x18e6bc: 0x84430000  lh          $v1, 0x0($v0)
    ctx->pc = 0x18e6bcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18e6c0: 0x84850000  lh          $a1, 0x0($a0)
    ctx->pc = 0x18e6c0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18e6c4: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x18e6c4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e6c8: 0x84420002  lh          $v0, 0x2($v0)
    ctx->pc = 0x18e6c8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x18e6cc: 0x46800be0  cvt.s.w     $f15, $f1
    ctx->pc = 0x18e6ccu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x18e6d0: 0x84840002  lh          $a0, 0x2($a0)
    ctx->pc = 0x18e6d0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18e6d4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18e6d4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18e6d8: 0x44851000  mtc1        $a1, $f2
    ctx->pc = 0x18e6d8u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x18e6dc: 0x46800420  cvt.s.w     $f16, $f0
    ctx->pc = 0x18e6dcu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[16] = FPU_CVT_S_W(tmp); }
    // 0x18e6e0: 0x44840800  mtc1        $a0, $f1
    ctx->pc = 0x18e6e0u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18e6e4: 0x46801360  cvt.s.w     $f13, $f2
    ctx->pc = 0x18e6e4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
    // 0x18e6e8: 0xc063c78  jal         func_18F1E0
    ctx->pc = 0x18E6E8u;
    SET_GPR_U32(ctx, 31, 0x18E6F0u);
    ctx->pc = 0x18E6ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E6E8u;
            // 0x18e6ec: 0x46800ba0  cvt.s.w     $f14, $f1 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[14] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F1E0u;
    if (runtime->hasFunction(0x18F1E0u)) {
        auto targetFn = runtime->lookupFunction(0x18F1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E6F0u; }
        if (ctx->pc != 0x18E6F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F1E0_0x18f1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E6F0u; }
        if (ctx->pc != 0x18E6F0u) { return; }
    }
    ctx->pc = 0x18E6F0u;
label_18e6f0:
    // 0x18e6f0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18e6f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18e6f4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x18e6f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x18e6f8: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x18e6f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18e6fc: 0x3e00008  jr          $ra
    ctx->pc = 0x18E6FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E6FCu;
            // 0x18e700: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E690u: goto label_18e690;
            case 0x18E6B4u: goto label_18e6b4;
            case 0x18E6F0u: goto label_18e6f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E704u;
    // 0x18e704: 0x0  nop
    ctx->pc = 0x18e704u;
    // NOP
    // 0x18e708: 0x0  nop
    ctx->pc = 0x18e708u;
    // NOP
    // 0x18e70c: 0x0  nop
    ctx->pc = 0x18e70cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

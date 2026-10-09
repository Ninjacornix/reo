#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2620
// Address: 0x1b2620 - 0x1b273c
void sub_001B2620_0x1b2620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2620_0x1b2620");
#endif

    switch (ctx->pc) {
        case 0x1b2648u: goto label_1b2648;
        case 0x1b2690u: goto label_1b2690;
        case 0x1b271cu: goto label_1b271c;
        default: break;
    }

    ctx->pc = 0x1b2620u;

    // 0x1b2620: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b2620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b2624: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b2624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b2628: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1b2628u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1b262c: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1b262cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1b2630: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b2630u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2634: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1b2634u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1b2638: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1b2638u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b263c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1b263cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1b2640: 0xc06c9e4  jal         func_1B2790
    ctx->pc = 0x1B2640u;
    SET_GPR_U32(ctx, 31, 0x1B2648u);
    ctx->pc = 0x1B2644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2640u;
            // 0x1b2644: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2790u;
    if (runtime->hasFunction(0x1B2790u)) {
        auto targetFn = runtime->lookupFunction(0x1B2790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2648u; }
        if (ctx->pc != 0x1B2648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2790_0x1b2790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2648u; }
        if (ctx->pc != 0x1B2648u) { return; }
    }
    ctx->pc = 0x1B2648u;
label_1b2648:
    // 0x1b2648: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B2648u;
    {
        const bool branch_taken_0x1b2648 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B264Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2648u;
            // 0x1b264c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2648) {
            ctx->pc = 0x1B2658u;
            goto label_1b2658;
        }
    }
    ctx->pc = 0x1B2650u;
    // 0x1b2650: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1B2650u;
    {
        const bool branch_taken_0x1b2650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2650u;
            // 0x1b2654: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2650) {
            ctx->pc = 0x1B2720u;
            goto label_1b2720;
        }
    }
    ctx->pc = 0x1B2658u;
label_1b2658:
    // 0x1b2658: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1b2658u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b265c: 0x0  nop
    ctx->pc = 0x1b265cu;
    // NOP
    // 0x1b2660: 0x4600a034  c.lt.s      $f20, $f0
    ctx->pc = 0x1b2660u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2664: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1B2664u;
    {
        const bool branch_taken_0x1b2664 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B2668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2664u;
            // 0x1b2668: 0x3402c350  ori         $v0, $zero, 0xC350 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)50000);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2664) {
            ctx->pc = 0x1B2670u;
            goto label_1b2670;
        }
    }
    ctx->pc = 0x1B266Cu;
    // 0x1b266c: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x1b266cu;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
label_1b2670:
    // 0x1b2670: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b2670u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b2674: 0x0  nop
    ctx->pc = 0x1b2674u;
    // NOP
    // 0x1b2678: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b2678u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b267c: 0x4600a036  c.le.s      $f20, $f0
    ctx->pc = 0x1b267cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2680: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B2680u;
    {
        const bool branch_taken_0x1b2680 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b2680) {
            ctx->pc = 0x1B2698u;
            goto label_1b2698;
        }
    }
    ctx->pc = 0x1B2688u;
    // 0x1b2688: 0xc06ca04  jal         func_1B2810
    ctx->pc = 0x1B2688u;
    SET_GPR_U32(ctx, 31, 0x1B2690u);
    ctx->pc = 0x1B2810u;
    if (runtime->hasFunction(0x1B2810u)) {
        auto targetFn = runtime->lookupFunction(0x1B2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2690u; }
        if (ctx->pc != 0x1B2690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2810_0x1b2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2690u; }
        if (ctx->pc != 0x1B2690u) { return; }
    }
    ctx->pc = 0x1B2690u;
label_1b2690:
    // 0x1b2690: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1B2690u;
    {
        const bool branch_taken_0x1b2690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2690u;
            // 0x1b2694: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2690) {
            ctx->pc = 0x1B2720u;
            goto label_1b2720;
        }
    }
    ctx->pc = 0x1B2698u;
label_1b2698:
    // 0x1b2698: 0xae12001c  sw          $s2, 0x1C($s0)
    ctx->pc = 0x1b2698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 18));
    // 0x1b269c: 0x0  nop
    ctx->pc = 0x1b269cu;
    // NOP
    // 0x1b26a0: 0x4600a083  div.s       $f2, $f20, $f0
    ctx->pc = 0x1b26a0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[20] / ctx->f[0];
    // 0x1b26a4: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x1b26a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x1b26a8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1b26a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1b26ac: 0xae110018  sw          $s1, 0x18($s0)
    ctx->pc = 0x1b26acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 17));
    // 0x1b26b0: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1b26b0u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b26b4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b26b4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b26b8: 0x0  nop
    ctx->pc = 0x1b26b8u;
    // NOP
    // 0x1b26bc: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x1b26bcu;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1b26c0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1b26c0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b26c4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B26C4u;
    {
        const bool branch_taken_0x1b26c4 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B26C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B26C4u;
            // 0x1b26c8: 0xe6140010  swc1        $f20, 0x10($s0) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 16), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b26c4) {
            ctx->pc = 0x1B26DCu;
            goto label_1b26dc;
        }
    }
    ctx->pc = 0x1B26CCu;
    // 0x1b26cc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b26ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b26d0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b26d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b26d4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B26D4u;
    {
        const bool branch_taken_0x1b26d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B26D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B26D4u;
            // 0x1b26d8: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b26d4) {
            ctx->pc = 0x1B26F8u;
            goto label_1b26f8;
        }
    }
    ctx->pc = 0x1B26DCu;
label_1b26dc:
    // 0x1b26dc: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1b26dcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b26e0: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1b26e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1b26e4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b26e4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b26e8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b26e8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b26ec: 0x0  nop
    ctx->pc = 0x1b26ecu;
    // NOP
    // 0x1b26f0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1b26f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1b26f4: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1b26f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_1b26f8:
    // 0x1b26f8: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b26f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b26fc: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x1b26fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b2700: 0x2403007f  addiu       $v1, $zero, 0x7F
    ctx->pc = 0x1b2700u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1b2704: 0x244288e0  addiu       $v0, $v0, -0x7720
    ctx->pc = 0x1b2704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936800));
    // 0x1b2708: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b2708u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b270c: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x1b270cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1b2710: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b2710u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b2714: 0xc06ca14  jal         func_1B2850
    ctx->pc = 0x1B2714u;
    SET_GPR_U32(ctx, 31, 0x1B271Cu);
    ctx->pc = 0x1B2718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2714u;
            // 0x1b2718: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2850u;
    if (runtime->hasFunction(0x1B2850u)) {
        auto targetFn = runtime->lookupFunction(0x1B2850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B271Cu; }
        if (ctx->pc != 0x1B271Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2850_0x1b2850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B271Cu; }
        if (ctx->pc != 0x1B271Cu) { return; }
    }
    ctx->pc = 0x1B271Cu;
label_1b271c:
    // 0x1b271c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1b271cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_1b2720:
    // 0x1b2720: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b2720u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b2724: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1b2724u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1b2728: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1b2728u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b272c: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1b272cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b2730: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1b2730u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2734: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2734u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2734u;
            // 0x1b2738: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2648u: goto label_1b2648;
            case 0x1B2658u: goto label_1b2658;
            case 0x1B2670u: goto label_1b2670;
            case 0x1B2690u: goto label_1b2690;
            case 0x1B2698u: goto label_1b2698;
            case 0x1B26DCu: goto label_1b26dc;
            case 0x1B26F8u: goto label_1b26f8;
            case 0x1B271Cu: goto label_1b271c;
            case 0x1B2720u: goto label_1b2720;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B273Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

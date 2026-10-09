#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B94B0
// Address: 0x1b94b0 - 0x1b9940
void sub_001B94B0_0x1b94b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B94B0_0x1b94b0");
#endif

    switch (ctx->pc) {
        case 0x1b94f0u: goto label_1b94f0;
        case 0x1b9528u: goto label_1b9528;
        case 0x1b9578u: goto label_1b9578;
        case 0x1b9584u: goto label_1b9584;
        case 0x1b9590u: goto label_1b9590;
        case 0x1b962cu: goto label_1b962c;
        case 0x1b96fcu: goto label_1b96fc;
        case 0x1b97a8u: goto label_1b97a8;
        case 0x1b9800u: goto label_1b9800;
        case 0x1b983cu: goto label_1b983c;
        case 0x1b9880u: goto label_1b9880;
        case 0x1b98fcu: goto label_1b98fc;
        case 0x1b9914u: goto label_1b9914;
        default: break;
    }

    ctx->pc = 0x1b94b0u;

    // 0x1b94b0: 0x27bdff00  addiu       $sp, $sp, -0x100
    ctx->pc = 0x1b94b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967040));
    // 0x1b94b4: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1b94b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1b94b8: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x1b94b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x1b94bc: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x1b94bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x1b94c0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b94c0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b94c4: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1b94c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1b94c8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b94c8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b94cc: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1b94ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1b94d0: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1b94d0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1b94d4: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1b94d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1b94d8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b94d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b94dc: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1b94dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b94e0: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1b94e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1b94e4: 0x24a540e0  addiu       $a1, $a1, 0x40E0
    ctx->pc = 0x1b94e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16608));
    // 0x1b94e8: 0xc06450c  jal         func_191430
    ctx->pc = 0x1B94E8u;
    SET_GPR_U32(ctx, 31, 0x1B94F0u);
    ctx->pc = 0x1B94ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B94E8u;
            // 0x1b94ec: 0xe7b40000  swc1        $f20, 0x0($sp) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191430u;
    if (runtime->hasFunction(0x191430u)) {
        auto targetFn = runtime->lookupFunction(0x191430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B94F0u; }
        if (ctx->pc != 0x1B94F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191430_0x191430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B94F0u; }
        if (ctx->pc != 0x1B94F0u) { return; }
    }
    ctx->pc = 0x1B94F0u;
label_1b94f0:
    // 0x1b94f0: 0xc6830004  lwc1        $f3, 0x4($s4)
    ctx->pc = 0x1b94f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1b94f4: 0xc7a200a4  lwc1        $f2, 0xA4($sp)
    ctx->pc = 0x1b94f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b94f8: 0xc6850000  lwc1        $f5, 0x0($s4)
    ctx->pc = 0x1b94f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x1b94fc: 0xc7a400a0  lwc1        $f4, 0xA0($sp)
    ctx->pc = 0x1b94fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1b9500: 0xc6810008  lwc1        $f1, 0x8($s4)
    ctx->pc = 0x1b9500u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9504: 0xc7a000a8  lwc1        $f0, 0xA8($sp)
    ctx->pc = 0x1b9504u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9508: 0x460218c1  sub.s       $f3, $f3, $f2
    ctx->pc = 0x1b9508u;
    ctx->f[3] = FPU_SUB_S(ctx->f[3], ctx->f[2]);
    // 0x1b950c: 0x46000881  sub.s       $f2, $f1, $f0
    ctx->pc = 0x1b950cu;
    ctx->f[2] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b9510: 0x46042901  sub.s       $f4, $f5, $f4
    ctx->pc = 0x1b9510u;
    ctx->f[4] = FPU_SUB_S(ctx->f[5], ctx->f[4]);
    // 0x1b9514: 0x46042042  mul.s       $f1, $f4, $f4
    ctx->pc = 0x1b9514u;
    ctx->f[1] = FPU_MUL_S(ctx->f[4], ctx->f[4]);
    // 0x1b9518: 0x46031802  mul.s       $f0, $f3, $f3
    ctx->pc = 0x1b9518u;
    ctx->f[0] = FPU_MUL_S(ctx->f[3], ctx->f[3]);
    // 0x1b951c: 0x46000818  adda.s      $f1, $f0
    ctx->pc = 0x1b951cu;
    ctx->f[31] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1b9520: 0xc0dc620  jal         func_371880
    ctx->pc = 0x1B9520u;
    SET_GPR_U32(ctx, 31, 0x1B9528u);
    ctx->pc = 0x1B9524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9520u;
            // 0x1b9524: 0x4602131c  madd.s      $f12, $f2, $f2 (Delay Slot)
        ctx->f[12] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[2], ctx->f[2]));
        ctx->in_delay_slot = false;
    ctx->pc = 0x371880u;
    {
        auto targetFn = runtime->lookupFunction(0x371880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9528u; }
        if (ctx->pc != 0x1B9528u) { return; }
    }
    ctx->pc = 0x1B9528u;
label_1b9528:
    // 0x1b9528: 0x46000506  mov.s       $f20, $f0
    ctx->pc = 0x1b9528u;
    ctx->f[20] = FPU_MOV_S(ctx->f[0]);
    // 0x1b952c: 0x3c024596  lui         $v0, 0x4596
    ctx->pc = 0x1b952cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17814 << 16));
    // 0x1b9530: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b9530u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9534: 0x2410003f  addiu       $s0, $zero, 0x3F
    ctx->pc = 0x1b9534u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x1b9538: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x1b9538u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x1b953c: 0x4600a034  c.lt.s      $f20, $f0
    ctx->pc = 0x1b953cu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b9540: 0x45010003  bc1t        . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9540u;
    {
        const bool branch_taken_0x1b9540 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B9544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9540u;
            // 0x1b9544: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9540) {
            ctx->pc = 0x1B9550u;
            goto label_1b9550;
        }
    }
    ctx->pc = 0x1B9548u;
    // 0x1b9548: 0x10000055  b           . + 4 + (0x55 << 2)
    ctx->pc = 0x1B9548u;
    {
        const bool branch_taken_0x1b9548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B954Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9548u;
            // 0x1b954c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9548) {
            ctx->pc = 0x1B96A0u;
            goto label_1b96a0;
        }
    }
    ctx->pc = 0x1B9550u;
label_1b9550:
    // 0x1b9550: 0x3c0242c8  lui         $v0, 0x42C8
    ctx->pc = 0x1b9550u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17096 << 16));
    // 0x1b9554: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b9554u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9558: 0x0  nop
    ctx->pc = 0x1b9558u;
    // NOP
    // 0x1b955c: 0x4600a036  c.le.s      $f20, $f0
    ctx->pc = 0x1b955cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[20], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b9560: 0x45000003  bc1f        . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9560u;
    {
        const bool branch_taken_0x1b9560 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B9564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9560u;
            // 0x1b9564: 0x27a400b0  addiu       $a0, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9560) {
            ctx->pc = 0x1B9570u;
            goto label_1b9570;
        }
    }
    ctx->pc = 0x1B9568u;
    // 0x1b9568: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1B9568u;
    {
        const bool branch_taken_0x1b9568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B956Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9568u;
            // 0x1b956c: 0x8e620000  lw          $v0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9568) {
            ctx->pc = 0x1B9694u;
            goto label_1b9694;
        }
    }
    ctx->pc = 0x1B9570u;
label_1b9570:
    // 0x1b9570: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x1B9570u;
    SET_GPR_U32(ctx, 31, 0x1B9578u);
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9578u; }
        if (ctx->pc != 0x1B9578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9578u; }
        if (ctx->pc != 0x1B9578u) { return; }
    }
    ctx->pc = 0x1B9578u;
label_1b9578:
    // 0x1b9578: 0x27a500b0  addiu       $a1, $sp, 0xB0
    ctx->pc = 0x1b9578u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
    // 0x1b957c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B957Cu;
    SET_GPR_U32(ctx, 31, 0x1B9584u);
    ctx->pc = 0x1B9580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B957Cu;
            // 0x1b9580: 0x2404001a  addiu       $a0, $zero, 0x1A (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9584u; }
        if (ctx->pc != 0x1B9584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9584u; }
        if (ctx->pc != 0x1B9584u) { return; }
    }
    ctx->pc = 0x1B9584u;
label_1b9584:
    // 0x1b9584: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1b9584u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9588: 0xc064810  jal         func_192040
    ctx->pc = 0x1B9588u;
    SET_GPR_U32(ctx, 31, 0x1B9590u);
    ctx->pc = 0x1B958Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9588u;
            // 0x1b958c: 0x27a400f0  addiu       $a0, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192040u;
    if (runtime->hasFunction(0x192040u)) {
        auto targetFn = runtime->lookupFunction(0x192040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9590u; }
        if (ctx->pc != 0x1B9590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192040_0x192040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9590u; }
        if (ctx->pc != 0x1B9590u) { return; }
    }
    ctx->pc = 0x1B9590u;
label_1b9590:
    // 0x1b9590: 0xc7a100f0  lwc1        $f1, 0xF0($sp)
    ctx->pc = 0x1b9590u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 240)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9594: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1b9594u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9598: 0x0  nop
    ctx->pc = 0x1b9598u;
    // NOP
    // 0x1b959c: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1b959cu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b95a0: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1B95A0u;
    {
        const bool branch_taken_0x1b95a0 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b95a0) {
            ctx->pc = 0x1B95ACu;
            goto label_1b95ac;
        }
    }
    ctx->pc = 0x1B95A8u;
    // 0x1b95a8: 0xe7a000f0  swc1        $f0, 0xF0($sp)
    ctx->pc = 0x1b95a8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 240), bits); }
label_1b95ac:
    // 0x1b95ac: 0xc7a100f0  lwc1        $f1, 0xF0($sp)
    ctx->pc = 0x1b95acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 240)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b95b0: 0x3c024420  lui         $v0, 0x4420
    ctx->pc = 0x1b95b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17440 << 16));
    // 0x1b95b4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b95b4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b95b8: 0x0  nop
    ctx->pc = 0x1b95b8u;
    // NOP
    // 0x1b95bc: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1b95bcu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b95c0: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x1B95C0u;
    {
        const bool branch_taken_0x1b95c0 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b95c0) {
            ctx->pc = 0x1B95CCu;
            goto label_1b95cc;
        }
    }
    ctx->pc = 0x1B95C8u;
    // 0x1b95c8: 0xe7a000f0  swc1        $f0, 0xF0($sp)
    ctx->pc = 0x1b95c8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 240), bits); }
label_1b95cc:
    // 0x1b95cc: 0xc7a100fc  lwc1        $f1, 0xFC($sp)
    ctx->pc = 0x1b95ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 252)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b95d0: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1b95d0u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b95d4: 0x0  nop
    ctx->pc = 0x1b95d4u;
    // NOP
    // 0x1b95d8: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1b95d8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b95dc: 0x45000008  bc1f        . + 4 + (0x8 << 2)
    ctx->pc = 0x1B95DCu;
    {
        const bool branch_taken_0x1b95dc = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B95E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B95DCu;
            // 0x1b95e0: 0x3c024396  lui         $v0, 0x4396 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17302 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b95dc) {
            ctx->pc = 0x1B9600u;
            goto label_1b9600;
        }
    }
    ctx->pc = 0x1B95E4u;
    // 0x1b95e4: 0xc7a000f0  lwc1        $f0, 0xF0($sp)
    ctx->pc = 0x1b95e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 240)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b95e8: 0x3c024420  lui         $v0, 0x4420
    ctx->pc = 0x1b95e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17440 << 16));
    // 0x1b95ec: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1b95ecu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b95f0: 0x0  nop
    ctx->pc = 0x1b95f0u;
    // NOP
    // 0x1b95f4: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1b95f4u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b95f8: 0xe7a000f0  swc1        $f0, 0xF0($sp)
    ctx->pc = 0x1b95f8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 240), bits); }
    // 0x1b95fc: 0x3c024396  lui         $v0, 0x4396
    ctx->pc = 0x1b95fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17302 << 16));
label_1b9600:
    // 0x1b9600: 0x3c010025  lui         $at, 0x25
    ctx->pc = 0x1b9600u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)37 << 16));
    // 0x1b9604: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b9604u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9608: 0xc7a200f0  lwc1        $f2, 0xF0($sp)
    ctx->pc = 0x1b9608u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 240)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b960c: 0x4600a303  div.s       $f12, $f20, $f0
    ctx->pc = 0x1b960cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[12] = std::bit_cast<float>(__maxf); } else ctx->f[12] = ctx->f[20] / ctx->f[0];
    // 0x1b9610: 0xc4210230  lwc1        $f1, 0x230($at)
    ctx->pc = 0x1b9610u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 560)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9614: 0x46011003  div.s       $f0, $f2, $f1
    ctx->pc = 0x1b9614u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[2] / ctx->f[1];
    // 0x1b9618: 0x0  nop
    ctx->pc = 0x1b9618u;
    // NOP
    // 0x1b961c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b961cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b9620: 0x44100000  mfc1        $s0, $f0
    ctx->pc = 0x1b9620u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 16, bits); }
    // 0x1b9624: 0xc06487c  jal         func_1921F0
    ctx->pc = 0x1B9624u;
    SET_GPR_U32(ctx, 31, 0x1B962Cu);
    ctx->pc = 0x1921F0u;
    if (runtime->hasFunction(0x1921F0u)) {
        auto targetFn = runtime->lookupFunction(0x1921F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B962Cu; }
        if (ctx->pc != 0x1B962Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001921F0_0x1921f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B962Cu; }
        if (ctx->pc != 0x1B962Cu) { return; }
    }
    ctx->pc = 0x1B962Cu;
label_1b962c:
    // 0x1b962c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b962cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b9630: 0x3c024396  lui         $v0, 0x4396
    ctx->pc = 0x1b9630u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17302 << 16));
    // 0x1b9634: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1b9634u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b9638: 0x0  nop
    ctx->pc = 0x1b9638u;
    // NOP
    // 0x1b963c: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x1b963cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1b9640: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b9640u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b9644: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b9644u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b9648: 0x2621021  addu        $v0, $s3, $v0
    ctx->pc = 0x1b9648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1b964c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1b964cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b9650: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1b9650u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1b9654: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1b9654u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1b9658: 0x4600a001  sub.s       $f0, $f20, $f0
    ctx->pc = 0x1b9658u;
    ctx->f[0] = FPU_SUB_S(ctx->f[20], ctx->f[0]);
    // 0x1b965c: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1b965cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b9660: 0x46010043  div.s       $f1, $f0, $f1
    ctx->pc = 0x1b9660u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[0] / ctx->f[1];
    // 0x1b9664: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b9664u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b9668: 0x0  nop
    ctx->pc = 0x1b9668u;
    // NOP
    // 0x1b966c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b966cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b9670: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x1b9670u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1b9674: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b9674u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b9678: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x1b9678u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1b967c: 0x0  nop
    ctx->pc = 0x1b967cu;
    // NOP
    // 0x1b9680: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1b9680u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b9684: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B9684u;
    {
        const bool branch_taken_0x1b9684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b9684) {
            ctx->pc = 0x1B9694u;
            goto label_1b9694;
        }
    }
    ctx->pc = 0x1B968Cu;
    // 0x1b968c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B968Cu;
    {
        const bool branch_taken_0x1b968c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B968Cu;
            // 0x1b9690: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b968c) {
            ctx->pc = 0x1B96A0u;
            goto label_1b96a0;
        }
    }
    ctx->pc = 0x1B9694u;
label_1b9694:
    // 0x1b9694: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x1b9694u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x1b9698: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b9698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b969c: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x1b969cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
label_1b96a0:
    // 0x1b96a0: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1b96a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1b96a4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1b96a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1b96a8: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x1b96a8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b96ac: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x1b96acu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b96b0: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1b96b0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b96b4: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1b96b4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b96b8: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1b96b8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b96bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B96BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B96C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B96BCu;
            // 0x1b96c0: 0x27bd0100  addiu       $sp, $sp, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B94F0u: goto label_1b94f0;
            case 0x1B9528u: goto label_1b9528;
            case 0x1B9550u: goto label_1b9550;
            case 0x1B9570u: goto label_1b9570;
            case 0x1B9578u: goto label_1b9578;
            case 0x1B9584u: goto label_1b9584;
            case 0x1B9590u: goto label_1b9590;
            case 0x1B95ACu: goto label_1b95ac;
            case 0x1B95CCu: goto label_1b95cc;
            case 0x1B9600u: goto label_1b9600;
            case 0x1B962Cu: goto label_1b962c;
            case 0x1B9694u: goto label_1b9694;
            case 0x1B96A0u: goto label_1b96a0;
            case 0x1B96FCu: goto label_1b96fc;
            case 0x1B97A8u: goto label_1b97a8;
            case 0x1B97C4u: goto label_1b97c4;
            case 0x1B97C8u: goto label_1b97c8;
            case 0x1B97E8u: goto label_1b97e8;
            case 0x1B9800u: goto label_1b9800;
            case 0x1B983Cu: goto label_1b983c;
            case 0x1B9874u: goto label_1b9874;
            case 0x1B9878u: goto label_1b9878;
            case 0x1B9880u: goto label_1b9880;
            case 0x1B98B4u: goto label_1b98b4;
            case 0x1B98B8u: goto label_1b98b8;
            case 0x1B98C4u: goto label_1b98c4;
            case 0x1B98FCu: goto label_1b98fc;
            case 0x1B9914u: goto label_1b9914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B96C4u;
    // 0x1b96c4: 0x0  nop
    ctx->pc = 0x1b96c4u;
    // NOP
    // 0x1b96c8: 0x0  nop
    ctx->pc = 0x1b96c8u;
    // NOP
    // 0x1b96cc: 0x0  nop
    ctx->pc = 0x1b96ccu;
    // NOP
    // 0x1b96d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b96d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b96d4: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1b96d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1b96d8: 0x3c07003c  lui         $a3, 0x3C
    ctx->pc = 0x1b96d8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)60 << 16));
    // 0x1b96dc: 0x3c06003c  lui         $a2, 0x3C
    ctx->pc = 0x1b96dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)60 << 16));
    // 0x1b96e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b96e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b96e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b96e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b96e8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b96e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b96ec: 0x24844c50  addiu       $a0, $a0, 0x4C50
    ctx->pc = 0x1b96ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19536));
    // 0x1b96f0: 0x24e72750  addiu       $a3, $a3, 0x2750
    ctx->pc = 0x1b96f0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 10064));
    // 0x1b96f4: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1B96F4u;
    {
        const bool branch_taken_0x1b96f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B96F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B96F4u;
            // 0x1b96f8: 0x24c63000  addiu       $a2, $a2, 0x3000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 12288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b96f4) {
            ctx->pc = 0x1B97C8u;
            goto label_1b97c8;
        }
    }
    ctx->pc = 0x1B96FCu;
label_1b96fc:
    // 0x1b96fc: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1b96fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1b9700: 0x1024023  subu        $t0, $t0, $v0
    ctx->pc = 0x1b9700u;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x1b9704: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1b9704u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b9708: 0x84080  sll         $t0, $t0, 2
    ctx->pc = 0x1b9708u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1b970c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b970cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9710: 0xe84821  addu        $t1, $a3, $t0
    ctx->pc = 0x1b9710u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x1b9714: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x1b9714u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b9718: 0xa1200000  sb          $zero, 0x0($t1)
    ctx->pc = 0x1b9718u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b971c: 0x24680d00  addiu       $t0, $v1, 0xD00
    ctx->pc = 0x1b971cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 3328));
    // 0x1b9720: 0xa1200007  sb          $zero, 0x7($t1)
    ctx->pc = 0x1b9720u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 7), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b9724: 0xa1200006  sb          $zero, 0x6($t1)
    ctx->pc = 0x1b9724u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 6), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b9728: 0xa1200005  sb          $zero, 0x5($t1)
    ctx->pc = 0x1b9728u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 5), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b972c: 0xa1200004  sb          $zero, 0x4($t1)
    ctx->pc = 0x1b972cu;
    WRITE8(ADD32(GPR_U32(ctx, 9), 4), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b9730: 0x90630d00  lbu         $v1, 0xD00($v1)
    ctx->pc = 0x1b9730u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 3328)));
    // 0x1b9734: 0x10600023  beqz        $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1B9734u;
    {
        const bool branch_taken_0x1b9734 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9734) {
            ctx->pc = 0x1B97C4u;
            goto label_1b97c4;
        }
    }
    ctx->pc = 0x1B973Cu;
    // 0x1b973c: 0xa1250000  sb          $a1, 0x0($t1)
    ctx->pc = 0x1b973cu;
    WRITE8(ADD32(GPR_U32(ctx, 9), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b9740: 0x95030002  lhu         $v1, 0x2($t0)
    ctx->pc = 0x1b9740u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x1b9744: 0x30638000  andi        $v1, $v1, 0x8000
    ctx->pc = 0x1b9744u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x1b9748: 0x3182b  sltu        $v1, $zero, $v1
    ctx->pc = 0x1b9748u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b974c: 0xa1230001  sb          $v1, 0x1($t1)
    ctx->pc = 0x1b974cu;
    WRITE8(ADD32(GPR_U32(ctx, 9), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b9750: 0x95030002  lhu         $v1, 0x2($t0)
    ctx->pc = 0x1b9750u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x1b9754: 0xa1230002  sb          $v1, 0x2($t1)
    ctx->pc = 0x1b9754u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b9758: 0x95030004  lhu         $v1, 0x4($t0)
    ctx->pc = 0x1b9758u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x1b975c: 0x3063000f  andi        $v1, $v1, 0xF
    ctx->pc = 0x1b975cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x1b9760: 0xa1230003  sb          $v1, 0x3($t1)
    ctx->pc = 0x1b9760u;
    WRITE8(ADD32(GPR_U32(ctx, 9), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b9764: 0xad280024  sw          $t0, 0x24($t1)
    ctx->pc = 0x1b9764u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 36), GPR_U32(ctx, 8));
    // 0x1b9768: 0x81230003  lb          $v1, 0x3($t1)
    ctx->pc = 0x1b9768u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 3)));
    // 0x1b976c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b976cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9770: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b9770u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b9774: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1b9774u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b9778: 0xad230028  sw          $v1, 0x28($t1)
    ctx->pc = 0x1b9778u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 40), GPR_U32(ctx, 3));
    // 0x1b977c: 0x91030001  lbu         $v1, 0x1($t0)
    ctx->pc = 0x1b977cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x1b9780: 0xa5230038  sh          $v1, 0x38($t1)
    ctx->pc = 0x1b9780u;
    WRITE16(ADD32(GPR_U32(ctx, 9), 56), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b9784: 0xc5020008  lwc1        $f2, 0x8($t0)
    ctx->pc = 0x1b9784u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b9788: 0xc501000c  lwc1        $f1, 0xC($t0)
    ctx->pc = 0x1b9788u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b978c: 0xc5000010  lwc1        $f0, 0x10($t0)
    ctx->pc = 0x1b978cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b9790: 0xe522002c  swc1        $f2, 0x2C($t1)
    ctx->pc = 0x1b9790u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 44), bits); }
    // 0x1b9794: 0xe5210030  swc1        $f1, 0x30($t1)
    ctx->pc = 0x1b9794u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 48), bits); }
    // 0x1b9798: 0xe5200034  swc1        $f0, 0x34($t1)
    ctx->pc = 0x1b9798u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 52), bits); }
    // 0x1b979c: 0x8d230028  lw          $v1, 0x28($t1)
    ctx->pc = 0x1b979cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 40)));
    // 0x1b97a0: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B97A0u;
    {
        const bool branch_taken_0x1b97a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b97a0) {
            ctx->pc = 0x1B97C4u;
            goto label_1b97c4;
        }
    }
    ctx->pc = 0x1B97A8u;
label_1b97a8:
    // 0x1b97a8: 0x0  nop
    ctx->pc = 0x1b97a8u;
    // NOP
    // 0x1b97ac: 0x0  nop
    ctx->pc = 0x1b97acu;
    // NOP
    // 0x1b97b0: 0x0  nop
    ctx->pc = 0x1b97b0u;
    // NOP
    // 0x1b97b4: 0x0  nop
    ctx->pc = 0x1b97b4u;
    // NOP
    // 0x1b97b8: 0x0  nop
    ctx->pc = 0x1b97b8u;
    // NOP
    // 0x1b97bc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B97BCu;
    {
        const bool branch_taken_0x1b97bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b97bc) {
            ctx->pc = 0x1B97A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b97a8;
        }
    }
    ctx->pc = 0x1B97C4u;
label_1b97c4:
    // 0x1b97c4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b97c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1b97c8:
    // 0x1b97c8: 0x28430004  slti        $v1, $v0, 0x4
    ctx->pc = 0x1b97c8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b97cc: 0x1460ffcb  bnez        $v1, . + 4 + (-0x35 << 2)
    ctx->pc = 0x1B97CCu;
    {
        const bool branch_taken_0x1b97cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B97D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B97CCu;
            // 0x1b97d0: 0x24100  sll         $t0, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b97cc) {
            ctx->pc = 0x1B96FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b96fc;
        }
    }
    ctx->pc = 0x1B97D4u;
    // 0x1b97d4: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1b97d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1b97d8: 0x8c263d74  lw          $a2, 0x3D74($at)
    ctx->pc = 0x1b97d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 15732)));
    // 0x1b97dc: 0x14c00002  bnez        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B97DCu;
    {
        const bool branch_taken_0x1b97dc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B97E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B97DCu;
            // 0x1b97e0: 0x3c01003c  lui         $at, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b97dc) {
            ctx->pc = 0x1B97E8u;
            goto label_1b97e8;
        }
    }
    ctx->pc = 0x1B97E4u;
    // 0x1b97e4: 0x24060300  addiu       $a2, $zero, 0x300
    ctx->pc = 0x1b97e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
label_1b97e8:
    // 0x1b97e8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b97e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b97ec: 0x90273d73  lbu         $a3, 0x3D73($at)
    ctx->pc = 0x1b97ecu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 15731)));
    // 0x1b97f0: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1b97f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1b97f4: 0x90283d78  lbu         $t0, 0x3D78($at)
    ctx->pc = 0x1b97f4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 15736)));
    // 0x1b97f8: 0xc06b3e0  jal         func_1ACF80
    ctx->pc = 0x1B97F8u;
    SET_GPR_U32(ctx, 31, 0x1B9800u);
    ctx->pc = 0x1B97FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B97F8u;
            // 0x1b97fc: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACF80u;
    if (runtime->hasFunction(0x1ACF80u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9800u; }
        if (ctx->pc != 0x1B9800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF80_0x1acf80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9800u; }
        if (ctx->pc != 0x1B9800u) { return; }
    }
    ctx->pc = 0x1B9800u;
label_1b9800:
    // 0x1b9800: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b9800u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9804: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b9804u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9808: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B980Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9808u;
            // 0x1b980c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B94F0u: goto label_1b94f0;
            case 0x1B9528u: goto label_1b9528;
            case 0x1B9550u: goto label_1b9550;
            case 0x1B9570u: goto label_1b9570;
            case 0x1B9578u: goto label_1b9578;
            case 0x1B9584u: goto label_1b9584;
            case 0x1B9590u: goto label_1b9590;
            case 0x1B95ACu: goto label_1b95ac;
            case 0x1B95CCu: goto label_1b95cc;
            case 0x1B9600u: goto label_1b9600;
            case 0x1B962Cu: goto label_1b962c;
            case 0x1B9694u: goto label_1b9694;
            case 0x1B96A0u: goto label_1b96a0;
            case 0x1B96FCu: goto label_1b96fc;
            case 0x1B97A8u: goto label_1b97a8;
            case 0x1B97C4u: goto label_1b97c4;
            case 0x1B97C8u: goto label_1b97c8;
            case 0x1B97E8u: goto label_1b97e8;
            case 0x1B9800u: goto label_1b9800;
            case 0x1B983Cu: goto label_1b983c;
            case 0x1B9874u: goto label_1b9874;
            case 0x1B9878u: goto label_1b9878;
            case 0x1B9880u: goto label_1b9880;
            case 0x1B98B4u: goto label_1b98b4;
            case 0x1B98B8u: goto label_1b98b8;
            case 0x1B98C4u: goto label_1b98c4;
            case 0x1B98FCu: goto label_1b98fc;
            case 0x1B9914u: goto label_1b9914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9810u;
    // 0x1b9810: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b9810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b9814: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b9814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b9818: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b9818u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b981c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b981cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9820: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b9820u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9824: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1b9824u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9828: 0x3c06003c  lui         $a2, 0x3C
    ctx->pc = 0x1b9828u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)60 << 16));
    // 0x1b982c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b982cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9830: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b9830u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9834: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1B9834u;
    {
        const bool branch_taken_0x1b9834 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9834u;
            // 0x1b9838: 0x24c62750  addiu       $a2, $a2, 0x2750 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 10064));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9834) {
            ctx->pc = 0x1B98B8u;
            goto label_1b98b8;
        }
    }
    ctx->pc = 0x1B983Cu;
label_1b983c:
    // 0x1b983c: 0x671823  subu        $v1, $v1, $a3
    ctx->pc = 0x1b983cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b9840: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b9840u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9844: 0xc38021  addu        $s0, $a2, $v1
    ctx->pc = 0x1b9844u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b9848: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1b9848u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b984c: 0x14600019  bnez        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1B984Cu;
    {
        const bool branch_taken_0x1b984c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B984Cu;
            // 0x1b9850: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b984c) {
            ctx->pc = 0x1B98B4u;
            goto label_1b98b4;
        }
    }
    ctx->pc = 0x1B9854u;
    // 0x1b9854: 0x5163c  dsll32      $v0, $a1, 24
    ctx->pc = 0x1b9854u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 24));
    // 0x1b9858: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1b9858u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b985c: 0x2163f  dsra32      $v0, $v0, 24
    ctx->pc = 0x1b985cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 24));
    // 0x1b9860: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9860u;
    {
        const bool branch_taken_0x1b9860 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9860u;
            // 0x1b9864: 0xa2050001  sb          $a1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9860) {
            ctx->pc = 0x1B9874u;
            goto label_1b9874;
        }
    }
    ctx->pc = 0x1B9868u;
    // 0x1b9868: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b9868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b986c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B986Cu;
    {
        const bool branch_taken_0x1b986c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B986Cu;
            // 0x1b9870: 0xa2020003  sb          $v0, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b986c) {
            ctx->pc = 0x1B9878u;
            goto label_1b9878;
        }
    }
    ctx->pc = 0x1B9874u;
label_1b9874:
    // 0x1b9874: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1b9874u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
label_1b9878:
    // 0x1b9878: 0xc06e21c  jal         func_1B8870
    ctx->pc = 0x1B9878u;
    SET_GPR_U32(ctx, 31, 0x1B9880u);
    ctx->pc = 0x1B8870u;
    if (runtime->hasFunction(0x1B8870u)) {
        auto targetFn = runtime->lookupFunction(0x1B8870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9880u; }
        if (ctx->pc != 0x1B9880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8870_0x1b8870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9880u; }
        if (ctx->pc != 0x1B9880u) { return; }
    }
    ctx->pc = 0x1B9880u;
label_1b9880:
    // 0x1b9880: 0x3c03001c  lui         $v1, 0x1C
    ctx->pc = 0x1b9880u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28 << 16));
    // 0x1b9884: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1b9884u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b9888: 0x24639ba0  addiu       $v1, $v1, -0x6460
    ctx->pc = 0x1b9888u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941600));
    // 0x1b988c: 0xae030028  sw          $v1, 0x28($s0)
    ctx->pc = 0x1b988cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
    // 0x1b9890: 0xc6220000  lwc1        $f2, 0x0($s1)
    ctx->pc = 0x1b9890u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b9894: 0xc6210004  lwc1        $f1, 0x4($s1)
    ctx->pc = 0x1b9894u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9898: 0xc6200008  lwc1        $f0, 0x8($s1)
    ctx->pc = 0x1b9898u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b989c: 0xe602002c  swc1        $f2, 0x2C($s0)
    ctx->pc = 0x1b989cu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 44), bits); }
    // 0x1b98a0: 0xe6010030  swc1        $f1, 0x30($s0)
    ctx->pc = 0x1b98a0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 48), bits); }
    // 0x1b98a4: 0xe6000034  swc1        $f0, 0x34($s0)
    ctx->pc = 0x1b98a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 52), bits); }
    // 0x1b98a8: 0xa6120038  sh          $s2, 0x38($s0)
    ctx->pc = 0x1b98a8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 56), (uint16_t)GPR_U32(ctx, 18));
    // 0x1b98ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B98ACu;
    {
        const bool branch_taken_0x1b98ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B98B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B98ACu;
            // 0x1b98b0: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b98ac) {
            ctx->pc = 0x1B98C4u;
            goto label_1b98c4;
        }
    }
    ctx->pc = 0x1B98B4u;
label_1b98b4:
    // 0x1b98b4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1b98b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1b98b8:
    // 0x1b98b8: 0x28e30004  slti        $v1, $a3, 0x4
    ctx->pc = 0x1b98b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b98bc: 0x1460ffdf  bnez        $v1, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1B98BCu;
    {
        const bool branch_taken_0x1b98bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B98C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B98BCu;
            // 0x1b98c0: 0x71900  sll         $v1, $a3, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b98bc) {
            ctx->pc = 0x1B983Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b983c;
        }
    }
    ctx->pc = 0x1B98C4u;
label_1b98c4:
    // 0x1b98c4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b98c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b98c8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b98c8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b98cc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b98ccu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b98d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b98d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b98d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B98D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B98D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B98D4u;
            // 0x1b98d8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B94F0u: goto label_1b94f0;
            case 0x1B9528u: goto label_1b9528;
            case 0x1B9550u: goto label_1b9550;
            case 0x1B9570u: goto label_1b9570;
            case 0x1B9578u: goto label_1b9578;
            case 0x1B9584u: goto label_1b9584;
            case 0x1B9590u: goto label_1b9590;
            case 0x1B95ACu: goto label_1b95ac;
            case 0x1B95CCu: goto label_1b95cc;
            case 0x1B9600u: goto label_1b9600;
            case 0x1B962Cu: goto label_1b962c;
            case 0x1B9694u: goto label_1b9694;
            case 0x1B96A0u: goto label_1b96a0;
            case 0x1B96FCu: goto label_1b96fc;
            case 0x1B97A8u: goto label_1b97a8;
            case 0x1B97C4u: goto label_1b97c4;
            case 0x1B97C8u: goto label_1b97c8;
            case 0x1B97E8u: goto label_1b97e8;
            case 0x1B9800u: goto label_1b9800;
            case 0x1B983Cu: goto label_1b983c;
            case 0x1B9874u: goto label_1b9874;
            case 0x1B9878u: goto label_1b9878;
            case 0x1B9880u: goto label_1b9880;
            case 0x1B98B4u: goto label_1b98b4;
            case 0x1B98B8u: goto label_1b98b8;
            case 0x1B98C4u: goto label_1b98c4;
            case 0x1B98FCu: goto label_1b98fc;
            case 0x1B9914u: goto label_1b9914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B98DCu;
    // 0x1b98dc: 0x0  nop
    ctx->pc = 0x1b98dcu;
    // NOP
    // 0x1b98e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b98e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b98e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b98e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b98e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b98e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b98ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b98ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b98f0: 0x3c11003c  lui         $s1, 0x3C
    ctx->pc = 0x1b98f0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)60 << 16));
    // 0x1b98f4: 0x26312750  addiu       $s1, $s1, 0x2750
    ctx->pc = 0x1b98f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 10064));
    // 0x1b98f8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b98f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b98fc:
    // 0x1b98fc: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1b98fcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b9900: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9900u;
    {
        const bool branch_taken_0x1b9900 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9900) {
            ctx->pc = 0x1B9914u;
            goto label_1b9914;
        }
    }
    ctx->pc = 0x1B9908u;
    // 0x1b9908: 0x8e220028  lw          $v0, 0x28($s1)
    ctx->pc = 0x1b9908u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x1b990c: 0x40f809  jalr        $v0
    ctx->pc = 0x1B990Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1B9914u);
        ctx->pc = 0x1B9910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B990Cu;
            // 0x1b9910: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1B9914u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B94F0u: goto label_1b94f0;
            case 0x1B9528u: goto label_1b9528;
            case 0x1B9550u: goto label_1b9550;
            case 0x1B9570u: goto label_1b9570;
            case 0x1B9578u: goto label_1b9578;
            case 0x1B9584u: goto label_1b9584;
            case 0x1B9590u: goto label_1b9590;
            case 0x1B95ACu: goto label_1b95ac;
            case 0x1B95CCu: goto label_1b95cc;
            case 0x1B9600u: goto label_1b9600;
            case 0x1B962Cu: goto label_1b962c;
            case 0x1B9694u: goto label_1b9694;
            case 0x1B96A0u: goto label_1b96a0;
            case 0x1B96FCu: goto label_1b96fc;
            case 0x1B97A8u: goto label_1b97a8;
            case 0x1B97C4u: goto label_1b97c4;
            case 0x1B97C8u: goto label_1b97c8;
            case 0x1B97E8u: goto label_1b97e8;
            case 0x1B9800u: goto label_1b9800;
            case 0x1B983Cu: goto label_1b983c;
            case 0x1B9874u: goto label_1b9874;
            case 0x1B9878u: goto label_1b9878;
            case 0x1B9880u: goto label_1b9880;
            case 0x1B98B4u: goto label_1b98b4;
            case 0x1B98B8u: goto label_1b98b8;
            case 0x1B98C4u: goto label_1b98c4;
            case 0x1B98FCu: goto label_1b98fc;
            case 0x1B9914u: goto label_1b9914;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1B9914u; }
            if (ctx->pc != 0x1B9914u) { return; }
        }
        }
    }
    ctx->pc = 0x1B9914u;
label_1b9914:
    // 0x1b9914: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b9914u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b9918: 0x2a030004  slti        $v1, $s0, 0x4
    ctx->pc = 0x1b9918u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b991c: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B991Cu;
    {
        const bool branch_taken_0x1b991c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B991Cu;
            // 0x1b9920: 0x2631003c  addiu       $s1, $s1, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b991c) {
            ctx->pc = 0x1B98FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b98fc;
        }
    }
    ctx->pc = 0x1B9924u;
    // 0x1b9924: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b9924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b9928: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b9928u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b992c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b992cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b9930: 0x3e00008  jr          $ra
    ctx->pc = 0x1B9930u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B9934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9930u;
            // 0x1b9934: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B94F0u: goto label_1b94f0;
            case 0x1B9528u: goto label_1b9528;
            case 0x1B9550u: goto label_1b9550;
            case 0x1B9570u: goto label_1b9570;
            case 0x1B9578u: goto label_1b9578;
            case 0x1B9584u: goto label_1b9584;
            case 0x1B9590u: goto label_1b9590;
            case 0x1B95ACu: goto label_1b95ac;
            case 0x1B95CCu: goto label_1b95cc;
            case 0x1B9600u: goto label_1b9600;
            case 0x1B962Cu: goto label_1b962c;
            case 0x1B9694u: goto label_1b9694;
            case 0x1B96A0u: goto label_1b96a0;
            case 0x1B96FCu: goto label_1b96fc;
            case 0x1B97A8u: goto label_1b97a8;
            case 0x1B97C4u: goto label_1b97c4;
            case 0x1B97C8u: goto label_1b97c8;
            case 0x1B97E8u: goto label_1b97e8;
            case 0x1B9800u: goto label_1b9800;
            case 0x1B983Cu: goto label_1b983c;
            case 0x1B9874u: goto label_1b9874;
            case 0x1B9878u: goto label_1b9878;
            case 0x1B9880u: goto label_1b9880;
            case 0x1B98B4u: goto label_1b98b4;
            case 0x1B98B8u: goto label_1b98b8;
            case 0x1B98C4u: goto label_1b98c4;
            case 0x1B98FCu: goto label_1b98fc;
            case 0x1B9914u: goto label_1b9914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B9938u;
    // 0x1b9938: 0x0  nop
    ctx->pc = 0x1b9938u;
    // NOP
    // 0x1b993c: 0x0  nop
    ctx->pc = 0x1b993cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

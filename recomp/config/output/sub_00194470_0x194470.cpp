#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00194470
// Address: 0x194470 - 0x194718
void sub_00194470_0x194470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00194470_0x194470");
#endif

    switch (ctx->pc) {
        case 0x1944acu: goto label_1944ac;
        case 0x1944b8u: goto label_1944b8;
        case 0x194508u: goto label_194508;
        case 0x194518u: goto label_194518;
        case 0x1945b0u: goto label_1945b0;
        case 0x1945c0u: goto label_1945c0;
        case 0x194658u: goto label_194658;
        case 0x194668u: goto label_194668;
        case 0x194700u: goto label_194700;
        default: break;
    }

    ctx->pc = 0x194470u;

    // 0x194470: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194470u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194474: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194474u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194478: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x194478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19447c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19447cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x194480: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x194480u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x194484: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194488: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194488u;
    {
        const bool branch_taken_0x194488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19448Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194488u;
            // 0x19448c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194488) {
            ctx->pc = 0x194498u;
            goto label_194498;
        }
    }
    ctx->pc = 0x194490u;
    // 0x194490: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x194490u;
    {
        const bool branch_taken_0x194490 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194490u;
            // 0x194494: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194490) {
            ctx->pc = 0x194704u;
            goto label_194704;
        }
    }
    ctx->pc = 0x194498u;
label_194498:
    // 0x194498: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194498u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x19449c: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x19449cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x1944a0: 0x2484fee0  addiu       $a0, $a0, -0x120
    ctx->pc = 0x1944a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967008));
    // 0x1944a4: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x1944A4u;
    SET_GPR_U32(ctx, 31, 0x1944ACu);
    ctx->pc = 0x1944A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1944A4u;
            // 0x1944a8: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944ACu; }
        if (ctx->pc != 0x1944ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944ACu; }
        if (ctx->pc != 0x1944ACu) { return; }
    }
    ctx->pc = 0x1944ACu;
label_1944ac:
    // 0x1944ac: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1944acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1944b0: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x1944B0u;
    SET_GPR_U32(ctx, 31, 0x1944B8u);
    ctx->pc = 0x1944B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1944B0u;
            // 0x1944b4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944B8u; }
        if (ctx->pc != 0x1944B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1944B8u; }
        if (ctx->pc != 0x1944B8u) { return; }
    }
    ctx->pc = 0x1944B8u;
label_1944b8:
    // 0x1944b8: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x1944b8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x1944bc: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x1944bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1944c0: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x1944c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1944c4: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1944c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1944c8: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x1944c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x1944cc: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1944ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1944d0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1944d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1944d4: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1944d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1944d8: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x1944d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x1944dc: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1944dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1944e0: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1944e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1944e4: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1944e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1944e8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1944e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1944ec: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x1944ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x1944f0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1944f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1944f4: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1944f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1944f8: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1944f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1944fc: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x1944fcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194500: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194500u;
    SET_GPR_U32(ctx, 31, 0x194508u);
    ctx->pc = 0x194504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194500u;
            // 0x194504: 0x86040000  lh          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194508u; }
        if (ctx->pc != 0x194508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194508u; }
        if (ctx->pc != 0x194508u) { return; }
    }
    ctx->pc = 0x194508u;
label_194508:
    // 0x194508: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x194508u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x19450c: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x19450cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194510: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194510u;
    SET_GPR_U32(ctx, 31, 0x194518u);
    ctx->pc = 0x194514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194510u;
            // 0x194514: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194518u; }
        if (ctx->pc != 0x194518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194518u; }
        if (ctx->pc != 0x194518u) { return; }
    }
    ctx->pc = 0x194518u;
label_194518:
    // 0x194518: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194518u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19451c: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x19451cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194520: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x194520u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194524: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194524u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194528: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x194528u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x19452c: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x19452cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194530: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x194530u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x194534: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194534u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194538: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194538u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19453c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x19453cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194540: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194544: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194544u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194548: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194548u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19454c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19454cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x194550: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x194550u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x194554: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194554u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194558: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194558u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x19455c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x19455cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194560: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194560u;
    {
        const bool branch_taken_0x194560 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194560u;
            // 0x194564: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194560) {
            ctx->pc = 0x194578u;
            goto label_194578;
        }
    }
    ctx->pc = 0x194568u;
    // 0x194568: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194568u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19456c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19456cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194570: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194570u;
    {
        const bool branch_taken_0x194570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194570u;
            // 0x194574: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194570) {
            ctx->pc = 0x194594u;
            goto label_194594;
        }
    }
    ctx->pc = 0x194578u;
label_194578:
    // 0x194578: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194578u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x19457c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x19457cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194580: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194580u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194584: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194584u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194588: 0x0  nop
    ctx->pc = 0x194588u;
    // NOP
    // 0x19458c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x19458cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194590: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194590u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194594:
    // 0x194594: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194594u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194598: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194598u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x19459c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x19459cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1945a0: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1945a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1945a4: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x1945a4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x1945a8: 0xc06629c  jal         func_198A70
    ctx->pc = 0x1945A8u;
    SET_GPR_U32(ctx, 31, 0x1945B0u);
    ctx->pc = 0x1945ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1945A8u;
            // 0x1945ac: 0x86040004  lh          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945B0u; }
        if (ctx->pc != 0x1945B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945B0u; }
        if (ctx->pc != 0x1945B0u) { return; }
    }
    ctx->pc = 0x1945B0u;
label_1945b0:
    // 0x1945b0: 0x86040006  lh          $a0, 0x6($s0)
    ctx->pc = 0x1945b0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1945b4: 0x28c3c  dsll32      $s1, $v0, 16
    ctx->pc = 0x1945b4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1945b8: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x1945B8u;
    SET_GPR_U32(ctx, 31, 0x1945C0u);
    ctx->pc = 0x1945BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1945B8u;
            // 0x1945bc: 0x118c3f  dsra32      $s1, $s1, 16 (Delay Slot)
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945C0u; }
        if (ctx->pc != 0x1945C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1945C0u; }
        if (ctx->pc != 0x1945C0u) { return; }
    }
    ctx->pc = 0x1945C0u;
label_1945c0:
    // 0x1945c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1945c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1945c4: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x1945c4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1945c8: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x1945c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x1945cc: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1945ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1945d0: 0x11243c  dsll32      $a0, $s1, 16
    ctx->pc = 0x1945d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << (32 + 16));
    // 0x1945d4: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x1945d4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x1945d8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1945d8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1945dc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1945dcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1945e0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1945e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1945e4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1945e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1945e8: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x1945e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x1945ec: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1945ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1945f0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1945f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1945f4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1945f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1945f8: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1945f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1945fc: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1945fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194600: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194604: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x194604u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194608: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194608u;
    {
        const bool branch_taken_0x194608 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x19460Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194608u;
            // 0x19460c: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194608) {
            ctx->pc = 0x194620u;
            goto label_194620;
        }
    }
    ctx->pc = 0x194610u;
    // 0x194610: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194610u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x194614: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x194614u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194618: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194618u;
    {
        const bool branch_taken_0x194618 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19461Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194618u;
            // 0x19461c: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194618) {
            ctx->pc = 0x19463Cu;
            goto label_19463c;
        }
    }
    ctx->pc = 0x194620u;
label_194620:
    // 0x194620: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x194620u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x194624: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194624u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194628: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194628u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x19462c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x19462cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194630: 0x0  nop
    ctx->pc = 0x194630u;
    // NOP
    // 0x194634: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194634u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194638: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194638u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_19463c:
    // 0x19463c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19463cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194640: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194640u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194644: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194648: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194648u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x19464c: 0xfc220038  sd          $v0, 0x38($at)
    ctx->pc = 0x19464cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
    // 0x194650: 0xc06629c  jal         func_198A70
    ctx->pc = 0x194650u;
    SET_GPR_U32(ctx, 31, 0x194658u);
    ctx->pc = 0x194654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194650u;
            // 0x194654: 0x86040008  lh          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A70u;
    if (runtime->hasFunction(0x198A70u)) {
        auto targetFn = runtime->lookupFunction(0x198A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194658u; }
        if (ctx->pc != 0x194658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A70_0x198a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194658u; }
        if (ctx->pc != 0x194658u) { return; }
    }
    ctx->pc = 0x194658u;
label_194658:
    // 0x194658: 0x8604000a  lh          $a0, 0xA($s0)
    ctx->pc = 0x194658u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x19465c: 0x2843c  dsll32      $s0, $v0, 16
    ctx->pc = 0x19465cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194660: 0xc0662a4  jal         func_198A90
    ctx->pc = 0x194660u;
    SET_GPR_U32(ctx, 31, 0x194668u);
    ctx->pc = 0x194664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194660u;
            // 0x194664: 0x10843f  dsra32      $s0, $s0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198A90u;
    if (runtime->hasFunction(0x198A90u)) {
        auto targetFn = runtime->lookupFunction(0x198A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194668u; }
        if (ctx->pc != 0x194668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198A90_0x198a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194668u; }
        if (ctx->pc != 0x194668u) { return; }
    }
    ctx->pc = 0x194668u;
label_194668:
    // 0x194668: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194668u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19466c: 0x22c3c  dsll32      $a1, $v0, 16
    ctx->pc = 0x19466cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 16));
    // 0x194670: 0x8c23fd54  lw          $v1, -0x2AC($at)
    ctx->pc = 0x194670u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966612)));
    // 0x194674: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194674u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194678: 0x10243c  dsll32      $a0, $s0, 16
    ctx->pc = 0x194678u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) << (32 + 16));
    // 0x19467c: 0x52c3f  dsra32      $a1, $a1, 16
    ctx->pc = 0x19467cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 16));
    // 0x194680: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x194680u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x194684: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x194684u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x194688: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194688u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19468c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x19468cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x194690: 0x8c22fd58  lw          $v0, -0x2A8($at)
    ctx->pc = 0x194690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966616)));
    // 0x194694: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x194694u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x194698: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194698u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19469c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19469cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1946a0: 0xc421f9f4  lwc1        $f1, -0x60C($at)
    ctx->pc = 0x1946a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294965748)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1946a4: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1946a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1946a8: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1946a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1946ac: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1946acu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1946b0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1946B0u;
    {
        const bool branch_taken_0x1946b0 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1946B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1946B0u;
            // 0x1946b4: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1946b0) {
            ctx->pc = 0x1946C8u;
            goto label_1946c8;
        }
    }
    ctx->pc = 0x1946B8u;
    // 0x1946b8: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1946b8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1946bc: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1946bcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1946c0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1946C0u;
    {
        const bool branch_taken_0x1946c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1946C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1946C0u;
            // 0x1946c4: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1946c0) {
            ctx->pc = 0x1946E4u;
            goto label_1946e4;
        }
    }
    ctx->pc = 0x1946C8u;
label_1946c8:
    // 0x1946c8: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1946c8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1946cc: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1946ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1946d0: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1946d0u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1946d4: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1946d4u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1946d8: 0x0  nop
    ctx->pc = 0x1946d8u;
    // NOP
    // 0x1946dc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1946dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1946e0: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x1946e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_1946e4:
    // 0x1946e4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x1946e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x1946e8: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1946e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1946ec: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1946ecu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1946f0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1946f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1946f4: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x1946f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1946f8: 0xc064f88  jal         func_193E20
    ctx->pc = 0x1946F8u;
    SET_GPR_U32(ctx, 31, 0x194700u);
    ctx->pc = 0x1946FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1946F8u;
            // 0x1946fc: 0xfc220040  sd          $v0, 0x40($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 64), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194700u; }
        if (ctx->pc != 0x194700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194700u; }
        if (ctx->pc != 0x194700u) { return; }
    }
    ctx->pc = 0x194700u;
label_194700:
    // 0x194700: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194704:
    // 0x194704: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x194704u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194708: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x194708u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19470c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19470cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x194710: 0x3e00008  jr          $ra
    ctx->pc = 0x194710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194710u;
            // 0x194714: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x194498u: goto label_194498;
            case 0x1944ACu: goto label_1944ac;
            case 0x1944B8u: goto label_1944b8;
            case 0x194508u: goto label_194508;
            case 0x194518u: goto label_194518;
            case 0x194578u: goto label_194578;
            case 0x194594u: goto label_194594;
            case 0x1945B0u: goto label_1945b0;
            case 0x1945C0u: goto label_1945c0;
            case 0x194620u: goto label_194620;
            case 0x19463Cu: goto label_19463c;
            case 0x194658u: goto label_194658;
            case 0x194668u: goto label_194668;
            case 0x1946C8u: goto label_1946c8;
            case 0x1946E4u: goto label_1946e4;
            case 0x194700u: goto label_194700;
            case 0x194704u: goto label_194704;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194718u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

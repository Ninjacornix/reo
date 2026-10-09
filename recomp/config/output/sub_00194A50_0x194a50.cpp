#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00194A50
// Address: 0x194a50 - 0x194c78
void sub_00194A50_0x194a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00194A50_0x194a50");
#endif

    switch (ctx->pc) {
        case 0x194a90u: goto label_194a90;
        case 0x194a9cu: goto label_194a9c;
        case 0x194aecu: goto label_194aec;
        case 0x194af8u: goto label_194af8;
        case 0x194b04u: goto label_194b04;
        case 0x194ba4u: goto label_194ba4;
        case 0x194bb0u: goto label_194bb0;
        case 0x194bbcu: goto label_194bbc;
        case 0x194c5cu: goto label_194c5c;
        default: break;
    }

    ctx->pc = 0x194a50u;

    // 0x194a50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x194a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x194a54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194a54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194a58: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x194a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x194a5c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x194a5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x194a60: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x194a60u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x194a64: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x194a64u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x194a68: 0x8c22fda4  lw          $v0, -0x25C($at)
    ctx->pc = 0x194a68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
    // 0x194a6c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x194A6Cu;
    {
        const bool branch_taken_0x194a6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x194A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194A6Cu;
            // 0x194a70: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194a6c) {
            ctx->pc = 0x194A7Cu;
            goto label_194a7c;
        }
    }
    ctx->pc = 0x194A74u;
    // 0x194a74: 0x1000007a  b           . + 4 + (0x7A << 2)
    ctx->pc = 0x194A74u;
    {
        const bool branch_taken_0x194a74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194A74u;
            // 0x194a78: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194a74) {
            ctx->pc = 0x194C60u;
            goto label_194c60;
        }
    }
    ctx->pc = 0x194A7Cu;
label_194a7c:
    // 0x194a7c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x194a7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x194a80: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x194a80u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x194a84: 0x2484ff90  addiu       $a0, $a0, -0x70
    ctx->pc = 0x194a84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967184));
    // 0x194a88: 0xc0626c2  jal         func_189B08
    ctx->pc = 0x194A88u;
    SET_GPR_U32(ctx, 31, 0x194A90u);
    ctx->pc = 0x194A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194A88u;
            // 0x194a8c: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189B08u;
    if (runtime->hasFunction(0x189B08u)) {
        auto targetFn = runtime->lookupFunction(0x189B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A90u; }
        if (ctx->pc != 0x194A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A90u; }
        if (ctx->pc != 0x194A90u) { return; }
    }
    ctx->pc = 0x194A90u;
label_194a90:
    // 0x194a90: 0x8e040020  lw          $a0, 0x20($s0)
    ctx->pc = 0x194a90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x194a94: 0xc0662d8  jal         func_198B60
    ctx->pc = 0x194A94u;
    SET_GPR_U32(ctx, 31, 0x194A9Cu);
    ctx->pc = 0x194A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194A94u;
            // 0x194a98: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B60u;
    if (runtime->hasFunction(0x198B60u)) {
        auto targetFn = runtime->lookupFunction(0x198B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A9Cu; }
        if (ctx->pc != 0x194A9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B60_0x198b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194A9Cu; }
        if (ctx->pc != 0x194A9Cu) { return; }
    }
    ctx->pc = 0x194A9Cu;
label_194a9c:
    // 0x194a9c: 0x22402  srl         $a0, $v0, 16
    ctx->pc = 0x194a9cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 16));
    // 0x194aa0: 0x21a02  srl         $v1, $v0, 8
    ctx->pc = 0x194aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x194aa4: 0x308500ff  andi        $a1, $a0, 0xFF
    ctx->pc = 0x194aa4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x194aa8: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x194aa8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x194aac: 0x32238  dsll        $a0, $v1, 8
    ctx->pc = 0x194aacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 8);
    // 0x194ab0: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194ab0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194ab4: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194ab4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194ab8: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x194ab8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x194abc: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x194abcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x194ac0: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x194ac0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x194ac4: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x194ac4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194ac8: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x194ac8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x194acc: 0x9e02000c  lwu         $v0, 0xC($s0)
    ctx->pc = 0x194accu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x194ad0: 0x31e38  dsll        $v1, $v1, 24
    ctx->pc = 0x194ad0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 24);
    // 0x194ad4: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x194ad4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x194ad8: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194ad8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194adc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x194adcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x194ae0: 0xfc220028  sd          $v0, 0x28($at)
    ctx->pc = 0x194ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 40), GPR_U64(ctx, 2));
    // 0x194ae4: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x194AE4u;
    SET_GPR_U32(ctx, 31, 0x194AECu);
    ctx->pc = 0x194AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194AE4u;
            // 0x194ae8: 0xc60c0000  lwc1        $f12, 0x0($s0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AECu; }
        if (ctx->pc != 0x194AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AECu; }
        if (ctx->pc != 0x194AECu) { return; }
    }
    ctx->pc = 0x194AECu;
label_194aec:
    // 0x194aec: 0xc60c0004  lwc1        $f12, 0x4($s0)
    ctx->pc = 0x194aecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194af0: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x194AF0u;
    SET_GPR_U32(ctx, 31, 0x194AF8u);
    ctx->pc = 0x194AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194AF0u;
            // 0x194af4: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AF8u; }
        if (ctx->pc != 0x194AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194AF8u; }
        if (ctx->pc != 0x194AF8u) { return; }
    }
    ctx->pc = 0x194AF8u;
label_194af8:
    // 0x194af8: 0xc60c0008  lwc1        $f12, 0x8($s0)
    ctx->pc = 0x194af8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194afc: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x194AFCu;
    SET_GPR_U32(ctx, 31, 0x194B04u);
    ctx->pc = 0x194B00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194AFCu;
            // 0x194b00: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194B04u; }
        if (ctx->pc != 0x194B04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194B04u; }
        if (ctx->pc != 0x194B04u) { return; }
    }
    ctx->pc = 0x194B04u;
label_194b04:
    // 0x194b04: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194b04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194b08: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194b08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194b0c: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x194b0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x194b10: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x194b10u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x194b14: 0x0  nop
    ctx->pc = 0x194b14u;
    // NOP
    // 0x194b18: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x194b18u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194b1c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194b1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194b20: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x194b20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194b24: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x194b24u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x194b28: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x194b28u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194b2c: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x194b2cu;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x194b30: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x194b30u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x194b34: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b34u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x194b38: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x194b38u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194b3c: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b3cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194b40: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x194b40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194b44: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194b44u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194b48: 0x0  nop
    ctx->pc = 0x194b48u;
    // NOP
    // 0x194b4c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194b50: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194b50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194b54: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194B54u;
    {
        const bool branch_taken_0x194b54 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194B54u;
            // 0x194b58: 0x622025  or          $a0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194b54) {
            ctx->pc = 0x194B6Cu;
            goto label_194b6c;
        }
    }
    ctx->pc = 0x194B5Cu;
    // 0x194b5c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b5cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194b60: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194b60u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194b64: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194B64u;
    {
        const bool branch_taken_0x194b64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194B64u;
            // 0x194b68: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194b64) {
            ctx->pc = 0x194B88u;
            goto label_194b88;
        }
    }
    ctx->pc = 0x194B6Cu;
label_194b6c:
    // 0x194b6c: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x194b6cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x194b70: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194b70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194b74: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194b74u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194b78: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194b78u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194b7c: 0x0  nop
    ctx->pc = 0x194b7cu;
    // NOP
    // 0x194b80: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194b80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194b84: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194b84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194b88:
    // 0x194b88: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194b88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194b8c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194b8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194b90: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194b90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194b94: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x194b94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x194b98: 0xfc220030  sd          $v0, 0x30($at)
    ctx->pc = 0x194b98u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 48), GPR_U64(ctx, 2));
    // 0x194b9c: 0xc0662b4  jal         func_198AD0
    ctx->pc = 0x194B9Cu;
    SET_GPR_U32(ctx, 31, 0x194BA4u);
    ctx->pc = 0x194BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194B9Cu;
            // 0x194ba0: 0xc60c0010  lwc1        $f12, 0x10($s0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AD0u;
    if (runtime->hasFunction(0x198AD0u)) {
        auto targetFn = runtime->lookupFunction(0x198AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BA4u; }
        if (ctx->pc != 0x194BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AD0_0x198ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BA4u; }
        if (ctx->pc != 0x194BA4u) { return; }
    }
    ctx->pc = 0x194BA4u;
label_194ba4:
    // 0x194ba4: 0xc60c0014  lwc1        $f12, 0x14($s0)
    ctx->pc = 0x194ba4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194ba8: 0xc0662bc  jal         func_198AF0
    ctx->pc = 0x194BA8u;
    SET_GPR_U32(ctx, 31, 0x194BB0u);
    ctx->pc = 0x194BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194BA8u;
            // 0x194bac: 0x46000546  mov.s       $f21, $f0 (Delay Slot)
        ctx->f[21] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198AF0u;
    if (runtime->hasFunction(0x198AF0u)) {
        auto targetFn = runtime->lookupFunction(0x198AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BB0u; }
        if (ctx->pc != 0x194BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198AF0_0x198af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BB0u; }
        if (ctx->pc != 0x194BB0u) { return; }
    }
    ctx->pc = 0x194BB0u;
label_194bb0:
    // 0x194bb0: 0xc60c0018  lwc1        $f12, 0x18($s0)
    ctx->pc = 0x194bb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x194bb4: 0xc0662cc  jal         func_198B30
    ctx->pc = 0x194BB4u;
    SET_GPR_U32(ctx, 31, 0x194BBCu);
    ctx->pc = 0x194BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194BB4u;
            // 0x194bb8: 0x46000506  mov.s       $f20, $f0 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[0]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x198B30u;
    if (runtime->hasFunction(0x198B30u)) {
        auto targetFn = runtime->lookupFunction(0x198B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BBCu; }
        if (ctx->pc != 0x194BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198B30_0x198b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194BBCu; }
        if (ctx->pc != 0x194BBCu) { return; }
    }
    ctx->pc = 0x194BBCu;
label_194bbc:
    // 0x194bbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194bbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194bc0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x194bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x194bc4: 0xc423fd54  lwc1        $f3, -0x2AC($at)
    ctx->pc = 0x194bc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966612)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x194bc8: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x194bc8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x194bcc: 0x0  nop
    ctx->pc = 0x194bccu;
    // NOP
    // 0x194bd0: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x194bd0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x194bd4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x194bd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x194bd8: 0xc422fd58  lwc1        $f2, -0x2A8($at)
    ctx->pc = 0x194bd8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966616)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x194bdc: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x194bdcu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x194be0: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x194be0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x194be4: 0x461518c0  add.s       $f3, $f3, $f21
    ctx->pc = 0x194be4u;
    ctx->f[3] = FPU_ADD_S(ctx->f[3], ctx->f[21]);
    // 0x194be8: 0x46141080  add.s       $f2, $f2, $f20
    ctx->pc = 0x194be8u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[20]);
    // 0x194bec: 0x460018e4  .word       0x460018E4                   # cvt.w.s     $f3, $f3 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194becu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[3]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x194bf0: 0x44021800  mfc1        $v0, $f3
    ctx->pc = 0x194bf0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194bf4: 0x460010a4  .word       0x460010A4                   # cvt.w.s     $f2, $f2 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194bf4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[2]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x194bf8: 0x21900  sll         $v1, $v0, 4
    ctx->pc = 0x194bf8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194bfc: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x194bfcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x194c00: 0x0  nop
    ctx->pc = 0x194c00u;
    // NOP
    // 0x194c04: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x194c04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x194c08: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x194c08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x194c0c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x194C0Cu;
    {
        const bool branch_taken_0x194c0c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x194C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C0Cu;
            // 0x194c10: 0x622825  or          $a1, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c0c) {
            ctx->pc = 0x194C24u;
            goto label_194c24;
        }
    }
    ctx->pc = 0x194C14u;
    // 0x194c14: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194c14u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194c18: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194c18u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194c1c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x194C1Cu;
    {
        const bool branch_taken_0x194c1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x194C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C1Cu;
            // 0x194c20: 0x3103c  dsll32      $v0, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x194c1c) {
            ctx->pc = 0x194C40u;
            goto label_194c40;
        }
    }
    ctx->pc = 0x194C24u;
label_194c24:
    // 0x194c24: 0x46010001  sub.s       $f0, $f0, $f1
    ctx->pc = 0x194c24u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[1]);
    // 0x194c28: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x194c28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x194c2c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x194c2cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x194c30: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x194c30u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x194c34: 0x0  nop
    ctx->pc = 0x194c34u;
    // NOP
    // 0x194c38: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x194c38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x194c3c: 0x3103c  dsll32      $v0, $v1, 0
    ctx->pc = 0x194c3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 0));
label_194c40:
    // 0x194c40: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x194c40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x194c44: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x194c44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x194c48: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x194c48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x194c4c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x194c4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x194c50: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x194c50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x194c54: 0xc064f88  jal         func_193E20
    ctx->pc = 0x194C54u;
    SET_GPR_U32(ctx, 31, 0x194C5Cu);
    ctx->pc = 0x194C58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x194C54u;
            // 0x194c58: 0xfc220038  sd          $v0, 0x38($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 56), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193E20u;
    if (runtime->hasFunction(0x193E20u)) {
        auto targetFn = runtime->lookupFunction(0x193E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194C5Cu; }
        if (ctx->pc != 0x194C5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193E20_0x193e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x194C5Cu; }
        if (ctx->pc != 0x194C5Cu) { return; }
    }
    ctx->pc = 0x194C5Cu;
label_194c5c:
    // 0x194c5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x194c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_194c60:
    // 0x194c60: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x194c60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x194c64: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x194c64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x194c68: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x194c68u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x194c6c: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x194c6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x194c70: 0x3e00008  jr          $ra
    ctx->pc = 0x194C70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x194C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x194C70u;
            // 0x194c74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x194A7Cu: goto label_194a7c;
            case 0x194A90u: goto label_194a90;
            case 0x194A9Cu: goto label_194a9c;
            case 0x194AECu: goto label_194aec;
            case 0x194AF8u: goto label_194af8;
            case 0x194B04u: goto label_194b04;
            case 0x194B6Cu: goto label_194b6c;
            case 0x194B88u: goto label_194b88;
            case 0x194BA4u: goto label_194ba4;
            case 0x194BB0u: goto label_194bb0;
            case 0x194BBCu: goto label_194bbc;
            case 0x194C24u: goto label_194c24;
            case 0x194C40u: goto label_194c40;
            case 0x194C5Cu: goto label_194c5c;
            case 0x194C60u: goto label_194c60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x194C78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

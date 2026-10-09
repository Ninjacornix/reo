#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1970
// Address: 0x1a1970 - 0x1a1ac0
void sub_001A1970_0x1a1970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1970_0x1a1970");
#endif

    switch (ctx->pc) {
        case 0x1a19dcu: goto label_1a19dc;
        case 0x1a1a90u: goto label_1a1a90;
        case 0x1a1aa4u: goto label_1a1aa4;
        default: break;
    }

    ctx->pc = 0x1a1970u;

    // 0x1a1970: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a1970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a1974: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x1a1974u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1a1978: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1a1978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1a197c: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1a197cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a1980: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1a1980u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1a1984: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1a1984u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a1988: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1a1988u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1a198c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1a198cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1a1990: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1a1990u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x1a1994: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a1994u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a1998: 0x8c28ffac  lw          $t0, -0x54($at)
    ctx->pc = 0x1a1998u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967212)));
    // 0x1a199c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1a199cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a19a0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a19a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a19a4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1a19a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1a19a8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1a19a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a19ac: 0x27a5004e  addiu       $a1, $sp, 0x4E
    ctx->pc = 0x1a19acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 78));
    // 0x1a19b0: 0x27a7004a  addiu       $a3, $sp, 0x4A
    ctx->pc = 0x1a19b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 74));
    // 0x1a19b4: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x1a19b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1a19b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a19b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a19bc: 0xc442001c  lwc1        $f2, 0x1C($v0)
    ctx->pc = 0x1a19bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a19c0: 0xc4410020  lwc1        $f1, 0x20($v0)
    ctx->pc = 0x1a19c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a19c4: 0xc4400024  lwc1        $f0, 0x24($v0)
    ctx->pc = 0x1a19c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a19c8: 0xe4c20000  swc1        $f2, 0x0($a2)
    ctx->pc = 0x1a19c8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 0), bits); }
    // 0x1a19cc: 0xe4c10004  swc1        $f1, 0x4($a2)
    ctx->pc = 0x1a19ccu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 4), bits); }
    // 0x1a19d0: 0xe4c00008  swc1        $f0, 0x8($a2)
    ctx->pc = 0x1a19d0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 8), bits); }
    // 0x1a19d4: 0xc0697c0  jal         func_1A5F00
    ctx->pc = 0x1A19D4u;
    SET_GPR_U32(ctx, 31, 0x1A19DCu);
    ctx->pc = 0x1A19D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A19D4u;
            // 0x1a19d8: 0x27a6004c  addiu       $a2, $sp, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5F00u;
    if (runtime->hasFunction(0x1A5F00u)) {
        auto targetFn = runtime->lookupFunction(0x1A5F00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A19DCu; }
        if (ctx->pc != 0x1A19DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5F00_0x1a5f00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A19DCu; }
        if (ctx->pc != 0x1A19DCu) { return; }
    }
    ctx->pc = 0x1A19DCu;
label_1a19dc:
    // 0x1a19dc: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A19DCu;
    {
        const bool branch_taken_0x1a19dc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a19dc) {
            ctx->pc = 0x1A19ECu;
            goto label_1a19ec;
        }
    }
    ctx->pc = 0x1A19E4u;
    // 0x1a19e4: 0x87a2004a  lh          $v0, 0x4A($sp)
    ctx->pc = 0x1a19e4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 74)));
    // 0x1a19e8: 0xa7a2004c  sh          $v0, 0x4C($sp)
    ctx->pc = 0x1a19e8u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 76), (uint16_t)GPR_U32(ctx, 2));
label_1a19ec:
    // 0x1a19ec: 0x87a3004c  lh          $v1, 0x4C($sp)
    ctx->pc = 0x1a19ecu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1a19f0: 0x3c0242fe  lui         $v0, 0x42FE
    ctx->pc = 0x1a19f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17150 << 16));
    // 0x1a19f4: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1a19f4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1a19f8: 0x86020004  lh          $v0, 0x4($s0)
    ctx->pc = 0x1a19f8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a19fc: 0x2464ffff  addiu       $a0, $v1, -0x1
    ctx->pc = 0x1a19fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a1a00: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1a1a00u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a1a04: 0x0  nop
    ctx->pc = 0x1a1a04u;
    // NOP
    // 0x1a1a08: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1a1a08u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1a1a0c: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1a1a0cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a1a10: 0x46000d03  div.s       $f20, $f1, $f0
    ctx->pc = 0x1a1a10u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[20] = std::bit_cast<float>(__maxf); } else ctx->f[20] = ctx->f[1] / ctx->f[0];
    // 0x1a1a14: 0x0  nop
    ctx->pc = 0x1a1a14u;
    // NOP
    // 0x1a1a18: 0x0  nop
    ctx->pc = 0x1a1a18u;
    // NOP
    // 0x1a1a1c: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1A1A1Cu;
    {
        const bool branch_taken_0x1a1a1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a1a1c) {
            ctx->pc = 0x1A1A80u;
            goto label_1a1a80;
        }
    }
    ctx->pc = 0x1A1A24u;
    // 0x1a1a24: 0x21c3c  dsll32      $v1, $v0, 16
    ctx->pc = 0x1a1a24u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1a1a28: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1a1a28u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1a1a2c: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1a1a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1a1a30: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1a1a30u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a1a34: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1a1a34u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1a1a38: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a1a38u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a1a3c: 0x0  nop
    ctx->pc = 0x1a1a3cu;
    // NOP
    // 0x1a1a40: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x1a1a40u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1a1a44: 0x4601a042  mul.s       $f1, $f20, $f1
    ctx->pc = 0x1a1a44u;
    ctx->f[1] = FPU_MUL_S(ctx->f[20], ctx->f[1]);
    // 0x1a1a48: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a1a48u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a1a4c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A1A4Cu;
    {
        const bool branch_taken_0x1a1a4c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a1a4c) {
            ctx->pc = 0x1A1A64u;
            goto label_1a1a64;
        }
    }
    ctx->pc = 0x1A1A54u;
    // 0x1a1a54: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a1a54u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a1a58: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a1a58u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a1a5c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A1A5Cu;
    {
        const bool branch_taken_0x1a1a5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1A5Cu;
            // 0x1a1a60: 0xa6030004  sh          $v1, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1a5c) {
            ctx->pc = 0x1A1A80u;
            goto label_1a1a80;
        }
    }
    ctx->pc = 0x1A1A64u;
label_1a1a64:
    // 0x1a1a64: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a1a64u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a1a68: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1a1a68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1a1a6c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a1a6cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a1a70: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a1a70u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a1a74: 0x0  nop
    ctx->pc = 0x1a1a74u;
    // NOP
    // 0x1a1a78: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1a1a78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a1a7c: 0xa6030004  sh          $v1, 0x4($s0)
    ctx->pc = 0x1a1a7cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 3));
label_1a1a80:
    // 0x1a1a80: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1a1a80u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a1a84: 0x87a5004c  lh          $a1, 0x4C($sp)
    ctx->pc = 0x1a1a84u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1a1a88: 0xc0686b0  jal         func_1A1AC0
    ctx->pc = 0x1A1A88u;
    SET_GPR_U32(ctx, 31, 0x1A1A90u);
    ctx->pc = 0x1A1A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1A88u;
            // 0x1a1a8c: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1AC0u;
    if (runtime->hasFunction(0x1A1AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1A90u; }
        if (ctx->pc != 0x1A1A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1AC0_0x1a1ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1A90u; }
        if (ctx->pc != 0x1A1A90u) { return; }
    }
    ctx->pc = 0x1A1A90u;
label_1a1a90:
    // 0x1a1a90: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1a1a90u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a1a94: 0x86040002  lh          $a0, 0x2($s0)
    ctx->pc = 0x1a1a94u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1a1a98: 0x87a5004c  lh          $a1, 0x4C($sp)
    ctx->pc = 0x1a1a98u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1a1a9c: 0xc0686b0  jal         func_1A1AC0
    ctx->pc = 0x1A1A9Cu;
    SET_GPR_U32(ctx, 31, 0x1A1AA4u);
    ctx->pc = 0x1A1AA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1A9Cu;
            // 0x1a1aa0: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1AC0u;
    if (runtime->hasFunction(0x1A1AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1AA4u; }
        if (ctx->pc != 0x1A1AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1AC0_0x1a1ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1AA4u; }
        if (ctx->pc != 0x1A1AA4u) { return; }
    }
    ctx->pc = 0x1A1AA4u;
label_1a1aa4:
    // 0x1a1aa4: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1a1aa4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a1aa8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1a1aa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a1aac: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1a1aacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1a1ab0: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1a1ab0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a1ab4: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1a1ab4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a1ab8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1AB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1AB8u;
            // 0x1a1abc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A19DCu: goto label_1a19dc;
            case 0x1A19ECu: goto label_1a19ec;
            case 0x1A1A64u: goto label_1a1a64;
            case 0x1A1A80u: goto label_1a1a80;
            case 0x1A1A90u: goto label_1a1a90;
            case 0x1A1AA4u: goto label_1a1aa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1AC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

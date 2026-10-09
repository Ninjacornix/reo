#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132E50
// Address: 0x132e50 - 0x132fe0
void sub_00132E50_0x132e50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132E50_0x132e50");
#endif

    switch (ctx->pc) {
        case 0x132e7cu: goto label_132e7c;
        case 0x132e9cu: goto label_132e9c;
        case 0x132ec0u: goto label_132ec0;
        case 0x132ed0u: goto label_132ed0;
        case 0x132efcu: goto label_132efc;
        case 0x132f64u: goto label_132f64;
        case 0x132f98u: goto label_132f98;
        default: break;
    }

    ctx->pc = 0x132e50u;

    // 0x132e50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x132e50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x132e54: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x132e54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x132e58: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x132e58u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132e5c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x132e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x132e60: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x132e60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132e64: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x132e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x132e68: 0x16400007  bnez        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x132E68u;
    {
        const bool branch_taken_0x132e68 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x132E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132E68u;
            // 0x132e6c: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132e68) {
            ctx->pc = 0x132E88u;
            goto label_132e88;
        }
    }
    ctx->pc = 0x132E70u;
    // 0x132e70: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132e70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132e74: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132E74u;
    SET_GPR_U32(ctx, 31, 0x132E7Cu);
    ctx->pc = 0x132E78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132E74u;
            // 0x132e78: 0x2484b4c0  addiu       $a0, $a0, -0x4B40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948032));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132E7Cu; }
        if (ctx->pc != 0x132E7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132E7Cu; }
        if (ctx->pc != 0x132E7Cu) { return; }
    }
    ctx->pc = 0x132E7Cu;
label_132e7c:
    // 0x132e7c: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x132E7Cu;
    {
        const bool branch_taken_0x132e7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132E7Cu;
            // 0x132e80: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132e7c) {
            ctx->pc = 0x132F68u;
            goto label_132f68;
        }
    }
    ctx->pc = 0x132E84u;
    // 0x132e84: 0x0  nop
    ctx->pc = 0x132e84u;
    // NOP
label_132e88:
    // 0x132e88: 0x82420072  lb          $v0, 0x72($s2)
    ctx->pc = 0x132e88u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 114)));
    // 0x132e8c: 0x12020035  beq         $s0, $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x132E8Cu;
    {
        const bool branch_taken_0x132e8c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x132E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132E8Cu;
            // 0x132e90: 0x82510001  lb          $s1, 0x1($s2) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132e8c) {
            ctx->pc = 0x132F64u;
            goto label_132f64;
        }
    }
    ctx->pc = 0x132E94u;
    // 0x132e94: 0xc049938  jal         func_1264E0
    ctx->pc = 0x132E94u;
    SET_GPR_U32(ctx, 31, 0x132E9Cu);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132E9Cu; }
        if (ctx->pc != 0x132E9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132E9Cu; }
        if (ctx->pc != 0x132E9Cu) { return; }
    }
    ctx->pc = 0x132E9Cu;
label_132e9c:
    // 0x132e9c: 0x2622fffd  addiu       $v0, $s1, -0x3
    ctx->pc = 0x132e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967293));
    // 0x132ea0: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x132ea0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x132ea4: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x132EA4u;
    {
        const bool branch_taken_0x132ea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x132EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132EA4u;
            // 0x132ea8: 0xa2500072  sb          $s0, 0x72($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 114), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132ea4) {
            ctx->pc = 0x132F5Cu;
            goto label_132f5c;
        }
    }
    ctx->pc = 0x132EACu;
    // 0x132eac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x132eacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x132eb0: 0x16020005  bne         $s0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x132EB0u;
    {
        const bool branch_taken_0x132eb0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x132EB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132EB0u;
            // 0x132eb4: 0x8e44000c  lw          $a0, 0xC($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132eb0) {
            ctx->pc = 0x132EC8u;
            goto label_132ec8;
        }
    }
    ctx->pc = 0x132EB8u;
    // 0x132eb8: 0xc04b1c0  jal         func_12C700
    ctx->pc = 0x132EB8u;
    SET_GPR_U32(ctx, 31, 0x132EC0u);
    ctx->pc = 0x132EBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132EB8u;
            // 0x132ebc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C700u;
    if (runtime->hasFunction(0x12C700u)) {
        auto targetFn = runtime->lookupFunction(0x12C700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132EC0u; }
        if (ctx->pc != 0x132EC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C700_0x12c700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132EC0u; }
        if (ctx->pc != 0x132EC0u) { return; }
    }
    ctx->pc = 0x132EC0u;
label_132ec0:
    // 0x132ec0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x132EC0u;
    {
        const bool branch_taken_0x132ec0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132EC0u;
            // 0x132ec4: 0x3c100022  lui         $s0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132ec0) {
            ctx->pc = 0x132EE0u;
            goto label_132ee0;
        }
    }
    ctx->pc = 0x132EC8u;
label_132ec8:
    // 0x132ec8: 0xc04b1c0  jal         func_12C700
    ctx->pc = 0x132EC8u;
    SET_GPR_U32(ctx, 31, 0x132ED0u);
    ctx->pc = 0x132ECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132EC8u;
            // 0x132ecc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C700u;
    if (runtime->hasFunction(0x12C700u)) {
        auto targetFn = runtime->lookupFunction(0x12C700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132ED0u; }
        if (ctx->pc != 0x132ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C700_0x12c700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132ED0u; }
        if (ctx->pc != 0x132ED0u) { return; }
    }
    ctx->pc = 0x132ED0u;
label_132ed0:
    // 0x132ed0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x132ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x132ed4: 0x8c43f3c4  lw          $v1, -0xC3C($v0)
    ctx->pc = 0x132ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294964164)));
    // 0x132ed8: 0xae4300a0  sw          $v1, 0xA0($s2)
    ctx->pc = 0x132ed8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 160), GPR_U32(ctx, 3));
    // 0x132edc: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x132edcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
label_132ee0:
    // 0x132ee0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x132ee0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132ee4: 0x2610b750  addiu       $s0, $s0, -0x48B0
    ctx->pc = 0x132ee4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294948688));
    // 0x132ee8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x132ee8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132eec: 0x8e110000  lw          $s1, 0x0($s0)
    ctx->pc = 0x132eecu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x132ef0: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x132ef0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x132ef4: 0xc04c858  jal         func_132160
    ctx->pc = 0x132EF4u;
    SET_GPR_U32(ctx, 31, 0x132EFCu);
    ctx->pc = 0x132EF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132EF4u;
            // 0x132ef8: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132160u;
    if (runtime->hasFunction(0x132160u)) {
        auto targetFn = runtime->lookupFunction(0x132160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132EFCu; }
        if (ctx->pc != 0x132EFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132160_0x132160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132EFCu; }
        if (ctx->pc != 0x132EFCu) { return; }
    }
    ctx->pc = 0x132EFCu;
label_132efc:
    // 0x132efc: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x132efcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x132f00: 0xc7a00000  lwc1        $f0, 0x0($sp)
    ctx->pc = 0x132f00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x132f04: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x132f04u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x132f08: 0x3c014f00  lui         $at, 0x4F00
    ctx->pc = 0x132f08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)20224 << 16));
    // 0x132f0c: 0x44811800  mtc1        $at, $f3
    ctx->pc = 0x132f0cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x132f10: 0xc7a20004  lwc1        $f2, 0x4($sp)
    ctx->pc = 0x132f10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x132f14: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x132f14u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x132f18: 0xc441b788  lwc1        $f1, -0x4878($v0)
    ctx->pc = 0x132f18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294948744)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x132f1c: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x132f1cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x132f20: 0x0  nop
    ctx->pc = 0x132f20u;
    // NOP
    // 0x132f24: 0x0  nop
    ctx->pc = 0x132f24u;
    // NOP
    // 0x132f28: 0x46020003  div.s       $f0, $f0, $f2
    ctx->pc = 0x132f28u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[2];
    // 0x132f2c: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x132f2cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x132f30: 0x46001836  c.le.s      $f3, $f0
    ctx->pc = 0x132f30u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[3], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x132f34: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x132f34u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x132f38: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x132f38u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x132f3c: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x132F3Cu;
    {
        const bool branch_taken_0x132f3c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x132F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132F3Cu;
            // 0x132f40: 0xae110000  sw          $s1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132f3c) {
            ctx->pc = 0x132F58u;
            goto label_132f58;
        }
    }
    ctx->pc = 0x132F44u;
    // 0x132f44: 0x46030001  sub.s       $f0, $f0, $f3
    ctx->pc = 0x132f44u;
    ctx->f[0] = FPU_SUB_S(ctx->f[0], ctx->f[3]);
    // 0x132f48: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x132f48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x132f4c: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x132f4cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x132f50: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x132f50u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x132f54: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x132f54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
label_132f58:
    // 0x132f58: 0xae43009c  sw          $v1, 0x9C($s2)
    ctx->pc = 0x132f58u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 156), GPR_U32(ctx, 3));
label_132f5c:
    // 0x132f5c: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x132F5Cu;
    SET_GPR_U32(ctx, 31, 0x132F64u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132F64u; }
        if (ctx->pc != 0x132F64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132F64u; }
        if (ctx->pc != 0x132F64u) { return; }
    }
    ctx->pc = 0x132F64u;
label_132f64:
    // 0x132f64: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x132f64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_132f68:
    // 0x132f68: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x132f68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x132f6c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x132f6cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x132f70: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x132f70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x132f74: 0x3e00008  jr          $ra
    ctx->pc = 0x132F74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132F74u;
            // 0x132f78: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132E7Cu: goto label_132e7c;
            case 0x132E88u: goto label_132e88;
            case 0x132E9Cu: goto label_132e9c;
            case 0x132EC0u: goto label_132ec0;
            case 0x132EC8u: goto label_132ec8;
            case 0x132ED0u: goto label_132ed0;
            case 0x132EE0u: goto label_132ee0;
            case 0x132EFCu: goto label_132efc;
            case 0x132F58u: goto label_132f58;
            case 0x132F5Cu: goto label_132f5c;
            case 0x132F64u: goto label_132f64;
            case 0x132F68u: goto label_132f68;
            case 0x132F98u: goto label_132f98;
            case 0x132FA0u: goto label_132fa0;
            case 0x132FA4u: goto label_132fa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132F7Cu;
    // 0x132f7c: 0x0  nop
    ctx->pc = 0x132f7cu;
    // NOP
    // 0x132f80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132f80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132f84: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132F84u;
    {
        const bool branch_taken_0x132f84 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132F84u;
            // 0x132f88: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132f84) {
            ctx->pc = 0x132FA0u;
            goto label_132fa0;
        }
    }
    ctx->pc = 0x132F8Cu;
    // 0x132f8c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132f8cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132f90: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132F90u;
    SET_GPR_U32(ctx, 31, 0x132F98u);
    ctx->pc = 0x132F94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132F90u;
            // 0x132f94: 0x2484b4e8  addiu       $a0, $a0, -0x4B18 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132F98u; }
        if (ctx->pc != 0x132F98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132F98u; }
        if (ctx->pc != 0x132F98u) { return; }
    }
    ctx->pc = 0x132F98u;
label_132f98:
    // 0x132f98: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132F98u;
    {
        const bool branch_taken_0x132f98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132F98u;
            // 0x132f9c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132f98) {
            ctx->pc = 0x132FA4u;
            goto label_132fa4;
        }
    }
    ctx->pc = 0x132FA0u;
label_132fa0:
    // 0x132fa0: 0x80820072  lb          $v0, 0x72($a0)
    ctx->pc = 0x132fa0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 114)));
label_132fa4:
    // 0x132fa4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132fa4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132fa8: 0x3e00008  jr          $ra
    ctx->pc = 0x132FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132FA8u;
            // 0x132fac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132E7Cu: goto label_132e7c;
            case 0x132E88u: goto label_132e88;
            case 0x132E9Cu: goto label_132e9c;
            case 0x132EC0u: goto label_132ec0;
            case 0x132EC8u: goto label_132ec8;
            case 0x132ED0u: goto label_132ed0;
            case 0x132EE0u: goto label_132ee0;
            case 0x132EFCu: goto label_132efc;
            case 0x132F58u: goto label_132f58;
            case 0x132F5Cu: goto label_132f5c;
            case 0x132F64u: goto label_132f64;
            case 0x132F68u: goto label_132f68;
            case 0x132F98u: goto label_132f98;
            case 0x132FA0u: goto label_132fa0;
            case 0x132FA4u: goto label_132fa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132FB0u;
    // 0x132fb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132fb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132fb8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132fb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132fbc: 0x804b23a  j           func_12C8E8
    ctx->pc = 0x132FBCu;
    ctx->pc = 0x132FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132FBCu;
            // 0x132fc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C8E8u;
    {
        auto targetFn = runtime->lookupFunction(0x12C8E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x132FC4u;
    // 0x132fc4: 0x0  nop
    ctx->pc = 0x132fc4u;
    // NOP
    // 0x132fc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132fc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132fcc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x132fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x132fd0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132fd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132fd4: 0x804b23c  j           func_12C8F0
    ctx->pc = 0x132FD4u;
    ctx->pc = 0x132FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132FD4u;
            // 0x132fd8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C8F0u;
    {
        auto targetFn = runtime->lookupFunction(0x12C8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x132FDCu;
    // 0x132fdc: 0x0  nop
    ctx->pc = 0x132fdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

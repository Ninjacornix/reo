#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018ED20
// Address: 0x18ed20 - 0x18eeb0
void sub_0018ED20_0x18ed20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018ED20_0x18ed20");
#endif

    switch (ctx->pc) {
        case 0x18edfcu: goto label_18edfc;
        default: break;
    }

    ctx->pc = 0x18ed20u;

    // 0x18ed20: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18ed20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18ed24: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x18ed24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18ed28: 0x8c224160  lw          $v0, 0x4160($at)
    ctx->pc = 0x18ed28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16736)));
    // 0x18ed2c: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x18ed2cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x18ed30: 0x624021  addu        $t0, $v1, $v0
    ctx->pc = 0x18ed30u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18ed34: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18ed34u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18ed38: 0x85020002  lh          $v0, 0x2($t0)
    ctx->pc = 0x18ed38u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x18ed3c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18ed3cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18ed40: 0x0  nop
    ctx->pc = 0x18ed40u;
    // NOP
    // 0x18ed44: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18ed44u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18ed48: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18ed48u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ed4c: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x18ED4Cu;
    {
        const bool branch_taken_0x18ed4c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ed4c) {
            ctx->pc = 0x18ED64u;
            goto label_18ed64;
        }
    }
    ctx->pc = 0x18ED54u;
    // 0x18ed54: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x18ed54u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18ed58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18ed58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ed5c: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18ED5Cu;
    {
        const bool branch_taken_0x18ed5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18ED60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ED5Cu;
            // 0x18ed60: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ed5c) {
            ctx->pc = 0x18ED74u;
            goto label_18ed74;
        }
    }
    ctx->pc = 0x18ED64u;
label_18ed64:
    // 0x18ed64: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ed64u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18ed68: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18ed68u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ed6c: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x18ED6Cu;
    {
        const bool branch_taken_0x18ed6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ED70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ED6Cu;
            // 0x18ed70: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ed6c) {
            ctx->pc = 0x18EEA0u;
            goto label_18eea0;
        }
    }
    ctx->pc = 0x18ED74u;
label_18ed74:
    // 0x18ed74: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x18ed74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x18ed78: 0x8442fffe  lh          $v0, -0x2($v0)
    ctx->pc = 0x18ed78u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294967294)));
    // 0x18ed7c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18ed7cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18ed80: 0x0  nop
    ctx->pc = 0x18ed80u;
    // NOP
    // 0x18ed84: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18ed84u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18ed88: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18ed88u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ed8c: 0x4501000b  bc1t        . + 4 + (0xB << 2)
    ctx->pc = 0x18ED8Cu;
    {
        const bool branch_taken_0x18ed8c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ed8c) {
            ctx->pc = 0x18EDBCu;
            goto label_18edbc;
        }
    }
    ctx->pc = 0x18ED94u;
    // 0x18ed94: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18ed94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18ed98: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18ed98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18ed9c: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x18ed9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x18eda0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18eda0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18eda4: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18eda4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18eda8: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x18eda8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18edac: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18edacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18edb0: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x18edb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18edb4: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x18EDB4u;
    {
        const bool branch_taken_0x18edb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EDB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EDB4u;
            // 0x18edb8: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18edb4) {
            ctx->pc = 0x18EEA0u;
            goto label_18eea0;
        }
    }
    ctx->pc = 0x18EDBCu;
label_18edbc:
    // 0x18edbc: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18edbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18edc0: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18edc0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18edc4: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18EDC4u;
    {
        const bool branch_taken_0x18edc4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x18edc4) {
            ctx->pc = 0x18EDD4u;
            goto label_18edd4;
        }
    }
    ctx->pc = 0x18EDCCu;
    // 0x18edcc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18EDCCu;
    {
        const bool branch_taken_0x18edcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EDCCu;
            // 0x18edd0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18edcc) {
            ctx->pc = 0x18EDECu;
            goto label_18edec;
        }
    }
    ctx->pc = 0x18EDD4u;
label_18edd4:
    // 0x18edd4: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x18edd4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x18edd8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18EDD8u;
    {
        const bool branch_taken_0x18edd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18edd8) {
            ctx->pc = 0x18EDECu;
            goto label_18edec;
        }
    }
    ctx->pc = 0x18EDE0u;
    // 0x18ede0: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18ede0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18ede4: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ede4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ede8: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x18ede8u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
label_18edec:
    // 0x18edec: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18edecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18edf0: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18edf0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18edf4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18edf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18edf8: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x18edf8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_18edfc:
    // 0x18edfc: 0x85030002  lh          $v1, 0x2($t0)
    ctx->pc = 0x18edfcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x18ee00: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18ee00u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18ee04: 0x0  nop
    ctx->pc = 0x18ee04u;
    // NOP
    // 0x18ee08: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18ee08u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18ee0c: 0x460c0032  c.eq.s      $f0, $f12
    ctx->pc = 0x18ee0cu;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ee10: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x18EE10u;
    {
        const bool branch_taken_0x18ee10 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ee10) {
            ctx->pc = 0x18EE28u;
            goto label_18ee28;
        }
    }
    ctx->pc = 0x18EE18u;
    // 0x18ee18: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ee18u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18ee1c: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18ee1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ee20: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x18EE20u;
    {
        const bool branch_taken_0x18ee20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EE24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EE20u;
            // 0x18ee24: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ee20) {
            ctx->pc = 0x18EEA0u;
            goto label_18eea0;
        }
    }
    ctx->pc = 0x18EE28u;
label_18ee28:
    // 0x18ee28: 0x460c0034  c.lt.s      $f0, $f12
    ctx->pc = 0x18ee28u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ee2c: 0x4500000d  bc1f        . + 4 + (0xD << 2)
    ctx->pc = 0x18EE2Cu;
    {
        const bool branch_taken_0x18ee2c = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ee2c) {
            ctx->pc = 0x18EE64u;
            goto label_18ee64;
        }
    }
    ctx->pc = 0x18EE34u;
    // 0x18ee34: 0x85020006  lh          $v0, 0x6($t0)
    ctx->pc = 0x18ee34u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 6)));
    // 0x18ee38: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18ee38u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18ee3c: 0x0  nop
    ctx->pc = 0x18ee3cu;
    // NOP
    // 0x18ee40: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18ee40u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18ee44: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18ee44u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ee48: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18EE48u;
    {
        const bool branch_taken_0x18ee48 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ee48) {
            ctx->pc = 0x18EE64u;
            goto label_18ee64;
        }
    }
    ctx->pc = 0x18EE50u;
    // 0x18ee50: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ee50u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18ee54: 0x25020004  addiu       $v0, $t0, 0x4
    ctx->pc = 0x18ee54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x18ee58: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x18ee58u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x18ee5c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x18EE5Cu;
    {
        const bool branch_taken_0x18ee5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EE60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EE5Cu;
            // 0x18ee60: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ee5c) {
            ctx->pc = 0x18EEA0u;
            goto label_18eea0;
        }
    }
    ctx->pc = 0x18EE64u;
label_18ee64:
    // 0x18ee64: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18ee64u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18ee68: 0x0  nop
    ctx->pc = 0x18ee68u;
    // NOP
    // 0x18ee6c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18ee6cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18ee70: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18ee70u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ee74: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18EE74u;
    {
        const bool branch_taken_0x18ee74 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18EE78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EE74u;
            // 0x18ee78: 0x24e20001  addiu       $v0, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ee74) {
            ctx->pc = 0x18EE90u;
            goto label_18ee90;
        }
    }
    ctx->pc = 0x18EE7Cu;
    // 0x18ee7c: 0x24e2ffff  addiu       $v0, $a3, -0x1
    ctx->pc = 0x18ee7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x18ee80: 0x2508fffc  addiu       $t0, $t0, -0x4
    ctx->pc = 0x18ee80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967292));
    // 0x18ee84: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ee84u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ee88: 0x1000ffdc  b           . + 4 + (-0x24 << 2)
    ctx->pc = 0x18EE88u;
    {
        const bool branch_taken_0x18ee88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EE8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EE88u;
            // 0x18ee8c: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ee88) {
            ctx->pc = 0x18EDFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18edfc;
        }
    }
    ctx->pc = 0x18EE90u;
label_18ee90:
    // 0x18ee90: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x18ee90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x18ee94: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ee94u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ee98: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x18EE98u;
    {
        const bool branch_taken_0x18ee98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EE9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EE98u;
            // 0x18ee9c: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ee98) {
            ctx->pc = 0x18EDFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18edfc;
        }
    }
    ctx->pc = 0x18EEA0u;
label_18eea0:
    // 0x18eea0: 0x3e00008  jr          $ra
    ctx->pc = 0x18EEA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18ED64u: goto label_18ed64;
            case 0x18ED74u: goto label_18ed74;
            case 0x18EDBCu: goto label_18edbc;
            case 0x18EDD4u: goto label_18edd4;
            case 0x18EDECu: goto label_18edec;
            case 0x18EDFCu: goto label_18edfc;
            case 0x18EE28u: goto label_18ee28;
            case 0x18EE64u: goto label_18ee64;
            case 0x18EE90u: goto label_18ee90;
            case 0x18EEA0u: goto label_18eea0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18EEA8u;
    // 0x18eea8: 0x0  nop
    ctx->pc = 0x18eea8u;
    // NOP
    // 0x18eeac: 0x0  nop
    ctx->pc = 0x18eeacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

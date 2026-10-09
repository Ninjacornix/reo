#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018EA60
// Address: 0x18ea60 - 0x18ebb0
void sub_0018EA60_0x18ea60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018EA60_0x18ea60");
#endif

    switch (ctx->pc) {
        case 0x18eb24u: goto label_18eb24;
        default: break;
    }

    ctx->pc = 0x18ea60u;

    // 0x18ea60: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18ea60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18ea64: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x18ea64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18ea68: 0x8c224160  lw          $v0, 0x4160($at)
    ctx->pc = 0x18ea68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16736)));
    // 0x18ea6c: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x18ea6cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x18ea70: 0x624021  addu        $t0, $v1, $v0
    ctx->pc = 0x18ea70u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18ea74: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18ea74u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18ea78: 0xc5000004  lwc1        $f0, 0x4($t0)
    ctx->pc = 0x18ea78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ea7c: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18ea7cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ea80: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x18EA80u;
    {
        const bool branch_taken_0x18ea80 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ea80) {
            ctx->pc = 0x18EA98u;
            goto label_18ea98;
        }
    }
    ctx->pc = 0x18EA88u;
    // 0x18ea88: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x18ea88u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18ea8c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18ea8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ea90: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18EA90u;
    {
        const bool branch_taken_0x18ea90 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18EA94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EA90u;
            // 0x18ea94: 0x31100  sll         $v0, $v1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ea90) {
            ctx->pc = 0x18EAA8u;
            goto label_18eaa8;
        }
    }
    ctx->pc = 0x18EA98u;
label_18ea98:
    // 0x18ea98: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ea98u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18ea9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18ea9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18eaa0: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x18EAA0u;
    {
        const bool branch_taken_0x18eaa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EAA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EAA0u;
            // 0x18eaa4: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eaa0) {
            ctx->pc = 0x18EBA4u;
            goto label_18eba4;
        }
    }
    ctx->pc = 0x18EAA8u;
label_18eaa8:
    // 0x18eaa8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x18eaa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x18eaac: 0xc440fff4  lwc1        $f0, -0xC($v0)
    ctx->pc = 0x18eaacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294967284)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18eab0: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18eab0u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18eab4: 0x4501000b  bc1t        . + 4 + (0xB << 2)
    ctx->pc = 0x18EAB4u;
    {
        const bool branch_taken_0x18eab4 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18eab4) {
            ctx->pc = 0x18EAE4u;
            goto label_18eae4;
        }
    }
    ctx->pc = 0x18EABCu;
    // 0x18eabc: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18eabcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18eac0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x18eac0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x18eac4: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x18eac4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x18eac8: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18eac8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18eacc: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18eaccu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18ead0: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x18ead0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18ead4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18ead4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18ead8: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x18ead8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18eadc: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x18EADCu;
    {
        const bool branch_taken_0x18eadc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EADCu;
            // 0x18eae0: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eadc) {
            ctx->pc = 0x18EBA4u;
            goto label_18eba4;
        }
    }
    ctx->pc = 0x18EAE4u;
label_18eae4:
    // 0x18eae4: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18eae4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18eae8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18eae8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18eaec: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18EAECu;
    {
        const bool branch_taken_0x18eaec = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x18eaec) {
            ctx->pc = 0x18EAFCu;
            goto label_18eafc;
        }
    }
    ctx->pc = 0x18EAF4u;
    // 0x18eaf4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18EAF4u;
    {
        const bool branch_taken_0x18eaf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EAF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EAF4u;
            // 0x18eaf8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eaf4) {
            ctx->pc = 0x18EB14u;
            goto label_18eb14;
        }
    }
    ctx->pc = 0x18EAFCu;
label_18eafc:
    // 0x18eafc: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x18eafcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x18eb00: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18EB00u;
    {
        const bool branch_taken_0x18eb00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18eb00) {
            ctx->pc = 0x18EB14u;
            goto label_18eb14;
        }
    }
    ctx->pc = 0x18EB08u;
    // 0x18eb08: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18eb08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18eb0c: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18eb0cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18eb10: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x18eb10u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
label_18eb14:
    // 0x18eb14: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18eb14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18eb18: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18eb18u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18eb1c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x18eb1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x18eb20: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x18eb20u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_18eb24:
    // 0x18eb24: 0xc5010004  lwc1        $f1, 0x4($t0)
    ctx->pc = 0x18eb24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18eb28: 0x460c0832  c.eq.s      $f1, $f12
    ctx->pc = 0x18eb28u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[1], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18eb2c: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x18EB2Cu;
    {
        const bool branch_taken_0x18eb2c = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18eb2c) {
            ctx->pc = 0x18EB44u;
            goto label_18eb44;
        }
    }
    ctx->pc = 0x18EB34u;
    // 0x18eb34: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18eb34u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18eb38: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18eb38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18eb3c: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x18EB3Cu;
    {
        const bool branch_taken_0x18eb3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EB40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EB3Cu;
            // 0x18eb40: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eb3c) {
            ctx->pc = 0x18EBA4u;
            goto label_18eba4;
        }
    }
    ctx->pc = 0x18EB44u;
label_18eb44:
    // 0x18eb44: 0x460c0834  c.lt.s      $f1, $f12
    ctx->pc = 0x18eb44u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18eb48: 0x4500000a  bc1f        . + 4 + (0xA << 2)
    ctx->pc = 0x18EB48u;
    {
        const bool branch_taken_0x18eb48 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18eb48) {
            ctx->pc = 0x18EB74u;
            goto label_18eb74;
        }
    }
    ctx->pc = 0x18EB50u;
    // 0x18eb50: 0xc5000014  lwc1        $f0, 0x14($t0)
    ctx->pc = 0x18eb50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18eb54: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18eb54u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18eb58: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18EB58u;
    {
        const bool branch_taken_0x18eb58 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18eb58) {
            ctx->pc = 0x18EB74u;
            goto label_18eb74;
        }
    }
    ctx->pc = 0x18EB60u;
    // 0x18eb60: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18eb60u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18eb64: 0x25020010  addiu       $v0, $t0, 0x10
    ctx->pc = 0x18eb64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 16));
    // 0x18eb68: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x18eb68u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x18eb6c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x18EB6Cu;
    {
        const bool branch_taken_0x18eb6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EB70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EB6Cu;
            // 0x18eb70: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eb6c) {
            ctx->pc = 0x18EBA4u;
            goto label_18eba4;
        }
    }
    ctx->pc = 0x18EB74u;
label_18eb74:
    // 0x18eb74: 0x46016034  c.lt.s      $f12, $f1
    ctx->pc = 0x18eb74u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18eb78: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18EB78u;
    {
        const bool branch_taken_0x18eb78 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18EB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EB78u;
            // 0x18eb7c: 0x24e20001  addiu       $v0, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eb78) {
            ctx->pc = 0x18EB94u;
            goto label_18eb94;
        }
    }
    ctx->pc = 0x18EB80u;
    // 0x18eb80: 0x24e2ffff  addiu       $v0, $a3, -0x1
    ctx->pc = 0x18eb80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x18eb84: 0x2508fff0  addiu       $t0, $t0, -0x10
    ctx->pc = 0x18eb84u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967280));
    // 0x18eb88: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18eb88u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18eb8c: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x18EB8Cu;
    {
        const bool branch_taken_0x18eb8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EB8Cu;
            // 0x18eb90: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eb8c) {
            ctx->pc = 0x18EB24u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18eb24;
        }
    }
    ctx->pc = 0x18EB94u;
label_18eb94:
    // 0x18eb94: 0x25080010  addiu       $t0, $t0, 0x10
    ctx->pc = 0x18eb94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 16));
    // 0x18eb98: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18eb98u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18eb9c: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x18EB9Cu;
    {
        const bool branch_taken_0x18eb9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EBA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EB9Cu;
            // 0x18eba0: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eb9c) {
            ctx->pc = 0x18EB24u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18eb24;
        }
    }
    ctx->pc = 0x18EBA4u;
label_18eba4:
    // 0x18eba4: 0x3e00008  jr          $ra
    ctx->pc = 0x18EBA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18EA98u: goto label_18ea98;
            case 0x18EAA8u: goto label_18eaa8;
            case 0x18EAE4u: goto label_18eae4;
            case 0x18EAFCu: goto label_18eafc;
            case 0x18EB14u: goto label_18eb14;
            case 0x18EB24u: goto label_18eb24;
            case 0x18EB44u: goto label_18eb44;
            case 0x18EB74u: goto label_18eb74;
            case 0x18EB94u: goto label_18eb94;
            case 0x18EBA4u: goto label_18eba4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18EBACu;
    // 0x18ebac: 0x0  nop
    ctx->pc = 0x18ebacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

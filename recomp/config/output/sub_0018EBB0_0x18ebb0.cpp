#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018EBB0
// Address: 0x18ebb0 - 0x18ed20
void sub_0018EBB0_0x18ebb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018EBB0_0x18ebb0");
#endif

    switch (ctx->pc) {
        case 0x18ec8cu: goto label_18ec8c;
        default: break;
    }

    ctx->pc = 0x18ebb0u;

    // 0x18ebb0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18ebb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18ebb4: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x18ebb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18ebb8: 0x8c224160  lw          $v0, 0x4160($at)
    ctx->pc = 0x18ebb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16736)));
    // 0x18ebbc: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x18ebbcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x18ebc0: 0x624021  addu        $t0, $v1, $v0
    ctx->pc = 0x18ebc0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18ebc4: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18ebc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18ebc8: 0xc5000008  lwc1        $f0, 0x8($t0)
    ctx->pc = 0x18ebc8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ebcc: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18ebccu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ebd0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x18EBD0u;
    {
        const bool branch_taken_0x18ebd0 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ebd0) {
            ctx->pc = 0x18EBE8u;
            goto label_18ebe8;
        }
    }
    ctx->pc = 0x18EBD8u;
    // 0x18ebd8: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x18ebd8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18ebdc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18ebdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18ebe0: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18EBE0u;
    {
        const bool branch_taken_0x18ebe0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18EBE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EBE0u;
            // 0x18ebe4: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ebe0) {
            ctx->pc = 0x18EBF8u;
            goto label_18ebf8;
        }
    }
    ctx->pc = 0x18EBE8u;
label_18ebe8:
    // 0x18ebe8: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ebe8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18ebec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18ebecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ebf0: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x18EBF0u;
    {
        const bool branch_taken_0x18ebf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EBF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EBF0u;
            // 0x18ebf4: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ebf0) {
            ctx->pc = 0x18ED0Cu;
            goto label_18ed0c;
        }
    }
    ctx->pc = 0x18EBF8u;
label_18ebf8:
    // 0x18ebf8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18ebf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18ebfc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18ebfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18ec00: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x18ec00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x18ec04: 0xc440fff4  lwc1        $f0, -0xC($v0)
    ctx->pc = 0x18ec04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294967284)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ec08: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18ec08u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ec0c: 0x4501000d  bc1t        . + 4 + (0xD << 2)
    ctx->pc = 0x18EC0Cu;
    {
        const bool branch_taken_0x18ec0c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ec0c) {
            ctx->pc = 0x18EC44u;
            goto label_18ec44;
        }
    }
    ctx->pc = 0x18EC14u;
    // 0x18ec14: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x18ec14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18ec18: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x18ec18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18ec1c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18ec1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18ec20: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18ec20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18ec24: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x18ec24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x18ec28: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18ec28u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18ec2c: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18ec2cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18ec30: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x18ec30u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18ec34: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18ec34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18ec38: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x18ec38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ec3c: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x18EC3Cu;
    {
        const bool branch_taken_0x18ec3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EC40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EC3Cu;
            // 0x18ec40: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ec3c) {
            ctx->pc = 0x18ED0Cu;
            goto label_18ed0c;
        }
    }
    ctx->pc = 0x18EC44u;
label_18ec44:
    // 0x18ec44: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18ec44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18ec48: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18ec48u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18ec4c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18EC4Cu;
    {
        const bool branch_taken_0x18ec4c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x18ec4c) {
            ctx->pc = 0x18EC5Cu;
            goto label_18ec5c;
        }
    }
    ctx->pc = 0x18EC54u;
    // 0x18ec54: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18EC54u;
    {
        const bool branch_taken_0x18ec54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EC58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EC54u;
            // 0x18ec58: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ec54) {
            ctx->pc = 0x18EC74u;
            goto label_18ec74;
        }
    }
    ctx->pc = 0x18EC5Cu;
label_18ec5c:
    // 0x18ec5c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x18ec5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x18ec60: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18EC60u;
    {
        const bool branch_taken_0x18ec60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18ec60) {
            ctx->pc = 0x18EC74u;
            goto label_18ec74;
        }
    }
    ctx->pc = 0x18EC68u;
    // 0x18ec68: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18ec68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18ec6c: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ec6cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ec70: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x18ec70u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
label_18ec74:
    // 0x18ec74: 0x71c3c  dsll32      $v1, $a3, 16
    ctx->pc = 0x18ec74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18ec78: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x18ec78u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x18ec7c: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x18ec7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18ec80: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18ec80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18ec84: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18ec84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18ec88: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x18ec88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_18ec8c:
    // 0x18ec8c: 0xc5010008  lwc1        $f1, 0x8($t0)
    ctx->pc = 0x18ec8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18ec90: 0x460c0832  c.eq.s      $f1, $f12
    ctx->pc = 0x18ec90u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[1], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ec94: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x18EC94u;
    {
        const bool branch_taken_0x18ec94 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ec94) {
            ctx->pc = 0x18ECACu;
            goto label_18ecac;
        }
    }
    ctx->pc = 0x18EC9Cu;
    // 0x18ec9c: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ec9cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18eca0: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18eca0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18eca4: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x18ECA4u;
    {
        const bool branch_taken_0x18eca4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ECA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ECA4u;
            // 0x18eca8: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eca4) {
            ctx->pc = 0x18ED0Cu;
            goto label_18ed0c;
        }
    }
    ctx->pc = 0x18ECACu;
label_18ecac:
    // 0x18ecac: 0x460c0834  c.lt.s      $f1, $f12
    ctx->pc = 0x18ecacu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ecb0: 0x4500000a  bc1f        . + 4 + (0xA << 2)
    ctx->pc = 0x18ECB0u;
    {
        const bool branch_taken_0x18ecb0 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ecb0) {
            ctx->pc = 0x18ECDCu;
            goto label_18ecdc;
        }
    }
    ctx->pc = 0x18ECB8u;
    // 0x18ecb8: 0xc500001c  lwc1        $f0, 0x1C($t0)
    ctx->pc = 0x18ecb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ecbc: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18ecbcu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ecc0: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18ECC0u;
    {
        const bool branch_taken_0x18ecc0 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ecc0) {
            ctx->pc = 0x18ECDCu;
            goto label_18ecdc;
        }
    }
    ctx->pc = 0x18ECC8u;
    // 0x18ecc8: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ecc8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18eccc: 0x25020014  addiu       $v0, $t0, 0x14
    ctx->pc = 0x18ecccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 20));
    // 0x18ecd0: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x18ecd0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x18ecd4: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x18ECD4u;
    {
        const bool branch_taken_0x18ecd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ECD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ECD4u;
            // 0x18ecd8: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ecd4) {
            ctx->pc = 0x18ED0Cu;
            goto label_18ed0c;
        }
    }
    ctx->pc = 0x18ECDCu;
label_18ecdc:
    // 0x18ecdc: 0x46016034  c.lt.s      $f12, $f1
    ctx->pc = 0x18ecdcu;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ece0: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18ECE0u;
    {
        const bool branch_taken_0x18ece0 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18ECE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ECE0u;
            // 0x18ece4: 0x24e20001  addiu       $v0, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ece0) {
            ctx->pc = 0x18ECFCu;
            goto label_18ecfc;
        }
    }
    ctx->pc = 0x18ECE8u;
    // 0x18ece8: 0x24e2ffff  addiu       $v0, $a3, -0x1
    ctx->pc = 0x18ece8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x18ecec: 0x2508ffec  addiu       $t0, $t0, -0x14
    ctx->pc = 0x18ececu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967276));
    // 0x18ecf0: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ecf0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ecf4: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x18ECF4u;
    {
        const bool branch_taken_0x18ecf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ECF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ECF4u;
            // 0x18ecf8: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ecf4) {
            ctx->pc = 0x18EC8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18ec8c;
        }
    }
    ctx->pc = 0x18ECFCu;
label_18ecfc:
    // 0x18ecfc: 0x25080014  addiu       $t0, $t0, 0x14
    ctx->pc = 0x18ecfcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 20));
    // 0x18ed00: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ed00u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ed04: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x18ED04u;
    {
        const bool branch_taken_0x18ed04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18ED08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18ED04u;
            // 0x18ed08: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ed04) {
            ctx->pc = 0x18EC8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18ec8c;
        }
    }
    ctx->pc = 0x18ED0Cu;
label_18ed0c:
    // 0x18ed0c: 0x3e00008  jr          $ra
    ctx->pc = 0x18ED0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18EBE8u: goto label_18ebe8;
            case 0x18EBF8u: goto label_18ebf8;
            case 0x18EC44u: goto label_18ec44;
            case 0x18EC5Cu: goto label_18ec5c;
            case 0x18EC74u: goto label_18ec74;
            case 0x18EC8Cu: goto label_18ec8c;
            case 0x18ECACu: goto label_18ecac;
            case 0x18ECDCu: goto label_18ecdc;
            case 0x18ECFCu: goto label_18ecfc;
            case 0x18ED0Cu: goto label_18ed0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18ED14u;
    // 0x18ed14: 0x0  nop
    ctx->pc = 0x18ed14u;
    // NOP
    // 0x18ed18: 0x0  nop
    ctx->pc = 0x18ed18u;
    // NOP
    // 0x18ed1c: 0x0  nop
    ctx->pc = 0x18ed1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

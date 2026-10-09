#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E910
// Address: 0x18e910 - 0x18ea60
void sub_0018E910_0x18e910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E910_0x18e910");
#endif

    switch (ctx->pc) {
        case 0x18e9d4u: goto label_18e9d4;
        default: break;
    }

    ctx->pc = 0x18e910u;

    // 0x18e910: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18e910u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18e914: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x18e914u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18e918: 0x8c224160  lw          $v0, 0x4160($at)
    ctx->pc = 0x18e918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16736)));
    // 0x18e91c: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x18e91cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x18e920: 0x624021  addu        $t0, $v1, $v0
    ctx->pc = 0x18e920u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18e924: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18e924u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18e928: 0xc5000004  lwc1        $f0, 0x4($t0)
    ctx->pc = 0x18e928u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18e92c: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18e92cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18e930: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x18E930u;
    {
        const bool branch_taken_0x18e930 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18e930) {
            ctx->pc = 0x18E948u;
            goto label_18e948;
        }
    }
    ctx->pc = 0x18E938u;
    // 0x18e938: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x18e938u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18e93c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18e93cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18e940: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18E940u;
    {
        const bool branch_taken_0x18e940 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18E944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E940u;
            // 0x18e944: 0x310c0  sll         $v0, $v1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e940) {
            ctx->pc = 0x18E958u;
            goto label_18e958;
        }
    }
    ctx->pc = 0x18E948u;
label_18e948:
    // 0x18e948: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18e948u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18e94c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18e94cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e950: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x18E950u;
    {
        const bool branch_taken_0x18e950 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E950u;
            // 0x18e954: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e950) {
            ctx->pc = 0x18EA54u;
            goto label_18ea54;
        }
    }
    ctx->pc = 0x18E958u;
label_18e958:
    // 0x18e958: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x18e958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x18e95c: 0xc440fffc  lwc1        $f0, -0x4($v0)
    ctx->pc = 0x18e95cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4294967292)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18e960: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18e960u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18e964: 0x4501000b  bc1t        . + 4 + (0xB << 2)
    ctx->pc = 0x18E964u;
    {
        const bool branch_taken_0x18e964 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18e964) {
            ctx->pc = 0x18E994u;
            goto label_18e994;
        }
    }
    ctx->pc = 0x18E96Cu;
    // 0x18e96c: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18e96cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18e970: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x18e970u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x18e974: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x18e974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x18e978: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18e978u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18e97c: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18e97cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18e980: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x18e980u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18e984: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18e984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18e988: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x18e988u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18e98c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x18E98Cu;
    {
        const bool branch_taken_0x18e98c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E98Cu;
            // 0x18e990: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e98c) {
            ctx->pc = 0x18EA54u;
            goto label_18ea54;
        }
    }
    ctx->pc = 0x18E994u;
label_18e994:
    // 0x18e994: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18e994u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18e998: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18e998u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18e99c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18E99Cu;
    {
        const bool branch_taken_0x18e99c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x18e99c) {
            ctx->pc = 0x18E9ACu;
            goto label_18e9ac;
        }
    }
    ctx->pc = 0x18E9A4u;
    // 0x18e9a4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18E9A4u;
    {
        const bool branch_taken_0x18e9a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E9A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E9A4u;
            // 0x18e9a8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e9a4) {
            ctx->pc = 0x18E9C4u;
            goto label_18e9c4;
        }
    }
    ctx->pc = 0x18E9ACu;
label_18e9ac:
    // 0x18e9ac: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x18e9acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x18e9b0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18E9B0u;
    {
        const bool branch_taken_0x18e9b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e9b0) {
            ctx->pc = 0x18E9C4u;
            goto label_18e9c4;
        }
    }
    ctx->pc = 0x18E9B8u;
    // 0x18e9b8: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18e9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18e9bc: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18e9bcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18e9c0: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x18e9c0u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
label_18e9c4:
    // 0x18e9c4: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18e9c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18e9c8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18e9c8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18e9cc: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x18e9ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x18e9d0: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x18e9d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_18e9d4:
    // 0x18e9d4: 0xc5010004  lwc1        $f1, 0x4($t0)
    ctx->pc = 0x18e9d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18e9d8: 0x460c0832  c.eq.s      $f1, $f12
    ctx->pc = 0x18e9d8u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[1], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18e9dc: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x18E9DCu;
    {
        const bool branch_taken_0x18e9dc = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18e9dc) {
            ctx->pc = 0x18E9F4u;
            goto label_18e9f4;
        }
    }
    ctx->pc = 0x18E9E4u;
    // 0x18e9e4: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18e9e4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18e9e8: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18e9e8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e9ec: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x18E9ECu;
    {
        const bool branch_taken_0x18e9ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E9F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E9ECu;
            // 0x18e9f0: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e9ec) {
            ctx->pc = 0x18EA54u;
            goto label_18ea54;
        }
    }
    ctx->pc = 0x18E9F4u;
label_18e9f4:
    // 0x18e9f4: 0x460c0834  c.lt.s      $f1, $f12
    ctx->pc = 0x18e9f4u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18e9f8: 0x4500000a  bc1f        . + 4 + (0xA << 2)
    ctx->pc = 0x18E9F8u;
    {
        const bool branch_taken_0x18e9f8 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18e9f8) {
            ctx->pc = 0x18EA24u;
            goto label_18ea24;
        }
    }
    ctx->pc = 0x18EA00u;
    // 0x18ea00: 0xc500000c  lwc1        $f0, 0xC($t0)
    ctx->pc = 0x18ea00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 8), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ea04: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18ea04u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ea08: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18EA08u;
    {
        const bool branch_taken_0x18ea08 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ea08) {
            ctx->pc = 0x18EA24u;
            goto label_18ea24;
        }
    }
    ctx->pc = 0x18EA10u;
    // 0x18ea10: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18ea10u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18ea14: 0x25020008  addiu       $v0, $t0, 0x8
    ctx->pc = 0x18ea14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
    // 0x18ea18: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x18ea18u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x18ea1c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x18EA1Cu;
    {
        const bool branch_taken_0x18ea1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EA1Cu;
            // 0x18ea20: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ea1c) {
            ctx->pc = 0x18EA54u;
            goto label_18ea54;
        }
    }
    ctx->pc = 0x18EA24u;
label_18ea24:
    // 0x18ea24: 0x46016034  c.lt.s      $f12, $f1
    ctx->pc = 0x18ea24u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ea28: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18EA28u;
    {
        const bool branch_taken_0x18ea28 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18EA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EA28u;
            // 0x18ea2c: 0x24e20001  addiu       $v0, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ea28) {
            ctx->pc = 0x18EA44u;
            goto label_18ea44;
        }
    }
    ctx->pc = 0x18EA30u;
    // 0x18ea30: 0x24e2ffff  addiu       $v0, $a3, -0x1
    ctx->pc = 0x18ea30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x18ea34: 0x2508fff8  addiu       $t0, $t0, -0x8
    ctx->pc = 0x18ea34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967288));
    // 0x18ea38: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ea38u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ea3c: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x18EA3Cu;
    {
        const bool branch_taken_0x18ea3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EA40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EA3Cu;
            // 0x18ea40: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ea3c) {
            ctx->pc = 0x18E9D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18e9d4;
        }
    }
    ctx->pc = 0x18EA44u;
label_18ea44:
    // 0x18ea44: 0x25080008  addiu       $t0, $t0, 0x8
    ctx->pc = 0x18ea44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
    // 0x18ea48: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ea48u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ea4c: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x18EA4Cu;
    {
        const bool branch_taken_0x18ea4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EA50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EA4Cu;
            // 0x18ea50: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ea4c) {
            ctx->pc = 0x18E9D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18e9d4;
        }
    }
    ctx->pc = 0x18EA54u;
label_18ea54:
    // 0x18ea54: 0x3e00008  jr          $ra
    ctx->pc = 0x18EA54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E948u: goto label_18e948;
            case 0x18E958u: goto label_18e958;
            case 0x18E994u: goto label_18e994;
            case 0x18E9ACu: goto label_18e9ac;
            case 0x18E9C4u: goto label_18e9c4;
            case 0x18E9D4u: goto label_18e9d4;
            case 0x18E9F4u: goto label_18e9f4;
            case 0x18EA24u: goto label_18ea24;
            case 0x18EA44u: goto label_18ea44;
            case 0x18EA54u: goto label_18ea54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18EA5Cu;
    // 0x18ea5c: 0x0  nop
    ctx->pc = 0x18ea5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

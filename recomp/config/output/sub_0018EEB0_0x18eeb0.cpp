#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018EEB0
// Address: 0x18eeb0 - 0x18f040
void sub_0018EEB0_0x18eeb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018EEB0_0x18eeb0");
#endif

    switch (ctx->pc) {
        case 0x18ef8cu: goto label_18ef8c;
        default: break;
    }

    ctx->pc = 0x18eeb0u;

    // 0x18eeb0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18eeb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18eeb4: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x18eeb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x18eeb8: 0x8c224160  lw          $v0, 0x4160($at)
    ctx->pc = 0x18eeb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16736)));
    // 0x18eebc: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x18eebcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x18eec0: 0x624021  addu        $t0, $v1, $v0
    ctx->pc = 0x18eec0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18eec4: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18eec4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18eec8: 0x85020002  lh          $v0, 0x2($t0)
    ctx->pc = 0x18eec8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x18eecc: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18eeccu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18eed0: 0x0  nop
    ctx->pc = 0x18eed0u;
    // NOP
    // 0x18eed4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18eed4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18eed8: 0x46006036  c.le.s      $f12, $f0
    ctx->pc = 0x18eed8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18eedc: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x18EEDCu;
    {
        const bool branch_taken_0x18eedc = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18eedc) {
            ctx->pc = 0x18EEF4u;
            goto label_18eef4;
        }
    }
    ctx->pc = 0x18EEE4u;
    // 0x18eee4: 0x94830002  lhu         $v1, 0x2($a0)
    ctx->pc = 0x18eee4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18eee8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18eee8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18eeec: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18EEECu;
    {
        const bool branch_taken_0x18eeec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18EEF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EEECu;
            // 0x18eef0: 0x310c0  sll         $v0, $v1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eeec) {
            ctx->pc = 0x18EF04u;
            goto label_18ef04;
        }
    }
    ctx->pc = 0x18EEF4u;
label_18eef4:
    // 0x18eef4: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18eef4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18eef8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18eef8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18eefc: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x18EEFCu;
    {
        const bool branch_taken_0x18eefc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EEFCu;
            // 0x18ef00: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18eefc) {
            ctx->pc = 0x18F030u;
            goto label_18f030;
        }
    }
    ctx->pc = 0x18EF04u;
label_18ef04:
    // 0x18ef04: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x18ef04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x18ef08: 0x8442fffa  lh          $v0, -0x6($v0)
    ctx->pc = 0x18ef08u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294967290)));
    // 0x18ef0c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18ef0cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18ef10: 0x0  nop
    ctx->pc = 0x18ef10u;
    // NOP
    // 0x18ef14: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18ef14u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18ef18: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18ef18u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18ef1c: 0x4501000b  bc1t        . + 4 + (0xB << 2)
    ctx->pc = 0x18EF1Cu;
    {
        const bool branch_taken_0x18ef1c = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x18ef1c) {
            ctx->pc = 0x18EF4Cu;
            goto label_18ef4c;
        }
    }
    ctx->pc = 0x18EF24u;
    // 0x18ef24: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18ef24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18ef28: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x18ef28u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x18ef2c: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x18ef2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x18ef30: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x18ef30u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x18ef34: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18ef34u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x18ef38: 0x94820002  lhu         $v0, 0x2($a0)
    ctx->pc = 0x18ef38u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x18ef3c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18ef3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18ef40: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x18ef40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ef44: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x18EF44u;
    {
        const bool branch_taken_0x18ef44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EF44u;
            // 0x18ef48: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ef44) {
            ctx->pc = 0x18F030u;
            goto label_18f030;
        }
    }
    ctx->pc = 0x18EF4Cu;
label_18ef4c:
    // 0x18ef4c: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18ef4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18ef50: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18ef50u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18ef54: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18EF54u;
    {
        const bool branch_taken_0x18ef54 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x18ef54) {
            ctx->pc = 0x18EF64u;
            goto label_18ef64;
        }
    }
    ctx->pc = 0x18EF5Cu;
    // 0x18ef5c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x18EF5Cu;
    {
        const bool branch_taken_0x18ef5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EF60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EF5Cu;
            // 0x18ef60: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18ef5c) {
            ctx->pc = 0x18EF7Cu;
            goto label_18ef7c;
        }
    }
    ctx->pc = 0x18EF64u;
label_18ef64:
    // 0x18ef64: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x18ef64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x18ef68: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18EF68u;
    {
        const bool branch_taken_0x18ef68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18ef68) {
            ctx->pc = 0x18EF7Cu;
            goto label_18ef7c;
        }
    }
    ctx->pc = 0x18EF70u;
    // 0x18ef70: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x18ef70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18ef74: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18ef74u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ef78: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x18ef78u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
label_18ef7c:
    // 0x18ef7c: 0x7143c  dsll32      $v0, $a3, 16
    ctx->pc = 0x18ef7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) << (32 + 16));
    // 0x18ef80: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x18ef80u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18ef84: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x18ef84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x18ef88: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x18ef88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_18ef8c:
    // 0x18ef8c: 0x85030002  lh          $v1, 0x2($t0)
    ctx->pc = 0x18ef8cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x18ef90: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18ef90u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18ef94: 0x0  nop
    ctx->pc = 0x18ef94u;
    // NOP
    // 0x18ef98: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18ef98u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18ef9c: 0x460c0032  c.eq.s      $f0, $f12
    ctx->pc = 0x18ef9cu;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18efa0: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x18EFA0u;
    {
        const bool branch_taken_0x18efa0 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18efa0) {
            ctx->pc = 0x18EFB8u;
            goto label_18efb8;
        }
    }
    ctx->pc = 0x18EFA8u;
    // 0x18efa8: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18efa8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18efac: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18efacu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18efb0: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x18EFB0u;
    {
        const bool branch_taken_0x18efb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EFB0u;
            // 0x18efb4: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18efb0) {
            ctx->pc = 0x18F030u;
            goto label_18f030;
        }
    }
    ctx->pc = 0x18EFB8u;
label_18efb8:
    // 0x18efb8: 0x460c0034  c.lt.s      $f0, $f12
    ctx->pc = 0x18efb8u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18efbc: 0x4500000d  bc1f        . + 4 + (0xD << 2)
    ctx->pc = 0x18EFBCu;
    {
        const bool branch_taken_0x18efbc = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18efbc) {
            ctx->pc = 0x18EFF4u;
            goto label_18eff4;
        }
    }
    ctx->pc = 0x18EFC4u;
    // 0x18efc4: 0x8502000a  lh          $v0, 0xA($t0)
    ctx->pc = 0x18efc4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 10)));
    // 0x18efc8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18efc8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18efcc: 0x0  nop
    ctx->pc = 0x18efccu;
    // NOP
    // 0x18efd0: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18efd0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18efd4: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18efd4u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18efd8: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18EFD8u;
    {
        const bool branch_taken_0x18efd8 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x18efd8) {
            ctx->pc = 0x18EFF4u;
            goto label_18eff4;
        }
    }
    ctx->pc = 0x18EFE0u;
    // 0x18efe0: 0xaca80000  sw          $t0, 0x0($a1)
    ctx->pc = 0x18efe0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 8));
    // 0x18efe4: 0x25020008  addiu       $v0, $t0, 0x8
    ctx->pc = 0x18efe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
    // 0x18efe8: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x18efe8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x18efec: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x18EFECu;
    {
        const bool branch_taken_0x18efec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18EFF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18EFECu;
            // 0x18eff0: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18efec) {
            ctx->pc = 0x18F030u;
            goto label_18f030;
        }
    }
    ctx->pc = 0x18EFF4u;
label_18eff4:
    // 0x18eff4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18eff4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18eff8: 0x0  nop
    ctx->pc = 0x18eff8u;
    // NOP
    // 0x18effc: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x18effcu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x18f000: 0x46006034  c.lt.s      $f12, $f0
    ctx->pc = 0x18f000u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[12], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x18f004: 0x45000006  bc1f        . + 4 + (0x6 << 2)
    ctx->pc = 0x18F004u;
    {
        const bool branch_taken_0x18f004 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x18F008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F004u;
            // 0x18f008: 0x24e20001  addiu       $v0, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f004) {
            ctx->pc = 0x18F020u;
            goto label_18f020;
        }
    }
    ctx->pc = 0x18F00Cu;
    // 0x18f00c: 0x24e2ffff  addiu       $v0, $a3, -0x1
    ctx->pc = 0x18f00cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x18f010: 0x2508fff8  addiu       $t0, $t0, -0x8
    ctx->pc = 0x18f010u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967288));
    // 0x18f014: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18f014u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18f018: 0x1000ffdc  b           . + 4 + (-0x24 << 2)
    ctx->pc = 0x18F018u;
    {
        const bool branch_taken_0x18f018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F01Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F018u;
            // 0x18f01c: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f018) {
            ctx->pc = 0x18EF8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18ef8c;
        }
    }
    ctx->pc = 0x18F020u;
label_18f020:
    // 0x18f020: 0x25080008  addiu       $t0, $t0, 0x8
    ctx->pc = 0x18f020u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
    // 0x18f024: 0x23c3c  dsll32      $a3, $v0, 16
    ctx->pc = 0x18f024u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18f028: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x18F028u;
    {
        const bool branch_taken_0x18f028 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18F02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F028u;
            // 0x18f02c: 0x73c3f  dsra32      $a3, $a3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18f028) {
            ctx->pc = 0x18EF8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18ef8c;
        }
    }
    ctx->pc = 0x18F030u;
label_18f030:
    // 0x18f030: 0x3e00008  jr          $ra
    ctx->pc = 0x18F030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18EEF4u: goto label_18eef4;
            case 0x18EF04u: goto label_18ef04;
            case 0x18EF4Cu: goto label_18ef4c;
            case 0x18EF64u: goto label_18ef64;
            case 0x18EF7Cu: goto label_18ef7c;
            case 0x18EF8Cu: goto label_18ef8c;
            case 0x18EFB8u: goto label_18efb8;
            case 0x18EFF4u: goto label_18eff4;
            case 0x18F020u: goto label_18f020;
            case 0x18F030u: goto label_18f030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F038u;
    // 0x18f038: 0x0  nop
    ctx->pc = 0x18f038u;
    // NOP
    // 0x18f03c: 0x0  nop
    ctx->pc = 0x18f03cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010CB48
// Address: 0x10cb48 - 0x10cd74
void sub_0010CB48_0x10cb48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010CB48_0x10cb48");
#endif

    switch (ctx->pc) {
        case 0x10cb90u: goto label_10cb90;
        case 0x10cc50u: goto label_10cc50;
        case 0x10cc64u: goto label_10cc64;
        case 0x10cc78u: goto label_10cc78;
        case 0x10ccb8u: goto label_10ccb8;
        default: break;
    }

    ctx->pc = 0x10cb48u;

    // 0x10cb48: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x10cb48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x10cb4c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x10cb4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x10cb50: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x10cb50u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cb54: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x10cb54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x10cb58: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x10cb58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x10cb5c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x10cb5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x10cb60: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x10cb60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x10cb64: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x10cb64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x10cb68: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x10cb68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x10cb6c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x10cb6cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x10cb70: 0xafa00004  sw          $zero, 0x4($sp)
    ctx->pc = 0x10cb70u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
    // 0x10cb74: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x10cb74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x10cb78: 0x2a0902d  daddu       $s2, $s5, $zero
    ctx->pc = 0x10cb78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cb7c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x10cb7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x10cb80: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x10cb80u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cb84: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x10cb84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x10cb88: 0xc0f02d  daddu       $fp, $a2, $zero
    ctx->pc = 0x10cb88u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cb8c: 0x0  nop
    ctx->pc = 0x10cb8cu;
    // NOP
label_10cb90:
    // 0x10cb90: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10cb90u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10cb94: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10cb94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10cb98: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x10cb98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x10cb9c: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10cb9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10cba0: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x10cba0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x10cba4: 0x0  nop
    ctx->pc = 0x10cba4u;
    // NOP
    // 0x10cba8: 0x0  nop
    ctx->pc = 0x10cba8u;
    // NOP
    // 0x10cbac: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10CBACu;
    {
        const bool branch_taken_0x10cbac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10CBB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CBACu;
            // 0x10cbb0: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cbac) {
            ctx->pc = 0x10CB90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10cb90;
        }
    }
    ctx->pc = 0x10CBB4u;
    // 0x10cbb4: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x10cbb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10cbb8: 0x16220007  bne         $s1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10CBB8u;
    {
        const bool branch_taken_0x10cbb8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10CBBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CBB8u;
            // 0x10cbbc: 0x2402002b  addiu       $v0, $zero, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cbb8) {
            ctx->pc = 0x10CBD8u;
            goto label_10cbd8;
        }
    }
    ctx->pc = 0x10CBC0u;
    // 0x10cbc0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10cbc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10cbc4: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10cbc4u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10cbc8: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10cbc8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x10cbcc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10CBCCu;
    {
        const bool branch_taken_0x10cbcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CBD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CBCCu;
            // 0x10cbd0: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cbcc) {
            ctx->pc = 0x10CBE8u;
            goto label_10cbe8;
        }
    }
    ctx->pc = 0x10CBD4u;
    // 0x10cbd4: 0x0  nop
    ctx->pc = 0x10cbd4u;
    // NOP
label_10cbd8:
    // 0x10cbd8: 0x16220003  bne         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CBD8u;
    {
        const bool branch_taken_0x10cbd8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x10cbd8) {
            ctx->pc = 0x10CBE8u;
            goto label_10cbe8;
        }
    }
    ctx->pc = 0x10CBE0u;
    // 0x10cbe0: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10cbe0u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10cbe4: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10cbe4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_10cbe8:
    // 0x10cbe8: 0x12600003  beqz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CBE8u;
    {
        const bool branch_taken_0x10cbe8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CBECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CBE8u;
            // 0x10cbec: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cbe8) {
            ctx->pc = 0x10CBF8u;
            goto label_10cbf8;
        }
    }
    ctx->pc = 0x10CBF0u;
    // 0x10cbf0: 0x1662000c  bne         $s3, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x10CBF0u;
    {
        const bool branch_taken_0x10cbf0 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        if (branch_taken_0x10cbf0) {
            ctx->pc = 0x10CC24u;
            goto label_10cc24;
        }
    }
    ctx->pc = 0x10CBF8u;
label_10cbf8:
    // 0x10cbf8: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x10cbf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10cbfc: 0x16220009  bne         $s1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10CBFCu;
    {
        const bool branch_taken_0x10cbfc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10CC00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CBFCu;
            // 0x10cc00: 0x24020078  addiu       $v0, $zero, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cbfc) {
            ctx->pc = 0x10CC24u;
            goto label_10cc24;
        }
    }
    ctx->pc = 0x10CC04u;
    // 0x10cc04: 0x82430000  lb          $v1, 0x0($s2)
    ctx->pc = 0x10cc04u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10cc08: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CC08u;
    {
        const bool branch_taken_0x10cc08 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x10CC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC08u;
            // 0x10cc0c: 0x24020058  addiu       $v0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cc08) {
            ctx->pc = 0x10CC18u;
            goto label_10cc18;
        }
    }
    ctx->pc = 0x10CC10u;
    // 0x10cc10: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10CC10u;
    {
        const bool branch_taken_0x10cc10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x10cc10) {
            ctx->pc = 0x10CC24u;
            goto label_10cc24;
        }
    }
    ctx->pc = 0x10CC18u;
label_10cc18:
    // 0x10cc18: 0x82510001  lb          $s1, 0x1($s2)
    ctx->pc = 0x10cc18u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0x10cc1c: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x10cc1cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x10cc20: 0x24130010  addiu       $s3, $zero, 0x10
    ctx->pc = 0x10cc20u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_10cc24:
    // 0x10cc24: 0x56600006  bnel        $s3, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10CC24u;
    {
        const bool branch_taken_0x10cc24 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x10cc24) {
            ctx->pc = 0x10CC28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC24u;
            // 0x10cc28: 0x260802d  daddu       $s0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10CC40u;
            goto label_10cc40;
        }
    }
    ctx->pc = 0x10CC2Cu;
    // 0x10cc2c: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x10cc2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x10cc30: 0x24130008  addiu       $s3, $zero, 0x8
    ctx->pc = 0x10cc30u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x10cc34: 0x3a220030  xori        $v0, $s1, 0x30
    ctx->pc = 0x10cc34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) ^ (uint64_t)(uint16_t)48);
    // 0x10cc38: 0x62980b  movn        $s3, $v1, $v0
    ctx->pc = 0x10cc38u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
    // 0x10cc3c: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x10cc3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_10cc40:
    // 0x10cc40: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x10cc40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10cc44: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10cc44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cc48: 0xc044210  jal         func_110840
    ctx->pc = 0x10CC48u;
    SET_GPR_U32(ctx, 31, 0x10CC50u);
    ctx->pc = 0x10CC4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC48u;
            // 0x10cc4c: 0x200b82d  daddu       $s7, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110840u;
    if (runtime->hasFunction(0x110840u)) {
        auto targetFn = runtime->lookupFunction(0x110840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CC50u; }
        if (ctx->pc != 0x10CC50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110840_0x110840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CC50u; }
        if (ctx->pc != 0x10CC50u) { return; }
    }
    ctx->pc = 0x10CC50u;
label_10cc50:
    // 0x10cc50: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x10cc50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10cc54: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10cc54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cc58: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x10cc58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cc5c: 0xc044370  jal         func_110DC0
    ctx->pc = 0x10CC5Cu;
    SET_GPR_U32(ctx, 31, 0x10CC64u);
    ctx->pc = 0x10CC60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC5Cu;
            // 0x10cc60: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110DC0u;
    if (runtime->hasFunction(0x110DC0u)) {
        auto targetFn = runtime->lookupFunction(0x110DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CC64u; }
        if (ctx->pc != 0x10CC64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110DC0_0x110dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CC64u; }
        if (ctx->pc != 0x10CC64u) { return; }
    }
    ctx->pc = 0x10CC64u;
label_10cc64:
    // 0x10cc64: 0x2b03c  dsll32      $s6, $v0, 0
    ctx->pc = 0x10cc64u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10cc68: 0x16b03f  dsra32      $s6, $s6, 0
    ctx->pc = 0x10cc68u;
    SET_GPR_S64(ctx, 22, GPR_S64(ctx, 22) >> (32 + 0));
    // 0x10cc6c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x10CC6Cu;
    {
        const bool branch_taken_0x10cc6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CC70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC6Cu;
            // 0x10cc70: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cc6c) {
            ctx->pc = 0x10CCC8u;
            goto label_10ccc8;
        }
    }
    ctx->pc = 0x10CC74u;
    // 0x10cc74: 0x0  nop
    ctx->pc = 0x10cc74u;
    // NOP
label_10cc78:
    // 0x10cc78: 0x233102a  slt         $v0, $s1, $s3
    ctx->pc = 0x10cc78u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x10cc7c: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x10CC7Cu;
    {
        const bool branch_taken_0x10cc7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10cc7c) {
            ctx->pc = 0x10CD08u;
            goto label_10cd08;
        }
    }
    ctx->pc = 0x10CC84u;
    // 0x10cc84: 0x6000008  bltz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10CC84u;
    {
        const bool branch_taken_0x10cc84 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x10CC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC84u;
            // 0x10cc88: 0x285102b  sltu        $v0, $s4, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cc84) {
            ctx->pc = 0x10CCA8u;
            goto label_10cca8;
        }
    }
    ctx->pc = 0x10CC8Cu;
    // 0x10cc8c: 0x5440000c  bnel        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x10CC8Cu;
    {
        const bool branch_taken_0x10cc8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10cc8c) {
            ctx->pc = 0x10CC90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC8Cu;
            // 0x10cc90: 0x2410ffff  addiu       $s0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10CCC0u;
            goto label_10ccc0;
        }
    }
    ctx->pc = 0x10CC94u;
    // 0x10cc94: 0x14b40006  bne         $a1, $s4, . + 4 + (0x6 << 2)
    ctx->pc = 0x10CC94u;
    {
        const bool branch_taken_0x10cc94 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 20));
        ctx->pc = 0x10CC98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CC94u;
            // 0x10cc98: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cc94) {
            ctx->pc = 0x10CCB0u;
            goto label_10ccb0;
        }
    }
    ctx->pc = 0x10CC9Cu;
    // 0x10cc9c: 0x2d1102a  slt         $v0, $s6, $s1
    ctx->pc = 0x10cc9cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x10cca0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CCA0u;
    {
        const bool branch_taken_0x10cca0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10cca0) {
            ctx->pc = 0x10CCB0u;
            goto label_10ccb0;
        }
    }
    ctx->pc = 0x10CCA8u;
label_10cca8:
    // 0x10cca8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10CCA8u;
    {
        const bool branch_taken_0x10cca8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CCACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CCA8u;
            // 0x10ccac: 0x2410ffff  addiu       $s0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cca8) {
            ctx->pc = 0x10CCC0u;
            goto label_10ccc0;
        }
    }
    ctx->pc = 0x10CCB0u;
label_10ccb0:
    // 0x10ccb0: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x10CCB0u;
    SET_GPR_U32(ctx, 31, 0x10CCB8u);
    ctx->pc = 0x10CCB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CCB0u;
            // 0x10ccb4: 0x2e0282d  daddu       $a1, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CCB8u; }
        if (ctx->pc != 0x10CCB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CCB8u; }
        if (ctx->pc != 0x10CCB8u) { return; }
    }
    ctx->pc = 0x10CCB8u;
label_10ccb8:
    // 0x10ccb8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x10ccb8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10ccbc: 0x222282d  daddu       $a1, $s1, $v0
    ctx->pc = 0x10ccbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 2));
label_10ccc0:
    // 0x10ccc0: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10ccc0u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10ccc4: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10ccc4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_10ccc8:
    // 0x10ccc8: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x10ccc8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x10cccc: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x10ccccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x10ccd0: 0x90847769  lbu         $a0, 0x7769($a0)
    ctx->pc = 0x10ccd0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30569)));
    // 0x10ccd4: 0x30820004  andi        $v0, $a0, 0x4
    ctx->pc = 0x10ccd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4);
    // 0x10ccd8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CCD8u;
    {
        const bool branch_taken_0x10ccd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CCDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CCD8u;
            // 0x10ccdc: 0x30820003  andi        $v0, $a0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ccd8) {
            ctx->pc = 0x10CCE8u;
            goto label_10cce8;
        }
    }
    ctx->pc = 0x10CCE0u;
    // 0x10cce0: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x10CCE0u;
    {
        const bool branch_taken_0x10cce0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CCE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CCE0u;
            // 0x10cce4: 0x2631ffd0  addiu       $s1, $s1, -0x30 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967248));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cce0) {
            ctx->pc = 0x10CC78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10cc78;
        }
    }
    ctx->pc = 0x10CCE8u;
label_10cce8:
    // 0x10cce8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10CCE8u;
    {
        const bool branch_taken_0x10cce8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CCECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CCE8u;
            // 0x10ccec: 0x2622ffc9  addiu       $v0, $s1, -0x37 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967241));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cce8) {
            ctx->pc = 0x10CD08u;
            goto label_10cd08;
        }
    }
    ctx->pc = 0x10CCF0u;
    // 0x10ccf0: 0x2623ffa9  addiu       $v1, $s1, -0x57
    ctx->pc = 0x10ccf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967209));
    // 0x10ccf4: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x10ccf4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x10ccf8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10ccf8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ccfc: 0x1000ffde  b           . + 4 + (-0x22 << 2)
    ctx->pc = 0x10CCFCu;
    {
        const bool branch_taken_0x10ccfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CD00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CCFCu;
            // 0x10cd00: 0x64880a  movz        $s1, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ccfc) {
            ctx->pc = 0x10CC78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10cc78;
        }
    }
    ctx->pc = 0x10CD04u;
    // 0x10cd04: 0x0  nop
    ctx->pc = 0x10cd04u;
    // NOP
label_10cd08:
    // 0x10cd08: 0x6010007  bgez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10CD08u;
    {
        const bool branch_taken_0x10cd08 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x10CD0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CD08u;
            // 0x10cd0c: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cd08) {
            ctx->pc = 0x10CD28u;
            goto label_10cd28;
        }
    }
    ctx->pc = 0x10CD10u;
    // 0x10cd10: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x10cd10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10cd14: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x10cd14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x10cd18: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x10cd18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10cd1c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10CD1Cu;
    {
        const bool branch_taken_0x10cd1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CD1Cu;
            // 0x10cd20: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cd1c) {
            ctx->pc = 0x10CD30u;
            goto label_10cd30;
        }
    }
    ctx->pc = 0x10CD24u;
    // 0x10cd24: 0x0  nop
    ctx->pc = 0x10cd24u;
    // NOP
label_10cd28:
    // 0x10cd28: 0x5102f  dsubu       $v0, $zero, $a1
    ctx->pc = 0x10cd28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) - GPR_U64(ctx, 5));
    // 0x10cd2c: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x10cd2cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
label_10cd30:
    // 0x10cd30: 0x13c00003  beqz        $fp, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CD30u;
    {
        const bool branch_taken_0x10cd30 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CD34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CD30u;
            // 0x10cd34: 0x2642ffff  addiu       $v0, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cd30) {
            ctx->pc = 0x10CD40u;
            goto label_10cd40;
        }
    }
    ctx->pc = 0x10CD38u;
    // 0x10cd38: 0x50a80b  movn        $s5, $v0, $s0
    ctx->pc = 0x10cd38u;
    if (GPR_U64(ctx, 16) != 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 2));
    // 0x10cd3c: 0xafd50000  sw          $s5, 0x0($fp)
    ctx->pc = 0x10cd3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 21));
label_10cd40:
    // 0x10cd40: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x10cd40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10cd44: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x10cd44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10cd48: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x10cd48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10cd4c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x10cd4cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10cd50: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x10cd50u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10cd54: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x10cd54u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10cd58: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x10cd58u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10cd5c: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x10cd5cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x10cd60: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x10cd60u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x10cd64: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x10cd64u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x10cd68: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x10cd68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x10cd6c: 0x3e00008  jr          $ra
    ctx->pc = 0x10CD6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10CD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CD6Cu;
            // 0x10cd70: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10CB90u: goto label_10cb90;
            case 0x10CBD8u: goto label_10cbd8;
            case 0x10CBE8u: goto label_10cbe8;
            case 0x10CBF8u: goto label_10cbf8;
            case 0x10CC18u: goto label_10cc18;
            case 0x10CC24u: goto label_10cc24;
            case 0x10CC40u: goto label_10cc40;
            case 0x10CC50u: goto label_10cc50;
            case 0x10CC64u: goto label_10cc64;
            case 0x10CC78u: goto label_10cc78;
            case 0x10CCA8u: goto label_10cca8;
            case 0x10CCB0u: goto label_10ccb0;
            case 0x10CCB8u: goto label_10ccb8;
            case 0x10CCC0u: goto label_10ccc0;
            case 0x10CCC8u: goto label_10ccc8;
            case 0x10CCE8u: goto label_10cce8;
            case 0x10CD08u: goto label_10cd08;
            case 0x10CD28u: goto label_10cd28;
            case 0x10CD30u: goto label_10cd30;
            case 0x10CD40u: goto label_10cd40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10CD74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010EAF0
// Address: 0x10eaf0 - 0x10f780
void sub_0010EAF0_0x10eaf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010EAF0_0x10eaf0");
#endif

    switch (ctx->pc) {
        case 0x10eb38u: goto label_10eb38;
        case 0x10eb3cu: goto label_10eb3c;
        case 0x10eb78u: goto label_10eb78;
        case 0x10eba4u: goto label_10eba4;
        case 0x10ebe8u: goto label_10ebe8;
        case 0x10ec18u: goto label_10ec18;
        case 0x10ec30u: goto label_10ec30;
        case 0x10ed48u: goto label_10ed48;
        case 0x10ee30u: goto label_10ee30;
        case 0x10ee50u: goto label_10ee50;
        case 0x10ee7cu: goto label_10ee7c;
        case 0x10eee0u: goto label_10eee0;
        case 0x10ef10u: goto label_10ef10;
        case 0x10ef68u: goto label_10ef68;
        case 0x10efa0u: goto label_10efa0;
        case 0x10efa4u: goto label_10efa4;
        case 0x10efe8u: goto label_10efe8;
        case 0x10f018u: goto label_10f018;
        case 0x10f01cu: goto label_10f01c;
        case 0x10f06cu: goto label_10f06c;
        case 0x10f0b8u: goto label_10f0b8;
        case 0x10f0bcu: goto label_10f0bc;
        case 0x10f10cu: goto label_10f10c;
        case 0x10f130u: goto label_10f130;
        case 0x10f134u: goto label_10f134;
        case 0x10f190u: goto label_10f190;
        case 0x10f1e0u: goto label_10f1e0;
        case 0x10f304u: goto label_10f304;
        case 0x10f340u: goto label_10f340;
        case 0x10f36cu: goto label_10f36c;
        case 0x10f3a0u: goto label_10f3a0;
        case 0x10f470u: goto label_10f470;
        case 0x10f578u: goto label_10f578;
        case 0x10f5c0u: goto label_10f5c0;
        case 0x10f5ccu: goto label_10f5cc;
        case 0x10f618u: goto label_10f618;
        case 0x10f63cu: goto label_10f63c;
        case 0x10f690u: goto label_10f690;
        case 0x10f6c8u: goto label_10f6c8;
        case 0x10f6dcu: goto label_10f6dc;
        case 0x10f720u: goto label_10f720;
        default: break;
    }

    ctx->pc = 0x10eaf0u;

    // 0x10eaf0: 0x27bdfd10  addiu       $sp, $sp, -0x2F0
    ctx->pc = 0x10eaf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966544));
    // 0x10eaf4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x10eaf4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10eaf8: 0xffb002a0  sd          $s0, 0x2A0($sp)
    ctx->pc = 0x10eaf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 672), GPR_U64(ctx, 16));
    // 0x10eafc: 0xffb102a8  sd          $s1, 0x2A8($sp)
    ctx->pc = 0x10eafcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 680), GPR_U64(ctx, 17));
    // 0x10eb00: 0xffb302b8  sd          $s3, 0x2B8($sp)
    ctx->pc = 0x10eb00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 696), GPR_U64(ctx, 19));
    // 0x10eb04: 0xffb402c0  sd          $s4, 0x2C0($sp)
    ctx->pc = 0x10eb04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 704), GPR_U64(ctx, 20));
    // 0x10eb08: 0xffb602d0  sd          $s6, 0x2D0($sp)
    ctx->pc = 0x10eb08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 720), GPR_U64(ctx, 22));
    // 0x10eb0c: 0xffbf02e8  sd          $ra, 0x2E8($sp)
    ctx->pc = 0x10eb0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 744), GPR_U64(ctx, 31));
    // 0x10eb10: 0xafa00264  sw          $zero, 0x264($sp)
    ctx->pc = 0x10eb10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 612), GPR_U32(ctx, 0));
    // 0x10eb14: 0xafa00260  sw          $zero, 0x260($sp)
    ctx->pc = 0x10eb14u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 608), GPR_U32(ctx, 0));
    // 0x10eb18: 0xffb202b0  sd          $s2, 0x2B0($sp)
    ctx->pc = 0x10eb18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 688), GPR_U64(ctx, 18));
    // 0x10eb1c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x10eb1cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10eb20: 0xffb502c8  sd          $s5, 0x2C8($sp)
    ctx->pc = 0x10eb20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 712), GPR_U64(ctx, 21));
    // 0x10eb24: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x10eb24u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10eb28: 0xffb702d8  sd          $s7, 0x2D8($sp)
    ctx->pc = 0x10eb28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 728), GPR_U64(ctx, 23));
    // 0x10eb2c: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x10eb2cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10eb30: 0xffbe02e0  sd          $fp, 0x2E0($sp)
    ctx->pc = 0x10eb30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 736), GPR_U64(ctx, 30));
    // 0x10eb34: 0xf02d  daddu       $fp, $zero, $zero
    ctx->pc = 0x10eb34u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10eb38:
    // 0x10eb38: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x10eb38u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
label_10eb3c:
    // 0x10eb3c: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x10eb3cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x10eb40: 0x10600302  beqz        $v1, . + 4 + (0x302 << 2)
    ctx->pc = 0x10EB40u;
    {
        const bool branch_taken_0x10eb40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EB40u;
            // 0x10eb44: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eb40) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10EB48u;
    // 0x10eb48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10eb48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10eb4c: 0x14420022  bne         $v0, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x10EB4Cu;
    {
        const bool branch_taken_0x10eb4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 2));
        ctx->pc = 0x10EB50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EB4Cu;
            // 0x10eb50: 0x24020025  addiu       $v0, $zero, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eb4c) {
            ctx->pc = 0x10EBD8u;
            goto label_10ebd8;
        }
    }
    ctx->pc = 0x10EB54u;
    // 0x10eb54: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10eb54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10eb58: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10eb58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10eb5c: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10eb5cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10eb60: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x10eb60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x10eb64: 0x5040001c  beql        $v0, $zero, . + 4 + (0x1C << 2)
    ctx->pc = 0x10EB64u;
    {
        const bool branch_taken_0x10eb64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10eb64) {
            ctx->pc = 0x10EB68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EB64u;
            // 0x10eb68: 0x24020025  addiu       $v0, $zero, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EBD8u;
            goto label_10ebd8;
        }
    }
    ctx->pc = 0x10EB6Cu;
    // 0x10eb6c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10EB6Cu;
    {
        const bool branch_taken_0x10eb6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EB70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EB6Cu;
            // 0x10eb70: 0x8e420004  lw          $v0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eb6c) {
            ctx->pc = 0x10EB90u;
            goto label_10eb90;
        }
    }
    ctx->pc = 0x10EB74u;
    // 0x10eb74: 0x0  nop
    ctx->pc = 0x10eb74u;
    // NOP
label_10eb78:
    // 0x10eb78: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x10eb78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10eb7c: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x10eb7cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x10eb80: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x10eb80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x10eb84: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x10eb84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x10eb88: 0xae430004  sw          $v1, 0x4($s2)
    ctx->pc = 0x10eb88u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
    // 0x10eb8c: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10eb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_10eb90:
    // 0x10eb90: 0x5c400007  bgtzl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10EB90u;
    {
        const bool branch_taken_0x10eb90 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x10eb90) {
            ctx->pc = 0x10EB94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EB90u;
            // 0x10eb94: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EBB0u;
            goto label_10ebb0;
        }
    }
    ctx->pc = 0x10EB98u;
    // 0x10eb98: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10eb98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10eb9c: 0xc042814  jal         func_10A050
    ctx->pc = 0x10EB9Cu;
    SET_GPR_U32(ctx, 31, 0x10EBA4u);
    ctx->pc = 0x10EBA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10EB9Cu;
            // 0x10eba0: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EBA4u; }
        if (ctx->pc != 0x10EBA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EBA4u; }
        if (ctx->pc != 0x10EBA4u) { return; }
    }
    ctx->pc = 0x10EBA4u;
label_10eba4:
    // 0x10eba4: 0x144002e8  bnez        $v0, . + 4 + (0x2E8 << 2)
    ctx->pc = 0x10EBA4u;
    {
        const bool branch_taken_0x10eba4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10EBA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EBA4u;
            // 0x10eba8: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eba4) {
            ctx->pc = 0x10F748u;
            goto label_10f748;
        }
    }
    ctx->pc = 0x10EBACu;
    // 0x10ebac: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x10ebacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10ebb0:
    // 0x10ebb0: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x10ebb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10ebb4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10ebb4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10ebb8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10ebb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10ebbc: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10ebbcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10ebc0: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x10ebc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x10ebc4: 0x5440ffec  bnel        $v0, $zero, . + 4 + (-0x14 << 2)
    ctx->pc = 0x10EBC4u;
    {
        const bool branch_taken_0x10ebc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ebc4) {
            ctx->pc = 0x10EBC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EBC4u;
            // 0x10ebc8: 0x8e430004  lw          $v1, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EB78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb78;
        }
    }
    ctx->pc = 0x10EBCCu;
    // 0x10ebcc: 0x1000ffdb  b           . + 4 + (-0x25 << 2)
    ctx->pc = 0x10EBCCu;
    {
        const bool branch_taken_0x10ebcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EBD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EBCCu;
            // 0x10ebd0: 0x82a30000  lb          $v1, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ebcc) {
            ctx->pc = 0x10EB3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb3c;
        }
    }
    ctx->pc = 0x10EBD4u;
    // 0x10ebd4: 0x0  nop
    ctx->pc = 0x10ebd4u;
    // NOP
label_10ebd8:
    // 0x10ebd8: 0x1462000e  bne         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x10EBD8u;
    {
        const bool branch_taken_0x10ebd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10EBDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EBD8u;
            // 0x10ebdc: 0x26b1ffff  addiu       $s1, $s5, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ebd8) {
            ctx->pc = 0x10EC14u;
            goto label_10ec14;
        }
    }
    ctx->pc = 0x10EBE0u;
    // 0x10ebe0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x10ebe0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ebe4: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x10ebe4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10ebe8:
    // 0x10ebe8: 0x82b00000  lb          $s0, 0x0($s5)
    ctx->pc = 0x10ebe8u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x10ebec: 0x2e020079  sltiu       $v0, $s0, 0x79
    ctx->pc = 0x10ebecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)121) ? 1 : 0);
    // 0x10ebf0: 0x1040007f  beqz        $v0, . + 4 + (0x7F << 2)
    ctx->pc = 0x10EBF0u;
    {
        const bool branch_taken_0x10ebf0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EBF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EBF0u;
            // 0x10ebf4: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ebf0) {
            ctx->pc = 0x10EDF0u;
            goto label_10edf0;
        }
    }
    ctx->pc = 0x10EBF8u;
    // 0x10ebf8: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x10ebf8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x10ebfc: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10ebfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10ec00: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10ec00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10ec04: 0x8c637d60  lw          $v1, 0x7D60($v1)
    ctx->pc = 0x10ec04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32096)));
    // 0x10ec08: 0x600008  jr          $v1
    ctx->pc = 0x10EC08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10EC10u: goto label_10ec10;
            case 0x10EC78u: goto label_10ec78;
            case 0x10EC80u: goto label_10ec80;
            case 0x10EC88u: goto label_10ec88;
            case 0x10EC90u: goto label_10ec90;
            case 0x10EC98u: goto label_10ec98;
            case 0x10ECB0u: goto label_10ecb0;
            case 0x10ECB4u: goto label_10ecb4;
            case 0x10ECC8u: goto label_10ecc8;
            case 0x10ECE0u: goto label_10ece0;
            case 0x10ECE4u: goto label_10ece4;
            case 0x10ED00u: goto label_10ed00;
            case 0x10ED18u: goto label_10ed18;
            case 0x10ED28u: goto label_10ed28;
            case 0x10ED30u: goto label_10ed30;
            case 0x10ED38u: goto label_10ed38;
            case 0x10ED60u: goto label_10ed60;
            case 0x10ED70u: goto label_10ed70;
            case 0x10ED90u: goto label_10ed90;
            case 0x10EDE8u: goto label_10ede8;
            case 0x10EDF0u: goto label_10edf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10EC10u;
label_10ec10:
    // 0x10ec10: 0x26b1ffff  addiu       $s1, $s5, -0x1
    ctx->pc = 0x10ec10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
label_10ec14:
    // 0x10ec14: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x10ec14u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10ec18:
    // 0x10ec18: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10ec18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10ec1c: 0x5c400007  bgtzl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10EC1Cu;
    {
        const bool branch_taken_0x10ec1c = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x10ec1c) {
            ctx->pc = 0x10EC20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC1Cu;
            // 0x10ec20: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EC3Cu;
            goto label_10ec3c;
        }
    }
    ctx->pc = 0x10EC24u;
    // 0x10ec24: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10ec24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ec28: 0xc042814  jal         func_10A050
    ctx->pc = 0x10EC28u;
    SET_GPR_U32(ctx, 31, 0x10EC30u);
    ctx->pc = 0x10EC2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC28u;
            // 0x10ec2c: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EC30u; }
        if (ctx->pc != 0x10EC30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EC30u; }
        if (ctx->pc != 0x10EC30u) { return; }
    }
    ctx->pc = 0x10EC30u;
label_10ec30:
    // 0x10ec30: 0x144002c1  bnez        $v0, . + 4 + (0x2C1 << 2)
    ctx->pc = 0x10EC30u;
    {
        const bool branch_taken_0x10ec30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10EC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC30u;
            // 0x10ec34: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec30) {
            ctx->pc = 0x10F738u;
            goto label_10f738;
        }
    }
    ctx->pc = 0x10EC38u;
    // 0x10ec38: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x10ec38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10ec3c:
    // 0x10ec3c: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x10ec3cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x10ec40: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x10ec40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10ec44: 0x144302c1  bne         $v0, $v1, . + 4 + (0x2C1 << 2)
    ctx->pc = 0x10EC44u;
    {
        const bool branch_taken_0x10ec44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x10EC48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC44u;
            // 0x10ec48: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec44) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10EC4Cu;
    // 0x10ec4c: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10ec4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10ec50: 0x24830001  addiu       $v1, $a0, 0x1
    ctx->pc = 0x10ec50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10ec54: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x10ec54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x10ec58: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x10ec58u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x10ec5c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x10ec5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10ec60: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x10ec60u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x10ec64: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x10ec64u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x10ec68: 0x1a00ffeb  blez        $s0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x10EC68u;
    {
        const bool branch_taken_0x10ec68 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10EC6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC68u;
            // 0x10ec6c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec68) {
            ctx->pc = 0x10EC18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ec18;
        }
    }
    ctx->pc = 0x10EC70u;
    // 0x10ec70: 0x1000ffb2  b           . + 4 + (-0x4E << 2)
    ctx->pc = 0x10EC70u;
    {
        const bool branch_taken_0x10ec70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EC74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC70u;
            // 0x10ec74: 0x82a30000  lb          $v1, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec70) {
            ctx->pc = 0x10EB3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb3c;
        }
    }
    ctx->pc = 0x10EC78u;
label_10ec78:
    // 0x10ec78: 0x1000ffdb  b           . + 4 + (-0x25 << 2)
    ctx->pc = 0x10EC78u;
    {
        const bool branch_taken_0x10ec78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EC7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC78u;
            // 0x10ec7c: 0x36310008  ori         $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec78) {
            ctx->pc = 0x10EBE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ebe8;
        }
    }
    ctx->pc = 0x10EC80u;
label_10ec80:
    // 0x10ec80: 0x1000ffd9  b           . + 4 + (-0x27 << 2)
    ctx->pc = 0x10EC80u;
    {
        const bool branch_taken_0x10ec80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC80u;
            // 0x10ec84: 0x36310001  ori         $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec80) {
            ctx->pc = 0x10EBE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ebe8;
        }
    }
    ctx->pc = 0x10EC88u;
label_10ec88:
    // 0x10ec88: 0x1000ffd7  b           . + 4 + (-0x29 << 2)
    ctx->pc = 0x10EC88u;
    {
        const bool branch_taken_0x10ec88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EC8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC88u;
            // 0x10ec8c: 0x36310002  ori         $s1, $s1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec88) {
            ctx->pc = 0x10EBE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ebe8;
        }
    }
    ctx->pc = 0x10EC90u;
label_10ec90:
    // 0x10ec90: 0x1000ffd5  b           . + 4 + (-0x2B << 2)
    ctx->pc = 0x10EC90u;
    {
        const bool branch_taken_0x10ec90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EC94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EC90u;
            // 0x10ec94: 0x36310004  ori         $s1, $s1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ec90) {
            ctx->pc = 0x10EBE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ebe8;
        }
    }
    ctx->pc = 0x10EC98u;
label_10ec98:
    // 0x10ec98: 0x141080  sll         $v0, $s4, 2
    ctx->pc = 0x10ec98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 2));
    // 0x10ec9c: 0x541021  addu        $v0, $v0, $s4
    ctx->pc = 0x10ec9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x10eca0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x10eca0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x10eca4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10eca4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10eca8: 0x1000ffcf  b           . + 4 + (-0x31 << 2)
    ctx->pc = 0x10ECA8u;
    {
        const bool branch_taken_0x10eca8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ECACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ECA8u;
            // 0x10ecac: 0x2454ffd0  addiu       $s4, $v0, -0x30 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967248));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eca8) {
            ctx->pc = 0x10EBE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ebe8;
        }
    }
    ctx->pc = 0x10ECB0u;
label_10ecb0:
    // 0x10ecb0: 0x36310001  ori         $s1, $s1, 0x1
    ctx->pc = 0x10ecb0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)1);
label_10ecb4:
    // 0x10ecb4: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x10ecb4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x10ecb8: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x10ecb8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10ecbc: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x10ECBCu;
    {
        const bool branch_taken_0x10ecbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ECC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ECBCu;
            // 0x10ecc0: 0x2442cb18  addiu       $v0, $v0, -0x34E8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953752));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ecbc) {
            ctx->pc = 0x10ED0Cu;
            goto label_10ed0c;
        }
    }
    ctx->pc = 0x10ECC4u;
    // 0x10ecc4: 0x0  nop
    ctx->pc = 0x10ecc4u;
    // NOP
label_10ecc8:
    // 0x10ecc8: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x10ecc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x10eccc: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x10ecccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10ecd0: 0x2442cb18  addiu       $v0, $v0, -0x34E8
    ctx->pc = 0x10ecd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953752));
    // 0x10ecd4: 0xf02d  daddu       $fp, $zero, $zero
    ctx->pc = 0x10ecd4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ecd8: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x10ECD8u;
    {
        const bool branch_taken_0x10ecd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ECDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ECD8u;
            // 0x10ecdc: 0xafa20264  sw          $v0, 0x264($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 612), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ecd8) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ECE0u;
label_10ece0:
    // 0x10ece0: 0x36310001  ori         $s1, $s1, 0x1
    ctx->pc = 0x10ece0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)1);
label_10ece4:
    // 0x10ece4: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x10ece4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x10ece8: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x10ece8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10ecec: 0x2442cd78  addiu       $v0, $v0, -0x3288
    ctx->pc = 0x10ececu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954360));
    // 0x10ecf0: 0x241e0008  addiu       $fp, $zero, 0x8
    ctx->pc = 0x10ecf0u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x10ecf4: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x10ECF4u;
    {
        const bool branch_taken_0x10ecf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ECF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ECF4u;
            // 0x10ecf8: 0xafa20264  sw          $v0, 0x264($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 612), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ecf4) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ECFCu;
    // 0x10ecfc: 0x0  nop
    ctx->pc = 0x10ecfcu;
    // NOP
label_10ed00:
    // 0x10ed00: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x10ed00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x10ed04: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x10ed04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10ed08: 0x2442cd78  addiu       $v0, $v0, -0x3288
    ctx->pc = 0x10ed08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954360));
label_10ed0c:
    // 0x10ed0c: 0x241e000a  addiu       $fp, $zero, 0xA
    ctx->pc = 0x10ed0cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x10ed10: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x10ED10u;
    {
        const bool branch_taken_0x10ed10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ED14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED10u;
            // 0x10ed14: 0xafa20264  sw          $v0, 0x264($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 612), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ed10) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ED18u;
label_10ed18:
    // 0x10ed18: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x10ed18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x10ed1c: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x10ED1Cu;
    {
        const bool branch_taken_0x10ed1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ED20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED1Cu;
            // 0x10ed20: 0x36310100  ori         $s1, $s1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ed1c) {
            ctx->pc = 0x10ED78u;
            goto label_10ed78;
        }
    }
    ctx->pc = 0x10ED24u;
    // 0x10ed24: 0x0  nop
    ctx->pc = 0x10ed24u;
    // NOP
label_10ed28:
    // 0x10ed28: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x10ED28u;
    {
        const bool branch_taken_0x10ed28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ED2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED28u;
            // 0x10ed2c: 0x24100004  addiu       $s0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ed28) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ED30u;
label_10ed30:
    // 0x10ed30: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x10ED30u;
    {
        const bool branch_taken_0x10ed30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ED34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED30u;
            // 0x10ed34: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ed30) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ED38u;
label_10ed38:
    // 0x10ed38: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x10ed38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ed3c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10ed3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ed40: 0xc043de0  jal         func_10F780
    ctx->pc = 0x10ED40u;
    SET_GPR_U32(ctx, 31, 0x10ED48u);
    ctx->pc = 0x10ED44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED40u;
            // 0x10ed44: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F780u;
    if (runtime->hasFunction(0x10F780u)) {
        auto targetFn = runtime->lookupFunction(0x10F780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10ED48u; }
        if (ctx->pc != 0x10ED48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F780_0x10f780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10ED48u; }
        if (ctx->pc != 0x10ED48u) { return; }
    }
    ctx->pc = 0x10ED48u;
label_10ed48:
    // 0x10ed48: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x10ed48u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ed4c: 0x36310020  ori         $s1, $s1, 0x20
    ctx->pc = 0x10ed4cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)32);
    // 0x10ed50: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x10ed50u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10ed54: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x10ED54u;
    {
        const bool branch_taken_0x10ed54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ED58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED54u;
            // 0x10ed58: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ed54) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ED5Cu;
    // 0x10ed5c: 0x0  nop
    ctx->pc = 0x10ed5cu;
    // NOP
label_10ed60:
    // 0x10ed60: 0x36310020  ori         $s1, $s1, 0x20
    ctx->pc = 0x10ed60u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)32);
    // 0x10ed64: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x10ED64u;
    {
        const bool branch_taken_0x10ed64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ED68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED64u;
            // 0x10ed68: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ed64) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ED6Cu;
    // 0x10ed6c: 0x0  nop
    ctx->pc = 0x10ed6cu;
    // NOP
label_10ed70:
    // 0x10ed70: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x10ed70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x10ed74: 0x36310110  ori         $s1, $s1, 0x110
    ctx->pc = 0x10ed74u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)272);
label_10ed78:
    // 0x10ed78: 0x2442cd78  addiu       $v0, $v0, -0x3288
    ctx->pc = 0x10ed78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954360));
    // 0x10ed7c: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x10ed7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10ed80: 0xafa20264  sw          $v0, 0x264($sp)
    ctx->pc = 0x10ed80u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 612), GPR_U32(ctx, 2));
    // 0x10ed84: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x10ED84u;
    {
        const bool branch_taken_0x10ed84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ED88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED84u;
            // 0x10ed88: 0x241e0010  addiu       $fp, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ed84) {
            ctx->pc = 0x10EE18u;
            goto label_10ee18;
        }
    }
    ctx->pc = 0x10ED8Cu;
    // 0x10ed8c: 0x0  nop
    ctx->pc = 0x10ed8cu;
    // NOP
label_10ed90:
    // 0x10ed90: 0x32220008  andi        $v0, $s1, 0x8
    ctx->pc = 0x10ed90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)8);
    // 0x10ed94: 0x5440ff69  bnel        $v0, $zero, . + 4 + (-0x97 << 2)
    ctx->pc = 0x10ED94u;
    {
        const bool branch_taken_0x10ed94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ed94) {
            ctx->pc = 0x10ED98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10ED94u;
            // 0x10ed98: 0x82a30000  lb          $v1, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EB3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb3c;
        }
    }
    ctx->pc = 0x10ED9Cu;
    // 0x10ed9c: 0x32220004  andi        $v0, $s1, 0x4
    ctx->pc = 0x10ed9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)4);
    // 0x10eda0: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x10EDA0u;
    {
        const bool branch_taken_0x10eda0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10eda0) {
            ctx->pc = 0x10EDA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EDA0u;
            // 0x10eda4: 0x32220001  andi        $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EDC0u;
            goto label_10edc0;
        }
    }
    ctx->pc = 0x10EDA8u;
    // 0x10eda8: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x10eda8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10edac: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10edacu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10edb0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x10edb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10edb4: 0x1000ff60  b           . + 4 + (-0xA0 << 2)
    ctx->pc = 0x10EDB4u;
    {
        const bool branch_taken_0x10edb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EDB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EDB4u;
            // 0x10edb8: 0xa4680000  sh          $t0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10edb4) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10EDBCu;
    // 0x10edbc: 0x0  nop
    ctx->pc = 0x10edbcu;
    // NOP
label_10edc0:
    // 0x10edc0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10EDC0u;
    {
        const bool branch_taken_0x10edc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EDC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EDC0u;
            // 0x10edc4: 0x2e0102d  daddu       $v0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10edc0) {
            ctx->pc = 0x10EDD8u;
            goto label_10edd8;
        }
    }
    ctx->pc = 0x10EDC8u;
    // 0x10edc8: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10edc8u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10edcc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x10edccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10edd0: 0x1000ff59  b           . + 4 + (-0xA7 << 2)
    ctx->pc = 0x10EDD0u;
    {
        const bool branch_taken_0x10edd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EDD0u;
            // 0x10edd4: 0xfc480000  sd          $t0, 0x0($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10edd0) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10EDD8u;
label_10edd8:
    // 0x10edd8: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10edd8u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10eddc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x10eddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10ede0: 0x1000ff55  b           . + 4 + (-0xAB << 2)
    ctx->pc = 0x10EDE0u;
    {
        const bool branch_taken_0x10ede0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EDE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EDE0u;
            // 0x10ede4: 0xac680000  sw          $t0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ede0) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10EDE8u;
label_10ede8:
    // 0x10ede8: 0x10000258  b           . + 4 + (0x258 << 2)
    ctx->pc = 0x10EDE8u;
    {
        const bool branch_taken_0x10ede8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EDECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EDE8u;
            // 0x10edec: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ede8) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10EDF0u;
label_10edf0:
    // 0x10edf0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10edf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10edf4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10edf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10edf8: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10edf8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10edfc: 0x24100003  addiu       $s0, $zero, 0x3
    ctx->pc = 0x10edfcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10ee00: 0x3c030011  lui         $v1, 0x11
    ctx->pc = 0x10ee00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17 << 16));
    // 0x10ee04: 0x241e000a  addiu       $fp, $zero, 0xA
    ctx->pc = 0x10ee04u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x10ee08: 0x2463cb18  addiu       $v1, $v1, -0x34E8
    ctx->pc = 0x10ee08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953752));
    // 0x10ee0c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x10ee0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x10ee10: 0xafa30264  sw          $v1, 0x264($sp)
    ctx->pc = 0x10ee10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 612), GPR_U32(ctx, 3));
    // 0x10ee14: 0x2228825  or          $s1, $s1, $v0
    ctx->pc = 0x10ee14u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
label_10ee18:
    // 0x10ee18: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10ee18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10ee1c: 0x5c400007  bgtzl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10EE1Cu;
    {
        const bool branch_taken_0x10ee1c = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x10ee1c) {
            ctx->pc = 0x10EE20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE1Cu;
            // 0x10ee20: 0x32220020  andi        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)32);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EE3Cu;
            goto label_10ee3c;
        }
    }
    ctx->pc = 0x10EE24u;
    // 0x10ee24: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10ee24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ee28: 0xc042814  jal         func_10A050
    ctx->pc = 0x10EE28u;
    SET_GPR_U32(ctx, 31, 0x10EE30u);
    ctx->pc = 0x10EE2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE28u;
            // 0x10ee2c: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EE30u; }
        if (ctx->pc != 0x10EE30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EE30u; }
        if (ctx->pc != 0x10EE30u) { return; }
    }
    ctx->pc = 0x10EE30u;
label_10ee30:
    // 0x10ee30: 0x14400241  bnez        $v0, . + 4 + (0x241 << 2)
    ctx->pc = 0x10EE30u;
    {
        const bool branch_taken_0x10ee30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10EE34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE30u;
            // 0x10ee34: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ee30) {
            ctx->pc = 0x10F738u;
            goto label_10f738;
        }
    }
    ctx->pc = 0x10EE38u;
    // 0x10ee38: 0x32220020  andi        $v0, $s1, 0x20
    ctx->pc = 0x10ee38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)32);
label_10ee3c:
    // 0x10ee3c: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x10EE3Cu;
    {
        const bool branch_taken_0x10ee3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10EE40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE3Cu;
            // 0x10ee40: 0x2e020005  sltiu       $v0, $s0, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ee3c) {
            ctx->pc = 0x10EEA8u;
            goto label_10eea8;
        }
    }
    ctx->pc = 0x10EE44u;
    // 0x10ee44: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x10EE44u;
    {
        const bool branch_taken_0x10ee44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EE48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE44u;
            // 0x10ee48: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ee44) {
            ctx->pc = 0x10EE88u;
            goto label_10ee88;
        }
    }
    ctx->pc = 0x10EE4Cu;
    // 0x10ee4c: 0x0  nop
    ctx->pc = 0x10ee4cu;
    // NOP
label_10ee50:
    // 0x10ee50: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x10ee50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x10ee54: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x10ee54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10ee58: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10EE58u;
    {
        const bool branch_taken_0x10ee58 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x10EE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE58u;
            // 0x10ee5c: 0xae420004  sw          $v0, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ee58) {
            ctx->pc = 0x10EE70u;
            goto label_10ee70;
        }
    }
    ctx->pc = 0x10EE60u;
    // 0x10ee60: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x10ee60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10ee64: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x10EE64u;
    {
        const bool branch_taken_0x10ee64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EE68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE64u;
            // 0x10ee68: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ee64) {
            ctx->pc = 0x10EE84u;
            goto label_10ee84;
        }
    }
    ctx->pc = 0x10EE6Cu;
    // 0x10ee6c: 0x0  nop
    ctx->pc = 0x10ee6cu;
    // NOP
label_10ee70:
    // 0x10ee70: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10ee70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ee74: 0xc042814  jal         func_10A050
    ctx->pc = 0x10EE74u;
    SET_GPR_U32(ctx, 31, 0x10EE7Cu);
    ctx->pc = 0x10EE78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE74u;
            // 0x10ee78: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EE7Cu; }
        if (ctx->pc != 0x10EE7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EE7Cu; }
        if (ctx->pc != 0x10EE7Cu) { return; }
    }
    ctx->pc = 0x10EE7Cu;
label_10ee7c:
    // 0x10ee7c: 0x1440022e  bnez        $v0, . + 4 + (0x22E << 2)
    ctx->pc = 0x10EE7Cu;
    {
        const bool branch_taken_0x10ee7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10EE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE7Cu;
            // 0x10ee80: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ee7c) {
            ctx->pc = 0x10F738u;
            goto label_10f738;
        }
    }
    ctx->pc = 0x10EE84u;
label_10ee84:
    // 0x10ee84: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x10ee84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10ee88:
    // 0x10ee88: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x10ee88u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10ee8c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10ee8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10ee90: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10ee90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10ee94: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10ee94u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10ee98: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x10ee98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x10ee9c: 0x5440ffec  bnel        $v0, $zero, . + 4 + (-0x14 << 2)
    ctx->pc = 0x10EE9Cu;
    {
        const bool branch_taken_0x10ee9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ee9c) {
            ctx->pc = 0x10EEA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EE9Cu;
            // 0x10eea0: 0x8e420004  lw          $v0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EE50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ee50;
        }
    }
    ctx->pc = 0x10EEA4u;
    // 0x10eea4: 0x2e020005  sltiu       $v0, $s0, 0x5
    ctx->pc = 0x10eea4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
label_10eea8:
    // 0x10eea8: 0x5040ff24  beql        $v0, $zero, . + 4 + (-0xDC << 2)
    ctx->pc = 0x10EEA8u;
    {
        const bool branch_taken_0x10eea8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10eea8) {
            ctx->pc = 0x10EEACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EEA8u;
            // 0x10eeac: 0x82a30000  lb          $v1, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EB3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb3c;
        }
    }
    ctx->pc = 0x10EEB0u;
    // 0x10eeb0: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x10eeb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x10eeb4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10eeb4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10eeb8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10eeb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10eebc: 0x8c637f50  lw          $v1, 0x7F50($v1)
    ctx->pc = 0x10eebcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32592)));
    // 0x10eec0: 0x600008  jr          $v1
    ctx->pc = 0x10EEC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10EEC8u: goto label_10eec8;
            case 0x10EF88u: goto label_10ef88;
            case 0x10F0A0u: goto label_10f0a0;
            case 0x10F1B8u: goto label_10f1b8;
            case 0x10F440u: goto label_10f440;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10EEC8u;
label_10eec8:
    // 0x10eec8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10eec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10eecc: 0x32230008  andi        $v1, $s1, 0x8
    ctx->pc = 0x10eeccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)8);
    // 0x10eed0: 0x1060001d  beqz        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x10EED0u;
    {
        const bool branch_taken_0x10eed0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EED0u;
            // 0x10eed4: 0x54a00a  movz        $s4, $v0, $s4 (Delay Slot)
        if (GPR_U64(ctx, 20) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eed0) {
            ctx->pc = 0x10EF48u;
            goto label_10ef48;
        }
    }
    ctx->pc = 0x10EED8u;
    // 0x10eed8: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x10eed8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10eedc: 0x0  nop
    ctx->pc = 0x10eedcu;
    // NOP
label_10eee0:
    // 0x10eee0: 0x8e500004  lw          $s0, 0x4($s2)
    ctx->pc = 0x10eee0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10eee4: 0x214102b  sltu        $v0, $s0, $s4
    ctx->pc = 0x10eee4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 20)) ? 1 : 0);
    // 0x10eee8: 0x5040000f  beql        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x10EEE8u;
    {
        const bool branch_taken_0x10eee8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10eee8) {
            ctx->pc = 0x10EEECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EEE8u;
            // 0x10eeec: 0x8e430000  lw          $v1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EF28u;
            goto label_10ef28;
        }
    }
    ctx->pc = 0x10EEF0u;
    // 0x10eef0: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x10eef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10eef4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10eef4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10eef8: 0x7fa80290  sq          $t0, 0x290($sp)
    ctx->pc = 0x10eef8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
    // 0x10eefc: 0x2308821  addu        $s1, $s1, $s0
    ctx->pc = 0x10eefcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x10ef00: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10ef00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10ef04: 0x290a023  subu        $s4, $s4, $s0
    ctx->pc = 0x10ef04u;
    SET_GPR_S32(ctx, 20, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x10ef08: 0xc042814  jal         func_10A050
    ctx->pc = 0x10EF08u;
    SET_GPR_U32(ctx, 31, 0x10EF10u);
    ctx->pc = 0x10EF0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF08u;
            // 0x10ef0c: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EF10u; }
        if (ctx->pc != 0x10EF10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EF10u; }
        if (ctx->pc != 0x10EF10u) { return; }
    }
    ctx->pc = 0x10EF10u;
label_10ef10:
    // 0x10ef10: 0x1040fff3  beqz        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x10EF10u;
    {
        const bool branch_taken_0x10ef10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EF14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF10u;
            // 0x10ef14: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ef10) {
            ctx->pc = 0x10EEE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eee0;
        }
    }
    ctx->pc = 0x10EF18u;
    // 0x10ef18: 0x5620ff07  bnel        $s1, $zero, . + 4 + (-0xF9 << 2)
    ctx->pc = 0x10EF18u;
    {
        const bool branch_taken_0x10ef18 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ef18) {
            ctx->pc = 0x10EF1Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF18u;
            // 0x10ef1c: 0x1114021  addu        $t0, $t0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10EF20u;
    // 0x10ef20: 0x10000206  b           . + 4 + (0x206 << 2)
    ctx->pc = 0x10EF20u;
    {
        const bool branch_taken_0x10ef20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EF24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF20u;
            // 0x10ef24: 0x8fa40260  lw          $a0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ef20) {
            ctx->pc = 0x10F73Cu;
            goto label_10f73c;
        }
    }
    ctx->pc = 0x10EF28u;
label_10ef28:
    // 0x10ef28: 0x2141023  subu        $v0, $s0, $s4
    ctx->pc = 0x10ef28u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 20)));
    // 0x10ef2c: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x10ef2cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x10ef30: 0x2348821  addu        $s1, $s1, $s4
    ctx->pc = 0x10ef30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
    // 0x10ef34: 0x741821  addu        $v1, $v1, $s4
    ctx->pc = 0x10ef34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x10ef38: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x10ef38u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x10ef3c: 0x1000fefe  b           . + 4 + (-0x102 << 2)
    ctx->pc = 0x10EF3Cu;
    {
        const bool branch_taken_0x10ef3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EF40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF3Cu;
            // 0x10ef40: 0x1114021  addu        $t0, $t0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ef3c) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10EF44u;
    // 0x10ef44: 0x0  nop
    ctx->pc = 0x10ef44u;
    // NOP
label_10ef48:
    // 0x10ef48: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x10ef48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ef4c: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10ef4cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10ef50: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x10ef50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10ef54: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x10ef54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ef58: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x10ef58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10ef5c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x10ef5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ef60: 0xc0415ee  jal         func_1057B8
    ctx->pc = 0x10EF60u;
    SET_GPR_U32(ctx, 31, 0x10EF68u);
    ctx->pc = 0x10EF64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF60u;
            // 0x10ef64: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1057B8u;
    if (runtime->hasFunction(0x1057B8u)) {
        auto targetFn = runtime->lookupFunction(0x1057B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EF68u; }
        if (ctx->pc != 0x10EF68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001057B8_0x1057b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EF68u; }
        if (ctx->pc != 0x10EF68u) { return; }
    }
    ctx->pc = 0x10EF68u;
label_10ef68:
    // 0x10ef68: 0x104001f3  beqz        $v0, . + 4 + (0x1F3 << 2)
    ctx->pc = 0x10EF68u;
    {
        const bool branch_taken_0x10ef68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EF6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF68u;
            // 0x10ef6c: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ef68) {
            ctx->pc = 0x10F738u;
            goto label_10f738;
        }
    }
    ctx->pc = 0x10EF70u;
    // 0x10ef70: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x10ef70u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x10ef74: 0x8fa20260  lw          $v0, 0x260($sp)
    ctx->pc = 0x10ef74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x10ef78: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10ef78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10ef7c: 0x1000feee  b           . + 4 + (-0x112 << 2)
    ctx->pc = 0x10EF7Cu;
    {
        const bool branch_taken_0x10ef7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EF80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF7Cu;
            // 0x10ef80: 0xafa20260  sw          $v0, 0x260($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 608), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ef7c) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10EF84u;
    // 0x10ef84: 0x0  nop
    ctx->pc = 0x10ef84u;
    // NOP
label_10ef88:
    // 0x10ef88: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10ef88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10ef8c: 0x32230008  andi        $v1, $s1, 0x8
    ctx->pc = 0x10ef8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)8);
    // 0x10ef90: 0x1060001d  beqz        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x10EF90u;
    {
        const bool branch_taken_0x10ef90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EF94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EF90u;
            // 0x10ef94: 0x54a00a  movz        $s4, $v0, $s4 (Delay Slot)
        if (GPR_U64(ctx, 20) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ef90) {
            ctx->pc = 0x10F008u;
            goto label_10f008;
        }
    }
    ctx->pc = 0x10EF98u;
    // 0x10ef98: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x10ef98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ef9c: 0x0  nop
    ctx->pc = 0x10ef9cu;
    // NOP
label_10efa0:
    // 0x10efa0: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x10efa0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10efa4:
    // 0x10efa4: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x10efa4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10efa8: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x10efa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x10efac: 0x80640000  lb          $a0, 0x0($v1)
    ctx->pc = 0x10efacu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10efb0: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x10EFB0u;
    {
        const bool branch_taken_0x10efb0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EFB0u;
            // 0x10efb4: 0x24a20001  addiu       $v0, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10efb0) {
            ctx->pc = 0x10EFF8u;
            goto label_10eff8;
        }
    }
    ctx->pc = 0x10EFB8u;
    // 0x10efb8: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x10efb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10efbc: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10efbcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x10efc0: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x10efc0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x10efc4: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x10efc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x10efc8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x10efc8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x10efcc: 0x1280000a  beqz        $s4, . + 4 + (0xA << 2)
    ctx->pc = 0x10EFCCu;
    {
        const bool branch_taken_0x10efcc = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EFD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EFCCu;
            // 0x10efd0: 0xae430004  sw          $v1, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10efcc) {
            ctx->pc = 0x10EFF8u;
            goto label_10eff8;
        }
    }
    ctx->pc = 0x10EFD4u;
    // 0x10efd4: 0x5c60fff3  bgtzl       $v1, . + 4 + (-0xD << 2)
    ctx->pc = 0x10EFD4u;
    {
        const bool branch_taken_0x10efd4 = (GPR_S64(ctx, 3) > 0);
        if (branch_taken_0x10efd4) {
            ctx->pc = 0x10EFD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EFD4u;
            // 0x10efd8: 0x8e450000  lw          $a1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EFA4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10efa4;
        }
    }
    ctx->pc = 0x10EFDCu;
    // 0x10efdc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10efdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10efe0: 0xc042814  jal         func_10A050
    ctx->pc = 0x10EFE0u;
    SET_GPR_U32(ctx, 31, 0x10EFE8u);
    ctx->pc = 0x10EFE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10EFE0u;
            // 0x10efe4: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EFE8u; }
        if (ctx->pc != 0x10EFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10EFE8u; }
        if (ctx->pc != 0x10EFE8u) { return; }
    }
    ctx->pc = 0x10EFE8u;
label_10efe8:
    // 0x10efe8: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x10EFE8u;
    {
        const bool branch_taken_0x10efe8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EFECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EFE8u;
            // 0x10efec: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10efe8) {
            ctx->pc = 0x10EFA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10efa0;
        }
    }
    ctx->pc = 0x10EFF0u;
    // 0x10eff0: 0x120001d2  beqz        $s0, . + 4 + (0x1D2 << 2)
    ctx->pc = 0x10EFF0u;
    {
        const bool branch_taken_0x10eff0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EFF0u;
            // 0x10eff4: 0x8fa40260  lw          $a0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eff0) {
            ctx->pc = 0x10F73Cu;
            goto label_10f73c;
        }
    }
    ctx->pc = 0x10EFF8u;
label_10eff8:
    // 0x10eff8: 0x5600fecf  bnel        $s0, $zero, . + 4 + (-0x131 << 2)
    ctx->pc = 0x10EFF8u;
    {
        const bool branch_taken_0x10eff8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x10eff8) {
            ctx->pc = 0x10EFFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EFF8u;
            // 0x10effc: 0x1104021  addu        $t0, $t0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10F000u;
    // 0x10f000: 0x100001d2  b           . + 4 + (0x1D2 << 2)
    ctx->pc = 0x10F000u;
    {
        const bool branch_taken_0x10f000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F000u;
            // 0x10f004: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f000) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10F008u;
label_10f008:
    // 0x10f008: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x10f008u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f00c: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10f00cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10f010: 0x8c530000  lw          $s3, 0x0($v0)
    ctx->pc = 0x10f010u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10f014: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x10f014u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_10f018:
    // 0x10f018: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x10f018u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10f01c:
    // 0x10f01c: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x10f01cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10f020: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x10f020u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x10f024: 0x80640000  lb          $a0, 0x0($v1)
    ctx->pc = 0x10f024u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10f028: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x10F028u;
    {
        const bool branch_taken_0x10f028 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F028u;
            // 0x10f02c: 0x24a40001  addiu       $a0, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f028) {
            ctx->pc = 0x10F07Cu;
            goto label_10f07c;
        }
    }
    ctx->pc = 0x10F030u;
    // 0x10f030: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10f030u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10f034: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10f034u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x10f038: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x10f038u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10f03c: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x10f03cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x10f040: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x10f040u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10f044: 0xa2630000  sb          $v1, 0x0($s3)
    ctx->pc = 0x10f044u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x10f048: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x10f048u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x10f04c: 0x1280000b  beqz        $s4, . + 4 + (0xB << 2)
    ctx->pc = 0x10F04Cu;
    {
        const bool branch_taken_0x10f04c = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F04Cu;
            // 0x10f050: 0xae440000  sw          $a0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f04c) {
            ctx->pc = 0x10F07Cu;
            goto label_10f07c;
        }
    }
    ctx->pc = 0x10F054u;
    // 0x10f054: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10f054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10f058: 0x5c40fff0  bgtzl       $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x10F058u;
    {
        const bool branch_taken_0x10f058 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x10f058) {
            ctx->pc = 0x10F05Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F058u;
            // 0x10f05c: 0x8e450000  lw          $a1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F01Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f01c;
        }
    }
    ctx->pc = 0x10F060u;
    // 0x10f060: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10f060u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f064: 0xc042814  jal         func_10A050
    ctx->pc = 0x10F064u;
    SET_GPR_U32(ctx, 31, 0x10F06Cu);
    ctx->pc = 0x10F068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F064u;
            // 0x10f068: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F06Cu; }
        if (ctx->pc != 0x10F06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F06Cu; }
        if (ctx->pc != 0x10F06Cu) { return; }
    }
    ctx->pc = 0x10F06Cu;
label_10f06c:
    // 0x10f06c: 0x1040ffea  beqz        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x10F06Cu;
    {
        const bool branch_taken_0x10f06c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F06Cu;
            // 0x10f070: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f06c) {
            ctx->pc = 0x10F018u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f018;
        }
    }
    ctx->pc = 0x10F074u;
    // 0x10f074: 0x127001b1  beq         $s3, $s0, . + 4 + (0x1B1 << 2)
    ctx->pc = 0x10F074u;
    {
        const bool branch_taken_0x10f074 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 16));
        ctx->pc = 0x10F078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F074u;
            // 0x10f078: 0x8fa40260  lw          $a0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f074) {
            ctx->pc = 0x10F73Cu;
            goto label_10f73c;
        }
    }
    ctx->pc = 0x10F07Cu;
label_10f07c:
    // 0x10f07c: 0x2708023  subu        $s0, $s3, $s0
    ctx->pc = 0x10f07cu;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x10f080: 0x120001b2  beqz        $s0, . + 4 + (0x1B2 << 2)
    ctx->pc = 0x10F080u;
    {
        const bool branch_taken_0x10f080 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F080u;
            // 0x10f084: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f080) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10F088u;
    // 0x10f088: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x10f088u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x10f08c: 0x8fa30260  lw          $v1, 0x260($sp)
    ctx->pc = 0x10f08cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x10f090: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10f090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10f094: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x10F094u;
    {
        const bool branch_taken_0x10f094 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F094u;
            // 0x10f098: 0xafa30260  sw          $v1, 0x260($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 608), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f094) {
            ctx->pc = 0x10F114u;
            goto label_10f114;
        }
    }
    ctx->pc = 0x10F09Cu;
    // 0x10f09c: 0x0  nop
    ctx->pc = 0x10f09cu;
    // NOP
label_10f0a0:
    // 0x10f0a0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10f0a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10f0a4: 0x32230008  andi        $v1, $s1, 0x8
    ctx->pc = 0x10f0a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)8);
    // 0x10f0a8: 0x1060001d  beqz        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x10F0A8u;
    {
        const bool branch_taken_0x10f0a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F0ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F0A8u;
            // 0x10f0ac: 0x54a00a  movz        $s4, $v0, $s4 (Delay Slot)
        if (GPR_U64(ctx, 20) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f0a8) {
            ctx->pc = 0x10F120u;
            goto label_10f120;
        }
    }
    ctx->pc = 0x10F0B0u;
    // 0x10f0b0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x10f0b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f0b4: 0x0  nop
    ctx->pc = 0x10f0b4u;
    // NOP
label_10f0b8:
    // 0x10f0b8: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x10f0b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10f0bc:
    // 0x10f0bc: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x10f0bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10f0c0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10f0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10f0c4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10f0c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10f0c8: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10f0c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10f0cc: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x10f0ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x10f0d0: 0x5440fe99  bnel        $v0, $zero, . + 4 + (-0x167 << 2)
    ctx->pc = 0x10F0D0u;
    {
        const bool branch_taken_0x10f0d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f0d0) {
            ctx->pc = 0x10F0D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F0D0u;
            // 0x10f0d4: 0x1104021  addu        $t0, $t0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10F0D8u;
    // 0x10f0d8: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x10f0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10f0dc: 0x24820001  addiu       $v0, $a0, 0x1
    ctx->pc = 0x10f0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10f0e0: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10f0e0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x10f0e4: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x10f0e4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x10f0e8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x10f0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x10f0ec: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x10f0ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x10f0f0: 0x12800008  beqz        $s4, . + 4 + (0x8 << 2)
    ctx->pc = 0x10F0F0u;
    {
        const bool branch_taken_0x10f0f0 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F0F0u;
            // 0x10f0f4: 0xae430004  sw          $v1, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f0f0) {
            ctx->pc = 0x10F114u;
            goto label_10f114;
        }
    }
    ctx->pc = 0x10F0F8u;
    // 0x10f0f8: 0x5c60fff0  bgtzl       $v1, . + 4 + (-0x10 << 2)
    ctx->pc = 0x10F0F8u;
    {
        const bool branch_taken_0x10f0f8 = (GPR_S64(ctx, 3) > 0);
        if (branch_taken_0x10f0f8) {
            ctx->pc = 0x10F0FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F0F8u;
            // 0x10f0fc: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F0BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f0bc;
        }
    }
    ctx->pc = 0x10F100u;
    // 0x10f100: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10f100u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f104: 0xc042814  jal         func_10A050
    ctx->pc = 0x10F104u;
    SET_GPR_U32(ctx, 31, 0x10F10Cu);
    ctx->pc = 0x10F108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F104u;
            // 0x10f108: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F10Cu; }
        if (ctx->pc != 0x10F10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F10Cu; }
        if (ctx->pc != 0x10F10Cu) { return; }
    }
    ctx->pc = 0x10F10Cu;
label_10f10c:
    // 0x10f10c: 0x1040ffea  beqz        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x10F10Cu;
    {
        const bool branch_taken_0x10f10c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F10Cu;
            // 0x10f110: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f10c) {
            ctx->pc = 0x10F0B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f0b8;
        }
    }
    ctx->pc = 0x10F114u;
label_10f114:
    // 0x10f114: 0x1000fe88  b           . + 4 + (-0x178 << 2)
    ctx->pc = 0x10F114u;
    {
        const bool branch_taken_0x10f114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F114u;
            // 0x10f118: 0x1104021  addu        $t0, $t0, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f114) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10F11Cu;
    // 0x10f11c: 0x0  nop
    ctx->pc = 0x10f11cu;
    // NOP
label_10f120:
    // 0x10f120: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x10f120u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f124: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10f124u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10f128: 0x8c530000  lw          $s3, 0x0($v0)
    ctx->pc = 0x10f128u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10f12c: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x10f12cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_10f130:
    // 0x10f130: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x10f130u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10f134:
    // 0x10f134: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x10f134u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10f138: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10f138u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10f13c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x10f13cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10f140: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10f140u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10f144: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x10f144u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x10f148: 0x54400014  bnel        $v0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x10F148u;
    {
        const bool branch_taken_0x10f148 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f148) {
            ctx->pc = 0x10F14Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F148u;
            // 0x10f14c: 0xa2600000  sb          $zero, 0x0($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F19Cu;
            goto label_10f19c;
        }
    }
    ctx->pc = 0x10F150u;
    // 0x10f150: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10f150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10f154: 0x24a40001  addiu       $a0, $a1, 0x1
    ctx->pc = 0x10f154u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10f158: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10f158u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x10f15c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x10f15cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10f160: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x10f160u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x10f164: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x10f164u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10f168: 0xa2630000  sb          $v1, 0x0($s3)
    ctx->pc = 0x10f168u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x10f16c: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x10f16cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x10f170: 0x12800009  beqz        $s4, . + 4 + (0x9 << 2)
    ctx->pc = 0x10F170u;
    {
        const bool branch_taken_0x10f170 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F170u;
            // 0x10f174: 0xae440000  sw          $a0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f170) {
            ctx->pc = 0x10F198u;
            goto label_10f198;
        }
    }
    ctx->pc = 0x10F178u;
    // 0x10f178: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10f178u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10f17c: 0x5c40ffed  bgtzl       $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x10F17Cu;
    {
        const bool branch_taken_0x10f17c = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x10f17c) {
            ctx->pc = 0x10F180u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F17Cu;
            // 0x10f180: 0x8e450000  lw          $a1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F134u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f134;
        }
    }
    ctx->pc = 0x10F184u;
    // 0x10f184: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10f184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f188: 0xc042814  jal         func_10A050
    ctx->pc = 0x10F188u;
    SET_GPR_U32(ctx, 31, 0x10F190u);
    ctx->pc = 0x10F18Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F188u;
            // 0x10f18c: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F190u; }
        if (ctx->pc != 0x10F190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F190u; }
        if (ctx->pc != 0x10F190u) { return; }
    }
    ctx->pc = 0x10F190u;
label_10f190:
    // 0x10f190: 0x1040ffe7  beqz        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x10F190u;
    {
        const bool branch_taken_0x10f190 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F190u;
            // 0x10f194: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f190) {
            ctx->pc = 0x10F130u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f130;
        }
    }
    ctx->pc = 0x10F198u;
label_10f198:
    // 0x10f198: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x10f198u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
label_10f19c:
    // 0x10f19c: 0x2701023  subu        $v0, $s3, $s0
    ctx->pc = 0x10f19cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x10f1a0: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x10f1a0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x10f1a4: 0x8fa40260  lw          $a0, 0x260($sp)
    ctx->pc = 0x10f1a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x10f1a8: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10f1a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10f1ac: 0x1000fe62  b           . + 4 + (-0x19E << 2)
    ctx->pc = 0x10F1ACu;
    {
        const bool branch_taken_0x10f1ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F1ACu;
            // 0x10f1b0: 0xafa40260  sw          $a0, 0x260($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 608), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f1ac) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10F1B4u;
    // 0x10f1b4: 0x0  nop
    ctx->pc = 0x10f1b4u;
    // NOP
label_10f1b8:
    // 0x10f1b8: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10f1b8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x10f1bc: 0x2403015c  addiu       $v1, $zero, 0x15C
    ctx->pc = 0x10f1bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 348));
    // 0x10f1c0: 0x2e82015d  sltiu       $v0, $s4, 0x15D
    ctx->pc = 0x10f1c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)(int64_t)(int32_t)349) ? 1 : 0);
    // 0x10f1c4: 0x363102c0  ori         $s1, $s1, 0x2C0
    ctx->pc = 0x10f1c4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)704);
    // 0x10f1c8: 0x62a00a  movz        $s4, $v1, $v0
    ctx->pc = 0x10f1c8u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 3));
    // 0x10f1cc: 0x27a20100  addiu       $v0, $sp, 0x100
    ctx->pc = 0x10f1ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x10f1d0: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x10f1d0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x10f1d4: 0x12800050  beqz        $s4, . + 4 + (0x50 << 2)
    ctx->pc = 0x10F1D4u;
    {
        const bool branch_taken_0x10f1d4 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F1D4u;
            // 0x10f1d8: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f1d4) {
            ctx->pc = 0x10F318u;
            goto label_10f318;
        }
    }
    ctx->pc = 0x10F1DCu;
    // 0x10f1dc: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x10f1dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10f1e0:
    // 0x10f1e0: 0x90500000  lbu         $s0, 0x0($v0)
    ctx->pc = 0x10f1e0u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10f1e4: 0x2603ffd5  addiu       $v1, $s0, -0x2B
    ctx->pc = 0x10f1e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967253));
    // 0x10f1e8: 0x2c62004e  sltiu       $v0, $v1, 0x4E
    ctx->pc = 0x10f1e8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)78) ? 1 : 0);
    // 0x10f1ec: 0x1040004b  beqz        $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x10F1ECu;
    {
        const bool branch_taken_0x10f1ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F1ECu;
            // 0x10f1f0: 0x32220080  andi        $v0, $s1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f1ec) {
            ctx->pc = 0x10F31Cu;
            goto label_10f31c;
        }
    }
    ctx->pc = 0x10F1F4u;
    // 0x10f1f4: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x10f1f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x10f1f8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10f1f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10f1fc: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10f1fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10f200: 0x8c637f70  lw          $v1, 0x7F70($v1)
    ctx->pc = 0x10f200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32624)));
    // 0x10f204: 0x600008  jr          $v1
    ctx->pc = 0x10F204u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10F210u: goto label_10f210;
            case 0x10F238u: goto label_10f238;
            case 0x10F258u: goto label_10f258;
            case 0x10F280u: goto label_10f280;
            case 0x10F298u: goto label_10f298;
            case 0x10F2B0u: goto label_10f2b0;
            case 0x10F318u: goto label_10f318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10F20Cu;
    // 0x10f20c: 0x0  nop
    ctx->pc = 0x10f20cu;
    // NOP
label_10f210:
    // 0x10f210: 0x17c00004  bnez        $fp, . + 4 + (0x4 << 2)
    ctx->pc = 0x10F210u;
    {
        const bool branch_taken_0x10f210 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F210u;
            // 0x10f214: 0x32220200  andi        $v0, $s1, 0x200 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)512);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f210) {
            ctx->pc = 0x10F224u;
            goto label_10f224;
        }
    }
    ctx->pc = 0x10F218u;
    // 0x10f218: 0x241e0008  addiu       $fp, $zero, 0x8
    ctx->pc = 0x10f218u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x10f21c: 0x36310100  ori         $s1, $s1, 0x100
    ctx->pc = 0x10f21cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)256);
    // 0x10f220: 0x32220200  andi        $v0, $s1, 0x200
    ctx->pc = 0x10f220u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)512);
label_10f224:
    // 0x10f224: 0x50400029  beql        $v0, $zero, . + 4 + (0x29 << 2)
    ctx->pc = 0x10F224u;
    {
        const bool branch_taken_0x10f224 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f224) {
            ctx->pc = 0x10F228u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F224u;
            // 0x10f228: 0x2402fe3f  addiu       $v0, $zero, -0x1C1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966847));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F2CCu;
            goto label_10f2cc;
        }
    }
    ctx->pc = 0x10F22Cu;
    // 0x10f22c: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x10F22Cu;
    {
        const bool branch_taken_0x10f22c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F22Cu;
            // 0x10f230: 0x2402fd3f  addiu       $v0, $zero, -0x2C1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966591));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f22c) {
            ctx->pc = 0x10F2CCu;
            goto label_10f2cc;
        }
    }
    ctx->pc = 0x10F234u;
    // 0x10f234: 0x0  nop
    ctx->pc = 0x10f234u;
    // NOP
label_10f238:
    // 0x10f238: 0x1e1040  sll         $v0, $fp, 1
    ctx->pc = 0x10f238u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), 1));
    // 0x10f23c: 0x2403fe3f  addiu       $v1, $zero, -0x1C1
    ctx->pc = 0x10f23cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966847));
    // 0x10f240: 0x3c1e0023  lui         $fp, 0x23
    ctx->pc = 0x10f240u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)35 << 16));
    // 0x10f244: 0x3c2f021  addu        $fp, $fp, $v0
    ctx->pc = 0x10f244u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
    // 0x10f248: 0x87de7d30  lh          $fp, 0x7D30($fp)
    ctx->pc = 0x10f248u;
    SET_GPR_S32(ctx, 30, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 32048)));
    // 0x10f24c: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x10F24Cu;
    {
        const bool branch_taken_0x10f24c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F24Cu;
            // 0x10f250: 0x2238824  and         $s1, $s1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f24c) {
            ctx->pc = 0x10F2D0u;
            goto label_10f2d0;
        }
    }
    ctx->pc = 0x10F254u;
    // 0x10f254: 0x0  nop
    ctx->pc = 0x10f254u;
    // NOP
label_10f258:
    // 0x10f258: 0x1e1040  sll         $v0, $fp, 1
    ctx->pc = 0x10f258u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), 1));
    // 0x10f25c: 0x3c1e0023  lui         $fp, 0x23
    ctx->pc = 0x10f25cu;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)35 << 16));
    // 0x10f260: 0x3c2f021  addu        $fp, $fp, $v0
    ctx->pc = 0x10f260u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
    // 0x10f264: 0x87de7d30  lh          $fp, 0x7D30($fp)
    ctx->pc = 0x10f264u;
    SET_GPR_S32(ctx, 30, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 32048)));
    // 0x10f268: 0x2bc30009  slti        $v1, $fp, 0x9
    ctx->pc = 0x10f268u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 30) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x10f26c: 0x5460002b  bnel        $v1, $zero, . + 4 + (0x2B << 2)
    ctx->pc = 0x10F26Cu;
    {
        const bool branch_taken_0x10f26c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f26c) {
            ctx->pc = 0x10F270u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F26Cu;
            // 0x10f270: 0x32220080  andi        $v0, $s1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F31Cu;
            goto label_10f31c;
        }
    }
    ctx->pc = 0x10F274u;
    // 0x10f274: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x10F274u;
    {
        const bool branch_taken_0x10f274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F274u;
            // 0x10f278: 0x2402fe3f  addiu       $v0, $zero, -0x1C1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966847));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f274) {
            ctx->pc = 0x10F2CCu;
            goto label_10f2cc;
        }
    }
    ctx->pc = 0x10F27Cu;
    // 0x10f27c: 0x0  nop
    ctx->pc = 0x10f27cu;
    // NOP
label_10f280:
    // 0x10f280: 0x2bc2000b  slti        $v0, $fp, 0xB
    ctx->pc = 0x10f280u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 30) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x10f284: 0x54400025  bnel        $v0, $zero, . + 4 + (0x25 << 2)
    ctx->pc = 0x10F284u;
    {
        const bool branch_taken_0x10f284 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f284) {
            ctx->pc = 0x10F288u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F284u;
            // 0x10f288: 0x32220080  andi        $v0, $s1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F31Cu;
            goto label_10f31c;
        }
    }
    ctx->pc = 0x10F28Cu;
    // 0x10f28c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x10F28Cu;
    {
        const bool branch_taken_0x10f28c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F28Cu;
            // 0x10f290: 0x2402fe3f  addiu       $v0, $zero, -0x1C1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966847));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f28c) {
            ctx->pc = 0x10F2CCu;
            goto label_10f2cc;
        }
    }
    ctx->pc = 0x10F294u;
    // 0x10f294: 0x0  nop
    ctx->pc = 0x10f294u;
    // NOP
label_10f298:
    // 0x10f298: 0x32220040  andi        $v0, $s1, 0x40
    ctx->pc = 0x10f298u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)64);
    // 0x10f29c: 0x1040001e  beqz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x10F29Cu;
    {
        const bool branch_taken_0x10f29c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F29Cu;
            // 0x10f2a0: 0x2402ffbf  addiu       $v0, $zero, -0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f29c) {
            ctx->pc = 0x10F318u;
            goto label_10f318;
        }
    }
    ctx->pc = 0x10F2A4u;
    // 0x10f2a4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x10F2A4u;
    {
        const bool branch_taken_0x10f2a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F2A4u;
            // 0x10f2a8: 0x2228824  and         $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f2a4) {
            ctx->pc = 0x10F2D0u;
            goto label_10f2d0;
        }
    }
    ctx->pc = 0x10F2ACu;
    // 0x10f2ac: 0x0  nop
    ctx->pc = 0x10f2acu;
    // NOP
label_10f2b0:
    // 0x10f2b0: 0x32220100  andi        $v0, $s1, 0x100
    ctx->pc = 0x10f2b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)256);
    // 0x10f2b4: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x10F2B4u;
    {
        const bool branch_taken_0x10f2b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F2B4u;
            // 0x10f2b8: 0x27a20101  addiu       $v0, $sp, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f2b4) {
            ctx->pc = 0x10F318u;
            goto label_10f318;
        }
    }
    ctx->pc = 0x10F2BCu;
    // 0x10f2bc: 0x16620017  bne         $s3, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x10F2BCu;
    {
        const bool branch_taken_0x10f2bc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        ctx->pc = 0x10F2C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F2BCu;
            // 0x10f2c0: 0x32220080  andi        $v0, $s1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f2bc) {
            ctx->pc = 0x10F31Cu;
            goto label_10f31c;
        }
    }
    ctx->pc = 0x10F2C4u;
    // 0x10f2c4: 0x2402feff  addiu       $v0, $zero, -0x101
    ctx->pc = 0x10f2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967039));
    // 0x10f2c8: 0x241e0010  addiu       $fp, $zero, 0x10
    ctx->pc = 0x10f2c8u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_10f2cc:
    // 0x10f2cc: 0x2228824  and         $s1, $s1, $v0
    ctx->pc = 0x10f2ccu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
label_10f2d0:
    // 0x10f2d0: 0xa2700000  sb          $s0, 0x0($s3)
    ctx->pc = 0x10f2d0u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 16));
    // 0x10f2d4: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x10f2d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x10f2d8: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10f2d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10f2dc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x10f2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10f2e0: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10F2E0u;
    {
        const bool branch_taken_0x10f2e0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x10F2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F2E0u;
            // 0x10f2e4: 0xae420004  sw          $v0, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f2e0) {
            ctx->pc = 0x10F2F8u;
            goto label_10f2f8;
        }
    }
    ctx->pc = 0x10F2E8u;
    // 0x10f2e8: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x10f2e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10f2ec: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10f2ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10f2f0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10F2F0u;
    {
        const bool branch_taken_0x10f2f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F2F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F2F0u;
            // 0x10f2f4: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f2f0) {
            ctx->pc = 0x10F30Cu;
            goto label_10f30c;
        }
    }
    ctx->pc = 0x10F2F8u;
label_10f2f8:
    // 0x10f2f8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10f2f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f2fc: 0xc042814  jal         func_10A050
    ctx->pc = 0x10F2FCu;
    SET_GPR_U32(ctx, 31, 0x10F304u);
    ctx->pc = 0x10F300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F2FCu;
            // 0x10f300: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F304u; }
        if (ctx->pc != 0x10F304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F304u; }
        if (ctx->pc != 0x10F304u) { return; }
    }
    ctx->pc = 0x10F304u;
label_10f304:
    // 0x10f304: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10F304u;
    {
        const bool branch_taken_0x10f304 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F304u;
            // 0x10f308: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f304) {
            ctx->pc = 0x10F318u;
            goto label_10f318;
        }
    }
    ctx->pc = 0x10F30Cu;
label_10f30c:
    // 0x10f30c: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10f30cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x10f310: 0x5680ffb3  bnel        $s4, $zero, . + 4 + (-0x4D << 2)
    ctx->pc = 0x10F310u;
    {
        const bool branch_taken_0x10f310 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f310) {
            ctx->pc = 0x10F314u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F310u;
            // 0x10f314: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F1E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f1e0;
        }
    }
    ctx->pc = 0x10F318u;
label_10f318:
    // 0x10f318: 0x32220080  andi        $v0, $s1, 0x80
    ctx->pc = 0x10f318u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
label_10f31c:
    // 0x10f31c: 0x5040000a  beql        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x10F31Cu;
    {
        const bool branch_taken_0x10f31c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f31c) {
            ctx->pc = 0x10F320u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F31Cu;
            // 0x10f320: 0x8270ffff  lb          $s0, -0x1($s3) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 4294967295)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F348u;
            goto label_10f348;
        }
    }
    ctx->pc = 0x10F324u;
    // 0x10f324: 0x27a30100  addiu       $v1, $sp, 0x100
    ctx->pc = 0x10f324u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x10f328: 0x73102b  sltu        $v0, $v1, $s3
    ctx->pc = 0x10f328u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x10f32c: 0x50400107  beql        $v0, $zero, . + 4 + (0x107 << 2)
    ctx->pc = 0x10F32Cu;
    {
        const bool branch_taken_0x10f32c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f32c) {
            ctx->pc = 0x10F330u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F32Cu;
            // 0x10f330: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10F334u;
    // 0x10f334: 0x8264ffff  lb          $a0, -0x1($s3)
    ctx->pc = 0x10f334u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 4294967295)));
    // 0x10f338: 0xc0433b8  jal         func_10CEE0
    ctx->pc = 0x10F338u;
    SET_GPR_U32(ctx, 31, 0x10F340u);
    ctx->pc = 0x10F33Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F338u;
            // 0x10f33c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CEE0u;
    if (runtime->hasFunction(0x10CEE0u)) {
        auto targetFn = runtime->lookupFunction(0x10CEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F340u; }
        if (ctx->pc != 0x10F340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CEE0_0x10cee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F340u; }
        if (ctx->pc != 0x10F340u) { return; }
    }
    ctx->pc = 0x10F340u;
label_10f340:
    // 0x10f340: 0x10000102  b           . + 4 + (0x102 << 2)
    ctx->pc = 0x10F340u;
    {
        const bool branch_taken_0x10f340 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F340u;
            // 0x10f344: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f340) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10F348u;
label_10f348:
    // 0x10f348: 0x24020078  addiu       $v0, $zero, 0x78
    ctx->pc = 0x10f348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
    // 0x10f34c: 0x12020003  beq         $s0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10F34Cu;
    {
        const bool branch_taken_0x10f34c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x10F350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F34Cu;
            // 0x10f350: 0x24020058  addiu       $v0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f34c) {
            ctx->pc = 0x10F35Cu;
            goto label_10f35c;
        }
    }
    ctx->pc = 0x10F354u;
    // 0x10f354: 0x16020008  bne         $s0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10F354u;
    {
        const bool branch_taken_0x10f354 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x10F358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F354u;
            // 0x10f358: 0x32220008  andi        $v0, $s1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f354) {
            ctx->pc = 0x10F378u;
            goto label_10f378;
        }
    }
    ctx->pc = 0x10F35Cu;
label_10f35c:
    // 0x10f35c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10f35cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f360: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10f360u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f364: 0xc0433b8  jal         func_10CEE0
    ctx->pc = 0x10F364u;
    SET_GPR_U32(ctx, 31, 0x10F36Cu);
    ctx->pc = 0x10F368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F364u;
            // 0x10f368: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CEE0u;
    if (runtime->hasFunction(0x10CEE0u)) {
        auto targetFn = runtime->lookupFunction(0x10CEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F36Cu; }
        if (ctx->pc != 0x10F36Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CEE0_0x10cee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F36Cu; }
        if (ctx->pc != 0x10F36Cu) { return; }
    }
    ctx->pc = 0x10F36Cu;
label_10f36c:
    // 0x10f36c: 0x7ba80290  lq          $t0, 0x290($sp)
    ctx->pc = 0x10f36cu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
    // 0x10f370: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x10f370u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x10f374: 0x32220008  andi        $v0, $s1, 0x8
    ctx->pc = 0x10f374u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)8);
label_10f378:
    // 0x10f378: 0x1440002d  bnez        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x10F378u;
    {
        const bool branch_taken_0x10f378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F378u;
            // 0x10f37c: 0x27a30100  addiu       $v1, $sp, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f378) {
            ctx->pc = 0x10F430u;
            goto label_10f430;
        }
    }
    ctx->pc = 0x10F380u;
    // 0x10f380: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x10f380u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x10f384: 0x27a20100  addiu       $v0, $sp, 0x100
    ctx->pc = 0x10f384u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x10f388: 0x7fa80290  sq          $t0, 0x290($sp)
    ctx->pc = 0x10f388u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
    // 0x10f38c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10f38cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f390: 0x8fa30264  lw          $v1, 0x264($sp)
    ctx->pc = 0x10f390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 612)));
    // 0x10f394: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10f394u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f398: 0x60f809  jalr        $v1
    ctx->pc = 0x10F398u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x10F3A0u);
        ctx->pc = 0x10F39Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F398u;
            // 0x10f39c: 0x3c0302d  daddu       $a2, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10F3A0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10EB38u: goto label_10eb38;
            case 0x10EB3Cu: goto label_10eb3c;
            case 0x10EB78u: goto label_10eb78;
            case 0x10EB90u: goto label_10eb90;
            case 0x10EBA4u: goto label_10eba4;
            case 0x10EBB0u: goto label_10ebb0;
            case 0x10EBD8u: goto label_10ebd8;
            case 0x10EBE8u: goto label_10ebe8;
            case 0x10EC10u: goto label_10ec10;
            case 0x10EC14u: goto label_10ec14;
            case 0x10EC18u: goto label_10ec18;
            case 0x10EC30u: goto label_10ec30;
            case 0x10EC3Cu: goto label_10ec3c;
            case 0x10EC78u: goto label_10ec78;
            case 0x10EC80u: goto label_10ec80;
            case 0x10EC88u: goto label_10ec88;
            case 0x10EC90u: goto label_10ec90;
            case 0x10EC98u: goto label_10ec98;
            case 0x10ECB0u: goto label_10ecb0;
            case 0x10ECB4u: goto label_10ecb4;
            case 0x10ECC8u: goto label_10ecc8;
            case 0x10ECE0u: goto label_10ece0;
            case 0x10ECE4u: goto label_10ece4;
            case 0x10ED00u: goto label_10ed00;
            case 0x10ED0Cu: goto label_10ed0c;
            case 0x10ED18u: goto label_10ed18;
            case 0x10ED28u: goto label_10ed28;
            case 0x10ED30u: goto label_10ed30;
            case 0x10ED38u: goto label_10ed38;
            case 0x10ED48u: goto label_10ed48;
            case 0x10ED60u: goto label_10ed60;
            case 0x10ED70u: goto label_10ed70;
            case 0x10ED78u: goto label_10ed78;
            case 0x10ED90u: goto label_10ed90;
            case 0x10EDC0u: goto label_10edc0;
            case 0x10EDD8u: goto label_10edd8;
            case 0x10EDE8u: goto label_10ede8;
            case 0x10EDF0u: goto label_10edf0;
            case 0x10EE18u: goto label_10ee18;
            case 0x10EE30u: goto label_10ee30;
            case 0x10EE3Cu: goto label_10ee3c;
            case 0x10EE50u: goto label_10ee50;
            case 0x10EE70u: goto label_10ee70;
            case 0x10EE7Cu: goto label_10ee7c;
            case 0x10EE84u: goto label_10ee84;
            case 0x10EE88u: goto label_10ee88;
            case 0x10EEA8u: goto label_10eea8;
            case 0x10EEC8u: goto label_10eec8;
            case 0x10EEE0u: goto label_10eee0;
            case 0x10EF10u: goto label_10ef10;
            case 0x10EF28u: goto label_10ef28;
            case 0x10EF48u: goto label_10ef48;
            case 0x10EF68u: goto label_10ef68;
            case 0x10EF88u: goto label_10ef88;
            case 0x10EFA0u: goto label_10efa0;
            case 0x10EFA4u: goto label_10efa4;
            case 0x10EFE8u: goto label_10efe8;
            case 0x10EFF8u: goto label_10eff8;
            case 0x10F008u: goto label_10f008;
            case 0x10F018u: goto label_10f018;
            case 0x10F01Cu: goto label_10f01c;
            case 0x10F06Cu: goto label_10f06c;
            case 0x10F07Cu: goto label_10f07c;
            case 0x10F0A0u: goto label_10f0a0;
            case 0x10F0B8u: goto label_10f0b8;
            case 0x10F0BCu: goto label_10f0bc;
            case 0x10F10Cu: goto label_10f10c;
            case 0x10F114u: goto label_10f114;
            case 0x10F120u: goto label_10f120;
            case 0x10F130u: goto label_10f130;
            case 0x10F134u: goto label_10f134;
            case 0x10F190u: goto label_10f190;
            case 0x10F198u: goto label_10f198;
            case 0x10F19Cu: goto label_10f19c;
            case 0x10F1B8u: goto label_10f1b8;
            case 0x10F1E0u: goto label_10f1e0;
            case 0x10F210u: goto label_10f210;
            case 0x10F224u: goto label_10f224;
            case 0x10F238u: goto label_10f238;
            case 0x10F258u: goto label_10f258;
            case 0x10F280u: goto label_10f280;
            case 0x10F298u: goto label_10f298;
            case 0x10F2B0u: goto label_10f2b0;
            case 0x10F2CCu: goto label_10f2cc;
            case 0x10F2D0u: goto label_10f2d0;
            case 0x10F2F8u: goto label_10f2f8;
            case 0x10F304u: goto label_10f304;
            case 0x10F30Cu: goto label_10f30c;
            case 0x10F318u: goto label_10f318;
            case 0x10F31Cu: goto label_10f31c;
            case 0x10F340u: goto label_10f340;
            case 0x10F348u: goto label_10f348;
            case 0x10F35Cu: goto label_10f35c;
            case 0x10F36Cu: goto label_10f36c;
            case 0x10F378u: goto label_10f378;
            case 0x10F3A0u: goto label_10f3a0;
            case 0x10F3D0u: goto label_10f3d0;
            case 0x10F3F0u: goto label_10f3f0;
            case 0x10F410u: goto label_10f410;
            case 0x10F420u: goto label_10f420;
            case 0x10F430u: goto label_10f430;
            case 0x10F440u: goto label_10f440;
            case 0x10F470u: goto label_10f470;
            case 0x10F498u: goto label_10f498;
            case 0x10F4B0u: goto label_10f4b0;
            case 0x10F4C0u: goto label_10f4c0;
            case 0x10F4D8u: goto label_10f4d8;
            case 0x10F4F0u: goto label_10f4f0;
            case 0x10F510u: goto label_10f510;
            case 0x10F52Cu: goto label_10f52c;
            case 0x10F538u: goto label_10f538;
            case 0x10F544u: goto label_10f544;
            case 0x10F568u: goto label_10f568;
            case 0x10F578u: goto label_10f578;
            case 0x10F584u: goto label_10f584;
            case 0x10F58Cu: goto label_10f58c;
            case 0x10F598u: goto label_10f598;
            case 0x10F59Cu: goto label_10f59c;
            case 0x10F5C0u: goto label_10f5c0;
            case 0x10F5CCu: goto label_10f5cc;
            case 0x10F5E8u: goto label_10f5e8;
            case 0x10F618u: goto label_10f618;
            case 0x10F628u: goto label_10f628;
            case 0x10F63Cu: goto label_10f63c;
            case 0x10F644u: goto label_10f644;
            case 0x10F678u: goto label_10f678;
            case 0x10F690u: goto label_10f690;
            case 0x10F69Cu: goto label_10f69c;
            case 0x10F6C8u: goto label_10f6c8;
            case 0x10F6CCu: goto label_10f6cc;
            case 0x10F6DCu: goto label_10f6dc;
            case 0x10F6F8u: goto label_10f6f8;
            case 0x10F710u: goto label_10f710;
            case 0x10F720u: goto label_10f720;
            case 0x10F728u: goto label_10f728;
            case 0x10F738u: goto label_10f738;
            case 0x10F73Cu: goto label_10f73c;
            case 0x10F748u: goto label_10f748;
            case 0x10F74Cu: goto label_10f74c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10F3A0u; }
            if (ctx->pc != 0x10F3A0u) { return; }
        }
        }
    }
    ctx->pc = 0x10F3A0u;
label_10f3a0:
    // 0x10f3a0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10f3a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f3a4: 0x32220010  andi        $v0, $s1, 0x10
    ctx->pc = 0x10f3a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)16);
    // 0x10f3a8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10F3A8u;
    {
        const bool branch_taken_0x10f3a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F3ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F3A8u;
            // 0x10f3ac: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f3a8) {
            ctx->pc = 0x10F3D0u;
            goto label_10f3d0;
        }
    }
    ctx->pc = 0x10F3B0u;
    // 0x10f3b0: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x10f3b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f3b4: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10f3b4u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10f3b8: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x10f3b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10f3bc: 0x5183c  dsll32      $v1, $a1, 0
    ctx->pc = 0x10f3bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 0));
    // 0x10f3c0: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x10f3c0u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x10f3c4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x10F3C4u;
    {
        const bool branch_taken_0x10f3c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F3C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F3C4u;
            // 0x10f3c8: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f3c4) {
            ctx->pc = 0x10F420u;
            goto label_10f420;
        }
    }
    ctx->pc = 0x10F3CCu;
    // 0x10f3cc: 0x0  nop
    ctx->pc = 0x10f3ccu;
    // NOP
label_10f3d0:
    // 0x10f3d0: 0x32220004  andi        $v0, $s1, 0x4
    ctx->pc = 0x10f3d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)4);
    // 0x10f3d4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10F3D4u;
    {
        const bool branch_taken_0x10f3d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F3D4u;
            // 0x10f3d8: 0x2e0182d  daddu       $v1, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f3d4) {
            ctx->pc = 0x10F3F0u;
            goto label_10f3f0;
        }
    }
    ctx->pc = 0x10F3DCu;
    // 0x10f3dc: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10f3dcu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10f3e0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x10f3e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10f3e4: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x10f3e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x10f3e8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x10F3E8u;
    {
        const bool branch_taken_0x10f3e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F3E8u;
            // 0x10f3ec: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f3e8) {
            ctx->pc = 0x10F420u;
            goto label_10f420;
        }
    }
    ctx->pc = 0x10F3F0u;
label_10f3f0:
    // 0x10f3f0: 0x32220001  andi        $v0, $s1, 0x1
    ctx->pc = 0x10f3f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
    // 0x10f3f4: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10F3F4u;
    {
        const bool branch_taken_0x10f3f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f3f4) {
            ctx->pc = 0x10F3F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F3F4u;
            // 0x10f3f8: 0x26f70008  addiu       $s7, $s7, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F410u;
            goto label_10f410;
        }
    }
    ctx->pc = 0x10F3FCu;
    // 0x10f3fc: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x10f3fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f400: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10f400u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10f404: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x10f404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10f408: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10F408u;
    {
        const bool branch_taken_0x10f408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F40Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F408u;
            // 0x10f40c: 0xfc450000  sd          $a1, 0x0($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f408) {
            ctx->pc = 0x10F420u;
            goto label_10f420;
        }
    }
    ctx->pc = 0x10F410u;
label_10f410:
    // 0x10f410: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x10f410u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10f414: 0x5103c  dsll32      $v0, $a1, 0
    ctx->pc = 0x10f414u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 0));
    // 0x10f418: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10f418u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10f41c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x10f41cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_10f420:
    // 0x10f420: 0x8fa40260  lw          $a0, 0x260($sp)
    ctx->pc = 0x10f420u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x10f424: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10f424u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10f428: 0xafa40260  sw          $a0, 0x260($sp)
    ctx->pc = 0x10f428u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 608), GPR_U32(ctx, 4));
    // 0x10f42c: 0x27a30100  addiu       $v1, $sp, 0x100
    ctx->pc = 0x10f42cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
label_10f430:
    // 0x10f430: 0x2631023  subu        $v0, $s3, $v1
    ctx->pc = 0x10f430u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x10f434: 0x1000fdc0  b           . + 4 + (-0x240 << 2)
    ctx->pc = 0x10F434u;
    {
        const bool branch_taken_0x10f434 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F434u;
            // 0x10f438: 0x1024021  addu        $t0, $t0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f434) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10F43Cu;
    // 0x10f43c: 0x0  nop
    ctx->pc = 0x10f43cu;
    // NOP
label_10f440:
    // 0x10f440: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10f440u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
    // 0x10f444: 0x2403015c  addiu       $v1, $zero, 0x15C
    ctx->pc = 0x10f444u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 348));
    // 0x10f448: 0x2e82015d  sltiu       $v0, $s4, 0x15D
    ctx->pc = 0x10f448u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)(int64_t)(int32_t)349) ? 1 : 0);
    // 0x10f44c: 0x27a40100  addiu       $a0, $sp, 0x100
    ctx->pc = 0x10f44cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x10f450: 0x62a00a  movz        $s4, $v1, $v0
    ctx->pc = 0x10f450u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 3));
    // 0x10f454: 0x363103c0  ori         $s1, $s1, 0x3C0
    ctx->pc = 0x10f454u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)960);
    // 0x10f458: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x10f458u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x10f45c: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x10f45cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f460: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x10f460u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f464: 0x12800049  beqz        $s4, . + 4 + (0x49 << 2)
    ctx->pc = 0x10F464u;
    {
        const bool branch_taken_0x10f464 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F464u;
            // 0x10f468: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f464) {
            ctx->pc = 0x10F58Cu;
            goto label_10f58c;
        }
    }
    ctx->pc = 0x10F46Cu;
    // 0x10f46c: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x10f46cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_10f470:
    // 0x10f470: 0x90500000  lbu         $s0, 0x0($v0)
    ctx->pc = 0x10f470u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10f474: 0x2603ffd5  addiu       $v1, $s0, -0x2B
    ctx->pc = 0x10f474u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967253));
    // 0x10f478: 0x2c62003b  sltiu       $v0, $v1, 0x3B
    ctx->pc = 0x10f478u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)59) ? 1 : 0);
    // 0x10f47c: 0x10400043  beqz        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x10F47Cu;
    {
        const bool branch_taken_0x10f47c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F47Cu;
            // 0x10f480: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f47c) {
            ctx->pc = 0x10F58Cu;
            goto label_10f58c;
        }
    }
    ctx->pc = 0x10F484u;
    // 0x10f484: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x10f484u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x10f488: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10f488u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10f48c: 0x8c6380b0  lw          $v1, -0x7F50($v1)
    ctx->pc = 0x10f48cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294934704)));
    // 0x10f490: 0x600008  jr          $v1
    ctx->pc = 0x10F490u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10F498u: goto label_10f498;
            case 0x10F4B0u: goto label_10f4b0;
            case 0x10F4C0u: goto label_10f4c0;
            case 0x10F4D8u: goto label_10f4d8;
            case 0x10F4F0u: goto label_10f4f0;
            case 0x10F58Cu: goto label_10f58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10F498u;
label_10f498:
    // 0x10f498: 0x32220080  andi        $v0, $s1, 0x80
    ctx->pc = 0x10f498u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
    // 0x10f49c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10F49Cu;
    {
        const bool branch_taken_0x10f49c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F4A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F49Cu;
            // 0x10f4a0: 0x2402ffbf  addiu       $v0, $zero, -0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f49c) {
            ctx->pc = 0x10F4B0u;
            goto label_10f4b0;
        }
    }
    ctx->pc = 0x10F4A4u;
    // 0x10f4a4: 0x66d60001  daddiu      $s6, $s6, 0x1
    ctx->pc = 0x10f4a4u;
    SET_GPR_S64(ctx, 22, (int64_t)GPR_S64(ctx, 22) + (int64_t)(int32_t)1);
    // 0x10f4a8: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x10F4A8u;
    {
        const bool branch_taken_0x10f4a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F4ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F4A8u;
            // 0x10f4ac: 0x2228824  and         $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f4a8) {
            ctx->pc = 0x10F544u;
            goto label_10f544;
        }
    }
    ctx->pc = 0x10F4B0u;
label_10f4b0:
    // 0x10f4b0: 0x2402ff3f  addiu       $v0, $zero, -0xC1
    ctx->pc = 0x10f4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967103));
    // 0x10f4b4: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x10F4B4u;
    {
        const bool branch_taken_0x10f4b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F4B4u;
            // 0x10f4b8: 0x2228824  and         $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f4b4) {
            ctx->pc = 0x10F538u;
            goto label_10f538;
        }
    }
    ctx->pc = 0x10F4BCu;
    // 0x10f4bc: 0x0  nop
    ctx->pc = 0x10f4bcu;
    // NOP
label_10f4c0:
    // 0x10f4c0: 0x32220040  andi        $v0, $s1, 0x40
    ctx->pc = 0x10f4c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)64);
    // 0x10f4c4: 0x10400031  beqz        $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x10F4C4u;
    {
        const bool branch_taken_0x10f4c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F4C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F4C4u;
            // 0x10f4c8: 0x2402ffbf  addiu       $v0, $zero, -0x41 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f4c4) {
            ctx->pc = 0x10F58Cu;
            goto label_10f58c;
        }
    }
    ctx->pc = 0x10F4CCu;
    // 0x10f4cc: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x10F4CCu;
    {
        const bool branch_taken_0x10f4cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F4D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F4CCu;
            // 0x10f4d0: 0x2228824  and         $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f4cc) {
            ctx->pc = 0x10F538u;
            goto label_10f538;
        }
    }
    ctx->pc = 0x10F4D4u;
    // 0x10f4d4: 0x0  nop
    ctx->pc = 0x10f4d4u;
    // NOP
label_10f4d8:
    // 0x10f4d8: 0x32220100  andi        $v0, $s1, 0x100
    ctx->pc = 0x10f4d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)256);
    // 0x10f4dc: 0x1040002b  beqz        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x10F4DCu;
    {
        const bool branch_taken_0x10f4dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F4E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F4DCu;
            // 0x10f4e0: 0x2402febf  addiu       $v0, $zero, -0x141 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966975));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f4dc) {
            ctx->pc = 0x10F58Cu;
            goto label_10f58c;
        }
    }
    ctx->pc = 0x10F4E4u;
    // 0x10f4e4: 0xffb60268  sd          $s6, 0x268($sp)
    ctx->pc = 0x10f4e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 22));
    // 0x10f4e8: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x10F4E8u;
    {
        const bool branch_taken_0x10f4e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F4ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F4E8u;
            // 0x10f4ec: 0x2228824  and         $s1, $s1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f4e8) {
            ctx->pc = 0x10F538u;
            goto label_10f538;
        }
    }
    ctx->pc = 0x10F4F0u;
label_10f4f0:
    // 0x10f4f0: 0x32230280  andi        $v1, $s1, 0x280
    ctx->pc = 0x10f4f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)640);
    // 0x10f4f4: 0x24020200  addiu       $v0, $zero, 0x200
    ctx->pc = 0x10f4f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x10f4f8: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10F4F8u;
    {
        const bool branch_taken_0x10f4f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x10F4FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F4F8u;
            // 0x10f4fc: 0x32220200  andi        $v0, $s1, 0x200 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)512);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f4f8) {
            ctx->pc = 0x10F510u;
            goto label_10f510;
        }
    }
    ctx->pc = 0x10F500u;
    // 0x10f500: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x10F500u;
    {
        const bool branch_taken_0x10f500 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f500) {
            ctx->pc = 0x10F58Cu;
            goto label_10f58c;
        }
    }
    ctx->pc = 0x10F508u;
    // 0x10f508: 0x12c00024  beqz        $s6, . + 4 + (0x24 << 2)
    ctx->pc = 0x10F508u;
    {
        const bool branch_taken_0x10f508 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F50Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F508u;
            // 0x10f50c: 0x32220080  andi        $v0, $s1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f508) {
            ctx->pc = 0x10F59Cu;
            goto label_10f59c;
        }
    }
    ctx->pc = 0x10F510u;
label_10f510:
    // 0x10f510: 0x32220100  andi        $v0, $s1, 0x100
    ctx->pc = 0x10f510u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)256);
    // 0x10f514: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10F514u;
    {
        const bool branch_taken_0x10f514 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F514u;
            // 0x10f518: 0x2402fcff  addiu       $v0, $zero, -0x301 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966527));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f514) {
            ctx->pc = 0x10F52Cu;
            goto label_10f52c;
        }
    }
    ctx->pc = 0x10F51Cu;
    // 0x10f51c: 0xdfa20268  ld          $v0, 0x268($sp)
    ctx->pc = 0x10f51cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x10f520: 0xafb30270  sw          $s3, 0x270($sp)
    ctx->pc = 0x10f520u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 624), GPR_U32(ctx, 19));
    // 0x10f524: 0x2c2382f  dsubu       $a3, $s6, $v0
    ctx->pc = 0x10f524u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 22) - GPR_U64(ctx, 2));
    // 0x10f528: 0x2402fcff  addiu       $v0, $zero, -0x301
    ctx->pc = 0x10f528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966527));
label_10f52c:
    // 0x10f52c: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x10f52cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f530: 0x2221024  and         $v0, $s1, $v0
    ctx->pc = 0x10f530u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
    // 0x10f534: 0x345100c0  ori         $s1, $v0, 0xC0
    ctx->pc = 0x10f534u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)192);
label_10f538:
    // 0x10f538: 0xa2700000  sb          $s0, 0x0($s3)
    ctx->pc = 0x10f538u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 16));
    // 0x10f53c: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x10f53cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x10f540: 0x2694ffff  addiu       $s4, $s4, -0x1
    ctx->pc = 0x10f540u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
label_10f544:
    // 0x10f544: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x10f544u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x10f548: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x10f548u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x10f54c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x10f54cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10f550: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10F550u;
    {
        const bool branch_taken_0x10f550 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x10F554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F550u;
            // 0x10f554: 0xae420004  sw          $v0, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f550) {
            ctx->pc = 0x10F568u;
            goto label_10f568;
        }
    }
    ctx->pc = 0x10F558u;
    // 0x10f558: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x10f558u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10f55c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10f55cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10f560: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10F560u;
    {
        const bool branch_taken_0x10f560 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F560u;
            // 0x10f564: 0xae420000  sw          $v0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f560) {
            ctx->pc = 0x10F584u;
            goto label_10f584;
        }
    }
    ctx->pc = 0x10F568u;
label_10f568:
    // 0x10f568: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x10f568u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f56c: 0x7fa70280  sq          $a3, 0x280($sp)
    ctx->pc = 0x10f56cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 640), GPR_VEC(ctx, 7));
    // 0x10f570: 0xc042814  jal         func_10A050
    ctx->pc = 0x10F570u;
    SET_GPR_U32(ctx, 31, 0x10F578u);
    ctx->pc = 0x10F574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F570u;
            // 0x10f574: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F578u; }
        if (ctx->pc != 0x10F578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F578u; }
        if (ctx->pc != 0x10F578u) { return; }
    }
    ctx->pc = 0x10F578u;
label_10f578:
    // 0x10f578: 0x7ba70280  lq          $a3, 0x280($sp)
    ctx->pc = 0x10f578u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x10f57c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10F57Cu;
    {
        const bool branch_taken_0x10f57c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F57Cu;
            // 0x10f580: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f57c) {
            ctx->pc = 0x10F58Cu;
            goto label_10f58c;
        }
    }
    ctx->pc = 0x10F584u;
label_10f584:
    // 0x10f584: 0x5680ffba  bnel        $s4, $zero, . + 4 + (-0x46 << 2)
    ctx->pc = 0x10F584u;
    {
        const bool branch_taken_0x10f584 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f584) {
            ctx->pc = 0x10F588u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F584u;
            // 0x10f588: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F470u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f470;
        }
    }
    ctx->pc = 0x10F58Cu;
label_10f58c:
    // 0x10f58c: 0x12c00002  beqz        $s6, . + 4 + (0x2 << 2)
    ctx->pc = 0x10F58Cu;
    {
        const bool branch_taken_0x10f58c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F58Cu;
            // 0x10f590: 0x2402ff7f  addiu       $v0, $zero, -0x81 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f58c) {
            ctx->pc = 0x10F598u;
            goto label_10f598;
        }
    }
    ctx->pc = 0x10F594u;
    // 0x10f594: 0x2228824  and         $s1, $s1, $v0
    ctx->pc = 0x10f594u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 2));
label_10f598:
    // 0x10f598: 0x32220080  andi        $v0, $s1, 0x80
    ctx->pc = 0x10f598u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)128);
label_10f59c:
    // 0x10f59c: 0x10400029  beqz        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x10F59Cu;
    {
        const bool branch_taken_0x10f59c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F5A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F59Cu;
            // 0x10f5a0: 0x32220200  andi        $v0, $s1, 0x200 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)512);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f59c) {
            ctx->pc = 0x10F644u;
            goto label_10f644;
        }
    }
    ctx->pc = 0x10F5A4u;
    // 0x10f5a4: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x10F5A4u;
    {
        const bool branch_taken_0x10f5a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f5a4) {
            ctx->pc = 0x10F5A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F5A4u;
            // 0x10f5a8: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F5E8u;
            goto label_10f5e8;
        }
    }
    ctx->pc = 0x10F5ACu;
    // 0x10f5ac: 0x27a30100  addiu       $v1, $sp, 0x100
    ctx->pc = 0x10f5acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x10f5b0: 0x73102b  sltu        $v0, $v1, $s3
    ctx->pc = 0x10f5b0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x10f5b4: 0x10400065  beqz        $v0, . + 4 + (0x65 << 2)
    ctx->pc = 0x10F5B4u;
    {
        const bool branch_taken_0x10f5b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F5B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F5B4u;
            // 0x10f5b8: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f5b4) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10F5BCu;
    // 0x10f5bc: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x10f5bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
label_10f5c0:
    // 0x10f5c0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10f5c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f5c4: 0xc0433b8  jal         func_10CEE0
    ctx->pc = 0x10F5C4u;
    SET_GPR_U32(ctx, 31, 0x10F5CCu);
    ctx->pc = 0x10F5C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F5C4u;
            // 0x10f5c8: 0x82640000  lb          $a0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CEE0u;
    if (runtime->hasFunction(0x10CEE0u)) {
        auto targetFn = runtime->lookupFunction(0x10CEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F5CCu; }
        if (ctx->pc != 0x10F5CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CEE0_0x10cee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F5CCu; }
        if (ctx->pc != 0x10F5CCu) { return; }
    }
    ctx->pc = 0x10F5CCu;
label_10f5cc:
    // 0x10f5cc: 0x27a40100  addiu       $a0, $sp, 0x100
    ctx->pc = 0x10f5ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x10f5d0: 0x93182b  sltu        $v1, $a0, $s3
    ctx->pc = 0x10f5d0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x10f5d4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10F5D4u;
    {
        const bool branch_taken_0x10f5d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F5D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F5D4u;
            // 0x10f5d8: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f5d4) {
            ctx->pc = 0x10F5C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10f5c0;
        }
    }
    ctx->pc = 0x10F5DCu;
    // 0x10f5dc: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x10F5DCu;
    {
        const bool branch_taken_0x10f5dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F5E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F5DCu;
            // 0x10f5e0: 0x8fa20260  lw          $v0, 0x260($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f5dc) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10F5E4u;
    // 0x10f5e4: 0x0  nop
    ctx->pc = 0x10f5e4u;
    // NOP
label_10f5e8:
    // 0x10f5e8: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x10f5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x10f5ec: 0x82700000  lb          $s0, 0x0($s3)
    ctx->pc = 0x10f5ecu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x10f5f0: 0x1202000d  beq         $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x10F5F0u;
    {
        const bool branch_taken_0x10f5f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x10F5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F5F0u;
            // 0x10f5f4: 0x2508ffff  addiu       $t0, $t0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f5f0) {
            ctx->pc = 0x10F628u;
            goto label_10f628;
        }
    }
    ctx->pc = 0x10F5F8u;
    // 0x10f5f8: 0x24020045  addiu       $v0, $zero, 0x45
    ctx->pc = 0x10f5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x10f5fc: 0x1202000a  beq         $s0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10F5FCu;
    {
        const bool branch_taken_0x10f5fc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x10F600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F5FCu;
            // 0x10f600: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f5fc) {
            ctx->pc = 0x10F628u;
            goto label_10f628;
        }
    }
    ctx->pc = 0x10F604u;
    // 0x10f604: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10f604u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f608: 0x7fa70280  sq          $a3, 0x280($sp)
    ctx->pc = 0x10f608u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 640), GPR_VEC(ctx, 7));
    // 0x10f60c: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x10f60cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x10f610: 0xc0433b8  jal         func_10CEE0
    ctx->pc = 0x10F610u;
    SET_GPR_U32(ctx, 31, 0x10F618u);
    ctx->pc = 0x10F614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F610u;
            // 0x10f614: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CEE0u;
    if (runtime->hasFunction(0x10CEE0u)) {
        auto targetFn = runtime->lookupFunction(0x10CEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F618u; }
        if (ctx->pc != 0x10F618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CEE0_0x10cee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F618u; }
        if (ctx->pc != 0x10F618u) { return; }
    }
    ctx->pc = 0x10F618u;
label_10f618:
    // 0x10f618: 0x7ba80290  lq          $t0, 0x290($sp)
    ctx->pc = 0x10f618u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
    // 0x10f61c: 0x82700000  lb          $s0, 0x0($s3)
    ctx->pc = 0x10f61cu;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x10f620: 0x7ba70280  lq          $a3, 0x280($sp)
    ctx->pc = 0x10f620u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x10f624: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x10f624u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
label_10f628:
    // 0x10f628: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10f628u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f62c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10f62cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f630: 0x7fa70280  sq          $a3, 0x280($sp)
    ctx->pc = 0x10f630u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 640), GPR_VEC(ctx, 7));
    // 0x10f634: 0xc0433b8  jal         func_10CEE0
    ctx->pc = 0x10F634u;
    SET_GPR_U32(ctx, 31, 0x10F63Cu);
    ctx->pc = 0x10F638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F634u;
            // 0x10f638: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CEE0u;
    if (runtime->hasFunction(0x10CEE0u)) {
        auto targetFn = runtime->lookupFunction(0x10CEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F63Cu; }
        if (ctx->pc != 0x10F63Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CEE0_0x10cee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F63Cu; }
        if (ctx->pc != 0x10F63Cu) { return; }
    }
    ctx->pc = 0x10F63Cu;
label_10f63c:
    // 0x10f63c: 0x7ba80290  lq          $t0, 0x290($sp)
    ctx->pc = 0x10f63cu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
    // 0x10f640: 0x7ba70280  lq          $a3, 0x280($sp)
    ctx->pc = 0x10f640u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 640)));
label_10f644:
    // 0x10f644: 0x32220008  andi        $v0, $s1, 0x8
    ctx->pc = 0x10f644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)8);
    // 0x10f648: 0x5440fd3c  bnel        $v0, $zero, . + 4 + (-0x2C4 << 2)
    ctx->pc = 0x10F648u;
    {
        const bool branch_taken_0x10f648 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10f648) {
            ctx->pc = 0x10F64Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F648u;
            // 0x10f64c: 0x82a30000  lb          $v1, 0x0($s5) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EB3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb3c;
        }
    }
    ctx->pc = 0x10F650u;
    // 0x10f650: 0x32230300  andi        $v1, $s1, 0x300
    ctx->pc = 0x10f650u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)768);
    // 0x10f654: 0x24020200  addiu       $v0, $zero, 0x200
    ctx->pc = 0x10f654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x10f658: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10F658u;
    {
        const bool branch_taken_0x10f658 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10F65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F658u;
            // 0x10f65c: 0xa2600000  sb          $zero, 0x0($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f658) {
            ctx->pc = 0x10F678u;
            goto label_10f678;
        }
    }
    ctx->pc = 0x10F660u;
    // 0x10f660: 0xdfa20268  ld          $v0, 0x268($sp)
    ctx->pc = 0x10f660u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x10f664: 0xafb30270  sw          $s3, 0x270($sp)
    ctx->pc = 0x10f664u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 624), GPR_U32(ctx, 19));
    // 0x10f668: 0x2c2382f  dsubu       $a3, $s6, $v0
    ctx->pc = 0x10f668u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 22) - GPR_U64(ctx, 2));
    // 0x10f66c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x10F66Cu;
    {
        const bool branch_taken_0x10f66c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F66Cu;
            // 0x10f670: 0x7302f  dsubu       $a2, $zero, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) - GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f66c) {
            ctx->pc = 0x10F69Cu;
            goto label_10f69c;
        }
    }
    ctx->pc = 0x10F674u;
    // 0x10f674: 0x0  nop
    ctx->pc = 0x10f674u;
    // NOP
label_10f678:
    // 0x10f678: 0x10e00014  beqz        $a3, . + 4 + (0x14 << 2)
    ctx->pc = 0x10F678u;
    {
        const bool branch_taken_0x10f678 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F678u;
            // 0x10f67c: 0x8fa30270  lw          $v1, 0x270($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 624)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f678) {
            ctx->pc = 0x10F6CCu;
            goto label_10f6cc;
        }
    }
    ctx->pc = 0x10F680u;
    // 0x10f680: 0x7fa70280  sq          $a3, 0x280($sp)
    ctx->pc = 0x10f680u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 640), GPR_VEC(ctx, 7));
    // 0x10f684: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x10f684u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10f688: 0xc040dea  jal         func_1037A8
    ctx->pc = 0x10F688u;
    SET_GPR_U32(ctx, 31, 0x10F690u);
    ctx->pc = 0x10F68Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F688u;
            // 0x10f68c: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1037A8u;
    if (runtime->hasFunction(0x1037A8u)) {
        auto targetFn = runtime->lookupFunction(0x1037A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F690u; }
        if (ctx->pc != 0x10F690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001037A8_0x1037a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F690u; }
        if (ctx->pc != 0x10F690u) { return; }
    }
    ctx->pc = 0x10F690u;
label_10f690:
    // 0x10f690: 0x7ba70280  lq          $a3, 0x280($sp)
    ctx->pc = 0x10f690u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x10f694: 0x7ba80290  lq          $t0, 0x290($sp)
    ctx->pc = 0x10f694u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
    // 0x10f698: 0x47302f  dsubu       $a2, $v0, $a3
    ctx->pc = 0x10f698u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) - GPR_U64(ctx, 7));
label_10f69c:
    // 0x10f69c: 0x10e0000b  beqz        $a3, . + 4 + (0xB << 2)
    ctx->pc = 0x10F69Cu;
    {
        const bool branch_taken_0x10f69c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F6A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F69Cu;
            // 0x10f6a0: 0x27a20249  addiu       $v0, $sp, 0x249 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 585));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f69c) {
            ctx->pc = 0x10F6CCu;
            goto label_10f6cc;
        }
    }
    ctx->pc = 0x10F6A4u;
    // 0x10f6a4: 0x8fa40270  lw          $a0, 0x270($sp)
    ctx->pc = 0x10f6a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x10f6a8: 0x27a30248  addiu       $v1, $sp, 0x248
    ctx->pc = 0x10f6a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 584));
    // 0x10f6ac: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x10f6acu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x10f6b0: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x10f6b0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x10f6b4: 0x24a57d58  addiu       $a1, $a1, 0x7D58
    ctx->pc = 0x10f6b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32088));
    // 0x10f6b8: 0x62200a  movz        $a0, $v1, $v0
    ctx->pc = 0x10f6b8u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x10f6bc: 0x7fa80290  sq          $t0, 0x290($sp)
    ctx->pc = 0x10f6bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
    // 0x10f6c0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x10F6C0u;
    SET_GPR_U32(ctx, 31, 0x10F6C8u);
    ctx->pc = 0x10F6C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F6C0u;
            // 0x10f6c4: 0xafa40270  sw          $a0, 0x270($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 624), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F6C8u; }
        if (ctx->pc != 0x10F6C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F6C8u; }
        if (ctx->pc != 0x10F6C8u) { return; }
    }
    ctx->pc = 0x10F6C8u;
label_10f6c8:
    // 0x10f6c8: 0x7ba80290  lq          $t0, 0x290($sp)
    ctx->pc = 0x10f6c8u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
label_10f6cc:
    // 0x10f6cc: 0x27a20100  addiu       $v0, $sp, 0x100
    ctx->pc = 0x10f6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
    // 0x10f6d0: 0x7fa80290  sq          $t0, 0x290($sp)
    ctx->pc = 0x10f6d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
    // 0x10f6d4: 0xc040dda  jal         func_103768
    ctx->pc = 0x10F6D4u;
    SET_GPR_U32(ctx, 31, 0x10F6DCu);
    ctx->pc = 0x10F6D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F6D4u;
            // 0x10f6d8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103768u;
    if (runtime->hasFunction(0x103768u)) {
        auto targetFn = runtime->lookupFunction(0x103768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F6DCu; }
        if (ctx->pc != 0x10F6DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103768_0x103768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F6DCu; }
        if (ctx->pc != 0x10F6DCu) { return; }
    }
    ctx->pc = 0x10F6DCu;
label_10f6dc:
    // 0x10f6dc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10f6dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f6e0: 0x32220001  andi        $v0, $s1, 0x1
    ctx->pc = 0x10f6e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)1);
    // 0x10f6e4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10F6E4u;
    {
        const bool branch_taken_0x10f6e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10F6E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F6E4u;
            // 0x10f6e8: 0x7ba80290  lq          $t0, 0x290($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f6e4) {
            ctx->pc = 0x10F6F8u;
            goto label_10f6f8;
        }
    }
    ctx->pc = 0x10F6ECu;
    // 0x10f6ec: 0x32220002  andi        $v0, $s1, 0x2
    ctx->pc = 0x10f6ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)2);
    // 0x10f6f0: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x10F6F0u;
    {
        const bool branch_taken_0x10f6f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10f6f0) {
            ctx->pc = 0x10F6F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10F6F0u;
            // 0x10f6f4: 0x2e0102d  daddu       $v0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10F710u;
            goto label_10f710;
        }
    }
    ctx->pc = 0x10F6F8u;
label_10f6f8:
    // 0x10f6f8: 0x2e0182d  daddu       $v1, $s7, $zero
    ctx->pc = 0x10f6f8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10f6fc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x10f6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10f700: 0xfc440000  sd          $a0, 0x0($v0)
    ctx->pc = 0x10f700u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 4));
    // 0x10f704: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10F704u;
    {
        const bool branch_taken_0x10f704 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F704u;
            // 0x10f708: 0x26f70008  addiu       $s7, $s7, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f704) {
            ctx->pc = 0x10F728u;
            goto label_10f728;
        }
    }
    ctx->pc = 0x10F70Cu;
    // 0x10f70c: 0x0  nop
    ctx->pc = 0x10f70cu;
    // NOP
label_10f710:
    // 0x10f710: 0x26f70008  addiu       $s7, $s7, 0x8
    ctx->pc = 0x10f710u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 8));
    // 0x10f714: 0x8c500000  lw          $s0, 0x0($v0)
    ctx->pc = 0x10f714u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10f718: 0xc04491c  jal         func_112470
    ctx->pc = 0x10F718u;
    SET_GPR_U32(ctx, 31, 0x10F720u);
    ctx->pc = 0x10F71Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10F718u;
            // 0x10f71c: 0x7fa80290  sq          $t0, 0x290($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 656), GPR_VEC(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F720u; }
        if (ctx->pc != 0x10F720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10F720u; }
        if (ctx->pc != 0x10F720u) { return; }
    }
    ctx->pc = 0x10F720u;
label_10f720:
    // 0x10f720: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x10f720u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x10f724: 0x7ba80290  lq          $t0, 0x290($sp)
    ctx->pc = 0x10f724u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 656)));
label_10f728:
    // 0x10f728: 0x8fa30260  lw          $v1, 0x260($sp)
    ctx->pc = 0x10f728u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x10f72c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10f72cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10f730: 0x1000fd01  b           . + 4 + (-0x2FF << 2)
    ctx->pc = 0x10F730u;
    {
        const bool branch_taken_0x10f730 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F730u;
            // 0x10f734: 0xafa30260  sw          $v1, 0x260($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 608), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f730) {
            ctx->pc = 0x10EB38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eb38;
        }
    }
    ctx->pc = 0x10F738u;
label_10f738:
    // 0x10f738: 0x8fa40260  lw          $a0, 0x260($sp)
    ctx->pc = 0x10f738u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
label_10f73c:
    // 0x10f73c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10f73cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10f740: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10F740u;
    {
        const bool branch_taken_0x10f740 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10F744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F740u;
            // 0x10f744: 0x84100b  movn        $v0, $a0, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10f740) {
            ctx->pc = 0x10F74Cu;
            goto label_10f74c;
        }
    }
    ctx->pc = 0x10F748u;
label_10f748:
    // 0x10f748: 0x8fa20260  lw          $v0, 0x260($sp)
    ctx->pc = 0x10f748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 608)));
label_10f74c:
    // 0x10f74c: 0xdfb002a0  ld          $s0, 0x2A0($sp)
    ctx->pc = 0x10f74cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 672)));
    // 0x10f750: 0xdfb102a8  ld          $s1, 0x2A8($sp)
    ctx->pc = 0x10f750u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 680)));
    // 0x10f754: 0xdfb202b0  ld          $s2, 0x2B0($sp)
    ctx->pc = 0x10f754u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 688)));
    // 0x10f758: 0xdfb302b8  ld          $s3, 0x2B8($sp)
    ctx->pc = 0x10f758u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 696)));
    // 0x10f75c: 0xdfb402c0  ld          $s4, 0x2C0($sp)
    ctx->pc = 0x10f75cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 704)));
    // 0x10f760: 0xdfb502c8  ld          $s5, 0x2C8($sp)
    ctx->pc = 0x10f760u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 712)));
    // 0x10f764: 0xdfb602d0  ld          $s6, 0x2D0($sp)
    ctx->pc = 0x10f764u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 720)));
    // 0x10f768: 0xdfb702d8  ld          $s7, 0x2D8($sp)
    ctx->pc = 0x10f768u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 728)));
    // 0x10f76c: 0xdfbe02e0  ld          $fp, 0x2E0($sp)
    ctx->pc = 0x10f76cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 736)));
    // 0x10f770: 0xdfbf02e8  ld          $ra, 0x2E8($sp)
    ctx->pc = 0x10f770u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 744)));
    // 0x10f774: 0x3e00008  jr          $ra
    ctx->pc = 0x10F774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10F778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10F774u;
            // 0x10f778: 0x27bd02f0  addiu       $sp, $sp, 0x2F0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 752));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10EB38u: goto label_10eb38;
            case 0x10EB3Cu: goto label_10eb3c;
            case 0x10EB78u: goto label_10eb78;
            case 0x10EB90u: goto label_10eb90;
            case 0x10EBA4u: goto label_10eba4;
            case 0x10EBB0u: goto label_10ebb0;
            case 0x10EBD8u: goto label_10ebd8;
            case 0x10EBE8u: goto label_10ebe8;
            case 0x10EC10u: goto label_10ec10;
            case 0x10EC14u: goto label_10ec14;
            case 0x10EC18u: goto label_10ec18;
            case 0x10EC30u: goto label_10ec30;
            case 0x10EC3Cu: goto label_10ec3c;
            case 0x10EC78u: goto label_10ec78;
            case 0x10EC80u: goto label_10ec80;
            case 0x10EC88u: goto label_10ec88;
            case 0x10EC90u: goto label_10ec90;
            case 0x10EC98u: goto label_10ec98;
            case 0x10ECB0u: goto label_10ecb0;
            case 0x10ECB4u: goto label_10ecb4;
            case 0x10ECC8u: goto label_10ecc8;
            case 0x10ECE0u: goto label_10ece0;
            case 0x10ECE4u: goto label_10ece4;
            case 0x10ED00u: goto label_10ed00;
            case 0x10ED0Cu: goto label_10ed0c;
            case 0x10ED18u: goto label_10ed18;
            case 0x10ED28u: goto label_10ed28;
            case 0x10ED30u: goto label_10ed30;
            case 0x10ED38u: goto label_10ed38;
            case 0x10ED48u: goto label_10ed48;
            case 0x10ED60u: goto label_10ed60;
            case 0x10ED70u: goto label_10ed70;
            case 0x10ED78u: goto label_10ed78;
            case 0x10ED90u: goto label_10ed90;
            case 0x10EDC0u: goto label_10edc0;
            case 0x10EDD8u: goto label_10edd8;
            case 0x10EDE8u: goto label_10ede8;
            case 0x10EDF0u: goto label_10edf0;
            case 0x10EE18u: goto label_10ee18;
            case 0x10EE30u: goto label_10ee30;
            case 0x10EE3Cu: goto label_10ee3c;
            case 0x10EE50u: goto label_10ee50;
            case 0x10EE70u: goto label_10ee70;
            case 0x10EE7Cu: goto label_10ee7c;
            case 0x10EE84u: goto label_10ee84;
            case 0x10EE88u: goto label_10ee88;
            case 0x10EEA8u: goto label_10eea8;
            case 0x10EEC8u: goto label_10eec8;
            case 0x10EEE0u: goto label_10eee0;
            case 0x10EF10u: goto label_10ef10;
            case 0x10EF28u: goto label_10ef28;
            case 0x10EF48u: goto label_10ef48;
            case 0x10EF68u: goto label_10ef68;
            case 0x10EF88u: goto label_10ef88;
            case 0x10EFA0u: goto label_10efa0;
            case 0x10EFA4u: goto label_10efa4;
            case 0x10EFE8u: goto label_10efe8;
            case 0x10EFF8u: goto label_10eff8;
            case 0x10F008u: goto label_10f008;
            case 0x10F018u: goto label_10f018;
            case 0x10F01Cu: goto label_10f01c;
            case 0x10F06Cu: goto label_10f06c;
            case 0x10F07Cu: goto label_10f07c;
            case 0x10F0A0u: goto label_10f0a0;
            case 0x10F0B8u: goto label_10f0b8;
            case 0x10F0BCu: goto label_10f0bc;
            case 0x10F10Cu: goto label_10f10c;
            case 0x10F114u: goto label_10f114;
            case 0x10F120u: goto label_10f120;
            case 0x10F130u: goto label_10f130;
            case 0x10F134u: goto label_10f134;
            case 0x10F190u: goto label_10f190;
            case 0x10F198u: goto label_10f198;
            case 0x10F19Cu: goto label_10f19c;
            case 0x10F1B8u: goto label_10f1b8;
            case 0x10F1E0u: goto label_10f1e0;
            case 0x10F210u: goto label_10f210;
            case 0x10F224u: goto label_10f224;
            case 0x10F238u: goto label_10f238;
            case 0x10F258u: goto label_10f258;
            case 0x10F280u: goto label_10f280;
            case 0x10F298u: goto label_10f298;
            case 0x10F2B0u: goto label_10f2b0;
            case 0x10F2CCu: goto label_10f2cc;
            case 0x10F2D0u: goto label_10f2d0;
            case 0x10F2F8u: goto label_10f2f8;
            case 0x10F304u: goto label_10f304;
            case 0x10F30Cu: goto label_10f30c;
            case 0x10F318u: goto label_10f318;
            case 0x10F31Cu: goto label_10f31c;
            case 0x10F340u: goto label_10f340;
            case 0x10F348u: goto label_10f348;
            case 0x10F35Cu: goto label_10f35c;
            case 0x10F36Cu: goto label_10f36c;
            case 0x10F378u: goto label_10f378;
            case 0x10F3A0u: goto label_10f3a0;
            case 0x10F3D0u: goto label_10f3d0;
            case 0x10F3F0u: goto label_10f3f0;
            case 0x10F410u: goto label_10f410;
            case 0x10F420u: goto label_10f420;
            case 0x10F430u: goto label_10f430;
            case 0x10F440u: goto label_10f440;
            case 0x10F470u: goto label_10f470;
            case 0x10F498u: goto label_10f498;
            case 0x10F4B0u: goto label_10f4b0;
            case 0x10F4C0u: goto label_10f4c0;
            case 0x10F4D8u: goto label_10f4d8;
            case 0x10F4F0u: goto label_10f4f0;
            case 0x10F510u: goto label_10f510;
            case 0x10F52Cu: goto label_10f52c;
            case 0x10F538u: goto label_10f538;
            case 0x10F544u: goto label_10f544;
            case 0x10F568u: goto label_10f568;
            case 0x10F578u: goto label_10f578;
            case 0x10F584u: goto label_10f584;
            case 0x10F58Cu: goto label_10f58c;
            case 0x10F598u: goto label_10f598;
            case 0x10F59Cu: goto label_10f59c;
            case 0x10F5C0u: goto label_10f5c0;
            case 0x10F5CCu: goto label_10f5cc;
            case 0x10F5E8u: goto label_10f5e8;
            case 0x10F618u: goto label_10f618;
            case 0x10F628u: goto label_10f628;
            case 0x10F63Cu: goto label_10f63c;
            case 0x10F644u: goto label_10f644;
            case 0x10F678u: goto label_10f678;
            case 0x10F690u: goto label_10f690;
            case 0x10F69Cu: goto label_10f69c;
            case 0x10F6C8u: goto label_10f6c8;
            case 0x10F6CCu: goto label_10f6cc;
            case 0x10F6DCu: goto label_10f6dc;
            case 0x10F6F8u: goto label_10f6f8;
            case 0x10F710u: goto label_10f710;
            case 0x10F720u: goto label_10f720;
            case 0x10F728u: goto label_10f728;
            case 0x10F738u: goto label_10f738;
            case 0x10F73Cu: goto label_10f73c;
            case 0x10F748u: goto label_10f748;
            case 0x10F74Cu: goto label_10f74c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10F77Cu;
    // 0x10f77c: 0x0  nop
    ctx->pc = 0x10f77cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AE10
// Address: 0x13ae10 - 0x13af00
void sub_0013AE10_0x13ae10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AE10_0x13ae10");
#endif

    switch (ctx->pc) {
        case 0x13ae8cu: goto label_13ae8c;
        case 0x13ae94u: goto label_13ae94;
        case 0x13aebcu: goto label_13aebc;
        default: break;
    }

    ctx->pc = 0x13ae10u;

    // 0x13ae10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13ae10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13ae14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13ae14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13ae18: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13ae18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ae1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13ae1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13ae20: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x13ae20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ae24: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13AE24u;
    {
        const bool branch_taken_0x13ae24 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13AE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AE24u;
            // 0x13ae28: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ae24) {
            ctx->pc = 0x13AE38u;
            goto label_13ae38;
        }
    }
    ctx->pc = 0x13AE2Cu;
    // 0x13ae2c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ae2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ae30: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x13AE30u;
    {
        const bool branch_taken_0x13ae30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AE34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AE30u;
            // 0x13ae34: 0xa040d8f0  sb          $zero, -0x2710($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 4294957296), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ae30) {
            ctx->pc = 0x13AEC4u;
            goto label_13aec4;
        }
    }
    ctx->pc = 0x13AE38u;
label_13ae38:
    // 0x13ae38: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x13ae38u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ae3c: 0x2402002f  addiu       $v0, $zero, 0x2F
    ctx->pc = 0x13ae3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x13ae40: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13AE40u;
    {
        const bool branch_taken_0x13ae40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13AE44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AE40u;
            // 0x13ae44: 0x2402005c  addiu       $v0, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ae40) {
            ctx->pc = 0x13AE78u;
            goto label_13ae78;
        }
    }
    ctx->pc = 0x13AE48u;
    // 0x13ae48: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x13AE48u;
    {
        const bool branch_taken_0x13ae48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13AE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AE48u;
            // 0x13ae4c: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ae48) {
            ctx->pc = 0x13AE78u;
            goto label_13ae78;
        }
    }
    ctx->pc = 0x13AE50u;
    // 0x13ae50: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13ae50u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13ae54: 0x2448cc70  addiu       $t0, $v0, -0x3390
    ctx->pc = 0x13ae54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954096));
    // 0x13ae58: 0x2487d8f0  addiu       $a3, $a0, -0x2710
    ctx->pc = 0x13ae58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957296));
    // 0x13ae5c: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x13ae5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x13ae60: 0x81060001  lb          $a2, 0x1($t0)
    ctx->pc = 0x13ae60u;
    SET_GPR_S32(ctx, 6, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x13ae64: 0xa0e30000  sb          $v1, 0x0($a3)
    ctx->pc = 0x13ae64u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x13ae68: 0xa0e60001  sb          $a2, 0x1($a3)
    ctx->pc = 0x13ae68u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 1), (uint8_t)GPR_U32(ctx, 6));
    // 0x13ae6c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x13AE6Cu;
    {
        const bool branch_taken_0x13ae6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AE70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AE6Cu;
            // 0x13ae70: 0x2491d8f0  addiu       $s1, $a0, -0x2710 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957296));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ae6c) {
            ctx->pc = 0x13AE84u;
            goto label_13ae84;
        }
    }
    ctx->pc = 0x13AE74u;
    // 0x13ae74: 0x0  nop
    ctx->pc = 0x13ae74u;
    // NOP
label_13ae78:
    // 0x13ae78: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13ae78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13ae7c: 0xa080d8f0  sb          $zero, -0x2710($a0)
    ctx->pc = 0x13ae7cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4294957296), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ae80: 0x2491d8f0  addiu       $s1, $a0, -0x2710
    ctx->pc = 0x13ae80u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957296));
label_13ae84:
    // 0x13ae84: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x13AE84u;
    SET_GPR_U32(ctx, 31, 0x13AE8Cu);
    ctx->pc = 0x13AE88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AE84u;
            // 0x13ae88: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AE8Cu; }
        if (ctx->pc != 0x13AE8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AE8Cu; }
        if (ctx->pc != 0x13AE8Cu) { return; }
    }
    ctx->pc = 0x13AE8Cu;
label_13ae8c:
    // 0x13ae8c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13AE8Cu;
    SET_GPR_U32(ctx, 31, 0x13AE94u);
    ctx->pc = 0x13AE90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AE8Cu;
            // 0x13ae90: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AE94u; }
        if (ctx->pc != 0x13AE94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AE94u; }
        if (ctx->pc != 0x13AE94u) { return; }
    }
    ctx->pc = 0x13AE94u;
label_13ae94:
    // 0x13ae94: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13ae94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ae98: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x13ae98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13ae9c: 0x2403002f  addiu       $v1, $zero, 0x2F
    ctx->pc = 0x13ae9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x13aea0: 0x8042ffff  lb          $v0, -0x1($v0)
    ctx->pc = 0x13aea0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x13aea4: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x13AEA4u;
    {
        const bool branch_taken_0x13aea4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x13AEA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AEA4u;
            // 0x13aea8: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13aea4) {
            ctx->pc = 0x13AEB4u;
            goto label_13aeb4;
        }
    }
    ctx->pc = 0x13AEACu;
    // 0x13aeac: 0x14450006  bne         $v0, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13AEACu;
    {
        const bool branch_taken_0x13aeac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x13AEB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AEACu;
            // 0x13aeb0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13aeac) {
            ctx->pc = 0x13AEC8u;
            goto label_13aec8;
        }
    }
    ctx->pc = 0x13AEB4u;
label_13aeb4:
    // 0x13aeb4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13AEB4u;
    SET_GPR_U32(ctx, 31, 0x13AEBCu);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AEBCu; }
        if (ctx->pc != 0x13AEBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13AEBCu; }
        if (ctx->pc != 0x13AEBCu) { return; }
    }
    ctx->pc = 0x13AEBCu;
label_13aebc:
    // 0x13aebc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x13aebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x13aec0: 0xa040ffff  sb          $zero, -0x1($v0)
    ctx->pc = 0x13aec0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 4294967295), (uint8_t)GPR_U32(ctx, 0));
label_13aec4:
    // 0x13aec4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13aec4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13aec8:
    // 0x13aec8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13aec8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13aecc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13aeccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13aed0: 0x3e00008  jr          $ra
    ctx->pc = 0x13AED0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AED0u;
            // 0x13aed4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AE38u: goto label_13ae38;
            case 0x13AE78u: goto label_13ae78;
            case 0x13AE84u: goto label_13ae84;
            case 0x13AE8Cu: goto label_13ae8c;
            case 0x13AE94u: goto label_13ae94;
            case 0x13AEB4u: goto label_13aeb4;
            case 0x13AEBCu: goto label_13aebc;
            case 0x13AEC4u: goto label_13aec4;
            case 0x13AEC8u: goto label_13aec8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AED8u;
    // 0x13aed8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13aed8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13aedc: 0x3e00008  jr          $ra
    ctx->pc = 0x13AEDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AEDCu;
            // 0x13aee0: 0x2442d8f0  addiu       $v0, $v0, -0x2710 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957296));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AE38u: goto label_13ae38;
            case 0x13AE78u: goto label_13ae78;
            case 0x13AE84u: goto label_13ae84;
            case 0x13AE8Cu: goto label_13ae8c;
            case 0x13AE94u: goto label_13ae94;
            case 0x13AEB4u: goto label_13aeb4;
            case 0x13AEBCu: goto label_13aebc;
            case 0x13AEC4u: goto label_13aec4;
            case 0x13AEC8u: goto label_13aec8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AEE4u;
    // 0x13aee4: 0x0  nop
    ctx->pc = 0x13aee4u;
    // NOP
    // 0x13aee8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13aee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13aeec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13aeecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13aef0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13aef0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13aef4: 0x804e0d8  j           func_138360
    ctx->pc = 0x13AEF4u;
    ctx->pc = 0x13AEF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AEF4u;
            // 0x13aef8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138360u;
    if (runtime->hasFunction(0x138360u)) {
        auto targetFn = runtime->lookupFunction(0x138360u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00138360_0x138360(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13AEFCu;
    // 0x13aefc: 0x0  nop
    ctx->pc = 0x13aefcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

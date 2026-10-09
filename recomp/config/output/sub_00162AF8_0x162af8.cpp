#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162AF8
// Address: 0x162af8 - 0x162c10
void sub_00162AF8_0x162af8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162AF8_0x162af8");
#endif

    switch (ctx->pc) {
        case 0x162b14u: goto label_162b14;
        case 0x162b6cu: goto label_162b6c;
        case 0x162b80u: goto label_162b80;
        case 0x162bb0u: goto label_162bb0;
        case 0x162bd8u: goto label_162bd8;
        case 0x162c00u: goto label_162c00;
        default: break;
    }

    ctx->pc = 0x162af8u;

    // 0x162af8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162af8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162afc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162b00: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x162b00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162b04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x162b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162b08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162b0c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x162B0Cu;
    SET_GPR_U32(ctx, 31, 0x162B14u);
    ctx->pc = 0x162B10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162B0Cu;
            // 0x162b10: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162B14u; }
        if (ctx->pc != 0x162B14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162B14u; }
        if (ctx->pc != 0x162B14u) { return; }
    }
    ctx->pc = 0x162B14u;
label_162b14:
    // 0x162b14: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162b14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162b18: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x162b18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x162b1c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x162B1Cu;
    {
        const bool branch_taken_0x162b1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162B1Cu;
            // 0x162b20: 0x248403b8  addiu       $a0, $a0, 0x3B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 952));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162b1c) {
            ctx->pc = 0x162B38u;
            goto label_162b38;
        }
    }
    ctx->pc = 0x162B24u;
    // 0x162b24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162b24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162b28: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162b28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162b2c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162b2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162b30: 0x8058dd4  j           func_163750
    ctx->pc = 0x162B30u;
    ctx->pc = 0x162B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162B30u;
            // 0x162b34: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162B38u;
label_162b38:
    // 0x162b38: 0x82020070  lb          $v0, 0x70($s0)
    ctx->pc = 0x162b38u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 112)));
    // 0x162b3c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x162B3Cu;
    {
        const bool branch_taken_0x162b3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x162B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162B3Cu;
            // 0x162b40: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162b3c) {
            ctx->pc = 0x162B50u;
            goto label_162b50;
        }
    }
    ctx->pc = 0x162B44u;
    // 0x162b44: 0x52200001  beql        $s1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x162B44u;
    {
        const bool branch_taken_0x162b44 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x162b44) {
            ctx->pc = 0x162B48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162B44u;
            // 0x162b48: 0xa2020071  sb          $v0, 0x71($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 113), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162B4Cu;
            goto label_162b4c;
        }
    }
    ctx->pc = 0x162B4Cu;
label_162b4c:
    // 0x162b4c: 0x82020070  lb          $v0, 0x70($s0)
    ctx->pc = 0x162b4cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 112)));
label_162b50:
    // 0x162b50: 0x5440000c  bnel        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x162B50u;
    {
        const bool branch_taken_0x162b50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x162b50) {
            ctx->pc = 0x162B54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162B50u;
            // 0x162b54: 0xa2110070  sb          $s1, 0x70($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 112), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162B84u;
            goto label_162b84;
        }
    }
    ctx->pc = 0x162B58u;
    // 0x162b58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x162b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x162b5c: 0x56220009  bnel        $s1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x162B5Cu;
    {
        const bool branch_taken_0x162b5c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x162b5c) {
            ctx->pc = 0x162B60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x162B5Cu;
            // 0x162b60: 0xa2110070  sb          $s1, 0x70($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 112), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x162B84u;
            goto label_162b84;
        }
    }
    ctx->pc = 0x162B64u;
    // 0x162b64: 0xc059f5c  jal         func_167D70
    ctx->pc = 0x162B64u;
    SET_GPR_U32(ctx, 31, 0x162B6Cu);
    ctx->pc = 0x167D70u;
    if (runtime->hasFunction(0x167D70u)) {
        auto targetFn = runtime->lookupFunction(0x167D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162B6Cu; }
        if (ctx->pc != 0x162B6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167D70_0x167d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162B6Cu; }
        if (ctx->pc != 0x162B6Cu) { return; }
    }
    ctx->pc = 0x162B6Cu;
label_162b6c:
    // 0x162b6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x162b6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162b70: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x162B70u;
    {
        const bool branch_taken_0x162b70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162B70u;
            // 0x162b74: 0x248403e8  addiu       $a0, $a0, 0x3E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1000));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162b70) {
            ctx->pc = 0x162B80u;
            goto label_162b80;
        }
    }
    ctx->pc = 0x162B78u;
    // 0x162b78: 0xc058dd4  jal         func_163750
    ctx->pc = 0x162B78u;
    SET_GPR_U32(ctx, 31, 0x162B80u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162B80u; }
        if (ctx->pc != 0x162B80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162B80u; }
        if (ctx->pc != 0x162B80u) { return; }
    }
    ctx->pc = 0x162B80u;
label_162b80:
    // 0x162b80: 0xa2110070  sb          $s1, 0x70($s0)
    ctx->pc = 0x162b80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 112), (uint8_t)GPR_U32(ctx, 17));
label_162b84:
    // 0x162b84: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162b84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162b88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162b88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162b8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162b8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162b90: 0x3e00008  jr          $ra
    ctx->pc = 0x162B90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162B94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162B90u;
            // 0x162b94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162B14u: goto label_162b14;
            case 0x162B38u: goto label_162b38;
            case 0x162B4Cu: goto label_162b4c;
            case 0x162B50u: goto label_162b50;
            case 0x162B6Cu: goto label_162b6c;
            case 0x162B80u: goto label_162b80;
            case 0x162B84u: goto label_162b84;
            case 0x162BB0u: goto label_162bb0;
            case 0x162BD8u: goto label_162bd8;
            case 0x162C00u: goto label_162c00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162B98u;
    // 0x162b98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162b98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162b9c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x162b9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ba0: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x162ba0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x162ba4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162ba8: 0xc058b04  jal         func_162C10
    ctx->pc = 0x162BA8u;
    SET_GPR_U32(ctx, 31, 0x162BB0u);
    ctx->pc = 0x162BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162BA8u;
            // 0x162bac: 0x27a60008  addiu       $a2, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162C10u;
    if (runtime->hasFunction(0x162C10u)) {
        auto targetFn = runtime->lookupFunction(0x162C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162BB0u; }
        if (ctx->pc != 0x162BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162C10_0x162c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162BB0u; }
        if (ctx->pc != 0x162BB0u) { return; }
    }
    ctx->pc = 0x162BB0u;
label_162bb0:
    // 0x162bb0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162bb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162bb4: 0x3e00008  jr          $ra
    ctx->pc = 0x162BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162BB4u;
            // 0x162bb8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162B14u: goto label_162b14;
            case 0x162B38u: goto label_162b38;
            case 0x162B4Cu: goto label_162b4c;
            case 0x162B50u: goto label_162b50;
            case 0x162B6Cu: goto label_162b6c;
            case 0x162B80u: goto label_162b80;
            case 0x162B84u: goto label_162b84;
            case 0x162BB0u: goto label_162bb0;
            case 0x162BD8u: goto label_162bd8;
            case 0x162C00u: goto label_162c00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162BBCu;
    // 0x162bbc: 0x0  nop
    ctx->pc = 0x162bbcu;
    // NOP
    // 0x162bc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162bc4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x162bc4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162bc8: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x162bc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x162bcc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162bccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162bd0: 0xc058b04  jal         func_162C10
    ctx->pc = 0x162BD0u;
    SET_GPR_U32(ctx, 31, 0x162BD8u);
    ctx->pc = 0x162BD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162BD0u;
            // 0x162bd4: 0x27a60008  addiu       $a2, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162C10u;
    if (runtime->hasFunction(0x162C10u)) {
        auto targetFn = runtime->lookupFunction(0x162C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162BD8u; }
        if (ctx->pc != 0x162BD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162C10_0x162c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162BD8u; }
        if (ctx->pc != 0x162BD8u) { return; }
    }
    ctx->pc = 0x162BD8u;
label_162bd8:
    // 0x162bd8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162bd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162bdc: 0x3e00008  jr          $ra
    ctx->pc = 0x162BDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162BDCu;
            // 0x162be0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162B14u: goto label_162b14;
            case 0x162B38u: goto label_162b38;
            case 0x162B4Cu: goto label_162b4c;
            case 0x162B50u: goto label_162b50;
            case 0x162B6Cu: goto label_162b6c;
            case 0x162B80u: goto label_162b80;
            case 0x162B84u: goto label_162b84;
            case 0x162BB0u: goto label_162bb0;
            case 0x162BD8u: goto label_162bd8;
            case 0x162C00u: goto label_162c00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162BE4u;
    // 0x162be4: 0x0  nop
    ctx->pc = 0x162be4u;
    // NOP
    // 0x162be8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162be8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162bec: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x162becu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162bf0: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x162bf0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x162bf4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162bf8: 0xc058b10  jal         func_162C40
    ctx->pc = 0x162BF8u;
    SET_GPR_U32(ctx, 31, 0x162C00u);
    ctx->pc = 0x162BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162BF8u;
            // 0x162bfc: 0x27a60008  addiu       $a2, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162C40u;
    if (runtime->hasFunction(0x162C40u)) {
        auto targetFn = runtime->lookupFunction(0x162C40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162C00u; }
        if (ctx->pc != 0x162C00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162C40_0x162c40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162C00u; }
        if (ctx->pc != 0x162C00u) { return; }
    }
    ctx->pc = 0x162C00u;
label_162c00:
    // 0x162c00: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162c00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162c04: 0x3e00008  jr          $ra
    ctx->pc = 0x162C04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162C04u;
            // 0x162c08: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162B14u: goto label_162b14;
            case 0x162B38u: goto label_162b38;
            case 0x162B4Cu: goto label_162b4c;
            case 0x162B50u: goto label_162b50;
            case 0x162B6Cu: goto label_162b6c;
            case 0x162B80u: goto label_162b80;
            case 0x162B84u: goto label_162b84;
            case 0x162BB0u: goto label_162bb0;
            case 0x162BD8u: goto label_162bd8;
            case 0x162C00u: goto label_162c00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162C0Cu;
    // 0x162c0c: 0x0  nop
    ctx->pc = 0x162c0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

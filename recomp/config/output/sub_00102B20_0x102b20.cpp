#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102B20
// Address: 0x102b20 - 0x102c20
void sub_00102B20_0x102b20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102B20_0x102b20");
#endif

    switch (ctx->pc) {
        case 0x102b5cu: goto label_102b5c;
        case 0x102bc0u: goto label_102bc0;
        default: break;
    }

    ctx->pc = 0x102b20u;

    // 0x102b20: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x102b20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x102b24: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x102b24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102b28: 0x34423c10  ori         $v0, $v0, 0x3C10
    ctx->pc = 0x102b28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15376);
    // 0x102b2c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102b30: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x102b30u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x102b34: 0x34633c20  ori         $v1, $v1, 0x3C20
    ctx->pc = 0x102b34u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15392);
    // 0x102b38: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x102b38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x102b3c: 0x3e00008  jr          $ra
    ctx->pc = 0x102B3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B3Cu;
            // 0x102b40: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102B5Cu: goto label_102b5c;
            case 0x102B6Cu: goto label_102b6c;
            case 0x102B74u: goto label_102b74;
            case 0x102B84u: goto label_102b84;
            case 0x102B94u: goto label_102b94;
            case 0x102BA0u: goto label_102ba0;
            case 0x102BC0u: goto label_102bc0;
            case 0x102BE0u: goto label_102be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102B44u;
    // 0x102b44: 0x0  nop
    ctx->pc = 0x102b44u;
    // NOP
    // 0x102b48: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x102b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x102b4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102b50: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x102b50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x102b54: 0xc040b08  jal         func_102C20
    ctx->pc = 0x102B54u;
    SET_GPR_U32(ctx, 31, 0x102B5Cu);
    ctx->pc = 0x102B58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102B54u;
            // 0x102b58: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102C20u;
    if (runtime->hasFunction(0x102C20u)) {
        auto targetFn = runtime->lookupFunction(0x102C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102B5Cu; }
        if (ctx->pc != 0x102B5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102C20_0x102c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102B5Cu; }
        if (ctx->pc != 0x102B5Cu) { return; }
    }
    ctx->pc = 0x102B5Cu;
label_102b5c:
    // 0x102b5c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102B5Cu;
    {
        const bool branch_taken_0x102b5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B5Cu;
            // 0x102b60: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b5c) {
            ctx->pc = 0x102B6Cu;
            goto label_102b6c;
        }
    }
    ctx->pc = 0x102B64u;
    // 0x102b64: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x102B64u;
    {
        const bool branch_taken_0x102b64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x102b64) {
            ctx->pc = 0x102B74u;
            goto label_102b74;
        }
    }
    ctx->pc = 0x102B6Cu;
label_102b6c:
    // 0x102b6c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x102B6Cu;
    {
        const bool branch_taken_0x102b6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B6Cu;
            // 0x102b70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b6c) {
            ctx->pc = 0x102BA0u;
            goto label_102ba0;
        }
    }
    ctx->pc = 0x102B74u;
label_102b74:
    // 0x102b74: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102B74u;
    {
        const bool branch_taken_0x102b74 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x102B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B74u;
            // 0x102b78: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b74) {
            ctx->pc = 0x102B84u;
            goto label_102b84;
        }
    }
    ctx->pc = 0x102B7Cu;
    // 0x102b7c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x102B7Cu;
    {
        const bool branch_taken_0x102b7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B7Cu;
            // 0x102b80: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b7c) {
            ctx->pc = 0x102B94u;
            goto label_102b94;
        }
    }
    ctx->pc = 0x102B84u;
label_102b84:
    // 0x102b84: 0x16030006  bne         $s0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x102B84u;
    {
        const bool branch_taken_0x102b84 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x102B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B84u;
            // 0x102b88: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b84) {
            ctx->pc = 0x102BA0u;
            goto label_102ba0;
        }
    }
    ctx->pc = 0x102B8Cu;
    // 0x102b8c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x102b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x102b90: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x102b90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_102b94:
    // 0x102b94: 0x34423c10  ori         $v0, $v0, 0x3C10
    ctx->pc = 0x102b94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15376);
    // 0x102b98: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x102b98u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x102b9c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_102ba0:
    // 0x102ba0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x102ba0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102ba4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102ba4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102ba8: 0x3e00008  jr          $ra
    ctx->pc = 0x102BA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102BA8u;
            // 0x102bac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102B5Cu: goto label_102b5c;
            case 0x102B6Cu: goto label_102b6c;
            case 0x102B74u: goto label_102b74;
            case 0x102B84u: goto label_102b84;
            case 0x102B94u: goto label_102b94;
            case 0x102BA0u: goto label_102ba0;
            case 0x102BC0u: goto label_102bc0;
            case 0x102BE0u: goto label_102be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102BB0u;
    // 0x102bb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x102bb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x102bb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x102bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x102bb8: 0xc040b08  jal         func_102C20
    ctx->pc = 0x102BB8u;
    SET_GPR_U32(ctx, 31, 0x102BC0u);
    ctx->pc = 0x102C20u;
    if (runtime->hasFunction(0x102C20u)) {
        auto targetFn = runtime->lookupFunction(0x102C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102BC0u; }
        if (ctx->pc != 0x102BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102C20_0x102c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102BC0u; }
        if (ctx->pc != 0x102BC0u) { return; }
    }
    ctx->pc = 0x102BC0u;
label_102bc0:
    // 0x102bc0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x102bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102bc4: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x102BC4u;
    {
        const bool branch_taken_0x102bc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x102BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102BC4u;
            // 0x102bc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102bc4) {
            ctx->pc = 0x102BE0u;
            goto label_102be0;
        }
    }
    ctx->pc = 0x102BCCu;
    // 0x102bcc: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102bccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102bd0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x102bd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x102bd4: 0x34633c10  ori         $v1, $v1, 0x3C10
    ctx->pc = 0x102bd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15376);
    // 0x102bd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102bdc: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x102bdcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_102be0:
    // 0x102be0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x102be0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102be4: 0x3e00008  jr          $ra
    ctx->pc = 0x102BE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102BE4u;
            // 0x102be8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102B5Cu: goto label_102b5c;
            case 0x102B6Cu: goto label_102b6c;
            case 0x102B74u: goto label_102b74;
            case 0x102B84u: goto label_102b84;
            case 0x102B94u: goto label_102b94;
            case 0x102BA0u: goto label_102ba0;
            case 0x102BC0u: goto label_102bc0;
            case 0x102BE0u: goto label_102be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102BECu;
    // 0x102bec: 0x0  nop
    ctx->pc = 0x102becu;
    // NOP
    // 0x102bf0: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x102bf0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x102bf4: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x102bf4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x102bf8: 0x851025  or          $v0, $a0, $a1
    ctx->pc = 0x102bf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x102bfc: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102c00: 0x461025  or          $v0, $v0, $a2
    ctx->pc = 0x102c00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
    // 0x102c04: 0x34633c20  ori         $v1, $v1, 0x3C20
    ctx->pc = 0x102c04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15392);
    // 0x102c08: 0x3e00008  jr          $ra
    ctx->pc = 0x102C08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102C08u;
            // 0x102c0c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102B5Cu: goto label_102b5c;
            case 0x102B6Cu: goto label_102b6c;
            case 0x102B74u: goto label_102b74;
            case 0x102B84u: goto label_102b84;
            case 0x102B94u: goto label_102b94;
            case 0x102BA0u: goto label_102ba0;
            case 0x102BC0u: goto label_102bc0;
            case 0x102BE0u: goto label_102be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102C10u;
    // 0x102c10: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102c10u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102c14: 0x34633c20  ori         $v1, $v1, 0x3C20
    ctx->pc = 0x102c14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15392);
    // 0x102c18: 0x3e00008  jr          $ra
    ctx->pc = 0x102C18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102C18u;
            // 0x102c1c: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102B5Cu: goto label_102b5c;
            case 0x102B6Cu: goto label_102b6c;
            case 0x102B74u: goto label_102b74;
            case 0x102B84u: goto label_102b84;
            case 0x102B94u: goto label_102b94;
            case 0x102BA0u: goto label_102ba0;
            case 0x102BC0u: goto label_102bc0;
            case 0x102BE0u: goto label_102be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102C20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

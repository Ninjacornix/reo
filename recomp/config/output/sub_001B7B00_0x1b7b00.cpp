#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B7B00
// Address: 0x1b7b00 - 0x1b7c00
void sub_001B7B00_0x1b7b00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B7B00_0x1b7b00");
#endif

    switch (ctx->pc) {
        case 0x1b7b4cu: goto label_1b7b4c;
        case 0x1b7b58u: goto label_1b7b58;
        case 0x1b7b70u: goto label_1b7b70;
        case 0x1b7b80u: goto label_1b7b80;
        case 0x1b7bbcu: goto label_1b7bbc;
        default: break;
    }

    ctx->pc = 0x1b7b00u;

    // 0x1b7b00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b7b00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b7b04: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b7b04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b7b08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b7b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b7b0c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b7b0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b7b10: 0x902343d6  lbu         $v1, 0x43D6($at)
    ctx->pc = 0x1b7b10u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17366)));
    // 0x1b7b14: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B7B14u;
    {
        const bool branch_taken_0x1b7b14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b7b14) {
            ctx->pc = 0x1B7B2Cu;
            goto label_1b7b2c;
        }
    }
    ctx->pc = 0x1B7B1Cu;
    // 0x1b7b1c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b7b1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b7b20: 0x902343ea  lbu         $v1, 0x43EA($at)
    ctx->pc = 0x1b7b20u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17386)));
    // 0x1b7b24: 0x10600030  beqz        $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x1B7B24u;
    {
        const bool branch_taken_0x1b7b24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b7b24) {
            ctx->pc = 0x1B7BE8u;
            goto label_1b7be8;
        }
    }
    ctx->pc = 0x1B7B2Cu;
label_1b7b2c:
    // 0x1b7b2c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b7b2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b7b30: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b7b30u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b7b34: 0x8c23ab54  lw          $v1, -0x54AC($at)
    ctx->pc = 0x1b7b34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945620)));
    // 0x1b7b38: 0x10600020  beqz        $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x1B7B38u;
    {
        const bool branch_taken_0x1b7b38 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7B38u;
            // 0x1b7b3c: 0x2610aaf0  addiu       $s0, $s0, -0x5510 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7b38) {
            ctx->pc = 0x1B7BBCu;
            goto label_1b7bbc;
        }
    }
    ctx->pc = 0x1B7B40u;
    // 0x1b7b40: 0x2404005f  addiu       $a0, $zero, 0x5F
    ctx->pc = 0x1b7b40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1b7b44: 0xc065804  jal         func_196010
    ctx->pc = 0x1B7B44u;
    SET_GPR_U32(ctx, 31, 0x1B7B4Cu);
    ctx->pc = 0x1B7B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7B44u;
            // 0x1b7b48: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B4Cu; }
        if (ctx->pc != 0x1B7B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B4Cu; }
        if (ctx->pc != 0x1B7B4Cu) { return; }
    }
    ctx->pc = 0x1B7B4Cu;
label_1b7b4c:
    // 0x1b7b4c: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x1b7b4cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x1b7b50: 0xc065804  jal         func_196010
    ctx->pc = 0x1B7B50u;
    SET_GPR_U32(ctx, 31, 0x1B7B58u);
    ctx->pc = 0x1B7B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7B50u;
            // 0x1b7b54: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B58u; }
        if (ctx->pc != 0x1B7B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B58u; }
        if (ctx->pc != 0x1B7B58u) { return; }
    }
    ctx->pc = 0x1B7B58u;
label_1b7b58:
    // 0x1b7b58: 0x8e0200a0  lw          $v0, 0xA0($s0)
    ctx->pc = 0x1b7b58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 160)));
    // 0x1b7b5c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B7B5Cu;
    {
        const bool branch_taken_0x1b7b5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7B5Cu;
            // 0x1b7b60: 0x2404006c  addiu       $a0, $zero, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7b5c) {
            ctx->pc = 0x1B7B78u;
            goto label_1b7b78;
        }
    }
    ctx->pc = 0x1B7B64u;
    // 0x1b7b64: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1b7b64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1b7b68: 0xc065804  jal         func_196010
    ctx->pc = 0x1B7B68u;
    SET_GPR_U32(ctx, 31, 0x1B7B70u);
    ctx->pc = 0x1B7B6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7B68u;
            // 0x1b7b6c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B70u; }
        if (ctx->pc != 0x1B7B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B70u; }
        if (ctx->pc != 0x1B7B70u) { return; }
    }
    ctx->pc = 0x1B7B70u;
label_1b7b70:
    // 0x1b7b70: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B7B70u;
    {
        const bool branch_taken_0x1b7b70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B7B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7B70u;
            // 0x1b7b74: 0x8e03004c  lw          $v1, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b7b70) {
            ctx->pc = 0x1B7B84u;
            goto label_1b7b84;
        }
    }
    ctx->pc = 0x1B7B78u;
label_1b7b78:
    // 0x1b7b78: 0xc065804  jal         func_196010
    ctx->pc = 0x1B7B78u;
    SET_GPR_U32(ctx, 31, 0x1B7B80u);
    ctx->pc = 0x1B7B7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7B78u;
            // 0x1b7b7c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x196010u;
    if (runtime->hasFunction(0x196010u)) {
        auto targetFn = runtime->lookupFunction(0x196010u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B80u; }
        if (ctx->pc != 0x1B7B80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00196010_0x196010(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7B80u; }
        if (ctx->pc != 0x1B7B80u) { return; }
    }
    ctx->pc = 0x1B7B80u;
label_1b7b80:
    // 0x1b7b80: 0x8e03004c  lw          $v1, 0x4C($s0)
    ctx->pc = 0x1b7b80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
label_1b7b84:
    // 0x1b7b84: 0x3c02f000  lui         $v0, 0xF000
    ctx->pc = 0x1b7b84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)61440 << 16));
    // 0x1b7b88: 0x3c05002a  lui         $a1, 0x2A
    ctx->pc = 0x1b7b88u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)42 << 16));
    // 0x1b7b8c: 0x24a5f6f0  addiu       $a1, $a1, -0x910
    ctx->pc = 0x1b7b8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294964976));
    // 0x1b7b90: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1b7b90u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1b7b94: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1b7b94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1b7b98: 0xac600008  sw          $zero, 0x8($v1)
    ctx->pc = 0x1b7b98u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 0));
    // 0x1b7b9c: 0xac60000c  sw          $zero, 0xC($v1)
    ctx->pc = 0x1b7b9cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x1b7ba0: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x1b7ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b7ba4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1b7ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b7ba8: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b7ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b7bac: 0x8c420038  lw          $v0, 0x38($v0)
    ctx->pc = 0x1b7bacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 56)));
    // 0x1b7bb0: 0x2213c  dsll32      $a0, $v0, 4
    ctx->pc = 0x1b7bb0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 4));
    // 0x1b7bb4: 0xc0633bc  jal         func_18CEF0
    ctx->pc = 0x1B7BB4u;
    SET_GPR_U32(ctx, 31, 0x1B7BBCu);
    ctx->pc = 0x1B7BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7BB4u;
            // 0x1b7bb8: 0x4213e  dsrl32      $a0, $a0, 4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CEF0u;
    if (runtime->hasFunction(0x18CEF0u)) {
        auto targetFn = runtime->lookupFunction(0x18CEF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7BBCu; }
        if (ctx->pc != 0x1B7BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CEF0_0x18cef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7BBCu; }
        if (ctx->pc != 0x1B7BBCu) { return; }
    }
    ctx->pc = 0x1B7BBCu;
label_1b7bbc:
    // 0x1b7bbc: 0x8e030048  lw          $v1, 0x48($s0)
    ctx->pc = 0x1b7bbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b7bc0: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1b7bc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1b7bc4: 0xae030048  sw          $v1, 0x48($s0)
    ctx->pc = 0x1b7bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 3));
    // 0x1b7bc8: 0x8e030048  lw          $v1, 0x48($s0)
    ctx->pc = 0x1b7bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x1b7bcc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b7bccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b7bd0: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b7bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b7bd4: 0x8c630040  lw          $v1, 0x40($v1)
    ctx->pc = 0x1b7bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 64)));
    // 0x1b7bd8: 0xae03004c  sw          $v1, 0x4C($s0)
    ctx->pc = 0x1b7bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
    // 0x1b7bdc: 0x8e030064  lw          $v1, 0x64($s0)
    ctx->pc = 0x1b7bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 100)));
    // 0x1b7be0: 0xae030068  sw          $v1, 0x68($s0)
    ctx->pc = 0x1b7be0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 104), GPR_U32(ctx, 3));
    // 0x1b7be4: 0xae000064  sw          $zero, 0x64($s0)
    ctx->pc = 0x1b7be4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 0));
label_1b7be8:
    // 0x1b7be8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b7be8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b7bec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b7becu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b7bf0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B7BF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B7BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B7BF0u;
            // 0x1b7bf4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7B2Cu: goto label_1b7b2c;
            case 0x1B7B4Cu: goto label_1b7b4c;
            case 0x1B7B58u: goto label_1b7b58;
            case 0x1B7B70u: goto label_1b7b70;
            case 0x1B7B78u: goto label_1b7b78;
            case 0x1B7B80u: goto label_1b7b80;
            case 0x1B7B84u: goto label_1b7b84;
            case 0x1B7BBCu: goto label_1b7bbc;
            case 0x1B7BE8u: goto label_1b7be8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B7BF8u;
    // 0x1b7bf8: 0x0  nop
    ctx->pc = 0x1b7bf8u;
    // NOP
    // 0x1b7bfc: 0x0  nop
    ctx->pc = 0x1b7bfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

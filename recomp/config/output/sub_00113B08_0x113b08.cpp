#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00113B08
// Address: 0x113b08 - 0x113ba8
void sub_00113B08_0x113b08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00113B08_0x113b08");
#endif

    switch (ctx->pc) {
        case 0x113b24u: goto label_113b24;
        case 0x113b38u: goto label_113b38;
        case 0x113b44u: goto label_113b44;
        case 0x113b60u: goto label_113b60;
        case 0x113b6cu: goto label_113b6c;
        case 0x113b80u: goto label_113b80;
        case 0x113b8cu: goto label_113b8c;
        default: break;
    }

    ctx->pc = 0x113b08u;

    // 0x113b08: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x113b08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x113b0c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x113b0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x113b10: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x113b10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x113b14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x113b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x113b18: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x113b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x113b1c: 0xc0449be  jal         func_1126F8
    ctx->pc = 0x113B1Cu;
    SET_GPR_U32(ctx, 31, 0x113B24u);
    ctx->pc = 0x113B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113B1Cu;
            // 0x113b20: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1126F8u;
    if (runtime->hasFunction(0x1126F8u)) {
        auto targetFn = runtime->lookupFunction(0x1126F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B24u; }
        if (ctx->pc != 0x113B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B24u; }
        if (ctx->pc != 0x113B24u) { return; }
    }
    ctx->pc = 0x113B24u;
label_113b24:
    // 0x113b24: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x113b24u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113b28: 0x16200009  bnez        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x113B28u;
    {
        const bool branch_taken_0x113b28 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x113B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113B28u;
            // 0x113b2c: 0x8e120008  lw          $s2, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113b28) {
            ctx->pc = 0x113B50u;
            goto label_113b50;
        }
    }
    ctx->pc = 0x113B30u;
    // 0x113b30: 0xc045440  jal         func_115100
    ctx->pc = 0x113B30u;
    SET_GPR_U32(ctx, 31, 0x113B38u);
    ctx->pc = 0x113B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113B30u;
            // 0x113b34: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115100u;
    if (runtime->hasFunction(0x115100u)) {
        auto targetFn = runtime->lookupFunction(0x115100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B38u; }
        if (ctx->pc != 0x113B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B38u; }
        if (ctx->pc != 0x113B38u) { return; }
    }
    ctx->pc = 0x113B38u;
label_113b38:
    // 0x113b38: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x113b38u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x113b3c: 0xc0450c8  jal         func_114320
    ctx->pc = 0x113B3Cu;
    SET_GPR_U32(ctx, 31, 0x113B44u);
    ctx->pc = 0x113B40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113B3Cu;
            // 0x113b40: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114320u;
    if (runtime->hasFunction(0x114320u)) {
        auto targetFn = runtime->lookupFunction(0x114320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B44u; }
        if (ctx->pc != 0x113B44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B44u; }
        if (ctx->pc != 0x113B44u) { return; }
    }
    ctx->pc = 0x113B44u;
label_113b44:
    // 0x113b44: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x113b44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x113b48: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x113B48u;
    {
        const bool branch_taken_0x113b48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113B48u;
            // 0x113b4c: 0xae00000c  sw          $zero, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113b48) {
            ctx->pc = 0x113B8Cu;
            goto label_113b8c;
        }
    }
    ctx->pc = 0x113B50u;
label_113b50:
    // 0x113b50: 0x52400007  beql        $s2, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x113B50u;
    {
        const bool branch_taken_0x113b50 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x113b50) {
            ctx->pc = 0x113B54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x113B50u;
            // 0x113b54: 0xae110008  sw          $s1, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x113B70u;
            goto label_113b70;
        }
    }
    ctx->pc = 0x113B58u;
    // 0x113b58: 0xc045440  jal         func_115100
    ctx->pc = 0x113B58u;
    SET_GPR_U32(ctx, 31, 0x113B60u);
    ctx->pc = 0x113B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113B58u;
            // 0x113b5c: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115100u;
    if (runtime->hasFunction(0x115100u)) {
        auto targetFn = runtime->lookupFunction(0x115100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B60u; }
        if (ctx->pc != 0x113B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B60u; }
        if (ctx->pc != 0x113B60u) { return; }
    }
    ctx->pc = 0x113B60u;
label_113b60:
    // 0x113b60: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x113b60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x113b64: 0xc0450c8  jal         func_114320
    ctx->pc = 0x113B64u;
    SET_GPR_U32(ctx, 31, 0x113B6Cu);
    ctx->pc = 0x113B68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113B64u;
            // 0x113b68: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114320u;
    if (runtime->hasFunction(0x114320u)) {
        auto targetFn = runtime->lookupFunction(0x114320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B6Cu; }
        if (ctx->pc != 0x113B6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B6Cu; }
        if (ctx->pc != 0x113B6Cu) { return; }
    }
    ctx->pc = 0x113B6Cu;
label_113b6c:
    // 0x113b6c: 0xae110008  sw          $s1, 0x8($s0)
    ctx->pc = 0x113b6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 17));
label_113b70:
    // 0x113b70: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x113b70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113b74: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x113b74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x113b78: 0xc0450c0  jal         func_114300
    ctx->pc = 0x113B78u;
    SET_GPR_U32(ctx, 31, 0x113B80u);
    ctx->pc = 0x113B7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113B78u;
            // 0x113b7c: 0x2406ffff  addiu       $a2, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114300u;
    if (runtime->hasFunction(0x114300u)) {
        auto targetFn = runtime->lookupFunction(0x114300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B80u; }
        if (ctx->pc != 0x113B80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114300_0x114300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B80u; }
        if (ctx->pc != 0x113B80u) { return; }
    }
    ctx->pc = 0x113B80u;
label_113b80:
    // 0x113b80: 0xae02000c  sw          $v0, 0xC($s0)
    ctx->pc = 0x113b80u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x113b84: 0xc04545a  jal         func_115168
    ctx->pc = 0x113B84u;
    SET_GPR_U32(ctx, 31, 0x113B8Cu);
    ctx->pc = 0x113B88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113B84u;
            // 0x113b88: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115168u;
    if (runtime->hasFunction(0x115168u)) {
        auto targetFn = runtime->lookupFunction(0x115168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B8Cu; }
        if (ctx->pc != 0x113B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115168_0x115168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113B8Cu; }
        if (ctx->pc != 0x113B8Cu) { return; }
    }
    ctx->pc = 0x113B8Cu;
label_113b8c:
    // 0x113b8c: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x113b8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113b90: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x113b90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x113b94: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x113b94u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x113b98: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x113b98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x113b9c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x113b9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113ba0: 0x3e00008  jr          $ra
    ctx->pc = 0x113BA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113BA0u;
            // 0x113ba4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113B24u: goto label_113b24;
            case 0x113B38u: goto label_113b38;
            case 0x113B44u: goto label_113b44;
            case 0x113B50u: goto label_113b50;
            case 0x113B60u: goto label_113b60;
            case 0x113B6Cu: goto label_113b6c;
            case 0x113B70u: goto label_113b70;
            case 0x113B80u: goto label_113b80;
            case 0x113B8Cu: goto label_113b8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113BA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

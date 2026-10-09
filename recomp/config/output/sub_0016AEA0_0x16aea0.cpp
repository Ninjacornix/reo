#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016AEA0
// Address: 0x16aea0 - 0x16afc8
void sub_0016AEA0_0x16aea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016AEA0_0x16aea0");
#endif

    switch (ctx->pc) {
        case 0x16aee8u: goto label_16aee8;
        case 0x16af28u: goto label_16af28;
        case 0x16af3cu: goto label_16af3c;
        case 0x16af4cu: goto label_16af4c;
        case 0x16af60u: goto label_16af60;
        case 0x16af88u: goto label_16af88;
        default: break;
    }

    ctx->pc = 0x16aea0u;

    // 0x16aea0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x16aea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x16aea4: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x16aea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x16aea8: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16aea8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aeac: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16aeacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aeb0: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x16aeb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x16aeb4: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x16aeb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x16aeb8: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x16aeb8u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aebc: 0xffb70068  sd          $s7, 0x68($sp)
    ctx->pc = 0x16aebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 23));
    // 0x16aec0: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x16aec0u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aec4: 0xffbe0070  sd          $fp, 0x70($sp)
    ctx->pc = 0x16aec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 30));
    // 0x16aec8: 0x100f02d  daddu       $fp, $t0, $zero
    ctx->pc = 0x16aec8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16aecc: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16aeccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16aed0: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x16aed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x16aed4: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x16aed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x16aed8: 0xffb50058  sd          $s5, 0x58($sp)
    ctx->pc = 0x16aed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 21));
    // 0x16aedc: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x16aedcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x16aee0: 0xc059bf4  jal         func_166FD0
    ctx->pc = 0x16AEE0u;
    SET_GPR_U32(ctx, 31, 0x16AEE8u);
    ctx->pc = 0x16AEE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AEE0u;
            // 0x16aee4: 0xe0882d  daddu       $s1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FD0u;
    if (runtime->hasFunction(0x166FD0u)) {
        auto targetFn = runtime->lookupFunction(0x166FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AEE8u; }
        if (ctx->pc != 0x16AEE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166FD0_0x166fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AEE8u; }
        if (ctx->pc != 0x16AEE8u) { return; }
    }
    ctx->pc = 0x16AEE8u;
label_16aee8:
    // 0x16aee8: 0x1440002b  bnez        $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x16AEE8u;
    {
        const bool branch_taken_0x16aee8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16AEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AEE8u;
            // 0x16aeec: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16aee8) {
            ctx->pc = 0x16AF98u;
            goto label_16af98;
        }
    }
    ctx->pc = 0x16AEF0u;
    // 0x16aef0: 0x8fb00004  lw          $s0, 0x4($sp)
    ctx->pc = 0x16aef0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16aef4: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x16aef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16aef8: 0x8fb30000  lw          $s3, 0x0($sp)
    ctx->pc = 0x16aef8u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16aefc: 0x211202a  slt         $a0, $s0, $s1
    ctx->pc = 0x16aefcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x16af00: 0x2031821  addu        $v1, $s0, $v1
    ctx->pc = 0x16af00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x16af04: 0x8fb40008  lw          $s4, 0x8($sp)
    ctx->pc = 0x16af04u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16af08: 0x71182a  slt         $v1, $v1, $s1
    ctx->pc = 0x16af08u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x16af0c: 0x14600021  bnez        $v1, . + 4 + (0x21 << 2)
    ctx->pc = 0x16AF0Cu;
    {
        const bool branch_taken_0x16af0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16AF10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF0Cu;
            // 0x16af10: 0x8fb50014  lw          $s5, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16af0c) {
            ctx->pc = 0x16AF94u;
            goto label_16af94;
        }
    }
    ctx->pc = 0x16AF14u;
    // 0x16af14: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16AF14u;
    {
        const bool branch_taken_0x16af14 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x16AF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF14u;
            // 0x16af18: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16af14) {
            ctx->pc = 0x16AF30u;
            goto label_16af30;
        }
    }
    ctx->pc = 0x16AF1Cu;
    // 0x16af1c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x16af1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16af20: 0xc055798  jal         func_155E60
    ctx->pc = 0x16AF20u;
    SET_GPR_U32(ctx, 31, 0x16AF28u);
    ctx->pc = 0x16AF24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF20u;
            // 0x16af24: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF28u; }
        if (ctx->pc != 0x16AF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF28u; }
        if (ctx->pc != 0x16AF28u) { return; }
    }
    ctx->pc = 0x16AF28u;
label_16af28:
    // 0x16af28: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x16AF28u;
    {
        const bool branch_taken_0x16af28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF28u;
            // 0x16af2c: 0x2a0382d  daddu       $a3, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16af28) {
            ctx->pc = 0x16AF50u;
            goto label_16af50;
        }
    }
    ctx->pc = 0x16AF30u;
label_16af30:
    // 0x16af30: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x16af30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16af34: 0xc055798  jal         func_155E60
    ctx->pc = 0x16AF34u;
    SET_GPR_U32(ctx, 31, 0x16AF3Cu);
    ctx->pc = 0x16AF38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF34u;
            // 0x16af38: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF3Cu; }
        if (ctx->pc != 0x16AF3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF3Cu; }
        if (ctx->pc != 0x16AF3Cu) { return; }
    }
    ctx->pc = 0x16AF3Cu;
label_16af3c:
    // 0x16af3c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x16af3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16af40: 0x2502821  addu        $a1, $s2, $s0
    ctx->pc = 0x16af40u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x16af44: 0xc055798  jal         func_155E60
    ctx->pc = 0x16AF44u;
    SET_GPR_U32(ctx, 31, 0x16AF4Cu);
    ctx->pc = 0x16AF48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF44u;
            // 0x16af48: 0x2303023  subu        $a2, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF4Cu; }
        if (ctx->pc != 0x16AF4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF4Cu; }
        if (ctx->pc != 0x16AF4Cu) { return; }
    }
    ctx->pc = 0x16AF4Cu;
label_16af4c:
    // 0x16af4c: 0x2a0382d  daddu       $a3, $s5, $zero
    ctx->pc = 0x16af4cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_16af50:
    // 0x16af50: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x16af50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16af54: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x16af54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16af58: 0xc059c32  jal         func_1670C8
    ctx->pc = 0x16AF58u;
    SET_GPR_U32(ctx, 31, 0x16AF60u);
    ctx->pc = 0x16AF5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF58u;
            // 0x16af5c: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1670C8u;
    if (runtime->hasFunction(0x1670C8u)) {
        auto targetFn = runtime->lookupFunction(0x1670C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF60u; }
        if (ctx->pc != 0x16AF60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001670C8_0x1670c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF60u; }
        if (ctx->pc != 0x16AF60u) { return; }
    }
    ctx->pc = 0x16AF60u;
label_16af60:
    // 0x16af60: 0x5440000d  bnel        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x16AF60u;
    {
        const bool branch_taken_0x16af60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16af60) {
            ctx->pc = 0x16AF64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF60u;
            // 0x16af64: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16AF98u;
            goto label_16af98;
        }
    }
    ctx->pc = 0x16AF68u;
    // 0x16af68: 0x7c00009  bltz        $fp, . + 4 + (0x9 << 2)
    ctx->pc = 0x16AF68u;
    {
        const bool branch_taken_0x16af68 = (GPR_S64(ctx, 30) < 0);
        ctx->pc = 0x16AF6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF68u;
            // 0x16af6c: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16af68) {
            ctx->pc = 0x16AF90u;
            goto label_16af90;
        }
    }
    ctx->pc = 0x16AF70u;
    // 0x16af70: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x16af70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16af74: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x16af74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x16af78: 0xafbe0020  sw          $fp, 0x20($sp)
    ctx->pc = 0x16af78u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 30));
    // 0x16af7c: 0xafb30024  sw          $s3, 0x24($sp)
    ctx->pc = 0x16af7cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
    // 0x16af80: 0xc05d086  jal         func_174218
    ctx->pc = 0x16AF80u;
    SET_GPR_U32(ctx, 31, 0x16AF88u);
    ctx->pc = 0x16AF84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF80u;
            // 0x16af84: 0xafb10028  sw          $s1, 0x28($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174218u;
    if (runtime->hasFunction(0x174218u)) {
        auto targetFn = runtime->lookupFunction(0x174218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF88u; }
        if (ctx->pc != 0x16AF88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174218_0x174218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AF88u; }
        if (ctx->pc != 0x16AF88u) { return; }
    }
    ctx->pc = 0x16AF88u;
label_16af88:
    // 0x16af88: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16AF88u;
    {
        const bool branch_taken_0x16af88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16AF8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AF88u;
            // 0x16af8c: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16af88) {
            ctx->pc = 0x16AF98u;
            goto label_16af98;
        }
    }
    ctx->pc = 0x16AF90u;
label_16af90:
    // 0x16af90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16af90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_16af94:
    // 0x16af94: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x16af94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_16af98:
    // 0x16af98: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x16af98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16af9c: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x16af9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16afa0: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x16afa0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16afa4: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x16afa4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x16afa8: 0xdfb50058  ld          $s5, 0x58($sp)
    ctx->pc = 0x16afa8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x16afac: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x16afacu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x16afb0: 0xdfb70068  ld          $s7, 0x68($sp)
    ctx->pc = 0x16afb0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x16afb4: 0xdfbe0070  ld          $fp, 0x70($sp)
    ctx->pc = 0x16afb4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x16afb8: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x16afb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x16afbc: 0x3e00008  jr          $ra
    ctx->pc = 0x16AFBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16AFC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AFBCu;
            // 0x16afc0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AEE8u: goto label_16aee8;
            case 0x16AF28u: goto label_16af28;
            case 0x16AF30u: goto label_16af30;
            case 0x16AF3Cu: goto label_16af3c;
            case 0x16AF4Cu: goto label_16af4c;
            case 0x16AF50u: goto label_16af50;
            case 0x16AF60u: goto label_16af60;
            case 0x16AF88u: goto label_16af88;
            case 0x16AF90u: goto label_16af90;
            case 0x16AF94u: goto label_16af94;
            case 0x16AF98u: goto label_16af98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16AFC4u;
    // 0x16afc4: 0x0  nop
    ctx->pc = 0x16afc4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

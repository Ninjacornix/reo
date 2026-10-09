#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ADB30
// Address: 0x1adb30 - 0x1adbfc
void sub_001ADB30_0x1adb30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ADB30_0x1adb30");
#endif

    switch (ctx->pc) {
        case 0x1adb4cu: goto label_1adb4c;
        case 0x1adb68u: goto label_1adb68;
        case 0x1adb80u: goto label_1adb80;
        case 0x1adbb8u: goto label_1adbb8;
        case 0x1adbd8u: goto label_1adbd8;
        case 0x1adbe4u: goto label_1adbe4;
        default: break;
    }

    ctx->pc = 0x1adb30u;

    // 0x1adb30: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1adb30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1adb34: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1adb34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1adb38: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1adb38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1adb3c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1adb3cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adb40: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1adb40u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1adb44: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1ADB44u;
    SET_GPR_U32(ctx, 31, 0x1ADB4Cu);
    ctx->pc = 0x1ADB48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB44u;
            // 0x1adb48: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB4Cu; }
        if (ctx->pc != 0x1ADB4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB4Cu; }
        if (ctx->pc != 0x1ADB4Cu) { return; }
    }
    ctx->pc = 0x1ADB4Cu;
label_1adb4c:
    // 0x1adb4c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1adb4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adb50: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADB50u;
    {
        const bool branch_taken_0x1adb50 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1ADB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB50u;
            // 0x1adb54: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb50) {
            ctx->pc = 0x1ADB60u;
            goto label_1adb60;
        }
    }
    ctx->pc = 0x1ADB58u;
    // 0x1adb58: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1ADB58u;
    {
        const bool branch_taken_0x1adb58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB58u;
            // 0x1adb5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb58) {
            ctx->pc = 0x1ADBE8u;
            goto label_1adbe8;
        }
    }
    ctx->pc = 0x1ADB60u;
label_1adb60:
    // 0x1adb60: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1ADB60u;
    SET_GPR_U32(ctx, 31, 0x1ADB68u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB68u; }
        if (ctx->pc != 0x1ADB68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB68u; }
        if (ctx->pc != 0x1ADB68u) { return; }
    }
    ctx->pc = 0x1ADB68u;
label_1adb68:
    // 0x1adb68: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADB68u;
    {
        const bool branch_taken_0x1adb68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB68u;
            // 0x1adb6c: 0x2404000a  addiu       $a0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb68) {
            ctx->pc = 0x1ADB78u;
            goto label_1adb78;
        }
    }
    ctx->pc = 0x1ADB70u;
    // 0x1adb70: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1ADB70u;
    {
        const bool branch_taken_0x1adb70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB70u;
            // 0x1adb74: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb70) {
            ctx->pc = 0x1ADBE8u;
            goto label_1adbe8;
        }
    }
    ctx->pc = 0x1ADB78u;
label_1adb78:
    // 0x1adb78: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1ADB78u;
    SET_GPR_U32(ctx, 31, 0x1ADB80u);
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB80u; }
        if (ctx->pc != 0x1ADB80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADB80u; }
        if (ctx->pc != 0x1ADB80u) { return; }
    }
    ctx->pc = 0x1ADB80u;
label_1adb80:
    // 0x1adb80: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1ADB80u;
    {
        const bool branch_taken_0x1adb80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB80u;
            // 0x1adb84: 0x111840  sll         $v1, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb80) {
            ctx->pc = 0x1ADB98u;
            goto label_1adb98;
        }
    }
    ctx->pc = 0x1ADB88u;
    // 0x1adb88: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ADB88u;
    {
        const bool branch_taken_0x1adb88 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1adb88) {
            ctx->pc = 0x1ADB98u;
            goto label_1adb98;
        }
    }
    ctx->pc = 0x1ADB90u;
    // 0x1adb90: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1ADB90u;
    {
        const bool branch_taken_0x1adb90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ADB94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADB90u;
            // 0x1adb94: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1adb90) {
            ctx->pc = 0x1ADBE8u;
            goto label_1adbe8;
        }
    }
    ctx->pc = 0x1ADB98u;
label_1adb98:
    // 0x1adb98: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adb98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adb9c: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1adb9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1adba0: 0x24428d78  addiu       $v0, $v0, -0x7288
    ctx->pc = 0x1adba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937976));
    // 0x1adba4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1adba4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1adba8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1adba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adbac: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1adbacu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1adbb0: 0xc06b7f4  jal         func_1ADFD0
    ctx->pc = 0x1ADBB0u;
    SET_GPR_U32(ctx, 31, 0x1ADBB8u);
    ctx->pc = 0x1ADBB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBB0u;
            // 0x1adbb4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADFD0u;
    if (runtime->hasFunction(0x1ADFD0u)) {
        auto targetFn = runtime->lookupFunction(0x1ADFD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBB8u; }
        if (ctx->pc != 0x1ADBB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADFD0_0x1adfd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBB8u; }
        if (ctx->pc != 0x1ADBB8u) { return; }
    }
    ctx->pc = 0x1ADBB8u;
label_1adbb8:
    // 0x1adbb8: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adbb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adbbc: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1adbbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1adbc0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1adbc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adbc4: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1adbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1adbc8: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1adbc8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adbcc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1adbccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1adbd0: 0xc04cd24  jal         func_133490
    ctx->pc = 0x1ADBD0u;
    SET_GPR_U32(ctx, 31, 0x1ADBD8u);
    ctx->pc = 0x1ADBD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBD0u;
            // 0x1adbd4: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133490u;
    if (runtime->hasFunction(0x133490u)) {
        auto targetFn = runtime->lookupFunction(0x133490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBD8u; }
        if (ctx->pc != 0x1ADBD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133490_0x133490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBD8u; }
        if (ctx->pc != 0x1ADBD8u) { return; }
    }
    ctx->pc = 0x1ADBD8u;
label_1adbd8:
    // 0x1adbd8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1adbd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1adbdc: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1ADBDCu;
    SET_GPR_U32(ctx, 31, 0x1ADBE4u);
    ctx->pc = 0x1ADBE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBDCu;
            // 0x1adbe0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBE4u; }
        if (ctx->pc != 0x1ADBE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADBE4u; }
        if (ctx->pc != 0x1ADBE4u) { return; }
    }
    ctx->pc = 0x1ADBE4u;
label_1adbe4:
    // 0x1adbe4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1adbe4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1adbe8:
    // 0x1adbe8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1adbe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1adbec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1adbecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1adbf0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1adbf0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1adbf4: 0x3e00008  jr          $ra
    ctx->pc = 0x1ADBF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ADBF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADBF4u;
            // 0x1adbf8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ADB4Cu: goto label_1adb4c;
            case 0x1ADB60u: goto label_1adb60;
            case 0x1ADB68u: goto label_1adb68;
            case 0x1ADB78u: goto label_1adb78;
            case 0x1ADB80u: goto label_1adb80;
            case 0x1ADB98u: goto label_1adb98;
            case 0x1ADBB8u: goto label_1adbb8;
            case 0x1ADBD8u: goto label_1adbd8;
            case 0x1ADBE4u: goto label_1adbe4;
            case 0x1ADBE8u: goto label_1adbe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ADBFCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

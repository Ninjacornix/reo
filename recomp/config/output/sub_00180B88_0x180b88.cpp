#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180B88
// Address: 0x180b88 - 0x180cd0
void sub_00180B88_0x180b88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180B88_0x180b88");
#endif

    switch (ctx->pc) {
        case 0x180bf0u: goto label_180bf0;
        case 0x180c14u: goto label_180c14;
        case 0x180c40u: goto label_180c40;
        case 0x180c74u: goto label_180c74;
        case 0x180c84u: goto label_180c84;
        case 0x180c98u: goto label_180c98;
        case 0x180ca0u: goto label_180ca0;
        case 0x180ca8u: goto label_180ca8;
        case 0x180cb4u: goto label_180cb4;
        default: break;
    }

    ctx->pc = 0x180b88u;

    // 0x180b88: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x180b88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x180b8c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x180b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x180b90: 0xffb20090  sd          $s2, 0x90($sp)
    ctx->pc = 0x180b90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 18));
    // 0x180b94: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x180b94u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x180b98: 0xffb00080  sd          $s0, 0x80($sp)
    ctx->pc = 0x180b98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 16));
    // 0x180b9c: 0x2445fa10  addiu       $a1, $v0, -0x5F0
    ctx->pc = 0x180b9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965776));
    // 0x180ba0: 0xffb10088  sd          $s1, 0x88($sp)
    ctx->pc = 0x180ba0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 17));
    // 0x180ba4: 0xffbf0098  sd          $ra, 0x98($sp)
    ctx->pc = 0x180ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 31));
    // 0x180ba8: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x180ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x180bac: 0x10720042  beq         $v1, $s2, . + 4 + (0x42 << 2)
    ctx->pc = 0x180BACu;
    {
        const bool branch_taken_0x180bac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 18));
        ctx->pc = 0x180BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180BACu;
            // 0x180bb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180bac) {
            ctx->pc = 0x180CB8u;
            goto label_180cb8;
        }
    }
    ctx->pc = 0x180BB4u;
    // 0x180bb4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180bb8: 0x1480003f  bnez        $a0, . + 4 + (0x3F << 2)
    ctx->pc = 0x180BB8u;
    {
        const bool branch_taken_0x180bb8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x180BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180BB8u;
            // 0x180bbc: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180bb8) {
            ctx->pc = 0x180CB8u;
            goto label_180cb8;
        }
    }
    ctx->pc = 0x180BC0u;
    // 0x180bc0: 0xacb20000  sw          $s2, 0x0($a1)
    ctx->pc = 0x180bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 18));
    // 0x180bc4: 0x27b00060  addiu       $s0, $sp, 0x60
    ctx->pc = 0x180bc4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x180bc8: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x180bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x180bcc: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x180bccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x180bd0: 0x24519a20  addiu       $s1, $v0, -0x65E0
    ctx->pc = 0x180bd0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941216));
    // 0x180bd4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x180bd4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180bd8: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x180bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x180bdc: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x180bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x180be0: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x180be0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x180be4: 0xafa00068  sw          $zero, 0x68($sp)
    ctx->pc = 0x180be4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 0));
    // 0x180be8: 0xc045188  jal         func_114620
    ctx->pc = 0x180BE8u;
    SET_GPR_U32(ctx, 31, 0x180BF0u);
    ctx->pc = 0x180BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180BE8u;
            // 0x180bec: 0xafb20064  sw          $s2, 0x64($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180BF0u; }
        if (ctx->pc != 0x180BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180BF0u; }
        if (ctx->pc != 0x180BF0u) { return; }
    }
    ctx->pc = 0x180BF0u;
label_180bf0:
    // 0x180bf0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x180bf0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180bf4: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180bf8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x180bf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180bfc: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x180bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x180c00: 0x460002d  bltz        $v1, . + 4 + (0x2D << 2)
    ctx->pc = 0x180C00u;
    {
        const bool branch_taken_0x180c00 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x180C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180C00u;
            // 0x180c04: 0x34428003  ori         $v0, $v0, 0x8003 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32771);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180c00) {
            ctx->pc = 0x180CB8u;
            goto label_180cb8;
        }
    }
    ctx->pc = 0x180C08u;
    // 0x180c08: 0xafa00068  sw          $zero, 0x68($sp)
    ctx->pc = 0x180c08u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 0));
    // 0x180c0c: 0xc045188  jal         func_114620
    ctx->pc = 0x180C0Cu;
    SET_GPR_U32(ctx, 31, 0x180C14u);
    ctx->pc = 0x180C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180C0Cu;
            // 0x180c10: 0xafb20064  sw          $s2, 0x64($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C14u; }
        if (ctx->pc != 0x180C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C14u; }
        if (ctx->pc != 0x180C14u) { return; }
    }
    ctx->pc = 0x180C14u;
label_180c14:
    // 0x180c14: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x180c14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x180c18: 0x3c030018  lui         $v1, 0x18
    ctx->pc = 0x180c18u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)24 << 16));
    // 0x180c1c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x180c1cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x180c20: 0x24869a40  addiu       $a2, $a0, -0x65C0
    ctx->pc = 0x180c20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941248));
    // 0x180c24: 0x24631a28  addiu       $v1, $v1, 0x1A28
    ctx->pc = 0x180c24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 6696));
    // 0x180c28: 0x24a51cf0  addiu       $a1, $a1, 0x1CF0
    ctx->pc = 0x180c28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7408));
    // 0x180c2c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x180c2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180c30: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x180C30u;
    {
        const bool branch_taken_0x180c30 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x180C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180C30u;
            // 0x180c34: 0xae220008  sw          $v0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180c30) {
            ctx->pc = 0x180C50u;
            goto label_180c50;
        }
    }
    ctx->pc = 0x180C38u;
    // 0x180c38: 0xc060334  jal         func_180CD0
    ctx->pc = 0x180C38u;
    SET_GPR_U32(ctx, 31, 0x180C40u);
    ctx->pc = 0x180CD0u;
    if (runtime->hasFunction(0x180CD0u)) {
        auto targetFn = runtime->lookupFunction(0x180CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C40u; }
        if (ctx->pc != 0x180C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180CD0_0x180cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C40u; }
        if (ctx->pc != 0x180C40u) { return; }
    }
    ctx->pc = 0x180C40u;
label_180c40:
    // 0x180c40: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180c40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180c44: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x180C44u;
    {
        const bool branch_taken_0x180c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180C44u;
            // 0x180c48: 0x34428003  ori         $v0, $v0, 0x8003 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32771);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180c44) {
            ctx->pc = 0x180CB8u;
            goto label_180cb8;
        }
    }
    ctx->pc = 0x180C4Cu;
    // 0x180c4c: 0x0  nop
    ctx->pc = 0x180c4cu;
    // NOP
label_180c50:
    // 0x180c50: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x180c50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x180c54: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x180c54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x180c58: 0xac409504  sw          $zero, -0x6AFC($v0)
    ctx->pc = 0x180c58u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294939908), GPR_U32(ctx, 0));
    // 0x180c5c: 0x3402c000  ori         $v0, $zero, 0xC000
    ctx->pc = 0x180c5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49152);
    // 0x180c60: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x180c60u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x180c64: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x180c64u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
    // 0x180c68: 0xafa50010  sw          $a1, 0x10($sp)
    ctx->pc = 0x180c68u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x180c6c: 0xc045108  jal         func_114420
    ctx->pc = 0x180C6Cu;
    SET_GPR_U32(ctx, 31, 0x180C74u);
    ctx->pc = 0x180C70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180C6Cu;
            // 0x180c70: 0xafb20014  sw          $s2, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C74u; }
        if (ctx->pc != 0x180C74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C74u; }
        if (ctx->pc != 0x180C74u) { return; }
    }
    ctx->pc = 0x180C74u;
label_180c74:
    // 0x180c74: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x180C74u;
    {
        const bool branch_taken_0x180c74 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x180C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180C74u;
            // 0x180c78: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180c74) {
            ctx->pc = 0x180C90u;
            goto label_180c90;
        }
    }
    ctx->pc = 0x180C7Cu;
    // 0x180c7c: 0xc060334  jal         func_180CD0
    ctx->pc = 0x180C7Cu;
    SET_GPR_U32(ctx, 31, 0x180C84u);
    ctx->pc = 0x180CD0u;
    if (runtime->hasFunction(0x180CD0u)) {
        auto targetFn = runtime->lookupFunction(0x180CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C84u; }
        if (ctx->pc != 0x180C84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180CD0_0x180cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C84u; }
        if (ctx->pc != 0x180C84u) { return; }
    }
    ctx->pc = 0x180C84u;
label_180c84:
    // 0x180c84: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x180c84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x180c88: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x180C88u;
    {
        const bool branch_taken_0x180c88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180C88u;
            // 0x180c8c: 0x34428004  ori         $v0, $v0, 0x8004 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32772);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180c88) {
            ctx->pc = 0x180CB8u;
            goto label_180cb8;
        }
    }
    ctx->pc = 0x180C90u;
label_180c90:
    // 0x180c90: 0xc061e0e  jal         func_187838
    ctx->pc = 0x180C90u;
    SET_GPR_U32(ctx, 31, 0x180C98u);
    ctx->pc = 0x187838u;
    if (runtime->hasFunction(0x187838u)) {
        auto targetFn = runtime->lookupFunction(0x187838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C98u; }
        if (ctx->pc != 0x180C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187838_0x187838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180C98u; }
        if (ctx->pc != 0x180C98u) { return; }
    }
    ctx->pc = 0x180C98u;
label_180c98:
    // 0x180c98: 0xc061aea  jal         func_186BA8
    ctx->pc = 0x180C98u;
    SET_GPR_U32(ctx, 31, 0x180CA0u);
    ctx->pc = 0x186BA8u;
    if (runtime->hasFunction(0x186BA8u)) {
        auto targetFn = runtime->lookupFunction(0x186BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180CA0u; }
        if (ctx->pc != 0x180CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00186BA8_0x186ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180CA0u; }
        if (ctx->pc != 0x180CA0u) { return; }
    }
    ctx->pc = 0x180CA0u;
label_180ca0:
    // 0x180ca0: 0xc060a08  jal         func_182820
    ctx->pc = 0x180CA0u;
    SET_GPR_U32(ctx, 31, 0x180CA8u);
    ctx->pc = 0x182820u;
    if (runtime->hasFunction(0x182820u)) {
        auto targetFn = runtime->lookupFunction(0x182820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180CA8u; }
        if (ctx->pc != 0x180CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182820_0x182820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180CA8u; }
        if (ctx->pc != 0x180CA8u) { return; }
    }
    ctx->pc = 0x180CA8u;
label_180ca8:
    // 0x180ca8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x180ca8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x180cac: 0xc045110  jal         func_114440
    ctx->pc = 0x180CACu;
    SET_GPR_U32(ctx, 31, 0x180CB4u);
    ctx->pc = 0x180CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180CACu;
            // 0x180cb0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180CB4u; }
        if (ctx->pc != 0x180CB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180CB4u; }
        if (ctx->pc != 0x180CB4u) { return; }
    }
    ctx->pc = 0x180CB4u;
label_180cb4:
    // 0x180cb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x180cb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_180cb8:
    // 0x180cb8: 0xdfb00080  ld          $s0, 0x80($sp)
    ctx->pc = 0x180cb8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x180cbc: 0xdfb10088  ld          $s1, 0x88($sp)
    ctx->pc = 0x180cbcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x180cc0: 0xdfb20090  ld          $s2, 0x90($sp)
    ctx->pc = 0x180cc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x180cc4: 0xdfbf0098  ld          $ra, 0x98($sp)
    ctx->pc = 0x180cc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x180cc8: 0x3e00008  jr          $ra
    ctx->pc = 0x180CC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180CC8u;
            // 0x180ccc: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180BF0u: goto label_180bf0;
            case 0x180C14u: goto label_180c14;
            case 0x180C40u: goto label_180c40;
            case 0x180C50u: goto label_180c50;
            case 0x180C74u: goto label_180c74;
            case 0x180C84u: goto label_180c84;
            case 0x180C90u: goto label_180c90;
            case 0x180C98u: goto label_180c98;
            case 0x180CA0u: goto label_180ca0;
            case 0x180CA8u: goto label_180ca8;
            case 0x180CB4u: goto label_180cb4;
            case 0x180CB8u: goto label_180cb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180CD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100B70
// Address: 0x100b70 - 0x100ce0
void sub_00100B70_0x100b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100B70_0x100b70");
#endif

    switch (ctx->pc) {
        case 0x100b90u: goto label_100b90;
        case 0x100b9cu: goto label_100b9c;
        case 0x100bc8u: goto label_100bc8;
        case 0x100becu: goto label_100bec;
        case 0x100bf4u: goto label_100bf4;
        case 0x100c08u: goto label_100c08;
        case 0x100c18u: goto label_100c18;
        case 0x100c30u: goto label_100c30;
        case 0x100c38u: goto label_100c38;
        case 0x100c58u: goto label_100c58;
        case 0x100c6cu: goto label_100c6c;
        case 0x100c90u: goto label_100c90;
        case 0x100c98u: goto label_100c98;
        default: break;
    }

    ctx->pc = 0x100b70u;

    // 0x100b70: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x100b70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x100b74: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100b78: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100b7c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x100b7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100b80: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x100b80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x100b84: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x100b84u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x100b88: 0xc040164  jal         func_100590
    ctx->pc = 0x100B88u;
    SET_GPR_U32(ctx, 31, 0x100B90u);
    ctx->pc = 0x100B8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100B88u;
            // 0x100b8c: 0xffb20020  sd          $s2, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100590u;
    if (runtime->hasFunction(0x100590u)) {
        auto targetFn = runtime->lookupFunction(0x100590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B90u; }
        if (ctx->pc != 0x100B90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B90u; }
        if (ctx->pc != 0x100B90u) { return; }
    }
    ctx->pc = 0x100B90u;
label_100b90:
    // 0x100b90: 0x8e047928  lw          $a0, 0x7928($s0)
    ctx->pc = 0x100b90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31016)));
    // 0x100b94: 0xc04519c  jal         func_114670
    ctx->pc = 0x100B94u;
    SET_GPR_U32(ctx, 31, 0x100B9Cu);
    ctx->pc = 0x114670u;
    if (runtime->hasFunction(0x114670u)) {
        auto targetFn = runtime->lookupFunction(0x114670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B9Cu; }
        if (ctx->pc != 0x100B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B9Cu; }
        if (ctx->pc != 0x100B9Cu) { return; }
    }
    ctx->pc = 0x100B9Cu;
label_100b9c:
    // 0x100b9c: 0x8e037928  lw          $v1, 0x7928($s0)
    ctx->pc = 0x100b9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31016)));
    // 0x100ba0: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x100BA0u;
    {
        const bool branch_taken_0x100ba0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x100BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100BA0u;
            // 0x100ba4: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100ba0) {
            ctx->pc = 0x100BD0u;
            goto label_100bd0;
        }
    }
    ctx->pc = 0x100BA8u;
    // 0x100ba8: 0x8c437910  lw          $v1, 0x7910($v0)
    ctx->pc = 0x100ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100bac: 0x18600016  blez        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x100BACu;
    {
        const bool branch_taken_0x100bac = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100BACu;
            // 0x100bb0: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100bac) {
            ctx->pc = 0x100C08u;
            goto label_100c08;
        }
    }
    ctx->pc = 0x100BB4u;
    // 0x100bb4: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x100bb4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x100bb8: 0x8c46791c  lw          $a2, 0x791C($v0)
    ctx->pc = 0x100bb8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31004)));
    // 0x100bbc: 0x24847518  addiu       $a0, $a0, 0x7518
    ctx->pc = 0x100bbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29976));
    // 0x100bc0: 0xc045a12  jal         func_116848
    ctx->pc = 0x100BC0u;
    SET_GPR_U32(ctx, 31, 0x100BC8u);
    ctx->pc = 0x100BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100BC0u;
            // 0x100bc4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BC8u; }
        if (ctx->pc != 0x100BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BC8u; }
        if (ctx->pc != 0x100BC8u) { return; }
    }
    ctx->pc = 0x100BC8u;
label_100bc8:
    // 0x100bc8: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x100BC8u;
    {
        const bool branch_taken_0x100bc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100BC8u;
            // 0x100bcc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100bc8) {
            ctx->pc = 0x100CC8u;
            goto label_100cc8;
        }
    }
    ctx->pc = 0x100BD0u;
label_100bd0:
    // 0x100bd0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x100bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x100bd4: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x100bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x100bd8: 0x8c449f98  lw          $a0, -0x6068($v0)
    ctx->pc = 0x100bd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942616)));
    // 0x100bdc: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x100bdcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x100be0: 0xac71791c  sw          $s1, 0x791C($v1)
    ctx->pc = 0x100be0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31004), GPR_U32(ctx, 17));
    // 0x100be4: 0xc045148  jal         func_114520
    ctx->pc = 0x100BE4u;
    SET_GPR_U32(ctx, 31, 0x100BECu);
    ctx->pc = 0x100BE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100BE4u;
            // 0x100be8: 0x24a59fa0  addiu       $a1, $a1, -0x6060 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BECu; }
        if (ctx->pc != 0x100BECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BECu; }
        if (ctx->pc != 0x100BECu) { return; }
    }
    ctx->pc = 0x100BECu;
label_100bec:
    // 0x100bec: 0xc04035e  jal         func_100D78
    ctx->pc = 0x100BECu;
    SET_GPR_U32(ctx, 31, 0x100BF4u);
    ctx->pc = 0x100BF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100BECu;
            // 0x100bf0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BF4u; }
        if (ctx->pc != 0x100BF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100BF4u; }
        if (ctx->pc != 0x100BF4u) { return; }
    }
    ctx->pc = 0x100BF4u;
label_100bf4:
    // 0x100bf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x100BF4u;
    {
        const bool branch_taken_0x100bf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100BF4u;
            // 0x100bf8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100bf4) {
            ctx->pc = 0x100C10u;
            goto label_100c10;
        }
    }
    ctx->pc = 0x100BFCu;
    // 0x100bfc: 0x8e047928  lw          $a0, 0x7928($s0)
    ctx->pc = 0x100bfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 31016)));
    // 0x100c00: 0xc045190  jal         func_114640
    ctx->pc = 0x100C00u;
    SET_GPR_U32(ctx, 31, 0x100C08u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C08u; }
        if (ctx->pc != 0x100C08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C08u; }
        if (ctx->pc != 0x100C08u) { return; }
    }
    ctx->pc = 0x100C08u;
label_100c08:
    // 0x100c08: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x100C08u;
    {
        const bool branch_taken_0x100c08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100C08u;
            // 0x100c0c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100c08) {
            ctx->pc = 0x100CC8u;
            goto label_100cc8;
        }
    }
    ctx->pc = 0x100C10u;
label_100c10:
    // 0x100c10: 0xc045c20  jal         func_117080
    ctx->pc = 0x100C10u;
    SET_GPR_U32(ctx, 31, 0x100C18u);
    ctx->pc = 0x100C14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100C10u;
            // 0x100c14: 0x3c120020  lui         $s2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C18u; }
        if (ctx->pc != 0x100C18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C18u; }
        if (ctx->pc != 0x100C18u) { return; }
    }
    ctx->pc = 0x100C18u;
label_100c18:
    // 0x100c18: 0x8e42793c  lw          $v0, 0x793C($s2)
    ctx->pc = 0x100c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 31036)));
    // 0x100c1c: 0x441002a  bgez        $v0, . + 4 + (0x2A << 2)
    ctx->pc = 0x100C1Cu;
    {
        const bool branch_taken_0x100c1c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x100C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100C1Cu;
            // 0x100c20: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100c1c) {
            ctx->pc = 0x100CC8u;
            goto label_100cc8;
        }
    }
    ctx->pc = 0x100C24u;
    // 0x100c24: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x100C24u;
    {
        const bool branch_taken_0x100c24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100C24u;
            // 0x100c28: 0x3c110021  lui         $s1, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100c24) {
            ctx->pc = 0x100C54u;
            goto label_100c54;
        }
    }
    ctx->pc = 0x100C2Cu;
    // 0x100c2c: 0x0  nop
    ctx->pc = 0x100c2cu;
    // NOP
label_100c30:
    // 0x100c30: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x100c30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x100c34: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x100c34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_100c38:
    // 0x100c38: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x100c38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100c3c: 0x0  nop
    ctx->pc = 0x100c3cu;
    // NOP
    // 0x100c40: 0x0  nop
    ctx->pc = 0x100c40u;
    // NOP
    // 0x100c44: 0x0  nop
    ctx->pc = 0x100c44u;
    // NOP
    // 0x100c48: 0x0  nop
    ctx->pc = 0x100c48u;
    // NOP
    // 0x100c4c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x100C4Cu;
    {
        const bool branch_taken_0x100c4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x100c4c) {
            ctx->pc = 0x100C38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100c38;
        }
    }
    ctx->pc = 0x100C54u;
label_100c54:
    // 0x100c54: 0x26308ad0  addiu       $s0, $s1, -0x7530
    ctx->pc = 0x100c54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294937296));
label_100c58:
    // 0x100c58: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x100c58u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x100c5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x100c5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100c60: 0x34a50595  ori         $a1, $a1, 0x595
    ctx->pc = 0x100c60u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1429);
    // 0x100c64: 0xc045e06  jal         func_117818
    ctx->pc = 0x100C64u;
    SET_GPR_U32(ctx, 31, 0x100C6Cu);
    ctx->pc = 0x100C68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100C64u;
            // 0x100c68: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C6Cu; }
        if (ctx->pc != 0x100C6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C6Cu; }
        if (ctx->pc != 0x100C6Cu) { return; }
    }
    ctx->pc = 0x100C6Cu;
label_100c6c:
    // 0x100c6c: 0x4430013  bgezl       $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x100C6Cu;
    {
        const bool branch_taken_0x100c6c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x100c6c) {
            ctx->pc = 0x100C70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x100C6Cu;
            // 0x100c70: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x100CBCu;
            goto label_100cbc;
        }
    }
    ctx->pc = 0x100C74u;
    // 0x100c74: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100c74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x100c78: 0x8c437910  lw          $v1, 0x7910($v0)
    ctx->pc = 0x100c78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100c7c: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x100C7Cu;
    {
        const bool branch_taken_0x100c7c = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100C80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100C7Cu;
            // 0x100c80: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100c7c) {
            ctx->pc = 0x100C94u;
            goto label_100c94;
        }
    }
    ctx->pc = 0x100C84u;
    // 0x100c84: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x100c84u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x100c88: 0xc045a12  jal         func_116848
    ctx->pc = 0x100C88u;
    SET_GPR_U32(ctx, 31, 0x100C90u);
    ctx->pc = 0x100C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100C88u;
            // 0x100c8c: 0x24847540  addiu       $a0, $a0, 0x7540 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30016));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C90u; }
        if (ctx->pc != 0x100C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100C90u; }
        if (ctx->pc != 0x100C90u) { return; }
    }
    ctx->pc = 0x100C90u;
label_100c90:
    // 0x100c90: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x100c90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
label_100c94:
    // 0x100c94: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x100c94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_100c98:
    // 0x100c98: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x100c98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100c9c: 0x0  nop
    ctx->pc = 0x100c9cu;
    // NOP
    // 0x100ca0: 0x0  nop
    ctx->pc = 0x100ca0u;
    // NOP
    // 0x100ca4: 0x0  nop
    ctx->pc = 0x100ca4u;
    // NOP
    // 0x100ca8: 0x0  nop
    ctx->pc = 0x100ca8u;
    // NOP
    // 0x100cac: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x100CACu;
    {
        const bool branch_taken_0x100cac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x100cac) {
            ctx->pc = 0x100C98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100c98;
        }
    }
    ctx->pc = 0x100CB4u;
    // 0x100cb4: 0x1000ffe8  b           . + 4 + (-0x18 << 2)
    ctx->pc = 0x100CB4u;
    {
        const bool branch_taken_0x100cb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100CB4u;
            // 0x100cb8: 0x26308ad0  addiu       $s0, $s1, -0x7530 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294937296));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100cb4) {
            ctx->pc = 0x100C58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100c58;
        }
    }
    ctx->pc = 0x100CBCu;
label_100cbc:
    // 0x100cbc: 0x1040ffdc  beqz        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x100CBCu;
    {
        const bool branch_taken_0x100cbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100CBCu;
            // 0x100cc0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100cbc) {
            ctx->pc = 0x100C30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100c30;
        }
    }
    ctx->pc = 0x100CC4u;
    // 0x100cc4: 0xae40793c  sw          $zero, 0x793C($s2)
    ctx->pc = 0x100cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 31036), GPR_U32(ctx, 0));
label_100cc8:
    // 0x100cc8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x100cc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100ccc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x100cccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100cd0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x100cd0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100cd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x100cd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100cd8: 0x3e00008  jr          $ra
    ctx->pc = 0x100CD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100CD8u;
            // 0x100cdc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100B90u: goto label_100b90;
            case 0x100B9Cu: goto label_100b9c;
            case 0x100BC8u: goto label_100bc8;
            case 0x100BD0u: goto label_100bd0;
            case 0x100BECu: goto label_100bec;
            case 0x100BF4u: goto label_100bf4;
            case 0x100C08u: goto label_100c08;
            case 0x100C10u: goto label_100c10;
            case 0x100C18u: goto label_100c18;
            case 0x100C30u: goto label_100c30;
            case 0x100C38u: goto label_100c38;
            case 0x100C54u: goto label_100c54;
            case 0x100C58u: goto label_100c58;
            case 0x100C6Cu: goto label_100c6c;
            case 0x100C90u: goto label_100c90;
            case 0x100C94u: goto label_100c94;
            case 0x100C98u: goto label_100c98;
            case 0x100CBCu: goto label_100cbc;
            case 0x100CC8u: goto label_100cc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100CE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

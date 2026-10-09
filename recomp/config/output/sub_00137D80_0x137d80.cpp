#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137D80
// Address: 0x137d80 - 0x137e90
void sub_00137D80_0x137d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137D80_0x137d80");
#endif

    switch (ctx->pc) {
        case 0x137dacu: goto label_137dac;
        case 0x137ddcu: goto label_137ddc;
        case 0x137de4u: goto label_137de4;
        case 0x137df8u: goto label_137df8;
        case 0x137e30u: goto label_137e30;
        case 0x137e38u: goto label_137e38;
        case 0x137e4cu: goto label_137e4c;
        default: break;
    }

    ctx->pc = 0x137d80u;

    // 0x137d80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x137d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x137d84: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137d84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137d88: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x137d88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x137d8c: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x137d8cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x137d90: 0x2664bbc4  addiu       $a0, $s3, -0x443C
    ctx->pc = 0x137d90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294949828));
    // 0x137d94: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x137d94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x137d98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137d98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137d9c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x137d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x137da0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x137da0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x137da4: 0xc050864  jal         func_142190
    ctx->pc = 0x137DA4u;
    SET_GPR_U32(ctx, 31, 0x137DACu);
    ctx->pc = 0x137DA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137DA4u;
            // 0x137da8: 0x2451bb88  addiu       $s1, $v0, -0x4478 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949768));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142190u;
    if (runtime->hasFunction(0x142190u)) {
        auto targetFn = runtime->lookupFunction(0x142190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DACu; }
        if (ctx->pc != 0x137DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142190_0x142190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DACu; }
        if (ctx->pc != 0x137DACu) { return; }
    }
    ctx->pc = 0x137DACu;
label_137dac:
    // 0x137dac: 0x10400028  beqz        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x137DACu;
    {
        const bool branch_taken_0x137dac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x137DB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137DACu;
            // 0x137db0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137dac) {
            ctx->pc = 0x137E50u;
            goto label_137e50;
        }
    }
    ctx->pc = 0x137DB4u;
    // 0x137db4: 0x82300001  lb          $s0, 0x1($s1)
    ctx->pc = 0x137db4u;
    SET_GPR_S32(ctx, 16, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x137db8: 0x16020010  bne         $s0, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x137DB8u;
    {
        const bool branch_taken_0x137db8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x137DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137DB8u;
            // 0x137dbc: 0x92230001  lbu         $v1, 0x1($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137db8) {
            ctx->pc = 0x137DFCu;
            goto label_137dfc;
        }
    }
    ctx->pc = 0x137DC0u;
    // 0x137dc0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x137dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x137dc4: 0x2452bbc8  addiu       $s2, $v0, -0x4438
    ctx->pc = 0x137dc4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949832));
    // 0x137dc8: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x137dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x137dcc: 0x14700003  bne         $v1, $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x137DCCu;
    {
        const bool branch_taken_0x137dcc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 16));
        if (branch_taken_0x137dcc) {
            ctx->pc = 0x137DDCu;
            goto label_137ddc;
        }
    }
    ctx->pc = 0x137DD4u;
    // 0x137dd4: 0xc0505cc  jal         func_141730
    ctx->pc = 0x137DD4u;
    SET_GPR_U32(ctx, 31, 0x137DDCu);
    ctx->pc = 0x141730u;
    if (runtime->hasFunction(0x141730u)) {
        auto targetFn = runtime->lookupFunction(0x141730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DDCu; }
        if (ctx->pc != 0x137DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141730_0x141730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DDCu; }
        if (ctx->pc != 0x137DDCu) { return; }
    }
    ctx->pc = 0x137DDCu;
label_137ddc:
    // 0x137ddc: 0xc04de74  jal         func_1379D0
    ctx->pc = 0x137DDCu;
    SET_GPR_U32(ctx, 31, 0x137DE4u);
    ctx->pc = 0x137DE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137DDCu;
            // 0x137de0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1379D0u;
    if (runtime->hasFunction(0x1379D0u)) {
        auto targetFn = runtime->lookupFunction(0x1379D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DE4u; }
        if (ctx->pc != 0x137DE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001379D0_0x1379d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DE4u; }
        if (ctx->pc != 0x137DE4u) { return; }
    }
    ctx->pc = 0x137DE4u;
label_137de4:
    // 0x137de4: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x137de4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x137de8: 0x54500004  bnel        $v0, $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x137DE8u;
    {
        const bool branch_taken_0x137de8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        if (branch_taken_0x137de8) {
            ctx->pc = 0x137DECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137DE8u;
            // 0x137dec: 0x92230001  lbu         $v1, 0x1($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137DFCu;
            goto label_137dfc;
        }
    }
    ctx->pc = 0x137DF0u;
    // 0x137df0: 0xc0505ea  jal         func_1417A8
    ctx->pc = 0x137DF0u;
    SET_GPR_U32(ctx, 31, 0x137DF8u);
    ctx->pc = 0x1417A8u;
    if (runtime->hasFunction(0x1417A8u)) {
        auto targetFn = runtime->lookupFunction(0x1417A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DF8u; }
        if (ctx->pc != 0x137DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001417A8_0x1417a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137DF8u; }
        if (ctx->pc != 0x137DF8u) { return; }
    }
    ctx->pc = 0x137DF8u;
label_137df8:
    // 0x137df8: 0x92230001  lbu         $v1, 0x1($s1)
    ctx->pc = 0x137df8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
label_137dfc:
    // 0x137dfc: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x137dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x137e00: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x137e00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x137e04: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x137e04u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x137e08: 0x54430011  bnel        $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x137E08u;
    {
        const bool branch_taken_0x137e08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x137e08) {
            ctx->pc = 0x137E0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137E08u;
            // 0x137e0c: 0xae60bbc4  sw          $zero, -0x443C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4294949828), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137E50u;
            goto label_137e50;
        }
    }
    ctx->pc = 0x137E10u;
    // 0x137e10: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137e10u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137e14: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x137e14u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137e18: 0x2470bbcc  addiu       $s0, $v1, -0x4434
    ctx->pc = 0x137e18u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949836));
    // 0x137e1c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x137e1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x137e20: 0x14520003  bne         $v0, $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x137E20u;
    {
        const bool branch_taken_0x137e20 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x137e20) {
            ctx->pc = 0x137E30u;
            goto label_137e30;
        }
    }
    ctx->pc = 0x137E28u;
    // 0x137e28: 0xc0505cc  jal         func_141730
    ctx->pc = 0x137E28u;
    SET_GPR_U32(ctx, 31, 0x137E30u);
    ctx->pc = 0x141730u;
    if (runtime->hasFunction(0x141730u)) {
        auto targetFn = runtime->lookupFunction(0x141730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137E30u; }
        if (ctx->pc != 0x137E30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141730_0x141730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137E30u; }
        if (ctx->pc != 0x137E30u) { return; }
    }
    ctx->pc = 0x137E30u;
label_137e30:
    // 0x137e30: 0xc04dee8  jal         func_137BA0
    ctx->pc = 0x137E30u;
    SET_GPR_U32(ctx, 31, 0x137E38u);
    ctx->pc = 0x137E34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x137E30u;
            // 0x137e34: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137BA0u;
    if (runtime->hasFunction(0x137BA0u)) {
        auto targetFn = runtime->lookupFunction(0x137BA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137E38u; }
        if (ctx->pc != 0x137E38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137BA0_0x137ba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137E38u; }
        if (ctx->pc != 0x137E38u) { return; }
    }
    ctx->pc = 0x137E38u;
label_137e38:
    // 0x137e38: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x137e38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x137e3c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x137E3Cu;
    {
        const bool branch_taken_0x137e3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x137e3c) {
            ctx->pc = 0x137E40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x137E3Cu;
            // 0x137e40: 0xae60bbc4  sw          $zero, -0x443C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4294949828), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137E50u;
            goto label_137e50;
        }
    }
    ctx->pc = 0x137E44u;
    // 0x137e44: 0xc0505ea  jal         func_1417A8
    ctx->pc = 0x137E44u;
    SET_GPR_U32(ctx, 31, 0x137E4Cu);
    ctx->pc = 0x1417A8u;
    if (runtime->hasFunction(0x1417A8u)) {
        auto targetFn = runtime->lookupFunction(0x1417A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137E4Cu; }
        if (ctx->pc != 0x137E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001417A8_0x1417a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137E4Cu; }
        if (ctx->pc != 0x137E4Cu) { return; }
    }
    ctx->pc = 0x137E4Cu;
label_137e4c:
    // 0x137e4c: 0xae60bbc4  sw          $zero, -0x443C($s3)
    ctx->pc = 0x137e4cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294949828), GPR_U32(ctx, 0));
label_137e50:
    // 0x137e50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137e50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137e54: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x137e54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137e58: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x137e58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137e5c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x137e5cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x137e60: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x137e60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x137e64: 0x3e00008  jr          $ra
    ctx->pc = 0x137E64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137E64u;
            // 0x137e68: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137DACu: goto label_137dac;
            case 0x137DDCu: goto label_137ddc;
            case 0x137DE4u: goto label_137de4;
            case 0x137DF8u: goto label_137df8;
            case 0x137DFCu: goto label_137dfc;
            case 0x137E30u: goto label_137e30;
            case 0x137E38u: goto label_137e38;
            case 0x137E4Cu: goto label_137e4c;
            case 0x137E50u: goto label_137e50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137E6Cu;
    // 0x137e6c: 0x0  nop
    ctx->pc = 0x137e6cu;
    // NOP
    // 0x137e70: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137e70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137e74: 0x3e00008  jr          $ra
    ctx->pc = 0x137E74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137E74u;
            // 0x137e78: 0x8062bb89  lb          $v0, -0x4477($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 4294949769)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137DACu: goto label_137dac;
            case 0x137DDCu: goto label_137ddc;
            case 0x137DE4u: goto label_137de4;
            case 0x137DF8u: goto label_137df8;
            case 0x137DFCu: goto label_137dfc;
            case 0x137E30u: goto label_137e30;
            case 0x137E38u: goto label_137e38;
            case 0x137E4Cu: goto label_137e4c;
            case 0x137E50u: goto label_137e50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137E7Cu;
    // 0x137e7c: 0x0  nop
    ctx->pc = 0x137e7cu;
    // NOP
    // 0x137e80: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x137e80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137e84: 0x3e00008  jr          $ra
    ctx->pc = 0x137E84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137E84u;
            // 0x137e88: 0x8c62bbbc  lw          $v0, -0x4444($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294949820)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137DACu: goto label_137dac;
            case 0x137DDCu: goto label_137ddc;
            case 0x137DE4u: goto label_137de4;
            case 0x137DF8u: goto label_137df8;
            case 0x137DFCu: goto label_137dfc;
            case 0x137E30u: goto label_137e30;
            case 0x137E38u: goto label_137e38;
            case 0x137E4Cu: goto label_137e4c;
            case 0x137E50u: goto label_137e50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137E8Cu;
    // 0x137e8c: 0x0  nop
    ctx->pc = 0x137e8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

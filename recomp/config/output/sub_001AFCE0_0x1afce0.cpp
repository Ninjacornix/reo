#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFCE0
// Address: 0x1afce0 - 0x1b02d0
void sub_001AFCE0_0x1afce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFCE0_0x1afce0");
#endif

    switch (ctx->pc) {
        case 0x1afcf0u: goto label_1afcf0;
        case 0x1afd08u: goto label_1afd08;
        case 0x1afd3cu: goto label_1afd3c;
        case 0x1afd70u: goto label_1afd70;
        case 0x1afdb4u: goto label_1afdb4;
        case 0x1afdc4u: goto label_1afdc4;
        case 0x1afdfcu: goto label_1afdfc;
        case 0x1afe3cu: goto label_1afe3c;
        case 0x1afe54u: goto label_1afe54;
        case 0x1afe80u: goto label_1afe80;
        case 0x1afeb8u: goto label_1afeb8;
        case 0x1afec8u: goto label_1afec8;
        case 0x1afef4u: goto label_1afef4;
        case 0x1aff2cu: goto label_1aff2c;
        case 0x1aff3cu: goto label_1aff3c;
        case 0x1aff70u: goto label_1aff70;
        case 0x1aff84u: goto label_1aff84;
        case 0x1affa4u: goto label_1affa4;
        case 0x1affe0u: goto label_1affe0;
        case 0x1afff4u: goto label_1afff4;
        case 0x1b0024u: goto label_1b0024;
        case 0x1b0060u: goto label_1b0060;
        case 0x1b0074u: goto label_1b0074;
        case 0x1b00a4u: goto label_1b00a4;
        case 0x1b00e0u: goto label_1b00e0;
        case 0x1b00f4u: goto label_1b00f4;
        case 0x1b0124u: goto label_1b0124;
        case 0x1b015cu: goto label_1b015c;
        case 0x1b016cu: goto label_1b016c;
        case 0x1b01a4u: goto label_1b01a4;
        case 0x1b01dcu: goto label_1b01dc;
        case 0x1b01ecu: goto label_1b01ec;
        case 0x1b0220u: goto label_1b0220;
        case 0x1b0234u: goto label_1b0234;
        case 0x1b0254u: goto label_1b0254;
        case 0x1b0290u: goto label_1b0290;
        case 0x1b02a0u: goto label_1b02a0;
        default: break;
    }

    ctx->pc = 0x1afce0u;

    // 0x1afce0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afce0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afce4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afce8: 0xc06c1a8  jal         func_1B06A0
    ctx->pc = 0x1AFCE8u;
    SET_GPR_U32(ctx, 31, 0x1AFCF0u);
    ctx->pc = 0x1B06A0u;
    if (runtime->hasFunction(0x1B06A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B06A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFCF0u; }
        if (ctx->pc != 0x1AFCF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B06A0_0x1b06a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFCF0u; }
        if (ctx->pc != 0x1AFCF0u) { return; }
    }
    ctx->pc = 0x1AFCF0u;
label_1afcf0:
    // 0x1afcf0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1afcf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1afcf4: 0x902343fa  lbu         $v1, 0x43FA($at)
    ctx->pc = 0x1afcf4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17402)));
    // 0x1afcf8: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFCF8u;
    {
        const bool branch_taken_0x1afcf8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afcf8) {
            ctx->pc = 0x1AFD3Cu;
            goto label_1afd3c;
        }
    }
    ctx->pc = 0x1AFD00u;
    // 0x1afd00: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFD00u;
    SET_GPR_U32(ctx, 31, 0x1AFD08u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFD08u; }
        if (ctx->pc != 0x1AFD08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFD08u; }
        if (ctx->pc != 0x1AFD08u) { return; }
    }
    ctx->pc = 0x1AFD08u;
label_1afd08:
    // 0x1afd08: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afd08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afd0c: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1AFD0Cu;
    {
        const bool branch_taken_0x1afd0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFD10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD0Cu;
            // 0x1afd10: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd0c) {
            ctx->pc = 0x1AFD3Cu;
            goto label_1afd3c;
        }
    }
    ctx->pc = 0x1AFD14u;
    // 0x1afd14: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFD14u;
    {
        const bool branch_taken_0x1afd14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afd14) {
            ctx->pc = 0x1AFD3Cu;
            goto label_1afd3c;
        }
    }
    ctx->pc = 0x1AFD1Cu;
    // 0x1afd1c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AFD1Cu;
    {
        const bool branch_taken_0x1afd1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD1Cu;
            // 0x1afd20: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd1c) {
            ctx->pc = 0x1AFD3Cu;
            goto label_1afd3c;
        }
    }
    ctx->pc = 0x1AFD24u;
    // 0x1afd24: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFD24u;
    {
        const bool branch_taken_0x1afd24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afd24) {
            ctx->pc = 0x1AFD34u;
            goto label_1afd34;
        }
    }
    ctx->pc = 0x1AFD2Cu;
    // 0x1afd2c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AFD2Cu;
    {
        const bool branch_taken_0x1afd2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFD30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD2Cu;
            // 0x1afd30: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd2c) {
            ctx->pc = 0x1AFD40u;
            goto label_1afd40;
        }
    }
    ctx->pc = 0x1AFD34u;
label_1afd34:
    // 0x1afd34: 0xc204884  jal         func_812210
    ctx->pc = 0x1AFD34u;
    SET_GPR_U32(ctx, 31, 0x1AFD3Cu);
    ctx->pc = 0x812210u;
    {
        auto targetFn = runtime->lookupFunction(0x812210u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFD3Cu; }
        if (ctx->pc != 0x1AFD3Cu) { return; }
    }
    ctx->pc = 0x1AFD3Cu;
label_1afd3c:
    // 0x1afd3c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afd3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afd40:
    // 0x1afd40: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFD40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFD44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD40u;
            // 0x1afd44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFD48u;
    // 0x1afd48: 0x0  nop
    ctx->pc = 0x1afd48u;
    // NOP
    // 0x1afd4c: 0x0  nop
    ctx->pc = 0x1afd4cu;
    // NOP
    // 0x1afd50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afd50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afd54: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1afd54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1afd58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afd58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afd5c: 0x902343fa  lbu         $v1, 0x43FA($at)
    ctx->pc = 0x1afd5cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17402)));
    // 0x1afd60: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AFD60u;
    {
        const bool branch_taken_0x1afd60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afd60) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFD68u;
    // 0x1afd68: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFD68u;
    SET_GPR_U32(ctx, 31, 0x1AFD70u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFD70u; }
        if (ctx->pc != 0x1AFD70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFD70u; }
        if (ctx->pc != 0x1AFD70u) { return; }
    }
    ctx->pc = 0x1AFD70u;
label_1afd70:
    // 0x1afd70: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afd70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afd74: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1AFD74u;
    {
        const bool branch_taken_0x1afd74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD74u;
            // 0x1afd78: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd74) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFD7Cu;
    // 0x1afd7c: 0x10430011  beq         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AFD7Cu;
    {
        const bool branch_taken_0x1afd7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afd7c) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFD84u;
    // 0x1afd84: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afd84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afd88: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1AFD88u;
    {
        const bool branch_taken_0x1afd88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afd88) {
            ctx->pc = 0x1AFDBCu;
            goto label_1afdbc;
        }
    }
    ctx->pc = 0x1AFD90u;
    // 0x1afd90: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFD90u;
    {
        const bool branch_taken_0x1afd90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD90u;
            // 0x1afd94: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd90) {
            ctx->pc = 0x1AFDA0u;
            goto label_1afda0;
        }
    }
    ctx->pc = 0x1AFD98u;
    // 0x1afd98: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1AFD98u;
    {
        const bool branch_taken_0x1afd98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFD98u;
            // 0x1afd9c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afd98) {
            ctx->pc = 0x1AFDC8u;
            goto label_1afdc8;
        }
    }
    ctx->pc = 0x1AFDA0u;
label_1afda0:
    // 0x1afda0: 0x9023ae94  lbu         $v1, -0x516C($at)
    ctx->pc = 0x1afda0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946452)));
    // 0x1afda4: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AFDA4u;
    {
        const bool branch_taken_0x1afda4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1afda4) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFDACu;
    // 0x1afdac: 0xc204210  jal         func_810840
    ctx->pc = 0x1AFDACu;
    SET_GPR_U32(ctx, 31, 0x1AFDB4u);
    ctx->pc = 0x810840u;
    {
        auto targetFn = runtime->lookupFunction(0x810840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDB4u; }
        if (ctx->pc != 0x1AFDB4u) { return; }
    }
    ctx->pc = 0x1AFDB4u;
label_1afdb4:
    // 0x1afdb4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFDB4u;
    {
        const bool branch_taken_0x1afdb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afdb4) {
            ctx->pc = 0x1AFDC4u;
            goto label_1afdc4;
        }
    }
    ctx->pc = 0x1AFDBCu;
label_1afdbc:
    // 0x1afdbc: 0xc204a48  jal         func_812920
    ctx->pc = 0x1AFDBCu;
    SET_GPR_U32(ctx, 31, 0x1AFDC4u);
    ctx->pc = 0x812920u;
    {
        auto targetFn = runtime->lookupFunction(0x812920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDC4u; }
        if (ctx->pc != 0x1AFDC4u) { return; }
    }
    ctx->pc = 0x1AFDC4u;
label_1afdc4:
    // 0x1afdc4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afdc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afdc8:
    // 0x1afdc8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFDC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFDCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFDC8u;
            // 0x1afdcc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFDD0u;
    // 0x1afdd0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1afdd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1afdd4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1afdd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1afdd8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1afdd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1afddc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1afddcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1afde0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1afde0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afde4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1afde4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1afde8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1afde8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afdec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1afdecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1afdf0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1afdf0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afdf4: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFDF4u;
    SET_GPR_U32(ctx, 31, 0x1AFDFCu);
    ctx->pc = 0x1AFDF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFDF4u;
            // 0x1afdf8: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDFCu; }
        if (ctx->pc != 0x1AFDFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFDFCu; }
        if (ctx->pc != 0x1AFDFCu) { return; }
    }
    ctx->pc = 0x1AFDFCu;
label_1afdfc:
    // 0x1afdfc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afdfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afe00: 0x10430014  beq         $v0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1AFE00u;
    {
        const bool branch_taken_0x1afe00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFE04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE00u;
            // 0x1afe04: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe00) {
            ctx->pc = 0x1AFE54u;
            goto label_1afe54;
        }
    }
    ctx->pc = 0x1AFE08u;
    // 0x1afe08: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFE08u;
    {
        const bool branch_taken_0x1afe08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afe08) {
            ctx->pc = 0x1AFE54u;
            goto label_1afe54;
        }
    }
    ctx->pc = 0x1AFE10u;
    // 0x1afe10: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afe10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afe14: 0x1043000b  beq         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1AFE14u;
    {
        const bool branch_taken_0x1afe14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE14u;
            // 0x1afe18: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe14) {
            ctx->pc = 0x1AFE44u;
            goto label_1afe44;
        }
    }
    ctx->pc = 0x1AFE1Cu;
    // 0x1afe1c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFE1Cu;
    {
        const bool branch_taken_0x1afe1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE1Cu;
            // 0x1afe20: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe1c) {
            ctx->pc = 0x1AFE2Cu;
            goto label_1afe2c;
        }
    }
    ctx->pc = 0x1AFE24u;
    // 0x1afe24: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1AFE24u;
    {
        const bool branch_taken_0x1afe24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE24u;
            // 0x1afe28: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe24) {
            ctx->pc = 0x1AFE58u;
            goto label_1afe58;
        }
    }
    ctx->pc = 0x1AFE2Cu;
label_1afe2c:
    // 0x1afe2c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1afe2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe30: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1afe30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe34: 0xc204464  jal         func_811190
    ctx->pc = 0x1AFE34u;
    SET_GPR_U32(ctx, 31, 0x1AFE3Cu);
    ctx->pc = 0x1AFE38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE34u;
            // 0x1afe38: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811190u;
    {
        auto targetFn = runtime->lookupFunction(0x811190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE3Cu; }
        if (ctx->pc != 0x1AFE3Cu) { return; }
    }
    ctx->pc = 0x1AFE3Cu;
label_1afe3c:
    // 0x1afe3c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1AFE3Cu;
    {
        const bool branch_taken_0x1afe3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afe3c) {
            ctx->pc = 0x1AFE54u;
            goto label_1afe54;
        }
    }
    ctx->pc = 0x1AFE44u;
label_1afe44:
    // 0x1afe44: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1afe44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe48: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1afe48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afe4c: 0xc20421c  jal         func_810870
    ctx->pc = 0x1AFE4Cu;
    SET_GPR_U32(ctx, 31, 0x1AFE54u);
    ctx->pc = 0x1AFE50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE4Cu;
            // 0x1afe50: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x810870u;
    {
        auto targetFn = runtime->lookupFunction(0x810870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE54u; }
        if (ctx->pc != 0x1AFE54u) { return; }
    }
    ctx->pc = 0x1AFE54u;
label_1afe54:
    // 0x1afe54: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1afe54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1afe58:
    // 0x1afe58: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1afe58u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1afe5c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1afe5cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1afe60: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1afe60u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1afe64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1afe64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1afe68: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFE68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFE6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE68u;
            // 0x1afe6c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFE70u;
    // 0x1afe70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afe70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afe74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afe74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afe78: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFE78u;
    SET_GPR_U32(ctx, 31, 0x1AFE80u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE80u; }
        if (ctx->pc != 0x1AFE80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE80u; }
        if (ctx->pc != 0x1AFE80u) { return; }
    }
    ctx->pc = 0x1AFE80u;
label_1afe80:
    // 0x1afe80: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afe80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afe84: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFE84u;
    {
        const bool branch_taken_0x1afe84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFE88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE84u;
            // 0x1afe88: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe84) {
            ctx->pc = 0x1AFED0u;
            goto label_1afed0;
        }
    }
    ctx->pc = 0x1AFE8Cu;
    // 0x1afe8c: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFE8Cu;
    {
        const bool branch_taken_0x1afe8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afe8c) {
            ctx->pc = 0x1AFED0u;
            goto label_1afed0;
        }
    }
    ctx->pc = 0x1AFE94u;
    // 0x1afe94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afe94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afe98: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFE98u;
    {
        const bool branch_taken_0x1afe98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afe98) {
            ctx->pc = 0x1AFEC0u;
            goto label_1afec0;
        }
    }
    ctx->pc = 0x1AFEA0u;
    // 0x1afea0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFEA0u;
    {
        const bool branch_taken_0x1afea0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afea0) {
            ctx->pc = 0x1AFEB0u;
            goto label_1afeb0;
        }
    }
    ctx->pc = 0x1AFEA8u;
    // 0x1afea8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AFEA8u;
    {
        const bool branch_taken_0x1afea8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFEACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEA8u;
            // 0x1afeac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afea8) {
            ctx->pc = 0x1AFED4u;
            goto label_1afed4;
        }
    }
    ctx->pc = 0x1AFEB0u;
label_1afeb0:
    // 0x1afeb0: 0xc2045dc  jal         func_811770
    ctx->pc = 0x1AFEB0u;
    SET_GPR_U32(ctx, 31, 0x1AFEB8u);
    ctx->pc = 0x811770u;
    {
        auto targetFn = runtime->lookupFunction(0x811770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEB8u; }
        if (ctx->pc != 0x1AFEB8u) { return; }
    }
    ctx->pc = 0x1AFEB8u;
label_1afeb8:
    // 0x1afeb8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1AFEB8u;
    {
        const bool branch_taken_0x1afeb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFEBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEB8u;
            // 0x1afebc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afeb8) {
            ctx->pc = 0x1AFED8u;
            goto label_1afed8;
        }
    }
    ctx->pc = 0x1AFEC0u;
label_1afec0:
    // 0x1afec0: 0xc2043cc  jal         func_810F30
    ctx->pc = 0x1AFEC0u;
    SET_GPR_U32(ctx, 31, 0x1AFEC8u);
    ctx->pc = 0x810F30u;
    {
        auto targetFn = runtime->lookupFunction(0x810F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEC8u; }
        if (ctx->pc != 0x1AFEC8u) { return; }
    }
    ctx->pc = 0x1AFEC8u;
label_1afec8:
    // 0x1afec8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1AFEC8u;
    {
        const bool branch_taken_0x1afec8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afec8) {
            ctx->pc = 0x1AFED4u;
            goto label_1afed4;
        }
    }
    ctx->pc = 0x1AFED0u;
label_1afed0:
    // 0x1afed0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1afed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1afed4:
    // 0x1afed4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afed8:
    // 0x1afed8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFED8u;
            // 0x1afedc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFEE0u;
    // 0x1afee0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1afee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1afee4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1afee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1afee8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1afee8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1afeec: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFEECu;
    SET_GPR_U32(ctx, 31, 0x1AFEF4u);
    ctx->pc = 0x1AFEF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEECu;
            // 0x1afef0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEF4u; }
        if (ctx->pc != 0x1AFEF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEF4u; }
        if (ctx->pc != 0x1AFEF4u) { return; }
    }
    ctx->pc = 0x1AFEF4u;
label_1afef4:
    // 0x1afef4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afef4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afef8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFEF8u;
    {
        const bool branch_taken_0x1afef8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFEFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEF8u;
            // 0x1afefc: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afef8) {
            ctx->pc = 0x1AFF44u;
            goto label_1aff44;
        }
    }
    ctx->pc = 0x1AFF00u;
    // 0x1aff00: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFF00u;
    {
        const bool branch_taken_0x1aff00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1aff00) {
            ctx->pc = 0x1AFF44u;
            goto label_1aff44;
        }
    }
    ctx->pc = 0x1AFF08u;
    // 0x1aff08: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1aff08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aff0c: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFF0Cu;
    {
        const bool branch_taken_0x1aff0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFF10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF0Cu;
            // 0x1aff10: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff0c) {
            ctx->pc = 0x1AFF34u;
            goto label_1aff34;
        }
    }
    ctx->pc = 0x1AFF14u;
    // 0x1aff14: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFF14u;
    {
        const bool branch_taken_0x1aff14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF14u;
            // 0x1aff18: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff14) {
            ctx->pc = 0x1AFF24u;
            goto label_1aff24;
        }
    }
    ctx->pc = 0x1AFF1Cu;
    // 0x1aff1c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AFF1Cu;
    {
        const bool branch_taken_0x1aff1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF1Cu;
            // 0x1aff20: 0x2001026  xor         $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff1c) {
            ctx->pc = 0x1AFF48u;
            goto label_1aff48;
        }
    }
    ctx->pc = 0x1AFF24u;
label_1aff24:
    // 0x1aff24: 0xc204748  jal         func_811D20
    ctx->pc = 0x1AFF24u;
    SET_GPR_U32(ctx, 31, 0x1AFF2Cu);
    ctx->pc = 0x811D20u;
    {
        auto targetFn = runtime->lookupFunction(0x811D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF2Cu; }
        if (ctx->pc != 0x1AFF2Cu) { return; }
    }
    ctx->pc = 0x1AFF2Cu;
label_1aff2c:
    // 0x1aff2c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AFF2Cu;
    {
        const bool branch_taken_0x1aff2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFF30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF2Cu;
            // 0x1aff30: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aff2c) {
            ctx->pc = 0x1AFF50u;
            goto label_1aff50;
        }
    }
    ctx->pc = 0x1AFF34u;
label_1aff34:
    // 0x1aff34: 0xc204574  jal         func_8115D0
    ctx->pc = 0x1AFF34u;
    SET_GPR_U32(ctx, 31, 0x1AFF3Cu);
    ctx->pc = 0x8115D0u;
    {
        auto targetFn = runtime->lookupFunction(0x8115D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF3Cu; }
        if (ctx->pc != 0x1AFF3Cu) { return; }
    }
    ctx->pc = 0x1AFF3Cu;
label_1aff3c:
    // 0x1aff3c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFF3Cu;
    {
        const bool branch_taken_0x1aff3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aff3c) {
            ctx->pc = 0x1AFF4Cu;
            goto label_1aff4c;
        }
    }
    ctx->pc = 0x1AFF44u;
label_1aff44:
    // 0x1aff44: 0x2001026  xor         $v0, $s0, $zero
    ctx->pc = 0x1aff44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 0));
label_1aff48:
    // 0x1aff48: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1aff48u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_1aff4c:
    // 0x1aff4c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1aff4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1aff50:
    // 0x1aff50: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aff50u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aff54: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFF54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFF58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF54u;
            // 0x1aff58: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFF5Cu;
    // 0x1aff5c: 0x0  nop
    ctx->pc = 0x1aff5cu;
    // NOP
    // 0x1aff60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1aff60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1aff64: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1aff64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1aff68: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFF68u;
    SET_GPR_U32(ctx, 31, 0x1AFF70u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF70u; }
        if (ctx->pc != 0x1AFF70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF70u; }
        if (ctx->pc != 0x1AFF70u) { return; }
    }
    ctx->pc = 0x1AFF70u;
label_1aff70:
    // 0x1aff70: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1aff70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aff74: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFF74u;
    {
        const bool branch_taken_0x1aff74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1aff74) {
            ctx->pc = 0x1AFF84u;
            goto label_1aff84;
        }
    }
    ctx->pc = 0x1AFF7Cu;
    // 0x1aff7c: 0xc2043d0  jal         func_810F40
    ctx->pc = 0x1AFF7Cu;
    SET_GPR_U32(ctx, 31, 0x1AFF84u);
    ctx->pc = 0x810F40u;
    {
        auto targetFn = runtime->lookupFunction(0x810F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFF84u; }
        if (ctx->pc != 0x1AFF84u) { return; }
    }
    ctx->pc = 0x1AFF84u;
label_1aff84:
    // 0x1aff84: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1aff84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aff88: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFF88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFF8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF88u;
            // 0x1aff8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFF90u;
    // 0x1aff90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1aff90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1aff94: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1aff94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1aff98: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aff98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aff9c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFF9Cu;
    SET_GPR_U32(ctx, 31, 0x1AFFA4u);
    ctx->pc = 0x1AFFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFF9Cu;
            // 0x1affa0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFA4u; }
        if (ctx->pc != 0x1AFFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFA4u; }
        if (ctx->pc != 0x1AFFA4u) { return; }
    }
    ctx->pc = 0x1AFFA4u;
label_1affa4:
    // 0x1affa4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1affa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1affa8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFFA8u;
    {
        const bool branch_taken_0x1affa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFFACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFA8u;
            // 0x1affac: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affa8) {
            ctx->pc = 0x1AFFF4u;
            goto label_1afff4;
        }
    }
    ctx->pc = 0x1AFFB0u;
    // 0x1affb0: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFFB0u;
    {
        const bool branch_taken_0x1affb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1affb0) {
            ctx->pc = 0x1AFFF4u;
            goto label_1afff4;
        }
    }
    ctx->pc = 0x1AFFB8u;
    // 0x1affb8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1affb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1affbc: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1AFFBCu;
    {
        const bool branch_taken_0x1affbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFFC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFBCu;
            // 0x1affc0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affbc) {
            ctx->pc = 0x1AFFE8u;
            goto label_1affe8;
        }
    }
    ctx->pc = 0x1AFFC4u;
    // 0x1affc4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFFC4u;
    {
        const bool branch_taken_0x1affc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFFC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFC4u;
            // 0x1affc8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affc4) {
            ctx->pc = 0x1AFFD4u;
            goto label_1affd4;
        }
    }
    ctx->pc = 0x1AFFCCu;
    // 0x1affcc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AFFCCu;
    {
        const bool branch_taken_0x1affcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFFD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFCCu;
            // 0x1affd0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1affcc) {
            ctx->pc = 0x1AFFF8u;
            goto label_1afff8;
        }
    }
    ctx->pc = 0x1AFFD4u;
label_1affd4:
    // 0x1affd4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1affd4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1affd8: 0xc20465c  jal         func_811970
    ctx->pc = 0x1AFFD8u;
    SET_GPR_U32(ctx, 31, 0x1AFFE0u);
    ctx->pc = 0x1AFFDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFD8u;
            // 0x1affdc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811970u;
    {
        auto targetFn = runtime->lookupFunction(0x811970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFE0u; }
        if (ctx->pc != 0x1AFFE0u) { return; }
    }
    ctx->pc = 0x1AFFE0u;
label_1affe0:
    // 0x1affe0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AFFE0u;
    {
        const bool branch_taken_0x1affe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1affe0) {
            ctx->pc = 0x1AFFF4u;
            goto label_1afff4;
        }
    }
    ctx->pc = 0x1AFFE8u;
label_1affe8:
    // 0x1affe8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1affe8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1affec: 0xc204450  jal         func_811140
    ctx->pc = 0x1AFFECu;
    SET_GPR_U32(ctx, 31, 0x1AFFF4u);
    ctx->pc = 0x1AFFF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFECu;
            // 0x1afff0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811140u;
    {
        auto targetFn = runtime->lookupFunction(0x811140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFFF4u; }
        if (ctx->pc != 0x1AFFF4u) { return; }
    }
    ctx->pc = 0x1AFFF4u;
label_1afff4:
    // 0x1afff4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1afff4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1afff8:
    // 0x1afff8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1afff8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1afffc: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFFFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFFFCu;
            // 0x1b0000: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0004u;
    // 0x1b0004: 0x0  nop
    ctx->pc = 0x1b0004u;
    // NOP
    // 0x1b0008: 0x0  nop
    ctx->pc = 0x1b0008u;
    // NOP
    // 0x1b000c: 0x0  nop
    ctx->pc = 0x1b000cu;
    // NOP
    // 0x1b0010: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0014: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0018: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0018u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b001c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B001Cu;
    SET_GPR_U32(ctx, 31, 0x1B0024u);
    ctx->pc = 0x1B0020u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B001Cu;
            // 0x1b0020: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0024u; }
        if (ctx->pc != 0x1B0024u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0024u; }
        if (ctx->pc != 0x1B0024u) { return; }
    }
    ctx->pc = 0x1B0024u;
label_1b0024:
    // 0x1b0024: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b0024u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b0028: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B0028u;
    {
        const bool branch_taken_0x1b0028 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B002Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0028u;
            // 0x1b002c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0028) {
            ctx->pc = 0x1B0074u;
            goto label_1b0074;
        }
    }
    ctx->pc = 0x1B0030u;
    // 0x1b0030: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B0030u;
    {
        const bool branch_taken_0x1b0030 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0030) {
            ctx->pc = 0x1B0074u;
            goto label_1b0074;
        }
    }
    ctx->pc = 0x1B0038u;
    // 0x1b0038: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0038u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b003c: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B003Cu;
    {
        const bool branch_taken_0x1b003c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B0040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B003Cu;
            // 0x1b0040: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b003c) {
            ctx->pc = 0x1B0068u;
            goto label_1b0068;
        }
    }
    ctx->pc = 0x1B0044u;
    // 0x1b0044: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0044u;
    {
        const bool branch_taken_0x1b0044 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0044u;
            // 0x1b0048: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0044) {
            ctx->pc = 0x1B0054u;
            goto label_1b0054;
        }
    }
    ctx->pc = 0x1B004Cu;
    // 0x1b004c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B004Cu;
    {
        const bool branch_taken_0x1b004c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B004Cu;
            // 0x1b0050: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b004c) {
            ctx->pc = 0x1B0078u;
            goto label_1b0078;
        }
    }
    ctx->pc = 0x1B0054u;
label_1b0054:
    // 0x1b0054: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b0054u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0058: 0xc2046cc  jal         func_811B30
    ctx->pc = 0x1B0058u;
    SET_GPR_U32(ctx, 31, 0x1B0060u);
    ctx->pc = 0x1B005Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0058u;
            // 0x1b005c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811B30u;
    {
        auto targetFn = runtime->lookupFunction(0x811B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0060u; }
        if (ctx->pc != 0x1B0060u) { return; }
    }
    ctx->pc = 0x1B0060u;
label_1b0060:
    // 0x1b0060: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B0060u;
    {
        const bool branch_taken_0x1b0060 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b0060) {
            ctx->pc = 0x1B0074u;
            goto label_1b0074;
        }
    }
    ctx->pc = 0x1B0068u;
label_1b0068:
    // 0x1b0068: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b0068u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b006c: 0xc2044c0  jal         func_811300
    ctx->pc = 0x1B006Cu;
    SET_GPR_U32(ctx, 31, 0x1B0074u);
    ctx->pc = 0x1B0070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B006Cu;
            // 0x1b0070: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811300u;
    {
        auto targetFn = runtime->lookupFunction(0x811300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0074u; }
        if (ctx->pc != 0x1B0074u) { return; }
    }
    ctx->pc = 0x1B0074u;
label_1b0074:
    // 0x1b0074: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b0074u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b0078:
    // 0x1b0078: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0078u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b007c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B007Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B007Cu;
            // 0x1b0080: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0084u;
    // 0x1b0084: 0x0  nop
    ctx->pc = 0x1b0084u;
    // NOP
    // 0x1b0088: 0x0  nop
    ctx->pc = 0x1b0088u;
    // NOP
    // 0x1b008c: 0x0  nop
    ctx->pc = 0x1b008cu;
    // NOP
    // 0x1b0090: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0094: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0098: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0098u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b009c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B009Cu;
    SET_GPR_U32(ctx, 31, 0x1B00A4u);
    ctx->pc = 0x1B00A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B009Cu;
            // 0x1b00a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00A4u; }
        if (ctx->pc != 0x1B00A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00A4u; }
        if (ctx->pc != 0x1B00A4u) { return; }
    }
    ctx->pc = 0x1B00A4u;
label_1b00a4:
    // 0x1b00a4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b00a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b00a8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B00A8u;
    {
        const bool branch_taken_0x1b00a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B00ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00A8u;
            // 0x1b00ac: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00a8) {
            ctx->pc = 0x1B00F4u;
            goto label_1b00f4;
        }
    }
    ctx->pc = 0x1B00B0u;
    // 0x1b00b0: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B00B0u;
    {
        const bool branch_taken_0x1b00b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b00b0) {
            ctx->pc = 0x1B00F4u;
            goto label_1b00f4;
        }
    }
    ctx->pc = 0x1B00B8u;
    // 0x1b00b8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b00b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b00bc: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1B00BCu;
    {
        const bool branch_taken_0x1b00bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B00C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00BCu;
            // 0x1b00c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00bc) {
            ctx->pc = 0x1B00E8u;
            goto label_1b00e8;
        }
    }
    ctx->pc = 0x1B00C4u;
    // 0x1b00c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B00C4u;
    {
        const bool branch_taken_0x1b00c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B00C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00C4u;
            // 0x1b00c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00c4) {
            ctx->pc = 0x1B00D4u;
            goto label_1b00d4;
        }
    }
    ctx->pc = 0x1B00CCu;
    // 0x1b00cc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B00CCu;
    {
        const bool branch_taken_0x1b00cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B00D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00CCu;
            // 0x1b00d0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b00cc) {
            ctx->pc = 0x1B00F8u;
            goto label_1b00f8;
        }
    }
    ctx->pc = 0x1B00D4u;
label_1b00d4:
    // 0x1b00d4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b00d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b00d8: 0xc2046cc  jal         func_811B30
    ctx->pc = 0x1B00D8u;
    SET_GPR_U32(ctx, 31, 0x1B00E0u);
    ctx->pc = 0x1B00DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00D8u;
            // 0x1b00dc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811B30u;
    {
        auto targetFn = runtime->lookupFunction(0x811B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00E0u; }
        if (ctx->pc != 0x1B00E0u) { return; }
    }
    ctx->pc = 0x1B00E0u;
label_1b00e0:
    // 0x1b00e0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B00E0u;
    {
        const bool branch_taken_0x1b00e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b00e0) {
            ctx->pc = 0x1B00F4u;
            goto label_1b00f4;
        }
    }
    ctx->pc = 0x1B00E8u;
label_1b00e8:
    // 0x1b00e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b00e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b00ec: 0xc204504  jal         func_811410
    ctx->pc = 0x1B00ECu;
    SET_GPR_U32(ctx, 31, 0x1B00F4u);
    ctx->pc = 0x1B00F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00ECu;
            // 0x1b00f0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x811410u;
    {
        auto targetFn = runtime->lookupFunction(0x811410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B00F4u; }
        if (ctx->pc != 0x1B00F4u) { return; }
    }
    ctx->pc = 0x1B00F4u;
label_1b00f4:
    // 0x1b00f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b00f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b00f8:
    // 0x1b00f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b00f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b00fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B00FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B00FCu;
            // 0x1b0100: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0104u;
    // 0x1b0104: 0x0  nop
    ctx->pc = 0x1b0104u;
    // NOP
    // 0x1b0108: 0x0  nop
    ctx->pc = 0x1b0108u;
    // NOP
    // 0x1b010c: 0x0  nop
    ctx->pc = 0x1b010cu;
    // NOP
    // 0x1b0110: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0114: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0114u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0118: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0118u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b011c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B011Cu;
    SET_GPR_U32(ctx, 31, 0x1B0124u);
    ctx->pc = 0x1B0120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B011Cu;
            // 0x1b0120: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0124u; }
        if (ctx->pc != 0x1B0124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0124u; }
        if (ctx->pc != 0x1B0124u) { return; }
    }
    ctx->pc = 0x1B0124u;
label_1b0124:
    // 0x1b0124: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b0124u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b0128: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B0128u;
    {
        const bool branch_taken_0x1b0128 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B012Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0128u;
            // 0x1b012c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0128) {
            ctx->pc = 0x1B0174u;
            goto label_1b0174;
        }
    }
    ctx->pc = 0x1B0130u;
    // 0x1b0130: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B0130u;
    {
        const bool branch_taken_0x1b0130 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0130) {
            ctx->pc = 0x1B0174u;
            goto label_1b0174;
        }
    }
    ctx->pc = 0x1B0138u;
    // 0x1b0138: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0138u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b013c: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B013Cu;
    {
        const bool branch_taken_0x1b013c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B0140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B013Cu;
            // 0x1b0140: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b013c) {
            ctx->pc = 0x1B0164u;
            goto label_1b0164;
        }
    }
    ctx->pc = 0x1B0144u;
    // 0x1b0144: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0144u;
    {
        const bool branch_taken_0x1b0144 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0144u;
            // 0x1b0148: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0144) {
            ctx->pc = 0x1B0154u;
            goto label_1b0154;
        }
    }
    ctx->pc = 0x1B014Cu;
    // 0x1b014c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B014Cu;
    {
        const bool branch_taken_0x1b014c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B014Cu;
            // 0x1b0150: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b014c) {
            ctx->pc = 0x1B0178u;
            goto label_1b0178;
        }
    }
    ctx->pc = 0x1B0154u;
label_1b0154:
    // 0x1b0154: 0xc204714  jal         func_811C50
    ctx->pc = 0x1B0154u;
    SET_GPR_U32(ctx, 31, 0x1B015Cu);
    ctx->pc = 0x811C50u;
    {
        auto targetFn = runtime->lookupFunction(0x811C50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B015Cu; }
        if (ctx->pc != 0x1B015Cu) { return; }
    }
    ctx->pc = 0x1B015Cu;
label_1b015c:
    // 0x1b015c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B015Cu;
    {
        const bool branch_taken_0x1b015c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B015Cu;
            // 0x1b0160: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b015c) {
            ctx->pc = 0x1B017Cu;
            goto label_1b017c;
        }
    }
    ctx->pc = 0x1B0164u;
label_1b0164:
    // 0x1b0164: 0xc20452c  jal         func_8114B0
    ctx->pc = 0x1B0164u;
    SET_GPR_U32(ctx, 31, 0x1B016Cu);
    ctx->pc = 0x8114B0u;
    {
        auto targetFn = runtime->lookupFunction(0x8114B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B016Cu; }
        if (ctx->pc != 0x1B016Cu) { return; }
    }
    ctx->pc = 0x1B016Cu;
label_1b016c:
    // 0x1b016c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B016Cu;
    {
        const bool branch_taken_0x1b016c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b016c) {
            ctx->pc = 0x1B0178u;
            goto label_1b0178;
        }
    }
    ctx->pc = 0x1B0174u;
label_1b0174:
    // 0x1b0174: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b0174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b0178:
    // 0x1b0178: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b0178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b017c:
    // 0x1b017c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b017cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0180: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0180u;
            // 0x1b0184: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0188u;
    // 0x1b0188: 0x0  nop
    ctx->pc = 0x1b0188u;
    // NOP
    // 0x1b018c: 0x0  nop
    ctx->pc = 0x1b018cu;
    // NOP
    // 0x1b0190: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0190u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0194: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0194u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0198: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0198u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b019c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B019Cu;
    SET_GPR_U32(ctx, 31, 0x1B01A4u);
    ctx->pc = 0x1B01A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B019Cu;
            // 0x1b01a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01A4u; }
        if (ctx->pc != 0x1B01A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01A4u; }
        if (ctx->pc != 0x1B01A4u) { return; }
    }
    ctx->pc = 0x1B01A4u;
label_1b01a4:
    // 0x1b01a4: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b01a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b01a8: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B01A8u;
    {
        const bool branch_taken_0x1b01a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B01ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01A8u;
            // 0x1b01ac: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01a8) {
            ctx->pc = 0x1B01F4u;
            goto label_1b01f4;
        }
    }
    ctx->pc = 0x1B01B0u;
    // 0x1b01b0: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B01B0u;
    {
        const bool branch_taken_0x1b01b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b01b0) {
            ctx->pc = 0x1B01F4u;
            goto label_1b01f4;
        }
    }
    ctx->pc = 0x1B01B8u;
    // 0x1b01b8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b01b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b01bc: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B01BCu;
    {
        const bool branch_taken_0x1b01bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B01C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01BCu;
            // 0x1b01c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01bc) {
            ctx->pc = 0x1B01E4u;
            goto label_1b01e4;
        }
    }
    ctx->pc = 0x1B01C4u;
    // 0x1b01c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B01C4u;
    {
        const bool branch_taken_0x1b01c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B01C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01C4u;
            // 0x1b01c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01c4) {
            ctx->pc = 0x1B01D4u;
            goto label_1b01d4;
        }
    }
    ctx->pc = 0x1B01CCu;
    // 0x1b01cc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B01CCu;
    {
        const bool branch_taken_0x1b01cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B01D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01CCu;
            // 0x1b01d0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01cc) {
            ctx->pc = 0x1B01F8u;
            goto label_1b01f8;
        }
    }
    ctx->pc = 0x1B01D4u;
label_1b01d4:
    // 0x1b01d4: 0xc204728  jal         func_811CA0
    ctx->pc = 0x1B01D4u;
    SET_GPR_U32(ctx, 31, 0x1B01DCu);
    ctx->pc = 0x811CA0u;
    {
        auto targetFn = runtime->lookupFunction(0x811CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01DCu; }
        if (ctx->pc != 0x1B01DCu) { return; }
    }
    ctx->pc = 0x1B01DCu;
label_1b01dc:
    // 0x1b01dc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B01DCu;
    {
        const bool branch_taken_0x1b01dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B01E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B01DCu;
            // 0x1b01e0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b01dc) {
            ctx->pc = 0x1B01FCu;
            goto label_1b01fc;
        }
    }
    ctx->pc = 0x1B01E4u;
label_1b01e4:
    // 0x1b01e4: 0xc204554  jal         func_811550
    ctx->pc = 0x1B01E4u;
    SET_GPR_U32(ctx, 31, 0x1B01ECu);
    ctx->pc = 0x811550u;
    {
        auto targetFn = runtime->lookupFunction(0x811550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B01ECu; }
        if (ctx->pc != 0x1B01ECu) { return; }
    }
    ctx->pc = 0x1B01ECu;
label_1b01ec:
    // 0x1b01ec: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B01ECu;
    {
        const bool branch_taken_0x1b01ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b01ec) {
            ctx->pc = 0x1B01F8u;
            goto label_1b01f8;
        }
    }
    ctx->pc = 0x1B01F4u;
label_1b01f4:
    // 0x1b01f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b01f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b01f8:
    // 0x1b01f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b01f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b01fc:
    // 0x1b01fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b01fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0200: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0200u;
            // 0x1b0204: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0208u;
    // 0x1b0208: 0x0  nop
    ctx->pc = 0x1b0208u;
    // NOP
    // 0x1b020c: 0x0  nop
    ctx->pc = 0x1b020cu;
    // NOP
    // 0x1b0210: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0210u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0214: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b0218: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B0218u;
    SET_GPR_U32(ctx, 31, 0x1B0220u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0220u; }
        if (ctx->pc != 0x1B0220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0220u; }
        if (ctx->pc != 0x1B0220u) { return; }
    }
    ctx->pc = 0x1B0220u;
label_1b0220:
    // 0x1b0220: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b0220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0224: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0224u;
    {
        const bool branch_taken_0x1b0224 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b0224) {
            ctx->pc = 0x1B0234u;
            goto label_1b0234;
        }
    }
    ctx->pc = 0x1B022Cu;
    // 0x1b022c: 0xc204afc  jal         func_812BF0
    ctx->pc = 0x1B022Cu;
    SET_GPR_U32(ctx, 31, 0x1B0234u);
    ctx->pc = 0x812BF0u;
    {
        auto targetFn = runtime->lookupFunction(0x812BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0234u; }
        if (ctx->pc != 0x1B0234u) { return; }
    }
    ctx->pc = 0x1B0234u;
label_1b0234:
    // 0x1b0234: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b0234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0238: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B023Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0238u;
            // 0x1b023c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0240u;
    // 0x1b0240: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0244: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0248: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0248u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b024c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B024Cu;
    SET_GPR_U32(ctx, 31, 0x1B0254u);
    ctx->pc = 0x1B0250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B024Cu;
            // 0x1b0250: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0254u; }
        if (ctx->pc != 0x1B0254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0254u; }
        if (ctx->pc != 0x1B0254u) { return; }
    }
    ctx->pc = 0x1B0254u;
label_1b0254:
    // 0x1b0254: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b0254u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b0258: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B0258u;
    {
        const bool branch_taken_0x1b0258 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0258) {
            ctx->pc = 0x1B02A8u;
            goto label_1b02a8;
        }
    }
    ctx->pc = 0x1B0260u;
    // 0x1b0260: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b0260u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b0264: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B0264u;
    {
        const bool branch_taken_0x1b0264 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0264) {
            ctx->pc = 0x1B02A8u;
            goto label_1b02a8;
        }
    }
    ctx->pc = 0x1B026Cu;
    // 0x1b026c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b026cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0270: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B0270u;
    {
        const bool branch_taken_0x1b0270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B0274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0270u;
            // 0x1b0274: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0270) {
            ctx->pc = 0x1B0298u;
            goto label_1b0298;
        }
    }
    ctx->pc = 0x1B0278u;
    // 0x1b0278: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0278u;
    {
        const bool branch_taken_0x1b0278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B027Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0278u;
            // 0x1b027c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0278) {
            ctx->pc = 0x1B0288u;
            goto label_1b0288;
        }
    }
    ctx->pc = 0x1B0280u;
    // 0x1b0280: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B0280u;
    {
        const bool branch_taken_0x1b0280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b0280) {
            ctx->pc = 0x1B02A8u;
            goto label_1b02a8;
        }
    }
    ctx->pc = 0x1B0288u;
label_1b0288:
    // 0x1b0288: 0xc204750  jal         func_811D40
    ctx->pc = 0x1B0288u;
    SET_GPR_U32(ctx, 31, 0x1B0290u);
    ctx->pc = 0x811D40u;
    {
        auto targetFn = runtime->lookupFunction(0x811D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0290u; }
        if (ctx->pc != 0x1B0290u) { return; }
    }
    ctx->pc = 0x1B0290u;
label_1b0290:
    // 0x1b0290: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B0290u;
    {
        const bool branch_taken_0x1b0290 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0290u;
            // 0x1b0294: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0290) {
            ctx->pc = 0x1B02C0u;
            goto label_1b02c0;
        }
    }
    ctx->pc = 0x1B0298u;
label_1b0298:
    // 0x1b0298: 0xc20457c  jal         func_8115F0
    ctx->pc = 0x1B0298u;
    SET_GPR_U32(ctx, 31, 0x1B02A0u);
    ctx->pc = 0x8115F0u;
    {
        auto targetFn = runtime->lookupFunction(0x8115F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B02A0u; }
        if (ctx->pc != 0x1B02A0u) { return; }
    }
    ctx->pc = 0x1B02A0u;
label_1b02a0:
    // 0x1b02a0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B02A0u;
    {
        const bool branch_taken_0x1b02a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b02a0) {
            ctx->pc = 0x1B02BCu;
            goto label_1b02bc;
        }
    }
    ctx->pc = 0x1B02A8u;
label_1b02a8:
    // 0x1b02a8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b02a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b02ac: 0x942243dc  lhu         $v0, 0x43DC($at)
    ctx->pc = 0x1b02acu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b02b0: 0x501026  xor         $v0, $v0, $s0
    ctx->pc = 0x1b02b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 16));
    // 0x1b02b4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1b02b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1b02b8: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1b02b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
label_1b02bc:
    // 0x1b02bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b02bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b02c0:
    // 0x1b02c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b02c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b02c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B02C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B02C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B02C4u;
            // 0x1b02c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFCF0u: goto label_1afcf0;
            case 0x1AFD08u: goto label_1afd08;
            case 0x1AFD34u: goto label_1afd34;
            case 0x1AFD3Cu: goto label_1afd3c;
            case 0x1AFD40u: goto label_1afd40;
            case 0x1AFD70u: goto label_1afd70;
            case 0x1AFDA0u: goto label_1afda0;
            case 0x1AFDB4u: goto label_1afdb4;
            case 0x1AFDBCu: goto label_1afdbc;
            case 0x1AFDC4u: goto label_1afdc4;
            case 0x1AFDC8u: goto label_1afdc8;
            case 0x1AFDFCu: goto label_1afdfc;
            case 0x1AFE2Cu: goto label_1afe2c;
            case 0x1AFE3Cu: goto label_1afe3c;
            case 0x1AFE44u: goto label_1afe44;
            case 0x1AFE54u: goto label_1afe54;
            case 0x1AFE58u: goto label_1afe58;
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            case 0x1AFEF4u: goto label_1afef4;
            case 0x1AFF24u: goto label_1aff24;
            case 0x1AFF2Cu: goto label_1aff2c;
            case 0x1AFF34u: goto label_1aff34;
            case 0x1AFF3Cu: goto label_1aff3c;
            case 0x1AFF44u: goto label_1aff44;
            case 0x1AFF48u: goto label_1aff48;
            case 0x1AFF4Cu: goto label_1aff4c;
            case 0x1AFF50u: goto label_1aff50;
            case 0x1AFF70u: goto label_1aff70;
            case 0x1AFF84u: goto label_1aff84;
            case 0x1AFFA4u: goto label_1affa4;
            case 0x1AFFD4u: goto label_1affd4;
            case 0x1AFFE0u: goto label_1affe0;
            case 0x1AFFE8u: goto label_1affe8;
            case 0x1AFFF4u: goto label_1afff4;
            case 0x1AFFF8u: goto label_1afff8;
            case 0x1B0024u: goto label_1b0024;
            case 0x1B0054u: goto label_1b0054;
            case 0x1B0060u: goto label_1b0060;
            case 0x1B0068u: goto label_1b0068;
            case 0x1B0074u: goto label_1b0074;
            case 0x1B0078u: goto label_1b0078;
            case 0x1B00A4u: goto label_1b00a4;
            case 0x1B00D4u: goto label_1b00d4;
            case 0x1B00E0u: goto label_1b00e0;
            case 0x1B00E8u: goto label_1b00e8;
            case 0x1B00F4u: goto label_1b00f4;
            case 0x1B00F8u: goto label_1b00f8;
            case 0x1B0124u: goto label_1b0124;
            case 0x1B0154u: goto label_1b0154;
            case 0x1B015Cu: goto label_1b015c;
            case 0x1B0164u: goto label_1b0164;
            case 0x1B016Cu: goto label_1b016c;
            case 0x1B0174u: goto label_1b0174;
            case 0x1B0178u: goto label_1b0178;
            case 0x1B017Cu: goto label_1b017c;
            case 0x1B01A4u: goto label_1b01a4;
            case 0x1B01D4u: goto label_1b01d4;
            case 0x1B01DCu: goto label_1b01dc;
            case 0x1B01E4u: goto label_1b01e4;
            case 0x1B01ECu: goto label_1b01ec;
            case 0x1B01F4u: goto label_1b01f4;
            case 0x1B01F8u: goto label_1b01f8;
            case 0x1B01FCu: goto label_1b01fc;
            case 0x1B0220u: goto label_1b0220;
            case 0x1B0234u: goto label_1b0234;
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B02CCu;
    // 0x1b02cc: 0x0  nop
    ctx->pc = 0x1b02ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

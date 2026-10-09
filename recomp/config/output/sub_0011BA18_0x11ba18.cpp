#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BA18
// Address: 0x11ba18 - 0x11bd78
void sub_0011BA18_0x11ba18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BA18_0x11ba18");
#endif

    switch (ctx->pc) {
        case 0x11ba28u: goto label_11ba28;
        case 0x11ba88u: goto label_11ba88;
        case 0x11bb0cu: goto label_11bb0c;
        case 0x11bb78u: goto label_11bb78;
        case 0x11bbe8u: goto label_11bbe8;
        case 0x11bc58u: goto label_11bc58;
        case 0x11bcd4u: goto label_11bcd4;
        case 0x11bd54u: goto label_11bd54;
        default: break;
    }

    ctx->pc = 0x11ba18u;

    // 0x11ba18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11ba18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11ba1c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11ba1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11ba20: 0xc046e68  jal         func_11B9A0
    ctx->pc = 0x11BA20u;
    SET_GPR_U32(ctx, 31, 0x11BA28u);
    ctx->pc = 0x11B9A0u;
    if (runtime->hasFunction(0x11B9A0u)) {
        auto targetFn = runtime->lookupFunction(0x11B9A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BA28u; }
        if (ctx->pc != 0x11BA28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B9A0_0x11b9a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BA28u; }
        if (ctx->pc != 0x11BA28u) { return; }
    }
    ctx->pc = 0x11BA28u;
label_11ba28:
    // 0x11ba28: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11ba28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ba2c: 0x3e00008  jr          $ra
    ctx->pc = 0x11BA2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BA30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BA2Cu;
            // 0x11ba30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BA28u: goto label_11ba28;
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BA34u;
    // 0x11ba34: 0x0  nop
    ctx->pc = 0x11ba34u;
    // NOP
    // 0x11ba38: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11ba38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11ba3c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11ba3cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11ba40: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11ba40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11ba44: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x11ba44u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ba48: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ba48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11ba4c: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BA4Cu;
    {
        const bool branch_taken_0x11ba4c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11BA50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BA4Cu;
            // 0x11ba50: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ba4c) {
            ctx->pc = 0x11BA5Cu;
            goto label_11ba5c;
        }
    }
    ctx->pc = 0x11BA54u;
    // 0x11ba54: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x11BA54u;
    {
        const bool branch_taken_0x11ba54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BA58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BA54u;
            // 0x11ba58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ba54) {
            ctx->pc = 0x11BB18u;
            goto label_11bb18;
        }
    }
    ctx->pc = 0x11BA5Cu;
label_11ba5c:
    // 0x11ba5c: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x11ba5cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x11ba60: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x11ba60u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x11ba64: 0x24e3e300  addiu       $v1, $a3, -0x1D00
    ctx->pc = 0x11ba64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959872));
    // 0x11ba68: 0xa0620004  sb          $v0, 0x4($v1)
    ctx->pc = 0x11ba68u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 2));
    // 0x11ba6c: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x11ba6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11ba70: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x11BA70u;
    {
        const bool branch_taken_0x11ba70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BA74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BA70u;
            // 0x11ba74: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ba70) {
            ctx->pc = 0x11BAB8u;
            goto label_11bab8;
        }
    }
    ctx->pc = 0x11BA78u;
    // 0x11ba78: 0x3c090026  lui         $t1, 0x26
    ctx->pc = 0x11ba78u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)38 << 16));
    // 0x11ba7c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11ba7cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11ba80: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x11ba80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x11ba84: 0x0  nop
    ctx->pc = 0x11ba84u;
    // NOP
label_11ba88:
    // 0x11ba88: 0x290200fc  slti        $v0, $t0, 0xFC
    ctx->pc = 0x11ba88u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)252) ? 1 : 0);
    // 0x11ba8c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11BA8Cu;
    {
        const bool branch_taken_0x11ba8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BA8Cu;
            // 0x11ba90: 0xc81021  addu        $v0, $a2, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ba8c) {
            ctx->pc = 0x11BAC0u;
            goto label_11bac0;
        }
    }
    ctx->pc = 0x11BA94u;
    // 0x11ba94: 0x24e3e300  addiu       $v1, $a3, -0x1D00
    ctx->pc = 0x11ba94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959872));
    // 0x11ba98: 0x90440000  lbu         $a0, 0x0($v0)
    ctx->pc = 0x11ba98u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11ba9c: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x11ba9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x11baa0: 0xa0640004  sb          $a0, 0x4($v1)
    ctx->pc = 0x11baa0u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 4));
    // 0x11baa4: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x11baa4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x11baa8: 0x5480fff7  bnel        $a0, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x11BAA8u;
    {
        const bool branch_taken_0x11baa8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x11baa8) {
            ctx->pc = 0x11BAACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BAA8u;
            // 0x11baac: 0x25080001  addiu       $t0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BA88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ba88;
        }
    }
    ctx->pc = 0x11BAB0u;
    // 0x11bab0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x11BAB0u;
    {
        const bool branch_taken_0x11bab0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BAB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BAB0u;
            // 0x11bab4: 0x240200fc  addiu       $v0, $zero, 0xFC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bab0) {
            ctx->pc = 0x11BAC4u;
            goto label_11bac4;
        }
    }
    ctx->pc = 0x11BAB8u;
label_11bab8:
    // 0x11bab8: 0x3c090026  lui         $t1, 0x26
    ctx->pc = 0x11bab8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)38 << 16));
    // 0x11babc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11babcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
label_11bac0:
    // 0x11bac0: 0x240200fc  addiu       $v0, $zero, 0xFC
    ctx->pc = 0x11bac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
label_11bac4:
    // 0x11bac4: 0x55020005  bnel        $t0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11BAC4u;
    {
        const bool branch_taken_0x11bac4 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        if (branch_taken_0x11bac4) {
            ctx->pc = 0x11BAC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BAC4u;
            // 0x11bac8: 0xace5e300  sw          $a1, -0x1D00($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4294959872), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BADCu;
            goto label_11badc;
        }
    }
    ctx->pc = 0x11BACCu;
    // 0x11bacc: 0x24e2e300  addiu       $v0, $a3, -0x1D00
    ctx->pc = 0x11baccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959872));
    // 0x11bad0: 0x240800fb  addiu       $t0, $zero, 0xFB
    ctx->pc = 0x11bad0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 251));
    // 0x11bad4: 0xa04000ff  sb          $zero, 0xFF($v0)
    ctx->pc = 0x11bad4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 255), (uint8_t)GPR_U32(ctx, 0));
    // 0x11bad8: 0xace5e300  sw          $a1, -0x1D00($a3)
    ctx->pc = 0x11bad8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294959872), GPR_U32(ctx, 5));
label_11badc:
    // 0x11badc: 0x24e2e300  addiu       $v0, $a3, -0x1D00
    ctx->pc = 0x11badcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959872));
    // 0x11bae0: 0x2524e240  addiu       $a0, $t1, -0x1DC0
    ctx->pc = 0x11bae0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), 4294959680));
    // 0x11bae4: 0xa04000ff  sb          $zero, 0xFF($v0)
    ctx->pc = 0x11bae4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 255), (uint8_t)GPR_U32(ctx, 0));
    // 0x11bae8: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x11bae8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11baec: 0x25080005  addiu       $t0, $t0, 0x5
    ctx->pc = 0x11baecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 5));
    // 0x11baf0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11baf0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11baf4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x11baf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x11baf8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11baf8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bafc: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bafcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bb00: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bb00u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bb04: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BB04u;
    SET_GPR_U32(ctx, 31, 0x11BB0Cu);
    ctx->pc = 0x11BB08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB04u;
            // 0x11bb08: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BB0Cu; }
        if (ctx->pc != 0x11BB0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BB0Cu; }
        if (ctx->pc != 0x11BB0Cu) { return; }
    }
    ctx->pc = 0x11BB0Cu;
label_11bb0c:
    // 0x11bb0c: 0x4410002  bgez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x11BB0Cu;
    {
        const bool branch_taken_0x11bb0c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BB10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB0Cu;
            // 0x11bb10: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bb0c) {
            ctx->pc = 0x11BB18u;
            goto label_11bb18;
        }
    }
    ctx->pc = 0x11BB14u;
    // 0x11bb14: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11bb14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_11bb18:
    // 0x11bb18: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bb18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bb1c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bb1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bb20: 0x3e00008  jr          $ra
    ctx->pc = 0x11BB20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BB24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB20u;
            // 0x11bb24: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BA28u: goto label_11ba28;
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BB28u;
    // 0x11bb28: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11bb28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11bb2c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bb2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bb30: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11bb30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11bb34: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bb34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bb38: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BB38u;
    {
        const bool branch_taken_0x11bb38 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11BB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB38u;
            // 0x11bb3c: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bb38) {
            ctx->pc = 0x11BB48u;
            goto label_11bb48;
        }
    }
    ctx->pc = 0x11BB40u;
    // 0x11bb40: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11BB40u;
    {
        const bool branch_taken_0x11bb40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB40u;
            // 0x11bb44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bb40) {
            ctx->pc = 0x11BB88u;
            goto label_11bb88;
        }
    }
    ctx->pc = 0x11BB48u;
label_11bb48:
    // 0x11bb48: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bb48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bb4c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bb4cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bb50: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bb50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bb54: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bb54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bb58: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x11bb58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x11bb5c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bb5cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bb60: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11bb60u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bb64: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11bb64u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bb68: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bb68u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bb6c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bb6cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bb70: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BB70u;
    SET_GPR_U32(ctx, 31, 0x11BB78u);
    ctx->pc = 0x11BB74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB70u;
            // 0x11bb74: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BB78u; }
        if (ctx->pc != 0x11BB78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BB78u; }
        if (ctx->pc != 0x11BB78u) { return; }
    }
    ctx->pc = 0x11BB78u;
label_11bb78:
    // 0x11bb78: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BB78u;
    {
        const bool branch_taken_0x11bb78 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bb78) {
            ctx->pc = 0x11BB7Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB78u;
            // 0x11bb7c: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BB88u;
            goto label_11bb88;
        }
    }
    ctx->pc = 0x11BB80u;
    // 0x11bb80: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bb80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bb84: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bb84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bb88:
    // 0x11bb88: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bb88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bb8c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bb8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bb90: 0x3e00008  jr          $ra
    ctx->pc = 0x11BB90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BB94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BB90u;
            // 0x11bb94: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BA28u: goto label_11ba28;
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BB98u;
    // 0x11bb98: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11bb98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11bb9c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bb9cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bba0: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11bba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11bba4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bba8: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BBA8u;
    {
        const bool branch_taken_0x11bba8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11BBACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBA8u;
            // 0x11bbac: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bba8) {
            ctx->pc = 0x11BBB8u;
            goto label_11bbb8;
        }
    }
    ctx->pc = 0x11BBB0u;
    // 0x11bbb0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11BBB0u;
    {
        const bool branch_taken_0x11bbb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBB0u;
            // 0x11bbb4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bbb0) {
            ctx->pc = 0x11BBF8u;
            goto label_11bbf8;
        }
    }
    ctx->pc = 0x11BBB8u;
label_11bbb8:
    // 0x11bbb8: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bbb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bbbc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bbbcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bbc0: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bbc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bbc4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bbc4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bbc8: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x11bbc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x11bbcc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bbccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bbd0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11bbd0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bbd4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11bbd4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bbd8: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bbd8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bbdc: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bbdcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bbe0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BBE0u;
    SET_GPR_U32(ctx, 31, 0x11BBE8u);
    ctx->pc = 0x11BBE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBE0u;
            // 0x11bbe4: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BBE8u; }
        if (ctx->pc != 0x11BBE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BBE8u; }
        if (ctx->pc != 0x11BBE8u) { return; }
    }
    ctx->pc = 0x11BBE8u;
label_11bbe8:
    // 0x11bbe8: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BBE8u;
    {
        const bool branch_taken_0x11bbe8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bbe8) {
            ctx->pc = 0x11BBECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BBE8u;
            // 0x11bbec: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BBF8u;
            goto label_11bbf8;
        }
    }
    ctx->pc = 0x11BBF0u;
    // 0x11bbf0: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bbf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bbf4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bbf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bbf8:
    // 0x11bbf8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bbf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bbfc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bbfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bc00: 0x3e00008  jr          $ra
    ctx->pc = 0x11BC00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BC04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC00u;
            // 0x11bc04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BA28u: goto label_11ba28;
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BC08u;
    // 0x11bc08: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11bc08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11bc0c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bc0cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bc10: 0x8c439df8  lw          $v1, -0x6208($v0)
    ctx->pc = 0x11bc10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942200)));
    // 0x11bc14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bc14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bc18: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BC18u;
    {
        const bool branch_taken_0x11bc18 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x11BC1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC18u;
            // 0x11bc1c: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc18) {
            ctx->pc = 0x11BC28u;
            goto label_11bc28;
        }
    }
    ctx->pc = 0x11BC20u;
    // 0x11bc20: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11BC20u;
    {
        const bool branch_taken_0x11bc20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BC24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC20u;
            // 0x11bc24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc20) {
            ctx->pc = 0x11BC68u;
            goto label_11bc68;
        }
    }
    ctx->pc = 0x11BC28u;
label_11bc28:
    // 0x11bc28: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bc28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bc2c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bc2cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bc30: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bc30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bc34: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bc34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bc38: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x11bc38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x11bc3c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bc3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc40: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x11bc40u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc44: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x11bc44u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc48: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bc48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bc4c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bc4cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bc50: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BC50u;
    SET_GPR_U32(ctx, 31, 0x11BC58u);
    ctx->pc = 0x11BC54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC50u;
            // 0x11bc54: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BC58u; }
        if (ctx->pc != 0x11BC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BC58u; }
        if (ctx->pc != 0x11BC58u) { return; }
    }
    ctx->pc = 0x11BC58u;
label_11bc58:
    // 0x11bc58: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BC58u;
    {
        const bool branch_taken_0x11bc58 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bc58) {
            ctx->pc = 0x11BC5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC58u;
            // 0x11bc5c: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BC68u;
            goto label_11bc68;
        }
    }
    ctx->pc = 0x11BC60u;
    // 0x11bc60: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bc60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bc64: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bc64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bc68:
    // 0x11bc68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bc68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bc6c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bc6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bc70: 0x3e00008  jr          $ra
    ctx->pc = 0x11BC70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BC74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC70u;
            // 0x11bc74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BA28u: goto label_11ba28;
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BC78u;
    // 0x11bc78: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11bc78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11bc7c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bc7cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bc80: 0x8c629df8  lw          $v0, -0x6208($v1)
    ctx->pc = 0x11bc80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942200)));
    // 0x11bc84: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11bc84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bc88: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bc88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bc8c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BC8Cu;
    {
        const bool branch_taken_0x11bc8c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BC90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC8Cu;
            // 0x11bc90: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc8c) {
            ctx->pc = 0x11BC9Cu;
            goto label_11bc9c;
        }
    }
    ctx->pc = 0x11BC94u;
    // 0x11bc94: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x11BC94u;
    {
        const bool branch_taken_0x11bc94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BC98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BC94u;
            // 0x11bc98: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bc94) {
            ctx->pc = 0x11BCE4u;
            goto label_11bce4;
        }
    }
    ctx->pc = 0x11BC9Cu;
label_11bc9c:
    // 0x11bc9c: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x11bc9cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x11bca0: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bca0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bca4: 0xace5e2c0  sw          $a1, -0x1D40($a3)
    ctx->pc = 0x11bca4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294959808), GPR_U32(ctx, 5));
    // 0x11bca8: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bca8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bcac: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bcacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bcb0: 0x24e7e2c0  addiu       $a3, $a3, -0x1D40
    ctx->pc = 0x11bcb0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959808));
    // 0x11bcb4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bcb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bcb8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x11bcb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x11bcbc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bcbcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bcc0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11bcc0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bcc4: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bcc4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bcc8: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bcc8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bccc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BCCCu;
    SET_GPR_U32(ctx, 31, 0x11BCD4u);
    ctx->pc = 0x11BCD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BCCCu;
            // 0x11bcd0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BCD4u; }
        if (ctx->pc != 0x11BCD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BCD4u; }
        if (ctx->pc != 0x11BCD4u) { return; }
    }
    ctx->pc = 0x11BCD4u;
label_11bcd4:
    // 0x11bcd4: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BCD4u;
    {
        const bool branch_taken_0x11bcd4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bcd4) {
            ctx->pc = 0x11BCD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BCD4u;
            // 0x11bcd8: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BCE4u;
            goto label_11bce4;
        }
    }
    ctx->pc = 0x11BCDCu;
    // 0x11bcdc: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bcdcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bce0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bce0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bce4:
    // 0x11bce4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bce4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bce8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bce8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bcec: 0x3e00008  jr          $ra
    ctx->pc = 0x11BCECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BCF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BCECu;
            // 0x11bcf0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BA28u: goto label_11ba28;
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BCF4u;
    // 0x11bcf4: 0x0  nop
    ctx->pc = 0x11bcf4u;
    // NOP
    // 0x11bcf8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11bcf8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11bcfc: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11bcfcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11bd00: 0x8c629df8  lw          $v0, -0x6208($v1)
    ctx->pc = 0x11bd00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942200)));
    // 0x11bd04: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x11bd04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bd08: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11bd08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11bd0c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BD0Cu;
    {
        const bool branch_taken_0x11bd0c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11BD10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD0Cu;
            // 0x11bd10: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bd0c) {
            ctx->pc = 0x11BD1Cu;
            goto label_11bd1c;
        }
    }
    ctx->pc = 0x11BD14u;
    // 0x11bd14: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x11BD14u;
    {
        const bool branch_taken_0x11bd14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11BD18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD14u;
            // 0x11bd18: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11bd14) {
            ctx->pc = 0x11BD64u;
            goto label_11bd64;
        }
    }
    ctx->pc = 0x11BD1Cu;
label_11bd1c:
    // 0x11bd1c: 0x3c070026  lui         $a3, 0x26
    ctx->pc = 0x11bd1cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
    // 0x11bd20: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11bd20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11bd24: 0xace5e2c0  sw          $a1, -0x1D40($a3)
    ctx->pc = 0x11bd24u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294959808), GPR_U32(ctx, 5));
    // 0x11bd28: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x11bd28u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x11bd2c: 0x2484e240  addiu       $a0, $a0, -0x1DC0
    ctx->pc = 0x11bd2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959680));
    // 0x11bd30: 0x24e7e2c0  addiu       $a3, $a3, -0x1D40
    ctx->pc = 0x11bd30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294959808));
    // 0x11bd34: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11bd34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11bd38: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x11bd38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x11bd3c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11bd3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11bd40: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x11bd40u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bd44: 0x2609e280  addiu       $t1, $s0, -0x1D80
    ctx->pc = 0x11bd44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959744));
    // 0x11bd48: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11bd48u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11bd4c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11BD4Cu;
    SET_GPR_U32(ctx, 31, 0x11BD54u);
    ctx->pc = 0x11BD50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD4Cu;
            // 0x11bd50: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BD54u; }
        if (ctx->pc != 0x11BD54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11BD54u; }
        if (ctx->pc != 0x11BD54u) { return; }
    }
    ctx->pc = 0x11BD54u;
label_11bd54:
    // 0x11bd54: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11BD54u;
    {
        const bool branch_taken_0x11bd54 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11bd54) {
            ctx->pc = 0x11BD58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD54u;
            // 0x11bd58: 0x8e02e280  lw          $v0, -0x1D80($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294959744)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11BD64u;
            goto label_11bd64;
        }
    }
    ctx->pc = 0x11BD5Cu;
    // 0x11bd5c: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11bd5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11bd60: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11bd60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_11bd64:
    // 0x11bd64: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11bd64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11bd68: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11bd68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11bd6c: 0x3e00008  jr          $ra
    ctx->pc = 0x11BD6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11BD70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11BD6Cu;
            // 0x11bd70: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11BA28u: goto label_11ba28;
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            case 0x11BB48u: goto label_11bb48;
            case 0x11BB78u: goto label_11bb78;
            case 0x11BB88u: goto label_11bb88;
            case 0x11BBB8u: goto label_11bbb8;
            case 0x11BBE8u: goto label_11bbe8;
            case 0x11BBF8u: goto label_11bbf8;
            case 0x11BC28u: goto label_11bc28;
            case 0x11BC58u: goto label_11bc58;
            case 0x11BC68u: goto label_11bc68;
            case 0x11BC9Cu: goto label_11bc9c;
            case 0x11BCD4u: goto label_11bcd4;
            case 0x11BCE4u: goto label_11bce4;
            case 0x11BD1Cu: goto label_11bd1c;
            case 0x11BD54u: goto label_11bd54;
            case 0x11BD64u: goto label_11bd64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BD74u;
    // 0x11bd74: 0x0  nop
    ctx->pc = 0x11bd74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011BA38
// Address: 0x11ba38 - 0x11bb28
void sub_0011BA38_0x11ba38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011BA38_0x11ba38");
#endif

    switch (ctx->pc) {
        case 0x11ba88u: goto label_11ba88;
        case 0x11bb0cu: goto label_11bb0c;
        default: break;
    }

    ctx->pc = 0x11ba38u;

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
            case 0x11BA5Cu: goto label_11ba5c;
            case 0x11BA88u: goto label_11ba88;
            case 0x11BAB8u: goto label_11bab8;
            case 0x11BAC0u: goto label_11bac0;
            case 0x11BAC4u: goto label_11bac4;
            case 0x11BADCu: goto label_11badc;
            case 0x11BB0Cu: goto label_11bb0c;
            case 0x11BB18u: goto label_11bb18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11BB28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

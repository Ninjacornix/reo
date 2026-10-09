#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011AD80
// Address: 0x11ad80 - 0x11b010
void sub_0011AD80_0x11ad80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011AD80_0x11ad80");
#endif

    switch (ctx->pc) {
        case 0x11add0u: goto label_11add0;
        case 0x11ade8u: goto label_11ade8;
        case 0x11ae08u: goto label_11ae08;
        case 0x11ae60u: goto label_11ae60;
        case 0x11aea0u: goto label_11aea0;
        case 0x11aec0u: goto label_11aec0;
        case 0x11af1cu: goto label_11af1c;
        case 0x11af3cu: goto label_11af3c;
        case 0x11af64u: goto label_11af64;
        case 0x11af74u: goto label_11af74;
        case 0x11af7cu: goto label_11af7c;
        case 0x11af90u: goto label_11af90;
        case 0x11afa0u: goto label_11afa0;
        case 0x11afb0u: goto label_11afb0;
        case 0x11afb8u: goto label_11afb8;
        case 0x11b000u: goto label_11b000;
        default: break;
    }

    ctx->pc = 0x11ad80u;

    // 0x11ad80: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x11ad80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x11ad84: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11ad84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11ad88: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x11ad88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x11ad8c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11ad8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ad90: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11ad90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11ad94: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x11ad94u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ad98: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x11ad98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x11ad9c: 0xe0b02d  daddu       $s6, $a3, $zero
    ctx->pc = 0x11ad9cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ada0: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11ada0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11ada4: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x11ada4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ada8: 0xffbe00c0  sd          $fp, 0xC0($sp)
    ctx->pc = 0x11ada8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 30));
    // 0x11adac: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x11adacu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11adb0: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11adb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11adb4: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x11adb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x11adb8: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x11adb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x11adbc: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x11adbcu;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
    // 0x11adc0: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11adc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11adc4: 0x27d2ca40  addiu       $s2, $fp, -0x35C0
    ctx->pc = 0x11adc4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 30), 4294953536));
    // 0x11adc8: 0xc04619c  jal         func_118670
    ctx->pc = 0x11ADC8u;
    SET_GPR_U32(ctx, 31, 0x11ADD0u);
    ctx->pc = 0x11ADCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ADC8u;
            // 0x11adcc: 0xffb40080  sd          $s4, 0x80($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ADD0u; }
        if (ctx->pc != 0x11ADD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ADD0u; }
        if (ctx->pc != 0x11ADD0u) { return; }
    }
    ctx->pc = 0x11ADD0u;
label_11add0:
    // 0x11add0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11add0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11add4: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11add4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11add8: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11ADD8u;
    {
        const bool branch_taken_0x11add8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11add8) {
            ctx->pc = 0x11ADDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11ADD8u;
            // 0x11addc: 0x92020000  lbu         $v0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11ADECu;
            goto label_11adec;
        }
    }
    ctx->pc = 0x11ADE0u;
    // 0x11ade0: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11ADE0u;
    SET_GPR_U32(ctx, 31, 0x11ADE8u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ADE8u; }
        if (ctx->pc != 0x11ADE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ADE8u; }
        if (ctx->pc != 0x11ADE8u) { return; }
    }
    ctx->pc = 0x11ADE8u;
label_11ade8:
    // 0x11ade8: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x11ade8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_11adec:
    // 0x11adec: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11adecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11adf0: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11adf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11adf4: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x11ADF4u;
    {
        const bool branch_taken_0x11adf4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ADF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ADF4u;
            // 0x11adf8: 0xa242000c  sb          $v0, 0xC($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11adf4) {
            ctx->pc = 0x11AE34u;
            goto label_11ae34;
        }
    }
    ctx->pc = 0x11ADFCu;
    // 0x11adfc: 0x2a270401  slti        $a3, $s1, 0x401
    ctx->pc = 0x11adfcu;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)1025) ? 1 : 0);
    // 0x11ae00: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11ae00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x11ae04: 0x0  nop
    ctx->pc = 0x11ae04u;
    // NOP
label_11ae08:
    // 0x11ae08: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11ae08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11ae0c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x11AE0Cu;
    {
        const bool branch_taken_0x11ae0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AE10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE0Cu;
            // 0x11ae10: 0x2051021  addu        $v0, $s0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ae0c) {
            ctx->pc = 0x11AE38u;
            goto label_11ae38;
        }
    }
    ctx->pc = 0x11AE14u;
    // 0x11ae14: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x11ae14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x11ae18: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11ae18u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11ae1c: 0xa083000c  sb          $v1, 0xC($a0)
    ctx->pc = 0x11ae1cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x11ae20: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11ae20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11ae24: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11AE24u;
    {
        const bool branch_taken_0x11ae24 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ae24) {
            ctx->pc = 0x11AE28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE24u;
            // 0x11ae28: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AE08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ae08;
        }
    }
    ctx->pc = 0x11AE2Cu;
    // 0x11ae2c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11AE2Cu;
    {
        const bool branch_taken_0x11ae2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE2Cu;
            // 0x11ae30: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ae2c) {
            ctx->pc = 0x11AE3Cu;
            goto label_11ae3c;
        }
    }
    ctx->pc = 0x11AE34u;
label_11ae34:
    // 0x11ae34: 0x2a270401  slti        $a3, $s1, 0x401
    ctx->pc = 0x11ae34u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)1025) ? 1 : 0);
label_11ae38:
    // 0x11ae38: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11ae38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11ae3c:
    // 0x11ae3c: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11AE3Cu;
    {
        const bool branch_taken_0x11ae3c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11ae3c) {
            ctx->pc = 0x11AE40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE3Cu;
            // 0x11ae40: 0xa240040b  sb          $zero, 0x40B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1035), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AE44u;
            goto label_11ae44;
        }
    }
    ctx->pc = 0x11AE44u;
label_11ae44:
    // 0x11ae44: 0x92620000  lbu         $v0, 0x0($s3)
    ctx->pc = 0x11ae44u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x11ae48: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11ae48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ae4c: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11ae4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11ae50: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x11AE50u;
    {
        const bool branch_taken_0x11ae50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AE54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE50u;
            // 0x11ae54: 0xa242040c  sb          $v0, 0x40C($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1036), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ae50) {
            ctx->pc = 0x11AE84u;
            goto label_11ae84;
        }
    }
    ctx->pc = 0x11AE58u;
    // 0x11ae58: 0x2646040c  addiu       $a2, $s2, 0x40C
    ctx->pc = 0x11ae58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 1036));
    // 0x11ae5c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11ae5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11ae60:
    // 0x11ae60: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11ae60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11ae64: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11AE64u;
    {
        const bool branch_taken_0x11ae64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AE68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE64u;
            // 0x11ae68: 0x2651021  addu        $v0, $s3, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ae64) {
            ctx->pc = 0x11AE84u;
            goto label_11ae84;
        }
    }
    ctx->pc = 0x11AE6Cu;
    // 0x11ae6c: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x11ae6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x11ae70: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11ae70u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11ae74: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11ae74u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11ae78: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11ae78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11ae7c: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11AE7Cu;
    {
        const bool branch_taken_0x11ae7c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ae7c) {
            ctx->pc = 0x11AE80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE7Cu;
            // 0x11ae80: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AE60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ae60;
        }
    }
    ctx->pc = 0x11AE84u;
label_11ae84:
    // 0x11ae84: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11ae84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x11ae88: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11AE88u;
    {
        const bool branch_taken_0x11ae88 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11ae88) {
            ctx->pc = 0x11AE8Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AE88u;
            // 0x11ae8c: 0xa240080b  sb          $zero, 0x80B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 2059), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AE90u;
            goto label_11ae90;
        }
    }
    ctx->pc = 0x11AE90u;
label_11ae90:
    // 0x11ae90: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x11AE90u;
    {
        const bool branch_taken_0x11ae90 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ae90) {
            ctx->pc = 0x11AEA8u;
            goto label_11aea8;
        }
    }
    ctx->pc = 0x11AE98u;
    // 0x11ae98: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11AE98u;
    SET_GPR_U32(ctx, 31, 0x11AEA0u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AEA0u; }
        if (ctx->pc != 0x11AEA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AEA0u; }
        if (ctx->pc != 0x11AEA0u) { return; }
    }
    ctx->pc = 0x11AEA0u;
label_11aea0:
    // 0x11aea0: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x11AEA0u;
    {
        const bool branch_taken_0x11aea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AEA0u;
            // 0x11aea4: 0x2402fff9  addiu       $v0, $zero, -0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967289));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aea0) {
            ctx->pc = 0x11AFBCu;
            goto label_11afbc;
        }
    }
    ctx->pc = 0x11AEA8u;
label_11aea8:
    // 0x11aea8: 0x1a20000f  blez        $s1, . + 4 + (0xF << 2)
    ctx->pc = 0x11AEA8u;
    {
        const bool branch_taken_0x11aea8 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x11AEACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AEA8u;
            // 0x11aeac: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aea8) {
            ctx->pc = 0x11AEE8u;
            goto label_11aee8;
        }
    }
    ctx->pc = 0x11AEB0u;
    // 0x11aeb0: 0x2646080c  addiu       $a2, $s2, 0x80C
    ctx->pc = 0x11aeb0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 2060));
    // 0x11aeb4: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11aeb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11aeb8: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11aeb8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11aebc: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11aebcu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11aec0:
    // 0x11aec0: 0x2c51021  addu        $v0, $s6, $a1
    ctx->pc = 0x11aec0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 5)));
    // 0x11aec4: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x11aec4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x11aec8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11aec8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11aecc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11aeccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x11aed0: 0xb1102a  slt         $v0, $a1, $s1
    ctx->pc = 0x11aed0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x11aed4: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11aed4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11aed8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11AED8u;
    {
        const bool branch_taken_0x11aed8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11aed8) {
            ctx->pc = 0x11AEC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11aec0;
        }
    }
    ctx->pc = 0x11AEE0u;
    // 0x11aee0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11AEE0u;
    {
        const bool branch_taken_0x11aee0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AEE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AEE0u;
            // 0x11aee4: 0xae510c10  sw          $s1, 0xC10($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 3088), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11aee0) {
            ctx->pc = 0x11AEF8u;
            goto label_11aef8;
        }
    }
    ctx->pc = 0x11AEE8u;
label_11aee8:
    // 0x11aee8: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11aee8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11aeec: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11aeecu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11aef0: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11aef0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11aef4: 0xae510c10  sw          $s1, 0xC10($s2)
    ctx->pc = 0x11aef4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 3088), GPR_U32(ctx, 17));
label_11aef8:
    // 0x11aef8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11aef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11aefc: 0xae570c0c  sw          $s7, 0xC0C($s2)
    ctx->pc = 0x11aefcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 3084), GPR_U32(ctx, 23));
    // 0x11af00: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11af00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11af04: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11af04u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11af08: 0x27d0ca40  addiu       $s0, $fp, -0x35C0
    ctx->pc = 0x11af08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 30), 4294953536));
    // 0x11af0c: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11af0cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11af10: 0x2694d680  addiu       $s4, $s4, -0x2980
    ctx->pc = 0x11af10u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
    // 0x11af14: 0xc045188  jal         func_114620
    ctx->pc = 0x11AF14u;
    SET_GPR_U32(ctx, 31, 0x11AF1Cu);
    ctx->pc = 0x11AF18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF14u;
            // 0x11af18: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF1Cu; }
        if (ctx->pc != 0x11AF1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF1Cu; }
        if (ctx->pc != 0x11AF1Cu) { return; }
    }
    ctx->pc = 0x11AF1Cu;
label_11af1c:
    // 0x11af1c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11af1cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11af20: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11af20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11af24: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11af24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11af28: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11af28u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11af2c: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11af2cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11af30: 0x24050c14  addiu       $a1, $zero, 0xC14
    ctx->pc = 0x11af30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3092));
    // 0x11af34: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11AF34u;
    SET_GPR_U32(ctx, 31, 0x11AF3Cu);
    ctx->pc = 0x11AF38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF34u;
            // 0x11af38: 0xae510000  sw          $s1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF3Cu; }
        if (ctx->pc != 0x11AF3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF3Cu; }
        if (ctx->pc != 0x11AF3Cu) { return; }
    }
    ctx->pc = 0x11AF3Cu;
label_11af3c:
    // 0x11af3c: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11af3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x11af40: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11af40u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11af44: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11af44u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11af48: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x11af48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x11af4c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11af4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11af50: 0x24080c14  addiu       $t0, $zero, 0xC14
    ctx->pc = 0x11af50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3092));
    // 0x11af54: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x11af54u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11af58: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11af58u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11af5c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11AF5Cu;
    SET_GPR_U32(ctx, 31, 0x11AF64u);
    ctx->pc = 0x11AF60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF5Cu;
            // 0x11af60: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF64u; }
        if (ctx->pc != 0x11AF64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF64u; }
        if (ctx->pc != 0x11AF64u) { return; }
    }
    ctx->pc = 0x11AF64u;
label_11af64:
    // 0x11af64: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11AF64u;
    {
        const bool branch_taken_0x11af64 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11AF68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF64u;
            // 0x11af68: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11af64) {
            ctx->pc = 0x11AF84u;
            goto label_11af84;
        }
    }
    ctx->pc = 0x11AF6Cu;
    // 0x11af6c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AF6Cu;
    SET_GPR_U32(ctx, 31, 0x11AF74u);
    ctx->pc = 0x11AF70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF6Cu;
            // 0x11af70: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF74u; }
        if (ctx->pc != 0x11AF74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF74u; }
        if (ctx->pc != 0x11AF74u) { return; }
    }
    ctx->pc = 0x11AF74u;
label_11af74:
    // 0x11af74: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11AF74u;
    SET_GPR_U32(ctx, 31, 0x11AF7Cu);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF7Cu; }
        if (ctx->pc != 0x11AF7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF7Cu; }
        if (ctx->pc != 0x11AF7Cu) { return; }
    }
    ctx->pc = 0x11AF7Cu;
label_11af7c:
    // 0x11af7c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11AF7Cu;
    {
        const bool branch_taken_0x11af7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AF80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF7Cu;
            // 0x11af80: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11af7c) {
            ctx->pc = 0x11AFBCu;
            goto label_11afbc;
        }
    }
    ctx->pc = 0x11AF84u;
label_11af84:
    // 0x11af84: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x11af84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x11af88: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11AF88u;
    SET_GPR_U32(ctx, 31, 0x11AF90u);
    ctx->pc = 0x11AF8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF88u;
            // 0x11af8c: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF90u; }
        if (ctx->pc != 0x11AF90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AF90u; }
        if (ctx->pc != 0x11AF90u) { return; }
    }
    ctx->pc = 0x11AF90u;
label_11af90:
    // 0x11af90: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11AF90u;
    {
        const bool branch_taken_0x11af90 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11af90) {
            ctx->pc = 0x11AFA8u;
            goto label_11afa8;
        }
    }
    ctx->pc = 0x11AF98u;
    // 0x11af98: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AF98u;
    SET_GPR_U32(ctx, 31, 0x11AFA0u);
    ctx->pc = 0x11AF9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AF98u;
            // 0x11af9c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AFA0u; }
        if (ctx->pc != 0x11AFA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AFA0u; }
        if (ctx->pc != 0x11AFA0u) { return; }
    }
    ctx->pc = 0x11AFA0u;
label_11afa0:
    // 0x11afa0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11AFA0u;
    {
        const bool branch_taken_0x11afa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AFA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AFA0u;
            // 0x11afa4: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11afa0) {
            ctx->pc = 0x11AFBCu;
            goto label_11afbc;
        }
    }
    ctx->pc = 0x11AFA8u;
label_11afa8:
    // 0x11afa8: 0xc045198  jal         func_114660
    ctx->pc = 0x11AFA8u;
    SET_GPR_U32(ctx, 31, 0x11AFB0u);
    ctx->pc = 0x11AFACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AFA8u;
            // 0x11afac: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AFB0u; }
        if (ctx->pc != 0x11AFB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AFB0u; }
        if (ctx->pc != 0x11AFB0u) { return; }
    }
    ctx->pc = 0x11AFB0u;
label_11afb0:
    // 0x11afb0: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AFB0u;
    SET_GPR_U32(ctx, 31, 0x11AFB8u);
    ctx->pc = 0x11AFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AFB0u;
            // 0x11afb4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AFB8u; }
        if (ctx->pc != 0x11AFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AFB8u; }
        if (ctx->pc != 0x11AFB8u) { return; }
    }
    ctx->pc = 0x11AFB8u;
label_11afb8:
    // 0x11afb8: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11afb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11afbc:
    // 0x11afbc: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x11afbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x11afc0: 0xdfbe00c0  ld          $fp, 0xC0($sp)
    ctx->pc = 0x11afc0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x11afc4: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x11afc4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11afc8: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11afc8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11afcc: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11afccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11afd0: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11afd0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11afd4: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11afd4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11afd8: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11afd8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11afdc: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11afdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11afe0: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11afe0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11afe4: 0x3e00008  jr          $ra
    ctx->pc = 0x11AFE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11AFE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AFE4u;
            // 0x11afe8: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11ADD0u: goto label_11add0;
            case 0x11ADE8u: goto label_11ade8;
            case 0x11ADECu: goto label_11adec;
            case 0x11AE08u: goto label_11ae08;
            case 0x11AE34u: goto label_11ae34;
            case 0x11AE38u: goto label_11ae38;
            case 0x11AE3Cu: goto label_11ae3c;
            case 0x11AE44u: goto label_11ae44;
            case 0x11AE60u: goto label_11ae60;
            case 0x11AE84u: goto label_11ae84;
            case 0x11AE90u: goto label_11ae90;
            case 0x11AEA0u: goto label_11aea0;
            case 0x11AEA8u: goto label_11aea8;
            case 0x11AEC0u: goto label_11aec0;
            case 0x11AEE8u: goto label_11aee8;
            case 0x11AEF8u: goto label_11aef8;
            case 0x11AF1Cu: goto label_11af1c;
            case 0x11AF3Cu: goto label_11af3c;
            case 0x11AF64u: goto label_11af64;
            case 0x11AF74u: goto label_11af74;
            case 0x11AF7Cu: goto label_11af7c;
            case 0x11AF84u: goto label_11af84;
            case 0x11AF90u: goto label_11af90;
            case 0x11AFA0u: goto label_11afa0;
            case 0x11AFA8u: goto label_11afa8;
            case 0x11AFB0u: goto label_11afb0;
            case 0x11AFB8u: goto label_11afb8;
            case 0x11AFBCu: goto label_11afbc;
            case 0x11B000u: goto label_11b000;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11AFECu;
    // 0x11afec: 0x0  nop
    ctx->pc = 0x11afecu;
    // NOP
    // 0x11aff0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11aff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11aff4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11aff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11aff8: 0xc0466ca  jal         func_119B28
    ctx->pc = 0x11AFF8u;
    SET_GPR_U32(ctx, 31, 0x11B000u);
    ctx->pc = 0x11AFFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AFF8u;
            // 0x11affc: 0x24050015  addiu       $a1, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119B28u;
    if (runtime->hasFunction(0x119B28u)) {
        auto targetFn = runtime->lookupFunction(0x119B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B000u; }
        if (ctx->pc != 0x11B000u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119B28_0x119b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B000u; }
        if (ctx->pc != 0x11B000u) { return; }
    }
    ctx->pc = 0x11B000u;
label_11b000:
    // 0x11b000: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11b000u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11b004: 0x3e00008  jr          $ra
    ctx->pc = 0x11B004u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B004u;
            // 0x11b008: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11ADD0u: goto label_11add0;
            case 0x11ADE8u: goto label_11ade8;
            case 0x11ADECu: goto label_11adec;
            case 0x11AE08u: goto label_11ae08;
            case 0x11AE34u: goto label_11ae34;
            case 0x11AE38u: goto label_11ae38;
            case 0x11AE3Cu: goto label_11ae3c;
            case 0x11AE44u: goto label_11ae44;
            case 0x11AE60u: goto label_11ae60;
            case 0x11AE84u: goto label_11ae84;
            case 0x11AE90u: goto label_11ae90;
            case 0x11AEA0u: goto label_11aea0;
            case 0x11AEA8u: goto label_11aea8;
            case 0x11AEC0u: goto label_11aec0;
            case 0x11AEE8u: goto label_11aee8;
            case 0x11AEF8u: goto label_11aef8;
            case 0x11AF1Cu: goto label_11af1c;
            case 0x11AF3Cu: goto label_11af3c;
            case 0x11AF64u: goto label_11af64;
            case 0x11AF74u: goto label_11af74;
            case 0x11AF7Cu: goto label_11af7c;
            case 0x11AF84u: goto label_11af84;
            case 0x11AF90u: goto label_11af90;
            case 0x11AFA0u: goto label_11afa0;
            case 0x11AFA8u: goto label_11afa8;
            case 0x11AFB0u: goto label_11afb0;
            case 0x11AFB8u: goto label_11afb8;
            case 0x11AFBCu: goto label_11afbc;
            case 0x11B000u: goto label_11b000;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B00Cu;
    // 0x11b00c: 0x0  nop
    ctx->pc = 0x11b00cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

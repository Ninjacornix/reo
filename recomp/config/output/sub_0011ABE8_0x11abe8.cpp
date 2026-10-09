#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011ABE8
// Address: 0x11abe8 - 0x11ad80
void sub_0011ABE8_0x11abe8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011ABE8_0x11abe8");
#endif

    switch (ctx->pc) {
        case 0x11ac24u: goto label_11ac24;
        case 0x11ac3cu: goto label_11ac3c;
        case 0x11ac60u: goto label_11ac60;
        case 0x11acc4u: goto label_11acc4;
        case 0x11ad00u: goto label_11ad00;
        case 0x11ad10u: goto label_11ad10;
        case 0x11ad18u: goto label_11ad18;
        case 0x11ad2cu: goto label_11ad2c;
        case 0x11ad3cu: goto label_11ad3c;
        case 0x11ad4cu: goto label_11ad4c;
        case 0x11ad54u: goto label_11ad54;
        default: break;
    }

    ctx->pc = 0x11abe8u;

    // 0x11abe8: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x11abe8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x11abec: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11abecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11abf0: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11abf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11abf4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11abf4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11abf8: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11abf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11abfc: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x11abfcu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ac00: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11ac00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11ac04: 0x24040013  addiu       $a0, $zero, 0x13
    ctx->pc = 0x11ac04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x11ac08: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x11ac08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x11ac0c: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11ac0cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11ac10: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11ac10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11ac14: 0x26d0ca40  addiu       $s0, $s6, -0x35C0
    ctx->pc = 0x11ac14u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11ac18: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x11ac18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x11ac1c: 0xc04619c  jal         func_118670
    ctx->pc = 0x11AC1Cu;
    SET_GPR_U32(ctx, 31, 0x11AC24u);
    ctx->pc = 0x11AC20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AC1Cu;
            // 0x11ac20: 0xffb20060  sd          $s2, 0x60($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AC24u; }
        if (ctx->pc != 0x11AC24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AC24u; }
        if (ctx->pc != 0x11AC24u) { return; }
    }
    ctx->pc = 0x11AC24u;
label_11ac24:
    // 0x11ac24: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11ac24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11ac28: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x11ac28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x11ac2c: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11AC2Cu;
    {
        const bool branch_taken_0x11ac2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ac2c) {
            ctx->pc = 0x11AC30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AC2Cu;
            // 0x11ac30: 0x92220000  lbu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AC40u;
            goto label_11ac40;
        }
    }
    ctx->pc = 0x11AC34u;
    // 0x11ac34: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11AC34u;
    SET_GPR_U32(ctx, 31, 0x11AC3Cu);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AC3Cu; }
        if (ctx->pc != 0x11AC3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AC3Cu; }
        if (ctx->pc != 0x11AC3Cu) { return; }
    }
    ctx->pc = 0x11AC3Cu;
label_11ac3c:
    // 0x11ac3c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11ac3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_11ac40:
    // 0x11ac40: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11ac40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ac44: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11ac44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11ac48: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x11AC48u;
    {
        const bool branch_taken_0x11ac48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AC4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AC48u;
            // 0x11ac4c: 0xa2020014  sb          $v0, 0x14($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ac48) {
            ctx->pc = 0x11AC8Cu;
            goto label_11ac8c;
        }
    }
    ctx->pc = 0x11AC50u;
    // 0x11ac50: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x11ac50u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11ac54: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11ac54u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11ac58: 0x3c130026  lui         $s3, 0x26
    ctx->pc = 0x11ac58u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
    // 0x11ac5c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11ac5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11ac60:
    // 0x11ac60: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11ac60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11ac64: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11AC64u;
    {
        const bool branch_taken_0x11ac64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AC68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AC64u;
            // 0x11ac68: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ac64) {
            ctx->pc = 0x11AC98u;
            goto label_11ac98;
        }
    }
    ctx->pc = 0x11AC6Cu;
    // 0x11ac6c: 0x2052021  addu        $a0, $s0, $a1
    ctx->pc = 0x11ac6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
    // 0x11ac70: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11ac70u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11ac74: 0xa0830014  sb          $v1, 0x14($a0)
    ctx->pc = 0x11ac74u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 20), (uint8_t)GPR_U32(ctx, 3));
    // 0x11ac78: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11ac78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11ac7c: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11AC7Cu;
    {
        const bool branch_taken_0x11ac7c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ac7c) {
            ctx->pc = 0x11AC80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AC7Cu;
            // 0x11ac80: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11AC60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ac60;
        }
    }
    ctx->pc = 0x11AC84u;
    // 0x11ac84: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11AC84u;
    {
        const bool branch_taken_0x11ac84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AC84u;
            // 0x11ac88: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ac84) {
            ctx->pc = 0x11AC9Cu;
            goto label_11ac9c;
        }
    }
    ctx->pc = 0x11AC8Cu;
label_11ac8c:
    // 0x11ac8c: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x11ac8cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11ac90: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11ac90u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11ac94: 0x3c130026  lui         $s3, 0x26
    ctx->pc = 0x11ac94u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
label_11ac98:
    // 0x11ac98: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11ac98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11ac9c:
    // 0x11ac9c: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11AC9Cu;
    {
        const bool branch_taken_0x11ac9c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11ac9c) {
            ctx->pc = 0x11ACA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11AC9Cu;
            // 0x11aca0: 0xa2000413  sb          $zero, 0x413($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1043), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11ACA4u;
            goto label_11aca4;
        }
    }
    ctx->pc = 0x11ACA4u;
label_11aca4:
    // 0x11aca4: 0xae150010  sw          $s5, 0x10($s0)
    ctx->pc = 0x11aca4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 21));
    // 0x11aca8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11aca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11acac: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11acacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11acb0: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11acb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11acb4: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11acb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11acb8: 0x2673d680  addiu       $s3, $s3, -0x2980
    ctx->pc = 0x11acb8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294956672));
    // 0x11acbc: 0xc045188  jal         func_114620
    ctx->pc = 0x11ACBCu;
    SET_GPR_U32(ctx, 31, 0x11ACC4u);
    ctx->pc = 0x11ACC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ACBCu;
            // 0x11acc0: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ACC4u; }
        if (ctx->pc != 0x11ACC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ACC4u; }
        if (ctx->pc != 0x11ACC4u) { return; }
    }
    ctx->pc = 0x11ACC4u;
label_11acc4:
    // 0x11acc4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11acc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11acc8: 0xae120004  sw          $s2, 0x4($s0)
    ctx->pc = 0x11acc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 18));
    // 0x11accc: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11acccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11acd0: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x11acd0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x11acd4: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x11acd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x11acd8: 0x2684e140  addiu       $a0, $s4, -0x1EC0
    ctx->pc = 0x11acd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), 4294959424));
    // 0x11acdc: 0x26c7ca40  addiu       $a3, $s6, -0x35C0
    ctx->pc = 0x11acdcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11ace0: 0x24050013  addiu       $a1, $zero, 0x13
    ctx->pc = 0x11ace0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x11ace4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11ace4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11ace8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11ace8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11acec: 0x24080414  addiu       $t0, $zero, 0x414
    ctx->pc = 0x11acecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1044));
    // 0x11acf0: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x11acf0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11acf4: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11acf4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11acf8: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11ACF8u;
    SET_GPR_U32(ctx, 31, 0x11AD00u);
    ctx->pc = 0x11ACFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ACF8u;
            // 0x11acfc: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD00u; }
        if (ctx->pc != 0x11AD00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD00u; }
        if (ctx->pc != 0x11AD00u) { return; }
    }
    ctx->pc = 0x11AD00u;
label_11ad00:
    // 0x11ad00: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11AD00u;
    {
        const bool branch_taken_0x11ad00 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11AD04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD00u;
            // 0x11ad04: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ad00) {
            ctx->pc = 0x11AD20u;
            goto label_11ad20;
        }
    }
    ctx->pc = 0x11AD08u;
    // 0x11ad08: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AD08u;
    SET_GPR_U32(ctx, 31, 0x11AD10u);
    ctx->pc = 0x11AD0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD08u;
            // 0x11ad0c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD10u; }
        if (ctx->pc != 0x11AD10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD10u; }
        if (ctx->pc != 0x11AD10u) { return; }
    }
    ctx->pc = 0x11AD10u;
label_11ad10:
    // 0x11ad10: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11AD10u;
    SET_GPR_U32(ctx, 31, 0x11AD18u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD18u; }
        if (ctx->pc != 0x11AD18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD18u; }
        if (ctx->pc != 0x11AD18u) { return; }
    }
    ctx->pc = 0x11AD18u;
label_11ad18:
    // 0x11ad18: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11AD18u;
    {
        const bool branch_taken_0x11ad18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AD1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD18u;
            // 0x11ad1c: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ad18) {
            ctx->pc = 0x11AD58u;
            goto label_11ad58;
        }
    }
    ctx->pc = 0x11AD20u;
label_11ad20:
    // 0x11ad20: 0x2621025  or          $v0, $s3, $v0
    ctx->pc = 0x11ad20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x11ad24: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11AD24u;
    SET_GPR_U32(ctx, 31, 0x11AD2Cu);
    ctx->pc = 0x11AD28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD24u;
            // 0x11ad28: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD2Cu; }
        if (ctx->pc != 0x11AD2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD2Cu; }
        if (ctx->pc != 0x11AD2Cu) { return; }
    }
    ctx->pc = 0x11AD2Cu;
label_11ad2c:
    // 0x11ad2c: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11AD2Cu;
    {
        const bool branch_taken_0x11ad2c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11ad2c) {
            ctx->pc = 0x11AD44u;
            goto label_11ad44;
        }
    }
    ctx->pc = 0x11AD34u;
    // 0x11ad34: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AD34u;
    SET_GPR_U32(ctx, 31, 0x11AD3Cu);
    ctx->pc = 0x11AD38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD34u;
            // 0x11ad38: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD3Cu; }
        if (ctx->pc != 0x11AD3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD3Cu; }
        if (ctx->pc != 0x11AD3Cu) { return; }
    }
    ctx->pc = 0x11AD3Cu;
label_11ad3c:
    // 0x11ad3c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11AD3Cu;
    {
        const bool branch_taken_0x11ad3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11AD40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD3Cu;
            // 0x11ad40: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ad3c) {
            ctx->pc = 0x11AD58u;
            goto label_11ad58;
        }
    }
    ctx->pc = 0x11AD44u;
label_11ad44:
    // 0x11ad44: 0xc045198  jal         func_114660
    ctx->pc = 0x11AD44u;
    SET_GPR_U32(ctx, 31, 0x11AD4Cu);
    ctx->pc = 0x11AD48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD44u;
            // 0x11ad48: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD4Cu; }
        if (ctx->pc != 0x11AD4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD4Cu; }
        if (ctx->pc != 0x11AD4Cu) { return; }
    }
    ctx->pc = 0x11AD4Cu;
label_11ad4c:
    // 0x11ad4c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11AD4Cu;
    SET_GPR_U32(ctx, 31, 0x11AD54u);
    ctx->pc = 0x11AD50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD4Cu;
            // 0x11ad50: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD54u; }
        if (ctx->pc != 0x11AD54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11AD54u; }
        if (ctx->pc != 0x11AD54u) { return; }
    }
    ctx->pc = 0x11AD54u;
label_11ad54:
    // 0x11ad54: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11ad54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11ad58:
    // 0x11ad58: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x11ad58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11ad5c: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11ad5cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11ad60: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11ad60u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11ad64: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11ad64u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11ad68: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11ad68u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11ad6c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11ad6cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11ad70: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11ad70u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11ad74: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11ad74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11ad78: 0x3e00008  jr          $ra
    ctx->pc = 0x11AD78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11AD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11AD78u;
            // 0x11ad7c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11AC24u: goto label_11ac24;
            case 0x11AC3Cu: goto label_11ac3c;
            case 0x11AC40u: goto label_11ac40;
            case 0x11AC60u: goto label_11ac60;
            case 0x11AC8Cu: goto label_11ac8c;
            case 0x11AC98u: goto label_11ac98;
            case 0x11AC9Cu: goto label_11ac9c;
            case 0x11ACA4u: goto label_11aca4;
            case 0x11ACC4u: goto label_11acc4;
            case 0x11AD00u: goto label_11ad00;
            case 0x11AD10u: goto label_11ad10;
            case 0x11AD18u: goto label_11ad18;
            case 0x11AD20u: goto label_11ad20;
            case 0x11AD2Cu: goto label_11ad2c;
            case 0x11AD3Cu: goto label_11ad3c;
            case 0x11AD44u: goto label_11ad44;
            case 0x11AD4Cu: goto label_11ad4c;
            case 0x11AD54u: goto label_11ad54;
            case 0x11AD58u: goto label_11ad58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11AD80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

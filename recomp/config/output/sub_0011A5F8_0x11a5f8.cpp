#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011A5F8
// Address: 0x11a5f8 - 0x11a798
void sub_0011A5F8_0x11a5f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011A5F8_0x11a5f8");
#endif

    switch (ctx->pc) {
        case 0x11a638u: goto label_11a638;
        case 0x11a650u: goto label_11a650;
        case 0x11a670u: goto label_11a670;
        case 0x11a6d8u: goto label_11a6d8;
        case 0x11a714u: goto label_11a714;
        case 0x11a724u: goto label_11a724;
        case 0x11a72cu: goto label_11a72c;
        case 0x11a740u: goto label_11a740;
        case 0x11a750u: goto label_11a750;
        case 0x11a760u: goto label_11a760;
        case 0x11a768u: goto label_11a768;
        default: break;
    }

    ctx->pc = 0x11a5f8u;

    // 0x11a5f8: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x11a5f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x11a5fc: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11a5fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11a600: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11a600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11a604: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11a604u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a608: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x11a608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x11a60c: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x11a60cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a610: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11a610u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11a614: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x11a614u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x11a618: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x11a618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x11a61c: 0x3c170026  lui         $s7, 0x26
    ctx->pc = 0x11a61cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)38 << 16));
    // 0x11a620: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11a620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11a624: 0x26f2ca40  addiu       $s2, $s7, -0x35C0
    ctx->pc = 0x11a624u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x11a628: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11a628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11a62c: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x11a62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x11a630: 0xc04619c  jal         func_118670
    ctx->pc = 0x11A630u;
    SET_GPR_U32(ctx, 31, 0x11A638u);
    ctx->pc = 0x11A634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A630u;
            // 0x11a634: 0xffb00040  sd          $s0, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A638u; }
        if (ctx->pc != 0x11A638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A638u; }
        if (ctx->pc != 0x11A638u) { return; }
    }
    ctx->pc = 0x11A638u;
label_11a638:
    // 0x11a638: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11a638u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11a63c: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x11a63cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x11a640: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11A640u;
    {
        const bool branch_taken_0x11a640 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a640) {
            ctx->pc = 0x11A644u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11A640u;
            // 0x11a644: 0x92220000  lbu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11A654u;
            goto label_11a654;
        }
    }
    ctx->pc = 0x11A648u;
    // 0x11a648: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11A648u;
    SET_GPR_U32(ctx, 31, 0x11A650u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A650u; }
        if (ctx->pc != 0x11A650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A650u; }
        if (ctx->pc != 0x11A650u) { return; }
    }
    ctx->pc = 0x11A650u;
label_11a650:
    // 0x11a650: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11a650u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_11a654:
    // 0x11a654: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x11a654u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a658: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x11a658u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a65c: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x11A65Cu;
    {
        const bool branch_taken_0x11a65c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A65Cu;
            // 0x11a660: 0xa2420010  sb          $v0, 0x10($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 16), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a65c) {
            ctx->pc = 0x11A698u;
            goto label_11a698;
        }
    }
    ctx->pc = 0x11A664u;
    // 0x11a664: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11a664u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a668: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11a668u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11a66c: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11a66cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11a670:
    // 0x11a670: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x11a670u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x11a674: 0x2a020400  slti        $v0, $s0, 0x400
    ctx->pc = 0x11a674u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11a678: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x11A678u;
    {
        const bool branch_taken_0x11a678 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A678u;
            // 0x11a67c: 0x2301021  addu        $v0, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a678) {
            ctx->pc = 0x11A6A4u;
            goto label_11a6a4;
        }
    }
    ctx->pc = 0x11A680u;
    // 0x11a680: 0x2502021  addu        $a0, $s2, $s0
    ctx->pc = 0x11a680u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x11a684: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11a684u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11a688: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11A688u;
    {
        const bool branch_taken_0x11a688 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x11A68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A688u;
            // 0x11a68c: 0xa0830010  sb          $v1, 0x10($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 16), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a688) {
            ctx->pc = 0x11A670u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11a670;
        }
    }
    ctx->pc = 0x11A690u;
    // 0x11a690: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11A690u;
    {
        const bool branch_taken_0x11a690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A690u;
            // 0x11a694: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a690) {
            ctx->pc = 0x11A6A8u;
            goto label_11a6a8;
        }
    }
    ctx->pc = 0x11A698u;
label_11a698:
    // 0x11a698: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11a698u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a69c: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11a69cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11a6a0: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11a6a0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11a6a4:
    // 0x11a6a4: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11a6a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11a6a8:
    // 0x11a6a8: 0x56020004  bnel        $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11A6A8u;
    {
        const bool branch_taken_0x11a6a8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x11a6a8) {
            ctx->pc = 0x11A6ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11A6A8u;
            // 0x11a6ac: 0xae56000c  sw          $s6, 0xC($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 22));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11A6BCu;
            goto label_11a6bc;
        }
    }
    ctx->pc = 0x11A6B0u;
    // 0x11a6b0: 0xa240040f  sb          $zero, 0x40F($s2)
    ctx->pc = 0x11a6b0u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1039), (uint8_t)GPR_U32(ctx, 0));
    // 0x11a6b4: 0x241003ff  addiu       $s0, $zero, 0x3FF
    ctx->pc = 0x11a6b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1023));
    // 0x11a6b8: 0xae56000c  sw          $s6, 0xC($s2)
    ctx->pc = 0x11a6b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 22));
label_11a6bc:
    // 0x11a6bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11a6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11a6c0: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11a6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11a6c4: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11a6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11a6c8: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11a6c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11a6cc: 0x2694d680  addiu       $s4, $s4, -0x2980
    ctx->pc = 0x11a6ccu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
    // 0x11a6d0: 0xc045188  jal         func_114620
    ctx->pc = 0x11A6D0u;
    SET_GPR_U32(ctx, 31, 0x11A6D8u);
    ctx->pc = 0x11A6D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A6D0u;
            // 0x11a6d4: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A6D8u; }
        if (ctx->pc != 0x11A6D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A6D8u; }
        if (ctx->pc != 0x11A6D8u) { return; }
    }
    ctx->pc = 0x11A6D8u;
label_11a6d8:
    // 0x11a6d8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11a6d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a6dc: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11a6dcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11a6e0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11a6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a6e4: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x11a6e4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x11a6e8: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11a6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11a6ec: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11a6ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x11a6f0: 0x26e7ca40  addiu       $a3, $s7, -0x35C0
    ctx->pc = 0x11a6f0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x11a6f4: 0x26080011  addiu       $t0, $s0, 0x11
    ctx->pc = 0x11a6f4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 17));
    // 0x11a6f8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11a6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11a6fc: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x11a6fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x11a700: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11a700u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a704: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x11a704u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a708: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11a708u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a70c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11A70Cu;
    SET_GPR_U32(ctx, 31, 0x11A714u);
    ctx->pc = 0x11A710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A70Cu;
            // 0x11a710: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A714u; }
        if (ctx->pc != 0x11A714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A714u; }
        if (ctx->pc != 0x11A714u) { return; }
    }
    ctx->pc = 0x11A714u;
label_11a714:
    // 0x11a714: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11A714u;
    {
        const bool branch_taken_0x11a714 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11A718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A714u;
            // 0x11a718: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a714) {
            ctx->pc = 0x11A734u;
            goto label_11a734;
        }
    }
    ctx->pc = 0x11A71Cu;
    // 0x11a71c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A71Cu;
    SET_GPR_U32(ctx, 31, 0x11A724u);
    ctx->pc = 0x11A720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A71Cu;
            // 0x11a720: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A724u; }
        if (ctx->pc != 0x11A724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A724u; }
        if (ctx->pc != 0x11A724u) { return; }
    }
    ctx->pc = 0x11A724u;
label_11a724:
    // 0x11a724: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A724u;
    SET_GPR_U32(ctx, 31, 0x11A72Cu);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A72Cu; }
        if (ctx->pc != 0x11A72Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A72Cu; }
        if (ctx->pc != 0x11A72Cu) { return; }
    }
    ctx->pc = 0x11A72Cu;
label_11a72c:
    // 0x11a72c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11A72Cu;
    {
        const bool branch_taken_0x11a72c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A72Cu;
            // 0x11a730: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a72c) {
            ctx->pc = 0x11A76Cu;
            goto label_11a76c;
        }
    }
    ctx->pc = 0x11A734u;
label_11a734:
    // 0x11a734: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x11a734u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x11a738: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A738u;
    SET_GPR_U32(ctx, 31, 0x11A740u);
    ctx->pc = 0x11A73Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A738u;
            // 0x11a73c: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A740u; }
        if (ctx->pc != 0x11A740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A740u; }
        if (ctx->pc != 0x11A740u) { return; }
    }
    ctx->pc = 0x11A740u;
label_11a740:
    // 0x11a740: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11A740u;
    {
        const bool branch_taken_0x11a740 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a740) {
            ctx->pc = 0x11A758u;
            goto label_11a758;
        }
    }
    ctx->pc = 0x11A748u;
    // 0x11a748: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A748u;
    SET_GPR_U32(ctx, 31, 0x11A750u);
    ctx->pc = 0x11A74Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A748u;
            // 0x11a74c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A750u; }
        if (ctx->pc != 0x11A750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A750u; }
        if (ctx->pc != 0x11A750u) { return; }
    }
    ctx->pc = 0x11A750u;
label_11a750:
    // 0x11a750: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11A750u;
    {
        const bool branch_taken_0x11a750 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A750u;
            // 0x11a754: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a750) {
            ctx->pc = 0x11A76Cu;
            goto label_11a76c;
        }
    }
    ctx->pc = 0x11A758u;
label_11a758:
    // 0x11a758: 0xc045198  jal         func_114660
    ctx->pc = 0x11A758u;
    SET_GPR_U32(ctx, 31, 0x11A760u);
    ctx->pc = 0x11A75Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A758u;
            // 0x11a75c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A760u; }
        if (ctx->pc != 0x11A760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A760u; }
        if (ctx->pc != 0x11A760u) { return; }
    }
    ctx->pc = 0x11A760u;
label_11a760:
    // 0x11a760: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A760u;
    SET_GPR_U32(ctx, 31, 0x11A768u);
    ctx->pc = 0x11A764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A760u;
            // 0x11a764: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A768u; }
        if (ctx->pc != 0x11A768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A768u; }
        if (ctx->pc != 0x11A768u) { return; }
    }
    ctx->pc = 0x11A768u;
label_11a768:
    // 0x11a768: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11a768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11a76c:
    // 0x11a76c: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x11a76cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x11a770: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x11a770u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11a774: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11a774u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11a778: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11a778u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11a77c: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11a77cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11a780: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11a780u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11a784: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11a784u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11a788: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11a788u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11a78c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11a78cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11a790: 0x3e00008  jr          $ra
    ctx->pc = 0x11A790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A790u;
            // 0x11a794: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11A638u: goto label_11a638;
            case 0x11A650u: goto label_11a650;
            case 0x11A654u: goto label_11a654;
            case 0x11A670u: goto label_11a670;
            case 0x11A698u: goto label_11a698;
            case 0x11A6A4u: goto label_11a6a4;
            case 0x11A6A8u: goto label_11a6a8;
            case 0x11A6BCu: goto label_11a6bc;
            case 0x11A6D8u: goto label_11a6d8;
            case 0x11A714u: goto label_11a714;
            case 0x11A724u: goto label_11a724;
            case 0x11A72Cu: goto label_11a72c;
            case 0x11A734u: goto label_11a734;
            case 0x11A740u: goto label_11a740;
            case 0x11A750u: goto label_11a750;
            case 0x11A758u: goto label_11a758;
            case 0x11A760u: goto label_11a760;
            case 0x11A768u: goto label_11a768;
            case 0x11A76Cu: goto label_11a76c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A798u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

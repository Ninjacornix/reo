#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011A130
// Address: 0x11a130 - 0x11a250
void sub_0011A130_0x11a130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011A130_0x11a130");
#endif

    switch (ctx->pc) {
        case 0x11a15cu: goto label_11a15c;
        case 0x11a174u: goto label_11a174;
        case 0x11a190u: goto label_11a190;
        case 0x11a1dcu: goto label_11a1dc;
        case 0x11a1ecu: goto label_11a1ec;
        case 0x11a1f4u: goto label_11a1f4;
        case 0x11a208u: goto label_11a208;
        case 0x11a218u: goto label_11a218;
        case 0x11a228u: goto label_11a228;
        case 0x11a230u: goto label_11a230;
        default: break;
    }

    ctx->pc = 0x11a130u;

    // 0x11a130: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x11a130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x11a134: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11a134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11a138: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11a138u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a13c: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x11a13cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x11a140: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11a140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11a144: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x11a144u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x11a148: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x11a148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x11a14c: 0x3c130026  lui         $s3, 0x26
    ctx->pc = 0x11a14cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
    // 0x11a150: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11a150u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11a154: 0xc04619c  jal         func_118670
    ctx->pc = 0x11A154u;
    SET_GPR_U32(ctx, 31, 0x11A15Cu);
    ctx->pc = 0x11A158u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A154u;
            // 0x11a158: 0x2670ca40  addiu       $s0, $s3, -0x35C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294953536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A15Cu; }
        if (ctx->pc != 0x11A15Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A15Cu; }
        if (ctx->pc != 0x11A15Cu) { return; }
    }
    ctx->pc = 0x11A15Cu;
label_11a15c:
    // 0x11a15c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11a15cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11a160: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11a160u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11a164: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11A164u;
    {
        const bool branch_taken_0x11a164 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a164) {
            ctx->pc = 0x11A168u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11A164u;
            // 0x11a168: 0xae11000c  sw          $s1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11A178u;
            goto label_11a178;
        }
    }
    ctx->pc = 0x11A16Cu;
    // 0x11a16c: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11A16Cu;
    SET_GPR_U32(ctx, 31, 0x11A174u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A174u; }
        if (ctx->pc != 0x11A174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A174u; }
        if (ctx->pc != 0x11A174u) { return; }
    }
    ctx->pc = 0x11A174u;
label_11a174:
    // 0x11a174: 0xae11000c  sw          $s1, 0xC($s0)
    ctx->pc = 0x11a174u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 17));
label_11a178:
    // 0x11a178: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11a178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11a17c: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11a17cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11a180: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11a180u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11a184: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11a184u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11a188: 0xc045188  jal         func_114620
    ctx->pc = 0x11A188u;
    SET_GPR_U32(ctx, 31, 0x11A190u);
    ctx->pc = 0x11A18Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A188u;
            // 0x11a18c: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A190u; }
        if (ctx->pc != 0x11A190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A190u; }
        if (ctx->pc != 0x11A190u) { return; }
    }
    ctx->pc = 0x11A190u;
label_11a190:
    // 0x11a190: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11a190u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a194: 0x27a30030  addiu       $v1, $sp, 0x30
    ctx->pc = 0x11a194u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a198: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11a198u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11a19c: 0xae71ca40  sw          $s1, -0x35C0($s3)
    ctx->pc = 0x11a19cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294953536), GPR_U32(ctx, 17));
    // 0x11a1a0: 0x2452d680  addiu       $s2, $v0, -0x2980
    ctx->pc = 0x11a1a0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956672));
    // 0x11a1a4: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11a1a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11a1a8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11a1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a1ac: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x11a1acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x11a1b0: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x11a1b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x11a1b4: 0x2484e140  addiu       $a0, $a0, -0x1EC0
    ctx->pc = 0x11a1b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959424));
    // 0x11a1b8: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11a1b8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a1bc: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x11a1bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x11a1c0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11a1c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11a1c4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11a1c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a1c8: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x11a1c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x11a1cc: 0x240482d  daddu       $t1, $s2, $zero
    ctx->pc = 0x11a1ccu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a1d0: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11a1d0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a1d4: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11A1D4u;
    SET_GPR_U32(ctx, 31, 0x11A1DCu);
    ctx->pc = 0x11A1D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1D4u;
            // 0x11a1d8: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1DCu; }
        if (ctx->pc != 0x11A1DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1DCu; }
        if (ctx->pc != 0x11A1DCu) { return; }
    }
    ctx->pc = 0x11A1DCu;
label_11a1dc:
    // 0x11a1dc: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11A1DCu;
    {
        const bool branch_taken_0x11a1dc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11A1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1DCu;
            // 0x11a1e0: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a1dc) {
            ctx->pc = 0x11A1FCu;
            goto label_11a1fc;
        }
    }
    ctx->pc = 0x11A1E4u;
    // 0x11a1e4: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A1E4u;
    SET_GPR_U32(ctx, 31, 0x11A1ECu);
    ctx->pc = 0x11A1E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1E4u;
            // 0x11a1e8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1ECu; }
        if (ctx->pc != 0x11A1ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1ECu; }
        if (ctx->pc != 0x11A1ECu) { return; }
    }
    ctx->pc = 0x11A1ECu;
label_11a1ec:
    // 0x11a1ec: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A1ECu;
    SET_GPR_U32(ctx, 31, 0x11A1F4u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1F4u; }
        if (ctx->pc != 0x11A1F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A1F4u; }
        if (ctx->pc != 0x11A1F4u) { return; }
    }
    ctx->pc = 0x11A1F4u;
label_11a1f4:
    // 0x11a1f4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11A1F4u;
    {
        const bool branch_taken_0x11a1f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A1F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A1F4u;
            // 0x11a1f8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a1f4) {
            ctx->pc = 0x11A234u;
            goto label_11a234;
        }
    }
    ctx->pc = 0x11A1FCu;
label_11a1fc:
    // 0x11a1fc: 0x2421025  or          $v0, $s2, $v0
    ctx->pc = 0x11a1fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x11a200: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A200u;
    SET_GPR_U32(ctx, 31, 0x11A208u);
    ctx->pc = 0x11A204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A200u;
            // 0x11a204: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A208u; }
        if (ctx->pc != 0x11A208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A208u; }
        if (ctx->pc != 0x11A208u) { return; }
    }
    ctx->pc = 0x11A208u;
label_11a208:
    // 0x11a208: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11A208u;
    {
        const bool branch_taken_0x11a208 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a208) {
            ctx->pc = 0x11A220u;
            goto label_11a220;
        }
    }
    ctx->pc = 0x11A210u;
    // 0x11a210: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A210u;
    SET_GPR_U32(ctx, 31, 0x11A218u);
    ctx->pc = 0x11A214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A210u;
            // 0x11a214: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A218u; }
        if (ctx->pc != 0x11A218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A218u; }
        if (ctx->pc != 0x11A218u) { return; }
    }
    ctx->pc = 0x11A218u;
label_11a218:
    // 0x11a218: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11A218u;
    {
        const bool branch_taken_0x11a218 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A21Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A218u;
            // 0x11a21c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a218) {
            ctx->pc = 0x11A234u;
            goto label_11a234;
        }
    }
    ctx->pc = 0x11A220u;
label_11a220:
    // 0x11a220: 0xc045198  jal         func_114660
    ctx->pc = 0x11A220u;
    SET_GPR_U32(ctx, 31, 0x11A228u);
    ctx->pc = 0x11A224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A220u;
            // 0x11a224: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A228u; }
        if (ctx->pc != 0x11A228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A228u; }
        if (ctx->pc != 0x11A228u) { return; }
    }
    ctx->pc = 0x11A228u;
label_11a228:
    // 0x11a228: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A228u;
    SET_GPR_U32(ctx, 31, 0x11A230u);
    ctx->pc = 0x11A22Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A228u;
            // 0x11a22c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A230u; }
        if (ctx->pc != 0x11A230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A230u; }
        if (ctx->pc != 0x11A230u) { return; }
    }
    ctx->pc = 0x11A230u;
label_11a230:
    // 0x11a230: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11a230u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11a234:
    // 0x11a234: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x11a234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11a238: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11a238u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11a23c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11a23cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11a240: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11a240u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11a244: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11a244u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11a248: 0x3e00008  jr          $ra
    ctx->pc = 0x11A248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A248u;
            // 0x11a24c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11A15Cu: goto label_11a15c;
            case 0x11A174u: goto label_11a174;
            case 0x11A178u: goto label_11a178;
            case 0x11A190u: goto label_11a190;
            case 0x11A1DCu: goto label_11a1dc;
            case 0x11A1ECu: goto label_11a1ec;
            case 0x11A1F4u: goto label_11a1f4;
            case 0x11A1FCu: goto label_11a1fc;
            case 0x11A208u: goto label_11a208;
            case 0x11A218u: goto label_11a218;
            case 0x11A220u: goto label_11a220;
            case 0x11A228u: goto label_11a228;
            case 0x11A230u: goto label_11a230;
            case 0x11A234u: goto label_11a234;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A250u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

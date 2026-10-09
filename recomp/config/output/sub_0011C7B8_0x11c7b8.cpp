#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C7B8
// Address: 0x11c7b8 - 0x11cad8
void sub_0011C7B8_0x11c7b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C7B8_0x11c7b8");
#endif

    switch (ctx->pc) {
        case 0x11c7e8u: goto label_11c7e8;
        case 0x11c7f8u: goto label_11c7f8;
        case 0x11c824u: goto label_11c824;
        case 0x11c838u: goto label_11c838;
        case 0x11c868u: goto label_11c868;
        case 0x11c8d0u: goto label_11c8d0;
        case 0x11c8fcu: goto label_11c8fc;
        case 0x11c930u: goto label_11c930;
        case 0x11c980u: goto label_11c980;
        case 0x11ca1cu: goto label_11ca1c;
        case 0x11caa4u: goto label_11caa4;
        default: break;
    }

    ctx->pc = 0x11c7b8u;

label_11c7b8:
    // 0x11c7b8: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x11c7b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x11c7bc: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x11c7bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x11c7c0: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x11c7c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x11c7c4: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11c7c4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c7c8: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11c7c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11c7cc: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x11c7ccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c7d0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11c7d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11c7d4: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11c7d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c7d8: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x11c7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x11c7dc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11c7dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c7e0: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C7E0u;
    SET_GPR_U32(ctx, 31, 0x11C7E8u);
    ctx->pc = 0x11C7E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C7E0u;
            // 0x11c7e4: 0xffb10020  sd          $s1, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C7E8u; }
        if (ctx->pc != 0x11C7E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C7E8u; }
        if (ctx->pc != 0x11C7E8u) { return; }
    }
    ctx->pc = 0x11C7E8u;
label_11c7e8:
    // 0x11c7e8: 0x440002c  bltz        $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x11C7E8u;
    {
        const bool branch_taken_0x11c7e8 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11C7ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C7E8u;
            // 0x11c7ec: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c7e8) {
            ctx->pc = 0x11C89Cu;
            goto label_11c89c;
        }
    }
    ctx->pc = 0x11C7F0u;
    // 0x11c7f0: 0xc046f9e  jal         func_11BE78
    ctx->pc = 0x11C7F0u;
    SET_GPR_U32(ctx, 31, 0x11C7F8u);
    ctx->pc = 0x11BE78u;
    if (runtime->hasFunction(0x11BE78u)) {
        auto targetFn = runtime->lookupFunction(0x11BE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C7F8u; }
        if (ctx->pc != 0x11C7F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BE78_0x11be78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C7F8u; }
        if (ctx->pc != 0x11C7F8u) { return; }
    }
    ctx->pc = 0x11C7F8u;
label_11c7f8:
    // 0x11c7f8: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C7F8u;
    {
        const bool branch_taken_0x11c7f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11c7f8) {
            ctx->pc = 0x11C7FCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C7F8u;
            // 0x11c7fc: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C80Cu;
            goto label_11c80c;
        }
    }
    ctx->pc = 0x11C800u;
    // 0x11c800: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c800u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c804: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x11C804u;
    {
        const bool branch_taken_0x11c804 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C804u;
            // 0x11c808: 0x3442fffc  ori         $v0, $v0, 0xFFFC (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c804) {
            ctx->pc = 0x11C89Cu;
            goto label_11c89c;
        }
    }
    ctx->pc = 0x11C80Cu;
label_11c80c:
    // 0x11c80c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11c80cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c810: 0x2451e408  addiu       $s1, $v0, -0x1BF8
    ctx->pc = 0x11c810u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960136));
    // 0x11c814: 0x240600fc  addiu       $a2, $zero, 0xFC
    ctx->pc = 0x11c814u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
    // 0x11c818: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11c818u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c81c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x11C81Cu;
    SET_GPR_U32(ctx, 31, 0x11C824u);
    ctx->pc = 0x11C820u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C81Cu;
            // 0x11c820: 0x2630fff8  addiu       $s0, $s1, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C824u; }
        if (ctx->pc != 0x11C824u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C824u; }
        if (ctx->pc != 0x11C824u) { return; }
    }
    ctx->pc = 0x11C824u;
label_11c824:
    // 0x11c824: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x11c824u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c828: 0xa2000103  sb          $zero, 0x103($s0)
    ctx->pc = 0x11c828u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 259), (uint8_t)GPR_U32(ctx, 0));
    // 0x11c82c: 0x262400fc  addiu       $a0, $s1, 0xFC
    ctx->pc = 0x11c82cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 252));
    // 0x11c830: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x11C830u;
    SET_GPR_U32(ctx, 31, 0x11C838u);
    ctx->pc = 0x11C834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C830u;
            // 0x11c834: 0x240600fc  addiu       $a2, $zero, 0xFC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C838u; }
        if (ctx->pc != 0x11C838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C838u; }
        if (ctx->pc != 0x11C838u) { return; }
    }
    ctx->pc = 0x11C838u;
label_11c838:
    // 0x11c838: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11c838u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11c83c: 0xa20001ff  sb          $zero, 0x1FF($s0)
    ctx->pc = 0x11c83cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 511), (uint8_t)GPR_U32(ctx, 0));
    // 0x11c840: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x11c840u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c844: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11c844u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11c848: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c848u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c84c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c84cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c850: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11c850u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c854: 0x24080200  addiu       $t0, $zero, 0x200
    ctx->pc = 0x11c854u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x11c858: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11c858u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c85c: 0x240a0010  addiu       $t2, $zero, 0x10
    ctx->pc = 0x11c85cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x11c860: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C860u;
    SET_GPR_U32(ctx, 31, 0x11C868u);
    ctx->pc = 0x11C864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C860u;
            // 0x11c864: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C868u; }
        if (ctx->pc != 0x11C868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C868u; }
        if (ctx->pc != 0x11C868u) { return; }
    }
    ctx->pc = 0x11C868u;
label_11c868:
    // 0x11c868: 0x4430004  bgezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C868u;
    {
        const bool branch_taken_0x11c868 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c868) {
            ctx->pc = 0x11C86Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C868u;
            // 0x11c86c: 0x8e22fff8  lw          $v0, -0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294967288)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C87Cu;
            goto label_11c87c;
        }
    }
    ctx->pc = 0x11C870u;
    // 0x11c870: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c870u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c874: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x11C874u;
    {
        const bool branch_taken_0x11c874 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C874u;
            // 0x11c878: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c874) {
            ctx->pc = 0x11C89Cu;
            goto label_11c89c;
        }
    }
    ctx->pc = 0x11C87Cu;
label_11c87c:
    // 0x11c87c: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C87Cu;
    {
        const bool branch_taken_0x11c87c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11c87c) {
            ctx->pc = 0x11C880u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C87Cu;
            // 0x11c880: 0xae820000  sw          $v0, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C890u;
            goto label_11c890;
        }
    }
    ctx->pc = 0x11C884u;
    // 0x11c884: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c884u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c888: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x11C888u;
    {
        const bool branch_taken_0x11c888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C88Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C888u;
            // 0x11c88c: 0x3442fffd  ori         $v0, $v0, 0xFFFD (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65533);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c888) {
            ctx->pc = 0x11C89Cu;
            goto label_11c89c;
        }
    }
    ctx->pc = 0x11C890u;
label_11c890:
    // 0x11c890: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11c890u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c894: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x11c894u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11c898: 0xae830004  sw          $v1, 0x4($s4)
    ctx->pc = 0x11c898u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4), GPR_U32(ctx, 3));
label_11c89c:
    // 0x11c89c: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x11c89cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11c8a0: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x11c8a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11c8a4: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x11c8a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11c8a8: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11c8a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11c8ac: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11c8acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c8b0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c8b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c8b4: 0x3e00008  jr          $ra
    ctx->pc = 0x11C8B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C8B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C8B4u;
            // 0x11c8b8: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C7B8u: goto label_11c7b8;
            case 0x11C7E8u: goto label_11c7e8;
            case 0x11C7F8u: goto label_11c7f8;
            case 0x11C80Cu: goto label_11c80c;
            case 0x11C824u: goto label_11c824;
            case 0x11C838u: goto label_11c838;
            case 0x11C868u: goto label_11c868;
            case 0x11C87Cu: goto label_11c87c;
            case 0x11C890u: goto label_11c890;
            case 0x11C89Cu: goto label_11c89c;
            case 0x11C8D0u: goto label_11c8d0;
            case 0x11C8FCu: goto label_11c8fc;
            case 0x11C930u: goto label_11c930;
            case 0x11C940u: goto label_11c940;
            case 0x11C980u: goto label_11c980;
            case 0x11C994u: goto label_11c994;
            case 0x11C9A8u: goto label_11c9a8;
            case 0x11C9BCu: goto label_11c9bc;
            case 0x11C9C4u: goto label_11c9c4;
            case 0x11C9D0u: goto label_11c9d0;
            case 0x11C9D4u: goto label_11c9d4;
            case 0x11C9D8u: goto label_11c9d8;
            case 0x11CA1Cu: goto label_11ca1c;
            case 0x11CA2Cu: goto label_11ca2c;
            case 0x11CA48u: goto label_11ca48;
            case 0x11CA60u: goto label_11ca60;
            case 0x11CA74u: goto label_11ca74;
            case 0x11CA78u: goto label_11ca78;
            case 0x11CAA4u: goto label_11caa4;
            case 0x11CABCu: goto label_11cabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C8BCu;
    // 0x11c8bc: 0x0  nop
    ctx->pc = 0x11c8bcu;
    // NOP
    // 0x11c8c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11c8c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11c8c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11c8c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11c8c8: 0xc0471ee  jal         func_11C7B8
    ctx->pc = 0x11C8C8u;
    SET_GPR_U32(ctx, 31, 0x11C8D0u);
    ctx->pc = 0x11C8CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C8C8u;
            // 0x11c8cc: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C7B8u;
    goto label_11c7b8;
    ctx->pc = 0x11C8D0u;
label_11c8d0:
    // 0x11c8d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11c8d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11c8d4: 0x3e00008  jr          $ra
    ctx->pc = 0x11C8D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C8D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C8D4u;
            // 0x11c8d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C7B8u: goto label_11c7b8;
            case 0x11C7E8u: goto label_11c7e8;
            case 0x11C7F8u: goto label_11c7f8;
            case 0x11C80Cu: goto label_11c80c;
            case 0x11C824u: goto label_11c824;
            case 0x11C838u: goto label_11c838;
            case 0x11C868u: goto label_11c868;
            case 0x11C87Cu: goto label_11c87c;
            case 0x11C890u: goto label_11c890;
            case 0x11C89Cu: goto label_11c89c;
            case 0x11C8D0u: goto label_11c8d0;
            case 0x11C8FCu: goto label_11c8fc;
            case 0x11C930u: goto label_11c930;
            case 0x11C940u: goto label_11c940;
            case 0x11C980u: goto label_11c980;
            case 0x11C994u: goto label_11c994;
            case 0x11C9A8u: goto label_11c9a8;
            case 0x11C9BCu: goto label_11c9bc;
            case 0x11C9C4u: goto label_11c9c4;
            case 0x11C9D0u: goto label_11c9d0;
            case 0x11C9D4u: goto label_11c9d4;
            case 0x11C9D8u: goto label_11c9d8;
            case 0x11CA1Cu: goto label_11ca1c;
            case 0x11CA2Cu: goto label_11ca2c;
            case 0x11CA48u: goto label_11ca48;
            case 0x11CA60u: goto label_11ca60;
            case 0x11CA74u: goto label_11ca74;
            case 0x11CA78u: goto label_11ca78;
            case 0x11CAA4u: goto label_11caa4;
            case 0x11CABCu: goto label_11cabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C8DCu;
    // 0x11c8dc: 0x0  nop
    ctx->pc = 0x11c8dcu;
    // NOP
    // 0x11c8e0: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x11c8e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c8e4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11c8e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11c8e8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x11c8e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x11c8ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11c8ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11c8f0: 0x24a58b98  addiu       $a1, $a1, -0x7468
    ctx->pc = 0x11c8f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294937496));
    // 0x11c8f4: 0xc0471ee  jal         func_11C7B8
    ctx->pc = 0x11C8F4u;
    SET_GPR_U32(ctx, 31, 0x11C8FCu);
    ctx->pc = 0x11C8F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C8F4u;
            // 0x11c8f8: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C7B8u;
    goto label_11c7b8;
    ctx->pc = 0x11C8FCu;
label_11c8fc:
    // 0x11c8fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11c8fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11c900: 0x3e00008  jr          $ra
    ctx->pc = 0x11C900u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C900u;
            // 0x11c904: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C7B8u: goto label_11c7b8;
            case 0x11C7E8u: goto label_11c7e8;
            case 0x11C7F8u: goto label_11c7f8;
            case 0x11C80Cu: goto label_11c80c;
            case 0x11C824u: goto label_11c824;
            case 0x11C838u: goto label_11c838;
            case 0x11C868u: goto label_11c868;
            case 0x11C87Cu: goto label_11c87c;
            case 0x11C890u: goto label_11c890;
            case 0x11C89Cu: goto label_11c89c;
            case 0x11C8D0u: goto label_11c8d0;
            case 0x11C8FCu: goto label_11c8fc;
            case 0x11C930u: goto label_11c930;
            case 0x11C940u: goto label_11c940;
            case 0x11C980u: goto label_11c980;
            case 0x11C994u: goto label_11c994;
            case 0x11C9A8u: goto label_11c9a8;
            case 0x11C9BCu: goto label_11c9bc;
            case 0x11C9C4u: goto label_11c9c4;
            case 0x11C9D0u: goto label_11c9d0;
            case 0x11C9D4u: goto label_11c9d4;
            case 0x11C9D8u: goto label_11c9d8;
            case 0x11CA1Cu: goto label_11ca1c;
            case 0x11CA2Cu: goto label_11ca2c;
            case 0x11CA48u: goto label_11ca48;
            case 0x11CA60u: goto label_11ca60;
            case 0x11CA74u: goto label_11ca74;
            case 0x11CA78u: goto label_11ca78;
            case 0x11CAA4u: goto label_11caa4;
            case 0x11CABCu: goto label_11cabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C908u;
    // 0x11c908: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x11c908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x11c90c: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x11c90cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x11c910: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11c910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11c914: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x11c914u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c918: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11c918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11c91c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11c91cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c920: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x11c920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x11c924: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x11c924u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c928: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C928u;
    SET_GPR_U32(ctx, 31, 0x11C930u);
    ctx->pc = 0x11C92Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C928u;
            // 0x11c92c: 0xffb10020  sd          $s1, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C930u; }
        if (ctx->pc != 0x11C930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C930u; }
        if (ctx->pc != 0x11C930u) { return; }
    }
    ctx->pc = 0x11C930u;
label_11c930:
    // 0x11c930: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11C930u;
    {
        const bool branch_taken_0x11c930 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11C934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C930u;
            // 0x11c934: 0x2e020003  sltiu       $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c930) {
            ctx->pc = 0x11C940u;
            goto label_11c940;
        }
    }
    ctx->pc = 0x11C938u;
    // 0x11c938: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x11C938u;
    {
        const bool branch_taken_0x11c938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C93Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C938u;
            // 0x11c93c: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c938) {
            ctx->pc = 0x11C9D8u;
            goto label_11c9d8;
        }
    }
    ctx->pc = 0x11C940u;
label_11c940:
    // 0x11c940: 0x10400020  beqz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x11C940u;
    {
        const bool branch_taken_0x11c940 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C940u;
            // 0x11c944: 0x3c110026  lui         $s1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c940) {
            ctx->pc = 0x11C9C4u;
            goto label_11c9c4;
        }
    }
    ctx->pc = 0x11C948u;
    // 0x11c948: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11c948u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11c94c: 0x2622e400  addiu       $v0, $s1, -0x1C00
    ctx->pc = 0x11c94cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294960128));
    // 0x11c950: 0xae33e400  sw          $s3, -0x1C00($s1)
    ctx->pc = 0x11c950u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294960128), GPR_U32(ctx, 19));
    // 0x11c954: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x11c954u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c958: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x11c958u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x11c95c: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11c95cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11c960: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x11c960u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x11c964: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c964u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c968: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c968u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c96c: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x11c96cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11c970: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x11c970u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c974: 0x240a0020  addiu       $t2, $zero, 0x20
    ctx->pc = 0x11c974u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11c978: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C978u;
    SET_GPR_U32(ctx, 31, 0x11C980u);
    ctx->pc = 0x11C97Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C978u;
            // 0x11c97c: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C980u; }
        if (ctx->pc != 0x11C980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C980u; }
        if (ctx->pc != 0x11C980u) { return; }
    }
    ctx->pc = 0x11C980u;
label_11c980:
    // 0x11c980: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C980u;
    {
        const bool branch_taken_0x11c980 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c980) {
            ctx->pc = 0x11C994u;
            goto label_11c994;
        }
    }
    ctx->pc = 0x11C988u;
    // 0x11c988: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c988u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c98c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x11C98Cu;
    {
        const bool branch_taken_0x11c98c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C98Cu;
            // 0x11c990: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c98c) {
            ctx->pc = 0x11C9D8u;
            goto label_11c9d8;
        }
    }
    ctx->pc = 0x11C994u;
label_11c994:
    // 0x11c994: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C994u;
    {
        const bool branch_taken_0x11c994 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x11C998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C994u;
            // 0x11c998: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c994) {
            ctx->pc = 0x11C9A8u;
            goto label_11c9a8;
        }
    }
    ctx->pc = 0x11C99Cu;
    // 0x11c99c: 0x9222e400  lbu         $v0, -0x1C00($s1)
    ctx->pc = 0x11c99cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 4294960128)));
    // 0x11c9a0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x11C9A0u;
    {
        const bool branch_taken_0x11c9a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C9A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9A0u;
            // 0x11c9a4: 0xa2420000  sb          $v0, 0x0($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9a0) {
            ctx->pc = 0x11C9D4u;
            goto label_11c9d4;
        }
    }
    ctx->pc = 0x11C9A8u;
label_11c9a8:
    // 0x11c9a8: 0x16020004  bne         $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C9A8u;
    {
        const bool branch_taken_0x11c9a8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x11C9ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9A8u;
            // 0x11c9ac: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9a8) {
            ctx->pc = 0x11C9BCu;
            goto label_11c9bc;
        }
    }
    ctx->pc = 0x11C9B0u;
    // 0x11c9b0: 0x9622e400  lhu         $v0, -0x1C00($s1)
    ctx->pc = 0x11c9b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 4294960128)));
    // 0x11c9b4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x11C9B4u;
    {
        const bool branch_taken_0x11c9b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9B4u;
            // 0x11c9b8: 0xa6420000  sh          $v0, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9b4) {
            ctx->pc = 0x11C9D4u;
            goto label_11c9d4;
        }
    }
    ctx->pc = 0x11C9BCu;
label_11c9bc:
    // 0x11c9bc: 0x52020004  beql        $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C9BCu;
    {
        const bool branch_taken_0x11c9bc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x11c9bc) {
            ctx->pc = 0x11C9C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9BCu;
            // 0x11c9c0: 0x8e22e400  lw          $v0, -0x1C00($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294960128)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C9D0u;
            goto label_11c9d0;
        }
    }
    ctx->pc = 0x11C9C4u;
label_11c9c4:
    // 0x11c9c4: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c9c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c9c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11C9C8u;
    {
        const bool branch_taken_0x11c9c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C9CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9C8u;
            // 0x11c9cc: 0x3442fffe  ori         $v0, $v0, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c9c8) {
            ctx->pc = 0x11C9D8u;
            goto label_11c9d8;
        }
    }
    ctx->pc = 0x11C9D0u;
label_11c9d0:
    // 0x11c9d0: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x11c9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_11c9d4:
    // 0x11c9d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11c9d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_11c9d8:
    // 0x11c9d8: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x11c9d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11c9dc: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x11c9dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11c9e0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11c9e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11c9e4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11c9e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c9e8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c9e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c9ec: 0x3e00008  jr          $ra
    ctx->pc = 0x11C9ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C9F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C9ECu;
            // 0x11c9f0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C7B8u: goto label_11c7b8;
            case 0x11C7E8u: goto label_11c7e8;
            case 0x11C7F8u: goto label_11c7f8;
            case 0x11C80Cu: goto label_11c80c;
            case 0x11C824u: goto label_11c824;
            case 0x11C838u: goto label_11c838;
            case 0x11C868u: goto label_11c868;
            case 0x11C87Cu: goto label_11c87c;
            case 0x11C890u: goto label_11c890;
            case 0x11C89Cu: goto label_11c89c;
            case 0x11C8D0u: goto label_11c8d0;
            case 0x11C8FCu: goto label_11c8fc;
            case 0x11C930u: goto label_11c930;
            case 0x11C940u: goto label_11c940;
            case 0x11C980u: goto label_11c980;
            case 0x11C994u: goto label_11c994;
            case 0x11C9A8u: goto label_11c9a8;
            case 0x11C9BCu: goto label_11c9bc;
            case 0x11C9C4u: goto label_11c9c4;
            case 0x11C9D0u: goto label_11c9d0;
            case 0x11C9D4u: goto label_11c9d4;
            case 0x11C9D8u: goto label_11c9d8;
            case 0x11CA1Cu: goto label_11ca1c;
            case 0x11CA2Cu: goto label_11ca2c;
            case 0x11CA48u: goto label_11ca48;
            case 0x11CA60u: goto label_11ca60;
            case 0x11CA74u: goto label_11ca74;
            case 0x11CA78u: goto label_11ca78;
            case 0x11CAA4u: goto label_11caa4;
            case 0x11CABCu: goto label_11cabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C9F4u;
    // 0x11c9f4: 0x0  nop
    ctx->pc = 0x11c9f4u;
    // NOP
    // 0x11c9f8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11c9f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11c9fc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11c9fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11ca00: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11ca00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11ca04: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x11ca04u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca08: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11ca08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11ca0c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11ca0cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca10: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11ca10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11ca14: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11CA14u;
    SET_GPR_U32(ctx, 31, 0x11CA1Cu);
    ctx->pc = 0x11CA18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA14u;
            // 0x11ca18: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CA1Cu; }
        if (ctx->pc != 0x11CA1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CA1Cu; }
        if (ctx->pc != 0x11CA1Cu) { return; }
    }
    ctx->pc = 0x11CA1Cu;
label_11ca1c:
    // 0x11ca1c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11CA1Cu;
    {
        const bool branch_taken_0x11ca1c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11CA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA1Cu;
            // 0x11ca20: 0x3c070026  lui         $a3, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca1c) {
            ctx->pc = 0x11CA2Cu;
            goto label_11ca2c;
        }
    }
    ctx->pc = 0x11CA24u;
    // 0x11ca24: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x11CA24u;
    {
        const bool branch_taken_0x11ca24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA24u;
            // 0x11ca28: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca24) {
            ctx->pc = 0x11CABCu;
            goto label_11cabc;
        }
    }
    ctx->pc = 0x11CA2Cu;
label_11ca2c:
    // 0x11ca2c: 0x24e3e400  addiu       $v1, $a3, -0x1C00
    ctx->pc = 0x11ca2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294960128));
    // 0x11ca30: 0xacf2e400  sw          $s2, -0x1C00($a3)
    ctx->pc = 0x11ca30u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294960128), GPR_U32(ctx, 18));
    // 0x11ca34: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CA34u;
    {
        const bool branch_taken_0x11ca34 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x11CA38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA34u;
            // 0x11ca38: 0xac700004  sw          $s0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca34) {
            ctx->pc = 0x11CA48u;
            goto label_11ca48;
        }
    }
    ctx->pc = 0x11CA3Cu;
    // 0x11ca3c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11ca3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11ca40: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x11CA40u;
    {
        const bool branch_taken_0x11ca40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA40u;
            // 0x11ca44: 0xa0620008  sb          $v0, 0x8($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 8), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca40) {
            ctx->pc = 0x11CA78u;
            goto label_11ca78;
        }
    }
    ctx->pc = 0x11CA48u;
label_11ca48:
    // 0x11ca48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11ca48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11ca4c: 0x16020004  bne         $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CA4Cu;
    {
        const bool branch_taken_0x11ca4c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x11CA50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA4Cu;
            // 0x11ca50: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca4c) {
            ctx->pc = 0x11CA60u;
            goto label_11ca60;
        }
    }
    ctx->pc = 0x11CA54u;
    // 0x11ca54: 0x96220000  lhu         $v0, 0x0($s1)
    ctx->pc = 0x11ca54u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11ca58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x11CA58u;
    {
        const bool branch_taken_0x11ca58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA58u;
            // 0x11ca5c: 0xa4620008  sh          $v0, 0x8($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 8), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca58) {
            ctx->pc = 0x11CA78u;
            goto label_11ca78;
        }
    }
    ctx->pc = 0x11CA60u;
label_11ca60:
    // 0x11ca60: 0x52020004  beql        $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11CA60u;
    {
        const bool branch_taken_0x11ca60 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x11ca60) {
            ctx->pc = 0x11CA64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA60u;
            // 0x11ca64: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11CA74u;
            goto label_11ca74;
        }
    }
    ctx->pc = 0x11CA68u;
    // 0x11ca68: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11ca68u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11ca6c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x11CA6Cu;
    {
        const bool branch_taken_0x11ca6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA6Cu;
            // 0x11ca70: 0x3442fffe  ori         $v0, $v0, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ca6c) {
            ctx->pc = 0x11CABCu;
            goto label_11cabc;
        }
    }
    ctx->pc = 0x11CA74u;
label_11ca74:
    // 0x11ca74: 0xac620008  sw          $v0, 0x8($v1)
    ctx->pc = 0x11ca74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 2));
label_11ca78:
    // 0x11ca78: 0x24e7e400  addiu       $a3, $a3, -0x1C00
    ctx->pc = 0x11ca78u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294960128));
    // 0x11ca7c: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11ca7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11ca80: 0x2484e600  addiu       $a0, $a0, -0x1A00
    ctx->pc = 0x11ca80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960640));
    // 0x11ca84: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11ca84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11ca88: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x11ca88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11ca8c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11ca8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca90: 0x24080020  addiu       $t0, $zero, 0x20
    ctx->pc = 0x11ca90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x11ca94: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x11ca94u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ca98: 0x240a0010  addiu       $t2, $zero, 0x10
    ctx->pc = 0x11ca98u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x11ca9c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11CA9Cu;
    SET_GPR_U32(ctx, 31, 0x11CAA4u);
    ctx->pc = 0x11CAA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CA9Cu;
            // 0x11caa0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CAA4u; }
        if (ctx->pc != 0x11CAA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CAA4u; }
        if (ctx->pc != 0x11CAA4u) { return; }
    }
    ctx->pc = 0x11CAA4u;
label_11caa4:
    // 0x11caa4: 0x3c04fffe  lui         $a0, 0xFFFE
    ctx->pc = 0x11caa4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65534 << 16));
    // 0x11caa8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x11caa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11caac: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x11caacu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x11cab0: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x11cab0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x11cab4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x11cab4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cab8: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x11cab8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_11cabc:
    // 0x11cabc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11cabcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11cac0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11cac0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11cac4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11cac4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11cac8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11cac8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11cacc: 0x3e00008  jr          $ra
    ctx->pc = 0x11CACCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CACCu;
            // 0x11cad0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C7B8u: goto label_11c7b8;
            case 0x11C7E8u: goto label_11c7e8;
            case 0x11C7F8u: goto label_11c7f8;
            case 0x11C80Cu: goto label_11c80c;
            case 0x11C824u: goto label_11c824;
            case 0x11C838u: goto label_11c838;
            case 0x11C868u: goto label_11c868;
            case 0x11C87Cu: goto label_11c87c;
            case 0x11C890u: goto label_11c890;
            case 0x11C89Cu: goto label_11c89c;
            case 0x11C8D0u: goto label_11c8d0;
            case 0x11C8FCu: goto label_11c8fc;
            case 0x11C930u: goto label_11c930;
            case 0x11C940u: goto label_11c940;
            case 0x11C980u: goto label_11c980;
            case 0x11C994u: goto label_11c994;
            case 0x11C9A8u: goto label_11c9a8;
            case 0x11C9BCu: goto label_11c9bc;
            case 0x11C9C4u: goto label_11c9c4;
            case 0x11C9D0u: goto label_11c9d0;
            case 0x11C9D4u: goto label_11c9d4;
            case 0x11C9D8u: goto label_11c9d8;
            case 0x11CA1Cu: goto label_11ca1c;
            case 0x11CA2Cu: goto label_11ca2c;
            case 0x11CA48u: goto label_11ca48;
            case 0x11CA60u: goto label_11ca60;
            case 0x11CA74u: goto label_11ca74;
            case 0x11CA78u: goto label_11ca78;
            case 0x11CAA4u: goto label_11caa4;
            case 0x11CABCu: goto label_11cabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CAD4u;
    // 0x11cad4: 0x0  nop
    ctx->pc = 0x11cad4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

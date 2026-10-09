#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011B660
// Address: 0x11b660 - 0x11b828
void sub_0011B660_0x11b660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011B660_0x11b660");
#endif

    switch (ctx->pc) {
        case 0x11b6a4u: goto label_11b6a4;
        case 0x11b6bcu: goto label_11b6bc;
        case 0x11b6e8u: goto label_11b6e8;
        case 0x11b74cu: goto label_11b74c;
        case 0x11b768u: goto label_11b768;
        case 0x11b7a4u: goto label_11b7a4;
        case 0x11b7b4u: goto label_11b7b4;
        case 0x11b7bcu: goto label_11b7bc;
        case 0x11b7d0u: goto label_11b7d0;
        case 0x11b7e0u: goto label_11b7e0;
        case 0x11b7f0u: goto label_11b7f0;
        case 0x11b7f8u: goto label_11b7f8;
        default: break;
    }

    ctx->pc = 0x11b660u;

    // 0x11b660: 0x27bdff30  addiu       $sp, $sp, -0xD0
    ctx->pc = 0x11b660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x11b664: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11b664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11b668: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11b668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11b66c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11b66cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b670: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11b670u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11b674: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x11b674u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b678: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x11b678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x11b67c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x11b67cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b680: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11b680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11b684: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x11b684u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x11b688: 0xffbf00c0  sd          $ra, 0xC0($sp)
    ctx->pc = 0x11b688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x11b68c: 0x3c170026  lui         $s7, 0x26
    ctx->pc = 0x11b68cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)38 << 16));
    // 0x11b690: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11b690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11b694: 0x26f2ca40  addiu       $s2, $s7, -0x35C0
    ctx->pc = 0x11b694u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x11b698: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11b698u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11b69c: 0xc04619c  jal         func_118670
    ctx->pc = 0x11B69Cu;
    SET_GPR_U32(ctx, 31, 0x11B6A4u);
    ctx->pc = 0x11B6A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B69Cu;
            // 0x11b6a0: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6A4u; }
        if (ctx->pc != 0x11B6A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6A4u; }
        if (ctx->pc != 0x11B6A4u) { return; }
    }
    ctx->pc = 0x11B6A4u;
label_11b6a4:
    // 0x11b6a4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11b6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11b6a8: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11b6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11b6ac: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11B6ACu;
    {
        const bool branch_taken_0x11b6ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b6ac) {
            ctx->pc = 0x11B6B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B6ACu;
            // 0x11b6b0: 0x92220000  lbu         $v0, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B6C0u;
            goto label_11b6c0;
        }
    }
    ctx->pc = 0x11B6B4u;
    // 0x11b6b4: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11B6B4u;
    SET_GPR_U32(ctx, 31, 0x11B6BCu);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6BCu; }
        if (ctx->pc != 0x11B6BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B6BCu; }
        if (ctx->pc != 0x11B6BCu) { return; }
    }
    ctx->pc = 0x11B6BCu;
label_11b6bc:
    // 0x11b6bc: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11b6bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_11b6c0:
    // 0x11b6c0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11b6c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b6c4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11b6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11b6c8: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x11B6C8u;
    {
        const bool branch_taken_0x11b6c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B6C8u;
            // 0x11b6cc: 0xa2420014  sb          $v0, 0x14($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 20), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b6c8) {
            ctx->pc = 0x11B714u;
            goto label_11b714;
        }
    }
    ctx->pc = 0x11B6D0u;
    // 0x11b6d0: 0x2e060400  sltiu       $a2, $s0, 0x400
    ctx->pc = 0x11b6d0u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b6d4: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b6d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b6d8: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11b6d8u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11b6dc: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b6dcu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11b6e0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b6e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x11b6e4: 0x0  nop
    ctx->pc = 0x11b6e4u;
    // NOP
label_11b6e8:
    // 0x11b6e8: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11b6e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b6ec: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x11B6ECu;
    {
        const bool branch_taken_0x11b6ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B6F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B6ECu;
            // 0x11b6f0: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b6ec) {
            ctx->pc = 0x11B724u;
            goto label_11b724;
        }
    }
    ctx->pc = 0x11B6F4u;
    // 0x11b6f4: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x11b6f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x11b6f8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b6f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b6fc: 0xa0830014  sb          $v1, 0x14($a0)
    ctx->pc = 0x11b6fcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 20), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b700: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11b700u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11b704: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B704u;
    {
        const bool branch_taken_0x11b704 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b704) {
            ctx->pc = 0x11B708u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B704u;
            // 0x11b708: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B6E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b6e8;
        }
    }
    ctx->pc = 0x11B70Cu;
    // 0x11b70c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B70Cu;
    {
        const bool branch_taken_0x11b70c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B70Cu;
            // 0x11b710: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b70c) {
            ctx->pc = 0x11B728u;
            goto label_11b728;
        }
    }
    ctx->pc = 0x11B714u;
label_11b714:
    // 0x11b714: 0x2e060400  sltiu       $a2, $s0, 0x400
    ctx->pc = 0x11b714u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b718: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b718u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b71c: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11b71cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11b720: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b720u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11b724:
    // 0x11b724: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11b724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11b728:
    // 0x11b728: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11B728u;
    {
        const bool branch_taken_0x11b728 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11b728) {
            ctx->pc = 0x11B72Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B728u;
            // 0x11b72c: 0xa2400413  sb          $zero, 0x413($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1043), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B730u;
            goto label_11b730;
        }
    }
    ctx->pc = 0x11B730u;
label_11b730:
    // 0x11b730: 0x240203ff  addiu       $v0, $zero, 0x3FF
    ctx->pc = 0x11b730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1023));
    // 0x11b734: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x11b734u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b738: 0x46800a  movz        $s0, $v0, $a2
    ctx->pc = 0x11b738u;
    if (GPR_U64(ctx, 6) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
    // 0x11b73c: 0xae550010  sw          $s5, 0x10($s2)
    ctx->pc = 0x11b73cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 21));
    // 0x11b740: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11b740u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b744: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11B744u;
    SET_GPR_U32(ctx, 31, 0x11B74Cu);
    ctx->pc = 0x11B748u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B744u;
            // 0x11b748: 0xae50000c  sw          $s0, 0xC($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B74Cu; }
        if (ctx->pc != 0x11B74Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B74Cu; }
        if (ctx->pc != 0x11B74Cu) { return; }
    }
    ctx->pc = 0x11B74Cu;
label_11b74c:
    // 0x11b74c: 0x2690d680  addiu       $s0, $s4, -0x2980
    ctx->pc = 0x11b74cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
    // 0x11b750: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11b750u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11b754: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11b754u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11b758: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11b758u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11b75c: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11b75cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11b760: 0xc045188  jal         func_114620
    ctx->pc = 0x11B760u;
    SET_GPR_U32(ctx, 31, 0x11B768u);
    ctx->pc = 0x11B764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B760u;
            // 0x11b764: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B768u; }
        if (ctx->pc != 0x11B768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B768u; }
        if (ctx->pc != 0x11B768u) { return; }
    }
    ctx->pc = 0x11B768u;
label_11b768:
    // 0x11b768: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11b768u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b76c: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11b76cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11b770: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11b770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b774: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x11b774u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x11b778: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11b778u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11b77c: 0x26c4e140  addiu       $a0, $s6, -0x1EC0
    ctx->pc = 0x11b77cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294959424));
    // 0x11b780: 0x26e7ca40  addiu       $a3, $s7, -0x35C0
    ctx->pc = 0x11b780u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x11b784: 0x24050019  addiu       $a1, $zero, 0x19
    ctx->pc = 0x11b784u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x11b788: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b788u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b78c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b78cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b790: 0x2408080c  addiu       $t0, $zero, 0x80C
    ctx->pc = 0x11b790u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2060));
    // 0x11b794: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11b794u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b798: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b798u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b79c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B79Cu;
    SET_GPR_U32(ctx, 31, 0x11B7A4u);
    ctx->pc = 0x11B7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B79Cu;
            // 0x11b7a0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7A4u; }
        if (ctx->pc != 0x11B7A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7A4u; }
        if (ctx->pc != 0x11B7A4u) { return; }
    }
    ctx->pc = 0x11B7A4u;
label_11b7a4:
    // 0x11b7a4: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B7A4u;
    {
        const bool branch_taken_0x11b7a4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B7A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7A4u;
            // 0x11b7a8: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b7a4) {
            ctx->pc = 0x11B7C4u;
            goto label_11b7c4;
        }
    }
    ctx->pc = 0x11B7ACu;
    // 0x11b7ac: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B7ACu;
    SET_GPR_U32(ctx, 31, 0x11B7B4u);
    ctx->pc = 0x11B7B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7ACu;
            // 0x11b7b0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7B4u; }
        if (ctx->pc != 0x11B7B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7B4u; }
        if (ctx->pc != 0x11B7B4u) { return; }
    }
    ctx->pc = 0x11B7B4u;
label_11b7b4:
    // 0x11b7b4: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B7B4u;
    SET_GPR_U32(ctx, 31, 0x11B7BCu);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7BCu; }
        if (ctx->pc != 0x11B7BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7BCu; }
        if (ctx->pc != 0x11B7BCu) { return; }
    }
    ctx->pc = 0x11B7BCu;
label_11b7bc:
    // 0x11b7bc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11B7BCu;
    {
        const bool branch_taken_0x11b7bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7BCu;
            // 0x11b7c0: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b7bc) {
            ctx->pc = 0x11B7FCu;
            goto label_11b7fc;
        }
    }
    ctx->pc = 0x11B7C4u;
label_11b7c4:
    // 0x11b7c4: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x11b7c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x11b7c8: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B7C8u;
    SET_GPR_U32(ctx, 31, 0x11B7D0u);
    ctx->pc = 0x11B7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7C8u;
            // 0x11b7cc: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7D0u; }
        if (ctx->pc != 0x11B7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7D0u; }
        if (ctx->pc != 0x11B7D0u) { return; }
    }
    ctx->pc = 0x11B7D0u;
label_11b7d0:
    // 0x11b7d0: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B7D0u;
    {
        const bool branch_taken_0x11b7d0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b7d0) {
            ctx->pc = 0x11B7E8u;
            goto label_11b7e8;
        }
    }
    ctx->pc = 0x11B7D8u;
    // 0x11b7d8: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B7D8u;
    SET_GPR_U32(ctx, 31, 0x11B7E0u);
    ctx->pc = 0x11B7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7D8u;
            // 0x11b7dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7E0u; }
        if (ctx->pc != 0x11B7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7E0u; }
        if (ctx->pc != 0x11B7E0u) { return; }
    }
    ctx->pc = 0x11B7E0u;
label_11b7e0:
    // 0x11b7e0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B7E0u;
    {
        const bool branch_taken_0x11b7e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7E0u;
            // 0x11b7e4: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b7e0) {
            ctx->pc = 0x11B7FCu;
            goto label_11b7fc;
        }
    }
    ctx->pc = 0x11B7E8u;
label_11b7e8:
    // 0x11b7e8: 0xc045198  jal         func_114660
    ctx->pc = 0x11B7E8u;
    SET_GPR_U32(ctx, 31, 0x11B7F0u);
    ctx->pc = 0x11B7ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7E8u;
            // 0x11b7ec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F0u; }
        if (ctx->pc != 0x11B7F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F0u; }
        if (ctx->pc != 0x11B7F0u) { return; }
    }
    ctx->pc = 0x11B7F0u;
label_11b7f0:
    // 0x11b7f0: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B7F0u;
    SET_GPR_U32(ctx, 31, 0x11B7F8u);
    ctx->pc = 0x11B7F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B7F0u;
            // 0x11b7f4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F8u; }
        if (ctx->pc != 0x11B7F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B7F8u; }
        if (ctx->pc != 0x11B7F8u) { return; }
    }
    ctx->pc = 0x11B7F8u;
label_11b7f8:
    // 0x11b7f8: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11b7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11b7fc:
    // 0x11b7fc: 0xdfbf00c0  ld          $ra, 0xC0($sp)
    ctx->pc = 0x11b7fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x11b800: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x11b800u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11b804: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11b804u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11b808: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11b808u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11b80c: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11b80cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11b810: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11b810u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11b814: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11b814u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11b818: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11b818u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11b81c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11b81cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11b820: 0x3e00008  jr          $ra
    ctx->pc = 0x11B820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B820u;
            // 0x11b824: 0x27bd00d0  addiu       $sp, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B6A4u: goto label_11b6a4;
            case 0x11B6BCu: goto label_11b6bc;
            case 0x11B6C0u: goto label_11b6c0;
            case 0x11B6E8u: goto label_11b6e8;
            case 0x11B714u: goto label_11b714;
            case 0x11B724u: goto label_11b724;
            case 0x11B728u: goto label_11b728;
            case 0x11B730u: goto label_11b730;
            case 0x11B74Cu: goto label_11b74c;
            case 0x11B768u: goto label_11b768;
            case 0x11B7A4u: goto label_11b7a4;
            case 0x11B7B4u: goto label_11b7b4;
            case 0x11B7BCu: goto label_11b7bc;
            case 0x11B7C4u: goto label_11b7c4;
            case 0x11B7D0u: goto label_11b7d0;
            case 0x11B7E0u: goto label_11b7e0;
            case 0x11B7E8u: goto label_11b7e8;
            case 0x11B7F0u: goto label_11b7f0;
            case 0x11B7F8u: goto label_11b7f8;
            case 0x11B7FCu: goto label_11b7fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B828u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

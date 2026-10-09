#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001154D0
// Address: 0x1154d0 - 0x115680
void sub_001154D0_0x1154d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001154D0_0x1154d0");
#endif

    switch (ctx->pc) {
        case 0x1154f8u: goto label_1154f8;
        case 0x115550u: goto label_115550;
        case 0x1155d0u: goto label_1155d0;
        case 0x115610u: goto label_115610;
        case 0x11566cu: goto label_11566c;
        default: break;
    }

    ctx->pc = 0x1154d0u;

    // 0x1154d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1154d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1154d4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1154d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1154d8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1154d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1154dc: 0x2403ffd1  addiu       $v1, $zero, -0x2F
    ctx->pc = 0x1154dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967249));
    // 0x1154e0: 0xc  syscall     0
    ctx->pc = 0x1154e0u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1154e4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1154e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1154e8: 0x12040005  beq         $s0, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1154E8u;
    {
        const bool branch_taken_0x1154e8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1154ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1154E8u;
            // 0x1154ec: 0x2e020100  sltiu       $v0, $s0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1154e8) {
            ctx->pc = 0x115500u;
            goto label_115500;
        }
    }
    ctx->pc = 0x1154F0u;
    // 0x1154f0: 0xc045158  jal         func_114560
    ctx->pc = 0x1154F0u;
    SET_GPR_U32(ctx, 31, 0x1154F8u);
    ctx->pc = 0x114560u;
    if (runtime->hasFunction(0x114560u)) {
        auto targetFn = runtime->lookupFunction(0x114560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154F8u; }
        if (ctx->pc != 0x1154F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114560_0x114560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154F8u; }
        if (ctx->pc != 0x1154F8u) { return; }
    }
    ctx->pc = 0x1154F8u;
label_1154f8:
    // 0x1154f8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1154F8u;
    {
        const bool branch_taken_0x1154f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1154FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1154F8u;
            // 0x1154fc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1154f8) {
            ctx->pc = 0x115558u;
            goto label_115558;
        }
    }
    ctx->pc = 0x115500u;
label_115500:
    // 0x115500: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x115500u;
    {
        const bool branch_taken_0x115500 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x115504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115500u;
            // 0x115504: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115500) {
            ctx->pc = 0x115514u;
            goto label_115514;
        }
    }
    ctx->pc = 0x115508u;
    // 0x115508: 0x8c439d38  lw          $v1, -0x62C8($v0)
    ctx->pc = 0x115508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942008)));
    // 0x11550c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11550Cu;
    {
        const bool branch_taken_0x11550c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x115510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11550Cu;
            // 0x115510: 0x3c030026  lui         $v1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11550c) {
            ctx->pc = 0x11551Cu;
            goto label_11551c;
        }
    }
    ctx->pc = 0x115514u;
label_115514:
    // 0x115514: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x115514u;
    {
        const bool branch_taken_0x115514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115514u;
            // 0x115518: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115514) {
            ctx->pc = 0x115554u;
            goto label_115554;
        }
    }
    ctx->pc = 0x11551Cu;
label_11551c:
    // 0x11551c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11551cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x115520: 0x2463a638  addiu       $v1, $v1, -0x59C8
    ctx->pc = 0x115520u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944312));
    // 0x115524: 0x8ca4a630  lw          $a0, -0x59D0($a1)
    ctx->pc = 0x115524u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294944304)));
    // 0x115528: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x115528u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x11552c: 0x304201ff  andi        $v0, $v0, 0x1FF
    ctx->pc = 0x11552cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x115530: 0x23040  sll         $a2, $v0, 1
    ctx->pc = 0x115530u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x115534: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x115534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x115538: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x115538u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x11553c: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x11553cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x115540: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x115540u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115544: 0xa0a00008  sb          $zero, 0x8($a1)
    ctx->pc = 0x115544u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 8), (uint8_t)GPR_U32(ctx, 0));
    // 0x115548: 0xc045194  jal         func_114650
    ctx->pc = 0x115548u;
    SET_GPR_U32(ctx, 31, 0x115550u);
    ctx->pc = 0x11554Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115548u;
            // 0x11554c: 0xa0700009  sb          $s0, 0x9($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 9), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115550u; }
        if (ctx->pc != 0x115550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115550u; }
        if (ctx->pc != 0x115550u) { return; }
    }
    ctx->pc = 0x115550u;
label_115550:
    // 0x115550: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x115550u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_115554:
    // 0x115554: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115554u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_115558:
    // 0x115558: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115558u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11555c: 0x3e00008  jr          $ra
    ctx->pc = 0x11555Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11555Cu;
            // 0x115560: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1154F8u: goto label_1154f8;
            case 0x115500u: goto label_115500;
            case 0x115514u: goto label_115514;
            case 0x11551Cu: goto label_11551c;
            case 0x115550u: goto label_115550;
            case 0x115554u: goto label_115554;
            case 0x115558u: goto label_115558;
            case 0x115590u: goto label_115590;
            case 0x115598u: goto label_115598;
            case 0x1155D0u: goto label_1155d0;
            case 0x1155D4u: goto label_1155d4;
            case 0x115610u: goto label_115610;
            case 0x115618u: goto label_115618;
            case 0x11562Cu: goto label_11562c;
            case 0x115634u: goto label_115634;
            case 0x11566Cu: goto label_11566c;
            case 0x115670u: goto label_115670;
            case 0x115674u: goto label_115674;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115564u;
    // 0x115564: 0x0  nop
    ctx->pc = 0x115564u;
    // NOP
    // 0x115568: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11556c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11556cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115570: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x115570u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115574: 0x2e020080  sltiu       $v0, $s0, 0x80
    ctx->pc = 0x115574u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x115578: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x115578u;
    {
        const bool branch_taken_0x115578 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11557Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115578u;
            // 0x11557c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115578) {
            ctx->pc = 0x115590u;
            goto label_115590;
        }
    }
    ctx->pc = 0x115580u;
    // 0x115580: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x115580u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x115584: 0x8c439d38  lw          $v1, -0x62C8($v0)
    ctx->pc = 0x115584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942008)));
    // 0x115588: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x115588u;
    {
        const bool branch_taken_0x115588 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x11558Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115588u;
            // 0x11558c: 0x3c030026  lui         $v1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115588) {
            ctx->pc = 0x115598u;
            goto label_115598;
        }
    }
    ctx->pc = 0x115590u;
label_115590:
    // 0x115590: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x115590u;
    {
        const bool branch_taken_0x115590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115590u;
            // 0x115594: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115590) {
            ctx->pc = 0x1155D4u;
            goto label_1155d4;
        }
    }
    ctx->pc = 0x115598u;
label_115598:
    // 0x115598: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x115598u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x11559c: 0x2463a638  addiu       $v1, $v1, -0x59C8
    ctx->pc = 0x11559cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944312));
    // 0x1155a0: 0x8ca4a630  lw          $a0, -0x59D0($a1)
    ctx->pc = 0x1155a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294944304)));
    // 0x1155a4: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1155a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1155a8: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1155a8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1155ac: 0x304201ff  andi        $v0, $v0, 0x1FF
    ctx->pc = 0x1155acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x1155b0: 0x23040  sll         $a2, $v0, 1
    ctx->pc = 0x1155b0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1155b4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1155b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1155b8: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x1155b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1155bc: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1155bcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1155c0: 0xa0a70008  sb          $a3, 0x8($a1)
    ctx->pc = 0x1155c0u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 8), (uint8_t)GPR_U32(ctx, 7));
    // 0x1155c4: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x1155c4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1155c8: 0xc045194  jal         func_114650
    ctx->pc = 0x1155C8u;
    SET_GPR_U32(ctx, 31, 0x1155D0u);
    ctx->pc = 0x1155CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1155C8u;
            // 0x1155cc: 0xa0700009  sb          $s0, 0x9($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 9), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1155D0u; }
        if (ctx->pc != 0x1155D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1155D0u; }
        if (ctx->pc != 0x1155D0u) { return; }
    }
    ctx->pc = 0x1155D0u;
label_1155d0:
    // 0x1155d0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1155d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1155d4:
    // 0x1155d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1155d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1155d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1155d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1155dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1155DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1155E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1155DCu;
            // 0x1155e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1154F8u: goto label_1154f8;
            case 0x115500u: goto label_115500;
            case 0x115514u: goto label_115514;
            case 0x11551Cu: goto label_11551c;
            case 0x115550u: goto label_115550;
            case 0x115554u: goto label_115554;
            case 0x115558u: goto label_115558;
            case 0x115590u: goto label_115590;
            case 0x115598u: goto label_115598;
            case 0x1155D0u: goto label_1155d0;
            case 0x1155D4u: goto label_1155d4;
            case 0x115610u: goto label_115610;
            case 0x115618u: goto label_115618;
            case 0x11562Cu: goto label_11562c;
            case 0x115634u: goto label_115634;
            case 0x11566Cu: goto label_11566c;
            case 0x115670u: goto label_115670;
            case 0x115674u: goto label_115674;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1155E4u;
    // 0x1155e4: 0x0  nop
    ctx->pc = 0x1155e4u;
    // NOP
    // 0x1155e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1155e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1155ec: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1155ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1155f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1155f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1155f4: 0x2403ffd1  addiu       $v1, $zero, -0x2F
    ctx->pc = 0x1155f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967249));
    // 0x1155f8: 0xc  syscall     0
    ctx->pc = 0x1155f8u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x1155fc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1155fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115600: 0x12040005  beq         $s0, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x115600u;
    {
        const bool branch_taken_0x115600 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x115604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115600u;
            // 0x115604: 0x2e020100  sltiu       $v0, $s0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x115600) {
            ctx->pc = 0x115618u;
            goto label_115618;
        }
    }
    ctx->pc = 0x115608u;
    // 0x115608: 0xc045168  jal         func_1145A0
    ctx->pc = 0x115608u;
    SET_GPR_U32(ctx, 31, 0x115610u);
    ctx->pc = 0x1145A0u;
    if (runtime->hasFunction(0x1145A0u)) {
        auto targetFn = runtime->lookupFunction(0x1145A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115610u; }
        if (ctx->pc != 0x115610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001145A0_0x1145a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115610u; }
        if (ctx->pc != 0x115610u) { return; }
    }
    ctx->pc = 0x115610u;
label_115610:
    // 0x115610: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x115610u;
    {
        const bool branch_taken_0x115610 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115610u;
            // 0x115614: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115610) {
            ctx->pc = 0x115674u;
            goto label_115674;
        }
    }
    ctx->pc = 0x115618u;
label_115618:
    // 0x115618: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x115618u;
    {
        const bool branch_taken_0x115618 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11561Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115618u;
            // 0x11561c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115618) {
            ctx->pc = 0x11562Cu;
            goto label_11562c;
        }
    }
    ctx->pc = 0x115620u;
    // 0x115620: 0x8c439d38  lw          $v1, -0x62C8($v0)
    ctx->pc = 0x115620u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942008)));
    // 0x115624: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x115624u;
    {
        const bool branch_taken_0x115624 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x115628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115624u;
            // 0x115628: 0x3c030026  lui         $v1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115624) {
            ctx->pc = 0x115634u;
            goto label_115634;
        }
    }
    ctx->pc = 0x11562Cu;
label_11562c:
    // 0x11562c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x11562Cu;
    {
        const bool branch_taken_0x11562c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11562Cu;
            // 0x115630: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11562c) {
            ctx->pc = 0x115670u;
            goto label_115670;
        }
    }
    ctx->pc = 0x115634u;
label_115634:
    // 0x115634: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x115634u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x115638: 0x2463a638  addiu       $v1, $v1, -0x59C8
    ctx->pc = 0x115638u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944312));
    // 0x11563c: 0x8ca4a630  lw          $a0, -0x59D0($a1)
    ctx->pc = 0x11563cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294944304)));
    // 0x115640: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x115640u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x115644: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x115644u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x115648: 0x304201ff  andi        $v0, $v0, 0x1FF
    ctx->pc = 0x115648u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)511);
    // 0x11564c: 0x23040  sll         $a2, $v0, 1
    ctx->pc = 0x11564cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x115650: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x115650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x115654: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x115654u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x115658: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x115658u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x11565c: 0xa0a70008  sb          $a3, 0x8($a1)
    ctx->pc = 0x11565cu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 8), (uint8_t)GPR_U32(ctx, 7));
    // 0x115660: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x115660u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115664: 0xc045194  jal         func_114650
    ctx->pc = 0x115664u;
    SET_GPR_U32(ctx, 31, 0x11566Cu);
    ctx->pc = 0x115668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115664u;
            // 0x115668: 0xa0700009  sb          $s0, 0x9($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 9), (uint8_t)GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11566Cu; }
        if (ctx->pc != 0x11566Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11566Cu; }
        if (ctx->pc != 0x11566Cu) { return; }
    }
    ctx->pc = 0x11566Cu;
label_11566c:
    // 0x11566c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11566cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_115670:
    // 0x115670: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115670u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_115674:
    // 0x115674: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115674u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115678: 0x3e00008  jr          $ra
    ctx->pc = 0x115678u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11567Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115678u;
            // 0x11567c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1154F8u: goto label_1154f8;
            case 0x115500u: goto label_115500;
            case 0x115514u: goto label_115514;
            case 0x11551Cu: goto label_11551c;
            case 0x115550u: goto label_115550;
            case 0x115554u: goto label_115554;
            case 0x115558u: goto label_115558;
            case 0x115590u: goto label_115590;
            case 0x115598u: goto label_115598;
            case 0x1155D0u: goto label_1155d0;
            case 0x1155D4u: goto label_1155d4;
            case 0x115610u: goto label_115610;
            case 0x115618u: goto label_115618;
            case 0x11562Cu: goto label_11562c;
            case 0x115634u: goto label_115634;
            case 0x11566Cu: goto label_11566c;
            case 0x115670u: goto label_115670;
            case 0x115674u: goto label_115674;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115680u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011B480
// Address: 0x11b480 - 0x11b660
void sub_0011B480_0x11b480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011B480_0x11b480");
#endif

    switch (ctx->pc) {
        case 0x11b4bcu: goto label_11b4bc;
        case 0x11b4d4u: goto label_11b4d4;
        case 0x11b4f8u: goto label_11b4f8;
        case 0x11b558u: goto label_11b558;
        case 0x11b5a4u: goto label_11b5a4;
        case 0x11b5e0u: goto label_11b5e0;
        case 0x11b5f0u: goto label_11b5f0;
        case 0x11b5f8u: goto label_11b5f8;
        case 0x11b60cu: goto label_11b60c;
        case 0x11b61cu: goto label_11b61c;
        case 0x11b62cu: goto label_11b62c;
        case 0x11b634u: goto label_11b634;
        default: break;
    }

    ctx->pc = 0x11b480u;

    // 0x11b480: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x11b480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x11b484: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11b484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11b488: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x11b488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11b48c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11b48cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b490: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11b490u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11b494: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11b494u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b498: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11b498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11b49c: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x11b49cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x11b4a0: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x11b4a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x11b4a4: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11b4a4u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11b4a8: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11b4a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11b4ac: 0x26d2ca40  addiu       $s2, $s6, -0x35C0
    ctx->pc = 0x11b4acu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11b4b0: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11b4b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11b4b4: 0xc04619c  jal         func_118670
    ctx->pc = 0x11B4B4u;
    SET_GPR_U32(ctx, 31, 0x11B4BCu);
    ctx->pc = 0x11B4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4B4u;
            // 0x11b4b8: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4BCu; }
        if (ctx->pc != 0x11B4BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4BCu; }
        if (ctx->pc != 0x11B4BCu) { return; }
    }
    ctx->pc = 0x11B4BCu;
label_11b4bc:
    // 0x11b4bc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11b4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11b4c0: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x11b4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x11b4c4: 0x54600004  bnel        $v1, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11B4C4u;
    {
        const bool branch_taken_0x11b4c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b4c4) {
            ctx->pc = 0x11B4C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4C4u;
            // 0x11b4c8: 0x92020000  lbu         $v0, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B4D8u;
            goto label_11b4d8;
        }
    }
    ctx->pc = 0x11B4CCu;
    // 0x11b4cc: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11B4CCu;
    SET_GPR_U32(ctx, 31, 0x11B4D4u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4D4u; }
        if (ctx->pc != 0x11B4D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B4D4u; }
        if (ctx->pc != 0x11B4D4u) { return; }
    }
    ctx->pc = 0x11B4D4u;
label_11b4d4:
    // 0x11b4d4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x11b4d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_11b4d8:
    // 0x11b4d8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11b4d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b4dc: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11b4dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11b4e0: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x11B4E0u;
    {
        const bool branch_taken_0x11b4e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4E0u;
            // 0x11b4e4: 0xa242000c  sb          $v0, 0xC($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 12), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b4e0) {
            ctx->pc = 0x11B524u;
            goto label_11b524;
        }
    }
    ctx->pc = 0x11B4E8u;
    // 0x11b4e8: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b4e8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b4ec: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11b4ecu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11b4f0: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b4f0u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x11b4f4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b4f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11b4f8:
    // 0x11b4f8: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11b4f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b4fc: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x11B4FCu;
    {
        const bool branch_taken_0x11b4fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B4FCu;
            // 0x11b500: 0x2051021  addu        $v0, $s0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b4fc) {
            ctx->pc = 0x11B530u;
            goto label_11b530;
        }
    }
    ctx->pc = 0x11B504u;
    // 0x11b504: 0x2452021  addu        $a0, $s2, $a1
    ctx->pc = 0x11b504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x11b508: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b508u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b50c: 0xa083000c  sb          $v1, 0xC($a0)
    ctx->pc = 0x11b50cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b510: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11b510u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11b514: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B514u;
    {
        const bool branch_taken_0x11b514 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b514) {
            ctx->pc = 0x11B518u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B514u;
            // 0x11b518: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B4F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b4f8;
        }
    }
    ctx->pc = 0x11B51Cu;
    // 0x11b51c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11B51Cu;
    {
        const bool branch_taken_0x11b51c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B51Cu;
            // 0x11b520: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b51c) {
            ctx->pc = 0x11B534u;
            goto label_11b534;
        }
    }
    ctx->pc = 0x11B524u;
label_11b524:
    // 0x11b524: 0x27b30030  addiu       $s3, $sp, 0x30
    ctx->pc = 0x11b524u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11b528: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11b528u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11b52c: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x11b52cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_11b530:
    // 0x11b530: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11b530u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11b534:
    // 0x11b534: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11B534u;
    {
        const bool branch_taken_0x11b534 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11b534) {
            ctx->pc = 0x11B538u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B534u;
            // 0x11b538: 0xa240040b  sb          $zero, 0x40B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1035), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B53Cu;
            goto label_11b53c;
        }
    }
    ctx->pc = 0x11B53Cu;
label_11b53c:
    // 0x11b53c: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x11b53cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11b540: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11b540u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b544: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x11b544u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x11b548: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x11B548u;
    {
        const bool branch_taken_0x11b548 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B548u;
            // 0x11b54c: 0xa242040c  sb          $v0, 0x40C($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1036), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b548) {
            ctx->pc = 0x11B57Cu;
            goto label_11b57c;
        }
    }
    ctx->pc = 0x11B550u;
    // 0x11b550: 0x2646040c  addiu       $a2, $s2, 0x40C
    ctx->pc = 0x11b550u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 1036));
    // 0x11b554: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x11b554u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_11b558:
    // 0x11b558: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x11b558u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11b55c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B55Cu;
    {
        const bool branch_taken_0x11b55c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B55Cu;
            // 0x11b560: 0x2251021  addu        $v0, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b55c) {
            ctx->pc = 0x11B57Cu;
            goto label_11b57c;
        }
    }
    ctx->pc = 0x11B564u;
    // 0x11b564: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x11b564u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x11b568: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11b568u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11b56c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x11b56cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x11b570: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x11b570u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x11b574: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11B574u;
    {
        const bool branch_taken_0x11b574 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b574) {
            ctx->pc = 0x11B578u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B574u;
            // 0x11b578: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B558u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11b558;
        }
    }
    ctx->pc = 0x11B57Cu;
label_11b57c:
    // 0x11b57c: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11b57cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x11b580: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x11B580u;
    {
        const bool branch_taken_0x11b580 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x11b580) {
            ctx->pc = 0x11B584u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11B580u;
            // 0x11b584: 0xa240080b  sb          $zero, 0x80B($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 2059), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11B588u;
            goto label_11b588;
        }
    }
    ctx->pc = 0x11B588u;
label_11b588:
    // 0x11b588: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11b588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11b58c: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11b58cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11b590: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11b590u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11b594: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11b594u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11b598: 0xafa00024  sw          $zero, 0x24($sp)
    ctx->pc = 0x11b598u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0x11b59c: 0xc045188  jal         func_114620
    ctx->pc = 0x11B59Cu;
    SET_GPR_U32(ctx, 31, 0x11B5A4u);
    ctx->pc = 0x11B5A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B59Cu;
            // 0x11b5a0: 0x2690d680  addiu       $s0, $s4, -0x2980 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5A4u; }
        if (ctx->pc != 0x11B5A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5A4u; }
        if (ctx->pc != 0x11B5A4u) { return; }
    }
    ctx->pc = 0x11B5A4u;
label_11b5a4:
    // 0x11b5a4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11b5a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b5a8: 0xae530004  sw          $s3, 0x4($s2)
    ctx->pc = 0x11b5a8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 19));
    // 0x11b5ac: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11b5acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b5b0: 0xae510000  sw          $s1, 0x0($s2)
    ctx->pc = 0x11b5b0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 17));
    // 0x11b5b4: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x11b5b4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x11b5b8: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11b5b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x11b5bc: 0x26c7ca40  addiu       $a3, $s6, -0x35C0
    ctx->pc = 0x11b5bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11b5c0: 0x24050018  addiu       $a1, $zero, 0x18
    ctx->pc = 0x11b5c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x11b5c4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11b5c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11b5c8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11b5c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b5cc: 0x2408080c  addiu       $t0, $zero, 0x80C
    ctx->pc = 0x11b5ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2060));
    // 0x11b5d0: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11b5d0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11b5d4: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11b5d4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11b5d8: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11B5D8u;
    SET_GPR_U32(ctx, 31, 0x11B5E0u);
    ctx->pc = 0x11B5DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5D8u;
            // 0x11b5dc: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5E0u; }
        if (ctx->pc != 0x11B5E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5E0u; }
        if (ctx->pc != 0x11B5E0u) { return; }
    }
    ctx->pc = 0x11B5E0u;
label_11b5e0:
    // 0x11b5e0: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11B5E0u;
    {
        const bool branch_taken_0x11b5e0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11B5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5E0u;
            // 0x11b5e4: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b5e0) {
            ctx->pc = 0x11B600u;
            goto label_11b600;
        }
    }
    ctx->pc = 0x11B5E8u;
    // 0x11b5e8: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B5E8u;
    SET_GPR_U32(ctx, 31, 0x11B5F0u);
    ctx->pc = 0x11B5ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5E8u;
            // 0x11b5ec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F0u; }
        if (ctx->pc != 0x11B5F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F0u; }
        if (ctx->pc != 0x11B5F0u) { return; }
    }
    ctx->pc = 0x11B5F0u;
label_11b5f0:
    // 0x11b5f0: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B5F0u;
    SET_GPR_U32(ctx, 31, 0x11B5F8u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F8u; }
        if (ctx->pc != 0x11B5F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B5F8u; }
        if (ctx->pc != 0x11B5F8u) { return; }
    }
    ctx->pc = 0x11B5F8u;
label_11b5f8:
    // 0x11b5f8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11B5F8u;
    {
        const bool branch_taken_0x11b5f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B5FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B5F8u;
            // 0x11b5fc: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b5f8) {
            ctx->pc = 0x11B638u;
            goto label_11b638;
        }
    }
    ctx->pc = 0x11B600u;
label_11b600:
    // 0x11b600: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x11b600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x11b604: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11B604u;
    SET_GPR_U32(ctx, 31, 0x11B60Cu);
    ctx->pc = 0x11B608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B604u;
            // 0x11b608: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B60Cu; }
        if (ctx->pc != 0x11B60Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B60Cu; }
        if (ctx->pc != 0x11B60Cu) { return; }
    }
    ctx->pc = 0x11B60Cu;
label_11b60c:
    // 0x11b60c: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11B60Cu;
    {
        const bool branch_taken_0x11b60c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11b60c) {
            ctx->pc = 0x11B624u;
            goto label_11b624;
        }
    }
    ctx->pc = 0x11B614u;
    // 0x11b614: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B614u;
    SET_GPR_U32(ctx, 31, 0x11B61Cu);
    ctx->pc = 0x11B618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B614u;
            // 0x11b618: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B61Cu; }
        if (ctx->pc != 0x11B61Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B61Cu; }
        if (ctx->pc != 0x11B61Cu) { return; }
    }
    ctx->pc = 0x11B61Cu;
label_11b61c:
    // 0x11b61c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11B61Cu;
    {
        const bool branch_taken_0x11b61c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11B620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B61Cu;
            // 0x11b620: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11b61c) {
            ctx->pc = 0x11B638u;
            goto label_11b638;
        }
    }
    ctx->pc = 0x11B624u;
label_11b624:
    // 0x11b624: 0xc045198  jal         func_114660
    ctx->pc = 0x11B624u;
    SET_GPR_U32(ctx, 31, 0x11B62Cu);
    ctx->pc = 0x11B628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B624u;
            // 0x11b628: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B62Cu; }
        if (ctx->pc != 0x11B62Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B62Cu; }
        if (ctx->pc != 0x11B62Cu) { return; }
    }
    ctx->pc = 0x11B62Cu;
label_11b62c:
    // 0x11b62c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11B62Cu;
    SET_GPR_U32(ctx, 31, 0x11B634u);
    ctx->pc = 0x11B630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11B62Cu;
            // 0x11b630: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B634u; }
        if (ctx->pc != 0x11B634u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11B634u; }
        if (ctx->pc != 0x11B634u) { return; }
    }
    ctx->pc = 0x11B634u;
label_11b634:
    // 0x11b634: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11b634u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11b638:
    // 0x11b638: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x11b638u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11b63c: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11b63cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11b640: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11b640u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11b644: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11b644u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11b648: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11b648u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11b64c: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11b64cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11b650: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11b650u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11b654: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11b654u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11b658: 0x3e00008  jr          $ra
    ctx->pc = 0x11B658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11B65Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11B658u;
            // 0x11b65c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11B4BCu: goto label_11b4bc;
            case 0x11B4D4u: goto label_11b4d4;
            case 0x11B4D8u: goto label_11b4d8;
            case 0x11B4F8u: goto label_11b4f8;
            case 0x11B524u: goto label_11b524;
            case 0x11B530u: goto label_11b530;
            case 0x11B534u: goto label_11b534;
            case 0x11B53Cu: goto label_11b53c;
            case 0x11B558u: goto label_11b558;
            case 0x11B57Cu: goto label_11b57c;
            case 0x11B588u: goto label_11b588;
            case 0x11B5A4u: goto label_11b5a4;
            case 0x11B5E0u: goto label_11b5e0;
            case 0x11B5F0u: goto label_11b5f0;
            case 0x11B5F8u: goto label_11b5f8;
            case 0x11B600u: goto label_11b600;
            case 0x11B60Cu: goto label_11b60c;
            case 0x11B61Cu: goto label_11b61c;
            case 0x11B624u: goto label_11b624;
            case 0x11B62Cu: goto label_11b62c;
            case 0x11B634u: goto label_11b634;
            case 0x11B638u: goto label_11b638;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11B660u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

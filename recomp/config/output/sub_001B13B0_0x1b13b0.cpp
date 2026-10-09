#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B13B0
// Address: 0x1b13b0 - 0x1b149c
void sub_001B13B0_0x1b13b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B13B0_0x1b13b0");
#endif

    switch (ctx->pc) {
        case 0x1b13d8u: goto label_1b13d8;
        case 0x1b1414u: goto label_1b1414;
        case 0x1b1424u: goto label_1b1424;
        case 0x1b144cu: goto label_1b144c;
        case 0x1b1454u: goto label_1b1454;
        case 0x1b1468u: goto label_1b1468;
        case 0x1b1470u: goto label_1b1470;
        case 0x1b147cu: goto label_1b147c;
        default: break;
    }

    ctx->pc = 0x1b13b0u;

    // 0x1b13b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b13b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b13b4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b13b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b13b8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b13b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b13bc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b13bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b13c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b13c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b13c4: 0x8c830808  lw          $v1, 0x808($a0)
    ctx->pc = 0x1b13c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 2056)));
    // 0x1b13c8: 0x1060002e  beqz        $v1, . + 4 + (0x2E << 2)
    ctx->pc = 0x1B13C8u;
    {
        const bool branch_taken_0x1b13c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B13CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B13C8u;
            // 0x1b13cc: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b13c8) {
            ctx->pc = 0x1B1484u;
            goto label_1b1484;
        }
    }
    ctx->pc = 0x1B13D0u;
    // 0x1b13d0: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1B13D0u;
    {
        const bool branch_taken_0x1b13d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B13D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B13D0u;
            // 0x1b13d4: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b13d0) {
            ctx->pc = 0x1B1434u;
            goto label_1b1434;
        }
    }
    ctx->pc = 0x1B13D8u;
label_1b13d8:
    // 0x1b13d8: 0x8e430808  lw          $v1, 0x808($s2)
    ctx->pc = 0x1b13d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
    // 0x1b13dc: 0x1110c0  sll         $v0, $s1, 3
    ctx->pc = 0x1b13dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1b13e0: 0x512021  addu        $a0, $v0, $s1
    ctx->pc = 0x1b13e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1b13e4: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1b13e4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b13e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b13e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b13ec: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1b13ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1b13f0: 0x480c0  sll         $s0, $a0, 3
    ctx->pc = 0x1b13f0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b13f4: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b13f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b13f8: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1b13f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b13fc: 0x1082000c  beq         $a0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1B13FCu;
    {
        const bool branch_taken_0x1b13fc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b13fc) {
            ctx->pc = 0x1B1430u;
            goto label_1b1430;
        }
    }
    ctx->pc = 0x1B1404u;
    // 0x1b1404: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B1404u;
    {
        const bool branch_taken_0x1b1404 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b1404) {
            ctx->pc = 0x1B1430u;
            goto label_1b1430;
        }
    }
    ctx->pc = 0x1B140Cu;
    // 0x1b140c: 0xc063128  jal         func_18C4A0
    ctx->pc = 0x1B140Cu;
    SET_GPR_U32(ctx, 31, 0x1B1414u);
    ctx->pc = 0x18C4A0u;
    if (runtime->hasFunction(0x18C4A0u)) {
        auto targetFn = runtime->lookupFunction(0x18C4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1414u; }
        if (ctx->pc != 0x1B1414u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C4A0_0x18c4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1414u; }
        if (ctx->pc != 0x1B1414u) { return; }
    }
    ctx->pc = 0x1B1414u;
label_1b1414:
    // 0x1b1414: 0x8e420808  lw          $v0, 0x808($s2)
    ctx->pc = 0x1b1414u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
    // 0x1b1418: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b1418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b141c: 0xc06c410  jal         func_1B1040
    ctx->pc = 0x1B141Cu;
    SET_GPR_U32(ctx, 31, 0x1B1424u);
    ctx->pc = 0x1B1420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B141Cu;
            // 0x1b1420: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1040u;
    if (runtime->hasFunction(0x1B1040u)) {
        auto targetFn = runtime->lookupFunction(0x1B1040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1424u; }
        if (ctx->pc != 0x1B1424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1040_0x1b1040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1424u; }
        if (ctx->pc != 0x1B1424u) { return; }
    }
    ctx->pc = 0x1B1424u;
label_1b1424:
    // 0x1b1424: 0x8e420808  lw          $v0, 0x808($s2)
    ctx->pc = 0x1b1424u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
    // 0x1b1428: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b1428u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b142c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1b142cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_1b1430:
    // 0x1b1430: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b1430u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b1434:
    // 0x1b1434: 0x96420812  lhu         $v0, 0x812($s2)
    ctx->pc = 0x1b1434u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2066)));
    // 0x1b1438: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1b1438u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1b143c: 0x1440ffe6  bnez        $v0, . + 4 + (-0x1A << 2)
    ctx->pc = 0x1B143Cu;
    {
        const bool branch_taken_0x1b143c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B143Cu;
            // 0x1b1440: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b143c) {
            ctx->pc = 0x1B13D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b13d8;
        }
    }
    ctx->pc = 0x1B1444u;
    // 0x1b1444: 0xc06c6a4  jal         func_1B1A90
    ctx->pc = 0x1B1444u;
    SET_GPR_U32(ctx, 31, 0x1B144Cu);
    ctx->pc = 0x1B1A90u;
    if (runtime->hasFunction(0x1B1A90u)) {
        auto targetFn = runtime->lookupFunction(0x1B1A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B144Cu; }
        if (ctx->pc != 0x1B144Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1A90_0x1b1a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B144Cu; }
        if (ctx->pc != 0x1B144Cu) { return; }
    }
    ctx->pc = 0x1B144Cu;
label_1b144c:
    // 0x1b144c: 0xc06c674  jal         func_1B19D0
    ctx->pc = 0x1B144Cu;
    SET_GPR_U32(ctx, 31, 0x1B1454u);
    ctx->pc = 0x1B1450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B144Cu;
            // 0x1b1450: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B19D0u;
    if (runtime->hasFunction(0x1B19D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B19D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1454u; }
        if (ctx->pc != 0x1B1454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B19D0_0x1b19d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1454u; }
        if (ctx->pc != 0x1B1454u) { return; }
    }
    ctx->pc = 0x1B1454u;
label_1b1454:
    // 0x1b1454: 0x8e44080c  lw          $a0, 0x80C($s2)
    ctx->pc = 0x1b1454u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2060)));
    // 0x1b1458: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B1458u;
    {
        const bool branch_taken_0x1b1458 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b1458) {
            ctx->pc = 0x1B1474u;
            goto label_1b1474;
        }
    }
    ctx->pc = 0x1B1460u;
    // 0x1b1460: 0xc064960  jal         func_192580
    ctx->pc = 0x1B1460u;
    SET_GPR_U32(ctx, 31, 0x1B1468u);
    ctx->pc = 0x192580u;
    if (runtime->hasFunction(0x192580u)) {
        auto targetFn = runtime->lookupFunction(0x192580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1468u; }
        if (ctx->pc != 0x1B1468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192580_0x192580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1468u; }
        if (ctx->pc != 0x1B1468u) { return; }
    }
    ctx->pc = 0x1B1468u;
label_1b1468:
    // 0x1b1468: 0xc06c444  jal         func_1B1110
    ctx->pc = 0x1B1468u;
    SET_GPR_U32(ctx, 31, 0x1B1470u);
    ctx->pc = 0x1B146Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1468u;
            // 0x1b146c: 0x8e44080c  lw          $a0, 0x80C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1110u;
    if (runtime->hasFunction(0x1B1110u)) {
        auto targetFn = runtime->lookupFunction(0x1B1110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1470u; }
        if (ctx->pc != 0x1B1470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1110_0x1b1110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1470u; }
        if (ctx->pc != 0x1B1470u) { return; }
    }
    ctx->pc = 0x1B1470u;
label_1b1470:
    // 0x1b1470: 0xae40080c  sw          $zero, 0x80C($s2)
    ctx->pc = 0x1b1470u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2060), GPR_U32(ctx, 0));
label_1b1474:
    // 0x1b1474: 0xc06cae4  jal         func_1B2B90
    ctx->pc = 0x1B1474u;
    SET_GPR_U32(ctx, 31, 0x1B147Cu);
    ctx->pc = 0x1B1478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1474u;
            // 0x1b1478: 0x8e440808  lw          $a0, 0x808($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2B90u;
    if (runtime->hasFunction(0x1B2B90u)) {
        auto targetFn = runtime->lookupFunction(0x1B2B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B147Cu; }
        if (ctx->pc != 0x1B147Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2B90_0x1b2b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B147Cu; }
        if (ctx->pc != 0x1B147Cu) { return; }
    }
    ctx->pc = 0x1B147Cu;
label_1b147c:
    // 0x1b147c: 0xae400808  sw          $zero, 0x808($s2)
    ctx->pc = 0x1b147cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2056), GPR_U32(ctx, 0));
    // 0x1b1480: 0xa6400812  sh          $zero, 0x812($s2)
    ctx->pc = 0x1b1480u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 2066), (uint16_t)GPR_U32(ctx, 0));
label_1b1484:
    // 0x1b1484: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b1484u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b1488: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b1488u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b148c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b148cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1490: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1490u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1494: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1494u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1494u;
            // 0x1b1498: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B13D8u: goto label_1b13d8;
            case 0x1B1414u: goto label_1b1414;
            case 0x1B1424u: goto label_1b1424;
            case 0x1B1430u: goto label_1b1430;
            case 0x1B1434u: goto label_1b1434;
            case 0x1B144Cu: goto label_1b144c;
            case 0x1B1454u: goto label_1b1454;
            case 0x1B1468u: goto label_1b1468;
            case 0x1B1470u: goto label_1b1470;
            case 0x1B1474u: goto label_1b1474;
            case 0x1B147Cu: goto label_1b147c;
            case 0x1B1484u: goto label_1b1484;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B149Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C13C0
// Address: 0x1c13c0 - 0x1c1578
void sub_001C13C0_0x1c13c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C13C0_0x1c13c0");
#endif

    switch (ctx->pc) {
        case 0x1c1408u: goto label_1c1408;
        case 0x1c1424u: goto label_1c1424;
        case 0x1c1430u: goto label_1c1430;
        case 0x1c143cu: goto label_1c143c;
        case 0x1c1448u: goto label_1c1448;
        case 0x1c1478u: goto label_1c1478;
        case 0x1c148cu: goto label_1c148c;
        case 0x1c14a0u: goto label_1c14a0;
        case 0x1c14bcu: goto label_1c14bc;
        case 0x1c14d0u: goto label_1c14d0;
        case 0x1c14e4u: goto label_1c14e4;
        case 0x1c14f8u: goto label_1c14f8;
        case 0x1c1530u: goto label_1c1530;
        case 0x1c1544u: goto label_1c1544;
        case 0x1c1560u: goto label_1c1560;
        default: break;
    }

    ctx->pc = 0x1c13c0u;

    // 0x1c13c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c13c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c13c4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1c13c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1c13c8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c13c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c13cc: 0x24635160  addiu       $v1, $v1, 0x5160
    ctx->pc = 0x1c13ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 20832));
    // 0x1c13d0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c13d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c13d4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c13d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c13d8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c13d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c13dc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c13dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c13e0: 0x8c8400a0  lw          $a0, 0xA0($a0)
    ctx->pc = 0x1c13e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 160)));
    // 0x1c13e4: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1c13e4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c13e8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1c13e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1c13ec: 0x8c710000  lw          $s1, 0x0($v1)
    ctx->pc = 0x1c13ecu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1c13f0: 0x8e23004c  lw          $v1, 0x4C($s1)
    ctx->pc = 0x1c13f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 76)));
    // 0x1c13f4: 0x10600040  beqz        $v1, . + 4 + (0x40 << 2)
    ctx->pc = 0x1C13F4u;
    {
        const bool branch_taken_0x1c13f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c13f4) {
            ctx->pc = 0x1C14F8u;
            goto label_1c14f8;
        }
    }
    ctx->pc = 0x1C13FCu;
    // 0x1c13fc: 0x8e320054  lw          $s2, 0x54($s1)
    ctx->pc = 0x1c13fcu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x1c1400: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1C1400u;
    SET_GPR_U32(ctx, 31, 0x1C1408u);
    ctx->pc = 0x1C1404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1400u;
            // 0x1c1404: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1408u; }
        if (ctx->pc != 0x1C1408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1408u; }
        if (ctx->pc != 0x1C1408u) { return; }
    }
    ctx->pc = 0x1C1408u;
label_1c1408:
    // 0x1c1408: 0xa6420006  sh          $v0, 0x6($s2)
    ctx->pc = 0x1c1408u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 6), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c140c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c140cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c1410: 0x8e260000  lw          $a2, 0x0($s1)
    ctx->pc = 0x1c1410u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c1414: 0x264400c0  addiu       $a0, $s2, 0xC0
    ctx->pc = 0x1c1414u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 192));
    // 0x1c1418: 0x8e270004  lw          $a3, 0x4($s1)
    ctx->pc = 0x1c1418u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1c141c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C141Cu;
    SET_GPR_U32(ctx, 31, 0x1C1424u);
    ctx->pc = 0x1C1420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C141Cu;
            // 0x1c1420: 0x24a50670  addiu       $a1, $a1, 0x670 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1648));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1424u; }
        if (ctx->pc != 0x1C1424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1424u; }
        if (ctx->pc != 0x1C1424u) { return; }
    }
    ctx->pc = 0x1C1424u;
label_1c1424:
    // 0x1c1424: 0x8e250020  lw          $a1, 0x20($s1)
    ctx->pc = 0x1c1424u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1c1428: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1C1428u;
    SET_GPR_U32(ctx, 31, 0x1C1430u);
    ctx->pc = 0x1C142Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1428u;
            // 0x1c142c: 0x26440104  addiu       $a0, $s2, 0x104 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 260));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1430u; }
        if (ctx->pc != 0x1C1430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1430u; }
        if (ctx->pc != 0x1C1430u) { return; }
    }
    ctx->pc = 0x1C1430u;
label_1c1430:
    // 0x1c1430: 0x8e250030  lw          $a1, 0x30($s1)
    ctx->pc = 0x1c1430u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x1c1434: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1C1434u;
    SET_GPR_U32(ctx, 31, 0x1C143Cu);
    ctx->pc = 0x1C1438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1434u;
            // 0x1c1438: 0x26440144  addiu       $a0, $s2, 0x144 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 324));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C143Cu; }
        if (ctx->pc != 0x1C143Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C143Cu; }
        if (ctx->pc != 0x1C143Cu) { return; }
    }
    ctx->pc = 0x1C143Cu;
label_1c143c:
    // 0x1c143c: 0x8e250040  lw          $a1, 0x40($s1)
    ctx->pc = 0x1c143cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x1c1440: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1C1440u;
    SET_GPR_U32(ctx, 31, 0x1C1448u);
    ctx->pc = 0x1C1444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1440u;
            // 0x1c1444: 0x26440184  addiu       $a0, $s2, 0x184 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 388));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1448u; }
        if (ctx->pc != 0x1C1448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1448u; }
        if (ctx->pc != 0x1C1448u) { return; }
    }
    ctx->pc = 0x1C1448u;
label_1c1448:
    // 0x1c1448: 0x8e0400a0  lw          $a0, 0xA0($s0)
    ctx->pc = 0x1c1448u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 160)));
    // 0x1c144c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c144cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1450: 0x10830015  beq         $a0, $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1C1450u;
    {
        const bool branch_taken_0x1c1450 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C1454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1450u;
            // 0x1c1454: 0x24060040  addiu       $a2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1450) {
            ctx->pc = 0x1C14A8u;
            goto label_1c14a8;
        }
    }
    ctx->pc = 0x1C1458u;
    // 0x1c1458: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1458u;
    {
        const bool branch_taken_0x1c1458 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C145Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1458u;
            // 0x1c145c: 0x3c050023  lui         $a1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1458) {
            ctx->pc = 0x1C1468u;
            goto label_1c1468;
        }
    }
    ctx->pc = 0x1C1460u;
    // 0x1c1460: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1C1460u;
    {
        const bool branch_taken_0x1c1460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1460u;
            // 0x1c1464: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1460) {
            ctx->pc = 0x1C14FCu;
            goto label_1c14fc;
        }
    }
    ctx->pc = 0x1C1468u;
label_1c1468:
    // 0x1c1468: 0x26440050  addiu       $a0, $s2, 0x50
    ctx->pc = 0x1c1468u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 80));
    // 0x1c146c: 0x24a551a0  addiu       $a1, $a1, 0x51A0
    ctx->pc = 0x1c146cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20896));
    // 0x1c1470: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C1470u;
    SET_GPR_U32(ctx, 31, 0x1C1478u);
    ctx->pc = 0x1C1474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1470u;
            // 0x1c1474: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1478u; }
        if (ctx->pc != 0x1C1478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1478u; }
        if (ctx->pc != 0x1C1478u) { return; }
    }
    ctx->pc = 0x1C1478u;
label_1c1478:
    // 0x1c1478: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1c1478u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1c147c: 0x26440080  addiu       $a0, $s2, 0x80
    ctx->pc = 0x1c147cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 128));
    // 0x1c1480: 0x24a551d0  addiu       $a1, $a1, 0x51D0
    ctx->pc = 0x1c1480u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20944));
    // 0x1c1484: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C1484u;
    SET_GPR_U32(ctx, 31, 0x1C148Cu);
    ctx->pc = 0x1C1488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1484u;
            // 0x1c1488: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C148Cu; }
        if (ctx->pc != 0x1C148Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C148Cu; }
        if (ctx->pc != 0x1C148Cu) { return; }
    }
    ctx->pc = 0x1C148Cu;
label_1c148c:
    // 0x1c148c: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1c148cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1c1490: 0x264400b0  addiu       $a0, $s2, 0xB0
    ctx->pc = 0x1c1490u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 176));
    // 0x1c1494: 0x24a55200  addiu       $a1, $a1, 0x5200
    ctx->pc = 0x1c1494u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20992));
    // 0x1c1498: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C1498u;
    SET_GPR_U32(ctx, 31, 0x1C14A0u);
    ctx->pc = 0x1C149Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1498u;
            // 0x1c149c: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14A0u; }
        if (ctx->pc != 0x1C14A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14A0u; }
        if (ctx->pc != 0x1C14A0u) { return; }
    }
    ctx->pc = 0x1C14A0u;
label_1c14a0:
    // 0x1c14a0: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1C14A0u;
    {
        const bool branch_taken_0x1c14a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c14a0) {
            ctx->pc = 0x1C14F8u;
            goto label_1c14f8;
        }
    }
    ctx->pc = 0x1C14A8u;
label_1c14a8:
    // 0x1c14a8: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1c14a8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1c14ac: 0x26440010  addiu       $a0, $s2, 0x10
    ctx->pc = 0x1c14acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x1c14b0: 0xae46000c  sw          $a2, 0xC($s2)
    ctx->pc = 0x1c14b0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 6));
    // 0x1c14b4: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C14B4u;
    SET_GPR_U32(ctx, 31, 0x1C14BCu);
    ctx->pc = 0x1C14B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C14B4u;
            // 0x1c14b8: 0x24a55210  addiu       $a1, $a1, 0x5210 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 21008));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14BCu; }
        if (ctx->pc != 0x1C14BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14BCu; }
        if (ctx->pc != 0x1C14BCu) { return; }
    }
    ctx->pc = 0x1C14BCu;
label_1c14bc:
    // 0x1c14bc: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1c14bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1c14c0: 0x26440050  addiu       $a0, $s2, 0x50
    ctx->pc = 0x1c14c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 80));
    // 0x1c14c4: 0x24a55250  addiu       $a1, $a1, 0x5250
    ctx->pc = 0x1c14c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 21072));
    // 0x1c14c8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C14C8u;
    SET_GPR_U32(ctx, 31, 0x1C14D0u);
    ctx->pc = 0x1C14CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C14C8u;
            // 0x1c14cc: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14D0u; }
        if (ctx->pc != 0x1C14D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14D0u; }
        if (ctx->pc != 0x1C14D0u) { return; }
    }
    ctx->pc = 0x1C14D0u;
label_1c14d0:
    // 0x1c14d0: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1c14d0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1c14d4: 0x26440080  addiu       $a0, $s2, 0x80
    ctx->pc = 0x1c14d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 128));
    // 0x1c14d8: 0x24a55280  addiu       $a1, $a1, 0x5280
    ctx->pc = 0x1c14d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 21120));
    // 0x1c14dc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C14DCu;
    SET_GPR_U32(ctx, 31, 0x1C14E4u);
    ctx->pc = 0x1C14E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C14DCu;
            // 0x1c14e0: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14E4u; }
        if (ctx->pc != 0x1C14E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14E4u; }
        if (ctx->pc != 0x1C14E4u) { return; }
    }
    ctx->pc = 0x1C14E4u;
label_1c14e4:
    // 0x1c14e4: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1c14e4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1c14e8: 0x264400b0  addiu       $a0, $s2, 0xB0
    ctx->pc = 0x1c14e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 176));
    // 0x1c14ec: 0x24a552b0  addiu       $a1, $a1, 0x52B0
    ctx->pc = 0x1c14ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 21168));
    // 0x1c14f0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C14F0u;
    SET_GPR_U32(ctx, 31, 0x1C14F8u);
    ctx->pc = 0x1C14F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C14F0u;
            // 0x1c14f4: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14F8u; }
        if (ctx->pc != 0x1C14F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C14F8u; }
        if (ctx->pc != 0x1C14F8u) { return; }
    }
    ctx->pc = 0x1C14F8u;
label_1c14f8:
    // 0x1c14f8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c14f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1c14fc:
    // 0x1c14fc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c14fcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1500: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c1500u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1504: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1504u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1508: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1508u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C150Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1508u;
            // 0x1c150c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1408u: goto label_1c1408;
            case 0x1C1424u: goto label_1c1424;
            case 0x1C1430u: goto label_1c1430;
            case 0x1C143Cu: goto label_1c143c;
            case 0x1C1448u: goto label_1c1448;
            case 0x1C1468u: goto label_1c1468;
            case 0x1C1478u: goto label_1c1478;
            case 0x1C148Cu: goto label_1c148c;
            case 0x1C14A0u: goto label_1c14a0;
            case 0x1C14A8u: goto label_1c14a8;
            case 0x1C14BCu: goto label_1c14bc;
            case 0x1C14D0u: goto label_1c14d0;
            case 0x1C14E4u: goto label_1c14e4;
            case 0x1C14F8u: goto label_1c14f8;
            case 0x1C14FCu: goto label_1c14fc;
            case 0x1C1530u: goto label_1c1530;
            case 0x1C1544u: goto label_1c1544;
            case 0x1C1548u: goto label_1c1548;
            case 0x1C1560u: goto label_1c1560;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1510u;
    // 0x1c1510: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c1510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c1514: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c1514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c1518: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c1518u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c151c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c151cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c1520: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1c1520u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1524: 0x3c100032  lui         $s0, 0x32
    ctx->pc = 0x1c1524u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)50 << 16));
    // 0x1c1528: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C1528u;
    {
        const bool branch_taken_0x1c1528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C152Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1528u;
            // 0x1c152c: 0x26106c50  addiu       $s0, $s0, 0x6C50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 27728));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1528) {
            ctx->pc = 0x1C1548u;
            goto label_1c1548;
        }
    }
    ctx->pc = 0x1C1530u;
label_1c1530:
    // 0x1c1530: 0x111880  sll         $v1, $s1, 2
    ctx->pc = 0x1c1530u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1c1534: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1c1534u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1c1538: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c153c: 0xc06038a  jal         func_180E28
    ctx->pc = 0x1C153Cu;
    SET_GPR_U32(ctx, 31, 0x1C1544u);
    ctx->pc = 0x1C1540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C153Cu;
            // 0x1c1540: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x180E28u;
    if (runtime->hasFunction(0x180E28u)) {
        auto targetFn = runtime->lookupFunction(0x180E28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1544u; }
        if (ctx->pc != 0x1C1544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180E28_0x180e28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1544u; }
        if (ctx->pc != 0x1C1544u) { return; }
    }
    ctx->pc = 0x1C1544u;
label_1c1544:
    // 0x1c1544: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c1544u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1c1548:
    // 0x1c1548: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c1548u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c154c: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1c154cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c1550: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1C1550u;
    {
        const bool branch_taken_0x1c1550 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1550u;
            // 0x1c1554: 0x3c020032  lui         $v0, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1550) {
            ctx->pc = 0x1C1530u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c1530;
        }
    }
    ctx->pc = 0x1C1558u;
    // 0x1c1558: 0xc060334  jal         func_180CD0
    ctx->pc = 0x1C1558u;
    SET_GPR_U32(ctx, 31, 0x1C1560u);
    ctx->pc = 0x180CD0u;
    if (runtime->hasFunction(0x180CD0u)) {
        auto targetFn = runtime->lookupFunction(0x180CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1560u; }
        if (ctx->pc != 0x1C1560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00180CD0_0x180cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1560u; }
        if (ctx->pc != 0x1C1560u) { return; }
    }
    ctx->pc = 0x1C1560u;
label_1c1560:
    // 0x1c1560: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c1560u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1564: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c1564u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1568: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1568u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c156c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C156Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C156Cu;
            // 0x1c1570: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1408u: goto label_1c1408;
            case 0x1C1424u: goto label_1c1424;
            case 0x1C1430u: goto label_1c1430;
            case 0x1C143Cu: goto label_1c143c;
            case 0x1C1448u: goto label_1c1448;
            case 0x1C1468u: goto label_1c1468;
            case 0x1C1478u: goto label_1c1478;
            case 0x1C148Cu: goto label_1c148c;
            case 0x1C14A0u: goto label_1c14a0;
            case 0x1C14A8u: goto label_1c14a8;
            case 0x1C14BCu: goto label_1c14bc;
            case 0x1C14D0u: goto label_1c14d0;
            case 0x1C14E4u: goto label_1c14e4;
            case 0x1C14F8u: goto label_1c14f8;
            case 0x1C14FCu: goto label_1c14fc;
            case 0x1C1530u: goto label_1c1530;
            case 0x1C1544u: goto label_1c1544;
            case 0x1C1548u: goto label_1c1548;
            case 0x1C1560u: goto label_1c1560;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1574u;
    // 0x1c1574: 0x0  nop
    ctx->pc = 0x1c1574u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

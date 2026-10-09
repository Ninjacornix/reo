#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D13F0
// Address: 0x1d13f0 - 0x1d14f8
void sub_001D13F0_0x1d13f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D13F0_0x1d13f0");
#endif

    switch (ctx->pc) {
        case 0x1d141cu: goto label_1d141c;
        case 0x1d1428u: goto label_1d1428;
        case 0x1d1434u: goto label_1d1434;
        case 0x1d1440u: goto label_1d1440;
        case 0x1d144cu: goto label_1d144c;
        case 0x1d1458u: goto label_1d1458;
        case 0x1d1464u: goto label_1d1464;
        case 0x1d1470u: goto label_1d1470;
        case 0x1d147cu: goto label_1d147c;
        case 0x1d148cu: goto label_1d148c;
        case 0x1d14c4u: goto label_1d14c4;
        case 0x1d14dcu: goto label_1d14dc;
        default: break;
    }

    ctx->pc = 0x1d13f0u;

    // 0x1d13f0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d13f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d13f4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d13f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d13f8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d13f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d13fc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d13fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d1400: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d1400u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1404: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d1404u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1408: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1408u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d140c: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x1d140cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d1410: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x1d1410u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x1d1414: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D1414u;
    SET_GPR_U32(ctx, 31, 0x1D141Cu);
    ctx->pc = 0x1D1418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1414u;
            // 0x1d1418: 0x24443000  addiu       $a0, $v0, 0x3000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D141Cu; }
        if (ctx->pc != 0x1D141Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D141Cu; }
        if (ctx->pc != 0x1D141Cu) { return; }
    }
    ctx->pc = 0x1D141Cu;
label_1d141c:
    // 0x1d141c: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d141cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d1420: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1420u;
    SET_GPR_U32(ctx, 31, 0x1D1428u);
    ctx->pc = 0x1D1424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1420u;
            // 0x1d1424: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1428u; }
        if (ctx->pc != 0x1D1428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1428u; }
        if (ctx->pc != 0x1D1428u) { return; }
    }
    ctx->pc = 0x1D1428u;
label_1d1428:
    // 0x1d1428: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d1428u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d142c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D142Cu;
    SET_GPR_U32(ctx, 31, 0x1D1434u);
    ctx->pc = 0x1D1430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D142Cu;
            // 0x1d1430: 0x24050800  addiu       $a1, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1434u; }
        if (ctx->pc != 0x1D1434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1434u; }
        if (ctx->pc != 0x1D1434u) { return; }
    }
    ctx->pc = 0x1D1434u;
label_1d1434:
    // 0x1d1434: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1434u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1438: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1438u;
    SET_GPR_U32(ctx, 31, 0x1D1440u);
    ctx->pc = 0x1D143Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1438u;
            // 0x1d143c: 0x34058000  ori         $a1, $zero, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1440u; }
        if (ctx->pc != 0x1D1440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1440u; }
        if (ctx->pc != 0x1D1440u) { return; }
    }
    ctx->pc = 0x1D1440u;
label_1d1440:
    // 0x1d1440: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d1440u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d1444: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1444u;
    SET_GPR_U32(ctx, 31, 0x1D144Cu);
    ctx->pc = 0x1D1448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1444u;
            // 0x1d1448: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D144Cu; }
        if (ctx->pc != 0x1D144Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D144Cu; }
        if (ctx->pc != 0x1D144Cu) { return; }
    }
    ctx->pc = 0x1D144Cu;
label_1d144c:
    // 0x1d144c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d144cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d1450: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1450u;
    SET_GPR_U32(ctx, 31, 0x1D1458u);
    ctx->pc = 0x1D1454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1450u;
            // 0x1d1454: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1458u; }
        if (ctx->pc != 0x1D1458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1458u; }
        if (ctx->pc != 0x1D1458u) { return; }
    }
    ctx->pc = 0x1D1458u;
label_1d1458:
    // 0x1d1458: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d1458u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d145c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D145Cu;
    SET_GPR_U32(ctx, 31, 0x1D1464u);
    ctx->pc = 0x1D1460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D145Cu;
            // 0x1d1460: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1464u; }
        if (ctx->pc != 0x1D1464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1464u; }
        if (ctx->pc != 0x1D1464u) { return; }
    }
    ctx->pc = 0x1D1464u;
label_1d1464:
    // 0x1d1464: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d1464u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d1468: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1468u;
    SET_GPR_U32(ctx, 31, 0x1D1470u);
    ctx->pc = 0x1D146Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1468u;
            // 0x1d146c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1470u; }
        if (ctx->pc != 0x1D1470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1470u; }
        if (ctx->pc != 0x1D1470u) { return; }
    }
    ctx->pc = 0x1D1470u;
label_1d1470:
    // 0x1d1470: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d1470u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1474: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1474u;
    SET_GPR_U32(ctx, 31, 0x1D147Cu);
    ctx->pc = 0x1D1478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1474u;
            // 0x1d1478: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D147Cu; }
        if (ctx->pc != 0x1D147Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D147Cu; }
        if (ctx->pc != 0x1D147Cu) { return; }
    }
    ctx->pc = 0x1D147Cu;
label_1d147c:
    // 0x1d147c: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1d147cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d1480: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x1d1480u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1d1484: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D1484u;
    SET_GPR_U32(ctx, 31, 0x1D148Cu);
    ctx->pc = 0x1D1488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1484u;
            // 0x1d1488: 0x26710070  addiu       $s1, $s3, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D148Cu; }
        if (ctx->pc != 0x1D148Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D148Cu; }
        if (ctx->pc != 0x1D148Cu) { return; }
    }
    ctx->pc = 0x1D148Cu;
label_1d148c:
    // 0x1d148c: 0xae220808  sw          $v0, 0x808($s1)
    ctx->pc = 0x1d148cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2056), GPR_U32(ctx, 2));
    // 0x1d1490: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1490u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1494: 0x26620890  addiu       $v0, $s3, 0x890
    ctx->pc = 0x1d1494u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2192));
    // 0x1d1498: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d1498u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d149c: 0x26620910  addiu       $v0, $s3, 0x910
    ctx->pc = 0x1d149cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 2320));
    // 0x1d14a0: 0xae220818  sw          $v0, 0x818($s1)
    ctx->pc = 0x1d14a0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2072), GPR_U32(ctx, 2));
    // 0x1d14a4: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d14a4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d14a8: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D14A8u;
    {
        const bool branch_taken_0x1d14a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D14ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14A8u;
            // 0x1d14ac: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d14a8) {
            ctx->pc = 0x1D14CCu;
            goto label_1d14cc;
        }
    }
    ctx->pc = 0x1D14B0u;
    // 0x1d14b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d14b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14b4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1d14b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14b8: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d14b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d14bc: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D14BCu;
    SET_GPR_U32(ctx, 31, 0x1D14C4u);
    ctx->pc = 0x1D14C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14BCu;
            // 0x1d14c0: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14C4u; }
        if (ctx->pc != 0x1D14C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14C4u; }
        if (ctx->pc != 0x1D14C4u) { return; }
    }
    ctx->pc = 0x1D14C4u;
label_1d14c4:
    // 0x1d14c4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D14C4u;
    {
        const bool branch_taken_0x1d14c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D14C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14C4u;
            // 0x1d14c8: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d14c4) {
            ctx->pc = 0x1D14E0u;
            goto label_1d14e0;
        }
    }
    ctx->pc = 0x1D14CCu;
label_1d14cc:
    // 0x1d14cc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d14ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14d0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d14d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d14d4: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D14D4u;
    SET_GPR_U32(ctx, 31, 0x1D14DCu);
    ctx->pc = 0x1D14D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14D4u;
            // 0x1d14d8: 0x24070003  addiu       $a3, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14DCu; }
        if (ctx->pc != 0x1D14DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D14DCu; }
        if (ctx->pc != 0x1D14DCu) { return; }
    }
    ctx->pc = 0x1D14DCu;
label_1d14dc:
    // 0x1d14dc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d14dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1d14e0:
    // 0x1d14e0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d14e0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d14e4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d14e4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d14e8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d14e8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d14ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d14ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d14f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D14F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D14F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D14F0u;
            // 0x1d14f4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D141Cu: goto label_1d141c;
            case 0x1D1428u: goto label_1d1428;
            case 0x1D1434u: goto label_1d1434;
            case 0x1D1440u: goto label_1d1440;
            case 0x1D144Cu: goto label_1d144c;
            case 0x1D1458u: goto label_1d1458;
            case 0x1D1464u: goto label_1d1464;
            case 0x1D1470u: goto label_1d1470;
            case 0x1D147Cu: goto label_1d147c;
            case 0x1D148Cu: goto label_1d148c;
            case 0x1D14C4u: goto label_1d14c4;
            case 0x1D14CCu: goto label_1d14cc;
            case 0x1D14DCu: goto label_1d14dc;
            case 0x1D14E0u: goto label_1d14e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D14F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001010A8
// Address: 0x1010a8 - 0x101388
void sub_001010A8_0x1010a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001010A8_0x1010a8");
#endif

    switch (ctx->pc) {
        case 0x1010e0u: goto label_1010e0;
        case 0x1010f4u: goto label_1010f4;
        case 0x1010fcu: goto label_1010fc;
        case 0x101170u: goto label_101170;
        case 0x101184u: goto label_101184;
        case 0x1011a4u: goto label_1011a4;
        case 0x1011b0u: goto label_1011b0;
        case 0x1011ecu: goto label_1011ec;
        case 0x101218u: goto label_101218;
        case 0x101238u: goto label_101238;
        case 0x101318u: goto label_101318;
        case 0x101320u: goto label_101320;
        case 0x10134cu: goto label_10134c;
        case 0x101354u: goto label_101354;
        default: break;
    }

    ctx->pc = 0x1010a8u;

    // 0x1010a8: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1010a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1010ac: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1010acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1010b0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1010b0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1010b4: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x1010b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x1010b8: 0xffbe0090  sd          $fp, 0x90($sp)
    ctx->pc = 0x1010b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x1010bc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1010bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1010c0: 0xffb70080  sd          $s7, 0x80($sp)
    ctx->pc = 0x1010c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x1010c4: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x1010c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x1010c8: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x1010c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1010cc: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x1010ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x1010d0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1010d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1010d4: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1010d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1010d8: 0xc040386  jal         func_100E18
    ctx->pc = 0x1010D8u;
    SET_GPR_U32(ctx, 31, 0x1010E0u);
    ctx->pc = 0x1010DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1010D8u;
            // 0x1010dc: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100E18u;
    if (runtime->hasFunction(0x100E18u)) {
        auto targetFn = runtime->lookupFunction(0x100E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010E0u; }
        if (ctx->pc != 0x1010E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E18_0x100e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010E0u; }
        if (ctx->pc != 0x1010E0u) { return; }
    }
    ctx->pc = 0x1010E0u;
label_1010e0:
    // 0x1010e0: 0x1440009d  bnez        $v0, . + 4 + (0x9D << 2)
    ctx->pc = 0x1010E0u;
    {
        const bool branch_taken_0x1010e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1010E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1010E0u;
            // 0x1010e4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1010e0) {
            ctx->pc = 0x101358u;
            goto label_101358;
        }
    }
    ctx->pc = 0x1010E8u;
    // 0x1010e8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1010e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1010ec: 0xc045c20  jal         func_117080
    ctx->pc = 0x1010ECu;
    SET_GPR_U32(ctx, 31, 0x1010F4u);
    ctx->pc = 0x1010F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1010ECu;
            // 0x1010f0: 0x3c150020  lui         $s5, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010F4u; }
        if (ctx->pc != 0x1010F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010F4u; }
        if (ctx->pc != 0x1010F4u) { return; }
    }
    ctx->pc = 0x1010F4u;
label_1010f4:
    // 0x1010f4: 0xc045144  jal         func_114510
    ctx->pc = 0x1010F4u;
    SET_GPR_U32(ctx, 31, 0x1010FCu);
    ctx->pc = 0x1010F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1010F4u;
            // 0x1010f8: 0x3c140020  lui         $s4, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010FCu; }
        if (ctx->pc != 0x1010FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1010FCu; }
        if (ctx->pc != 0x1010FCu) { return; }
    }
    ctx->pc = 0x1010FCu;
label_1010fc:
    // 0x1010fc: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1010fcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x101100: 0x8ea57954  lw          $a1, 0x7954($s5)
    ctx->pc = 0x101100u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 31060)));
    // 0x101104: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x101104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101108: 0x3c040020  lui         $a0, 0x20
    ctx->pc = 0x101108u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32 << 16));
    // 0x10110c: 0x3c060026  lui         $a2, 0x26
    ctx->pc = 0x10110cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)38 << 16));
    // 0x101110: 0xac837924  sw          $v1, 0x7924($a0)
    ctx->pc = 0x101110u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 31012), GPR_U32(ctx, 3));
    // 0x101114: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x101114u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x101118: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x101118u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10111c: 0x3c070020  lui         $a3, 0x20
    ctx->pc = 0x10111cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)32 << 16));
    // 0x101120: 0x3c080020  lui         $t0, 0x20
    ctx->pc = 0x101120u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32 << 16));
    // 0x101124: 0x3c090020  lui         $t1, 0x20
    ctx->pc = 0x101124u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32 << 16));
    // 0x101128: 0x3c0b0020  lui         $t3, 0x20
    ctx->pc = 0x101128u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)32 << 16));
    // 0x10112c: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x10112cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x101130: 0x3c0a0020  lui         $t2, 0x20
    ctx->pc = 0x101130u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)32 << 16));
    // 0x101134: 0xacc29f98  sw          $v0, -0x6068($a2)
    ctx->pc = 0x101134u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294942616), GPR_U32(ctx, 2));
    // 0x101138: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x101138u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x10113c: 0xac647940  sw          $a0, 0x7940($v1)
    ctx->pc = 0x10113cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31040), GPR_U32(ctx, 4));
    // 0x101140: 0xace47944  sw          $a0, 0x7944($a3)
    ctx->pc = 0x101140u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 31044), GPR_U32(ctx, 4));
    // 0x101144: 0x2451a1a8  addiu       $s1, $v0, -0x5E58
    ctx->pc = 0x101144u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294943144));
    // 0x101148: 0xad04793c  sw          $a0, 0x793C($t0)
    ctx->pc = 0x101148u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 31036), GPR_U32(ctx, 4));
    // 0x10114c: 0x2612a200  addiu       $s2, $s0, -0x5E00
    ctx->pc = 0x10114cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 4294943232));
    // 0x101150: 0xad24794c  sw          $a0, 0x794C($t1)
    ctx->pc = 0x101150u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 31052), GPR_U32(ctx, 4));
    // 0x101154: 0x3c1e0021  lui         $fp, 0x21
    ctx->pc = 0x101154u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)33 << 16));
    // 0x101158: 0xad647948  sw          $a0, 0x7948($t3)
    ctx->pc = 0x101158u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 31048), GPR_U32(ctx, 4));
    // 0x10115c: 0x3c170020  lui         $s7, 0x20
    ctx->pc = 0x10115cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)32 << 16));
    // 0x101160: 0xad407938  sw          $zero, 0x7938($t2)
    ctx->pc = 0x101160u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 31032), GPR_U32(ctx, 0));
    // 0x101164: 0x3c160023  lui         $s6, 0x23
    ctx->pc = 0x101164u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)35 << 16));
    // 0x101168: 0xaea57954  sw          $a1, 0x7954($s5)
    ctx->pc = 0x101168u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 31060), GPR_U32(ctx, 5));
    // 0x10116c: 0xae847950  sw          $a0, 0x7950($s4)
    ctx->pc = 0x10116cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 31056), GPR_U32(ctx, 4));
label_101170:
    // 0x101170: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x101170u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x101174: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x101174u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101178: 0x34a50592  ori         $a1, $a1, 0x592
    ctx->pc = 0x101178u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1426);
    // 0x10117c: 0xc045e06  jal         func_117818
    ctx->pc = 0x10117Cu;
    SET_GPR_U32(ctx, 31, 0x101184u);
    ctx->pc = 0x101180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10117Cu;
            // 0x101180: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101184u; }
        if (ctx->pc != 0x101184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101184u; }
        if (ctx->pc != 0x101184u) { return; }
    }
    ctx->pc = 0x101184u;
label_101184:
    // 0x101184: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x101184u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101188: 0x4a30012  bgezl       $a1, . + 4 + (0x12 << 2)
    ctx->pc = 0x101188u;
    {
        const bool branch_taken_0x101188 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x101188) {
            ctx->pc = 0x10118Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x101188u;
            // 0x10118c: 0x8e220024  lw          $v0, 0x24($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1011D4u;
            goto label_1011d4;
        }
    }
    ctx->pc = 0x101190u;
    // 0x101190: 0x8ee27910  lw          $v0, 0x7910($s7)
    ctx->pc = 0x101190u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 30992)));
    // 0x101194: 0x18400003  blez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101194u;
    {
        const bool branch_taken_0x101194 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x101198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101194u;
            // 0x101198: 0x8ea67954  lw          $a2, 0x7954($s5) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 31060)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101194) {
            ctx->pc = 0x1011A4u;
            goto label_1011a4;
        }
    }
    ctx->pc = 0x10119Cu;
    // 0x10119c: 0xc045a12  jal         func_116848
    ctx->pc = 0x10119Cu;
    SET_GPR_U32(ctx, 31, 0x1011A4u);
    ctx->pc = 0x1011A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10119Cu;
            // 0x1011a0: 0x26c475b8  addiu       $a0, $s6, 0x75B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 30136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1011A4u; }
        if (ctx->pc != 0x1011A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1011A4u; }
        if (ctx->pc != 0x1011A4u) { return; }
    }
    ctx->pc = 0x1011A4u;
label_1011a4:
    // 0x1011a4: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1011a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1011a8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1011a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1011ac: 0x0  nop
    ctx->pc = 0x1011acu;
    // NOP
label_1011b0:
    // 0x1011b0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1011b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1011b4: 0x0  nop
    ctx->pc = 0x1011b4u;
    // NOP
    // 0x1011b8: 0x0  nop
    ctx->pc = 0x1011b8u;
    // NOP
    // 0x1011bc: 0x0  nop
    ctx->pc = 0x1011bcu;
    // NOP
    // 0x1011c0: 0x0  nop
    ctx->pc = 0x1011c0u;
    // NOP
    // 0x1011c4: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1011C4u;
    {
        const bool branch_taken_0x1011c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1011c4) {
            ctx->pc = 0x1011B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1011b0;
        }
    }
    ctx->pc = 0x1011CCu;
    // 0x1011cc: 0x1000ffe8  b           . + 4 + (-0x18 << 2)
    ctx->pc = 0x1011CCu;
    {
        const bool branch_taken_0x1011cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1011cc) {
            ctx->pc = 0x101170u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101170;
        }
    }
    ctx->pc = 0x1011D4u;
label_1011d4:
    // 0x1011d4: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1011D4u;
    {
        const bool branch_taken_0x1011d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1011D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1011D4u;
            // 0x1011d8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1011d4) {
            ctx->pc = 0x10122Cu;
            goto label_10122c;
        }
    }
    ctx->pc = 0x1011DCu;
    // 0x1011dc: 0xae13a200  sw          $s3, -0x5E00($s0)
    ctx->pc = 0x1011dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294943232), GPR_U32(ctx, 19));
    // 0x1011e0: 0xae807950  sw          $zero, 0x7950($s4)
    ctx->pc = 0x1011e0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 31056), GPR_U32(ctx, 0));
    // 0x1011e4: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x1011E4u;
    SET_GPR_U32(ctx, 31, 0x1011ECu);
    ctx->pc = 0x1011E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1011E4u;
            // 0x1011e8: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1011ECu; }
        if (ctx->pc != 0x1011ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1011ECu; }
        if (ctx->pc != 0x1011ECu) { return; }
    }
    ctx->pc = 0x1011ECu;
label_1011ec:
    // 0x1011ec: 0x27d08b00  addiu       $s0, $fp, -0x7500
    ctx->pc = 0x1011ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 30), 4294937344));
    // 0x1011f0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1011f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1011f4: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1011f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1011f8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1011f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1011fc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1011fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101200: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x101200u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101204: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x101204u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x101208: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x101208u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10120c: 0x240a0010  addiu       $t2, $zero, 0x10
    ctx->pc = 0x10120cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x101210: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x101210u;
    SET_GPR_U32(ctx, 31, 0x101218u);
    ctx->pc = 0x101214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101210u;
            // 0x101214: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101218u; }
        if (ctx->pc != 0x101218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101218u; }
        if (ctx->pc != 0x101218u) { return; }
    }
    ctx->pc = 0x101218u;
label_101218:
    // 0x101218: 0x4410010  bgez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x101218u;
    {
        const bool branch_taken_0x101218 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10121Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101218u;
            // 0x10121c: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101218) {
            ctx->pc = 0x10125Cu;
            goto label_10125c;
        }
    }
    ctx->pc = 0x101220u;
    // 0x101220: 0xac407924  sw          $zero, 0x7924($v0)
    ctx->pc = 0x101220u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31012), GPR_U32(ctx, 0));
    // 0x101224: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x101224u;
    {
        const bool branch_taken_0x101224 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101224u;
            // 0x101228: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101224) {
            ctx->pc = 0x101358u;
            goto label_101358;
        }
    }
    ctx->pc = 0x10122Cu;
label_10122c:
    // 0x10122c: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x10122cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x101230: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x101230u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x101234: 0x0  nop
    ctx->pc = 0x101234u;
    // NOP
label_101238:
    // 0x101238: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x101238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10123c: 0x0  nop
    ctx->pc = 0x10123cu;
    // NOP
    // 0x101240: 0x0  nop
    ctx->pc = 0x101240u;
    // NOP
    // 0x101244: 0x0  nop
    ctx->pc = 0x101244u;
    // NOP
    // 0x101248: 0x0  nop
    ctx->pc = 0x101248u;
    // NOP
    // 0x10124c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10124Cu;
    {
        const bool branch_taken_0x10124c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x10124c) {
            ctx->pc = 0x101238u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101238;
        }
    }
    ctx->pc = 0x101254u;
    // 0x101254: 0x1000ffc6  b           . + 4 + (-0x3A << 2)
    ctx->pc = 0x101254u;
    {
        const bool branch_taken_0x101254 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x101254) {
            ctx->pc = 0x101170u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101170;
        }
    }
    ctx->pc = 0x10125Cu;
label_10125c:
    // 0x10125c: 0x3c052000  lui         $a1, 0x2000
    ctx->pc = 0x10125cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)8192 << 16));
    // 0x101260: 0x2602000c  addiu       $v0, $s0, 0xC
    ctx->pc = 0x101260u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x101264: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x101264u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x101268: 0x26030004  addiu       $v1, $s0, 0x4
    ctx->pc = 0x101268u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x10126c: 0x26040008  addiu       $a0, $s0, 0x8
    ctx->pc = 0x10126cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x101270: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x101270u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x101274: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x101274u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x101278: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x101278u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x10127c: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x10127cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x101280: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x101280u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101284: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x101284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x101288: 0x10c20016  beq         $a2, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x101288u;
    {
        const bool branch_taken_0x101288 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x10128Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101288u;
            // 0x10128c: 0x8c840000  lw          $a0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101288) {
            ctx->pc = 0x1012E4u;
            goto label_1012e4;
        }
    }
    ctx->pc = 0x101290u;
    // 0x101290: 0x240200fe  addiu       $v0, $zero, 0xFE
    ctx->pc = 0x101290u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 254));
    // 0x101294: 0x14c20004  bne         $a2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x101294u;
    {
        const bool branch_taken_0x101294 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x101298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101294u;
            // 0x101298: 0x2406ffff  addiu       $a2, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101294) {
            ctx->pc = 0x1012A8u;
            goto label_1012a8;
        }
    }
    ctx->pc = 0x10129Cu;
    // 0x10129c: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x10129cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1012a0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1012A0u;
    {
        const bool branch_taken_0x1012a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1012A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1012A0u;
            // 0x1012a4: 0xac507910  sw          $s0, 0x7910($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 30992), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1012a0) {
            ctx->pc = 0x1012E4u;
            goto label_1012e4;
        }
    }
    ctx->pc = 0x1012A8u;
label_1012a8:
    // 0x1012a8: 0x24a200ff  addiu       $v0, $a1, 0xFF
    ctx->pc = 0x1012a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 255));
    // 0x1012ac: 0xc5182a  slt         $v1, $a2, $a1
    ctx->pc = 0x1012acu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1012b0: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x1012b0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x1012b4: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1012b4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1012b8: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1012b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1012bc: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1012BCu;
    {
        const bool branch_taken_0x1012bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1012bc) {
            ctx->pc = 0x1012C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1012BCu;
            // 0x1012c0: 0x24100002  addiu       $s0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1012E4u;
            goto label_1012e4;
        }
    }
    ctx->pc = 0x1012C4u;
    // 0x1012c4: 0xc4182a  slt         $v1, $a2, $a0
    ctx->pc = 0x1012c4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1012c8: 0x248200ff  addiu       $v0, $a0, 0xFF
    ctx->pc = 0x1012c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 255));
    // 0x1012cc: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x1012ccu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x1012d0: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1012d0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1012d4: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1012d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1012d8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1012D8u;
    {
        const bool branch_taken_0x1012d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1012DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1012D8u;
            // 0x1012dc: 0x3c040020  lui         $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1012d8) {
            ctx->pc = 0x1012E8u;
            goto label_1012e8;
        }
    }
    ctx->pc = 0x1012E0u;
    // 0x1012e0: 0x24100002  addiu       $s0, $zero, 0x2
    ctx->pc = 0x1012e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1012e4:
    // 0x1012e4: 0x3c040020  lui         $a0, 0x20
    ctx->pc = 0x1012e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32 << 16));
label_1012e8:
    // 0x1012e8: 0xac807924  sw          $zero, 0x7924($a0)
    ctx->pc = 0x1012e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 31012), GPR_U32(ctx, 0));
    // 0x1012ec: 0x6600015  bltz        $s3, . + 4 + (0x15 << 2)
    ctx->pc = 0x1012ECu;
    {
        const bool branch_taken_0x1012ec = (GPR_S64(ctx, 19) < 0);
        ctx->pc = 0x1012F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1012ECu;
            // 0x1012f0: 0x2a620002  slti        $v0, $s3, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1012ec) {
            ctx->pc = 0x101344u;
            goto label_101344;
        }
    }
    ctx->pc = 0x1012F4u;
    // 0x1012f4: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1012F4u;
    {
        const bool branch_taken_0x1012f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1012F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1012F4u;
            // 0x1012f8: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1012f4) {
            ctx->pc = 0x101344u;
            goto label_101344;
        }
    }
    ctx->pc = 0x1012FCu;
    // 0x1012fc: 0x16620011  bne         $s3, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1012FCu;
    {
        const bool branch_taken_0x1012fc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        ctx->pc = 0x101300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1012FCu;
            // 0x101300: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1012fc) {
            ctx->pc = 0x101344u;
            goto label_101344;
        }
    }
    ctx->pc = 0x101304u;
    // 0x101304: 0x8c437910  lw          $v1, 0x7910($v0)
    ctx->pc = 0x101304u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x101308: 0x18600003  blez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x101308u;
    {
        const bool branch_taken_0x101308 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x10130Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101308u;
            // 0x10130c: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101308) {
            ctx->pc = 0x101318u;
            goto label_101318;
        }
    }
    ctx->pc = 0x101310u;
    // 0x101310: 0xc045a12  jal         func_116848
    ctx->pc = 0x101310u;
    SET_GPR_U32(ctx, 31, 0x101318u);
    ctx->pc = 0x101314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101310u;
            // 0x101314: 0x248475d8  addiu       $a0, $a0, 0x75D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101318u; }
        if (ctx->pc != 0x101318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101318u; }
        if (ctx->pc != 0x101318u) { return; }
    }
    ctx->pc = 0x101318u;
label_101318:
    // 0x101318: 0xc040192  jal         func_100648
    ctx->pc = 0x101318u;
    SET_GPR_U32(ctx, 31, 0x101320u);
    ctx->pc = 0x100648u;
    if (runtime->hasFunction(0x100648u)) {
        auto targetFn = runtime->lookupFunction(0x100648u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101320u; }
        if (ctx->pc != 0x101320u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100648_0x100648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101320u; }
        if (ctx->pc != 0x101320u) { return; }
    }
    ctx->pc = 0x101320u;
label_101320:
    // 0x101320: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x101320u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x101324: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101324u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101328: 0xac447928  sw          $a0, 0x7928($v0)
    ctx->pc = 0x101328u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31016), GPR_U32(ctx, 4));
    // 0x10132c: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x10132cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x101330: 0xac64792c  sw          $a0, 0x792C($v1)
    ctx->pc = 0x101330u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 31020), GPR_U32(ctx, 4));
    // 0x101334: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101334u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101338: 0xac447920  sw          $a0, 0x7920($v0)
    ctx->pc = 0x101338u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 31008), GPR_U32(ctx, 4));
    // 0x10133c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10133Cu;
    {
        const bool branch_taken_0x10133c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10133Cu;
            // 0x101340: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10133c) {
            ctx->pc = 0x101358u;
            goto label_101358;
        }
    }
    ctx->pc = 0x101344u;
label_101344:
    // 0x101344: 0xc040164  jal         func_100590
    ctx->pc = 0x101344u;
    SET_GPR_U32(ctx, 31, 0x10134Cu);
    ctx->pc = 0x100590u;
    if (runtime->hasFunction(0x100590u)) {
        auto targetFn = runtime->lookupFunction(0x100590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10134Cu; }
        if (ctx->pc != 0x10134Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10134Cu; }
        if (ctx->pc != 0x10134Cu) { return; }
    }
    ctx->pc = 0x10134Cu;
label_10134c:
    // 0x10134c: 0xc0401f0  jal         func_1007C0
    ctx->pc = 0x10134Cu;
    SET_GPR_U32(ctx, 31, 0x101354u);
    ctx->pc = 0x1007C0u;
    if (runtime->hasFunction(0x1007C0u)) {
        auto targetFn = runtime->lookupFunction(0x1007C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101354u; }
        if (ctx->pc != 0x101354u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001007C0_0x1007c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101354u; }
        if (ctx->pc != 0x101354u) { return; }
    }
    ctx->pc = 0x101354u;
label_101354:
    // 0x101354: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101354u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101358:
    // 0x101358: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x101358u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x10135c: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x10135cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x101360: 0xdfb70080  ld          $s7, 0x80($sp)
    ctx->pc = 0x101360u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x101364: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x101364u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x101368: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x101368u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x10136c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x10136cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x101370: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x101370u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101374: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x101374u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101378: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101378u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10137c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x10137cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101380: 0x3e00008  jr          $ra
    ctx->pc = 0x101380u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101380u;
            // 0x101384: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1010E0u: goto label_1010e0;
            case 0x1010F4u: goto label_1010f4;
            case 0x1010FCu: goto label_1010fc;
            case 0x101170u: goto label_101170;
            case 0x101184u: goto label_101184;
            case 0x1011A4u: goto label_1011a4;
            case 0x1011B0u: goto label_1011b0;
            case 0x1011D4u: goto label_1011d4;
            case 0x1011ECu: goto label_1011ec;
            case 0x101218u: goto label_101218;
            case 0x10122Cu: goto label_10122c;
            case 0x101238u: goto label_101238;
            case 0x10125Cu: goto label_10125c;
            case 0x1012A8u: goto label_1012a8;
            case 0x1012E4u: goto label_1012e4;
            case 0x1012E8u: goto label_1012e8;
            case 0x101318u: goto label_101318;
            case 0x101320u: goto label_101320;
            case 0x101344u: goto label_101344;
            case 0x10134Cu: goto label_10134c;
            case 0x101354u: goto label_101354;
            case 0x101358u: goto label_101358;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101388u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

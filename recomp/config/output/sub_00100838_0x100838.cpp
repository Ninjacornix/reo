#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100838
// Address: 0x100838 - 0x100b70
void sub_00100838_0x100838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100838_0x100838");
#endif

    switch (ctx->pc) {
        case 0x100878u: goto label_100878;
        case 0x100884u: goto label_100884;
        case 0x1008b0u: goto label_1008b0;
        case 0x1008b8u: goto label_1008b8;
        case 0x1008c8u: goto label_1008c8;
        case 0x1008e8u: goto label_1008e8;
        case 0x1008f0u: goto label_1008f0;
        case 0x100910u: goto label_100910;
        case 0x100924u: goto label_100924;
        case 0x100944u: goto label_100944;
        case 0x100950u: goto label_100950;
        case 0x1009b0u: goto label_1009b0;
        case 0x100a04u: goto label_100a04;
        case 0x100a20u: goto label_100a20;
        case 0x100a48u: goto label_100a48;
        case 0x100a5cu: goto label_100a5c;
        case 0x100ad0u: goto label_100ad0;
        case 0x100ae8u: goto label_100ae8;
        case 0x100b00u: goto label_100b00;
        case 0x100b18u: goto label_100b18;
        case 0x100b60u: goto label_100b60;
        default: break;
    }

    ctx->pc = 0x100838u;

label_100838:
    // 0x100838: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x100838u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x10083c: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x10083cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x100840: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x100840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x100844: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x100844u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100848: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x100848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x10084c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x10084cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100850: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x100850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x100854: 0x3c160020  lui         $s6, 0x20
    ctx->pc = 0x100854u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)32 << 16));
    // 0x100858: 0xffbe00a0  sd          $fp, 0xA0($sp)
    ctx->pc = 0x100858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x10085c: 0xffb70090  sd          $s7, 0x90($sp)
    ctx->pc = 0x10085cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x100860: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x100860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x100864: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x100864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x100868: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x100868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x10086c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x10086cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x100870: 0xc040164  jal         func_100590
    ctx->pc = 0x100870u;
    SET_GPR_U32(ctx, 31, 0x100878u);
    ctx->pc = 0x100874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100870u;
            // 0x100874: 0xafa60010  sw          $a2, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100590u;
    if (runtime->hasFunction(0x100590u)) {
        auto targetFn = runtime->lookupFunction(0x100590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100878u; }
        if (ctx->pc != 0x100878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100878u; }
        if (ctx->pc != 0x100878u) { return; }
    }
    ctx->pc = 0x100878u;
label_100878:
    // 0x100878: 0x8ec47928  lw          $a0, 0x7928($s6)
    ctx->pc = 0x100878u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x10087c: 0xc04519c  jal         func_114670
    ctx->pc = 0x10087Cu;
    SET_GPR_U32(ctx, 31, 0x100884u);
    ctx->pc = 0x114670u;
    if (runtime->hasFunction(0x114670u)) {
        auto targetFn = runtime->lookupFunction(0x114670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100884u; }
        if (ctx->pc != 0x100884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100884u; }
        if (ctx->pc != 0x100884u) { return; }
    }
    ctx->pc = 0x100884u;
label_100884:
    // 0x100884: 0x8ec37928  lw          $v1, 0x7928($s6)
    ctx->pc = 0x100884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x100888: 0x146200a4  bne         $v1, $v0, . + 4 + (0xA4 << 2)
    ctx->pc = 0x100888u;
    {
        const bool branch_taken_0x100888 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10088Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100888u;
            // 0x10088c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100888) {
            ctx->pc = 0x100B1Cu;
            goto label_100b1c;
        }
    }
    ctx->pc = 0x100890u;
    // 0x100890: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x100890u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x100894: 0x3c060020  lui         $a2, 0x20
    ctx->pc = 0x100894u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32 << 16));
    // 0x100898: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x100898u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10089c: 0x8c449f98  lw          $a0, -0x6068($v0)
    ctx->pc = 0x10089cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942616)));
    // 0x1008a0: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1008a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1008a4: 0x0  nop
    ctx->pc = 0x1008a4u;
    // NOP
    // 0x1008a8: 0xc045148  jal         func_114520
    ctx->pc = 0x1008A8u;
    SET_GPR_U32(ctx, 31, 0x1008B0u);
    ctx->pc = 0x1008ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1008A8u;
            // 0x1008ac: 0x24a59fa0  addiu       $a1, $a1, -0x6060 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008B0u; }
        if (ctx->pc != 0x1008B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008B0u; }
        if (ctx->pc != 0x1008B0u) { return; }
    }
    ctx->pc = 0x1008B0u;
label_1008b0:
    // 0x1008b0: 0xc04035e  jal         func_100D78
    ctx->pc = 0x1008B0u;
    SET_GPR_U32(ctx, 31, 0x1008B8u);
    ctx->pc = 0x1008B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1008B0u;
            // 0x1008b4: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008B8u; }
        if (ctx->pc != 0x1008B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008B8u; }
        if (ctx->pc != 0x1008B8u) { return; }
    }
    ctx->pc = 0x1008B8u;
label_1008b8:
    // 0x1008b8: 0x14400065  bnez        $v0, . + 4 + (0x65 << 2)
    ctx->pc = 0x1008B8u;
    {
        const bool branch_taken_0x1008b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1008BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1008B8u;
            // 0x1008bc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1008b8) {
            ctx->pc = 0x100A50u;
            goto label_100a50;
        }
    }
    ctx->pc = 0x1008C0u;
    // 0x1008c0: 0xc045c20  jal         func_117080
    ctx->pc = 0x1008C0u;
    SET_GPR_U32(ctx, 31, 0x1008C8u);
    ctx->pc = 0x1008C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1008C0u;
            // 0x1008c4: 0x3c110020  lui         $s1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008C8u; }
        if (ctx->pc != 0x1008C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1008C8u; }
        if (ctx->pc != 0x1008C8u) { return; }
    }
    ctx->pc = 0x1008C8u;
label_1008c8:
    // 0x1008c8: 0x8e227944  lw          $v0, 0x7944($s1)
    ctx->pc = 0x1008c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31044)));
    // 0x1008cc: 0x441002d  bgez        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1008CCu;
    {
        const bool branch_taken_0x1008cc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1008D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1008CCu;
            // 0x1008d0: 0x3c170026  lui         $s7, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1008cc) {
            ctx->pc = 0x100984u;
            goto label_100984;
        }
    }
    ctx->pc = 0x1008D4u;
    // 0x1008d4: 0x3c140020  lui         $s4, 0x20
    ctx->pc = 0x1008d4u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
    // 0x1008d8: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x1008d8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x1008dc: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1008DCu;
    {
        const bool branch_taken_0x1008dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1008E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1008DCu;
            // 0x1008e0: 0x3c1e0026  lui         $fp, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1008dc) {
            ctx->pc = 0x10090Cu;
            goto label_10090c;
        }
    }
    ctx->pc = 0x1008E4u;
    // 0x1008e4: 0x0  nop
    ctx->pc = 0x1008e4u;
    // NOP
label_1008e8:
    // 0x1008e8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1008e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1008ec: 0x0  nop
    ctx->pc = 0x1008ecu;
    // NOP
label_1008f0:
    // 0x1008f0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1008f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1008f4: 0x0  nop
    ctx->pc = 0x1008f4u;
    // NOP
    // 0x1008f8: 0x0  nop
    ctx->pc = 0x1008f8u;
    // NOP
    // 0x1008fc: 0x0  nop
    ctx->pc = 0x1008fcu;
    // NOP
    // 0x100900: 0x0  nop
    ctx->pc = 0x100900u;
    // NOP
    // 0x100904: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x100904u;
    {
        const bool branch_taken_0x100904 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x100904) {
            ctx->pc = 0x1008F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1008f0;
        }
    }
    ctx->pc = 0x10090Cu;
label_10090c:
    // 0x10090c: 0x26f0a180  addiu       $s0, $s7, -0x5E80
    ctx->pc = 0x10090cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 4294943104));
label_100910:
    // 0x100910: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x100910u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x100914: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x100914u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100918: 0x34a50597  ori         $a1, $a1, 0x597
    ctx->pc = 0x100918u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1431);
    // 0x10091c: 0xc045e06  jal         func_117818
    ctx->pc = 0x10091Cu;
    SET_GPR_U32(ctx, 31, 0x100924u);
    ctx->pc = 0x100920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10091Cu;
            // 0x100920: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100924u; }
        if (ctx->pc != 0x100924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100924u; }
        if (ctx->pc != 0x100924u) { return; }
    }
    ctx->pc = 0x100924u;
label_100924:
    // 0x100924: 0x4430013  bgezl       $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x100924u;
    {
        const bool branch_taken_0x100924 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x100924) {
            ctx->pc = 0x100928u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x100924u;
            // 0x100928: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x100974u;
            goto label_100974;
        }
    }
    ctx->pc = 0x10092Cu;
    // 0x10092c: 0x8e827910  lw          $v0, 0x7910($s4)
    ctx->pc = 0x10092cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100930: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x100930u;
    {
        const bool branch_taken_0x100930 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x100934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100930u;
            // 0x100934: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100930) {
            ctx->pc = 0x100948u;
            goto label_100948;
        }
    }
    ctx->pc = 0x100938u;
    // 0x100938: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x100938u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x10093c: 0xc045a12  jal         func_116848
    ctx->pc = 0x10093Cu;
    SET_GPR_U32(ctx, 31, 0x100944u);
    ctx->pc = 0x100940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10093Cu;
            // 0x100940: 0x248474a8  addiu       $a0, $a0, 0x74A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100944u; }
        if (ctx->pc != 0x100944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100944u; }
        if (ctx->pc != 0x100944u) { return; }
    }
    ctx->pc = 0x100944u;
label_100944:
    // 0x100944: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x100944u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
label_100948:
    // 0x100948: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x100948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10094c: 0x0  nop
    ctx->pc = 0x10094cu;
    // NOP
label_100950:
    // 0x100950: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x100950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100954: 0x0  nop
    ctx->pc = 0x100954u;
    // NOP
    // 0x100958: 0x0  nop
    ctx->pc = 0x100958u;
    // NOP
    // 0x10095c: 0x0  nop
    ctx->pc = 0x10095cu;
    // NOP
    // 0x100960: 0x0  nop
    ctx->pc = 0x100960u;
    // NOP
    // 0x100964: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x100964u;
    {
        const bool branch_taken_0x100964 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x100964) {
            ctx->pc = 0x100950u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100950;
        }
    }
    ctx->pc = 0x10096Cu;
    // 0x10096c: 0x1000ffe8  b           . + 4 + (-0x18 << 2)
    ctx->pc = 0x10096Cu;
    {
        const bool branch_taken_0x10096c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10096Cu;
            // 0x100970: 0x26f0a180  addiu       $s0, $s7, -0x5E80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 4294943104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10096c) {
            ctx->pc = 0x100910u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100910;
        }
    }
    ctx->pc = 0x100974u;
label_100974:
    // 0x100974: 0x1040ffdc  beqz        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x100974u;
    {
        const bool branch_taken_0x100974 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x100978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100974u;
            // 0x100978: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100974) {
            ctx->pc = 0x1008E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1008e8;
        }
    }
    ctx->pc = 0x10097Cu;
    // 0x10097c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10097Cu;
    {
        const bool branch_taken_0x10097c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10097Cu;
            // 0x100980: 0xae207944  sw          $zero, 0x7944($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 31044), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10097c) {
            ctx->pc = 0x100990u;
            goto label_100990;
        }
    }
    ctx->pc = 0x100984u;
label_100984:
    // 0x100984: 0x3c140020  lui         $s4, 0x20
    ctx->pc = 0x100984u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
    // 0x100988: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x100988u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x10098c: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x10098cu;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
label_100990:
    // 0x100990: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x100990u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x100994: 0x26a4a000  addiu       $a0, $s5, -0x6000
    ctx->pc = 0x100994u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294942720));
    // 0x100998: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x100998u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10099c: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x10099cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1009a0: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1009A0u;
    {
        const bool branch_taken_0x1009a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1009A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1009A0u;
            // 0x1009a4: 0xa0830024  sb          $v1, 0x24($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 36), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1009a0) {
            ctx->pc = 0x1009D4u;
            goto label_1009d4;
        }
    }
    ctx->pc = 0x1009A8u;
    // 0x1009a8: 0x24860024  addiu       $a2, $a0, 0x24
    ctx->pc = 0x1009a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 36));
    // 0x1009ac: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1009acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1009b0:
    // 0x1009b0: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x1009b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1009b4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1009B4u;
    {
        const bool branch_taken_0x1009b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1009B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1009B4u;
            // 0x1009b8: 0x2451021  addu        $v0, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1009b4) {
            ctx->pc = 0x1009D4u;
            goto label_1009d4;
        }
    }
    ctx->pc = 0x1009BCu;
    // 0x1009bc: 0xa62021  addu        $a0, $a1, $a2
    ctx->pc = 0x1009bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1009c0: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1009c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1009c4: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1009c4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1009c8: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1009c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1009cc: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1009CCu;
    {
        const bool branch_taken_0x1009cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1009cc) {
            ctx->pc = 0x1009D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1009CCu;
            // 0x1009d0: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1009B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1009b0;
        }
    }
    ctx->pc = 0x1009D4u;
label_1009d4:
    // 0x1009d4: 0x24020100  addiu       $v0, $zero, 0x100
    ctx->pc = 0x1009d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1009d8: 0x14a20004  bne         $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1009D8u;
    {
        const bool branch_taken_0x1009d8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x1009DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1009D8u;
            // 0x1009dc: 0x8e827910  lw          $v0, 0x7910($s4) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1009d8) {
            ctx->pc = 0x1009ECu;
            goto label_1009ec;
        }
    }
    ctx->pc = 0x1009E0u;
    // 0x1009e0: 0x26a2a000  addiu       $v0, $s5, -0x6000
    ctx->pc = 0x1009e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), 4294942720));
    // 0x1009e4: 0xa0400123  sb          $zero, 0x123($v0)
    ctx->pc = 0x1009e4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 291), (uint8_t)GPR_U32(ctx, 0));
    // 0x1009e8: 0x8e827910  lw          $v0, 0x7910($s4)
    ctx->pc = 0x1009e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
label_1009ec:
    // 0x1009ec: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1009ECu;
    {
        const bool branch_taken_0x1009ec = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1009F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1009ECu;
            // 0x1009f0: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1009ec) {
            ctx->pc = 0x100A04u;
            goto label_100a04;
        }
    }
    ctx->pc = 0x1009F4u;
    // 0x1009f4: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1009f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1009f8: 0x248474c8  addiu       $a0, $a0, 0x74C8
    ctx->pc = 0x1009f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29896));
    // 0x1009fc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1009FCu;
    SET_GPR_U32(ctx, 31, 0x100A04u);
    ctx->pc = 0x100A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1009FCu;
            // 0x100a00: 0x24a5a024  addiu       $a1, $a1, -0x5FDC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942756));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A04u; }
        if (ctx->pc != 0x100A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A04u; }
        if (ctx->pc != 0x100A04u) { return; }
    }
    ctx->pc = 0x100A04u;
label_100a04:
    // 0x100a04: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x100a04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100a08: 0x26b0a000  addiu       $s0, $s5, -0x6000
    ctx->pc = 0x100a08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294942720));
    // 0x100a0c: 0x2405012c  addiu       $a1, $zero, 0x12C
    ctx->pc = 0x100a0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x100a10: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x100a10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a14: 0xae020128  sw          $v0, 0x128($s0)
    ctx->pc = 0x100a14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
    // 0x100a18: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x100A18u;
    SET_GPR_U32(ctx, 31, 0x100A20u);
    ctx->pc = 0x100A1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100A18u;
            // 0x100a1c: 0xae100124  sw          $s0, 0x124($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 292), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A20u; }
        if (ctx->pc != 0x100A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A20u; }
        if (ctx->pc != 0x100A20u) { return; }
    }
    ctx->pc = 0x100A20u;
label_100a20:
    // 0x100a20: 0x26e4a180  addiu       $a0, $s7, -0x5E80
    ctx->pc = 0x100a20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), 4294943104));
    // 0x100a24: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x100a24u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x100a28: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x100a28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a2c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x100a2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a30: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x100a30u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100a34: 0x2408012c  addiu       $t0, $zero, 0x12C
    ctx->pc = 0x100a34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x100a38: 0x27c9a140  addiu       $t1, $fp, -0x5EC0
    ctx->pc = 0x100a38u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 30), 4294943040));
    // 0x100a3c: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x100a3cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x100a40: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x100A40u;
    SET_GPR_U32(ctx, 31, 0x100A48u);
    ctx->pc = 0x100A44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100A40u;
            // 0x100a44: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A48u; }
        if (ctx->pc != 0x100A48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A48u; }
        if (ctx->pc != 0x100A48u) { return; }
    }
    ctx->pc = 0x100A48u;
label_100a48:
    // 0x100a48: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x100A48u;
    {
        const bool branch_taken_0x100a48 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x100A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100A48u;
            // 0x100a4c: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100a48) {
            ctx->pc = 0x100A64u;
            goto label_100a64;
        }
    }
    ctx->pc = 0x100A50u;
label_100a50:
    // 0x100a50: 0x8ec47928  lw          $a0, 0x7928($s6)
    ctx->pc = 0x100a50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x100a54: 0xc045190  jal         func_114640
    ctx->pc = 0x100A54u;
    SET_GPR_U32(ctx, 31, 0x100A5Cu);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A5Cu; }
        if (ctx->pc != 0x100A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100A5Cu; }
        if (ctx->pc != 0x100A5Cu) { return; }
    }
    ctx->pc = 0x100A5Cu;
label_100a5c:
    // 0x100a5c: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x100A5Cu;
    {
        const bool branch_taken_0x100a5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100A5Cu;
            // 0x100a60: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100a5c) {
            ctx->pc = 0x100B1Cu;
            goto label_100b1c;
        }
    }
    ctx->pc = 0x100A64u;
label_100a64:
    // 0x100a64: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x100a64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x100a68: 0x68430007  ldl         $v1, 0x7($v0)
    ctx->pc = 0x100a68u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x100a6c: 0x6c430000  ldr         $v1, 0x0($v0)
    ctx->pc = 0x100a6cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x100a70: 0x6844000f  ldl         $a0, 0xF($v0)
    ctx->pc = 0x100a70u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x100a74: 0x6c440008  ldr         $a0, 0x8($v0)
    ctx->pc = 0x100a74u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x100a78: 0x68450017  ldl         $a1, 0x17($v0)
    ctx->pc = 0x100a78u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x100a7c: 0x6c450010  ldr         $a1, 0x10($v0)
    ctx->pc = 0x100a7cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x100a80: 0x6846001f  ldl         $a2, 0x1F($v0)
    ctx->pc = 0x100a80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x100a84: 0x6c460018  ldr         $a2, 0x18($v0)
    ctx->pc = 0x100a84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x100a88: 0xb2630007  sdl         $v1, 0x7($s3)
    ctx->pc = 0x100a88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a8c: 0xb6630000  sdr         $v1, 0x0($s3)
    ctx->pc = 0x100a8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a90: 0xb264000f  sdl         $a0, 0xF($s3)
    ctx->pc = 0x100a90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a94: 0xb6640008  sdr         $a0, 0x8($s3)
    ctx->pc = 0x100a94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a98: 0xb2650017  sdl         $a1, 0x17($s3)
    ctx->pc = 0x100a98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100a9c: 0xb6650010  sdr         $a1, 0x10($s3)
    ctx->pc = 0x100a9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100aa0: 0xb266001f  sdl         $a2, 0x1F($s3)
    ctx->pc = 0x100aa0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100aa4: 0xb6660018  sdr         $a2, 0x18($s3)
    ctx->pc = 0x100aa4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x100aa8: 0x88430023  lwl         $v1, 0x23($v0)
    ctx->pc = 0x100aa8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x100aac: 0x98430020  lwr         $v1, 0x20($v0)
    ctx->pc = 0x100aacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x100ab0: 0xaa630023  swl         $v1, 0x23($s3)
    ctx->pc = 0x100ab0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 35); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x100ab4: 0xba630020  swr         $v1, 0x20($s3)
    ctx->pc = 0x100ab4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 32); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x100ab8: 0x8e837910  lw          $v1, 0x7910($s4)
    ctx->pc = 0x100ab8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100abc: 0x18600010  blez        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x100ABCu;
    {
        const bool branch_taken_0x100abc = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x100AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100ABCu;
            // 0x100ac0: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100abc) {
            ctx->pc = 0x100B00u;
            goto label_100b00;
        }
    }
    ctx->pc = 0x100AC4u;
    // 0x100ac4: 0x26650008  addiu       $a1, $s3, 0x8
    ctx->pc = 0x100ac4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x100ac8: 0xc045a12  jal         func_116848
    ctx->pc = 0x100AC8u;
    SET_GPR_U32(ctx, 31, 0x100AD0u);
    ctx->pc = 0x100ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100AC8u;
            // 0x100acc: 0x248474e0  addiu       $a0, $a0, 0x74E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29920));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100AD0u; }
        if (ctx->pc != 0x100AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100AD0u; }
        if (ctx->pc != 0x100AD0u) { return; }
    }
    ctx->pc = 0x100AD0u;
label_100ad0:
    // 0x100ad0: 0x8e827910  lw          $v0, 0x7910($s4)
    ctx->pc = 0x100ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100ad4: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x100AD4u;
    {
        const bool branch_taken_0x100ad4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x100AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100AD4u;
            // 0x100ad8: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100ad4) {
            ctx->pc = 0x100B00u;
            goto label_100b00;
        }
    }
    ctx->pc = 0x100ADCu;
    // 0x100adc: 0x8e650004  lw          $a1, 0x4($s3)
    ctx->pc = 0x100adcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x100ae0: 0xc045a12  jal         func_116848
    ctx->pc = 0x100AE0u;
    SET_GPR_U32(ctx, 31, 0x100AE8u);
    ctx->pc = 0x100AE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100AE0u;
            // 0x100ae4: 0x248474f0  addiu       $a0, $a0, 0x74F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100AE8u; }
        if (ctx->pc != 0x100AE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100AE8u; }
        if (ctx->pc != 0x100AE8u) { return; }
    }
    ctx->pc = 0x100AE8u;
label_100ae8:
    // 0x100ae8: 0x8e827910  lw          $v0, 0x7910($s4)
    ctx->pc = 0x100ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 30992)));
    // 0x100aec: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x100AECu;
    {
        const bool branch_taken_0x100aec = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x100AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100AECu;
            // 0x100af0: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100aec) {
            ctx->pc = 0x100B00u;
            goto label_100b00;
        }
    }
    ctx->pc = 0x100AF4u;
    // 0x100af4: 0x8e650000  lw          $a1, 0x0($s3)
    ctx->pc = 0x100af4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x100af8: 0xc045a12  jal         func_116848
    ctx->pc = 0x100AF8u;
    SET_GPR_U32(ctx, 31, 0x100B00u);
    ctx->pc = 0x100AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100AF8u;
            // 0x100afc: 0x24847500  addiu       $a0, $a0, 0x7500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29952));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B00u; }
        if (ctx->pc != 0x100B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B00u; }
        if (ctx->pc != 0x100B00u) { return; }
    }
    ctx->pc = 0x100B00u;
label_100b00:
    // 0x100b00: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x100b00u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x100b04: 0x27c2a140  addiu       $v0, $fp, -0x5EC0
    ctx->pc = 0x100b04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 4294943040));
    // 0x100b08: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x100b08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x100b0c: 0x8ec47928  lw          $a0, 0x7928($s6)
    ctx->pc = 0x100b0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 31016)));
    // 0x100b10: 0xc045190  jal         func_114640
    ctx->pc = 0x100B10u;
    SET_GPR_U32(ctx, 31, 0x100B18u);
    ctx->pc = 0x100B14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100B10u;
            // 0x100b14: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B18u; }
        if (ctx->pc != 0x100B18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100B18u; }
        if (ctx->pc != 0x100B18u) { return; }
    }
    ctx->pc = 0x100B18u;
label_100b18:
    // 0x100b18: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x100b18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_100b1c:
    // 0x100b1c: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x100b1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x100b20: 0xdfbe00a0  ld          $fp, 0xA0($sp)
    ctx->pc = 0x100b20u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x100b24: 0xdfb70090  ld          $s7, 0x90($sp)
    ctx->pc = 0x100b24u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x100b28: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x100b28u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x100b2c: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x100b2cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x100b30: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x100b30u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x100b34: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x100b34u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x100b38: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x100b38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x100b3c: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x100b3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100b40: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x100b40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100b44: 0x3e00008  jr          $ra
    ctx->pc = 0x100B44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100B44u;
            // 0x100b48: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100838u: goto label_100838;
            case 0x100878u: goto label_100878;
            case 0x100884u: goto label_100884;
            case 0x1008B0u: goto label_1008b0;
            case 0x1008B8u: goto label_1008b8;
            case 0x1008C8u: goto label_1008c8;
            case 0x1008E8u: goto label_1008e8;
            case 0x1008F0u: goto label_1008f0;
            case 0x10090Cu: goto label_10090c;
            case 0x100910u: goto label_100910;
            case 0x100924u: goto label_100924;
            case 0x100944u: goto label_100944;
            case 0x100948u: goto label_100948;
            case 0x100950u: goto label_100950;
            case 0x100974u: goto label_100974;
            case 0x100984u: goto label_100984;
            case 0x100990u: goto label_100990;
            case 0x1009B0u: goto label_1009b0;
            case 0x1009D4u: goto label_1009d4;
            case 0x1009ECu: goto label_1009ec;
            case 0x100A04u: goto label_100a04;
            case 0x100A20u: goto label_100a20;
            case 0x100A48u: goto label_100a48;
            case 0x100A50u: goto label_100a50;
            case 0x100A5Cu: goto label_100a5c;
            case 0x100A64u: goto label_100a64;
            case 0x100AD0u: goto label_100ad0;
            case 0x100AE8u: goto label_100ae8;
            case 0x100B00u: goto label_100b00;
            case 0x100B18u: goto label_100b18;
            case 0x100B1Cu: goto label_100b1c;
            case 0x100B60u: goto label_100b60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100B4Cu;
    // 0x100b4c: 0x0  nop
    ctx->pc = 0x100b4cu;
    // NOP
    // 0x100b50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x100b50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x100b54: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x100b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x100b58: 0xc04020e  jal         func_100838
    ctx->pc = 0x100B58u;
    SET_GPR_U32(ctx, 31, 0x100B60u);
    ctx->pc = 0x100B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100B58u;
            // 0x100b5c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100838u;
    goto label_100838;
    ctx->pc = 0x100B60u;
label_100b60:
    // 0x100b60: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x100b60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100b64: 0x3e00008  jr          $ra
    ctx->pc = 0x100B64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100B64u;
            // 0x100b68: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100838u: goto label_100838;
            case 0x100878u: goto label_100878;
            case 0x100884u: goto label_100884;
            case 0x1008B0u: goto label_1008b0;
            case 0x1008B8u: goto label_1008b8;
            case 0x1008C8u: goto label_1008c8;
            case 0x1008E8u: goto label_1008e8;
            case 0x1008F0u: goto label_1008f0;
            case 0x10090Cu: goto label_10090c;
            case 0x100910u: goto label_100910;
            case 0x100924u: goto label_100924;
            case 0x100944u: goto label_100944;
            case 0x100948u: goto label_100948;
            case 0x100950u: goto label_100950;
            case 0x100974u: goto label_100974;
            case 0x100984u: goto label_100984;
            case 0x100990u: goto label_100990;
            case 0x1009B0u: goto label_1009b0;
            case 0x1009D4u: goto label_1009d4;
            case 0x1009ECu: goto label_1009ec;
            case 0x100A04u: goto label_100a04;
            case 0x100A20u: goto label_100a20;
            case 0x100A48u: goto label_100a48;
            case 0x100A50u: goto label_100a50;
            case 0x100A5Cu: goto label_100a5c;
            case 0x100A64u: goto label_100a64;
            case 0x100AD0u: goto label_100ad0;
            case 0x100AE8u: goto label_100ae8;
            case 0x100B00u: goto label_100b00;
            case 0x100B18u: goto label_100b18;
            case 0x100B1Cu: goto label_100b1c;
            case 0x100B60u: goto label_100b60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100B6Cu;
    // 0x100b6c: 0x0  nop
    ctx->pc = 0x100b6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101388
// Address: 0x101388 - 0x101788
void sub_00101388_0x101388(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101388_0x101388");
#endif

    switch (ctx->pc) {
        case 0x1013ccu: goto label_1013cc;
        case 0x1013d4u: goto label_1013d4;
        case 0x1013e0u: goto label_1013e0;
        case 0x1013f4u: goto label_1013f4;
        case 0x101404u: goto label_101404;
        case 0x101420u: goto label_101420;
        case 0x101428u: goto label_101428;
        case 0x101448u: goto label_101448;
        case 0x10145cu: goto label_10145c;
        case 0x10147cu: goto label_10147c;
        case 0x101488u: goto label_101488;
        case 0x1014d8u: goto label_1014d8;
        case 0x101504u: goto label_101504;
        case 0x101518u: goto label_101518;
        case 0x10153cu: goto label_10153c;
        case 0x101550u: goto label_101550;
        case 0x1015c0u: goto label_1015c0;
        case 0x1015c8u: goto label_1015c8;
        case 0x1015d4u: goto label_1015d4;
        case 0x1015ecu: goto label_1015ec;
        case 0x101600u: goto label_101600;
        case 0x101610u: goto label_101610;
        case 0x101634u: goto label_101634;
        case 0x101648u: goto label_101648;
        case 0x101668u: goto label_101668;
        case 0x101670u: goto label_101670;
        case 0x1016c0u: goto label_1016c0;
        case 0x1016f0u: goto label_1016f0;
        case 0x101704u: goto label_101704;
        case 0x101724u: goto label_101724;
        case 0x10172cu: goto label_10172c;
        case 0x101744u: goto label_101744;
        case 0x101758u: goto label_101758;
        default: break;
    }

    ctx->pc = 0x101388u;

label_101388:
    // 0x101388: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x101388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x10138c: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x10138cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x101390: 0x3c160020  lui         $s6, 0x20
    ctx->pc = 0x101390u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)32 << 16));
    // 0x101394: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x101394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x101398: 0x8ec27910  lw          $v0, 0x7910($s6)
    ctx->pc = 0x101398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 30992)));
    // 0x10139c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x10139cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1013a0: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1013a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1013a4: 0xffb70080  sd          $s7, 0x80($sp)
    ctx->pc = 0x1013a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x1013a8: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x1013a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1013ac: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x1013acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x1013b0: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1013b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1013b4: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1013b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1013b8: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1013B8u;
    {
        const bool branch_taken_0x1013b8 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1013BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1013B8u;
            // 0x1013bc: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1013b8) {
            ctx->pc = 0x1013CCu;
            goto label_1013cc;
        }
    }
    ctx->pc = 0x1013C0u;
    // 0x1013c0: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1013c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1013c4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1013C4u;
    SET_GPR_U32(ctx, 31, 0x1013CCu);
    ctx->pc = 0x1013C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1013C4u;
            // 0x1013c8: 0x248475e8  addiu       $a0, $a0, 0x75E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013CCu; }
        if (ctx->pc != 0x1013CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013CCu; }
        if (ctx->pc != 0x1013CCu) { return; }
    }
    ctx->pc = 0x1013CCu;
label_1013cc:
    // 0x1013cc: 0xc040164  jal         func_100590
    ctx->pc = 0x1013CCu;
    SET_GPR_U32(ctx, 31, 0x1013D4u);
    ctx->pc = 0x1013D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1013CCu;
            // 0x1013d0: 0x3c130020  lui         $s3, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100590u;
    if (runtime->hasFunction(0x100590u)) {
        auto targetFn = runtime->lookupFunction(0x100590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013D4u; }
        if (ctx->pc != 0x1013D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013D4u; }
        if (ctx->pc != 0x1013D4u) { return; }
    }
    ctx->pc = 0x1013D4u;
label_1013d4:
    // 0x1013d4: 0x8e64792c  lw          $a0, 0x792C($s3)
    ctx->pc = 0x1013d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 31020)));
    // 0x1013d8: 0xc04519c  jal         func_114670
    ctx->pc = 0x1013D8u;
    SET_GPR_U32(ctx, 31, 0x1013E0u);
    ctx->pc = 0x114670u;
    if (runtime->hasFunction(0x114670u)) {
        auto targetFn = runtime->lookupFunction(0x114670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013E0u; }
        if (ctx->pc != 0x1013E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013E0u; }
        if (ctx->pc != 0x1013E0u) { return; }
    }
    ctx->pc = 0x1013E0u;
label_1013e0:
    // 0x1013e0: 0x8e63792c  lw          $v1, 0x792C($s3)
    ctx->pc = 0x1013e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 31020)));
    // 0x1013e4: 0x1462005b  bne         $v1, $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x1013E4u;
    {
        const bool branch_taken_0x1013e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1013E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1013E4u;
            // 0x1013e8: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1013e4) {
            ctx->pc = 0x101554u;
            goto label_101554;
        }
    }
    ctx->pc = 0x1013ECu;
    // 0x1013ec: 0xc040386  jal         func_100E18
    ctx->pc = 0x1013ECu;
    SET_GPR_U32(ctx, 31, 0x1013F4u);
    ctx->pc = 0x1013F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1013ECu;
            // 0x1013f0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100E18u;
    if (runtime->hasFunction(0x100E18u)) {
        auto targetFn = runtime->lookupFunction(0x100E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013F4u; }
        if (ctx->pc != 0x1013F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E18_0x100e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1013F4u; }
        if (ctx->pc != 0x1013F4u) { return; }
    }
    ctx->pc = 0x1013F4u;
label_1013f4:
    // 0x1013f4: 0x14400045  bnez        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1013F4u;
    {
        const bool branch_taken_0x1013f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1013F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1013F4u;
            // 0x1013f8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1013f4) {
            ctx->pc = 0x10150Cu;
            goto label_10150c;
        }
    }
    ctx->pc = 0x1013FCu;
    // 0x1013fc: 0xc045c20  jal         func_117080
    ctx->pc = 0x1013FCu;
    SET_GPR_U32(ctx, 31, 0x101404u);
    ctx->pc = 0x101400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1013FCu;
            // 0x101400: 0x3c110020  lui         $s1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101404u; }
        if (ctx->pc != 0x101404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101404u; }
        if (ctx->pc != 0x101404u) { return; }
    }
    ctx->pc = 0x101404u;
label_101404:
    // 0x101404: 0x8e227948  lw          $v0, 0x7948($s1)
    ctx->pc = 0x101404u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31048)));
    // 0x101408: 0x441002c  bgez        $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x101408u;
    {
        const bool branch_taken_0x101408 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10140Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101408u;
            // 0x10140c: 0x3c150026  lui         $s5, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101408) {
            ctx->pc = 0x1014BCu;
            goto label_1014bc;
        }
    }
    ctx->pc = 0x101410u;
    // 0x101410: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x101410u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x101414: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x101414u;
    {
        const bool branch_taken_0x101414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101414u;
            // 0x101418: 0x3c170021  lui         $s7, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101414) {
            ctx->pc = 0x101444u;
            goto label_101444;
        }
    }
    ctx->pc = 0x10141Cu;
    // 0x10141c: 0x0  nop
    ctx->pc = 0x10141cu;
    // NOP
label_101420:
    // 0x101420: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x101420u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x101424: 0x0  nop
    ctx->pc = 0x101424u;
    // NOP
label_101428:
    // 0x101428: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x101428u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10142c: 0x0  nop
    ctx->pc = 0x10142cu;
    // NOP
    // 0x101430: 0x0  nop
    ctx->pc = 0x101430u;
    // NOP
    // 0x101434: 0x0  nop
    ctx->pc = 0x101434u;
    // NOP
    // 0x101438: 0x0  nop
    ctx->pc = 0x101438u;
    // NOP
    // 0x10143c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10143Cu;
    {
        const bool branch_taken_0x10143c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x10143c) {
            ctx->pc = 0x101428u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101428;
        }
    }
    ctx->pc = 0x101444u;
label_101444:
    // 0x101444: 0x26b0a1d0  addiu       $s0, $s5, -0x5E30
    ctx->pc = 0x101444u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294943184));
label_101448:
    // 0x101448: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x101448u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x10144c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10144cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101450: 0x34a5059a  ori         $a1, $a1, 0x59A
    ctx->pc = 0x101450u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1434);
    // 0x101454: 0xc045e06  jal         func_117818
    ctx->pc = 0x101454u;
    SET_GPR_U32(ctx, 31, 0x10145Cu);
    ctx->pc = 0x101458u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101454u;
            // 0x101458: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10145Cu; }
        if (ctx->pc != 0x10145Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10145Cu; }
        if (ctx->pc != 0x10145Cu) { return; }
    }
    ctx->pc = 0x10145Cu;
label_10145c:
    // 0x10145c: 0x4430013  bgezl       $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x10145Cu;
    {
        const bool branch_taken_0x10145c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x10145c) {
            ctx->pc = 0x101460u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10145Cu;
            // 0x101460: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1014ACu;
            goto label_1014ac;
        }
    }
    ctx->pc = 0x101464u;
    // 0x101464: 0x8ec27910  lw          $v0, 0x7910($s6)
    ctx->pc = 0x101464u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 30992)));
    // 0x101468: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x101468u;
    {
        const bool branch_taken_0x101468 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x10146Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101468u;
            // 0x10146c: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101468) {
            ctx->pc = 0x101480u;
            goto label_101480;
        }
    }
    ctx->pc = 0x101470u;
    // 0x101470: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x101470u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x101474: 0xc045a12  jal         func_116848
    ctx->pc = 0x101474u;
    SET_GPR_U32(ctx, 31, 0x10147Cu);
    ctx->pc = 0x101478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101474u;
            // 0x101478: 0x24847600  addiu       $a0, $a0, 0x7600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10147Cu; }
        if (ctx->pc != 0x10147Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10147Cu; }
        if (ctx->pc != 0x10147Cu) { return; }
    }
    ctx->pc = 0x10147Cu;
label_10147c:
    // 0x10147c: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x10147cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
label_101480:
    // 0x101480: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x101480u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x101484: 0x0  nop
    ctx->pc = 0x101484u;
    // NOP
label_101488:
    // 0x101488: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x101488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10148c: 0x0  nop
    ctx->pc = 0x10148cu;
    // NOP
    // 0x101490: 0x0  nop
    ctx->pc = 0x101490u;
    // NOP
    // 0x101494: 0x0  nop
    ctx->pc = 0x101494u;
    // NOP
    // 0x101498: 0x0  nop
    ctx->pc = 0x101498u;
    // NOP
    // 0x10149c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10149Cu;
    {
        const bool branch_taken_0x10149c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x10149c) {
            ctx->pc = 0x101488u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101488;
        }
    }
    ctx->pc = 0x1014A4u;
    // 0x1014a4: 0x1000ffe8  b           . + 4 + (-0x18 << 2)
    ctx->pc = 0x1014A4u;
    {
        const bool branch_taken_0x1014a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1014A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1014A4u;
            // 0x1014a8: 0x26b0a1d0  addiu       $s0, $s5, -0x5E30 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294943184));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1014a4) {
            ctx->pc = 0x101448u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101448;
        }
    }
    ctx->pc = 0x1014ACu;
label_1014ac:
    // 0x1014ac: 0x1040ffdc  beqz        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x1014ACu;
    {
        const bool branch_taken_0x1014ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1014B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1014ACu;
            // 0x1014b0: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1014ac) {
            ctx->pc = 0x101420u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101420;
        }
    }
    ctx->pc = 0x1014B4u;
    // 0x1014b4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1014B4u;
    {
        const bool branch_taken_0x1014b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1014B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1014B4u;
            // 0x1014b8: 0xae207948  sw          $zero, 0x7948($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 31048), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1014b4) {
            ctx->pc = 0x1014C4u;
            goto label_1014c4;
        }
    }
    ctx->pc = 0x1014BCu;
label_1014bc:
    // 0x1014bc: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x1014bcu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x1014c0: 0x3c170021  lui         $s7, 0x21
    ctx->pc = 0x1014c0u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)33 << 16));
label_1014c4:
    // 0x1014c4: 0x2690a210  addiu       $s0, $s4, -0x5DF0
    ctx->pc = 0x1014c4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 20), 4294943248));
    // 0x1014c8: 0xae92a210  sw          $s2, -0x5DF0($s4)
    ctx->pc = 0x1014c8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4294943248), GPR_U32(ctx, 18));
    // 0x1014cc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1014ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1014d0: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x1014D0u;
    SET_GPR_U32(ctx, 31, 0x1014D8u);
    ctx->pc = 0x1014D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1014D0u;
            // 0x1014d4: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1014D8u; }
        if (ctx->pc != 0x1014D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1014D8u; }
        if (ctx->pc != 0x1014D8u) { return; }
    }
    ctx->pc = 0x1014D8u;
label_1014d8:
    // 0x1014d8: 0x26f18b00  addiu       $s1, $s7, -0x7500
    ctx->pc = 0x1014d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 23), 4294937344));
    // 0x1014dc: 0x26a4a1d0  addiu       $a0, $s5, -0x5E30
    ctx->pc = 0x1014dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294943184));
    // 0x1014e0: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1014e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1014e4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1014e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1014e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1014e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1014ec: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1014ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1014f0: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x1014f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1014f4: 0x220482d  daddu       $t1, $s1, $zero
    ctx->pc = 0x1014f4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1014f8: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x1014f8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1014fc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1014FCu;
    SET_GPR_U32(ctx, 31, 0x101504u);
    ctx->pc = 0x101500u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1014FCu;
            // 0x101500: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101504u; }
        if (ctx->pc != 0x101504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101504u; }
        if (ctx->pc != 0x101504u) { return; }
    }
    ctx->pc = 0x101504u;
label_101504:
    // 0x101504: 0x4430009  bgezl       $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x101504u;
    {
        const bool branch_taken_0x101504 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x101504) {
            ctx->pc = 0x101508u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x101504u;
            // 0x101508: 0x8ec27910  lw          $v0, 0x7910($s6) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 30992)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10152Cu;
            goto label_10152c;
        }
    }
    ctx->pc = 0x10150Cu;
label_10150c:
    // 0x10150c: 0x8e64792c  lw          $a0, 0x792C($s3)
    ctx->pc = 0x10150cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 31020)));
    // 0x101510: 0xc045190  jal         func_114640
    ctx->pc = 0x101510u;
    SET_GPR_U32(ctx, 31, 0x101518u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101518u; }
        if (ctx->pc != 0x101518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101518u; }
        if (ctx->pc != 0x101518u) { return; }
    }
    ctx->pc = 0x101518u;
label_101518:
    // 0x101518: 0x3a440008  xori        $a0, $s2, 0x8
    ctx->pc = 0x101518u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) ^ (uint64_t)(uint16_t)8);
    // 0x10151c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10151cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x101520: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x101520u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x101524: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x101524u;
    {
        const bool branch_taken_0x101524 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101524u;
            // 0x101528: 0x64100a  movz        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101524) {
            ctx->pc = 0x101554u;
            goto label_101554;
        }
    }
    ctx->pc = 0x10152Cu;
label_10152c:
    // 0x10152c: 0x18400003  blez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10152Cu;
    {
        const bool branch_taken_0x10152c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x101530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10152Cu;
            // 0x101530: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10152c) {
            ctx->pc = 0x10153Cu;
            goto label_10153c;
        }
    }
    ctx->pc = 0x101534u;
    // 0x101534: 0xc045a12  jal         func_116848
    ctx->pc = 0x101534u;
    SET_GPR_U32(ctx, 31, 0x10153Cu);
    ctx->pc = 0x101538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101534u;
            // 0x101538: 0x24847620  addiu       $a0, $a0, 0x7620 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10153Cu; }
        if (ctx->pc != 0x10153Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10153Cu; }
        if (ctx->pc != 0x10153Cu) { return; }
    }
    ctx->pc = 0x10153Cu;
label_10153c:
    // 0x10153c: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x10153cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x101540: 0x8e64792c  lw          $a0, 0x792C($s3)
    ctx->pc = 0x101540u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 31020)));
    // 0x101544: 0x2221025  or          $v0, $s1, $v0
    ctx->pc = 0x101544u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x101548: 0xc045190  jal         func_114640
    ctx->pc = 0x101548u;
    SET_GPR_U32(ctx, 31, 0x101550u);
    ctx->pc = 0x10154Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101548u;
            // 0x10154c: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101550u; }
        if (ctx->pc != 0x101550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101550u; }
        if (ctx->pc != 0x101550u) { return; }
    }
    ctx->pc = 0x101550u;
label_101550:
    // 0x101550: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101550u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101554:
    // 0x101554: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x101554u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x101558: 0xdfb70080  ld          $s7, 0x80($sp)
    ctx->pc = 0x101558u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x10155c: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x10155cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x101560: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x101560u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x101564: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x101564u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x101568: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x101568u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x10156c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x10156cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101570: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101570u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101574: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x101574u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101578: 0x3e00008  jr          $ra
    ctx->pc = 0x101578u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10157Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101578u;
            // 0x10157c: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101388u: goto label_101388;
            case 0x1013CCu: goto label_1013cc;
            case 0x1013D4u: goto label_1013d4;
            case 0x1013E0u: goto label_1013e0;
            case 0x1013F4u: goto label_1013f4;
            case 0x101404u: goto label_101404;
            case 0x101420u: goto label_101420;
            case 0x101428u: goto label_101428;
            case 0x101444u: goto label_101444;
            case 0x101448u: goto label_101448;
            case 0x10145Cu: goto label_10145c;
            case 0x10147Cu: goto label_10147c;
            case 0x101480u: goto label_101480;
            case 0x101488u: goto label_101488;
            case 0x1014ACu: goto label_1014ac;
            case 0x1014BCu: goto label_1014bc;
            case 0x1014C4u: goto label_1014c4;
            case 0x1014D8u: goto label_1014d8;
            case 0x101504u: goto label_101504;
            case 0x10150Cu: goto label_10150c;
            case 0x101518u: goto label_101518;
            case 0x10152Cu: goto label_10152c;
            case 0x10153Cu: goto label_10153c;
            case 0x101550u: goto label_101550;
            case 0x101554u: goto label_101554;
            case 0x1015C0u: goto label_1015c0;
            case 0x1015C8u: goto label_1015c8;
            case 0x1015D4u: goto label_1015d4;
            case 0x1015ECu: goto label_1015ec;
            case 0x101600u: goto label_101600;
            case 0x101610u: goto label_101610;
            case 0x101630u: goto label_101630;
            case 0x101634u: goto label_101634;
            case 0x101648u: goto label_101648;
            case 0x101668u: goto label_101668;
            case 0x10166Cu: goto label_10166c;
            case 0x101670u: goto label_101670;
            case 0x101694u: goto label_101694;
            case 0x1016A4u: goto label_1016a4;
            case 0x1016A8u: goto label_1016a8;
            case 0x1016C0u: goto label_1016c0;
            case 0x1016F0u: goto label_1016f0;
            case 0x101704u: goto label_101704;
            case 0x101708u: goto label_101708;
            case 0x101718u: goto label_101718;
            case 0x101724u: goto label_101724;
            case 0x10172Cu: goto label_10172c;
            case 0x101734u: goto label_101734;
            case 0x101744u: goto label_101744;
            case 0x101758u: goto label_101758;
            case 0x10175Cu: goto label_10175c;
            case 0x101760u: goto label_101760;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101580u;
    // 0x101580: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x101580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x101584: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x101584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x101588: 0x3c160020  lui         $s6, 0x20
    ctx->pc = 0x101588u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)32 << 16));
    // 0x10158c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x10158cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x101590: 0x8ec27910  lw          $v0, 0x7910($s6)
    ctx->pc = 0x101590u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 30992)));
    // 0x101594: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x101594u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101598: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x101598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x10159c: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x10159cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1015a0: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x1015a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x1015a4: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1015a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1015a8: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1015a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1015ac: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1015ACu;
    {
        const bool branch_taken_0x1015ac = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1015B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1015ACu;
            // 0x1015b0: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1015ac) {
            ctx->pc = 0x1015C0u;
            goto label_1015c0;
        }
    }
    ctx->pc = 0x1015B4u;
    // 0x1015b4: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1015b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1015b8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1015B8u;
    SET_GPR_U32(ctx, 31, 0x1015C0u);
    ctx->pc = 0x1015BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1015B8u;
            // 0x1015bc: 0x24847638  addiu       $a0, $a0, 0x7638 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015C0u; }
        if (ctx->pc != 0x1015C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015C0u; }
        if (ctx->pc != 0x1015C0u) { return; }
    }
    ctx->pc = 0x1015C0u;
label_1015c0:
    // 0x1015c0: 0xc040164  jal         func_100590
    ctx->pc = 0x1015C0u;
    SET_GPR_U32(ctx, 31, 0x1015C8u);
    ctx->pc = 0x1015C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1015C0u;
            // 0x1015c4: 0x3c140020  lui         $s4, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100590u;
    if (runtime->hasFunction(0x100590u)) {
        auto targetFn = runtime->lookupFunction(0x100590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015C8u; }
        if (ctx->pc != 0x1015C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015C8u; }
        if (ctx->pc != 0x1015C8u) { return; }
    }
    ctx->pc = 0x1015C8u;
label_1015c8:
    // 0x1015c8: 0x8e847930  lw          $a0, 0x7930($s4)
    ctx->pc = 0x1015c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 31024)));
    // 0x1015cc: 0xc04519c  jal         func_114670
    ctx->pc = 0x1015CCu;
    SET_GPR_U32(ctx, 31, 0x1015D4u);
    ctx->pc = 0x114670u;
    if (runtime->hasFunction(0x114670u)) {
        auto targetFn = runtime->lookupFunction(0x114670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015D4u; }
        if (ctx->pc != 0x1015D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015D4u; }
        if (ctx->pc != 0x1015D4u) { return; }
    }
    ctx->pc = 0x1015D4u;
label_1015d4:
    // 0x1015d4: 0x8e837930  lw          $v1, 0x7930($s4)
    ctx->pc = 0x1015d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 31024)));
    // 0x1015d8: 0x1462004b  bne         $v1, $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x1015D8u;
    {
        const bool branch_taken_0x1015d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1015DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1015D8u;
            // 0x1015dc: 0x3a440008  xori        $a0, $s2, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) ^ (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1015d8) {
            ctx->pc = 0x101708u;
            goto label_101708;
        }
    }
    ctx->pc = 0x1015E0u;
    // 0x1015e0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1015e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1015e4: 0xc045c20  jal         func_117080
    ctx->pc = 0x1015E4u;
    SET_GPR_U32(ctx, 31, 0x1015ECu);
    ctx->pc = 0x1015E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1015E4u;
            // 0x1015e8: 0x3c130020  lui         $s3, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015ECu; }
        if (ctx->pc != 0x1015ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1015ECu; }
        if (ctx->pc != 0x1015ECu) { return; }
    }
    ctx->pc = 0x1015ECu;
label_1015ec:
    // 0x1015ec: 0x8e627948  lw          $v0, 0x7948($s3)
    ctx->pc = 0x1015ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 31048)));
    // 0x1015f0: 0x441002c  bgez        $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1015F0u;
    {
        const bool branch_taken_0x1015f0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1015F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1015F0u;
            // 0x1015f4: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1015f0) {
            ctx->pc = 0x1016A4u;
            goto label_1016a4;
        }
    }
    ctx->pc = 0x1015F8u;
    // 0x1015f8: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1015F8u;
    {
        const bool branch_taken_0x1015f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1015FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1015F8u;
            // 0x1015fc: 0x3c150026  lui         $s5, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1015f8) {
            ctx->pc = 0x101630u;
            goto label_101630;
        }
    }
    ctx->pc = 0x101600u;
label_101600:
    // 0x101600: 0x10400045  beqz        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x101600u;
    {
        const bool branch_taken_0x101600 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101600u;
            // 0x101604: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101600) {
            ctx->pc = 0x101718u;
            goto label_101718;
        }
    }
    ctx->pc = 0x101608u;
    // 0x101608: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x101608u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
    // 0x10160c: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x10160cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_101610:
    // 0x101610: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x101610u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x101614: 0x0  nop
    ctx->pc = 0x101614u;
    // NOP
    // 0x101618: 0x0  nop
    ctx->pc = 0x101618u;
    // NOP
    // 0x10161c: 0x0  nop
    ctx->pc = 0x10161cu;
    // NOP
    // 0x101620: 0x0  nop
    ctx->pc = 0x101620u;
    // NOP
    // 0x101624: 0x1464fffa  bne         $v1, $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x101624u;
    {
        const bool branch_taken_0x101624 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x101624) {
            ctx->pc = 0x101610u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101610;
        }
    }
    ctx->pc = 0x10162Cu;
    // 0x10162c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10162cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_101630:
    // 0x101630: 0x26b0a1d0  addiu       $s0, $s5, -0x5E30
    ctx->pc = 0x101630u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294943184));
label_101634:
    // 0x101634: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x101634u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x101638: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x101638u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10163c: 0x34a5059c  ori         $a1, $a1, 0x59C
    ctx->pc = 0x10163cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1436);
    // 0x101640: 0xc045e06  jal         func_117818
    ctx->pc = 0x101640u;
    SET_GPR_U32(ctx, 31, 0x101648u);
    ctx->pc = 0x101644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101640u;
            // 0x101644: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101648u; }
        if (ctx->pc != 0x101648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101648u; }
        if (ctx->pc != 0x101648u) { return; }
    }
    ctx->pc = 0x101648u;
label_101648:
    // 0x101648: 0x4430012  bgezl       $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x101648u;
    {
        const bool branch_taken_0x101648 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x101648) {
            ctx->pc = 0x10164Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x101648u;
            // 0x10164c: 0x8e020024  lw          $v0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x101694u;
            goto label_101694;
        }
    }
    ctx->pc = 0x101650u;
    // 0x101650: 0x8ec27910  lw          $v0, 0x7910($s6)
    ctx->pc = 0x101650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 30992)));
    // 0x101654: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x101654u;
    {
        const bool branch_taken_0x101654 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x101658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101654u;
            // 0x101658: 0x3c030010  lui         $v1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101654) {
            ctx->pc = 0x10166Cu;
            goto label_10166c;
        }
    }
    ctx->pc = 0x10165Cu;
    // 0x10165c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x10165cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x101660: 0xc045a12  jal         func_116848
    ctx->pc = 0x101660u;
    SET_GPR_U32(ctx, 31, 0x101668u);
    ctx->pc = 0x101664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101660u;
            // 0x101664: 0x24847600  addiu       $a0, $a0, 0x7600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101668u; }
        if (ctx->pc != 0x101668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101668u; }
        if (ctx->pc != 0x101668u) { return; }
    }
    ctx->pc = 0x101668u;
label_101668:
    // 0x101668: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x101668u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
label_10166c:
    // 0x10166c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10166cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_101670:
    // 0x101670: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x101670u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x101674: 0x0  nop
    ctx->pc = 0x101674u;
    // NOP
    // 0x101678: 0x0  nop
    ctx->pc = 0x101678u;
    // NOP
    // 0x10167c: 0x0  nop
    ctx->pc = 0x10167cu;
    // NOP
    // 0x101680: 0x0  nop
    ctx->pc = 0x101680u;
    // NOP
    // 0x101684: 0x1462fffa  bne         $v1, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x101684u;
    {
        const bool branch_taken_0x101684 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x101684) {
            ctx->pc = 0x101670u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101670;
        }
    }
    ctx->pc = 0x10168Cu;
    // 0x10168c: 0x1000ffe9  b           . + 4 + (-0x17 << 2)
    ctx->pc = 0x10168Cu;
    {
        const bool branch_taken_0x10168c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10168Cu;
            // 0x101690: 0x26b0a1d0  addiu       $s0, $s5, -0x5E30 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294943184));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10168c) {
            ctx->pc = 0x101634u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101634;
        }
    }
    ctx->pc = 0x101694u;
label_101694:
    // 0x101694: 0x1040ffda  beqz        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x101694u;
    {
        const bool branch_taken_0x101694 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101694u;
            // 0x101698: 0x2a220011  slti        $v0, $s1, 0x11 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)17) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101694) {
            ctx->pc = 0x101600u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_101600;
        }
    }
    ctx->pc = 0x10169Cu;
    // 0x10169c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10169Cu;
    {
        const bool branch_taken_0x10169c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1016A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10169Cu;
            // 0x1016a0: 0xae607948  sw          $zero, 0x7948($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 31048), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10169c) {
            ctx->pc = 0x1016A8u;
            goto label_1016a8;
        }
    }
    ctx->pc = 0x1016A4u;
label_1016a4:
    // 0x1016a4: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x1016a4u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
label_1016a8:
    // 0x1016a8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1016a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1016ac: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1016acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1016b0: 0x2450a210  addiu       $s0, $v0, -0x5DF0
    ctx->pc = 0x1016b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294943248));
    // 0x1016b4: 0xac52a210  sw          $s2, -0x5DF0($v0)
    ctx->pc = 0x1016b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294943248), GPR_U32(ctx, 18));
    // 0x1016b8: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x1016B8u;
    SET_GPR_U32(ctx, 31, 0x1016C0u);
    ctx->pc = 0x1016BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1016B8u;
            // 0x1016bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1016C0u; }
        if (ctx->pc != 0x1016C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1016C0u; }
        if (ctx->pc != 0x1016C0u) { return; }
    }
    ctx->pc = 0x1016C0u;
label_1016c0:
    // 0x1016c0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1016c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1016c4: 0x26a4a1d0  addiu       $a0, $s5, -0x5E30
    ctx->pc = 0x1016c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294943184));
    // 0x1016c8: 0x24519380  addiu       $s1, $v0, -0x6C80
    ctx->pc = 0x1016c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294939520));
    // 0x1016cc: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1016ccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1016d0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1016d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1016d4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1016d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1016d8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1016d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1016dc: 0x24080004  addiu       $t0, $zero, 0x4
    ctx->pc = 0x1016dcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1016e0: 0x220482d  daddu       $t1, $s1, $zero
    ctx->pc = 0x1016e0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1016e4: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x1016e4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1016e8: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1016E8u;
    SET_GPR_U32(ctx, 31, 0x1016F0u);
    ctx->pc = 0x1016ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1016E8u;
            // 0x1016ec: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1016F0u; }
        if (ctx->pc != 0x1016F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1016F0u; }
        if (ctx->pc != 0x1016F0u) { return; }
    }
    ctx->pc = 0x1016F0u;
label_1016f0:
    // 0x1016f0: 0x4430010  bgezl       $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1016F0u;
    {
        const bool branch_taken_0x1016f0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1016f0) {
            ctx->pc = 0x1016F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1016F0u;
            // 0x1016f4: 0x8ec27910  lw          $v0, 0x7910($s6) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 30992)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x101734u;
            goto label_101734;
        }
    }
    ctx->pc = 0x1016F8u;
    // 0x1016f8: 0x8e847930  lw          $a0, 0x7930($s4)
    ctx->pc = 0x1016f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 31024)));
    // 0x1016fc: 0xc045190  jal         func_114640
    ctx->pc = 0x1016FCu;
    SET_GPR_U32(ctx, 31, 0x101704u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101704u; }
        if (ctx->pc != 0x101704u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101704u; }
        if (ctx->pc != 0x101704u) { return; }
    }
    ctx->pc = 0x101704u;
label_101704:
    // 0x101704: 0x3a440008  xori        $a0, $s2, 0x8
    ctx->pc = 0x101704u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 18) ^ (uint64_t)(uint16_t)8);
label_101708:
    // 0x101708: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x101708u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10170c: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x10170cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x101710: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x101710u;
    {
        const bool branch_taken_0x101710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101710u;
            // 0x101714: 0x64100a  movz        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101710) {
            ctx->pc = 0x10175Cu;
            goto label_10175c;
        }
    }
    ctx->pc = 0x101718u;
label_101718:
    // 0x101718: 0x8e847930  lw          $a0, 0x7930($s4)
    ctx->pc = 0x101718u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 31024)));
    // 0x10171c: 0xc045190  jal         func_114640
    ctx->pc = 0x10171Cu;
    SET_GPR_U32(ctx, 31, 0x101724u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101724u; }
        if (ctx->pc != 0x101724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101724u; }
        if (ctx->pc != 0x101724u) { return; }
    }
    ctx->pc = 0x101724u;
label_101724:
    // 0x101724: 0xc0404e2  jal         func_101388
    ctx->pc = 0x101724u;
    SET_GPR_U32(ctx, 31, 0x10172Cu);
    ctx->pc = 0x101728u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101724u;
            // 0x101728: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101388u;
    goto label_101388;
    ctx->pc = 0x10172Cu;
label_10172c:
    // 0x10172c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x10172Cu;
    {
        const bool branch_taken_0x10172c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10172Cu;
            // 0x101730: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10172c) {
            ctx->pc = 0x101760u;
            goto label_101760;
        }
    }
    ctx->pc = 0x101734u;
label_101734:
    // 0x101734: 0x18400003  blez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101734u;
    {
        const bool branch_taken_0x101734 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x101738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101734u;
            // 0x101738: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101734) {
            ctx->pc = 0x101744u;
            goto label_101744;
        }
    }
    ctx->pc = 0x10173Cu;
    // 0x10173c: 0xc045a12  jal         func_116848
    ctx->pc = 0x10173Cu;
    SET_GPR_U32(ctx, 31, 0x101744u);
    ctx->pc = 0x101740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10173Cu;
            // 0x101740: 0x24847620  addiu       $a0, $a0, 0x7620 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101744u; }
        if (ctx->pc != 0x101744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101744u; }
        if (ctx->pc != 0x101744u) { return; }
    }
    ctx->pc = 0x101744u;
label_101744:
    // 0x101744: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x101744u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x101748: 0x8e847930  lw          $a0, 0x7930($s4)
    ctx->pc = 0x101748u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 31024)));
    // 0x10174c: 0x2221025  or          $v0, $s1, $v0
    ctx->pc = 0x10174cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x101750: 0xc045190  jal         func_114640
    ctx->pc = 0x101750u;
    SET_GPR_U32(ctx, 31, 0x101758u);
    ctx->pc = 0x101754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101750u;
            // 0x101754: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101758u; }
        if (ctx->pc != 0x101758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101758u; }
        if (ctx->pc != 0x101758u) { return; }
    }
    ctx->pc = 0x101758u;
label_101758:
    // 0x101758: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101758u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_10175c:
    // 0x10175c: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x10175cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_101760:
    // 0x101760: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x101760u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x101764: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x101764u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x101768: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x101768u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x10176c: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x10176cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101770: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x101770u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101774: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101774u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101778: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x101778u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10177c: 0x3e00008  jr          $ra
    ctx->pc = 0x10177Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10177Cu;
            // 0x101780: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101388u: goto label_101388;
            case 0x1013CCu: goto label_1013cc;
            case 0x1013D4u: goto label_1013d4;
            case 0x1013E0u: goto label_1013e0;
            case 0x1013F4u: goto label_1013f4;
            case 0x101404u: goto label_101404;
            case 0x101420u: goto label_101420;
            case 0x101428u: goto label_101428;
            case 0x101444u: goto label_101444;
            case 0x101448u: goto label_101448;
            case 0x10145Cu: goto label_10145c;
            case 0x10147Cu: goto label_10147c;
            case 0x101480u: goto label_101480;
            case 0x101488u: goto label_101488;
            case 0x1014ACu: goto label_1014ac;
            case 0x1014BCu: goto label_1014bc;
            case 0x1014C4u: goto label_1014c4;
            case 0x1014D8u: goto label_1014d8;
            case 0x101504u: goto label_101504;
            case 0x10150Cu: goto label_10150c;
            case 0x101518u: goto label_101518;
            case 0x10152Cu: goto label_10152c;
            case 0x10153Cu: goto label_10153c;
            case 0x101550u: goto label_101550;
            case 0x101554u: goto label_101554;
            case 0x1015C0u: goto label_1015c0;
            case 0x1015C8u: goto label_1015c8;
            case 0x1015D4u: goto label_1015d4;
            case 0x1015ECu: goto label_1015ec;
            case 0x101600u: goto label_101600;
            case 0x101610u: goto label_101610;
            case 0x101630u: goto label_101630;
            case 0x101634u: goto label_101634;
            case 0x101648u: goto label_101648;
            case 0x101668u: goto label_101668;
            case 0x10166Cu: goto label_10166c;
            case 0x101670u: goto label_101670;
            case 0x101694u: goto label_101694;
            case 0x1016A4u: goto label_1016a4;
            case 0x1016A8u: goto label_1016a8;
            case 0x1016C0u: goto label_1016c0;
            case 0x1016F0u: goto label_1016f0;
            case 0x101704u: goto label_101704;
            case 0x101708u: goto label_101708;
            case 0x101718u: goto label_101718;
            case 0x101724u: goto label_101724;
            case 0x10172Cu: goto label_10172c;
            case 0x101734u: goto label_101734;
            case 0x101744u: goto label_101744;
            case 0x101758u: goto label_101758;
            case 0x10175Cu: goto label_10175c;
            case 0x101760u: goto label_101760;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101784u;
    // 0x101784: 0x0  nop
    ctx->pc = 0x101784u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

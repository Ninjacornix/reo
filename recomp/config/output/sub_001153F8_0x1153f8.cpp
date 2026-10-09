#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001153F8
// Address: 0x1153f8 - 0x1154d0
void sub_001153F8_0x1153f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001153F8_0x1153f8");
#endif

    switch (ctx->pc) {
        case 0x115428u: goto label_115428;
        case 0x11546cu: goto label_11546c;
        case 0x115480u: goto label_115480;
        case 0x1154a0u: goto label_1154a0;
        case 0x1154a8u: goto label_1154a8;
        case 0x1154b4u: goto label_1154b4;
        default: break;
    }

    ctx->pc = 0x1153f8u;

    // 0x1153f8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1153f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1153fc: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x1153fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x115400: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x115400u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x115404: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x115404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x115408: 0x8e029d38  lw          $v0, -0x62C8($s0)
    ctx->pc = 0x115408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942008)));
    // 0x11540c: 0x1c40001c  bgtz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x11540Cu;
    {
        const bool branch_taken_0x11540c = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x115410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11540Cu;
            // 0x115410: 0xffb10060  sd          $s1, 0x60($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11540c) {
            ctx->pc = 0x115480u;
            goto label_115480;
        }
    }
    ctx->pc = 0x115414u;
    // 0x115414: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x115414u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x115418: 0xafa00038  sw          $zero, 0x38($sp)
    ctx->pc = 0x115418u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
    // 0x11541c: 0xafa20034  sw          $v0, 0x34($sp)
    ctx->pc = 0x11541cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 2));
    // 0x115420: 0xc045188  jal         func_114620
    ctx->pc = 0x115420u;
    SET_GPR_U32(ctx, 31, 0x115428u);
    ctx->pc = 0x115424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115420u;
            // 0x115424: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115428u; }
        if (ctx->pc != 0x115428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115428u; }
        if (ctx->pc != 0x115428u) { return; }
    }
    ctx->pc = 0x115428u;
label_115428:
    // 0x115428: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x115428u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x11542c: 0x4400014  bltz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x11542Cu;
    {
        const bool branch_taken_0x11542c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x115430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11542Cu;
            // 0x115430: 0xae22a630  sw          $v0, -0x59D0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4294944304), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11542c) {
            ctx->pc = 0x115480u;
            goto label_115480;
        }
    }
    ctx->pc = 0x115434u;
    // 0x115434: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x115434u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x115438: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x115438u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11543c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11543cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x115440: 0x24425320  addiu       $v0, $v0, 0x5320
    ctx->pc = 0x115440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21280));
    // 0x115444: 0x2463a230  addiu       $v1, $v1, -0x5DD0
    ctx->pc = 0x115444u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294943280));
    // 0x115448: 0x24a51cf0  addiu       $a1, $a1, 0x1CF0
    ctx->pc = 0x115448u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7408));
    // 0x11544c: 0x24060400  addiu       $a2, $zero, 0x400
    ctx->pc = 0x11544cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x115450: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x115450u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x115454: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x115454u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x115458: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x115458u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11545c: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x11545cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x115460: 0xafa50010  sw          $a1, 0x10($sp)
    ctx->pc = 0x115460u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x115464: 0xc045108  jal         func_114420
    ctx->pc = 0x115464u;
    SET_GPR_U32(ctx, 31, 0x11546Cu);
    ctx->pc = 0x115468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115464u;
            // 0x115468: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114420u;
    if (runtime->hasFunction(0x114420u)) {
        auto targetFn = runtime->lookupFunction(0x114420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11546Cu; }
        if (ctx->pc != 0x11546Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114420_0x114420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11546Cu; }
        if (ctx->pc != 0x11546Cu) { return; }
    }
    ctx->pc = 0x11546Cu;
label_11546c:
    // 0x11546c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11546cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115470: 0x4810005  bgez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x115470u;
    {
        const bool branch_taken_0x115470 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x115474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115470u;
            // 0x115474: 0xae049d38  sw          $a0, -0x62C8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4294942008), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115470) {
            ctx->pc = 0x115488u;
            goto label_115488;
        }
    }
    ctx->pc = 0x115478u;
    // 0x115478: 0xc04518c  jal         func_114630
    ctx->pc = 0x115478u;
    SET_GPR_U32(ctx, 31, 0x115480u);
    ctx->pc = 0x11547Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115478u;
            // 0x11547c: 0x8e24a630  lw          $a0, -0x59D0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294944304)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115480u; }
        if (ctx->pc != 0x115480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115480u; }
        if (ctx->pc != 0x115480u) { return; }
    }
    ctx->pc = 0x115480u;
label_115480:
    // 0x115480: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x115480u;
    {
        const bool branch_taken_0x115480 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115480u;
            // 0x115484: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115480) {
            ctx->pc = 0x1154B8u;
            goto label_1154b8;
        }
    }
    ctx->pc = 0x115488u;
label_115488:
    // 0x115488: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x115488u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x11548c: 0x2443a638  addiu       $v1, $v0, -0x59C8
    ctx->pc = 0x11548cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944312));
    // 0x115490: 0xac40a638  sw          $zero, -0x59C8($v0)
    ctx->pc = 0x115490u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294944312), GPR_U32(ctx, 0));
    // 0x115494: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x115494u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115498: 0xc045110  jal         func_114440
    ctx->pc = 0x115498u;
    SET_GPR_U32(ctx, 31, 0x1154A0u);
    ctx->pc = 0x11549Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115498u;
            // 0x11549c: 0xac600004  sw          $zero, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114440u;
    if (runtime->hasFunction(0x114440u)) {
        auto targetFn = runtime->lookupFunction(0x114440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154A0u; }
        if (ctx->pc != 0x1154A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114440_0x114440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154A0u; }
        if (ctx->pc != 0x1154A0u) { return; }
    }
    ctx->pc = 0x1154A0u;
label_1154a0:
    // 0x1154a0: 0xc045144  jal         func_114510
    ctx->pc = 0x1154A0u;
    SET_GPR_U32(ctx, 31, 0x1154A8u);
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154A8u; }
        if (ctx->pc != 0x1154A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154A8u; }
        if (ctx->pc != 0x1154A8u) { return; }
    }
    ctx->pc = 0x1154A8u;
label_1154a8:
    // 0x1154a8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1154a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1154ac: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x1154ACu;
    SET_GPR_U32(ctx, 31, 0x1154B4u);
    ctx->pc = 0x1154B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1154ACu;
            // 0x1154b0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154B4u; }
        if (ctx->pc != 0x1154B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1154B4u; }
        if (ctx->pc != 0x1154B4u) { return; }
    }
    ctx->pc = 0x1154B4u;
label_1154b4:
    // 0x1154b4: 0x8e029d38  lw          $v0, -0x62C8($s0)
    ctx->pc = 0x1154b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942008)));
label_1154b8:
    // 0x1154b8: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1154b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1154bc: 0xdfb10060  ld          $s1, 0x60($sp)
    ctx->pc = 0x1154bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1154c0: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x1154c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1154c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1154C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1154C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1154C4u;
            // 0x1154c8: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115428u: goto label_115428;
            case 0x11546Cu: goto label_11546c;
            case 0x115480u: goto label_115480;
            case 0x115488u: goto label_115488;
            case 0x1154A0u: goto label_1154a0;
            case 0x1154A8u: goto label_1154a8;
            case 0x1154B4u: goto label_1154b4;
            case 0x1154B8u: goto label_1154b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1154CCu;
    // 0x1154cc: 0x0  nop
    ctx->pc = 0x1154ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

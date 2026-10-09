#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001187A0
// Address: 0x1187a0 - 0x1189a8
void sub_001187A0_0x1187a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001187A0_0x1187a0");
#endif

    switch (ctx->pc) {
        case 0x1187ccu: goto label_1187cc;
        case 0x1187d8u: goto label_1187d8;
        case 0x1187f8u: goto label_1187f8;
        case 0x118810u: goto label_118810;
        case 0x118820u: goto label_118820;
        case 0x118828u: goto label_118828;
        case 0x118830u: goto label_118830;
        case 0x118864u: goto label_118864;
        case 0x118880u: goto label_118880;
        case 0x118888u: goto label_118888;
        case 0x1188a8u: goto label_1188a8;
        case 0x1188e0u: goto label_1188e0;
        case 0x118918u: goto label_118918;
        default: break;
    }

    ctx->pc = 0x1187a0u;

    // 0x1187a0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1187a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1187a4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1187a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1187a8: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1187a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1187ac: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1187acu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x1187b0: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x1187b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x1187b4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1187b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1187b8: 0x2611e1c0  addiu       $s1, $s0, -0x1E40
    ctx->pc = 0x1187b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4294959552));
    // 0x1187bc: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x1187bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x1187c0: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x1187c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x1187c4: 0xc045c20  jal         func_117080
    ctx->pc = 0x1187C4u;
    SET_GPR_U32(ctx, 31, 0x1187CCu);
    ctx->pc = 0x1187C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1187C4u;
            // 0x1187c8: 0xffb20040  sd          $s2, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187CCu; }
        if (ctx->pc != 0x1187CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187CCu; }
        if (ctx->pc != 0x1187CCu) { return; }
    }
    ctx->pc = 0x1187CCu;
label_1187cc:
    // 0x1187cc: 0xae00e1c0  sw          $zero, -0x1E40($s0)
    ctx->pc = 0x1187ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294959552), GPR_U32(ctx, 0));
    // 0x1187d0: 0xc047598  jal         func_11D660
    ctx->pc = 0x1187D0u;
    SET_GPR_U32(ctx, 31, 0x1187D8u);
    ctx->pc = 0x1187D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1187D0u;
            // 0x1187d4: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187D8u; }
        if (ctx->pc != 0x1187D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187D8u; }
        if (ctx->pc != 0x1187D8u) { return; }
    }
    ctx->pc = 0x1187D8u;
label_1187d8:
    // 0x1187d8: 0x3c050012  lui         $a1, 0x12
    ctx->pc = 0x1187d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)18 << 16));
    // 0x1187dc: 0x3c060026  lui         $a2, 0x26
    ctx->pc = 0x1187dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)38 << 16));
    // 0x1187e0: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1187e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1187e4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1187e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1187e8: 0x24a58268  addiu       $a1, $a1, -0x7D98
    ctx->pc = 0x1187e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294935144));
    // 0x1187ec: 0x24c6e180  addiu       $a2, $a2, -0x1E80
    ctx->pc = 0x1187ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294959488));
    // 0x1187f0: 0xc045b02  jal         func_116C08
    ctx->pc = 0x1187F0u;
    SET_GPR_U32(ctx, 31, 0x1187F8u);
    ctx->pc = 0x1187F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1187F0u;
            // 0x1187f4: 0x34840011  ori         $a0, $a0, 0x11 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)17);
        ctx->in_delay_slot = false;
    ctx->pc = 0x116C08u;
    if (runtime->hasFunction(0x116C08u)) {
        auto targetFn = runtime->lookupFunction(0x116C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187F8u; }
        if (ctx->pc != 0x1187F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116C08_0x116c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1187F8u; }
        if (ctx->pc != 0x1187F8u) { return; }
    }
    ctx->pc = 0x1187F8u;
label_1187f8:
    // 0x1187f8: 0x3c050012  lui         $a1, 0x12
    ctx->pc = 0x1187f8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)18 << 16));
    // 0x1187fc: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1187fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x118800: 0x24a58758  addiu       $a1, $a1, -0x78A8
    ctx->pc = 0x118800u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294936408));
    // 0x118804: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x118804u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118808: 0xc045b02  jal         func_116C08
    ctx->pc = 0x118808u;
    SET_GPR_U32(ctx, 31, 0x118810u);
    ctx->pc = 0x11880Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118808u;
            // 0x11880c: 0x34840013  ori         $a0, $a0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
    ctx->pc = 0x116C08u;
    if (runtime->hasFunction(0x116C08u)) {
        auto targetFn = runtime->lookupFunction(0x116C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118810u; }
        if (ctx->pc != 0x118810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116C08_0x116c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118810u; }
        if (ctx->pc != 0x118810u) { return; }
    }
    ctx->pc = 0x118810u;
label_118810:
    // 0x118810: 0x1200000e  beqz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x118810u;
    {
        const bool branch_taken_0x118810 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x118814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118810u;
            // 0x118814: 0x3c130026  lui         $s3, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118810) {
            ctx->pc = 0x11884Cu;
            goto label_11884c;
        }
    }
    ctx->pc = 0x118818u;
    // 0x118818: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x118818u;
    SET_GPR_U32(ctx, 31, 0x118820u);
    ctx->pc = 0x11881Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118818u;
            // 0x11881c: 0x2670e140  addiu       $s0, $s3, -0x1EC0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294959424));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118820u; }
        if (ctx->pc != 0x118820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118820u; }
        if (ctx->pc != 0x118820u) { return; }
    }
    ctx->pc = 0x118820u;
label_118820:
    // 0x118820: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x118820u;
    {
        const bool branch_taken_0x118820 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x118820) {
            ctx->pc = 0x118850u;
            goto label_118850;
        }
    }
    ctx->pc = 0x118828u;
label_118828:
    // 0x118828: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x118828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11882c: 0x0  nop
    ctx->pc = 0x11882cu;
    // NOP
label_118830:
    // 0x118830: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x118830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x118834: 0x0  nop
    ctx->pc = 0x118834u;
    // NOP
    // 0x118838: 0x0  nop
    ctx->pc = 0x118838u;
    // NOP
    // 0x11883c: 0x0  nop
    ctx->pc = 0x11883cu;
    // NOP
    // 0x118840: 0x0  nop
    ctx->pc = 0x118840u;
    // NOP
    // 0x118844: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x118844u;
    {
        const bool branch_taken_0x118844 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x118844) {
            ctx->pc = 0x118830u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118830;
        }
    }
    ctx->pc = 0x11884Cu;
label_11884c:
    // 0x11884c: 0x2670e140  addiu       $s0, $s3, -0x1EC0
    ctx->pc = 0x11884cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294959424));
label_118850:
    // 0x118850: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x118850u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x118854: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x118854u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118858: 0x34a50001  ori         $a1, $a1, 0x1
    ctx->pc = 0x118858u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1);
    // 0x11885c: 0xc045e06  jal         func_117818
    ctx->pc = 0x11885Cu;
    SET_GPR_U32(ctx, 31, 0x118864u);
    ctx->pc = 0x118860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11885Cu;
            // 0x118860: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118864u; }
        if (ctx->pc != 0x118864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118864u; }
        if (ctx->pc != 0x118864u) { return; }
    }
    ctx->pc = 0x118864u;
label_118864:
    // 0x118864: 0x4400047  bltz        $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x118864u;
    {
        const bool branch_taken_0x118864 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x118868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118864u;
            // 0x118868: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118864) {
            ctx->pc = 0x118984u;
            goto label_118984;
        }
    }
    ctx->pc = 0x11886Cu;
    // 0x11886c: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x11886cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x118870: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x118870u;
    {
        const bool branch_taken_0x118870 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x118874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118870u;
            // 0x118874: 0x3c020010  lui         $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118870) {
            ctx->pc = 0x118828u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118828;
        }
    }
    ctx->pc = 0x118878u;
    // 0x118878: 0xc046044  jal         func_118110
    ctx->pc = 0x118878u;
    SET_GPR_U32(ctx, 31, 0x118880u);
    ctx->pc = 0x11887Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118878u;
            // 0x11887c: 0x3c140021  lui         $s4, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118110u;
    if (runtime->hasFunction(0x118110u)) {
        auto targetFn = runtime->lookupFunction(0x118110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118880u; }
        if (ctx->pc != 0x118880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118110_0x118110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118880u; }
        if (ctx->pc != 0x118880u) { return; }
    }
    ctx->pc = 0x118880u;
label_118880:
    // 0x118880: 0xc045198  jal         func_114660
    ctx->pc = 0x118880u;
    SET_GPR_U32(ctx, 31, 0x118888u);
    ctx->pc = 0x118884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118880u;
            // 0x118884: 0x8e849de8  lw          $a0, -0x6218($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118888u; }
        if (ctx->pc != 0x118888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118888u; }
        if (ctx->pc != 0x118888u) { return; }
    }
    ctx->pc = 0x118888u;
label_118888:
    // 0x118888: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x118888u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11888c: 0x2463df40  addiu       $v1, $v1, -0x20C0
    ctx->pc = 0x11888cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958912));
    // 0x118890: 0x24640200  addiu       $a0, $v1, 0x200
    ctx->pc = 0x118890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 512));
    // 0x118894: 0x64102b  sltu        $v0, $v1, $a0
    ctx->pc = 0x118894u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x118898: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x118898u;
    {
        const bool branch_taken_0x118898 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11889Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118898u;
            // 0x11889c: 0x3c120026  lui         $s2, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118898) {
            ctx->pc = 0x1188CCu;
            goto label_1188cc;
        }
    }
    ctx->pc = 0x1188A0u;
    // 0x1188a0: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x1188a0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x1188a4: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1188a4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
label_1188a8:
    // 0x1188a8: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1188a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1188ac: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x1188acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1188b0: 0x64102b  sltu        $v0, $v1, $a0
    ctx->pc = 0x1188b0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1188b4: 0x0  nop
    ctx->pc = 0x1188b4u;
    // NOP
    // 0x1188b8: 0x0  nop
    ctx->pc = 0x1188b8u;
    // NOP
    // 0x1188bc: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1188BCu;
    {
        const bool branch_taken_0x1188bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1188bc) {
            ctx->pc = 0x1188A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1188a8;
        }
    }
    ctx->pc = 0x1188C4u;
    // 0x1188c4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1188C4u;
    {
        const bool branch_taken_0x1188c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1188C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1188C4u;
            // 0x1188c8: 0x8e849de8  lw          $a0, -0x6218($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294942184)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1188c4) {
            ctx->pc = 0x1188D8u;
            goto label_1188d8;
        }
    }
    ctx->pc = 0x1188CCu;
label_1188cc:
    // 0x1188cc: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x1188ccu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
    // 0x1188d0: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x1188d0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x1188d4: 0x8e849de8  lw          $a0, -0x6218($s4)
    ctx->pc = 0x1188d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294942184)));
label_1188d8:
    // 0x1188d8: 0xc045190  jal         func_114640
    ctx->pc = 0x1188D8u;
    SET_GPR_U32(ctx, 31, 0x1188E0u);
    ctx->pc = 0x1188DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1188D8u;
            // 0x1188dc: 0x2610d680  addiu       $s0, $s0, -0x2980 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294956672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1188E0u; }
        if (ctx->pc != 0x1188E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1188E0u; }
        if (ctx->pc != 0x1188E0u) { return; }
    }
    ctx->pc = 0x1188E0u;
label_1188e0:
    // 0x1188e0: 0x2623d6c0  addiu       $v1, $s1, -0x2940
    ctx->pc = 0x1188e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294956736));
    // 0x1188e4: 0x2647ca00  addiu       $a3, $s2, -0x3600
    ctx->pc = 0x1188e4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), 4294953472));
    // 0x1188e8: 0xae43ca00  sw          $v1, -0x3600($s2)
    ctx->pc = 0x1188e8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294953472), GPR_U32(ctx, 3));
    // 0x1188ec: 0x2664e140  addiu       $a0, $s3, -0x1EC0
    ctx->pc = 0x1188ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294959424));
    // 0x1188f0: 0x24630440  addiu       $v1, $v1, 0x440
    ctx->pc = 0x1188f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1088));
    // 0x1188f4: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1188f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1188f8: 0xace30004  sw          $v1, 0x4($a3)
    ctx->pc = 0x1188f8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
    // 0x1188fc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1188fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118900: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x118900u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x118904: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x118904u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x118908: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x118908u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11890c: 0x240a0008  addiu       $t2, $zero, 0x8
    ctx->pc = 0x11890cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x118910: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x118910u;
    SET_GPR_U32(ctx, 31, 0x118918u);
    ctx->pc = 0x118914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118910u;
            // 0x118914: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118918u; }
        if (ctx->pc != 0x118918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118918u; }
        if (ctx->pc != 0x118918u) { return; }
    }
    ctx->pc = 0x118918u;
label_118918:
    // 0x118918: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x118918u;
    {
        const bool branch_taken_0x118918 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11891Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118918u;
            // 0x11891c: 0x3c042000  lui         $a0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118918) {
            ctx->pc = 0x11892Cu;
            goto label_11892c;
        }
    }
    ctx->pc = 0x118920u;
    // 0x118920: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x118920u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x118924: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x118924u;
    {
        const bool branch_taken_0x118924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118924u;
            // 0x118928: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x118924) {
            ctx->pc = 0x118984u;
            goto label_118984;
        }
    }
    ctx->pc = 0x11892Cu;
label_11892c:
    // 0x11892c: 0x26020004  addiu       $v0, $s0, 0x4
    ctx->pc = 0x11892cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x118930: 0x2041825  or          $v1, $s0, $a0
    ctx->pc = 0x118930u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) | GPR_U64(ctx, 4));
    // 0x118934: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x118934u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x118938: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x118938u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x11893c: 0x24a8e168  addiu       $t0, $a1, -0x1E98
    ctx->pc = 0x11893cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959464));
    // 0x118940: 0x88640003  lwl         $a0, 0x3($v1)
    ctx->pc = 0x118940u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x118944: 0x98640000  lwr         $a0, 0x0($v1)
    ctx->pc = 0x118944u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x118948: 0xa9040003  swl         $a0, 0x3($t0)
    ctx->pc = 0x118948u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11894c: 0xb9040000  swr         $a0, 0x0($t0)
    ctx->pc = 0x11894cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x118950: 0x88430003  lwl         $v1, 0x3($v0)
    ctx->pc = 0x118950u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 3) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 3, (int32_t)merged); }
    // 0x118954: 0x98430000  lwr         $v1, 0x0($v0)
    ctx->pc = 0x118954u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 3) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 3) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 3, merged64); }
    // 0x118958: 0xaba30013  swl         $v1, 0x13($sp)
    ctx->pc = 0x118958u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 19); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11895c: 0xbba30010  swr         $v1, 0x10($sp)
    ctx->pc = 0x11895cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 3); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x118960: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x118960u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x118964: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x118964u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x118968: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x118968u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11896c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x11896cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x118970: 0xaca49ddc  sw          $a0, -0x6224($a1)
    ctx->pc = 0x118970u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4294942172), GPR_U32(ctx, 4));
    // 0x118974: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x118974u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118978: 0x38630002  xori        $v1, $v1, 0x2
    ctx->pc = 0x118978u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
    // 0x11897c: 0x2c630001  sltiu       $v1, $v1, 0x1
    ctx->pc = 0x11897cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x118980: 0xacc39de0  sw          $v1, -0x6220($a2)
    ctx->pc = 0x118980u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294942176), GPR_U32(ctx, 3));
label_118984:
    // 0x118984: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x118984u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x118988: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x118988u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11898c: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x11898cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x118990: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x118990u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x118994: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x118994u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x118998: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x118998u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11899c: 0x3e00008  jr          $ra
    ctx->pc = 0x11899Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1189A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11899Cu;
            // 0x1189a0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1187CCu: goto label_1187cc;
            case 0x1187D8u: goto label_1187d8;
            case 0x1187F8u: goto label_1187f8;
            case 0x118810u: goto label_118810;
            case 0x118820u: goto label_118820;
            case 0x118828u: goto label_118828;
            case 0x118830u: goto label_118830;
            case 0x11884Cu: goto label_11884c;
            case 0x118850u: goto label_118850;
            case 0x118864u: goto label_118864;
            case 0x118880u: goto label_118880;
            case 0x118888u: goto label_118888;
            case 0x1188A8u: goto label_1188a8;
            case 0x1188CCu: goto label_1188cc;
            case 0x1188D8u: goto label_1188d8;
            case 0x1188E0u: goto label_1188e0;
            case 0x118918u: goto label_118918;
            case 0x11892Cu: goto label_11892c;
            case 0x118984u: goto label_118984;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1189A4u;
    // 0x1189a4: 0x0  nop
    ctx->pc = 0x1189a4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5130
// Address: 0x1d5130 - 0x1d53f0
void sub_001D5130_0x1d5130(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5130_0x1d5130");
#endif

    switch (ctx->pc) {
        case 0x1d5150u: goto label_1d5150;
        case 0x1d5158u: goto label_1d5158;
        case 0x1d5168u: goto label_1d5168;
        case 0x1d519cu: goto label_1d519c;
        case 0x1d51c8u: goto label_1d51c8;
        case 0x1d51dcu: goto label_1d51dc;
        case 0x1d51ecu: goto label_1d51ec;
        case 0x1d51fcu: goto label_1d51fc;
        case 0x1d523cu: goto label_1d523c;
        case 0x1d5258u: goto label_1d5258;
        case 0x1d52d4u: goto label_1d52d4;
        case 0x1d52e4u: goto label_1d52e4;
        case 0x1d52fcu: goto label_1d52fc;
        case 0x1d530cu: goto label_1d530c;
        case 0x1d5344u: goto label_1d5344;
        case 0x1d5358u: goto label_1d5358;
        case 0x1d536cu: goto label_1d536c;
        case 0x1d537cu: goto label_1d537c;
        case 0x1d5394u: goto label_1d5394;
        case 0x1d53b0u: goto label_1d53b0;
        case 0x1d53c8u: goto label_1d53c8;
        default: break;
    }

    ctx->pc = 0x1d5130u;

    // 0x1d5130: 0x27bdff00  addiu       $sp, $sp, -0x100
    ctx->pc = 0x1d5130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967040));
    // 0x1d5134: 0xffb200e0  sd          $s2, 0xE0($sp)
    ctx->pc = 0x1d5134u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 18));
    // 0x1d5138: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1d5138u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d513c: 0xffb100d0  sd          $s1, 0xD0($sp)
    ctx->pc = 0x1d513cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 17));
    // 0x1d5140: 0xffb000c0  sd          $s0, 0xC0($sp)
    ctx->pc = 0x1d5140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 16));
    // 0x1d5144: 0xffbf00f0  sd          $ra, 0xF0($sp)
    ctx->pc = 0x1d5144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 240), GPR_U64(ctx, 31));
    // 0x1d5148: 0xc045c20  jal         func_117080
    ctx->pc = 0x1D5148u;
    SET_GPR_U32(ctx, 31, 0x1D5150u);
    ctx->pc = 0x1D514Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5148u;
            // 0x1d514c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5150u; }
        if (ctx->pc != 0x1D5150u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5150u; }
        if (ctx->pc != 0x1D5150u) { return; }
    }
    ctx->pc = 0x1D5150u;
label_1d5150:
    // 0x1d5150: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D5150u;
    {
        const bool branch_taken_0x1d5150 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5150u;
            // 0x1d5154: 0x3c110034  lui         $s1, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5150) {
            ctx->pc = 0x1D5184u;
            goto label_1d5184;
        }
    }
    ctx->pc = 0x1D5158u;
label_1d5158:
    // 0x1d5158: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1d5158u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1d515c: 0x3c060001  lui         $a2, 0x1
    ctx->pc = 0x1d515cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
    // 0x1d5160: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1d5160u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1d5164: 0x0  nop
    ctx->pc = 0x1d5164u;
    // NOP
label_1d5168:
    // 0x1d5168: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1d5168u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1d516c: 0x0  nop
    ctx->pc = 0x1d516cu;
    // NOP
    // 0x1d5170: 0x0  nop
    ctx->pc = 0x1d5170u;
    // NOP
    // 0x1d5174: 0x0  nop
    ctx->pc = 0x1d5174u;
    // NOP
    // 0x1d5178: 0x0  nop
    ctx->pc = 0x1d5178u;
    // NOP
    // 0x1d517c: 0x14c2fffa  bne         $a2, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D517Cu;
    {
        const bool branch_taken_0x1d517c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d517c) {
            ctx->pc = 0x1D5168u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5168;
        }
    }
    ctx->pc = 0x1D5184u;
label_1d5184:
    // 0x1d5184: 0x263028e0  addiu       $s0, $s1, 0x28E0
    ctx->pc = 0x1d5184u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 10464));
    // 0x1d5188: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x1d5188u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1d518c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d518cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5190: 0x34a50211  ori         $a1, $a1, 0x211
    ctx->pc = 0x1d5190u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)529);
    // 0x1d5194: 0xc045e06  jal         func_117818
    ctx->pc = 0x1D5194u;
    SET_GPR_U32(ctx, 31, 0x1D519Cu);
    ctx->pc = 0x1D5198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5194u;
            // 0x1d5198: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D519Cu; }
        if (ctx->pc != 0x1D519Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D519Cu; }
        if (ctx->pc != 0x1D519Cu) { return; }
    }
    ctx->pc = 0x1D519Cu;
label_1d519c:
    // 0x1d519c: 0x4400055  bltz        $v0, . + 4 + (0x55 << 2)
    ctx->pc = 0x1D519Cu;
    {
        const bool branch_taken_0x1d519c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1D51A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D519Cu;
            // 0x1d51a0: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d519c) {
            ctx->pc = 0x1D52F4u;
            goto label_1d52f4;
        }
    }
    ctx->pc = 0x1D51A4u;
    // 0x1d51a4: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x1d51a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1d51a8: 0x1040ffeb  beqz        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1D51A8u;
    {
        const bool branch_taken_0x1d51a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D51ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51A8u;
            // 0x1d51ac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d51a8) {
            ctx->pc = 0x1D5158u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5158;
        }
    }
    ctx->pc = 0x1D51B0u;
    // 0x1d51b0: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1d51b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1d51b4: 0xafa20094  sw          $v0, 0x94($sp)
    ctx->pc = 0x1d51b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 148), GPR_U32(ctx, 2));
    // 0x1d51b8: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1d51b8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x1d51bc: 0xafa20098  sw          $v0, 0x98($sp)
    ctx->pc = 0x1d51bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 152), GPR_U32(ctx, 2));
    // 0x1d51c0: 0xc045188  jal         func_114620
    ctx->pc = 0x1D51C0u;
    SET_GPR_U32(ctx, 31, 0x1D51C8u);
    ctx->pc = 0x1D51C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51C0u;
            // 0x1d51c4: 0x2410ffff  addiu       $s0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51C8u; }
        if (ctx->pc != 0x1D51C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51C8u; }
        if (ctx->pc != 0x1D51C8u) { return; }
    }
    ctx->pc = 0x1D51C8u;
label_1d51c8:
    // 0x1d51c8: 0x14500006  bne         $v0, $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D51C8u;
    {
        const bool branch_taken_0x1d51c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 16));
        ctx->pc = 0x1D51CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51C8u;
            // 0x1d51cc: 0xae226998  sw          $v0, 0x6998($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d51c8) {
            ctx->pc = 0x1D51E4u;
            goto label_1d51e4;
        }
    }
    ctx->pc = 0x1D51D0u;
    // 0x1d51d0: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d51d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d51d4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D51D4u;
    SET_GPR_U32(ctx, 31, 0x1D51DCu);
    ctx->pc = 0x1D51D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51D4u;
            // 0x1d51d8: 0x24846de8  addiu       $a0, $a0, 0x6DE8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51DCu; }
        if (ctx->pc != 0x1D51DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51DCu; }
        if (ctx->pc != 0x1D51DCu) { return; }
    }
    ctx->pc = 0x1D51DCu;
label_1d51dc:
    // 0x1d51dc: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x1D51DCu;
    {
        const bool branch_taken_0x1d51dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D51E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51DCu;
            // 0x1d51e0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d51dc) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D51E4u;
label_1d51e4:
    // 0x1d51e4: 0xc0754fc  jal         func_1D53F0
    ctx->pc = 0x1D51E4u;
    SET_GPR_U32(ctx, 31, 0x1D51ECu);
    ctx->pc = 0x1D51E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51E4u;
            // 0x1d51e8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D53F0u;
    if (runtime->hasFunction(0x1D53F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D53F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51ECu; }
        if (ctx->pc != 0x1D51ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D53F0_0x1d53f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51ECu; }
        if (ctx->pc != 0x1D51ECu) { return; }
    }
    ctx->pc = 0x1D51ECu;
label_1d51ec:
    // 0x1d51ec: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1D51ECu;
    {
        const bool branch_taken_0x1d51ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D51F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51ECu;
            // 0x1d51f0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d51ec) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D51F4u;
    // 0x1d51f4: 0xc075646  jal         func_1D5918
    ctx->pc = 0x1D51F4u;
    SET_GPR_U32(ctx, 31, 0x1D51FCu);
    ctx->pc = 0x1D51F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D51F4u;
            // 0x1d51f8: 0x27a500b0  addiu       $a1, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51FCu; }
        if (ctx->pc != 0x1D51FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D51FCu; }
        if (ctx->pc != 0x1D51FCu) { return; }
    }
    ctx->pc = 0x1D51FCu;
label_1d51fc:
    // 0x1d51fc: 0x8fa300b0  lw          $v1, 0xB0($sp)
    ctx->pc = 0x1d51fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1d5200: 0x1460000c  bnez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1D5200u;
    {
        const bool branch_taken_0x1d5200 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5200u;
            // 0x1d5204: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5200) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D5208u;
    // 0x1d5208: 0x1880000a  blez        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D5208u;
    {
        const bool branch_taken_0x1d5208 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x1D520Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5208u;
            // 0x1d520c: 0x28820080  slti        $v0, $a0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5208) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D5210u;
    // 0x1d5210: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D5210u;
    {
        const bool branch_taken_0x1d5210 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5210u;
            // 0x1d5214: 0x3c070034  lui         $a3, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5210) {
            ctx->pc = 0x1D5234u;
            goto label_1d5234;
        }
    }
    ctx->pc = 0x1D5218u;
    // 0x1d5218: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5218u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d521c: 0x24422a10  addiu       $v0, $v0, 0x2A10
    ctx->pc = 0x1d521cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10768));
    // 0x1d5220: 0x24e32840  addiu       $v1, $a3, 0x2840
    ctx->pc = 0x1d5220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 10304));
    // 0x1d5224: 0xace42840  sw          $a0, 0x2840($a3)
    ctx->pc = 0x1d5224u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 10304), GPR_U32(ctx, 4));
    // 0x1d5228: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x1d5228u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x1d522c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D522Cu;
    {
        const bool branch_taken_0x1d522c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D522Cu;
            // 0x1d5230: 0xac620004  sw          $v0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d522c) {
            ctx->pc = 0x1D5248u;
            goto label_1d5248;
        }
    }
    ctx->pc = 0x1D5234u;
label_1d5234:
    // 0x1d5234: 0xc04518c  jal         func_114630
    ctx->pc = 0x1D5234u;
    SET_GPR_U32(ctx, 31, 0x1D523Cu);
    ctx->pc = 0x1D5238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5234u;
            // 0x1d5238: 0x8e246998  lw          $a0, 0x6998($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 27032)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D523Cu; }
        if (ctx->pc != 0x1D523Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D523Cu; }
        if (ctx->pc != 0x1D523Cu) { return; }
    }
    ctx->pc = 0x1D523Cu;
label_1d523c:
    // 0x1d523c: 0xae306998  sw          $s0, 0x6998($s1)
    ctx->pc = 0x1d523cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 16));
    // 0x1d5240: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1D5240u;
    {
        const bool branch_taken_0x1d5240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5240u;
            // 0x1d5244: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5240) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D5248u;
label_1d5248:
    // 0x1d5248: 0x1080001b  beqz        $a0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1D5248u;
    {
        const bool branch_taken_0x1d5248 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D524Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5248u;
            // 0x1d524c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5248) {
            ctx->pc = 0x1D52B8u;
            goto label_1d52b8;
        }
    }
    ctx->pc = 0x1D5250u;
    // 0x1d5250: 0x3c08001d  lui         $t0, 0x1D
    ctx->pc = 0x1d5250u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)29 << 16));
    // 0x1d5254: 0x24030038  addiu       $v1, $zero, 0x38
    ctx->pc = 0x1d5254u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
label_1d5258:
    // 0x1d5258: 0x24e22840  addiu       $v0, $a3, 0x2840
    ctx->pc = 0x1d5258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 10304));
    // 0x1d525c: 0xc31818  mult        $v1, $a2, $v1
    ctx->pc = 0x1d525cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1d5260: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x1d5260u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1d5264: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d5264u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d5268: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d5268u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d526c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1d526cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1d5270: 0xac640008  sw          $a0, 0x8($v1)
    ctx->pc = 0x1d5270u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 4));
    // 0x1d5274: 0xac600034  sw          $zero, 0x34($v1)
    ctx->pc = 0x1d5274u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 52), GPR_U32(ctx, 0));
    // 0x1d5278: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1d5278u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1d527c: 0xac640004  sw          $a0, 0x4($v1)
    ctx->pc = 0x1d527cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
    // 0x1d5280: 0xac60000c  sw          $zero, 0xC($v1)
    ctx->pc = 0x1d5280u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 0));
    // 0x1d5284: 0xac600010  sw          $zero, 0x10($v1)
    ctx->pc = 0x1d5284u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x1d5288: 0xac600014  sw          $zero, 0x14($v1)
    ctx->pc = 0x1d5288u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 0));
    // 0x1d528c: 0xac600018  sw          $zero, 0x18($v1)
    ctx->pc = 0x1d528cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 24), GPR_U32(ctx, 0));
    // 0x1d5290: 0xac60001c  sw          $zero, 0x1C($v1)
    ctx->pc = 0x1d5290u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 0));
    // 0x1d5294: 0xac60002c  sw          $zero, 0x2C($v1)
    ctx->pc = 0x1d5294u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 44), GPR_U32(ctx, 0));
    // 0x1d5298: 0xac600030  sw          $zero, 0x30($v1)
    ctx->pc = 0x1d5298u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 48), GPR_U32(ctx, 0));
    // 0x1d529c: 0xa4600020  sh          $zero, 0x20($v1)
    ctx->pc = 0x1d529cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 32), (uint16_t)GPR_U32(ctx, 0));
    // 0x1d52a0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1d52a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d52a4: 0xc2102b  sltu        $v0, $a2, $v0
    ctx->pc = 0x1d52a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d52a8: 0x1440ffeb  bnez        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1D52A8u;
    {
        const bool branch_taken_0x1d52a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D52ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52A8u;
            // 0x1d52ac: 0x24030038  addiu       $v1, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d52a8) {
            ctx->pc = 0x1D5258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5258;
        }
    }
    ctx->pc = 0x1D52B0u;
    // 0x1d52b0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D52B0u;
    {
        const bool branch_taken_0x1d52b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D52B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52B0u;
            // 0x1d52b4: 0x24f02840  addiu       $s0, $a3, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d52b0) {
            ctx->pc = 0x1D52C0u;
            goto label_1d52c0;
        }
    }
    ctx->pc = 0x1D52B8u;
label_1d52b8:
    // 0x1d52b8: 0x3c08001d  lui         $t0, 0x1D
    ctx->pc = 0x1d52b8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)29 << 16));
    // 0x1d52bc: 0x24f02840  addiu       $s0, $a3, 0x2840
    ctx->pc = 0x1d52bcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 10304));
label_1d52c0:
    // 0x1d52c0: 0x25056090  addiu       $a1, $t0, 0x6090
    ctx->pc = 0x1d52c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 24720));
    // 0x1d52c4: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x1d52c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x1d52c8: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1d52c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d52cc: 0xc0450c0  jal         func_114300
    ctx->pc = 0x1D52CCu;
    SET_GPR_U32(ctx, 31, 0x1D52D4u);
    ctx->pc = 0x1D52D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52CCu;
            // 0x1d52d0: 0x2406ffff  addiu       $a2, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114300u;
    if (runtime->hasFunction(0x114300u)) {
        auto targetFn = runtime->lookupFunction(0x114300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52D4u; }
        if (ctx->pc != 0x1D52D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114300_0x114300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52D4u; }
        if (ctx->pc != 0x1D52D4u) { return; }
    }
    ctx->pc = 0x1D52D4u;
label_1d52d4:
    // 0x1d52d4: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D52D4u;
    {
        const bool branch_taken_0x1d52d4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D52D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52D4u;
            // 0x1d52d8: 0xae02009c  sw          $v0, 0x9C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 156), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d52d4) {
            ctx->pc = 0x1D5304u;
            goto label_1d5304;
        }
    }
    ctx->pc = 0x1D52DCu;
    // 0x1d52dc: 0xc04518c  jal         func_114630
    ctx->pc = 0x1D52DCu;
    SET_GPR_U32(ctx, 31, 0x1D52E4u);
    ctx->pc = 0x1D52E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52DCu;
            // 0x1d52e0: 0x8e246998  lw          $a0, 0x6998($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 27032)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52E4u; }
        if (ctx->pc != 0x1D52E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52E4u; }
        if (ctx->pc != 0x1D52E4u) { return; }
    }
    ctx->pc = 0x1D52E4u;
label_1d52e4:
    // 0x1d52e4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d52e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d52e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d52e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d52ec: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D52ECu;
    {
        const bool branch_taken_0x1d52ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D52F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52ECu;
            // 0x1d52f0: 0xae236998  sw          $v1, 0x6998($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d52ec) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D52F4u;
label_1d52f4:
    // 0x1d52f4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D52F4u;
    SET_GPR_U32(ctx, 31, 0x1D52FCu);
    ctx->pc = 0x1D52F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52F4u;
            // 0x1d52f8: 0x24846dd0  addiu       $a0, $a0, 0x6DD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52FCu; }
        if (ctx->pc != 0x1D52FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D52FCu; }
        if (ctx->pc != 0x1D52FCu) { return; }
    }
    ctx->pc = 0x1D52FCu;
label_1d52fc:
    // 0x1d52fc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D52FCu;
    {
        const bool branch_taken_0x1d52fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D52FCu;
            // 0x1d5300: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d52fc) {
            ctx->pc = 0x1D5310u;
            goto label_1d5310;
        }
    }
    ctx->pc = 0x1D5304u;
label_1d5304:
    // 0x1d5304: 0xc04545a  jal         func_115168
    ctx->pc = 0x1D5304u;
    SET_GPR_U32(ctx, 31, 0x1D530Cu);
    ctx->pc = 0x1D5308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5304u;
            // 0x1d5308: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115168u;
    if (runtime->hasFunction(0x115168u)) {
        auto targetFn = runtime->lookupFunction(0x115168u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D530Cu; }
        if (ctx->pc != 0x1D530Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115168_0x115168(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D530Cu; }
        if (ctx->pc != 0x1D530Cu) { return; }
    }
    ctx->pc = 0x1D530Cu;
label_1d530c:
    // 0x1d530c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d530cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5310:
    // 0x1d5310: 0xdfbf00f0  ld          $ra, 0xF0($sp)
    ctx->pc = 0x1d5310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x1d5314: 0xdfb200e0  ld          $s2, 0xE0($sp)
    ctx->pc = 0x1d5314u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x1d5318: 0xdfb100d0  ld          $s1, 0xD0($sp)
    ctx->pc = 0x1d5318u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1d531c: 0xdfb000c0  ld          $s0, 0xC0($sp)
    ctx->pc = 0x1d531cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1d5320: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5320u;
            // 0x1d5324: 0x27bd0100  addiu       $sp, $sp, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 256));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5150u: goto label_1d5150;
            case 0x1D5158u: goto label_1d5158;
            case 0x1D5168u: goto label_1d5168;
            case 0x1D5184u: goto label_1d5184;
            case 0x1D519Cu: goto label_1d519c;
            case 0x1D51C8u: goto label_1d51c8;
            case 0x1D51DCu: goto label_1d51dc;
            case 0x1D51E4u: goto label_1d51e4;
            case 0x1D51ECu: goto label_1d51ec;
            case 0x1D51FCu: goto label_1d51fc;
            case 0x1D5234u: goto label_1d5234;
            case 0x1D523Cu: goto label_1d523c;
            case 0x1D5248u: goto label_1d5248;
            case 0x1D5258u: goto label_1d5258;
            case 0x1D52B8u: goto label_1d52b8;
            case 0x1D52C0u: goto label_1d52c0;
            case 0x1D52D4u: goto label_1d52d4;
            case 0x1D52E4u: goto label_1d52e4;
            case 0x1D52F4u: goto label_1d52f4;
            case 0x1D52FCu: goto label_1d52fc;
            case 0x1D5304u: goto label_1d5304;
            case 0x1D530Cu: goto label_1d530c;
            case 0x1D5310u: goto label_1d5310;
            case 0x1D5344u: goto label_1d5344;
            case 0x1D5358u: goto label_1d5358;
            case 0x1D536Cu: goto label_1d536c;
            case 0x1D537Cu: goto label_1d537c;
            case 0x1D5394u: goto label_1d5394;
            case 0x1D5398u: goto label_1d5398;
            case 0x1D53B0u: goto label_1d53b0;
            case 0x1D53C8u: goto label_1d53c8;
            case 0x1D53D0u: goto label_1d53d0;
            case 0x1D53D4u: goto label_1d53d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5328u;
    // 0x1d5328: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d5328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d532c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1d532cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1d5330: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1d5330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1d5334: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1d5334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1d5338: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d5338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d533c: 0xc047598  jal         func_11D660
    ctx->pc = 0x1D533Cu;
    SET_GPR_U32(ctx, 31, 0x1D5344u);
    ctx->pc = 0x1D5340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D533Cu;
            // 0x1d5340: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5344u; }
        if (ctx->pc != 0x1D5344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5344u; }
        if (ctx->pc != 0x1D5344u) { return; }
    }
    ctx->pc = 0x1D5344u;
label_1d5344:
    // 0x1d5344: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1d5344u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5348: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1d5348u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d534c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d534cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d5350: 0xc0450c8  jal         func_114320
    ctx->pc = 0x1D5350u;
    SET_GPR_U32(ctx, 31, 0x1D5358u);
    ctx->pc = 0x1D5354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5350u;
            // 0x1d5354: 0x8c4528dc  lw          $a1, 0x28DC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10460)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114320u;
    if (runtime->hasFunction(0x114320u)) {
        auto targetFn = runtime->lookupFunction(0x114320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5358u; }
        if (ctx->pc != 0x1D5358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5358u; }
        if (ctx->pc != 0x1D5358u) { return; }
    }
    ctx->pc = 0x1D5358u;
label_1d5358:
    // 0x1d5358: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1d5358u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d535c: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D535Cu;
    {
        const bool branch_taken_0x1d535c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d535c) {
            ctx->pc = 0x1D536Cu;
            goto label_1d536c;
        }
    }
    ctx->pc = 0x1D5364u;
    // 0x1d5364: 0xc045440  jal         func_115100
    ctx->pc = 0x1D5364u;
    SET_GPR_U32(ctx, 31, 0x1D536Cu);
    ctx->pc = 0x1D5368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5364u;
            // 0x1d5368: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115100u;
    if (runtime->hasFunction(0x115100u)) {
        auto targetFn = runtime->lookupFunction(0x115100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D536Cu; }
        if (ctx->pc != 0x1D536Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D536Cu; }
        if (ctx->pc != 0x1D536Cu) { return; }
    }
    ctx->pc = 0x1D536Cu;
label_1d536c:
    // 0x1d536c: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D536Cu;
    {
        const bool branch_taken_0x1d536c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d536c) {
            ctx->pc = 0x1D537Cu;
            goto label_1d537c;
        }
    }
    ctx->pc = 0x1D5374u;
    // 0x1d5374: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1D5374u;
    SET_GPR_U32(ctx, 31, 0x1D537Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D537Cu; }
        if (ctx->pc != 0x1D537Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D537Cu; }
        if (ctx->pc != 0x1D537Cu) { return; }
    }
    ctx->pc = 0x1D537Cu;
label_1d537c:
    // 0x1d537c: 0x6010006  bgez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D537Cu;
    {
        const bool branch_taken_0x1d537c = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1D5380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D537Cu;
            // 0x1d5380: 0x3c110023  lui         $s1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d537c) {
            ctx->pc = 0x1D5398u;
            goto label_1d5398;
        }
    }
    ctx->pc = 0x1D5384u;
    // 0x1d5384: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d5384u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d5388: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1d5388u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d538c: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D538Cu;
    SET_GPR_U32(ctx, 31, 0x1D5394u);
    ctx->pc = 0x1D5390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D538Cu;
            // 0x1d5390: 0x24846e08  addiu       $a0, $a0, 0x6E08 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5394u; }
        if (ctx->pc != 0x1D5394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5394u; }
        if (ctx->pc != 0x1D5394u) { return; }
    }
    ctx->pc = 0x1D5394u;
label_1d5394:
    // 0x1d5394: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1d5394u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
label_1d5398:
    // 0x1d5398: 0x2410ffff  addiu       $s0, $zero, -0x1
    ctx->pc = 0x1d5398u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d539c: 0x8e246998  lw          $a0, 0x6998($s1)
    ctx->pc = 0x1d539cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 27032)));
    // 0x1d53a0: 0x1090000c  beq         $a0, $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D53A0u;
    {
        const bool branch_taken_0x1d53a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 16));
        ctx->pc = 0x1D53A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53A0u;
            // 0x1d53a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d53a0) {
            ctx->pc = 0x1D53D4u;
            goto label_1d53d4;
        }
    }
    ctx->pc = 0x1D53A8u;
    // 0x1d53a8: 0xc04518c  jal         func_114630
    ctx->pc = 0x1D53A8u;
    SET_GPR_U32(ctx, 31, 0x1D53B0u);
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53B0u; }
        if (ctx->pc != 0x1D53B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53B0u; }
        if (ctx->pc != 0x1D53B0u) { return; }
    }
    ctx->pc = 0x1D53B0u;
label_1d53b0:
    // 0x1d53b0: 0x4430007  bgezl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D53B0u;
    {
        const bool branch_taken_0x1d53b0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d53b0) {
            ctx->pc = 0x1D53B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53B0u;
            // 0x1d53b4: 0xae306998  sw          $s0, 0x6998($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D53D0u;
            goto label_1d53d0;
        }
    }
    ctx->pc = 0x1D53B8u;
    // 0x1d53b8: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d53b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d53bc: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1d53bcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d53c0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D53C0u;
    SET_GPR_U32(ctx, 31, 0x1D53C8u);
    ctx->pc = 0x1D53C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53C0u;
            // 0x1d53c4: 0x24846e38  addiu       $a0, $a0, 0x6E38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53C8u; }
        if (ctx->pc != 0x1D53C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53C8u; }
        if (ctx->pc != 0x1D53C8u) { return; }
    }
    ctx->pc = 0x1D53C8u;
label_1d53c8:
    // 0x1d53c8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1D53C8u;
    {
        const bool branch_taken_0x1d53c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D53CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53C8u;
            // 0x1d53cc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d53c8) {
            ctx->pc = 0x1D53D4u;
            goto label_1d53d4;
        }
    }
    ctx->pc = 0x1D53D0u;
label_1d53d0:
    // 0x1d53d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d53d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1d53d4:
    // 0x1d53d4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d53d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d53d8: 0x12100a  movz        $v0, $zero, $s2
    ctx->pc = 0x1d53d8u;
    if (GPR_U64(ctx, 18) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1d53dc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1d53dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d53e0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1d53e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d53e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1d53e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d53e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D53E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D53ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53E8u;
            // 0x1d53ec: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5150u: goto label_1d5150;
            case 0x1D5158u: goto label_1d5158;
            case 0x1D5168u: goto label_1d5168;
            case 0x1D5184u: goto label_1d5184;
            case 0x1D519Cu: goto label_1d519c;
            case 0x1D51C8u: goto label_1d51c8;
            case 0x1D51DCu: goto label_1d51dc;
            case 0x1D51E4u: goto label_1d51e4;
            case 0x1D51ECu: goto label_1d51ec;
            case 0x1D51FCu: goto label_1d51fc;
            case 0x1D5234u: goto label_1d5234;
            case 0x1D523Cu: goto label_1d523c;
            case 0x1D5248u: goto label_1d5248;
            case 0x1D5258u: goto label_1d5258;
            case 0x1D52B8u: goto label_1d52b8;
            case 0x1D52C0u: goto label_1d52c0;
            case 0x1D52D4u: goto label_1d52d4;
            case 0x1D52E4u: goto label_1d52e4;
            case 0x1D52F4u: goto label_1d52f4;
            case 0x1D52FCu: goto label_1d52fc;
            case 0x1D5304u: goto label_1d5304;
            case 0x1D530Cu: goto label_1d530c;
            case 0x1D5310u: goto label_1d5310;
            case 0x1D5344u: goto label_1d5344;
            case 0x1D5358u: goto label_1d5358;
            case 0x1D536Cu: goto label_1d536c;
            case 0x1D537Cu: goto label_1d537c;
            case 0x1D5394u: goto label_1d5394;
            case 0x1D5398u: goto label_1d5398;
            case 0x1D53B0u: goto label_1d53b0;
            case 0x1D53C8u: goto label_1d53c8;
            case 0x1D53D0u: goto label_1d53d0;
            case 0x1D53D4u: goto label_1d53d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D53F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

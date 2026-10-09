#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001160B0
// Address: 0x1160b0 - 0x116218
void sub_001160B0_0x1160b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001160B0_0x1160b0");
#endif

    switch (ctx->pc) {
        case 0x1160d8u: goto label_1160d8;
        case 0x1160e8u: goto label_1160e8;
        case 0x1160fcu: goto label_1160fc;
        case 0x11610cu: goto label_11610c;
        case 0x116120u: goto label_116120;
        case 0x116130u: goto label_116130;
        case 0x116144u: goto label_116144;
        case 0x116164u: goto label_116164;
        case 0x116178u: goto label_116178;
        case 0x116188u: goto label_116188;
        case 0x11619cu: goto label_11619c;
        case 0x1161b4u: goto label_1161b4;
        case 0x1161bcu: goto label_1161bc;
        case 0x1161c4u: goto label_1161c4;
        case 0x1161d0u: goto label_1161d0;
        default: break;
    }

    ctx->pc = 0x1160b0u;

    // 0x1160b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1160b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1160b4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1160b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1160b8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1160b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1160bc: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1160bcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1160c0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1160c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1160c4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1160c4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1160c8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1160c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1160cc: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1160ccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1160d0: 0xc0448a6  jal         func_112298
    ctx->pc = 0x1160D0u;
    SET_GPR_U32(ctx, 31, 0x1160D8u);
    ctx->pc = 0x1160D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1160D0u;
            // 0x1160d4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1160D8u; }
        if (ctx->pc != 0x1160D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1160D8u; }
        if (ctx->pc != 0x1160D8u) { return; }
    }
    ctx->pc = 0x1160D8u;
label_1160d8:
    // 0x1160d8: 0x4410008  bgez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1160D8u;
    {
        const bool branch_taken_0x1160d8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1160DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1160D8u;
            // 0x1160dc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1160d8) {
            ctx->pc = 0x1160FCu;
            goto label_1160fc;
        }
    }
    ctx->pc = 0x1160E0u;
    // 0x1160e0: 0xc044752  jal         func_111D48
    ctx->pc = 0x1160E0u;
    SET_GPR_U32(ctx, 31, 0x1160E8u);
    ctx->pc = 0x1160E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1160E0u;
            // 0x1160e4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1160E8u; }
        if (ctx->pc != 0x1160E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1160E8u; }
        if (ctx->pc != 0x1160E8u) { return; }
    }
    ctx->pc = 0x1160E8u;
label_1160e8:
    // 0x1160e8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1160e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1160ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1160ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1160f0: 0x8c629d44  lw          $v0, -0x62BC($v1)
    ctx->pc = 0x1160f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942020)));
    // 0x1160f4: 0x40f809  jalr        $v0
    ctx->pc = 0x1160F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1160FCu);
        ctx->pc = 0x1160F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1160F4u;
            // 0x1160f8: 0x2404002d  addiu       $a0, $zero, 0x2D (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1160FCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1160D8u: goto label_1160d8;
            case 0x1160E8u: goto label_1160e8;
            case 0x1160FCu: goto label_1160fc;
            case 0x11610Cu: goto label_11610c;
            case 0x116120u: goto label_116120;
            case 0x116130u: goto label_116130;
            case 0x116134u: goto label_116134;
            case 0x116144u: goto label_116144;
            case 0x116154u: goto label_116154;
            case 0x116164u: goto label_116164;
            case 0x116178u: goto label_116178;
            case 0x116188u: goto label_116188;
            case 0x11618Cu: goto label_11618c;
            case 0x11619Cu: goto label_11619c;
            case 0x1161A4u: goto label_1161a4;
            case 0x1161B4u: goto label_1161b4;
            case 0x1161BCu: goto label_1161bc;
            case 0x1161C4u: goto label_1161c4;
            case 0x1161D0u: goto label_1161d0;
            case 0x1161F8u: goto label_1161f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1160FCu; }
            if (ctx->pc != 0x1160FCu) { return; }
        }
        }
    }
    ctx->pc = 0x1160FCu;
label_1160fc:
    // 0x1160fc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x1160fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x116100: 0xdc2589d8  ld          $a1, -0x7628($at)
    ctx->pc = 0x116100u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937048)));
    // 0x116104: 0xc0448a6  jal         func_112298
    ctx->pc = 0x116104u;
    SET_GPR_U32(ctx, 31, 0x11610Cu);
    ctx->pc = 0x116108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116104u;
            // 0x116108: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11610Cu; }
        if (ctx->pc != 0x11610Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11610Cu; }
        if (ctx->pc != 0x11610Cu) { return; }
    }
    ctx->pc = 0x11610Cu;
label_11610c:
    // 0x11610c: 0x4410011  bgez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x11610Cu;
    {
        const bool branch_taken_0x11610c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x116110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11610Cu;
            // 0x116110: 0x3c120024  lui         $s2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11610c) {
            ctx->pc = 0x116154u;
            goto label_116154;
        }
    }
    ctx->pc = 0x116114u;
    // 0x116114: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x116114u;
    {
        const bool branch_taken_0x116114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x116114) {
            ctx->pc = 0x116134u;
            goto label_116134;
        }
    }
    ctx->pc = 0x11611Cu;
    // 0x11611c: 0x0  nop
    ctx->pc = 0x11611cu;
    // NOP
label_116120:
    // 0x116120: 0x34058048  ori         $a1, $zero, 0x8048
    ctx->pc = 0x116120u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x116124: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x116124u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x116128: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x116128u;
    SET_GPR_U32(ctx, 31, 0x116130u);
    ctx->pc = 0x11612Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116128u;
            // 0x11612c: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116130u; }
        if (ctx->pc != 0x116130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116130u; }
        if (ctx->pc != 0x116130u) { return; }
    }
    ctx->pc = 0x116130u;
label_116130:
    // 0x116130: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x116130u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_116134:
    // 0x116134: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x116134u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x116138: 0xdc2589e0  ld          $a1, -0x7620($at)
    ctx->pc = 0x116138u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937056)));
    // 0x11613c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x11613Cu;
    SET_GPR_U32(ctx, 31, 0x116144u);
    ctx->pc = 0x116140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11613Cu;
            // 0x116140: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116144u; }
        if (ctx->pc != 0x116144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116144u; }
        if (ctx->pc != 0x116144u) { return; }
    }
    ctx->pc = 0x116144u;
label_116144:
    // 0x116144: 0x440fff6  bltz        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x116144u;
    {
        const bool branch_taken_0x116144 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x116148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116144u;
            // 0x116148: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116144) {
            ctx->pc = 0x116120u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116120;
        }
    }
    ctx->pc = 0x11614Cu;
    // 0x11614c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x11614Cu;
    {
        const bool branch_taken_0x11614c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11614c) {
            ctx->pc = 0x1161A4u;
            goto label_1161a4;
        }
    }
    ctx->pc = 0x116154u;
label_116154:
    // 0x116154: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x116154u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x116158: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x116158u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x11615c: 0xc0448a6  jal         func_112298
    ctx->pc = 0x11615Cu;
    SET_GPR_U32(ctx, 31, 0x116164u);
    ctx->pc = 0x116160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11615Cu;
            // 0x116160: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116164u; }
        if (ctx->pc != 0x116164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116164u; }
        if (ctx->pc != 0x116164u) { return; }
    }
    ctx->pc = 0x116164u;
label_116164:
    // 0x116164: 0x440000f  bltz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x116164u;
    {
        const bool branch_taken_0x116164 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x116168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116164u;
            // 0x116168: 0x3c120024  lui         $s2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116164) {
            ctx->pc = 0x1161A4u;
            goto label_1161a4;
        }
    }
    ctx->pc = 0x11616Cu;
    // 0x11616c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x11616Cu;
    {
        const bool branch_taken_0x11616c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11616c) {
            ctx->pc = 0x11618Cu;
            goto label_11618c;
        }
    }
    ctx->pc = 0x116174u;
    // 0x116174: 0x0  nop
    ctx->pc = 0x116174u;
    // NOP
label_116178:
    // 0x116178: 0x34058048  ori         $a1, $zero, 0x8048
    ctx->pc = 0x116178u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x11617c: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x11617cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x116180: 0xc04480e  jal         func_112038
    ctx->pc = 0x116180u;
    SET_GPR_U32(ctx, 31, 0x116188u);
    ctx->pc = 0x116184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116180u;
            // 0x116184: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116188u; }
        if (ctx->pc != 0x116188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116188u; }
        if (ctx->pc != 0x116188u) { return; }
    }
    ctx->pc = 0x116188u;
label_116188:
    // 0x116188: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x116188u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_11618c:
    // 0x11618c: 0x3405ffc0  ori         $a1, $zero, 0xFFC0
    ctx->pc = 0x11618cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x116190: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x116190u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x116194: 0xc0448a6  jal         func_112298
    ctx->pc = 0x116194u;
    SET_GPR_U32(ctx, 31, 0x11619Cu);
    ctx->pc = 0x116198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116194u;
            // 0x116198: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11619Cu; }
        if (ctx->pc != 0x11619Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11619Cu; }
        if (ctx->pc != 0x11619Cu) { return; }
    }
    ctx->pc = 0x11619Cu;
label_11619c:
    // 0x11619c: 0x441fff6  bgez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x11619Cu;
    {
        const bool branch_taken_0x11619c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1161A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11619Cu;
            // 0x1161a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11619c) {
            ctx->pc = 0x116178u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_116178;
        }
    }
    ctx->pc = 0x1161A4u;
label_1161a4:
    // 0x1161a4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x1161a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x1161a8: 0xdc2589e8  ld          $a1, -0x7618($at)
    ctx->pc = 0x1161a8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294937064)));
    // 0x1161ac: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1161ACu;
    SET_GPR_U32(ctx, 31, 0x1161B4u);
    ctx->pc = 0x1161B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1161ACu;
            // 0x1161b0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161B4u; }
        if (ctx->pc != 0x1161B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161B4u; }
        if (ctx->pc != 0x1161B4u) { return; }
    }
    ctx->pc = 0x1161B4u;
label_1161b4:
    // 0x1161b4: 0xc04452e  jal         func_1114B8
    ctx->pc = 0x1161B4u;
    SET_GPR_U32(ctx, 31, 0x1161BCu);
    ctx->pc = 0x1161B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1161B4u;
            // 0x1161b8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1114B8u;
    if (runtime->hasFunction(0x1114B8u)) {
        auto targetFn = runtime->lookupFunction(0x1114B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161BCu; }
        if (ctx->pc != 0x1161BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001114B8_0x1114b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161BCu; }
        if (ctx->pc != 0x1161BCu) { return; }
    }
    ctx->pc = 0x1161BCu;
label_1161bc:
    // 0x1161bc: 0xc045806  jal         func_116018
    ctx->pc = 0x1161BCu;
    SET_GPR_U32(ctx, 31, 0x1161C4u);
    ctx->pc = 0x1161C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1161BCu;
            // 0x1161c0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116018u;
    if (runtime->hasFunction(0x116018u)) {
        auto targetFn = runtime->lookupFunction(0x116018u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161C4u; }
        if (ctx->pc != 0x1161C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116018_0x116018(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161C4u; }
        if (ctx->pc != 0x1161C4u) { return; }
    }
    ctx->pc = 0x1161C4u;
label_1161c4:
    // 0x1161c4: 0x264489c0  addiu       $a0, $s2, -0x7640
    ctx->pc = 0x1161c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 4294937024));
    // 0x1161c8: 0xc045a04  jal         func_116810
    ctx->pc = 0x1161C8u;
    SET_GPR_U32(ctx, 31, 0x1161D0u);
    ctx->pc = 0x1161CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1161C8u;
            // 0x1161cc: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161D0u; }
        if (ctx->pc != 0x1161D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1161D0u; }
        if (ctx->pc != 0x1161D0u) { return; }
    }
    ctx->pc = 0x1161D0u;
label_1161d0:
    // 0x1161d0: 0x6200009  bltz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1161D0u;
    {
        const bool branch_taken_0x1161d0 = (GPR_S64(ctx, 17) < 0);
        ctx->pc = 0x1161D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1161D0u;
            // 0x1161d4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1161d0) {
            ctx->pc = 0x1161F8u;
            goto label_1161f8;
        }
    }
    ctx->pc = 0x1161D8u;
    // 0x1161d8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1161d8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1161dc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1161dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1161e0: 0x248489c8  addiu       $a0, $a0, -0x7638
    ctx->pc = 0x1161e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937032));
    // 0x1161e4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1161e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1161e8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1161e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1161ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1161ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1161f0: 0x8045a04  j           func_116810
    ctx->pc = 0x1161F0u;
    ctx->pc = 0x1161F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1161F0u;
            // 0x1161f4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116810_0x116810(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1161F8u;
label_1161f8:
    // 0x1161f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1161f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1161fc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1161fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x116200: 0x248489d0  addiu       $a0, $a0, -0x7630
    ctx->pc = 0x116200u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937040));
    // 0x116204: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x116204u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116208: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x116208u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11620c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11620cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116210: 0x8045a04  j           func_116810
    ctx->pc = 0x116210u;
    ctx->pc = 0x116214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116210u;
            // 0x116214: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116810_0x116810(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x116218u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111648
// Address: 0x111648 - 0x111770
void sub_00111648_0x111648(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111648_0x111648");
#endif

    switch (ctx->pc) {
        case 0x111664u: goto label_111664;
        case 0x111678u: goto label_111678;
        case 0x111694u: goto label_111694;
        case 0x1116a0u: goto label_1116a0;
        case 0x1116bcu: goto label_1116bc;
        case 0x1116d0u: goto label_1116d0;
        case 0x1116e0u: goto label_1116e0;
        case 0x1116f0u: goto label_1116f0;
        case 0x111708u: goto label_111708;
        case 0x111724u: goto label_111724;
        case 0x111730u: goto label_111730;
        case 0x111748u: goto label_111748;
        default: break;
    }

    ctx->pc = 0x111648u;

    // 0x111648: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x111648u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11164c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x11164cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x111650: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x111650u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x111654: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x111654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x111658: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x111658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x11165c: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x11165Cu;
    SET_GPR_U32(ctx, 31, 0x111664u);
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111664u; }
        if (ctx->pc != 0x111664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111664u; }
        if (ctx->pc != 0x111664u) { return; }
    }
    ctx->pc = 0x111664u;
label_111664:
    // 0x111664: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x111664u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111668: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x111668u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11166c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11166cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111670: 0xc0448a6  jal         func_112298
    ctx->pc = 0x111670u;
    SET_GPR_U32(ctx, 31, 0x111678u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111678u; }
        if (ctx->pc != 0x111678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111678u; }
        if (ctx->pc != 0x111678u) { return; }
    }
    ctx->pc = 0x111678u;
label_111678:
    // 0x111678: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x111678u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11167c: 0x3405f7c0  ori         $a1, $zero, 0xF7C0
    ctx->pc = 0x11167cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)63424);
    // 0x111680: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x111680u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x111684: 0x4400034  bltz        $v0, . + 4 + (0x34 << 2)
    ctx->pc = 0x111684u;
    {
        const bool branch_taken_0x111684 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x111688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111684u;
            // 0x111688: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111684) {
            ctx->pc = 0x111758u;
            goto label_111758;
        }
    }
    ctx->pc = 0x11168Cu;
    // 0x11168c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11168Cu;
    SET_GPR_U32(ctx, 31, 0x111694u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111694u; }
        if (ctx->pc != 0x111694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111694u; }
        if (ctx->pc != 0x111694u) { return; }
    }
    ctx->pc = 0x111694u;
label_111694:
    // 0x111694: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111694u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111698: 0xc044932  jal         func_1124C8
    ctx->pc = 0x111698u;
    SET_GPR_U32(ctx, 31, 0x1116A0u);
    ctx->pc = 0x1124C8u;
    if (runtime->hasFunction(0x1124C8u)) {
        auto targetFn = runtime->lookupFunction(0x1124C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116A0u; }
        if (ctx->pc != 0x1116A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001124C8_0x1124c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116A0u; }
        if (ctx->pc != 0x1116A0u) { return; }
    }
    ctx->pc = 0x1116A0u;
label_1116a0:
    // 0x1116a0: 0x2803c  dsll32      $s0, $v0, 0
    ctx->pc = 0x1116a0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1116a4: 0x32020001  andi        $v0, $s0, 0x1
    ctx->pc = 0x1116a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
    // 0x1116a8: 0x10207a  dsrl        $a0, $s0, 1
    ctx->pc = 0x1116a8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 16) >> 1);
    // 0x1116ac: 0x6000006  bltz        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1116ACu;
    {
        const bool branch_taken_0x1116ac = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x1116B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1116ACu;
            // 0x1116b0: 0x442025  or          $a0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1116ac) {
            ctx->pc = 0x1116C8u;
            goto label_1116c8;
        }
    }
    ctx->pc = 0x1116B4u;
    // 0x1116b4: 0xc0444ca  jal         func_111328
    ctx->pc = 0x1116B4u;
    SET_GPR_U32(ctx, 31, 0x1116BCu);
    ctx->pc = 0x1116B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1116B4u;
            // 0x1116b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116BCu; }
        if (ctx->pc != 0x1116BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116BCu; }
        if (ctx->pc != 0x1116BCu) { return; }
    }
    ctx->pc = 0x1116BCu;
label_1116bc:
    // 0x1116bc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1116BCu;
    {
        const bool branch_taken_0x1116bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1116bc) {
            ctx->pc = 0x1116E0u;
            goto label_1116e0;
        }
    }
    ctx->pc = 0x1116C4u;
    // 0x1116c4: 0x0  nop
    ctx->pc = 0x1116c4u;
    // NOP
label_1116c8:
    // 0x1116c8: 0xc0444ca  jal         func_111328
    ctx->pc = 0x1116C8u;
    SET_GPR_U32(ctx, 31, 0x1116D0u);
    ctx->pc = 0x111328u;
    if (runtime->hasFunction(0x111328u)) {
        auto targetFn = runtime->lookupFunction(0x111328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116D0u; }
        if (ctx->pc != 0x1116D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116D0u; }
        if (ctx->pc != 0x1116D0u) { return; }
    }
    ctx->pc = 0x1116D0u;
label_1116d0:
    // 0x1116d0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1116d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1116d4: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1116d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1116d8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x1116D8u;
    SET_GPR_U32(ctx, 31, 0x1116E0u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116E0u; }
        if (ctx->pc != 0x1116E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116E0u; }
        if (ctx->pc != 0x1116E0u) { return; }
    }
    ctx->pc = 0x1116E0u;
label_1116e0:
    // 0x1116e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1116e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1116e4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1116e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1116e8: 0xc044752  jal         func_111D48
    ctx->pc = 0x1116E8u;
    SET_GPR_U32(ctx, 31, 0x1116F0u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116F0u; }
        if (ctx->pc != 0x1116F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1116F0u; }
        if (ctx->pc != 0x1116F0u) { return; }
    }
    ctx->pc = 0x1116F0u;
label_1116f0:
    // 0x1116f0: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1116f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1116f4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1116f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1116f8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1116f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1116fc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1116fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111700: 0xc0448a6  jal         func_112298
    ctx->pc = 0x111700u;
    SET_GPR_U32(ctx, 31, 0x111708u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111708u; }
        if (ctx->pc != 0x111708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111708u; }
        if (ctx->pc != 0x111708u) { return; }
    }
    ctx->pc = 0x111708u;
label_111708:
    // 0x111708: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x111708u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11170c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x11170cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111710: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x111710u;
    {
        const bool branch_taken_0x111710 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x111710) {
            ctx->pc = 0x111740u;
            goto label_111740;
        }
    }
    ctx->pc = 0x111718u;
    // 0x111718: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x111718u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11171c: 0xc044752  jal         func_111D48
    ctx->pc = 0x11171Cu;
    SET_GPR_U32(ctx, 31, 0x111724u);
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111724u; }
        if (ctx->pc != 0x111724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111724u; }
        if (ctx->pc != 0x111724u) { return; }
    }
    ctx->pc = 0x111724u;
label_111724:
    // 0x111724: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111724u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111728: 0xc044932  jal         func_1124C8
    ctx->pc = 0x111728u;
    SET_GPR_U32(ctx, 31, 0x111730u);
    ctx->pc = 0x1124C8u;
    if (runtime->hasFunction(0x1124C8u)) {
        auto targetFn = runtime->lookupFunction(0x1124C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111730u; }
        if (ctx->pc != 0x111730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001124C8_0x1124c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111730u; }
        if (ctx->pc != 0x111730u) { return; }
    }
    ctx->pc = 0x111730u;
label_111730:
    // 0x111730: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x111730u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x111734: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x111734u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x111738: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x111738u;
    {
        const bool branch_taken_0x111738 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11173Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111738u;
            // 0x11173c: 0x202802f  dsubu       $s0, $s0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111738) {
            ctx->pc = 0x111754u;
            goto label_111754;
        }
    }
    ctx->pc = 0x111740u;
label_111740:
    // 0x111740: 0xc044932  jal         func_1124C8
    ctx->pc = 0x111740u;
    SET_GPR_U32(ctx, 31, 0x111748u);
    ctx->pc = 0x1124C8u;
    if (runtime->hasFunction(0x1124C8u)) {
        auto targetFn = runtime->lookupFunction(0x1124C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111748u; }
        if (ctx->pc != 0x111748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001124C8_0x1124c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111748u; }
        if (ctx->pc != 0x111748u) { return; }
    }
    ctx->pc = 0x111748u;
label_111748:
    // 0x111748: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x111748u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x11174c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x11174cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x111750: 0x202802d  daddu       $s0, $s0, $v0
    ctx->pc = 0x111750u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 2));
label_111754:
    // 0x111754: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x111754u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_111758:
    // 0x111758: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x111758u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11175c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x11175cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x111760: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x111760u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x111764: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x111764u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x111768: 0x3e00008  jr          $ra
    ctx->pc = 0x111768u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11176Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111768u;
            // 0x11176c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111664u: goto label_111664;
            case 0x111678u: goto label_111678;
            case 0x111694u: goto label_111694;
            case 0x1116A0u: goto label_1116a0;
            case 0x1116BCu: goto label_1116bc;
            case 0x1116C8u: goto label_1116c8;
            case 0x1116D0u: goto label_1116d0;
            case 0x1116E0u: goto label_1116e0;
            case 0x1116F0u: goto label_1116f0;
            case 0x111708u: goto label_111708;
            case 0x111724u: goto label_111724;
            case 0x111730u: goto label_111730;
            case 0x111740u: goto label_111740;
            case 0x111748u: goto label_111748;
            case 0x111754u: goto label_111754;
            case 0x111758u: goto label_111758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111770u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB6E0
// Address: 0x1bb6e0 - 0x1bb7c0
void sub_001BB6E0_0x1bb6e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB6E0_0x1bb6e0");
#endif

    switch (ctx->pc) {
        case 0x1bb6f0u: goto label_1bb6f0;
        case 0x1bb738u: goto label_1bb738;
        case 0x1bb744u: goto label_1bb744;
        case 0x1bb750u: goto label_1bb750;
        case 0x1bb75cu: goto label_1bb75c;
        case 0x1bb774u: goto label_1bb774;
        case 0x1bb780u: goto label_1bb780;
        case 0x1bb78cu: goto label_1bb78c;
        case 0x1bb798u: goto label_1bb798;
        case 0x1bb7a4u: goto label_1bb7a4;
        case 0x1bb7acu: goto label_1bb7ac;
        default: break;
    }

    ctx->pc = 0x1bb6e0u;

    // 0x1bb6e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb6e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb6e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb6e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb6e8: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1BB6E8u;
    SET_GPR_U32(ctx, 31, 0x1BB6F0u);
    ctx->pc = 0x1BB6ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB6E8u;
            // 0x1bb6ec: 0x24040058  addiu       $a0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB6F0u; }
        if (ctx->pc != 0x1BB6F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB6F0u; }
        if (ctx->pc != 0x1BB6F0u) { return; }
    }
    ctx->pc = 0x1BB6F0u;
label_1bb6f0:
    // 0x1bb6f0: 0x1440002e  bnez        $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x1BB6F0u;
    {
        const bool branch_taken_0x1bb6f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB6F0u;
            // 0x1bb6f4: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb6f0) {
            ctx->pc = 0x1BB7ACu;
            goto label_1bb7ac;
        }
    }
    ctx->pc = 0x1BB6F8u;
    // 0x1bb6f8: 0x902243c0  lbu         $v0, 0x43C0($at)
    ctx->pc = 0x1bb6f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17344)));
    // 0x1bb6fc: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1BB6FCu;
    {
        const bool branch_taken_0x1bb6fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb6fc) {
            ctx->pc = 0x1BB75Cu;
            goto label_1bb75c;
        }
    }
    ctx->pc = 0x1BB704u;
    // 0x1bb704: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1bb704u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1bb708: 0x8022adf8  lb          $v0, -0x5208($at)
    ctx->pc = 0x1bb708u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946296)));
    // 0x1bb70c: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1BB70Cu;
    {
        const bool branch_taken_0x1bb70c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb70c) {
            ctx->pc = 0x1BB75Cu;
            goto label_1bb75c;
        }
    }
    ctx->pc = 0x1BB714u;
    // 0x1bb714: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb714u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb718: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1bb718u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1bb71c: 0x8c236614  lw          $v1, 0x6614($at)
    ctx->pc = 0x1bb71cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26132)));
    // 0x1bb720: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1bb720u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1bb724: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1BB724u;
    {
        const bool branch_taken_0x1bb724 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb724) {
            ctx->pc = 0x1BB75Cu;
            goto label_1bb75c;
        }
    }
    ctx->pc = 0x1BB72Cu;
    // 0x1bb72c: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1bb72cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1bb730: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BB730u;
    SET_GPR_U32(ctx, 31, 0x1BB738u);
    ctx->pc = 0x1BB734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB730u;
            // 0x1bb734: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB738u; }
        if (ctx->pc != 0x1BB738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB738u; }
        if (ctx->pc != 0x1BB738u) { return; }
    }
    ctx->pc = 0x1BB738u;
label_1bb738:
    // 0x1bb738: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1bb738u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1bb73c: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1BB73Cu;
    SET_GPR_U32(ctx, 31, 0x1BB744u);
    ctx->pc = 0x1BB740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB73Cu;
            // 0x1bb740: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB744u; }
        if (ctx->pc != 0x1BB744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB744u; }
        if (ctx->pc != 0x1BB744u) { return; }
    }
    ctx->pc = 0x1BB744u;
label_1bb744:
    // 0x1bb744: 0x2404005e  addiu       $a0, $zero, 0x5E
    ctx->pc = 0x1bb744u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x1bb748: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BB748u;
    SET_GPR_U32(ctx, 31, 0x1BB750u);
    ctx->pc = 0x1BB74Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB748u;
            // 0x1bb74c: 0x24050032  addiu       $a1, $zero, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB750u; }
        if (ctx->pc != 0x1BB750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB750u; }
        if (ctx->pc != 0x1BB750u) { return; }
    }
    ctx->pc = 0x1BB750u;
label_1bb750:
    // 0x1bb750: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb750u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb754: 0xc06aed8  jal         func_1ABB60
    ctx->pc = 0x1BB754u;
    SET_GPR_U32(ctx, 31, 0x1BB75Cu);
    ctx->pc = 0x1BB758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB754u;
            // 0x1bb758: 0x2484660c  addiu       $a0, $a0, 0x660C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26124));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ABB60u;
    if (runtime->hasFunction(0x1ABB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ABB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB75Cu; }
        if (ctx->pc != 0x1BB75Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ABB60_0x1abb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB75Cu; }
        if (ctx->pc != 0x1BB75Cu) { return; }
    }
    ctx->pc = 0x1BB75Cu;
label_1bb75c:
    // 0x1bb75c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb75cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb760: 0x90226620  lbu         $v0, 0x6620($at)
    ctx->pc = 0x1bb760u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26144)));
    // 0x1bb764: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1BB764u;
    {
        const bool branch_taken_0x1bb764 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB764u;
            // 0x1bb768: 0x2404006c  addiu       $a0, $zero, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb764) {
            ctx->pc = 0x1BB7A4u;
            goto label_1bb7a4;
        }
    }
    ctx->pc = 0x1BB76Cu;
    // 0x1bb76c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BB76Cu;
    SET_GPR_U32(ctx, 31, 0x1BB774u);
    ctx->pc = 0x1BB770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB76Cu;
            // 0x1bb770: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB774u; }
        if (ctx->pc != 0x1BB774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB774u; }
        if (ctx->pc != 0x1BB774u) { return; }
    }
    ctx->pc = 0x1BB774u;
label_1bb774:
    // 0x1bb774: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1bb774u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1bb778: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1BB778u;
    SET_GPR_U32(ctx, 31, 0x1BB780u);
    ctx->pc = 0x1BB77Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB778u;
            // 0x1bb77c: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB780u; }
        if (ctx->pc != 0x1BB780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB780u; }
        if (ctx->pc != 0x1BB780u) { return; }
    }
    ctx->pc = 0x1BB780u;
label_1bb780:
    // 0x1bb780: 0x2404005e  addiu       $a0, $zero, 0x5E
    ctx->pc = 0x1bb780u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x1bb784: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1BB784u;
    SET_GPR_U32(ctx, 31, 0x1BB78Cu);
    ctx->pc = 0x1BB788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB784u;
            // 0x1bb788: 0x24050032  addiu       $a1, $zero, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB78Cu; }
        if (ctx->pc != 0x1BB78Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB78Cu; }
        if (ctx->pc != 0x1BB78Cu) { return; }
    }
    ctx->pc = 0x1BB78Cu;
label_1bb78c:
    // 0x1bb78c: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb78cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb790: 0xc06aed8  jal         func_1ABB60
    ctx->pc = 0x1BB790u;
    SET_GPR_U32(ctx, 31, 0x1BB798u);
    ctx->pc = 0x1BB794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB790u;
            // 0x1bb794: 0x2484662c  addiu       $a0, $a0, 0x662C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26156));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ABB60u;
    if (runtime->hasFunction(0x1ABB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ABB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB798u; }
        if (ctx->pc != 0x1BB798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ABB60_0x1abb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB798u; }
        if (ctx->pc != 0x1BB798u) { return; }
    }
    ctx->pc = 0x1BB798u;
label_1bb798:
    // 0x1bb798: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb798u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb79c: 0xc06aed8  jal         func_1ABB60
    ctx->pc = 0x1BB79Cu;
    SET_GPR_U32(ctx, 31, 0x1BB7A4u);
    ctx->pc = 0x1BB7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB79Cu;
            // 0x1bb7a0: 0x24846638  addiu       $a0, $a0, 0x6638 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ABB60u;
    if (runtime->hasFunction(0x1ABB60u)) {
        auto targetFn = runtime->lookupFunction(0x1ABB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB7A4u; }
        if (ctx->pc != 0x1BB7A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ABB60_0x1abb60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB7A4u; }
        if (ctx->pc != 0x1BB7A4u) { return; }
    }
    ctx->pc = 0x1BB7A4u;
label_1bb7a4:
    // 0x1bb7a4: 0xc06edf0  jal         func_1BB7C0
    ctx->pc = 0x1BB7A4u;
    SET_GPR_U32(ctx, 31, 0x1BB7ACu);
    ctx->pc = 0x1BB7C0u;
    if (runtime->hasFunction(0x1BB7C0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB7ACu; }
        if (ctx->pc != 0x1BB7ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB7C0_0x1bb7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB7ACu; }
        if (ctx->pc != 0x1BB7ACu) { return; }
    }
    ctx->pc = 0x1BB7ACu;
label_1bb7ac:
    // 0x1bb7ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bb7acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb7b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB7B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB7B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB7B0u;
            // 0x1bb7b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB6F0u: goto label_1bb6f0;
            case 0x1BB738u: goto label_1bb738;
            case 0x1BB744u: goto label_1bb744;
            case 0x1BB750u: goto label_1bb750;
            case 0x1BB75Cu: goto label_1bb75c;
            case 0x1BB774u: goto label_1bb774;
            case 0x1BB780u: goto label_1bb780;
            case 0x1BB78Cu: goto label_1bb78c;
            case 0x1BB798u: goto label_1bb798;
            case 0x1BB7A4u: goto label_1bb7a4;
            case 0x1BB7ACu: goto label_1bb7ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB7B8u;
    // 0x1bb7b8: 0x0  nop
    ctx->pc = 0x1bb7b8u;
    // NOP
    // 0x1bb7bc: 0x0  nop
    ctx->pc = 0x1bb7bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

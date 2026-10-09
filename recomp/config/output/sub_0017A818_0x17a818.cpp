#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A818
// Address: 0x17a818 - 0x17a918
void sub_0017A818_0x17a818(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A818_0x17a818");
#endif

    switch (ctx->pc) {
        case 0x17a868u: goto label_17a868;
        case 0x17a884u: goto label_17a884;
        case 0x17a8a8u: goto label_17a8a8;
        case 0x17a8b8u: goto label_17a8b8;
        case 0x17a8ccu: goto label_17a8cc;
        case 0x17a8d8u: goto label_17a8d8;
        case 0x17a8e4u: goto label_17a8e4;
        case 0x17a8f8u: goto label_17a8f8;
        default: break;
    }

    ctx->pc = 0x17a818u;

    // 0x17a818: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17a818u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a81c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17a81cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17a820: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17a820u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a824: 0x805ea46  j           func_17A918
    ctx->pc = 0x17A824u;
    ctx->pc = 0x17A828u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A824u;
            // 0x17a828: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A918u;
    if (runtime->hasFunction(0x17A918u)) {
        auto targetFn = runtime->lookupFunction(0x17A918u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017A918_0x17a918(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17A82Cu;
    // 0x17a82c: 0x0  nop
    ctx->pc = 0x17a82cu;
    // NOP
    // 0x17a830: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17a830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17a834: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17a834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17a838: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17a838u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a83c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17a83cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17a840: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17a840u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a844: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x17a844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x17a848: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x17a848u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a84c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x17a84cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x17a850: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x17a850u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a854: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x17a854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x17a858: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x17a858u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x17a85c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17a85cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17a860: 0xc05f49a  jal         func_17D268
    ctx->pc = 0x17A860u;
    SET_GPR_U32(ctx, 31, 0x17A868u);
    ctx->pc = 0x17A864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A860u;
            // 0x17a864: 0x8e120048  lw          $s2, 0x48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D268u;
    if (runtime->hasFunction(0x17D268u)) {
        auto targetFn = runtime->lookupFunction(0x17D268u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A868u; }
        if (ctx->pc != 0x17A868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D268_0x17d268(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A868u; }
        if (ctx->pc != 0x17A868u) { return; }
    }
    ctx->pc = 0x17A868u;
label_17a868:
    // 0x17a868: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x17a868u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a86c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17a86cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a870: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17a870u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a874: 0x128fc2  srl         $s1, $s2, 31
    ctx->pc = 0x17a874u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x17a878: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x17a878u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x17a87c: 0xc05f496  jal         func_17D258
    ctx->pc = 0x17A87Cu;
    SET_GPR_U32(ctx, 31, 0x17A884u);
    ctx->pc = 0x17A880u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A87Cu;
            // 0x17a880: 0x2518821  addu        $s1, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D258u;
    if (runtime->hasFunction(0x17D258u)) {
        auto targetFn = runtime->lookupFunction(0x17D258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A884u; }
        if (ctx->pc != 0x17A884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D258_0x17d258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A884u; }
        if (ctx->pc != 0x17A884u) { return; }
    }
    ctx->pc = 0x17A884u;
label_17a884:
    // 0x17a884: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17a884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17a888: 0x118843  sra         $s1, $s1, 1
    ctx->pc = 0x17a888u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x17a88c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a88cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a890: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17a890u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17a894: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17a894u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a898: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17a898u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17a89c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17a89cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17a8a0: 0xc05f546  jal         func_17D518
    ctx->pc = 0x17A8A0u;
    SET_GPR_U32(ctx, 31, 0x17A8A8u);
    ctx->pc = 0x17A8A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A8A0u;
            // 0x17a8a4: 0xae020048  sw          $v0, 0x48($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D518u;
    {
        auto targetFn = runtime->lookupFunction(0x17D518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8A8u; }
        if (ctx->pc != 0x17A8A8u) { return; }
    }
    ctx->pc = 0x17A8A8u;
label_17a8a8:
    // 0x17a8a8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17a8a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8ac: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a8acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8b0: 0xc05ea46  jal         func_17A918
    ctx->pc = 0x17A8B0u;
    SET_GPR_U32(ctx, 31, 0x17A8B8u);
    ctx->pc = 0x17A8B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A8B0u;
            // 0x17a8b4: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A918u;
    if (runtime->hasFunction(0x17A918u)) {
        auto targetFn = runtime->lookupFunction(0x17A918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8B8u; }
        if (ctx->pc != 0x17A8B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A918_0x17a918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8B8u; }
        if (ctx->pc != 0x17A8B8u) { return; }
    }
    ctx->pc = 0x17A8B8u;
label_17a8b8:
    // 0x17a8b8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17a8b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8bc: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x17a8bcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a8c0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17a8c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8c4: 0xc05f496  jal         func_17D258
    ctx->pc = 0x17A8C4u;
    SET_GPR_U32(ctx, 31, 0x17A8CCu);
    ctx->pc = 0x17A8C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A8C4u;
            // 0x17a8c8: 0x52840  sll         $a1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D258u;
    if (runtime->hasFunction(0x17D258u)) {
        auto targetFn = runtime->lookupFunction(0x17D258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8CCu; }
        if (ctx->pc != 0x17A8CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D258_0x17d258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8CCu; }
        if (ctx->pc != 0x17A8CCu) { return; }
    }
    ctx->pc = 0x17A8CCu;
label_17a8cc:
    // 0x17a8cc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a8ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8d0: 0xc05f546  jal         func_17D518
    ctx->pc = 0x17A8D0u;
    SET_GPR_U32(ctx, 31, 0x17A8D8u);
    ctx->pc = 0x17A8D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A8D0u;
            // 0x17a8d4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D518u;
    {
        auto targetFn = runtime->lookupFunction(0x17D518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8D8u; }
        if (ctx->pc != 0x17A8D8u) { return; }
    }
    ctx->pc = 0x17A8D8u;
label_17a8d8:
    // 0x17a8d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a8d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8dc: 0xc05f524  jal         func_17D490
    ctx->pc = 0x17A8DCu;
    SET_GPR_U32(ctx, 31, 0x17A8E4u);
    ctx->pc = 0x17A8E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A8DCu;
            // 0x17a8e0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D490u;
    {
        auto targetFn = runtime->lookupFunction(0x17D490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8E4u; }
        if (ctx->pc != 0x17A8E4u) { return; }
    }
    ctx->pc = 0x17A8E4u;
label_17a8e4:
    // 0x17a8e4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17a8e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8e8: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x17a8e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a8ec: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a8ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a8f0: 0xc05ea46  jal         func_17A918
    ctx->pc = 0x17A8F0u;
    SET_GPR_U32(ctx, 31, 0x17A8F8u);
    ctx->pc = 0x17A8F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A8F0u;
            // 0x17a8f4: 0x2863021  addu        $a2, $s4, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A918u;
    if (runtime->hasFunction(0x17A918u)) {
        auto targetFn = runtime->lookupFunction(0x17A918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8F8u; }
        if (ctx->pc != 0x17A8F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A918_0x17a918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A8F8u; }
        if (ctx->pc != 0x17A8F8u) { return; }
    }
    ctx->pc = 0x17A8F8u;
label_17a8f8:
    // 0x17a8f8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17a8f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a8fc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17a8fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a900: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17a900u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17a904: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x17a904u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17a908: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x17a908u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17a90c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x17a90cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17a910: 0x3e00008  jr          $ra
    ctx->pc = 0x17A910u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A910u;
            // 0x17a914: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A868u: goto label_17a868;
            case 0x17A884u: goto label_17a884;
            case 0x17A8A8u: goto label_17a8a8;
            case 0x17A8B8u: goto label_17a8b8;
            case 0x17A8CCu: goto label_17a8cc;
            case 0x17A8D8u: goto label_17a8d8;
            case 0x17A8E4u: goto label_17a8e4;
            case 0x17A8F8u: goto label_17a8f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A918u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

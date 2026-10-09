#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017BA20
// Address: 0x17ba20 - 0x17bae8
void sub_0017BA20_0x17ba20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017BA20_0x17ba20");
#endif

    switch (ctx->pc) {
        case 0x17ba70u: goto label_17ba70;
        case 0x17ba9cu: goto label_17ba9c;
        case 0x17baacu: goto label_17baac;
        case 0x17bab8u: goto label_17bab8;
        case 0x17bac4u: goto label_17bac4;
        default: break;
    }

    ctx->pc = 0x17ba20u;

    // 0x17ba20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17ba20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17ba24: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17ba24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17ba28: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17ba28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ba2c: 0x805eedc  j           func_17BB70
    ctx->pc = 0x17BA2Cu;
    ctx->pc = 0x17BA30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BA2Cu;
            // 0x17ba30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BB70u;
    if (runtime->hasFunction(0x17BB70u)) {
        auto targetFn = runtime->lookupFunction(0x17BB70u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017BB70_0x17bb70(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17BA34u;
    // 0x17ba34: 0x0  nop
    ctx->pc = 0x17ba34u;
    // NOP
    // 0x17ba38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17ba38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17ba3c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17ba3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17ba40: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17ba40u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ba44: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17ba44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17ba48: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17ba48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ba4c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x17ba4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x17ba50: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x17ba50u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ba54: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x17ba54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x17ba58: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x17ba58u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ba5c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x17ba5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x17ba60: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x17ba60u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x17ba64: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17ba64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17ba68: 0xc05f49a  jal         func_17D268
    ctx->pc = 0x17BA68u;
    SET_GPR_U32(ctx, 31, 0x17BA70u);
    ctx->pc = 0x17BA6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BA68u;
            // 0x17ba6c: 0x8e120048  lw          $s2, 0x48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D268u;
    if (runtime->hasFunction(0x17D268u)) {
        auto targetFn = runtime->lookupFunction(0x17D268u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BA70u; }
        if (ctx->pc != 0x17BA70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D268_0x17d268(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BA70u; }
        if (ctx->pc != 0x17BA70u) { return; }
    }
    ctx->pc = 0x17BA70u;
label_17ba70:
    // 0x17ba70: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17ba70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17ba74: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ba74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ba78: 0x128fc2  srl         $s1, $s2, 31
    ctx->pc = 0x17ba78u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x17ba7c: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17ba7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17ba80: 0x2518821  addu        $s1, $s2, $s1
    ctx->pc = 0x17ba80u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x17ba84: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17ba84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17ba88: 0x118843  sra         $s1, $s1, 1
    ctx->pc = 0x17ba88u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x17ba8c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17ba8cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17ba90: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ba90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ba94: 0xc05f546  jal         func_17D518
    ctx->pc = 0x17BA94u;
    SET_GPR_U32(ctx, 31, 0x17BA9Cu);
    ctx->pc = 0x17BA98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BA94u;
            // 0x17ba98: 0xae020048  sw          $v0, 0x48($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D518u;
    if (runtime->hasFunction(0x17D518u)) {
        auto targetFn = runtime->lookupFunction(0x17D518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BA9Cu; }
        if (ctx->pc != 0x17BA9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D518_0x17d518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BA9Cu; }
        if (ctx->pc != 0x17BA9Cu) { return; }
    }
    ctx->pc = 0x17BA9Cu;
label_17ba9c:
    // 0x17ba9c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17ba9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17baa0: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x17baa0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17baa4: 0xc05eedc  jal         func_17BB70
    ctx->pc = 0x17BAA4u;
    SET_GPR_U32(ctx, 31, 0x17BAACu);
    ctx->pc = 0x17BAA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BAA4u;
            // 0x17baa8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17BB70u;
    if (runtime->hasFunction(0x17BB70u)) {
        auto targetFn = runtime->lookupFunction(0x17BB70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BAACu; }
        if (ctx->pc != 0x17BAACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017BB70_0x17bb70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BAACu; }
        if (ctx->pc != 0x17BAACu) { return; }
    }
    ctx->pc = 0x17BAACu;
label_17baac:
    // 0x17baac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17baacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17bab0: 0xc05f546  jal         func_17D518
    ctx->pc = 0x17BAB0u;
    SET_GPR_U32(ctx, 31, 0x17BAB8u);
    ctx->pc = 0x17BAB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BAB0u;
            // 0x17bab4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D518u;
    if (runtime->hasFunction(0x17D518u)) {
        auto targetFn = runtime->lookupFunction(0x17D518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BAB8u; }
        if (ctx->pc != 0x17BAB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D518_0x17d518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BAB8u; }
        if (ctx->pc != 0x17BAB8u) { return; }
    }
    ctx->pc = 0x17BAB8u;
label_17bab8:
    // 0x17bab8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17bab8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17babc: 0xc05f524  jal         func_17D490
    ctx->pc = 0x17BABCu;
    SET_GPR_U32(ctx, 31, 0x17BAC4u);
    ctx->pc = 0x17BAC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BABCu;
            // 0x17bac0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D490u;
    if (runtime->hasFunction(0x17D490u)) {
        auto targetFn = runtime->lookupFunction(0x17D490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BAC4u; }
        if (ctx->pc != 0x17BAC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D490_0x17d490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17BAC4u; }
        if (ctx->pc != 0x17BAC4u) { return; }
    }
    ctx->pc = 0x17BAC4u;
label_17bac4:
    // 0x17bac4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17bac4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17bac8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17bac8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17bacc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17baccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17bad0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x17bad0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17bad4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x17bad4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17bad8: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x17bad8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17badc: 0x3e00008  jr          $ra
    ctx->pc = 0x17BADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17BAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BADCu;
            // 0x17bae0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17BA70u: goto label_17ba70;
            case 0x17BA9Cu: goto label_17ba9c;
            case 0x17BAACu: goto label_17baac;
            case 0x17BAB8u: goto label_17bab8;
            case 0x17BAC4u: goto label_17bac4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17BAE4u;
    // 0x17bae4: 0x0  nop
    ctx->pc = 0x17bae4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

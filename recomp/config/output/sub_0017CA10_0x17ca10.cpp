#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CA10
// Address: 0x17ca10 - 0x17cb10
void sub_0017CA10_0x17ca10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CA10_0x17ca10");
#endif

    switch (ctx->pc) {
        case 0x17ca60u: goto label_17ca60;
        case 0x17ca7cu: goto label_17ca7c;
        case 0x17caa0u: goto label_17caa0;
        case 0x17cab0u: goto label_17cab0;
        case 0x17cac4u: goto label_17cac4;
        case 0x17cad0u: goto label_17cad0;
        case 0x17cadcu: goto label_17cadc;
        case 0x17caf0u: goto label_17caf0;
        default: break;
    }

    ctx->pc = 0x17ca10u;

    // 0x17ca10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17ca10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17ca14: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17ca14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17ca18: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17ca18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ca1c: 0x805f2c4  j           func_17CB10
    ctx->pc = 0x17CA1Cu;
    ctx->pc = 0x17CA20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CA1Cu;
            // 0x17ca20: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CB10u;
    if (runtime->hasFunction(0x17CB10u)) {
        auto targetFn = runtime->lookupFunction(0x17CB10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017CB10_0x17cb10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CA24u;
    // 0x17ca24: 0x0  nop
    ctx->pc = 0x17ca24u;
    // NOP
    // 0x17ca28: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17ca28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17ca2c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17ca2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17ca30: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17ca30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca34: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17ca34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17ca38: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17ca38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca3c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x17ca3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x17ca40: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x17ca40u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca44: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x17ca44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x17ca48: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x17ca48u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca4c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x17ca4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x17ca50: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x17ca50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x17ca54: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17ca54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17ca58: 0xc05f49a  jal         func_17D268
    ctx->pc = 0x17CA58u;
    SET_GPR_U32(ctx, 31, 0x17CA60u);
    ctx->pc = 0x17CA5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CA58u;
            // 0x17ca5c: 0x8e120048  lw          $s2, 0x48($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D268u;
    if (runtime->hasFunction(0x17D268u)) {
        auto targetFn = runtime->lookupFunction(0x17D268u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CA60u; }
        if (ctx->pc != 0x17CA60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D268_0x17d268(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CA60u; }
        if (ctx->pc != 0x17CA60u) { return; }
    }
    ctx->pc = 0x17CA60u;
label_17ca60:
    // 0x17ca60: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x17ca60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ca64: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17ca64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca68: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17ca68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca6c: 0x128fc2  srl         $s1, $s2, 31
    ctx->pc = 0x17ca6cu;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 18), 31));
    // 0x17ca70: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x17ca70u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x17ca74: 0xc05f496  jal         func_17D258
    ctx->pc = 0x17CA74u;
    SET_GPR_U32(ctx, 31, 0x17CA7Cu);
    ctx->pc = 0x17CA78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CA74u;
            // 0x17ca78: 0x2518821  addu        $s1, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D258u;
    if (runtime->hasFunction(0x17D258u)) {
        auto targetFn = runtime->lookupFunction(0x17D258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CA7Cu; }
        if (ctx->pc != 0x17CA7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D258_0x17d258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CA7Cu; }
        if (ctx->pc != 0x17CA7Cu) { return; }
    }
    ctx->pc = 0x17CA7Cu;
label_17ca7c:
    // 0x17ca7c: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17ca7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17ca80: 0x118843  sra         $s1, $s1, 1
    ctx->pc = 0x17ca80u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x17ca84: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ca84u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca88: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17ca88u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17ca8c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ca8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca90: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17ca90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17ca94: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17ca94u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17ca98: 0xc05f546  jal         func_17D518
    ctx->pc = 0x17CA98u;
    SET_GPR_U32(ctx, 31, 0x17CAA0u);
    ctx->pc = 0x17CA9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CA98u;
            // 0x17ca9c: 0xae020048  sw          $v0, 0x48($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 72), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D518u;
    if (runtime->hasFunction(0x17D518u)) {
        auto targetFn = runtime->lookupFunction(0x17D518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAA0u; }
        if (ctx->pc != 0x17CAA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D518_0x17d518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAA0u; }
        if (ctx->pc != 0x17CAA0u) { return; }
    }
    ctx->pc = 0x17CAA0u;
label_17caa0:
    // 0x17caa0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17caa0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17caa4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17caa4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17caa8: 0xc05f2c4  jal         func_17CB10
    ctx->pc = 0x17CAA8u;
    SET_GPR_U32(ctx, 31, 0x17CAB0u);
    ctx->pc = 0x17CAACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CAA8u;
            // 0x17caac: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CB10u;
    if (runtime->hasFunction(0x17CB10u)) {
        auto targetFn = runtime->lookupFunction(0x17CB10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAB0u; }
        if (ctx->pc != 0x17CAB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CB10_0x17cb10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAB0u; }
        if (ctx->pc != 0x17CAB0u) { return; }
    }
    ctx->pc = 0x17CAB0u;
label_17cab0:
    // 0x17cab0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17cab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cab4: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x17cab4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cab8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17cab8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cabc: 0xc05f496  jal         func_17D258
    ctx->pc = 0x17CABCu;
    SET_GPR_U32(ctx, 31, 0x17CAC4u);
    ctx->pc = 0x17CAC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CABCu;
            // 0x17cac0: 0x52840  sll         $a1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D258u;
    if (runtime->hasFunction(0x17D258u)) {
        auto targetFn = runtime->lookupFunction(0x17D258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAC4u; }
        if (ctx->pc != 0x17CAC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D258_0x17d258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAC4u; }
        if (ctx->pc != 0x17CAC4u) { return; }
    }
    ctx->pc = 0x17CAC4u;
label_17cac4:
    // 0x17cac4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17cac4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cac8: 0xc05f546  jal         func_17D518
    ctx->pc = 0x17CAC8u;
    SET_GPR_U32(ctx, 31, 0x17CAD0u);
    ctx->pc = 0x17CACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CAC8u;
            // 0x17cacc: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D518u;
    if (runtime->hasFunction(0x17D518u)) {
        auto targetFn = runtime->lookupFunction(0x17D518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAD0u; }
        if (ctx->pc != 0x17CAD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D518_0x17d518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAD0u; }
        if (ctx->pc != 0x17CAD0u) { return; }
    }
    ctx->pc = 0x17CAD0u;
label_17cad0:
    // 0x17cad0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17cad0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cad4: 0xc05f524  jal         func_17D490
    ctx->pc = 0x17CAD4u;
    SET_GPR_U32(ctx, 31, 0x17CADCu);
    ctx->pc = 0x17CAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CAD4u;
            // 0x17cad8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D490u;
    if (runtime->hasFunction(0x17D490u)) {
        auto targetFn = runtime->lookupFunction(0x17D490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CADCu; }
        if (ctx->pc != 0x17CADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D490_0x17d490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CADCu; }
        if (ctx->pc != 0x17CADCu) { return; }
    }
    ctx->pc = 0x17CADCu;
label_17cadc:
    // 0x17cadc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x17cadcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cae0: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x17cae0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cae4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17cae4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cae8: 0xc05f2c4  jal         func_17CB10
    ctx->pc = 0x17CAE8u;
    SET_GPR_U32(ctx, 31, 0x17CAF0u);
    ctx->pc = 0x17CAECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CAE8u;
            // 0x17caec: 0x2863021  addu        $a2, $s4, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CB10u;
    if (runtime->hasFunction(0x17CB10u)) {
        auto targetFn = runtime->lookupFunction(0x17CB10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAF0u; }
        if (ctx->pc != 0x17CAF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CB10_0x17cb10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CAF0u; }
        if (ctx->pc != 0x17CAF0u) { return; }
    }
    ctx->pc = 0x17CAF0u;
label_17caf0:
    // 0x17caf0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17caf0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17caf4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17caf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17caf8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17caf8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17cafc: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x17cafcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17cb00: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x17cb00u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17cb04: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x17cb04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17cb08: 0x3e00008  jr          $ra
    ctx->pc = 0x17CB08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CB0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CB08u;
            // 0x17cb0c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CA60u: goto label_17ca60;
            case 0x17CA7Cu: goto label_17ca7c;
            case 0x17CAA0u: goto label_17caa0;
            case 0x17CAB0u: goto label_17cab0;
            case 0x17CAC4u: goto label_17cac4;
            case 0x17CAD0u: goto label_17cad0;
            case 0x17CADCu: goto label_17cadc;
            case 0x17CAF0u: goto label_17caf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CB10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

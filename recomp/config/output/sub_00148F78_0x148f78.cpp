#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148F78
// Address: 0x148f78 - 0x1490a8
void sub_00148F78_0x148f78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148F78_0x148f78");
#endif

    switch (ctx->pc) {
        case 0x148facu: goto label_148fac;
        case 0x148fb8u: goto label_148fb8;
        case 0x148ff4u: goto label_148ff4;
        case 0x149010u: goto label_149010;
        case 0x14903cu: goto label_14903c;
        default: break;
    }

    ctx->pc = 0x148f78u;

    // 0x148f78: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x148f78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x148f7c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x148f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148f80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x148f84: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x148f84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148f88: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x148f88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x148f8c: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x148f8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148f90: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x148f90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x148f94: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x148f94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148f98: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x148f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x148f9c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x148f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x148fa0: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x148fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x148fa4: 0xc050fe2  jal         func_143F88
    ctx->pc = 0x148FA4u;
    SET_GPR_U32(ctx, 31, 0x148FACu);
    ctx->pc = 0x148FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148FA4u;
            // 0x148fa8: 0xae300860  sw          $s0, 0x860($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 2144), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x143F88u;
    if (runtime->hasFunction(0x143F88u)) {
        auto targetFn = runtime->lookupFunction(0x143F88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FACu; }
        if (ctx->pc != 0x148FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00143F88_0x143f88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FACu; }
        if (ctx->pc != 0x148FACu) { return; }
    }
    ctx->pc = 0x148FACu;
label_148fac:
    // 0x148fac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148facu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fb0: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x148FB0u;
    SET_GPR_U32(ctx, 31, 0x148FB8u);
    ctx->pc = 0x148FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148FB0u;
            // 0x148fb4: 0x2405001c  addiu       $a1, $zero, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FB8u; }
        if (ctx->pc != 0x148FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FB8u; }
        if (ctx->pc != 0x148FB8u) { return; }
    }
    ctx->pc = 0x148FB8u;
label_148fb8:
    // 0x148fb8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x148fb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fbc: 0x121842  srl         $v1, $s2, 1
    ctx->pc = 0x148fbcu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
    // 0x148fc0: 0x121442  srl         $v0, $s2, 17
    ctx->pc = 0x148fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 17));
    // 0x148fc4: 0x30750fff  andi        $s5, $v1, 0xFFF
    ctx->pc = 0x148fc4u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4095);
    // 0x148fc8: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x148fc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x148fcc: 0x122342  srl         $a0, $s2, 13
    ctx->pc = 0x148fccu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 18), 13));
    // 0x148fd0: 0x121bc2  srl         $v1, $s2, 15
    ctx->pc = 0x148fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 18), 15));
    // 0x148fd4: 0x30940003  andi        $s4, $a0, 0x3
    ctx->pc = 0x148fd4u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
    // 0x148fd8: 0x30730003  andi        $s3, $v1, 0x3
    ctx->pc = 0x148fd8u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
    // 0x148fdc: 0x10500005  beq         $v0, $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x148FDCu;
    {
        const bool branch_taken_0x148fdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        ctx->pc = 0x148FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148FDCu;
            // 0x148fe0: 0xae220158  sw          $v0, 0x158($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 344), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148fdc) {
            ctx->pc = 0x148FF4u;
            goto label_148ff4;
        }
    }
    ctx->pc = 0x148FE4u;
    // 0x148fe4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x148fe4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x148fe8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148fe8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fec: 0xc05221c  jal         func_148870
    ctx->pc = 0x148FECu;
    SET_GPR_U32(ctx, 31, 0x148FF4u);
    ctx->pc = 0x148FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148FECu;
            // 0x148ff0: 0x24a5e160  addiu       $a1, $a1, -0x1EA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959456));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FF4u; }
        if (ctx->pc != 0x148FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FF4u; }
        if (ctx->pc != 0x148FF4u) { return; }
    }
    ctx->pc = 0x148FF4u;
label_148ff4:
    // 0x148ff4: 0x1214c2  srl         $v0, $s2, 19
    ctx->pc = 0x148ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 19));
    // 0x148ff8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148ff8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ffc: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x148ffcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x149000: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x149000u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x149004: 0xae220154  sw          $v0, 0x154($s1)
    ctx->pc = 0x149004u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 340), GPR_U32(ctx, 2));
    // 0x149008: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x149008u;
    SET_GPR_U32(ctx, 31, 0x149010u);
    ctx->pc = 0x14900Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149008u;
            // 0x14900c: 0x128502  srl         $s0, $s2, 20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 18), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149010u; }
        if (ctx->pc != 0x149010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149010u; }
        if (ctx->pc != 0x149010u) { return; }
    }
    ctx->pc = 0x149010u;
label_149010:
    // 0x149010: 0x29202  srl         $s2, $v0, 8
    ctx->pc = 0x149010u;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x149014: 0x24020048  addiu       $v0, $zero, 0x48
    ctx->pc = 0x149014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x149018: 0x12020008  beq         $s0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x149018u;
    {
        const bool branch_taken_0x149018 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x14901Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149018u;
            // 0x14901c: 0x24020058  addiu       $v0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x149018) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149020u;
    // 0x149020: 0x12020006  beq         $s0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x149020u;
    {
        const bool branch_taken_0x149020 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x149024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149020u;
            // 0x149024: 0x24020044  addiu       $v0, $zero, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
        ctx->in_delay_slot = false;
        if (branch_taken_0x149020) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149028u;
    // 0x149028: 0x12020004  beq         $s0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x149028u;
    {
        const bool branch_taken_0x149028 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x14902Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149028u;
            // 0x14902c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x149028) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149030u;
    // 0x149030: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x149030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149034: 0xc05221c  jal         func_148870
    ctx->pc = 0x149034u;
    SET_GPR_U32(ctx, 31, 0x14903Cu);
    ctx->pc = 0x149038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149034u;
            // 0x149038: 0x24a5e188  addiu       $a1, $a1, -0x1E78 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959496));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14903Cu; }
        if (ctx->pc != 0x14903Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14903Cu; }
        if (ctx->pc != 0x14903Cu) { return; }
    }
    ctx->pc = 0x14903Cu;
label_14903c:
    // 0x14903c: 0x8e24013c  lw          $a0, 0x13C($s1)
    ctx->pc = 0x14903cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 316)));
    // 0x149040: 0x154480  sll         $t0, $s5, 18
    ctx->pc = 0x149040u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 21), 18));
    // 0x149044: 0x8e230140  lw          $v1, 0x140($s1)
    ctx->pc = 0x149044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 320)));
    // 0x149048: 0x124a80  sll         $t1, $s2, 10
    ctx->pc = 0x149048u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 18), 10));
    // 0x14904c: 0x8e26014c  lw          $a2, 0x14C($s1)
    ctx->pc = 0x14904cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 332)));
    // 0x149050: 0x133b00  sll         $a3, $s3, 12
    ctx->pc = 0x149050u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 19), 12));
    // 0x149054: 0x8e220150  lw          $v0, 0x150($s1)
    ctx->pc = 0x149054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 336)));
    // 0x149058: 0x142b00  sll         $a1, $s4, 12
    ctx->pc = 0x149058u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 20), 12));
    // 0x14905c: 0x30840fff  andi        $a0, $a0, 0xFFF
    ctx->pc = 0x14905cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4095);
    // 0x149060: 0x30630fff  andi        $v1, $v1, 0xFFF
    ctx->pc = 0x149060u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4095);
    // 0x149064: 0xe43825  or          $a3, $a3, $a0
    ctx->pc = 0x149064u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
    // 0x149068: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x149068u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x14906c: 0xc83021  addu        $a2, $a2, $t0
    ctx->pc = 0x14906cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x149070: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x149070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x149074: 0xae220150  sw          $v0, 0x150($s1)
    ctx->pc = 0x149074u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 336), GPR_U32(ctx, 2));
    // 0x149078: 0xae27013c  sw          $a3, 0x13C($s1)
    ctx->pc = 0x149078u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 316), GPR_U32(ctx, 7));
    // 0x14907c: 0xae250140  sw          $a1, 0x140($s1)
    ctx->pc = 0x14907cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 320), GPR_U32(ctx, 5));
    // 0x149080: 0xae26014c  sw          $a2, 0x14C($s1)
    ctx->pc = 0x149080u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 332), GPR_U32(ctx, 6));
    // 0x149084: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x149084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x149088: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x149088u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14908c: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x14908cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x149090: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x149090u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x149094: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x149094u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x149098: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x149098u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14909c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14909cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1490a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1490A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1490A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1490A0u;
            // 0x1490a4: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148FACu: goto label_148fac;
            case 0x148FB8u: goto label_148fb8;
            case 0x148FF4u: goto label_148ff4;
            case 0x149010u: goto label_149010;
            case 0x14903Cu: goto label_14903c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1490A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

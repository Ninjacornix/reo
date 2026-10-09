#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AF60
// Address: 0x12af60 - 0x12b034
void sub_0012AF60_0x12af60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AF60_0x12af60");
#endif

    switch (ctx->pc) {
        case 0x12afb8u: goto label_12afb8;
        case 0x12afccu: goto label_12afcc;
        case 0x12afe8u: goto label_12afe8;
        case 0x12aff8u: goto label_12aff8;
        default: break;
    }

    ctx->pc = 0x12af60u;

    // 0x12af60: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12af60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12af64: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12af64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12af68: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12af68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12af6c: 0x24450548  addiu       $a1, $v0, 0x548
    ctx->pc = 0x12af6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1352));
    // 0x12af70: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12af70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12af74: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12af74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12af78: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12af78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12af7c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12af7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12af80: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12af80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12af84: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12af84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12af88: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x12af88u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12af8c: 0x1460001d  bnez        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x12AF8Cu;
    {
        const bool branch_taken_0x12af8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12AF90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF8Cu;
            // 0x12af90: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12af8c) {
            ctx->pc = 0x12B004u;
            goto label_12b004;
        }
    }
    ctx->pc = 0x12AF94u;
    // 0x12af94: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12af94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12af98: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12af98u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12af9c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12af9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12afa0: 0x245404c8  addiu       $s4, $v0, 0x4C8
    ctx->pc = 0x12afa0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 1224));
    // 0x12afa4: 0x24730498  addiu       $s3, $v1, 0x498
    ctx->pc = 0x12afa4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), 1176));
    // 0x12afa8: 0x24920484  addiu       $s2, $a0, 0x484
    ctx->pc = 0x12afa8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 1156));
    // 0x12afac: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x12afacu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12afb0: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12afb0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12afb4: 0x0  nop
    ctx->pc = 0x12afb4u;
    // NOP
label_12afb8:
    // 0x12afb8: 0xde820000  ld          $v0, 0x0($s4)
    ctx->pc = 0x12afb8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12afbc: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12afbcu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12afc0: 0xfe820000  sd          $v0, 0x0($s4)
    ctx->pc = 0x12afc0u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
    // 0x12afc4: 0xc05080e  jal         func_142038
    ctx->pc = 0x12AFC4u;
    SET_GPR_U32(ctx, 31, 0x12AFCCu);
    ctx->pc = 0x12AFC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AFC4u;
            // 0x12afc8: 0xae710000  sw          $s1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142038u;
    if (runtime->hasFunction(0x142038u)) {
        auto targetFn = runtime->lookupFunction(0x142038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFCCu; }
        if (ctx->pc != 0x12AFCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142038_0x142038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFCCu; }
        if (ctx->pc != 0x12AFCCu) { return; }
    }
    ctx->pc = 0x12AFCCu;
label_12afcc:
    // 0x12afcc: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x12afccu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x12afd0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12afd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12afd4: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x12afd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12afd8: 0x14510003  bne         $v0, $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AFD8u;
    {
        const bool branch_taken_0x12afd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x12afd8) {
            ctx->pc = 0x12AFE8u;
            goto label_12afe8;
        }
    }
    ctx->pc = 0x12AFE0u;
    // 0x12afe0: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AFE0u;
    SET_GPR_U32(ctx, 31, 0x12AFE8u);
    ctx->pc = 0x12AFE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AFE0u;
            // 0x12afe4: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFE8u; }
        if (ctx->pc != 0x12AFE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFE8u; }
        if (ctx->pc != 0x12AFE8u) { return; }
    }
    ctx->pc = 0x12AFE8u;
label_12afe8:
    // 0x12afe8: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AFE8u;
    {
        const bool branch_taken_0x12afe8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x12afe8) {
            ctx->pc = 0x12AFF8u;
            goto label_12aff8;
        }
    }
    ctx->pc = 0x12AFF0u;
    // 0x12aff0: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AFF0u;
    SET_GPR_U32(ctx, 31, 0x12AFF8u);
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFF8u; }
        if (ctx->pc != 0x12AFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AFF8u; }
        if (ctx->pc != 0x12AFF8u) { return; }
    }
    ctx->pc = 0x12AFF8u;
label_12aff8:
    // 0x12aff8: 0xdea20000  ld          $v0, 0x0($s5)
    ctx->pc = 0x12aff8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x12affc: 0x1040ffee  beqz        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x12AFFCu;
    {
        const bool branch_taken_0x12affc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AFFCu;
            // 0x12b000: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12affc) {
            ctx->pc = 0x12AFB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12afb8;
        }
    }
    ctx->pc = 0x12B004u;
label_12b004:
    // 0x12b004: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12b004u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b008: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12b008u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12b00c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12b00cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12b010: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12b010u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12b014: 0x24420550  addiu       $v0, $v0, 0x550
    ctx->pc = 0x12b014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1360));
    // 0x12b018: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12b018u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12b01c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12b01cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12b020: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12b020u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12b024: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12b024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b028: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12b028u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12b02c: 0x8045118  j           func_114460
    ctx->pc = 0x12B02Cu;
    ctx->pc = 0x12B030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B02Cu;
            // 0x12b030: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B034u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

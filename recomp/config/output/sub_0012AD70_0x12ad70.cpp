#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AD70
// Address: 0x12ad70 - 0x12ae4c
void sub_0012AD70_0x12ad70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AD70_0x12ad70");
#endif

    switch (ctx->pc) {
        case 0x12add0u: goto label_12add0;
        case 0x12adf8u: goto label_12adf8;
        case 0x12ae10u: goto label_12ae10;
        default: break;
    }

    ctx->pc = 0x12ad70u;

    // 0x12ad70: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12ad70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12ad74: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ad74u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ad78: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ad78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ad7c: 0x24450528  addiu       $a1, $v0, 0x528
    ctx->pc = 0x12ad7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1320));
    // 0x12ad80: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ad80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ad84: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ad84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ad88: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ad88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ad8c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12ad8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12ad90: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12ad90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12ad94: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12ad94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12ad98: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x12ad98u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12ad9c: 0x1460001f  bnez        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x12AD9Cu;
    {
        const bool branch_taken_0x12ad9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12ADA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AD9Cu;
            // 0x12ada0: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ad9c) {
            ctx->pc = 0x12AE1Cu;
            goto label_12ae1c;
        }
    }
    ctx->pc = 0x12ADA4u;
    // 0x12ada4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ada4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ada8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ada8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12adac: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12adacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12adb0: 0x3c111200  lui         $s1, 0x1200
    ctx->pc = 0x12adb0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)4608 << 16));
    // 0x12adb4: 0x245304b8  addiu       $s3, $v0, 0x4B8
    ctx->pc = 0x12adb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 1208));
    // 0x12adb8: 0x24720490  addiu       $s2, $v1, 0x490
    ctx->pc = 0x12adb8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 1168));
    // 0x12adbc: 0x24900564  addiu       $s0, $a0, 0x564
    ctx->pc = 0x12adbcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 1380));
    // 0x12adc0: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x12adc0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12adc4: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x12adc4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12adc8: 0x363100e0  ori         $s1, $s1, 0xE0
    ctx->pc = 0x12adc8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)224);
    // 0x12adcc: 0x0  nop
    ctx->pc = 0x12adccu;
    // NOP
label_12add0:
    // 0x12add0: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x12add0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12add4: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x12add4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12add8: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12add8u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12addc: 0xfe620000  sd          $v0, 0x0($s3)
    ctx->pc = 0x12addcu;
    WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 2));
    // 0x12ade0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12ADE0u;
    {
        const bool branch_taken_0x12ade0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12ADE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ADE0u;
            // 0x12ade4: 0xae540000  sw          $s4, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ade0) {
            ctx->pc = 0x12ADF0u;
            goto label_12adf0;
        }
    }
    ctx->pc = 0x12ADE8u;
    // 0x12ade8: 0x96020000  lhu         $v0, 0x0($s0)
    ctx->pc = 0x12ade8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12adec: 0xfe220000  sd          $v0, 0x0($s1)
    ctx->pc = 0x12adecu;
    WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 2));
label_12adf0:
    // 0x12adf0: 0xc0507fc  jal         func_141FF0
    ctx->pc = 0x12ADF0u;
    SET_GPR_U32(ctx, 31, 0x12ADF8u);
    ctx->pc = 0x141FF0u;
    if (runtime->hasFunction(0x141FF0u)) {
        auto targetFn = runtime->lookupFunction(0x141FF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ADF8u; }
        if (ctx->pc != 0x12ADF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141FF0_0x141ff0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ADF8u; }
        if (ctx->pc != 0x12ADF8u) { return; }
    }
    ctx->pc = 0x12ADF8u;
label_12adf8:
    // 0x12adf8: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x12adf8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12adfc: 0x54600001  bnel        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12ADFCu;
    {
        const bool branch_taken_0x12adfc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12adfc) {
            ctx->pc = 0x12AE00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12ADFCu;
            // 0x12ae00: 0xfe200000  sd          $zero, 0x0($s1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12AE04u;
            goto label_12ae04;
        }
    }
    ctx->pc = 0x12AE04u;
label_12ae04:
    // 0x12ae04: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x12ae04u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x12ae08: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AE08u;
    SET_GPR_U32(ctx, 31, 0x12AE10u);
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AE10u; }
        if (ctx->pc != 0x12AE10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AE10u; }
        if (ctx->pc != 0x12AE10u) { return; }
    }
    ctx->pc = 0x12AE10u;
label_12ae10:
    // 0x12ae10: 0xdea20000  ld          $v0, 0x0($s5)
    ctx->pc = 0x12ae10u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x12ae14: 0x1040ffee  beqz        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x12AE14u;
    {
        const bool branch_taken_0x12ae14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AE14u;
            // 0x12ae18: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ae14) {
            ctx->pc = 0x12ADD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12add0;
        }
    }
    ctx->pc = 0x12AE1Cu;
label_12ae1c:
    // 0x12ae1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ae1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ae20: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ae20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ae24: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12ae24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12ae28: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12ae28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ae2c: 0x24420530  addiu       $v0, $v0, 0x530
    ctx->pc = 0x12ae2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1328));
    // 0x12ae30: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12ae30u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ae34: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12ae34u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ae38: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12ae38u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ae3c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12ae3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ae40: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12ae40u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12ae44: 0x8045118  j           func_114460
    ctx->pc = 0x12AE44u;
    ctx->pc = 0x12AE48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AE44u;
            // 0x12ae48: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AE4Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AE50
// Address: 0x12ae50 - 0x12af60
void sub_0012AE50_0x12ae50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AE50_0x12ae50");
#endif

    switch (ctx->pc) {
        case 0x12aeb0u: goto label_12aeb0;
        case 0x12aec4u: goto label_12aec4;
        case 0x12aee0u: goto label_12aee0;
        case 0x12aef0u: goto label_12aef0;
        case 0x12af04u: goto label_12af04;
        case 0x12af18u: goto label_12af18;
        case 0x12af20u: goto label_12af20;
        default: break;
    }

    ctx->pc = 0x12ae50u;

    // 0x12ae50: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12ae50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12ae54: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ae54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ae58: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ae58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ae5c: 0x24450538  addiu       $a1, $v0, 0x538
    ctx->pc = 0x12ae5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 1336));
    // 0x12ae60: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ae60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ae64: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ae64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ae68: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12ae68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12ae6c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12ae6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12ae70: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12ae70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12ae74: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x12ae74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x12ae78: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x12ae78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x12ae7c: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x12ae7cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12ae80: 0x1460002a  bnez        $v1, . + 4 + (0x2A << 2)
    ctx->pc = 0x12AE80u;
    {
        const bool branch_taken_0x12ae80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12AE84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AE80u;
            // 0x12ae84: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ae80) {
            ctx->pc = 0x12AF2Cu;
            goto label_12af2c;
        }
    }
    ctx->pc = 0x12AE88u;
    // 0x12ae88: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12ae88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12ae8c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12ae8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12ae90: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12ae90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12ae94: 0x245404c0  addiu       $s4, $v0, 0x4C0
    ctx->pc = 0x12ae94u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 1216));
    // 0x12ae98: 0x24730494  addiu       $s3, $v1, 0x494
    ctx->pc = 0x12ae98u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), 1172));
    // 0x12ae9c: 0x24920484  addiu       $s2, $a0, 0x484
    ctx->pc = 0x12ae9cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), 1156));
    // 0x12aea0: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x12aea0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aea4: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x12aea4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12aea8: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x12aea8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x12aeac: 0x0  nop
    ctx->pc = 0x12aeacu;
    // NOP
label_12aeb0:
    // 0x12aeb0: 0xde820000  ld          $v0, 0x0($s4)
    ctx->pc = 0x12aeb0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12aeb4: 0x64420001  daddiu      $v0, $v0, 0x1
    ctx->pc = 0x12aeb4u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x12aeb8: 0xfe820000  sd          $v0, 0x0($s4)
    ctx->pc = 0x12aeb8u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 0), GPR_U64(ctx, 2));
    // 0x12aebc: 0xc050808  jal         func_142020
    ctx->pc = 0x12AEBCu;
    SET_GPR_U32(ctx, 31, 0x12AEC4u);
    ctx->pc = 0x12AEC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AEBCu;
            // 0x12aec0: 0xae710000  sw          $s1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142020u;
    if (runtime->hasFunction(0x142020u)) {
        auto targetFn = runtime->lookupFunction(0x142020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEC4u; }
        if (ctx->pc != 0x12AEC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142020_0x142020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEC4u; }
        if (ctx->pc != 0x12AEC4u) { return; }
    }
    ctx->pc = 0x12AEC4u;
label_12aec4:
    // 0x12aec4: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x12aec4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x12aec8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12aec8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aecc: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x12aeccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x12aed0: 0x14510003  bne         $v0, $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AED0u;
    {
        const bool branch_taken_0x12aed0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        if (branch_taken_0x12aed0) {
            ctx->pc = 0x12AEE0u;
            goto label_12aee0;
        }
    }
    ctx->pc = 0x12AED8u;
    // 0x12aed8: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AED8u;
    SET_GPR_U32(ctx, 31, 0x12AEE0u);
    ctx->pc = 0x12AEDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AED8u;
            // 0x12aedc: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEE0u; }
        if (ctx->pc != 0x12AEE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEE0u; }
        if (ctx->pc != 0x12AEE0u) { return; }
    }
    ctx->pc = 0x12AEE0u;
label_12aee0:
    // 0x12aee0: 0x1600000f  bnez        $s0, . + 4 + (0xF << 2)
    ctx->pc = 0x12AEE0u;
    {
        const bool branch_taken_0x12aee0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x12aee0) {
            ctx->pc = 0x12AF20u;
            goto label_12af20;
        }
    }
    ctx->pc = 0x12AEE8u;
    // 0x12aee8: 0xc04ad4c  jal         func_12B530
    ctx->pc = 0x12AEE8u;
    SET_GPR_U32(ctx, 31, 0x12AEF0u);
    ctx->pc = 0x12B530u;
    if (runtime->hasFunction(0x12B530u)) {
        auto targetFn = runtime->lookupFunction(0x12B530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEF0u; }
        if (ctx->pc != 0x12AEF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B530_0x12b530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AEF0u; }
        if (ctx->pc != 0x12AEF0u) { return; }
    }
    ctx->pc = 0x12AEF0u;
label_12aef0:
    // 0x12aef0: 0x14510009  bne         $v0, $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x12AEF0u;
    {
        const bool branch_taken_0x12aef0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x12AEF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AEF0u;
            // 0x12aef4: 0x26b004f0  addiu       $s0, $s5, 0x4F0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 1264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12aef0) {
            ctx->pc = 0x12AF18u;
            goto label_12af18;
        }
    }
    ctx->pc = 0x12AEF8u;
    // 0x12aef8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12aef8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12aefc: 0xc04ac3c  jal         func_12B0F0
    ctx->pc = 0x12AEFCu;
    SET_GPR_U32(ctx, 31, 0x12AF04u);
    ctx->pc = 0x12B0F0u;
    if (runtime->hasFunction(0x12B0F0u)) {
        auto targetFn = runtime->lookupFunction(0x12B0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF04u; }
        if (ctx->pc != 0x12AF04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0F0_0x12b0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF04u; }
        if (ctx->pc != 0x12AF04u) { return; }
    }
    ctx->pc = 0x12AF04u;
label_12af04:
    // 0x12af04: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12af04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12af08: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12AF08u;
    {
        const bool branch_taken_0x12af08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x12af08) {
            ctx->pc = 0x12AF18u;
            goto label_12af18;
        }
    }
    ctx->pc = 0x12AF10u;
    // 0x12af10: 0xc04ac22  jal         func_12B088
    ctx->pc = 0x12AF10u;
    SET_GPR_U32(ctx, 31, 0x12AF18u);
    ctx->pc = 0x12AF14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF10u;
            // 0x12af14: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B088u;
    if (runtime->hasFunction(0x12B088u)) {
        auto targetFn = runtime->lookupFunction(0x12B088u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF18u; }
        if (ctx->pc != 0x12AF18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B088_0x12b088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF18u; }
        if (ctx->pc != 0x12AF18u) { return; }
    }
    ctx->pc = 0x12AF18u;
label_12af18:
    // 0x12af18: 0xc04ac36  jal         func_12B0D8
    ctx->pc = 0x12AF18u;
    SET_GPR_U32(ctx, 31, 0x12AF20u);
    ctx->pc = 0x12B0D8u;
    if (runtime->hasFunction(0x12B0D8u)) {
        auto targetFn = runtime->lookupFunction(0x12B0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF20u; }
        if (ctx->pc != 0x12AF20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0D8_0x12b0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AF20u; }
        if (ctx->pc != 0x12AF20u) { return; }
    }
    ctx->pc = 0x12AF20u;
label_12af20:
    // 0x12af20: 0xdec20000  ld          $v0, 0x0($s6)
    ctx->pc = 0x12af20u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x12af24: 0x1040ffe2  beqz        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x12AF24u;
    {
        const bool branch_taken_0x12af24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AF28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF24u;
            // 0x12af28: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12af24) {
            ctx->pc = 0x12AEB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12aeb0;
        }
    }
    ctx->pc = 0x12AF2Cu;
label_12af2c:
    // 0x12af2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12af2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12af30: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12af30u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12af34: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12af34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12af38: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12af38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12af3c: 0x24420540  addiu       $v0, $v0, 0x540
    ctx->pc = 0x12af3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1344));
    // 0x12af40: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12af40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12af44: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12af44u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12af48: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12af48u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12af4c: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x12af4cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12af50: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x12af50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12af54: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12af54u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12af58: 0x8045118  j           func_114460
    ctx->pc = 0x12AF58u;
    ctx->pc = 0x12AF5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AF58u;
            // 0x12af5c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12AF60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012AA60
// Address: 0x12aa60 - 0x12ab38
void sub_0012AA60_0x12aa60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012AA60_0x12aa60");
#endif

    switch (ctx->pc) {
        case 0x12aab4u: goto label_12aab4;
        case 0x12aac0u: goto label_12aac0;
        case 0x12aad4u: goto label_12aad4;
        case 0x12aadcu: goto label_12aadc;
        case 0x12ab04u: goto label_12ab04;
        case 0x12ab10u: goto label_12ab10;
        case 0x12ab18u: goto label_12ab18;
        default: break;
    }

    ctx->pc = 0x12aa60u;

    // 0x12aa60: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12aa60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12aa64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12aa64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12aa68: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12aa68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aa6c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12aa6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12aa70: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x12aa70u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aa74: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12aa74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12aa78: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12aa78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12aa7c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12aa7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12aa80: 0x12200025  beqz        $s1, . + 4 + (0x25 << 2)
    ctx->pc = 0x12AA80u;
    {
        const bool branch_taken_0x12aa80 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AA84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AA80u;
            // 0x12aa84: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12aa80) {
            ctx->pc = 0x12AB18u;
            goto label_12ab18;
        }
    }
    ctx->pc = 0x12AA88u;
    // 0x12aa88: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12aa88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12aa8c: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x12aa8cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x12aa90: 0x8c450460  lw          $a1, 0x460($v0)
    ctx->pc = 0x12aa90u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1120)));
    // 0x12aa94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12aa94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12aa98: 0x26100484  addiu       $s0, $s0, 0x484
    ctx->pc = 0x12aa98u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1156));
    // 0x12aa9c: 0x3c120beb  lui         $s2, 0xBEB
    ctx->pc = 0x12aa9cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)3051 << 16));
    // 0x12aaa0: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12aaa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x12aaa4: 0x200982d  daddu       $s3, $s0, $zero
    ctx->pc = 0x12aaa4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12aaa8: 0x3652c1ff  ori         $s2, $s2, 0xC1FF
    ctx->pc = 0x12aaa8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)49663);
    // 0x12aaac: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12AAACu;
    SET_GPR_U32(ctx, 31, 0x12AAB4u);
    ctx->pc = 0x12AAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AAACu;
            // 0x12aab0: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AAB4u; }
        if (ctx->pc != 0x12AAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AAB4u; }
        if (ctx->pc != 0x12AAB4u) { return; }
    }
    ctx->pc = 0x12AAB4u;
label_12aab4:
    // 0x12aab4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12AAB4u;
    {
        const bool branch_taken_0x12aab4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12AAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AAB4u;
            // 0x12aab8: 0x250102a  slt         $v0, $s2, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12aab4) {
            ctx->pc = 0x12AAC4u;
            goto label_12aac4;
        }
    }
    ctx->pc = 0x12AABCu;
    // 0x12aabc: 0x0  nop
    ctx->pc = 0x12aabcu;
    // NOP
label_12aac0:
    // 0x12aac0: 0x250102a  slt         $v0, $s2, $s0
    ctx->pc = 0x12aac0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
label_12aac4:
    // 0x12aac4: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x12AAC4u;
    {
        const bool branch_taken_0x12aac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12aac4) {
            ctx->pc = 0x12AAC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12AAC4u;
            // 0x12aac8: 0x3c020beb  lui         $v0, 0xBEB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3051 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12AAECu;
            goto label_12aaec;
        }
    }
    ctx->pc = 0x12AACCu;
    // 0x12aacc: 0xc04ac22  jal         func_12B088
    ctx->pc = 0x12AACCu;
    SET_GPR_U32(ctx, 31, 0x12AAD4u);
    ctx->pc = 0x12AAD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AACCu;
            // 0x12aad0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B088u;
    if (runtime->hasFunction(0x12B088u)) {
        auto targetFn = runtime->lookupFunction(0x12B088u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AAD4u; }
        if (ctx->pc != 0x12AAD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B088_0x12b088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AAD4u; }
        if (ctx->pc != 0x12AAD4u) { return; }
    }
    ctx->pc = 0x12AAD4u;
label_12aad4:
    // 0x12aad4: 0xc04ac3c  jal         func_12B0F0
    ctx->pc = 0x12AAD4u;
    SET_GPR_U32(ctx, 31, 0x12AADCu);
    ctx->pc = 0x12AAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AAD4u;
            // 0x12aad8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B0F0u;
    if (runtime->hasFunction(0x12B0F0u)) {
        auto targetFn = runtime->lookupFunction(0x12B0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AADCu; }
        if (ctx->pc != 0x12AADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B0F0_0x12b0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AADCu; }
        if (ctx->pc != 0x12AADCu) { return; }
    }
    ctx->pc = 0x12AADCu;
label_12aadc:
    // 0x12aadc: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x12aadcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x12aae0: 0x5460fff7  bnel        $v1, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x12AAE0u;
    {
        const bool branch_taken_0x12aae0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12aae0) {
            ctx->pc = 0x12AAE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12AAE0u;
            // 0x12aae4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12AAC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12aac0;
        }
    }
    ctx->pc = 0x12AAE8u;
    // 0x12aae8: 0x3c020beb  lui         $v0, 0xBEB
    ctx->pc = 0x12aae8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3051 << 16));
label_12aaec:
    // 0x12aaec: 0x3442c200  ori         $v0, $v0, 0xC200
    ctx->pc = 0x12aaecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)49664);
    // 0x12aaf0: 0x56020005  bnel        $s0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12AAF0u;
    {
        const bool branch_taken_0x12aaf0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x12aaf0) {
            ctx->pc = 0x12AAF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12AAF0u;
            // 0x12aaf4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12AB08u;
            goto label_12ab08;
        }
    }
    ctx->pc = 0x12AAF8u;
    // 0x12aaf8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12aaf8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12aafc: 0xc05062a  jal         func_1418A8
    ctx->pc = 0x12AAFCu;
    SET_GPR_U32(ctx, 31, 0x12AB04u);
    ctx->pc = 0x12AB00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AAFCu;
            // 0x12ab00: 0x2484a4b8  addiu       $a0, $a0, -0x5B48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1418A8u;
    if (runtime->hasFunction(0x1418A8u)) {
        auto targetFn = runtime->lookupFunction(0x1418A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB04u; }
        if (ctx->pc != 0x12AB04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001418A8_0x1418a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB04u; }
        if (ctx->pc != 0x12AB04u) { return; }
    }
    ctx->pc = 0x12AB04u;
label_12ab04:
    // 0x12ab04: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12ab04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12ab08:
    // 0x12ab08: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12AB08u;
    SET_GPR_U32(ctx, 31, 0x12AB10u);
    ctx->pc = 0x12AB0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AB08u;
            // 0x12ab0c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB10u; }
        if (ctx->pc != 0x12AB10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB10u; }
        if (ctx->pc != 0x12AB10u) { return; }
    }
    ctx->pc = 0x12AB10u;
label_12ab10:
    // 0x12ab10: 0xc04ac56  jal         func_12B158
    ctx->pc = 0x12AB10u;
    SET_GPR_U32(ctx, 31, 0x12AB18u);
    ctx->pc = 0x12AB14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12AB10u;
            // 0x12ab14: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B158u;
    if (runtime->hasFunction(0x12B158u)) {
        auto targetFn = runtime->lookupFunction(0x12B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB18u; }
        if (ctx->pc != 0x12AB18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B158_0x12b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12AB18u; }
        if (ctx->pc != 0x12AB18u) { return; }
    }
    ctx->pc = 0x12AB18u;
label_12ab18:
    // 0x12ab18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ab18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12ab1c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ab1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ab20: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12ab20u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ab24: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12ab24u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12ab28: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12ab28u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ab2c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x12ab2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ab30: 0x3e00008  jr          $ra
    ctx->pc = 0x12AB30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12AB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12AB30u;
            // 0x12ab34: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12AAB4u: goto label_12aab4;
            case 0x12AAC0u: goto label_12aac0;
            case 0x12AAC4u: goto label_12aac4;
            case 0x12AAD4u: goto label_12aad4;
            case 0x12AADCu: goto label_12aadc;
            case 0x12AAECu: goto label_12aaec;
            case 0x12AB04u: goto label_12ab04;
            case 0x12AB08u: goto label_12ab08;
            case 0x12AB10u: goto label_12ab10;
            case 0x12AB18u: goto label_12ab18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12AB38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015ADE8
// Address: 0x15ade8 - 0x15af40
void sub_0015ADE8_0x15ade8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015ADE8_0x15ade8");
#endif

    switch (ctx->pc) {
        case 0x15ae10u: goto label_15ae10;
        case 0x15ae18u: goto label_15ae18;
        case 0x15ae38u: goto label_15ae38;
        case 0x15ae50u: goto label_15ae50;
        case 0x15ae68u: goto label_15ae68;
        case 0x15ae78u: goto label_15ae78;
        case 0x15ae94u: goto label_15ae94;
        case 0x15aeacu: goto label_15aeac;
        case 0x15aec4u: goto label_15aec4;
        case 0x15aef0u: goto label_15aef0;
        case 0x15af20u: goto label_15af20;
        default: break;
    }

    ctx->pc = 0x15ade8u;

    // 0x15ade8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15ade8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15adec: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x15adecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x15adf0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15adf0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15adf4: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x15adf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x15adf8: 0x27b30010  addiu       $s3, $sp, 0x10
    ctx->pc = 0x15adf8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x15adfc: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x15adfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x15ae00: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x15ae00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x15ae04: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x15AE04u;
    {
        const bool branch_taken_0x15ae04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE04u;
            // 0x15ae08: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ae04) {
            ctx->pc = 0x15AED0u;
            goto label_15aed0;
        }
    }
    ctx->pc = 0x15AE0Cu;
    // 0x15ae0c: 0x0  nop
    ctx->pc = 0x15ae0cu;
    // NOP
label_15ae10:
    // 0x15ae10: 0xc0561d4  jal         func_158750
    ctx->pc = 0x15AE10u;
    SET_GPR_U32(ctx, 31, 0x15AE18u);
    ctx->pc = 0x15AE14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE10u;
            // 0x15ae14: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE18u; }
        if (ctx->pc != 0x15AE18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE18u; }
        if (ctx->pc != 0x15AE18u) { return; }
    }
    ctx->pc = 0x15AE18u;
label_15ae18:
    // 0x15ae18: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x15ae18u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae1c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x15ae1cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae20: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x15ae20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae24: 0x16200012  bnez        $s1, . + 4 + (0x12 << 2)
    ctx->pc = 0x15AE24u;
    {
        const bool branch_taken_0x15ae24 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x15AE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE24u;
            // 0x15ae28: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ae24) {
            ctx->pc = 0x15AE70u;
            goto label_15ae70;
        }
    }
    ctx->pc = 0x15AE2Cu;
    // 0x15ae2c: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x15ae2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15ae30: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x15AE30u;
    SET_GPR_U32(ctx, 31, 0x15AE38u);
    ctx->pc = 0x15AE34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE30u;
            // 0x15ae34: 0x24a5fffd  addiu       $a1, $a1, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967293));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE38u; }
        if (ctx->pc != 0x15AE38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE38u; }
        if (ctx->pc != 0x15AE38u) { return; }
    }
    ctx->pc = 0x15AE38u;
label_15ae38:
    // 0x15ae38: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15ae38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15ae3c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15ae3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae40: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15ae40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae44: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15ae44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15ae48: 0x40f809  jalr        $v0
    ctx->pc = 0x15AE48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AE50u);
        ctx->pc = 0x15AE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE48u;
            // 0x15ae4c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AE50u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AE10u: goto label_15ae10;
            case 0x15AE18u: goto label_15ae18;
            case 0x15AE38u: goto label_15ae38;
            case 0x15AE50u: goto label_15ae50;
            case 0x15AE68u: goto label_15ae68;
            case 0x15AE70u: goto label_15ae70;
            case 0x15AE78u: goto label_15ae78;
            case 0x15AE94u: goto label_15ae94;
            case 0x15AEACu: goto label_15aeac;
            case 0x15AEC4u: goto label_15aec4;
            case 0x15AED0u: goto label_15aed0;
            case 0x15AED4u: goto label_15aed4;
            case 0x15AEF0u: goto label_15aef0;
            case 0x15AF20u: goto label_15af20;
            case 0x15AF24u: goto label_15af24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AE50u; }
            if (ctx->pc != 0x15AE50u) { return; }
        }
        }
    }
    ctx->pc = 0x15AE50u;
label_15ae50:
    // 0x15ae50: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15ae50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15ae54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15ae54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae58: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15ae58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15ae5c: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x15ae5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15ae60: 0x40f809  jalr        $v0
    ctx->pc = 0x15AE60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AE68u);
        ctx->pc = 0x15AE64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE60u;
            // 0x15ae64: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AE68u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AE10u: goto label_15ae10;
            case 0x15AE18u: goto label_15ae18;
            case 0x15AE38u: goto label_15ae38;
            case 0x15AE50u: goto label_15ae50;
            case 0x15AE68u: goto label_15ae68;
            case 0x15AE70u: goto label_15ae70;
            case 0x15AE78u: goto label_15ae78;
            case 0x15AE94u: goto label_15ae94;
            case 0x15AEACu: goto label_15aeac;
            case 0x15AEC4u: goto label_15aec4;
            case 0x15AED0u: goto label_15aed0;
            case 0x15AED4u: goto label_15aed4;
            case 0x15AEF0u: goto label_15aef0;
            case 0x15AF20u: goto label_15af20;
            case 0x15AF24u: goto label_15af24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AE68u; }
            if (ctx->pc != 0x15AE68u) { return; }
        }
        }
    }
    ctx->pc = 0x15AE68u;
label_15ae68:
    // 0x15ae68: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x15AE68u;
    {
        const bool branch_taken_0x15ae68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AE6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE68u;
            // 0x15ae6c: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15ae68) {
            ctx->pc = 0x15AED4u;
            goto label_15aed4;
        }
    }
    ctx->pc = 0x15AE70u;
label_15ae70:
    // 0x15ae70: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x15AE70u;
    SET_GPR_U32(ctx, 31, 0x15AE78u);
    ctx->pc = 0x15AE74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE70u;
            // 0x15ae74: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE78u; }
        if (ctx->pc != 0x15AE78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE78u; }
        if (ctx->pc != 0x15AE78u) { return; }
    }
    ctx->pc = 0x15AE78u;
label_15ae78:
    // 0x15ae78: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x15ae78u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae7c: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x15ae7cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ae80: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x15ae80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae84: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x15ae84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae88: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x15ae88u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae8c: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x15AE8Cu;
    SET_GPR_U32(ctx, 31, 0x15AE94u);
    ctx->pc = 0x15AE90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15AE8Cu;
            // 0x15ae90: 0x2252823  subu        $a1, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE94u; }
        if (ctx->pc != 0x15AE94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15AE94u; }
        if (ctx->pc != 0x15AE94u) { return; }
    }
    ctx->pc = 0x15AE94u;
label_15ae94:
    // 0x15ae94: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15ae94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15ae98: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15ae98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ae9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15ae9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aea0: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15aea0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15aea4: 0x40f809  jalr        $v0
    ctx->pc = 0x15AEA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AEACu);
        ctx->pc = 0x15AEA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AEA4u;
            // 0x15aea8: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AEACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AE10u: goto label_15ae10;
            case 0x15AE18u: goto label_15ae18;
            case 0x15AE38u: goto label_15ae38;
            case 0x15AE50u: goto label_15ae50;
            case 0x15AE68u: goto label_15ae68;
            case 0x15AE70u: goto label_15ae70;
            case 0x15AE78u: goto label_15ae78;
            case 0x15AE94u: goto label_15ae94;
            case 0x15AEACu: goto label_15aeac;
            case 0x15AEC4u: goto label_15aec4;
            case 0x15AED0u: goto label_15aed0;
            case 0x15AED4u: goto label_15aed4;
            case 0x15AEF0u: goto label_15aef0;
            case 0x15AF20u: goto label_15af20;
            case 0x15AF24u: goto label_15af24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AEACu; }
            if (ctx->pc != 0x15AEACu) { return; }
        }
        }
    }
    ctx->pc = 0x15AEACu;
label_15aeac:
    // 0x15aeac: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15aeacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15aeb0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15aeb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aeb4: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x15aeb4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aeb8: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x15aeb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15aebc: 0x40f809  jalr        $v0
    ctx->pc = 0x15AEBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AEC4u);
        ctx->pc = 0x15AEC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AEBCu;
            // 0x15aec0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AEC4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AE10u: goto label_15ae10;
            case 0x15AE18u: goto label_15ae18;
            case 0x15AE38u: goto label_15ae38;
            case 0x15AE50u: goto label_15ae50;
            case 0x15AE68u: goto label_15ae68;
            case 0x15AE70u: goto label_15ae70;
            case 0x15AE78u: goto label_15ae78;
            case 0x15AE94u: goto label_15ae94;
            case 0x15AEACu: goto label_15aeac;
            case 0x15AEC4u: goto label_15aec4;
            case 0x15AED0u: goto label_15aed0;
            case 0x15AED4u: goto label_15aed4;
            case 0x15AEF0u: goto label_15aef0;
            case 0x15AF20u: goto label_15af20;
            case 0x15AF24u: goto label_15af24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AEC4u; }
            if (ctx->pc != 0x15AEC4u) { return; }
        }
        }
    }
    ctx->pc = 0x15AEC4u;
label_15aec4:
    // 0x15aec4: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x15AEC4u;
    {
        const bool branch_taken_0x15aec4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AEC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AEC4u;
            // 0x15aec8: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15aec4) {
            ctx->pc = 0x15AF24u;
            goto label_15af24;
        }
    }
    ctx->pc = 0x15AECCu;
    // 0x15aecc: 0x0  nop
    ctx->pc = 0x15aeccu;
    // NOP
label_15aed0:
    // 0x15aed0: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15aed0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_15aed4:
    // 0x15aed4: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x15aed4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x15aed8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15aed8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15aedc: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x15aedcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x15aee0: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x15aee0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15aee4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15aee4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aee8: 0x40f809  jalr        $v0
    ctx->pc = 0x15AEE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AEF0u);
        ctx->pc = 0x15AEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AEE8u;
            // 0x15aeec: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AEF0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AE10u: goto label_15ae10;
            case 0x15AE18u: goto label_15ae18;
            case 0x15AE38u: goto label_15ae38;
            case 0x15AE50u: goto label_15ae50;
            case 0x15AE68u: goto label_15ae68;
            case 0x15AE70u: goto label_15ae70;
            case 0x15AE78u: goto label_15ae78;
            case 0x15AE94u: goto label_15ae94;
            case 0x15AEACu: goto label_15aeac;
            case 0x15AEC4u: goto label_15aec4;
            case 0x15AED0u: goto label_15aed0;
            case 0x15AED4u: goto label_15aed4;
            case 0x15AEF0u: goto label_15aef0;
            case 0x15AF20u: goto label_15af20;
            case 0x15AF24u: goto label_15af24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AEF0u; }
            if (ctx->pc != 0x15AEF0u) { return; }
        }
        }
    }
    ctx->pc = 0x15AEF0u;
label_15aef0:
    // 0x15aef0: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x15aef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15aef4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x15aef4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15aef8: 0x28420004  slti        $v0, $v0, 0x4
    ctx->pc = 0x15aef8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x15aefc: 0x1040ffc4  beqz        $v0, . + 4 + (-0x3C << 2)
    ctx->pc = 0x15AEFCu;
    {
        const bool branch_taken_0x15aefc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15AF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AEFCu;
            // 0x15af00: 0x2406ffff  addiu       $a2, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15aefc) {
            ctx->pc = 0x15AE10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15ae10;
        }
    }
    ctx->pc = 0x15AF04u;
    // 0x15af04: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15af04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15af08: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15af08u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15af0c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15af0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15af10: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x15af10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15af14: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x15af14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15af18: 0x40f809  jalr        $v0
    ctx->pc = 0x15AF18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15AF20u);
        ctx->pc = 0x15AF1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AF18u;
            // 0x15af1c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15AF20u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AE10u: goto label_15ae10;
            case 0x15AE18u: goto label_15ae18;
            case 0x15AE38u: goto label_15ae38;
            case 0x15AE50u: goto label_15ae50;
            case 0x15AE68u: goto label_15ae68;
            case 0x15AE70u: goto label_15ae70;
            case 0x15AE78u: goto label_15ae78;
            case 0x15AE94u: goto label_15ae94;
            case 0x15AEACu: goto label_15aeac;
            case 0x15AEC4u: goto label_15aec4;
            case 0x15AED0u: goto label_15aed0;
            case 0x15AED4u: goto label_15aed4;
            case 0x15AEF0u: goto label_15aef0;
            case 0x15AF20u: goto label_15af20;
            case 0x15AF24u: goto label_15af24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15AF20u; }
            if (ctx->pc != 0x15AF20u) { return; }
        }
        }
    }
    ctx->pc = 0x15AF20u;
label_15af20:
    // 0x15af20: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x15af20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_15af24:
    // 0x15af24: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x15af24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15af28: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x15af28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15af2c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x15af2cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15af30: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x15af30u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15af34: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x15af34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15af38: 0x3e00008  jr          $ra
    ctx->pc = 0x15AF38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15AF3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15AF38u;
            // 0x15af3c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15AE10u: goto label_15ae10;
            case 0x15AE18u: goto label_15ae18;
            case 0x15AE38u: goto label_15ae38;
            case 0x15AE50u: goto label_15ae50;
            case 0x15AE68u: goto label_15ae68;
            case 0x15AE70u: goto label_15ae70;
            case 0x15AE78u: goto label_15ae78;
            case 0x15AE94u: goto label_15ae94;
            case 0x15AEACu: goto label_15aeac;
            case 0x15AEC4u: goto label_15aec4;
            case 0x15AED0u: goto label_15aed0;
            case 0x15AED4u: goto label_15aed4;
            case 0x15AEF0u: goto label_15aef0;
            case 0x15AF20u: goto label_15af20;
            case 0x15AF24u: goto label_15af24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15AF40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

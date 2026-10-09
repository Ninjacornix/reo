#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164038
// Address: 0x164038 - 0x1640d8
void sub_00164038_0x164038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164038_0x164038");
#endif

    switch (ctx->pc) {
        case 0x164064u: goto label_164064;
        case 0x164070u: goto label_164070;
        case 0x164080u: goto label_164080;
        case 0x164088u: goto label_164088;
        case 0x164098u: goto label_164098;
        case 0x1640acu: goto label_1640ac;
        case 0x1640b4u: goto label_1640b4;
        case 0x1640bcu: goto label_1640bc;
        default: break;
    }

    ctx->pc = 0x164038u;

    // 0x164038: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x164038u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x16403c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16403cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x164040: 0x8c43de54  lw          $v1, -0x21AC($v0)
    ctx->pc = 0x164040u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294958676)));
    // 0x164044: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x164044u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164048: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x164048u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16404c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16404cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164050: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x164050u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x164054: 0x1464001b  bne         $v1, $a0, . + 4 + (0x1B << 2)
    ctx->pc = 0x164054u;
    {
        const bool branch_taken_0x164054 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x164058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164054u;
            // 0x164058: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164054) {
            ctx->pc = 0x1640C4u;
            goto label_1640c4;
        }
    }
    ctx->pc = 0x16405Cu;
    // 0x16405c: 0xc05799e  jal         func_15E678
    ctx->pc = 0x16405Cu;
    SET_GPR_U32(ctx, 31, 0x164064u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164064u; }
        if (ctx->pc != 0x164064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164064u; }
        if (ctx->pc != 0x164064u) { return; }
    }
    ctx->pc = 0x164064u;
label_164064:
    // 0x164064: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x164064u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164068: 0xc058dce  jal         func_163738
    ctx->pc = 0x164068u;
    SET_GPR_U32(ctx, 31, 0x164070u);
    ctx->pc = 0x16406Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164068u;
            // 0x16406c: 0x26040054  addiu       $a0, $s0, 0x54 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 84));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163738u;
    if (runtime->hasFunction(0x163738u)) {
        auto targetFn = runtime->lookupFunction(0x163738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164070u; }
        if (ctx->pc != 0x164070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163738_0x163738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164070u; }
        if (ctx->pc != 0x164070u) { return; }
    }
    ctx->pc = 0x164070u;
label_164070:
    // 0x164070: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x164070u;
    {
        const bool branch_taken_0x164070 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x164070) {
            ctx->pc = 0x164074u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164070u;
            // 0x164074: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1640C8u;
            goto label_1640c8;
        }
    }
    ctx->pc = 0x164078u;
    // 0x164078: 0xc058ff6  jal         func_163FD8
    ctx->pc = 0x164078u;
    SET_GPR_U32(ctx, 31, 0x164080u);
    ctx->pc = 0x16407Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164078u;
            // 0x16407c: 0x26100068  addiu       $s0, $s0, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163FD8u;
    if (runtime->hasFunction(0x163FD8u)) {
        auto targetFn = runtime->lookupFunction(0x163FD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164080u; }
        if (ctx->pc != 0x164080u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163FD8_0x163fd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164080u; }
        if (ctx->pc != 0x164080u) { return; }
    }
    ctx->pc = 0x164080u;
label_164080:
    // 0x164080: 0x24110007  addiu       $s1, $zero, 0x7
    ctx->pc = 0x164080u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x164084: 0x0  nop
    ctx->pc = 0x164084u;
    // NOP
label_164088:
    // 0x164088: 0x52000004  beql        $s0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x164088u;
    {
        const bool branch_taken_0x164088 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x164088) {
            ctx->pc = 0x16408Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164088u;
            // 0x16408c: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16409Cu;
            goto label_16409c;
        }
    }
    ctx->pc = 0x164090u;
    // 0x164090: 0xc059036  jal         func_1640D8
    ctx->pc = 0x164090u;
    SET_GPR_U32(ctx, 31, 0x164098u);
    ctx->pc = 0x164094u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164090u;
            // 0x164094: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1640D8u;
    if (runtime->hasFunction(0x1640D8u)) {
        auto targetFn = runtime->lookupFunction(0x1640D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164098u; }
        if (ctx->pc != 0x164098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001640D8_0x1640d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164098u; }
        if (ctx->pc != 0x164098u) { return; }
    }
    ctx->pc = 0x164098u;
label_164098:
    // 0x164098: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x164098u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_16409c:
    // 0x16409c: 0x621fffa  bgez        $s1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x16409Cu;
    {
        const bool branch_taken_0x16409c = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x1640A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16409Cu;
            // 0x1640a0: 0x26100210  addiu       $s0, $s0, 0x210 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 528));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16409c) {
            ctx->pc = 0x164088u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_164088;
        }
    }
    ctx->pc = 0x1640A4u;
    // 0x1640a4: 0xc05909c  jal         func_164270
    ctx->pc = 0x1640A4u;
    SET_GPR_U32(ctx, 31, 0x1640ACu);
    ctx->pc = 0x1640A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1640A4u;
            // 0x1640a8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164270u;
    if (runtime->hasFunction(0x164270u)) {
        auto targetFn = runtime->lookupFunction(0x164270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1640ACu; }
        if (ctx->pc != 0x1640ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164270_0x164270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1640ACu; }
        if (ctx->pc != 0x1640ACu) { return; }
    }
    ctx->pc = 0x1640ACu;
label_1640ac:
    // 0x1640ac: 0xc05c932  jal         func_1724C8
    ctx->pc = 0x1640ACu;
    SET_GPR_U32(ctx, 31, 0x1640B4u);
    ctx->pc = 0x1724C8u;
    if (runtime->hasFunction(0x1724C8u)) {
        auto targetFn = runtime->lookupFunction(0x1724C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1640B4u; }
        if (ctx->pc != 0x1640B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001724C8_0x1724c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1640B4u; }
        if (ctx->pc != 0x1640B4u) { return; }
    }
    ctx->pc = 0x1640B4u;
label_1640b4:
    // 0x1640b4: 0xc059002  jal         func_164008
    ctx->pc = 0x1640B4u;
    SET_GPR_U32(ctx, 31, 0x1640BCu);
    ctx->pc = 0x1640B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1640B4u;
            // 0x1640b8: 0x38500001  xori        $s0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x164008u;
    if (runtime->hasFunction(0x164008u)) {
        auto targetFn = runtime->lookupFunction(0x164008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1640BCu; }
        if (ctx->pc != 0x1640BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164008_0x164008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1640BCu; }
        if (ctx->pc != 0x1640BCu) { return; }
    }
    ctx->pc = 0x1640BCu;
label_1640bc:
    // 0x1640bc: 0x10802b  sltu        $s0, $zero, $s0
    ctx->pc = 0x1640bcu;
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1640c0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1640c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1640c4:
    // 0x1640c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1640c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1640c8:
    // 0x1640c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1640c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1640cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1640ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1640d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1640D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1640D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1640D0u;
            // 0x1640d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164064u: goto label_164064;
            case 0x164070u: goto label_164070;
            case 0x164080u: goto label_164080;
            case 0x164088u: goto label_164088;
            case 0x164098u: goto label_164098;
            case 0x16409Cu: goto label_16409c;
            case 0x1640ACu: goto label_1640ac;
            case 0x1640B4u: goto label_1640b4;
            case 0x1640BCu: goto label_1640bc;
            case 0x1640C4u: goto label_1640c4;
            case 0x1640C8u: goto label_1640c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1640D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B05B0
// Address: 0x1b05b0 - 0x1b06a0
void sub_001B05B0_0x1b05b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B05B0_0x1b05b0");
#endif

    switch (ctx->pc) {
        case 0x1b05c0u: goto label_1b05c0;
        case 0x1b05d8u: goto label_1b05d8;
        case 0x1b05e4u: goto label_1b05e4;
        case 0x1b05f0u: goto label_1b05f0;
        case 0x1b05fcu: goto label_1b05fc;
        case 0x1b0608u: goto label_1b0608;
        case 0x1b0614u: goto label_1b0614;
        case 0x1b064cu: goto label_1b064c;
        case 0x1b0688u: goto label_1b0688;
        default: break;
    }

    ctx->pc = 0x1b05b0u;

    // 0x1b05b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b05b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b05b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b05b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b05b8: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1B05B8u;
    SET_GPR_U32(ctx, 31, 0x1B05C0u);
    ctx->pc = 0x1B05BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05B8u;
            // 0x1b05bc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05C0u; }
        if (ctx->pc != 0x1B05C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05C0u; }
        if (ctx->pc != 0x1B05C0u) { return; }
    }
    ctx->pc = 0x1B05C0u;
label_1b05c0:
    // 0x1b05c0: 0xafa2001c  sw          $v0, 0x1C($sp)
    ctx->pc = 0x1b05c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
    // 0x1b05c4: 0x8fa3001c  lw          $v1, 0x1C($sp)
    ctx->pc = 0x1b05c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1b05c8: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B05C8u;
    {
        const bool branch_taken_0x1b05c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B05CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05C8u;
            // 0x1b05cc: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b05c8) {
            ctx->pc = 0x1B0614u;
            goto label_1b0614;
        }
    }
    ctx->pc = 0x1B05D0u;
    // 0x1b05d0: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1B05D0u;
    SET_GPR_U32(ctx, 31, 0x1B05D8u);
    ctx->pc = 0x1B05D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05D0u;
            // 0x1b05d4: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05D8u; }
        if (ctx->pc != 0x1B05D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05D8u; }
        if (ctx->pc != 0x1B05D8u) { return; }
    }
    ctx->pc = 0x1B05D8u;
label_1b05d8:
    // 0x1b05d8: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x1b05d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1b05dc: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B05DCu;
    SET_GPR_U32(ctx, 31, 0x1B05E4u);
    ctx->pc = 0x1B05E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05DCu;
            // 0x1b05e0: 0x3c050001  lui         $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05E4u; }
        if (ctx->pc != 0x1B05E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05E4u; }
        if (ctx->pc != 0x1B05E4u) { return; }
    }
    ctx->pc = 0x1B05E4u;
label_1b05e4:
    // 0x1b05e4: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1b05e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1b05e8: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B05E8u;
    SET_GPR_U32(ctx, 31, 0x1B05F0u);
    ctx->pc = 0x1B05ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05E8u;
            // 0x1b05ec: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05F0u; }
        if (ctx->pc != 0x1B05F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05F0u; }
        if (ctx->pc != 0x1B05F0u) { return; }
    }
    ctx->pc = 0x1B05F0u;
label_1b05f0:
    // 0x1b05f0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b05f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b05f4: 0xc0675c8  jal         func_19D720
    ctx->pc = 0x1B05F4u;
    SET_GPR_U32(ctx, 31, 0x1B05FCu);
    ctx->pc = 0x1B05F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05F4u;
            // 0x1b05f8: 0x27a5001c  addiu       $a1, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19D720u;
    if (runtime->hasFunction(0x19D720u)) {
        auto targetFn = runtime->lookupFunction(0x19D720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05FCu; }
        if (ctx->pc != 0x1B05FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D720_0x19d720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B05FCu; }
        if (ctx->pc != 0x1B05FCu) { return; }
    }
    ctx->pc = 0x1B05FCu;
label_1b05fc:
    // 0x1b05fc: 0x8fa5001c  lw          $a1, 0x1C($sp)
    ctx->pc = 0x1b05fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1b0600: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B0600u;
    SET_GPR_U32(ctx, 31, 0x1B0608u);
    ctx->pc = 0x1B0604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0600u;
            // 0x1b0604: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0608u; }
        if (ctx->pc != 0x1B0608u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0608u; }
        if (ctx->pc != 0x1B0608u) { return; }
    }
    ctx->pc = 0x1B0608u;
label_1b0608:
    // 0x1b0608: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1b0608u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1b060c: 0xc06ae18  jal         func_1AB860
    ctx->pc = 0x1B060Cu;
    SET_GPR_U32(ctx, 31, 0x1B0614u);
    ctx->pc = 0x1B0610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B060Cu;
            // 0x1b0610: 0x248443a0  addiu       $a0, $a0, 0x43A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17312));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB860u;
    if (runtime->hasFunction(0x1AB860u)) {
        auto targetFn = runtime->lookupFunction(0x1AB860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0614u; }
        if (ctx->pc != 0x1B0614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB860_0x1ab860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0614u; }
        if (ctx->pc != 0x1B0614u) { return; }
    }
    ctx->pc = 0x1B0614u;
label_1b0614:
    // 0x1b0614: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b0614u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0618: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B061Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0618u;
            // 0x1b061c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B05C0u: goto label_1b05c0;
            case 0x1B05D8u: goto label_1b05d8;
            case 0x1B05E4u: goto label_1b05e4;
            case 0x1B05F0u: goto label_1b05f0;
            case 0x1B05FCu: goto label_1b05fc;
            case 0x1B0608u: goto label_1b0608;
            case 0x1B0614u: goto label_1b0614;
            case 0x1B064Cu: goto label_1b064c;
            case 0x1B0688u: goto label_1b0688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0620u;
    // 0x1b0620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0624: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b0624u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0628: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b062c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b062cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0630: 0xac248df8  sw          $a0, -0x7208($at)
    ctx->pc = 0x1b0630u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938104), GPR_U32(ctx, 4));
    // 0x1b0634: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b0634u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0638: 0x8c238df0  lw          $v1, -0x7210($at)
    ctx->pc = 0x1b0638u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938096)));
    // 0x1b063c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B063Cu;
    {
        const bool branch_taken_0x1b063c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B0640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B063Cu;
            // 0x1b0640: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b063c) {
            ctx->pc = 0x1B064Cu;
            goto label_1b064c;
        }
    }
    ctx->pc = 0x1B0644u;
    // 0x1b0644: 0xc072e30  jal         func_1CB8C0
    ctx->pc = 0x1B0644u;
    SET_GPR_U32(ctx, 31, 0x1B064Cu);
    ctx->pc = 0x1B0648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0644u;
            // 0x1b0648: 0xac248df0  sw          $a0, -0x7210($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294938096), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB8C0u;
    if (runtime->hasFunction(0x1CB8C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CB8C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B064Cu; }
        if (ctx->pc != 0x1B064Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB8C0_0x1cb8c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B064Cu; }
        if (ctx->pc != 0x1B064Cu) { return; }
    }
    ctx->pc = 0x1B064Cu;
label_1b064c:
    // 0x1b064c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b064cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0650: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0650u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0650u;
            // 0x1b0654: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B05C0u: goto label_1b05c0;
            case 0x1B05D8u: goto label_1b05d8;
            case 0x1B05E4u: goto label_1b05e4;
            case 0x1B05F0u: goto label_1b05f0;
            case 0x1B05FCu: goto label_1b05fc;
            case 0x1B0608u: goto label_1b0608;
            case 0x1B0614u: goto label_1b0614;
            case 0x1B064Cu: goto label_1b064c;
            case 0x1B0688u: goto label_1b0688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0658u;
    // 0x1b0658: 0x0  nop
    ctx->pc = 0x1b0658u;
    // NOP
    // 0x1b065c: 0x0  nop
    ctx->pc = 0x1b065cu;
    // NOP
    // 0x1b0660: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0664: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b0664u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0668: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b066c: 0xac208df8  sw          $zero, -0x7208($at)
    ctx->pc = 0x1b066cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938104), GPR_U32(ctx, 0));
    // 0x1b0670: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b0670u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b0674: 0x8c238df0  lw          $v1, -0x7210($at)
    ctx->pc = 0x1b0674u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938096)));
    // 0x1b0678: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0678u;
    {
        const bool branch_taken_0x1b0678 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B067Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0678u;
            // 0x1b067c: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0678) {
            ctx->pc = 0x1B0688u;
            goto label_1b0688;
        }
    }
    ctx->pc = 0x1B0680u;
    // 0x1b0680: 0xc072e3c  jal         func_1CB8F0
    ctx->pc = 0x1B0680u;
    SET_GPR_U32(ctx, 31, 0x1B0688u);
    ctx->pc = 0x1B0684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0680u;
            // 0x1b0684: 0xac208df0  sw          $zero, -0x7210($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294938096), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB8F0u;
    if (runtime->hasFunction(0x1CB8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CB8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0688u; }
        if (ctx->pc != 0x1B0688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB8F0_0x1cb8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0688u; }
        if (ctx->pc != 0x1B0688u) { return; }
    }
    ctx->pc = 0x1B0688u;
label_1b0688:
    // 0x1b0688: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b0688u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b068c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B068Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B068Cu;
            // 0x1b0690: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B05C0u: goto label_1b05c0;
            case 0x1B05D8u: goto label_1b05d8;
            case 0x1B05E4u: goto label_1b05e4;
            case 0x1B05F0u: goto label_1b05f0;
            case 0x1B05FCu: goto label_1b05fc;
            case 0x1B0608u: goto label_1b0608;
            case 0x1B0614u: goto label_1b0614;
            case 0x1B064Cu: goto label_1b064c;
            case 0x1B0688u: goto label_1b0688;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0694u;
    // 0x1b0694: 0x0  nop
    ctx->pc = 0x1b0694u;
    // NOP
    // 0x1b0698: 0x0  nop
    ctx->pc = 0x1b0698u;
    // NOP
    // 0x1b069c: 0x0  nop
    ctx->pc = 0x1b069cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

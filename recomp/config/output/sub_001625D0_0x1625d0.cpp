#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001625D0
// Address: 0x1625d0 - 0x16265c
void sub_001625D0_0x1625d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001625D0_0x1625d0");
#endif

    switch (ctx->pc) {
        case 0x1625e4u: goto label_1625e4;
        case 0x162610u: goto label_162610;
        case 0x16261cu: goto label_16261c;
        case 0x162624u: goto label_162624;
        case 0x16262cu: goto label_16262c;
        case 0x162648u: goto label_162648;
        default: break;
    }

    ctx->pc = 0x1625d0u;

    // 0x1625d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1625d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1625d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1625d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1625d8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1625d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1625dc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1625DCu;
    SET_GPR_U32(ctx, 31, 0x1625E4u);
    ctx->pc = 0x1625E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1625DCu;
            // 0x1625e0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1625E4u; }
        if (ctx->pc != 0x1625E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1625E4u; }
        if (ctx->pc != 0x1625E4u) { return; }
    }
    ctx->pc = 0x1625E4u;
label_1625e4:
    // 0x1625e4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1625e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1625e8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1625E8u;
    {
        const bool branch_taken_0x1625e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1625ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1625E8u;
            // 0x1625ec: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1625e8) {
            ctx->pc = 0x162608u;
            goto label_162608;
        }
    }
    ctx->pc = 0x1625F0u;
    // 0x1625f0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1625f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1625f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1625f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1625f8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1625f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1625fc: 0x24840198  addiu       $a0, $a0, 0x198
    ctx->pc = 0x1625fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 408));
    // 0x162600: 0x8058dd4  j           func_163750
    ctx->pc = 0x162600u;
    ctx->pc = 0x162604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162600u;
            // 0x162604: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162608u;
label_162608:
    // 0x162608: 0xc058abe  jal         func_162AF8
    ctx->pc = 0x162608u;
    SET_GPR_U32(ctx, 31, 0x162610u);
    ctx->pc = 0x162AF8u;
    if (runtime->hasFunction(0x162AF8u)) {
        auto targetFn = runtime->lookupFunction(0x162AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162610u; }
        if (ctx->pc != 0x162610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162AF8_0x162af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162610u; }
        if (ctx->pc != 0x162610u) { return; }
    }
    ctx->pc = 0x162610u;
label_162610:
    // 0x162610: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162610u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162614: 0xc057c9c  jal         func_15F270
    ctx->pc = 0x162614u;
    SET_GPR_U32(ctx, 31, 0x16261Cu);
    ctx->pc = 0x162618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162614u;
            // 0x162618: 0x8e05012c  lw          $a1, 0x12C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F270u;
    if (runtime->hasFunction(0x15F270u)) {
        auto targetFn = runtime->lookupFunction(0x15F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16261Cu; }
        if (ctx->pc != 0x16261Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F270_0x15f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16261Cu; }
        if (ctx->pc != 0x16261Cu) { return; }
    }
    ctx->pc = 0x16261Cu;
label_16261c:
    // 0x16261c: 0xc057d6c  jal         func_15F5B0
    ctx->pc = 0x16261Cu;
    SET_GPR_U32(ctx, 31, 0x162624u);
    ctx->pc = 0x162620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16261Cu;
            // 0x162620: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F5B0u;
    if (runtime->hasFunction(0x15F5B0u)) {
        auto targetFn = runtime->lookupFunction(0x15F5B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162624u; }
        if (ctx->pc != 0x162624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F5B0_0x15f5b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162624u; }
        if (ctx->pc != 0x162624u) { return; }
    }
    ctx->pc = 0x162624u;
label_162624:
    // 0x162624: 0xc04f3c4  jal         func_13CF10
    ctx->pc = 0x162624u;
    SET_GPR_U32(ctx, 31, 0x16262Cu);
    ctx->pc = 0x162628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162624u;
            // 0x162628: 0x8e04004c  lw          $a0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF10u;
    if (runtime->hasFunction(0x13CF10u)) {
        auto targetFn = runtime->lookupFunction(0x13CF10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16262Cu; }
        if (ctx->pc != 0x16262Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF10_0x13cf10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16262Cu; }
        if (ctx->pc != 0x16262Cu) { return; }
    }
    ctx->pc = 0x16262Cu;
label_16262c:
    // 0x16262c: 0x8e020128  lw          $v0, 0x128($s0)
    ctx->pc = 0x16262cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x162630: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x162630u;
    {
        const bool branch_taken_0x162630 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162630u;
            // 0x162634: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162630) {
            ctx->pc = 0x162648u;
            goto label_162648;
        }
    }
    ctx->pc = 0x162638u;
    // 0x162638: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x162638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x16263c: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x16263cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x162640: 0x60f809  jalr        $v1
    ctx->pc = 0x162640u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x162648u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x162648u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1625E4u: goto label_1625e4;
            case 0x162608u: goto label_162608;
            case 0x162610u: goto label_162610;
            case 0x16261Cu: goto label_16261c;
            case 0x162624u: goto label_162624;
            case 0x16262Cu: goto label_16262c;
            case 0x162648u: goto label_162648;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x162648u; }
            if (ctx->pc != 0x162648u) { return; }
        }
        }
    }
    ctx->pc = 0x162648u;
label_162648:
    // 0x162648: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162648u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16264c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16264cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162650: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162650u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162654: 0x8056fea  j           func_15BFA8
    ctx->pc = 0x162654u;
    ctx->pc = 0x162658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162654u;
            // 0x162658: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BFA8u;
    if (runtime->hasFunction(0x15BFA8u)) {
        auto targetFn = runtime->lookupFunction(0x15BFA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015BFA8_0x15bfa8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16265Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

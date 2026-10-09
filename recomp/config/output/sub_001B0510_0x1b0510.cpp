#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0510
// Address: 0x1b0510 - 0x1b05b0
void sub_001B0510_0x1b0510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0510_0x1b0510");
#endif

    switch (ctx->pc) {
        case 0x1b0524u: goto label_1b0524;
        case 0x1b053cu: goto label_1b053c;
        case 0x1b0540u: goto label_1b0540;
        case 0x1b0548u: goto label_1b0548;
        case 0x1b0554u: goto label_1b0554;
        case 0x1b0560u: goto label_1b0560;
        case 0x1b056cu: goto label_1b056c;
        case 0x1b0578u: goto label_1b0578;
        case 0x1b0584u: goto label_1b0584;
        case 0x1b0590u: goto label_1b0590;
        default: break;
    }

    ctx->pc = 0x1b0510u;

    // 0x1b0510: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b0510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b0514: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b0514u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0518: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b051c: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1B051Cu;
    SET_GPR_U32(ctx, 31, 0x1B0524u);
    ctx->pc = 0x1B0520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B051Cu;
            // 0x1b0520: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0524u; }
        if (ctx->pc != 0x1B0524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0524u; }
        if (ctx->pc != 0x1B0524u) { return; }
    }
    ctx->pc = 0x1B0524u;
label_1b0524:
    // 0x1b0524: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1b0524u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1b0528: 0x8fa3002c  lw          $v1, 0x2C($sp)
    ctx->pc = 0x1b0528u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1b052c: 0x1060001c  beqz        $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1B052Cu;
    {
        const bool branch_taken_0x1b052c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b052c) {
            ctx->pc = 0x1B05A0u;
            goto label_1b05a0;
        }
    }
    ctx->pc = 0x1B0534u;
    // 0x1b0534: 0xc063594  jal         func_18D650
    ctx->pc = 0x1B0534u;
    SET_GPR_U32(ctx, 31, 0x1B053Cu);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B053Cu; }
        if (ctx->pc != 0x1B053Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B053Cu; }
        if (ctx->pc != 0x1B053Cu) { return; }
    }
    ctx->pc = 0x1B053Cu;
label_1b053c:
    // 0x1b053c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b053cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b0540:
    // 0x1b0540: 0xc06eabc  jal         func_1BAAF0
    ctx->pc = 0x1B0540u;
    SET_GPR_U32(ctx, 31, 0x1B0548u);
    ctx->pc = 0x1B0544u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0540u;
            // 0x1b0544: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BAAF0u;
    if (runtime->hasFunction(0x1BAAF0u)) {
        auto targetFn = runtime->lookupFunction(0x1BAAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0548u; }
        if (ctx->pc != 0x1B0548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAAF0_0x1baaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0548u; }
        if (ctx->pc != 0x1B0548u) { return; }
    }
    ctx->pc = 0x1B0548u;
label_1b0548:
    // 0x1b0548: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1b0548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b054c: 0xc06bc78  jal         func_1AF1E0
    ctx->pc = 0x1B054Cu;
    SET_GPR_U32(ctx, 31, 0x1B0554u);
    ctx->pc = 0x1B0550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B054Cu;
            // 0x1b0550: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF1E0u;
    if (runtime->hasFunction(0x1AF1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0554u; }
        if (ctx->pc != 0x1B0554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF1E0_0x1af1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0554u; }
        if (ctx->pc != 0x1B0554u) { return; }
    }
    ctx->pc = 0x1B0554u;
label_1b0554:
    // 0x1b0554: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x1b0554u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1b0558: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B0558u;
    SET_GPR_U32(ctx, 31, 0x1B0560u);
    ctx->pc = 0x1B055Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0558u;
            // 0x1b055c: 0x3c050001  lui         $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0560u; }
        if (ctx->pc != 0x1B0560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0560u; }
        if (ctx->pc != 0x1B0560u) { return; }
    }
    ctx->pc = 0x1B0560u;
label_1b0560:
    // 0x1b0560: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x1b0560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1b0564: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B0564u;
    SET_GPR_U32(ctx, 31, 0x1B056Cu);
    ctx->pc = 0x1B0568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0564u;
            // 0x1b0568: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B056Cu; }
        if (ctx->pc != 0x1B056Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B056Cu; }
        if (ctx->pc != 0x1B056Cu) { return; }
    }
    ctx->pc = 0x1B056Cu;
label_1b056c:
    // 0x1b056c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b056cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0570: 0xc0675c8  jal         func_19D720
    ctx->pc = 0x1B0570u;
    SET_GPR_U32(ctx, 31, 0x1B0578u);
    ctx->pc = 0x1B0574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0570u;
            // 0x1b0574: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19D720u;
    if (runtime->hasFunction(0x19D720u)) {
        auto targetFn = runtime->lookupFunction(0x19D720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0578u; }
        if (ctx->pc != 0x1B0578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D720_0x19d720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0578u; }
        if (ctx->pc != 0x1B0578u) { return; }
    }
    ctx->pc = 0x1B0578u;
label_1b0578:
    // 0x1b0578: 0x8fa5002c  lw          $a1, 0x2C($sp)
    ctx->pc = 0x1b0578u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1b057c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1B057Cu;
    SET_GPR_U32(ctx, 31, 0x1B0584u);
    ctx->pc = 0x1B0580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B057Cu;
            // 0x1b0580: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0584u; }
        if (ctx->pc != 0x1B0584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0584u; }
        if (ctx->pc != 0x1B0584u) { return; }
    }
    ctx->pc = 0x1B0584u;
label_1b0584:
    // 0x1b0584: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1b0584u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1b0588: 0xc06ae18  jal         func_1AB860
    ctx->pc = 0x1B0588u;
    SET_GPR_U32(ctx, 31, 0x1B0590u);
    ctx->pc = 0x1B058Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0588u;
            // 0x1b058c: 0x24844380  addiu       $a0, $a0, 0x4380 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB860u;
    if (runtime->hasFunction(0x1AB860u)) {
        auto targetFn = runtime->lookupFunction(0x1AB860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0590u; }
        if (ctx->pc != 0x1B0590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB860_0x1ab860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0590u; }
        if (ctx->pc != 0x1B0590u) { return; }
    }
    ctx->pc = 0x1B0590u;
label_1b0590:
    // 0x1b0590: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b0590u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b0594: 0x2a030003  slti        $v1, $s0, 0x3
    ctx->pc = 0x1b0594u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1b0598: 0x1460ffe9  bnez        $v1, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1B0598u;
    {
        const bool branch_taken_0x1b0598 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b0598) {
            ctx->pc = 0x1B0540u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0540;
        }
    }
    ctx->pc = 0x1B05A0u;
label_1b05a0:
    // 0x1b05a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b05a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b05a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b05a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b05a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B05A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B05ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B05A8u;
            // 0x1b05ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0524u: goto label_1b0524;
            case 0x1B053Cu: goto label_1b053c;
            case 0x1B0540u: goto label_1b0540;
            case 0x1B0548u: goto label_1b0548;
            case 0x1B0554u: goto label_1b0554;
            case 0x1B0560u: goto label_1b0560;
            case 0x1B056Cu: goto label_1b056c;
            case 0x1B0578u: goto label_1b0578;
            case 0x1B0584u: goto label_1b0584;
            case 0x1B0590u: goto label_1b0590;
            case 0x1B05A0u: goto label_1b05a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B05B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9500
// Address: 0x1a9500 - 0x1a95a0
void sub_001A9500_0x1a9500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9500_0x1a9500");
#endif

    switch (ctx->pc) {
        case 0x1a9524u: goto label_1a9524;
        case 0x1a9530u: goto label_1a9530;
        case 0x1a9548u: goto label_1a9548;
        case 0x1a9558u: goto label_1a9558;
        case 0x1a9560u: goto label_1a9560;
        case 0x1a957cu: goto label_1a957c;
        default: break;
    }

    ctx->pc = 0x1a9500u;

    // 0x1a9500: 0x27bdf7d0  addiu       $sp, $sp, -0x830
    ctx->pc = 0x1a9500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294965200));
    // 0x1a9504: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1a9504u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9508: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a9508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a950c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1a950cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1a9510: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a9510u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a9514: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a9514u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9518: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a9518u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a951c: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A951Cu;
    SET_GPR_U32(ctx, 31, 0x1A9524u);
    ctx->pc = 0x1A9520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A951Cu;
            // 0x1a9520: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9524u; }
        if (ctx->pc != 0x1A9524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9524u; }
        if (ctx->pc != 0x1A9524u) { return; }
    }
    ctx->pc = 0x1A9524u;
label_1a9524:
    // 0x1a9524: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1a9524u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1a9528: 0xc04a432  jal         func_1290C8
    ctx->pc = 0x1A9528u;
    SET_GPR_U32(ctx, 31, 0x1A9530u);
    ctx->pc = 0x1A952Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9528u;
            // 0x1a952c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1290C8u;
    if (runtime->hasFunction(0x1290C8u)) {
        auto targetFn = runtime->lookupFunction(0x1290C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9530u; }
        if (ctx->pc != 0x1A9530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001290C8_0x1290c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9530u; }
        if (ctx->pc != 0x1A9530u) { return; }
    }
    ctx->pc = 0x1A9530u;
label_1a9530:
    // 0x1a9530: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1a9530u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9534: 0x0  nop
    ctx->pc = 0x1a9534u;
    // NOP
    // 0x1a9538: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A9538u;
    {
        const bool branch_taken_0x1a9538 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9538) {
            ctx->pc = 0x1A9524u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9524;
        }
    }
    ctx->pc = 0x1A9540u;
    // 0x1a9540: 0xc04a702  jal         func_129C08
    ctx->pc = 0x1A9540u;
    SET_GPR_U32(ctx, 31, 0x1A9548u);
    ctx->pc = 0x1A9544u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9540u;
            // 0x1a9544: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129C08u;
    if (runtime->hasFunction(0x129C08u)) {
        auto targetFn = runtime->lookupFunction(0x129C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9548u; }
        if (ctx->pc != 0x1A9548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129C08_0x129c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9548u; }
        if (ctx->pc != 0x1A9548u) { return; }
    }
    ctx->pc = 0x1A9548u;
label_1a9548:
    // 0x1a9548: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1a9548u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a954c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1a954cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9550: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x1A9550u;
    SET_GPR_U32(ctx, 31, 0x1A9558u);
    ctx->pc = 0x1A9554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9550u;
            // 0x1a9554: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9558u; }
        if (ctx->pc != 0x1A9558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9558u; }
        if (ctx->pc != 0x1A9558u) { return; }
    }
    ctx->pc = 0x1A9558u;
label_1a9558:
    // 0x1a9558: 0xc04a752  jal         func_129D48
    ctx->pc = 0x1A9558u;
    SET_GPR_U32(ctx, 31, 0x1A9560u);
    ctx->pc = 0x1A955Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9558u;
            // 0x1a955c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9560u; }
        if (ctx->pc != 0x1A9560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9560u; }
        if (ctx->pc != 0x1A9560u) { return; }
    }
    ctx->pc = 0x1A9560u;
label_1a9560:
    // 0x1a9560: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a9560u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a9564: 0x0  nop
    ctx->pc = 0x1a9564u;
    // NOP
    // 0x1a9568: 0x0  nop
    ctx->pc = 0x1a9568u;
    // NOP
    // 0x1a956c: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A956Cu;
    {
        const bool branch_taken_0x1a956c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1a956c) {
            ctx->pc = 0x1A9558u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9558;
        }
    }
    ctx->pc = 0x1A9574u;
    // 0x1a9574: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1A9574u;
    SET_GPR_U32(ctx, 31, 0x1A957Cu);
    ctx->pc = 0x1A9578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9574u;
            // 0x1a9578: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A957Cu; }
        if (ctx->pc != 0x1A957Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A957Cu; }
        if (ctx->pc != 0x1A957Cu) { return; }
    }
    ctx->pc = 0x1A957Cu;
label_1a957c:
    // 0x1a957c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a957cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a9580: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a9580u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9584: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a9584u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a9588: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a9588u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a958c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A958Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A958Cu;
            // 0x1a9590: 0x27bd0830  addiu       $sp, $sp, 0x830 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 2096));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9524u: goto label_1a9524;
            case 0x1A9530u: goto label_1a9530;
            case 0x1A9548u: goto label_1a9548;
            case 0x1A9558u: goto label_1a9558;
            case 0x1A9560u: goto label_1a9560;
            case 0x1A957Cu: goto label_1a957c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9594u;
    // 0x1a9594: 0x0  nop
    ctx->pc = 0x1a9594u;
    // NOP
    // 0x1a9598: 0x0  nop
    ctx->pc = 0x1a9598u;
    // NOP
    // 0x1a959c: 0x0  nop
    ctx->pc = 0x1a959cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

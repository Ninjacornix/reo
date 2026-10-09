#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172828
// Address: 0x172828 - 0x1728d8
void sub_00172828_0x172828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172828_0x172828");
#endif

    switch (ctx->pc) {
        case 0x17284cu: goto label_17284c;
        case 0x172860u: goto label_172860;
        case 0x172870u: goto label_172870;
        case 0x172880u: goto label_172880;
        case 0x172898u: goto label_172898;
        case 0x1728a8u: goto label_1728a8;
        default: break;
    }

    ctx->pc = 0x172828u;

    // 0x172828: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172828u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17282c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x17282cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x172830: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x172834: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x172834u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172838: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x172838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17283c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17283cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x172840: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x172840u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x172844: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172844u;
    SET_GPR_U32(ctx, 31, 0x17284Cu);
    ctx->pc = 0x172848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172844u;
            // 0x172848: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17284Cu; }
        if (ctx->pc != 0x17284Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17284Cu; }
        if (ctx->pc != 0x17284Cu) { return; }
    }
    ctx->pc = 0x17284Cu;
label_17284c:
    // 0x17284c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17284cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172850: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x172850u;
    {
        const bool branch_taken_0x172850 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x172854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172850u;
            // 0x172854: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172850) {
            ctx->pc = 0x172878u;
            goto label_172878;
        }
    }
    ctx->pc = 0x172858u;
    // 0x172858: 0xc05df12  jal         func_177C48
    ctx->pc = 0x172858u;
    SET_GPR_U32(ctx, 31, 0x172860u);
    ctx->pc = 0x177C48u;
    if (runtime->hasFunction(0x177C48u)) {
        auto targetFn = runtime->lookupFunction(0x177C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172860u; }
        if (ctx->pc != 0x172860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C48_0x177c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172860u; }
        if (ctx->pc != 0x172860u) { return; }
    }
    ctx->pc = 0x172860u;
label_172860:
    // 0x172860: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172860u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172864: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x172864u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x172868: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x172868u;
    SET_GPR_U32(ctx, 31, 0x172870u);
    ctx->pc = 0x17286Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172868u;
            // 0x17286c: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172870u; }
        if (ctx->pc != 0x172870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172870u; }
        if (ctx->pc != 0x172870u) { return; }
    }
    ctx->pc = 0x172870u;
label_172870:
    // 0x172870: 0x2429025  or          $s2, $s2, $v0
    ctx->pc = 0x172870u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 2));
    // 0x172874: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_172878:
    // 0x172878: 0xc05d58a  jal         func_175628
    ctx->pc = 0x172878u;
    SET_GPR_U32(ctx, 31, 0x172880u);
    ctx->pc = 0x17287Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x172878u;
            // 0x17287c: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172880u; }
        if (ctx->pc != 0x172880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172880u; }
        if (ctx->pc != 0x172880u) { return; }
    }
    ctx->pc = 0x172880u;
label_172880:
    // 0x172880: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172880u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172884: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x172884u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x172888: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x172888u;
    {
        const bool branch_taken_0x172888 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17288Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172888u;
            // 0x17288c: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x172888) {
            ctx->pc = 0x1728ACu;
            goto label_1728ac;
        }
    }
    ctx->pc = 0x172890u;
    // 0x172890: 0xc05df12  jal         func_177C48
    ctx->pc = 0x172890u;
    SET_GPR_U32(ctx, 31, 0x172898u);
    ctx->pc = 0x177C48u;
    if (runtime->hasFunction(0x177C48u)) {
        auto targetFn = runtime->lookupFunction(0x177C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172898u; }
        if (ctx->pc != 0x172898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C48_0x177c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172898u; }
        if (ctx->pc != 0x172898u) { return; }
    }
    ctx->pc = 0x172898u;
label_172898:
    // 0x172898: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x172898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17289c: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x17289cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1728a0: 0xc05df1e  jal         func_177C78
    ctx->pc = 0x1728A0u;
    SET_GPR_U32(ctx, 31, 0x1728A8u);
    ctx->pc = 0x1728A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1728A0u;
            // 0x1728a4: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C78u;
    if (runtime->hasFunction(0x177C78u)) {
        auto targetFn = runtime->lookupFunction(0x177C78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1728A8u; }
        if (ctx->pc != 0x1728A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C78_0x177c78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1728A8u; }
        if (ctx->pc != 0x1728A8u) { return; }
    }
    ctx->pc = 0x1728A8u;
label_1728a8:
    // 0x1728a8: 0x2228825  or          $s1, $s1, $v0
    ctx->pc = 0x1728a8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
label_1728ac:
    // 0x1728ac: 0x12400004  beqz        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1728ACu;
    {
        const bool branch_taken_0x1728ac = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x1728B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1728ACu;
            // 0x1728b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1728ac) {
            ctx->pc = 0x1728C0u;
            goto label_1728c0;
        }
    }
    ctx->pc = 0x1728B4u;
    // 0x1728b4: 0x16200002  bnez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1728B4u;
    {
        const bool branch_taken_0x1728b4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x1728B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1728B4u;
            // 0x1728b8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1728b4) {
            ctx->pc = 0x1728C0u;
            goto label_1728c0;
        }
    }
    ctx->pc = 0x1728BCu;
    // 0x1728bc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1728bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1728c0:
    // 0x1728c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1728c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1728c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1728c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1728c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1728c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1728cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1728ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1728d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1728D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1728D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1728D0u;
            // 0x1728d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17284Cu: goto label_17284c;
            case 0x172860u: goto label_172860;
            case 0x172870u: goto label_172870;
            case 0x172878u: goto label_172878;
            case 0x172880u: goto label_172880;
            case 0x172898u: goto label_172898;
            case 0x1728A8u: goto label_1728a8;
            case 0x1728ACu: goto label_1728ac;
            case 0x1728C0u: goto label_1728c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1728D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

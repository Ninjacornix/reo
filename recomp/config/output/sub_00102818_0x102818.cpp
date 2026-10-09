#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102818
// Address: 0x102818 - 0x102880
void sub_00102818_0x102818(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102818_0x102818");
#endif

    switch (ctx->pc) {
        case 0x10282cu: goto label_10282c;
        default: break;
    }

    ctx->pc = 0x102818u;

    // 0x102818: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x102818u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10281c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10281cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102820: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x102820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x102824: 0xc040a3c  jal         func_1028F0
    ctx->pc = 0x102824u;
    SET_GPR_U32(ctx, 31, 0x10282Cu);
    ctx->pc = 0x102828u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102824u;
            // 0x102828: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1028F0u;
    if (runtime->hasFunction(0x1028F0u)) {
        auto targetFn = runtime->lookupFunction(0x1028F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10282Cu; }
        if (ctx->pc != 0x10282Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001028F0_0x1028f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10282Cu; }
        if (ctx->pc != 0x10282Cu) { return; }
    }
    ctx->pc = 0x10282Cu;
label_10282c:
    // 0x10282c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10282Cu;
    {
        const bool branch_taken_0x10282c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10282Cu;
            // 0x102830: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10282c) {
            ctx->pc = 0x10283Cu;
            goto label_10283c;
        }
    }
    ctx->pc = 0x102834u;
    // 0x102834: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x102834u;
    {
        const bool branch_taken_0x102834 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x102834) {
            ctx->pc = 0x102844u;
            goto label_102844;
        }
    }
    ctx->pc = 0x10283Cu;
label_10283c:
    // 0x10283c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x10283Cu;
    {
        const bool branch_taken_0x10283c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10283Cu;
            // 0x102840: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10283c) {
            ctx->pc = 0x102870u;
            goto label_102870;
        }
    }
    ctx->pc = 0x102844u;
label_102844:
    // 0x102844: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102844u;
    {
        const bool branch_taken_0x102844 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x102848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102844u;
            // 0x102848: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102844) {
            ctx->pc = 0x102854u;
            goto label_102854;
        }
    }
    ctx->pc = 0x10284Cu;
    // 0x10284c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10284Cu;
    {
        const bool branch_taken_0x10284c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10284Cu;
            // 0x102850: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10284c) {
            ctx->pc = 0x102864u;
            goto label_102864;
        }
    }
    ctx->pc = 0x102854u;
label_102854:
    // 0x102854: 0x16030006  bne         $s0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x102854u;
    {
        const bool branch_taken_0x102854 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x102858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102854u;
            // 0x102858: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102854) {
            ctx->pc = 0x102870u;
            goto label_102870;
        }
    }
    ctx->pc = 0x10285Cu;
    // 0x10285c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x10285cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x102860: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x102860u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_102864:
    // 0x102864: 0x34423810  ori         $v0, $v0, 0x3810
    ctx->pc = 0x102864u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14352);
    // 0x102868: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x102868u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x10286c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10286cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_102870:
    // 0x102870: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x102870u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102874: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102874u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102878: 0x3e00008  jr          $ra
    ctx->pc = 0x102878u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10287Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102878u;
            // 0x10287c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10282Cu: goto label_10282c;
            case 0x10283Cu: goto label_10283c;
            case 0x102844u: goto label_102844;
            case 0x102854u: goto label_102854;
            case 0x102864u: goto label_102864;
            case 0x102870u: goto label_102870;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102880u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

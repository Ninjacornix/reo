#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168820
// Address: 0x168820 - 0x168888
void sub_00168820_0x168820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168820_0x168820");
#endif

    switch (ctx->pc) {
        case 0x168848u: goto label_168848;
        case 0x168850u: goto label_168850;
        default: break;
    }

    ctx->pc = 0x168820u;

    // 0x168820: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x168820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x168824: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x168824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x168828: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x168828u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16882c: 0x2a220004  slti        $v0, $s1, 0x4
    ctx->pc = 0x16882cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x168830: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x168830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x168834: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x168834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x168838: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x168838u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16883c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16883cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x168840: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x168840u;
    {
        const bool branch_taken_0x168840 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168840u;
            // 0x168844: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168840) {
            ctx->pc = 0x16886Cu;
            goto label_16886c;
        }
    }
    ctx->pc = 0x168848u;
label_168848:
    // 0x168848: 0xc055f4a  jal         func_157D28
    ctx->pc = 0x168848u;
    SET_GPR_U32(ctx, 31, 0x168850u);
    ctx->pc = 0x16884Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168848u;
            // 0x16884c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157D28u;
    if (runtime->hasFunction(0x157D28u)) {
        auto targetFn = runtime->lookupFunction(0x157D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168850u; }
        if (ctx->pc != 0x168850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157D28_0x157d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168850u; }
        if (ctx->pc != 0x168850u) { return; }
    }
    ctx->pc = 0x168850u;
label_168850:
    // 0x168850: 0x14520003  bne         $v0, $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x168850u;
    {
        const bool branch_taken_0x168850 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        ctx->pc = 0x168854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168850u;
            // 0x168854: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168850) {
            ctx->pc = 0x168860u;
            goto label_168860;
        }
    }
    ctx->pc = 0x168858u;
    // 0x168858: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x168858u;
    {
        const bool branch_taken_0x168858 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16885Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168858u;
            // 0x16885c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168858) {
            ctx->pc = 0x168870u;
            goto label_168870;
        }
    }
    ctx->pc = 0x168860u;
label_168860:
    // 0x168860: 0x2a220004  slti        $v0, $s1, 0x4
    ctx->pc = 0x168860u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x168864: 0x1040fff8  beqz        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x168864u;
    {
        const bool branch_taken_0x168864 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168864u;
            // 0x168868: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168864) {
            ctx->pc = 0x168848u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_168848;
        }
    }
    ctx->pc = 0x16886Cu;
label_16886c:
    // 0x16886c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16886cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_168870:
    // 0x168870: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x168870u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168874: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x168874u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x168878: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x168878u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16887c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16887cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168880: 0x3e00008  jr          $ra
    ctx->pc = 0x168880u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168880u;
            // 0x168884: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168848u: goto label_168848;
            case 0x168850u: goto label_168850;
            case 0x168860u: goto label_168860;
            case 0x16886Cu: goto label_16886c;
            case 0x168870u: goto label_168870;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168888u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

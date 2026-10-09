#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001023C8
// Address: 0x1023c8 - 0x102418
void sub_001023C8_0x1023c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001023C8_0x1023c8");
#endif

    switch (ctx->pc) {
        case 0x1023dcu: goto label_1023dc;
        case 0x1023fcu: goto label_1023fc;
        case 0x102404u: goto label_102404;
        default: break;
    }

    ctx->pc = 0x1023c8u;

    // 0x1023c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1023c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1023cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1023ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1023d0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1023d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1023d4: 0xc040926  jal         func_102498
    ctx->pc = 0x1023D4u;
    SET_GPR_U32(ctx, 31, 0x1023DCu);
    ctx->pc = 0x1023D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1023D4u;
            // 0x1023d8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102498u;
    if (runtime->hasFunction(0x102498u)) {
        auto targetFn = runtime->lookupFunction(0x102498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023DCu; }
        if (ctx->pc != 0x1023DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102498_0x102498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023DCu; }
        if (ctx->pc != 0x1023DCu) { return; }
    }
    ctx->pc = 0x1023DCu;
label_1023dc:
    // 0x1023dc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1023dcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1023e0: 0x28620004  slti        $v0, $v1, 0x4
    ctx->pc = 0x1023e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1023e4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1023E4u;
    {
        const bool branch_taken_0x1023e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1023E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1023E4u;
            // 0x1023e8: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1023e4) {
            ctx->pc = 0x102408u;
            goto label_102408;
        }
    }
    ctx->pc = 0x1023ECu;
    // 0x1023ec: 0x18600007  blez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1023ECu;
    {
        const bool branch_taken_0x1023ec = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1023F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1023ECu;
            // 0x1023f0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1023ec) {
            ctx->pc = 0x10240Cu;
            goto label_10240c;
        }
    }
    ctx->pc = 0x1023F4u;
    // 0x1023f4: 0xc04093c  jal         func_1024F0
    ctx->pc = 0x1023F4u;
    SET_GPR_U32(ctx, 31, 0x1023FCu);
    ctx->pc = 0x1023F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1023F4u;
            // 0x1023f8: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1024F0u;
    if (runtime->hasFunction(0x1024F0u)) {
        auto targetFn = runtime->lookupFunction(0x1024F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023FCu; }
        if (ctx->pc != 0x1023FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001024F0_0x1024f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023FCu; }
        if (ctx->pc != 0x1023FCu) { return; }
    }
    ctx->pc = 0x1023FCu;
label_1023fc:
    // 0x1023fc: 0xc040938  jal         func_1024E0
    ctx->pc = 0x1023FCu;
    SET_GPR_U32(ctx, 31, 0x102404u);
    ctx->pc = 0x102400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1023FCu;
            // 0x102400: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1024E0u;
    if (runtime->hasFunction(0x1024E0u)) {
        auto targetFn = runtime->lookupFunction(0x1024E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102404u; }
        if (ctx->pc != 0x102404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001024E0_0x1024e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102404u; }
        if (ctx->pc != 0x102404u) { return; }
    }
    ctx->pc = 0x102404u;
label_102404:
    // 0x102404: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x102404u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_102408:
    // 0x102408: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x102408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_10240c:
    // 0x10240c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10240cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102410: 0x3e00008  jr          $ra
    ctx->pc = 0x102410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102410u;
            // 0x102414: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102418u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

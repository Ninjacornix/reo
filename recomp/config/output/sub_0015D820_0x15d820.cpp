#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D820
// Address: 0x15d820 - 0x15d878
void sub_0015D820_0x15d820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D820_0x15d820");
#endif

    switch (ctx->pc) {
        case 0x15d834u: goto label_15d834;
        case 0x15d848u: goto label_15d848;
        default: break;
    }

    ctx->pc = 0x15d820u;

    // 0x15d820: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15d820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15d824: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d828: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15d828u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15d82c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15D82Cu;
    SET_GPR_U32(ctx, 31, 0x15D834u);
    ctx->pc = 0x15D830u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D82Cu;
            // 0x15d830: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D834u; }
        if (ctx->pc != 0x15D834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D834u; }
        if (ctx->pc != 0x15D834u) { return; }
    }
    ctx->pc = 0x15D834u;
label_15d834:
    // 0x15d834: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15D834u;
    {
        const bool branch_taken_0x15d834 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D834u;
            // 0x15d838: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d834) {
            ctx->pc = 0x15D860u;
            goto label_15d860;
        }
    }
    ctx->pc = 0x15D83Cu;
    // 0x15d83c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d83cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d840: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D840u;
    SET_GPR_U32(ctx, 31, 0x15D848u);
    ctx->pc = 0x15D844u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D840u;
            // 0x15d844: 0x2484ec20  addiu       $a0, $a0, -0x13E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D848u; }
        if (ctx->pc != 0x15D848u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D848u; }
        if (ctx->pc != 0x15D848u) { return; }
    }
    ctx->pc = 0x15D848u;
label_15d848:
    // 0x15d848: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15d848u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d84c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d84cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d850: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d850u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d854: 0x3e00008  jr          $ra
    ctx->pc = 0x15D854u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D854u;
            // 0x15d858: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D834u: goto label_15d834;
            case 0x15D848u: goto label_15d848;
            case 0x15D860u: goto label_15d860;
            case 0x15D870u: goto label_15d870;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D85Cu;
    // 0x15d85c: 0x0  nop
    ctx->pc = 0x15d85cu;
    // NOP
label_15d860:
    // 0x15d860: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d860u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d864: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d864u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d868: 0x805761c  j           func_15D870
    ctx->pc = 0x15D868u;
    ctx->pc = 0x15D86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D868u;
            // 0x15d86c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D870u;
    goto label_15d870;
    ctx->pc = 0x15D870u;
label_15d870:
    // 0x15d870: 0x3e00008  jr          $ra
    ctx->pc = 0x15D870u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D870u;
            // 0x15d874: 0x8c820054  lw          $v0, 0x54($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 84)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D834u: goto label_15d834;
            case 0x15D848u: goto label_15d848;
            case 0x15D860u: goto label_15d860;
            case 0x15D870u: goto label_15d870;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D878u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

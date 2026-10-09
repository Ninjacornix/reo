#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148838
// Address: 0x148838 - 0x148870
void sub_00148838_0x148838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148838_0x148838");
#endif

    switch (ctx->pc) {
        case 0x148850u: goto label_148850;
        case 0x14885cu: goto label_14885c;
        default: break;
    }

    ctx->pc = 0x148838u;

    // 0x148838: 0x27bdfee0  addiu       $sp, $sp, -0x120
    ctx->pc = 0x148838u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x14883c: 0xffb00100  sd          $s0, 0x100($sp)
    ctx->pc = 0x14883cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 256), GPR_U64(ctx, 16));
    // 0x148840: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x148840u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148844: 0xffbf0110  sd          $ra, 0x110($sp)
    ctx->pc = 0x148844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 31));
    // 0x148848: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x148848u;
    SET_GPR_U32(ctx, 31, 0x148850u);
    ctx->pc = 0x14884Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148848u;
            // 0x14884c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148850u; }
        if (ctx->pc != 0x148850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148850u; }
        if (ctx->pc != 0x148850u) { return; }
    }
    ctx->pc = 0x148850u;
label_148850:
    // 0x148850: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x148850u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148854: 0xc05221c  jal         func_148870
    ctx->pc = 0x148854u;
    SET_GPR_U32(ctx, 31, 0x14885Cu);
    ctx->pc = 0x148858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148854u;
            // 0x148858: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14885Cu; }
        if (ctx->pc != 0x14885Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14885Cu; }
        if (ctx->pc != 0x14885Cu) { return; }
    }
    ctx->pc = 0x14885Cu;
label_14885c:
    // 0x14885c: 0xdfbf0110  ld          $ra, 0x110($sp)
    ctx->pc = 0x14885cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x148860: 0xdfb00100  ld          $s0, 0x100($sp)
    ctx->pc = 0x148860u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x148864: 0x3e00008  jr          $ra
    ctx->pc = 0x148864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148864u;
            // 0x148868: 0x27bd0120  addiu       $sp, $sp, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 288));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148850u: goto label_148850;
            case 0x14885Cu: goto label_14885c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14886Cu;
    // 0x14886c: 0x0  nop
    ctx->pc = 0x14886cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

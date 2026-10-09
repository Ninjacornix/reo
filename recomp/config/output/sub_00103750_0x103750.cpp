#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103750
// Address: 0x103750 - 0x103768
void sub_00103750_0x103750(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103750_0x103750");
#endif

    switch (ctx->pc) {
        case 0x103760u: goto label_103760;
        default: break;
    }

    ctx->pc = 0x103750u;

    // 0x103750: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x103750u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x103754: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x103754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x103758: 0xc0429aa  jal         func_10A6A8
    ctx->pc = 0x103758u;
    SET_GPR_U32(ctx, 31, 0x103760u);
    ctx->pc = 0x10375Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103758u;
            // 0x10375c: 0x24040006  addiu       $a0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A6A8u;
    if (runtime->hasFunction(0x10A6A8u)) {
        auto targetFn = runtime->lookupFunction(0x10A6A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103760u; }
        if (ctx->pc != 0x103760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A6A8_0x10a6a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103760u; }
        if (ctx->pc != 0x103760u) { return; }
    }
    ctx->pc = 0x103760u;
label_103760:
    // 0x103760: 0xc040086  jal         func_100218
    ctx->pc = 0x103760u;
    SET_GPR_U32(ctx, 31, 0x103768u);
    ctx->pc = 0x103764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103760u;
            // 0x103764: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100218u;
    if (runtime->hasFunction(0x100218u)) {
        auto targetFn = runtime->lookupFunction(0x100218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103768u; }
        if (ctx->pc != 0x103768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100218_0x100218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103768u; }
        if (ctx->pc != 0x103768u) { return; }
    }
    ctx->pc = 0x103768u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

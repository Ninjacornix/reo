#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2380
// Address: 0x1d2380 - 0x1d23a8
void sub_001D2380_0x1d2380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2380_0x1d2380");
#endif

    switch (ctx->pc) {
        case 0x1d2394u: goto label_1d2394;
        case 0x1d239cu: goto label_1d239c;
        default: break;
    }

    ctx->pc = 0x1d2380u;

    // 0x1d2380: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2384: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d2384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2388: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d238c: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1D238Cu;
    SET_GPR_U32(ctx, 31, 0x1D2394u);
    ctx->pc = 0x1D2390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D238Cu;
            // 0x1d2390: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2394u; }
        if (ctx->pc != 0x1D2394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2394u; }
        if (ctx->pc != 0x1D2394u) { return; }
    }
    ctx->pc = 0x1D2394u;
label_1d2394:
    // 0x1d2394: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D2394u;
    SET_GPR_U32(ctx, 31, 0x1D239Cu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D239Cu; }
        if (ctx->pc != 0x1D239Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D239Cu; }
        if (ctx->pc != 0x1D239Cu) { return; }
    }
    ctx->pc = 0x1D239Cu;
label_1d239c:
    // 0x1d239c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d239cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d23a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D23A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D23A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D23A0u;
            // 0x1d23a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2394u: goto label_1d2394;
            case 0x1D239Cu: goto label_1d239c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D23A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

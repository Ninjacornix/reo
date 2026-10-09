#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2480
// Address: 0x1d2480 - 0x1d24a8
void sub_001D2480_0x1d2480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2480_0x1d2480");
#endif

    switch (ctx->pc) {
        case 0x1d2494u: goto label_1d2494;
        case 0x1d249cu: goto label_1d249c;
        default: break;
    }

    ctx->pc = 0x1d2480u;

    // 0x1d2480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2484: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1d2484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2488: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d248c: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1D248Cu;
    SET_GPR_U32(ctx, 31, 0x1D2494u);
    ctx->pc = 0x1D2490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D248Cu;
            // 0x1d2490: 0x24044200  addiu       $a0, $zero, 0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2494u; }
        if (ctx->pc != 0x1D2494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2494u; }
        if (ctx->pc != 0x1D2494u) { return; }
    }
    ctx->pc = 0x1D2494u;
label_1d2494:
    // 0x1d2494: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D2494u;
    SET_GPR_U32(ctx, 31, 0x1D249Cu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D249Cu; }
        if (ctx->pc != 0x1D249Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D249Cu; }
        if (ctx->pc != 0x1D249Cu) { return; }
    }
    ctx->pc = 0x1D249Cu;
label_1d249c:
    // 0x1d249c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d249cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d24a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D24A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D24A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D24A0u;
            // 0x1d24a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2494u: goto label_1d2494;
            case 0x1D249Cu: goto label_1d249c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D24A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2280
// Address: 0x1d2280 - 0x1d22a8
void sub_001D2280_0x1d2280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2280_0x1d2280");
#endif

    switch (ctx->pc) {
        case 0x1d2294u: goto label_1d2294;
        case 0x1d229cu: goto label_1d229c;
        default: break;
    }

    ctx->pc = 0x1d2280u;

    // 0x1d2280: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d2280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d2284: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d2284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d2288: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d2288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d228c: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1D228Cu;
    SET_GPR_U32(ctx, 31, 0x1D2294u);
    ctx->pc = 0x1D2290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D228Cu;
            // 0x1d2290: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2294u; }
        if (ctx->pc != 0x1D2294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2294u; }
        if (ctx->pc != 0x1D2294u) { return; }
    }
    ctx->pc = 0x1D2294u;
label_1d2294:
    // 0x1d2294: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D2294u;
    SET_GPR_U32(ctx, 31, 0x1D229Cu);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D229Cu; }
        if (ctx->pc != 0x1D229Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D229Cu; }
        if (ctx->pc != 0x1D229Cu) { return; }
    }
    ctx->pc = 0x1D229Cu;
label_1d229c:
    // 0x1d229c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d229cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d22a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D22A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D22A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D22A0u;
            // 0x1d22a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2294u: goto label_1d2294;
            case 0x1D229Cu: goto label_1d229c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D22A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B308
// Address: 0x13b308 - 0x13b32c
void sub_0013B308_0x13b308(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B308_0x13b308");
#endif

    switch (ctx->pc) {
        case 0x13b318u: goto label_13b318;
        default: break;
    }

    ctx->pc = 0x13b308u;

    // 0x13b308: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13b308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13b30c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13b30cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13b310: 0xc04eccc  jal         func_13B330
    ctx->pc = 0x13B310u;
    SET_GPR_U32(ctx, 31, 0x13B318u);
    ctx->pc = 0x13B330u;
    if (runtime->hasFunction(0x13B330u)) {
        auto targetFn = runtime->lookupFunction(0x13B330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B318u; }
        if (ctx->pc != 0x13B318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B330_0x13b330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B318u; }
        if (ctx->pc != 0x13B318u) { return; }
    }
    ctx->pc = 0x13B318u;
label_13b318:
    // 0x13b318: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13b318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b31c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x13b31cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x13b320: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x13b320u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x13b324: 0x3e00008  jr          $ra
    ctx->pc = 0x13B324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B324u;
            // 0x13b328: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B318u: goto label_13b318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B32Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163E88
// Address: 0x163e88 - 0x163ea8
void sub_00163E88_0x163e88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163E88_0x163e88");
#endif

    switch (ctx->pc) {
        case 0x163e98u: goto label_163e98;
        default: break;
    }

    ctx->pc = 0x163e88u;

    // 0x163e88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163e88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163e8c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163e90: 0xc05799e  jal         func_15E678
    ctx->pc = 0x163E90u;
    SET_GPR_U32(ctx, 31, 0x163E98u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E98u; }
        if (ctx->pc != 0x163E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163E98u; }
        if (ctx->pc != 0x163E98u) { return; }
    }
    ctx->pc = 0x163E98u;
label_163e98:
    // 0x163e98: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x163e98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x163e9c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163e9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163ea0: 0x3e00008  jr          $ra
    ctx->pc = 0x163EA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163EA0u;
            // 0x163ea4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163E98u: goto label_163e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163EA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

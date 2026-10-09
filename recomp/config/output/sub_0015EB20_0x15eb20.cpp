#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EB20
// Address: 0x15eb20 - 0x15eb40
void sub_0015EB20_0x15eb20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EB20_0x15eb20");
#endif

    switch (ctx->pc) {
        case 0x15eb30u: goto label_15eb30;
        default: break;
    }

    ctx->pc = 0x15eb20u;

    // 0x15eb20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15eb20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15eb24: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15eb24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15eb28: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15EB28u;
    SET_GPR_U32(ctx, 31, 0x15EB30u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EB30u; }
        if (ctx->pc != 0x15EB30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EB30u; }
        if (ctx->pc != 0x15EB30u) { return; }
    }
    ctx->pc = 0x15EB30u;
label_15eb30:
    // 0x15eb30: 0x8c420064  lw          $v0, 0x64($v0)
    ctx->pc = 0x15eb30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x15eb34: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15eb34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15eb38: 0x3e00008  jr          $ra
    ctx->pc = 0x15EB38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EB38u;
            // 0x15eb3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EB30u: goto label_15eb30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EB40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015EE28
// Address: 0x15ee28 - 0x15ee48
void sub_0015EE28_0x15ee28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015EE28_0x15ee28");
#endif

    switch (ctx->pc) {
        case 0x15ee38u: goto label_15ee38;
        default: break;
    }

    ctx->pc = 0x15ee28u;

    // 0x15ee28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ee28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ee2c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ee2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ee30: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15EE30u;
    SET_GPR_U32(ctx, 31, 0x15EE38u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE38u; }
        if (ctx->pc != 0x15EE38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15EE38u; }
        if (ctx->pc != 0x15EE38u) { return; }
    }
    ctx->pc = 0x15EE38u;
label_15ee38:
    // 0x15ee38: 0x8c420034  lw          $v0, 0x34($v0)
    ctx->pc = 0x15ee38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x15ee3c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ee3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ee40: 0x3e00008  jr          $ra
    ctx->pc = 0x15EE40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15EE44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15EE40u;
            // 0x15ee44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15EE38u: goto label_15ee38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EE48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

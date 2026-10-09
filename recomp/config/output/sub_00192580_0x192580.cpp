#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192580
// Address: 0x192580 - 0x1925a0
void sub_00192580_0x192580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192580_0x192580");
#endif

    switch (ctx->pc) {
        case 0x192590u: goto label_192590;
        default: break;
    }

    ctx->pc = 0x192580u;

    // 0x192580: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x192580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x192584: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x192584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x192588: 0xc063724  jal         func_18DC90
    ctx->pc = 0x192588u;
    SET_GPR_U32(ctx, 31, 0x192590u);
    ctx->pc = 0x18DC90u;
    if (runtime->hasFunction(0x18DC90u)) {
        auto targetFn = runtime->lookupFunction(0x18DC90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192590u; }
        if (ctx->pc != 0x192590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192590u; }
        if (ctx->pc != 0x192590u) { return; }
    }
    ctx->pc = 0x192590u;
label_192590:
    // 0x192590: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x192590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192594: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192598: 0x3e00008  jr          $ra
    ctx->pc = 0x192598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19259Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192598u;
            // 0x19259c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192590u: goto label_192590;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1925A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E978
// Address: 0x15e978 - 0x15e998
void sub_0015E978_0x15e978(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E978_0x15e978");
#endif

    switch (ctx->pc) {
        case 0x15e988u: goto label_15e988;
        default: break;
    }

    ctx->pc = 0x15e978u;

    // 0x15e978: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e978u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e97c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15e97cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15e980: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15E980u;
    SET_GPR_U32(ctx, 31, 0x15E988u);
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E988u; }
        if (ctx->pc != 0x15E988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E988u; }
        if (ctx->pc != 0x15E988u) { return; }
    }
    ctx->pc = 0x15E988u;
label_15e988:
    // 0x15e988: 0x8c42003c  lw          $v0, 0x3C($v0)
    ctx->pc = 0x15e988u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 60)));
    // 0x15e98c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15e98cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e990: 0x3e00008  jr          $ra
    ctx->pc = 0x15E990u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E990u;
            // 0x15e994: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E988u: goto label_15e988;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E998u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

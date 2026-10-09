#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B478
// Address: 0x15b478 - 0x15b4a0
void sub_0015B478_0x15b478(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B478_0x15b478");
#endif

    switch (ctx->pc) {
        case 0x15b488u: goto label_15b488;
        default: break;
    }

    ctx->pc = 0x15b478u;

    // 0x15b478: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b47c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15b47cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15b480: 0xc056e02  jal         func_15B808
    ctx->pc = 0x15B480u;
    SET_GPR_U32(ctx, 31, 0x15B488u);
    ctx->pc = 0x15B808u;
    if (runtime->hasFunction(0x15B808u)) {
        auto targetFn = runtime->lookupFunction(0x15B808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B488u; }
        if (ctx->pc != 0x15B488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B808_0x15b808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B488u; }
        if (ctx->pc != 0x15B488u) { return; }
    }
    ctx->pc = 0x15B488u;
label_15b488:
    // 0x15b488: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x15b488u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x15b48c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15b48cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b490: 0x8c444cc0  lw          $a0, 0x4CC0($v0)
    ctx->pc = 0x15b490u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 19648)));
    // 0x15b494: 0x24050ae0  addiu       $a1, $zero, 0xAE0
    ctx->pc = 0x15b494u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2784));
    // 0x15b498: 0x8056da6  j           func_15B698
    ctx->pc = 0x15B498u;
    ctx->pc = 0x15B49Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B498u;
            // 0x15b49c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B698u;
    if (runtime->hasFunction(0x15B698u)) {
        auto targetFn = runtime->lookupFunction(0x15B698u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015B698_0x15b698(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15B4A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

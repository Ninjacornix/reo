#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B838
// Address: 0x15b838 - 0x15b850
void sub_0015B838_0x15b838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B838_0x15b838");
#endif

    ctx->pc = 0x15b838u;

    // 0x15b838: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b838u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b83c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15b83cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15b840: 0x8c840380  lw          $a0, 0x380($a0)
    ctx->pc = 0x15b840u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 896)));
    // 0x15b844: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15b844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b848: 0x80540bc  j           func_1502F0
    ctx->pc = 0x15B848u;
    ctx->pc = 0x15B84Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B848u;
            // 0x15b84c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1502F0u;
    if (runtime->hasFunction(0x1502F0u)) {
        auto targetFn = runtime->lookupFunction(0x1502F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001502F0_0x1502f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15B850u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

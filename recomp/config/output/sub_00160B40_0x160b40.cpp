#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160B40
// Address: 0x160b40 - 0x160b58
void sub_00160B40_0x160b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160B40_0x160b40");
#endif

    ctx->pc = 0x160b40u;

    // 0x160b40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160b44: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160b48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160b48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160b4c: 0x805f3bc  j           func_17CEF0
    ctx->pc = 0x160B4Cu;
    ctx->pc = 0x160B50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160B4Cu;
            // 0x160b50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CEF0u;
    if (runtime->hasFunction(0x17CEF0u)) {
        auto targetFn = runtime->lookupFunction(0x17CEF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017CEF0_0x17cef0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160B54u;
    // 0x160b54: 0x0  nop
    ctx->pc = 0x160b54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

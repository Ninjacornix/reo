#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C7C8
// Address: 0x12c7c8 - 0x12c7e0
void sub_0012C7C8_0x12c7c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C7C8_0x12c7c8");
#endif

    ctx->pc = 0x12c7c8u;

    // 0x12c7c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c7c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c7cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c7ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c7d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c7d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c7d4: 0x804fbde  j           func_13EF78
    ctx->pc = 0x12C7D4u;
    ctx->pc = 0x12C7D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C7D4u;
            // 0x12c7d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EF78u;
    if (runtime->hasFunction(0x13EF78u)) {
        auto targetFn = runtime->lookupFunction(0x13EF78u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EF78_0x13ef78(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C7DCu;
    // 0x12c7dc: 0x0  nop
    ctx->pc = 0x12c7dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C7E0
// Address: 0x12c7e0 - 0x12c7f8
void sub_0012C7E0_0x12c7e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C7E0_0x12c7e0");
#endif

    ctx->pc = 0x12c7e0u;

    // 0x12c7e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c7e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c7e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c7e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c7e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c7ec: 0x804fbe0  j           func_13EF80
    ctx->pc = 0x12C7ECu;
    ctx->pc = 0x12C7F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C7ECu;
            // 0x12c7f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EF80u;
    if (runtime->hasFunction(0x13EF80u)) {
        auto targetFn = runtime->lookupFunction(0x13EF80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EF80_0x13ef80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C7F4u;
    // 0x12c7f4: 0x0  nop
    ctx->pc = 0x12c7f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

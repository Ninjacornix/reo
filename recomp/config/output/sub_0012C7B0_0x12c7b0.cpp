#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C7B0
// Address: 0x12c7b0 - 0x12c7c4
void sub_0012C7B0_0x12c7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C7B0_0x12c7b0");
#endif

    ctx->pc = 0x12c7b0u;

    // 0x12c7b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c7b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c7b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c7b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c7b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c7b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c7bc: 0x804fbd6  j           func_13EF58
    ctx->pc = 0x12C7BCu;
    ctx->pc = 0x12C7C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C7BCu;
            // 0x12c7c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EF58u;
    if (runtime->hasFunction(0x13EF58u)) {
        auto targetFn = runtime->lookupFunction(0x13EF58u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EF58_0x13ef58(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C7C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

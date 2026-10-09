#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B620
// Address: 0x12b620 - 0x12b638
void sub_0012B620_0x12b620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B620_0x12b620");
#endif

    ctx->pc = 0x12b620u;

    // 0x12b620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12b620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12b624: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12b624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12b628: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b628u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b62c: 0x805076c  j           func_141DB0
    ctx->pc = 0x12B62Cu;
    ctx->pc = 0x12B630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B62Cu;
            // 0x12b630: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141DB0u;
    if (runtime->hasFunction(0x141DB0u)) {
        auto targetFn = runtime->lookupFunction(0x141DB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141DB0_0x141db0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B634u;
    // 0x12b634: 0x0  nop
    ctx->pc = 0x12b634u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

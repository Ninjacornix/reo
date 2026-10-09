#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C630
// Address: 0x12c630 - 0x12c648
void sub_0012C630_0x12c630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C630_0x12c630");
#endif

    ctx->pc = 0x12c630u;

    // 0x12c630: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c634: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c638: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c638u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c63c: 0x804f8ae  j           func_13E2B8
    ctx->pc = 0x12C63Cu;
    ctx->pc = 0x12C640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C63Cu;
            // 0x12c640: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E2B8u;
    if (runtime->hasFunction(0x13E2B8u)) {
        auto targetFn = runtime->lookupFunction(0x13E2B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E2B8_0x13e2b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C644u;
    // 0x12c644: 0x0  nop
    ctx->pc = 0x12c644u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

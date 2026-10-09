#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C488
// Address: 0x12c488 - 0x12c4a0
void sub_0012C488_0x12c488(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C488_0x12c488");
#endif

    ctx->pc = 0x12c488u;

    // 0x12c488: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c488u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c48c: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x12c48cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x12c490: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c490u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c494: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c494u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c498: 0x805075c  j           func_141D70
    ctx->pc = 0x12C498u;
    ctx->pc = 0x12C49Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C498u;
            // 0x12c49c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141D70u;
    if (runtime->hasFunction(0x141D70u)) {
        auto targetFn = runtime->lookupFunction(0x141D70u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141D70_0x141d70(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C4A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

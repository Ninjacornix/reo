#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012BD78
// Address: 0x12bd78 - 0x12bd90
void sub_0012BD78_0x12bd78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012BD78_0x12bd78");
#endif

    ctx->pc = 0x12bd78u;

    // 0x12bd78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12bd78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12bd7c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12bd7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12bd80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12bd80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12bd84: 0x80505b4  j           func_1416D0
    ctx->pc = 0x12BD84u;
    ctx->pc = 0x12BD88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12BD84u;
            // 0x12bd88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416D0_0x1416d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12BD8Cu;
    // 0x12bd8c: 0x0  nop
    ctx->pc = 0x12bd8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F258
// Address: 0x13f258 - 0x13f270
void sub_0013F258_0x13f258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F258_0x13f258");
#endif

    ctx->pc = 0x13f258u;

    // 0x13f258: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f258u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f25c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f25cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f260: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f264: 0x80505b4  j           func_1416D0
    ctx->pc = 0x13F264u;
    ctx->pc = 0x13F268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F264u;
            // 0x13f268: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416D0_0x1416d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F26Cu;
    // 0x13f26c: 0x0  nop
    ctx->pc = 0x13f26cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

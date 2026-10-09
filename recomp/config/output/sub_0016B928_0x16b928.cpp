#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B928
// Address: 0x16b928 - 0x16b93c
void sub_0016B928_0x16b928(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B928_0x16b928");
#endif

    ctx->pc = 0x16b928u;

    // 0x16b928: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16b928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16b92c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16b92cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16b930: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16b930u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b934: 0x805a704  j           func_169C10
    ctx->pc = 0x16B934u;
    ctx->pc = 0x16B938u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B934u;
            // 0x16b938: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B93Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

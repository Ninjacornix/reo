#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F288
// Address: 0x13f288 - 0x13f29c
void sub_0013F288_0x13f288(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F288_0x13f288");
#endif

    ctx->pc = 0x13f288u;

    // 0x13f288: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f288u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f28c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f28cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f290: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f290u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f294: 0x805062a  j           func_1418A8
    ctx->pc = 0x13F294u;
    ctx->pc = 0x13F298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F294u;
            // 0x13f298: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1418A8u;
    if (runtime->hasFunction(0x1418A8u)) {
        auto targetFn = runtime->lookupFunction(0x1418A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001418A8_0x1418a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F29Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

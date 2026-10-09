#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AF18
// Address: 0x13af18 - 0x13af2c
void sub_0013AF18_0x13af18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AF18_0x13af18");
#endif

    ctx->pc = 0x13af18u;

    // 0x13af18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13af18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13af1c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13af1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13af20: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13af20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13af24: 0x804e09e  j           func_138278
    ctx->pc = 0x13AF24u;
    ctx->pc = 0x13AF28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13AF24u;
            // 0x13af28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138278u;
    if (runtime->hasFunction(0x138278u)) {
        auto targetFn = runtime->lookupFunction(0x138278u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00138278_0x138278(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13AF2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

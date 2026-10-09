#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160B28
// Address: 0x160b28 - 0x160b40
void sub_00160B28_0x160b28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160B28_0x160b28");
#endif

    ctx->pc = 0x160b28u;

    // 0x160b28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160b28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160b2c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x160b2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160b30: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160b30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x160b34: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160b34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160b38: 0x8058dd4  j           func_163750
    ctx->pc = 0x160B38u;
    ctx->pc = 0x160B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160B38u;
            // 0x160b3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160B40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001645C0
// Address: 0x1645c0 - 0x1645d8
void sub_001645C0_0x1645c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001645C0_0x1645c0");
#endif

    ctx->pc = 0x1645c0u;

    // 0x1645c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1645c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1645c4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1645c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1645c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1645c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1645cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1645ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1645d0: 0x804c0f6  j           func_1303D8
    ctx->pc = 0x1645D0u;
    ctx->pc = 0x1645D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1645D0u;
            // 0x1645d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1303D8u;
    if (runtime->hasFunction(0x1303D8u)) {
        auto targetFn = runtime->lookupFunction(0x1303D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001303D8_0x1303d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1645D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

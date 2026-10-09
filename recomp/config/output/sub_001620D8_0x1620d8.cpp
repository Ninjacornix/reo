#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001620D8
// Address: 0x1620d8 - 0x1620ec
void sub_001620D8_0x1620d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001620D8_0x1620d8");
#endif

    ctx->pc = 0x1620d8u;

    // 0x1620d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1620d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1620dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1620dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1620e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1620e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1620e4: 0x805882a  j           func_1620A8
    ctx->pc = 0x1620E4u;
    ctx->pc = 0x1620E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1620E4u;
            // 0x1620e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1620A8u;
    if (runtime->hasFunction(0x1620A8u)) {
        auto targetFn = runtime->lookupFunction(0x1620A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001620A8_0x1620a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1620ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

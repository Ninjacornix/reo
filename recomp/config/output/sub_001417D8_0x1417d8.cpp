#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001417D8
// Address: 0x1417d8 - 0x1417f0
void sub_001417D8_0x1417d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001417D8_0x1417d8");
#endif

    ctx->pc = 0x1417d8u;

    // 0x1417d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1417d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1417dc: 0x240403e8  addiu       $a0, $zero, 0x3E8
    ctx->pc = 0x1417dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x1417e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1417e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1417e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1417e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1417e8: 0x8050590  j           func_141640
    ctx->pc = 0x1417E8u;
    ctx->pc = 0x1417ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1417E8u;
            // 0x1417ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141640u;
    if (runtime->hasFunction(0x141640u)) {
        auto targetFn = runtime->lookupFunction(0x141640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141640_0x141640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1417F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

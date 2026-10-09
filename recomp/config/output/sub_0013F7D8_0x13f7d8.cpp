#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F7D8
// Address: 0x13f7d8 - 0x13f7f4
void sub_0013F7D8_0x13f7d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F7D8_0x13f7d8");
#endif

    ctx->pc = 0x13f7d8u;

    // 0x13f7d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f7d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f7dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f7dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f7e0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f7e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f7e4: 0x2484da68  addiu       $a0, $a0, -0x2598
    ctx->pc = 0x13f7e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957672));
    // 0x13f7e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f7e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f7ec: 0x804fca2  j           func_13F288
    ctx->pc = 0x13F7ECu;
    ctx->pc = 0x13F7F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F7ECu;
            // 0x13f7f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F288u;
    if (runtime->hasFunction(0x13F288u)) {
        auto targetFn = runtime->lookupFunction(0x13F288u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F288_0x13f288(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F7F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

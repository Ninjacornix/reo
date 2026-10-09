#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001620A8
// Address: 0x1620a8 - 0x1620c0
void sub_001620A8_0x1620a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001620A8_0x1620a8");
#endif

    ctx->pc = 0x1620a8u;

    // 0x1620a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1620a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1620ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1620acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1620b0: 0x8c8400a8  lw          $a0, 0xA8($a0)
    ctx->pc = 0x1620b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
    // 0x1620b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1620b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1620b8: 0x805f5aa  j           func_17D6A8
    ctx->pc = 0x1620B8u;
    ctx->pc = 0x1620BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1620B8u;
            // 0x1620bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D6A8u;
    if (runtime->hasFunction(0x17D6A8u)) {
        auto targetFn = runtime->lookupFunction(0x17D6A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D6A8_0x17d6a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1620C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

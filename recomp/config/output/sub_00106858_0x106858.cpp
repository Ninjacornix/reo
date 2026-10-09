#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106858
// Address: 0x106858 - 0x10687c
void sub_00106858_0x106858(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106858_0x106858");
#endif

    ctx->pc = 0x106858u;

    // 0x106858: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x106858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10685c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10685cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106860: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x106860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x106864: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x106864u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106868: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x106868u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10686c: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10686cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106870: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x106870u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106874: 0x8041a2a  j           func_1068A8
    ctx->pc = 0x106874u;
    ctx->pc = 0x106878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106874u;
            // 0x106878: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1068A8u;
    if (runtime->hasFunction(0x1068A8u)) {
        auto targetFn = runtime->lookupFunction(0x1068A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001068A8_0x1068a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10687Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142220
// Address: 0x142220 - 0x142238
void sub_00142220_0x142220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142220_0x142220");
#endif

    ctx->pc = 0x142220u;

    // 0x142220: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x142220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x142224: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x142224u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142228: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x142228u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14222c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14222cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142230: 0x805087e  j           func_1421F8
    ctx->pc = 0x142230u;
    ctx->pc = 0x142234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142230u;
            // 0x142234: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1421F8u;
    if (runtime->hasFunction(0x1421F8u)) {
        auto targetFn = runtime->lookupFunction(0x1421F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001421F8_0x1421f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x142238u;
    ctx->pc = GPR_U32(ctx, 31); return;
}

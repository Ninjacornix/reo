#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001888A0
// Address: 0x1888a0 - 0x1888c0
void sub_001888A0_0x1888a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001888A0_0x1888a0");
#endif

    ctx->pc = 0x1888a0u;

    // 0x1888a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1888a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1888a4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1888a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1888a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1888a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1888ac: 0x8c44b8c4  lw          $a0, -0x473C($v0)
    ctx->pc = 0x1888acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949060)));
    // 0x1888b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1888b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1888b4: 0x8045190  j           func_114640
    ctx->pc = 0x1888B4u;
    ctx->pc = 0x1888B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1888B4u;
            // 0x1888b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1888BCu;
    // 0x1888bc: 0x0  nop
    ctx->pc = 0x1888bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

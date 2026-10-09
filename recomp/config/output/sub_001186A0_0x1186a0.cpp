#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001186A0
// Address: 0x1186a0 - 0x1186b0
void sub_001186A0_0x1186a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001186A0_0x1186a0");
#endif

    ctx->pc = 0x1186a0u;

    // 0x1186a0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1186a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1186a4: 0x8045190  j           func_114640
    ctx->pc = 0x1186A4u;
    ctx->pc = 0x1186A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1186A4u;
            // 0x1186a8: 0x8c449de4  lw          $a0, -0x621C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942180)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1186ACu;
    // 0x1186ac: 0x0  nop
    ctx->pc = 0x1186acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}

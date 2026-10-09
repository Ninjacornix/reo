#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E148
// Address: 0x15e148 - 0x15e15c
void sub_0015E148_0x15e148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E148_0x15e148");
#endif

    ctx->pc = 0x15e148u;

    // 0x15e148: 0x8c8200e4  lw          $v0, 0xE4($a0)
    ctx->pc = 0x15e148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 228)));
    // 0x15e14c: 0x8c8300e0  lw          $v1, 0xE0($a0)
    ctx->pc = 0x15e14cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 224)));
    // 0x15e150: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x15e150u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x15e154: 0x3e00008  jr          $ra
    ctx->pc = 0x15E154u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E154u;
            // 0x15e158: 0xaca30000  sw          $v1, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15E15Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
